
.text
.thumb
.syntax unified
.global save_context
.type    save_context, %function
.global load_context
.type    load_context, %function

save_context:
               MRS    r0, msp
               STMDB  r0!, {r4-r11}
               MSR    msp, r0
               VPUSH.32  {s0-s15}
               VPUSH.32  {s16-s31}
               MRS    r0, msp
               BX     lr


load_context:


               MSR    msp, r0
               VPOP.32  {s16-s31}
               VPOP.32  {s0-s15}
               MRS    r0, msp
               LDMFD  r0!, {r4-r11}
               MSR    msp, r0
               BX     lr
.end
