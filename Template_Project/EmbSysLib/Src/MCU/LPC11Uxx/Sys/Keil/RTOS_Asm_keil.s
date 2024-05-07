           AREA    |.text|, CODE, READONLY
           THUMB

;
load_context FUNCTION
               EXPORT load_context
               MSR    msp, r0;
               MRS    r0, msp
               LDM    r0!, {r4-r7}
               MSR    msp, r0
               BX     lr
             ENDP

;
save_context FUNCTION
               EXPORT save_context
               MRS    r0, msp
               STM    r0!, {r4-r7}
               MSR    msp, r0
               BX     lr
             ENDP

           END

