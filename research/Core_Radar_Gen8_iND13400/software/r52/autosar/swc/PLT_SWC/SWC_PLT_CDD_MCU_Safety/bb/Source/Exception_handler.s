/*Assembly code to load the stack pointer R-13*/
        .global exception_asm_load
        .type exception_asm_load,%function
exception_asm_load:
        STR r5, [r0]        //r0 is loaded with the address of global variable
        bx      lr
