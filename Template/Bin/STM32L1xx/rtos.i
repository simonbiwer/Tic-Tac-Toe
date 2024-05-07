#line 1 "..\\EmbSysLib\\Src\\Module\\RTOS.cpp"







 


#line 1 "..\\EmbSysLib\\Src\\Module\\RTOS/RTOS.cpp"





 


#line 1 "..\\EmbSysLib\\Src\\Module\\RTOS/RTOS.h"





 






#line 1 ".\\..\\EmbSysLib\\Src\\lib.h"









 









#line 1 ".\\..\\EmbSysLib\\Src\\MCU/System.h"







 















 
class cSystem
{
  public:
    
    
 
    typedef enum
    {
      WD_TIMEOUT_16ms = 0,  
      WD_TIMEOUT_32ms,      
      WD_TIMEOUT_65ms,      
      WD_TIMEOUT_130ms,     
      WD_TIMEOUT_260ms,     
      WD_TIMEOUT_520ms,     
      WD_TIMEOUT_1000ms,    
      WD_TIMEOUT_2000ms     
    } MODE;

    
    



 
    cSystem( unsigned char disableInterrupts = false );

    
    
 
    void start( void );

    
    



 
    static void disableInterrupt( void );

    
    



 
    static void enableInterrupt( void );

    
    

 
    static void enterISR( void );

    
    

 
    static void leaveISR(void);

    
    

 
    static void enableWatchdog( MODE mode );

    
    
 
    static void disableWatchdog( void );

    
    
 
    static void feedWatchdog( void );

    
    
 
    static void reset( void );

    
    

 


    
    


 
    static void delayMicroSec( unsigned short delay );

    
    


 
    static void delayMilliSec( unsigned short delay );

  private:
    
    static unsigned char cntInterrupt;

}; 




 
extern "C" 
{
  void SystemInit(void);
}

#line 21 ".\\..\\EmbSysLib\\Src\\lib.h"
#line 1 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\MCU.h"











 






#line 31 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\MCU.h"


#line 1 "C:\\Bin\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\inttypes.h"
 
 





 

 








#line 1 "C:\\Bin\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"
 
 





 









     
#line 27 "C:\\Bin\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"
     












      namespace std {

          extern "C" {








 

     

     
typedef   signed          char int8_t;
typedef   signed short     int int16_t;
typedef   signed           int int32_t;
typedef   signed       __int64 int64_t;

     
typedef unsigned          char uint8_t;
typedef unsigned short     int uint16_t;
typedef unsigned           int uint32_t;
typedef unsigned       __int64 uint64_t;

     

     
     
typedef   signed          char int_least8_t;
typedef   signed short     int int_least16_t;
typedef   signed           int int_least32_t;
typedef   signed       __int64 int_least64_t;

     
typedef unsigned          char uint_least8_t;
typedef unsigned short     int uint_least16_t;
typedef unsigned           int uint_least32_t;
typedef unsigned       __int64 uint_least64_t;

     

     
typedef   signed           int int_fast8_t;
typedef   signed           int int_fast16_t;
typedef   signed           int int_fast32_t;
typedef   signed       __int64 int_fast64_t;

     
typedef unsigned           int uint_fast8_t;
typedef unsigned           int uint_fast16_t;
typedef unsigned           int uint_fast32_t;
typedef unsigned       __int64 uint_fast64_t;

     




typedef   signed           int intptr_t;
typedef unsigned           int uintptr_t;


     
typedef   signed     long long intmax_t;
typedef unsigned     long long uintmax_t;


#line 247 "C:\\Bin\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"

#line 266 "C:\\Bin\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"


         }   
      }   





      using ::std::int8_t;
      using ::std::int16_t;
      using ::std::int32_t;
      using ::std::int64_t;
      using ::std::uint8_t;
      using ::std::uint16_t;
      using ::std::uint32_t;
      using ::std::uint64_t;
      using ::std::int_least8_t;
      using ::std::int_least16_t;
      using ::std::int_least32_t;
      using ::std::int_least64_t;
      using ::std::uint_least8_t;
      using ::std::uint_least16_t;
      using ::std::uint_least32_t;
      using ::std::uint_least64_t;
      using ::std::int_fast8_t;
      using ::std::int_fast16_t;
      using ::std::int_fast32_t;
      using ::std::int_fast64_t;
      using ::std::uint_fast8_t;
      using ::std::uint_fast16_t;
      using ::std::uint_fast32_t;
      using ::std::uint_fast64_t;
      using ::std::intptr_t;
      using ::std::uintptr_t;
      using ::std::intmax_t;
      using ::std::uintmax_t;








 
#line 20 "C:\\Bin\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\inttypes.h"

#line 203 "C:\\Bin\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\inttypes.h"

#line 221 "C:\\Bin\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\inttypes.h"

typedef struct imaxdiv_t { intmax_t quot, rem; } imaxdiv_t;
    


extern "C" {


__declspec(__nothrow) intmax_t strtoimax(const char * __restrict  ,
                   char ** __restrict  , int  ) __attribute__((__nonnull__(1)));
     
__declspec(__nothrow) uintmax_t strtoumax(const char * __restrict  ,
                    char ** __restrict  , int  ) __attribute__((__nonnull__(1)));
     

__declspec(__nothrow) intmax_t wcstoimax(const wchar_t * __restrict  ,
                   wchar_t ** __restrict  , int  ) __attribute__((__nonnull__(1)));
__declspec(__nothrow) uintmax_t wcstoumax(const wchar_t * __restrict  ,
                    wchar_t ** __restrict  , int  ) __attribute__((__nonnull__(1)));

extern __declspec(__nothrow) __attribute__((const)) intmax_t imaxabs(intmax_t  );
   



 
extern __declspec(__nothrow) __attribute__((const)) imaxdiv_t imaxdiv(intmax_t  , intmax_t  );
   











 


}




 

#line 34 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\MCU.h"
#line 1 "C:\\Bin\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdlib.h"
 
 
 




 
 



 






   














  


 









      namespace std {

          extern "C" {





  



    typedef unsigned int size_t;    
#line 70 "C:\\Bin\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdlib.h"




#line 91 "C:\\Bin\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdlib.h"

typedef struct div_t { int quot, rem; } div_t;
    
typedef struct ldiv_t { long int quot, rem; } ldiv_t;
    

typedef struct lldiv_t { long long quot, rem; } lldiv_t;
    


#line 112 "C:\\Bin\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdlib.h"
   



 

   




 
#line 131 "C:\\Bin\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdlib.h"
   


 
extern __declspec(__nothrow) int __aeabi_MB_CUR_MAX(void);

   




 

   




 




extern __declspec(__nothrow) double atof(const char *  ) __attribute__((__nonnull__(1)));
   



 
extern __declspec(__nothrow) int atoi(const char *  ) __attribute__((__nonnull__(1)));
   



 
extern __declspec(__nothrow) long int atol(const char *  ) __attribute__((__nonnull__(1)));
   



 

extern __declspec(__nothrow) long long atoll(const char *  ) __attribute__((__nonnull__(1)));
   



 


extern __declspec(__nothrow) double strtod(const char * __restrict  , char ** __restrict  ) __attribute__((__nonnull__(1)));
   

















 

extern __declspec(__nothrow) float strtof(const char * __restrict  , char ** __restrict  ) __attribute__((__nonnull__(1)));
extern __declspec(__nothrow) long double strtold(const char * __restrict  , char ** __restrict  ) __attribute__((__nonnull__(1)));
   

 

extern __declspec(__nothrow) long int strtol(const char * __restrict  ,
                        char ** __restrict  , int  ) __attribute__((__nonnull__(1)));
   



























 
extern __declspec(__nothrow) unsigned long int strtoul(const char * __restrict  ,
                                       char ** __restrict  , int  ) __attribute__((__nonnull__(1)));
   


























 

 
extern __declspec(__nothrow) long long strtoll(const char * __restrict  ,
                                  char ** __restrict  , int  )
                          __attribute__((__nonnull__(1)));
   




 
extern __declspec(__nothrow) unsigned long long strtoull(const char * __restrict  ,
                                            char ** __restrict  , int  )
                                   __attribute__((__nonnull__(1)));
   



 

extern __declspec(__nothrow) int rand(void);
   







 
extern __declspec(__nothrow) void srand(unsigned int  );
   






 

struct _rand_state { int __x[57]; };
extern __declspec(__nothrow) int _rand_r(struct _rand_state *);
extern __declspec(__nothrow) void _srand_r(struct _rand_state *, unsigned int);
struct _ANSI_rand_state { int __x[1]; };
extern __declspec(__nothrow) int _ANSI_rand_r(struct _ANSI_rand_state *);
extern __declspec(__nothrow) void _ANSI_srand_r(struct _ANSI_rand_state *, unsigned int);
   


 

extern __declspec(__nothrow) void *calloc(size_t  , size_t  );
   



 
extern __declspec(__nothrow) void free(void *  );
   





 
extern __declspec(__nothrow) void *malloc(size_t  );
   



 
extern __declspec(__nothrow) void *realloc(void *  , size_t  );
   













 

extern __declspec(__nothrow) int posix_memalign(void **  , size_t  , size_t  );
   









 

typedef int (*__heapprt)(void *, char const *, ...);
extern __declspec(__nothrow) void __heapstats(int (*  )(void *  ,
                                           char const *  , ...),
                        void *  ) __attribute__((__nonnull__(1)));
   










 
extern __declspec(__nothrow) int __heapvalid(int (*  )(void *  ,
                                           char const *  , ...),
                       void *  , int  ) __attribute__((__nonnull__(1)));
   














 
extern __declspec(__nothrow) __declspec(__noreturn) void abort(void);
   







 

extern __declspec(__nothrow) int atexit(void (*  )(void)) __attribute__((__nonnull__(1)));
   




 




    

 
    typedef void (* __C_exitfuncptr)();
    extern "C++"
    inline int atexit(void (* __func)()) {
      return atexit((__C_exitfuncptr)__func);
    }



extern __declspec(__nothrow) __declspec(__noreturn) void exit(int  );
   












 

extern __declspec(__nothrow) __declspec(__noreturn) void _Exit(int  );
   







      

extern __declspec(__nothrow) char *getenv(const char *  ) __attribute__((__nonnull__(1)));
   









 

extern __declspec(__nothrow) int  system(const char *  );
   









 

extern  void *bsearch(const void *  , const void *  ,
              size_t  , size_t  ,
              int (*  )(const void *, const void *)) __attribute__((__nonnull__(1,2,5)));
   












 

    

 
    typedef int (* __C_compareprocptr)(const void *, const void *);
    extern "C++"
    void *bsearch(const void * __key, const void * __base,
              size_t __nmemb, size_t __size,
              int (* __compar)(const void *, const void *)) __attribute__((__nonnull__(1,2,5)));
    extern "C++"
    inline void *bsearch(const void * __key, const void * __base,
              size_t __nmemb, size_t __size,
              int (* __compar)(const void *, const void *)) {
      return bsearch(__key, __base, __nmemb, __size, (__C_compareprocptr)__compar);
    }



extern  void qsort(void *  , size_t  , size_t  ,
           int (*  )(const void *, const void *)) __attribute__((__nonnull__(1,4)));
   









 


    

     
    extern "C++"
    void qsort(void * __base, size_t __nmemb, size_t __size,
               int (* __compar)(const void *, const void *)) __attribute__((__nonnull__(1,4)));
    extern "C++"
    inline void qsort(void * __base, size_t __nmemb, size_t __size,
                      int (* __compar)(const void *, const void *)) {
      qsort(__base, __nmemb, __size, (__C_compareprocptr)__compar);
    }


extern __declspec(__nothrow) __attribute__((const)) int abs(int  );
   



 

extern __declspec(__nothrow) __attribute__((const)) div_t div(int  , int  );
   









 
extern __declspec(__nothrow) __attribute__((const)) long int labs(long int  );
   



 

   extern "C++" inline __declspec(__nothrow) __attribute__((const)) long abs(long int x) { return labs(x); }


extern __declspec(__nothrow) __attribute__((const)) ldiv_t ldiv(long int  , long int  );
   











 

   extern "C++" inline __declspec(__nothrow) __attribute__((const)) ldiv_t div(long int __numer, long int __denom) {
       return ldiv(__numer, __denom);
   }



extern __declspec(__nothrow) __attribute__((const)) long long llabs(long long  );
   



 

   extern "C++" inline __declspec(__nothrow) __attribute__((const)) long long abs(long long x) { return llabs(x); }


extern __declspec(__nothrow) __attribute__((const)) lldiv_t lldiv(long long  , long long  );
   











 

   extern "C++" inline __declspec(__nothrow) __attribute__((const)) lldiv_t div(long long __numer, long long __denom) {
       return lldiv(__numer, __denom);
   }






 
typedef struct __sdiv32by16 { int quot, rem; } __sdiv32by16;
typedef struct __udiv32by16 { unsigned int quot, rem; } __udiv32by16;
    
typedef struct __sdiv64by32 { int rem, quot; } __sdiv64by32;

__value_in_regs extern __declspec(__nothrow) __attribute__((const)) __sdiv32by16 __rt_sdiv32by16(
     int  ,
     short int  );
   

 
__value_in_regs extern __declspec(__nothrow) __attribute__((const)) __udiv32by16 __rt_udiv32by16(
     unsigned int  ,
     unsigned short  );
   

 
__value_in_regs extern __declspec(__nothrow) __attribute__((const)) __sdiv64by32 __rt_sdiv64by32(
     int  , unsigned int  ,
     int  );
   

 




 
extern __declspec(__nothrow) unsigned int __fp_status(unsigned int  , unsigned int  );
   







 























 
extern __declspec(__nothrow) int mblen(const char *  , size_t  );
   












 
extern __declspec(__nothrow) int mbtowc(wchar_t * __restrict  ,
                   const char * __restrict  , size_t  );
   















 
extern __declspec(__nothrow) int wctomb(char *  , wchar_t  );
   













 





 
extern __declspec(__nothrow) size_t mbstowcs(wchar_t * __restrict  ,
                      const char * __restrict  , size_t  ) __attribute__((__nonnull__(2)));
   














 
extern __declspec(__nothrow) size_t wcstombs(char * __restrict  ,
                      const wchar_t * __restrict  , size_t  ) __attribute__((__nonnull__(2)));
   














 

extern __declspec(__nothrow) void __use_realtime_heap(void);
extern __declspec(__nothrow) void __use_realtime_division(void);
extern __declspec(__nothrow) void __use_two_region_memory(void);
extern __declspec(__nothrow) void __use_no_heap(void);
extern __declspec(__nothrow) void __use_no_heap_region(void);

extern __declspec(__nothrow) char const *__C_library_version_string(void);
extern __declspec(__nothrow) int __C_library_version_number(void);


         }   
      }   










        using ::std::atoll;
        using ::std::lldiv_t;

      using ::std::div_t;
      using ::std::ldiv_t;
      using ::std::atof;
      using ::std::atoi;
      using ::std::atol;
      using ::std::strtod;

      using ::std::strtof;
      using ::std::strtold;

      using ::std::strtol;
      using ::std::strtoul;
      using ::std::strtoll;
      using ::std::strtoull;
      using ::std::rand;
      using ::std::srand;
      using ::std::_rand_state;
      using ::std::_rand_r;
      using ::std::_srand_r;
      using ::std::_ANSI_rand_state;
      using ::std::_ANSI_rand_r;
      using ::std::_ANSI_srand_r;
      using ::std::calloc;
      using ::std::free;
      using ::std::malloc;
      using ::std::realloc;

      using ::std::posix_memalign;

      using ::std::__heapprt;
      using ::std::__heapstats;
      using ::std::__heapvalid;
      using ::std::abort;
      using ::std::atexit;
      using ::std::exit;
      using ::std::_Exit;
      using ::std::getenv;
      using ::std::system;
      using ::std::bsearch;
      using ::std::qsort;
      using ::std::abs;
      using ::std::div;
      using ::std::labs;
      using ::std::ldiv;

        using ::std::llabs;
        using ::std::lldiv;


      using ::std::__sdiv32by16;
      using ::std::__udiv32by16;
      using ::std::__sdiv64by32;
      using ::std::__rt_sdiv32by16;
      using ::std::__rt_udiv32by16;
      using ::std::__rt_sdiv64by32;

      using ::std::__fp_status;
      using ::std::mblen;
      using ::std::mbtowc;
      using ::std::wctomb;
      using ::std::mbstowcs;
      using ::std::wcstombs;
      using ::std::__use_realtime_heap;
      using ::std::__use_realtime_division;
      using ::std::__use_two_region_memory;
      using ::std::__use_no_heap;
      using ::std::__use_no_heap_region;
      using ::std::__C_library_version_string;
      using ::std::__C_library_version_number;
      using ::std::size_t;
      using ::std::__aeabi_MB_CUR_MAX;







 
#line 35 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\MCU.h"


