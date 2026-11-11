/*
 * this file defines a minimal IRQ handler for the R52 written in assembly language,
 * it is based on one found here: https://github.com/ISI-apex/hpsc-baremetal/blob/hpsc/rtps/startup.s
 * and hands off the actually handling to a c function but deals with the low level
 * exception mechanics and GIC-handling
 *
 */

.text
.syntax unified
.thumb

.type   EL1_IRQ_Handler, %function
.global EL1_IRQ_Handler
.extern el1_irq_bad_id_reporter
.extern el1_irq_spurious_id_reporter
.extern el1_irq_zero_handler

.type   EL1_FIQ_Handler, %function
.global EL1_FIQ_Handler

.extern IsrVectorTable
// the following table length is a bit fragile and MUST line up with the one used in the table declaration
.equ IsrVectorTable_Length, (32 + 137)

.equ SpuriousIntID, 1023
.equ Mode_FIQ, 0x11
.equ Mode_IRQ, 0x12

EL1_IRQ_Handler:
    sub   lr, #4  // undo auto offset to get preferred ret address (ARMv8-A/R Reference, Table B1-7, IRQ/FIQ row)
    srsdb sp!, #Mode_IRQ
    push  {r0, r1} // save the contents of registers that will be lost //TODO: o [captain] do we really need to protect r0?
        mrc   p15, 0, r0, c12, c12, 0 // read the 'INT ID' from IRCC_IAR1
el1_irq_handler__store_int_id:
        push  {r0, lr} // save a copy of int_id and the state of LR_SVC before we call
            // we seem to be called to handle the 'spurious' ID (e.g. in the fusa_ioctrl_err_int test) but
            // this should not happen, for now I've added in a quick trap for this condition that will be
            // reported separately...
            mov   r1, #SpuriousIntID
            cmp   r0, r1
            blt   el1_irq_handler__table_length_test
            bl    el1_irq_spurious_id_reporter
            b     el1_irq_handler__handled
el1_irq_handler__table_length_test:
            // we establish the handler for an interrupt by fetching an entry from the ISR vector
            // table, to ensure we don't mistakenly attempt to read beyond the end of the table we
            // first check that the passed ID is not 'too high', if the value is less than or equal
            // to the number of handlers in the table we jump ahead (to continue with the lookup)
            // otherwise we will branch to an error handler then jump beyond any thought of calling
            // a handler...
            mov   r1, #IsrVectorTable_Length
            cmp   r0, r1
            blt   el1_irq_handler__lookup
            bl    el1_irq_bad_id_reporter // the int ID is in r0 - we expect the handler to look like: void fn(uint32_t id)
            b     el1_irq_handler__handled
el1_irq_handler__lookup:
            //TODO: should we: cpsie i // re-enable interrupts during the actual handler execution
            ldr   r1, =IsrVectorTable // fetch the base address of the ISR vector table
            ldr   r1, [r1, r0, lsl #2] // load r1 with the contents of the word at address r1 + (r0 * 4) -- e.g. the appropriate vector
            cbnz  r1, el1_irq_handler__call // skip over the error handler if the address is non-zero
            bl    el1_irq_zero_handler
            b     el1_irq_handler__handled
el1_irq_handler__call:
            blx   r1 // call the ISR for this interrupt ID
            //TODO: if we cpsie'd above, we need to: cpsid i // disable interrupts again
el1_irq_handler__handled:
            pop   {r0, lr} // restore int_id and LR_SVC
        mcr   p15, 0, r0, c12, c12, 1  // write INTID back to ICC_EOIR1 (to indicate that we've handled it)
        mrc   p15, 0, r0, c12, c12, 0 // read the next 'INT ID' from IRCC_IAR1
        mov   r1, #SpuriousIntID  // load the magical 'spurious ID' value
        cmp   r0, r1 // check whether this id is the 'spurious ID' (if it is then there is no work left to do here)
        bne   el1_irq_handler__store_int_id // if it wasn't the 'spurious ID' then we look back to handle it
        pop   {r0, r1} // restore the registers we used
    rfeia sp!

//EL1_FIQ_Handler:
//    SUB   lr, #4  // undo auto offset to get preferred ret address (ARMv8-A/R Reference, Table B1-7, IRQ/FIQ row)
//    SRSDB sp!, #Mode_FIQ
//    PUSH  {r0} // save the contents of registers that will be lost //TODO: o [captain] do we really need to protect r0?
//    MRC   p15, 0, r0, c12, c8, 0 // read the 'INT ID' from IRCC_IAR0
//    PUSH  {r0} // save a copy of INTID so that we can use it later (the handler will likely clobber it)
//    BL    el1_fiq_dispatcher // int_id arg passed in r0 (IRQ #)
//    POP   {r0} // restore INTID
//    MCR   p15, 0, r0, c12, c8, 1  // write INTID back to ICC_EOIR0 (to indicate that we've handled it)
//    POP   {r0} // restore the registers we used
//    RFEIA sp!


EL1_FIQ_Handler:
    sub   lr, #4  // undo auto offset to get preferred ret address (ARMv8-A/R Reference, Table B1-7, IRQ/FIQ row)
    srsdb sp!, #Mode_FIQ
    push  {r0, r1} // save the contents of registers that will be lost //TODO: o [captain] do we really need to protect r0?
    mrc   p15, 0, r0, c12, c8, 0 // read the 'INT ID' from IRCC_IAR0
el1_fiq_handler_store_int_id:
    push  {r0, lr} // save a copy of int_id and the state of LR_SVC before we call
    //BL el1_fiq_dispatcher // int_id arg passed in r0 (IRQ #)
    //TODO: should we: cpsie i // re-enable interrupts during the actual handler execution
    ldr   r1, =IsrVectorTable // fetch the base address of the ISR vector table
    ldr   r1, [r1, r0, lsl #2] // load r1 with the contents of the word at address r1 + (r0 * 4) -- e.g. the appropriate vector
    blx   r1 // call the ISR for this interrupt ID
    //TODO: if we cpsie'd above, we need to: cpsid i // disable interrupts again
    pop   {r0, lr} // restore int_id and LR_SVC
    mcr   p15, 0, r0, c12, c8, 1  // write INTID back to ICC_EOIR0 (to indicate that we've handled it)
    mrc   p15, 0, r0, c12, c8, 0 // read the next 'INT ID' from IRCC_IAR0
    mov   r1, #SpuriousIntID
    cmp   r0, r1
    bne   el1_fiq_handler_store_int_id
    pop   {r0, r1} // restore the registers we used
    rfeia sp!

.end
