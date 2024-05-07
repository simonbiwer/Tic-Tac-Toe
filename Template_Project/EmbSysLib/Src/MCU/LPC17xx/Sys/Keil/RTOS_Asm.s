           AREA    |.text|, CODE, READONLY
           THUMB

;
load_context FUNCTION
               EXPORT load_context
               MSR    msp, r0;
               MRS    r0, msp
               LDMFD  r0!, {r4-r11}
               MSR    msp, r0
               BX     lr
             ENDP

;
save_context FUNCTION
               EXPORT save_context
               MRS    r0, msp
               STMDB  r0!, {r4-r11}
               MSR    msp, r0
               BX     lr
             ENDP

           END

