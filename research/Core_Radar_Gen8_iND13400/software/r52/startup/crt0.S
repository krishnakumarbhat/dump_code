//
//	src/crtarm/crt0.s: startup for an embedded environment: ARM and Thumb2
//
//	Copyright 2017,2018 Wind River Systems, Inc.
//
//	CAUTION: FILE REQUIRES PREPROCESSING
//
//	This file contains code for both the ARM and Thumb2. The required
//      code is selected by applying the C preprocessor to the file before
//      assembling, using preprocessor macro name __thumb2__ for the Thumb2
//      version (__thumb2__ definition is supplied by the driver when using
//      a Thumb2 -t option).
//
//	To apply the preprocessor to this file, use the dcc driver with the options
//      -Xpreprocess-assembly
//	This directs dcc to first preprocesses the code and then assemble it.
//
//	ARM example:
//
//          dcc -tARMV7A... -c -Xpreprocess-assembly crt0.s
//
//      Thumb2 example:
//
//          dcc -tARMV7AT2... -c -Xpreprocess-assembly crt0.s
//
//	See also note at end regarding use of "//" and '#' comments.
//

	.file		"chandra_crt0.S"
	.text
	.global		__start_main

#ifdef __thumb2__
	.balign 	1
	.thumb_func
#else
	.balign		2
#endif

__start_main:
#ifdef __thumb2__
    ldr     r4, =__SP_INIT
    mov     sp, r4
    sub     sp,sp,#16
#else
    ldr		r13,=__SP_INIT	// Initialize stack pointer sp to
    sub		sp,sp,#16	// value in linker command file.
#endif

//
// Insert other initialization code here.
//

	bl		__init_main	// Finish initialization (copies .data
					// ROM to RAM, clears .bss), then calls
					// example main(), which calls exit(),
					// which halts.

// Note: use "//" at the start of a comment line to avoid invalid directive
// warnings when preprocessing assembly code. Use '#' for comments on code
// lines because "//" is not valid there if the code is not preprocessed.