#line 1 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"











































 



 



 





 extern "C" {




 



 


       
       











 










 
   








 







 







 






















 
#line 152 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"



 



 




 





 
typedef enum IRQn
{
 
  NonMaskableInt_IRQn         = -14,     
  MemoryManagement_IRQn       = -12,     
  BusFault_IRQn               = -11,     
  UsageFault_IRQn             = -10,     
  SVC_IRQn                    = -5,      
  DebugMonitor_IRQn           = -4,      
  PendSV_IRQn                 = -2,      
  SysTick_IRQn                = -1,      

 
  WWDG_IRQn                   = 0,       
  PVD_IRQn                    = 1,       
  TAMPER_STAMP_IRQn           = 2,       
  RTC_WKUP_IRQn               = 3,       
  FLASH_IRQn                  = 4,       
  RCC_IRQn                    = 5,       
  EXTI0_IRQn                  = 6,       
  EXTI1_IRQn                  = 7,       
  EXTI2_IRQn                  = 8,       
  EXTI3_IRQn                  = 9,       
  EXTI4_IRQn                  = 10,      
  DMA1_Channel1_IRQn          = 11,      
  DMA1_Channel2_IRQn          = 12,      
  DMA1_Channel3_IRQn          = 13,      
  DMA1_Channel4_IRQn          = 14,      
  DMA1_Channel5_IRQn          = 15,      
  DMA1_Channel6_IRQn          = 16,      
  DMA1_Channel7_IRQn          = 17,      
  ADC1_IRQn                   = 18,      
  USB_HP_IRQn                 = 19,      
  USB_LP_IRQn                 = 20,      
  DAC_IRQn                    = 21,      
  COMP_IRQn                   = 22,      
  EXTI9_5_IRQn                = 23,      
  LCD_IRQn                    = 24,      
  TIM9_IRQn                   = 25,      
  TIM10_IRQn                  = 26,      
  TIM11_IRQn                  = 27,      
  TIM2_IRQn                   = 28,      
  TIM3_IRQn                   = 29,      
  TIM4_IRQn                   = 30,      
  I2C1_EV_IRQn                = 31,      
  I2C1_ER_IRQn                = 32,      
  I2C2_EV_IRQn                = 33,      
  I2C2_ER_IRQn                = 34,      
  SPI1_IRQn                   = 35,      
  SPI2_IRQn                   = 36,      
  USART1_IRQn                 = 37,      
  USART2_IRQn                 = 38,      
  USART3_IRQn                 = 39,      
  EXTI15_10_IRQn              = 40,      
  RTC_Alarm_IRQn              = 41,      
  USB_FS_WKUP_IRQn            = 42,      
  TIM6_IRQn                   = 43,      




#line 244 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"


  TIM7_IRQn                   = 44,      
  SDIO_IRQn                   = 45,      
  TIM5_IRQn                   = 46,      
  SPI3_IRQn                   = 47,      
  UART4_IRQn                  = 48,      
  UART5_IRQn                  = 49,      
  DMA2_Channel1_IRQn          = 50,      
  DMA2_Channel2_IRQn          = 51,      
  DMA2_Channel3_IRQn          = 52,      
  DMA2_Channel4_IRQn          = 53,      
  DMA2_Channel5_IRQn          = 54,      
  AES_IRQn                    = 55,      
  COMP_ACQ_IRQn               = 56       

} IRQn_Type;



 

#line 1 "C:\\Bin\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.0.1\\CMSIS\\Include\\core_cm3.h"
 




 
















 










#line 35 "C:\\Bin\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.0.1\\CMSIS\\Include\\core_cm3.h"


 extern "C" {














 




 



 

 









 







#line 112 "C:\\Bin\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.0.1\\CMSIS\\Include\\core_cm3.h"

#line 1 "C:\\Bin\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.0.1\\CMSIS\\Include\\cmsis_compiler.h"
 




 
















 




#line 29 "C:\\Bin\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.0.1\\CMSIS\\Include\\cmsis_compiler.h"



 
#line 1 "C:\\Bin\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.0.1\\CMSIS\\Include\\cmsis_armcc.h"
 




 
















 









 













   
   


 
#line 82 "C:\\Bin\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.0.1\\CMSIS\\Include\\cmsis_armcc.h"


 



 





 
 






 
 





 
static __inline uint32_t __get_CONTROL(void)
{
  register uint32_t __regControl         __asm("control");
  return(__regControl);
}






 
static __inline void __set_CONTROL(uint32_t control)
{
  register uint32_t __regControl         __asm("control");
  __regControl = control;
}






 
static __inline uint32_t __get_IPSR(void)
{
  register uint32_t __regIPSR          __asm("ipsr");
  return(__regIPSR);
}






 
static __inline uint32_t __get_APSR(void)
{
  register uint32_t __regAPSR          __asm("apsr");
  return(__regAPSR);
}






 
static __inline uint32_t __get_xPSR(void)
{
  register uint32_t __regXPSR          __asm("xpsr");
  return(__regXPSR);
}






 
static __inline uint32_t __get_PSP(void)
{
  register uint32_t __regProcessStackPointer  __asm("psp");
  return(__regProcessStackPointer);
}






 
static __inline void __set_PSP(uint32_t topOfProcStack)
{
  register uint32_t __regProcessStackPointer  __asm("psp");
  __regProcessStackPointer = topOfProcStack;
}






 
static __inline uint32_t __get_MSP(void)
{
  register uint32_t __regMainStackPointer     __asm("msp");
  return(__regMainStackPointer);
}






 
static __inline void __set_MSP(uint32_t topOfMainStack)
{
  register uint32_t __regMainStackPointer     __asm("msp");
  __regMainStackPointer = topOfMainStack;
}






 
static __inline uint32_t __get_PRIMASK(void)
{
  register uint32_t __regPriMask         __asm("primask");
  return(__regPriMask);
}






 
static __inline void __set_PRIMASK(uint32_t priMask)
{
  register uint32_t __regPriMask         __asm("primask");
  __regPriMask = (priMask);
}









 







 







 
static __inline uint32_t  __get_BASEPRI(void)
{
  register uint32_t __regBasePri         __asm("basepri");
  return(__regBasePri);
}






 
static __inline void __set_BASEPRI(uint32_t basePri)
{
  register uint32_t __regBasePri         __asm("basepri");
  __regBasePri = (basePri & 0xFFU);
}







 
static __inline void __set_BASEPRI_MAX(uint32_t basePri)
{
  register uint32_t __regBasePriMax      __asm("basepri_max");
  __regBasePriMax = (basePri & 0xFFU);
}






 
static __inline uint32_t __get_FAULTMASK(void)
{
  register uint32_t __regFaultMask       __asm("faultmask");
  return(__regFaultMask);
}






 
static __inline void __set_FAULTMASK(uint32_t faultMask)
{
  register uint32_t __regFaultMask       __asm("faultmask");
  __regFaultMask = (faultMask & (uint32_t)1U);
}





#line 356 "C:\\Bin\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.0.1\\CMSIS\\Include\\cmsis_armcc.h"



 


 



 




 






 







 






 








 










 










 











 








 

__attribute__((section(".rev16_text"))) static __inline __asm uint32_t __REV16(uint32_t value)
{
  rev16 r0, r0
  bx lr
}








 

__attribute__((section(".revsh_text"))) static __inline __asm int32_t __REVSH(int32_t value)
{
  revsh r0, r0
  bx lr
}









 









 








 
#line 516 "C:\\Bin\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.0.1\\CMSIS\\Include\\cmsis_armcc.h"







 











 












 












 














 














 














 










 









 









 









 

__attribute__((section(".rrx_text"))) static __inline __asm uint32_t __RRX(uint32_t value)
{
  rrx r0, r0
  bx lr
}








 








 








 








 








 








 





   


 



 

#line 794 "C:\\Bin\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.0.1\\CMSIS\\Include\\cmsis_armcc.h"
 


#line 35 "C:\\Bin\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.0.1\\CMSIS\\Include\\cmsis_compiler.h"




 
#line 220 "C:\\Bin\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.0.1\\CMSIS\\Include\\cmsis_compiler.h"




#line 114 "C:\\Bin\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.0.1\\CMSIS\\Include\\core_cm3.h"



}










 extern "C" {


 
#line 153 "C:\\Bin\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.0.1\\CMSIS\\Include\\core_cm3.h"

 






 
#line 169 "C:\\Bin\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.0.1\\CMSIS\\Include\\core_cm3.h"

 




 












 



 






 



 
typedef union
{
  struct
  {
    uint32_t _reserved0:27;               
    uint32_t Q:1;                         
    uint32_t V:1;                         
    uint32_t C:1;                         
    uint32_t Z:1;                         
    uint32_t N:1;                         
  } b;                                    
  uint32_t w;                             
} APSR_Type;

 


















 
typedef union
{
  struct
  {
    uint32_t ISR:9;                       
    uint32_t _reserved0:23;               
  } b;                                    
  uint32_t w;                             
} IPSR_Type;

 






 
typedef union
{
  struct
  {
    uint32_t ISR:9;                       
    uint32_t _reserved0:1;                
    uint32_t ICI_IT_1:6;                  
    uint32_t _reserved1:8;                
    uint32_t T:1;                         
    uint32_t ICI_IT_2:2;                  
    uint32_t Q:1;                         
    uint32_t V:1;                         
    uint32_t C:1;                         
    uint32_t Z:1;                         
    uint32_t N:1;                         
  } b;                                    
  uint32_t w;                             
} xPSR_Type;

 






























 
typedef union
{
  struct
  {
    uint32_t nPRIV:1;                     
    uint32_t SPSEL:1;                     
    uint32_t _reserved1:30;               
  } b;                                    
  uint32_t w;                             
} CONTROL_Type;

 






 







 



 
typedef struct
{
  volatile uint32_t ISER[8U];                
        uint32_t RESERVED0[24U];
  volatile uint32_t ICER[8U];                
        uint32_t RSERVED1[24U];
  volatile uint32_t ISPR[8U];                
        uint32_t RESERVED2[24U];
  volatile uint32_t ICPR[8U];                
        uint32_t RESERVED3[24U];
  volatile uint32_t IABR[8U];                
        uint32_t RESERVED4[56U];
  volatile uint8_t  IP[240U];                
        uint32_t RESERVED5[644U];
  volatile  uint32_t STIR;                    
}  NVIC_Type;

 



 







 



 
typedef struct
{
  volatile const  uint32_t CPUID;                   
  volatile uint32_t ICSR;                    
  volatile uint32_t VTOR;                    
  volatile uint32_t AIRCR;                   
  volatile uint32_t SCR;                     
  volatile uint32_t CCR;                     
  volatile uint8_t  SHP[12U];                
  volatile uint32_t SHCSR;                   
  volatile uint32_t CFSR;                    
  volatile uint32_t HFSR;                    
  volatile uint32_t DFSR;                    
  volatile uint32_t MMFAR;                   
  volatile uint32_t BFAR;                    
  volatile uint32_t AFSR;                    
  volatile const  uint32_t PFR[2U];                 
  volatile const  uint32_t DFR;                     
  volatile const  uint32_t ADR;                     
  volatile const  uint32_t MMFR[4U];                
  volatile const  uint32_t ISAR[5U];                
        uint32_t RESERVED0[5U];
  volatile uint32_t CPACR;                   
} SCB_Type;

 















 






























 




#line 455 "C:\\Bin\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.0.1\\CMSIS\\Include\\core_cm3.h"

 





















 









 


















 










































 









 















 


















 


















 









 















 







 



 
typedef struct
{
        uint32_t RESERVED0[1U];
  volatile const  uint32_t ICTR;                    

  volatile uint32_t ACTLR;                   



} SCnSCB_Type;

 



 










 







 



 
typedef struct
{
  volatile uint32_t CTRL;                    
  volatile uint32_t LOAD;                    
  volatile uint32_t VAL;                     
  volatile const  uint32_t CALIB;                   
} SysTick_Type;

 












 



 



 









 







 



 
typedef struct
{
  volatile  union
  {
    volatile  uint8_t    u8;                  
    volatile  uint16_t   u16;                 
    volatile  uint32_t   u32;                 
  }  PORT [32U];                          
        uint32_t RESERVED0[864U];
  volatile uint32_t TER;                     
        uint32_t RESERVED1[15U];
  volatile uint32_t TPR;                     
        uint32_t RESERVED2[15U];
  volatile uint32_t TCR;                     
        uint32_t RESERVED3[29U];
  volatile  uint32_t IWR;                     
  volatile const  uint32_t IRR;                     
  volatile uint32_t IMCR;                    
        uint32_t RESERVED4[43U];
  volatile  uint32_t LAR;                     
  volatile const  uint32_t LSR;                     
        uint32_t RESERVED5[6U];
  volatile const  uint32_t PID4;                    
  volatile const  uint32_t PID5;                    
  volatile const  uint32_t PID6;                    
  volatile const  uint32_t PID7;                    
  volatile const  uint32_t PID0;                    
  volatile const  uint32_t PID1;                    
  volatile const  uint32_t PID2;                    
  volatile const  uint32_t PID3;                    
  volatile const  uint32_t CID0;                    
  volatile const  uint32_t CID1;                    
  volatile const  uint32_t CID2;                    
  volatile const  uint32_t CID3;                    
} ITM_Type;

 



 



























 



 



 



 









   







 



 
typedef struct
{
  volatile uint32_t CTRL;                    
  volatile uint32_t CYCCNT;                  
  volatile uint32_t CPICNT;                  
  volatile uint32_t EXCCNT;                  
  volatile uint32_t SLEEPCNT;                
  volatile uint32_t LSUCNT;                  
  volatile uint32_t FOLDCNT;                 
  volatile const  uint32_t PCSR;                    
  volatile uint32_t COMP0;                   
  volatile uint32_t MASK0;                   
  volatile uint32_t FUNCTION0;               
        uint32_t RESERVED0[1U];
  volatile uint32_t COMP1;                   
  volatile uint32_t MASK1;                   
  volatile uint32_t FUNCTION1;               
        uint32_t RESERVED1[1U];
  volatile uint32_t COMP2;                   
  volatile uint32_t MASK2;                   
  volatile uint32_t FUNCTION2;               
        uint32_t RESERVED2[1U];
  volatile uint32_t COMP3;                   
  volatile uint32_t MASK3;                   
  volatile uint32_t FUNCTION3;               
} DWT_Type;

 






















































 



 



 



 



 



 



 



























   







 



 
typedef struct
{
  volatile uint32_t SSPSR;                   
  volatile uint32_t CSPSR;                   
        uint32_t RESERVED0[2U];
  volatile uint32_t ACPR;                    
        uint32_t RESERVED1[55U];
  volatile uint32_t SPPR;                    
        uint32_t RESERVED2[131U];
  volatile const  uint32_t FFSR;                    
  volatile uint32_t FFCR;                    
  volatile const  uint32_t FSCR;                    
        uint32_t RESERVED3[759U];
  volatile const  uint32_t TRIGGER;                 
  volatile const  uint32_t FIFO0;                   
  volatile const  uint32_t ITATBCTR2;               
        uint32_t RESERVED4[1U];
  volatile const  uint32_t ITATBCTR0;               
  volatile const  uint32_t FIFO1;                   
  volatile uint32_t ITCTRL;                  
        uint32_t RESERVED5[39U];
  volatile uint32_t CLAIMSET;                
  volatile uint32_t CLAIMCLR;                
        uint32_t RESERVED7[8U];
  volatile const  uint32_t DEVID;                   
  volatile const  uint32_t DEVTYPE;                 
} TPI_Type;

 



 



 












 






 



 





















 



 





















 



 



 


















 






   








 



 
typedef struct
{
  volatile const  uint32_t TYPE;                    
  volatile uint32_t CTRL;                    
  volatile uint32_t RNR;                     
  volatile uint32_t RBAR;                    
  volatile uint32_t RASR;                    
  volatile uint32_t RBAR_A1;                 
  volatile uint32_t RASR_A1;                 
  volatile uint32_t RBAR_A2;                 
  volatile uint32_t RASR_A2;                 
  volatile uint32_t RBAR_A3;                 
  volatile uint32_t RASR_A3;                 
} MPU_Type;

 









 









 



 









 






























 








 



 
typedef struct
{
  volatile uint32_t DHCSR;                   
  volatile  uint32_t DCRSR;                   
  volatile uint32_t DCRDR;                   
  volatile uint32_t DEMCR;                   
} CoreDebug_Type;

 




































 






 







































 







 






 







 


 







 

 
#line 1381 "C:\\Bin\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.0.1\\CMSIS\\Include\\core_cm3.h"

#line 1390 "C:\\Bin\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.0.1\\CMSIS\\Include\\core_cm3.h"






 










 


 



 





 

#line 1441 "C:\\Bin\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.0.1\\CMSIS\\Include\\core_cm3.h"

#line 1451 "C:\\Bin\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.0.1\\CMSIS\\Include\\core_cm3.h"













 
static __inline void __NVIC_SetPriorityGrouping(uint32_t PriorityGroup)
{
  uint32_t reg_value;
  uint32_t PriorityGroupTmp = (PriorityGroup & (uint32_t)0x07UL);              

  reg_value  =  ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->AIRCR;                                                    
  reg_value &= ~((uint32_t)((0xFFFFUL << 16U) | (7UL << 8U)));  
  reg_value  =  (reg_value                                   |
                ((uint32_t)0x5FAUL << 16U) |
                (PriorityGroupTmp << 8U)                      );               
  ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->AIRCR =  reg_value;
}






 
static __inline uint32_t __NVIC_GetPriorityGrouping(void)
{
  return ((uint32_t)((((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->AIRCR & (7UL << 8U)) >> 8U));
}







 
static __inline void __NVIC_EnableIRQ(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ISER[(((uint32_t)(int32_t)IRQn) >> 5UL)] = (uint32_t)(1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL));
  }
}









 
static __inline uint32_t __NVIC_GetEnableIRQ(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    return((uint32_t)(((((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ISER[(((uint32_t)(int32_t)IRQn) >> 5UL)] & (1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL))) != 0UL) ? 1UL : 0UL));
  }
  else
  {
    return(0U);
  }
}







 
static __inline void __NVIC_DisableIRQ(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ICER[(((uint32_t)(int32_t)IRQn) >> 5UL)] = (uint32_t)(1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL));
    do { __schedule_barrier(); __dsb(0xF); __schedule_barrier(); } while (0U);
    do { __schedule_barrier(); __isb(0xF); __schedule_barrier(); } while (0U);
  }
}









 
static __inline uint32_t __NVIC_GetPendingIRQ(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    return((uint32_t)(((((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ISPR[(((uint32_t)(int32_t)IRQn) >> 5UL)] & (1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL))) != 0UL) ? 1UL : 0UL));
  }
  else
  {
    return(0U);
  }
}







 
static __inline void __NVIC_SetPendingIRQ(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ISPR[(((uint32_t)(int32_t)IRQn) >> 5UL)] = (uint32_t)(1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL));
  }
}







 
static __inline void __NVIC_ClearPendingIRQ(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ICPR[(((uint32_t)(int32_t)IRQn) >> 5UL)] = (uint32_t)(1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL));
  }
}









 
static __inline uint32_t __NVIC_GetActive(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    return((uint32_t)(((((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->IABR[(((uint32_t)(int32_t)IRQn) >> 5UL)] & (1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL))) != 0UL) ? 1UL : 0UL));
  }
  else
  {
    return(0U);
  }
}










 
static __inline void __NVIC_SetPriority(IRQn_Type IRQn, uint32_t priority)
{
  if ((int32_t)(IRQn) >= 0)
  {
    ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->IP[((uint32_t)(int32_t)IRQn)]               = (uint8_t)((priority << (8U - 4)) & (uint32_t)0xFFUL);
  }
  else
  {
    ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->SHP[(((uint32_t)(int32_t)IRQn) & 0xFUL)-4UL] = (uint8_t)((priority << (8U - 4)) & (uint32_t)0xFFUL);
  }
}










 
static __inline uint32_t __NVIC_GetPriority(IRQn_Type IRQn)
{

  if ((int32_t)(IRQn) >= 0)
  {
    return(((uint32_t)((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->IP[((uint32_t)(int32_t)IRQn)]               >> (8U - 4)));
  }
  else
  {
    return(((uint32_t)((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->SHP[(((uint32_t)(int32_t)IRQn) & 0xFUL)-4UL] >> (8U - 4)));
  }
}












 
static __inline uint32_t NVIC_EncodePriority (uint32_t PriorityGroup, uint32_t PreemptPriority, uint32_t SubPriority)
{
  uint32_t PriorityGroupTmp = (PriorityGroup & (uint32_t)0x07UL);    
  uint32_t PreemptPriorityBits;
  uint32_t SubPriorityBits;

  PreemptPriorityBits = ((7UL - PriorityGroupTmp) > (uint32_t)(4)) ? (uint32_t)(4) : (uint32_t)(7UL - PriorityGroupTmp);
  SubPriorityBits     = ((PriorityGroupTmp + (uint32_t)(4)) < (uint32_t)7UL) ? (uint32_t)0UL : (uint32_t)((PriorityGroupTmp - 7UL) + (uint32_t)(4));

  return (
           ((PreemptPriority & (uint32_t)((1UL << (PreemptPriorityBits)) - 1UL)) << SubPriorityBits) |
           ((SubPriority     & (uint32_t)((1UL << (SubPriorityBits    )) - 1UL)))
         );
}












 
static __inline void NVIC_DecodePriority (uint32_t Priority, uint32_t PriorityGroup, uint32_t* const pPreemptPriority, uint32_t* const pSubPriority)
{
  uint32_t PriorityGroupTmp = (PriorityGroup & (uint32_t)0x07UL);    
  uint32_t PreemptPriorityBits;
  uint32_t SubPriorityBits;

  PreemptPriorityBits = ((7UL - PriorityGroupTmp) > (uint32_t)(4)) ? (uint32_t)(4) : (uint32_t)(7UL - PriorityGroupTmp);
  SubPriorityBits     = ((PriorityGroupTmp + (uint32_t)(4)) < (uint32_t)7UL) ? (uint32_t)0UL : (uint32_t)((PriorityGroupTmp - 7UL) + (uint32_t)(4));

  *pPreemptPriority = (Priority >> SubPriorityBits) & (uint32_t)((1UL << (PreemptPriorityBits)) - 1UL);
  *pSubPriority     = (Priority                   ) & (uint32_t)((1UL << (SubPriorityBits    )) - 1UL);
}










 
static __inline void __NVIC_SetVector(IRQn_Type IRQn, uint32_t vector)
{
  uint32_t *vectors = (uint32_t *)((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->VTOR;
  vectors[(int32_t)IRQn + 16] = vector;
}









 
static __inline uint32_t __NVIC_GetVector(IRQn_Type IRQn)
{
  uint32_t *vectors = (uint32_t *)((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->VTOR;
  return vectors[(int32_t)IRQn + 16];
}





 
static __inline void __NVIC_SystemReset(void)
{
  do { __schedule_barrier(); __dsb(0xF); __schedule_barrier(); } while (0U);                                                          
 
  ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->AIRCR  = (uint32_t)((0x5FAUL << 16U)    |
                           (((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->AIRCR & (7UL << 8U)) |
                            (1UL << 2U)    );          
  do { __schedule_barrier(); __dsb(0xF); __schedule_barrier(); } while (0U);                                                           

  for(;;)                                                            
  {
    __nop();
  }
}

 


 





 








 
static __inline uint32_t SCB_GetFPUType(void)
{
    return 0U;            
}


 



 





 













 
static __inline uint32_t SysTick_Config(uint32_t ticks)
{
  if ((ticks - 1UL) > (0xFFFFFFUL ))
  {
    return (1UL);                                                    
  }

  ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->LOAD  = (uint32_t)(ticks - 1UL);                          
  __NVIC_SetPriority (SysTick_IRQn, (1UL << 4) - 1UL);  
  ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->VAL   = 0UL;                                              
  ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->CTRL  = (1UL << 2U) |
                   (1UL << 1U)   |
                   (1UL );                          
  return (0UL);                                                      
}



 



 





 

extern volatile int32_t ITM_RxBuffer;                               










 
static __inline uint32_t ITM_SendChar (uint32_t ch)
{
  if (((((ITM_Type *) (0xE0000000UL) )->TCR & (1UL )) != 0UL) &&       
      ((((ITM_Type *) (0xE0000000UL) )->TER & 1UL               ) != 0UL)   )      
  {
    while (((ITM_Type *) (0xE0000000UL) )->PORT[0U].u32 == 0UL)
    {
      __nop();
    }
    ((ITM_Type *) (0xE0000000UL) )->PORT[0U].u8 = (uint8_t)ch;
  }
  return (ch);
}







 
static __inline int32_t ITM_ReceiveChar (void)
{
  int32_t ch = -1;                            

  if (ITM_RxBuffer != ((int32_t)0x5AA55AA5U))
  {
    ch = ITM_RxBuffer;
    ITM_RxBuffer = ((int32_t)0x5AA55AA5U);        
  }

  return (ch);
}







 
static __inline int32_t ITM_CheckChar (void)
{

  if (ITM_RxBuffer == ((int32_t)0x5AA55AA5U))
  {
    return (0);                               
  }
  else
  {
    return (1);                               
  }
}

 





}




#line 267 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"
#line 1 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/system_stm32l1xx.h"

























 



 



   
  


 




 extern "C" {




 



 




 

extern uint32_t SystemCoreClock;           



 



 



 



 



 



 
  
extern void SystemInit(void);
extern void SystemCoreClockUpdate(void);


 


}






 
  


   
 
#line 268 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"
#line 269 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"



 

typedef enum {RESET = 0, SET = !RESET} FlagStatus, ITStatus;

typedef enum {DISABLE = 0, ENABLE = !DISABLE} FunctionalState;


typedef enum {ERROR = 0, SUCCESS = !ERROR} ErrorStatus;



 









 


#line 320 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"



 



 



 

typedef struct
{
  volatile uint32_t SR;            
  volatile uint32_t CR1;           
  volatile uint32_t CR2;           
  volatile uint32_t SMPR1;         
  volatile uint32_t SMPR2;         
  volatile uint32_t SMPR3;         
  volatile uint32_t JOFR1;         
  volatile uint32_t JOFR2;         
  volatile uint32_t JOFR3;         
  volatile uint32_t JOFR4;         
  volatile uint32_t HTR;           
  volatile uint32_t LTR;           
  volatile uint32_t SQR1;          
  volatile uint32_t SQR2;          
  volatile uint32_t SQR3;          
  volatile uint32_t SQR4;          
  volatile uint32_t SQR5;          
  volatile uint32_t JSQR;          
  volatile uint32_t JDR1;          
  volatile uint32_t JDR2;          
  volatile uint32_t JDR3;          
  volatile uint32_t JDR4;          
  volatile uint32_t DR;            
  volatile uint32_t SMPR0;         
} ADC_TypeDef;

typedef struct
{
  volatile uint32_t CSR;           
  volatile uint32_t CCR;           
} ADC_Common_TypeDef;




 

typedef struct
{
  volatile uint32_t CR;            
  volatile uint32_t SR;            
  volatile uint32_t DINR;          
  volatile uint32_t DOUTR;         
  volatile uint32_t KEYR0;         
  volatile uint32_t KEYR1;         
  volatile uint32_t KEYR2;         
  volatile uint32_t KEYR3;         
  volatile uint32_t IVR0;          
  volatile uint32_t IVR1;          
  volatile uint32_t IVR2;          
  volatile uint32_t IVR3;          
} AES_TypeDef;



 

typedef struct
{
  volatile uint32_t CSR;           
} COMP_TypeDef;



 

typedef struct
{
  volatile uint32_t DR;            
  volatile uint8_t  IDR;           
  uint8_t   RESERVED0;         
  uint16_t  RESERVED1;         
  volatile uint32_t CR;            
} CRC_TypeDef;



 

typedef struct
{
  volatile uint32_t CR;            
  volatile uint32_t SWTRIGR;       
  volatile uint32_t DHR12R1;       
  volatile uint32_t DHR12L1;       
  volatile uint32_t DHR8R1;        
  volatile uint32_t DHR12R2;       
  volatile uint32_t DHR12L2;       
  volatile uint32_t DHR8R2;        
  volatile uint32_t DHR12RD;       
  volatile uint32_t DHR12LD;       
  volatile uint32_t DHR8RD;        
  volatile uint32_t DOR1;          
  volatile uint32_t DOR2;          
  volatile uint32_t SR;            
} DAC_TypeDef;



 

typedef struct
{
  volatile uint32_t IDCODE;        
  volatile uint32_t CR;            
  volatile uint32_t APB1FZ;        
  volatile uint32_t APB2FZ;        
}DBGMCU_TypeDef;



 

typedef struct
{
  volatile uint32_t CCR;           
  volatile uint32_t CNDTR;         
  volatile uint32_t CPAR;          
  volatile uint32_t CMAR;          
} DMA_Channel_TypeDef;

typedef struct
{
  volatile uint32_t ISR;           
  volatile uint32_t IFCR;          
} DMA_TypeDef;



 

typedef struct
{
  volatile uint32_t IMR;           
  volatile uint32_t EMR;           
  volatile uint32_t RTSR;          
  volatile uint32_t FTSR;          
  volatile uint32_t SWIER;         
  volatile uint32_t PR;            
} EXTI_TypeDef;



 

typedef struct
{
  volatile uint32_t ACR;           
  volatile uint32_t PECR;          
  volatile uint32_t PDKEYR;        
  volatile uint32_t PEKEYR;        
  volatile uint32_t PRGKEYR;       
  volatile uint32_t OPTKEYR;       
  volatile uint32_t SR;            
  volatile uint32_t OBR;           
  volatile uint32_t WRPR;          
  uint32_t   RESERVED[23];     
  volatile uint32_t WRPR1;         
  volatile uint32_t WRPR2;         
} FLASH_TypeDef;



 

typedef struct
{
  volatile uint32_t RDP;                
  volatile uint32_t USER;               
  volatile uint32_t WRP01;              
  volatile uint32_t WRP23;              
  volatile uint32_t WRP45;              
  volatile uint32_t WRP67;              
  volatile uint32_t WRP89;              
  volatile uint32_t WRP1011;            
} OB_TypeDef;



 

typedef struct
{
  volatile uint32_t CSR;           
  volatile uint32_t OTR;           
  volatile uint32_t LPOTR;         
} OPAMP_TypeDef;



 

typedef struct
{
  volatile uint32_t BTCR[8];       
} FSMC_Bank1_TypeDef;



 

typedef struct
{
  volatile uint32_t BWTR[7];       
} FSMC_Bank1E_TypeDef;



 

typedef struct
{
  volatile uint32_t MODER;         
  volatile uint16_t OTYPER;        
  uint16_t RESERVED0;          
  volatile uint32_t OSPEEDR;       
  volatile uint32_t PUPDR;         
  volatile uint16_t IDR;           
  uint16_t RESERVED1;          
  volatile uint16_t ODR;           
  uint16_t RESERVED2;          
  volatile uint16_t BSRRL;         
  volatile uint16_t BSRRH;         
  volatile uint32_t LCKR;          
  volatile uint32_t AFR[2];        
  volatile uint16_t BRR;           
  uint16_t RESERVED3;          
} GPIO_TypeDef;



 

typedef struct
{
  volatile uint32_t MEMRMP;        
  volatile uint32_t PMC;           
  volatile uint32_t EXTICR[4];     
} SYSCFG_TypeDef;



 

typedef struct
{
  volatile uint16_t CR1;           
  uint16_t  RESERVED0;         
  volatile uint16_t CR2;           
  uint16_t  RESERVED1;         
  volatile uint16_t OAR1;          
  uint16_t  RESERVED2;         
  volatile uint16_t OAR2;          
  uint16_t  RESERVED3;         
  volatile uint16_t DR;            
  uint16_t  RESERVED4;         
  volatile uint16_t SR1;           
  uint16_t  RESERVED5;         
  volatile uint16_t SR2;           
  uint16_t  RESERVED6;         
  volatile uint16_t CCR;           
  uint16_t  RESERVED7;         
  volatile uint16_t TRISE;         
  uint16_t  RESERVED8;         
} I2C_TypeDef;



 

typedef struct
{
  volatile uint32_t KR;            
  volatile uint32_t PR;            
  volatile uint32_t RLR;           
  volatile uint32_t SR;            
} IWDG_TypeDef;




 

typedef struct
{
  volatile uint32_t CR;         
  volatile uint32_t FCR;        
  volatile uint32_t SR;         
  volatile uint32_t CLR;        
  uint32_t RESERVED;        
  volatile uint32_t RAM[16];    
} LCD_TypeDef;



 

typedef struct
{
  volatile uint32_t CR;    
  volatile uint32_t CSR;   
} PWR_TypeDef;



 

typedef struct
{
  volatile uint32_t CR;             
  volatile uint32_t ICSCR;          
  volatile uint32_t CFGR;           
  volatile uint32_t CIR;            
  volatile uint32_t AHBRSTR;        
  volatile uint32_t APB2RSTR;       
  volatile uint32_t APB1RSTR;       
  volatile uint32_t AHBENR;         
  volatile uint32_t APB2ENR;        
  volatile uint32_t APB1ENR;        
  volatile uint32_t AHBLPENR;       
  volatile uint32_t APB2LPENR;      
  volatile uint32_t APB1LPENR;      
  volatile uint32_t CSR;            
} RCC_TypeDef;



 

typedef struct
{
  volatile uint32_t ICR;        
  volatile uint32_t ASCR1;      
  volatile uint32_t ASCR2;      
  volatile uint32_t HYSCR1;      
  volatile uint32_t HYSCR2;      
  volatile uint32_t HYSCR3;      
  volatile uint32_t HYSCR4;      
} RI_TypeDef;



 

typedef struct
{
  volatile uint32_t TR;          
  volatile uint32_t DR;          
  volatile uint32_t CR;          
  volatile uint32_t ISR;         
  volatile uint32_t PRER;        
  volatile uint32_t WUTR;        
  volatile uint32_t CALIBR;      
  volatile uint32_t ALRMAR;      
  volatile uint32_t ALRMBR;      
  volatile uint32_t WPR;         
  volatile uint32_t SSR;         
  volatile uint32_t SHIFTR;      
  volatile uint32_t TSTR;        
  volatile uint32_t TSDR;        
  volatile uint32_t TSSSR;       
  volatile uint32_t CALR;        
  volatile uint32_t TAFCR;       
  volatile uint32_t ALRMASSR;    
  volatile uint32_t ALRMBSSR;    
  uint32_t RESERVED7;        
  volatile uint32_t BKP0R;       
  volatile uint32_t BKP1R;       
  volatile uint32_t BKP2R;       
  volatile uint32_t BKP3R;       
  volatile uint32_t BKP4R;       
  volatile uint32_t BKP5R;       
  volatile uint32_t BKP6R;       
  volatile uint32_t BKP7R;       
  volatile uint32_t BKP8R;       
  volatile uint32_t BKP9R;       
  volatile uint32_t BKP10R;      
  volatile uint32_t BKP11R;      
  volatile uint32_t BKP12R;      
  volatile uint32_t BKP13R;      
  volatile uint32_t BKP14R;      
  volatile uint32_t BKP15R;      
  volatile uint32_t BKP16R;      
  volatile uint32_t BKP17R;      
  volatile uint32_t BKP18R;      
  volatile uint32_t BKP19R;      
  volatile uint32_t BKP20R;      
  volatile uint32_t BKP21R;      
  volatile uint32_t BKP22R;      
  volatile uint32_t BKP23R;      
  volatile uint32_t BKP24R;      
  volatile uint32_t BKP25R;      
  volatile uint32_t BKP26R;      
  volatile uint32_t BKP27R;      
  volatile uint32_t BKP28R;      
  volatile uint32_t BKP29R;      
  volatile uint32_t BKP30R;      
  volatile uint32_t BKP31R;      
} RTC_TypeDef;



 

typedef struct
{
  volatile uint32_t POWER;           
  volatile uint32_t CLKCR;           
  volatile uint32_t ARG;             
  volatile uint32_t CMD;             
  volatile uint32_t  RESPCMD;         
  volatile uint32_t  RESP1;           
  volatile uint32_t  RESP2;           
  volatile uint32_t  RESP3;           
  volatile uint32_t  RESP4;           
  volatile uint32_t DTIMER;          
  volatile uint32_t DLEN;            
  volatile uint32_t DCTRL;           
  volatile uint32_t  DCOUNT;          
  volatile uint32_t  STA;             
  volatile uint32_t ICR;             
  volatile uint32_t MASK;            
  uint32_t      RESERVED0[2];    
  volatile uint32_t  FIFOCNT;         
  uint32_t      RESERVED1[13];   
  volatile uint32_t FIFO;            
} SDIO_TypeDef;



 

typedef struct
{
  volatile uint16_t CR1;         
  uint16_t      RESERVED0;   
  volatile uint16_t CR2;         
  uint16_t      RESERVED1;   
  volatile uint16_t SR;          
  uint16_t      RESERVED2;   
  volatile uint16_t DR;          
  uint16_t      RESERVED3;   
  volatile uint16_t CRCPR;       
  uint16_t      RESERVED4;   
  volatile uint16_t RXCRCR;      
  uint16_t      RESERVED5;   
  volatile uint16_t TXCRCR;      
  uint16_t      RESERVED6;   
  volatile uint16_t I2SCFGR;     
  uint16_t      RESERVED7;   
  volatile uint16_t I2SPR;       
  uint16_t      RESERVED8;   
} SPI_TypeDef;



 

typedef struct
{
  volatile uint16_t CR1;           
  uint16_t      RESERVED0;     
  volatile uint16_t CR2;           
  uint16_t      RESERVED1;     
  volatile uint16_t SMCR;          
  uint16_t      RESERVED2;     
  volatile uint16_t DIER;          
  uint16_t      RESERVED3;     
  volatile uint16_t SR;            
  uint16_t      RESERVED4;     
  volatile uint16_t EGR;           
  uint16_t      RESERVED5;     
  volatile uint16_t CCMR1;         
  uint16_t      RESERVED6;     
  volatile uint16_t CCMR2;         
  uint16_t      RESERVED7;     
  volatile uint16_t CCER;          
  uint16_t      RESERVED8;     
  volatile uint32_t CNT;           
  volatile uint16_t PSC;           
  uint16_t      RESERVED10;    
  volatile uint32_t ARR;           
  uint32_t      RESERVED12;    
  volatile uint32_t CCR1;          
  volatile uint32_t CCR2;          
  volatile uint32_t CCR3;          
  volatile uint32_t CCR4;          
  uint32_t      RESERVED17;    
  volatile uint16_t DCR;           
  uint16_t      RESERVED18;    
  volatile uint16_t DMAR;          
  uint16_t      RESERVED19;    
  volatile uint16_t OR;            
  uint16_t      RESERVED20;    
} TIM_TypeDef;



 

typedef struct
{
  volatile uint16_t SR;          
  uint16_t      RESERVED0;   
  volatile uint16_t DR;          
  uint16_t      RESERVED1;   
  volatile uint16_t BRR;         
  uint16_t      RESERVED2;   
  volatile uint16_t CR1;         
  uint16_t      RESERVED3;   
  volatile uint16_t CR2;         
  uint16_t      RESERVED4;   
  volatile uint16_t CR3;         
  uint16_t      RESERVED5;   
  volatile uint16_t GTPR;        
  uint16_t      RESERVED6;   
} USART_TypeDef;



 

typedef struct
{
  volatile uint32_t CR;    
  volatile uint32_t CFR;   
  volatile uint32_t SR;    
} WWDG_TypeDef;



 



 










 




#line 909 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

#line 920 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

#line 931 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"





#line 944 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

#line 951 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"










 



 

#line 992 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

#line 1009 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

#line 1016 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"




#line 1028 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"













 



 



 

 
 
 
 
 
 
 
 

 
#line 1070 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 
#line 1078 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

#line 1087 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"


















 






































 


















































 


















































 


















































 


 


 


 


 


 


 






#line 1328 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

#line 1335 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

#line 1342 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

#line 1349 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 
#line 1357 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

#line 1364 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

#line 1371 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

#line 1378 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

#line 1385 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

#line 1392 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 
#line 1400 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

#line 1407 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

#line 1414 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

#line 1421 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

#line 1428 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

#line 1435 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 
#line 1443 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

#line 1450 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

#line 1457 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

#line 1464 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

#line 1471 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

#line 1478 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 
#line 1486 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

#line 1493 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

#line 1500 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

#line 1507 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

#line 1514 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

#line 1521 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"


 
#line 1530 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

#line 1537 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

#line 1544 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

#line 1551 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"





 


 


 


 


 


 










 
#line 1590 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 





 
 
 
 
 
 













#line 1622 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 




 


 


 


 


 


 


 


 


 


 


 
 
 
 
 

 

































 
 
 
 
 
 
#line 1736 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 





 




 
 
 
 
 

 


 


 


 
 
 
 
 

 










































 



 


 


 


 


 


 


 



 



 



 


 


 



 
 
 
 
 

 


#line 1882 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 









 

#line 1906 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 





 
 
 
 
 

 
#line 1948 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 
#line 1978 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 
#line 1988 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"















 
#line 2012 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"















 
#line 2036 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"















 
#line 2060 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"















 
#line 2084 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"















 
#line 2108 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"















 
#line 2132 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"















 


 


 


 


 


 


 


 


 


 



 


 


 



 


 


 


 



 


 


 


 


 
 
 
 
 

 
#line 2244 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 
#line 2270 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 
#line 2296 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 
#line 2322 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 
#line 2348 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 
#line 2374 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 
 
 
 
 
 

 






 
#line 2402 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 


 


 


 


 











 
#line 2435 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 


 


 

 
 
 
 
 
 











#line 2471 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 











#line 2494 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 











#line 2517 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 











#line 2540 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 








































 








































 








































 








































 


































 


































 


































 


































 
 
 
 
 
 
#line 2899 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 
#line 2917 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 
#line 2967 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 
#line 3017 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 
#line 3035 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"
 
#line 3052 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 
#line 3070 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"
 
#line 3087 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 
#line 3121 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 
#line 3140 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 
#line 3150 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 
#line 3160 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 
 
 
 
 

 
#line 3182 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 
#line 3191 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"







 



#line 3212 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"



 



 


 
#line 3237 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 
#line 3247 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 




 


 
 
 
 
 

 


 





 


 



 
 
 
 
 

 














 































 
#line 3338 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 



 


 
 
 
 
 

 











 
#line 3373 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"










 
#line 3390 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"





 
 
 
 
 
 


















 



#line 3433 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 




 









 











 
#line 3471 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"






 











 






 












 
#line 3519 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 





 











 
#line 3547 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"






 






 
#line 3569 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

#line 3577 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

#line 3586 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"


 
#line 3603 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 
#line 3613 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 
#line 3635 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 
#line 3652 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"


 
#line 3663 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"


 
#line 3686 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 
#line 3705 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 
#line 3715 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 
#line 3737 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 













 








#line 3769 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"


 
 
 
 
 
 
#line 3804 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 
#line 3834 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 
#line 3862 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 
#line 3881 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 



 


 



 
#line 3934 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 
#line 3976 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 


 


 



 
#line 4015 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 
#line 4035 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 


 
#line 4053 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 
#line 4075 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 
#line 4083 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 
#line 4091 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 
 
 
 
 

 




 












 


 






#line 4229 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 


 


 


 


 


 


 


 


 
















 


 
#line 4299 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 
#line 4314 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 
#line 4340 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 


 


 
 
 
 
 

 









#line 4373 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 
#line 4382 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 
#line 4392 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 


 


 


 


 





















 




 
 
 
 
 
 
#line 4444 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 


 







 
#line 4465 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"



 
#line 4477 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"



 
#line 4489 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"



 
#line 4500 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 







 
#line 4517 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"



 
#line 4528 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"



 
#line 4539 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"



 
#line 4550 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 







 
#line 4567 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"



 
#line 4578 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"



 
#line 4589 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"



 
#line 4600 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 







 
#line 4617 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"



 
#line 4628 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"



 
#line 4639 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"



 
#line 4650 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 
 
 
 
 

 

































 
#line 4724 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 
#line 4753 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 
#line 4772 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

#line 4790 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 
#line 4809 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

#line 4827 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 
#line 4846 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

#line 4864 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 
#line 4883 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 
 
 
 
 

 
















 









 



























 
#line 4958 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 
#line 4970 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 
#line 4978 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 




























 





















 




























 





















 
#line 5094 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 


 


 


 


 


 


 


 
#line 5123 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

#line 5130 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 


 




 
 
 
 
 

 
#line 5156 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 


 



 
#line 5180 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 
#line 5189 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"







 
#line 5209 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 
#line 5220 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"



 
 
 
 
 

 
 























 























 























 























 























 























 























 























 
 
#line 5437 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 
#line 5449 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 






 
#line 5466 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"



 


 
 


 


 


 


 


 


 


 


 

 


 


 


 


 


 


 


 


 

 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 

 


 


 


 


 


 


 


 


 

 


#line 5610 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"



 


#line 5622 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"



 


#line 5634 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"



 


#line 5646 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"



 


#line 5658 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"



 


#line 5670 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"



 


#line 5682 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"



 


#line 5694 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"



 

 


#line 5708 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"



 


#line 5720 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"



 


#line 5732 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"



 


#line 5744 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"



 


#line 5756 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"



 


#line 5768 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"



 


#line 5780 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"



 


#line 5792 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"



 


#line 5804 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"



 


#line 5816 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"



 


#line 5828 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"



 


#line 5840 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"



 


#line 5852 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"



 


#line 5864 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"



 


#line 5876 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"



 


#line 5888 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"



 
 
 
 
 

 
#line 5906 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"



 
#line 5918 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"







 


 
 
 
 
 

 





 


 


 




 
 
 
 
 

 
#line 5991 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 
#line 6026 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 
#line 6061 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 
#line 6096 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 
#line 6131 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 





 





 





 





 





 





 





 





 






 
#line 6198 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 



 









 
#line 6222 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"




 




 
#line 6238 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 





 
#line 6260 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 
 





 
#line 6275 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"
 
#line 6282 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/STM32L1xx.h"

 




 






 


 


 



 

 

 







 

















 


}






 

  

 

 
#line 38 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\MCU.h"









#line 53 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\MCU.h"


typedef uint8_t    BYTE;
typedef uint16_t   WORD;
typedef uint32_t   DWORD;
typedef uint32_t   MTYPE;


inline void* operator new[]    ( unsigned int  x ) { return malloc(x); }
inline void* operator new      ( unsigned int  x ) { return malloc(x); }
inline void  operator delete[] ( void         *x ) { if(x) free(x);    }
inline void  operator delete   ( void         *x ) { if(x) free(x);    }







#line 1 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/PinConfig.h"







 

















 
class cHwPinConfig
{
  public:
    
    
 
    typedef enum
    {
      
      INPUT          = 0x0000, 
      OUTPUT         = 0x0001, 
      ALTERNATE_FUNC = 0x0002, 
      ANALOG         = 0x0003, 
      
      
      PUSH_PULL      = 0x0000, 
      OPEN_DRAIN     = 0x0010, 
      
      
      NO_PUPD        = 0x0000, 
      PULL_UP        = 0x0100, 
      PULL_DOWN      = 0x0200, 

      
      LOW_SPEED      = 0x0000, 
      MEDIUM_SPEED   = 0x1000, 
      FAST_SPEED     = 0x2000, 
      HIGH_SPEED     = 0x3000  
      
    } MODE;

    
    typedef enum
    {
          ADC12_IN0 = 1,
          ADC12_IN1,
          ADC12_IN10,
          ADC12_IN11,
          ADC12_IN12,
          ADC12_IN13,
          ADC12_IN14,
          ADC12_IN15,
          ADC12_IN2,
          ADC12_IN3,
          ADC12_IN4,
          ADC12_IN5,
          ADC12_IN6,
          ADC12_IN7,
          ADC12_IN8,
          ADC12_IN9,
          DAC_OUT1,
          DAC_OUT2,
          I2C1_SCL,
          I2C1_SDA,
          I2C1_SMBAl,
          I2C2_SCL,
          I2C2_SDA,
          I2C2_SMBAl,
          I2S2_CK,
          I2S2_MCK,
          I2S2_SD,
          I2S2_WS,
          I2S3_CK,
          I2S3_MCK,
          I2S3_SD,
          I2S3_WS,
          SPI_MOSI,
          SPI1_MISO,
          SPI1_MOSI,
          SPI1_NSS,
          SPI1_SCK,
          SPI2_MISO,
          SPI2_MOSI,
          SPI2_NSS,
          SPI2_SCK,
          SPI3_MISO,
          SPI3_MOSI,
          SPI3_NSS,
          SPI3_SCK,
          TIM10_CH1,
          TIM11_CH1,
          TIM2_CH1_ETR,
          TIM2_CH2,
          TIM2_CH3,
          TIM2_CH4,
          TIM3_CH1,
          TIM3_CH2,
          TIM3_CH3,
          TIM3_CH4,
          TIM3_ETR,
          TIM4_CH1,
          TIM4_CH2,
          TIM4_CH3,
          TIM4_CH4,
          TIM9_CH1,
          TIM9_CH2,
          USART1_CK,
          USART1_CTS,
          USART1_RTS,
          USART1_RX,
          USART1_TX,
          USART2_CK,
          USART2_CTS,
          USART2_RTS,
          USART2_RX,
          USART2_TX,
          USART3_CK,
          USART3_CTS,
          USART3_RTS,
          USART3_RX,
          USART3_TX,
          USBDM,
          USBDP,
    } Function;

    
    



 
    typedef enum
    {
          ADC12_IN0_PA_0     = (ADC12_IN0   <<16)|(0<<12)|( 0<<4)|( 0<<0),  
          ADC12_IN1_PA_1     = (ADC12_IN1   <<16)|(0<<12)|( 1<<4)|( 0<<0),  
          ADC12_IN10_PC_0    = (ADC12_IN10  <<16)|(2<<12)|( 0<<4)|( 0<<0),  
          ADC12_IN11_PC_1    = (ADC12_IN11  <<16)|(2<<12)|( 1<<4)|( 0<<0),  
          ADC12_IN12_PC_2    = (ADC12_IN12  <<16)|(2<<12)|( 2<<4)|( 0<<0),  
          ADC12_IN13_PC_3    = (ADC12_IN13  <<16)|(2<<12)|( 3<<4)|( 0<<0),  
          ADC12_IN14_PC_4    = (ADC12_IN14  <<16)|(2<<12)|( 4<<4)|( 0<<0),  
          ADC12_IN15_PC_5    = (ADC12_IN15  <<16)|(2<<12)|( 5<<4)|( 0<<0),  
          ADC12_IN2_PA_2     = (ADC12_IN2   <<16)|(0<<12)|( 2<<4)|( 0<<0),  
          ADC12_IN3_PA_3     = (ADC12_IN3   <<16)|(0<<12)|( 3<<4)|( 0<<0),  
          ADC12_IN4_PA_4     = (ADC12_IN4   <<16)|(0<<12)|( 4<<4)|( 0<<0),  
          ADC12_IN5_PA_5     = (ADC12_IN5   <<16)|(0<<12)|( 5<<4)|( 0<<0),  
          ADC12_IN6_PA_6     = (ADC12_IN6   <<16)|(0<<12)|( 6<<4)|( 0<<0),  
          ADC12_IN7_PA_7     = (ADC12_IN7   <<16)|(0<<12)|( 7<<4)|( 0<<0),  
          ADC12_IN8_PB_0     = (ADC12_IN8   <<16)|(1<<12)|( 0<<4)|( 0<<0),  
          ADC12_IN9_PB_1     = (ADC12_IN9   <<16)|(1<<12)|( 1<<4)|( 0<<0),  
          DAC_OUT1_PA_4      = (DAC_OUT1    <<16)|(0<<12)|( 4<<4)|( 0<<0),  
          DAC_OUT2_PA_5      = (DAC_OUT2    <<16)|(0<<12)|( 5<<4)|( 0<<0),  
          I2C1_SCL_PB_6      = (I2C1_SCL    <<16)|(1<<12)|( 6<<4)|( 4<<0),  
          I2C1_SCL_PB_8      = (I2C1_SCL    <<16)|(1<<12)|( 8<<4)|( 4<<0),  
          I2C1_SDA_PB_7      = (I2C1_SDA    <<16)|(1<<12)|( 7<<4)|( 4<<0),  
          I2C1_SDA_PB_9      = (I2C1_SDA    <<16)|(1<<12)|( 9<<4)|( 4<<0),  
          I2C1_SMBAl_PB_5    = (I2C1_SMBAl  <<16)|(1<<12)|( 5<<4)|( 4<<0),  
          I2C2_SCL_PB_10     = (I2C2_SCL    <<16)|(1<<12)|(10<<4)|( 4<<0),  
          I2C2_SDA_PB_11     = (I2C2_SDA    <<16)|(1<<12)|(11<<4)|( 4<<0),  
          I2C2_SMBAl_PB_12   = (I2C2_SMBAl  <<16)|(1<<12)|(12<<4)|( 4<<0),  
          I2S2_CK_PB_13      = (I2S2_CK     <<16)|(1<<12)|(13<<4)|( 5<<0),  
          I2S2_MCK_PC_6      = (I2S2_MCK    <<16)|(2<<12)|( 6<<4)|( 5<<0),  
          I2S2_SD_PB_15      = (I2S2_SD     <<16)|(1<<12)|(15<<4)|( 5<<0),  
          I2S2_WS_PB_12      = (I2S2_WS     <<16)|(1<<12)|(12<<4)|( 5<<0),  
          I2S3_CK_PB_3       = (I2S3_CK     <<16)|(1<<12)|( 3<<4)|( 6<<0),  
          I2S3_CK_PC_10      = (I2S3_CK     <<16)|(2<<12)|(10<<4)|( 6<<0),  
          I2S3_MCK_PC_7      = (I2S3_MCK    <<16)|(2<<12)|( 7<<4)|( 6<<0),  
          I2S3_SD_PB_5       = (I2S3_SD     <<16)|(1<<12)|( 5<<4)|( 6<<0),  
          I2S3_SD_PC_12      = (I2S3_SD     <<16)|(2<<12)|(12<<4)|( 6<<0),  
          I2S3_WS_PA_4       = (I2S3_WS     <<16)|(0<<12)|( 4<<4)|( 6<<0),  
          I2S3_WS_PA_15      = (I2S3_WS     <<16)|(0<<12)|(15<<4)|( 6<<0),  
          SPI_MOSI_PA_12     = (SPI_MOSI    <<16)|(0<<12)|(12<<4)|( 5<<0),  
          SPI1_MISO_PA_6     = (SPI1_MISO   <<16)|(0<<12)|( 6<<4)|( 5<<0),  
          SPI1_MISO_PA_11    = (SPI1_MISO   <<16)|(0<<12)|(11<<4)|( 5<<0),  
          SPI1_MISO_PB_4     = (SPI1_MISO   <<16)|(1<<12)|( 4<<4)|( 5<<0),  
          SPI1_MOSI_PA_7     = (SPI1_MOSI   <<16)|(0<<12)|( 7<<4)|( 5<<0),  
          SPI1_MOSI_PB_5     = (SPI1_MOSI   <<16)|(1<<12)|( 5<<4)|( 5<<0),  
          SPI1_NSS_PA_4      = (SPI1_NSS    <<16)|(0<<12)|( 4<<4)|( 5<<0),  
          SPI1_NSS_PA_15     = (SPI1_NSS    <<16)|(0<<12)|(15<<4)|( 5<<0),  
          SPI1_SCK_PA_5      = (SPI1_SCK    <<16)|(0<<12)|( 5<<4)|( 5<<0),  
          SPI1_SCK_PB_3      = (SPI1_SCK    <<16)|(1<<12)|( 3<<4)|( 5<<0),  
          SPI2_MISO_PB_14    = (SPI2_MISO   <<16)|(1<<12)|(14<<4)|( 5<<0),  
          SPI2_MOSI_PB_15    = (SPI2_MOSI   <<16)|(1<<12)|(15<<4)|( 5<<0),  
          SPI2_NSS_PB_12     = (SPI2_NSS    <<16)|(1<<12)|(12<<4)|( 5<<0),  
          SPI2_SCK_PB_13     = (SPI2_SCK    <<16)|(1<<12)|(13<<4)|( 5<<0),  
          SPI3_MISO_PB_4     = (SPI3_MISO   <<16)|(1<<12)|( 4<<4)|( 6<<0),  
          SPI3_MISO_PC_11    = (SPI3_MISO   <<16)|(2<<12)|(11<<4)|( 6<<0),  
          SPI3_MOSI_PB_5     = (SPI3_MOSI   <<16)|(1<<12)|( 5<<4)|( 6<<0),  
          SPI3_MOSI_PC_12    = (SPI3_MOSI   <<16)|(2<<12)|(12<<4)|( 6<<0),  
          SPI3_NSS_PA_4      = (SPI3_NSS    <<16)|(0<<12)|( 4<<4)|( 6<<0),  
          SPI3_NSS_PA_15     = (SPI3_NSS    <<16)|(0<<12)|(15<<4)|( 6<<0),  
          SPI3_SCK_PB_3      = (SPI3_SCK    <<16)|(1<<12)|( 3<<4)|( 6<<0),  
          SPI3_SCK_PC_10     = (SPI3_SCK    <<16)|(2<<12)|(10<<4)|( 6<<0),  
          TIM10_CH1_PA_6     = (TIM10_CH1   <<16)|(0<<12)|( 6<<4)|( 3<<0),  
          TIM10_CH1_PB_8     = (TIM10_CH1   <<16)|(1<<12)|( 8<<4)|( 3<<0),  
          TIM10_CH1_PB_12    = (TIM10_CH1   <<16)|(1<<12)|(12<<4)|( 3<<0),  
          TIM11_CH1_PA_7     = (TIM11_CH1   <<16)|(0<<12)|( 7<<4)|( 3<<0),  
          TIM11_CH1_PB_9     = (TIM11_CH1   <<16)|(1<<12)|( 9<<4)|( 3<<0),  
          TIM11_CH1_PB_15    = (TIM11_CH1   <<16)|(1<<12)|(15<<4)|( 3<<0),  
          TIM2_CH1_ETR_PA_0  = (TIM2_CH1_ETR<<16)|(0<<12)|( 0<<4)|( 1<<0),  
          TIM2_CH1_ETR_PA_5  = (TIM2_CH1_ETR<<16)|(0<<12)|( 5<<4)|( 1<<0),  
          TIM2_CH1_ETR_PA_15 = (TIM2_CH1_ETR<<16)|(0<<12)|(15<<4)|( 1<<0),  
          TIM2_CH2_PA_1      = (TIM2_CH2    <<16)|(0<<12)|( 1<<4)|( 1<<0),  
          TIM2_CH2_PB_3      = (TIM2_CH2    <<16)|(1<<12)|( 3<<4)|( 1<<0),  
          TIM2_CH3_PA_2      = (TIM2_CH3    <<16)|(0<<12)|( 2<<4)|( 1<<0),  
          TIM2_CH3_PB_10     = (TIM2_CH3    <<16)|(1<<12)|(10<<4)|( 1<<0),  
          TIM2_CH4_PA_3      = (TIM2_CH4    <<16)|(0<<12)|( 3<<4)|( 1<<0),  
          TIM2_CH4_PB_11     = (TIM2_CH4    <<16)|(1<<12)|(11<<4)|( 1<<0),  
          TIM3_CH1_PA_6      = (TIM3_CH1    <<16)|(0<<12)|( 6<<4)|( 2<<0),  
          TIM3_CH1_PB_4      = (TIM3_CH1    <<16)|(1<<12)|( 4<<4)|( 2<<0),  
          TIM3_CH1_PC_6      = (TIM3_CH1    <<16)|(2<<12)|( 6<<4)|( 2<<0),  
          TIM3_CH2_PA_7      = (TIM3_CH2    <<16)|(0<<12)|( 7<<4)|( 2<<0),  
          TIM3_CH2_PB_5      = (TIM3_CH2    <<16)|(1<<12)|( 5<<4)|( 2<<0),  
          TIM3_CH2_PC_7      = (TIM3_CH2    <<16)|(2<<12)|( 7<<4)|( 2<<0),  
          TIM3_CH3_PB_0      = (TIM3_CH3    <<16)|(1<<12)|( 0<<4)|( 2<<0),  
          TIM3_CH3_PC_8      = (TIM3_CH3    <<16)|(2<<12)|( 8<<4)|( 2<<0),  
          TIM3_CH4_PB_1      = (TIM3_CH4    <<16)|(1<<12)|( 1<<4)|( 2<<0),  
          TIM3_CH4_PC_9      = (TIM3_CH4    <<16)|(2<<12)|( 9<<4)|( 2<<0),  
          TIM3_ETR_PD_2      = (TIM3_ETR    <<16)|(3<<12)|( 2<<4)|( 2<<0),  
          TIM4_CH1_PB_6      = (TIM4_CH1    <<16)|(1<<12)|( 6<<4)|( 2<<0),  
          TIM4_CH2_PB_7      = (TIM4_CH2    <<16)|(1<<12)|( 7<<4)|( 2<<0),  
          TIM4_CH3_PB_8      = (TIM4_CH3    <<16)|(1<<12)|( 8<<4)|( 2<<0),  
          TIM4_CH4_PB_9      = (TIM4_CH4    <<16)|(1<<12)|( 9<<4)|( 2<<0),  
          TIM9_CH1_PA_2      = (TIM9_CH1    <<16)|(0<<12)|( 2<<4)|( 3<<0),  
          TIM9_CH1_PB_13     = (TIM9_CH1    <<16)|(1<<12)|(13<<4)|( 3<<0),  
          TIM9_CH2_PA_3      = (TIM9_CH2    <<16)|(0<<12)|( 3<<4)|( 3<<0),  
          TIM9_CH2_PB_14     = (TIM9_CH2    <<16)|(1<<12)|(14<<4)|( 3<<0),  
          USART1_CK_PA_8     = (USART1_CK   <<16)|(0<<12)|( 8<<4)|( 7<<0),  
          USART1_CTS_PA_11   = (USART1_CTS  <<16)|(0<<12)|(11<<4)|( 7<<0),  
          USART1_RTS_PA_12   = (USART1_RTS  <<16)|(0<<12)|(12<<4)|( 7<<0),  
          USART1_RX_PA_10    = (USART1_RX   <<16)|(0<<12)|(10<<4)|( 7<<0),  
          USART1_RX_PB_7     = (USART1_RX   <<16)|(1<<12)|( 7<<4)|( 7<<0),  
          USART1_TX_PA_9     = (USART1_TX   <<16)|(0<<12)|( 9<<4)|( 7<<0),  
          USART1_TX_PB_6     = (USART1_TX   <<16)|(1<<12)|( 6<<4)|( 7<<0),  
          USART2_CK_PA_4     = (USART2_CK   <<16)|(0<<12)|( 4<<4)|( 7<<0),  
          USART2_CTS_PA_0    = (USART2_CTS  <<16)|(0<<12)|( 0<<4)|( 7<<0),  
          USART2_RTS_PA_1    = (USART2_RTS  <<16)|(0<<12)|( 1<<4)|( 7<<0),  
          USART2_RX_PA_3     = (USART2_RX   <<16)|(0<<12)|( 3<<4)|( 7<<0),  
          USART2_TX_PA_2     = (USART2_TX   <<16)|(0<<12)|( 2<<4)|( 7<<0),  
          USART3_CK_PB_12    = (USART3_CK   <<16)|(1<<12)|(12<<4)|( 7<<0),  
          USART3_CK_PC_12    = (USART3_CK   <<16)|(2<<12)|(12<<4)|( 7<<0),  
          USART3_CTS_PB_13   = (USART3_CTS  <<16)|(1<<12)|(13<<4)|( 7<<0),  
          USART3_RTS_PB_14   = (USART3_RTS  <<16)|(1<<12)|(14<<4)|( 7<<0),  
          USART3_RX_PB_11    = (USART3_RX   <<16)|(1<<12)|(11<<4)|( 7<<0),  
          USART3_RX_PC_11    = (USART3_RX   <<16)|(2<<12)|(11<<4)|( 7<<0),  
          USART3_TX_PB_10    = (USART3_TX   <<16)|(1<<12)|(10<<4)|( 7<<0),  
          USART3_TX_PC_10    = (USART3_TX   <<16)|(2<<12)|(10<<4)|( 7<<0),  
          USBDM_PA_11        = (USBDM       <<16)|(0<<12)|(11<<4)|(10<<0),  
          USBDP_PA_12        = (USBDP       <<16)|(0<<12)|(12<<4)|(10<<0),  
      END_OF_TABLE = 0
    } MAP;

  public:
    
    









 
    static void set( GPIO_TypeDef *gpio, 
                     BYTE          pinId, 
                     DWORD mode, 
                     BYTE          af = 0 );

    
    














 
    static bool set( Function func,
                     DWORD    mode = 0 );

  public:
    
    


 
    static MAP table[];

}; 

#line 73 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\MCU.h"
#line 1 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Sys/RTOS_MCU.h"







 























 
class cHwRTOS_MCU
{
  private:
    
    typedef struct
    {
      struct
      {
        uint32_t r4;
        uint32_t r5;
        uint32_t r6;
        uint32_t r7;
        uint32_t r8;
        uint32_t r9;
        uint32_t r10;
        uint32_t r11;
      } sw;

      struct
      {
        uint32_t r4;
        uint32_t lr_pc;
      } add;

      struct
      {
        uint32_t r0;
        uint32_t r1;
        uint32_t r2;
        uint32_t r3;
        uint32_t r12;
        uint32_t lr;
        uint32_t pc;
        uint32_t psr;
      } hw;

    } StackFrame;

  public:
    
    
 
    cHwRTOS_MCU( void );

    
    









 
    static void init( WORD us, DWORD (*scheduleIn)( DWORD sp, BYTE flag ))
    {
      schedule = scheduleIn;

      ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->CTRL =  (1UL )
                 | (1UL << 1U)
                 | (1UL << 2U);

        ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->LOAD = (1E-6 * ((32000000)) * us) - 1;

			sysTicTime = us;
    }

    
    










 
    static unsigned start( char     *stackAddrIn,
                           unsigned  stackSizeIn,
                           void     *arg,
                           DWORD   (*startFunc)(void *) )
    {
      void *stackAddr = (void*)(  ((unsigned)stackAddrIn+3) & ~0x03); 
      int   stackSize = stackSizeIn - 4;

      StackFrame *stack = (StackFrame *)((unsigned)stackAddr + stackSize - sizeof(StackFrame));

      stack->hw.r0  = (uint32_t)arg;
      stack->hw.r1  = 0;
      stack->hw.r2  = 0;
      stack->hw.r3  = 0;
      stack->hw.r12 = 0;
      stack->hw.pc  = ((uint32_t)startFunc ) & ~0x01;
      stack->hw.lr  = ((uint32_t)deleteFunc) & ~0x01;
      stack->hw.psr = 0x21000000; 

      stack->sw.r4  = 0;
      stack->sw.r5  = 0;
      stack->sw.r6  = 0;
      stack->sw.r7  = 0;
      stack->sw.r8  = 0;
      stack->sw.r9  = 0;
      stack->sw.r10 = 0;
      stack->sw.r11 = 0;

      stack->add.r4 = 0;
      stack->add.lr_pc = 0xFFFFFFF9;

      return( (unsigned)stackAddr + stackSize - sizeof(StackFrame) );
    }

    
    



 
    static void stop( DWORD id )
    {
      ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->ICSR |= (1UL << 28U); 
    }

    
    


 
    static void pause( void )
    {
      ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->ICSR |= (1UL << 28U); 
    }

    
    


 
		
    static unsigned long getSysTime( void )
		{
			return( (unsigned long)((unsigned long long)sysTic*sysTicTime/1000) );
		}

    
    
 
    static void deleteFunc( void )
    {
      while(1);
    }

  public:    
    
    static DWORD (*schedule)( DWORD sp, BYTE flag );

  public:
    
    static unsigned long  sysTic;
    static unsigned       sysTicTime;

}; 

#line 74 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\MCU.h"


#line 1 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Src/ADC_MCU.h"







 






#line 1 ".\\..\\EmbSysLib\\Src\\Com/Hardware/Analog/ADC.h"







 






#line 1 ".\\..\\EmbSysLib\\Src\\Com/Hardware/Timer/Timer.h"







 






#line 1 ".\\..\\EmbSysLib\\Src\\Com/Std/List.h"







 












 
class cList
{
  public:
    
    








 
    class Item
    {
      public:
          
          

 
          Item( cList *list = 0 );

          
          

 
          Item *getNext( void );

          
          


 
          Item *getPrev( cList &list );

        private:
          
          
 
          virtual void update( void ) {};

        private:
          
          Item *PtrNext; 

        friend class cList;
      }; 
      

  public:
    
    
 
    cList( void );

    
    




 
    BYTE add( Item *itemPtr );

    
    
 
    void updateAll( void );

    
    


 
    Item* getFirst( void );

    
    


 
    Item* operator[](WORD index);

  private:
    
    Item *PtrFirst; 

}; 

#line 16 ".\\..\\EmbSysLib\\Src\\Com/Hardware/Timer/Timer.h"















 
class cHwTimer
{
  public:
    
    

 
    typedef enum
    {
      NORMAL  = 0x00, 
      INVERS  = 0x01  
    } Mode;

  protected:
    
    
    
    cHwTimer( void )
    {
    }

  public:
    
    

 
    virtual DWORD getCycleTime( void );

    
    



 
    virtual void add( cList::Item *ptr );

    
    


 
    virtual void enablePWM( BYTE channel  = 0, 
                            Mode polarity = NORMAL) = 0;

    
    


 
    virtual void setPWM( WORD value, 
                         BYTE channel = 0 ) = 0;

  protected:
  
  public:
    
    
    
    
    
    virtual void isrHandler( void );

  protected:
    
    DWORD cycleTime; 

  private:
    
    cList isrList; 

}; 

#line 16 ".\\..\\EmbSysLib\\Src\\Com/Hardware/Analog/ADC.h"





























 
class cHwADC : public cList::Item
{
  protected:
    
    
    
    
    
    
    
    cHwADC( BYTE      num, 
            cHwTimer *tPtr = 0 );

  public:
    
    


 
    virtual void enable( BYTE ch, BYTE para = 0 );

    
    


 
    virtual WORD get( BYTE ch );

    
    

 
    virtual BYTE getNumberOfChannels( void );

    
    

 
    virtual void update( void );

  public:
    
    
    
    
    
    virtual void isr( void );

  protected:
    
    
    
    
    virtual WORD getResult( void ) = 0;

    
    
    
    
    virtual void startCh( BYTE ch ) = 0;

    
    
    
    
    virtual void configCh( BYTE ch, BYTE para = 0 ) = 0;

  protected:
    
    WORD *result[2];      
    BYTE  idx;            
    BYTE *chList;         
    BYTE  numOfChannels;  
    BYTE  numActivatedCh; 
    BYTE  currentCh;      
    BYTE  currentId;      
    BYTE  isRunning;      

}; 

#line 16 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Src/ADC_MCU.h"








 
class cHwADC_0 : public cHwADC
{
  public:
    
    




 
    cHwADC_0( cHwTimer *tPtr = 0 );

  private:
    
    virtual WORD getResult( void );

    
    virtual void startCh( BYTE ch );

    
    virtual void configCh( BYTE ch, BYTE para = 0 );

  public:
    
    static cHwADC *adcPtr;
    
}; 

#line 77 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\MCU.h"
#line 1 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Src/DAC_MCU.h"







 






#line 1 ".\\..\\EmbSysLib\\Src\\Com/Hardware/Analog/DAC.h"







 





















 
class cHwDAC
{
  protected:
    
    
    
    cHwDAC( BYTE numIn );

  public:
    
    




 
    virtual void set( WORD value,
                      BYTE ch = 0 ) = 0;

    
    

 
    virtual void enable( BYTE ch = 0 ) = 0;

    
    

 
    virtual BYTE getNumberOfChannels( void );

  protected:
    
    BYTE  numOfChannels;  

}; 

#line 16 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Src/DAC_MCU.h"








 
class cHwDAC_0 : public cHwDAC
{
  public:
    
    
 
    cHwDAC_0( void );

    
    virtual void set( WORD value, 
                      BYTE ch = 0 );

    
    virtual void enable( BYTE ch = 0 );

}; 

#line 78 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\MCU.h"
#line 1 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Src/Encoder_MCU.h"







 






#line 1 ".\\..\\EmbSysLib\\Src\\Com/Hardware/Timer/Encoder.h"







 






#line 16 ".\\..\\EmbSysLib\\Src\\Com/Hardware/Timer/Encoder.h"
#line 1 ".\\..\\EmbSysLib\\Src\\Com/Hardware/Port/Port.h"







 















 
class cHwPort
{
  public:
    
    

 
    typedef enum
    {
      
      In  = 0x00,         
      Out = 0x01,         

      
      OD = 0x02,          
      PU = 0x04,          
      PD = 0x08,          

      
      InFL  = In,         
      InPU  = In|PU,      
      InPD  = In|PD,      
      OutPP = Out,        
      OutOD = Out  |OD,   
      OutPU = OutOD|PU,   
      OutPD = OutOD|PD    
    } Mode;

  public:
    
    





 
    class Pin
    {
      public:
        
        


 
        Pin( cHwPort &port, BYTE pinId );

        
        




 
        Pin( cHwPort &port, BYTE pinId, Mode mode );

        
        

 
        virtual void setMode( Mode mode )
        {
          port.setPinMode( pinId, mode );
        }

        
        
 
        virtual void set( void )
        {
          port.set( pinMask );
        }

        
        

 
        virtual void set( bool value )
        {
          if( value )  port.set( pinMask );
          else         port.clr( pinMask );
        }

        
        
 
        virtual void clr( void )
        {
          port.clr( pinMask );
        }

        
        

 
        virtual bool get( void )
        {
          return( (port.get() & pinMask) != 0 );
        }

      private:
        
        cHwPort &port;
        BYTE     pinId;
        MTYPE    pinMask;

    }; 
    

  protected:
    
    
    
    cHwPort( void )
    {
    }

  public:
    
    


 
    virtual void setMode( MTYPE mask, Mode mode ) = 0;

    
    


 
    virtual void setPinMode( BYTE pinId, Mode mode ) = 0;

    
    

 
    virtual void set( MTYPE mask ) = 0;

    
    


 
    virtual void set( MTYPE mask, MTYPE value ) = 0;

    
    

 
    virtual void clr( MTYPE mask ) = 0;

    
    

 
    virtual MTYPE get( void ) = 0;

}; 

#line 17 ".\\..\\EmbSysLib\\Src\\Com/Hardware/Timer/Encoder.h"
#line 18 ".\\..\\EmbSysLib\\Src\\Com/Hardware/Timer/Encoder.h"
#line 19 ".\\..\\EmbSysLib\\Src\\Com/Hardware/Timer/Encoder.h"








 
class cHwEncoder
{
  public:
    
    

 
    typedef enum
    {
      NORMAL  = 0x00, 
      REVERSE = 0x01  
    } Mode;

  protected:
    
    
    
    cHwEncoder( Mode modeIn )
    {
      mode = modeIn;
    }

  public:
    
    

 
    virtual int get( void ) = 0;
  

  protected:
    
    Mode mode;

}; 






 
class cHwEncoder_Emul : public cHwEncoder, cList::Item
{
  public:
    
    cHwEncoder_Emul( cHwPort::Pin &pinAIn,
                     cHwPort::Pin &pinBIn,
                     cHwTimer     &timer,
                     Mode          modeIn )
    : cHwEncoder( modeIn ),
      pinA( pinAIn ),
      pinB( pinBIn )
      {
          pinA.setMode( cHwPort::InFL );
          pinB.setMode( cHwPort::InFL );
          timer.add( this );
          A_last = 0;
          B_last = 0;
          cnt    = 0;
      }

    
    virtual void update( void )
    {
      BYTE A_new = pinA.get();
      BYTE B_new = pinB.get();

      cSystem::disableInterrupt();
        
      if( A_new != A_last )
      {
          if( A_new == B_new )
          {
            cnt++;
          }
          else
          {
            cnt--;
          }
      }
      else if( B_new != B_last )
      {
          if( B_new != A_new )
          {
            cnt++;
          }
          else
          {
            cnt--;
          }
      }
      cSystem::enableInterrupt();
        
      A_last = A_new;
      B_last = B_new;
    }

    
    virtual int get( void )
    {
        cSystem::disableInterrupt();
        int ret = cnt;
        cnt = 0;
        cSystem::enableInterrupt();
        return( (mode&REVERSE)?ret:-ret );
    }

  private:
    
    cHwPort::Pin &pinA;
    cHwPort::Pin &pinB;
    BYTE A_last;
    BYTE B_last;

    int cnt;
};

#line 16 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Src/Encoder_MCU.h"








 
class cHwEncoder_N : public cHwEncoder
{
  public:
    
    

 
    typedef enum
    {
      TIM_2 = 2,  
      TIM_3,      
      TIM_4,      
    } TimerId;

  public:
    
    


 
    cHwEncoder_N( TimerId timerId, Mode mode );

    
    virtual int get();

  private:
    
    TIM_TypeDef *ptr;
    WORD         cntLast;

}; 

#line 79 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\MCU.h"
#line 1 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Src/I2Cmaster_MCU.h"







 






#line 1 ".\\..\\EmbSysLib\\Src\\Com/Hardware/I2C/I2Cmaster.h"







 






#line 16 ".\\..\\EmbSysLib\\Src\\Com/Hardware/I2C/I2Cmaster.h"



















 
class cHwI2Cmaster
{
  public:
    
    
 
    typedef enum
    {
      CR_10kHz  = 0, 
      CR_50kHz     , 
      CR_100kHz    , 
      CR_400kHz    , 
      CR_1000kHz     
    } MODE;

  protected:
    
    
    
    cHwI2Cmaster( BYTE maskIntrIn = true );

  public:
    
    
 
    
    class Device
    {
      public:
        
        
 
        
        Device( cHwI2Cmaster &i2cIn,     
                BYTE          hwAddrIn   
              )

        : i2c( i2cIn)

        {
          hwAddr = hwAddrIn;
          isErrorFlag = false;
        }

        
        

 
        virtual BYTE read( void );

         
        


 
        virtual BYTE read( BYTE addr );

         
        


 
        virtual BYTE read( WORD addr );

        
        


 
        virtual void read( BYTE *data, BYTE size   );

        
        



 
        virtual void read( BYTE addr, BYTE *data, BYTE size );

        
        



 
        virtual void read( WORD addr, BYTE *data, BYTE size );

        
        
 
        virtual void write( BYTE data  
                          );

        
        
 
        virtual void write( BYTE addr,  
                            BYTE data   
                          );

        
        
 
        virtual void write( WORD addr,  
                            BYTE data   
                          );

        
        
 
        virtual void write( BYTE *data, 
                            BYTE size   
                          );

        
        
 
        virtual void write( BYTE addr,  
                            BYTE *data, 
                            BYTE size   
                          );

        
        
 
        virtual void write( WORD addr,  
                            BYTE *data, 
                            BYTE size   
                          );

        
        





 
        virtual BYTE isError( void );

        cHwI2Cmaster &i2c;
        BYTE          hwAddr;
        BYTE isErrorFlag;
    };

  protected:
    
    BYTE isHardwareOK;
    BYTE maskIntr;


  protected:
    
    virtual BYTE write( BYTE  hwAddr,
                             BYTE *adr,
                             BYTE  sizeAdr,
                             BYTE *data,
                             BYTE  sizeData );
    
    virtual BYTE read( BYTE  hwAddr,
                             BYTE *adr,
                             BYTE  sizeAdr,
                             BYTE *data,
                             BYTE  sizeData );
  private:
    
    
    
    
    virtual void start( void ) = 0;

    
    
    
    
    virtual void stop( void ) = 0;

    
    
    
    
    
    virtual void sendAddr( BYTE hwAddr ) = 0;

    
    
    
    
    virtual void writeByte( BYTE data ) = 0;

    
    
    
    
    virtual BYTE readByteAck( void ) = 0;

    
    
    
    
    virtual BYTE readByteNack( void ) = 0;

}; 








 
class cHwI2Cmaster_Emul : public cHwI2Cmaster
{
  public:
    
    





 
    cHwI2Cmaster_Emul( cHwPort::Pin &pinSCL,
                       cHwPort::Pin &pinSDA,
                       MODE          mode );

  private:
    
    virtual void start( void );

    
    virtual void stop( void );

    
    virtual void sendAddr( BYTE addr );

    
    virtual void writeByte( BYTE byte );

    
    virtual BYTE readByteAck( void );

    
    virtual BYTE readByteNack( void );

    
    
    
    virtual void waitForAckn( void );

    
    virtual void wait( void );

  private:
    
    volatile BYTE *ptrIn;
    volatile BYTE *ptrDir;
    volatile BYTE *ptrOut;

    WORD Twait;

    BYTE maskSCL;
    BYTE maskSDA;

    cHwPort::Pin &pinSCL;
    cHwPort::Pin &pinSDA;

}; 

#line 16 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Src/I2Cmaster_MCU.h"








 
class cHwI2Cmaster_N : public cHwI2Cmaster
{
  public:
    
    typedef enum
    {
      I2C_1 = 1, 
      I2C_2      
    } I2C_ID;
    
  public:
    
    





 
    cHwI2Cmaster_N( I2C_ID id, 
                    MODE   mode, 
                    BYTE   maskIntr = true );

  private:
    
    virtual void waitForAckn( MTYPE state );

    
    virtual void start( void );

    
    virtual void stop( void );

    
    virtual void sendAddr( BYTE addr );

    
    virtual void writeByte( BYTE byte );

    
    virtual BYTE readByteAck( void );

    
    virtual BYTE readByteNack( void );

  private:
    
    I2C_TypeDef* ptrBase;

}; 

#line 80 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\MCU.h"
#line 1 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Src/Memory_EEPROM.h"







 






#line 1 ".\\..\\EmbSysLib\\Src\\Com/Hardware/Memory/Memory.h"







 




















 
class cHwMemory
{
  protected:
    
    
    
    
    
    cHwMemory( DWORD size, 
               BYTE  def );

  public:
    
    
 
    virtual void unlock( void ) = 0;
    
    
    
 
    virtual void lock( void ) = 0;
    
    
    


 
    virtual void write( DWORD addr, 
                        BYTE  data );
    
    
    


 
    virtual BYTE read( DWORD addr );

    
    

 
    virtual void clear( DWORD offset = 0 );

    
    

 
    virtual DWORD getSize( void );

    
    

 
    virtual bool isFlash( void );

  protected:
    
    
    
    
    
    virtual void writeByte( DWORD addr, 
                            BYTE  data ) = 0;

    
    
    
    
    
    virtual BYTE readByte( DWORD addr ) = 0;

  protected:
    
    DWORD size;
    BYTE  def;
    bool  isFlashFlag;

}; 

#line 16 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Src/Memory_EEPROM.h"








 
class cHwMemory_EEPROM : public cHwMemory
{
  public:
    
    
 
    cHwMemory_EEPROM( DWORD offset, DWORD size );

    
    
 
    virtual void unlock( void );
    
    
    
 
    virtual void lock( void );
    
  private:
    
    virtual void writeByte( DWORD addr,
                            BYTE  data );

    
    virtual BYTE readByte( DWORD addr );

  private:
    
    BYTE *ptr;
  
}; 



#line 81 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\MCU.h"
#line 1 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Src/Memory_Flash.h"







 






#line 16 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Src/Memory_Flash.h"








 
















 
class cHwMemory_Flash : public cHwMemory
{
  public:
    
    


 
    cHwMemory_Flash( DWORD *startAddress, DWORD size );

    
    
 
    virtual void unlock( void );
    
    
    
 
    virtual void lock( void );
    
  private:
    
    virtual void writeByte( DWORD addr,
                            BYTE  data );

    
    virtual BYTE readByte( DWORD addr );

  public:
    
    virtual void clear( DWORD offset = 0 );

  private:
    
    DWORD *ptr;
    DWORD  dataDoubleWord;
  
}; 



#line 82 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\MCU.h"
#line 1 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Src/Memory_RAM.h"







 






#line 16 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Src/Memory_RAM.h"








 
class cHwMemory_RAM : public cHwMemory
{
  public:
    
    
 
    cHwMemory_RAM( void );

    
    virtual void unlock( void );
    
    
    virtual void lock( void );
    
  private:
    
    virtual void writeByte( DWORD addr, 
                            BYTE  data );

    
    virtual BYTE readByte( DWORD addr );

  private:
    
    DWORD *ptr;

}; 

#line 83 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\MCU.h"
#line 1 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Src/Port_MCU.h"







 






#line 16 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Src/Port_MCU.h"








 
class cHwPort_N : public cHwPort
{
  public:
    
    

 
    typedef enum
    {
      PA = 0, 
      PB,     
      PC,     
      PD,     
      PE,     
      PF,     
      PG,     
      PH,     
    } PortId;

  public:
    
    

 
    cHwPort_N( PortId portId );

    
    virtual void setMode( MTYPE mask, Mode mode );

    
    virtual void setPinMode( BYTE pinId, Mode modeIn );

    
    virtual void set( MTYPE mask )
    {
      ptr->BSRRL = mask;
    }

    
    virtual void set( MTYPE mask, MTYPE value )
    {
      ptr->BSRRL = mask &  value;
      ptr->BSRRH = mask & ~value;
    }
 
    
    virtual void clr( MTYPE mask )
    {
      ptr->BSRRH = mask;
    }

    
    virtual MTYPE get( void )
    {
      return( ptr->IDR );
    }

  private:
    
    GPIO_TypeDef *ptr;

}; 

#line 84 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\MCU.h"
#line 1 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Src/RTC_MCU.h"







 






#line 1 ".\\..\\EmbSysLib\\Src\\Com/Hardware/RTC/RTC.h"







 




















 
class cHwRTC
{
  public:
    
    
 
    class Properties
    {
      public:
        WORD year;   
        BYTE month;  
        BYTE day;    
        BYTE dow;    
        BYTE hour;   
        BYTE minute; 
        BYTE second; 
    
    };

  protected:
    
    
    
    cHwRTC( void );

    
    
    
    
    
    static BYTE getDayOfWeek( BYTE day, BYTE month, WORD year )
    {
       if (month < 3)
       {
         month += 12;
         year--;
       }
       return( ( ( (13*month+3)/5 + day + year + year/4 - year/100 + year/400) % 7) + 1 );
    } 

  public:
    
    


 
    virtual void set( const cHwRTC::Properties &clock ) = 0;

    
    





 
    virtual BYTE get( cHwRTC::Properties &clock ) = 0;

}; 

#line 16 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Src/RTC_MCU.h"








 
class cHwRTC_0 : public cHwRTC
{
  public:
    
    
 
    cHwRTC_0( void );

    
    virtual void set( const cHwRTC::Properties &clock );

    
    virtual BYTE get( cHwRTC::Properties &clock );

}; 

#line 85 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\MCU.h"
#line 1 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Src/SPImaster_MCU.h"







 






#line 1 ".\\..\\EmbSysLib\\Src\\Com/Hardware/SPI/SPImaster.h"







 






#line 16 ".\\..\\EmbSysLib\\Src\\Com/Hardware/SPI/SPImaster.h"



















 
class cHwSPImaster
{
  public:
    
    
 
    typedef enum
    {
      CR_250kHz  =  0, 
      CR_500kHz,       
      CR_1000kHz,      
      CR_2000kHz,      
      CR_4000kHz,      
      CR_8000kHz       
    } MODE;

    
    
 
    typedef enum
    {
      CPOL_L_CPHA_L = 0x00, 
      CPOL_L_CPHA_H = 0x01, 
      CPOL_H_CPHA_L = 0x10, 
      CPOL_H_CPHA_H = 0x11  
      
    } ClockPolPha;

    
    

 
    class Device
    {
      public:
        
        


 
        Device( cHwSPImaster &spiIn,
                cHwPort      &CS_port_In,
                BYTE          CS_pin_In )
        
        : spi( spiIn ),
          CS( CS_port_In, CS_pin_In )
        {
          CS.setMode( cHwPort::Out );
          CS.set();
        }

        
        
 
        void start()
        {
          CS.clr();
        }

        
        
 
        void stop()
        {
          CS.set();
        }
        
        
        


 
        virtual BYTE transceive( BYTE data = 0 );
        
        
        


 
        virtual void transceive( BYTE *data, WORD size );
        
        
        

 
        virtual BYTE read( void );
        
        
        


 
        virtual void read( BYTE *data, WORD size );
        
        
        

 
        virtual void write( BYTE data );

        
        

 
        virtual void write( WORD data );

        
        


 
        virtual void write( BYTE *data, WORD size );

        
        





 
        virtual void writeExt( BYTE bit9, BYTE data );

        
        



 
        virtual void writeExt( BYTE bit9, WORD data );

      public:
        
        cHwSPImaster &spi;
        cHwPort::Pin  CS;
    };

  protected:
    
    
    
    cHwSPImaster( void );
    
  public:

 
    
    
    
    
    
    
    virtual BYTE transceiveByte( BYTE data = 0 ) = 0;
    
    
    
    
    
    
    virtual BYTE transceiveByteExt( BYTE bit = 0, BYTE data = 0 ) = 0;

}; 

#line 16 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Src/SPImaster_MCU.h"








 
class cHwSPImaster_N : public cHwSPImaster
{
  public:
    
    

 
    typedef enum
    {
      SPI_1 = 1,  
      SPI_2,      
      SPI_3       
    } SPI_ID;

  public:
    
    



 
    cHwSPImaster_N( SPI_ID       id,      
                    MODE         mode,       
                    ClockPolPha  clockPolPha );

  private:
    
    virtual BYTE transceiveByte( BYTE value = 0 );

    
    virtual BYTE transceiveByteExt( BYTE bit   = 0,
                                    BYTE value = 0 );

  private:
    
    SPI_TypeDef *ptr;

}; 

#line 86 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\MCU.h"
#line 1 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Src/Timer_MCU.h"







 






#line 16 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Src/Timer_MCU.h"








 
class cHwTimer_N : public cHwTimer
{
  public:
    
    

 
    typedef enum
    {
      TIM_2 = 2,  
      TIM_3,      
      TIM_4,      
      TIM_5,      
      TIM_6,      
      TIM_7       
    } TimerId;

  public:
    
    


 
    cHwTimer_N( TimerId timerId, DWORD cycleTime );

    
    virtual void enablePWM( BYTE channel = 0, Mode polarity = NORMAL );

    
    virtual void setPWM( WORD value, BYTE channel = 0 );

    
    
    
    
    void isr( void );

  public:
    
    static cHwTimer_N *timerPtr_2;
    static cHwTimer_N *timerPtr_3;
    static cHwTimer_N *timerPtr_4;
    static cHwTimer_N *timerPtr_5;
    static cHwTimer_N *timerPtr_6;
    static cHwTimer_N *timerPtr_7;
 
  private:
    
    DWORD        tics; 
    TimerId      timerId;
    TIM_TypeDef *ptr;

}; 

#line 87 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\MCU.h"
#line 1 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Src/UART_MCU.h"







 






#line 1 ".\\..\\EmbSysLib\\Src\\Com/Hardware/UART/UART.h"







 






#line 1 ".\\..\\EmbSysLib\\Src\\Com/Std/Fifo.h"







 





#line 15 ".\\..\\EmbSysLib\\Src\\Com/Std/Fifo.h"










 
template <class T> class cFifo
{
  public:
    
    

 
    cFifo( BYTE sizeIn )
    {
      in   = 0;
      out  = 0;
      anz  = 0;
      size = sizeIn;
      if( size > 0 )
      {
        speicher = new T[size];
      }
    }

    
    



 
    BYTE isFull( void )
    {
      BYTE ret;

      cSystem::disableInterrupt();
      ret = ( anz >= size );
      cSystem::enableInterrupt();

      return( ret );
    }

    
    



 
    BYTE isEmpty( void )
    {
      BYTE ret;

      cSystem::disableInterrupt();
      ret = ( anz == 0 );
      cSystem::enableInterrupt();

      return(ret);
    }

    
    

 
    BYTE getCount( void )
    {
      BYTE ret;

      cSystem::disableInterrupt();
      ret = anz;
      cSystem::enableInterrupt();

      return(ret);
    }

    
    

 
    BYTE getSize( void )
    {
      return( size );
    }

    
    




 
    BYTE operator<<( const T &ref )
    {
      BYTE ret = 0;

      cSystem::disableInterrupt();
      if( anz < size )
      {
        speicher[in] = ref;
        in = (in < size-1) ? in+1 : 0;
        anz++;
        ret = 1;
      }
      cSystem::enableInterrupt();

      return( ret );
    }

    
    




 
    BYTE operator>>( T &ref )
    {
      BYTE ret = 0;

      cSystem::disableInterrupt();
      if( anz != 0 )
      {
        ref = speicher[out];
        out = (out < size-1) ? out+1 : 0;
        anz--;
        ret = 1;
      }
      cSystem::enableInterrupt();

      return( ret );
    }

  private:
    
    T    *speicher;
    BYTE  in;
    BYTE  out;
    BYTE  anz;
    BYTE  size;

}; 

#line 16 ".\\..\\EmbSysLib\\Src\\Com/Hardware/UART/UART.h"

















 
class cHwUART
{
  public:
    
    

 
    typedef enum
    {
      BR_2400  = 0, 
      BR_4800,      
      BR_9600,      
      BR_19200,     
      BR_38400,     
      BR_57600,     
      BR_115200     
    } Mode;

  protected:
    
    
    
    
    
    cHwUART( BYTE sizeRxBuf,
             BYTE sizeTxBuf );

  public:
    
    




 
    virtual void set( BYTE data );

    
    





 
    virtual void set( const BYTE *data, BYTE length );

    
    




 
    virtual void set( const char *str );

    
    




 
    virtual bool isTxBufferFull( void );

    
    




 
    virtual bool get( BYTE *data );

    
    



 
    virtual BYTE get( void );

  protected:
  public:
    
    
    
    
    
    virtual void isrRx( void );

    
    
    
    
    
    
    virtual void isrTx( void );

  private:
    
    
    
    
    virtual void transmitByte( BYTE data );

    
    
    
    
    virtual void setByte( BYTE data ) = 0;

    
    
    
    
    
    virtual BYTE getByte( void ) = 0;

  protected:
    
    cFifo<BYTE>  dataRxBuf; 
    cFifo<BYTE>  dataTxBuf; 

  protected:
    
    bool         txReady;   
                            

}; 

#line 16 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Src/UART_MCU.h"








 
class cHwUART_N : public cHwUART
{
  public:
    
    

 
    typedef enum
    {
      USART_1 = 1, 
      USART_2,     
      USART_3      
    } USART_Id;

  public:
    
    





 
    cHwUART_N( USART_Id id,
               Mode     mode,
               BYTE     sizeRxBuf,
               BYTE     sizeTxBuf );

    
    
    
    
    void isr( void );

  private:
    
    virtual BYTE getByte( void );

    
    virtual void setByte( BYTE c );

  public:
    
    static cHwUART_N *uartPtr_1;
    static cHwUART_N *uartPtr_2;
    static cHwUART_N *uartPtr_3;
        
  private:
    
    USART_TypeDef *ptr;
  
}; 

#line 88 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\MCU.h"
#line 1 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Src/USB_MCU.h"







 






#line 1 ".\\..\\EmbSysLib\\Src\\Com/Hardware/USB/USB.h"












































































 






#line 1 ".\\..\\EmbSysLib\\Src\\Com/Hardware/USB/USBdesc.h"






















 






#line 1 ".\\..\\EmbSysLib\\Src\\Com/Std/DataPointer.h"





 













 
class cDataPointer
{
  public:
    
    
 
    cDataPointer( void )
    {
      ptr  = 0;
      size = 0;
    }
  
    
    


 
    cDataPointer( BYTE *ptrIn, 
                  WORD  sizeIn )
    {
      ptr  = ptrIn;
      size = sizeIn;
    }

    
    

 
    template <class T> 
    cDataPointer( const T &object )
    {
      ptr  = (BYTE*)( &object );
      size = sizeof( T );
    }

    
    
 
    void operator=( const cDataPointer &dataIn )
    {
      if( dataIn.ptr && dataIn.size )
      {
        ptr  = dataIn.ptr;
        size = dataIn.size;        
      }
      else
      {
        ptr  = 0;
        size = 0;
      }
    }

    
    


 
    BYTE set( const BYTE *ptrIn, WORD sizeIn )
    {
      if( ptrIn && sizeIn )
      {
        ptr = (BYTE*)ptrIn;
        size = sizeIn;
        return(true);
      }
      return(false);
    }

    
    

 
    template <class T> void set( const T &dataIn )
    {
      ptr = (BYTE*)(&dataIn);
      size = sizeof( T );
    }
    
    
    

 
    BYTE *getPtr( void ) const
    {
      return( ptr );
    }
    
    
    

 
    template <class T> operator T *()
    {
      return( (T *)getPtr() );
    }
    
    
    



 
    BYTE isEmpty( void )
    {
     return( size?false:true );
    }

    
    

 
    WORD getSize( void )
    {
      return( size );
    }
    
    
    

 
    void shift( WORD shift )
    {
      if( shift <= size )
      {
        ptr  += shift;
        size -= shift;
      }
      else
      {
        ptr = 0;
        size = 0;
      }
    }

  private:
    
    BYTE  *ptr;
    WORD   size;

};

#line 31 ".\\..\\EmbSysLib\\Src\\Com/Hardware/USB/USBdesc.h"











class cHwUSBinterf;
class cHwUSBendpoint;













 
#pragma pack(1)
class cHwUSBdesc
{
  public:
    
    

 
    typedef enum
    {
      RESERVED_CLASS              = 0,   
      AUDIO_CLASS                 = 1,   
      COMMUNICATIONS_CLASS        = 2,   
      HUMAN_INTERFACE_CLASS       = 3,   
      MONITOR_CLASS               = 4,   
      PHYSICAL_INTERFACE_CLASS    = 5,   
      POWER_CLASS                 = 6,   
      PRINTER_CLASS               = 7,   
      STORAGE_CLASS               = 8,   
      HUB_CLASS                   = 9,   
      MISCELLANEOUS_CLASS         = 239, 
      VENDOR_SPECIFIC_CLASS       = 255  
    } DeviceClassType;

    
    

 
    typedef enum
    {
      CONTROL_ENDPOINT     = 0,
      ISOCHRONOUS_ENDPOINT = 1,
      BULK_ENDPOINT        = 2,
      INTERRUPT_ENDPOINT   = 3
    } EndpointType;

  protected:
    
    
    typedef enum
    {
      DEVICE_DESCRIPTOR                  =  1,
      CONFIGURATION_DESCRIPTOR           =  2,
      STRING_DESCRIPTOR                  =  3,
      INTERFACE_DESCRIPTOR               =  4,
      ENDPOINT_DESCRIPTOR                =  5,
      DEVICE_QUALIFIER_DESCRIPTOR        =  6,
      OTHER_SPEED_CONFIG_DESCRIPTOR      =  7,
      INTERFACE_POWER_DESCRIPTOR         =  8,
      OTG_DESCRIPTOR                     =  9,
      DEBUG_DESCRIPTOR                   = 10,
      INTERFACE_ASSOCIATION_DESCRIPTOR   = 11
    } DescriptorType;

  protected:
    
    class cDevice
    {
      public:
        BYTE  bLength;
        BYTE  bDescriptorType;
        WORD  bcdUSB;
        BYTE  bDeviceClass;
        BYTE  bDeviceSubClass;
        BYTE  bDeviceProtocol;
        BYTE  bMaxPacketSize0;
        WORD  idVendor;
        WORD  idProduct;
        WORD  bcdDevice;
        BYTE  iManufacturer;
        BYTE  iProduct;
        BYTE  iSerialNumber;
        BYTE  bNumConfigurations;
    };

    
    class cConfiguration
    {
      public:
        BYTE  bLength;
        BYTE  bDescriptorType;
        WORD  wTotalLength;
        BYTE  bNumInterfaces;
        BYTE  bConfigurationValue;
        BYTE  iConfiguration;
        BYTE  bmAttributes;
        BYTE  bMaxPower;
    };

    
    class cHID
    {
      public:
        BYTE bLength;
        BYTE bDescriptorType;
        WORD bcdHID;
        BYTE bCountryCode;
        BYTE bNumDescriptors;
         
        struct _HID_DESCRIPTOR_LIST {
          BYTE bDescriptorType;
          WORD wDescriptorLength;
        } DescriptorList[1]; 
    };

    
    class cEndpoint
    {
      public:
        BYTE  bLength;
        BYTE  bDescriptorType;
        BYTE  bEndpointAddress;
        BYTE  bmAttributes;
        WORD  wMaxPacketSize;
        BYTE  bInterval;
    };

    
    class cInterface
    {
      public:
        BYTE  bLength;
        BYTE  bDescriptorType;
        BYTE  bInterfaceNumber;
        BYTE  bAlternateSetting;
        BYTE  bNumEndpoints;
        BYTE  bInterfaceClass;
        BYTE  bInterfaceSubClass;
        BYTE  bInterfaceProtocol;
        BYTE  iInterface;
    };

    
    class cReport
    {
      public:
        WORD  bLength;
    };

    
    
    class cString
    {
      public:
        BYTE bLength;
        BYTE bDescriptorType;
    };
#pragma pack()

  protected:
    
    enum
    {
       DEVICE = 0,
       CONFIG,
       INTERF,
       CLASS,
       ENDPOINT,
       REPORT,
       STRING
    };

  protected:
    
    static WORD getId( BYTE type,
                       BYTE confID,
                       BYTE interfID,
                       BYTE id )
    {
        
        return(    ((id      &0x0F)<<12)
                 | ((interfID&0x0F)<< 8)
                 | ((confID  &0x0F)<< 4)
                 | ((type    &0x0F)<< 0) );
    }

    
    virtual const BYTE *getDescriptor( WORD id ) = 0;

    
    virtual void registerEndpoint( BYTE            epId,
                                   cHwUSBendpoint *endpoint ) = 0;

    
    virtual cHwUSBendpoint *getEndpoint( BYTE epId ) = 0;

    
    virtual void registerInterface( BYTE          confId,
                                    BYTE          interfId,
                                    cHwUSBinterf *interf ) = 0;

    
    virtual cHwUSBinterf *getInterface( BYTE confId,
                                        BYTE interfId ) = 0;

    
    virtual cDataPointer getDescriptorDevice( void );

    
    virtual cDataPointer getDescriptorConfig( BYTE confId );

    
    virtual cDataPointer getDescriptorInterface( BYTE confId,
                                                 BYTE interfId );

    
    virtual cDataPointer getDescriptorEndpoint( BYTE confId,
                                                BYTE interfId,
                                                BYTE epId );

    
    virtual cDataPointer getDescriptorHID( BYTE confId,
                                           BYTE interfId,
                                           BYTE hidId );

    
    virtual cDataPointer getDescriptorHIDreport( BYTE confId,
                                                 BYTE interfId,
                                                 BYTE hidId );

    
    virtual cDataPointer getDescriptorString( BYTE strId );

  public: 
    
    virtual BYTE getMaxPacketSize0( void );

  protected:
    
    virtual BYTE getConfigDeviceStatus( BYTE confId );

  
  friend class cHwUSB;
  friend class cHwUSBctrl;
  friend class cHwUSBinterf;

}; 

#line 85 ".\\..\\EmbSysLib\\Src\\Com/Hardware/USB/USB.h"
#line 1 ".\\..\\EmbSysLib\\Src\\Com/Hardware/USB/USBendpoint.h"







 






#line 16 ".\\..\\EmbSysLib\\Src\\Com/Hardware/USB/USBendpoint.h"


class cHwUSB;






 
class cHwUSBendpoint
{
  private:
    
    
    cHwUSBendpoint( cHwUSB       &usb,
                    cHwUSBinterf *interfIn,
                    BYTE          id,
                    WORD          maxPacketSize,
                    BYTE          attributes  );

    
    
    cHwUSBendpoint( cHwUSB       &usb,
                    BYTE          id,
                    WORD          maxPacketSize );

    
    void in( void );

    
    void inCtrl( void );

    
    void out( void );

    
    void outCtrl( void );

    
    WORD readData( void );

    
    void writeData( void );

    
  public: 
    void writeData( const cDataPointer &epDataIn );

  private:
    
    void writeDataLen( const cDataPointer &epDataIn,
                       WORD                maxLen );

    
    void writeAcknowledge( void );

    
    void readAcknowledge( void );

    
    void stall( void );

    
    void clrStall( void );

    
    void clrFeature( void );

    
    void setConfiguration( void );

  private:
    
    cHwUSB        &usb;
    cHwUSBinterf  *interf;
    cDataPointer   epData;
    BYTE           id;
    WORD           maxPacketSize;
    BYTE           attributes;

  
  friend class cHwUSB;
  friend class cHwUSBctrl;
  friend class cHwUSBinterf;

}; 

#line 86 ".\\..\\EmbSysLib\\Src\\Com/Hardware/USB/USB.h"
#line 1 ".\\..\\EmbSysLib\\Src\\Com/Hardware/USB/USBctrl.h"







 












 
class cHwUSBctrl
{
  private:
    
    
    #pragma pack(1)
    class Setup
    {
      private:
        
        BYTE bmRequestType;
        BYTE bRequest;
        WORD wValue;
        WORD wIndex;
        WORD wLength;

      private:
        
        BYTE reqRecipient() { return( (bmRequestType     ) & 0x1F ); }
        BYTE reqType()      { return( (bmRequestType >> 5) & 0x03 ); }
        BYTE reqDir()       { return( (bmRequestType >> 7) & 0x01 ); }
        BYTE request()      { return(  bRequest                   ); }
        WORD value()        { return(  wValue                     ); }
        BYTE valueLow()     { return(  wValue & 0xFF              ); }
        BYTE valueHigh()    { return(  wValue >> 8                ); }
        BYTE index()        { return(  wIndex                     ); }
        BYTE indexLow()     { return(  wIndex & 0xFF              ); }
        BYTE indexHigh()    { return(  wIndex >> 8                ); }
        WORD length()       { return(  wLength                    ); }

      
      friend class cHwUSBctrl;

    }; 
    #pragma pack()
    

  private:
    
    enum
    {
      REQ_RECIPIENT_DEVICE    = 0,
      REQ_RECIPIENT_INTERFACE = 1,
      REQ_RECIPIENT_ENDPOINT  = 2,
      REQ_RECIPIENT_OTHER     = 3
    };

    
    enum
    {
      REQ_DIR_HOST_TO_DEVICE = 0,
      REQ_DIR_DEVICE_TO_HOST = 1
    };

    
    enum
    {
      REQ_TYPE_STANDARD  = 0,
      REQ_TYPE_CLASS     = 1,
      REQ_TYPE_VENDOR    = 2,
      REQ_TYPE_RESERVED  = 3
    };

    
    enum
    {
      REQUEST_GET_STATUS        =  0,
      REQUEST_CLR_FEATURE       =  1,
      REQUEST_RESERVED_0        =  2,
      REQUEST_SET_FEATURE       =  3,
      REQUEST_RESERVED_1        =  4,
      REQUEST_SET_ADDRESS       =  5,
      REQUEST_GET_DESCRIPTOR    =  6,
      REQUEST_SET_DESCRIPTOR    =  7,
      REQUEST_GET_CONFIGURATION =  8,
      REQUEST_SET_CONFIGURATION =  9,
      REQUEST_GET_INTERFACE     = 10,
      REQUEST_SET_INTERFACE     = 11,
      REQUEST_SYNC_FRAME        = 12
    };

    
    enum
    {
      FEATURE_BIT_ENDPOINT_STALL = 0x00,
      FEATURE_BIT_REMOTE_WAKEUP  = 0x01
    };

  private:
    
    cHwUSBctrl( cHwUSB &usbPtr );

    
    virtual void setup( void );

    
    virtual void out( void );

    
    virtual void in( void );

  private:
    
    virtual void Stall( void );

  private:
    
    
    void ReqDevice   ( void );
    void ReqInterface( void );
    void ReqEndpoint ( void );

    
    
    void ReqDeviceStd_GetStatus        ( void );
    void ReqDeviceStd_ClrFeature       ( void );
    void ReqDeviceStd_SetFeature       ( void );
    void ReqDeviceStd_SetAddress       ( void );
    void ReqDeviceStd_GetDescriptor    ( void );
    void ReqDeviceStd_GetConfiguration ( void );
    void ReqDeviceStd_SetConfiguration ( void );

    
    
    void ReqInterfaceStd_GetStatus     ( void );
    void ReqInterfaceStd_GetDescriptor ( void );
    void ReqInterfaceStd_GetInterface  ( void );
    void ReqInterfaceStd_SetInterface  ( void );

    void ReqInterfaceClass( void );

    
    
    void ReqEndpointStd_ClrFeature ( void );
    void ReqEndpointStd_SetFeature ( void );

   private:
     
     cHwUSB         &usb;
     cHwUSBendpoint  epIN;
     cHwUSBendpoint  epOUT;
     Setup           setupData;
     WORD            DeviceStatus;
     BYTE            Configuration;

   
   friend class cHwUSB;

}; 

#line 87 ".\\..\\EmbSysLib\\Src\\Com/Hardware/USB/USB.h"
#line 1 ".\\..\\EmbSysLib\\Src\\Com/Hardware/USB/USBinterf.h"







 






#line 16 ".\\..\\EmbSysLib\\Src\\Com/Hardware/USB/USBinterf.h"


class cHwUSB;






 
class cHwUSBinterf
{
  public:
    
    




 
    cHwUSBinterf( cHwUSB &usb, 
                  BYTE    configId, 
                  BYTE    interfId );

  protected:
    
    









 
    virtual bool transmit( BYTE          epId, 
                           cDataPointer &epdata ) = 0;

    
    










 
    virtual bool request( BYTE          epId, 
                          cDataPointer &epdata ) = 0;

    
    












 
    virtual bool requestCtrlIN( cDataPointer &epdata, 
                                BYTE          request,
                                WORD          value, 
                                WORD          length ) = 0;

    
    













 
    virtual bool requestCtrlOUT( cDataPointer &epdata, 
                                 BYTE          request,
                                 WORD          value, 
                                 WORD          length ) = 0;

    
    










 
    virtual bool receive( BYTE epId, WORD len )  = 0;

  private:
    
    virtual cDataPointer GetDescriptor( WORD value ) 
    {
      return( cDataPointer() );
    }

    
    virtual void clrFeature( void )
    {
    }

    
    virtual void setFeature( void )
    {
    }

  protected:
    
    cHwUSB         &usb;
    cHwUSBendpoint *epIN;
    cHwUSBendpoint *epOUT;
    BYTE            configId;
    BYTE            interfId;
  
  
  friend class cHwUSBendpoint;
  friend class cHwUSBctrl;

}; 

#line 88 ".\\..\\EmbSysLib\\Src\\Com/Hardware/USB/USB.h"
#line 1 ".\\..\\EmbSysLib\\Src\\Com/Hardware/USB/USBhardware.h"







 














 
class cHwUSB
{
  protected:
    
    cHwUSB( cHwUSBdesc &desc );

    
    virtual void eventHandler( BYTE EPnum,
                               BYTE isSetup );
  public:
    
    
 
    virtual void start( void ) = 0;

  protected:
    
    virtual void reset( void ) = 0;

    
    virtual void configure( BYTE flag ) = 0;

    
    virtual void setAddress( BYTE addr ) = 0;

    
    virtual void configEP( BYTE epAddr,
                           WORD epMaxPacketSize,
                           BYTE epType          ) = 0;

    
    virtual void setStallEP( BYTE epAddr ) = 0;

    
    virtual void clrStallEP( BYTE epAddr ) = 0;

    
    virtual WORD readEP( BYTE  epAddr,
                         BYTE *dataPtr,
                         WORD  len     ) = 0;

    
    virtual WORD writeEP( BYTE  epAddr,
                          BYTE *dataPtr,
                          WORD  len     ) = 0;

  protected:
    
    cHwUSBdesc   &desc;   
    cHwUSBctrl    epCtrl;

  
  friend class cHwUSBctrl;
  friend class cHwUSBendpoint;
  friend class cHwUSBinterf;

}; 

#line 89 ".\\..\\EmbSysLib\\Src\\Com/Hardware/USB/USB.h"

#line 16 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\Src/USB_MCU.h"










 
class cHwUSB_0 : public cHwUSB
{
  public:
    
    
 
    cHwUSB_0( cHwUSBdesc &desc );

    
    
    void isr( void );

    
    virtual void start( void );

  private:
    
    class EPconfig
    {
      public:
        
        EPconfig()
        {
          regPtr = 0;
          config = 0;
          rxPtr = 0;
          txPtr = 0;
        }

        
        void init( DWORD addrIn, DWORD type, DWORD kind, WORD sizeIn);

        
        WORD *bdt_init(BYTE num, BYTE isRX, WORD size);

        
        void clrCTR_RX();

        
        void clrCTR_TX( );

        
        void setSTAT_RX( DWORD stat);

        
        void setSTAT_TX(DWORD stat);

        
        DWORD config;
        DWORD *regPtr;
        DWORD addr;
        WORD  rxSize;
        WORD  txSize;
        WORD *txPtr;
        WORD *rxPtr;

        
        static WORD offset;

    };  


  private:
    
    virtual void reset( void );

    
    virtual void configure( BYTE flag );

    
    virtual void setAddress( BYTE adr = 0 );

    
    virtual void configEP( BYTE epAddr,
                           WORD epMaxPacketSize,
                           BYTE epType );

    
    virtual void setStallEP( BYTE epAddr );

    
    virtual void clrStallEP( BYTE epAddr );

    
    virtual WORD readEP( BYTE  epAddr,
                         BYTE *dataPtr,
                         WORD  len );

    
    virtual WORD writeEP( BYTE  epAddr,
                          BYTE *pData,
                          WORD  cnt );

    
    BYTE epAddr2Index( BYTE epAddr )
    {
      return( ((epAddr & 0x0F) << 1) | ((epAddr & 0x80)?0x01:0x00) );
    }

  public:
    
    static cHwUSB_0 *usbPtr;

  private:
    
    static const WORD USB_EP_NUM = 32;

    EPconfig    EP[8];


}; 

#line 89 ".\\..\\EmbSysLib\\Src\\MCU\\STM32L1xx\\MCU.h"





#line 22 ".\\..\\EmbSysLib\\Src\\lib.h"




#line 1 ".\\..\\EmbSysLib\\Src\\Com/Hardware/Net/Net.h"









 






#line 1 ".\\..\\EmbSysLib\\Src\\Com/Hardware/Net/NetStd.h"










 





#line 1 "C:\\Bin\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\string.h"
 
 
 
 




 








 













        namespace std {

        extern "C" {





  



    typedef unsigned int size_t;    
#line 54 "C:\\Bin\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\string.h"




extern __declspec(__nothrow) void *memcpy(void * __restrict  ,
                    const void * __restrict  , size_t  ) __attribute__((__nonnull__(1,2)));
   




 
extern __declspec(__nothrow) void *memmove(void *  ,
                    const void *  , size_t  ) __attribute__((__nonnull__(1,2)));
   







 
extern __declspec(__nothrow) char *strcpy(char * __restrict  , const char * __restrict  ) __attribute__((__nonnull__(1,2)));
   




 
extern __declspec(__nothrow) char *strncpy(char * __restrict  , const char * __restrict  , size_t  ) __attribute__((__nonnull__(1,2)));
   





 

extern __declspec(__nothrow) char *strcat(char * __restrict  , const char * __restrict  ) __attribute__((__nonnull__(1,2)));
   




 
extern __declspec(__nothrow) char *strncat(char * __restrict  , const char * __restrict  , size_t  ) __attribute__((__nonnull__(1,2)));
   






 






 

extern __declspec(__nothrow) int memcmp(const void *  , const void *  , size_t  ) __attribute__((__nonnull__(1,2)));
   





 
extern __declspec(__nothrow) int strcmp(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));
   




 
extern __declspec(__nothrow) int strncmp(const char *  , const char *  , size_t  ) __attribute__((__nonnull__(1,2)));
   






 
extern __declspec(__nothrow) int strcasecmp(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));
   





 
extern __declspec(__nothrow) int strncasecmp(const char *  , const char *  , size_t  ) __attribute__((__nonnull__(1,2)));
   






 
extern __declspec(__nothrow) int strcoll(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));
   







 

extern __declspec(__nothrow) size_t strxfrm(char * __restrict  , const char * __restrict  , size_t  ) __attribute__((__nonnull__(2)));
   













 



extern __declspec(__nothrow) const void *memchr(const void *  , int  , size_t  ) __attribute__((__nonnull__(1)));
extern "C++" void *memchr(void * __s, int __c, size_t __n) __attribute__((__nonnull__(1)));
extern "C++" inline void *memchr(void * __s, int __c, size_t __n)
    { return const_cast<void *>(memchr(const_cast<const void *>(__s), __c, __n)); }



   





 


extern __declspec(__nothrow) const char *strchr(const char *  , int  ) __attribute__((__nonnull__(1)));
extern "C++" char *strchr(char * __s, int __c) __attribute__((__nonnull__(1)));
extern "C++" inline char *strchr(char * __s, int __c)
    { return const_cast<char *>(strchr(const_cast<const char *>(__s), __c)); }



   




 

extern __declspec(__nothrow) size_t strcspn(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));
   




 


extern __declspec(__nothrow) const char *strpbrk(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));
extern "C++" char *strpbrk(char * __s1, const char * __s2) __attribute__((__nonnull__(1,2)));
extern "C++" inline char *strpbrk(char * __s1, const char * __s2)
    { return const_cast<char *>(strpbrk(const_cast<const char *>(__s1), __s2)); }



   




 


extern __declspec(__nothrow) const char *strrchr(const char *  , int  ) __attribute__((__nonnull__(1)));
extern "C++" char *strrchr(char * __s, int __c) __attribute__((__nonnull__(1)));
extern "C++" inline char *strrchr(char * __s, int __c)
    { return const_cast<char *>(strrchr(const_cast<const char *>(__s), __c)); }



   





 

extern __declspec(__nothrow) size_t strspn(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));
   



 


extern __declspec(__nothrow) const char *strstr(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));
extern "C++" char *strstr(char * __s1, const char * __s2) __attribute__((__nonnull__(1,2)));
extern "C++" inline char *strstr(char * __s1, const char * __s2)
    { return const_cast<char *>(strstr(const_cast<const char *>(__s1), __s2)); }



   





 

extern __declspec(__nothrow) char *strtok(char * __restrict  , const char * __restrict  ) __attribute__((__nonnull__(2)));
extern __declspec(__nothrow) char *_strtok_r(char *  , const char *  , char **  ) __attribute__((__nonnull__(2,3)));

extern __declspec(__nothrow) char *strtok_r(char *  , const char *  , char **  ) __attribute__((__nonnull__(2,3)));

   

































 

extern __declspec(__nothrow) void *memset(void *  , int  , size_t  ) __attribute__((__nonnull__(1)));
   



 
extern __declspec(__nothrow) char *strerror(int  );
   





 
extern __declspec(__nothrow) size_t strlen(const char *  ) __attribute__((__nonnull__(1)));
   



 

extern __declspec(__nothrow) size_t strlcpy(char *  , const char *  , size_t  ) __attribute__((__nonnull__(1,2)));
   
















 

extern __declspec(__nothrow) size_t strlcat(char *  , const char *  , size_t  ) __attribute__((__nonnull__(1,2)));
   






















 

extern __declspec(__nothrow) void _membitcpybl(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitcpybb(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitcpyhl(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitcpyhb(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitcpywl(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitcpywb(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitmovebl(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitmovebb(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitmovehl(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitmovehb(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitmovewl(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitmovewb(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
    














































 


         }   
      }   





      using ::std::size_t;
      using ::std::memcpy;
      using ::std::memmove;
      using ::std::strcpy;
      using ::std::strncpy;
      using ::std::strcat;
      using ::std::strncat;
      using ::std::memcmp;
      using ::std::strcmp;
      using ::std::strncmp;
      using ::std::strcasecmp;
      using ::std::strncasecmp;
      using ::std::strcoll;
      using ::std::strxfrm;
      using ::std::memchr;
      using ::std::strchr;
      using ::std::strcspn;
      using ::std::strpbrk;
      using ::std::strrchr;
      using ::std::strspn;
      using ::std::strstr;
      using ::std::strtok;

      using ::std::strtok_r;

      using ::std::_strtok_r;
      using ::std::memset;
      using ::std::strerror;
      using ::std::strlen;
      using ::std::strlcpy;
      using ::std::strlcat;
      using ::std::_membitcpybl;
      using ::std::_membitcpybb;
      using ::std::_membitcpyhl;
      using ::std::_membitcpyhb;
      using ::std::_membitcpywl;
      using ::std::_membitcpywb;
      using ::std::_membitmovebl;
      using ::std::_membitmovebb;
      using ::std::_membitmovehl;
      using ::std::_membitmovehb;
      using ::std::_membitmovewl;
      using ::std::_membitmovewb;





 

#line 18 ".\\..\\EmbSysLib\\Src\\Com/Hardware/Net/NetStd.h"
#line 1 "C:\\Bin\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdio.h"
 
 
 





 






 







 




  
 










      namespace std {

        extern "C" {





  



    typedef unsigned int size_t;    









 
 

 



    typedef struct __va_list __va_list;






   




 




typedef struct __fpos_t_struct {
    unsigned __int64 __pos;
    



 
    struct {
        unsigned int __state1, __state2;
    } __mbstate;
} fpos_t;
   


 


   

 

typedef struct __FILE FILE;
   






 

#line 136 "C:\\Bin\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdio.h"


extern FILE __stdin, __stdout, __stderr;
extern FILE *__aeabi_stdin, *__aeabi_stdout, *__aeabi_stderr;

#line 166 "C:\\Bin\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdio.h"
    

    

    





     



   


 


   


 

   



 

   


 




   


 





    


 






extern __declspec(__nothrow) int remove(const char *  ) __attribute__((__nonnull__(1)));
   





 
extern __declspec(__nothrow) int rename(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));
   








 
extern __declspec(__nothrow) FILE *tmpfile(void);
   




 
extern __declspec(__nothrow) char *tmpnam(char *  );
   











 

extern __declspec(__nothrow) int fclose(FILE *  ) __attribute__((__nonnull__(1)));
   







 
extern __declspec(__nothrow) int fflush(FILE *  );
   







 
extern __declspec(__nothrow) FILE *fopen(const char * __restrict  ,
                           const char * __restrict  ) __attribute__((__nonnull__(1,2)));
   








































 
extern __declspec(__nothrow) FILE *freopen(const char * __restrict  ,
                    const char * __restrict  ,
                    FILE * __restrict  ) __attribute__((__nonnull__(2,3)));
   








 
extern __declspec(__nothrow) void setbuf(FILE * __restrict  ,
                    char * __restrict  ) __attribute__((__nonnull__(1)));
   




 
extern __declspec(__nothrow) int setvbuf(FILE * __restrict  ,
                   char * __restrict  ,
                   int  , size_t  ) __attribute__((__nonnull__(1)));
   















 
#pragma __printf_args
extern __declspec(__nothrow) int fprintf(FILE * __restrict  ,
                    const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   


















 
#pragma __printf_args
extern __declspec(__nothrow) int _fprintf(FILE * __restrict  ,
                     const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   



 
#pragma __printf_args
extern __declspec(__nothrow) int printf(const char * __restrict  , ...) __attribute__((__nonnull__(1)));
   




 
#pragma __printf_args
extern __declspec(__nothrow) int _printf(const char * __restrict  , ...) __attribute__((__nonnull__(1)));
   



 
#pragma __printf_args
extern __declspec(__nothrow) int sprintf(char * __restrict  , const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   






 
#pragma __printf_args
extern __declspec(__nothrow) int _sprintf(char * __restrict  , const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   



 

#pragma __printf_args
extern __declspec(__nothrow) int __ARM_snprintf(char * __restrict  , size_t  ,
                     const char * __restrict  , ...) __attribute__((__nonnull__(3)));


#pragma __printf_args
extern __declspec(__nothrow) int snprintf(char * __restrict  , size_t  ,
                     const char * __restrict  , ...) __attribute__((__nonnull__(3)));
   















 

#pragma __printf_args
extern __declspec(__nothrow) int _snprintf(char * __restrict  , size_t  ,
                      const char * __restrict  , ...) __attribute__((__nonnull__(3)));
   



 
#pragma __scanf_args
extern __declspec(__nothrow) int fscanf(FILE * __restrict  ,
                    const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   






























 
#pragma __scanf_args
extern __declspec(__nothrow) int _fscanf(FILE * __restrict  ,
                     const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   



 
#pragma __scanf_args
extern __declspec(__nothrow) int scanf(const char * __restrict  , ...) __attribute__((__nonnull__(1)));
   






 
#pragma __scanf_args
extern __declspec(__nothrow) int _scanf(const char * __restrict  , ...) __attribute__((__nonnull__(1)));
   



 
#pragma __scanf_args
extern __declspec(__nothrow) int sscanf(const char * __restrict  ,
                    const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   








 
#pragma __scanf_args
extern __declspec(__nothrow) int _sscanf(const char * __restrict  ,
                     const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   



 

 
extern __declspec(__nothrow) int vfscanf(FILE * __restrict  , const char * __restrict  , __va_list) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) int vscanf(const char * __restrict  , __va_list) __attribute__((__nonnull__(1)));
extern __declspec(__nothrow) int vsscanf(const char * __restrict  , const char * __restrict  , __va_list) __attribute__((__nonnull__(1,2)));

extern __declspec(__nothrow) int _vfscanf(FILE * __restrict  , const char * __restrict  , __va_list) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) int _vscanf(const char * __restrict  , __va_list) __attribute__((__nonnull__(1)));
extern __declspec(__nothrow) int _vsscanf(const char * __restrict  , const char * __restrict  , __va_list) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) int __ARM_vsscanf(const char * __restrict  , const char * __restrict  , __va_list) __attribute__((__nonnull__(1,2)));

extern __declspec(__nothrow) int vprintf(const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1)));
   





 
extern __declspec(__nothrow) int _vprintf(const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1)));
   



 
extern __declspec(__nothrow) int vfprintf(FILE * __restrict  ,
                    const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1,2)));
   






 
extern __declspec(__nothrow) int vsprintf(char * __restrict  ,
                     const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1,2)));
   






 
extern __declspec(__nothrow) int __ARM_vsnprintf(char * __restrict  , size_t  ,
                     const char * __restrict  , __va_list  ) __attribute__((__nonnull__(3)));

extern __declspec(__nothrow) int vsnprintf(char * __restrict  , size_t  ,
                     const char * __restrict  , __va_list  ) __attribute__((__nonnull__(3)));
   







 

extern __declspec(__nothrow) int _vsprintf(char * __restrict  ,
                      const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1,2)));
   



 
extern __declspec(__nothrow) int _vfprintf(FILE * __restrict  ,
                     const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1,2)));
   



 
extern __declspec(__nothrow) int _vsnprintf(char * __restrict  , size_t  ,
                      const char * __restrict  , __va_list  ) __attribute__((__nonnull__(3)));
   



 

#pragma __printf_args
extern __declspec(__nothrow) int asprintf(char **  , const char * __restrict  , ...) __attribute__((__nonnull__(2)));
extern __declspec(__nothrow) int vasprintf(char **  , const char * __restrict  , __va_list  ) __attribute__((__nonnull__(2)));

#pragma __printf_args
extern __declspec(__nothrow) int __ARM_asprintf(char **  , const char * __restrict  , ...) __attribute__((__nonnull__(2)));
extern __declspec(__nothrow) int __ARM_vasprintf(char **  , const char * __restrict  , __va_list  ) __attribute__((__nonnull__(2)));
   








 

extern __declspec(__nothrow) int fgetc(FILE *  ) __attribute__((__nonnull__(1)));
   







 
extern __declspec(__nothrow) char *fgets(char * __restrict  , int  ,
                    FILE * __restrict  ) __attribute__((__nonnull__(1,3)));
   










 
extern __declspec(__nothrow) int fputc(int  , FILE *  ) __attribute__((__nonnull__(2)));
   







 
extern __declspec(__nothrow) int fputs(const char * __restrict  , FILE * __restrict  ) __attribute__((__nonnull__(1,2)));
   




 
extern __declspec(__nothrow) int getc(FILE *  ) __attribute__((__nonnull__(1)));
   







 

    inline int getchar() { return getc((& ::std:: __stdin)); }




   





 
extern __declspec(__nothrow) char *gets(char *  ) __attribute__((__nonnull__(1)));
   









 
extern __declspec(__nothrow) int putc(int  , FILE *  ) __attribute__((__nonnull__(2)));
   





 

    inline int putchar(int __c) { return putc(__c, (& ::std:: __stdout)); }




   



 
extern __declspec(__nothrow) int puts(const char *  ) __attribute__((__nonnull__(1)));
   





 
extern __declspec(__nothrow) int ungetc(int  , FILE *  ) __attribute__((__nonnull__(2)));
   






















 

extern __declspec(__nothrow) size_t fread(void * __restrict  ,
                    size_t  , size_t  , FILE * __restrict  ) __attribute__((__nonnull__(1,4)));
   











 

extern __declspec(__nothrow) size_t __fread_bytes_avail(void * __restrict  ,
                    size_t  , FILE * __restrict  ) __attribute__((__nonnull__(1,3)));
   











 

extern __declspec(__nothrow) size_t fwrite(const void * __restrict  ,
                    size_t  , size_t  , FILE * __restrict  ) __attribute__((__nonnull__(1,4)));
   







 

extern __declspec(__nothrow) int fgetpos(FILE * __restrict  , fpos_t * __restrict  ) __attribute__((__nonnull__(1,2)));
   








 
extern __declspec(__nothrow) int fseek(FILE *  , long int  , int  ) __attribute__((__nonnull__(1)));
   














 
extern __declspec(__nothrow) int fsetpos(FILE * __restrict  , const fpos_t * __restrict  ) __attribute__((__nonnull__(1,2)));
   










 
extern __declspec(__nothrow) long int ftell(FILE *  ) __attribute__((__nonnull__(1)));
   











 
extern __declspec(__nothrow) void rewind(FILE *  ) __attribute__((__nonnull__(1)));
   





 

extern __declspec(__nothrow) void clearerr(FILE *  ) __attribute__((__nonnull__(1)));
   




 

extern __declspec(__nothrow) int feof(FILE *  ) __attribute__((__nonnull__(1)));
   


 
extern __declspec(__nothrow) int ferror(FILE *  ) __attribute__((__nonnull__(1)));
   


 
extern __declspec(__nothrow) void perror(const char *  );
   









 

extern __declspec(__nothrow) int _fisatty(FILE *   ) __attribute__((__nonnull__(1)));
    
 

extern __declspec(__nothrow) void __use_no_semihosting_swi(void);
extern __declspec(__nothrow) void __use_no_semihosting(void);
    





 


        }   
      }   








    using ::std::size_t;
    using ::std::fpos_t;
    using ::std::FILE;
    using ::std::remove;
    using ::std::rename;
    using ::std::tmpfile;
    using ::std::tmpnam;
    using ::std::fclose;
    using ::std::fflush;
    using ::std::fopen;
    using ::std::freopen;
    using ::std::setbuf;
    using ::std::setvbuf;
    using ::std::fprintf;
    using ::std::_fprintf;
    using ::std::printf;
    using ::std::_printf;
    using ::std::sprintf;
    using ::std::_sprintf;

      using ::std::snprintf;
      using ::std::vsnprintf;
      using ::std::vfscanf;
      using ::std::vscanf;
      using ::std::vsscanf;

    using ::std::_snprintf;
    using ::std::_vsnprintf;

    using ::std::asprintf;
    using ::std::vasprintf;

    using ::std::__ARM_asprintf;
    using ::std::__ARM_vasprintf;
    using ::std::__ARM_vsnprintf;
    using ::std::__ARM_snprintf;
    using ::std::__ARM_vsscanf;
    using ::std::fscanf;
    using ::std::_fscanf;
    using ::std::scanf;
    using ::std::_scanf;
    using ::std::sscanf;
    using ::std::_sscanf;
    using ::std::_vfscanf;
    using ::std::_vscanf;
    using ::std::_vsscanf;
    using ::std::vprintf;
    using ::std::_vprintf;
    using ::std::vfprintf;
    using ::std::_vfprintf;
    using ::std::vsprintf;
    using ::std::_vsprintf;
    using ::std::fgetc;
    using ::std::fgets;
    using ::std::fputc;
    using ::std::fputs;
    using ::std::getc;
    using ::std::getchar;
    using ::std::gets;
    using ::std::putc;
    using ::std::putchar;
    using ::std::puts;
    using ::std::ungetc;
    using ::std::fread;
    using ::std::__fread_bytes_avail;
    using ::std::fwrite;
    using ::std::fgetpos;
    using ::std::fseek;
    using ::std::fsetpos;
    using ::std::ftell;
    using ::std::rewind;
    using ::std::clearerr;
    using ::std::feof;
    using ::std::ferror;
    using ::std::perror;
    using ::std::_fisatty;
    using ::std::__use_no_semihosting_swi;
    using ::std::__use_no_semihosting;




 

#line 19 ".\\..\\EmbSysLib\\Src\\Com/Hardware/Net/NetStd.h"


template <BYTE size> class cNetAddr
{
  public:
    
    BYTE operator==(const cNetAddr &x) const
    {
      return( memcmp(addr, x.addr, size) == 0 );
    }

    
    void operator=(BYTE *addrIn)
    {
      BYTE i=0;
      while(i < size)
      {
        addr[i] = addrIn[i];
        i++;
       }
    }

    
    void operator=(char *addrIn)
    {
        WORD tmp[4] = {0,0,0,0};
        sscanf((char*)addrIn,"%hu.%hu.%hu.%hu", &tmp[0],&tmp[1],&tmp[2],&tmp[3]);
        for(BYTE i=0;i<4;i++)
            addr[i] = tmp[i];
    }

    
    operator char *()
    {
     static char tmp[16] = "";
        sprintf(tmp,"%u.%u.%u.%u", addr[0],addr[1],addr[2],addr[3]);
        return( tmp );
    }

    
    void operator=(DWORD addrIn)
    {
      BYTE i=0;
      while(i < size)
      {
        addr[i] = (addrIn>>(8*i))&0xFF;
        i++;
       }
    }

    
    operator DWORD()
    {
      return( (DWORD)(*((DWORD*)addr)) );
    }

  public:
    
    BYTE addr[size];

};

WORD hton( const WORD in );
DWORD hton( const DWORD in );

WORD ntoh( const WORD in );
DWORD ntoh( const DWORD in );

#pragma pack(1)
template <class T> class cNetTYPE
{
  public:
    T data;

    void operator=(T x)
    {
      data = hton( x );
    }

    operator T()
    {
      return( ntoh(data) );
    }
};
#pragma pack(8)

typedef BYTE            cNetBYTE;
typedef cNetTYPE<WORD>  cNetWORD;
typedef cNetTYPE<DWORD> cNetDWORD;

const cNetAddr<4> zeroAddr = {{0,0,0,0}};
const cNetAddr<6> zeroAddrPhy = {{0,0,0,0,0,0}};
const cNetAddr<4> broadcastAddr = {{255,255,255,255}};
const cNetAddr<6> broadcastAddrPhy = {{0xFF,0xFF,0xFF,0xFF,0xFF,0xFF}};

WORD Checksum(BYTE *buf, WORD len, DWORD initialSum);

#line 18 ".\\..\\EmbSysLib\\Src\\Com/Hardware/Net/Net.h"
#line 1 ".\\..\\EmbSysLib\\Src\\Com/Hardware/Net/NetApp.h"



#line 5 ".\\..\\EmbSysLib\\Src\\Com/Hardware/Net/NetApp.h"

class cNetApplication : public cList::Item
{
  public:
    cNetApplication( void )
    {
      timeOutTic = 0;
    }

  private:
    virtual void OnReceive( void ) = 0;

    virtual void OnError( void ) = 0;

    virtual void OnUpdate( void ) = 0;

    virtual void OnTimeout( void ) = 0;

  protected:
    virtual void setTimeout( WORD timeSec, WORD timeMilli = 0 )
    {
      
      timeOutTic = (DWORD)100*timeSec + timeMilli/10;
    }

  private:
    virtual void update( void )
    {
      OnUpdate();
      if( timeOutTic && !(--timeOutTic) )
      {
        OnTimeout();
      }
    }

    DWORD       timeOutTic;

  friend class cNetTCP;
  friend class cNetUDP;
  friend class cNetWinTransport;
};

#line 19 ".\\..\\EmbSysLib\\Src\\Com/Hardware/Net/Net.h"
#line 1 ".\\..\\EmbSysLib\\Src\\Com/Hardware/Net/NetTransport.h"



#line 5 ".\\..\\EmbSysLib\\Src\\Com/Hardware/Net/NetTransport.h"
#line 6 ".\\..\\EmbSysLib\\Src\\Com/Hardware/Net/NetTransport.h"


#line 1 "C:\\Bin\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdarg.h"
 
 
 





 











      namespace std {

          extern "C" {











 

 
 
#line 57 "C:\\Bin\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdarg.h"
    typedef struct __va_list { void *__ap; } va_list;

   






 


   










 


   















 




   

 


   




 



   





 



         }   
      }   


#line 138 "C:\\Bin\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdarg.h"





      using ::std::va_list;




 

#line 9 ".\\..\\EmbSysLib\\Src\\Com/Hardware/Net/NetTransport.h"
#line 10 ".\\..\\EmbSysLib\\Src\\Com/Hardware/Net/NetTransport.h"
#line 11 ".\\..\\EmbSysLib\\Src\\Com/Hardware/Net/NetTransport.h"




class cNetTransport
{
  public:

    
    
    
  class Socket : public cList::Item
    {
      public:
        Socket( cNetTransport   &trans,
                cNetApplication &app,
                cNetAddr<4>      inAddrIn,
                WORD             portIn
              );

        virtual void open( cNetAddr<4> addr,
                           WORD port
                         ) = 0;

        virtual void openDefault( void )
        {
          open( remoteAddr, remotePort );
        }

        virtual void close( void ) = 0;

        virtual BYTE isConnected( void ) = 0;

        virtual BYTE isReady( void ) = 0;

        virtual cNetAddr<4> getRemoteIP( void );

        virtual void clear( void ) = 0;

        virtual BYTE *getDataPtr() = 0;

        virtual void setDataLength(WORD len) = 0;

        virtual void send( void ) = 0;

        virtual BYTE get( char *c ) = 0;

        virtual BYTE isServer()
		{
			return( isServerFlag );
		}

      private:
        virtual void fillBuffer( const char c ) = 0;



        
        virtual void update( void )
        {
        }

      public:
        virtual void fill( const char c )
        {
          fillBuffer( c );
        }

        virtual void fill( const char *str )
        {
          fill( str, strlen(str) );
        }

        virtual void fill( const char *buf,
                           WORD        len
                         )
        {
          for( WORD i = 0; i< len; i++ )
          {
            fill( buf[i] );
          }
        }
				
				
				void printf( const char *format, ... )
				{
					char strOut[128+1];
					va_list argzeiger;

					__va_start(argzeiger, format);
					vsnprintf( strOut, 128, format, argzeiger );
					__va_end(argzeiger);

					
					fill( strOut );
				}


        

            virtual BYTE process( void )= 0;
          
            virtual void timeout( void ) = 0;

      protected:
        virtual void setTimeout( WORD timeSec, WORD timeMilli = 0 )
        {
          
          timeOutTic = (DWORD)100*timeSec + timeMilli/10;
        }
        
        
      protected:
        enum
        {
          STATE_WAITING = 0,
          STATE_OPEN_WAIT_ARP,
          STATE_CONNECTED,
        };

      protected:
        cNetAddr<6> addrPhy;
        cNetAddr<4> addr;
        cNetWORD    myPort;
        cNetAddr<4> remoteAddr;
        cNetWORD    remotePort;
        DWORD       timeOutTic;


        BYTE        state;
        
        
		
		BYTE isServerFlag;

        cNetApplication &app;

      friend class cNetTransport;

    }; 



  protected:
    cNetTransport(  );

  public:

 

   virtual void process( void );

    virtual void update( void );

    virtual void timeout( void );

    virtual cNetAddr<4> getAddr( void ) = 0;

    virtual const cNetAddr<6> getAddrPhy( void ) = 0;

  public:
   
  protected:
  public:

   

  public:
    cList  appList;

}; 

#line 20 ".\\..\\EmbSysLib\\Src\\Com/Hardware/Net/Net.h"



#line 1 ".\\..\\EmbSysLib\\Src\\Com/Hardware/Net/NetARP.h"



#line 1 ".\\..\\EmbSysLib\\Src\\Com/Hardware/Ethernet/Ethernet.h"




#line 6 ".\\..\\EmbSysLib\\Src\\Com/Hardware/Ethernet/Ethernet.h"



#pragma pack(1)  

class cHwEthernet_Header
{
  public:                        
    cNetAddr<6> destinationAddr; 
    cNetAddr<6> sourceAddr;      
    cNetWORD    type;            
	                               
};     

#pragma pack(8)

class cNetARP;
class cNetIP;


class cHwEthernet
{
  public:
    enum
    {
      TYPE_IP    = 0x0800,
      TYPE_ARP   = 0x0806,
      TYPE_UNDEF = 0
    };

    cHwEthernet( const cNetAddr<6> &addrPhy );

    virtual void update();

    virtual void create( const cNetAddr<6> destAddr,
                         const WORD        type
                       ) = 0;

    virtual void PacketSend( BYTE *packet,
                             WORD  len                 
                           ) = 0;

    virtual bool PacketReceive( void ) = 0;

    virtual WORD getType( void ) = 0;
    
    void setARP( cNetARP *arpIn );
    void setIP( cNetIP *ipIn );

      cNetAddr<4> &getIP( void );
    bool isNewIP();    

  public:
    BYTE        buf[1500+1];
    WORD        plen;
    const cNetAddr<6> &addrPhy;
  
    cNetARP   *arp;
    cNetIP *ip;
  
};

#line 5 ".\\..\\EmbSysLib\\Src\\Com/Hardware/Net/NetARP.h"

#pragma pack(1)

class cNetARP_Header
{
  public:                         
    cNetWORD    hardwareType;     
    cNetWORD    protocolType;     
    cNetBYTE    physicalAddrLen;  
    cNetBYTE    protocolAddrLen;  
    cNetWORD    operationCode;    
    cNetAddr<6> sourceAddrPhy;    
    cNetAddr<4> sourceAddr;       
    cNetAddr<6> destAddrPhy;      
    cNetAddr<4> destAddr;         
                                  
};

class cNetARP_Msg
{
  public:                    
    cHwEthernet_Header eth;  
    cNetARP_Header     arp;  
                             
};

#pragma pack(8)

class cNetTCP;
class cNetUDP;




class cNetARP
{
  public:
    cNetARP( cHwEthernet &eth,
             
  cNetAddr<4> &addr
           );

    void process( void );
  
    void request( cNetAddr<4> &addr 
                );
  
  void setTCP( cNetTCP *tcp 
               );

    void setUDP( cNetUDP *udp 
               );

  private:
    enum 
    {
      OPCODE_REQUEST = 0x0001,
      OPCODE_REPLY   = 0x0002
    };

  private:
    cHwEthernet  &eth;
    cNetAddr<4>  &addr;
    cNetARP_Msg  &msg;
    cNetTCP      *tcp;
    cNetUDP      *udp;

}; 

#line 24 ".\\..\\EmbSysLib\\Src\\Com/Hardware/Net/Net.h"
#line 1 ".\\..\\EmbSysLib\\Src\\Com/Hardware/Net/NetDHCP.h"





#line 1 ".\\..\\EmbSysLib\\Src\\Com/Hardware/Net/NetUDP.h"



#line 1 ".\\..\\EmbSysLib\\Src\\Com/Hardware/Net/NetIP.h"




#line 6 ".\\..\\EmbSysLib\\Src\\Com/Hardware/Net/NetIP.h"
#line 7 ".\\..\\EmbSysLib\\Src\\Com/Hardware/Net/NetIP.h"


#pragma pack(1)

class cNetIP_Header
{
  public:                             
    cNetBYTE    version_IHL;          
    cNetBYTE    TypeOfService;        
    cNetWORD    packetLength;         
    cNetWORD    identification;       
    cNetWORD    flags_fragmentOffset; 
    cNetBYTE    TTL;                  
    cNetBYTE    protocol;             
    cNetWORD    headerChecksum;       
    cNetAddr<4> sourceAddr;           
    cNetAddr<4> destAddr;             
    
                                      

    
    BYTE getFlags()
    {
      return( flags_fragmentOffset.data & 0x00FF );
    }

    void setFlags( BYTE flags )
    {
      flags_fragmentOffset.data = (flags_fragmentOffset.data & 0xFF00) | flags;
    }

    BYTE getFragmentOffset()
    {
      return( (flags_fragmentOffset.data & 0xFF00) >> 8 );
    }

    void setFragmentOffset( BYTE offset )
    {
      flags_fragmentOffset.data = (flags_fragmentOffset.data & 0x00FF) | ((WORD)offset<<8);
    }
};


class cNetIP_Msg
{
  public:                   
    cHwEthernet_Header eth; 
    cNetIP_Header      ip;  
                            
};


#pragma pack(8)


class cNetICMP;
class cNetTCP;
class cNetUDP;




class cNetIP
{
  public:
    enum
    {
      PROTOCOL_NONE = 0x00,
      PROTOCOL_ICMP = 0x01,
      PROTOCOL_TCP  = 0x06,
      PROTOCOL_UDP  = 0x11
    };

  public:
    
    cNetIP( cHwEthernet &eth,
            const cNetAddr<4> &addr,
            cHwTimer    &timer
          );

    void create( const cNetAddr<6> destAddrPhy,
                 const cNetAddr<4> destAddr,
                 const WORD        len,
                 const WORD        protocol
               );

    void process( void );

    void update();

    void setTCP( cNetTCP  *tcp
               );

    void setUDP( cNetUDP  *udp
               );

    void setICMP( cNetICMP *icmp
                );

    cNetAddr<4> &getAddr( void )
    {
      return( addr );
    }
    
    bool isNewIP()
    {
      if( addr.addr[0] != 0 && !isNewIP_flag ) 
      {
        isNewIP_flag = true;
        return( true );
      }
      return( false );
    }      

  private:
    
  class cTimeOutTimer : public cList::Item
    {
      public:
        
        cTimeOutTimer( cHwTimer &timer )
        {
          timer.add( this );
          max = 10000L / timer.getCycleTime(); 

          if( max > 0 )
            max--;
          
          cnt = max;
        }

        
        virtual void update( void )
        {
          if( !(cnt--) )
          {
            cnt = max;
            flag = true;
          }
        }

        
        WORD cnt;
        WORD max;
        BYTE flag;
    };

  public:
    
    cHwEthernet &eth;
    cNetAddr<4>  addr;
    cNetARP      arp;

  private:
    
    static const BYTE  VERSION_IHL   = (0x40 | 0x05); 

    cTimeOutTimer timeOutTimer;

    cNetIP_Msg &msg;
    cNetUDP    *udp;
    cNetTCP    *tcp;
    cNetICMP   *icmp;
  
    bool isNewIP_flag;

}; 

#line 5 ".\\..\\EmbSysLib\\Src\\Com/Hardware/Net/NetUDP.h"

#pragma pack(1)

class cNetUDP_Header
{
  public:                
    cNetWORD sourcePort; 
    cNetWORD destPort;   
    cNetWORD length;     
    cNetWORD checksum;   
                         
};

class cNetUDP_Msg
{
  public:                   
    cHwEthernet_Header eth; 
    cNetIP_Header     ip;   
    cNetUDP_Header    udp;  
                            
};

#pragma pack(8)





class cNetUDP : public cNetTransport
{
  public:
    
    class Socket : public cNetTransport::Socket
    {
      public:
        
        Socket( cNetUDP         &udp,
                cNetApplication &app,
                cNetAddr<4>      inAddr,
                WORD             port,
                WORD             updateTime = 0
              );

      virtual void open( cNetAddr<4> addr,
                         WORD        port );

      virtual void close( void );

      virtual BYTE isConnected( void );

      virtual BYTE isReady( void );

      virtual void clear( void );

      virtual void fillBuffer( const char c );

      virtual void send( void );

      virtual BYTE get( char *c );

      virtual BYTE *getDataPtr( void );

      virtual void setDataLength( WORD len );


      private:
        
        virtual BYTE process( void );
        virtual void update( void );
        virtual void timeout( void );


      private:
        WORD        dataLen;
        BYTE       *dataPtr;

        cNetUDP         &udp;

      friend class cNetUDP;

    }; 

    
    cNetUDP( cNetIP   &ip
             
           );

    virtual void handleARP( cNetAddr<4> addr, cNetAddr<6> addrPhy );

  private:
    
    void create( Socket &con, WORD payloadLen );
  public:
    virtual cNetAddr<4> getAddr( void )
    {
      return( ip.addr );
    }

    virtual const cNetAddr<6> getAddrPhy( void )
    {
      return( ip.eth.addrPhy );
    }

  public:
    cNetIP   &ip;

  private:
    WORD inPos;
    WORD inBufLen;
    BYTE *buf;

}; 

#line 7 ".\\..\\EmbSysLib\\Src\\Com/Hardware/Net/NetDHCP.h"


#pragma pack(1)



class cNetDHCP_Data
{
  public:                    
    cNetBYTE    op;          
    cNetBYTE    htype;       
    cNetBYTE    hlen;        
    cNetBYTE    hops;        
    cNetDWORD   xid;         
    cNetWORD    secs;        
    cNetWORD    flags;       
    cNetAddr<4> ciAddr;      
    cNetAddr<4> yiAddr;      
    cNetAddr<4> siAddr;      
    cNetAddr<4> giAddr;      
    cNetBYTE    chAddr[16];  
    cNetBYTE    sname[64];   
    cNetBYTE    bfile[128];  
    cNetBYTE    options[64]; 
                             
};


#pragma pack(8)





class cNetDHCP : public cNetApplication
{
  public:
    
    cNetDHCP(cNetUDP     &udpIn,
             const char  *hostName = ""
            );

    
    virtual void OnReceive( void );
    
    
    virtual void OnUpdate( void ) {}

    
    virtual void OnError( void );

    
    virtual void OnTimeout( void );

  private:
   
   enum
    {
      DISCOVER = 1,
      OFFER    = 2,
      REQUEST  = 3,
      DECLINE  = 4,
      ACK      = 5,
      NAK      = 6,
      RELEASE  = 7,
      INFORM   = 8
    };
    
  private:
    
    void send( BYTE msgType );

    
    BYTE parse_options( BYTE *optptr, 
                        int   len );

  private:   
    
    const char        *hostName;
    
    const cNetAddr<6>  addrPhy;
    cNetAddr<4>        serverAddr;
    cNetUDP &udp;
    cNetUDP::Socket    con;
    
}; 

#line 25 ".\\..\\EmbSysLib\\Src\\Com/Hardware/Net/Net.h"
#line 1 ".\\..\\EmbSysLib\\Src\\Com/Hardware/Net/NetICMP.h"




#line 6 ".\\..\\EmbSysLib\\Src\\Com/Hardware/Net/NetICMP.h"

#pragma pack(1)

class cNetICMP_Header
{
  public:              
    cNetBYTE type;     
    cNetBYTE code;     
    cNetWORD checksum; 
                       
};

class cNetICMP_Msg
{
  public:                    
    cHwEthernet_Header eth;  
    cNetIP_Header      ip;   
    cNetICMP_Header    icmp; 
                             
};

#pragma pack(8)




class cNetICMP
{
  public:
    cNetICMP( cNetIP &ip
            );

    void process( void );
    
    void update( void ) {}

    void timeout( void ) {}

  private:
    enum
    {
      TYPE_ECHOREPLY   = 0x00,
      TYPE_ECHOREQUEST = 0x08
    };
    
  private:
    cNetIP &ip;

}; 

#line 26 ".\\..\\EmbSysLib\\Src\\Com/Hardware/Net/Net.h"
#line 1 ".\\..\\EmbSysLib\\Src\\Com/Hardware/Net/NetTCP.h"





class cNetARP;




class cNetTCP : public cNetTransport
{
  private:
    
    
    #pragma pack(1)
    class Header
    {
      public:                        
        cNetWORD  sourcePort;        
        cNetWORD  destPort;          
        cNetDWORD sequenceNumber;    
        cNetDWORD acknowledgeNumber; 
        cNetWORD  dataOffset_flags;  
        cNetWORD  windowSize;        
        cNetWORD  checksum;          
        cNetWORD  urgentPointer;     
        
                                     

        
        WORD getDataOffset()
        {
          return( (WORD)((dataOffset_flags.data & 0x00FF)>>4) * 4 );
        }

        
        void setDataOffset( BYTE offset )
        {
          dataOffset_flags.data = (dataOffset_flags.data &0xFF00) | (offset/4)<<4;
        }

        
        BYTE getFlags()
        {
          return( (dataOffset_flags.data & 0xFF00) >> 8 );
        }

        
        void setFlags( BYTE flags )
        {
          dataOffset_flags.data = (dataOffset_flags.data &0x00FF) | ((WORD)flags<<8);
        }
    };
    #pragma pack(8)

  private:
    
    
    #pragma pack(1)
    class Msg
    {
      public:                   
        cHwEthernet_Header eth; 
        cNetIP_Header      ip;  
        cNetTCP::Header    tcp; 
                                
    };
    #pragma pack(8)

  public:
    
    
    class Socket : public cNetTransport::Socket
    {
      public:
        
        Socket( cNetTCP         &tcp,
                cNetApplication &app,
                cNetAddr<4>      inAddr,
                WORD             port );

        virtual void open( cNetAddr<4> addr,
                           WORD port );

        virtual void close( void );

        virtual BYTE isConnected( void );

        virtual BYTE isReady( void );

        virtual void clear( void );

        virtual void fillBuffer( const char c);

        virtual void send( void );

        virtual BYTE get( char *c );

        virtual BYTE *getDataPtr( void );

        virtual void setDataLength( WORD len);

      private:
        
        virtual BYTE process( void );
        virtual void update( void );
        virtual void timeout( void );

      private:
        enum
        {
          STATE_PENDING          = 100,
          STATE_OPEN_WAIT_SERVER,
          STATE_CONNECTED_WAIT_ACK,
          STATE_FINISHING
        };

      private:
        WORD     flags;
        BYTE     mss;
        DWORD    initialSeqNum;
        DWORD    seqNum;
        DWORD    ackNum;
        DWORD    ackNumExpected;
        cNetTCP &tcp;

      friend class cNetTCP;

    }; 

    
    enum
    {
      FLAG_NONE   = 0x00,
      FLAG_FIN    = 0x01,
      FLAG_SYN    = 0x02,
      FLAG_RST    = 0x04,
      FLAG_PUSH   = 0x08,
      FLAG_ACK    = 0x10,
      FLAG_URG_V  = 0x20,
      FLAG_ECE_V  = 0x40,
      FLAG_CWR_V  = 0x80
    };

  public:
    
    cNetTCP( cNetIP  &ip );

    virtual void handleARP( cNetAddr<4> addr, cNetAddr<6> addrPhy );

    virtual cNetAddr<4> getAddr( void )
    {
      return( ip.addr );
    }

    virtual const cNetAddr<6> getAddrPhy( void )
    {
      return( ip.eth.addrPhy );
    }

  private:
    
    void create( Socket &con, WORD payloadLen );

  private:
    
    cNetIP  &ip;
    WORD     inPos;
    WORD     inBufLen;
    BYTE    *buf;

}; 

#line 27 ".\\..\\EmbSysLib\\Src\\Com/Hardware/Net/Net.h"
#line 28 ".\\..\\EmbSysLib\\Src\\Com/Hardware/Net/Net.h"


#line 27 ".\\..\\EmbSysLib\\Src\\lib.h"









#line 1 ".\\..\\EmbSysLib\\Src\\Com/Std/Std.h"









 






#line 18 ".\\..\\EmbSysLib\\Src\\Com/Std/Std.h"
#line 19 ".\\..\\EmbSysLib\\Src\\Com/Std/Std.h"
#line 20 ".\\..\\EmbSysLib\\Src\\Com/Std/Std.h"






 
template <class T> inline T MAX( T x, T y )
{
  if( x > y )
    return( x );
  else
    return( y );
}





 
template <class T> inline T MIN( T x, T y )
{
  if( x < y )
    return( x );
  else
    return( y );
}











 
template <class T> inline T RANGE( T x, T min, T max )
{
  if( x > max )
    return( max );
  if( x < min )
    return( min );
  return( x );
}






 
template <class T> inline T SIGN( T x )
{
  if( x >= 0 )
    return( +1 );
  else
    return( -1 );
}



const float PI = (float)3.1415926535897932384626433832795;

#line 37 ".\\..\\EmbSysLib\\Src\\lib.h"
#line 1 ".\\..\\EmbSysLib\\Src\\Com/Std/StaticArray.h"





 





#pragma pack(1)


template <class T, WORD size> class cStaticArray
{
  public:
    cStaticArray()
    {
      len = 0;
    }

    
    



 
    
    void operator=( cStaticArray<T,size> &in)
    {
      len = in.len;
      memcpy( element, in.element, size );
    }

    
    T &operator[](WORD idx)
    {
      T &r = element[idx];
      return( r );
    }

    
    BYTE operator<<(T x)
    {
      if( len < size )
      {
        element[len++] = x;
        return( true );
      }
      return( false );
    }

    
    void clear( void )
    {
      len = 0;
      memset( element,0, size );
    }

		WORD length()
		{
			return( len );
		}

		BYTE isFull()
		{
			return( len >= size );
		}
    
    BYTE isEmpty()
		{
			return( len == 0 );
		}

    
  








 
    
   
   
   
   

  private:
    
    WORD  len;
    T element[size];

};



#pragma pack()



#line 38 ".\\..\\EmbSysLib\\Src\\lib.h"
#line 1 ".\\..\\EmbSysLib\\Src\\Com/Std/CRC.h"





 






















 
class cCRC
{
  public:
    
    
 
    typedef enum
    {
      SMALL = 0, 
      FAST       
    } MODE;

    
    





 
    cCRC( MODE mode,
          WORD startCRC         = 0xFFFF,
          WORD generatorPolynom = 0xA001 );

    
    
 
    ~cCRC( void );

    
    




 
    WORD operator()( const BYTE *ptr,
                     DWORD        size );

    void operator()( const BYTE data );

    WORD get( void )
    {
      return( crc );
    }

    void reset( void )
    {
      crc = startCRC;
    }

  private:
    
    
    
    WORD tabMethod( BYTE idx );

  private:
    
    WORD *tabArray;
    WORD  crc;
    WORD  startCRC;
    WORD  generatorPolynom;

}; 

#line 39 ".\\..\\EmbSysLib\\Src\\lib.h"
#line 40 ".\\..\\EmbSysLib\\Src\\lib.h"
#line 41 ".\\..\\EmbSysLib\\Src\\lib.h"
#line 1 ".\\..\\EmbSysLib\\Src\\Com/Std/SharedMem.h"







 






#line 16 ".\\..\\EmbSysLib\\Src\\Com/Std/SharedMem.h"









 
template <class T> class cSharedMem
{
  public:
    
    
 
    cSharedMem( void )
    {
      memset( &speicher, 0, sizeof(T) );
    }

    
    

 
    void operator<<( const T &ref )
    {
      cSystem::disableInterrupt();
      speicher = ref;
      cSystem::enableInterrupt();
    }

    
    

 
    void operator>>( T &ref )
    {
      cSystem::disableInterrupt();
      ref = speicher;
      cSystem::enableInterrupt();
    }

  private:
    
    T speicher;

}; 

#line 42 ".\\..\\EmbSysLib\\Src\\lib.h"
#line 43 ".\\..\\EmbSysLib\\Src\\lib.h"
#line 1 ".\\..\\EmbSysLib\\Src\\Com/Std/Timer.h"







 












 
class cTimer
{
  public:
    
    


 
    cTimer( void );

    
    


 
    void start( WORD timeToWait_msec,
                WORD timeToWait_usec = 0 );

    
    
 
    void start( void );

    
    











 
    BYTE timeout( WORD timeToWait_msec,
                  WORD timeToWait_usec = 0 );

    
    



 
    BYTE timeout( void );

    
    
 
    BYTE isRunning( void );

    
    

 
    void stop( void );

  protected:
    
    
    
    
    void set( WORD timeToWait_msec,
              WORD timeToWait_usec = 0 );
              
  protected:
    
    virtual DWORD getTics() = 0;

    
    virtual DWORD getTimeOfTic() = 0;

  protected:
    
    DWORD  startTime;
    DWORD  timeToGo;
    BYTE   running;

}; 

#line 44 ".\\..\\EmbSysLib\\Src\\lib.h"







#line 1 ".\\..\\EmbSysLib\\Src\\Com/Device/Analog/devAnalogInADC.h"







 






#line 1 ".\\..\\EmbSysLib\\Src\\Com/Device/Analog/devAnalogIn.h"







 






#line 1 ".\\..\\EmbSysLib\\Src\\Com/Device/Analog/devAnalog.h"







 
















 
class cDevAnalog
{
  protected:
    
    
    
    
    
    cDevAnalog( BYTE  channel,
                float gain,
                float offset );

  protected:
    
    BYTE  channel;
    float gain;
    float offs;

}; 

#line 16 ".\\..\\EmbSysLib\\Src\\Com/Device/Analog/devAnalogIn.h"












 
class cDevAnalogIn : public cDevAnalog
{
  protected:
    
    
    
    
    
    cDevAnalogIn( BYTE  channel,
                  float max,
                  float min = 0.0f );

  public:
    
    

 
    virtual float get( void );

    
    

 
    virtual operator float( void );

    
    
 
    void calibrate( float x1,
                    float y1,
                    float x2,
                    float y2
                   );

    
    

 
    virtual WORD getRaw( void ) = 0;

    virtual void enable() = 0;


}; 

#line 16 ".\\..\\EmbSysLib\\Src\\Com/Device/Analog/devAnalogInADC.h"
#line 17 ".\\..\\EmbSysLib\\Src\\Com/Device/Analog/devAnalogInADC.h"








 
class cDevAnalogInADC : public cDevAnalogIn
{
  public:
    
    




 
    cDevAnalogInADC( cHwADC &adc,
                     BYTE    channel = 0,
                     float   max     = 1.0,
                     float   min     = 0.0,
                     BYTE    para    = 0 );

  public:
    
    

 
    virtual WORD getRaw( void );

    virtual void enable();

  private:
    
    cHwADC &adc;

}; 

#line 52 ".\\..\\EmbSysLib\\Src\\lib.h"
#line 1 ".\\..\\EmbSysLib\\Src\\Com/Device/Analog/devAnalogOutDAC.h"








 






#line 1 ".\\..\\EmbSysLib\\Src\\Com/Device/Analog/devAnalogOut.h"







 






#line 16 ".\\..\\EmbSysLib\\Src\\Com/Device/Analog/devAnalogOut.h"












 
class cDevAnalogOut : public cDevAnalog
{
  protected:
    
    
    
    
    
    cDevAnalogOut( BYTE  channel,
                   float max,
                   float min = 0.0f );

  public:
    
    

 
    virtual void set( float value );

    
    


 
    virtual float operator=( float value );

    
    

 
    virtual void setRaw( WORD value ) = 0;

}; 

#line 17 ".\\..\\EmbSysLib\\Src\\Com/Device/Analog/devAnalogOutDAC.h"
#line 18 ".\\..\\EmbSysLib\\Src\\Com/Device/Analog/devAnalogOutDAC.h"








 
class cDevAnalogOutDAC : public cDevAnalogOut
{
  public:
    
    




 
    cDevAnalogOutDAC( cHwDAC &dac,
                      BYTE    channel = 0,
                      float   max     = 1.0f,
                      float   min     = 0.0f );

  public:
    
    

 
    virtual void setRaw( WORD value );

  private:
    
    cHwDAC &dac;

  public:
    
    using cDevAnalogOut::operator=;

}; 

#line 53 ".\\..\\EmbSysLib\\Src\\lib.h"
#line 1 ".\\..\\EmbSysLib\\Src\\Com/Device/Analog/devAnalogOutPWM.h"








 






#line 17 ".\\..\\EmbSysLib\\Src\\Com/Device/Analog/devAnalogOutPWM.h"
#line 1 ".\\..\\EmbSysLib\\Src\\Com/Device/Digital/devDigital.h"







 






#line 16 ".\\..\\EmbSysLib\\Src\\Com/Device/Digital/devDigital.h"
















 
class cDevDigital
{
  public:
    
    

 
    typedef enum
    {
      
      In    = cHwPort::In,     
      InPU  = cHwPort::InPU,   
      InPD  = cHwPort::InPD,   

      
      Out   = cHwPort::OutPP,  
      OutOD = cHwPort::OutOD,  
      OutPU = cHwPort::OutPU,  
      OutPD = cHwPort::OutPD   
    } Mode;

    
    

 
    typedef enum
    {
      NONE  = 0,  
      ACTIVATED,  
      RELEASED,   
    } Event;

  public:
    
    






 
    cDevDigital( cHwPort &port,
                 BYTE     pinId,
                 Mode     mode,
                 bool     def = 0 );

  public:
   
   
   
    
   


 
    virtual void setMode( Mode mode );

    
    

 
    virtual void set( bool value );

    
    
 
    virtual void set( void )
    {
      set( 1 );
    }

    
    
 
    virtual void clr( void )
    {
      set( 0 );
    }

    
    
 
    virtual void toggle( void )
    {
      set( !valueOut );
    }

    
    
    
    
    

 
    virtual bool get( void );

    
    


 
    virtual Event getEvent( void )
    {
      bool valueInLast = valueIn;
      valueIn = get();
      if( valueIn && !valueInLast )
        return( ACTIVATED );
      else if( !valueIn && valueInLast )
        return( RELEASED );
      return( NONE );
    }

    
    
    
    
    


 
    virtual bool operator=( bool value )
    {
      set( value );
      return( value );
    }

    
    


 
    virtual bool operator=( cDevDigital &x)
    {
      set( x.get() );
      return( valueOut );
    }

    
    

 
    virtual operator bool( void )
    {
      return( get() );
    }


  private:
    
    bool         valueIn;
    bool         valueOut;
    bool         pinDefault;
    cHwPort::Pin pin;

}; 

#line 18 ".\\..\\EmbSysLib\\Src\\Com/Device/Analog/devAnalogOutPWM.h"
#line 19 ".\\..\\EmbSysLib\\Src\\Com/Device/Analog/devAnalogOutPWM.h"








 
class cDevAnalogOutPWM : public cDevAnalogOut
{
  public:
    
    





 
    cDevAnalogOutPWM( cHwTimer       &timer,
                      cHwTimer::Mode  mode    = cHwTimer::NORMAL,
                      BYTE            channel = 0,
                      float           max     = 1.0f,
                      float           min     = 0.0f );

  public:
    
    

 
    virtual void setRaw( WORD value );

  private:
    
    cHwTimer &timer;

  public:
    
    using cDevAnalogOut::operator=;

}; 









 
class cDevAnalogOutPWMemul : public cDevAnalogOut, 
                                      cList::Item
{
  public:
    
    







 
    cDevAnalogOutPWMemul( cHwTimer    &timer,
                          cDevDigital &port,
                          BYTE         res = 16,
                          float        max = 1.0,
                          float        min = 0.0 );

  public:
    
    

 
    virtual void setRaw( WORD value );

  private:
    
    virtual void update( void );

  private:
    
    cHwTimer         &timer;
    BYTE              shift;
    WORD              t;
    WORD              max;
    WORD              limit;
    cDevDigital      &port;
    cSharedMem<WORD>  limitBuf;

  public:
    
    using cDevAnalogOut::operator=;

}; 

#line 54 ".\\..\\EmbSysLib\\Src\\lib.h"




#line 59 ".\\..\\EmbSysLib\\Src\\lib.h"
#line 1 ".\\..\\EmbSysLib\\Src\\Com/Device/Digital/devDigitalIndicator.h"







 






#line 16 ".\\..\\EmbSysLib\\Src\\Com/Device/Digital/devDigitalIndicator.h"










 
class cDevDigitalIndicator : public cList::Item
{
  public:
    
    

 
    













 

  public:
    
    






 
    cDevDigitalIndicator( cDevDigital &devDigital,
                          cHwTimer    &timer );

  public:
    
    
    
    
    
 
    virtual void set( void )
    {
      devDigital.set();
    }

     
    
 
    virtual void clr( void )
    {
      devDigital.clr();
    }

    
    
 
    virtual void trigger( WORD timeoutIn )
    {
      blink_flag=false;
      devDigital.set();
      timeout = ((DWORD)timeoutIn*1000)/cycleTime;
    }

    
    
 
    void blink( WORD Tp, WORD duty, WORD pwrIn )
    {
      blink_flag= true;
      timeout=0;
      maxi = 1000*Tp/cycleTime;
      limit = duty*maxi/100;
      pwr = RANGE( pwrIn,(WORD)0,(WORD)100)*G/100;
    }


  private:
    
    virtual void update( void );

  private:
    
    cDevDigital &devDigital;
    cHwTimer    &timer;
    DWORD        timeout;
    DWORD        cycleTime;

    int limit;
    int maxi;
    int pwr;
    int mean;
    int t;
    int p;
    int P;
    int M;
    int G;
    bool blink_flag;

}; 

#line 60 ".\\..\\EmbSysLib\\Src\\lib.h"




#line 1 ".\\..\\EmbSysLib\\Src\\Com/Device/Display/devDisplay.h"







 












 
class cDevDisplay
{
  protected:
    
    
    
    cDevDisplay( void );

  public:
    
    
 
    virtual void clear( void ) = 0;

    
    
 
	virtual void refresh( void ) = 0;
  
    
    





 
    virtual void printf( BYTE        line,   
                         BYTE        column, 
                         BYTE        minLen, 
                         const char *format, 
                         ...) = 0;
						 

}; 

#line 65 ".\\..\\EmbSysLib\\Src\\lib.h"
#line 1 ".\\..\\EmbSysLib\\Src\\Com/Device/Display/devDisplayChar.h"







 






#line 1 ".\\..\\EmbSysLib\\Src\\Com/Hardware/Display/Display.h"







 















 
class cHwDisplay
{
  protected:
    
    
    
    cHwDisplay( BYTE numberOfLinesIn,
                BYTE numberOfColumnsIn );

  public:
    
    
 
    virtual void clear( void ) = 0;

    
    
 
    virtual void refresh( void ) = 0;

    
    


 
    virtual void gotoTextPos( BYTE line, 
                              BYTE column ) = 0;

    
    


 
    virtual void putChar( char c ) = 0;

    
    

 
    virtual BYTE getNumberOfLines( void );

    
    

 
    virtual BYTE getNumberOfColumns( void );

  protected:
    
    WORD numberOfLines;
    WORD numberOfColumns;

}; 

#line 16 ".\\..\\EmbSysLib\\Src\\Com/Device/Display/devDisplayChar.h"
#line 17 ".\\..\\EmbSysLib\\Src\\Com/Device/Display/devDisplayChar.h"










 
class cDevDisplayChar : public cDevDisplay
{
  public:
    
    



 
    cDevDisplayChar( cHwDisplay &display );

    
    
 
    virtual void clear( void );

    
    
 
    virtual void refresh( void );

    
    





 
    virtual void printf( BYTE        line, 
                         BYTE        column,
                         const char *str );

    
    









 
    virtual void printf( BYTE        line,
                         BYTE        column,
                         BYTE        minLen,
                         const char *format,
                         ... );

  private:
    
    cHwDisplay &display;

}; 

#line 66 ".\\..\\EmbSysLib\\Src\\lib.h"
#line 1 ".\\..\\EmbSysLib\\Src\\Com/Device/Display/devDisplayGraphic.h"





 







#line 1 ".\\..\\EmbSysLib\\Src\\Com/Hardware/Display/DisplayGraphic.h"





 






#line 14 ".\\..\\EmbSysLib\\Src\\Com/Hardware/Display/DisplayGraphic.h"
#line 1 ".\\..\\EmbSysLib\\Src\\Com/Hardware/Display/DisplayFont.h"





 






class cHwDisplayFontProperties;











 
class cHwDisplayFont
{
  public:
    
    



  
     cHwDisplayFont( void ) {}

    cHwDisplayFont( const cHwDisplayFontProperties *prop, 
                     const BYTE                     *data );
     
    
    

 
    BYTE getCharWidth( void ) const;
      
    
    

 
    BYTE getCharHeight( void ) const;
      
    
    


 
    void setChar( BYTE c );
      
    
    







 
    BYTE getPixel( BYTE x, 
                   BYTE y );
    
  private:
    
    const cHwDisplayFontProperties *prop;
    const BYTE                     *data;
    const BYTE                     *selected;

}; 






 
class cHwDisplayFontProperties
{
  public:
    
    BYTE firstId;      
    BYTE lastId;       
    BYTE bytePerChar;  
    BYTE charWidth;    
    BYTE charHeight;   

}; 








 
template <WORD NUM_OF_CHAR, BYTE BYTE_PER_CHAR> class cHwDisplayFontData
{
  public:
    
    cHwDisplayFontProperties prop;
    BYTE                     data[NUM_OF_CHAR  ]
                                 [BYTE_PER_CHAR];  

    
    

 
    operator cHwDisplayFont( void ) const
    {
      return( cHwDisplayFont( &prop, (BYTE*)data ) );
    } 
      
}; 

#line 15 ".\\..\\EmbSysLib\\Src\\Com/Hardware/Display/DisplayGraphic.h"
























 





class cHwDisplayGraphic : public cHwDisplay
{
  public:
    
    
 
    
    
    
    
    

    
 
    typedef enum
    {
      
      Black     = ( ((0 >> 3) << 0) | ((0 >> 2) << 5) | ((0 >> 3) << 11) ),  
      Navy      = ( ((96 >> 3) << 0) | ((48 >> 2) << 5) | ((0 >> 3) << 11) ),  
      DarkGreen = ( ((0 >> 3) << 0) | ((128 >> 2) << 5) | ((0 >> 3) << 11) ),  
      DarkCyan  = ( ((128 >> 3) << 0) | ((128 >> 2) << 5) | ((0 >> 3) << 11) ),  
      Maroon    = ( ((0 >> 3) << 0) | ((0 >> 2) << 5) | ((128 >> 3) << 11) ),  
      Purple    = ( ((128 >> 3) << 0) | ((0 >> 2) << 5) | ((128 >> 3) << 11) ),  
      Olive     = ( ((0 >> 3) << 0) | ((196 >> 2) << 5) | ((128 >> 3) << 11) ),  
      Grey      = ( ((192 >> 3) << 0) | ((192 >> 2) << 5) | ((192 >> 3) << 11) ),  
      DarkGrey  = ( ((128 >> 3) << 0) | ((128 >> 2) << 5) | ((128 >> 3) << 11) ),  
      Blue      = ( ((255 >> 3) << 0) | ((0 >> 2) << 5) | ((0 >> 3) << 11) ),  
      Green     = ( ((0 >> 3) << 0) | ((255 >> 2) << 5) | ((0 >> 3) << 11) ),  
      Cyan      = ( ((255 >> 3) << 0) | ((255 >> 2) << 5) | ((0 >> 3) << 11) ),  
      Red       = ( ((0 >> 3) << 0) | ((0 >> 2) << 5) | ((255 >> 3) << 11) ),  
      Magenta   = ( ((255 >> 3) << 0) | ((0 >> 2) << 5) | ((255 >> 3) << 11) ),  
      Yellow    = ( ((0 >> 3) << 0) | ((255 >> 2) << 5) | ((255 >> 3) << 11) ),  
      White     = ( ((255 >> 3) << 0) | ((255 >> 2) << 5) | ((255 >> 3) << 11) ),   
      DarkBlue  = ( ((192 >> 3) << 0) | ((0 >> 2) << 5) | ((0 >> 3) << 11) ),  

    } colorPredefined;

  

  protected:
    
    
    
    
    
    cHwDisplayGraphic( cHwDisplayFont font,
                       BYTE           zoom = 1 );

  public:
    
    


 
    virtual void setFont( cHwDisplayFont font,
                          BYTE           zoom = 1 );

    
    

 
    virtual void setZoom(BYTE zoom = 1);

    
    

 
    virtual void setBackColor( WORD color );

    
    


 
    virtual void setPaintColor( WORD color );

    
    

 
    virtual void setTextColor( WORD color );

    
    


 
    virtual void gotoPixelPos(WORD x,
                              WORD y);

    
    


 
    virtual void gotoTextPos( BYTE line,
                              BYTE colum );

    
    


 
    virtual void putChar( char c );

    
    


 
    virtual void putPixel( WORD x,
                           WORD y );

    
    




 
    virtual void putRectangle( WORD x,
                               WORD y,
                               WORD w,
                               WORD h );

    
    






 
    virtual void putBitmap( WORD        x,
                            WORD        y,
                            WORD        w,
                            WORD        h,
                            const WORD *bitmap );
    
    
		
    virtual void refresh( void ) 
    {
    }

    
    
 
    virtual cHwDisplayFont getDefaultFont( void )
    {
      return( font );
    }
		
		
    

 
    virtual WORD getWidth( void )
		{
			return( Hsize );
		}

    
    

 
    virtual WORD getHeight( void )
		{
			return( Vsize );
		}



  private:
    
    
    
    
    
    
    
    
    
    virtual void setArea( WORD x,
                          WORD y,
                          WORD w,
                          WORD h ) = 0;

    
    
    
    
    
    
    virtual void setPixel( WORD color,
                           WORD x,
                           WORD y      ) = 0;

    
    
    
    
    
    
    virtual void setPixel( WORD color ) = 0;

  protected:
    
    WORD xPos;
    WORD yPos;
	
	  DWORD Hsize;
	  DWORD Vsize;

    
    cHwDisplayFont font;
    BYTE           zoom;

    
    WORD BackColor;
    WORD PaintColor;
    WORD TextColor;

}; 

#line 15 ".\\..\\EmbSysLib\\Src\\Com/Device/Display/devDisplayGraphic.h"
#line 16 ".\\..\\EmbSysLib\\Src\\Com/Device/Display/devDisplayGraphic.h"

















 
class cDevDisplayGraphic : public cDevDisplay
{
  public:
    
    


 
    cDevDisplayGraphic( cHwDisplayGraphic &display 
                      );

    
    
 
    virtual void clear( void );

    
    
 
    virtual void refresh( void );

    
    







 
    virtual void printf( BYTE        line,   
                         BYTE        column, 
                         BYTE        minLen, 
                         const char *format, 
                         ...);

    
    
 
    virtual void setFont( cHwDisplayFont font,     
                          BYTE           zoom = 1  
                        );

    
    
 
    virtual void setZoom( BYTE zoom = 1 
                        );

    
    
 
    virtual void setBackColor( WORD color 
                             );

    
    
 
    virtual void setTextColor( WORD color  
                             );

    
    
 
    virtual void drawText( WORD        x,  
                           WORD        y,  
                           const char *str 
                          );

    
    





 
    virtual void drawText( WORD        x,      
                           WORD        y,      
                           BYTE        minLen, 
                           const char *format, 
                           ... );

    
    
 
    virtual void drawPixel( WORD x,     
                            WORD y,     
                            WORD color  
                          );

    
    
 
    virtual void drawRectangle( WORD x,    
                                WORD y,    
                                WORD w,    
                                WORD h,    
                                WORD color 
                              );

    
    
 
    virtual void drawFrame( WORD x,    
                            WORD y,    
                            WORD w,    
                            WORD h,    
                            WORD th,   
                            WORD color 
                          );

    
    
 
    virtual void drawCircle( WORD x,    
                             WORD y,    
                             WORD r,    
                             WORD color 
                           );

    
    
 
    virtual void drawLine( WORD x0,   
                           WORD y0,   
                           WORD x1,   
                           WORD y1,   
                           WORD th,   
                           WORD color 
                         );

    
    



 
    virtual void drawBitmap( WORD        x,     
                             WORD        y,     
                             WORD        w,     
                             WORD        h,     
                             const WORD *bitmap 
                           );

    
    

 
    virtual cHwDisplayFont getDefaultFont( void );
														 
    
		WORD getWidth( void )
		{
			return( display.getWidth() );
		}

    
		WORD getHeight( void )
		{
			return( display.getHeight() );
		}

  private:
    
    cHwDisplayGraphic &display;

}; 

#line 67 ".\\..\\EmbSysLib\\Src\\lib.h"




#line 1 ".\\..\\EmbSysLib\\Src\\Com/Device/Memory/devMemory.h"







 






#line 16 ".\\..\\EmbSysLib\\Src\\Com/Device/Memory/devMemory.h"








 
class cDevMemory
{
  public:
    
    


 
    cDevMemory( cHwMemory &memIn,      
                WORD       addrIn = 0  
              );

    
    

 
    WORD allocate( WORD size   
                 );

    
    
 
    void write( BYTE *data, 
                WORD  size, 
                WORD  offs  
              );

    
    
 
    void read( BYTE *data,  
               WORD  size,  
               WORD  offs   
             );

    
    
 
    void clear( void );

    
    
 
    void setValid( void );

    
    



 
    BYTE isValid( void );

    BYTE isFlash( void )
    {
      return( mem.isFlash() );
    }


  private:
    
    WORD       addr;
    WORD       pos;
    cHwMemory &mem;

}; 








 
template <class T> class cDevMemoryFragment
{
  public:
    
    
 
    cDevMemoryFragment( cDevMemory &memIn  
                      )
    : mem( memIn )

    {
      offs = mem.allocate( sizeof( T )+1 );
    }

    
    



 
    BYTE isValid( void )
    {
      BYTE valid = 0;

      mem.read( &valid, sizeof( BYTE ), offs );
      return( ( valid == 0xAA ) ? true : false );
    }

    
    
 
    void clear( void )
    {
      BYTE valid = 0;
      mem.write( &valid, sizeof( BYTE ), offs );
    }

    
    


 
    void operator>>( T &data 
                   )
    {
      if( isValid() )
      {
        mem.read( (BYTE*)&data, sizeof( T ), offs+1 );
      }
    }

    
    
 
    void operator<<( const T &data 
                   )
    {
      BYTE valid = 0xAA;

      mem.write( (BYTE*)&data, sizeof( T ), offs+1 );
      mem.write( &valid, sizeof( BYTE ), offs );
    }

  private:
    
    cDevMemory &mem;
    WORD        offs;

};

#line 72 ".\\..\\EmbSysLib\\Src\\lib.h"
#line 1 ".\\..\\EmbSysLib\\Src\\Com/Device/Memory/devMemoryFlash.h"







 






#line 16 ".\\..\\EmbSysLib\\Src\\Com/Device/Memory/devMemoryFlash.h"








 
template <class T> class cDevMemoryFlash
{
  public:
    
    



 
    cDevMemoryFlash( cHwMemory &memIn )

    : mem( memIn )

    {
      WORD  checkSum = 0;
      DWORD i        = 0;

      isValidFlag = false;
      if( mem.read( sizeof(T)+2 ) == 0xAA ) 
      {
        for( i = 0; i < sizeof(T); i++ )
        {
          checkSum += mem.read( i );
        }

        if(    (checkSum&0xFF) == mem.read( i++ )
            && (checkSum>>8)   == mem.read( i++ ) )
        {
          BYTE *ptr = (BYTE*)&data;
          for( i = 0; i < sizeof(T); i++, ptr++ )
          {
            *ptr = mem.read( i );
          }
          isValidFlag = true;
        }
      }
    }

    
    
 
    bool isValid()
    {
      return( isValidFlag );
    }
    
    
 
    BYTE store( void )
    {
      BYTE *ptr      = (BYTE*)&data;
      DWORD i        = 0;
      WORD  checkSum = 0;
      BYTE  ok       = true;


      mem.unlock();
      mem.clear();
      mem.lock();

      mem.unlock();
      for( i = 0; i < sizeof(T); i++, ptr++ )
      {
        mem.write( i, *ptr );
        checkSum += *ptr;
      }
      mem.write( i++, checkSum&0xFF );
      mem.write( i++, checkSum>>8  );
      mem.write( i++, 0xAA );
      while( i%4 ) 
      {
        mem.write( i++, 0x00 );
      }
      mem.lock();


      
      ptr = (BYTE*)&data;
      for( i = 0; i < sizeof(T); i++, ptr++ )
      {
        if( *ptr != mem.read( i ) )
        {
          ok = false;
        }
      }
      if(    (checkSum&0xFF) != mem.read( i++ )
          || (checkSum>>8  ) != mem.read( i++ )
          || (0xAA         ) != mem.read( i++ ) )
      {
        ok = false;
      }

      if( ok )
      {
        isValidFlag = true;
      }
      return( ok );
    }

  public:
    
    T          data;

  private:
    
    cHwMemory &mem;
    bool       isValidFlag;

}; 

#line 73 ".\\..\\EmbSysLib\\Src\\lib.h"




#line 1 ".\\..\\EmbSysLib\\Src\\Com/Device/TextIO/devTextIO_UART.h"







 






#line 1 ".\\..\\EmbSysLib\\Src\\Com/Device/TextIO/devTextIO.h"







 




























 
class cDevTextIO
{
  protected:
    
    
    cDevTextIO( BYTE        inBufSize,    
                BYTE        outBufSize,   
                const char *eos = "\n\r", 
                const char *key = ""      
              );

  public:
    
    














 
    char *getString( void );

    
    





 
    virtual void printf( const char *format, 
                         ...                 
                       );

  protected:
    
    virtual void set( BYTE *str, BYTE size ) = 0;
    
    
    virtual bool get( BYTE *c ) = 0;
    
  private:
    
    char       *strIn;
    char       *strOut;
    BYTE        inBufSize;
    BYTE        outBufSize;
    BYTE        idx;
    const char *eos;
    const char *key;
    BYTE        escape;
    BYTE        last;

}; 

#line 16 ".\\..\\EmbSysLib\\Src\\Com/Device/TextIO/devTextIO_UART.h"
#line 17 ".\\..\\EmbSysLib\\Src\\Com/Device/TextIO/devTextIO_UART.h"









 
class cDevTextIO_UART : public cDevTextIO
{
  public:
    
    

 
    cDevTextIO_UART( cHwUART    &uart,         
                     BYTE        inBufSize,    
                     BYTE        outBufSize,   
                     const char *eos = "\n\r", 
                     const char *key = ""      
                   );

  protected:
    
    virtual void set( BYTE *str, BYTE size );
    
    
    virtual bool get( BYTE *c );
    
  private:
    
    cHwUART    &uart;
 
}; 

#line 78 ".\\..\\EmbSysLib\\Src\\lib.h"




#line 1 ".\\..\\EmbSysLib\\Src\\Com/Device/Control/devControlEncoder.h"





 






#line 14 ".\\..\\EmbSysLib\\Src\\Com/Device/Control/devControlEncoder.h"
#line 15 ".\\..\\EmbSysLib\\Src\\Com/Device/Control/devControlEncoder.h"














 
class cDevControlEncoder : public cList::Item
{
  public:
    
    
 
	  typedef enum
    {
      NONE = 0, 
      LEFT,     
      RIGHT,    
      CTRL_DWN, 
      CTRL_UP,  
      NUMITEMS

	  } tEvent;

  protected:
    
    
    
    
    
    cDevControlEncoder( cDevDigital *btnCtrlIn,
                 cHwTimer    *timer = 0 );

  public:
    
    

 
    tEvent get( void );

    
    


 
 	  virtual void update( void );

  protected:
    
    
    
    
    
    
    
    
    
    
		
		
    
    
	  virtual tEvent getCtrl( void );

    
    
    
    
    
	  virtual tEvent getIncrement( void ) = 0;

  private:
    
    cFifo<tEvent> fifo;
    cDevDigital  *btnCtrl;

};

#line 83 ".\\..\\EmbSysLib\\Src\\lib.h"
#line 1 ".\\..\\EmbSysLib\\Src\\Com/Device/Control/devControlEncoderJoystick.h"





 






#line 14 ".\\..\\EmbSysLib\\Src\\Com/Device/Control/devControlEncoderJoystick.h"











 
class cDevControlEncoderJoystick : public cDevControlEncoder
{
  public:
    
    




 
	  cDevControlEncoderJoystick( cDevDigital *btnLeft,       
                         cDevDigital *btnRight,      
                         cDevDigital *btnCtrl,       
                         cHwTimer    *timerPtr = 0,  
                         WORD         repeatTime = 0 
                       );

  private:
    
	  virtual tEvent getIncrement( void );

  private:
    
    WORD         timerStart;
    WORD         timerCnt;
    cDevDigital *btnLeft;
    cDevDigital *btnRight;

};

#line 84 ".\\..\\EmbSysLib\\Src\\lib.h"
#line 1 ".\\..\\EmbSysLib\\Src\\Com/Device/Control/devControlEncoderRotaryknob.h"





 






#line 14 ".\\..\\EmbSysLib\\Src\\Com/Device/Control/devControlEncoderRotaryknob.h"











 
class cDevControlEncoderRotaryKnob : public cDevControlEncoder
{
  public:
    
    
 
    cDevControlEncoderRotaryKnob( cDevDigital *btnLeft,   
                                  cDevDigital *btnRight,  
                                  cDevDigital *btnCtrl,   
                                  cHwTimer *timerPtr = 0  
                                );

  private:
    
	  virtual tEvent getIncrement( void );

  private:
    
    cDevDigital *btnLeft;
    cDevDigital *btnRight;
};

#line 85 ".\\..\\EmbSysLib\\Src\\lib.h"
#line 1 ".\\..\\EmbSysLib\\Src\\Com/Device/Control/devControlPointer.h"





 






#line 1 ".\\..\\EmbSysLib\\Src\\Com/Hardware/Display/Touch.h"





 




















 
class cHwTouch
{
  protected:
    
    
    
    
    cHwTouch( WORD width, 
              WORD height );

  public:
    
    

 
    virtual void update( void ) = 0;

    
    



 
    virtual WORD getPosX( void );

    
    



 
    virtual WORD getPosY( void );

    
    



 
    virtual BYTE isTouched( void );

  protected:
    
    WORD xPos;
    WORD yPos;
    BYTE isTouchedFlag;

    WORD width;
    WORD height;

}; 

#line 14 ".\\..\\EmbSysLib\\Src\\Com/Device/Control/devControlPointer.h"








 
class cDevControlPointer
{
  public:
    
    



 
    class cData
    {
      public:
        
        
 
        typedef enum
        {
          NONE     = 0,            
          PRESSED  = 0x01,         
          MOVE_X   = 0x02|PRESSED, 
          MOVE_Y   = 0x04|PRESSED, 
          CTRL_DWN = 0x10,         
          CTRL_UP  = 0x20          
        } Flags;

        
        WORD  posX;  
        WORD  posY;  
        int   delta; 
        Flags flags; 
    };

    
    
 
    cDevControlPointer( cHwTouch &touch 
               );

    
    

 
    virtual cData get( void );

  private:
    
    cHwTouch &touch;
    BYTE      isTouchedPrev;
    cData     data;
    int       posXprev;
    int       posYprev;

};

#line 86 ".\\..\\EmbSysLib\\Src\\lib.h"




#line 1 ".\\..\\EmbSysLib\\Src\\Com/Task/TaskHandler.h"







 






#line 16 ".\\..\\EmbSysLib\\Src\\Com/Task/TaskHandler.h"
#line 17 ".\\..\\EmbSysLib\\Src\\Com/Task/TaskHandler.h"
















 
class cTaskHandler : public cList::Item
{
  public:
    
    








 
    class Task : public cList::Item
    {
      public:
        
        


 
        
        
        
        
        
        Task( cTaskHandler &taskHandler );

      private:
        
        
 
        virtual void update( void ) = 0;

    }; 


  public:
    
    





 
    class Timer : public cTimer
    {
      public:
        
        






 
        Timer( cTaskHandler &taskHandler,
               WORD          timeToWait_msec = 0,
               WORD          timeToWait_usec = 0 );

      private:
        
        virtual DWORD getTics( void );

        
        virtual DWORD getTimeOfTic( void );

      private:
        
        cTaskHandler &taskHandler;

    }; 

  public:
    
    

 
    cTaskHandler( cHwTimer *timerPtr );

    
    



 
    cTaskHandler( cTaskHandler *taskPtr = 0 );

    
    

 
    virtual DWORD getCycleTime( void );

    
    


 
    virtual unsigned long getTics( void );

    
    
 
    virtual void run( void );

    
    

 
    virtual void addTask( Task *taskPtr );

  private:
    
    virtual void update( void );

  private:
    
    DWORD         tics;
    DWORD         cycleTime;
    cHwTimer     *timerPtr;
    cTaskHandler *taskPtr;
    cList         idle;

}; 

#line 91 ".\\..\\EmbSysLib\\Src\\lib.h"

#line 14 "..\\EmbSysLib\\Src\\Module\\RTOS/RTOS.h"










 
class cRTOS
{
  public:
    
    











 
    class Task
    {
      protected:
        
        


 
        Task( cRTOS    &rtos,
              unsigned  stackSize );

        
        
 
        virtual ~Task( void );


      public:
        
        




 
        virtual void Stop( void );

        
        

 
        virtual void Pause( WORD time = 0 );

        
        
 
        virtual void Start( void );

        
        


 
        virtual void Finish( void );

        
        



 
        virtual bool isActive( void ) { return( isActiveFlag );}

      private:
        
        virtual void update( void ) = 0;

        
        virtual void OnStart( void ) {}

        
        virtual void OnStop( void ) {}

        
        static DWORD  starter( void *ptr );

      private:
        
        char     *stackAddr;
        unsigned  stackSize;
        int       id;
        BYTE      isActiveFlag;

        public:
        
        cRTOS &rtos;

      
      friend class cRTOS;

      }; 

  public:
    
    









 
    class Timer : public cTimer
    {
      public:
        
        





 
        Timer( WORD timeToWait_msec = 0);

      private:
        
        virtual DWORD getTics();

        
        virtual DWORD getTimeOfTic();

    }; 

  public:
    
    



 
    cRTOS( void );

  protected:
    
    int Start( Task &task );

    
    void Pause( Task &task );

    
    void Stop( Task &task );

  protected:
    
    virtual int add( unsigned sp ) = 0;

    
    virtual DWORD del( int id ) = 0;
    
    
    virtual DWORD get( int id ) = 0;

  protected:
    
    virtual unsigned scheduler( unsigned sp,
                                bool     isSysTic ) = 0;

  public:
    
    
    
    static DWORD schedule( DWORD sp, BYTE flag )
    {
      return( ptr->scheduler( sp, flag ) );
    }

  public:
    
    static cRTOS  *ptr;

}; 

#line 10 "..\\EmbSysLib\\Src\\Module\\RTOS/RTOS.cpp"


cRTOS *cRTOS::ptr = 0;







cRTOS::Task::Task( cRTOS    &rtosIn,
                   unsigned  stackSizeIn )

: rtos( rtosIn )
{
  stackSize = stackSizeIn;
  stackAddr = new char[stackSize];
  isActiveFlag = false;
}


cRTOS::Task::~Task( void )
{
   Stop();
   delete stackAddr;
   stackAddr = 0;
}


DWORD  cRTOS::Task::starter( void *ptr )
{
  ((Task*)ptr)->update();
  ((Task*)ptr)->Finish();
  return(0);
}


void cRTOS::Task::Finish( void )
{
  if( isActiveFlag )
  {
    isActiveFlag = false;
    OnStop();
    rtos.Stop( *this );

    
    while(1);
  }
}


void cRTOS::Task::Stop( void )
{
  if( isActiveFlag )
  {
    isActiveFlag = false;
    rtos.Stop( *this );
    OnStop();
  }
}


void cRTOS::Task::Pause( WORD time  )
{
  unsigned long timeToGo = cHwRTOS_MCU::getSysTime() + time;

  do
  {
    rtos.Pause( *this );
  } while( cHwRTOS_MCU::getSysTime() < timeToGo );

}


void cRTOS::Task::Start( void )
{
  if( !isActiveFlag )
  {
    isActiveFlag = true;
    OnStart();
    rtos.Start( *this );
  }
}







cRTOS::Timer::Timer( WORD timeToWait_msec )
{
  set( timeToWait_msec ); 
}


DWORD cRTOS::Timer::getTics( void )
{
  return( cHwRTOS_MCU::getSysTime() );
}


DWORD cRTOS::Timer::getTimeOfTic( void )
{
  return( 1000  );
}







cRTOS::cRTOS( void )
{
  ptr = this;
}


int cRTOS::Start( cRTOS::Task &task )
{
  int ret = 0;

  
  
  cSystem::disableInterrupt();

  unsigned sp = cHwRTOS_MCU::start( task.stackAddr,
                                    task.stackSize,
                                    (void *)&task,
                                    cRTOS::Task::starter );

  ret = add( sp );

  
  cSystem::enableInterrupt();

  task.id = ret;

  return (ret);
}


void cRTOS::Pause( cRTOS::Task &task )
{
  cHwRTOS_MCU::pause();
}


void cRTOS::Stop( cRTOS::Task &task )
{
  cHwRTOS_MCU::stop( get(task.id) );

  del( task.id );
}


#line 12 "..\\EmbSysLib\\Src\\Module\\RTOS.cpp"
#line 1 "..\\EmbSysLib\\Src\\Module\\RTOS/RTOS_Scheduler.cpp"





 


#line 1 "..\\EmbSysLib\\Src\\Module\\RTOS/RTOS_Scheduler.h"





 






#line 14 "..\\EmbSysLib\\Src\\Module\\RTOS/RTOS_Scheduler.h"
#line 15 "..\\EmbSysLib\\Src\\Module\\RTOS/RTOS_Scheduler.h"








 
template <BYTE NUM_OF_TASK> 
class cRTOS_RR : public cRTOS
{
  private:
    
    typedef struct
    {
      unsigned stackPtr; 
      int      flags;    
    } TaskInfo;

  private:
    
    typedef enum
    {
      IN_USE_FLAG = 0x01,
      EXEC_FLAG   = 0x02,
      IDLE_FLAG   = 0x04
    } Flag;

  public:
    
    


 
    cRTOS_RR( unsigned us = 1000 )
  
    : cRTOS()
    
    {
      currentTask       = 0;
      currentCyclicTask = 0;
      
      for( int i = 0; i < NUM_OF_TASK + 1; i++ )
      {
          taskTable[i].flags = 0;
      }
      taskTable[0].stackPtr = 0;
      taskTable[0].flags    = IN_USE_FLAG | EXEC_FLAG | IDLE_FLAG;

      cHwRTOS_MCU::init( (WORD)us , 
                         (DWORD (*)( DWORD sp, BYTE flag ))schedule );
    }
  private:
    
    
    virtual int add( unsigned stackPtr )
    {
      if( currentCyclicTask == 0)
      {
        currentCyclicTask = 1;
      }
      int flags = IN_USE_FLAG | EXEC_FLAG;

      for(int i = 0; i < NUM_OF_TASK + 1; i++ )
      {
        if( taskTable[i].flags == 0 )
        {
          taskTable[i].stackPtr = stackPtr;
          taskTable[i].flags    = flags;
          return( i );
        }
      }
      return( 0 );
    }

    
    virtual DWORD del( int id )
    {
      DWORD ret = taskTable[id].stackPtr;
      
      taskTable[id].flags    = 0;
      taskTable[id].stackPtr = 0;
      return( ret );
    }

    
    
    virtual DWORD get( int id )
    {
      return( taskTable[id].stackPtr );
    }

    
    virtual unsigned scheduler( unsigned stackPtr,
                                bool     isSysTic )
    {
      taskTable[currentTask].stackPtr = stackPtr;

      if( isSysTic ) 
      {
        lastTask = currentCyclicTask;
        while( 1 )
        {
          currentCyclicTask++;
          
          if( currentCyclicTask == NUM_OF_TASK + 1 )
          {
            currentCyclicTask = 0;
          }
          if( currentCyclicTask == lastTask )
          {
            break;
          }
          if( taskTable[currentCyclicTask].flags & EXEC_FLAG )
          {  
            break;
          }
        }        
        currentTask = currentCyclicTask;
      }
      else
      {
        currentTask = 0;
      }

      return( taskTable[currentTask].stackPtr );
    }

  private:
    
    TaskInfo  taskTable[ NUM_OF_TASK + 1 ];
    int       currentTask;
    int       currentCyclicTask;
    int       lastTask;
};

#line 10 "..\\EmbSysLib\\Src\\Module\\RTOS/RTOS_Scheduler.cpp"











#line 13 "..\\EmbSysLib\\Src\\Module\\RTOS.cpp"


