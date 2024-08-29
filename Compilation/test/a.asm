square:
        sub     sp, sp, #4
        str     r0, [sp]
        ldr     r1, [sp]
        mul     r0, r1, r1
        add     sp, sp, #4
        bx      lr