
.text
.thumb
.syntax unified
.global save_context
.type    save_context, %function
.global load_context
.type    load_context, %function

save_context:
               MRS    r0, msp
               STM    r0!, {r4-r7}
               MSR    msp, r0
               BX     lr


load_context:
               MSR    msp, r0
               MRS    r0, msp
               LDM    r0!, {r4-r7}
               MSR    msp, r0
               BX     lr
.end

