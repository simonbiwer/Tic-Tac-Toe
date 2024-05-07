           AREA    |.text|, CODE, READONLY
           THUMB

save_context FUNCTION
               EXPORT save_context
               MRS    r0, msp
               STMDB  r0!, {r4-r11}
               MSR    msp, r0
               VPUSH.32  {s0-s31}
               MRS    r0, msp
               BX     lr
             ENDP

load_context FUNCTION
               EXPORT load_context
               MSR    msp, r0;
               VPOP.32  {s0-s31}
               MRS    r0, msp
               LDMFD  r0!, {r4-r11}
               MSR    msp, r0
               BX     lr
             ENDP

           END
