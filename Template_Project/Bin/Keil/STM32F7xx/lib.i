#line 1 "..\\EmbSysLib\\Src\\lib.cpp"









 


#line 1 "..\\EmbSysLib\\Src\\lib.h"









 









#line 1 "..\\EmbSysLib\\Src\\MCU/System.h"







 















 
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

#line 21 "..\\EmbSysLib\\Src\\lib.h"
#line 1 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\MCU.h"











 






#line 25 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\MCU.h"


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




 

#line 28 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\MCU.h"
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







 
#line 29 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\MCU.h"
  

#line 1 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f7xx.h"













































 



 



 
    




 extern "C" {

  


 



 






 
#line 99 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f7xx.h"



 






 
   




 
#line 124 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f7xx.h"


 



 
#line 1 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"









































 



 



 





 extern "C" {




 




 
typedef enum
{
 
  NonMaskableInt_IRQn         = -14,     
  MemoryManagement_IRQn       = -12,     
  BusFault_IRQn               = -11,     
  UsageFault_IRQn             = -10,     
  SVCall_IRQn                 = -5,      
  DebugMonitor_IRQn           = -4,      
  PendSV_IRQn                 = -2,      
  SysTick_IRQn                = -1,      
 
  WWDG_IRQn                   = 0,       
  PVD_IRQn                    = 1,       
  TAMP_STAMP_IRQn             = 2,       
  RTC_WKUP_IRQn               = 3,       
  FLASH_IRQn                  = 4,       
  RCC_IRQn                    = 5,       
  EXTI0_IRQn                  = 6,       
  EXTI1_IRQn                  = 7,       
  EXTI2_IRQn                  = 8,       
  EXTI3_IRQn                  = 9,       
  EXTI4_IRQn                  = 10,      
  DMA1_Stream0_IRQn           = 11,      
  DMA1_Stream1_IRQn           = 12,      
  DMA1_Stream2_IRQn           = 13,      
  DMA1_Stream3_IRQn           = 14,      
  DMA1_Stream4_IRQn           = 15,      
  DMA1_Stream5_IRQn           = 16,      
  DMA1_Stream6_IRQn           = 17,      
  ADC_IRQn                    = 18,      
  CAN1_TX_IRQn                = 19,      
  CAN1_RX0_IRQn               = 20,      
  CAN1_RX1_IRQn               = 21,      
  CAN1_SCE_IRQn               = 22,      
  EXTI9_5_IRQn                = 23,      
  TIM1_BRK_TIM9_IRQn          = 24,      
  TIM1_UP_TIM10_IRQn          = 25,      
  TIM1_TRG_COM_TIM11_IRQn     = 26,      
  TIM1_CC_IRQn                = 27,      
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
  OTG_FS_WKUP_IRQn            = 42,      
  TIM8_BRK_TIM12_IRQn         = 43,      
  TIM8_UP_TIM13_IRQn          = 44,      
  TIM8_TRG_COM_TIM14_IRQn     = 45,      
  TIM8_CC_IRQn                = 46,      
  DMA1_Stream7_IRQn           = 47,      
  FMC_IRQn                    = 48,      
  SDMMC1_IRQn                 = 49,      
  TIM5_IRQn                   = 50,      
  SPI3_IRQn                   = 51,      
  UART4_IRQn                  = 52,      
  UART5_IRQn                  = 53,      
  TIM6_DAC_IRQn               = 54,      
  TIM7_IRQn                   = 55,      
  DMA2_Stream0_IRQn           = 56,      
  DMA2_Stream1_IRQn           = 57,      
  DMA2_Stream2_IRQn           = 58,      
  DMA2_Stream3_IRQn           = 59,      
  DMA2_Stream4_IRQn           = 60,      
  ETH_IRQn                    = 61,      
  ETH_WKUP_IRQn               = 62,      
  CAN2_TX_IRQn                = 63,      
  CAN2_RX0_IRQn               = 64,      
  CAN2_RX1_IRQn               = 65,      
  CAN2_SCE_IRQn               = 66,      
  OTG_FS_IRQn                 = 67,      
  DMA2_Stream5_IRQn           = 68,      
  DMA2_Stream6_IRQn           = 69,      
  DMA2_Stream7_IRQn           = 70,      
  USART6_IRQn                 = 71,      
  I2C3_EV_IRQn                = 72,      
  I2C3_ER_IRQn                = 73,      
  OTG_HS_EP1_OUT_IRQn         = 74,      
  OTG_HS_EP1_IN_IRQn          = 75,      
  OTG_HS_WKUP_IRQn            = 76,      
  OTG_HS_IRQn                 = 77,      
  DCMI_IRQn                   = 78,      
  RNG_IRQn                    = 80,      
  FPU_IRQn                    = 81,      
  UART7_IRQn                  = 82,      
  UART8_IRQn                  = 83,      
  SPI4_IRQn                   = 84,      
  SPI5_IRQn                   = 85,      
  SPI6_IRQn                   = 86,      
  SAI1_IRQn                   = 87,      
  LTDC_IRQn                   = 88,      
  LTDC_ER_IRQn                = 89,      
  DMA2D_IRQn                  = 90,      
  SAI2_IRQn                   = 91,      
  QUADSPI_IRQn                = 92,      
  LPTIM1_IRQn                 = 93,      
  CEC_IRQn                    = 94,      
  I2C4_EV_IRQn                = 95,      
  I2C4_ER_IRQn                = 96,      
  SPDIF_RX_IRQn               = 97,      
  DSI_IRQn                    = 98,      
  DFSDM1_FLT0_IRQn	          = 99,      
  DFSDM1_FLT1_IRQn	          = 100,     
  DFSDM1_FLT2_IRQn	          = 101,     
  DFSDM1_FLT3_IRQn	          = 102,     
  SDMMC2_IRQn                 = 103,     
  CAN3_TX_IRQn                = 104,     
  CAN3_RX0_IRQn               = 105,     
  CAN3_RX1_IRQn               = 106,     
  CAN3_SCE_IRQn               = 107,     
  JPEG_IRQn                   = 108,     
  MDIOS_IRQn                  = 109      
} IRQn_Type;



 



 
#line 204 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

#line 1 "C:\\Bin\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.0.1\\CMSIS\\Include\\core_cm7.h"
 




 
















 










#line 35 "C:\\Bin\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.0.1\\CMSIS\\Include\\core_cm7.h"


 extern "C" {














 




 



 

 









 
#line 85 "C:\\Bin\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.0.1\\CMSIS\\Include\\core_cm7.h"

#line 159 "C:\\Bin\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.0.1\\CMSIS\\Include\\core_cm7.h"

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











 
static __inline uint32_t __get_FPSCR(void)
{


  register uint32_t __regfpscr         __asm("fpscr");
  return(__regfpscr);



}






 
static __inline void __set_FPSCR(uint32_t fpscr)
{


  register uint32_t __regfpscr         __asm("fpscr");
  __regfpscr = (fpscr);



}





 


 



 




 






 







 






 








 










 










 











 








 

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








 








 








 








 








 








 





   


 



 



#line 783 "C:\\Bin\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.0.1\\CMSIS\\Include\\cmsis_armcc.h"











 


#line 35 "C:\\Bin\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.0.1\\CMSIS\\Include\\cmsis_compiler.h"




 
#line 220 "C:\\Bin\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.0.1\\CMSIS\\Include\\cmsis_compiler.h"




#line 161 "C:\\Bin\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.0.1\\CMSIS\\Include\\core_cm7.h"



}










 extern "C" {


 
#line 220 "C:\\Bin\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.0.1\\CMSIS\\Include\\core_cm7.h"

 






 
#line 236 "C:\\Bin\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.0.1\\CMSIS\\Include\\core_cm7.h"

 




 













 



 






 



 
typedef union
{
  struct
  {
    uint32_t _reserved0:16;               
    uint32_t GE:4;                        
    uint32_t _reserved1:7;                
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
    uint32_t GE:4;                        
    uint32_t _reserved1:4;                
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
    uint32_t FPCA:1;                      
    uint32_t _reserved0:29;               
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
  volatile uint8_t  SHPR[12U];               
  volatile uint32_t SHCSR;                   
  volatile uint32_t CFSR;                    
  volatile uint32_t HFSR;                    
  volatile uint32_t DFSR;                    
  volatile uint32_t MMFAR;                   
  volatile uint32_t BFAR;                    
  volatile uint32_t AFSR;                    
  volatile const  uint32_t ID_PFR[2U];              
  volatile const  uint32_t ID_DFR;                  
  volatile const  uint32_t ID_AFR;                  
  volatile const  uint32_t ID_MFR[4U];              
  volatile const  uint32_t ID_ISAR[5U];             
        uint32_t RESERVED0[1U];
  volatile const  uint32_t CLIDR;                   
  volatile const  uint32_t CTR;                     
  volatile const  uint32_t CCSIDR;                  
  volatile uint32_t CSSELR;                  
  volatile uint32_t CPACR;                   
        uint32_t RESERVED3[93U];
  volatile  uint32_t STIR;                    
        uint32_t RESERVED4[15U];
  volatile const  uint32_t MVFR0;                   
  volatile const  uint32_t MVFR1;                   
  volatile const  uint32_t MVFR2;                   
        uint32_t RESERVED5[1U];
  volatile  uint32_t ICIALLU;                 
        uint32_t RESERVED6[1U];
  volatile  uint32_t ICIMVAU;                 
  volatile  uint32_t DCIMVAC;                 
  volatile  uint32_t DCISW;                   
  volatile  uint32_t DCCMVAU;                 
  volatile  uint32_t DCCMVAC;                 
  volatile  uint32_t DCCSW;                   
  volatile  uint32_t DCCIMVAC;                
  volatile  uint32_t DCCISW;                  
        uint32_t RESERVED7[6U];
  volatile uint32_t ITCMCR;                  
  volatile uint32_t DTCMCR;                  
  volatile uint32_t AHBPCR;                  
  volatile uint32_t CACR;                    
  volatile uint32_t AHBSCR;                  
        uint32_t RESERVED8[1U];
  volatile uint32_t ABFSR;                   
} SCB_Type;

 















 






























 



 





















 









 



























 










































 









 


















 





















 


















 









 















 






 















 





















 






 



 






 






 






 












 












 






 









 









 


















 







 



 
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
        uint32_t RESERVED3[981U];
  volatile  uint32_t LAR;                     
  volatile const  uint32_t LSR;                     
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
        uint32_t RESERVED0[1U];
  volatile uint32_t FPCCR;                   
  volatile uint32_t FPCAR;                   
  volatile uint32_t FPDSCR;                  
  volatile const  uint32_t MVFR0;                   
  volatile const  uint32_t MVFR1;                   
  volatile const  uint32_t MVFR2;                   
} FPU_Type;

 



























 



 












 
























 












 

 







 



 
typedef struct
{
  volatile uint32_t DHCSR;                   
  volatile  uint32_t DCRSR;                   
  volatile uint32_t DCRDR;                   
  volatile uint32_t DEMCR;                   
} CoreDebug_Type;

 




































 






 







































 







 






 







 


 







 

 
#line 1760 "C:\\Bin\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.0.1\\CMSIS\\Include\\core_cm7.h"

#line 1769 "C:\\Bin\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.0.1\\CMSIS\\Include\\core_cm7.h"









 










 


 



 





 

#line 1817 "C:\\Bin\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.0.1\\CMSIS\\Include\\core_cm7.h"


















 
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
    ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->IP[((uint32_t)(int32_t)IRQn)]                = (uint8_t)((priority << (8U - 4)) & (uint32_t)0xFFUL);
  }
  else
  {
    ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->SHPR[(((uint32_t)(int32_t)IRQn) & 0xFUL)-4UL] = (uint8_t)((priority << (8U - 4)) & (uint32_t)0xFFUL);
  }
}










 
static __inline uint32_t __NVIC_GetPriority(IRQn_Type IRQn)
{

  if ((int32_t)(IRQn) >= 0)
  {
    return(((uint32_t)((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->IP[((uint32_t)(int32_t)IRQn)]                >> (8U - 4)));
  }
  else
  {
    return(((uint32_t)((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->SHPR[(((uint32_t)(int32_t)IRQn) & 0xFUL)-4UL] >> (8U - 4)));
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





 
static __inline void NVIC_SystemReset(void)
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
  uint32_t mvfr0;

  mvfr0 = ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->MVFR0;
  if      ((mvfr0 & ((0xFUL << 4U) | (0xFUL << 8U))) == 0x220U)
  {
    return 2U;            
  }
  else if ((mvfr0 & ((0xFUL << 4U) | (0xFUL << 8U))) == 0x020U)
  {
    return 1U;            
  }
  else
  {
    return 0U;            
  }
}


 



 





 

 







 
static __inline void SCB_EnableICache (void)
{

    do { __schedule_barrier(); __dsb(0xF); __schedule_barrier(); } while (0U);
    do { __schedule_barrier(); __isb(0xF); __schedule_barrier(); } while (0U);
    ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->ICIALLU = 0UL;                      
    do { __schedule_barrier(); __dsb(0xF); __schedule_barrier(); } while (0U);
    do { __schedule_barrier(); __isb(0xF); __schedule_barrier(); } while (0U);
    ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->CCR |=  (uint32_t)(1UL << 17U);   
    do { __schedule_barrier(); __dsb(0xF); __schedule_barrier(); } while (0U);
    do { __schedule_barrier(); __isb(0xF); __schedule_barrier(); } while (0U);

}





 
static __inline void SCB_DisableICache (void)
{

    do { __schedule_barrier(); __dsb(0xF); __schedule_barrier(); } while (0U);
    do { __schedule_barrier(); __isb(0xF); __schedule_barrier(); } while (0U);
    ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->CCR &= ~(uint32_t)(1UL << 17U);   
    ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->ICIALLU = 0UL;                      
    do { __schedule_barrier(); __dsb(0xF); __schedule_barrier(); } while (0U);
    do { __schedule_barrier(); __isb(0xF); __schedule_barrier(); } while (0U);

}





 
static __inline void SCB_InvalidateICache (void)
{

    do { __schedule_barrier(); __dsb(0xF); __schedule_barrier(); } while (0U);
    do { __schedule_barrier(); __isb(0xF); __schedule_barrier(); } while (0U);
    ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->ICIALLU = 0UL;
    do { __schedule_barrier(); __dsb(0xF); __schedule_barrier(); } while (0U);
    do { __schedule_barrier(); __isb(0xF); __schedule_barrier(); } while (0U);

}





 
static __inline void SCB_EnableDCache (void)
{

    uint32_t ccsidr;
    uint32_t sets;
    uint32_t ways;

    ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->CSSELR = 0U;     
    do { __schedule_barrier(); __dsb(0xF); __schedule_barrier(); } while (0U);

    ccsidr = ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->CCSIDR;

                                             
    sets = (uint32_t)((((ccsidr) & (0x7FFFUL << 13U) ) >> 13U ));
    do {
      ways = (uint32_t)((((ccsidr) & (0x3FFUL << 3U)) >> 3U));
      do {
        ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->DCISW = (((sets << 5U) & (0x1FFUL << 5U)) |
                      ((ways << 30U) & (3UL << 30U))  );

          __schedule_barrier();

      } while (ways-- != 0U);
    } while(sets-- != 0U);
    do { __schedule_barrier(); __dsb(0xF); __schedule_barrier(); } while (0U);

    ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->CCR |=  (uint32_t)(1UL << 16U);   

    do { __schedule_barrier(); __dsb(0xF); __schedule_barrier(); } while (0U);
    do { __schedule_barrier(); __isb(0xF); __schedule_barrier(); } while (0U);

}





 
static __inline void SCB_DisableDCache (void)
{

    register uint32_t ccsidr;
    register uint32_t sets;
    register uint32_t ways;

    ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->CSSELR = 0U;     
    do { __schedule_barrier(); __dsb(0xF); __schedule_barrier(); } while (0U);

    ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->CCR &= ~(uint32_t)(1UL << 16U);   
    do { __schedule_barrier(); __dsb(0xF); __schedule_barrier(); } while (0U);

    ccsidr = ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->CCSIDR;

                                             
    sets = (uint32_t)((((ccsidr) & (0x7FFFUL << 13U) ) >> 13U ));
    do {
      ways = (uint32_t)((((ccsidr) & (0x3FFUL << 3U)) >> 3U));
      do {
        ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->DCCISW = (((sets << 5U) & (0x1FFUL << 5U)) |
                       ((ways << 30U) & (3UL << 30U))  );

          __schedule_barrier();

      } while (ways-- != 0U);
    } while(sets-- != 0U);

    do { __schedule_barrier(); __dsb(0xF); __schedule_barrier(); } while (0U);
    do { __schedule_barrier(); __isb(0xF); __schedule_barrier(); } while (0U);

}





 
static __inline void SCB_InvalidateDCache (void)
{

    uint32_t ccsidr;
    uint32_t sets;
    uint32_t ways;

    ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->CSSELR = 0U;     
    do { __schedule_barrier(); __dsb(0xF); __schedule_barrier(); } while (0U);

    ccsidr = ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->CCSIDR;

                                             
    sets = (uint32_t)((((ccsidr) & (0x7FFFUL << 13U) ) >> 13U ));
    do {
      ways = (uint32_t)((((ccsidr) & (0x3FFUL << 3U)) >> 3U));
      do {
        ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->DCISW = (((sets << 5U) & (0x1FFUL << 5U)) |
                      ((ways << 30U) & (3UL << 30U))  );

          __schedule_barrier();

      } while (ways-- != 0U);
    } while(sets-- != 0U);

    do { __schedule_barrier(); __dsb(0xF); __schedule_barrier(); } while (0U);
    do { __schedule_barrier(); __isb(0xF); __schedule_barrier(); } while (0U);

}





 
static __inline void SCB_CleanDCache (void)
{

    uint32_t ccsidr;
    uint32_t sets;
    uint32_t ways;

     ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->CSSELR = 0U;     
   do { __schedule_barrier(); __dsb(0xF); __schedule_barrier(); } while (0U);

    ccsidr = ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->CCSIDR;

                                             
    sets = (uint32_t)((((ccsidr) & (0x7FFFUL << 13U) ) >> 13U ));
    do {
      ways = (uint32_t)((((ccsidr) & (0x3FFUL << 3U)) >> 3U));
      do {
        ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->DCCSW = (((sets << 5U) & (0x1FFUL << 5U)) |
                      ((ways << 30U) & (3UL << 30U))  );

          __schedule_barrier();

      } while (ways-- != 0U);
    } while(sets-- != 0U);

    do { __schedule_barrier(); __dsb(0xF); __schedule_barrier(); } while (0U);
    do { __schedule_barrier(); __isb(0xF); __schedule_barrier(); } while (0U);

}





 
static __inline void SCB_CleanInvalidateDCache (void)
{

    uint32_t ccsidr;
    uint32_t sets;
    uint32_t ways;

    ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->CSSELR = 0U;     
    do { __schedule_barrier(); __dsb(0xF); __schedule_barrier(); } while (0U);

    ccsidr = ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->CCSIDR;

                                             
    sets = (uint32_t)((((ccsidr) & (0x7FFFUL << 13U) ) >> 13U ));
    do {
      ways = (uint32_t)((((ccsidr) & (0x3FFUL << 3U)) >> 3U));
      do {
        ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->DCCISW = (((sets << 5U) & (0x1FFUL << 5U)) |
                       ((ways << 30U) & (3UL << 30U))  );

          __schedule_barrier();

      } while (ways-- != 0U);
    } while(sets-- != 0U);

    do { __schedule_barrier(); __dsb(0xF); __schedule_barrier(); } while (0U);
    do { __schedule_barrier(); __isb(0xF); __schedule_barrier(); } while (0U);

}







 
static __inline void SCB_InvalidateDCache_by_Addr (uint32_t *addr, int32_t dsize)
{

     int32_t op_size = dsize;
    uint32_t op_addr = (uint32_t)addr;
     int32_t linesize = 32;                 

    do { __schedule_barrier(); __dsb(0xF); __schedule_barrier(); } while (0U);

    while (op_size > 0) {
      ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->DCIMVAC = op_addr;
      op_addr += (uint32_t)linesize;
      op_size -=           linesize;
    }

    do { __schedule_barrier(); __dsb(0xF); __schedule_barrier(); } while (0U);
    do { __schedule_barrier(); __isb(0xF); __schedule_barrier(); } while (0U);

}







 
static __inline void SCB_CleanDCache_by_Addr (uint32_t *addr, int32_t dsize)
{

     int32_t op_size = dsize;
    uint32_t op_addr = (uint32_t) addr;
     int32_t linesize = 32;                 

    do { __schedule_barrier(); __dsb(0xF); __schedule_barrier(); } while (0U);

    while (op_size > 0) {
      ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->DCCMVAC = op_addr;
      op_addr += (uint32_t)linesize;
      op_size -=           linesize;
    }

    do { __schedule_barrier(); __dsb(0xF); __schedule_barrier(); } while (0U);
    do { __schedule_barrier(); __isb(0xF); __schedule_barrier(); } while (0U);

}







 
static __inline void SCB_CleanInvalidateDCache_by_Addr (uint32_t *addr, int32_t dsize)
{

     int32_t op_size = dsize;
    uint32_t op_addr = (uint32_t) addr;
     int32_t linesize = 32;                 

    do { __schedule_barrier(); __dsb(0xF); __schedule_barrier(); } while (0U);

    while (op_size > 0) {
      ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->DCCIMVAC = op_addr;
      op_addr += (uint32_t)linesize;
      op_size -=           linesize;
    }

    do { __schedule_barrier(); __dsb(0xF); __schedule_barrier(); } while (0U);
    do { __schedule_barrier(); __isb(0xF); __schedule_barrier(); } while (0U);

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




#line 206 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"


#line 1 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f7xx.h"













































 



 



 
    
#line 218 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f7xx.h"



 

  

 

 
#line 209 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"
#line 210 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"



 



 

typedef struct
{
  volatile uint32_t SR;      
  volatile uint32_t CR1;     
  volatile uint32_t CR2;     
  volatile uint32_t SMPR1;   
  volatile uint32_t SMPR2;   
  volatile uint32_t JOFR1;   
  volatile uint32_t JOFR2;   
  volatile uint32_t JOFR3;   
  volatile uint32_t JOFR4;   
  volatile uint32_t HTR;     
  volatile uint32_t LTR;     
  volatile uint32_t SQR1;    
  volatile uint32_t SQR2;    
  volatile uint32_t SQR3;    
  volatile uint32_t JSQR;    
  volatile uint32_t JDR1;    
  volatile uint32_t JDR2;    
  volatile uint32_t JDR3;    
  volatile uint32_t JDR4;    
  volatile uint32_t DR;      
} ADC_TypeDef;

typedef struct
{
  volatile uint32_t CSR;     
  volatile uint32_t CCR;     
  volatile uint32_t CDR;    
 
} ADC_Common_TypeDef;




 

typedef struct
{
  volatile uint32_t TIR;   
  volatile uint32_t TDTR;  
  volatile uint32_t TDLR;  
  volatile uint32_t TDHR;  
} CAN_TxMailBox_TypeDef;



 

typedef struct
{
  volatile uint32_t RIR;   
  volatile uint32_t RDTR;  
  volatile uint32_t RDLR;  
  volatile uint32_t RDHR;  
} CAN_FIFOMailBox_TypeDef;



 

typedef struct
{
  volatile uint32_t FR1;  
  volatile uint32_t FR2;  
} CAN_FilterRegister_TypeDef;



 

typedef struct
{
  volatile uint32_t              MCR;                  
  volatile uint32_t              MSR;                  
  volatile uint32_t              TSR;                  
  volatile uint32_t              RF0R;                 
  volatile uint32_t              RF1R;                 
  volatile uint32_t              IER;                  
  volatile uint32_t              ESR;                  
  volatile uint32_t              BTR;                  
  uint32_t                   RESERVED0[88];        
  CAN_TxMailBox_TypeDef      sTxMailBox[3];        
  CAN_FIFOMailBox_TypeDef    sFIFOMailBox[2];      
  uint32_t                   RESERVED1[12];        
  volatile uint32_t              FMR;                  
  volatile uint32_t              FM1R;                 
  uint32_t                   RESERVED2;            
  volatile uint32_t              FS1R;                 
  uint32_t                   RESERVED3;            
  volatile uint32_t              FFA1R;                
  uint32_t                   RESERVED4;            
  volatile uint32_t              FA1R;                 
  uint32_t                   RESERVED5[8];         
  CAN_FilterRegister_TypeDef sFilterRegister[28];  
} CAN_TypeDef;



 

typedef struct
{
  volatile uint32_t CR;            
  volatile uint32_t CFGR;          
  volatile uint32_t TXDR;          
  volatile uint32_t RXDR;          
  volatile uint32_t ISR;           
  volatile uint32_t IER;           
}CEC_TypeDef;



 

typedef struct
{
  volatile uint32_t  DR;           
  volatile uint8_t   IDR;          
  uint8_t        RESERVED0;    
  uint16_t       RESERVED1;    
  volatile uint32_t  CR;           
  uint32_t       RESERVED2;    
  volatile uint32_t  INIT;         
  volatile uint32_t  POL;          
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
  volatile uint32_t FLTCR1;          
  volatile uint32_t FLTCR2;          
  volatile uint32_t FLTISR;          
  volatile uint32_t FLTICR;          
  volatile uint32_t FLTJCHGR;        
  volatile uint32_t FLTFCR;          
  volatile uint32_t FLTJDATAR;       
  volatile uint32_t FLTRDATAR;       
  volatile uint32_t FLTAWHTR;        
  volatile uint32_t FLTAWLTR;        
  volatile uint32_t FLTAWSR;         
  volatile uint32_t FLTAWCFR;        
  volatile uint32_t FLTEXMAX;        
  volatile uint32_t FLTEXMIN;        
  volatile uint32_t FLTCNVTIMR;      
} DFSDM_Filter_TypeDef;



 
typedef struct
{
  volatile uint32_t CHCFGR1;      
  volatile uint32_t CHCFGR2;      
  volatile uint32_t CHAWSCDR;    
 
  volatile uint32_t CHWDATAR;     
  volatile uint32_t CHDATINR;     
} DFSDM_Channel_TypeDef;



 

typedef struct
{
  volatile uint32_t IDCODE;   
  volatile uint32_t CR;       
  volatile uint32_t APB1FZ;   
  volatile uint32_t APB2FZ;   
}DBGMCU_TypeDef;



 

typedef struct
{
  volatile uint32_t CR;        
  volatile uint32_t SR;        
  volatile uint32_t RISR;      
  volatile uint32_t IER;       
  volatile uint32_t MISR;      
  volatile uint32_t ICR;       
  volatile uint32_t ESCR;      
  volatile uint32_t ESUR;      
  volatile uint32_t CWSTRTR;   
  volatile uint32_t CWSIZER;   
  volatile uint32_t DR;        
} DCMI_TypeDef;



 

typedef struct
{
  volatile uint32_t CR;      
  volatile uint32_t NDTR;    
  volatile uint32_t PAR;     
  volatile uint32_t M0AR;    
  volatile uint32_t M1AR;    
  volatile uint32_t FCR;     
} DMA_Stream_TypeDef;

typedef struct
{
  volatile uint32_t LISR;    
  volatile uint32_t HISR;    
  volatile uint32_t LIFCR;   
  volatile uint32_t HIFCR;   
} DMA_TypeDef;



 

typedef struct
{
  volatile uint32_t CR;             
  volatile uint32_t ISR;            
  volatile uint32_t IFCR;           
  volatile uint32_t FGMAR;          
  volatile uint32_t FGOR;           
  volatile uint32_t BGMAR;          
  volatile uint32_t BGOR;           
  volatile uint32_t FGPFCCR;        
  volatile uint32_t FGCOLR;         
  volatile uint32_t BGPFCCR;        
  volatile uint32_t BGCOLR;         
  volatile uint32_t FGCMAR;         
  volatile uint32_t BGCMAR;         
  volatile uint32_t OPFCCR;         
  volatile uint32_t OCOLR;          
  volatile uint32_t OMAR;           
  volatile uint32_t OOR;            
  volatile uint32_t NLR;            
  volatile uint32_t LWR;            
  volatile uint32_t AMTCR;          
  uint32_t      RESERVED[236];  
  volatile uint32_t FGCLUT[256];    
  volatile uint32_t BGCLUT[256];    
} DMA2D_TypeDef;




 

typedef struct
{
  volatile uint32_t MACCR;
  volatile uint32_t MACFFR;
  volatile uint32_t MACHTHR;
  volatile uint32_t MACHTLR;
  volatile uint32_t MACMIIAR;
  volatile uint32_t MACMIIDR;
  volatile uint32_t MACFCR;
  volatile uint32_t MACVLANTR;              
  uint32_t      RESERVED0[2];
  volatile uint32_t MACRWUFFR;              
  volatile uint32_t MACPMTCSR;
  uint32_t      RESERVED1;
  volatile uint32_t MACDBGR;
  volatile uint32_t MACSR;                  
  volatile uint32_t MACIMR;
  volatile uint32_t MACA0HR;
  volatile uint32_t MACA0LR;
  volatile uint32_t MACA1HR;
  volatile uint32_t MACA1LR;
  volatile uint32_t MACA2HR;
  volatile uint32_t MACA2LR;
  volatile uint32_t MACA3HR;
  volatile uint32_t MACA3LR;                
  uint32_t      RESERVED2[40];
  volatile uint32_t MMCCR;                  
  volatile uint32_t MMCRIR;
  volatile uint32_t MMCTIR;
  volatile uint32_t MMCRIMR;
  volatile uint32_t MMCTIMR;                
  uint32_t      RESERVED3[14];
  volatile uint32_t MMCTGFSCCR;             
  volatile uint32_t MMCTGFMSCCR;
  uint32_t      RESERVED4[5];
  volatile uint32_t MMCTGFCR;
  uint32_t      RESERVED5[10];
  volatile uint32_t MMCRFCECR;
  volatile uint32_t MMCRFAECR;
  uint32_t      RESERVED6[10];
  volatile uint32_t MMCRGUFCR;
  uint32_t      RESERVED7[334];
  volatile uint32_t PTPTSCR;
  volatile uint32_t PTPSSIR;
  volatile uint32_t PTPTSHR;
  volatile uint32_t PTPTSLR;
  volatile uint32_t PTPTSHUR;
  volatile uint32_t PTPTSLUR;
  volatile uint32_t PTPTSAR;
  volatile uint32_t PTPTTHR;
  volatile uint32_t PTPTTLR;
  volatile uint32_t RESERVED8;
  volatile uint32_t PTPTSSR;
  uint32_t      RESERVED9[565];
  volatile uint32_t DMABMR;
  volatile uint32_t DMATPDR;
  volatile uint32_t DMARPDR;
  volatile uint32_t DMARDLAR;
  volatile uint32_t DMATDLAR;
  volatile uint32_t DMASR;
  volatile uint32_t DMAOMR;
  volatile uint32_t DMAIER;
  volatile uint32_t DMAMFBOCR;
  volatile uint32_t DMARSWTR;
  uint32_t      RESERVED10[8];
  volatile uint32_t DMACHTDR;
  volatile uint32_t DMACHRDR;
  volatile uint32_t DMACHTBAR;
  volatile uint32_t DMACHRBAR;
} ETH_TypeDef;



 

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
  volatile uint32_t KEYR;      
  volatile uint32_t OPTKEYR;   
  volatile uint32_t SR;        
  volatile uint32_t CR;        
  volatile uint32_t OPTCR;     
  volatile uint32_t OPTCR1;    
} FLASH_TypeDef;





 

typedef struct
{
  volatile uint32_t BTCR[8];     
} FMC_Bank1_TypeDef;



 

typedef struct
{
  volatile uint32_t BWTR[7];     
} FMC_Bank1E_TypeDef;



 

typedef struct
{
  volatile uint32_t PCR;         
  volatile uint32_t SR;          
  volatile uint32_t PMEM;        
  volatile uint32_t PATT;        
  uint32_t      RESERVED0;   
  volatile uint32_t ECCR;        
} FMC_Bank3_TypeDef;



 

typedef struct
{
  volatile uint32_t SDCR[2];         
  volatile uint32_t SDTR[2];         
  volatile uint32_t SDCMR;        
  volatile uint32_t SDRTR;        
  volatile uint32_t SDSR;         
} FMC_Bank5_6_TypeDef;




 

typedef struct
{
  volatile uint32_t MODER;     
  volatile uint32_t OTYPER;    
  volatile uint32_t OSPEEDR;   
  volatile uint32_t PUPDR;     
  volatile uint32_t IDR;       
  volatile uint32_t ODR;       
  volatile uint32_t BSRR;      
  volatile uint32_t LCKR;      
  volatile uint32_t AFR[2];    
} GPIO_TypeDef;



 

typedef struct
{
  volatile uint32_t MEMRMP;        
  volatile uint32_t PMC;           
  volatile uint32_t EXTICR[4];     
  uint32_t      RESERVED;      
  volatile uint32_t CBR;           
  volatile uint32_t CMPCR;         
} SYSCFG_TypeDef;



 

typedef struct
{
  volatile uint32_t CR1;       
  volatile uint32_t CR2;       
  volatile uint32_t OAR1;      
  volatile uint32_t OAR2;      
  volatile uint32_t TIMINGR;   
  volatile uint32_t TIMEOUTR;  
  volatile uint32_t ISR;       
  volatile uint32_t ICR;       
  volatile uint32_t PECR;      
  volatile uint32_t RXDR;      
  volatile uint32_t TXDR;      
} I2C_TypeDef;



 

typedef struct
{
  volatile uint32_t KR;    
  volatile uint32_t PR;    
  volatile uint32_t RLR;   
  volatile uint32_t SR;    
  volatile uint32_t WINR;  
} IWDG_TypeDef;




 

typedef struct
{
  uint32_t      RESERVED0[2];   
  volatile uint32_t SSCR;           
  volatile uint32_t BPCR;           
  volatile uint32_t AWCR;           
  volatile uint32_t TWCR;           
  volatile uint32_t GCR;            
  uint32_t      RESERVED1[2];   
  volatile uint32_t SRCR;           
  uint32_t      RESERVED2[1];   
  volatile uint32_t BCCR;           
  uint32_t      RESERVED3[1];   
  volatile uint32_t IER;            
  volatile uint32_t ISR;            
  volatile uint32_t ICR;            
  volatile uint32_t LIPCR;          
  volatile uint32_t CPSR;           
  volatile uint32_t CDSR;          
} LTDC_TypeDef;



 

typedef struct
{
  volatile uint32_t CR;             
  volatile uint32_t WHPCR;          
  volatile uint32_t WVPCR;          
  volatile uint32_t CKCR;           
  volatile uint32_t PFCR;           
  volatile uint32_t CACR;           
  volatile uint32_t DCCR;           
  volatile uint32_t BFCR;           
  uint32_t      RESERVED0[2];   
  volatile uint32_t CFBAR;          
  volatile uint32_t CFBLR;          
  volatile uint32_t CFBLNR;         
  uint32_t      RESERVED1[3];   
  volatile uint32_t CLUTWR;         

} LTDC_Layer_TypeDef;



 

typedef struct
{
  volatile uint32_t CR1;    
  volatile uint32_t CSR1;   
  volatile uint32_t CR2;    
  volatile uint32_t CSR2;   
} PWR_TypeDef;




 

typedef struct
{
  volatile uint32_t CR;             
  volatile uint32_t PLLCFGR;        
  volatile uint32_t CFGR;           
  volatile uint32_t CIR;            
  volatile uint32_t AHB1RSTR;       
  volatile uint32_t AHB2RSTR;       
  volatile uint32_t AHB3RSTR;       
  uint32_t      RESERVED0;      
  volatile uint32_t APB1RSTR;       
  volatile uint32_t APB2RSTR;       
  uint32_t      RESERVED1[2];   
  volatile uint32_t AHB1ENR;        
  volatile uint32_t AHB2ENR;        
  volatile uint32_t AHB3ENR;        
  uint32_t      RESERVED2;      
  volatile uint32_t APB1ENR;        
  volatile uint32_t APB2ENR;        
  uint32_t      RESERVED3[2];   
  volatile uint32_t AHB1LPENR;      
  volatile uint32_t AHB2LPENR;      
  volatile uint32_t AHB3LPENR;      
  uint32_t      RESERVED4;      
  volatile uint32_t APB1LPENR;      
  volatile uint32_t APB2LPENR;      
  uint32_t      RESERVED5[2];   
  volatile uint32_t BDCR;           
  volatile uint32_t CSR;            
  uint32_t      RESERVED6[2];   
  volatile uint32_t SSCGR;          
  volatile uint32_t PLLI2SCFGR;     
  volatile uint32_t PLLSAICFGR;     
  volatile uint32_t DCKCFGR1;       
  volatile uint32_t DCKCFGR2;       

} RCC_TypeDef;



 

typedef struct
{
  volatile uint32_t TR;          
  volatile uint32_t DR;          
  volatile uint32_t CR;          
  volatile uint32_t ISR;         
  volatile uint32_t PRER;        
  volatile uint32_t WUTR;        
       uint32_t reserved;    
  volatile uint32_t ALRMAR;      
  volatile uint32_t ALRMBR;      
  volatile uint32_t WPR;         
  volatile uint32_t SSR;         
  volatile uint32_t SHIFTR;      
  volatile uint32_t TSTR;        
  volatile uint32_t TSDR;        
  volatile uint32_t TSSSR;       
  volatile uint32_t CALR;        
  volatile uint32_t TAMPCR;      
  volatile uint32_t ALRMASSR;    
  volatile uint32_t ALRMBSSR;    
  volatile uint32_t OR;          
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
  volatile uint32_t GCR;       
} SAI_TypeDef;

typedef struct
{
  volatile uint32_t CR1;       
  volatile uint32_t CR2;       
  volatile uint32_t FRCR;      
  volatile uint32_t SLOTR;     
  volatile uint32_t IMR;       
  volatile uint32_t SR;        
  volatile uint32_t CLRFR;     
  volatile uint32_t DR;        
} SAI_Block_TypeDef;



 

typedef struct
{
  volatile uint32_t   CR;            
  volatile uint32_t   IMR;           
  volatile uint32_t   SR;            
  volatile uint32_t   IFCR;          
  volatile uint32_t   DR;            
  volatile uint32_t   CSR;           
  volatile uint32_t   DIR;           
} SPDIFRX_TypeDef;



 

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
} SDMMC_TypeDef;



 

typedef struct
{
  volatile uint32_t CR1;         
  volatile uint32_t CR2;         
  volatile uint32_t SR;          
  volatile uint32_t DR;          
  volatile uint32_t CRCPR;       
  volatile uint32_t RXCRCR;      
  volatile uint32_t TXCRCR;      
  volatile uint32_t I2SCFGR;     
  volatile uint32_t I2SPR;       
} SPI_TypeDef;



 

typedef struct
{
  volatile uint32_t CR;        
  volatile uint32_t DCR;       
  volatile uint32_t SR;        
  volatile uint32_t FCR;       
  volatile uint32_t DLR;       
  volatile uint32_t CCR;       
  volatile uint32_t AR;        
  volatile uint32_t ABR;       
  volatile uint32_t DR;        
  volatile uint32_t PSMKR;     
  volatile uint32_t PSMAR;     
  volatile uint32_t PIR;       
  volatile uint32_t LPTR;      
} QUADSPI_TypeDef;



 

typedef struct
{
  volatile uint32_t CR1;          
  volatile uint32_t CR2;          
  volatile uint32_t SMCR;         
  volatile uint32_t DIER;         
  volatile uint32_t SR;           
  volatile uint32_t EGR;          
  volatile uint32_t CCMR1;        
  volatile uint32_t CCMR2;        
  volatile uint32_t CCER;         
  volatile uint32_t CNT;          
  volatile uint32_t PSC;          
  volatile uint32_t ARR;          
  volatile uint32_t RCR;          
  volatile uint32_t CCR1;         
  volatile uint32_t CCR2;         
  volatile uint32_t CCR3;         
  volatile uint32_t CCR4;         
  volatile uint32_t BDTR;         
  volatile uint32_t DCR;          
  volatile uint32_t DMAR;         
  volatile uint32_t OR;           
  volatile uint32_t CCMR3;        
  volatile uint32_t CCR5;         
  volatile uint32_t CCR6;         
  volatile uint32_t AF1;          
  volatile uint32_t AF2;          

} TIM_TypeDef;



 
typedef struct
{
  volatile uint32_t ISR;       
  volatile uint32_t ICR;       
  volatile uint32_t IER;       
  volatile uint32_t CFGR;      
  volatile uint32_t CR;        
  volatile uint32_t CMP;       
  volatile uint32_t ARR;       
  volatile uint32_t CNT;       
} LPTIM_TypeDef;




 

typedef struct
{
  volatile uint32_t CR1;     
  volatile uint32_t CR2;     
  volatile uint32_t CR3;     
  volatile uint32_t BRR;     
  volatile uint32_t GTPR;    
  volatile uint32_t RTOR;    
  volatile uint32_t RQR;     
  volatile uint32_t ISR;     
  volatile uint32_t ICR;     
  volatile uint32_t RDR;     
  volatile uint32_t TDR;     
} USART_TypeDef;




 

typedef struct
{
  volatile uint32_t CR;    
  volatile uint32_t CFR;   
  volatile uint32_t SR;    
} WWDG_TypeDef;




 

typedef struct
{
  volatile uint32_t CR;   
  volatile uint32_t SR;   
  volatile uint32_t DR;   
} RNG_TypeDef;



 



 
typedef struct
{
 volatile uint32_t GOTGCTL;                
  volatile uint32_t GOTGINT;               
  volatile uint32_t GAHBCFG;               
  volatile uint32_t GUSBCFG;               
  volatile uint32_t GRSTCTL;               
  volatile uint32_t GINTSTS;               
  volatile uint32_t GINTMSK;               
  volatile uint32_t GRXSTSR;               
  volatile uint32_t GRXSTSP;               
  volatile uint32_t GRXFSIZ;               
  volatile uint32_t DIEPTXF0_HNPTXFSIZ;    
  volatile uint32_t HNPTXSTS;              
  uint32_t Reserved30[2];              
  volatile uint32_t GCCFG;                 
  volatile uint32_t CID;                   
  uint32_t  Reserved5[3];              
  volatile uint32_t GHWCFG3;               
  uint32_t  Reserved6;                 
  volatile uint32_t GLPMCFG;               
  volatile uint32_t GPWRDN;                
  volatile uint32_t GDFIFOCFG;             
   volatile uint32_t GADPCTL;              
    uint32_t  Reserved43[39];          
  volatile uint32_t HPTXFSIZ;              
  volatile uint32_t DIEPTXF[0x0F];         
} USB_OTG_GlobalTypeDef;




 
typedef struct
{
  volatile uint32_t DCFG;             
  volatile uint32_t DCTL;             
  volatile uint32_t DSTS;             
  uint32_t Reserved0C;            
  volatile uint32_t DIEPMSK;          
  volatile uint32_t DOEPMSK;          
  volatile uint32_t DAINT;            
  volatile uint32_t DAINTMSK;         
  uint32_t  Reserved20;           
  uint32_t Reserved9;             
  volatile uint32_t DVBUSDIS;         
  volatile uint32_t DVBUSPULSE;       
  volatile uint32_t DTHRCTL;          
  volatile uint32_t DIEPEMPMSK;       
  volatile uint32_t DEACHINT;         
  volatile uint32_t DEACHMSK;         
  uint32_t Reserved40;            
  volatile uint32_t DINEP1MSK;        
  uint32_t  Reserved44[15];       
  volatile uint32_t DOUTEP1MSK;       
} USB_OTG_DeviceTypeDef;




 
typedef struct
{
  volatile uint32_t DIEPCTL;            
  uint32_t Reserved04;              
  volatile uint32_t DIEPINT;            
  uint32_t Reserved0C;              
  volatile uint32_t DIEPTSIZ;           
  volatile uint32_t DIEPDMA;            
  volatile uint32_t DTXFSTS;            
  uint32_t Reserved18;              
} USB_OTG_INEndpointTypeDef;




 
typedef struct
{
  volatile uint32_t DOEPCTL;        
  uint32_t Reserved04;          
  volatile uint32_t DOEPINT;        
  uint32_t Reserved0C;          
  volatile uint32_t DOEPTSIZ;       
  volatile uint32_t DOEPDMA;        
  uint32_t Reserved18[2];       
} USB_OTG_OUTEndpointTypeDef;




 
typedef struct
{
  volatile uint32_t HCFG;              
  volatile uint32_t HFIR;              
  volatile uint32_t HFNUM;             
  uint32_t Reserved40C;            
  volatile uint32_t HPTXSTS;           
  volatile uint32_t HAINT;             
  volatile uint32_t HAINTMSK;          
} USB_OTG_HostTypeDef;



 
typedef struct
{
  volatile uint32_t HCCHAR;            
  volatile uint32_t HCSPLT;            
  volatile uint32_t HCINT;             
  volatile uint32_t HCINTMSK;          
  volatile uint32_t HCTSIZ;            
  volatile uint32_t HCDMA;             
  uint32_t Reserved[2];            
} USB_OTG_HostChannelTypeDef;


 



 
typedef struct
{
  volatile uint32_t CONFR0;           
  volatile uint32_t CONFR1;           
  volatile uint32_t CONFR2;           
  volatile uint32_t CONFR3;           
  volatile uint32_t CONFR4;           
  volatile uint32_t CONFR5;           
  volatile uint32_t CONFR6;           
  volatile uint32_t CONFR7;           
  uint32_t  Reserved20[4];        
  volatile uint32_t CR;               
  volatile uint32_t SR;               
  volatile uint32_t CFR;              
  uint32_t  Reserved3c;           
  volatile uint32_t DIR;              
  volatile uint32_t DOR;              
  uint32_t  Reserved48[2];        
  volatile uint32_t QMEM0[16];        
  volatile uint32_t QMEM1[16];        
  volatile uint32_t QMEM2[16];        
  volatile uint32_t QMEM3[16];        
  volatile uint32_t HUFFMIN[16];      
  volatile uint32_t HUFFBASE[32];     
  volatile uint32_t HUFFSYMB[84];     
  volatile uint32_t DHTMEM[103];      
  uint32_t  Reserved4FC;          
  volatile uint32_t HUFFENC_AC0[88];  
  volatile uint32_t HUFFENC_AC1[88];  
  volatile uint32_t HUFFENC_DC0[8];   
  volatile uint32_t HUFFENC_DC1[8];   

} JPEG_TypeDef;



 

typedef struct
{
  volatile uint32_t CR;                
  volatile uint32_t WRFR;              
  volatile uint32_t CWRFR;             
  volatile uint32_t RDFR;              
  volatile uint32_t CRDFR;             
  volatile uint32_t SR;                
  volatile uint32_t CLRFR;             
  uint32_t RESERVED0[57];          
  volatile uint32_t DINR0;             
  volatile uint32_t DINR1;             
  volatile uint32_t DINR2;             
  volatile uint32_t DINR3;             
  volatile uint32_t DINR4;             
  volatile uint32_t DINR5;             
  volatile uint32_t DINR6;             
  volatile uint32_t DINR7;             
  volatile uint32_t DINR8;             
  volatile uint32_t DINR9;             
  volatile uint32_t DINR10;            
  volatile uint32_t DINR11;            
  volatile uint32_t DINR12;            
  volatile uint32_t DINR13;            
  volatile uint32_t DINR14;            
  volatile uint32_t DINR15;            
  volatile uint32_t DINR16;            
  volatile uint32_t DINR17;            
  volatile uint32_t DINR18;            
  volatile uint32_t DINR19;            
  volatile uint32_t DINR20;            
  volatile uint32_t DINR21;            
  volatile uint32_t DINR22;            
  volatile uint32_t DINR23;            
  volatile uint32_t DINR24;            
  volatile uint32_t DINR25;            
  volatile uint32_t DINR26;            
  volatile uint32_t DINR27;            
  volatile uint32_t DINR28;            
  volatile uint32_t DINR29;            
  volatile uint32_t DINR30;            
  volatile uint32_t DINR31;            
  volatile uint32_t DOUTR0;            
  volatile uint32_t DOUTR1;            
  volatile uint32_t DOUTR2;            
  volatile uint32_t DOUTR3;            
  volatile uint32_t DOUTR4;            
  volatile uint32_t DOUTR5;            
  volatile uint32_t DOUTR6;            
  volatile uint32_t DOUTR7;            
  volatile uint32_t DOUTR8;            
  volatile uint32_t DOUTR9;            
  volatile uint32_t DOUTR10;           
  volatile uint32_t DOUTR11;           
  volatile uint32_t DOUTR12;           
  volatile uint32_t DOUTR13;           
  volatile uint32_t DOUTR14;           
  volatile uint32_t DOUTR15;           
  volatile uint32_t DOUTR16;           
  volatile uint32_t DOUTR17;           
  volatile uint32_t DOUTR18;           
  volatile uint32_t DOUTR19;           
  volatile uint32_t DOUTR20;           
  volatile uint32_t DOUTR21;           
  volatile uint32_t DOUTR22;           
  volatile uint32_t DOUTR23;           
  volatile uint32_t DOUTR24;           
  volatile uint32_t DOUTR25;           
  volatile uint32_t DOUTR26;           
  volatile uint32_t DOUTR27;           
  volatile uint32_t DOUTR28;           
  volatile uint32_t DOUTR29;           
  volatile uint32_t DOUTR30;           
  volatile uint32_t DOUTR31;           
} MDIOS_TypeDef;



 

typedef struct
{
  volatile uint32_t VR;             
  volatile uint32_t CR;             
  volatile uint32_t CCR;            
  volatile uint32_t LVCIDR;         
  volatile uint32_t LCOLCR;         
  volatile uint32_t LPCR;           
  volatile uint32_t LPMCR;          
  uint32_t      RESERVED0[4];   
  volatile uint32_t PCR;            
  volatile uint32_t GVCIDR;         
  volatile uint32_t MCR;            
  volatile uint32_t VMCR;           
  volatile uint32_t VPCR;           
  volatile uint32_t VCCR;           
  volatile uint32_t VNPCR;          
  volatile uint32_t VHSACR;         
  volatile uint32_t VHBPCR;         
  volatile uint32_t VLCR;           
  volatile uint32_t VVSACR;         
  volatile uint32_t VVBPCR;         
  volatile uint32_t VVFPCR;         
  volatile uint32_t VVACR;          
  volatile uint32_t LCCR;           
  volatile uint32_t CMCR;           
  volatile uint32_t GHCR;           
  volatile uint32_t GPDR;           
  volatile uint32_t GPSR;           
  volatile uint32_t TCCR[6];        
  volatile uint32_t TDCR;           
  volatile uint32_t CLCR;           
  volatile uint32_t CLTCR;          
  volatile uint32_t DLTCR;          
  volatile uint32_t PCTLR;          
  volatile uint32_t PCONFR;         
  volatile uint32_t PUCR;           
  volatile uint32_t PTTCR;          
  volatile uint32_t PSR;            
  uint32_t      RESERVED1[2];   
  volatile uint32_t ISR[2];         
  volatile uint32_t IER[2];         
  uint32_t      RESERVED2[3];   
  volatile uint32_t FIR[2];         
  uint32_t      RESERVED3[8];   
  volatile uint32_t VSCR;           
  uint32_t      RESERVED4[2];   
  volatile uint32_t LCVCIDR;        
  volatile uint32_t LCCCR;          
  uint32_t      RESERVED5;      
  volatile uint32_t LPMCCR;         
  uint32_t      RESERVED6[7];   
  volatile uint32_t VMCCR;          
  volatile uint32_t VPCCR;          
  volatile uint32_t VCCCR;          
  volatile uint32_t VNPCCR;         
  volatile uint32_t VHSACCR;        
  volatile uint32_t VHBPCCR;        
  volatile uint32_t VLCCR;          
  volatile uint32_t VVSACCR;        
  volatile uint32_t VVBPCCR;        
  volatile uint32_t VVFPCCR;        
  volatile uint32_t VVACCR;         
  uint32_t      RESERVED7[11];  
  volatile uint32_t TDCCR;          
  uint32_t      RESERVED8[155];  
  volatile uint32_t WCFGR;           
  volatile uint32_t WCR;             
  volatile uint32_t WIER;            
  volatile uint32_t WISR;            
  volatile uint32_t WIFCR;           
  uint32_t      RESERVED9;       
  volatile uint32_t WPCR[5];         
  uint32_t      RESERVED10;      
  volatile uint32_t WRPCR;           
} DSI_TypeDef;



 
#line 1406 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 


 





 
#line 1449 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 1494 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"
 
#line 1512 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"
 


#line 1539 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"
 



 





 


 



#line 1568 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"



 



 
#line 1697 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"



 



 

  

 

 
 
 

 
 
 
 
 
 
#line 1738 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 1792 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 1842 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 1898 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 1960 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 




 




 




 




 




 




 
#line 2031 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 2081 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 2131 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 2170 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 


 


 


 


 
#line 2190 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 2246 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 





 
#line 2288 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 2296 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 



 
 
 
 
 
 
 
#line 2335 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 2364 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 2414 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

#line 2427 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

#line 2440 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 2454 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 2468 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 2512 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 2523 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

#line 2530 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

#line 2537 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 2566 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
 
#line 2584 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 2595 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 2609 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 2623 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 2640 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 2651 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 2665 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 2679 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 2696 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 2707 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 2721 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 2735 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 2749 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 2760 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 2774 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 2788 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 2802 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 2813 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 2827 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 2841 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
 





 
#line 2895 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 2942 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 2989 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 3036 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 3134 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 3232 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 3330 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 3428 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 3526 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 3624 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 3722 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 3820 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 3918 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 4016 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 4114 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 4212 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 4310 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 4408 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 4506 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 4604 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 4702 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 4800 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 4898 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 4996 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 5094 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 5192 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 5290 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 5388 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 5486 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 5584 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 5682 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 5780 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
 
 
 
 

 
#line 5797 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 5826 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 




 




 
#line 5877 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 5918 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
 
 
 
 
 




 




 
#line 5951 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 




 





 
 
 
 
 
 
#line 6035 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 6043 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 




 




 




 




 




 




 
#line 6081 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 6089 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 6097 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 




 




 
#line 6115 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
 
 
 
 

 

 
#line 6166 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 6174 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 6190 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 




 
#line 6203 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 

 
#line 6256 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 6285 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 6314 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 6328 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 




 
#line 6347 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 6355 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 6366 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 6374 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 6382 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 6390 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 6398 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 6406 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 6414 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 




 
 
 
 
 

 
 
 
 
 
 
#line 6480 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 6491 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 6508 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 






 
#line 6532 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"


 
#line 6550 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"


 
#line 6568 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"


 
#line 6583 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 6597 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 6605 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 6613 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 6627 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
 
 
 
 
 
#line 6707 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 6728 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 6747 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 6809 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 6871 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 6933 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 6995 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 




 




 




 
 
 
 
 


 

 

#line 7054 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 

#line 7075 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 

#line 7096 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 7104 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 





 





 





 





 

#line 7161 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 

#line 7173 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 

#line 7206 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 

#line 7218 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 





 





 

#line 7245 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 

 






 




 





 





 





 





 

#line 7292 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 





 

#line 7307 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"


 

 

 
 
 
 
 
 
#line 7394 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 7421 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"





 
#line 7502 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 7529 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"


 
#line 7607 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 7684 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 7761 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 7838 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
 
 
 
 


 


 
#line 7878 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 7901 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 7941 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 8004 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 8012 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"


 
 
 
 
 
 
#line 8078 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 8132 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 8186 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 8240 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 8293 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 8346 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 8399 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 8452 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 8491 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 8530 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 8569 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 8608 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 8647 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 8670 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 8716 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 8762 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 




 
#line 8808 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 8849 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 8896 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 8943 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 8967 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 8978 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 8996 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
 
 
 
 
 
#line 9083 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 9101 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 9183 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 9265 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 9283 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 9301 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 9335 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 9388 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 9446 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 9504 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"


 
 
 
 
 
 
#line 9569 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"


 
#line 9605 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 9616 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 9649 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 9666 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 9683 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 9736 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 9765 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 




 




 





 
 
 
 
 
 




 
#line 9799 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 




 
#line 9815 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 




 
 
 
 
 

 

#line 9835 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 

#line 9844 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 

#line 9853 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 

#line 9862 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 

#line 9892 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"


 

#line 9902 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 

#line 9914 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 

#line 9929 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 

#line 9944 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 

#line 9959 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 





 

#line 9974 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 

#line 9989 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 

#line 10001 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 

#line 10010 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 

#line 10019 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 

#line 10031 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 





 





 

#line 10058 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 

#line 10067 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 





 

#line 10082 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 





 

#line 10103 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
 
 
 
 
 
#line 10128 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 10183 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 10215 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"


 
#line 10254 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 10292 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
 
 
 
 
 
#line 10360 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 10379 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 10407 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 10421 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 




 
#line 10491 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"
 




 




 




 




 




 




 




 
 
 
 
 
 
#line 10587 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 10629 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

#line 10636 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
 
#line 10647 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 10657 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 10666 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

#line 10676 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 10684 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"







 
#line 10698 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"







 
#line 10714 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 










#line 10732 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

#line 10739 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"







 
#line 10816 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 10869 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 10883 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 

#line 10892 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 10984 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 11049 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 11120 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 11134 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 11142 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 11237 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 11308 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 11391 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 11405 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 11413 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"
 
#line 11507 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 11578 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 11605 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 11637 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 11651 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 11683 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 11715 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 11725 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

#line 11734 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"









 
#line 11750 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"



 
#line 11760 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

#line 11770 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 11852 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
 
 
 
 
 
#line 11865 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 11882 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
 
 
 
 
 
#line 11930 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 11974 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 12044 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 


 
#line 12103 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 12111 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 




 
#line 12186 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 12256 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 




 




 
#line 12274 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 12317 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 12347 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 




 
#line 12375 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 12447 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"


 
#line 12460 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 12472 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 12482 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"
                     


 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 


 
 
 
 
 
 












 












#line 12685 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

#line 12692 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"







#line 12714 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

#line 12722 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 12730 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

#line 12743 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

#line 12753 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"











 
#line 12776 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

#line 12787 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

#line 12797 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 


 
#line 12810 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"







#line 12824 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"





 
#line 12851 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 12874 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

#line 12881 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 12904 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 




 
 
 
 
 
 
#line 12955 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 12978 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 13010 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 13024 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 13044 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 13064 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 13072 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 13083 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 13091 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
 
 
 
 
 






 
#line 13117 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"







#line 13130 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 




 










#line 13159 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 




 




 




 




 




 




 




 




 
#line 13213 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

#line 13221 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

#line 13234 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 




 
#line 13307 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 13342 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 13410 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 




 




 
 
 
 
 
 
#line 13472 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 13514 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 13553 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 




 




 




 




 
#line 13608 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 13619 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"


 
 
 
 
 
 














 
#line 13666 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

#line 13679 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"





 
#line 13697 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"


 
#line 13711 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"



 
#line 13726 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"



 
#line 13741 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"



 
#line 13756 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 13770 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"


 
#line 13784 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"



 
#line 13799 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"



 
#line 13814 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"



 
#line 13829 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 13843 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"



 
#line 13857 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"



 
#line 13871 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"



 
#line 13885 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"



 
#line 13899 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"


 
#line 13914 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"


 
#line 13927 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"



 
#line 13941 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"



 
#line 13955 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"



 
#line 13969 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 13977 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 13985 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
 
 
 
 


 

 
#line 14011 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"











#line 14030 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 14041 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

#line 14048 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

#line 14055 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

#line 14063 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

#line 14088 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 14097 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

#line 14104 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"





#line 14116 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"







#line 14129 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 14176 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 14226 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 14255 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 






#line 14269 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

#line 14277 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"











#line 14294 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

#line 14302 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"





 







#line 14322 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"







#line 14336 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 






#line 14350 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

#line 14358 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"













#line 14377 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

#line 14385 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"





 







#line 14405 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"







#line 14419 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 14478 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"


 
#line 14487 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 




 




 




 




 




 




 




 
#line 14535 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"







#line 14572 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 14582 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

#line 14591 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 




 
#line 14608 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 






 






 






 
#line 14637 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

#line 14645 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"





#line 14656 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

#line 14664 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"





 
#line 14682 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 


 
#line 14696 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 14707 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 14718 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 14729 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"


 
 
 
 
 
 
#line 14758 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 14781 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 14804 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 






















#line 14834 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

#line 14841 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"







#line 14866 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 14877 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 




 




 



 
 
 
 
 
 
#line 14967 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 



 
#line 15031 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 15087 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 15095 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 15103 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"


 
#line 15112 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 15129 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 15191 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 15226 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 




 




 
 
 
 
 
 
#line 15253 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"






 
#line 15270 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"













 




 
 
 
 
 
 
#line 15300 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 15314 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"







 
#line 15382 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 15399 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
 
 
 
 
 
#line 15464 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 15508 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 




 




 
#line 15548 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 




 
#line 15586 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 15594 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 




 








 

 
#line 15633 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 15713 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 15730 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 15738 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 




 




 
#line 15768 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 




 
#line 15793 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 




 
#line 15818 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 




 
 
 

 
#line 15847 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 15858 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 15869 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 15880 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 15891 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 




 




 




 




 




 




 
 
 

 
#line 15954 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

#line 15973 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 




 




 
#line 15991 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 




 
#line 16004 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 




 




 




 
#line 16027 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
 
 

 
#line 16094 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 




 




 




 




 
#line 16128 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"
   
#line 16221 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 16271 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 16318 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 16332 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 




 




 




 




 
 
 
 
 
 
#line 16413 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 16423 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 16433 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

#line 16444 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"













 
#line 16467 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 16490 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 16504 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

#line 16526 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 




 
#line 16539 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 




#line 16556 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 16578 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 16641 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 16672 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 16698 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 16714 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

#line 16726 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 




 
#line 16757 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 16843 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 16929 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 16937 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 




 
#line 16956 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 16964 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 

#line 16977 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"







#line 16991 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

#line 16999 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

#line 17007 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 

#line 17020 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"







#line 17034 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

#line 17042 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

#line 17050 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 




 




 
#line 17074 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 




 




#line 17096 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

#line 17107 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 17115 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

#line 17131 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

#line 17147 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 




 
#line 17160 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 17168 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 17176 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 17184 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 




 
#line 17236 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 17265 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 17294 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

#line 17303 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

#line 17311 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"







 
#line 17352 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 17360 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 17374 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

#line 17383 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

#line 17409 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 




#line 17428 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"













#line 17460 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 

#line 17473 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

#line 17484 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

#line 17496 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 17531 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 17566 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 17601 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 

#line 17613 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"
 
#line 17628 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 




 




 




 
#line 17651 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 17691 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 17714 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 17722 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"







 
#line 17739 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"


 
 
 
 
 
 




 
#line 17779 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 




 
#line 17792 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 17826 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 17860 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 17894 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 17928 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 17963 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 17986 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 17994 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 




 




 
 
 
 
 
 
#line 18034 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 




 




 




 




 
#line 18065 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 18076 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
 
 
 
 
 




 




 
#line 18120 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

#line 18148 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 18159 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 18176 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"





 
#line 18191 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 18220 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

#line 18248 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 18265 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 18276 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 




 
#line 18292 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

#line 18326 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 18373 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 18417 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 18461 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 18502 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 18543 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 18593 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 18628 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 18663 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 18698 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 18745 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 18798 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 18842 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 18865 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

#line 18875 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

#line 18903 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

#line 18931 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 18944 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

#line 18956 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

#line 18968 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

#line 18980 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 19003 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 19056 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

#line 19108 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 19161 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 19214 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 19267 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"





 
#line 19324 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 19377 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 








#line 19396 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 19404 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 19439 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

#line 19473 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 19523 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

#line 19551 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

#line 19579 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 19587 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 19598 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

#line 19626 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 19640 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 19657 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 19683 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 19748 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 19789 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 19854 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 19895 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 19960 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 20001 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 20009 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 20020 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 20037 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"





 
#line 20070 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

#line 20098 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 20109 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

#line 20134 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 20181 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 20225 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 20269 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 20310 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 20351 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 20401 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 20436 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 20471 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 20506 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 20553 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 








#line 20572 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 20589 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

#line 20602 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 20616 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 20633 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 20659 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 20676 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 20687 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

#line 20748 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 20759 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

#line 20769 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

#line 20779 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

#line 20789 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"





#line 20803 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

#line 20813 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

#line 20823 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"





#line 20837 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 20866 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

#line 20894 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

#line 20922 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

#line 20950 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 20979 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

#line 21007 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

#line 21035 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

#line 21063 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 21092 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 21121 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

#line 21137 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

#line 21147 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"







 



 



 

 







 



 


 


 


 





#line 21199 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 


 
#line 21220 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 21233 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

#line 21245 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 


 



 





 






 




 


 


 


 



 


 


 




 


 



 


 
#line 21312 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 21328 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 



 



 



 



 
#line 21358 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 21368 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 21376 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 21384 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 



 



 



 
#line 21406 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 21414 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 21422 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 




 
#line 21435 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"
                                                        
 
#line 21443 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"
                                                        
 






 
#line 21459 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 21468 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 



 
#line 21480 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 21490 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 21500 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 21508 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 




 
#line 21575 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 21587 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 




 
#line 21603 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"
	 
 
#line 21617 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"
                                                        
 


                                                        
 
#line 21631 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"
                                                        
 
#line 21639 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"
                                                        
 
#line 21647 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"
                                                         
 



 





 
#line 21667 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 





 
#line 21683 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 21693 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 21703 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 
#line 21713 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 





 
#line 21729 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f769xx.h"

 


 



 
 
 
 
 
 
 

 


 




 



 



 


}





 
#line 151 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f7xx.h"
#line 158 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/stm32f7xx.h"



 



  
typedef enum 
{
  RESET = 0, 
  SET = !RESET
} FlagStatus, ITStatus;

typedef enum 
{
  DISABLE = 0, 
  ENABLE = !DISABLE
} FunctionalState;


typedef enum 
{
  ERROR = 0, 
  SUCCESS = !ERROR
} ErrorStatus;



 
  


 


















 



}






 

  

 

 
#line 32 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\MCU.h"









#line 47 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\MCU.h"


typedef uint8_t    BYTE;
typedef uint16_t   WORD;
typedef uint32_t   DWORD;
typedef uint32_t   MTYPE;


inline void* operator new[]    ( unsigned int  x ) { return malloc(x); }
inline void* operator new      ( unsigned int  x ) { return malloc(x); }
inline void  operator delete[] ( void         *x ) { if(x) free(x);    }
inline void  operator delete   ( void         *x ) { if(x) free(x);    }







#line 1 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/PinConfig.h"







 

















 
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
					ADC3_IN8,
					ADC3_IN12,
          CAN1_RX,
          CAN1_TX,
          CAN2_RX,
          CAN2_TX,
          CAN3_RX,
          CAN3_TX,
          DAC_OUT1,
          DAC_OUT2,
          DCMDIOS_MDC,
          DCMI_D0,
          DCMI_D1,
          DCMI_D10,
          DCMI_D11,
          DCMI_D12,
          DCMI_D13,
          DCMI_D2,
          DCMI_D3,
          DCMI_D4,
          DCMI_D5,
          DCMI_D6,
          DCMI_D7,
          DCMI_D8,
          DCMI_D9,
          DCMI_HSYNC,
          DCMI_PIXCLK,
          DCMI_VSYNC,
          DFSDM1_CKIN0,
          DFSDM1_CKIN1,
          DFSDM1_CKIN2,
          DFSDM1_CKIN3,
          DFSDM1_CKIN4,
          DFSDM1_CKIN5,
          DFSDM1_CKIN6,
          DFSDM1_CKIN7,
          DFSDM1_CKOUT,
          DFSDM1_DATAIN0,
          DFSDM1_DATAIN1,
          DFSDM1_DATAIN2,
          DFSDM1_DATAIN3,
          DFSDM1_DATAIN4,
          DFSDM1_DATAIN5,
          DFSDM1_DATAIN6,
          DFSDM1_DATAIN7,
          DFSDM1_DATIN1,
          DFSDM1_DATIN4,
          DFSDM1_DATIN5,
          DSI_TE,
          ETH_M,
          ETH_MDIO,
          ETH_MII_COL,
          ETH_MII_CRS,
          ETH_MII_RX_CLK,
          ETH_MII_RX_DV,
          ETH_MII_RX_ER,
          ETH_MII_RXD0,
          ETH_MII_RXD1,
          ETH_MII_RXD2,
          ETH_MII_RXD3,
          ETH_MII_TX_CLK,
          ETH_MII_TX_EN,
          ETH_MII_TXD0,
          ETH_MII_TXD1,
          ETH_MII_TXD2,
          ETH_MII_TXD3,
          ETH_PPS_OUT,
          ETH_RMII_CRS_DV,
          ETH_RMII_REF_CLK,
          ETH_RMII_RXD0,
          ETH_RMII_RXD1,
          ETH_RMII_TX_EN,
          ETH_RMII_TXD0,
          ETH_RMII_TXD1,
          FMC_A0,
          FMC_A1,
          FMC_A10,
          FMC_A11,
          FMC_A12,
          FMC_A13,
          FMC_A14,
          FMC_A15,
          FMC_A16,
          FMC_A17,
          FMC_A18,
          FMC_A19,
          FMC_A2,
          FMC_A20,
          FMC_A21,
          FMC_A22,
          FMC_A23,
          FMC_A24,
          FMC_A25,
          FMC_A3,
          FMC_A4,
          FMC_A5,
          FMC_A6,
          FMC_A7,
          FMC_A8,
          FMC_A9,
          FMC_ALE,
          FMC_BA0,
          FMC_BA1,
          FMC_CLE,
          FMC_CLK,
          FMC_D0,
          FMC_D1,
          FMC_D10,
          FMC_D11,
          FMC_D12,
          FMC_D13,
          FMC_D14,
          FMC_D15,
          FMC_D16,
          FMC_D17,
          FMC_D18,
          FMC_D19,
          FMC_D2,
          FMC_D20,
          FMC_D21,
          FMC_D22,
          FMC_D23,
          FMC_D24,
          FMC_D25,
          FMC_D26,
          FMC_D27,
          FMC_D28,
          FMC_D29,
          FMC_D3,
          FMC_D30,
          FMC_D31,
          FMC_D4,
          FMC_D5,
          FMC_D6,
          FMC_D7,
          FMC_D8,
          FMC_D9,
          FMC_INT,
          FMC_NBL0,
          FMC_NBL1,
          FMC_NBL2,
          FMC_NBL3,
          FMC_NCE,
          FMC_NE1,
          FMC_NE2,
          FMC_NE3,
          FMC_NE4,
          FMC_NOE,
          FMC_NWAIT,
          FMC_NWE,
          FMC_SDCKE0,
          FMC_SDCKE1,
          FMC_SDCLK,
          FMC_SDNCAS,
          FMC_SDNE0,
          FMC_SDNE1,
          FMC_SDNRAS,
          FMC_SDNWE,
          HDMICEC,
          I2C1_SCL,
					I2C1_SDA,
          I2C1_SMBA,
          I2C2_SCL,
          I2C2_SDA,
          I2C2_SMBA,
          I2C3_SCL,
          I2C3_SDA,
          I2C3_SMBA,
          I2C4_SCL,
          I2C4_SDA,
          I2C4_SMBA,
          I2S_CKIN,
          I2S1_CK,
          I2S1_MCK,
          I2S1_SD,
          I2S1_WS,
          I2S2_CK,
          I2S2_MCK,
          I2S2_SD,
          I2S2_WS,
          I2S3_CK,
          I2S3_MCK,
          I2S3_SD,
          I2S3_WS,
          JTCKSWCLK,
          JTDI,
          JTDO,
          JTMSSWDIO,
          LCD_B0,
          LCD_B1,
          LCD_B2,
          LCD_B3,
          LCD_B4,
          LCD_B5,
          LCD_B6,
          LCD_B7,
          LCD_CLK,
          LCD_DE,
          LCD_G0,
          LCD_G1,
          LCD_G2,
          LCD_G3,
          LCD_G4,
          LCD_G5,
          LCD_G6,
          LCD_G7,
          LCD_HSYNC,
          LCD_R0,
          LCD_R1,
          LCD_R2,
          LCD_R3,
          LCD_R4,
          LCD_R5,
          LCD_R6,
          LCD_R7,
          LCD_VSYNC,
          LPTIM1_ETR,
          LPTIM1_IN1,
          LPTIM1_IN2,
          LPTIM1_OUT,
          MCO1,
          MCO2,
          MDIOS_MDC,
          MDIOS_MDIO,
          NJTRST,
          OTG_FS_DM,
          OTG_FS_DP,
          OTG_FS_ID,
          OTG_FS_SOF,
          OTG_HS_SOF,
          OTG_HS_ULPI_CK,
          OTG_HS_ULPI_D0,
          OTG_HS_ULPI_D1,
          OTG_HS_ULPI_D2,
          OTG_HS_ULPI_D7,
          OTG_HS_ULPI_DIR,
          OTG_HS_ULPI_NXT,
          OTG_HS_ULPI_STP,
          QUADSPI_BK1_IO0,
          QUADSPI_BK1_IO1,
          QUADSPI_BK1_IO2,
          QUADSPI_BK1_IO3,
          QUADSPI_BK1_NCS,
          QUADSPI_BK2_IO0,
          QUADSPI_BK2_IO1,
          QUADSPI_BK2_IO2,
          QUADSPI_BK2_IO3,
          QUADSPI_BK2_NCS,
          QUADSPI_CLK,
          SAI1_FS_A,
          SAI1_FS_B,
          SAI1_MCLK_A,
          SAI1_MCLK_B,
          SAI1_SCK_A,
          SAI1_SCK_B,
          SAI1_SD_A,
          SAI1_SD_B,
          SAI2_FS_A,
          SAI2_FS_B,
          SAI2_MCK_A,
          SAI2_MCK_B,
          SAI2_SCK_A,
          SAI2_SCK_B,
          SAI2_SD_A,
          SAI2_SD_B,
          SDMMC_CK,
          SDMMC_CMD,
          SDMMC_D0,
          SDMMC_D1,
          SDMMC_D2,
          SDMMC_D3,
          SDMMC_D6,
          SDMMC_D7,
          SDMMC2_CK,
          SDMMC2_CMD,
          SDMMC2_D0,
          SDMMC2_D1,
          SDMMC2_D2,
          SDMMC2_D3,
          SDMMC2_D6,
          SDMMC2_D7,
          SPDIF_RX0,
          SPDIF_RX1,
          SPDIF_RX2,
          SPDIF_RX3,
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
          SPI4_MISO,
          SPI4_MOSI,
          SPI4_NSS,
          SPI4_SCK,
          SPI5_MISO,
          SPI5_MOSI,
          SPI5_NSS,
          SPI5_SCK,
          SPI6_MISO,
          SPI6_MOSI,
          SPI6_NSS,
          SPI6_SCK,
          TIM1_BKIN,
          TIM1_BKIN2,
          TIM1_CH1,
          TIM1_CH1N,
          TIM1_CH2,
          TIM1_CH2N,
          TIM1_CH3,
          TIM1_CH3N,
          TIM1_CH4,
          TIM1_ETR,
          TIM1_IN1,
          TIM10_CH1,
          TIM11_CH1,
          TIM12_CH1,
          TIM12_CH2,
          TIM13_CH1,
          TIM14_CH1,
          TIM2_CH1,
          TIM2_CH2,
          TIM2_CH3,
          TIM2_CH4,
          TIM2_ETR,
          TIM3_CH1,
          TIM3_CH2,
          TIM3_CH3,
          TIM3_CH4,
          TIM3_ETR,
          TIM4_CH1,
          TIM4_CH1LP,
          TIM4_CH2,
          TIM4_CH3,
          TIM4_CH4,
          TIM4_ETR,
          TIM5_CH1,
          TIM5_CH2,
          TIM5_CH3,
          TIM5_CH4,
          TIM8_BKIN,
          TIM8_BKIN2,
          TIM8_CH1,
          TIM8_CH1N,
          TIM8_CH2,
          TIM8_CH2N,
          TIM8_CH3,
          TIM8_CH3N,
          TIM8_CH4,
          TIM8_ETR,
          TIM9_CH1,
          TIM9_CH2,
          TRACECLK,
          TRACED0,
          TRACED1,
          TRACED2,
          TRACED3,
          TRACESWO,
          UART4_CTS,
          UART4_RTS,
          UART4_RX,
          UART4_TX,
          UART5_CTS,
          UART5_RTS,
          UART5_RX,
          UART5_TX,
          UART7_CTS,
          UART7_RTS,
          UART7_RX,
          UART7_TX,
          UART8_CTS,
          UART8_RTS,
          UART8_Rx,
          UART8_Tx,
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
          USART6_CK,
          USART6_CTS,
          USART6_RTS,
          USART6_RX,
          USART6_TX,
          
    } Function;

    
    



 
		
		
		
    typedef enum
    {
      
			ADC3_IN8_PF_10 = (ADC3_IN8<<16)|(5<<12)|( 10<<4)|( 0<<0),  
      ADC3_IN12_PC_2 = (ADC3_IN12<<16)|(2<<12)|( 2<<4)|( 0<<0),  
      CAN1_RX_PA_11 = (CAN1_RX<<16)|(0<<12)|(11<<4)|(9<<0),  
      CAN1_RX_PD_0 = (CAN1_RX<<16)|(3<<12)|(0<<4)|(9<<0),  
      CAN1_RX_PH_14 = (CAN1_RX<<16)|(7<<12)|(14<<4)|(9<<0),  
      CAN1_RX_PI_9 = (CAN1_RX<<16)|(8<<12)|(9<<4)|(9<<0),  
      CAN1_TX_PA_12 = (CAN1_TX<<16)|(0<<12)|(12<<4)|(9<<0),  
      CAN1_TX_PD_1 = (CAN1_TX<<16)|(3<<12)|(1<<4)|(9<<0),  
      CAN1_TX_PH_13 = (CAN1_TX<<16)|(7<<12)|(13<<4)|(9<<0),  
      CAN2_RX_PB_5 = (CAN2_RX<<16)|(1<<12)|(5<<4)|(9<<0),  
      CAN2_TX_PB_6 = (CAN2_TX<<16)|(1<<12)|(6<<4)|(9<<0),  
      CAN3_RX_PA_8 = (CAN3_RX<<16)|(0<<12)|(8<<4)|(11<<0),  
      CAN3_RX_PB_3 = (CAN3_RX<<16)|(1<<12)|(3<<4)|(11<<0),  
      CAN3_TX_PA_15 = (CAN3_TX<<16)|(0<<12)|(15<<4)|(11<<0),  
      CAN3_TX_PB_4 = (CAN3_TX<<16)|(1<<12)|(4<<4)|(11<<0),  
      DAC_OUT1_PA_4 = (DAC_OUT1<<16)|(0<<12)|(4<<4)|(0<<0),  
      DAC_OUT2_PA_5 = (DAC_OUT2<<16)|(0<<12)|(5<<4)|(0<<0),  
      DCMDIOS_MDC_PC_1 = (DCMDIOS_MDC<<16)|(2<<12)|(1<<4)|(12<<0),  
      DCMI_D0_PA_9 = (DCMI_D0<<16)|(0<<12)|(9<<4)|(13<<0),  
      DCMI_D0_PC_6 = (DCMI_D0<<16)|(2<<12)|(6<<4)|(13<<0),  
      DCMI_D0_PH_9 = (DCMI_D0<<16)|(7<<12)|(9<<4)|(13<<0),  
      DCMI_D1_PA_10 = (DCMI_D1<<16)|(0<<12)|(10<<4)|(13<<0),  
      DCMI_D1_PC_7 = (DCMI_D1<<16)|(2<<12)|(7<<4)|(13<<0),  
      DCMI_D1_PH_10 = (DCMI_D1<<16)|(7<<12)|(10<<4)|(13<<0),  
      DCMI_D10_PB_5 = (DCMI_D10<<16)|(1<<12)|(5<<4)|(13<<0),  
      DCMI_D10_PD_6 = (DCMI_D10<<16)|(3<<12)|(6<<4)|(13<<0),  
      DCMI_D10_PI_3 = (DCMI_D10<<16)|(8<<12)|(3<<4)|(13<<0),  
      DCMI_D11_PD_2 = (DCMI_D11<<16)|(3<<12)|(2<<4)|(13<<0),  
      DCMI_D11_PF_10 = (DCMI_D11<<16)|(5<<12)|(10<<4)|(13<<0),  
      DCMI_D11_PH_15 = (DCMI_D11<<16)|(7<<12)|(15<<4)|(13<<0),  
      DCMI_D12_PF_11 = (DCMI_D12<<16)|(5<<12)|(11<<4)|(13<<0),  
      DCMI_D12_PG_6 = (DCMI_D12<<16)|(6<<12)|(6<<4)|(13<<0),  
      DCMI_D13_PG_7 = (DCMI_D13<<16)|(6<<12)|(7<<4)|(13<<0),  
      DCMI_D13_PG_15 = (DCMI_D13<<16)|(6<<12)|(15<<4)|(13<<0),  
      DCMI_D13_PI_0 = (DCMI_D13<<16)|(8<<12)|(0<<4)|(13<<0),  
      DCMI_D2_PC_8 = (DCMI_D2<<16)|(2<<12)|(8<<4)|(13<<0),  
      DCMI_D2_PE_0 = (DCMI_D2<<16)|(4<<12)|(0<<4)|(13<<0),  
      DCMI_D2_PG_10 = (DCMI_D2<<16)|(6<<12)|(10<<4)|(13<<0),  
      DCMI_D2_PH_11 = (DCMI_D2<<16)|(7<<12)|(11<<4)|(13<<0),  
      DCMI_D3_PC_9 = (DCMI_D3<<16)|(2<<12)|(9<<4)|(13<<0),  
      DCMI_D3_PE_1 = (DCMI_D3<<16)|(4<<12)|(1<<4)|(13<<0),  
      DCMI_D3_PG_11 = (DCMI_D3<<16)|(6<<12)|(11<<4)|(13<<0),  
      DCMI_D3_PH_12 = (DCMI_D3<<16)|(7<<12)|(12<<4)|(13<<0),  
      DCMI_D4_PC_11 = (DCMI_D4<<16)|(2<<12)|(11<<4)|(13<<0),  
      DCMI_D4_PE_4 = (DCMI_D4<<16)|(4<<12)|(4<<4)|(13<<0),  
      DCMI_D4_PH_14 = (DCMI_D4<<16)|(7<<12)|(14<<4)|(13<<0),  
      DCMI_D5_PB_6 = (DCMI_D5<<16)|(1<<12)|(6<<4)|(13<<0),  
      DCMI_D5_PD_3 = (DCMI_D5<<16)|(3<<12)|(3<<4)|(13<<0),  
      DCMI_D5_PI_4 = (DCMI_D5<<16)|(8<<12)|(4<<4)|(13<<0),  
      DCMI_D6_PE_5 = (DCMI_D6<<16)|(4<<12)|(5<<4)|(13<<0),  
      DCMI_D6_PI_6 = (DCMI_D6<<16)|(8<<12)|(6<<4)|(13<<0),  
      DCMI_D7_PE_6 = (DCMI_D7<<16)|(4<<12)|(6<<4)|(13<<0),  
      DCMI_D7_PI_7 = (DCMI_D7<<16)|(8<<12)|(7<<4)|(13<<0),  
      DCMI_D8_PC_10 = (DCMI_D8<<16)|(2<<12)|(10<<4)|(13<<0),  
      DCMI_D8_PH_6 = (DCMI_D8<<16)|(7<<12)|(6<<4)|(13<<0),  
      DCMI_D8_PI_1 = (DCMI_D8<<16)|(8<<12)|(1<<4)|(13<<0),  
      DCMI_D9_PC_12 = (DCMI_D9<<16)|(2<<12)|(12<<4)|(13<<0),  
      DCMI_D9_PH_7 = (DCMI_D9<<16)|(7<<12)|(7<<4)|(13<<0),  
      DCMI_D9_PI_2 = (DCMI_D9<<16)|(8<<12)|(2<<4)|(13<<0),  
      DCMI_HSYNC_PA_4 = (DCMI_HSYNC<<16)|(0<<12)|(4<<4)|(13<<0),  
      DCMI_HSYNC_PH_8 = (DCMI_HSYNC<<16)|(7<<12)|(8<<4)|(13<<0),  
      DCMI_PIXCLK_PA_6 = (DCMI_PIXCLK<<16)|(0<<12)|(6<<4)|(13<<0),  
      DCMI_VSYNC_PG_9 = (DCMI_VSYNC<<16)|(6<<12)|(9<<4)|(13<<0),  
      DCMI_VSYNC_PI_5 = (DCMI_VSYNC<<16)|(8<<12)|(5<<4)|(13<<0),  
      DFSDM1_CKIN0_PC_0 = (DFSDM1_CKIN0<<16)|(2<<12)|(0<<4)|(3<<0),  
      DFSDM1_CKIN0_PD_4 = (DFSDM1_CKIN0<<16)|(3<<12)|(4<<4)|(6<<0),  
      DFSDM1_CKIN1_PB_2 = (DFSDM1_CKIN1<<16)|(1<<12)|(2<<4)|(10<<0),  
      DFSDM1_CKIN1_PC_2 = (DFSDM1_CKIN1<<16)|(2<<12)|(2<<4)|(3<<0),  
      DFSDM1_CKIN1_PD_7 = (DFSDM1_CKIN1<<16)|(3<<12)|(7<<4)|(6<<0),  
      DFSDM1_CKIN2_PC_4 = (DFSDM1_CKIN2<<16)|(2<<12)|(4<<4)|(3<<0),  
      DFSDM1_CKIN2_PE_8 = (DFSDM1_CKIN2<<16)|(4<<12)|(8<<4)|(6<<0),  
      DFSDM1_CKIN3_PC_6 = (DFSDM1_CKIN3<<16)|(2<<12)|(6<<4)|(7<<0),  
      DFSDM1_CKIN3_PD_8 = (DFSDM1_CKIN3<<16)|(3<<12)|(8<<4)|(3<<0),  
      DFSDM1_CKIN3_PE_5 = (DFSDM1_CKIN3<<16)|(4<<12)|(5<<4)|(10<<0),  
      DFSDM1_CKIN4_PC_1 = (DFSDM1_CKIN4<<16)|(2<<12)|(1<<4)|(10<<0),  
      DFSDM1_CKIN4_PD_6 = (DFSDM1_CKIN4<<16)|(3<<12)|(6<<4)|(3<<0),  
      DFSDM1_CKIN4_PE_11 = (DFSDM1_CKIN4<<16)|(4<<12)|(11<<4)|(6<<0),  
      DFSDM1_CKIN5_PC_10 = (DFSDM1_CKIN5<<16)|(2<<12)|(10<<4)|(3<<0),  
      DFSDM1_CKIN5_PE_13 = (DFSDM1_CKIN5<<16)|(4<<12)|(13<<4)|(6<<0),  
      DFSDM1_CKIN6_PD_0 = (DFSDM1_CKIN6<<16)|(3<<12)|(0<<4)|(3<<0),  
      DFSDM1_CKIN6_PF_14 = (DFSDM1_CKIN6<<16)|(5<<12)|(14<<4)|(6<<0),  
      DFSDM1_CKIN7_PD_1 = (DFSDM1_CKIN7<<16)|(3<<12)|(1<<4)|(6<<0),  
      DFSDM1_CKOUT_PB_0 = (DFSDM1_CKOUT<<16)|(1<<12)|(0<<4)|(6<<0),  
      DFSDM1_CKOUT_PC_2 = (DFSDM1_CKOUT<<16)|(2<<12)|(2<<4)|(6<<0),  
      DFSDM1_CKOUT_PD_3 = (DFSDM1_CKOUT<<16)|(3<<12)|(3<<4)|(3<<0),  
      DFSDM1_CKOUT_PD_10 = (DFSDM1_CKOUT<<16)|(3<<12)|(10<<4)|(3<<0),  
      DFSDM1_CKOUT_PE_9 = (DFSDM1_CKOUT<<16)|(4<<12)|(9<<4)|(6<<0),  
      DFSDM1_DATAIN0_PC_1 = (DFSDM1_DATAIN0<<16)|(2<<12)|(1<<4)|(3<<0),  
      DFSDM1_DATAIN0_PD_3 = (DFSDM1_DATAIN0<<16)|(3<<12)|(3<<4)|(6<<0),  
      DFSDM1_DATAIN1_PC_3 = (DFSDM1_DATAIN1<<16)|(2<<12)|(3<<4)|(3<<0),  
      DFSDM1_DATAIN1_PD_6 = (DFSDM1_DATAIN1<<16)|(3<<12)|(6<<4)|(10<<0),  
      DFSDM1_DATAIN2_PC_5 = (DFSDM1_DATAIN2<<16)|(2<<12)|(5<<4)|(3<<0),  
      DFSDM1_DATAIN2_PE_7 = (DFSDM1_DATAIN2<<16)|(4<<12)|(7<<4)|(6<<0),  
      DFSDM1_DATAIN3_PC_7 = (DFSDM1_DATAIN3<<16)|(2<<12)|(7<<4)|(7<<0),  
      DFSDM1_DATAIN3_PD_9 = (DFSDM1_DATAIN3<<16)|(3<<12)|(9<<4)|(3<<0),  
      DFSDM1_DATAIN3_PE_4 = (DFSDM1_DATAIN3<<16)|(4<<12)|(4<<4)|(10<<0),  
      DFSDM1_DATAIN4_PD_7 = (DFSDM1_DATAIN4<<16)|(3<<12)|(7<<4)|(3<<0),  
      DFSDM1_DATAIN4_PE_10 = (DFSDM1_DATAIN4<<16)|(4<<12)|(10<<4)|(6<<0),  
      DFSDM1_DATAIN5_PC_11 = (DFSDM1_DATAIN5<<16)|(2<<12)|(11<<4)|(3<<0),  
      DFSDM1_DATAIN5_PE_12 = (DFSDM1_DATAIN5<<16)|(4<<12)|(12<<4)|(6<<0),  
      DFSDM1_DATAIN6_PD_1 = (DFSDM1_DATAIN6<<16)|(3<<12)|(1<<4)|(3<<0),  
      DFSDM1_DATAIN6_PF_13 = (DFSDM1_DATAIN6<<16)|(5<<12)|(13<<4)|(6<<0),  
      DFSDM1_DATAIN7_PD_0 = (DFSDM1_DATAIN7<<16)|(3<<12)|(0<<4)|(6<<0),  
      DFSDM1_DATIN1_PB_1 = (DFSDM1_DATIN1<<16)|(1<<12)|(1<<4)|(6<<0),  
      DFSDM1_DATIN4_PC_0 = (DFSDM1_DATIN4<<16)|(2<<12)|(0<<4)|(6<<0),  
      DFSDM1_DATIN5_PB_6 = (DFSDM1_DATIN5<<16)|(1<<12)|(6<<4)|(6<<0),  
      DSI_TE_PJ_2 = (DSI_TE<<16)|(9<<12)|(2<<4)|(13<<0),  
      ETH_M_PC_1 = (ETH_M<<16)|(2<<12)|(1<<4)|(11<<0),  
      ETH_MDIO_PA_2 = (ETH_MDIO<<16)|(0<<12)|(2<<4)|(11<<0),  
      ETH_MII_COL_PA_3 = (ETH_MII_COL<<16)|(0<<12)|(3<<4)|(11<<0),  
      ETH_MII_COL_PH_3 = (ETH_MII_COL<<16)|(7<<12)|(3<<4)|(11<<0),  
      ETH_MII_CRS_PA_0 = (ETH_MII_CRS<<16)|(0<<12)|(0<<4)|(11<<0),  
      ETH_MII_CRS_PH_2 = (ETH_MII_CRS<<16)|(7<<12)|(2<<4)|(11<<0),  
      ETH_MII_RX_CLK_PA_1 = (ETH_MII_RX_CLK<<16)|(0<<12)|(1<<4)|(11<<0),  
      ETH_MII_RX_DV_PA_7 = (ETH_MII_RX_DV<<16)|(0<<12)|(7<<4)|(11<<0),  
      ETH_MII_RX_ER_PI_10 = (ETH_MII_RX_ER<<16)|(8<<12)|(10<<4)|(11<<0),  
      ETH_MII_RXD0_PC_4 = (ETH_MII_RXD0<<16)|(2<<12)|(4<<4)|(11<<0),  
      ETH_MII_RXD1_PC_5 = (ETH_MII_RXD1<<16)|(2<<12)|(5<<4)|(11<<0),  
      ETH_MII_RXD2_PB_0 = (ETH_MII_RXD2<<16)|(1<<12)|(0<<4)|(11<<0),  
      ETH_MII_RXD2_PH_6 = (ETH_MII_RXD2<<16)|(7<<12)|(6<<4)|(11<<0),  
      ETH_MII_RXD3_PB_1 = (ETH_MII_RXD3<<16)|(1<<12)|(1<<4)|(11<<0),  
      ETH_MII_RXD3_PH_7 = (ETH_MII_RXD3<<16)|(7<<12)|(7<<4)|(11<<0),  
      ETH_MII_TX_CLK_PC_3 = (ETH_MII_TX_CLK<<16)|(2<<12)|(3<<4)|(11<<0),  
      ETH_MII_TX_EN_PG_11 = (ETH_MII_TX_EN<<16)|(6<<12)|(11<<4)|(11<<0),  
      ETH_MII_TXD0_PG_13 = (ETH_MII_TXD0<<16)|(6<<12)|(13<<4)|(11<<0),  
      ETH_MII_TXD1_PG_14 = (ETH_MII_TXD1<<16)|(6<<12)|(14<<4)|(11<<0),  
      ETH_MII_TXD2_PC_2 = (ETH_MII_TXD2<<16)|(2<<12)|(2<<4)|(11<<0),  
      ETH_MII_TXD3_PE_2 = (ETH_MII_TXD3<<16)|(4<<12)|(2<<4)|(11<<0),  
      ETH_PPS_OUT_PB_5 = (ETH_PPS_OUT<<16)|(1<<12)|(5<<4)|(11<<0),  
      ETH_PPS_OUT_PG_8 = (ETH_PPS_OUT<<16)|(6<<12)|(8<<4)|(11<<0),  
      ETH_RMII_CRS_DV_PA_7 = (ETH_RMII_CRS_DV<<16)|(0<<12)|(7<<4)|(11<<0),  
      ETH_RMII_REF_CLK_PA_1 = (ETH_RMII_REF_CLK<<16)|(0<<12)|(1<<4)|(11<<0),  
      ETH_RMII_RXD0_PC_4 = (ETH_RMII_RXD0<<16)|(2<<12)|(4<<4)|(11<<0),  
      ETH_RMII_RXD1_PC_5 = (ETH_RMII_RXD1<<16)|(2<<12)|(5<<4)|(11<<0),  
      ETH_RMII_TX_EN_PG_11 = (ETH_RMII_TX_EN<<16)|(6<<12)|(11<<4)|(11<<0),  
      ETH_RMII_TXD0_PG_13 = (ETH_RMII_TXD0<<16)|(6<<12)|(13<<4)|(11<<0),  
      ETH_RMII_TXD1_PG_14 = (ETH_RMII_TXD1<<16)|(6<<12)|(14<<4)|(11<<0),  
      FMC_A0_PF_0 = (FMC_A0<<16)|(5<<12)|(0<<4)|(12<<0),  
      FMC_A1_PF_1 = (FMC_A1<<16)|(5<<12)|(1<<4)|(12<<0),  
      FMC_A10_PG_0 = (FMC_A10<<16)|(6<<12)|(0<<4)|(12<<0),  
      FMC_A11_PG_1 = (FMC_A11<<16)|(6<<12)|(1<<4)|(12<<0),  
      FMC_A12_PG_2 = (FMC_A12<<16)|(6<<12)|(2<<4)|(12<<0),  
      FMC_A13_PG_3 = (FMC_A13<<16)|(6<<12)|(3<<4)|(12<<0),  
      FMC_A14_PG_4 = (FMC_A14<<16)|(6<<12)|(4<<4)|(12<<0),  
      FMC_A15_PG_5 = (FMC_A15<<16)|(6<<12)|(5<<4)|(12<<0),  
      FMC_A16_PD_11 = (FMC_A16<<16)|(3<<12)|(11<<4)|(12<<0),  
      FMC_A17_PD_12 = (FMC_A17<<16)|(3<<12)|(12<<4)|(12<<0),  
      FMC_A18_PD_13 = (FMC_A18<<16)|(3<<12)|(13<<4)|(12<<0),  
      FMC_A19_PE_3 = (FMC_A19<<16)|(4<<12)|(3<<4)|(12<<0),  
      FMC_A2_PF_2 = (FMC_A2<<16)|(5<<12)|(2<<4)|(12<<0),  
      FMC_A20_PE_4 = (FMC_A20<<16)|(4<<12)|(4<<4)|(12<<0),  
      FMC_A21_PE_5 = (FMC_A21<<16)|(4<<12)|(5<<4)|(12<<0),  
      FMC_A22_PE_6 = (FMC_A22<<16)|(4<<12)|(6<<4)|(12<<0),  
      FMC_A23_PE_2 = (FMC_A23<<16)|(4<<12)|(2<<4)|(12<<0),  
      FMC_A24_PG_13 = (FMC_A24<<16)|(6<<12)|(13<<4)|(12<<0),  
      FMC_A25_PG_14 = (FMC_A25<<16)|(6<<12)|(14<<4)|(12<<0),  
      FMC_A3_PF_3 = (FMC_A3<<16)|(5<<12)|(3<<4)|(12<<0),  
      FMC_A4_PF_4 = (FMC_A4<<16)|(5<<12)|(4<<4)|(12<<0),  
      FMC_A5_PF_5 = (FMC_A5<<16)|(5<<12)|(5<<4)|(12<<0),  
      FMC_A6_PF_12 = (FMC_A6<<16)|(5<<12)|(12<<4)|(12<<0),  
      FMC_A7_PF_13 = (FMC_A7<<16)|(5<<12)|(13<<4)|(12<<0),  
      FMC_A8_PF_14 = (FMC_A8<<16)|(5<<12)|(14<<4)|(12<<0),  
      FMC_A9_PF_15 = (FMC_A9<<16)|(5<<12)|(15<<4)|(12<<0),  
      FMC_ALE_PD_12 = (FMC_ALE<<16)|(3<<12)|(12<<4)|(12<<0),  
      FMC_BA0_PG_4 = (FMC_BA0<<16)|(6<<12)|(4<<4)|(12<<0),  
      FMC_BA1_PG_5 = (FMC_BA1<<16)|(6<<12)|(5<<4)|(12<<0),  
      FMC_CLE_PD_11 = (FMC_CLE<<16)|(3<<12)|(11<<4)|(12<<0),  
      FMC_CLK_PD_3 = (FMC_CLK<<16)|(3<<12)|(3<<4)|(12<<0),  
      FMC_D0_PD_14 = (FMC_D0<<16)|(3<<12)|(14<<4)|(12<<0),  
      FMC_D1_PD_15 = (FMC_D1<<16)|(3<<12)|(15<<4)|(12<<0),  
      FMC_D10_PE_13 = (FMC_D10<<16)|(4<<12)|(13<<4)|(12<<0),  
      FMC_D11_PE_14 = (FMC_D11<<16)|(4<<12)|(14<<4)|(12<<0),  
      FMC_D12_PE_15 = (FMC_D12<<16)|(4<<12)|(15<<4)|(12<<0),  
      FMC_D13_PD_8 = (FMC_D13<<16)|(3<<12)|(8<<4)|(12<<0),  
      FMC_D14_PD_9 = (FMC_D14<<16)|(3<<12)|(9<<4)|(12<<0),  
      FMC_D15_PD_10 = (FMC_D15<<16)|(3<<12)|(10<<4)|(12<<0),  
      FMC_D16_PH_8 = (FMC_D16<<16)|(7<<12)|(8<<4)|(12<<0),  
      FMC_D17_PH_9 = (FMC_D17<<16)|(7<<12)|(9<<4)|(12<<0),  
      FMC_D18_PH_10 = (FMC_D18<<16)|(7<<12)|(10<<4)|(12<<0),  
      FMC_D19_PH_11 = (FMC_D19<<16)|(7<<12)|(11<<4)|(12<<0),  
      FMC_D2_PD_0 = (FMC_D2<<16)|(3<<12)|(0<<4)|(12<<0),  
      FMC_D20_PH_12 = (FMC_D20<<16)|(7<<12)|(12<<4)|(12<<0),  
      FMC_D21_PH_13 = (FMC_D21<<16)|(7<<12)|(13<<4)|(12<<0),  
      FMC_D22_PH_14 = (FMC_D22<<16)|(7<<12)|(14<<4)|(12<<0),  
      FMC_D23_PH_15 = (FMC_D23<<16)|(7<<12)|(15<<4)|(12<<0),  
      FMC_D24_PI_0 = (FMC_D24<<16)|(8<<12)|(0<<4)|(12<<0),  
      FMC_D25_PI_1 = (FMC_D25<<16)|(8<<12)|(1<<4)|(12<<0),  
      FMC_D26_PI_2 = (FMC_D26<<16)|(8<<12)|(2<<4)|(12<<0),  
      FMC_D27_PI_3 = (FMC_D27<<16)|(8<<12)|(3<<4)|(12<<0),  
      FMC_D28_PI_6 = (FMC_D28<<16)|(8<<12)|(6<<4)|(12<<0),  
      FMC_D29_PI_7 = (FMC_D29<<16)|(8<<12)|(7<<4)|(12<<0),  
      FMC_D3_PD_1 = (FMC_D3<<16)|(3<<12)|(1<<4)|(12<<0),  
      FMC_D30_PI_9 = (FMC_D30<<16)|(8<<12)|(9<<4)|(12<<0),  
      FMC_D31_PI_10 = (FMC_D31<<16)|(8<<12)|(10<<4)|(12<<0),  
      FMC_D4_PE_7 = (FMC_D4<<16)|(4<<12)|(7<<4)|(12<<0),  
      FMC_D5_PE_8 = (FMC_D5<<16)|(4<<12)|(8<<4)|(12<<0),  
      FMC_D6_PE_9 = (FMC_D6<<16)|(4<<12)|(9<<4)|(12<<0),  
      FMC_D7_PE_10 = (FMC_D7<<16)|(4<<12)|(10<<4)|(12<<0),  
      FMC_D8_PE_11 = (FMC_D8<<16)|(4<<12)|(11<<4)|(12<<0),  
      FMC_D9_PE_12 = (FMC_D9<<16)|(4<<12)|(12<<4)|(12<<0),  
      FMC_INT_PG_7 = (FMC_INT<<16)|(6<<12)|(7<<4)|(12<<0),  
      FMC_NBL0_PE_0 = (FMC_NBL0<<16)|(4<<12)|(0<<4)|(12<<0),  
      FMC_NBL1_PE_1 = (FMC_NBL1<<16)|(4<<12)|(1<<4)|(12<<0),  
      FMC_NBL2_PI_4 = (FMC_NBL2<<16)|(8<<12)|(4<<4)|(12<<0),  
      FMC_NBL3_PI_5 = (FMC_NBL3<<16)|(8<<12)|(5<<4)|(12<<0),  
      FMC_NCE_PC_8 = (FMC_NCE<<16)|(2<<12)|(8<<4)|(9<<0),  
      FMC_NCE_PG_9 = (FMC_NCE<<16)|(6<<12)|(9<<4)|(12<<0),  
      FMC_NE1_PC_7 = (FMC_NE1<<16)|(2<<12)|(7<<4)|(9<<0),  
      FMC_NE1_PD_7 = (FMC_NE1<<16)|(3<<12)|(7<<4)|(12<<0),  
      FMC_NE2_PC_8 = (FMC_NE2<<16)|(2<<12)|(8<<4)|(9<<0),  
      FMC_NE2_PG_9 = (FMC_NE2<<16)|(6<<12)|(9<<4)|(12<<0),  
      FMC_NE3_PG_6 = (FMC_NE3<<16)|(6<<12)|(6<<4)|(12<<0),  
      FMC_NE3_PG_10 = (FMC_NE3<<16)|(6<<12)|(10<<4)|(12<<0),  
      FMC_NE4_PG_12 = (FMC_NE4<<16)|(6<<12)|(12<<4)|(12<<0),  
      FMC_NOE_PD_4 = (FMC_NOE<<16)|(3<<12)|(4<<4)|(12<<0),  
      FMC_NWAIT_PC_6 = (FMC_NWAIT<<16)|(2<<12)|(6<<4)|(9<<0),  
      FMC_NWAIT_PD_6 = (FMC_NWAIT<<16)|(3<<12)|(6<<4)|(12<<0),  
      FMC_NWE_PD_5 = (FMC_NWE<<16)|(3<<12)|(5<<4)|(12<<0),  
      FMC_SDCKE0_PC_3 = (FMC_SDCKE0<<16)|(2<<12)|(3<<4)|(12<<0),  
      FMC_SDCKE0_PC_5 = (FMC_SDCKE0<<16)|(2<<12)|(5<<4)|(12<<0),  
      FMC_SDCKE0_PH_2 = (FMC_SDCKE0<<16)|(7<<12)|(2<<4)|(12<<0),  
      FMC_SDCKE1_PB_5 = (FMC_SDCKE1<<16)|(1<<12)|(5<<4)|(12<<0),  
      FMC_SDCKE1_PH_7 = (FMC_SDCKE1<<16)|(7<<12)|(7<<4)|(12<<0),  
      FMC_SDCLK_PG_8 = (FMC_SDCLK<<16)|(6<<12)|(8<<4)|(12<<0),  
      FMC_SDNCAS_PG_15 = (FMC_SDNCAS<<16)|(6<<12)|(15<<4)|(12<<0),  
      FMC_SDNE0_PC_2 = (FMC_SDNE0<<16)|(2<<12)|(2<<4)|(12<<0),  
      FMC_SDNE0_PC_4 = (FMC_SDNE0<<16)|(2<<12)|(4<<4)|(12<<0),  
      FMC_SDNE0_PH_3 = (FMC_SDNE0<<16)|(7<<12)|(3<<4)|(12<<0),  
      FMC_SDNE1_PB_6 = (FMC_SDNE1<<16)|(1<<12)|(6<<4)|(12<<0),  
      FMC_SDNE1_PH_6 = (FMC_SDNE1<<16)|(7<<12)|(6<<4)|(12<<0),  
      FMC_SDNRAS_PF_11 = (FMC_SDNRAS<<16)|(5<<12)|(11<<4)|(12<<0),  
      FMC_SDNWE_PA_7 = (FMC_SDNWE<<16)|(0<<12)|(7<<4)|(12<<0),  
      FMC_SDNWE_PC_0 = (FMC_SDNWE<<16)|(2<<12)|(0<<4)|(12<<0),  
      FMC_SDNWE_PH_5 = (FMC_SDNWE<<16)|(7<<12)|(5<<4)|(12<<0),  
      HDMICEC_PA_15 = (HDMICEC<<16)|(0<<12)|(15<<4)|(3<<0),  
      HDMICEC_PB_6 = (HDMICEC<<16)|(1<<12)|(6<<4)|(3<<0),  
      I2C1_SCL_PB_6 = (I2C1_SCL<<16)|(1<<12)|(6<<4)|(4<<0),  
      I2C1_SCL_PB_8 = (I2C1_SCL<<16)|(1<<12)|(8<<4)|(4<<0),  
      I2C1_SDA_PB_9 = (I2C1_SDA<<16)|(1<<12)|(9<<4)|(4<<0),  
			I2C1_SMBA_PB_5 = (I2C1_SMBA<<16)|(1<<12)|(5<<4)|(4<<0),  
      I2C2_SCL_PF_1 = (I2C2_SCL<<16)|(5<<12)|(1<<4)|(4<<0),  
      I2C2_SCL_PH_4 = (I2C2_SCL<<16)|(7<<12)|(4<<4)|(4<<0),  
      I2C2_SDA_PF_0 = (I2C2_SDA<<16)|(5<<12)|(0<<4)|(4<<0),  
      I2C2_SDA_PH_5 = (I2C2_SDA<<16)|(7<<12)|(5<<4)|(4<<0),  
      I2C2_SMBA_PF_2 = (I2C2_SMBA<<16)|(5<<12)|(2<<4)|(4<<0),  
      I2C2_SMBA_PH_6 = (I2C2_SMBA<<16)|(7<<12)|(6<<4)|(4<<0),  
      I2C3_SCL_PA_8 = (I2C3_SCL<<16)|(0<<12)|(8<<4)|(4<<0),  
      I2C3_SCL_PH_7 = (I2C3_SCL<<16)|(7<<12)|(7<<4)|(4<<0),  
      I2C3_SDA_PC_9 = (I2C3_SDA<<16)|(2<<12)|(9<<4)|(4<<0),  
      I2C3_SDA_PH_8 = (I2C3_SDA<<16)|(7<<12)|(8<<4)|(4<<0),  
      I2C3_SMBA_PA_9 = (I2C3_SMBA<<16)|(0<<12)|(9<<4)|(4<<0),  
      I2C3_SMBA_PH_9 = (I2C3_SMBA<<16)|(7<<12)|(9<<4)|(4<<0),  
      I2C4_SCL_PB_6 = (I2C4_SCL<<16)|(1<<12)|(6<<4)|(11<<0),  
      I2C4_SCL_PD_12 = (I2C4_SCL<<16)|(3<<12)|(12<<4)|(4<<0),  
      I2C4_SCL_PF_14 = (I2C4_SCL<<16)|(5<<12)|(14<<4)|(4<<0),  
      I2C4_SCL_PH_11 = (I2C4_SCL<<16)|(7<<12)|(11<<4)|(4<<0),  
      I2C4_SDA_PB_7  = (I2C4_SDA<<16)|(1<<12)|(7<<4)|(11<<0),  
      I2C4_SDA_PD_13 = (I2C4_SDA<<16)|(3<<12)|(13<<4)|(4<<0),  
      I2C4_SDA_PF_15 = (I2C4_SDA<<16)|(5<<12)|(15<<4)|(4<<0),  
      I2C4_SDA_PH_12 = (I2C4_SDA<<16)|(7<<12)|(12<<4)|(4<<0),  
      I2C4_SMBA_PD_11 = (I2C4_SMBA<<16)|(3<<12)|(11<<4)|(4<<0),  
      I2C4_SMBA_PF_13 = (I2C4_SMBA<<16)|(5<<12)|(13<<4)|(4<<0),  
      I2C4_SMBA_PH_10 = (I2C4_SMBA<<16)|(7<<12)|(10<<4)|(4<<0),  
      I2S_CKIN_PC_9 = (I2S_CKIN<<16)|(2<<12)|(9<<4)|(5<<0),  
      I2S1_CK_PA_5 = (I2S1_CK<<16)|(0<<12)|(5<<4)|(5<<0),  
      I2S1_CK_PB_3 = (I2S1_CK<<16)|(1<<12)|(3<<4)|(5<<0),  
      I2S1_CK_PG_11 = (I2S1_CK<<16)|(6<<12)|(11<<4)|(5<<0),  
      I2S1_MCK_PC_4 = (I2S1_MCK<<16)|(2<<12)|(4<<4)|(5<<0),  
      I2S1_SD_PA_7 = (I2S1_SD<<16)|(0<<12)|(7<<4)|(5<<0),  
      I2S1_SD_PB_5 = (I2S1_SD<<16)|(1<<12)|(5<<4)|(5<<0),  
      I2S1_SD_PD_7 = (I2S1_SD<<16)|(3<<12)|(7<<4)|(5<<0),  
      I2S1_WS_PA_4 = (I2S1_WS<<16)|(0<<12)|(4<<4)|(5<<0),  
      I2S1_WS_PA_15 = (I2S1_WS<<16)|(0<<12)|(15<<4)|(5<<0),  
      I2S1_WS_PG_10 = (I2S1_WS<<16)|(6<<12)|(10<<4)|(5<<0),  
      I2S2_CK_PA_9 = (I2S2_CK<<16)|(0<<12)|(9<<4)|(5<<0),  
      I2S2_CK_PA_12 = (I2S2_CK<<16)|(0<<12)|(12<<4)|(5<<0),  
      I2S2_CK_PD_3 = (I2S2_CK<<16)|(3<<12)|(3<<4)|(5<<0),  
      I2S2_CK_PI_1 = (I2S2_CK<<16)|(8<<12)|(1<<4)|(5<<0),  
      I2S2_MCK_PC_6 = (I2S2_MCK<<16)|(2<<12)|(6<<4)|(5<<0),  
      I2S2_SD_PC_1 = (I2S2_SD<<16)|(2<<12)|(1<<4)|(5<<0),  
      I2S2_SD_PC_3 = (I2S2_SD<<16)|(2<<12)|(3<<4)|(5<<0),  
      I2S2_SD_PI_3 = (I2S2_SD<<16)|(8<<12)|(3<<4)|(5<<0),  
      I2S2_WS_PA_11 = (I2S2_WS<<16)|(0<<12)|(11<<4)|(5<<0),  
      I2S2_WS_PB_4 = (I2S2_WS<<16)|(1<<12)|(4<<4)|(7<<0),  
      I2S2_WS_PI_0 = (I2S2_WS<<16)|(8<<12)|(0<<4)|(5<<0),  
      I2S3_CK_PB_3 = (I2S3_CK<<16)|(1<<12)|(3<<4)|(6<<0),  
      I2S3_CK_PC_10 = (I2S3_CK<<16)|(2<<12)|(10<<4)|(6<<0),  
      I2S3_MCK_PC_7 = (I2S3_MCK<<16)|(2<<12)|(7<<4)|(6<<0),  
      I2S3_SD_PB_2 = (I2S3_SD<<16)|(1<<12)|(2<<4)|(7<<0),  
      I2S3_SD_PB_5 = (I2S3_SD<<16)|(1<<12)|(5<<4)|(6<<0),  
      I2S3_SD_PC_12 = (I2S3_SD<<16)|(2<<12)|(12<<4)|(6<<0),  
      I2S3_SD_PD_6 = (I2S3_SD<<16)|(3<<12)|(6<<4)|(5<<0),  
      I2S3_WS_PA_4 = (I2S3_WS<<16)|(0<<12)|(4<<4)|(6<<0),  
      I2S3_WS_PA_15 = (I2S3_WS<<16)|(0<<12)|(15<<4)|(6<<0),  
      JTCKSWCLK_PA_14 = (JTCKSWCLK<<16)|(0<<12)|(14<<4)|(0<<0),  
      JTDI_PA_15 = (JTDI<<16)|(0<<12)|(15<<4)|(0<<0),  
      JTDO_PB_3 = (JTDO<<16)|(1<<12)|(3<<4)|(0<<0),  
      JTMSSWDIO_PA_13 = (JTMSSWDIO<<16)|(0<<12)|(13<<4)|(0<<0),  
      LCD_B0_PE_4 = (LCD_B0<<16)|(4<<12)|(4<<4)|(14<<0),  
      LCD_B0_PG_14 = (LCD_B0<<16)|(6<<12)|(14<<4)|(14<<0),  
      LCD_B0_PJ_12 = (LCD_B0<<16)|(9<<12)|(12<<4)|(14<<0),  
      LCD_B1_PA_10 = (LCD_B1<<16)|(0<<12)|(10<<4)|(14<<0),  
      LCD_B1_PG_12 = (LCD_B1<<16)|(6<<12)|(12<<4)|(14<<0),  
      LCD_B1_PJ_13 = (LCD_B1<<16)|(9<<12)|(13<<4)|(14<<0),  
      LCD_B2_PA_3 = (LCD_B2<<16)|(0<<12)|(3<<4)|(9<<0),  
      LCD_B2_PC_9 = (LCD_B2<<16)|(2<<12)|(9<<4)|(14<<0),  
      LCD_B2_PD_6 = (LCD_B2<<16)|(3<<12)|(6<<4)|(14<<0),  
      LCD_B2_PG_10 = (LCD_B2<<16)|(6<<12)|(10<<4)|(14<<0),  
      LCD_B2_PJ_14 = (LCD_B2<<16)|(9<<12)|(14<<4)|(14<<0),  
      LCD_B3_PA_8 = (LCD_B3<<16)|(0<<12)|(8<<4)|(13<<0),  
      LCD_B3_PD_10 = (LCD_B3<<16)|(3<<12)|(10<<4)|(14<<0),  
      LCD_B3_PG_11 = (LCD_B3<<16)|(6<<12)|(11<<4)|(14<<0),  
      LCD_B3_PJ_15 = (LCD_B3<<16)|(9<<12)|(15<<4)|(14<<0),  
      LCD_B4_PA_10 = (LCD_B4<<16)|(0<<12)|(10<<4)|(9<<0),  
      LCD_B4_PE_12 = (LCD_B4<<16)|(4<<12)|(12<<4)|(14<<0),  
      LCD_B4_PG_12 = (LCD_B4<<16)|(6<<12)|(12<<4)|(9<<0),  
      LCD_B4_PI_4 = (LCD_B4<<16)|(8<<12)|(4<<4)|(14<<0),  
      LCD_B4_PK_3 = (LCD_B4<<16)|(10<<12)|(3<<4)|(14<<0),  
      LCD_B5_PA_3 = (LCD_B5<<16)|(0<<12)|(3<<4)|(14<<0),  
      LCD_B5_PI_5 = (LCD_B5<<16)|(8<<12)|(5<<4)|(14<<0),  
      LCD_B5_PK_4 = (LCD_B5<<16)|(10<<12)|(4<<4)|(14<<0),  
      LCD_B6_PI_6 = (LCD_B6<<16)|(8<<12)|(6<<4)|(14<<0),  
      LCD_B6_PK_5 = (LCD_B6<<16)|(10<<12)|(5<<4)|(14<<0),  
      LCD_B7_PI_7 = (LCD_B7<<16)|(8<<12)|(7<<4)|(14<<0),  
      LCD_B7_PK_6 = (LCD_B7<<16)|(10<<12)|(6<<4)|(14<<0),  
      LCD_CLK_PE_14 = (LCD_CLK<<16)|(4<<12)|(14<<4)|(14<<0),  
      LCD_CLK_PG_7 = (LCD_CLK<<16)|(6<<12)|(7<<4)|(14<<0),  
      LCD_CLK_PI_14 = (LCD_CLK<<16)|(8<<12)|(14<<4)|(14<<0),  
      LCD_DE_PE_13 = (LCD_DE<<16)|(4<<12)|(13<<4)|(14<<0),  
      LCD_DE_PF_10 = (LCD_DE<<16)|(5<<12)|(10<<4)|(14<<0),  
      LCD_DE_PK_7 = (LCD_DE<<16)|(10<<12)|(7<<4)|(14<<0),  
      LCD_G0_PB_1 = (LCD_G0<<16)|(1<<12)|(1<<4)|(14<<0),  
      LCD_G0_PE_5 = (LCD_G0<<16)|(4<<12)|(5<<4)|(14<<0),  
      LCD_G0_PJ_7 = (LCD_G0<<16)|(9<<12)|(7<<4)|(14<<0),  
      LCD_G1_PB_0 = (LCD_G1<<16)|(1<<12)|(0<<4)|(14<<0),  
      LCD_G1_PE_6 = (LCD_G1<<16)|(4<<12)|(6<<4)|(14<<0),  
      LCD_G1_PJ_8 = (LCD_G1<<16)|(9<<12)|(8<<4)|(14<<0),  
      LCD_G2_PA_6 = (LCD_G2<<16)|(0<<12)|(6<<4)|(14<<0),  
      LCD_G2_PH_13 = (LCD_G2<<16)|(7<<12)|(13<<4)|(14<<0),  
      LCD_G2_PI_15 = (LCD_G2<<16)|(8<<12)|(15<<4)|(9<<0),  
      LCD_G2_PJ_9 = (LCD_G2<<16)|(9<<12)|(9<<4)|(14<<0),  
      LCD_G3_PC_9 = (LCD_G3<<16)|(2<<12)|(9<<4)|(10<<0),  
      LCD_G3_PE_11 = (LCD_G3<<16)|(4<<12)|(11<<4)|(14<<0),  
      LCD_G3_PG_10 = (LCD_G3<<16)|(6<<12)|(10<<4)|(9<<0),  
      LCD_G3_PH_14 = (LCD_G3<<16)|(7<<12)|(14<<4)|(14<<0),  
      LCD_G3_PJ_10 = (LCD_G3<<16)|(9<<12)|(10<<4)|(14<<0),  
      LCD_G3_PJ_12 = (LCD_G3<<16)|(9<<12)|(12<<4)|(9<<0),  
      LCD_G4_PH_4 = (LCD_G4<<16)|(7<<12)|(4<<4)|(14<<0),  
      LCD_G4_PH_15 = (LCD_G4<<16)|(7<<12)|(15<<4)|(14<<0),  
      LCD_G4_PJ_11 = (LCD_G4<<16)|(9<<12)|(11<<4)|(14<<0),  
      LCD_G4_PJ_13 = (LCD_G4<<16)|(9<<12)|(13<<4)|(9<<0),  
      LCD_G5_PH_4 = (LCD_G5<<16)|(7<<12)|(4<<4)|(9<<0),  
      LCD_G5_PI_0 = (LCD_G5<<16)|(8<<12)|(0<<4)|(14<<0),  
      LCD_G5_PK_0 = (LCD_G5<<16)|(10<<12)|(0<<4)|(14<<0),  
      LCD_G6_PC_7 = (LCD_G6<<16)|(2<<12)|(7<<4)|(14<<0),  
      LCD_G6_PI_1 = (LCD_G6<<16)|(8<<12)|(1<<4)|(14<<0),  
      LCD_G6_PI_11 = (LCD_G6<<16)|(8<<12)|(11<<4)|(9<<0),  
      LCD_G6_PK_1 = (LCD_G6<<16)|(10<<12)|(1<<4)|(14<<0),  
      LCD_G7_PB_5 = (LCD_G7<<16)|(1<<12)|(5<<4)|(14<<0),  
      LCD_G7_PD_3 = (LCD_G7<<16)|(3<<12)|(3<<4)|(14<<0),  
      LCD_G7_PG_8 = (LCD_G7<<16)|(6<<12)|(8<<4)|(14<<0),  
      LCD_G7_PI_2 = (LCD_G7<<16)|(8<<12)|(2<<4)|(14<<0),  
      LCD_G7_PK_2 = (LCD_G7<<16)|(10<<12)|(2<<4)|(14<<0),  
      LCD_HSYNC_PC_6 = (LCD_HSYNC<<16)|(2<<12)|(6<<4)|(14<<0),  
      LCD_HSYNC_PI_10 = (LCD_HSYNC<<16)|(8<<12)|(10<<4)|(14<<0),  
      LCD_HSYNC_PI_12 = (LCD_HSYNC<<16)|(8<<12)|(12<<4)|(14<<0),  
      LCD_R0_PG_13 = (LCD_R0<<16)|(6<<12)|(13<<4)|(14<<0),  
      LCD_R0_PH_2 = (LCD_R0<<16)|(7<<12)|(2<<4)|(14<<0),  
      LCD_R0_PI_15 = (LCD_R0<<16)|(8<<12)|(15<<4)|(14<<0),  
      LCD_R1_PA_2 = (LCD_R1<<16)|(0<<12)|(2<<4)|(14<<0),  
      LCD_R1_PH_3 = (LCD_R1<<16)|(7<<12)|(3<<4)|(14<<0),  
      LCD_R1_PJ_0 = (LCD_R1<<16)|(9<<12)|(0<<4)|(14<<0),  
      LCD_R2_PA_1 = (LCD_R2<<16)|(0<<12)|(1<<4)|(14<<0),  
      LCD_R2_PC_10 = (LCD_R2<<16)|(2<<12)|(10<<4)|(14<<0),  
      LCD_R2_PH_8 = (LCD_R2<<16)|(7<<12)|(8<<4)|(14<<0),  
      LCD_R2_PJ_1 = (LCD_R2<<16)|(9<<12)|(1<<4)|(14<<0),  
      LCD_R3_PB_0 = (LCD_R3<<16)|(1<<12)|(0<<4)|(9<<0),  
      LCD_R3_PH_9 = (LCD_R3<<16)|(7<<12)|(9<<4)|(14<<0),  
      LCD_R3_PJ_2 = (LCD_R3<<16)|(9<<12)|(2<<4)|(14<<0),  
      LCD_R4_PA_5 = (LCD_R4<<16)|(0<<12)|(5<<4)|(14<<0),  
      LCD_R4_PA_11 = (LCD_R4<<16)|(0<<12)|(11<<4)|(14<<0),  
      LCD_R4_PH_10 = (LCD_R4<<16)|(7<<12)|(10<<4)|(14<<0),  
      LCD_R4_PJ_3 = (LCD_R4<<16)|(9<<12)|(3<<4)|(14<<0),  
      LCD_R5_PA_9 = (LCD_R5<<16)|(0<<12)|(9<<4)|(14<<0),  
      LCD_R5_PA_12 = (LCD_R5<<16)|(0<<12)|(12<<4)|(14<<0),  
      LCD_R5_PC_0 = (LCD_R5<<16)|(2<<12)|(0<<4)|(14<<0),  
      LCD_R5_PH_11 = (LCD_R5<<16)|(7<<12)|(11<<4)|(14<<0),  
      LCD_R5_PJ_4 = (LCD_R5<<16)|(9<<12)|(4<<4)|(14<<0),  
      LCD_R6_PA_8 = (LCD_R6<<16)|(0<<12)|(8<<4)|(14<<0),  
      LCD_R6_PB_1 = (LCD_R6<<16)|(1<<12)|(1<<4)|(9<<0),  
      LCD_R6_PH_12 = (LCD_R6<<16)|(7<<12)|(12<<4)|(14<<0),  
      LCD_R6_PJ_5 = (LCD_R6<<16)|(9<<12)|(5<<4)|(14<<0),  
      LCD_R7_PE_15 = (LCD_R7<<16)|(4<<12)|(15<<4)|(14<<0),  
      LCD_R7_PG_6 = (LCD_R7<<16)|(6<<12)|(6<<4)|(14<<0),  
      LCD_R7_PJ_0 = (LCD_R7<<16)|(9<<12)|(0<<4)|(9<<0),  
      LCD_R7_PJ_6 = (LCD_R7<<16)|(9<<12)|(6<<4)|(14<<0),  
      LCD_VSYNC_PI_13 = (LCD_VSYNC<<16)|(8<<12)|(13<<4)|(14<<0),  
      LCD_VSYNC_PA_4 = (LCD_VSYNC<<16)|(0<<12)|(4<<4)|(14<<0),  
      LCD_VSYNC_PI_9 = (LCD_VSYNC<<16)|(8<<12)|(9<<4)|(14<<0),  
      LPTIM1_ETR_PE_0 = (LPTIM1_ETR<<16)|(4<<12)|(0<<4)|(3<<0),  
      LPTIM1_ETR_PG_14 = (LPTIM1_ETR<<16)|(6<<12)|(14<<4)|(3<<0),  
      LPTIM1_IN1_PG_12 = (LPTIM1_IN1<<16)|(6<<12)|(12<<4)|(3<<0),  
      LPTIM1_IN2_PE_1 = (LPTIM1_IN2<<16)|(4<<12)|(1<<4)|(3<<0),  
      LPTIM1_IN2_PH_2 = (LPTIM1_IN2<<16)|(7<<12)|(2<<4)|(3<<0),  
      LPTIM1_OUT_PD_13 = (LPTIM1_OUT<<16)|(3<<12)|(13<<4)|(3<<0),  
      LPTIM1_OUT_PG_13 = (LPTIM1_OUT<<16)|(6<<12)|(13<<4)|(3<<0),  
      MCO1_PA_8 = (MCO1<<16)|(0<<12)|(8<<4)|(0<<0),  
      MCO2_PC_9 = (MCO2<<16)|(2<<12)|(9<<4)|(0<<0),  
      MDIOS_MDC_PA_6 = (MDIOS_MDC<<16)|(0<<12)|(6<<4)|(12<<0),  
      MDIOS_MDIO_PA_2 = (MDIOS_MDIO<<16)|(0<<12)|(2<<4)|(12<<0),  
      MDIOS_MDIO_PA_10 = (MDIOS_MDIO<<16)|(0<<12)|(10<<4)|(12<<0),  
      NJTRST_PB_4 = (NJTRST<<16)|(1<<12)|(4<<4)|(0<<0),  
      OTG_FS_DM_PA_11 = (OTG_FS_DM<<16)|(0<<12)|(11<<4)|(10<<0),  
      OTG_FS_DP_PA_12 = (OTG_FS_DP<<16)|(0<<12)|(12<<4)|(10<<0),  
      OTG_FS_ID_PA_10 = (OTG_FS_ID<<16)|(0<<12)|(10<<4)|(10<<0),  
      OTG_FS_SOF_PA_8 = (OTG_FS_SOF<<16)|(0<<12)|(8<<4)|(10<<0),  
      OTG_HS_SOF_PA_4 = (OTG_HS_SOF<<16)|(0<<12)|(4<<4)|(12<<0),  
      OTG_HS_ULPI_CK_PA_5 = (OTG_HS_ULPI_CK<<16)|(0<<12)|(5<<4)|(10<<0),  
      OTG_HS_ULPI_D0_PA_3 = (OTG_HS_ULPI_D0<<16)|(0<<12)|(3<<4)|(10<<0),  
      OTG_HS_ULPI_D1_PB_0 = (OTG_HS_ULPI_D1<<16)|(1<<12)|(0<<4)|(10<<0),  
      OTG_HS_ULPI_D2_PB_1 = (OTG_HS_ULPI_D2<<16)|(1<<12)|(1<<4)|(10<<0),  
      OTG_HS_ULPI_D7_PB_5 = (OTG_HS_ULPI_D7<<16)|(1<<12)|(5<<4)|(10<<0),  
      OTG_HS_ULPI_DIR_PC_2 = (OTG_HS_ULPI_DIR<<16)|(2<<12)|(2<<4)|(10<<0),  
      OTG_HS_ULPI_DIR_PI_11 = (OTG_HS_ULPI_DIR<<16)|(8<<12)|(11<<4)|(10<<0),  
      OTG_HS_ULPI_NXT_PC_3 = (OTG_HS_ULPI_NXT<<16)|(2<<12)|(3<<4)|(10<<0),  
      OTG_HS_ULPI_NXT_PH_4 = (OTG_HS_ULPI_NXT<<16)|(7<<12)|(4<<4)|(10<<0),  
      OTG_HS_ULPI_STP_PC_0 = (OTG_HS_ULPI_STP<<16)|(2<<12)|(0<<4)|(10<<0),  
      QUADSPI_BK1_IO0_PC_9 = (QUADSPI_BK1_IO0<<16)|(2<<12)|(9<<4)|(9<<0),  
      QUADSPI_BK1_IO0_PD_11 = (QUADSPI_BK1_IO0<<16)|(3<<12)|(11<<4)|(9<<0),  
      QUADSPI_BK1_IO0_PF_8 = (QUADSPI_BK1_IO0<<16)|(5<<12)|(8<<4)|(10<<0),  
      QUADSPI_BK1_IO1_PC_10 = (QUADSPI_BK1_IO1<<16)|(2<<12)|(10<<4)|(9<<0),  
      QUADSPI_BK1_IO1_PD_12 = (QUADSPI_BK1_IO1<<16)|(3<<12)|(12<<4)|(9<<0),  
      QUADSPI_BK1_IO1_PF_9 = (QUADSPI_BK1_IO1<<16)|(5<<12)|(9<<4)|(10<<0),  
      QUADSPI_BK1_IO2_PE_2 = (QUADSPI_BK1_IO2<<16)|(4<<12)|(2<<4)|(9<<0),  
      QUADSPI_BK1_IO2_PF_7 = (QUADSPI_BK1_IO2<<16)|(5<<12)|(7<<4)|(9<<0),  
      QUADSPI_BK1_IO3_PA_1 = (QUADSPI_BK1_IO3<<16)|(0<<12)|(1<<4)|(9<<0),  
      QUADSPI_BK1_IO3_PD_13 = (QUADSPI_BK1_IO3<<16)|(3<<12)|(13<<4)|(9<<0),  
      QUADSPI_BK1_IO3_PF_6 = (QUADSPI_BK1_IO3<<16)|(5<<12)|(6<<4)|(9<<0),  
      QUADSPI_BK1_NCS_PB_6 = (QUADSPI_BK1_NCS<<16)|(1<<12)|(6<<4)|(10<<0),  
      QUADSPI_BK2_IO0_PE_7 = (QUADSPI_BK2_IO0<<16)|(4<<12)|(7<<4)|(10<<0),  
      QUADSPI_BK2_IO0_PH_2 = (QUADSPI_BK2_IO0<<16)|(7<<12)|(2<<4)|(9<<0),  
      QUADSPI_BK2_IO1_PE_8 = (QUADSPI_BK2_IO1<<16)|(4<<12)|(8<<4)|(10<<0),  
      QUADSPI_BK2_IO1_PH_3 = (QUADSPI_BK2_IO1<<16)|(7<<12)|(3<<4)|(9<<0),  
      QUADSPI_BK2_IO2_PE_9 = (QUADSPI_BK2_IO2<<16)|(4<<12)|(9<<4)|(10<<0),  
      QUADSPI_BK2_IO2_PG_9 = (QUADSPI_BK2_IO2<<16)|(6<<12)|(9<<4)|(9<<0),  
      QUADSPI_BK2_IO3_PE_10 = (QUADSPI_BK2_IO3<<16)|(4<<12)|(10<<4)|(10<<0),  
      QUADSPI_BK2_IO3_PG_14 = (QUADSPI_BK2_IO3<<16)|(6<<12)|(14<<4)|(9<<0),  
      QUADSPI_BK2_NCS_PC_11 = (QUADSPI_BK2_NCS<<16)|(2<<12)|(11<<4)|(9<<0),  
      QUADSPI_CLK_PB_2 = (QUADSPI_CLK<<16)|(1<<12)|(2<<4)|(9<<0),  
      QUADSPI_CLK_PF_10 = (QUADSPI_CLK<<16)|(5<<12)|(10<<4)|(9<<0),  
      SAI1_FS_A_PE_4 = (SAI1_FS_A<<16)|(4<<12)|(4<<4)|(6<<0),  
      SAI1_FS_B_PF_9 = (SAI1_FS_B<<16)|(5<<12)|(9<<4)|(6<<0),  
      SAI1_MCLK_A_PE_2 = (SAI1_MCLK_A<<16)|(4<<12)|(2<<4)|(6<<0),  
      SAI1_MCLK_A_PG_7 = (SAI1_MCLK_A<<16)|(6<<12)|(7<<4)|(6<<0),  
      SAI1_MCLK_B_PF_7 = (SAI1_MCLK_B<<16)|(5<<12)|(7<<4)|(6<<0),  
      SAI1_SCK_A_PE_5 = (SAI1_SCK_A<<16)|(4<<12)|(5<<4)|(6<<0),  
      SAI1_SCK_B_PF_8 = (SAI1_SCK_B<<16)|(5<<12)|(8<<4)|(6<<0),  
      SAI1_SD_A_PB_2 = (SAI1_SD_A<<16)|(1<<12)|(2<<4)|(6<<0),  
      SAI1_SD_A_PC_1 = (SAI1_SD_A<<16)|(2<<12)|(1<<4)|(6<<0),  
      SAI1_SD_A_PD_6 = (SAI1_SD_A<<16)|(3<<12)|(6<<4)|(6<<0),  
      SAI1_SD_A_PE_6 = (SAI1_SD_A<<16)|(4<<12)|(6<<4)|(6<<0),  
      SAI1_SD_B_PE_3 = (SAI1_SD_B<<16)|(4<<12)|(3<<4)|(6<<0),  
      SAI1_SD_B_PF_6 = (SAI1_SD_B<<16)|(5<<12)|(6<<4)|(6<<0),  
      SAI2_FS_A_PD_12 = (SAI2_FS_A<<16)|(3<<12)|(12<<4)|(10<<0),  
      SAI2_FS_A_PI_7 = (SAI2_FS_A<<16)|(8<<12)|(7<<4)|(10<<0),  
      SAI2_FS_B_PA_12 = (SAI2_FS_B<<16)|(0<<12)|(12<<4)|(8<<0),  
      SAI2_FS_B_PC_0 = (SAI2_FS_B<<16)|(2<<12)|(0<<4)|(8<<0),  
      SAI2_FS_B_PE_13 = (SAI2_FS_B<<16)|(4<<12)|(13<<4)|(10<<0),  
      SAI2_FS_B_PG_9 = (SAI2_FS_B<<16)|(6<<12)|(9<<4)|(10<<0),  
      SAI2_MCK_A_PE_0 = (SAI2_MCK_A<<16)|(4<<12)|(0<<4)|(10<<0),  
      SAI2_MCK_A_PI_4 = (SAI2_MCK_A<<16)|(8<<12)|(4<<4)|(10<<0),  
      SAI2_MCK_B_PA_1 = (SAI2_MCK_B<<16)|(0<<12)|(1<<4)|(10<<0),  
      SAI2_MCK_B_PE_6 = (SAI2_MCK_B<<16)|(4<<12)|(6<<4)|(10<<0),  
      SAI2_MCK_B_PE_14 = (SAI2_MCK_B<<16)|(4<<12)|(14<<4)|(10<<0),  
      SAI2_MCK_B_PH_3 = (SAI2_MCK_B<<16)|(7<<12)|(3<<4)|(10<<0),  
      SAI2_SCK_A_PD_13 = (SAI2_SCK_A<<16)|(3<<12)|(13<<4)|(10<<0),  
      SAI2_SCK_A_PI_5 = (SAI2_SCK_A<<16)|(8<<12)|(5<<4)|(10<<0),  
      SAI2_SCK_B_PA_2 = (SAI2_SCK_B<<16)|(0<<12)|(2<<4)|(8<<0),  
      SAI2_SCK_B_PE_12 = (SAI2_SCK_B<<16)|(4<<12)|(12<<4)|(10<<0),  
      SAI2_SCK_B_PH_2 = (SAI2_SCK_B<<16)|(7<<12)|(2<<4)|(10<<0),  
      SAI2_SD_A_PD_11 = (SAI2_SD_A<<16)|(3<<12)|(11<<4)|(10<<0),  
      SAI2_SD_A_PI_6 = (SAI2_SD_A<<16)|(8<<12)|(6<<4)|(10<<0),  
      SAI2_SD_B_PA_0 = (SAI2_SD_B<<16)|(0<<12)|(0<<4)|(10<<0),  
      SAI2_SD_B_PE_11 = (SAI2_SD_B<<16)|(4<<12)|(11<<4)|(10<<0),  
      SAI2_SD_B_PF_11 = (SAI2_SD_B<<16)|(5<<12)|(11<<4)|(10<<0),  
      SAI2_SD_B_PG_10 = (SAI2_SD_B<<16)|(6<<12)|(10<<4)|(10<<0),  
      SDMMC_CK_PC_12 = (SDMMC_CK<<16)|(2<<12)|(12<<4)|(12<<0),  
      SDMMC_CMD_PD_2 = (SDMMC_CMD<<16)|(3<<12)|(2<<4)|(12<<0),  
      SDMMC_D0_PC_8 = (SDMMC_D0<<16)|(2<<12)|(8<<4)|(12<<0),  
      SDMMC_D1_PC_9 = (SDMMC_D1<<16)|(2<<12)|(9<<4)|(12<<0),  
      SDMMC_D2_PC_10 = (SDMMC_D2<<16)|(2<<12)|(10<<4)|(12<<0),  
      SDMMC_D3_PC_11 = (SDMMC_D3<<16)|(2<<12)|(11<<4)|(12<<0),  
      SDMMC_D6_PC_6 = (SDMMC_D6<<16)|(2<<12)|(6<<4)|(12<<0),  
      SDMMC_D7_PC_7 = (SDMMC_D7<<16)|(2<<12)|(7<<4)|(12<<0),  
      SDMMC2_CK_PD_6 = (SDMMC2_CK<<16)|(3<<12)|(6<<4)|(11<<0),  
      SDMMC2_CMD_PD_7 = (SDMMC2_CMD<<16)|(3<<12)|(7<<4)|(11<<0),  
      SDMMC2_D0_PG_9 = (SDMMC2_D0<<16)|(6<<12)|(9<<4)|(11<<0),  
      SDMMC2_D1_PG_10 = (SDMMC2_D1<<16)|(6<<12)|(10<<4)|(11<<0),  
      SDMMC2_D2_PB_3 = (SDMMC2_D2<<16)|(1<<12)|(3<<4)|(10<<0),  
      SDMMC2_D2_PG_11 = (SDMMC2_D2<<16)|(6<<12)|(11<<4)|(10<<0),  
      SDMMC2_D3_PB_4 = (SDMMC2_D3<<16)|(1<<12)|(4<<4)|(10<<0),  
      SDMMC2_D3_PG_12 = (SDMMC2_D3<<16)|(6<<12)|(12<<4)|(11<<0),  
      SDMMC2_D6_PC_6 = (SDMMC2_D6<<16)|(2<<12)|(6<<4)|(10<<0),  
      SDMMC2_D7_PC_7 = (SDMMC2_D7<<16)|(2<<12)|(7<<4)|(10<<0),  
      SPDIF_RX0_PD_7 = (SPDIF_RX0<<16)|(3<<12)|(7<<4)|(8<<0),  
      SPDIF_RX0_PG_11 = (SPDIF_RX0<<16)|(6<<12)|(11<<4)|(7<<0),  
      SPDIF_RX1_PD_8 = (SPDIF_RX1<<16)|(3<<12)|(8<<4)|(8<<0),  
      SPDIF_RX1_PG_12 = (SPDIF_RX1<<16)|(6<<12)|(12<<4)|(7<<0),  
      SPDIF_RX2_PC_4 = (SPDIF_RX2<<16)|(2<<12)|(4<<4)|(8<<0),  
      SPDIF_RX2_PG_8 = (SPDIF_RX2<<16)|(6<<12)|(8<<4)|(7<<0),  
      SPDIF_RX3_PC_5 = (SPDIF_RX3<<16)|(2<<12)|(5<<4)|(8<<0),  
      SPDIF_RX3_PG_9 = (SPDIF_RX3<<16)|(6<<12)|(9<<4)|(7<<0),  
      SPI1_MISO_PA_6 = (SPI1_MISO<<16)|(0<<12)|(6<<4)|(5<<0),  
      SPI1_MISO_PB_4 = (SPI1_MISO<<16)|(1<<12)|(4<<4)|(5<<0),  
      SPI1_MISO_PG_9 = (SPI1_MISO<<16)|(6<<12)|(9<<4)|(5<<0),  
      SPI1_MOSI_PA_7 = (SPI1_MOSI<<16)|(0<<12)|(7<<4)|(5<<0),  
      SPI1_MOSI_PB_5 = (SPI1_MOSI<<16)|(1<<12)|(5<<4)|(5<<0),  
      SPI1_MOSI_PD_7 = (SPI1_MOSI<<16)|(3<<12)|(7<<4)|(5<<0),  
      SPI1_NSS_PA_15 = (SPI1_NSS<<16)|(0<<12)|(15<<4)|(4<<0),  
      SPI1_NSS_PA_4 = (SPI1_NSS<<16)|(0<<12)|(4<<4)|(5<<0),  
      SPI1_NSS_PG_10 = (SPI1_NSS<<16)|(6<<12)|(10<<4)|(5<<0),  
      SPI1_SCK_PA_5 = (SPI1_SCK<<16)|(0<<12)|(5<<4)|(5<<0),  
      SPI1_SCK_PB_3 = (SPI1_SCK<<16)|(1<<12)|(3<<4)|(5<<0),  
      SPI1_SCK_PG_11 = (SPI1_SCK<<16)|(6<<12)|(11<<4)|(5<<0),  
      SPI2_MISO_PC_2 = (SPI2_MISO<<16)|(2<<12)|(2<<4)|(5<<0),  
      SPI2_MISO_PI_2 = (SPI2_MISO<<16)|(8<<12)|(2<<4)|(5<<0),  
      SPI2_MOSI_PC_1 = (SPI2_MOSI<<16)|(2<<12)|(1<<4)|(5<<0),  
      SPI2_MOSI_PC_3 = (SPI2_MOSI<<16)|(2<<12)|(3<<4)|(5<<0),  
      SPI2_MOSI_PI_3 = (SPI2_MOSI<<16)|(8<<12)|(3<<4)|(5<<0),  
      SPI2_NSS_PA_11 = (SPI2_NSS<<16)|(0<<12)|(11<<4)|(5<<0),  
      SPI2_NSS_PB_4 = (SPI2_NSS<<16)|(1<<12)|(4<<4)|(7<<0),  
      SPI2_NSS_PI_0 = (SPI2_NSS<<16)|(8<<12)|(0<<4)|(5<<0),  
      SPI2_SCK_PA_9 = (SPI2_SCK<<16)|(0<<12)|(9<<4)|(5<<0),  
      SPI2_SCK_PA_12 = (SPI2_SCK<<16)|(0<<12)|(12<<4)|(5<<0),  
      SPI2_SCK_PD_3 = (SPI2_SCK<<16)|(3<<12)|(3<<4)|(5<<0),  
      SPI2_SCK_PI_1 = (SPI2_SCK<<16)|(8<<12)|(1<<4)|(5<<0),  
      SPI3_MISO_PB_4 = (SPI3_MISO<<16)|(1<<12)|(4<<4)|(6<<0),  
      SPI3_MISO_PC_11 = (SPI3_MISO<<16)|(2<<12)|(11<<4)|(6<<0),  
      SPI3_MOSI_PB_2 = (SPI3_MOSI<<16)|(1<<12)|(2<<4)|(7<<0),  
      SPI3_MOSI_PB_5 = (SPI3_MOSI<<16)|(1<<12)|(5<<4)|(6<<0),  
      SPI3_MOSI_PC_12 = (SPI3_MOSI<<16)|(2<<12)|(12<<4)|(6<<0),  
      SPI3_NSS_PA_4 = (SPI3_NSS<<16)|(0<<12)|(4<<4)|(6<<0),  
      SPI3_NSS_PA_15 = (SPI3_NSS<<16)|(0<<12)|(15<<4)|(6<<0),  
      SPI3_SCK_PB_3 = (SPI3_SCK<<16)|(1<<12)|(3<<4)|(6<<0),  
      SPI3_SCK_PC_10 = (SPI3_SCK<<16)|(2<<12)|(10<<4)|(6<<0),  
      SPI4_MISO_PE_5 = (SPI4_MISO<<16)|(4<<12)|(5<<4)|(5<<0),  
      SPI4_MISO_PE_13 = (SPI4_MISO<<16)|(4<<12)|(13<<4)|(5<<0),  
      SPI4_MOSI_PE_6 = (SPI4_MOSI<<16)|(4<<12)|(6<<4)|(5<<0),  
      SPI4_MOSI_PE_14 = (SPI4_MOSI<<16)|(4<<12)|(14<<4)|(5<<0),  
      SPI4_NSS_PE_4 = (SPI4_NSS<<16)|(4<<12)|(4<<4)|(5<<0),  
      SPI4_NSS_PE_11 = (SPI4_NSS<<16)|(4<<12)|(11<<4)|(5<<0),  
      SPI4_SCK_PE_2 = (SPI4_SCK<<16)|(4<<12)|(2<<4)|(5<<0),  
      SPI4_SCK_PE_12 = (SPI4_SCK<<16)|(4<<12)|(12<<4)|(5<<0),  
      SPI5_MISO_PF_8 = (SPI5_MISO<<16)|(5<<12)|(8<<4)|(5<<0),  
      SPI5_MISO_PH_7 = (SPI5_MISO<<16)|(7<<12)|(7<<4)|(5<<0),  
      SPI5_MOSI_PF_9 = (SPI5_MOSI<<16)|(5<<12)|(9<<4)|(5<<0),  
      SPI5_MOSI_PF_11 = (SPI5_MOSI<<16)|(5<<12)|(11<<4)|(5<<0),  
      SPI5_NSS_PF_6 = (SPI5_NSS<<16)|(5<<12)|(6<<4)|(5<<0),  
      SPI5_NSS_PH_5 = (SPI5_NSS<<16)|(7<<12)|(5<<4)|(5<<0),  
      SPI5_SCK_PF_7 = (SPI5_SCK<<16)|(5<<12)|(7<<4)|(5<<0),  
      SPI5_SCK_PH_6 = (SPI5_SCK<<16)|(7<<12)|(6<<4)|(5<<0),  
      SPI6_MISO_PA_6 = (SPI6_MISO<<16)|(0<<12)|(6<<4)|(8<<0),  
      SPI6_MISO_PB_4 = (SPI6_MISO<<16)|(1<<12)|(4<<4)|(8<<0),  
      SPI6_MISO_PG_12 = (SPI6_MISO<<16)|(6<<12)|(12<<4)|(5<<0),  
      SPI6_MOSI_PA_7 = (SPI6_MOSI<<16)|(0<<12)|(7<<4)|(8<<0),  
      SPI6_MOSI_PB_5 = (SPI6_MOSI<<16)|(1<<12)|(5<<4)|(8<<0),  
      SPI6_MOSI_PG_14 = (SPI6_MOSI<<16)|(6<<12)|(14<<4)|(5<<0),  
      SPI6_NSS_PA_4 = (SPI6_NSS<<16)|(0<<12)|(4<<4)|(8<<0),  
      SPI6_NSS_PA_15 = (SPI6_NSS<<16)|(0<<12)|(15<<4)|(7<<0),  
      SPI6_NSS_PG_8 = (SPI6_NSS<<16)|(6<<12)|(8<<4)|(5<<0),  
      SPI6_SCK_PA_5 = (SPI6_SCK<<16)|(0<<12)|(5<<4)|(8<<0),  
      SPI6_SCK_PB_3 = (SPI6_SCK<<16)|(1<<12)|(3<<4)|(8<<0),  
      SPI6_SCK_PG_13 = (SPI6_SCK<<16)|(6<<12)|(13<<4)|(5<<0),  
      TIM1_BKIN_PA_6 = (TIM1_BKIN<<16)|(0<<12)|(6<<4)|(1<<0),  
      TIM1_BKIN_PE_15 = (TIM1_BKIN<<16)|(4<<12)|(15<<4)|(1<<0),  
      TIM1_BKIN2_PE_6 = (TIM1_BKIN2<<16)|(4<<12)|(6<<4)|(1<<0),  
      TIM1_CH1_PA_8 = (TIM1_CH1<<16)|(0<<12)|(8<<4)|(1<<0),  
      TIM1_CH1_PE_9 = (TIM1_CH1<<16)|(4<<12)|(9<<4)|(1<<0),  
      TIM1_CH1N_PA_7 = (TIM1_CH1N<<16)|(0<<12)|(7<<4)|(1<<0),  
      TIM1_CH1N_PE_8 = (TIM1_CH1N<<16)|(4<<12)|(8<<4)|(1<<0),  
      TIM1_CH2_PA_9 = (TIM1_CH2<<16)|(0<<12)|(9<<4)|(1<<0),  
      TIM1_CH2_PE_11 = (TIM1_CH2<<16)|(4<<12)|(11<<4)|(1<<0),  
      TIM1_CH2N_PB_0 = (TIM1_CH2N<<16)|(1<<12)|(0<<4)|(1<<0),  
      TIM1_CH2N_PE_10 = (TIM1_CH2N<<16)|(4<<12)|(10<<4)|(1<<0),  
      TIM1_CH3_PA_10 = (TIM1_CH3<<16)|(0<<12)|(10<<4)|(1<<0),  
      TIM1_CH3_PE_13 = (TIM1_CH3<<16)|(4<<12)|(13<<4)|(1<<0),  
      TIM1_CH3N_PB_1 = (TIM1_CH3N<<16)|(1<<12)|(1<<4)|(1<<0),  
      TIM1_CH3N_PE_12 = (TIM1_CH3N<<16)|(4<<12)|(12<<4)|(1<<0),  
      TIM1_CH4_PA_11 = (TIM1_CH4<<16)|(0<<12)|(11<<4)|(1<<0),  
      TIM1_CH4_PE_14 = (TIM1_CH4<<16)|(4<<12)|(14<<4)|(1<<0),  
      TIM1_ETR_PA_12 = (TIM1_ETR<<16)|(0<<12)|(12<<4)|(1<<0),  
      TIM1_ETR_PE_7 = (TIM1_ETR<<16)|(4<<12)|(7<<4)|(1<<0),  
      TIM1_IN1_PD_12 = (TIM1_IN1<<16)|(3<<12)|(12<<4)|(3<<0),  
      TIM10_CH1_PF_6 = (TIM10_CH1<<16)|(5<<12)|(6<<4)|(3<<0),  
      TIM11_CH1_PF_7 = (TIM11_CH1<<16)|(5<<12)|(7<<4)|(3<<0),  
      TIM12_CH1_PH_6 = (TIM12_CH1<<16)|(7<<12)|(6<<4)|(9<<0),  
      TIM12_CH2_PH_9 = (TIM12_CH2<<16)|(7<<12)|(9<<4)|(9<<0),  
      TIM13_CH1_PA_6 = (TIM13_CH1<<16)|(0<<12)|(6<<4)|(9<<0),  
      TIM13_CH1_PF_8 = (TIM13_CH1<<16)|(5<<12)|(8<<4)|(9<<0),  
      TIM14_CH1_PA_7 = (TIM14_CH1<<16)|(0<<12)|(7<<4)|(9<<0),  
      TIM14_CH1_PF_9 = (TIM14_CH1<<16)|(5<<12)|(9<<4)|(9<<0),  
      TIM2_CH1_PA_0 = (TIM2_CH1<<16)|(0<<12)|(0<<4)|(1<<0),  
      TIM2_CH1_PA_5 = (TIM2_CH1<<16)|(0<<12)|(5<<4)|(1<<0),  
      TIM2_CH1_PA_15 = (TIM2_CH1<<16)|(0<<12)|(15<<4)|(1<<0),  
      TIM2_CH2_PA_1 = (TIM2_CH2<<16)|(0<<12)|(1<<4)|(1<<0),  
      TIM2_CH2_PB_3 = (TIM2_CH2<<16)|(1<<12)|(3<<4)|(1<<0),  
      TIM2_CH3_PA_2 = (TIM2_CH3<<16)|(0<<12)|(2<<4)|(1<<0),  
      TIM2_CH4_PA_3 = (TIM2_CH4<<16)|(0<<12)|(3<<4)|(1<<0),  
      TIM2_ETR_PA_0 = (TIM2_ETR<<16)|(0<<12)|(0<<4)|(1<<0),  
      TIM2_ETR_PA_5 = (TIM2_ETR<<16)|(0<<12)|(5<<4)|(1<<0),  
      TIM2_ETR_PA_15 = (TIM2_ETR<<16)|(0<<12)|(15<<4)|(1<<0),  
      TIM3_CH1_PA_6 = (TIM3_CH1<<16)|(0<<12)|(6<<4)|(2<<0),  
      TIM3_CH1_PB_4 = (TIM3_CH1<<16)|(1<<12)|(4<<4)|(2<<0),  
      TIM3_CH1_PC_6 = (TIM3_CH1<<16)|(2<<12)|(6<<4)|(2<<0),  
      TIM3_CH2_PA_7 = (TIM3_CH2<<16)|(0<<12)|(7<<4)|(2<<0),  
      TIM3_CH2_PB_5 = (TIM3_CH2<<16)|(1<<12)|(5<<4)|(2<<0),  
      TIM3_CH2_PC_7 = (TIM3_CH2<<16)|(2<<12)|(7<<4)|(2<<0),  
      TIM3_CH3_PB_0 = (TIM3_CH3<<16)|(1<<12)|(0<<4)|(2<<0),  
      TIM3_CH3_PC_8 = (TIM3_CH3<<16)|(2<<12)|(8<<4)|(2<<0),  
      TIM3_CH4_PB_1 = (TIM3_CH4<<16)|(1<<12)|(1<<4)|(2<<0),  
      TIM3_CH4_PC_9 = (TIM3_CH4<<16)|(2<<12)|(9<<4)|(2<<0),  
      TIM3_ETR_PD_2 = (TIM3_ETR<<16)|(3<<12)|(2<<4)|(2<<0),  
      TIM4_CH1_PB_6 = (TIM4_CH1<<16)|(1<<12)|(6<<4)|(2<<0),  
      TIM4_CH1LP_PD_12 = (TIM4_CH1LP<<16)|(3<<12)|(12<<4)|(2<<0),  
      TIM4_CH2_PD_13 = (TIM4_CH2<<16)|(3<<12)|(13<<4)|(2<<0),  
      TIM4_CH3_PD_14 = (TIM4_CH3<<16)|(3<<12)|(14<<4)|(2<<0),  
      TIM4_CH4_PD_15 = (TIM4_CH4<<16)|(3<<12)|(15<<4)|(2<<0),  
      TIM4_ETR_PE_0 = (TIM4_ETR<<16)|(4<<12)|(0<<4)|(2<<0),  
      TIM5_CH1_PA_0 = (TIM5_CH1<<16)|(0<<12)|(0<<4)|(2<<0),  
      TIM5_CH1_PH_10 = (TIM5_CH1<<16)|(7<<12)|(10<<4)|(2<<0),  
      TIM5_CH2_PA_1 = (TIM5_CH2<<16)|(0<<12)|(1<<4)|(2<<0),  
      TIM5_CH2_PH_11 = (TIM5_CH2<<16)|(7<<12)|(11<<4)|(2<<0),  
      TIM5_CH3_PA_2 = (TIM5_CH3<<16)|(0<<12)|(2<<4)|(2<<0),  
      TIM5_CH3_PH_12 = (TIM5_CH3<<16)|(7<<12)|(12<<4)|(2<<0),  
      TIM5_CH4_PA_3 = (TIM5_CH4<<16)|(0<<12)|(3<<4)|(2<<0),  
      TIM5_CH4_PI_0 = (TIM5_CH4<<16)|(8<<12)|(0<<4)|(2<<0),  
      TIM8_BKIN_PA_6 = (TIM8_BKIN<<16)|(0<<12)|(6<<4)|(3<<0),  
      TIM8_BKIN_PI_4 = (TIM8_BKIN<<16)|(8<<12)|(4<<4)|(3<<0),  
      TIM8_BKIN2_PA_8 = (TIM8_BKIN2<<16)|(0<<12)|(8<<4)|(3<<0),  
      TIM8_BKIN2_PI_1 = (TIM8_BKIN2<<16)|(8<<12)|(1<<4)|(3<<0),  
      TIM8_CH1_PC_6 = (TIM8_CH1<<16)|(2<<12)|(6<<4)|(3<<0),  
      TIM8_CH1_PI_5 = (TIM8_CH1<<16)|(8<<12)|(5<<4)|(3<<0),  
      TIM8_CH1N_PA_5 = (TIM8_CH1N<<16)|(0<<12)|(5<<4)|(3<<0),  
      TIM8_CH1N_PA_7 = (TIM8_CH1N<<16)|(0<<12)|(7<<4)|(3<<0),  
      TIM8_CH1N_PH_13 = (TIM8_CH1N<<16)|(7<<12)|(13<<4)|(3<<0),  
      TIM8_CH2_PC_7 = (TIM8_CH2<<16)|(2<<12)|(7<<4)|(3<<0),  
      TIM8_CH2_PI_6 = (TIM8_CH2<<16)|(8<<12)|(6<<4)|(3<<0),  
      TIM8_CH2N_PB_0 = (TIM8_CH2N<<16)|(1<<12)|(0<<4)|(3<<0),  
      TIM8_CH2N_PH_14 = (TIM8_CH2N<<16)|(7<<12)|(14<<4)|(3<<0),  
      TIM8_CH3_PC_8 = (TIM8_CH3<<16)|(2<<12)|(8<<4)|(3<<0),  
      TIM8_CH3_PI_7 = (TIM8_CH3<<16)|(8<<12)|(7<<4)|(3<<0),  
      TIM8_CH3N_PB_1 = (TIM8_CH3N<<16)|(1<<12)|(1<<4)|(3<<0),  
      TIM8_CH3N_PH_15 = (TIM8_CH3N<<16)|(7<<12)|(15<<4)|(3<<0),  
      TIM8_CH4_PC_9 = (TIM8_CH4<<16)|(2<<12)|(9<<4)|(3<<0),  
      TIM8_CH4_PI_2 = (TIM8_CH4<<16)|(8<<12)|(2<<4)|(3<<0),  
      TIM8_ETR_PA_0 = (TIM8_ETR<<16)|(0<<12)|(0<<4)|(3<<0),  
      TIM8_ETR_PI_3 = (TIM8_ETR<<16)|(8<<12)|(3<<4)|(3<<0),  
      TIM9_CH1_PA_2 = (TIM9_CH1<<16)|(0<<12)|(2<<4)|(3<<0),  
      TIM9_CH1_PE_5 = (TIM9_CH1<<16)|(4<<12)|(5<<4)|(3<<0),  
      TIM9_CH2_PA_3 = (TIM9_CH2<<16)|(0<<12)|(3<<4)|(3<<0),  
      TIM9_CH2_PE_6 = (TIM9_CH2<<16)|(4<<12)|(6<<4)|(3<<0),  
      TRACECLK_PE_2 = (TRACECLK<<16)|(4<<12)|(2<<4)|(0<<0),  
      TRACED0_PC_1 = (TRACED0<<16)|(2<<12)|(1<<4)|(0<<0),  
      TRACED0_PE_3 = (TRACED0<<16)|(4<<12)|(3<<4)|(0<<0),  
      TRACED0_PG_13 = (TRACED0<<16)|(6<<12)|(13<<4)|(0<<0),  
      TRACED1_PC_8 = (TRACED1<<16)|(2<<12)|(8<<4)|(0<<0),  
      TRACED1_PE_4 = (TRACED1<<16)|(4<<12)|(4<<4)|(0<<0),  
      TRACED1_PG_14 = (TRACED1<<16)|(6<<12)|(14<<4)|(0<<0),  
      TRACED2_PD_2 = (TRACED2<<16)|(3<<12)|(2<<4)|(0<<0),  
      TRACED2_PE_5 = (TRACED2<<16)|(4<<12)|(5<<4)|(0<<0),  
      TRACED3_PC_12 = (TRACED3<<16)|(2<<12)|(12<<4)|(0<<0),  
      TRACED3_PE_6 = (TRACED3<<16)|(4<<12)|(6<<4)|(0<<0),  
      TRACESWO_PB_3 = (TRACESWO<<16)|(1<<12)|(3<<4)|(0<<0),  
      UART4_CTS_PB_0 = (UART4_CTS<<16)|(1<<12)|(0<<4)|(8<<0),  
      UART4_RTS_PA_15 = (UART4_RTS<<16)|(0<<12)|(15<<4)|(8<<0),  
      UART4_RX_PA_1 = (UART4_RX<<16)|(0<<12)|(1<<4)|(8<<0),  
      UART4_RX_PA_11 = (UART4_RX<<16)|(0<<12)|(11<<4)|(6<<0),  
      UART4_RX_PC_11 = (UART4_RX<<16)|(2<<12)|(11<<4)|(8<<0),  
      UART4_RX_PD_0 = (UART4_RX<<16)|(3<<12)|(0<<4)|(8<<0),  
      UART4_RX_PH_14 = (UART4_RX<<16)|(7<<12)|(14<<4)|(8<<0),  
      UART4_RX_PI_9 = (UART4_RX<<16)|(8<<12)|(9<<4)|(8<<0),  
      UART4_TX_PA_0 = (UART4_TX<<16)|(0<<12)|(0<<4)|(8<<0),  
      UART4_TX_PA_12 = (UART4_TX<<16)|(0<<12)|(12<<4)|(6<<0),  
      UART4_TX_PC_10 = (UART4_TX<<16)|(2<<12)|(10<<4)|(8<<0),  
      UART4_TX_PD_1 = (UART4_TX<<16)|(3<<12)|(1<<4)|(8<<0),  
      UART4_TX_PH_13 = (UART4_TX<<16)|(7<<12)|(13<<4)|(8<<0),  
      UART5_CTS_PC_9 = (UART5_CTS<<16)|(2<<12)|(9<<4)|(7<<0),  
      UART5_RTS_PC_8 = (UART5_RTS<<16)|(2<<12)|(8<<4)|(7<<0),  
      UART5_RX_PB_5 = (UART5_RX<<16)|(1<<12)|(5<<4)|(1<<0),  
      UART5_RX_PD_2 = (UART5_RX<<16)|(3<<12)|(2<<4)|(8<<0),  
      UART5_TX_PB_6 = (UART5_TX<<16)|(1<<12)|(6<<4)|(1<<0),  
      UART5_TX_PC_12 = (UART5_TX<<16)|(2<<12)|(12<<4)|(8<<0),  
      UART7_CTS_PE_10 = (UART7_CTS<<16)|(4<<12)|(10<<4)|(8<<0),  
      UART7_CTS_PF_9 = (UART7_CTS<<16)|(5<<12)|(9<<4)|(8<<0),  
      UART7_RTS_PE_9 = (UART7_RTS<<16)|(4<<12)|(9<<4)|(8<<0),  
      UART7_RTS_PF_8 = (UART7_RTS<<16)|(5<<12)|(8<<4)|(8<<0),  
      UART7_RX_PA_8 = (UART7_RX<<16)|(0<<12)|(8<<4)|(12<<0),  
      UART7_RX_PB_3 = (UART7_RX<<16)|(1<<12)|(3<<4)|(12<<0),  
      UART7_RX_PE_7 = (UART7_RX<<16)|(4<<12)|(7<<4)|(8<<0),  
      UART7_RX_PF_6 = (UART7_RX<<16)|(5<<12)|(6<<4)|(8<<0),  
      UART7_TX_PA_15 = (UART7_TX<<16)|(0<<12)|(15<<4)|(12<<0),  
      UART7_TX_PB_4 = (UART7_TX<<16)|(1<<12)|(4<<4)|(12<<0),  
      UART7_TX_PE_8 = (UART7_TX<<16)|(4<<12)|(8<<4)|(8<<0),  
      UART7_TX_PF_7 = (UART7_TX<<16)|(5<<12)|(7<<4)|(8<<0),  
      UART8_CTS_PD_14 = (UART8_CTS<<16)|(3<<12)|(14<<4)|(8<<0),  
      UART8_RTS_PD_15 = (UART8_RTS<<16)|(3<<12)|(15<<4)|(8<<0),  
      UART8_Rx_PE_0 = (UART8_Rx<<16)|(4<<12)|(0<<4)|(8<<0),  
      UART8_Tx_PE_1 = (UART8_Tx<<16)|(4<<12)|(1<<4)|(8<<0),  
      USART1_CK_PA_8 = (USART1_CK<<16)|(0<<12)|(8<<4)|(7<<0),  
      USART1_CTS_PA_11 = (USART1_CTS<<16)|(0<<12)|(11<<4)|(7<<0),  
      USART1_RTS_PA_12 = (USART1_RTS<<16)|(0<<12)|(12<<4)|(7<<0),  
      USART1_RX_PA_10 = (USART1_RX<<16)|(0<<12)|(10<<4)|(7<<0),  
      USART1_TX_PA_9 = (USART1_TX<<16)|(0<<12)|(9<<4)|(7<<0),  
      USART1_TX_PB_6 = (USART1_TX<<16)|(1<<12)|(6<<4)|(7<<0),  
      USART2_CK_PA_4 = (USART2_CK<<16)|(0<<12)|(4<<4)|(7<<0),  
      USART2_CK_PD_7 = (USART2_CK<<16)|(3<<12)|(7<<4)|(7<<0),  
      USART2_CTS_PA_0 = (USART2_CTS<<16)|(0<<12)|(0<<4)|(7<<0),  
      USART2_CTS_PD_3 = (USART2_CTS<<16)|(3<<12)|(3<<4)|(7<<0),  
      USART2_RTS_PA_1 = (USART2_RTS<<16)|(0<<12)|(1<<4)|(7<<0),  
      USART2_RTS_PD_4 = (USART2_RTS<<16)|(3<<12)|(4<<4)|(7<<0),  
      USART2_RX_PA_3 = (USART2_RX<<16)|(0<<12)|(3<<4)|(7<<0),  
      USART2_RX_PD_6 = (USART2_RX<<16)|(3<<12)|(6<<4)|(7<<0),  
      USART2_TX_PA_2 = (USART2_TX<<16)|(0<<12)|(2<<4)|(7<<0),  
      USART2_TX_PD_5 = (USART2_TX<<16)|(3<<12)|(5<<4)|(7<<0),  
      USART3_CK_PC_12 = (USART3_CK<<16)|(2<<12)|(12<<4)|(7<<0),  
      USART3_CK_PD_10 = (USART3_CK<<16)|(3<<12)|(10<<4)|(7<<0),  
      USART3_CTS_PD_11 = (USART3_CTS<<16)|(3<<12)|(11<<4)|(7<<0),  
      USART3_RTS_PD_12 = (USART3_RTS<<16)|(3<<12)|(12<<4)|(7<<0),  
      USART3_RX_PC_11 = (USART3_RX<<16)|(2<<12)|(11<<4)|(7<<0),  
      USART3_RX_PD_9 = (USART3_RX<<16)|(3<<12)|(9<<4)|(7<<0),  
      USART3_TX_PC_10 = (USART3_TX<<16)|(2<<12)|(10<<4)|(7<<0),  
      USART3_TX_PD_8 = (USART3_TX<<16)|(3<<12)|(8<<4)|(7<<0),  
      USART6_CK_PC_8 = (USART6_CK<<16)|(2<<12)|(8<<4)|(8<<0),  
      USART6_CK_PG_7 = (USART6_CK<<16)|(6<<12)|(7<<4)|(8<<0),  
      USART6_CTS_PG_13 = (USART6_CTS<<16)|(6<<12)|(13<<4)|(8<<0),  
      USART6_CTS_PG_15 = (USART6_CTS<<16)|(6<<12)|(15<<4)|(8<<0),  
      USART6_RTS_PG_8 = (USART6_RTS<<16)|(6<<12)|(8<<4)|(8<<0),  
      USART6_RTS_PG_12 = (USART6_RTS<<16)|(6<<12)|(12<<4)|(8<<0),  
      USART6_RX_PC_7 = (USART6_RX<<16)|(2<<12)|(7<<4)|(8<<0),  
      USART6_RX_PG_9 = (USART6_RX<<16)|(6<<12)|(9<<4)|(8<<0),  
      USART6_TX_PC_6 = (USART6_TX<<16)|(2<<12)|(6<<4)|(8<<0),  
      USART6_TX_PG_14 = (USART6_TX<<16)|(6<<12)|(14<<4)|(8<<0),  
      END_OF_TABLE     = 0
    } MAP;

  public:
    
    









 
    static void set( GPIO_TypeDef *gpio, 
                     BYTE          pinId, 
                     DWORD         mode, 
                     BYTE          af = 0 );

    
    














 
    static bool set( Function func,
                     DWORD    mode = 0 );

  public:
    
    


 
    static MAP table[];

}; 

#line 67 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\MCU.h"
#line 1 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/RTOS_MCU.h"







 























 
class cHwRTOS_MCU
{
  private:
    
    typedef struct
    {
      struct
      {
        float s[32];
      } fpu;

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

      ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->CTRL =   (1UL )
                      | (1UL << 1U)
                      | (1UL << 2U);

      ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->LOAD = (1E-6 * ((200000000)) * us) - 1;

			sysTicTime = us;
    }

    
    










 
    static unsigned start( char     *stackAddrIn,
                           unsigned  stackSizeIn,
                           void     *arg,
                           DWORD   (*startFunc)(void *) )
    {
      void *stackAddr = (void*)( ( (unsigned)stackAddrIn+3) & ~0x03 ); 
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

      stack->add.r4    = 0;
      stack->add.lr_pc = 0xFFFFFFF9;

      for( int i = 0; i < 32; i++ )
      {
        stack->fpu.s[i] = 0;
      }

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

#line 68 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\MCU.h"


#line 1 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Src/ADC_MCU.h"







 






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

#line 16 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Src/ADC_MCU.h"








 
class cHwADC_0 : public cHwADC
{
  public:
      typedef enum
      {
          SAMPLING_TIME_3 = 0,
          SAMPLING_TIME_15,
          SAMPLING_TIME_28,
          SAMPLING_TIME_56,
          SAMPLING_TIME_84,
          SAMPLING_TIME_112,
          SAMPLING_TIME_144,
          SAMPLING_TIME_480
      } Para;

  public:
    
    




 
    cHwADC_0( cHwTimer *tPtr = 0 );

  private:
    
    virtual WORD getResult( void );

    
    virtual void startCh( BYTE ch );

    
    virtual void configCh( BYTE ch, BYTE para = 0 );

  public:
    
    static cHwADC *adcPtr;
    
}; 

#line 71 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\MCU.h"
#line 1 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Src/DAC_MCU.h"







 






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

#line 16 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Src/DAC_MCU.h"








 
class cHwDAC_0 : public cHwDAC
{
  public:
    
    
 
    cHwDAC_0( void );

    
    virtual void set( WORD value, 
                      BYTE ch = 0 );

    
    virtual void enable( BYTE ch = 0 );

}; 

#line 72 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\MCU.h"
#line 1 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Src/DSI.h"





 






#line 1 ".\\..\\EmbSysLib\\Src\\lib.h"









 


#line 14 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Src/DSI.h"
#line 1 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Src/LTDC.h"





 














 
class cHwLTDC
{
  public:
		
		cHwLTDC( uint32_t startAddrIn )   
		{
      startAddr = startAddrIn;
      
			((RCC_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3800U))->APB2ENR  |=  (0x1U << (26U));   
			((RCC_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3800U))->APB2RSTR |=  (0x1U << (26U)); 
			((RCC_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3800U))->APB2RSTR &= ~(0x1U << (26U));
		}
  
		
		void Init( WORD Hsize, WORD Vsize )
		{
      DWORD h = 0;
      DWORD v = 0;
      
			
			((LTDC_TypeDef *)((0x40000000U + 0x00010000U) + 0x6800U))->GCR = (!(0x1U << (31U))   
									|!(0x1U << (30U))   
									|!(0x1U << (29U))   
                  |!(0x1U << (28U)) );

			
      h += 1; 
      v += 1; 
			((LTDC_TypeDef *)((0x40000000U + 0x00010000U) + 0x6800U))->SSCR = ((h << 16)  
                   |(v <<  0));

			
      h += 1; 
      v += 1; 
			((LTDC_TypeDef *)((0x40000000U + 0x00010000U) + 0x6800U))->BPCR = ((h << 16)  
                   |(v <<  0));

			
      h += Hsize;
      v += Vsize;      
			((LTDC_TypeDef *)((0x40000000U + 0x00010000U) + 0x6800U))->AWCR = ((h << 16)  
                   |(v <<  0));

			
      h += 1; 
      v += 1; 
			((LTDC_TypeDef *)((0x40000000U + 0x00010000U) + 0x6800U))->TWCR = ((h << 16)  
                   |(v <<  0));

			
			((LTDC_TypeDef *)((0x40000000U + 0x00010000U) + 0x6800U))->BCCR = ( (0x00 << 16)    
                   | (0x00 <<  8)    
                   | (0x00 <<  0) ); 

      
      ((LTDC_TypeDef *)((0x40000000U + 0x00010000U) + 0x6800U))->IER = 0; 

			
			((LTDC_TypeDef *)((0x40000000U + 0x00010000U) + 0x6800U))->GCR |= (0x1U << (0U)); 
		}
  
    
    uint32_t LayerConfig( uint32_t width, uint32_t height, uint8_t layerID = 0 )
		{
      LTDC_Layer_TypeDef *layer = (layerID) ? ((LTDC_Layer_TypeDef *)(((0x40000000U + 0x00010000U) + 0x6800U) + 0x104U)) : ((LTDC_Layer_TypeDef *)(((0x40000000U + 0x00010000U) + 0x6800U) + 0x84U)); 
     
      uint32_t hbp  = (((LTDC_TypeDef *)((0x40000000U + 0x00010000U) + 0x6800U))->BPCR & (0xFFFU << (16U))) >> 16; 
      uint32_t vbp  = (((LTDC_TypeDef *)((0x40000000U + 0x00010000U) + 0x6800U))->BPCR & (0x7FFU << (0U))) >> 0;  
      uint32_t bpp  = 2; 
            
      
      layer->WHPCR = ( ((width       + hbp) << 16)    
                     | ((0  + 1 + hbp) <<  0) ); 

      
      layer->WVPCR = ( ((height      + vbp) << 16)    
                     | ((0  + 1 + vbp) <<  0) ); 

      
      layer->PFCR = 0x02; 

      
      layer->DCCR = ( (0x00 << 24)    
                    | (0x00 << 16)    
                    | (0x00 <<  8)    
                    | (0x00 <<  0) ); 

      
      layer->CACR = (0xFF); 

      
      layer->BFCR = ( (0x06 << 8)   
                    | (0x07 << 0) );

      
      layer->CFBAR = startAddr;

      
      
      layer->CFBLR  = ( ((((width          )*bpp)  ) << 16)   
                      | ((((width - 0 )*bpp)+3) <<  0) );

      
      layer->CFBLNR = height; 

      
      layer->CR |= (0x1U << (0U)); 

      
			((LTDC_TypeDef *)((0x40000000U + 0x00010000U) + 0x6800U))->SRCR = (0x1U << (0U)); 

      return( startAddr );
		}
    
  private:
    
    uint32_t startAddr;

};

#line 15 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Src/DSI.h"
#line 1 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Src/FMC.h"







 














 
class cHwFMC
{

  
  public:
    typedef enum
    {
      NOR         = 0x00,
      NAND        = 0x01,
      SDRAM       = 0x02,
      SDRAM_Bank1 = (0<<4) | SDRAM,
      SDRAM_Bank2 = (1<<4) | SDRAM

    } FMCtype;

  public:
    
    

 
    cHwFMC( FMCtype typeIn, bool bothIn = false )
    {
      type = typeIn&0x0F;
      bank = (typeIn>>4)&0x0F;
      both = bothIn;

      WORD mode =  cHwPinConfig::FAST_SPEED
                 | cHwPinConfig::PUSH_PULL
                 | cHwPinConfig::PULL_UP 
                 | cHwPinConfig::NO_PUPD;

      cHwPinConfig::set(cHwPinConfig::FMC_D0,mode);
      cHwPinConfig::set(cHwPinConfig::FMC_D1,mode);
      cHwPinConfig::set(cHwPinConfig::FMC_D2,mode);
      cHwPinConfig::set(cHwPinConfig::FMC_D3,mode);
      cHwPinConfig::set(cHwPinConfig::FMC_D4,mode);
      cHwPinConfig::set(cHwPinConfig::FMC_D5,mode);
      cHwPinConfig::set(cHwPinConfig::FMC_D6,mode);
      cHwPinConfig::set(cHwPinConfig::FMC_D7,mode);
      cHwPinConfig::set(cHwPinConfig::FMC_D8,mode);
      cHwPinConfig::set(cHwPinConfig::FMC_D9,mode);
      cHwPinConfig::set(cHwPinConfig::FMC_D10,mode);
      cHwPinConfig::set(cHwPinConfig::FMC_D11,mode);
      cHwPinConfig::set(cHwPinConfig::FMC_D12,mode);
      cHwPinConfig::set(cHwPinConfig::FMC_D13,mode);
      cHwPinConfig::set(cHwPinConfig::FMC_D14,mode);
      cHwPinConfig::set(cHwPinConfig::FMC_D15,mode);
      cHwPinConfig::set(cHwPinConfig::FMC_D16,mode);
      cHwPinConfig::set(cHwPinConfig::FMC_D17,mode);
      cHwPinConfig::set(cHwPinConfig::FMC_D18,mode);
      cHwPinConfig::set(cHwPinConfig::FMC_D19,mode);
      cHwPinConfig::set(cHwPinConfig::FMC_D20,mode);
      cHwPinConfig::set(cHwPinConfig::FMC_D21,mode);
      cHwPinConfig::set(cHwPinConfig::FMC_D22,mode);
      cHwPinConfig::set(cHwPinConfig::FMC_D23,mode);
      cHwPinConfig::set(cHwPinConfig::FMC_D24,mode);
      cHwPinConfig::set(cHwPinConfig::FMC_D25,mode);
      cHwPinConfig::set(cHwPinConfig::FMC_D26,mode);
      cHwPinConfig::set(cHwPinConfig::FMC_D27,mode);
      cHwPinConfig::set(cHwPinConfig::FMC_D28,mode);
      cHwPinConfig::set(cHwPinConfig::FMC_D29,mode);
      cHwPinConfig::set(cHwPinConfig::FMC_D30,mode);
      cHwPinConfig::set(cHwPinConfig::FMC_D31,mode);

      cHwPinConfig::set(cHwPinConfig::FMC_NBL0,mode);
      cHwPinConfig::set(cHwPinConfig::FMC_NBL1,mode);

      cHwPinConfig::set(cHwPinConfig::FMC_A0,mode);
      cHwPinConfig::set(cHwPinConfig::FMC_A1,mode);
      cHwPinConfig::set(cHwPinConfig::FMC_A2,mode);
      cHwPinConfig::set(cHwPinConfig::FMC_A3,mode);
      cHwPinConfig::set(cHwPinConfig::FMC_A4,mode);
      cHwPinConfig::set(cHwPinConfig::FMC_A5,mode);
      cHwPinConfig::set(cHwPinConfig::FMC_A6,mode);
      cHwPinConfig::set(cHwPinConfig::FMC_A7,mode);
      cHwPinConfig::set(cHwPinConfig::FMC_A8,mode);
      cHwPinConfig::set(cHwPinConfig::FMC_A9,mode);
      cHwPinConfig::set(cHwPinConfig::FMC_A10,mode);
      cHwPinConfig::set(cHwPinConfig::FMC_A11,mode);
      cHwPinConfig::set(cHwPinConfig::FMC_A12,mode);
      cHwPinConfig::set(cHwPinConfig::FMC_A13,mode);
      cHwPinConfig::set(cHwPinConfig::FMC_A14,mode);
      cHwPinConfig::set(cHwPinConfig::FMC_A15,mode);

      cHwPinConfig::set(cHwPinConfig::FMC_SDCLK,mode);
      cHwPinConfig::set(cHwPinConfig::FMC_SDNCAS,mode);

      cHwPinConfig::set(cHwPinConfig::FMC_SDNRAS,mode);

      cHwPinConfig::set(cHwPinConfig::FMC_SDCKE0,mode);
      cHwPinConfig::set(cHwPinConfig::FMC_SDNE0,mode);
      cHwPinConfig::set(cHwPinConfig::FMC_SDNWE,mode);
      cHwPinConfig::set(cHwPinConfig::FMC_NBL2,mode);
      cHwPinConfig::set(cHwPinConfig::FMC_NBL3,mode);

       
      ((RCC_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3800U))->AHB3ENR |= (0x1U << (0U));

      if( type == SDRAM )
      {
        SDRAM_Init( );
      }
    }
    
    
    uint32_t startAddr( void )
    {
      if( bank == 0 )
        return( 0xC0000000 );
      else
        return( 0xD0000000 );
    }
    
  private:
    
    void SDRAM_Init(  )
    {
      uint32_t reg  = 0;

      
      
      
      
      
      reg  = ((FMC_Bank5_6_TypeDef *) (0xA0000000U + 0x0140U))->SDCR[0 ];
      reg &= ~( (0x3U << (10U))
              | (0x1U << (12U))
              | (0x3U << (13U)) );
      reg |=  (  (2<<10)          
              |  (0x1U << (12U)) 
              |  (0<<13) );       
      ((FMC_Bank5_6_TypeDef *) (0xA0000000U + 0x0140U))->SDCR[0 ] = reg;

      
      reg  = ((FMC_Bank5_6_TypeDef *) (0xA0000000U + 0x0140U))->SDTR[0 ];
      reg &= ~( (0xFU << (12U))
              | (0xFU << (20U)) );
      reg |=  ( ((7 - 1) << 12)    
              | ((2 - 1) << 20) ); 
      ((FMC_Bank5_6_TypeDef *) (0xA0000000U + 0x0140U))->SDTR[0 ] = reg;

      
      
      
      reg  = ((FMC_Bank5_6_TypeDef *) (0xA0000000U + 0x0140U))->SDCR[bank];
      reg &= ~( (0x3U << (0U))
              | (0x3U << (2U))
              | (0x3U << (4U))
              | (0x1U << (6U))
              | (0x3U << (7U))
              | (0x1U << (9U)) );
      reg |=  ( (0 <<  0)       
              | (1 <<  2)       
              | (2 <<  4)       
              | (1 <<  6)       
              | (3 <<  7)       
              |!(0x1U << (9U)) ); 
      ((FMC_Bank5_6_TypeDef *) (0xA0000000U + 0x0140U))->SDCR[bank] = reg;

      
      reg  = ((FMC_Bank5_6_TypeDef *) (0xA0000000U + 0x0140U))->SDTR[bank];
      reg &= ~( (0xFU << (0U))
              | (0xFU << (4U))
              | (0xFU << (8U))
              | (0xFU << (16U))
              | (0xFU << (24U)) );
      reg |=  ( ((2 - 1) <<  0)   
              | ((7 - 1) <<  4)   
              | ((4 - 1) <<  8)   
              | ((2 - 1) << 16)   
              | ((2 - 1) << 24)); 
      ((FMC_Bank5_6_TypeDef *) (0xA0000000U + 0x0140U))->SDTR[bank] = reg;


      
      

      
      SendCommand( 0x01 , 1, 0 );

      
      cSystem::delayMilliSec(1);

      
      SendCommand( 0x02 , 1, 0 );

      
      SendCommand( 0x03 , 8, 0 );

      
      
      reg = ( (0<<0)   
            | (0<<3)   
            | (3<<4)   
            | (0<<7)   
            | (1<<9) );
      SendCommand(0x04 , 1, reg);

      
      
      
      
      
      
      
      
      ((FMC_Bank5_6_TypeDef *) (0xA0000000U + 0x0140U))->SDRTR |= (1583 << 1);
    }

  private:
    
    void SendCommand( uint32_t Command,       
                      uint32_t AutoRefresh,   
                                              
                      uint32_t ModeRegister ) 
    {
      uint32_t ctb;

      
      
      
      
      if( both && (   Command == 0x02    
                   || Command == 0x03 )) 
        ctb = 3; 
      else if( bank == 0)
        ctb = 1<<1; 
      else
        ctb = 1<<0; 

      ((FMC_Bank5_6_TypeDef *) (0xA0000000U + 0x0140U))->SDCMR = ( (Command         << 0)
                           | (ctb             << 3)
                           | ((AutoRefresh-1) << 5)
                           | (ModeRegister    << 9) );
      
      while( ((FMC_Bank5_6_TypeDef *) (0xA0000000U + 0x0140U))->SDSR & (0x1U << (5U)) ); 
    }

  private:
    
    uint8_t type;
    uint8_t bank;
    bool    both;

}; 

#line 16 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Src/DSI.h"










 
class cHwDSI
{
  public:
    
    cHwDSI( uint32_t startAddr )
    : hwLTDC( startAddr )
    {
			
			((RCC_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3800U))->APB2ENR  |=  (0x1U << (27U));
			((RCC_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3800U))->APB2RSTR |=  (0x1U << (27U));
			((RCC_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3800U))->APB2RSTR &= ~(0x1U << (27U));
		}
    
		
		void Init( WORD Hsize, WORD Vsize, bool useLTDC )
		{
			((DSI_TypeDef *)((0x40000000U + 0x00010000U) + 0x6C00U))->WCR   &= ~(0x1U << (3U));   
			((DSI_TypeDef *)((0x40000000U + 0x00010000U) + 0x6C00U))->CR    &= ~(0x1U << (0U));       
			((DSI_TypeDef *)((0x40000000U + 0x00010000U) + 0x6C00U))->PCTLR &= ~(0x1U << (2U));   
			((DSI_TypeDef *)((0x40000000U + 0x00010000U) + 0x6C00U))->PCTLR &= ~(0x1U << (1U));   
			((DSI_TypeDef *)((0x40000000U + 0x00010000U) + 0x6C00U))->WRPCR &= ~(0x1U << (0U)); 
			((DSI_TypeDef *)((0x40000000U + 0x00010000U) + 0x6C00U))->WRPCR &= ~(0x1U << (24U)); 
		       
			
			
			((DSI_TypeDef *)((0x40000000U + 0x00010000U) + 0x6C00U))->WRPCR |= (0x1U << (24U)); 

			
			while( !(((DSI_TypeDef *)((0x40000000U + 0x00010000U) + 0x6C00U))->WISR & (0x1U << (12U))) ); 
					
			
			
			
			
			
      
			
			
			
			
			

   	  double F_PHI = 500E6;  
			
			((DSI_TypeDef *)((0x40000000U + 0x00010000U) + 0x6C00U))->WRPCR &= ~( (0x7FU << (2U)) 
										 | (0xFU << (11U)) 
										 | (0x3U << (16U)) );
			((DSI_TypeDef *)((0x40000000U + 0x00010000U) + 0x6C00U))->WRPCR |=  ( (100 <<  2)   
										 | (5   << 11)   
										 | (0   << 16)); 
				
			((DSI_TypeDef *)((0x40000000U + 0x00010000U) + 0x6C00U))->WRPCR |= (0x1U << (0U)); 
				
			
			while( !(((DSI_TypeDef *)((0x40000000U + 0x00010000U) + 0x6C00U))->WISR & (0x1U << (8U))) ); 
					
      
			
			
			((DSI_TypeDef *)((0x40000000U + 0x00010000U) + 0x6C00U))->PCTLR  = ( (0x1U << (2U))    
										| (0x1U << (1U)) ); 
          
			
			((DSI_TypeDef *)((0x40000000U + 0x00010000U) + 0x6C00U))->CLCR  =  ( (0x1U << (0U))    
			              |!(0x1U << (1U)) );  
				
		  
			((DSI_TypeDef *)((0x40000000U + 0x00010000U) + 0x6C00U))->PCONFR  =  ( (10 <<8 )      
			                | 0x01 );        
											
			
			
			
      ((DSI_TypeDef *)((0x40000000U + 0x00010000U) + 0x6C00U))->CCR  =  ( (0 << 8)          
			             | (4 << 0) );       
          
			
      ((DSI_TypeDef *)((0x40000000U + 0x00010000U) + 0x6C00U))->WPCR[0] = (WORD)(1.0/(0.25E-9*F_PHI)); 
        
   		
			((DSI_TypeDef *)((0x40000000U + 0x00010000U) + 0x6C00U))->IER[0] = 0;
			((DSI_TypeDef *)((0x40000000U + 0x00010000U) + 0x6C00U))->IER[1] = 0;
 
			
      ((DSI_TypeDef *)((0x40000000U + 0x00010000U) + 0x6C00U))->MCR = (0x1U << (0U)); 
			
			
			((DSI_TypeDef *)((0x40000000U + 0x00010000U) + 0x6C00U))->WCFGR  = ( (0x1U << (0U))    
										| !(0x1U << (4U))  
										| !(0x1U << (5U))  
										| !(0x1U << (6U))     
										| !(0x1U << (7U))  
										| (0x05<<1) );      
										 
			
			((DSI_TypeDef *)((0x40000000U + 0x00010000U) + 0x6C00U))->LVCIDR = 0;                
  
			
			((DSI_TypeDef *)((0x40000000U + 0x00010000U) + 0x6C00U))->LPCR  =  (!(0x1U << (0U))    
			              |!(0x1U << (1U))    
                    |!(0x1U << (2U)) ); 
  
			
			((DSI_TypeDef *)((0x40000000U + 0x00010000U) + 0x6C00U))->LCOLCR = ( !(0x1U << (8U))  
										| 0x05      		 );
  
			
			((DSI_TypeDef *)((0x40000000U + 0x00010000U) + 0x6C00U))->LCCR = Hsize; 
   
  		
			
			
			((DSI_TypeDef *)((0x40000000U + 0x00010000U) + 0x6C00U))->CMCR = ( (0x1U << (8U))
									| (0x1U << (9U)) 
			            |	(0x1U << (10U)) 
									| (0x1U << (11U))   
									| (0x1U << (12U))  
									| (0x1U << (13U))  
									| (0x1U << (14U))      
									| (0x1U << (14U))  
									| (0x1U << (17U)) 
									| (0x1U << (18U))   
									| (0x1U << (19U))      
									| 0   
									| 0); 
	    
			if( useLTDC )
			{
				hwLTDC.Init( Hsize, Vsize );
			}
			      
			
			((DSI_TypeDef *)((0x40000000U + 0x00010000U) + 0x6C00U))->CR  |= (0x1U << (0U));
			((DSI_TypeDef *)((0x40000000U + 0x00010000U) + 0x6C00U))->WCR |= (0x1U << (3U));
			
			
			
			
			
      
			
      
			((DSI_TypeDef *)((0x40000000U + 0x00010000U) + 0x6C00U))->CLTCR = ( (35 <<  0)    
 			             | (35 << 16) ); 
  
			
			((DSI_TypeDef *)((0x40000000U + 0x00010000U) + 0x6C00U))->DLTCR = ( ( 0 <<  0 )   
									 | (35 << 16 )   
									 | (35 << 24 ) );
  
		} 
  
    
	  uint32_t startLTDC( WORD Hsize, WORD Vsize )
	  {
			
			
			
			((DSI_TypeDef *)((0x40000000U + 0x00010000U) + 0x6C00U))->CMCR = (!(0x1U << (8U))
			            |!(0x1U << (9U)) 
									|!(0x1U << (10U)) 
									|!(0x1U << (11U))   
									|!(0x1U << (12U))  
									|!(0x1U << (13U))  
									|!(0x1U << (14U)) 
									|!(0x1U << (14U))  
									|!(0x1U << (17U)) 
									|!(0x1U << (18U))   
									|!(0x1U << (19U)) 
									| 0   
									| 0); 
		
			
			((DSI_TypeDef *)((0x40000000U + 0x00010000U) + 0x6C00U))->PCR =  (!(0x1U << (4U))
									|!(0x1U << (3U))
									| (0x1U << (2U))
									|!(0x1U << (1U))
									|!(0x1U << (0U)) );
			
			DisplayRefresh();
			
			return( hwLTDC.LayerConfig(Hsize, Vsize) );
		}
	
    
		virtual void writeShort( uint8_t para0, uint8_t para1 )
		{
			
			while( !(((DSI_TypeDef *)((0x40000000U + 0x00010000U) + 0x6C00U))->GPSR & (0x1U << (0U))) ); 
			
			
			((DSI_TypeDef *)((0x40000000U + 0x00010000U) + 0x6C00U))->GHCR = ( 0x15                      
			            | (              0 <<  6)   
			            | ((uint32_t)para0 <<  8)   
			            | ((uint32_t)para1 << 16) );
		}
	
    
		virtual void writeLong( uint8_t*para, uint32_t N )
		{
			uint32_t n = 0;

			
			while( !(((DSI_TypeDef *)((0x40000000U + 0x00010000U) + 0x6C00U))->GPSR & (0x1U << (0U))) ); 

			

			
			while(n < N)
			{
				((DSI_TypeDef *)((0x40000000U + 0x00010000U) + 0x6C00U))->GPDR = (  (uint32_t)(*(para + n  ))
										| ((uint32_t)(*(para + n+1)) <<  8) 
										| ((uint32_t)(*(para + n+2)) << 16) 
										| ((uint32_t)(*(para + n+3)) << 24) );
				n += 4;
			}

			
			((DSI_TypeDef *)((0x40000000U + 0x00010000U) + 0x6C00U))->GHCR = ( 0x39                 
				          | ( 0         << 6)    
						      | ((N&0xFFFF) << 8) ); 
		}
	
    
		void DisplayRefresh()
		{
			((DSI_TypeDef *)((0x40000000U + 0x00010000U) + 0x6C00U))->WCR |= (0x1U << (2U));
		}
  
	private:
    
	  cHwLTDC hwLTDC;
	  
};

#line 73 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\MCU.h"



#line 1 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Src/Ethernet_MCU.h"




















 



















 




















 



















 

 



 
#line 1 ".\\..\\EmbSysLib\\Src\\Com/Hardware/Ethernet/Ethernet.h"




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

#line 90 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Src/Ethernet_MCU.h"
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

#line 91 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Src/Ethernet_MCU.h"

#line 93 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Src/Ethernet_MCU.h"

 

 




 




     


#line 116 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Src/Ethernet_MCU.h"


 

 



 





   


 


  
 



  
typedef struct  {
  volatile uint32_t   Status;                 
  uint32_t   ControlBufferSize;      
  uint32_t   Buffer1Addr;            
  uint32_t   Buffer2NextDescAddr;    
 

  uint32_t   ExtendedStatus;         
  uint32_t   Reserved1;              
  uint32_t   TimeStampLow;           
  uint32_t   TimeStampHigh;          

} ETH_DMADESCTypeDef;


typedef struct{
  uint32_t length;
  uint32_t buffer;
  volatile ETH_DMADESCTypeDef *descriptor;
}FrameTypeDef;


typedef struct  {
  volatile ETH_DMADESCTypeDef *FS_Rx_Desc;           
  volatile ETH_DMADESCTypeDef *LS_Rx_Desc;           
  volatile uint32_t  Seg_Count;                      
} ETH_DMA_Rx_Frame_infos;
  

 


  
 
#line 184 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Src/Ethernet_MCU.h"

 












  
   

     




  





 












  
   

   




  






 


  
 














 



  
#line 293 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Src/Ethernet_MCU.h"



  





  




  


  



 

 


 















 



  
#line 359 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Src/Ethernet_MCU.h"



  








  




  










 

 
#line 409 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Src/Ethernet_MCU.h"

 


 



 


  
 


  





  





  
#line 447 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Src/Ethernet_MCU.h"



  






  








  








  







  





  
#line 496 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Src/Ethernet_MCU.h"

 


  
 



  





  







  





  
#line 547 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Src/Ethernet_MCU.h"



  
#line 569 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Src/Ethernet_MCU.h"



  
#line 579 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Src/Ethernet_MCU.h"



  
#line 589 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Src/Ethernet_MCU.h"



  





 


  
 


 



  




 


  
 


  






 






  
#line 647 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Src/Ethernet_MCU.h"


 


  
 


  





  










  






  
#line 690 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Src/Ethernet_MCU.h"






  







 
#line 711 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Src/Ethernet_MCU.h"


 



 


 


 



 



 


 


 


 


 


 


 



 





class cHwEthernet_MCU: public cHwEthernet
{
	public:
	  cHwEthernet_MCU( cHwPort::Pin &reset, const cNetAddr<6> &addrPhyIn );

  public:


    virtual void create( const cNetAddr<6> destAddr, const WORD type );


    virtual void     PacketSend   (uint8_t* packet, uint16_t len);
		virtual bool     PacketReceive();

    virtual WORD getType(  );

		
  private:
    void  low_level_init( void );
    int   low_level_output( BYTE *buff, DWORD length );
    DWORD low_level_input ( BYTE *ibuffer, DWORD maxLen);

volatile uint32_t  EthInitStatus;
volatile uint8_t EthLinkStatus;



 
 
 








 
uint32_t ETH_Init( uint16_t PHYAddress)
{
  uint32_t RegValue = 0, tmpreg = 0;
  volatile uint32_t i = 0;
  uint32_t hclk = (200000000);
  volatile uint32_t timeout = 0;

   
   
   
  tmpreg = ((ETH_TypeDef *) ((0x40000000U + 0x00020000U) + 0x8000U))->MACMIIAR;
   
  tmpreg &= ((uint32_t)0xFFFFFFE3);

   
  if((hclk >= 20000000)&&(hclk < 35000000))
  {
     
    tmpreg |= (uint32_t)(0x1U << (3U));
  }
  else if((hclk >= 35000000)&&(hclk < 60000000))
  {
     
    tmpreg |= (uint32_t)(0x3U << (2U));
  }
  else if((hclk >= 60000000)&&(hclk < 100000000))
  {
     
    tmpreg |= (uint32_t)0x00000000U;
  }
  else if((hclk >= 100000000)&&(hclk < 150000000))
  {
     
    tmpreg |= (uint32_t)(0x1U << (2U));
  }
  else  
  {
     
    tmpreg |= (uint32_t)(0x1U << (4U));
  }

   
  ((ETH_TypeDef *) ((0x40000000U + 0x00020000U) + 0x8000U))->MACMIIAR = (uint32_t)tmpreg;
   
   
  if(!(ETH_WritePHYRegister(PHYAddress, 0, ((uint16_t)0x8000))))
  {
     
    return ((uint32_t)0);
  }

   
  cSystem::delayMilliSec(10);

  if( ETH_AutoNegotiation )
  {
     
    do
    {
      timeout++;
    } while (!(ETH_ReadPHYRegister(PHYAddress, 1) & ((uint16_t)0x0004)) && (timeout < ((uint32_t)0x0004FFFF)));

     
    if(timeout == ((uint32_t)0x0004FFFF))
    {
      return ((uint32_t)0);
    }

     
    timeout = 0;
     
    if(!(ETH_WritePHYRegister(PHYAddress, 0, ((uint16_t)0x1000))))
    {
       
      return ((uint32_t)0);
    }

     
    do
    {
      timeout++;
    } while (!(ETH_ReadPHYRegister(PHYAddress, 1) & ((uint16_t)0x0020)) && (timeout < (uint32_t)((uint32_t)0x0004FFFF)));

     
    if(timeout == ((uint32_t)0x0004FFFF))
    {
      return ((uint32_t)0);
    }

     
    timeout = 0;

     
    RegValue = ETH_ReadPHYRegister(PHYAddress, ((uint16_t)31));

		switch (RegValue & ((uint16_t)0x001C))
		{
		  case (18):
			  ETH_Mode  = (0x1U << (11U)); 
				ETH_Speed = (0x1U << (14U)); 
			  break;

		  case (8):
			  ETH_Mode  = !(0x1U << (11U)); 
				ETH_Speed = (0x1U << (14U)); 
  			break;

		  case (14):
			  ETH_Mode  = (0x1U << (11U)); 
				ETH_Speed = !(0x1U << (14U));
			  break;

		  case (4):
			  ETH_Mode  = !(0x1U << (11U)); 
				ETH_Speed = !(0x1U << (14U));
			  break;

		  default:
			  break;
		}
  }
  else
  {
    if(!ETH_WritePHYRegister(PHYAddress, 0, ((uint16_t)(ETH_Mode >> 3) |
                                                   (uint16_t)(ETH_Speed >> 1))))
    {
       
      return ((uint32_t)0);
    }
     
    cSystem::delayMilliSec(100);

  }
   
   
  tmpreg = ((ETH_TypeDef *) ((0x40000000U + 0x00020000U) + 0x8000U))->MACCR;
   
  tmpreg &= ((uint32_t)0xFF20810F);
  
  tmpreg |= (uint32_t)(ETH_Watchdog |
                       ETH_Jabber |
                  ETH_InterFrameGap |
                  ETH_CarrierSense |
                  ETH_Speed |
                  ETH_ReceiveOwn |
                  ETH_LoopbackMode |
                  ETH_Mode |
                  ETH_ChecksumOffload |
                  ETH_RetryTransmission |
                  ETH_AutomaticPadCRCStrip |
                  ETH_BackOffLimit |
                  ETH_DeferralCheck);
   
  ((ETH_TypeDef *) ((0x40000000U + 0x00020000U) + 0x8000U))->MACCR = (uint32_t)tmpreg;

   
  ((ETH_TypeDef *) ((0x40000000U + 0x00020000U) + 0x8000U))->MACFFR = (uint32_t)(ETH_ReceiveAll |
                          ETH_SourceAddrFilter |
                          ETH_PassControlFrames |
                          ETH_BroadcastFramesReception |
                          ETH_DestinationAddrFilter |
                          ETH_PromiscuousMode |
                          ETH_MulticastFramesFilter |
                          ETH_UnicastFramesFilter);
  
   
   
  ((ETH_TypeDef *) ((0x40000000U + 0x00020000U) + 0x8000U))->MACHTHR = (uint32_t)ETH_HashTableHigh;
  
   
  ((ETH_TypeDef *) ((0x40000000U + 0x00020000U) + 0x8000U))->MACHTLR = (uint32_t)ETH_HashTableLow;
  
   
   
  tmpreg = ((ETH_TypeDef *) ((0x40000000U + 0x00020000U) + 0x8000U))->MACFCR;
   
  tmpreg &= ((uint32_t)0x0000FF41);

  tmpreg |= (uint32_t)((ETH_PauseTime << 16) |
                   ETH_ZeroQuantaPause |
                   ETH_PauseLowThreshold |
                   ETH_UnicastPauseFrameDetect |
                   ETH_ReceiveFlowControl |
                   ETH_TransmitFlowControl);
   
  ((ETH_TypeDef *) ((0x40000000U + 0x00020000U) + 0x8000U))->MACFCR = (uint32_t)tmpreg;
  
   
   
   
  ((ETH_TypeDef *) ((0x40000000U + 0x00020000U) + 0x8000U))->MACVLANTR = (uint32_t)(ETH_VLANTagComparison |
                             ETH_VLANTagIdentifier);

   
   
   
  tmpreg = ((ETH_TypeDef *) ((0x40000000U + 0x00020000U) + 0x8000U))->DMAOMR;
   
  tmpreg &= ((uint32_t)0xF8DE3F23);

   
   
   
   
   
   
   
   
   
  tmpreg |= (uint32_t)(ETH_DropTCPIPChecksumErrorFrame |
                  ETH_ReceiveStoreForward |
                  ETH_FlushReceivedFrame |
                  ETH_TransmitStoreForward |
                  ETH_TransmitThresholdControl |
                  ETH_ForwardErrorFrames |
                  ETH_ForwardUndersizedGoodFrames |
                  ETH_ReceiveThresholdControl |
                  ETH_SecondFrameOperate);
   
  ((ETH_TypeDef *) ((0x40000000U + 0x00020000U) + 0x8000U))->DMAOMR = (uint32_t)tmpreg;

   
  ((ETH_TypeDef *) ((0x40000000U + 0x00020000U) + 0x8000U))->DMABMR = (uint32_t)(ETH_AddressAlignedBeats |
                          ETH_FixedBurst |
                          ETH_RxDMABurstLength |  
                          ETH_TxDMABurstLength |
                         (ETH_DescriptorSkipLength << 2) |
                          ETH_DMAArbitration |
                          (0x1U << (23U)));  


     
    ((ETH_TypeDef *) ((0x40000000U + 0x00020000U) + 0x8000U))->DMABMR |= (0x1U << (7U));


   
  return ((uint32_t)1);
}





 
void ETH_Start(void)
{
   
  ((ETH_TypeDef *) ((0x40000000U + 0x00020000U) + 0x8000U))->MACCR |= (0x1U << (3U));
  
   
   
  ((ETH_TypeDef *) ((0x40000000U + 0x00020000U) + 0x8000U))->DMAOMR |= (0x1U << (20U));
  
   
  ((ETH_TypeDef *) ((0x40000000U + 0x00020000U) + 0x8000U))->MACCR |= (0x1U << (2U));

   
   
    ((ETH_TypeDef *) ((0x40000000U + 0x00020000U) + 0x8000U))->DMAOMR |= (0x1U << (13U));
  
   
 
    ((ETH_TypeDef *) ((0x40000000U + 0x00020000U) + 0x8000U))->DMAOMR |= (0x1U << (1U));
}











 
void ETH_MACAddressConfig(uint32_t MacAddr, uint8_t *Addr)
{
  uint32_t tmpreg;

   
  tmpreg = ((uint32_t)Addr[5] << 8) | (uint32_t)Addr[4];
   
  (*(volatile uint32_t *) (((((0x40000000U + 0x00020000U) + 0x8000U)) + 0x40) + MacAddr)) = tmpreg;
   
  tmpreg = ((uint32_t)Addr[3] << 24) | ((uint32_t)Addr[2] << 16) | ((uint32_t)Addr[1] << 8) | Addr[0];

   
  (*(volatile uint32_t *) (((((0x40000000U + 0x00020000U) + 0x8000U)) + 0x44) + MacAddr)) = tmpreg;
}



 
 
 






 
FrameTypeDef ETH_Get_Received_Frame(void);





 
uint32_t ETH_Prepare_Transmit_Descriptors(uint16_t FrameLength);








 
void ETH_DMARxDescChainInit(ETH_DMADESCTypeDef *DMARxDescTab, uint8_t *RxBuff, uint32_t RxBuffCount);





 
uint32_t ETH_CheckFrameReceived(void);







 
void ETH_DMATxDescChainInit(ETH_DMADESCTypeDef *DMATxDescTab, uint8_t* TxBuff, uint32_t TxBuffCount);

 
 
 













 
uint16_t ETH_ReadPHYRegister(uint16_t PHYAddress, uint16_t PHYReg)
{
  uint32_t tmpreg = 0;
volatile uint32_t timeout = 0;

   
  tmpreg = ((ETH_TypeDef *) ((0x40000000U + 0x00020000U) + 0x8000U))->MACMIIAR;
   
  tmpreg &= ~((uint32_t)0xFFFFFFE3);
   
  tmpreg |=(((uint32_t)PHYAddress<<11) & (0x1FU << (11U)));  
  tmpreg |=(((uint32_t)PHYReg<<6) & (0x1FU << (6U)));       
  tmpreg &= ~(0x1U << (1U));                               
  tmpreg |= (0x1U << (0U));                                
   
  ((ETH_TypeDef *) ((0x40000000U + 0x00020000U) + 0x8000U))->MACMIIAR = tmpreg;
   
  do
  {
    timeout++;
    tmpreg = ((ETH_TypeDef *) ((0x40000000U + 0x00020000U) + 0x8000U))->MACMIIAR;
  } while ((tmpreg & (0x1U << (0U))) && (timeout < (uint32_t)((uint32_t)0x0004FFFF)));
   
  if(timeout == ((uint32_t)0x0004FFFF))
  {
    return (uint16_t)((uint32_t)0);
  }

   
  return (uint16_t)(((ETH_TypeDef *) ((0x40000000U + 0x00020000U) + 0x8000U))->MACMIIDR);
}












 
uint32_t ETH_WritePHYRegister(uint16_t PHYAddress, uint16_t PHYReg, uint16_t PHYValue)
{
  uint32_t tmpreg = 0;
  volatile uint32_t timeout = 0;

   
  tmpreg = ((ETH_TypeDef *) ((0x40000000U + 0x00020000U) + 0x8000U))->MACMIIAR;
   
  tmpreg &= ~((uint32_t)0xFFFFFFE3);
   
  tmpreg |=(((uint32_t)PHYAddress<<11) & (0x1FU << (11U)));  
  tmpreg |=(((uint32_t)PHYReg<<6) & (0x1FU << (6U)));       
  tmpreg |= (0x1U << (1U));                                
  tmpreg |= (0x1U << (0U));                                
   
  ((ETH_TypeDef *) ((0x40000000U + 0x00020000U) + 0x8000U))->MACMIIDR = PHYValue;
   
  ((ETH_TypeDef *) ((0x40000000U + 0x00020000U) + 0x8000U))->MACMIIAR = tmpreg;
   
  do
  {
    timeout++;
    tmpreg = ((ETH_TypeDef *) ((0x40000000U + 0x00020000U) + 0x8000U))->MACMIIAR;
  } while ((tmpreg & (0x1U << (0U))) && (timeout < (uint32_t)((uint32_t)0x0004FFFF)));
   
  if(timeout == ((uint32_t)0x0004FFFF))
  {
    return ((uint32_t)0);
  }

   
  return ((uint32_t)1);
}


  
  bool     ETH_AutoNegotiation;
  uint32_t ETH_Watchdog;
  uint32_t ETH_Jabber;
  uint32_t ETH_InterFrameGap;
  uint32_t ETH_CarrierSense;
  uint32_t ETH_Speed;
  uint32_t ETH_ReceiveOwn;
  uint32_t ETH_LoopbackMode;
  uint32_t ETH_Mode;
  uint32_t ETH_ChecksumOffload;
  uint32_t ETH_RetryTransmission;
  uint32_t ETH_AutomaticPadCRCStrip;
  uint32_t ETH_BackOffLimit;
  uint32_t ETH_DeferralCheck;
  uint32_t ETH_ReceiveAll;
  uint32_t ETH_SourceAddrFilter;
  uint32_t ETH_PassControlFrames;
  uint32_t ETH_BroadcastFramesReception;
  uint32_t ETH_DestinationAddrFilter;
  uint32_t ETH_PromiscuousMode;
  uint32_t ETH_MulticastFramesFilter;
  uint32_t ETH_UnicastFramesFilter;
  uint32_t ETH_HashTableHigh;
  uint32_t ETH_HashTableLow;
  uint32_t ETH_PauseTime;
  uint32_t ETH_ZeroQuantaPause;
  uint32_t ETH_PauseLowThreshold;
  uint32_t ETH_UnicastPauseFrameDetect;
  uint32_t ETH_ReceiveFlowControl;
  uint32_t ETH_TransmitFlowControl;
  uint32_t ETH_VLANTagComparison;
  uint32_t ETH_VLANTagIdentifier;
  uint32_t ETH_DropTCPIPChecksumErrorFrame;
  uint32_t ETH_ReceiveStoreForward;
  uint32_t ETH_FlushReceivedFrame;
  uint32_t ETH_TransmitStoreForward;
  uint32_t ETH_TransmitThresholdControl;
  uint32_t ETH_ForwardErrorFrames;
  uint32_t ETH_ForwardUndersizedGoodFrames;
  uint32_t ETH_ReceiveThresholdControl;
  uint32_t ETH_SecondFrameOperate;
  uint32_t ETH_AddressAlignedBeats;
  uint32_t ETH_FixedBurst;
  uint32_t ETH_RxDMABurstLength;
  uint32_t ETH_TxDMABurstLength;
  uint32_t ETH_DescriptorSkipLength;
  uint32_t ETH_DMAArbitration;

};


#line 77 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\MCU.h"


#line 1 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Src/I2Cmaster_MCU.h"







 






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

#line 16 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Src/I2Cmaster_MCU.h"








 
class cHwI2Cmaster_N : public cHwI2Cmaster
{
  public:
    
    
 
    typedef enum
    {
      I2C_1 = 1, 
      I2C_2,     
      I2C_3,     
      I2C_4      
    } I2C_ID;
    
  public:
    
    






 
    cHwI2Cmaster_N( I2C_ID id, 
                    MODE   mode, 
                    BYTE   maskIntr = true );

  private:
    
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
   	
		
    virtual void waitForAckn( MTYPE state ) {};

    
    virtual void start( void ) {};

    
    virtual void stop( void ) {};

    
    virtual void sendAddr( BYTE addr ) {};

    
    virtual void writeByte( BYTE byte ) {};

    
    virtual BYTE readByteAck( void ) { return(0); };

    
    virtual BYTE readByteNack( void ) { return(0); };

  private:
    
    I2C_TypeDef* ptrBase;

}; 

#line 80 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\MCU.h"
#line 81 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\MCU.h"

#line 1 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Src/Memory_Flash.h"







 






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

#line 16 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Src/Memory_Flash.h"








 
class cHwMemory_Flash : public cHwMemory
{
  public:
    
    typedef enum
    {
      
      
      SECTOR_0  = (0x00<<8)|( 0<<4)|(1<<0), 
      SECTOR_1  = (0x01<<8)|( 1<<4)|(1<<0), 
      SECTOR_2  = (0x02<<8)|( 2<<4)|(1<<0), 
      SECTOR_3  = (0x03<<8)|( 3<<4)|(1<<0), 
			
      SECTOR_4  = (0x04<<8)|( 4<<4)|(4<<0), 

      SECTOR_5  = (0x08<<8)|( 5<<4)|(8<<0), 
      SECTOR_6  = (0x10<<8)|( 6<<4)|(8<<0), 
      SECTOR_7  = (0x18<<8)|( 7<<4)|(8<<0), 
      SECTOR_8  = (0x20<<8)|( 8<<4)|(8<<0), 
      SECTOR_9  = (0x28<<8)|( 9<<4)|(8<<0), 
      SECTOR_10 = (0x30<<8)|(10<<4)|(8<<0), 
      SECTOR_11 = (0x38<<8)|(11<<4)|(8<<0), 
      
      
      
    } Sector;

  public:
    
    

 
    cHwMemory_Flash( Sector sector );

  
    
    virtual void lock( void );
		
    
    virtual void unlock( void );

    
    virtual void writeByte( DWORD addr,
                            BYTE  data );

    
    virtual BYTE readByte( DWORD addr );

  public:
    
    virtual void clear( DWORD offset = 0 );

  protected:
    
    BYTE  *ptr;

  private:
    
    BYTE   sectorID;
    DWORD  dataDoubleWord;

}; 

#line 83 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\MCU.h"

#line 1 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Src/Port_MCU.h"







 






#line 16 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Src/Port_MCU.h"








 
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
      PI,     
      PJ,     
    } PortId;

  public:
    
    

 
    cHwPort_N( PortId portId );

    
    virtual void setMode( MTYPE mask, Mode mode );

    
    virtual void setPinMode( BYTE pinId, Mode modeIn );

    
    virtual void set( MTYPE mask )
    {
      ptr->BSRR = mask;
    }

    
    virtual void set( MTYPE mask, MTYPE value )
    {
      ptr->BSRR = (mask &  value);
      ptr->BSRR = (mask & ~value)<<16;
    }

    
    virtual void clr( MTYPE mask )
    {
      ptr->BSRR = mask << 16;
    }

    
    virtual MTYPE get( void )
    {
      return( ptr->IDR );
    }

  private:
    
    GPIO_TypeDef *ptr;

}; 

#line 85 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\MCU.h"
#line 1 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Src/RTC_MCU.h"







 






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

#line 16 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Src/RTC_MCU.h"








 
class cHwRTC_0 : public cHwRTC
{
  public:
	  typedef enum
		{
      LSI = 0,
			LSE
		} RTC_ClockConfig_t;
	
    
    
 
    cHwRTC_0( RTC_ClockConfig_t config );

    
    virtual void set( const cHwRTC::Properties &clock );

    
    virtual BYTE get( cHwRTC::Properties &clock );

}; 

#line 86 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\MCU.h"

#line 1 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Src/Timer_MCU.h"







 






#line 16 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Src/Timer_MCU.h"








 
class cHwTimer_N : public cHwTimer
{
  public:
    
    

 
    typedef enum
    {
      TIM_1 = 1, 
      TIM_2,     
      TIM_3,     
      TIM_4,     
      TIM_5,     
      TIM_7,     
      TIM_8,     
      TIM_9,     
      TIM_10,    
      TIM_11,    
      TIM_14     
    } TimerId;

  public:
    
    


 
    cHwTimer_N( TimerId timerId, DWORD cycleTime );

    
    virtual void enablePWM( BYTE channel = 0, Mode polarity = NORMAL );

    
    virtual void setPWM( WORD value, BYTE channel = 0 );

    
    
    
    
    void isr_N( void );

  public:
    
    static cHwTimer_N *timerPtr_1;
    static cHwTimer_N *timerPtr_2;
    static cHwTimer_N *timerPtr_3;
    static cHwTimer_N *timerPtr_4;
    static cHwTimer_N *timerPtr_5;
    static cHwTimer_N *timerPtr_7;
    static cHwTimer_N *timerPtr_8;
    static cHwTimer_N *timerPtr_9;
    static cHwTimer_N *timerPtr_10;
    static cHwTimer_N *timerPtr_11;
    static cHwTimer_N *timerPtr_14;
  
  private:
    
    DWORD        tics;
    TimerId      timerId;
    TIM_TypeDef *ptr;

}; 

#line 88 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\MCU.h"
#line 1 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Src/UART_MCU.h"







 






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

#line 16 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Src/UART_MCU.h"








 
class cHwUART_N : public cHwUART
{
  public:
    
    

 
    typedef enum
    {
      USART_1 = 1, 
      USART_2 = 2, 
      USART_3 = 3, 
      UART_4  = 4, 
      UART_5  = 5, 
      USART_6 = 6  
    } USART_Id;

    
    typedef enum
    {
      RTS  = 0x80000000,
      CTS  = 0x40000000,
      EVEN = 0x20000000,
      ODD  = 0x10000000,
      
      BR_230400 = BR_115200+1,
      BR_460800
    } MODE;

  public:
    
    





 
    cHwUART_N( USART_Id id,
               DWORD    mode,
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
    static cHwUART_N *uartPtr_4;
    static cHwUART_N *uartPtr_5;
    static cHwUART_N *uartPtr_6;

  protected:
    
    USART_TypeDef *ptr;

}; 

#line 89 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\MCU.h"
#line 1 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Src/USB_MCU.h"







 






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

#line 16 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Src/USB_MCU.h"









 
class cHwUSB_0 : public cHwUSB
{
  private:  
    
    class Buffer
    {
      public:
        
        BYTE data[128];
        BYTE size;
        BYTE flag;
        BYTE maxpacket;
      
        
        Buffer( void )
        {
          size      = 0;
          flag      = false;
          maxpacket = 0;
        }
    };
    
  private:
    
    class EndpointIN
    {
      public:
        
        EndpointIN( void );
        
        
        void  init    ( BYTE numIn );
        void  config  ( WORD epMPS, BYTE epType = 0 ); 
        void  flush   ( void );
        void  reset   ( void );
        void  start   ( void );
        void  setStall( void );
        void  clrStall( void );
        
        
        WORD  write      ( BYTE *dataPtr, WORD len );
        void  writeToFifo( void );
        void  transmit   ( bool flag );
        void  transmitZLP( void );
        
        
        DWORD getInterrupt( void );
        void  clrInterrupt( DWORD interruptID );

      private:
        
        BYTE                        num;
        Buffer                      txBuf;
        USB_OTG_INEndpointTypeDef  *inep;
        volatile DWORD                 *fifo;
        
    }; 
    
  
  private:
    
    class EndpointOUT
    {
      public:
        EndpointOUT( void );
        
        
        void init    ( BYTE numIn );
        void config  ( WORD epMPS, BYTE epType = 0 ); 
        void flush   ( void );
        void reset   ( void );
        void start   ( void );
        void setStall( void );
        void clrStall( void );
      
        
        WORD read        ( BYTE *dataPtr, WORD len );
        void readFromFifo( WORD  len);
        void receive     ( void );
        void receiveZLP  ( void );

        
        DWORD getInterrupt( void );
        void  clrInterrupt( DWORD interruptID );
        
      private:
        
        BYTE                        num;
        Buffer                      rxBuf;
        USB_OTG_OUTEndpointTypeDef *outep;
        volatile DWORD                 *fifo;
        
    }; 
    

  public:
    
    

 
    cHwUSB_0( cHwUSBdesc &desc );

    
    
 
    virtual void start( void );

    
    
    void isr( void );

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
                          BYTE *dataPtr,
                          WORD  len );

  private:
    
    BYTE  CoreReset         ( void );
    DWORD getInInterrupt    ( void );
    DWORD getOutInterrupt   ( void );
    BYTE  isInterruptPending( DWORD interuptID );
    void  clrInterrupt      ( DWORD interuptID );

  public:
    
    static cHwUSB_0 *usbPtr;

  private:
    
    static const WORD NUM_OF_ENDPOINTS = 4;
    static const WORD MAX_EP0_SIZE     = 64;

    cHwUSB_0::EndpointIN  epIN [ NUM_OF_ENDPOINTS ];
    cHwUSB_0::EndpointOUT epOUT[ NUM_OF_ENDPOINTS ];

}; 

#line 90 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\MCU.h"






#line 22 "..\\EmbSysLib\\Src\\lib.h"




#line 1 "..\\EmbSysLib\\Src\\Com/Hardware/Net/Net.h"









 






#line 18 "..\\EmbSysLib\\Src\\Com/Hardware/Net/Net.h"
#line 1 "..\\EmbSysLib\\Src\\Com/Hardware/Net/NetApp.h"



#line 5 "..\\EmbSysLib\\Src\\Com/Hardware/Net/NetApp.h"

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

#line 19 "..\\EmbSysLib\\Src\\Com/Hardware/Net/Net.h"
#line 1 "..\\EmbSysLib\\Src\\Com/Hardware/Net/NetTransport.h"



#line 5 "..\\EmbSysLib\\Src\\Com/Hardware/Net/NetTransport.h"
#line 6 "..\\EmbSysLib\\Src\\Com/Hardware/Net/NetTransport.h"


#line 1 "C:\\Bin\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdarg.h"
 
 
 





 











      namespace std {

          extern "C" {











 

 
 
#line 57 "C:\\Bin\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdarg.h"
    typedef struct __va_list { void *__ap; } va_list;

   






 


   










 


   















 




   

 


   




 



   





 



         }   
      }   


#line 138 "C:\\Bin\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdarg.h"





      using ::std::va_list;




 

#line 9 "..\\EmbSysLib\\Src\\Com/Hardware/Net/NetTransport.h"
#line 10 "..\\EmbSysLib\\Src\\Com/Hardware/Net/NetTransport.h"
#line 11 "..\\EmbSysLib\\Src\\Com/Hardware/Net/NetTransport.h"




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

#line 20 "..\\EmbSysLib\\Src\\Com/Hardware/Net/Net.h"



#line 1 "..\\EmbSysLib\\Src\\Com/Hardware/Net/NetARP.h"



#line 5 "..\\EmbSysLib\\Src\\Com/Hardware/Net/NetARP.h"

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

#line 24 "..\\EmbSysLib\\Src\\Com/Hardware/Net/Net.h"
#line 1 "..\\EmbSysLib\\Src\\Com/Hardware/Net/NetDHCP.h"





#line 1 "..\\EmbSysLib\\Src\\Com/Hardware/Net/NetUDP.h"



#line 1 "..\\EmbSysLib\\Src\\Com/Hardware/Net/NetIP.h"




#line 6 "..\\EmbSysLib\\Src\\Com/Hardware/Net/NetIP.h"
#line 7 "..\\EmbSysLib\\Src\\Com/Hardware/Net/NetIP.h"


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

#line 5 "..\\EmbSysLib\\Src\\Com/Hardware/Net/NetUDP.h"

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

#line 7 "..\\EmbSysLib\\Src\\Com/Hardware/Net/NetDHCP.h"


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

#line 25 "..\\EmbSysLib\\Src\\Com/Hardware/Net/Net.h"
#line 1 "..\\EmbSysLib\\Src\\Com/Hardware/Net/NetICMP.h"




#line 6 "..\\EmbSysLib\\Src\\Com/Hardware/Net/NetICMP.h"

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

#line 26 "..\\EmbSysLib\\Src\\Com/Hardware/Net/Net.h"
#line 1 "..\\EmbSysLib\\Src\\Com/Hardware/Net/NetTCP.h"





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

#line 27 "..\\EmbSysLib\\Src\\Com/Hardware/Net/Net.h"
#line 28 "..\\EmbSysLib\\Src\\Com/Hardware/Net/Net.h"


#line 27 "..\\EmbSysLib\\Src\\lib.h"









#line 1 "..\\EmbSysLib\\Src\\Com/Std/Std.h"









 






#line 18 "..\\EmbSysLib\\Src\\Com/Std/Std.h"
#line 19 "..\\EmbSysLib\\Src\\Com/Std/Std.h"
#line 20 "..\\EmbSysLib\\Src\\Com/Std/Std.h"






 
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

#line 37 "..\\EmbSysLib\\Src\\lib.h"
#line 1 "..\\EmbSysLib\\Src\\Com/Std/StaticArray.h"





 





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



#line 38 "..\\EmbSysLib\\Src\\lib.h"
#line 1 "..\\EmbSysLib\\Src\\Com/Std/CRC.h"





 






















 
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

#line 39 "..\\EmbSysLib\\Src\\lib.h"
#line 40 "..\\EmbSysLib\\Src\\lib.h"
#line 41 "..\\EmbSysLib\\Src\\lib.h"
#line 1 "..\\EmbSysLib\\Src\\Com/Std/SharedMem.h"







 






#line 16 "..\\EmbSysLib\\Src\\Com/Std/SharedMem.h"









 
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

#line 42 "..\\EmbSysLib\\Src\\lib.h"
#line 43 "..\\EmbSysLib\\Src\\lib.h"
#line 1 "..\\EmbSysLib\\Src\\Com/Std/Timer.h"







 












 
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

#line 44 "..\\EmbSysLib\\Src\\lib.h"







#line 1 "..\\EmbSysLib\\Src\\Com/Device/Analog/devAnalogInADC.h"







 






#line 1 "..\\EmbSysLib\\Src\\Com/Device/Analog/devAnalogIn.h"







 






#line 1 "..\\EmbSysLib\\Src\\Com/Device/Analog/devAnalog.h"







 
















 
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

#line 16 "..\\EmbSysLib\\Src\\Com/Device/Analog/devAnalogIn.h"












 
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

#line 16 "..\\EmbSysLib\\Src\\Com/Device/Analog/devAnalogInADC.h"
#line 17 "..\\EmbSysLib\\Src\\Com/Device/Analog/devAnalogInADC.h"








 
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

#line 52 "..\\EmbSysLib\\Src\\lib.h"
#line 1 "..\\EmbSysLib\\Src\\Com/Device/Analog/devAnalogOutDAC.h"








 






#line 1 "..\\EmbSysLib\\Src\\Com/Device/Analog/devAnalogOut.h"







 






#line 16 "..\\EmbSysLib\\Src\\Com/Device/Analog/devAnalogOut.h"












 
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

#line 17 "..\\EmbSysLib\\Src\\Com/Device/Analog/devAnalogOutDAC.h"
#line 18 "..\\EmbSysLib\\Src\\Com/Device/Analog/devAnalogOutDAC.h"








 
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

#line 53 "..\\EmbSysLib\\Src\\lib.h"
#line 1 "..\\EmbSysLib\\Src\\Com/Device/Analog/devAnalogOutPWM.h"








 






#line 17 "..\\EmbSysLib\\Src\\Com/Device/Analog/devAnalogOutPWM.h"
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

#line 18 "..\\EmbSysLib\\Src\\Com/Device/Analog/devAnalogOutPWM.h"
#line 19 "..\\EmbSysLib\\Src\\Com/Device/Analog/devAnalogOutPWM.h"








 
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

#line 54 "..\\EmbSysLib\\Src\\lib.h"




#line 59 "..\\EmbSysLib\\Src\\lib.h"
#line 1 "..\\EmbSysLib\\Src\\Com/Device/Digital/devDigitalIndicator.h"







 






#line 16 "..\\EmbSysLib\\Src\\Com/Device/Digital/devDigitalIndicator.h"










 
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

#line 60 "..\\EmbSysLib\\Src\\lib.h"




#line 1 "..\\EmbSysLib\\Src\\Com/Device/Display/devDisplay.h"







 












 
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

#line 65 "..\\EmbSysLib\\Src\\lib.h"
#line 1 "..\\EmbSysLib\\Src\\Com/Device/Display/devDisplayChar.h"







 






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

#line 16 "..\\EmbSysLib\\Src\\Com/Device/Display/devDisplayChar.h"
#line 17 "..\\EmbSysLib\\Src\\Com/Device/Display/devDisplayChar.h"










 
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

#line 66 "..\\EmbSysLib\\Src\\lib.h"
#line 1 "..\\EmbSysLib\\Src\\Com/Device/Display/devDisplayGraphic.h"





 







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

#line 15 "..\\EmbSysLib\\Src\\Com/Device/Display/devDisplayGraphic.h"
#line 16 "..\\EmbSysLib\\Src\\Com/Device/Display/devDisplayGraphic.h"

















 
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

#line 67 "..\\EmbSysLib\\Src\\lib.h"




#line 1 "..\\EmbSysLib\\Src\\Com/Device/Memory/devMemory.h"







 






#line 16 "..\\EmbSysLib\\Src\\Com/Device/Memory/devMemory.h"








 
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

#line 72 "..\\EmbSysLib\\Src\\lib.h"
#line 1 "..\\EmbSysLib\\Src\\Com/Device/Memory/devMemoryFlash.h"







 






#line 16 "..\\EmbSysLib\\Src\\Com/Device/Memory/devMemoryFlash.h"








 
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

#line 73 "..\\EmbSysLib\\Src\\lib.h"




#line 1 "..\\EmbSysLib\\Src\\Com/Device/TextIO/devTextIO_UART.h"







 






#line 1 "..\\EmbSysLib\\Src\\Com/Device/TextIO/devTextIO.h"







 




























 
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

#line 16 "..\\EmbSysLib\\Src\\Com/Device/TextIO/devTextIO_UART.h"
#line 17 "..\\EmbSysLib\\Src\\Com/Device/TextIO/devTextIO_UART.h"









 
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

#line 78 "..\\EmbSysLib\\Src\\lib.h"




#line 1 "..\\EmbSysLib\\Src\\Com/Device/Control/devControlEncoder.h"





 






#line 14 "..\\EmbSysLib\\Src\\Com/Device/Control/devControlEncoder.h"
#line 15 "..\\EmbSysLib\\Src\\Com/Device/Control/devControlEncoder.h"














 
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

#line 83 "..\\EmbSysLib\\Src\\lib.h"
#line 1 "..\\EmbSysLib\\Src\\Com/Device/Control/devControlEncoderJoystick.h"





 






#line 14 "..\\EmbSysLib\\Src\\Com/Device/Control/devControlEncoderJoystick.h"











 
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

#line 84 "..\\EmbSysLib\\Src\\lib.h"
#line 1 "..\\EmbSysLib\\Src\\Com/Device/Control/devControlEncoderRotaryknob.h"





 






#line 14 "..\\EmbSysLib\\Src\\Com/Device/Control/devControlEncoderRotaryknob.h"











 
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

#line 85 "..\\EmbSysLib\\Src\\lib.h"
#line 1 "..\\EmbSysLib\\Src\\Com/Device/Control/devControlPointer.h"





 






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

#line 14 "..\\EmbSysLib\\Src\\Com/Device/Control/devControlPointer.h"








 
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

#line 86 "..\\EmbSysLib\\Src\\lib.h"




#line 1 "..\\EmbSysLib\\Src\\Com/Task/TaskHandler.h"







 






#line 16 "..\\EmbSysLib\\Src\\Com/Task/TaskHandler.h"
#line 17 "..\\EmbSysLib\\Src\\Com/Task/TaskHandler.h"
















 
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

#line 91 "..\\EmbSysLib\\Src\\lib.h"

#line 14 "..\\EmbSysLib\\Src\\lib.cpp"




#line 1 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\MCU.cpp"











 


#line 1 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/System.cpp"









 


#line 14 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/System.cpp"


#line 17 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/System.cpp"












unsigned char cSystem::cntInterrupt = 0;


cSystem::cSystem( unsigned char disableInterrupts )
{
  disableWatchdog();
  if( disableInterrupts )
  {
    disableInterrupt();
  }
}


void cSystem::start( void )
{
  enableInterrupt();
}


void cSystem::disableInterrupt( void )
{
  __disable_irq();
  cntInterrupt++;
}


void cSystem::enableInterrupt( void )
{
  if(cntInterrupt > 0)
  {
    cntInterrupt--;
  }
  if(cntInterrupt == 0)
  {
     __enable_irq();
  }
}


void cSystem::enterISR( void )
{
  cntInterrupt++;
}


void cSystem::leaveISR( void )
{
  if( cntInterrupt > 0 )
  {
    cntInterrupt--;
  }
}


void cSystem::enableWatchdog( MODE mode )
{
  DWORD pr  = 0;
  DWORD rlr = 0;

  
  switch( mode )
  {
    default:
    case WD_TIMEOUT_16ms:   pr = 0; rlr =  160; break; 
    case WD_TIMEOUT_32ms:   pr = 0; rlr =  320; break; 
    case WD_TIMEOUT_65ms:   pr = 0; rlr =  650; break; 
    case WD_TIMEOUT_130ms:  pr = 0; rlr = 1300; break; 
    case WD_TIMEOUT_260ms:  pr = 0; rlr = 2600; break; 
    case WD_TIMEOUT_520ms:  pr = 1; rlr = 2600; break; 
    case WD_TIMEOUT_1000ms: pr = 2; rlr = 2500; break; 
    case WD_TIMEOUT_2000ms: pr = 3; rlr = 2500; break; 
  }

  ((IWDG_TypeDef *) (0x40000000U + 0x3000U))->KR  = 0x5555;
  ((IWDG_TypeDef *) (0x40000000U + 0x3000U))->PR  = pr;
  ((IWDG_TypeDef *) (0x40000000U + 0x3000U))->KR  = 0x5555;
  ((IWDG_TypeDef *) (0x40000000U + 0x3000U))->RLR = rlr;
  ((IWDG_TypeDef *) (0x40000000U + 0x3000U))->KR  = 0xAAAA;
  ((IWDG_TypeDef *) (0x40000000U + 0x3000U))->KR  = 0xCCCC;
}


void cSystem::disableWatchdog( void )
{
  
}


void cSystem::feedWatchdog( void )
{
  ((IWDG_TypeDef *) (0x40000000U + 0x3000U))->KR  = 0xAAAA;
}


void cSystem::reset( void )
{
  do { __schedule_barrier(); __dsb(0xF); __schedule_barrier(); } while (0U);
  *((unsigned long *)(0x2000FFF0)) = 0xDEADBEEF;
  NVIC_SystemReset();
}


void cSystem::delayMicroSec( unsigned short delay )
{
  
  delay *= 4;
  for(;delay>0;delay--)
  {
    asm volatile("nop");
  }
}


void cSystem::delayMilliSec( unsigned short delay )
{
  for(;delay>0;delay--)
    delayMicroSec(1000);
}












 
void SystemInit( void )
{
  


    
    ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->CPACR |=   (3UL << 10*2)  
                  | (3UL << 11*2); 



  
  ((RCC_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3800U))->CR |= (0x1U << (0U));

  
  ((RCC_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3800U))->CFGR = 0x00000000;       

  
  ((RCC_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3800U))->CR &= ~(   (0x1U << (24U))  
                | (0x1U << (19U))
                | (0x1U << (16U)) );

  
  ((RCC_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3800U))->PLLCFGR = 0x24003010;   
                               

  
  ((RCC_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3800U))->CR &= ~((0x1U << (18U))); 

  
  ((RCC_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3800U))->CIR = 0;                

  



    ((RCC_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3800U))->CR |= ((0x1U << (16U)) );



  

  
  
  ((RCC_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3800U))->CR |= (0x1U << (0U));   

  
  for( unsigned i = 0; i < (0x05000); i++ )
  {
    if( ((RCC_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3800U))->CR & (0x1U << (17U)) )
      break;
  }

  if( ((RCC_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3800U))->CR & (0x1U << (17U)) )
  {
    
    ((FLASH_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3C00U))->ACR =  
                 
                 0| 0x00000007U;  

    
    ((RCC_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3800U))->APB1ENR |= (0x1U << (28U));    

    

                                          

    
    
    ((RCC_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3800U))->CFGR |=   0x00000000U     
                 | 0x0000A000U    
                 | 0x00001400U;   
		

    
    


















 
    

    const DWORD pll_M = (25000)/1000UL; 
    const DWORD pll_N = 400;               
    const DWORD pll_P = 2;                 
    const DWORD pll_Q = 8;                 
    const DWORD pll_R = 7;                 

    
    ((RCC_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3800U))->PLLCFGR =   (0x1U << (22U))
                   | ( pll_M           )
                   | ( pll_N      <<  6)
                   | ((pll_P/2-1) << 16)
                   | ( pll_Q      << 24)
                   | ( pll_R      << 28);

    
    ((RCC_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3800U))->CR |= (0x1U << (24U));            
    while( !(((RCC_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3800U))->CR & (0x1U << (25U))) );

    
    ((RCC_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3800U))->CFGR &= ~((0x3U << (0U)));          
    ((RCC_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3800U))->CFGR |=  (0x00000002U);      
                                        

    
    while( (((RCC_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3800U))->CFGR & (0x3U << (2U))) != 0x00000008U );
		
		
		
		    
    
     
     
     
     
            
    ((RCC_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3800U))->CR &= ~(0x1U << (28U)); 

    
    while( ((RCC_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3800U))->CR & (0x1U << (29U)) ); 

     
     uint32_t  pllQ = (((RCC_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3800U))->PLLSAICFGR >> 24) & 0x0F;
     uint32_t  pllP = 8; 
     uint32_t  pllN = 384;
     uint32_t  pllR = 5;    
                               
    ((RCC_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3800U))->PLLSAICFGR =    ( pllN <<  6)
                       | ( (pllP/2-1) << 16)
                       | ( pllQ << 24)
                       | ( pllR << 28);

    ((RCC_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3800U))->DCKCFGR1 = (((RCC_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3800U))->DCKCFGR1 & ~(0x3U << (16U)))  | 0 ;
		((RCC_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3800U))->DCKCFGR2 |= (0x1U << (27U)); 

     
    ((RCC_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3800U))->CR |= (0x1U << (28U));

    
    while( !(((RCC_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3800U))->CR & (0x1U << (29U))) );

  }
  else
  {
    
  }

  
  ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->VTOR = 0x08000000U | 0x00; 

  SCB_InvalidateDCache();
	SCB_DisableDCache();
}


#line 16 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\MCU.cpp"
#line 1 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/PinConfig.cpp"







 







void cHwPinConfig::set( GPIO_TypeDef *gpio, BYTE pinId, DWORD mode, BYTE af )
{
  BYTE pin2 = 2*pinId;
  BYTE pin3 = pinId>>3;

  MTYPE bitmask1 = ~((MTYPE)0x01 <<     pinId    );
  MTYPE bitmask2 = ~((MTYPE)0x03 <<     pin2     );
  MTYPE bitmask3 = ~((MTYPE)0x0F << (4*(pinId%8)));

  MTYPE moder   = (MTYPE)((mode    )&0x03) << pin2;
  MTYPE pupdr   = (MTYPE)((mode>> 8)&0x03) << pin2;
  MTYPE otyper  = (MTYPE)((mode>> 4)&0x01) << pinId;
  MTYPE ospeedr = (MTYPE)((mode>>12)&0x03) << pin2;
  MTYPE afr     = (MTYPE)((af      )&0x0F) << (4*(pinId%8));

  cSystem::disableInterrupt();
  gpio->MODER     = ( gpio->MODER     & bitmask2 ) | moder;
  gpio->PUPDR     = ( gpio->PUPDR     & bitmask2 ) | pupdr;
  gpio->OTYPER    = ( gpio->OTYPER    & bitmask1 ) | otyper;
  gpio->OSPEEDR   = ( gpio->OSPEEDR   & bitmask2 ) | ospeedr;
  gpio->AFR[pin3] = ( gpio->AFR[pin3] & bitmask3 ) | afr;
  cSystem::enableInterrupt();
}


bool cHwPinConfig::set( Function func, DWORD mode )
{
  BYTE port;
  BYTE pin;
  BYTE af;

  GPIO_TypeDef *gpio;

  for( WORD i = 0; table[i] != END_OF_TABLE; i++ )
  {
    if( (table[i] >> 16) == func )
    {
      port = (table[i]>>12)&0x0F;
      pin  = (table[i]>> 4)&0x0F;
      af   = (table[i]>> 0)&0x0F;

      if( (mode & 0x0F) != ANALOG )
      {
        mode |= ALTERNATE_FUNC;
      }

      ((RCC_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3800U))->AHB1ENR |= ((1UL << port) );

      gpio = (GPIO_TypeDef *)(((0x40000000U + 0x00020000U) + 0x0000U) + (0x400*port));
      set( gpio, pin, mode, af );
      return( true );
    }
  }
  
  return( false );
}


#line 17 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\MCU.cpp"
#line 1 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/RTOS_MCU.cpp"







 


#line 12 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/RTOS_MCU.cpp"







DWORD (*cHwRTOS_MCU::schedule)( DWORD sp, BYTE flag ) = 0;

unsigned long  cHwRTOS_MCU::sysTic     = 0;
unsigned       cHwRTOS_MCU::sysTicTime = 0;


cHwRTOS_MCU::cHwRTOS_MCU( void )
{
}


extern "C"
{
  unsigned save_context( void         );
  void     load_context( unsigned ptr );
}



  #pragma push
  #pragma O0
#line 46 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Sys/RTOS_MCU.cpp"



extern "C"
{
  void SysTick_Handler( void )
  {
    static unsigned stackPointer = 0;

    stackPointer = save_context();
    cHwRTOS_MCU::sysTic++;
    stackPointer = cHwRTOS_MCU::schedule( stackPointer, true );
    load_context( stackPointer );
  }
}


extern "C"
{
  void PendSV_Handler( void )
  {
    static unsigned stackPointer = 0;

    stackPointer = save_context();
    stackPointer = cHwRTOS_MCU::schedule( stackPointer, false );
    load_context( stackPointer );
  }
}



  #pragma pop








#line 18 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\MCU.cpp"


#line 1 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Src/ADC_MCU.cpp"







 


#line 12 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Src/ADC_MCU.cpp"







cHwADC *cHwADC_0::adcPtr = 0;


cHwADC_0::cHwADC_0( cHwTimer *tPtrIn )

: cHwADC( 16, tPtrIn )

{
  adcPtr = this;

  ((RCC_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3800U))->APB2ENR |= (0x1U << (10U));

  ((ADC_Common_TypeDef *) ((0x40000000U + 0x00010000U) + 0x2300U))->CCR |= (3<<16); 

  ((ADC_TypeDef *) ((0x40000000U + 0x00010000U) + 0x2200U))->CR2  =    (0x1U << (0U))  
               | !(0x1U << (1U))  
               |  (0x1U << (11U));

  ((ADC_TypeDef *) ((0x40000000U + 0x00010000U) + 0x2200U))->CR1 =    (0x1U << (5U)); 



  __NVIC_EnableIRQ( ADC_IRQn );
}


void cHwADC_0::configCh( BYTE ch, BYTE para )
{

  DWORD paraLoc = para & 0x07; 

  switch( ch )
  {
    default:
      
      break;








    case  8: cHwPinConfig::set( cHwPinConfig::ADC3_IN8,   cHwPinConfig::ANALOG ); ((ADC_TypeDef *) ((0x40000000U + 0x00010000U) + 0x2200U))->SMPR2 |= (paraLoc<<24); break;



    case 12: cHwPinConfig::set( cHwPinConfig::ADC3_IN12, cHwPinConfig::ANALOG ); ((ADC_TypeDef *) ((0x40000000U + 0x00010000U) + 0x2200U))->SMPR1 |= (paraLoc<< 6); break;




  }
}


inline WORD cHwADC_0::getResult( void )
{
  return( ((ADC_TypeDef *) ((0x40000000U + 0x00010000U) + 0x2200U))->DR & 0xFFFF );
}


inline void cHwADC_0::startCh( BYTE ch )
{
  
  ((ADC_TypeDef *) ((0x40000000U + 0x00010000U) + 0x2200U))->SQR3 = ch & 0x1F;

  ((ADC_TypeDef *) ((0x40000000U + 0x00010000U) + 0x2200U))->CR2 |= (0x1U << (30U));
}


extern "C"
{
  void ADC_IRQHandler(void)
  {
    ((ADC_TypeDef *) ((0x40000000U + 0x00010000U) + 0x2200U))->SR &= ~(0x1U << (1U));
    cHwADC_0::adcPtr->isr();
  }
}


#line 21 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\MCU.cpp"
#line 1 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Src/DAC_MCU.cpp"







 


#line 12 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Src/DAC_MCU.cpp"







cHwDAC_0::cHwDAC_0( void )

: cHwDAC( 2 )

{
  ((RCC_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3800U))->APB1ENR |= (0x1U << (29U));
}


inline void cHwDAC_0::set( WORD value, BYTE ch )
{
  switch( ch )
  {
    default:
      
      break;
    case 0: ((DAC_TypeDef *) (0x40000000U + 0x7400U))->DHR12L1 = value & 0xFFF0; break;
    case 1: ((DAC_TypeDef *) (0x40000000U + 0x7400U))->DHR12L2 = value & 0xFFF0; break;
  }
}


inline void cHwDAC_0::enable( BYTE ch )
{
  switch( ch )
  {
    default:
      
      break;
    
    case 0: 
      cHwPinConfig::set( cHwPinConfig::DAC_OUT1, cHwPinConfig::ANALOG );
      ((DAC_TypeDef *) (0x40000000U + 0x7400U))->CR |=   (0x1U << (0U))
                 | (0x1U << (1U));
      break;
    
    case 1:
      cHwPinConfig::set( cHwPinConfig::DAC_OUT2, cHwPinConfig::ANALOG );
      ((DAC_TypeDef *) (0x40000000U + 0x7400U))->CR |=   (0x1U << (16U))
                 | (0x1U << (17U)); 
      break;
  }
}


#line 22 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\MCU.cpp"



#line 1 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Src/Ethernet_MCU.cpp"
#line 2 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Src/Ethernet_MCU.cpp"
#line 3 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Src/Ethernet_MCU.cpp"














ETH_DMADESCTypeDef  DMARxDscrTab[5] __attribute__((at(0x20000000))); 

ETH_DMADESCTypeDef  DMATxDscrTab[5] __attribute__((at(0x20002000))); 

uint8_t Rx_Buff[5][1524] __attribute__((at(0x20000100)));  

uint8_t Tx_Buff[5][1524] __attribute__((at(0x20002100)));  

#line 52 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Src/Ethernet_MCU.cpp"


 
volatile ETH_DMADESCTypeDef  *DMATxDescToSet;
volatile ETH_DMADESCTypeDef  *DMARxDescToGet;


 
ETH_DMA_Rx_Frame_infos RX_Frame_Descriptor;
volatile ETH_DMA_Rx_Frame_infos *DMA_RX_FRAME_infos;
volatile uint32_t Frame_Rx_index;




cHwEthernet_MCU::cHwEthernet_MCU( cHwPort::Pin &resetPin, const cNetAddr<6> &addrPhyIn )

: cHwEthernet( addrPhyIn )

{
  EthInitStatus = 0;
  EthLinkStatus = 0;

  ETH_AutoNegotiation      =  true; 

  
  ETH_Watchdog             = !(0x1U << (23U)); 
  ETH_Jabber               = !(0x1U << (22U)); 
  ETH_InterFrameGap        =  0x00000000U;
  ETH_CarrierSense         = !(0x1U << (16U)); 
  ETH_Speed                =  (0x1U << (14U)); 
  ETH_ReceiveOwn           = !(0x1U << (13U)); 
  ETH_LoopbackMode         = !(0x1U << (12U)); 
  ETH_Mode                 =  (0x1U << (11U)); 



  ETH_ChecksumOffload      = !(0x1U << (10U));

  ETH_RetryTransmission    =  (0x1U << (9U));  
  ETH_AutomaticPadCRCStrip = !(0x1U << (7U));
  ETH_BackOffLimit         =  0x00000000U;
  ETH_DeferralCheck        = !(0x1U << (4U));

  
  ETH_ReceiveAll               = !(0x1U << (31U));
  ETH_SourceAddrFilter         =  !(0x1U << (9U))   
                                 |!(0x1U << (8U)); 
  ETH_PassControlFrames        =  (0x1U << (6U));
  ETH_BroadcastFramesReception = !(0x1U << (5U)); 
  ETH_DestinationAddrFilter    = !(0x1U << (3U));
  ETH_PromiscuousMode          = !(0x1U << (0U));
  ETH_MulticastFramesFilter    =  !(0x1U << (10U))
                                 |!(0x1U << (4U))
                                 |!(0x1U << (2U));  
  ETH_UnicastFramesFilter      =  !(0x1U << (10U))
                                 |!(0x1U << (1U));   

  
  ETH_HashTableHigh            = 0x0;

  
  ETH_HashTableLow             = 0x0;

  
  ETH_PauseTime                = 0x0;

  ETH_ZeroQuantaPause          =  (0x1U << (7U)); 
  ETH_PauseLowThreshold        =  0x00000000U; 
  ETH_UnicastPauseFrameDetect  = !(0x1U << (3U));
  ETH_ReceiveFlowControl       = !(0x1U << (2U));
  ETH_TransmitFlowControl      = !(0x1U << (1U));

  
  ETH_VLANTagComparison        = !(0x1U << (16U)); 
  ETH_VLANTagIdentifier        = 0x0;

  
  ETH_DropTCPIPChecksumErrorFrame = !(0x1U << (26U)); 
  ETH_ReceiveStoreForward         =  (0x1U << (25U));
  ETH_FlushReceivedFrame          = !(0x1U << (24U)); 
  ETH_TransmitStoreForward        =  (0x1U << (21U));
  ETH_TransmitThresholdControl    =  0x00000000U;
  ETH_ForwardErrorFrames          = !(0x1U << (7U));
  ETH_ForwardUndersizedGoodFrames = !(0x1U << (6U));
  ETH_ReceiveThresholdControl     =  0x00000000U;
  ETH_SecondFrameOperate          =  (0x1U << (2U));

  
  ETH_AddressAlignedBeats         =  (0x1U << (25U));
  ETH_FixedBurst                  =  (0x1U << (16U));
  ETH_RxDMABurstLength            =  0x00400000U;
  ETH_TxDMABurstLength            =  0x00002000U;
  ETH_DescriptorSkipLength        =  0x0;

  ETH_DMAArbitration              =   0x00000000U 
                                    |!(0x1U << (1U));      

  ((RCC_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3800U))->APB2ENR |= (0x1U << (14U));  

   
  ((SYSCFG_TypeDef *) ((0x40000000U + 0x00010000U) + 0x3800U))->PMC |= (0x1U << (23U)); 

  cHwPinConfig::set( cHwPinConfig::ETH_M,        cHwPinConfig::HIGH_SPEED
                                                |cHwPinConfig::PUSH_PULL
                                                |cHwPinConfig::NO_PUPD  );
																								
  cHwPinConfig::set( cHwPinConfig::ETH_MDIO,         cHwPinConfig::HIGH_SPEED
																								|cHwPinConfig::OPEN_DRAIN
                                                |cHwPinConfig::NO_PUPD  );
																								
  cHwPinConfig::set( cHwPinConfig::ETH_MII_RX_CLK,   cHwPinConfig::HIGH_SPEED
                                                |cHwPinConfig::OPEN_DRAIN
                                                |cHwPinConfig::NO_PUPD  );
																								
  cHwPinConfig::set( cHwPinConfig::ETH_MII_RX_DV,    cHwPinConfig::HIGH_SPEED
                                                |cHwPinConfig::OPEN_DRAIN
                                                |cHwPinConfig::NO_PUPD  );

 cHwPinConfig::set( cHwPinConfig::ETH_MII_TX_EN,    cHwPinConfig::HIGH_SPEED
                                                |cHwPinConfig::PUSH_PULL
                                                |cHwPinConfig::NO_PUPD  );

  cHwPinConfig::set( cHwPinConfig::ETH_MII_TXD0,    cHwPinConfig::HIGH_SPEED
                                                  |cHwPinConfig::PUSH_PULL
                                                  |cHwPinConfig::NO_PUPD  );
																									
  cHwPinConfig::set( cHwPinConfig::ETH_MII_TXD1,    cHwPinConfig::HIGH_SPEED
                                                  |cHwPinConfig::PUSH_PULL
                                                  |cHwPinConfig::NO_PUPD  );

 
 



  cHwPinConfig::set( cHwPinConfig::ETH_MII_RXD0,    cHwPinConfig::HIGH_SPEED
                                                |cHwPinConfig::INPUT
                                                |cHwPinConfig::NO_PUPD  );
  cHwPinConfig::set( cHwPinConfig::ETH_MII_RXD1,    cHwPinConfig::HIGH_SPEED
                                                |cHwPinConfig::INPUT
                                                |cHwPinConfig::NO_PUPD  );

  resetPin.setMode(cHwPort::OutOD);
  resetPin.clr();
  cSystem::delayMilliSec(1000);
  resetPin.set();

  ((RCC_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3800U))->AHB1ENR |= (  (0x1U << (25U))
                   | (0x1U << (26U))
                   | (0x1U << (27U))
                   | (0x1U << (28U)) ); 

   
  ((RCC_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3800U))->AHB1RSTR |= (0x1U << (25U));
  ((RCC_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3800U))->AHB1RSTR &= ~(0x1U << (25U));

   
   
   
  ((ETH_TypeDef *) ((0x40000000U + 0x00020000U) + 0x8000U))->DMABMR |= (0x1U << (0U));

   
  while( ((ETH_TypeDef *) ((0x40000000U + 0x00020000U) + 0x8000U))->DMABMR & (0x1U << (0U)) );


   
  DWORD id;
  BYTE PhyAddr;
  for(PhyAddr = 0; 32 > PhyAddr; PhyAddr++)
  {
    id =   (DWORD)ETH_ReadPHYRegister(PhyAddr,2)<<16
         | (DWORD)ETH_ReadPHYRegister(PhyAddr,3);

    
    
    if ((0x00221619 == id) || (0x0007C0F1 == id))
      break;
  }

  if(32 < PhyAddr)
  {
    
    while(1);
  }

   
  EthInitStatus = ETH_Init( PhyAddr);

   if (EthInitStatus == 0) {
    while(1);
  }

  low_level_init();
}


WORD cHwEthernet_MCU::getType( )
{
  cHwEthernet_Header *eth =(cHwEthernet_Header *)buf;

  if     ( plen >= sizeof( cNetIP_Msg ) && eth->type == TYPE_IP )
  {
    return( TYPE_IP );
  }
  else if( plen >= sizeof( cNetARP_Msg ) && eth->type == TYPE_ARP )
  {
    return( TYPE_ARP );
  }
  else
  {
    return( TYPE_UNDEF );
  }
  
}


void cHwEthernet_MCU::PacketSend(  uint8_t* packet, uint16_t len)
{
  low_level_output(packet, len);







}







bool cHwEthernet_MCU::PacketReceive()
{
  if( ETH_CheckFrameReceived() )
  {







		plen = low_level_input(buf,1500);

    return( true );
  }

















  return( false );
}


void cHwEthernet_MCU::create( const cNetAddr<6> destAddr,
                                   const WORD    type )
{
  cHwEthernet_Header *eth = (cHwEthernet_Header*)buf;

  eth->destinationAddr = destAddr;
  eth->sourceAddr      = addrPhy;
  eth->type            = type;
}






void cHwEthernet_MCU::low_level_init( )
    {



       
      
BYTE hwaddr[6];
       
      hwaddr[0] =  addrPhy.addr[0]; 
      hwaddr[1] =  addrPhy.addr[1];
      hwaddr[2] =  addrPhy.addr[2];
      hwaddr[3] =  addrPhy.addr[3];
      hwaddr[4] =  addrPhy.addr[4];
      hwaddr[5] =  addrPhy.addr[5];

       
      ETH_MACAddressConfig(((uint32_t)0x00000000), hwaddr);

       
      

       
       
      

       
      ETH_DMATxDescChainInit(DMATxDscrTab, &Tx_Buff[0][0], 5);
       
      ETH_DMARxDescChainInit(DMARxDscrTab, &Rx_Buff[0][0], 5);

#line 376 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Src/Ethernet_MCU.cpp"

        

       
      ETH_Start();

    }





    int cHwEthernet_MCU::low_level_output(  BYTE *buff, DWORD length ) 
    {
			

      int framelength = 0;
      uint8_t *buffer =  (uint8_t *)(DMATxDescToSet->Buffer1Addr);





      memcpy(buffer,buff,length);
      framelength = length;
 






 
      
 

       
      ETH_Prepare_Transmit_Descriptors(framelength);

      return 0; 
    }





    
    

    DWORD cHwEthernet_MCU::low_level_input(BYTE *ibuffer, DWORD maxLen) 
    {
      
      uint16_t len;

      FrameTypeDef frame;
      uint8_t *buffer;
      uint32_t i=0;
      volatile ETH_DMADESCTypeDef *DMARxNextDesc;


     

       
      frame = ETH_Get_Received_Frame();

       
      len = frame.length;
      buffer = (uint8_t *)frame.buffer;

       
     

     

      memcpy( ibuffer, buffer,len);




 
       









       
       
      if (DMA_RX_FRAME_infos->Seg_Count > 1)
      {
        DMARxNextDesc = DMA_RX_FRAME_infos->FS_Rx_Desc;
      }
      else
      {
        DMARxNextDesc = frame.descriptor;
      }

       
      for (i=0; i<DMA_RX_FRAME_infos->Seg_Count; i++)
      {
        DMARxNextDesc->Status = ((uint32_t)0x80000000);
        DMARxNextDesc = (ETH_DMADESCTypeDef *)(DMARxNextDesc->Buffer2NextDescAddr);
      }

       
      DMA_RX_FRAME_infos->Seg_Count =0;

       
      if ((((ETH_TypeDef *) ((0x40000000U + 0x00020000U) + 0x8000U))->DMASR & (0x1U << (7U))) != (uint32_t)RESET)
      {
         
        ((ETH_TypeDef *) ((0x40000000U + 0x00020000U) + 0x8000U))->DMASR = (0x1U << (7U));
         
        ((ETH_TypeDef *) ((0x40000000U + 0x00020000U) + 0x8000U))->DMARPDR = 0;
      }
     
      return( len );
    }

 
 
 

FrameTypeDef cHwEthernet_MCU::ETH_Get_Received_Frame(void)
{
  uint32_t framelength = 0;
  FrameTypeDef frame = {0,0,0};

   
  framelength = ((DMARxDescToGet->Status & ((uint32_t)0x3FFF0000)) >> 16) - 4;
  frame.length = framelength;

   
   
  if (DMA_RX_FRAME_infos->Seg_Count >1)
  {
    frame.buffer =(DMA_RX_FRAME_infos->FS_Rx_Desc)->Buffer1Addr;
  }
  else
  {
    frame.buffer = DMARxDescToGet->Buffer1Addr;
  }

  frame.descriptor = DMARxDescToGet;

   
   
   
  DMARxDescToGet = (ETH_DMADESCTypeDef*) (DMARxDescToGet->Buffer2NextDescAddr);

   
  return (frame);
}


uint32_t cHwEthernet_MCU::ETH_Prepare_Transmit_Descriptors(uint16_t FrameLength)
{
  uint32_t buf_count =0, size=0,i=0;

   
  if((DMATxDescToSet->Status & ((uint32_t)0x80000000)) != (uint32_t)RESET)
  {
     
    return ((uint32_t)0);
  }

  if (FrameLength > 1524)
  {
    buf_count = FrameLength/1524;
    if (FrameLength%1524) buf_count++;
  }
  else buf_count =1;

  if (buf_count ==1)
  {
     
    DMATxDescToSet->Status |= (((uint32_t)0x10000000)|((uint32_t)0x20000000));
     
    DMATxDescToSet->ControlBufferSize = (FrameLength& ((uint32_t)0x00001FFF));
     
    DMATxDescToSet->Status |= ((uint32_t)0x80000000);
    DMATxDescToSet= (ETH_DMADESCTypeDef *)(DMATxDescToSet->Buffer2NextDescAddr);
  }
  else
  {
    for (i=0; i< buf_count; i++)
    {
			 
      DMATxDescToSet->Status &= ~(((uint32_t)0x10000000) | ((uint32_t)0x20000000));
      if (i==0)
      {
         
        DMATxDescToSet->Status |= ((uint32_t)0x10000000);
      }

       
      DMATxDescToSet->ControlBufferSize = (1524 & ((uint32_t)0x00001FFF));

      if (i== (buf_count-1))
      {
         
        DMATxDescToSet->Status |= ((uint32_t)0x20000000);
        size = FrameLength - (buf_count-1)*1524;
        DMATxDescToSet->ControlBufferSize = (size & ((uint32_t)0x00001FFF));
      }

       
      DMATxDescToSet->Status |= ((uint32_t)0x80000000);

      DMATxDescToSet = (ETH_DMADESCTypeDef *)(DMATxDescToSet->Buffer2NextDescAddr);
       
     }
  }

   
  if ((((ETH_TypeDef *) ((0x40000000U + 0x00020000U) + 0x8000U))->DMASR & (0x1U << (2U))) != (uint32_t)RESET)
  {
     
    ((ETH_TypeDef *) ((0x40000000U + 0x00020000U) + 0x8000U))->DMASR = (0x1U << (2U));
     
    ((ETH_TypeDef *) ((0x40000000U + 0x00020000U) + 0x8000U))->DMATPDR = 0;
  }

   
  return ((uint32_t)1);
}


void cHwEthernet_MCU::ETH_DMARxDescChainInit(ETH_DMADESCTypeDef *DMARxDescTab, uint8_t *RxBuff, uint32_t RxBuffCount)
{
  uint32_t i = 0;
  ETH_DMADESCTypeDef *DMARxDesc;

   
  DMARxDescToGet = DMARxDescTab;
   
  for(i=0; i < RxBuffCount; i++)
  {
     
    DMARxDesc = DMARxDescTab+i;
     
    DMARxDesc->Status = ((uint32_t)0x80000000);

     
    DMARxDesc->ControlBufferSize = ((uint32_t)0x00004000) | (uint32_t)1524;
     
    DMARxDesc->Buffer1Addr = (uint32_t)(&RxBuff[i*1524]);

     
    if(i < (RxBuffCount-1))
    {
       
      DMARxDesc->Buffer2NextDescAddr = (uint32_t)(DMARxDescTab+i+1);
    }
    else
    {
       
      DMARxDesc->Buffer2NextDescAddr = (uint32_t)(DMARxDescTab);
    }
  }

   
  ((ETH_TypeDef *) ((0x40000000U + 0x00020000U) + 0x8000U))->DMARDLAR = (uint32_t) DMARxDescTab;


  DMA_RX_FRAME_infos = &RX_Frame_Descriptor;

}


uint32_t cHwEthernet_MCU::ETH_CheckFrameReceived(void)
{
   
  if(((DMARxDescToGet->Status & ((uint32_t)0x80000000)) == (uint32_t)RESET) &&
     ((DMARxDescToGet->Status & ((uint32_t)0x00000100)) != (uint32_t)RESET))
    {
			
      DMA_RX_FRAME_infos->LS_Rx_Desc = DMARxDescToGet;
      DMA_RX_FRAME_infos->Seg_Count++;
      return 1;
    }

     
    else if(((DMARxDescToGet->Status & ((uint32_t)0x80000000)) == (uint32_t)RESET) &&
     ((DMARxDescToGet->Status & ((uint32_t)0x00000200)) != (uint32_t)RESET)&&
     ((DMARxDescToGet->Status & ((uint32_t)0x00000100)) == (uint32_t)RESET))
    {
      DMA_RX_FRAME_infos->FS_Rx_Desc = DMARxDescToGet;
      DMA_RX_FRAME_infos->LS_Rx_Desc = 0;
      DMA_RX_FRAME_infos->Seg_Count = 1;
      DMARxDescToGet = (ETH_DMADESCTypeDef*) (DMARxDescToGet->Buffer2NextDescAddr);
    }

     
    else if(((DMARxDescToGet->Status & ((uint32_t)0x80000000)) == (uint32_t)RESET) &&
     ((DMARxDescToGet->Status & ((uint32_t)0x00000200)) == (uint32_t)RESET)&&
     ((DMARxDescToGet->Status & ((uint32_t)0x00000100)) == (uint32_t)RESET))
    {
      (DMA_RX_FRAME_infos->Seg_Count) ++;
      DMARxDescToGet = (ETH_DMADESCTypeDef*) (DMARxDescToGet->Buffer2NextDescAddr);
    }
    return 0;
}




void cHwEthernet_MCU::ETH_DMATxDescChainInit(ETH_DMADESCTypeDef *DMATxDescTab, uint8_t* TxBuff, uint32_t TxBuffCount)
{
  uint32_t i = 0;
  ETH_DMADESCTypeDef *DMATxDesc;

   
  DMATxDescToSet = DMATxDescTab;
   
  for(i=0; i < TxBuffCount; i++)
  {
     
    DMATxDesc = DMATxDescTab + i;
     
    DMATxDesc->Status = ((uint32_t)0x00100000);

     
    DMATxDesc->Buffer1Addr = (uint32_t)(&TxBuff[i*1524]);

     
    if(i < (TxBuffCount-1))
    {
       
      DMATxDesc->Buffer2NextDescAddr = (uint32_t)(DMATxDescTab+i+1);
    }
    else
    {
       
      DMATxDesc->Buffer2NextDescAddr = (uint32_t) DMATxDescTab;
    }
  }

   
  ((ETH_TypeDef *) ((0x40000000U + 0x00020000U) + 0x8000U))->DMATDLAR = (uint32_t) DMATxDescTab;
}

#line 26 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\MCU.cpp"


#line 1 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Src/I2Cmaster_MCU.cpp"









 


#line 14 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Src/I2Cmaster_MCU.cpp"












cHwI2Cmaster_N::cHwI2Cmaster_N( I2C_ID id, 
                                MODE   mode,
                                BYTE   maskIntr )

: cHwI2Cmaster( maskIntr )

{
  switch( id )
  {  
    default:
      
      break;
      
    case I2C_1: 
      ptrBase       = (I2C_TypeDef*)(0x40000000U + 0x5400U); 
      ((RCC_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3800U))->APB1ENR |= (0x1U << (21U));
      cHwPinConfig::set( cHwPinConfig::I2C1_SCL, cHwPinConfig::OPEN_DRAIN );
      cHwPinConfig::set( cHwPinConfig::I2C1_SDA, cHwPinConfig::OPEN_DRAIN );
      break;
            
    case I2C_2: 
      ptrBase       = (I2C_TypeDef*)(0x40000000U + 0x5800U); 
      ((RCC_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3800U))->APB1ENR |= (0x1U << (22U));
      cHwPinConfig::set( cHwPinConfig::I2C2_SCL, cHwPinConfig::OPEN_DRAIN );
      cHwPinConfig::set( cHwPinConfig::I2C2_SDA, cHwPinConfig::OPEN_DRAIN );
      break;

    case I2C_3: 
      ptrBase       = (I2C_TypeDef*)(0x40000000U + 0x5C00U); 
      ((RCC_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3800U))->APB1ENR |= (0x1U << (23U));
      cHwPinConfig::set( cHwPinConfig::I2C3_SCL, cHwPinConfig::OPEN_DRAIN );
      cHwPinConfig::set( cHwPinConfig::I2C3_SDA, cHwPinConfig::OPEN_DRAIN );
      break;

    case I2C_4: 
      ptrBase       = (I2C_TypeDef*)(0x40000000U + 0x6000U); 
      ((RCC_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3800U))->APB1ENR |= (0x1U << (24U));
      cHwPinConfig::set( cHwPinConfig::I2C4_SCL, cHwPinConfig::OPEN_DRAIN);
      cHwPinConfig::set( cHwPinConfig::I2C4_SDA, cHwPinConfig::OPEN_DRAIN);
      break;
  }

	WORD presc [] = {0x0B, 0x0B, 0x05, 0x05};
	WORD scll  [] = {0xC7, 0x13, 0x09, 0x03};
	WORD sclh  [] = {0xC3, 0x0F, 0x03, 0x01};
	WORD sdadel[] = {0x02, 0x02, 0x03, 0x00};
	WORD scldel[] = {0x04, 0x04, 0x03, 0x01};
		
	BYTE idx;
  
	
  switch( mode )
  {
    default:
    case CR_10kHz:   idx = 0; break;
    case CR_100kHz:  idx = 1; break;
    case CR_400kHz:  idx = 2; break;
    case CR_1000kHz: idx = 3; break;
  } 
	ptrBase->TIMINGR =   (presc[idx] <<28)
	                   | (scldel[idx]<<20)
	                   | (sdadel[idx]<<16)
	                   | (sclh[idx]  << 8)
	                   | (scll[idx]  << 0);

  ptrBase->CR1 |= (0x1U << (12U)) | (0x1U << (0U)); 
}


BYTE cHwI2Cmaster_N::write( BYTE  hwAddr,
                            BYTE *addr,
                            BYTE  sizeAddr,
                            BYTE *data,
                            BYTE  sizeData )
{
  BYTE i = 0;
  
  isHardwareOK = true;

  if( maskIntr )
    cSystem::disableInterrupt();
	
	if( sizeAddr )
	{
		
		ptrBase->CR2 =   !(0x1U << (25U))
									 | !(0x1U << (24U))
									 |  (sizeAddr+sizeData)<<16
									 | !(0x1U << (11U))	
									 | !(0x1U << (10U))
									 |  ((hwAddr & 0xFE) ); 

		ptrBase->CR2 |= (0x1U << (13U));
		
    for( i=0; i< sizeAddr; i++ )
    {
			while( !(ptrBase->ISR & (0x1U << (1U))) );
      ptrBase->TXDR = addr[i];
    }
    for( i=0; i< sizeData; i++ )
    {
			while( !(ptrBase->ISR & (0x1U << (1U))) );
      ptrBase->TXDR = data[i];
    }
		while( !(ptrBase->ISR & (0x1U << (6U))) );
	}
	
  ptrBase->CR2 |= (0x1U << (14U));

  if( maskIntr )
    cSystem::enableInterrupt();

  return( !isHardwareOK );
}


BYTE cHwI2Cmaster_N::read( BYTE  hwAddr,
                           BYTE *addr,
                           BYTE  sizeAddr,
                           BYTE *data,
                           BYTE  sizeData )
{
  BYTE i = 0;
  
  isHardwareOK = true;

  if( maskIntr )
    cSystem::disableInterrupt();
	
	if( sizeAddr )
	{
		
		ptrBase->CR2 =   !(0x1U << (25U))
									 | !(0x1U << (24U))
									 |  (sizeAddr)<<16
									 | !(0x1U << (11U))	
									 | !(0x1U << (10U))
									 |  ((hwAddr & 0xFE) ); 

		ptrBase->CR2 |= (0x1U << (13U));
		
    for( i=0; i< sizeAddr; i++ )
    {
			while( !(ptrBase->ISR & (0x1U << (1U))) );
      ptrBase->TXDR = addr[i];
    }
		while( !(ptrBase->ISR & (0x1U << (6U))) );
	}
	
	ptrBase->CR2 =     !(0x1U << (25U))
									 | !(0x1U << (24U))
									 |  (sizeData)<<16
									 | !(0x1U << (11U))	
									 |  (0x1U << (10U))
									 |  ((hwAddr & 0xFE) ); 

  ptrBase->CR2 |= (0x1U << (13U));
	
	for( i=0; i< sizeData; i++ )
	{
		while( !(ptrBase->ISR & (0x1U << (2U))) );
		data[i] = ptrBase->RXDR;
	}
	while( !(ptrBase->ISR & (0x1U << (6U))) );

  ptrBase->CR2 |= (0x1U << (14U));
  
	if( maskIntr )
    cSystem::enableInterrupt();

  return( !isHardwareOK );
}


#line 29 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\MCU.cpp"

#line 1 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Src/Memory_Flash.cpp"







 


#line 12 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Src/Memory_Flash.cpp"







cHwMemory_Flash::cHwMemory_Flash( Sector sector )

: cHwMemory( (sector&0x0F)*0x8000, 
             0xFF ) 

{
  ptr            = (BYTE*)( (sector>>8)*0x8000 + 0x08000000 );
  sectorID       = (sector>>4)&0x0F;
  dataDoubleWord = 0;
  isFlashFlag    = true;
}


void cHwMemory_Flash::lock( ) 
{  
	((FLASH_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3C00U))->CR |= (0x1U << (31U));
	while( ((FLASH_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3C00U))->SR & (0x1U << (16U)) );
}
		

void cHwMemory_Flash::unlock() 
{
	while( ((FLASH_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3C00U))->SR & (0x1U << (16U)) );
		
	((FLASH_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3C00U))->KEYR = 0x45670123;
	((FLASH_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3C00U))->KEYR = 0xCDEF89AB;
		
	while( ((FLASH_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3C00U))->SR & (0x1U << (16U)) );
}
		

void cHwMemory_Flash::clear( DWORD offset )
{
  ((FLASH_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3C00U))->CR &= ~((0x1U << (16U)) | (0x1U << (1U)) | (0xf<<3)); 
  ((FLASH_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3C00U))->CR |=   (0x1U << (1U)) | (sectorID<<3); 
  
  ((FLASH_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3C00U))->CR |= (0x1U << (16U));
  
  while( ((FLASH_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3C00U))->SR & (0x1U << (16U)) );
  
  ((FLASH_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3C00U))->CR &= ~((0x1U << (16U)) | (0x1U << (1U)) | (0xf<<3)); 
}


void cHwMemory_Flash::writeByte( DWORD addr, BYTE data )
{
  ((FLASH_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3C00U))->CR |= (0x1U << (0U));
  
  ptr[addr] = data;
  
  while( ((FLASH_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3C00U))->SR & (0x1U << (16U)) );
}


BYTE cHwMemory_Flash::readByte( DWORD addr )
{
  return( ptr[addr] );
}


#line 31 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\MCU.cpp"

#line 1 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Src/Port_MCU.cpp"







 


#line 12 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Src/Port_MCU.cpp"







cHwPort_N::cHwPort_N( PortId portId ) 

: cHwPort()

{
  switch( portId )
  {
    default:
      
      break;
    case PA: ptr = (GPIO_TypeDef *)(((0x40000000U + 0x00020000U) + 0x0000U)); ((RCC_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3800U))->AHB1ENR |= ((1UL << 0) ); break;
    case PB: ptr = (GPIO_TypeDef *)(((0x40000000U + 0x00020000U) + 0x0400U)); ((RCC_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3800U))->AHB1ENR |= ((1UL << 1) ); break;
    case PC: ptr = (GPIO_TypeDef *)(((0x40000000U + 0x00020000U) + 0x0800U)); ((RCC_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3800U))->AHB1ENR |= ((1UL << 2) ); break;
    case PD: ptr = (GPIO_TypeDef *)(((0x40000000U + 0x00020000U) + 0x0C00U)); ((RCC_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3800U))->AHB1ENR |= ((1UL << 3) ); break;
    case PE: ptr = (GPIO_TypeDef *)(((0x40000000U + 0x00020000U) + 0x1000U)); ((RCC_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3800U))->AHB1ENR |= ((1UL << 4) ); break;
    case PF: ptr = (GPIO_TypeDef *)(((0x40000000U + 0x00020000U) + 0x1400U)); ((RCC_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3800U))->AHB1ENR |= ((1UL << 5) ); break;
    case PG: ptr = (GPIO_TypeDef *)(((0x40000000U + 0x00020000U) + 0x1800U)); ((RCC_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3800U))->AHB1ENR |= ((1UL << 6) ); break;
    case PH: ptr = (GPIO_TypeDef *)(((0x40000000U + 0x00020000U) + 0x1C00U)); ((RCC_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3800U))->AHB1ENR |= ((1UL << 7) ); break;
    case PI: ptr = (GPIO_TypeDef *)(((0x40000000U + 0x00020000U) + 0x2000U)); ((RCC_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3800U))->AHB1ENR |= ((1UL << 8) ); break;
    case PJ: ptr = (GPIO_TypeDef *)(((0x40000000U + 0x00020000U) + 0x2400U)); ((RCC_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3800U))->AHB1ENR |= ((1UL << 9) ); break;
  }
}


void cHwPort_N::setMode( MTYPE mask, Mode mode )
{
  for( BYTE i = 0; i < 16; i++, mask >>= 1 )
  {
    if( mask & 0x01 )
    {
      setPinMode( i, mode );
    }
  }
}


void cHwPort_N::setPinMode( BYTE pinId, Mode mode )
{
  BYTE  pinId2 = pinId << 1;

  MTYPE bitmask  = ~((MTYPE)0x01 << pinId  );
  MTYPE bitmask2 = ~((MTYPE)0x03 << pinId2 );

  MTYPE moder  = 0;
  MTYPE pupdr  = 0;
  MTYPE otyper = 0;
  
  if( mode & cHwPort::Out ) moder   = (MTYPE)0x01<< pinId2;
  if( mode & cHwPort::PU  ) pupdr  |= (MTYPE)0x01<< pinId2;
  if( mode & cHwPort::PD  ) pupdr  |= (MTYPE)0x02<< pinId2;
  if( mode & cHwPort::OD  ) otyper  = (MTYPE)0x01<< pinId;

  cSystem::disableInterrupt();
  ptr->MODER     = ( ptr->MODER     & bitmask2 ) | moder;
  ptr->PUPDR     = ( ptr->PUPDR     & bitmask2 ) | pupdr;
  ptr->OTYPER    = ( ptr->OTYPER    & bitmask  ) | otyper;
  cSystem::enableInterrupt();
}


#line 33 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\MCU.cpp"
#line 1 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Src/RTC_MCU.cpp"







 


#line 12 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Src/RTC_MCU.cpp"







cHwRTC_0::cHwRTC_0( RTC_ClockConfig_t config )
{
  ((PWR_TypeDef *) (0x40000000U + 0x7000U))->CR1 |= (0x1U << (8U));


	if( config == LSE )
	{
  ((RCC_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3800U))->BDCR &= ~(0x03<<8); 
  ((RCC_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3800U))->BDCR |=  (   1<<15) 
               |(0x01<< 8)  
               |(1<<0); 
	}
	else if(config == LSI)
	{
		if( !(((RCC_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3800U))->BDCR & (3<<8)) ) 
		{
			((RCC_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3800U))->BDCR |=  (0x01<<16); 
			((RCC_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3800U))->BDCR &= ~(0x01<<16); 
		}
  	((RCC_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3800U))->BDCR &= ~(0x03<<8); 
		((RCC_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3800U))->BDCR |=  (   1<<15) 
									 |(0x03<< 8)  
									 |(1<<0); 
	}

  ((RCC_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3800U))->CFGR &= ~(0x1F<<16);
  ((RCC_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3800U))->CFGR |=  ( (25000/1000)<<16);    

  
  ((RTC_TypeDef *) (0x40000000U + 0x2800U))->WPR = 0xCA;
  ((RTC_TypeDef *) (0x40000000U + 0x2800U))->WPR = 0x53;

  
  ((RTC_TypeDef *) (0x40000000U + 0x2800U))->ISR |= (0x1U << (7U));

  while( !(((RTC_TypeDef *) (0x40000000U + 0x2800U))->ISR & (0x1U << (6U))) );

  
if( config == LSE )
	{
  
  
	}
	else if( config == LSI )
	{

    ((RTC_TypeDef *) (0x40000000U + 0x2800U))->PRER  = ((MTYPE)(8000-1)<< 0); 
    ((RTC_TypeDef *) (0x40000000U + 0x2800U))->PRER |= ((MTYPE)(  125-1)<<16); 
	}
  
  
  ((RTC_TypeDef *) (0x40000000U + 0x2800U))->ISR &= ~(0x1U << (7U));

 






















 
}


void cHwRTC_0::set( const cHwRTC::Properties &clock )
{
  BYTE dow;

  
  ((RTC_TypeDef *) (0x40000000U + 0x2800U))->WPR = 0xCA;
  ((RTC_TypeDef *) (0x40000000U + 0x2800U))->WPR = 0x53;

  
  ((RTC_TypeDef *) (0x40000000U + 0x2800U))->ISR |= (0x1U << (7U));

  while( !(((RTC_TypeDef *) (0x40000000U + 0x2800U))->ISR & (0x1U << (6U))) );

  if( clock.dow == 0 )
  {
    dow = getDayOfWeek( clock.day, clock.month, clock.year );
  }
  else
  {
    dow = clock.dow;
  }

   WORD year = clock.year%100;

  ((RTC_TypeDef *) (0x40000000U + 0x2800U))->TR =  ((DWORD)((clock.second%10)&0xF) << 0)
            |((DWORD)((clock.second/10)&0x7) << 4)
            |((DWORD)((clock.minute%10)&0xF) << 8)
            |((DWORD)((clock.minute/10)&0x7) <<12)
            |((DWORD)((clock.hour  %10)&0xF) <<16)
            |((DWORD)((clock.hour  /10)&0x3) <<20);

  ((RTC_TypeDef *) (0x40000000U + 0x2800U))->DR =  ((DWORD)((clock.day  %10)&0xF) << 0)
            |((DWORD)((clock.day  /10)&0x3) << 4)
            |((DWORD)((clock.month%10)&0xF) << 8)
            |((DWORD)((clock.month/10)&0x1) <<12)
            |((DWORD)((dow  % 8)&0x7) <<13)
            |((DWORD)((year %10)&0xF) <<16)
            |((DWORD)((year /10)&0xF) <<20);

  
  ((RTC_TypeDef *) (0x40000000U + 0x2800U))->ISR &= ~(0x1U << (7U));
}


BYTE cHwRTC_0::get( cHwRTC::Properties &clock )
{
   BYTE sec;

  clock.second = (BYTE)(((((RTC_TypeDef *) (0x40000000U + 0x2800U))->TR >> 0)&0xF) + 10*((((RTC_TypeDef *) (0x40000000U + 0x2800U))->TR >> 4)&0x7));
  clock.minute = (BYTE)(((((RTC_TypeDef *) (0x40000000U + 0x2800U))->TR >> 8)&0xF) + 10*((((RTC_TypeDef *) (0x40000000U + 0x2800U))->TR >>12)&0x7));
  clock.hour   = (BYTE)(((((RTC_TypeDef *) (0x40000000U + 0x2800U))->TR >>16)&0xF) + 10*((((RTC_TypeDef *) (0x40000000U + 0x2800U))->TR >>20)&0x3));

  clock.dow    = (BYTE)(((((RTC_TypeDef *) (0x40000000U + 0x2800U))->DR >>13)&0x7)                          );

  clock.day    = (BYTE)(((((RTC_TypeDef *) (0x40000000U + 0x2800U))->DR >> 0)&0xF) + 10*((((RTC_TypeDef *) (0x40000000U + 0x2800U))->DR >> 4)&0x3));
  clock.month  = (BYTE)(((((RTC_TypeDef *) (0x40000000U + 0x2800U))->DR >> 8)&0xF) + 10*((((RTC_TypeDef *) (0x40000000U + 0x2800U))->DR >>12)&0x1));
  clock.year   = (BYTE)(((((RTC_TypeDef *) (0x40000000U + 0x2800U))->DR >>16)&0xF) + 10*((((RTC_TypeDef *) (0x40000000U + 0x2800U))->DR >>20)&0xF));

  
  sec          = (BYTE)(((((RTC_TypeDef *) (0x40000000U + 0x2800U))->TR >> 0)&0xF) + 10*((((RTC_TypeDef *) (0x40000000U + 0x2800U))->TR >> 4)&0x7));

 clock.year += 2000;

  return( (clock.second <= sec) ? true : false );
}


#line 34 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\MCU.cpp"

#line 1 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Src/Timer_MCU.cpp"







 


#line 12 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Src/Timer_MCU.cpp"












cHwTimer_N *cHwTimer_N::timerPtr_1 = 0;
cHwTimer_N *cHwTimer_N::timerPtr_2 = 0;
cHwTimer_N *cHwTimer_N::timerPtr_3 = 0;
cHwTimer_N *cHwTimer_N::timerPtr_4 = 0;
cHwTimer_N *cHwTimer_N::timerPtr_5 = 0;
cHwTimer_N *cHwTimer_N::timerPtr_7 = 0;
cHwTimer_N *cHwTimer_N::timerPtr_8 = 0;
cHwTimer_N *cHwTimer_N::timerPtr_9 = 0;
cHwTimer_N *cHwTimer_N::timerPtr_10 = 0;
cHwTimer_N *cHwTimer_N::timerPtr_11 = 0;
cHwTimer_N *cHwTimer_N::timerPtr_14 = 0;


cHwTimer_N::cHwTimer_N( TimerId timerIdIn,
                        DWORD   cycleTimeIn )

: cHwTimer()

{
  timerId = timerIdIn;

  switch( timerId )
  {
     default:
      
      break;

   case TIM_1:
      ptr           = (TIM_TypeDef*)((0x40000000U + 0x00010000U) + 0x0000U);
      timerPtr_1    = this;
      ((RCC_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3800U))->APB2ENR |= (0x1U << (0U));
      __NVIC_EnableIRQ( TIM1_UP_TIM10_IRQn );
      break;

    case TIM_2:
      ptr           = (TIM_TypeDef*)(0x40000000U + 0x0000U);
      timerPtr_2    = this;
      ((RCC_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3800U))->APB1ENR |= (0x1U << (0U));
      __NVIC_EnableIRQ( TIM2_IRQn );
      break;

    case TIM_3:
      ptr           = (TIM_TypeDef*)(0x40000000U + 0x0400U);
      timerPtr_3    = this;
      ((RCC_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3800U))->APB1ENR |= (0x1U << (1U));
      __NVIC_EnableIRQ( TIM3_IRQn );
      break;

    case TIM_4:
      ptr           = (TIM_TypeDef*)(0x40000000U + 0x0800U);
      timerPtr_4    = this;
      ((RCC_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3800U))->APB1ENR |= (0x1U << (2U));
      __NVIC_EnableIRQ( TIM4_IRQn );
      break;

    case TIM_5:
      ptr           = (TIM_TypeDef*)(0x40000000U + 0x0C00U);
      timerPtr_5    = this;
      ((RCC_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3800U))->APB1ENR |= (0x1U << (3U));
      __NVIC_EnableIRQ( TIM5_IRQn );
      break;

    case TIM_7:
      ptr           = (TIM_TypeDef*)(0x40000000U + 0x1400U);
      timerPtr_7    = this;
      ((RCC_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3800U))->APB1ENR |= (0x1U << (5U));
      __NVIC_EnableIRQ( TIM7_IRQn );
      break;

    case TIM_8:
      ptr           = (TIM_TypeDef*)((0x40000000U + 0x00010000U) + 0x0400U);
      timerPtr_8    = this;
      ((RCC_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3800U))->APB2ENR |= (0x1U << (1U));
      __NVIC_EnableIRQ( TIM8_CC_IRQn );
      break;

    case TIM_9:
      ptr           = (TIM_TypeDef*)((0x40000000U + 0x00010000U) + 0x4000U);
      timerPtr_9    = this;
      ((RCC_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3800U))->APB2ENR |= (0x1U << (16U));
      
      
      break;

    case TIM_10:
      ptr           = (TIM_TypeDef*)((0x40000000U + 0x00010000U) + 0x4400U);
      timerPtr_10    = this;
      ((RCC_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3800U))->APB2ENR |= (0x1U << (17U));
      
      
      break;

    case TIM_11:
      ptr           = (TIM_TypeDef*)((0x40000000U + 0x00010000U) + 0x4800U);
      timerPtr_11    = this;
      ((RCC_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3800U))->APB2ENR |= (0x1U << (18U));
      
      
      break;

    case TIM_14:
      ptr           = (TIM_TypeDef*)(0x40000000U + 0x2000U);
      timerPtr_14    = this;
      ((RCC_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3800U))->APB1ENR |= (0x1U << (8U));
      
      
      break;
  }

  
  float rawTics = 2.0*((200000000)/4) * cycleTimeIn * 1E-6f;
  DWORD ps      = 1;
  while( rawTics > 0xFFFF ) 
  {
    ps      *= 10;
    rawTics /= 10;
  }

  tics      = (DWORD)rawTics;
  cycleTime = (DWORD)(1E6 * tics * ps / (2.0*((200000000)/4)) );

  ptr->DIER = (0x1U << (0U)); 
  ptr->EGR  = (0x1U << (0U));   
  ptr->PSC  = ps - 1;
  ptr->ARR  = tics;
  ptr->CR1  = (0x1U << (0U));  
}


void cHwTimer_N::enablePWM( BYTE channel, Mode polarity )
{
  switch( timerId )
  {
    case TIM_1:
      switch( channel )
      {
        case 0: cHwPinConfig::set( cHwPinConfig::TIM1_CH1     ); break;
        case 1: cHwPinConfig::set( cHwPinConfig::TIM1_CH2     ); break;
        case 2: cHwPinConfig::set( cHwPinConfig::TIM1_CH3     ); break;
        case 3: cHwPinConfig::set( cHwPinConfig::TIM1_CH4     ); break;
      }
      ((TIM_TypeDef *) ((0x40000000U + 0x00010000U) + 0x0000U))->BDTR |= (1<<15); 
      break;

    case TIM_2:
      switch( channel )
      {
        case 0: cHwPinConfig::set( cHwPinConfig::TIM2_CH1     ); break;
        case 1: cHwPinConfig::set( cHwPinConfig::TIM2_CH2     ); break;
        case 2: cHwPinConfig::set( cHwPinConfig::TIM2_CH3     ); break;
        case 3: cHwPinConfig::set( cHwPinConfig::TIM2_CH4     ); break;
      }
      break;

    case TIM_3:
      switch( channel )
      {
        case 0: cHwPinConfig::set( cHwPinConfig::TIM3_CH1     ); break;
        case 1: cHwPinConfig::set( cHwPinConfig::TIM3_CH2     ); break;
        case 2: cHwPinConfig::set( cHwPinConfig::TIM3_CH3     ); break;
        case 3: cHwPinConfig::set( cHwPinConfig::TIM3_CH4     ); break;
      }
      break;

    case TIM_4:
      switch( channel )
      {
        case 0: cHwPinConfig::set( cHwPinConfig::TIM4_CH1     ); break;
        case 1: cHwPinConfig::set( cHwPinConfig::TIM4_CH2     ); break;
        case 2: cHwPinConfig::set( cHwPinConfig::TIM4_CH3     ); break;
        case 3: cHwPinConfig::set( cHwPinConfig::TIM4_CH4     ); break;
      }
      break;

    case TIM_5:
      switch( channel )
      {
        case 0: cHwPinConfig::set( cHwPinConfig::TIM5_CH1     ); break;
        case 1: cHwPinConfig::set( cHwPinConfig::TIM5_CH2     ); break;
        case 2: cHwPinConfig::set( cHwPinConfig::TIM5_CH3     ); break;
        case 3: cHwPinConfig::set( cHwPinConfig::TIM5_CH4     ); break;
      }
      break;

    case TIM_7:
      switch( channel )
      {




      }
      break;

    case TIM_8:
      switch( channel )
      {
        case 0: cHwPinConfig::set( cHwPinConfig::TIM8_CH1     ); break;
        case 1: cHwPinConfig::set( cHwPinConfig::TIM8_CH2     ); break;
        case 2: cHwPinConfig::set( cHwPinConfig::TIM8_CH3     ); break;
        case 3: cHwPinConfig::set( cHwPinConfig::TIM8_CH4     ); break;
      }
      ((TIM_TypeDef *) ((0x40000000U + 0x00010000U) + 0x0400U))->BDTR |= (1<<15); 
      break;

    case TIM_9:
      switch( channel )
      {
        case 0: cHwPinConfig::set( cHwPinConfig::TIM9_CH1     ); break;
        case 1: cHwPinConfig::set( cHwPinConfig::TIM9_CH2     ); break;
      }
      break;

    case TIM_10:
      switch( channel )
      {
        case 0: cHwPinConfig::set( cHwPinConfig::TIM10_CH1     ); break;
      }
      ((TIM_TypeDef *) ((0x40000000U + 0x00010000U) + 0x4400U))->BDTR |= (1<<15); 
      break;

    case TIM_11:
      switch( channel )
      {
        case 0: cHwPinConfig::set( cHwPinConfig::TIM11_CH1     ); break;
      }
      ((TIM_TypeDef *) ((0x40000000U + 0x00010000U) + 0x4800U))->BDTR |= (1<<15); 
      break;

    case TIM_14:
      switch( channel )
      {
        case 0: cHwPinConfig::set( cHwPinConfig::TIM14_CH1     ); break;
      }
      break;

    default:
      
      break;
  }

  WORD ccmr =  (7<<4)  
              |(1<<3); 

  WORD ccer = 0;
  if( polarity )
  {
   ccer =  (1<<2)  
              |(1<<3); 
  }
  else
  {
   ccer =  (1<<0)  
              |(1<<1); 
  }
  switch( channel )
  {
    case 0:
      ptr->CCMR1 |=  ccmr;
      ptr->CCER  |=  ccer;
      break;

    case 1:
      ptr->CCMR1 |=  ccmr<<8;
      ptr->CCER  |=  ccer<<4;
      break;

    case 2:
      ptr->CCMR2 |=  ccmr;
      ptr->CCER  |=  ccer<<8;
      break;

    case 3:
      ptr->CCMR2 |=  ccmr<<8;
      ptr->CCER  |=  ccer<<12;
      break;
  }
}


void cHwTimer_N::setPWM( WORD value, BYTE ch )
{
  value = (WORD)((DWORD)value*tics >> 16);

  switch( ch )
  {
    case 0: ptr->CCR1  = value; break;
    case 1: ptr->CCR2  = value; break;
    case 2: ptr->CCR3  = value; break;
    case 3: ptr->CCR4  = value; break;
  }
}


void cHwTimer_N::isr_N(void)
{
 
  ptr->SR = 0;
  isrHandler();
}


extern "C" {
  void TIM1_UP_TIM10_IRQHandler(void)
		
  {
    if( ((TIM_TypeDef *) ((0x40000000U + 0x00010000U) + 0x0000U))->SR & (0x1U << (0U)) )
		{
			cHwTimer_N::timerPtr_1->isr_N();
			((TIM_TypeDef *) ((0x40000000U + 0x00010000U) + 0x0000U))->SR = 0;
		}
		else if( ((TIM_TypeDef *) ((0x40000000U + 0x00010000U) + 0x4400U))->SR )
		{
			((TIM_TypeDef *) ((0x40000000U + 0x00010000U) + 0x4400U))->SR=0;
		}
  }
}


extern "C" {
  void TIM2_IRQHandler(void)
  {
    cHwTimer_N::timerPtr_2->isr_N();
  }
}


extern "C" {
  void TIM3_IRQHandler(void)
  {
    cHwTimer_N::timerPtr_3->isr_N();
  }
}


extern "C" {
  void TIM4_IRQHandler(void)
  {
    cHwTimer_N::timerPtr_4->isr_N();
  }
}


extern "C" {
  void TIM5_IRQHandler(void)
  {
    cHwTimer_N::timerPtr_5->isr_N();
  }
}


extern "C" {
  void TIM7_IRQHandler(void)
  {
    cHwTimer_N::timerPtr_7->isr_N();
  }
}


extern "C" {
  void TIM8_CC_IRQHandler(void)
  {
    cHwTimer_N::timerPtr_8->isr_N();
  }
}




#line 36 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\MCU.cpp"
#line 1 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Src/UART_MCU.cpp"







 


#line 12 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Src/UART_MCU.cpp"












cHwUART_N *cHwUART_N::uartPtr_1 = 0;
cHwUART_N *cHwUART_N::uartPtr_2 = 0;
cHwUART_N *cHwUART_N::uartPtr_3 = 0;
cHwUART_N *cHwUART_N::uartPtr_4 = 0;
cHwUART_N *cHwUART_N::uartPtr_5 = 0;
cHwUART_N *cHwUART_N::uartPtr_6 = 0;


cHwUART_N::cHwUART_N( USART_Id id,
                      DWORD    mode,
                      BYTE     sizeRxBuf,
                      BYTE     sizeTxBuf )

: cHwUART( sizeRxBuf, sizeTxBuf )

{
  switch( id )
  {
    default:
      
      break;
    
    case USART_1:
      ptr           = (USART_TypeDef*)((0x40000000U + 0x00010000U) + 0x1000U);
      uartPtr_1     = this;
      ((RCC_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3800U))->APB2ENR |= (0x1U << (4U));  
      cHwPinConfig::set( cHwPinConfig::USART1_RX );
      cHwPinConfig::set( cHwPinConfig::USART1_TX );
      if( mode & RTS )
      {
        cHwPinConfig::set( cHwPinConfig::USART1_RTS );
      }
      if( mode & CTS )
      {
        cHwPinConfig::set( cHwPinConfig::USART1_CTS );
      }
      __NVIC_EnableIRQ( USART1_IRQn );
      break;

  case USART_2:
      ptr           = (USART_TypeDef*)(0x40000000U + 0x4400U);
      uartPtr_2     = this;
      ((RCC_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3800U))->APB1ENR |= (0x1U << (17U));  
      cHwPinConfig::set( cHwPinConfig::USART2_RX );
      cHwPinConfig::set( cHwPinConfig::USART2_TX );
      if( mode & RTS )
      {
        cHwPinConfig::set( cHwPinConfig::USART2_RTS );
      }
      if( mode & CTS )
      {
        cHwPinConfig::set( cHwPinConfig::USART2_CTS );
      }
      __NVIC_EnableIRQ( USART2_IRQn );
      break;

    case USART_3:
      ptr           = (USART_TypeDef*)(0x40000000U + 0x4800U);
      uartPtr_3     = this;
      ((RCC_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3800U))->APB1ENR |= (0x1U << (18U));  
      cHwPinConfig::set( cHwPinConfig::USART3_RX );
      cHwPinConfig::set( cHwPinConfig::USART3_TX );
      if( mode & RTS )
      {
        cHwPinConfig::set( cHwPinConfig::USART3_RTS );
      }
      if( mode & CTS )
      {
        cHwPinConfig::set( cHwPinConfig::USART3_CTS );
      }
      __NVIC_EnableIRQ( USART3_IRQn );
      break;

    case UART_4:
      ptr           = (USART_TypeDef*)(0x40000000U + 0x4C00U);
      uartPtr_4     = this;
      ((RCC_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3800U))->APB1ENR |= (0x1U << (19U));  
      cHwPinConfig::set( cHwPinConfig::UART4_RX );
      cHwPinConfig::set( cHwPinConfig::UART4_TX );
      if( mode & RTS )
      {
       
      }
      if( mode & CTS )
      {
        
      }
      __NVIC_EnableIRQ( UART4_IRQn );
      break;

    case UART_5:
      ptr           = (USART_TypeDef*)(0x40000000U + 0x5000U);
      uartPtr_5     = this;
      ((RCC_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3800U))->APB1ENR |= (0x1U << (20U));  
      cHwPinConfig::set( cHwPinConfig::UART5_RX );
      cHwPinConfig::set( cHwPinConfig::UART5_TX );
      if( mode & RTS )
      {
       
      }
      if( mode & CTS )
      {
        
      }
      __NVIC_EnableIRQ( UART5_IRQn );
      break;

    case USART_6:
      ptr           = (USART_TypeDef*)((0x40000000U + 0x00010000U) + 0x1400U);
      uartPtr_6     = this;
      ((RCC_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3800U))->APB2ENR |= (0x1U << (5U));  
      cHwPinConfig::set( cHwPinConfig::USART6_RX );
      cHwPinConfig::set( cHwPinConfig::USART6_TX );
      if( mode & RTS )
      {
        cHwPinConfig::set( cHwPinConfig::USART6_RTS );
      }
      if( mode & CTS )
      {
        cHwPinConfig::set( cHwPinConfig::USART6_CTS );
      }

      __NVIC_EnableIRQ( USART6_IRQn );
      break;
  }

  DWORD baudRate;

  switch( mode & 0xFFFF )
  {
    default:
    case BR_2400:   baudRate =   2400; break;
    case BR_4800:   baudRate =   4800; break;
    case BR_9600:   baudRate =   9600; break;
    case BR_19200:  baudRate =  19200; break;
    case BR_38400:  baudRate =  38400; break;
    case BR_57600:  baudRate =  57600; break;
    case BR_115200: baudRate = 115200; break;
    case BR_230400: baudRate = 230400; break;
    case BR_460800: baudRate = 460800; break;
  }

  ptr->CR2 |=  ((MTYPE)0<<12); 

  ptr->CR1 |=  (        ((mode&(EVEN|ODD))?(0x10001U << (12U))  :0)  
                     |  ((mode&(EVEN|ODD))?(0x1U << (10U)):0)  
                     |  ((mode&      ODD )?(0x1U << (9U)) :0)  
                     |  (0x1U << (2U))   
                     |  (0x1U << (3U)) );

  ptr->CR3 |=  (  ((mode&RTS)?(0x1U << (8U)):0)
                | ((mode&CTS)?(0x1U << (9U)):0) ); 

  
  
  
  
  
  
  
  
  
  
  ptr->BRR  = (WORD)(((200000000)/4) / baudRate);

  ptr->CR1 |= (  (0x1U << (0U))       
               | (0x1U << (6U))     
               | (0x1U << (5U)) );
}


inline BYTE cHwUART_N::getByte( void )
{
  return( ptr->RDR );
}


inline void cHwUART_N::setByte( BYTE c )
{
  ptr->TDR = c;
}


void cHwUART_N::isr( void )
{
  if( ptr->ISR & (0x1U << (6U)) ) 
  {
    ptr->ICR |= (0x1U << (6U));
    isrTx();
  }
  if( ptr->ISR & (0x1U << (5U)) ) 
  {
    isrRx();
  }
}


extern "C"
{
  void USART1_IRQHandler(void)
  {
    cHwUART_N::uartPtr_1->isr();
  }
}


extern "C"
{
  void USART2_IRQHandler(void)
  {
    cHwUART_N::uartPtr_2->isr();
  }
}


extern "C"
{
  void USART3_IRQHandler(void)
  {
    cHwUART_N::uartPtr_3->isr();
  }
}


extern "C"
{
  void UART4_IRQHandler(void)
  {
    cHwUART_N::uartPtr_4->isr();
  }
}


extern "C"
{
  void UART5_IRQHandler(void)
  {
    cHwUART_N::uartPtr_5->isr();
  }
}


extern "C"
{
  void USART6_IRQHandler(void)
  {
    cHwUART_N::uartPtr_6->isr();
  }
}

#line 37 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\MCU.cpp"
#line 1 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Src/USB_MCU.cpp"










 


#line 15 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\Src/USB_MCU.cpp"











cHwUSB_0::EndpointIN::EndpointIN( void )
{
}
  

void cHwUSB_0::EndpointIN::init( BYTE numIn )
{
  num  = numIn;
  inep = ((USB_OTG_INEndpointTypeDef *)((DWORD)((USB_OTG_GlobalTypeDef *) 0x50000000U) + 0x900U  + (num)*0x20U));
  fifo = (volatile DWORD                 *)((DWORD)((USB_OTG_GlobalTypeDef *) 0x50000000U) + 0x1000U         + (num)*0x1000U   );
}


void cHwUSB_0::EndpointIN::config( WORD epMPS, BYTE epType )
{
  txBuf.maxpacket = epMPS;
  
  if( num == 0 )
  {
    epMPS = 0; 
  }
  ((USB_OTG_DeviceTypeDef *)((DWORD)((USB_OTG_GlobalTypeDef *) 0x50000000U) + 0x800U ))->DAINTMSK |= (0xFFFFU << (0U)) & ((1 << (num)));

  if( !(inep->DIEPCTL & (0x1U << (15U))) )
  {
    inep->DIEPCTL |= (  (epMPS & (0x7FFU << (0U)) ) 
                      | (epType << 18 ) 
                      | (num    << 22 ) 
                      | (0x1U << (28U)) 
                      | (0x1U << (15U)) ); 
  } 
}


void cHwUSB_0::EndpointIN::flush( void )
{
  DWORD count = 200000;
  
  ((USB_OTG_GlobalTypeDef *) 0x50000000U)->GRSTCTL = (0x1U << (5U)) | (num << 5);
  
  while(    (((USB_OTG_GlobalTypeDef *) 0x50000000U)->GRSTCTL & (0x1U << (5U))) 
         && (count--) );
}
 

void cHwUSB_0::EndpointIN::reset()
{
  inep->DIEPINT = 0xFF;
}


void cHwUSB_0::EndpointIN::start()
{
  if( inep->DIEPCTL & (0x1U << (31U)) )
  {
    inep->DIEPCTL = (  (0x1U << (30U)) 
                     | (0x1U << (27U))  );
  }
  else
  {
    inep->DIEPCTL = 0;
  }
  inep->DIEPTSIZ = 0;
  inep->DIEPINT  = 0xFF;        
}


void cHwUSB_0::EndpointIN::setStall( void )
{
  if( !(inep->DIEPCTL & (0x1U << (31U))) )
  {
    inep->DIEPCTL &= ~((0x1U << (30U))); 
  } 
  inep->DIEPCTL |= (0x1U << (21U));
}


void cHwUSB_0::EndpointIN::clrStall( void ) 
{
  inep->DIEPCTL &= ~(0x1U << (21U));
  inep->DIEPCTL |=  (0x1U << (28U));
}


WORD cHwUSB_0::EndpointIN::write( BYTE *dataPtr, WORD len )
{
  len = MIN( len, (WORD)128 );
  
  for(WORD i = 0; i < len; i++ )
  {
    txBuf.data[i] = dataPtr[i];
  }
  txBuf.size = len;
  txBuf.flag = true;
  
  return( len );
}


void cHwUSB_0::EndpointIN::writeToFifo( void )
{
  WORD len = MIN( txBuf.size, txBuf.maxpacket );
  WORD cnt = (len + 3) / 4;
 
  if( (inep->DTXFSTS & (0xFFFFU << (0U))) >= cnt )
  {
    __packed DWORD *src = (__packed DWORD *)&txBuf.data[0];
    
    txBuf.size = 0;
    txBuf.flag = false;
    
    for( WORD i = 0; i < cnt; i++, src ++)
    {      
      *fifo = *src;
    }
  }
  
  if( len <= 0 )
  {
    ((USB_OTG_DeviceTypeDef *)((DWORD)((USB_OTG_GlobalTypeDef *) 0x50000000U) + 0x800U ))->DIEPEMPMSK &= ~(0x1 << num);
  }    
}


void cHwUSB_0::EndpointIN::transmit( bool flag )
{
  WORD mps  = txBuf.maxpacket;
  WORD len  = MIN( txBuf.size, txBuf.maxpacket );

  if( !txBuf.flag )
  {
    transmitZLP();
    return;
  }

  if( len == 0 ) 
  {
    if( flag )
    {
      transmitZLP();
    }
  }
  else
  {
    BYTE pktCnt =  ((len + mps -1)/ mps);
    
    inep->DIEPTSIZ &= ~(   (0x3FFU << (19U))
                         | (0x7FFFFU << (0U)) );
    
    inep->DIEPTSIZ |=  (  ((0x3FFU << (19U)) & (pktCnt << 19))
                         |((0x7FFFFU << (0U)) & len) ); 
    
    ((USB_OTG_DeviceTypeDef *)((DWORD)((USB_OTG_GlobalTypeDef *) 0x50000000U) + 0x800U ))->DIEPEMPMSK |= 1 << num; 

    inep->DIEPCTL  |=  (   (0x1U << (26U)) 
                         | (0x1U << (31U)) ); 
  }
}


void cHwUSB_0::EndpointIN::transmitZLP( void )
{
    inep->DIEPTSIZ &= ~(   (0x3FFU << (19U))
                         | (0x7FFFFU << (0U)) );
    
    inep->DIEPTSIZ |=  (   (0x3FFU << (19U)) & (1 << 19) ); 

    inep->DIEPCTL  |=  (   (0x1U << (26U)) 
                         | (0x1U << (31U)) ); 
}


DWORD cHwUSB_0::EndpointIN::getInterrupt( void )
{
  DWORD msk = ((USB_OTG_DeviceTypeDef *)((DWORD)((USB_OTG_GlobalTypeDef *) 0x50000000U) + 0x800U ))->DIEPMSK | (((((USB_OTG_DeviceTypeDef *)((DWORD)((USB_OTG_GlobalTypeDef *) 0x50000000U) + 0x800U ))->DIEPEMPMSK >> num) & 0x1) << 7);

  return( inep->DIEPINT & msk );
}


void cHwUSB_0::EndpointIN::clrInterrupt( DWORD interruptID )
{
  inep->DIEPINT = interruptID;  
}







cHwUSB_0::EndpointOUT::EndpointOUT( void )
{
}


void cHwUSB_0::EndpointOUT::init( BYTE numIn )
{
  num   = numIn;
  outep = ((USB_OTG_OUTEndpointTypeDef *)((DWORD)((USB_OTG_GlobalTypeDef *) 0x50000000U) + 0xB00U + (num)*0x20U));
  fifo  = (volatile DWORD                  *)((DWORD)((USB_OTG_GlobalTypeDef *) 0x50000000U) + 0x1000U         + (num)*0x1000U   );
}
 

void cHwUSB_0::EndpointOUT::config( WORD epMPS, BYTE epType )
{
  rxBuf.maxpacket = epMPS;

  if( num == 0 )
  {
    epMPS = 0; 
  }
  
  ((USB_OTG_DeviceTypeDef *)((DWORD)((USB_OTG_GlobalTypeDef *) 0x50000000U) + 0x800U ))->DAINTMSK |= (0xFFFFU << (16U)) & ((1 << (num)) << 16);
  
  if( !(outep->DOEPCTL & (0x1U << (15U))) )
  {
    outep->DOEPCTL |= (  (epMPS & (0x7FFU << (0U)) ) 
                       | (epType << 18 ) 
                       | ((0x1U << (28U)))
                       | ((0x1U << (15U))));
  }
  
  if( num > 0 )
  {
    receive();
  }
}


void cHwUSB_0::EndpointOUT::flush( void )
{
  DWORD count = 200000;
 
  ((USB_OTG_GlobalTypeDef *) 0x50000000U)->GRSTCTL = (0x1U << (4U));
  
  while(    (((USB_OTG_GlobalTypeDef *) 0x50000000U)->GRSTCTL & (0x1U << (4U))) 
         && (count--) );
}


void cHwUSB_0::EndpointOUT::reset()
{
  outep->DOEPINT = 0xFF;
}


void cHwUSB_0::EndpointOUT::start()
{
  if( outep->DOEPCTL & (0x1U << (31U)) )
  {
    outep->DOEPCTL = (   (0x1U << (30U)) 
                       | (0x1U << (27U))  );
  }
  else
  {
    outep->DOEPCTL = 0;
  }
  
  if( num == 0 )  
  {
    outep->DOEPTSIZ =   ((0x3FFU << (19U)) & (1 << 19))
                      | MAX_EP0_SIZE
                      | (0x3U << (29U));
  }
  else
  {
    outep->DOEPTSIZ = 0;
    outep->DOEPINT  = 0xFF;
  }
}


void cHwUSB_0::EndpointOUT::setStall( void )
{
  
  if( !(outep->DOEPCTL & (0x1U << (31U)))  )
  {
    outep->DOEPCTL &= ~((0x1U << (30U))); 
  } 
  outep->DOEPCTL |= (0x1U << (21U));

  if( num == 0 )
  {
    outep->DOEPTSIZ = ( ((0x3FFU << (19U)) & (1 << 19))
                       | MAX_EP0_SIZE
                       | (0x3U << (29U)) );  
  }
}


void cHwUSB_0::EndpointOUT::clrStall( void ) 
{
  outep->DOEPCTL &= ~(0x1U << (21U));
  outep->DOEPCTL |=  (0x1U << (28U));
}


WORD cHwUSB_0::EndpointOUT::read( BYTE *dataPtr, WORD len )
{
  len = MIN( len, (WORD)rxBuf.size );
  
  for( WORD i = 0; i < len; i++ )
  {
    dataPtr[i] = rxBuf.data[i];
  }
  rxBuf.size = 0;
  rxBuf.flag = false;

  return( len );
}


void cHwUSB_0::EndpointOUT::readFromFifo( WORD len )
{
  WORD cnt = (len + 3) / 4;

  __packed DWORD *dest = (__packed DWORD *)&rxBuf.data[0];

  rxBuf.size = len;
  rxBuf.flag = true;
  
  for( WORD  i = 0; i < cnt; i++, dest++ )
  {
    *dest = *fifo;    
  }
}


void cHwUSB_0::EndpointOUT::receive( void )
{
  WORD mps = rxBuf.maxpacket;
  WORD len = MIN( rxBuf.size, rxBuf.maxpacket );

  if( len == 0 )
  {
    receiveZLP();
  }
  else
  {
   BYTE pktcnt = (rxBuf.size + mps -1)/ mps;
    
   outep->DOEPTSIZ  &= ~(   (0x3FFU << (19U)) 
                          | (0x7FFFFU << (0U)) );
    
    outep->DOEPTSIZ |=  (  ((0x3FFU << (19U)) & (pktcnt << 19))
                          |((0x7FFFFU << (0U)) & (mps * pktcnt)) ); 
  
    outep->DOEPCTL  |=  (   (0x1U << (26U)) 
                          | (0x1U << (31U)) );  
  }
}


void cHwUSB_0::EndpointOUT::receiveZLP()
{
  outep->DOEPTSIZ &= ~(   (0x3FFU << (19U))
                        | (0x7FFFFU << (0U)) ); 
    
  outep->DOEPTSIZ |=  (  ((0x3FFU << (19U)) & (1 << 19))
                      |  ((0x7FFFFU << (0U)) & rxBuf.maxpacket) );

  outep->DOEPCTL  |=  (   (0x1U << (26U)) 
                        | (0x1U << (31U)) );  
}


DWORD cHwUSB_0::EndpointOUT::getInterrupt( void )
{
  return( outep->DOEPINT & ((USB_OTG_DeviceTypeDef *)((DWORD)((USB_OTG_GlobalTypeDef *) 0x50000000U) + 0x800U ))->DOEPMSK );
}


void cHwUSB_0::EndpointOUT::clrInterrupt( DWORD interruptID )
{
  outep->DOEPINT = interruptID;  
}







cHwUSB_0 *cHwUSB_0::usbPtr = 0;


cHwUSB_0::cHwUSB_0( cHwUSBdesc &desc )

: cHwUSB( desc )

{
  usbPtr = this;

  for( WORD i = 0; i < NUM_OF_ENDPOINTS; i++ )
  {
    epIN [i].init( i );
    epOUT[i].init( i );
  }
}


void cHwUSB_0::start(void)
{




  cHwPinConfig::set( cHwPinConfig::OTG_FS_ID, cHwPinConfig::PULL_UP
                                             |cHwPinConfig::HIGH_SPEED
                                             |cHwPinConfig::OPEN_DRAIN );
  
  cHwPinConfig::set( cHwPinConfig::OTG_FS_DM, cHwPinConfig::NO_PUPD
                                             |cHwPinConfig::HIGH_SPEED
                                             |cHwPinConfig::PUSH_PULL );
  
  cHwPinConfig::set( cHwPinConfig::OTG_FS_DP, cHwPinConfig::NO_PUPD
                                             |cHwPinConfig::HIGH_SPEED
                                             |cHwPinConfig::PUSH_PULL);

  ((RCC_TypeDef *) ((0x40000000U + 0x00020000U) + 0x3800U))->AHB2ENR |= (0x1U << (7U));              
    
  __NVIC_EnableIRQ( OTG_FS_IRQn );
    
  ((USB_OTG_GlobalTypeDef *) 0x50000000U)->GAHBCFG &= ~(0x1U << (0U));     
  ((USB_OTG_GlobalTypeDef *) 0x50000000U)->GUSBCFG |=  (0x1U << (6U));   
  CoreReset();                                      
                                                    
  ((USB_OTG_GlobalTypeDef *) 0x50000000U)->GCCFG    = (0x1U << (16U));      
  ((USB_OTG_GlobalTypeDef *) 0x50000000U)->GUSBCFG &= ~( (0x1U << (29U))   
                           |(0x1U << (30U)) ); 
  ((USB_OTG_GlobalTypeDef *) 0x50000000U)->GUSBCFG |=  ( (0x1U << (30U)) ); 

  for (uint32_t i = 0; i < 15 ; i++)
  {
    ((USB_OTG_GlobalTypeDef *) 0x50000000U)->DIEPTXF[i] = 0;
  }



  *(volatile DWORD *)((DWORD)((USB_OTG_GlobalTypeDef *) 0x50000000U) + 0xE00U)        = 0;                         
  
  
  ((USB_OTG_DeviceTypeDef *)((DWORD)((USB_OTG_GlobalTypeDef *) 0x50000000U) + 0x800U ))->DCFG  |= ( (3 <<  0)   
                        |(0 << 11)); 
  
  
  epIN [0].flush();                  
  epOUT[0].flush();
  
  
  ((USB_OTG_DeviceTypeDef *)((DWORD)((USB_OTG_GlobalTypeDef *) 0x50000000U) + 0x800U ))->DIEPMSK  = 0;
  ((USB_OTG_DeviceTypeDef *)((DWORD)((USB_OTG_GlobalTypeDef *) 0x50000000U) + 0x800U ))->DOEPMSK  = 0;
  ((USB_OTG_DeviceTypeDef *)((DWORD)((USB_OTG_GlobalTypeDef *) 0x50000000U) + 0x800U ))->DAINT    = 0xFFFFFFFF;
  ((USB_OTG_DeviceTypeDef *)((DWORD)((USB_OTG_GlobalTypeDef *) 0x50000000U) + 0x800U ))->DAINTMSK = 0;
  
  for (uint32_t i = 0; i < NUM_OF_ENDPOINTS; i++)
  {
    epIN[i].start();
    epOUT[i].start();
  }
  
  ((USB_OTG_DeviceTypeDef *)((DWORD)((USB_OTG_GlobalTypeDef *) 0x50000000U) + 0x800U ))->DIEPMSK &= ~((0x1U << (8U)));  
  ((USB_OTG_GlobalTypeDef *) 0x50000000U)->GINTMSK  = 0;                          
  ((USB_OTG_GlobalTypeDef *) 0x50000000U)->GINTSTS  = 0xBFFFFFFF;                 

  ((USB_OTG_GlobalTypeDef *) 0x50000000U)->GINTMSK |= (0x1U << (4U));    
  
  
  ((USB_OTG_GlobalTypeDef *) 0x50000000U)->GINTMSK |= (  (0x1U << (11U)) 
                          | (0x1U << (12U)) 
                          | (0x1U << (13U)) 
                          | (0x1U << (18U)) 
                          | (0x1U << (19U))   
                          | (0x1U << (31U)) );
  ((USB_OTG_GlobalTypeDef *) 0x50000000U)->GINTMSK |= (  (0x1U << (30U)) 
                          | (0x1U << (2U))); 
 
  ((USB_OTG_DeviceTypeDef *)((DWORD)((USB_OTG_GlobalTypeDef *) 0x50000000U) + 0x800U ))->DCTL |= (0x1U << (1U));             

  WORD offset = 0;
  ((USB_OTG_GlobalTypeDef *) 0x50000000U)->GRXFSIZ            = (  64                ); offset  = 64; 
  ((USB_OTG_GlobalTypeDef *) 0x50000000U)->DIEPTXF0_HNPTXFSIZ = (( 64 << 16) | offset); offset += 64; 
  ((USB_OTG_GlobalTypeDef *) 0x50000000U)->DIEPTXF[0]         = (( 64 << 16) | offset); offset += 64; 
  ((USB_OTG_GlobalTypeDef *) 0x50000000U)->DIEPTXF[1]         = (( 64 << 16) | offset); offset += 64; 
  ((USB_OTG_GlobalTypeDef *) 0x50000000U)->DIEPTXF[2]         = (( 64 << 16) | offset);               

  ((USB_OTG_DeviceTypeDef *)((DWORD)((USB_OTG_GlobalTypeDef *) 0x50000000U) + 0x800U ))->DCTL    &= ~(0x1U << (1U));         
  ((USB_OTG_GlobalTypeDef *) 0x50000000U)->GAHBCFG |=  (0x1U << (0U));      
}


inline void cHwUSB_0::isr(void)
{
  
  if( ((USB_OTG_GlobalTypeDef *) 0x50000000U)->GINTSTS & (0x1U << (0U)) ) 
  {
    return;
  }
  
  
  if( isInterruptPending( (0x1U << (1U)) ) )
  {
    
    clrInterrupt( (0x1U << (1U)));
  }
  
  
  if( isInterruptPending( (0x1U << (19U)) ) )
  {
    DWORD interruptBits = getOutInterrupt();
    DWORD interruptType = 0;
    BYTE  epNum         = 0;
    
    while ( interruptBits )
    {
      if( interruptBits & 0x1 )
      {
        interruptType = epOUT[epNum].getInterrupt();
        
        if( interruptType & (0x1U << (0U)) ) 
        {
          
          epOUT[epNum].receive();
          eventHandler( epNum, false ); 
          epOUT[epNum].clrInterrupt( (0x1U << (0U)) );
        }
                
        if( interruptType & (0x1U << (3U)) )
        {
          
          eventHandler( 0, true ); 
          epIN[0].transmit(true);
          epOUT[epNum].clrInterrupt( (0x1U << (3U)) );
        }
        
        if( interruptType & (0x1U << (4U)) )
        {
          epOUT[epNum].clrInterrupt( (0x1U << (4U)));
        }
      }

      
      epNum++;
      interruptBits >>= 1;
    }
  }
  
  
  if( isInterruptPending( (0x1U << (18U)) ) )
  {
    DWORD interruptBits = getInInterrupt();
    DWORD interruptType = 0;
    BYTE  epNum         = 0;
      
    while( interruptBits )
    {
      if( interruptBits & 0x1 )
      {
        interruptType = epIN[epNum].getInterrupt( );

        if( interruptType & (0x1U << (0U)) )
        {
          ((USB_OTG_DeviceTypeDef *)((DWORD)((USB_OTG_GlobalTypeDef *) 0x50000000U) + 0x800U ))->DIEPEMPMSK = ~(0x1 << epNum);
          epIN[epNum].clrInterrupt( (0x1U << (0U)) );
          epOUT[0].receiveZLP();
          eventHandler( epNum | 0x80, true );          
          epIN[epNum].transmit( false );
        }
         
        if( interruptType & (0x1U << (3U)) )
        {
          epIN[epNum].clrInterrupt( (0x1U << (3U)) );
        }
        
        if( interruptType & (0x1U << (4U)) )
        {
          epIN[epNum].clrInterrupt( (0x1U << (4U)) );
        }
        
        if( interruptType & (0x1U << (6U)) )
        {
          epIN[epNum].clrInterrupt( (0x1U << (6U)) );
        }
        
        if( interruptType & (0x1U << (1U)) )
        {
          epIN[epNum].clrInterrupt( (0x1U << (1U)) );
        }
        
        if( interruptType & (0x1U << (7U)) )
        {
          epIN[epNum].writeToFifo();
          epIN[epNum].clrInterrupt( (0x1U << (7U)) );
        }
      }

      
      epNum++;
      interruptBits >>= 1;
    }
  }
  
  
  if( isInterruptPending( (0x1U << (31U)) ) )
  {    
    ((USB_OTG_DeviceTypeDef *)((DWORD)((USB_OTG_GlobalTypeDef *) 0x50000000U) + 0x800U ))->DCTL &= ~(0x1U << (0U));
    clrInterrupt( (0x1U << (31U)) );
  }
  
  
  if( isInterruptPending( (0x1U << (11U)) ) )
  {
    clrInterrupt( (0x1U << (11U)) );
  }
  
  
  if( isInterruptPending( (0x1U << (12U)) ) )
  {
    reset();
    clrInterrupt( (0x1U << (12U)) );
  }
  
  
  if( isInterruptPending( (0x1U << (13U)) ) )
  {
    ((USB_OTG_DeviceTypeDef *)((DWORD)((USB_OTG_GlobalTypeDef *) 0x50000000U) + 0x800U ))->DCTL |= (0x1U << (8U));
    
    ((USB_OTG_GlobalTypeDef *) 0x50000000U)->GUSBCFG &= ~(  (0xFU << (10U)) );    
    ((USB_OTG_GlobalTypeDef *) 0x50000000U)->GUSBCFG |=  (  (0x1U << (10U)) 
                             | (0x4U << (10U)) );  
      
    epOUT[0].config( MAX_EP0_SIZE );
    epIN [0].config( MAX_EP0_SIZE );    
    
    clrInterrupt( (0x1U << (13U)) );
  }
    
  
  if( isInterruptPending( (0x1U << (4U)) ) )
  {
    ((USB_OTG_GlobalTypeDef *) 0x50000000U)->GINTMSK &= ~((0x1U << (4U))); 
        
    DWORD temp = ((USB_OTG_GlobalTypeDef *) 0x50000000U)->GRXSTSP;
    
    BYTE epnum = temp & (0xFU << (0U));
   
    if( ((temp & (0xFU << (17U))) >> 17) ==  2 ) 
    { 
      if( temp & (0x7FFU << (4U)) )
      { 
        epOUT[epnum].readFromFifo( (temp & (0x7FFU << (4U))) >> 4 );
      }
    }
    else if( ((temp & (0xFU << (17U))) >> 17) ==  6 ) 
    {
      epOUT[epnum].readFromFifo( 8 );
    }
    ((USB_OTG_GlobalTypeDef *) 0x50000000U)->GINTMSK |= ((0x1U << (4U))); 
  }
  
  
  if( isInterruptPending( (0x1U << (3U)) ) )
  {
    clrInterrupt( (0x1U << (3U)) );
  }
  
  
  if( isInterruptPending( (0x1U << (30U)) ) )
  {
    clrInterrupt( (0x1U << (30U)) );
  } 
  
  
  if( isInterruptPending( (0x1U << (2U)) ) )
  {
    DWORD temp = ((USB_OTG_GlobalTypeDef *) 0x50000000U)->GOTGINT;
    ((USB_OTG_GlobalTypeDef *) 0x50000000U)->GOTGINT |= temp;
  }
}


void cHwUSB_0::reset( void ) 
{
  ((USB_OTG_DeviceTypeDef *)((DWORD)((USB_OTG_GlobalTypeDef *) 0x50000000U) + 0x800U ))->DCTL &= ~(0x1U << (0U)); 
  
  epIN[0].flush();
      
  for( WORD i = 0; i < NUM_OF_ENDPOINTS ; i++ )
  {
    epIN [i].reset();
    epOUT[i].reset();
  }

  ((USB_OTG_DeviceTypeDef *)((DWORD)((USB_OTG_GlobalTypeDef *) 0x50000000U) + 0x800U ))->DAINT     = 0xFFFFFFFF;
  ((USB_OTG_DeviceTypeDef *)((DWORD)((USB_OTG_GlobalTypeDef *) 0x50000000U) + 0x800U ))->DAINTMSK |= 0x10001;
  
  ((USB_OTG_DeviceTypeDef *)((DWORD)((USB_OTG_GlobalTypeDef *) 0x50000000U) + 0x800U ))->DOEPMSK |= (  (0x1U << (3U)) 
                          | (0x1U << (0U)) 
                          | (0x1U << (1U)) 
                          | (0x1U << (4U)) );
  
  ((USB_OTG_DeviceTypeDef *)((DWORD)((USB_OTG_GlobalTypeDef *) 0x50000000U) + 0x800U ))->DIEPMSK |= (  (0x1U << (3U)) 
                          | (0x1U << (0U)) 
                          | (0x1U << (1U)) );

  ((USB_OTG_DeviceTypeDef *)((DWORD)((USB_OTG_GlobalTypeDef *) 0x50000000U) + 0x800U ))->DCFG    &= ~(0x7FU << (4U)); 
}


void cHwUSB_0::configure( BYTE flag ) 
{
}


void cHwUSB_0::setAddress( BYTE adr )
{
  ((USB_OTG_DeviceTypeDef *)((DWORD)((USB_OTG_GlobalTypeDef *) 0x50000000U) + 0x800U ))->DCFG &= ~(0x7FU << (4U));
  ((USB_OTG_DeviceTypeDef *)((DWORD)((USB_OTG_GlobalTypeDef *) 0x50000000U) + 0x800U ))->DCFG |=  (0x7FU << (4U)) & (adr << 4);
  
  epIN[0].transmitZLP();
}


void cHwUSB_0::configEP( BYTE epAddr, 
                         WORD epMaxPacketSize, 
                         BYTE epType ) 
{
  BYTE epNum = epAddr&0x7F;
  
  if( epNum < NUM_OF_ENDPOINTS )
  {
    if( epAddr & 0x80 )
    {
      epIN[epNum].config( epMaxPacketSize, epType );
    }
    else
    {    
      epOUT[epNum].config( epMaxPacketSize, epType );
    }

    clrStallEP( epAddr );

    epIN[epNum].transmitZLP();
  }
}


void cHwUSB_0::setStallEP (BYTE epAddr) 
{
  BYTE epNum = epAddr&0x7F;
  
  if( epNum < NUM_OF_ENDPOINTS )
  {
    if( epAddr & 0x80 )
    {
      epIN[epNum].setStall();
    }
    else
    {
      epOUT[epNum].setStall();
    }
  }
}


void cHwUSB_0::clrStallEP (BYTE epAddr) 
{
  BYTE epNum = epAddr&0x7F;
  
  if( epNum < NUM_OF_ENDPOINTS )
  {
    if( epAddr & 0x80 )
      epIN[epNum].clrStall();
    else
      epOUT[epNum].clrStall();
  }
}


WORD cHwUSB_0::readEP( BYTE  epAddr, 
                       BYTE *dataPtr, 
                       WORD  len )
{
  BYTE epNum = epAddr&0x7F;
  
  if( epNum < NUM_OF_ENDPOINTS )
  {
    return( epOUT[epNum].read( dataPtr, len ) );
  }
  return( 0 );
}


WORD cHwUSB_0::writeEP( BYTE  epAddr, 
                        BYTE *dataPtr, 
                        WORD  len ) 
{
  BYTE epNum = epAddr&0x7F;
  
  if( epNum < NUM_OF_ENDPOINTS )
  {
    return( epIN[epNum].write( dataPtr, len ) );
  }
  return( 0 );
}


BYTE cHwUSB_0::CoreReset( void )
{
  DWORD count = 200000;

  
  while( !(((USB_OTG_GlobalTypeDef *) 0x50000000U)->GRSTCTL & (0x1U << (31U))) )
  {
    if( !count-- )
    {
      return false;
    }
  }
  
  ((USB_OTG_GlobalTypeDef *) 0x50000000U)->GRSTCTL |= (0x1U << (0U));  
 
  count = 200000;
  while( ((USB_OTG_GlobalTypeDef *) 0x50000000U)->GRSTCTL & (0x1U << (0U)) )
  {
    if( !count-- )
    {
      return false;
    }
  }
  
  return true;
}


DWORD cHwUSB_0::getInInterrupt( void )
{
  return(    ((USB_OTG_DeviceTypeDef *)((DWORD)((USB_OTG_GlobalTypeDef *) 0x50000000U) + 0x800U ))->DAINT
           & ((USB_OTG_DeviceTypeDef *)((DWORD)((USB_OTG_GlobalTypeDef *) 0x50000000U) + 0x800U ))->DAINTMSK 
           & 0xFFFF               );
}


DWORD cHwUSB_0::getOutInterrupt( void )
{
  return( (   ((USB_OTG_DeviceTypeDef *)((DWORD)((USB_OTG_GlobalTypeDef *) 0x50000000U) + 0x800U ))->DAINT 
            & ((USB_OTG_DeviceTypeDef *)((DWORD)((USB_OTG_GlobalTypeDef *) 0x50000000U) + 0x800U ))->DAINTMSK 
            & 0xFFFF0000           ) >> 16);
}


BYTE cHwUSB_0::isInterruptPending( DWORD interuptID )
{
  return( (   ((USB_OTG_GlobalTypeDef *) 0x50000000U)->GINTSTS 
            & ((USB_OTG_GlobalTypeDef *) 0x50000000U)->GINTMSK 
            & interuptID          ) == interuptID );  
}


void cHwUSB_0::clrInterrupt( DWORD interuptID )
{
  ((USB_OTG_GlobalTypeDef *) 0x50000000U)->GINTSTS |= interuptID;
}



extern "C" 
{
  void OTG_FS_IRQHandler(void)
  {
    cSystem::disableInterrupt();
    cHwUSB_0::usbPtr->isr();
    cSystem::enableInterrupt();
  }
}


#line 38 ".\\..\\EmbSysLib\\Src\\MCU\\STM32F7xx\\MCU.cpp"


WORD hton( const WORD in )
{
  return(  (((in>>8)&0xFF)   )
         | (((in   )&0xFF)<<8) );
}

DWORD hton( const DWORD in )
{
  return( (((in>>24)&0xFF)    )
         |(((in>>16)&0xFF)<< 8)
         |(((in>> 8)&0xFF)<<16)
         |(((in    )&0xFF)<<24) );
}

WORD ntoh( const WORD in )
{
  return( hton(in) );
}

DWORD ntoh( const DWORD in )
{
  return( hton(in) );
}


#line 19 "..\\EmbSysLib\\Src\\lib.cpp"







#line 1 "..\\EmbSysLib\\Src\\Com/Hardware/Analog/ADC.cpp"







 



#line 13 "..\\EmbSysLib\\Src\\Com/Hardware/Analog/ADC.cpp"







cHwADC::cHwADC( BYTE numIn, cHwTimer *tPtrIn )
{
  if( tPtrIn ) 
  {
    tPtrIn->add( this ); 
  }

  currentCh      = 0;
  currentId      = 0;
  numActivatedCh = 0;
  numOfChannels  = numIn;
  result[0]      = new WORD[numIn];
  result[1]      = new WORD[numIn];
  chList         = new BYTE[numIn];
  idx            = 0;
  isRunning      = false;
}


void cHwADC::enable( BYTE ch, BYTE para )
{
  if(    ch             < numOfChannels )  
  {
      for(int i=0;i<numActivatedCh;i++)
          if( chList[i]  == ch)
          {
              configCh( ch, para );
              return;
          }


      if( numActivatedCh < numOfChannels )  
      {
        result[0][numActivatedCh] = 0;
        result[1][numActivatedCh] = 0;
        chList[numActivatedCh++]  = ch; 
        configCh( ch, para );                 
      }
  }
}


inline WORD cHwADC::get( BYTE ch )
{
  cSystem::disableInterrupt();    
                                  
  WORD ret = result[idx?0:1][ch]; 

  cSystem::enableInterrupt();

  return( ret );
}


inline BYTE cHwADC::getNumberOfChannels( void )
{
  return( numOfChannels );
}


inline void cHwADC::update( void )
{
  if( numActivatedCh && !isRunning ) 
                                     
                                     
  {
    currentId = 0;                   
    currentCh = chList[currentId];   
    idx = idx?0:1;                   
    isRunning = true;                
    startCh( currentCh );            
  }
}


inline void cHwADC::isr( void )
{
  result[idx?1:0][currentCh]       
    = getResult();                 
                                   
  currentId++;                     

  if( currentId < numActivatedCh ) 
  {
    currentCh = chList[currentId]; 
    startCh( currentCh );          
  }
  else                             
  {
    currentId = 0;
    currentCh = chList[currentId];
    isRunning = false;
  }
}


#line 27 "..\\EmbSysLib\\Src\\lib.cpp"
#line 1 "..\\EmbSysLib\\Src\\Com/Hardware/Analog/DAC.cpp"







 


#line 12 "..\\EmbSysLib\\Src\\Com/Hardware/Analog/DAC.cpp"







cHwDAC::cHwDAC( BYTE numIn )
{
  numOfChannels = numIn;
}


inline BYTE cHwDAC::getNumberOfChannels( void )
{
  return( numOfChannels );
}


#line 28 "..\\EmbSysLib\\Src\\lib.cpp"
#line 1 "..\\EmbSysLib\\Src\\Com/Hardware/Display/Display.cpp"







 


#line 12 "..\\EmbSysLib\\Src\\Com/Hardware/Display/Display.cpp"







cHwDisplay::cHwDisplay( BYTE numberOfLinesIn,
                        BYTE numberOfColumnsIn )
{
  numberOfLines  = numberOfLinesIn;
  numberOfColumns = numberOfColumnsIn;
}


inline BYTE cHwDisplay::getNumberOfLines( void )
{
  return( numberOfLines );
}


inline BYTE cHwDisplay::getNumberOfColumns( void )
{
  return( numberOfColumns );
}


#line 29 "..\\EmbSysLib\\Src\\lib.cpp"
#line 1 "..\\EmbSysLib\\Src\\Com/Hardware/Display/DisplayFont.cpp"





 


#line 10 "..\\EmbSysLib\\Src\\Com/Hardware/Display/DisplayFont.cpp"







cHwDisplayFont::cHwDisplayFont( const cHwDisplayFontProperties *propIn,
                                const BYTE                     *dataIn )
{
  prop     = propIn;
  data     = dataIn;
  selected = data;  
}


 BYTE cHwDisplayFont::getCharWidth( void ) const
{
  return( (prop->charWidth) );
}


BYTE cHwDisplayFont::getCharHeight( void ) const
{
  return( (prop->charHeight) );
}


void cHwDisplayFont::setChar( BYTE c )
{
  BYTE id = 0;

  if( (prop->firstId) <= c && c <= (prop->lastId) ) 
  {
    id = c - (prop->firstId);
  }
  selected = data + (WORD)id * (prop->bytePerChar);
}


BYTE cHwDisplayFont::getPixel( BYTE x, BYTE y )
{
                                                 
  WORD pixel  = ( (WORD)x + (WORD)y * getCharWidth() );

                                                
  BYTE ret = (*(selected+(pixel>>3))) & ( 0x80>>(pixel&0x07) );

  return( ret ? true : false );
}


#line 30 "..\\EmbSysLib\\Src\\lib.cpp"
#line 1 "..\\EmbSysLib\\Src\\Com/Hardware/Display/DisplayGraphic.cpp"





 


#line 10 "..\\EmbSysLib\\Src\\Com/Hardware/Display/DisplayGraphic.cpp"








cHwDisplayGraphic::cHwDisplayGraphic( cHwDisplayFont fontIn,
                                      BYTE           zoomIn )
: cHwDisplay( 10, 20 ), 
  font( fontIn ),
  zoom( zoomIn )
{
  BackColor  = Blue;
  PaintColor = Grey;
  TextColor  = White;

  xPos = 0;
  yPos = 0;
}


void cHwDisplayGraphic::setFont( cHwDisplayFont fontIn,
                                 BYTE           zoomIn )
{
  font = fontIn;
  zoom = zoomIn;
}


void cHwDisplayGraphic::setZoom( BYTE zoomIn )
{
  zoom = zoomIn;
}


void cHwDisplayGraphic::setBackColor( WORD color )
{
  BackColor = color;
}


void cHwDisplayGraphic::setPaintColor( WORD color )
{
  PaintColor = color;
}


void cHwDisplayGraphic::setTextColor( WORD color )
{
  TextColor = color;
}


void cHwDisplayGraphic::gotoPixelPos( WORD x,
                                      WORD y )
{
  xPos = x;
  yPos = y;
}


void cHwDisplayGraphic::gotoTextPos( BYTE line,
                                     BYTE colum )
{
  xPos = colum * zoom * font.getCharWidth();
  yPos = line  * zoom * font.getCharHeight();
}


void cHwDisplayGraphic::putChar( char ch )
{
  font.setChar( ch ); 

  setArea( xPos,     
           yPos,
           zoom*font.getCharWidth(),
           zoom*font.getCharHeight() + 1 );

  for( BYTE j = 0; j < font.getCharHeight(); j++ )  
  {
     for( BYTE zoomY = 0; zoomY < zoom; zoomY++ )
     {
        for( BYTE i = 0 ; i < font.getCharWidth(); i++ ) 
        {
          BYTE pixel = font.getPixel(i, j);             
          for( BYTE zoomX = 0; zoomX < zoom; zoomX++ )
          {
            setPixel( (pixel) ? TextColor : BackColor );
          }
        }
     }
  }
  xPos += (WORD)zoom*font.getCharWidth(); 
}


void cHwDisplayGraphic::putPixel( WORD x,
                                  WORD y )
{
  setPixel( PaintColor, x, y );
}


void cHwDisplayGraphic::putRectangle( WORD x,
                                      WORD y,
                                      WORD w,
                                      WORD h )
{
  setArea( x, y, w, h );          

  for( WORD i = 0; i < h; i++ )   
  {
    for( WORD j = 0; j < w; j++ ) 
    {
      setPixel( PaintColor );     
    }
  }
}


void cHwDisplayGraphic::putBitmap( WORD        x,
                                   WORD        y,
                                   WORD        w,
                                   WORD        h,
                                   const WORD *bitmap )
{
  setArea( x, y, w, h );          

  for( WORD i = 0; i < h; i++ )   
  {
    for( WORD j = 0; j < w; j++ ) 
    {
      setPixel( *bitmap++ );      
    }
  }
}


#line 31 "..\\EmbSysLib\\Src\\lib.cpp"
#line 1 "..\\EmbSysLib\\Src\\Com/Hardware/Timer/Encoder.cpp"







 


#line 1 "..\\EmbSysLib\\Src\\Com/Hardware/Timer/Encoder.h"







 






#line 16 "..\\EmbSysLib\\Src\\Com/Hardware/Timer/Encoder.h"
#line 17 "..\\EmbSysLib\\Src\\Com/Hardware/Timer/Encoder.h"
#line 18 "..\\EmbSysLib\\Src\\Com/Hardware/Timer/Encoder.h"
#line 19 "..\\EmbSysLib\\Src\\Com/Hardware/Timer/Encoder.h"








 
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

#line 12 "..\\EmbSysLib\\Src\\Com/Hardware/Timer/Encoder.cpp"











#line 32 "..\\EmbSysLib\\Src\\lib.cpp"
#line 1 "..\\EmbSysLib\\Src\\Com/Hardware/Ethernet/Ethernet.cpp"

#line 3 "..\\EmbSysLib\\Src\\Com/Hardware/Ethernet/Ethernet.cpp"
#line 4 "..\\EmbSysLib\\Src\\Com/Hardware/Ethernet/Ethernet.cpp"
#line 5 "..\\EmbSysLib\\Src\\Com/Hardware/Ethernet/Ethernet.cpp"


#line 8 "..\\EmbSysLib\\Src\\Com/Hardware/Ethernet/Ethernet.cpp"



cHwEthernet::cHwEthernet( const cNetAddr<6> &addrPhyIn )

: addrPhy( addrPhyIn )
{
  plen    = 0;
  arp = 0;
  ip  = 0;
}


void cHwEthernet::update( void )
{
  if( PacketReceive( ) )
  {
    switch( getType() )
    {
      case cHwEthernet::TYPE_ARP: if( arp )  arp->process(); break;
      case cHwEthernet::TYPE_IP:  if(  ip )   ip->process(); break;
    }
  }
  
  if( ip )
  {    
    ip->update();
  }
}



void cHwEthernet::setARP( cNetARP *arpIn )
{
  arp = arpIn;
}


void cHwEthernet::setIP( cNetIP *ipIn )
{
  ip = ipIn;
}


  cNetAddr<4> &cHwEthernet::getIP( void )
{
	static cNetAddr <4> ret = zeroAddr;
	
  if( ip )
    ret = ip->getAddr();
  return( ret );
}


bool cHwEthernet::isNewIP()
{
  if( ip )
    return( ip->isNewIP() );
  return( false );
}

#line 34 "..\\EmbSysLib\\Src\\lib.cpp"
#line 1 "..\\EmbSysLib\\Src\\Com/Hardware/I2C/I2Cmaster.cpp"







 



#line 13 "..\\EmbSysLib\\Src\\Com/Hardware/I2C/I2Cmaster.cpp"







cHwI2Cmaster::cHwI2Cmaster( BYTE maskIntrIn )
{
  isHardwareOK = true;
  maskIntr     = maskIntrIn;
}


BYTE cHwI2Cmaster::Device::read( void )
{
  BYTE dat = 0;

  isErrorFlag |= i2c.read( hwAddr, 0, 0, &dat, 1 );

  return( dat );
}


BYTE cHwI2Cmaster::Device::read( BYTE addr )
{
  BYTE dat = 0;

  isErrorFlag |= i2c.read( hwAddr, &addr, 1, &dat, 1 );

  return( dat );
}


BYTE cHwI2Cmaster::Device::read( WORD addr )
{
  BYTE dat        = 0;
  BYTE addrTmp[2] = { (BYTE)(addr>>8),
                      (BYTE)(addr&0xFF) };

  isErrorFlag |= i2c.read( hwAddr, (BYTE *)&addrTmp, 2, &dat, 1 );

  return( dat );
}


void cHwI2Cmaster::Device::read( BYTE *data, BYTE size )
{
  isErrorFlag |= i2c.read( hwAddr, 0, 0, data, size );
}


void cHwI2Cmaster::Device::read( BYTE addr, BYTE *data, BYTE size )
{
  isErrorFlag |= i2c.read( hwAddr, &addr, 1, data, size );
}


void cHwI2Cmaster::Device::read( WORD addr, BYTE *data, BYTE size )
{
  BYTE addrTmp[2] = { (BYTE)(addr>>8),
                      (BYTE)(addr&0xFF) };

  isErrorFlag |= i2c.read( hwAddr, addrTmp, 2, data, size );
}


void cHwI2Cmaster::Device::write( BYTE data )
{
  isErrorFlag |= i2c.write( hwAddr, &data, 1, 0, 0 );
}


void cHwI2Cmaster::Device::write( BYTE addr, BYTE data )
{
  isErrorFlag |= i2c.write( hwAddr, &addr, 1, &data, 1 );
}


void cHwI2Cmaster::Device::write( WORD addr, BYTE data )
{
  BYTE addrTmp[2] = { (BYTE)(addr>>8),
                      (BYTE)(addr&0xFF) };

  isErrorFlag |= i2c.write( hwAddr, (BYTE*)&addrTmp, 2, &data, 1 );
}


void cHwI2Cmaster::Device::write( BYTE *data, BYTE size )
{
  isErrorFlag |= i2c.write( hwAddr, data, size, 0, 0 );
}


void cHwI2Cmaster::Device::write( BYTE addr, BYTE *data, BYTE size )
{
  isErrorFlag |= i2c.write( hwAddr, &addr, 1, data, size );
}


void cHwI2Cmaster::Device::write( WORD addr, BYTE *data, BYTE size )
{
  BYTE addrTmp[2] = { (BYTE)(addr>>8),
                      (BYTE)(addr&0xFF) };

  isErrorFlag |= i2c.write( hwAddr, addrTmp, 2, data, size );
}


BYTE cHwI2Cmaster::Device::isError( void )
{
  BYTE ret = isErrorFlag;

  isErrorFlag = false;

  return( ret );
}


BYTE cHwI2Cmaster::write( BYTE  hwAddr,
                          BYTE *adr,
                          BYTE  sizeAdr,
                          BYTE *data,
                          BYTE  sizeData )
{

  BYTE i = 0;
  isHardwareOK = true;

  if( maskIntr )
    cSystem::disableInterrupt();

  if( sizeAdr || sizeData )
  {
    start();
    sendAddr( hwAddr ); 
    for( i=0; i< sizeAdr; i++ )
    {
       writeByte( adr[i] );
    }
    for( i=0; i< sizeData; i++ )
    {
       writeByte( data[i] );
    }
  }

  stop();

  if( maskIntr )
    cSystem::enableInterrupt();


  return( !isHardwareOK );
}


BYTE cHwI2Cmaster::read( BYTE  hwAddr,
                         BYTE *adr,
                         BYTE  sizeAdr,
                         BYTE *data,
                         BYTE  sizeData )
{
  BYTE i = 0;

  isHardwareOK = true;

  if( maskIntr )
    cSystem::disableInterrupt();

  if( sizeAdr )
  {
    start();
    sendAddr( hwAddr ); 
    for( i=0; i< sizeAdr; i++ )
    {
       writeByte( adr[i] );
    }
  }

  if( sizeData )
  {
    start();
    sendAddr( hwAddr | 0x01 ); 
    for( i=0; i < sizeData - 1; i++ )
    {
      data[i] = readByteAck();
    }
    data[i] = readByteNack();
  }

  stop();

  if( maskIntr )
    cSystem::enableInterrupt();

  return( !isHardwareOK );
}







cHwI2Cmaster_Emul::cHwI2Cmaster_Emul( cHwPort::Pin &pinSCL_In,
                                      cHwPort::Pin &pinSDA_In,
                                      MODE          mode )

: cHwI2Cmaster( false),
  pinSCL      ( pinSCL_In ),
  pinSDA      ( pinSDA_In )

{
  pinSCL.set();
  pinSDA.set();
  pinSCL.setMode( cHwPort::OutOD );
  pinSDA.setMode( cHwPort::OutOD );

  switch( mode )
  {
    default:
    case CR_10kHz:     Twait = 33; break;
    case CR_50kHz:     Twait =  6; break;
    case CR_100kHz:    Twait =  3; break;
    case CR_400kHz:    Twait =  1; break;
    case CR_1000kHz:   Twait =  0; break;
  }
}


void cHwI2Cmaster_Emul::wait( void )
{
  cSystem::delayMicroSec( Twait );
}


void cHwI2Cmaster_Emul::waitForAckn( void )
{
  WORD i= 0xFFFF;

  while( (--i) && pinSDA.get() ); 

  if( i == 0 )
  {
    isHardwareOK = false;
  
  }
  else
  {
    isHardwareOK = true;
  }
}



void cHwI2Cmaster_Emul::start( void )
{
  wait();
  pinSDA.set();
  wait();
  pinSCL.set();
  wait();
  pinSDA.clr();
  wait();
  pinSCL.clr();
  wait();

}



void cHwI2Cmaster_Emul::stop( void )
{
  wait();
  pinSDA.clr();
  wait();
  pinSCL.set();
  wait();
  pinSDA.set();
  wait();
  pinSCL.clr();
  wait();
  pinSCL.set();
}


void cHwI2Cmaster_Emul::sendAddr( BYTE addr )
{
  writeByte( addr );
}


void cHwI2Cmaster_Emul::writeByte( BYTE byte )
{
  wait();
  pinSCL.clr();
  for( BYTE mask = 0x80; mask; mask >>= 1 )
  {
    wait();
    pinSDA.set( byte & mask );

    
    wait();
    pinSCL.set();
    wait();
    pinSCL.clr();
  }

  wait();
  pinSDA.set();

  wait();
  waitForAckn();

  wait();
  pinSCL.set();
  wait();
  pinSCL.clr();
}


BYTE cHwI2Cmaster_Emul::readByteNack(void) 
{
  BYTE byte = 0;

  wait();
  pinSDA.set();

  for (BYTE mask=0x80; mask ; mask >>= 1)
  {
    wait();
    pinSCL.set();
    wait();
    byte |= (pinSDA.get() ? mask : 0 );
    wait();
    pinSCL.clr();
  }

  pinSDA.set(); 

  
  wait();
  pinSCL.set();
  wait();
  pinSCL.clr();
  wait();
  pinSDA.set();
  wait();

  return byte;
}



BYTE cHwI2Cmaster_Emul::readByteAck(void) 
{
  BYTE byte = 0;

  wait();
  pinSDA.set();

  for (BYTE mask=0x80; mask ; mask >>= 1)
  {
    wait();
    pinSCL.set();
    wait();
    byte |= (pinSDA.get() ? mask : 0 );
    wait();
    pinSCL.clr();
  }

  pinSDA.clr(); 

  
  wait();
  pinSCL.set();

  wait();
  pinSCL.clr();
  pinSDA.set();

  return byte;
}


#line 36 "..\\EmbSysLib\\Src\\lib.cpp"
#line 1 "..\\EmbSysLib\\Src\\Com/Hardware/I2C/I2Cslave.cpp"





 


#line 1 "..\\EmbSysLib\\Src\\Com/Hardware/I2C/I2Cslave.h"





 























 
class cHwI2Cslave
{
  public:















 
class DataHandler
{
  public:
    




 
    virtual void receive( BYTE data, 
                          BYTE id   ) = 0;

    
    




 
    virtual BYTE transmit( BYTE id ) = 0;

    
    




 
    

}; 

  protected:
    
    
    
    
    
    
    cHwI2Cslave( DataHandler &handler,
                 BYTE         hwAddr  );
    
  protected:
    
    DataHandler &handler;
    BYTE         hwAddr;
   
}; 

#line 10 "..\\EmbSysLib\\Src\\Com/Hardware/I2C/I2Cslave.cpp"







cHwI2Cslave::cHwI2Cslave( cHwI2Cslave::DataHandler &handlerIn,
                          BYTE         hwAddrIn  )
: handler(handlerIn)

{
  hwAddr = hwAddrIn;
}


#line 37 "..\\EmbSysLib\\Src\\lib.cpp"
#line 1 "..\\EmbSysLib\\Src\\Com/Hardware/Memory/Memory.cpp"







 


#line 12 "..\\EmbSysLib\\Src\\Com/Hardware/Memory/Memory.cpp"







cHwMemory::cHwMemory( DWORD sizeIn, BYTE defIn ) 
{
  size        = sizeIn;
  def         = defIn;
  isFlashFlag = false;
}


inline void cHwMemory::write( DWORD addr, BYTE data ) 
{
  if( addr < size )        
  {
    writeByte(addr, data); 
  }
}


inline BYTE cHwMemory::read( DWORD addr ) 
{
  if( addr < size )           
  {
    return( readByte(addr) ); 
  }
  return( def );
}


inline void cHwMemory::clear( DWORD offset ) 
{
  for( DWORD i = offset; i < size; i++ )  
  {
    writeByte( i, def );
  }
}


inline DWORD cHwMemory::getSize( void ) 
{
  return( size );
}


inline bool cHwMemory::isFlash( void ) 
{
  return( isFlashFlag );
}


#line 38 "..\\EmbSysLib\\Src\\lib.cpp"
#line 1 "..\\EmbSysLib\\Src\\Com/Hardware/Port/Port.cpp"







 


#line 12 "..\\EmbSysLib\\Src\\Com/Hardware/Port/Port.cpp"
















cHwPort::Pin::Pin( cHwPort &portIn, BYTE pinIdIn )

: port( portIn )

{
  pinId   = pinIdIn;
  pinMask = (1<<pinId);
}


cHwPort::Pin::Pin( cHwPort &portIn, BYTE pinIdIn, Mode mode )

: port( portIn )

{
  pinId   = pinIdIn;
  pinMask = (1<<pinId);

  port.setPinMode( pinId, mode );
}


#line 39 "..\\EmbSysLib\\Src\\lib.cpp"
#line 1 "..\\EmbSysLib\\Src\\Com/Hardware/RTC/RTC.cpp"







 


#line 12 "..\\EmbSysLib\\Src\\Com/Hardware/RTC/RTC.cpp"







cHwRTC::cHwRTC( void )
{
  
}


#line 40 "..\\EmbSysLib\\Src\\lib.cpp"
#line 1 "..\\EmbSysLib\\Src\\Com/Hardware/SPI/SPImaster.cpp"







 


#line 1 "..\\EmbSysLib\\Src\\Com/Hardware/SPI/SPImaster.h"







 






#line 16 "..\\EmbSysLib\\Src\\Com/Hardware/SPI/SPImaster.h"



















 
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

#line 12 "..\\EmbSysLib\\Src\\Com/Hardware/SPI/SPImaster.cpp"







cHwSPImaster::cHwSPImaster( void )
{
  
}


BYTE cHwSPImaster::Device::transceive(  BYTE    data )
{
  cSystem::disableInterrupt();

  start();

  BYTE ret = spi.transceiveByte( data );
  stop();

  cSystem::enableInterrupt();
  return(ret);
}


void cHwSPImaster::Device::transceive( BYTE   *data, 
                                      WORD    size )
{
  cSystem::disableInterrupt();

  start();
  for( WORD i = 0; i < size; i++ )
  {
    data[i] = spi.transceiveByte(data[i]);
  }
  stop();

  cSystem::enableInterrupt();
}


inline BYTE cHwSPImaster::Device::read( void )
{
  return( transceive( ) );
}


inline void cHwSPImaster::Device::read( BYTE   *data, 
                                WORD    size )
{
  cSystem::disableInterrupt();

  start();
  for( WORD i = 0; i < size; i++ )
  {
    data[i] = spi.transceiveByte();
  }
  stop();

  cSystem::enableInterrupt();
}


inline void cHwSPImaster::Device::write( BYTE    data )
{
  transceive( data );
}


inline void cHwSPImaster::Device::write(  WORD    data )
{
  cSystem::disableInterrupt();

  start();
  spi.transceiveByte( data >> 8    );
  spi.transceiveByte( data &  0xFF );
  stop();

  cSystem::enableInterrupt();
}


inline void cHwSPImaster::Device::write(  BYTE   *data, 
                                 WORD    size )
{
  cSystem::disableInterrupt();

  start();
  for( WORD i = 0; i < size; i++ )
  {
    spi.transceiveByte( data[i] );
  }
  stop();

  cSystem::enableInterrupt();
}


inline void cHwSPImaster::Device::writeExt(   BYTE    bit9, 
                                    BYTE    data )
{
  cSystem::disableInterrupt();

  start();
  spi.transceiveByteExt( bit9, data );
  stop();

  cSystem::enableInterrupt();
}


inline void cHwSPImaster::Device::writeExt(   BYTE    bit, 
                                    WORD    data )
{
  cSystem::disableInterrupt();

  start();
  spi.transceiveByteExt( bit, data>>8 );
  spi.transceiveByteExt( bit, data &  0xFF );
  stop();

  cSystem::enableInterrupt();
}


#line 41 "..\\EmbSysLib\\Src\\lib.cpp"
#line 1 "..\\EmbSysLib\\Src\\Com/Hardware/SPI/SPIslave.cpp"





 


#line 1 "..\\EmbSysLib\\Src\\Com/Hardware/SPI/SPIslave.h"





 






#line 1 "..\\EmbSysLib\\Src\\Com/Hardware/SPI/SPIslave.h"





 


#line 14 "..\\EmbSysLib\\Src\\Com/Hardware/SPI/SPIslave.h"


















 
class cHwSPIslave
{
  public:














 
class DataHandler
{
  public:
    
    






 
    virtual BYTE transceive( BYTE data ) = 0;

}; 
     
protected:
    
    
    
    
    
    cHwSPIslave( DataHandler &handler );
    
  protected:
    
    DataHandler &handler;
   
}; 

#line 10 "..\\EmbSysLib\\Src\\Com/Hardware/SPI/SPIslave.cpp"







cHwSPIslave::cHwSPIslave( cHwSPIslave::DataHandler &handlerIn )

: handler( handlerIn )

{
}


#line 42 "..\\EmbSysLib\\Src\\lib.cpp"
#line 1 "..\\EmbSysLib\\Src\\Com/Hardware/Timer/Timer.cpp"







 


#line 12 "..\\EmbSysLib\\Src\\Com/Hardware/Timer/Timer.cpp"







DWORD cHwTimer::getCycleTime( void )
{
  return( cycleTime );
}


void cHwTimer::add( cList::Item *ptr )
{
  isrList.add( ptr );
}


inline void cHwTimer::isrHandler( void )
{
  isrList.updateAll();
}


#line 43 "..\\EmbSysLib\\Src\\lib.cpp"
#line 1 "..\\EmbSysLib\\Src\\Com/Hardware/Display/Touch.cpp"





 


#line 10 "..\\EmbSysLib\\Src\\Com/Hardware/Display/Touch.cpp"







cHwTouch::cHwTouch( WORD widthIn, 
                    WORD heightIn )
{
  width  = widthIn;
  height = heightIn;
  xPos   = 0;
  yPos   = 0;
  isTouchedFlag = false;
}


inline WORD cHwTouch::getPosX( void )
{
  return( xPos );
}


inline WORD cHwTouch::getPosY( void )
{
  return( yPos );
}


inline BYTE cHwTouch::isTouched( void )
{
  return( isTouchedFlag );
}


#line 44 "..\\EmbSysLib\\Src\\lib.cpp"
#line 1 "..\\EmbSysLib\\Src\\Com/Hardware/UART/UART.cpp"







 


#line 12 "..\\EmbSysLib\\Src\\Com/Hardware/UART/UART.cpp"







cHwUART::cHwUART( BYTE sizeRxBuf, BYTE sizeTxBuf )

: dataRxBuf( sizeRxBuf ), 
  dataTxBuf( sizeTxBuf )

{
  txReady = true;
}


inline void cHwUART::isrRx( void )
{
  BYTE data = getByte(); 

  dataRxBuf << data;     
}


inline void cHwUART::isrTx( void )
{
  BYTE data = 0;

  if( !dataTxBuf.isEmpty() ) 
  {
    dataTxBuf >> data;       
    txReady = false;         
                             
                             
    setByte( data );         
  }
  else
  {
    txReady = true;          
  }
}


void cHwUART::transmitByte( BYTE data )
{














 

  while( dataTxBuf.isFull() ) 
  {
    if( txReady )             
                              
                              
    {
      isrTx();                
    }
                              
                              
  }

  dataTxBuf << data;          

  if( txReady )               
                              
  {
    isrTx();
  }
}


void cHwUART::set( BYTE data )
{
  transmitByte( data );
}


void cHwUART::set( const BYTE *data, BYTE length )
{
  while( length-- )
  {
    transmitByte( *(data++ ) ); 
  }
}


void cHwUART::set( const char *str )
{
  while( *str )       
  {
    transmitByte( *(str++ ) ); 
  }
}

inline bool cHwUART::isTxBufferFull( void )
{
  return( dataTxBuf.isFull() );
}


bool cHwUART::get( BYTE *data )
{
  BYTE tmp = 0;

  if( dataRxBuf >> tmp )   
  {
    *data = tmp;           
    return( true );        
  }
  else
  {
    return( false );       
  }
}


BYTE cHwUART::get( void )
{
  BYTE tmp = 0;

  if( get( &tmp) )   
  {
    return( tmp );        
  }
  else
  {
    return( 0 );         
  }
}


#line 45 "..\\EmbSysLib\\Src\\lib.cpp"



#line 1 "..\\EmbSysLib\\Src\\Com/Hardware/USB/USBhardware.cpp"







 


#line 12 "..\\EmbSysLib\\Src\\Com/Hardware/USB/USBhardware.cpp"







cHwUSB::cHwUSB( cHwUSBdesc &descIn )

:desc( descIn ),
 epCtrl( *this )

{
}


void cHwUSB::eventHandler( BYTE epAddr, BYTE isSetup )
{
  cHwUSBendpoint *ptr = 0;
  
  switch( epAddr )
  {
    case 0x00: 
      if( isSetup )
      {
        epCtrl.setup();
      }
      else
      {
        epCtrl.out();
      }
      break;
      
    case 0x80: 
      epCtrl.in();
      break;
    
    default:
      if( (ptr = desc.getEndpoint( epAddr )) != 0 )
      {
        if( epAddr & 0x80 ) 
        {
          ptr->in();
        }
        else  
        {
          ptr->out();
        }
      }
      break;
  }
}  


#line 49 "..\\EmbSysLib\\Src\\lib.cpp"
#line 1 "..\\EmbSysLib\\Src\\Com/Hardware/USB/USBctrl.cpp"









 


#line 14 "..\\EmbSysLib\\Src\\Com/Hardware/USB/USBctrl.cpp"







cHwUSBctrl::cHwUSBctrl(cHwUSB &usbPtr)

: usb  ( usbPtr ),
  epIN ( usbPtr, 0x80, usb.desc.getMaxPacketSize0() ),
  epOUT( usbPtr, 0x00, usb.desc.getMaxPacketSize0() )
  
{
  DeviceStatus = usb.desc.getConfigDeviceStatus( 1 );
}




void cHwUSBctrl::setup()
{
  WORD cnt = usb.readEP( 0x00, (BYTE *)&setupData, sizeof(setupData) );
                      

  if( cnt ==  sizeof( setupData ) )
  {
    switch( setupData.reqRecipient() )
    {
      case REQ_RECIPIENT_DEVICE:     ReqDevice   (); return;
      case REQ_RECIPIENT_INTERFACE:  ReqInterface(); return;
      case REQ_RECIPIENT_ENDPOINT:   ReqEndpoint (); return;
    }
  }
  Stall();
}


void cHwUSBctrl::in()
{
  
  {
    switch(setupData.reqRecipient())
    {
      case REQ_RECIPIENT_DEVICE:    epIN.writeData(); return;
      case REQ_RECIPIENT_INTERFACE: epIN.inCtrl();    return;
      case REQ_RECIPIENT_ENDPOINT:                    return;
    }
  }
}


void cHwUSBctrl::out()
{
  if( setupData.reqDir() == REQ_DIR_HOST_TO_DEVICE )
  {
    switch( setupData.reqRecipient() )
    {
      case REQ_RECIPIENT_DEVICE:                     return;
      case REQ_RECIPIENT_INTERFACE: epOUT.outCtrl(); return;
      case REQ_RECIPIENT_ENDPOINT:                   return;
    }
  }
}





__inline void cHwUSBctrl::ReqDevice()
{
  switch( setupData.reqType() )
  {
    case REQ_TYPE_STANDARD:
      switch( setupData.request() )
      {
        case REQUEST_GET_STATUS:        ReqDeviceStd_GetStatus();        return;
        case REQUEST_CLR_FEATURE:       break;                           
        case REQUEST_RESERVED_0:        break;                           
        case REQUEST_SET_FEATURE:       break;                           
        case REQUEST_RESERVED_1:        break;                           
        case REQUEST_SET_ADDRESS:       ReqDeviceStd_SetAddress();       return;
        case REQUEST_GET_DESCRIPTOR:    ReqDeviceStd_GetDescriptor();    return;
        case REQUEST_SET_DESCRIPTOR:    break;                           
        case REQUEST_GET_CONFIGURATION: ReqDeviceStd_GetConfiguration(); return;
        case REQUEST_SET_CONFIGURATION: ReqDeviceStd_SetConfiguration(); return;
        case REQUEST_GET_INTERFACE:     break;                           
        case REQUEST_SET_INTERFACE:     break;                           
        case REQUEST_SYNC_FRAME:        break;                           
      }
      break;

    case REQ_TYPE_CLASS:
      break;

    case REQ_TYPE_VENDOR:
      break;
  }
  Stall();
}


__inline void cHwUSBctrl::ReqInterface()
{
  switch( setupData.reqType() )
  {
    case REQ_TYPE_STANDARD:
      switch( setupData.request() )
      {
        case REQUEST_GET_STATUS:        ReqInterfaceStd_GetStatus();     return;
        case REQUEST_CLR_FEATURE:       break;                           
        case REQUEST_RESERVED_0:        break;                           
        case REQUEST_SET_FEATURE:       break;                           
        case REQUEST_RESERVED_1:        break;                           
        case REQUEST_SET_ADDRESS:       break;                           
        case REQUEST_GET_DESCRIPTOR:    ReqInterfaceStd_GetDescriptor(); return;
        case REQUEST_SET_DESCRIPTOR:    break;                           
        case REQUEST_GET_CONFIGURATION: break;                           
        case REQUEST_SET_CONFIGURATION: break;                           
        case REQUEST_GET_INTERFACE:     ReqInterfaceStd_GetInterface();  return;
        case REQUEST_SET_INTERFACE:     ReqInterfaceStd_SetInterface();  return;
        case REQUEST_SYNC_FRAME:        break;                           
      }
      break;

    case REQ_TYPE_CLASS: 
      ReqInterfaceClass(); return;  

    case REQ_TYPE_VENDOR:
      break;
  }
  Stall();
}


__inline void cHwUSBctrl::ReqEndpoint()
{
  switch( setupData.reqType() )
  {
    case REQ_TYPE_STANDARD:
      switch( setupData.request() )
      {
        case REQUEST_GET_STATUS:        break;                        
        case REQUEST_CLR_FEATURE:       ReqEndpointStd_ClrFeature();     return;
        case REQUEST_RESERVED_0:        break;                        
        case REQUEST_SET_FEATURE:       ReqEndpointStd_SetFeature();     return;
        case REQUEST_RESERVED_1:        break;                        
        case REQUEST_SET_ADDRESS:       break;                        
        case REQUEST_GET_DESCRIPTOR:    break;                        
        case REQUEST_SET_DESCRIPTOR:    break;                        
        case REQUEST_GET_CONFIGURATION: break;                        
        case REQUEST_SET_CONFIGURATION: break;                        
        case REQUEST_GET_INTERFACE:     break;                        
        case REQUEST_SET_INTERFACE:     break;                        
        case REQUEST_SYNC_FRAME:        break;                        
      }
      break;

    case REQ_TYPE_CLASS:
      break;

    case REQ_TYPE_VENDOR:
      break;
  }
  Stall();
}





__inline void cHwUSBctrl::ReqDeviceStd_GetStatus( void )
{
  epIN.writeData( cDataPointer( (BYTE*)&DeviceStatus, setupData.length()) );
}


__inline void cHwUSBctrl::ReqDeviceStd_SetAddress( void )
{
  usb.setAddress( setupData.valueLow() );
}


__inline void cHwUSBctrl::ReqDeviceStd_GetDescriptor( void )
{
  switch( setupData.valueHigh() )
  {
    case cHwUSBdesc::DEVICE_DESCRIPTOR:
      epIN.writeDataLen( usb.desc.getDescriptorDevice(),
                         setupData.length() );
      return;

    case cHwUSBdesc::CONFIGURATION_DESCRIPTOR:
      epIN.writeDataLen( usb.desc.getDescriptorConfig( setupData.valueLow() + 1 ),
                         setupData.length() );
      return;

    case cHwUSBdesc::STRING_DESCRIPTOR:
      epIN.writeDataLen( usb.desc.getDescriptorString( setupData.valueLow() ),
                         setupData.length() );
       return;
    
    case cHwUSBdesc::INTERFACE_POWER_DESCRIPTOR:
       return;
  }

}


__inline void cHwUSBctrl::ReqDeviceStd_GetConfiguration( void )
{
  epIN.writeData(cDataPointer( (BYTE*)&Configuration,
                               setupData.length()) );
}


 __inline void cHwUSBctrl::ReqDeviceStd_SetConfiguration( void )
{
  cHwUSBdesc::cEndpoint *epDesc   = 0; 
  cHwUSBendpoint        *ep       = 0;
  BYTE                   configId = setupData.valueLow();

  if( (void *)usb.desc.getDescriptorConfig( configId ) != 0 )
  {
    Configuration = configId;
    usb.configure(true);

    DeviceStatus = usb.desc.getConfigDeviceStatus( configId );
    
    
    for( WORD i = 0;
         (void *)usb.desc.getDescriptorInterface( configId, i ) != 0; 
         i++ )
    { 
      for( WORD e=0;
           (epDesc = usb.desc.getDescriptorEndpoint( configId, i, e )) != 0;
           e++ )
      {
        if( (ep = usb.desc.getEndpoint( epDesc->bEndpointAddress )) !=0 )
        {
          ep->setConfiguration();
        }
      }
    }
    epIN.writeAcknowledge();
  }
  else
  {
    Configuration = 0;
    usb.configure(false); 
    Stall();
  }
}





 __inline void cHwUSBctrl::ReqInterfaceStd_GetStatus( void )
{
  
  Stall();
}


 __inline void cHwUSBctrl::ReqInterfaceStd_GetDescriptor( void )
{
  
  cHwUSBinterf *interf 
    = usb.desc.getInterface( setupData.valueLow()+1,  
                             setupData.indexLow() );  
  if( interf )
  {
    epIN.writeDataLen( interf->GetDescriptor( setupData.value() ),
                       setupData.length() );
    return;
  }
  Stall();
}


 __inline void cHwUSBctrl::ReqInterfaceStd_GetInterface( void )
{
  
  Stall();
}


 __inline void cHwUSBctrl::ReqInterfaceStd_SetInterface( void )
{
  
  Stall();
}


 __inline void cHwUSBctrl::ReqInterfaceClass( void )
{
  cDataPointer tmp;

  cHwUSBinterf *interfTmp 
    = usb.desc.getInterface( 1, setupData.indexLow() );

  if( interfTmp )
  {
    switch( setupData.reqDir() )
    {
      case REQ_DIR_DEVICE_TO_HOST:
        if( interfTmp->requestCtrlIN( tmp, 
                                  setupData.request(),
                                  setupData.value(), 
                                  setupData.length() ))
        {
          epIN.interf = interfTmp;
          epIN.epData = tmp;
          epIN.writeData();
          return;
        }
        break;
      case REQ_DIR_HOST_TO_DEVICE:
        if( interfTmp->requestCtrlOUT( tmp, 
                                  setupData.request(),
                                  setupData.value(), 
                                  setupData.length() ))
        {
          epOUT.interf = interfTmp;
          epOUT.epData = tmp;
          epIN.writeAcknowledge(); 
          return;
        }
        break;
    }
  }

  Stall();
}





__inline void cHwUSBctrl::ReqEndpointStd_ClrFeature ( void )
{
  cHwUSBendpoint *ep = usb.desc.getEndpoint( setupData.indexLow() );
  
  if( ep && Configuration > 0)
  {
    switch( setupData.value() )
    {
      case FEATURE_BIT_ENDPOINT_STALL:
        ep->clrStall();
        ep->clrFeature();
        epIN.writeAcknowledge();
        return;
    }
  }
  Stall();
}


__inline void cHwUSBctrl::ReqEndpointStd_SetFeature ( void )
{
  cHwUSBendpoint *ep = usb.desc.getEndpoint( setupData.indexLow() );

  if( ep && Configuration > 0 ) 
  {
    switch( setupData.valueLow() )
    {
      case FEATURE_BIT_ENDPOINT_STALL: 
        ep->stall();
        epOUT.writeAcknowledge();
        return;
    }
  }
  Stall();
}





__inline void cHwUSBctrl::Stall( void )
{
  epIN.stall();
}


#line 50 "..\\EmbSysLib\\Src\\lib.cpp"
#line 1 "..\\EmbSysLib\\Src\\Com/Hardware/USB/USBdesc.cpp"







 


#line 12 "..\\EmbSysLib\\Src\\Com/Hardware/USB/USBdesc.cpp"







cDataPointer cHwUSBdesc::getDescriptorDevice( void )
{
  WORD id  = getId( DEVICE, 0, 0, 0 );
  
  cHwUSBdesc::cDevice *ptr 
    = (cHwUSBdesc::cDevice *)getDescriptor( id );
  
  if( ptr )
  {
    return( cDataPointer( (BYTE*)ptr, ptr->bLength ) );
  }
  return( cDataPointer() );
}


cDataPointer cHwUSBdesc::getDescriptorConfig( BYTE confId )
{
  WORD id = getId( CONFIG, confId, 0, 0 );
  
  cHwUSBdesc::cConfiguration *ptr 
    = (cHwUSBdesc::cConfiguration *)getDescriptor( id );
  
  if( ptr )
  {
    return( cDataPointer( (BYTE*)ptr, ptr->wTotalLength ) );
  }
  return( cDataPointer() );
}


cDataPointer cHwUSBdesc::getDescriptorInterface( BYTE confId, 
                                                 BYTE interfId )
{
  WORD id = getId( INTERF, confId, interfId, 0 );
  
  cHwUSBdesc::cInterface *ptr 
    = (cHwUSBdesc::cInterface *)getDescriptor( id );

  if( ptr )
  {
    return( cDataPointer( (BYTE*)ptr, ptr->bLength ) );
  }
  return( cDataPointer() );
}


cDataPointer cHwUSBdesc::getDescriptorEndpoint( BYTE confId, 
                                                BYTE interfId, 
                                                BYTE epId )
{
  WORD id = getId( ENDPOINT, confId, interfId, epId );
  
  cHwUSBdesc::cEndpoint *ptr 
    = (cHwUSBdesc::cEndpoint *)getDescriptor( id );

  if( ptr )
  {
    return( cDataPointer( (BYTE*)ptr, ptr->bLength ) );
  }
  return( cDataPointer() );
}


cDataPointer cHwUSBdesc::getDescriptorHID( BYTE confId, 
                                           BYTE interfId, 
                                           BYTE hidId )
{
  WORD id = getId( CLASS, confId, interfId, hidId );
  
  cHwUSBdesc::cHID *ptr 
    = (cHwUSBdesc::cHID *)getDescriptor( id );

  if( ptr )
  {
    return( cDataPointer( (BYTE*)ptr, ptr->bLength ) );
  }
  return( cDataPointer() );
}


cDataPointer cHwUSBdesc::getDescriptorHIDreport( BYTE confId, 
                                                 BYTE interfId, 
                                                 BYTE hidId )
{
  WORD id = getId( REPORT, confId, interfId, hidId );
  
  cHwUSBdesc::cReport *ptr 
    = (cHwUSBdesc::cReport *)getDescriptor( id );

  if( ptr )
  {
    return( cDataPointer( (BYTE*)ptr+2, ptr->bLength-2 ) );  
  }
  return( cDataPointer() );
}


cDataPointer cHwUSBdesc::getDescriptorString( BYTE strId )
{
  WORD id = getId( STRING, 0, 0, strId );
  
  cHwUSBdesc::cString *ptr 
    = (cHwUSBdesc::cString *)getDescriptor( id );

  if( ptr )
  {
    return( cDataPointer( (BYTE*)ptr, ptr->bLength ) ); 
  }
  return( cDataPointer() );
}


BYTE cHwUSBdesc::getMaxPacketSize0( void )
{
  cHwUSBdesc::cDevice *ptr 
    = (cHwUSBdesc::cDevice *)cHwUSBdesc::getDescriptorDevice();
  
  if( ptr )
    return( ptr->bMaxPacketSize0 );
  return( 0 );
}


BYTE cHwUSBdesc::getConfigDeviceStatus( BYTE confId )
{
  cHwUSBdesc::cConfiguration *ptr 
    = (cHwUSBdesc::cConfiguration *)cHwUSBdesc::getDescriptorConfig( confId );

  BYTE ret = 0;

  if( ptr )
  {
    if( ptr->bmAttributes & 0x40 )
    {
      ret |= 0x01;
    }
    if( ptr->bmAttributes & 0x20 )
    {
      ret |= 0x02;
    }
  }
  return( ret );      
}


#line 51 "..\\EmbSysLib\\Src\\lib.cpp"
#line 1 "..\\EmbSysLib\\Src\\Com/Hardware/USB/USBendpoint.cpp"







 


#line 12 "..\\EmbSysLib\\Src\\Com/Hardware/USB/USBendpoint.cpp"







cHwUSBendpoint::cHwUSBendpoint( cHwUSB       &usbIn, 
                                cHwUSBinterf *interfIn,
                                BYTE          idIn, 
                                WORD          maxPacketSizeIn,
                                BYTE          attributesIn )
: usb( usbIn )
{
  interf        = interfIn;
  id            = idIn;
  maxPacketSize = maxPacketSizeIn;
  attributes    = attributesIn;
}


cHwUSBendpoint::cHwUSBendpoint( cHwUSB &usbIn, 
                                BYTE    idIn, 
                                WORD    maxPacketSizeIn )
: usb( usbIn )
{
  interf        = 0;
  id            = idIn;
  maxPacketSize = maxPacketSizeIn;
  attributes    = cHwUSBdesc::CONTROL_ENDPOINT;
}


void cHwUSBendpoint::in( void )
{
  if( interf && epData.isEmpty() )
  {
    interf->transmit( id, epData );
  }
  
  if( !epData.isEmpty() )
  {
    writeData( ); 
  }
}


void cHwUSBendpoint::inCtrl( void )
{
  writeData();
  if( epData.getSize() == 0 && interf )
  {
    interf->transmit( id, epData );
  }
}



void cHwUSBendpoint::out( void )
{
  WORD cnt = 0;
  
  if( interf ) 
  {
    interf->request( id, epData );
  }
  
  cnt = readData( );

  if( interf ) 
  {
    if( interf->receive( id, cnt ) != true)
    {
      stall();
    }
  }





}
    


void cHwUSBendpoint::outCtrl( void )
{
  WORD cnt = readData( );
  if( interf ) 
  {
    if( interf->receive( 0x00, cnt ) )
    {
      writeAcknowledge();
    }
    else
    {
      stall();
    }
  }
}


WORD cHwUSBendpoint::readData( void ) 
{
  WORD cnt = usb.readEP( id,  
                         epData.getPtr(), 
                         epData.getSize() );
  
  epData.shift( cnt );
  
  return( cnt );
}


void cHwUSBendpoint::writeData( void )
{
  WORD cnt = usb.writeEP( id, 
                          epData.getPtr(), 
                          MIN( epData.getSize(), 
                               maxPacketSize ) );
  
  epData.shift( cnt ); 
}


void cHwUSBendpoint::writeData( const cDataPointer &epDataIn )
{
  epData.set( epDataIn );
  writeData();
}


void cHwUSBendpoint::writeDataLen( const cDataPointer &epDataIn, 
                                   WORD                maxLen )
{
  cDataPointer tmp( epDataIn );
   
  epData.set( tmp.getPtr(), MIN( tmp.getSize(), maxLen ));
  writeData();
}


void cHwUSBendpoint::writeAcknowledge( void ) 
{
  usb.writeEP( id, 0, 0 );
}


void cHwUSBendpoint::readAcknowledge( void ) 
{
  BYTE buffer;

  usb.readEP( id, &buffer, 1 );
}


void cHwUSBendpoint::setConfiguration( void ) 
{
  usb.configEP( id, maxPacketSize, attributes );
}


void cHwUSBendpoint::stall( void )
{
  usb.setStallEP( id );
}


void cHwUSBendpoint::clrStall( void )
{
  usb.clrStallEP( id );
}


void cHwUSBendpoint::clrFeature( void )
{
  if( interf )
  {
    interf->clrFeature();
  }
}


#line 52 "..\\EmbSysLib\\Src\\lib.cpp"
#line 1 "..\\EmbSysLib\\Src\\Com/Hardware/USB/USBinterf.cpp"







 

#line 11 "..\\EmbSysLib\\Src\\Com/Hardware/USB/USBinterf.cpp"







cHwUSBinterf::cHwUSBinterf( cHwUSB &usbIn, 
                            BYTE    configIdIn, 
                            BYTE    interfIdIn )

:usb(usbIn)

{
  configId = configIdIn;
  interfId = interfIdIn;
  
  cHwUSBdesc::cEndpoint  *epDesc = 0;
  
  usb.desc.registerInterface( configId, interfId, this );
  
  for( WORD e = 0;
       (epDesc = usb.desc.getDescriptorEndpoint( configId, interfId, e )) != 0;
       e++ )
  {
    cHwUSBendpoint *ptr = new cHwUSBendpoint( usb, 
                        this, 
                        epDesc->bEndpointAddress,
                        epDesc->wMaxPacketSize,
                        epDesc->bmAttributes );
                        
    usb.desc.registerEndpoint( epDesc->bEndpointAddress, ptr );
                  
    
    if( (epDesc->bEndpointAddress & 0x80) && !epIN && ptr )  
    {
      epIN = ptr;
    }      
    if( !(epDesc->bEndpointAddress & 0x80) && !epOUT && ptr )
    {
      epOUT = ptr;
    }      
  } 
}
  


#line 53 "..\\EmbSysLib\\Src\\lib.cpp"

#line 1 "..\\EmbSysLib\\Src\\Com/Hardware/Net/Net.cpp"





 


#line 1 "..\\EmbSysLib\\Src\\Com/Hardware/Net/NetStd.cpp"





 



#line 196 "..\\EmbSysLib\\Src\\Com/Hardware/Net/NetStd.cpp"





























WORD Checksum( BYTE *buf, WORD len, DWORD initialSum = 0)
{
   
   
   
   DWORD sum = initialSum;

   
   while(len > 1)
   {
      sum += 0xFFFF & (((WORD)(*buf) << 8) | *(buf+1));
      buf += 2;
      len -= 2;
   }
   
   if (len > 0)
   {
      sum += ((WORD)(0xFF & *buf) << 8);
   }
   
   
   while (sum >> 16)
   {
      sum = (sum & 0xFFFF) + (sum >> 16);
   }
   
   return ((WORD)sum ^ 0xFFFF);
}



#line 10 "..\\EmbSysLib\\Src\\Com/Hardware/Net/Net.cpp"
#line 1 "..\\EmbSysLib\\Src\\Com/Hardware/Net/NetTransport.cpp"
#line 2 "..\\EmbSysLib\\Src\\Com/Hardware/Net/NetTransport.cpp"


cNetTransport::Socket::Socket( cNetTransport   &transIn,
                                cNetApplication &appIn,
                                cNetAddr<4>      inAddrIn,
                                WORD             portIn )
: app  ( appIn   )

{
  addrPhy    = zeroAddrPhy;
  addr       = zeroAddr;
  myPort     = portIn;
  remoteAddr = inAddrIn;
  remotePort = portIn;
  timeOutTic = 0;


    setTimeout(1);

  state      = STATE_WAITING;

  isServerFlag = (inAddrIn == broadcastAddr);
  transIn.appList.add( (cList::Item*)this );
}



cNetTransport::cNetTransport(   )



{
}


void cNetTransport::process( void )
{
  Socket *ptr = (Socket *)appList.getFirst();

  while( ptr   )
  {
    ptr->process();
    ptr = (Socket *)ptr->getNext();
  }
}


void cNetTransport::update( void )
{
  Socket *ptr = (Socket *)appList.getFirst();

  while( ptr )
  {
    ptr->update();
    ptr = (Socket *)ptr->getNext();
  }
}


void cNetTransport::timeout( void )
{
  Socket *ptr = (Socket *)appList.getFirst();

  while( ptr )
  {
    ptr->timeout();
    ptr = (Socket *)ptr->getNext();
  }
}


cNetAddr<4> cNetTransport::Socket::getRemoteIP( void )
{
  return( remoteAddr );
}

#line 11 "..\\EmbSysLib\\Src\\Com/Hardware/Net/Net.cpp"

#line 1 "..\\EmbSysLib\\Src\\Com/Hardware/Net/NetARP.cpp"
#line 2 "..\\EmbSysLib\\Src\\Com/Hardware/Net/NetARP.cpp"
#line 3 "..\\EmbSysLib\\Src\\Com/Hardware/Net/NetARP.cpp"
#line 4 "..\\EmbSysLib\\Src\\Com/Hardware/Net/NetARP.cpp"
extern cDevTextIO_UART    com;



cNetARP::cNetARP( cHwEthernet &ethIn,
                  
                  cNetAddr<4> &addrIn )

: eth ( ethIn  ), 
  addr( addrIn ) ,
  msg( *(cNetARP_Msg*)eth.buf )

{
  eth.setARP( this );
  tcp = 0;
  udp = 0;
}


void cNetARP::process( void )
{
  switch( msg.arp.operationCode )
  {
    case OPCODE_REQUEST:
      if( msg.arp.destAddr == addr )
      {
        eth.create( msg.eth.sourceAddr, cHwEthernet::TYPE_ARP );

        msg.arp.operationCode = OPCODE_REPLY;
        msg.arp.sourceAddrPhy = eth.addrPhy;
        msg.arp.sourceAddr    = addr;
        msg.arp.destAddrPhy   = msg.arp.sourceAddrPhy;
        msg.arp.destAddr      = msg.arp.sourceAddr;

        eth.PacketSend( (BYTE*)&msg, sizeof(cNetARP_Msg) ); 
      }
      break;

    case OPCODE_REPLY:
      if( tcp )
      {
        tcp->handleARP( msg.arp.sourceAddr, 
                        msg.arp.sourceAddrPhy );
      }
      if( udp )
      {
        udp->handleARP( msg.arp.sourceAddr, 
                        msg.arp.sourceAddrPhy );
      }
      break;
  }
}


void cNetARP::request( cNetAddr<4> &addrIn )
{
  eth.create( broadcastAddrPhy, cHwEthernet::TYPE_ARP );

  msg.arp.hardwareType    = (WORD)1; 
  msg.arp.protocolType    = 0x0800;
  msg.arp.physicalAddrLen = 6;
  msg.arp.protocolAddrLen = 4;
  msg.arp.operationCode   = OPCODE_REQUEST;
  msg.arp.sourceAddrPhy   = eth.addrPhy;
  msg.arp.sourceAddr      = addr;
  msg.arp.destAddrPhy     = broadcastAddrPhy;
  msg.arp.destAddr        = addrIn;

  eth.PacketSend( (BYTE*)&msg,  sizeof(cNetARP_Msg) ); 
}


void cNetARP::setTCP( cNetTCP *tcpIn )
{
  tcp = tcpIn;
}


void cNetARP::setUDP( cNetUDP *udpIn )
{
  udp = udpIn;
}


#line 14 "..\\EmbSysLib\\Src\\Com/Hardware/Net/Net.cpp"
#line 1 "..\\EmbSysLib\\Src\\Com/Hardware/Net/NetDHCP.cpp"
#line 2 "..\\EmbSysLib\\Src\\Com/Hardware/Net/NetDHCP.cpp"







cNetDHCP::cNetDHCP( cNetUDP     &udpIn,
                    const char  *hostNameIn )

: 
  addrPhy( udpIn.getAddrPhy() ),
  udp    ( udpIn ),
  con    ( udpIn, *this, broadcastAddr, 68 )
{
  hostName       = hostNameIn;
  serverAddr     = zeroAddr;

  setTimeout( 1 );
}


void cNetDHCP::OnReceive()
{
  cNetDHCP_Data &dhcp = *(cNetDHCP_Data*)con.getDataPtr();

  
  if(    dhcp.op   == 2               
      && dhcp.hlen == sizeof(addrPhy) 
      && memcmp( (char*)&addrPhy,
                 dhcp.chAddr, 
                 sizeof(addrPhy) ) == 0 )
  {
    switch( parse_options( dhcp.options, sizeof(dhcp.options) ) )
    {
      case OFFER:
        if( serverAddr == zeroAddr )
        {
          serverAddr = dhcp.siAddr;

          udp.ip.addr = dhcp.yiAddr;
          con.open( broadcastAddr, 67 );
          send( REQUEST );
        }
        break;

      case ACK:
      case NAK:
        setTimeout( 3600 ); 
        break;
    }
  }
}


void cNetDHCP::OnError()
{
}
  

void cNetDHCP::OnTimeout()
{
  if( udp.ip.addr == zeroAddr )
  {
    con.open( broadcastAddr, 67 );
    send( DISCOVER ); 
  }
  else
  {
    con.open( serverAddr, 67 );
    send( REQUEST ); 
  }
  setTimeout( 3 ); 
}


BYTE cNetDHCP::parse_options( BYTE *optptr, int len )
{
  BYTE pos = 4; 
  BYTE type = 0;

  while(pos < len) 
  {
    switch( optptr[pos] ) 
    {
      case 53: 
        type = optptr[pos + 2];
        break;

      case 255: 
        return type;
    }
    pos += optptr[pos+1] + 2;
  }
  return type;
}


void cNetDHCP::send( BYTE msgType )
{
  
  
  cNetDHCP_Data &dhcp = *(cNetDHCP_Data*)con.getDataPtr();
  
  memset((char*)&dhcp, 0, sizeof(cNetDHCP_Data));
  
  dhcp.op    = 1; 
  dhcp.htype = 1; 
  dhcp.hlen  = sizeof( addrPhy );
  dhcp.hops  = 0;
  dhcp.xid   = 0x1234abcd;
  dhcp.secs  = 0;
  dhcp.flags = 0x8000; 

  memcpy( dhcp.chAddr, &addrPhy, dhcp.hlen );

  con.setDataLength( sizeof(cNetDHCP_Data) - sizeof(dhcp.options) );

  
  
  
  
  
  
  con.fill(  99 ); 
  con.fill( 130 );
  con.fill(  83 );
  con.fill(  99 );

  
  con.fill( 53 ); 
  con.fill( 1 );
  con.fill( msgType );

  
  con.fill( 12 ); 
  con.fill( strlen( hostName ) );
  con.fill( hostName );

  
  con.fill( 255 ); 

  con.send();
}


#line 15 "..\\EmbSysLib\\Src\\Com/Hardware/Net/Net.cpp"
#line 1 "..\\EmbSysLib\\Src\\Com/Hardware/Net/NetICMP.cpp"
#line 2 "..\\EmbSysLib\\Src\\Com/Hardware/Net/NetICMP.cpp"


cNetICMP::cNetICMP( cNetIP &ipIn )

: ip( ipIn )

{
  ip.setICMP( this );
}


void cNetICMP::process( void )
{
  cNetICMP_Msg &msg = *(cNetICMP_Msg*)ip.eth.buf;

  switch( msg.icmp.type )
  {
    case TYPE_ECHOREQUEST:

      WORD dataLen    = msg.ip.packetLength;
      WORD payloadLen = dataLen - (   sizeof( cNetIP_Header ) 
                                    + sizeof( cNetICMP_Header ) );
      ip.create( msg.eth.sourceAddr, 
                 msg.ip.sourceAddr, 
                 payloadLen+sizeof(cNetICMP_Header),
                 cNetIP::PROTOCOL_ICMP );

      msg.icmp.type = TYPE_ECHOREPLY;

      msg.icmp.checksum = 0;
      msg.icmp.checksum = Checksum( (BYTE*)&msg.ip, dataLen, 0 );

      ip.eth.PacketSend( ip.eth.buf,
                         sizeof( cHwEthernet_Header ) + dataLen );
      break;
  }
}


#line 16 "..\\EmbSysLib\\Src\\Com/Hardware/Net/Net.cpp"
#line 1 "..\\EmbSysLib\\Src\\Com/Hardware/Net/NetIP.cpp"






cNetIP::cNetIP( cHwEthernet &ethIn,
                const cNetAddr<4> &addrIn,
                cHwTimer &timer )

: eth         ( ethIn  ), 
  addr        ( addrIn ),
  arp         ( ethIn, addr ),
  timeOutTimer( timer  ),
  msg         ( *(cNetIP_Msg*)eth.buf )

{
  isNewIP_flag = false;
  
  tcp  = 0;
  udp  = 0;
  icmp = 0;
  eth.setIP( this );
}


void cNetIP::process( void )
{
  if( msg.ip.version_IHL == VERSION_IHL )
  {
    if(    msg.ip.destAddr == addr 
        || msg.ip.protocol == PROTOCOL_UDP )
    {
      switch( msg.ip.protocol )
      {
        case cNetIP::PROTOCOL_TCP:  if(  tcp ) {  tcp->process(); } break;
        case cNetIP::PROTOCOL_UDP:  if(  udp ) {  udp->process(); } break;
        case cNetIP::PROTOCOL_ICMP: if( icmp ) { icmp->process(); } break;
      }
    }
  }
}


void cNetIP::update( void )
{
  if(  tcp ) {  tcp->update(); }
  if(  udp ) {  udp->update(); }
  if( icmp ) { icmp->update(); }

  if( timeOutTimer.flag )
  {
    timeOutTimer.flag = false;

    if(  tcp )  {  tcp->timeout(); }
    if(  udp )  {  udp->timeout(); }
    if( icmp )  { icmp->timeout(); }
  }
}


void cNetIP::create( const cNetAddr<6> destAddrPhy,
                     const cNetAddr<4> destAddr,
                     const WORD        len,
                     const WORD        protocol )
{
  eth.create( destAddrPhy, cHwEthernet::TYPE_IP );
  
  msg.ip.version_IHL    = VERSION_IHL;
  msg.ip.TypeOfService  = 0;
  msg.ip.packetLength   = sizeof( cNetIP_Header ) + len;
  msg.ip.identification = 123;
  msg.ip.TTL            = 64;
  msg.ip.protocol       = protocol;
  msg.ip.sourceAddr     = addr;
  msg.ip.destAddr       = destAddr;

  msg.ip.setFlags         ( 0x40 ); 
  msg.ip.setFragmentOffset( 0x00 );

  msg.ip.headerChecksum = 0; 
  msg.ip.headerChecksum = Checksum( (BYTE*)&msg.ip, 
                                     sizeof( cNetIP_Header ), 
                                     0 );
}


inline void cNetIP::setTCP( cNetTCP *tcpIn )
{
  tcp = tcpIn;
  arp.setTCP( tcpIn );
}


inline void cNetIP::setUDP( cNetUDP *udpIn )
{
  udp = udpIn;
  arp.setUDP( udpIn );
}


inline void cNetIP::setICMP( cNetICMP *icmpIn )
{
  icmp = icmpIn;
}



#line 17 "..\\EmbSysLib\\Src\\Com/Hardware/Net/Net.cpp"
#line 1 "..\\EmbSysLib\\Src\\Com/Hardware/Net/NetTCP.cpp"








cNetTCP::cNetTCP( cNetIP   &ipIn )

: cNetTransport( ),
  ip( ipIn )

{
  ip.arp.setTCP( this );
  ip.setTCP    ( this );
}


void cNetTCP::create( Socket &con, WORD payloadLen )
{
  cNetTCP::Msg &msg = *(cNetTCP::Msg*)ip.eth.buf;

  
  
  msg.tcp.sourcePort        = con.myPort;
  msg.tcp.destPort          = con.remotePort;
  msg.tcp.sequenceNumber    = con.seqNum;
  msg.tcp.acknowledgeNumber = con.ackNum;
  msg.tcp.setFlags( con.flags );
  msg.tcp.windowSize        = 1000;
  msg.tcp.urgentPointer     = 0;

  if (con.mss > 0 )
  {
    
    
    
    ip.eth.buf[ sizeof( cNetTCP::Msg)    ] = 2;
    ip.eth.buf[ sizeof( cNetTCP::Msg) + 1] = 4;
    ip.eth.buf[ sizeof( cNetTCP::Msg) + 2] = 0x05;
    ip.eth.buf[ sizeof( cNetTCP::Msg) + 3] = 0x80;
    payloadLen += 4;

    msg.tcp.setDataOffset( 24 );
  }
  else
  {
    msg.tcp.setDataOffset( 20 );
  }

  ip.create( con.addrPhy,
             con.addr,
             payloadLen+sizeof(cNetTCP::Header),
             cNetIP::PROTOCOL_TCP );

  
  WORD  len = sizeof( cNetTCP::Header) + payloadLen;

  msg.tcp.checksum = 0;
  msg.tcp.checksum = Checksum( (BYTE*)&msg.ip.sourceAddr,
                                len + 8,
                                (DWORD)len + cNetIP::PROTOCOL_TCP );

  ip.eth.PacketSend( ip.eth.buf, sizeof( cNetTCP::Msg) + payloadLen );
}



cNetTCP::Socket::Socket( cNetTCP         &tcpIn,
                         cNetApplication &appIn,
                         cNetAddr<4>      inAddrIn,
                         WORD             portIn )

: cNetTransport::Socket( (cNetTransport &)tcpIn,
                         appIn,
                         inAddrIn,
                         portIn ),
  tcp( tcpIn )

{
  initialSeqNum = 10000;
}


void cNetTCP::Socket::open( cNetAddr<4> addrIn,
                            WORD        portIn )
{
  initialSeqNum += 10000; 

  remotePort = portIn;
  flags      = cNetTCP::FLAG_SYN;
  addrPhy    = zeroAddrPhy;
  addr       = zeroAddr;
  seqNum     = initialSeqNum;
  ackNum     = 0;
  mss        = true;

  if( addr == addrIn && !(addrPhy == zeroAddrPhy))
  {
    state = STATE_OPEN_WAIT_SERVER;
    clear();
    tcp.create( *this, tcp.ip.eth.plen );
    setTimeout( 3 );    
  }
  else if( !(addr == broadcastAddr) )
  {
    state = STATE_OPEN_WAIT_ARP;
    addr = addrIn;
    clear();
    tcp.ip.arp.request( addr );
    setTimeout( 6 );
  }
}


void cNetTCP::Socket::close( void )
{
  if( state != STATE_FINISHING )
  {
    state  = STATE_FINISHING;
    flags  = cNetTCP::FLAG_FIN | cNetTCP::FLAG_ACK;
    tcp.create( *this, tcp.ip.eth.plen );
    seqNum += tcp.ip.eth.plen;
    setTimeout( 3 );
    clear();
  }
}


BYTE cNetTCP::Socket::isConnected( void )
{
  return(    state == STATE_CONNECTED
          || state == STATE_CONNECTED_WAIT_ACK );
}


BYTE cNetTCP::Socket::isReady( void )
{
  return(    !(tcp.ip.addr == zeroAddr)
          &&   state == STATE_WAITING );
}


void cNetTCP::Socket::clear( void )
{
  tcp.ip.eth.plen = 0;
}


void cNetTCP::Socket::fillBuffer( const char c )
{
  WORD pos = sizeof( cNetTCP::Msg ) + tcp.ip.eth.plen;

  if( pos < 1500 )
  {
    tcp.ip.eth.buf[pos] = c;
    tcp.ip.eth.plen++;
  }

  if( pos + 1 >= 1500 )
  {
    send();
  }
}


void cNetTCP::Socket::send( void )
{
  tcp.create( *this, tcp.ip.eth.plen );
  seqNum += tcp.ip.eth.plen;
  setTimeout( 3 );
  ackNumExpected = seqNum;
  state = STATE_CONNECTED_WAIT_ACK;
  clear( );
}


BYTE cNetTCP::Socket::get( char *c )
{
  if( tcp.inPos < tcp.inBufLen )
  {
    *c = tcp.buf[tcp.inPos++];
    return( true );
  }
  return( false );
}


BYTE *cNetTCP::Socket::getDataPtr( void )
{
  return( (BYTE*)&tcp.ip.eth.buf[ sizeof(cNetTCP::Msg) ] );
}


void cNetTCP::Socket::setDataLength( WORD len )
{
  tcp.ip.eth.plen = len;
}



BYTE cNetTCP::Socket::process( void )
{
  cNetTCP::Msg &msg = *(cNetTCP::Msg*)tcp.ip.eth.buf;

  WORD  flagsMsg   = msg.tcp.getFlags();
  DWORD ackNumMsg  = msg.tcp.acknowledgeNumber;
  DWORD seqNumMsg  = msg.tcp.sequenceNumber;

  WORD dataLen =   msg.ip.packetLength
                 - sizeof(cNetIP_Header)
                 - msg.tcp.getDataOffset();

  

  BYTE *dataPtr = 0;

  if( dataLen > 0 )
  {
    WORD idx = sizeof( cNetIP_Msg ) + msg.tcp.getDataOffset();
    if( idx > 0 )
    {
      dataPtr = &tcp.ip.eth.buf[ idx ];
    }
  }

  
  tcp.ip.eth.plen = 0;

  if( !(myPort == msg.tcp.destPort) )
  {
    return( false );
  }

  if( flagsMsg & cNetTCP::FLAG_RST )
  {
    
    state = STATE_WAITING;
    mss   = false;
    return( true );
  }

  switch( state )
  {
    case STATE_WAITING:
      if( flagsMsg & cNetTCP::FLAG_SYN )
      {
        state   = Socket::STATE_PENDING;
        addr    = msg.ip.sourceAddr;
        remotePort    = msg.tcp.sourcePort;
        addrPhy = msg.eth.sourceAddr;
        flags   = cNetTCP::FLAG_SYN | cNetTCP::FLAG_ACK;
        mss     = true;

        initialSeqNum += 10000;

        seqNum = initialSeqNum;
        ackNum = seqNumMsg + 1;

        tcp.create( *this, tcp.ip.eth.plen );
        setTimeout( 3 );
        return( true) ;
      }
      break;

    case STATE_PENDING:
      if( flagsMsg & cNetTCP::FLAG_ACK )
      {
        state = STATE_CONNECTED;
        mss   = false;
      }
      seqNum = seqNum + 1;
      ackNum = seqNumMsg  + 1;
      break;

    case STATE_OPEN_WAIT_SERVER:
      if( flagsMsg & cNetTCP::FLAG_ACK )
      {
        state  = STATE_CONNECTED;
        mss    = false;
        flags  = cNetTCP::FLAG_ACK;
        seqNum = seqNum + 1;
        ackNum = seqNumMsg  + 1;

        tcp.create( *this, tcp.ip.eth.plen );
        setTimeout( 0 );
        return( true );
      }
      break;

    case STATE_CONNECTED:
      if( flagsMsg & cNetTCP::FLAG_FIN )
      {
        state  = Socket::STATE_FINISHING;
        flags  = cNetTCP::FLAG_FIN | cNetTCP::FLAG_ACK;
        seqNum = ackNumMsg;
        ackNum = seqNumMsg + dataLen;
        tcp.ip.eth.plen = 0;      

        tcp.create( *this, tcp.ip.eth.plen );
        setTimeout( 3 );
        return( true );
      }
      else
      {
        state  = Socket::STATE_CONNECTED_WAIT_ACK;

        flags = cNetTCP::FLAG_ACK;
      }
      seqNum = ackNumMsg;
      ackNum = seqNumMsg + dataLen;
      break;

    case STATE_CONNECTED_WAIT_ACK:
      if(   ( flagsMsg & cNetTCP::FLAG_ACK )
           && ackNumMsg == ackNumExpected  )
      {
        state = STATE_CONNECTED;
        flags = cNetTCP::FLAG_NONE;
      }

      if( dataLen > 0 )
      {
        flags = cNetTCP::FLAG_ACK;
      }
      seqNum = ackNumMsg;
      ackNum = seqNumMsg + dataLen;
      break;

    case STATE_FINISHING:
      if( flagsMsg & cNetTCP::FLAG_FIN )
      {
        if( flagsMsg & cNetTCP::FLAG_ACK )
        {
          state  = Socket::STATE_WAITING;
          setTimeout(0 );
          flags  = cNetTCP::FLAG_ACK;
          seqNum = ackNumMsg;
          ackNum = seqNumMsg + dataLen + 1;

          tcp.create( *this, tcp.ip.eth.plen );
          return( true );
        }
        else
        {
         
          
          setTimeout( 3 );
          flags  = cNetTCP::FLAG_ACK;
          seqNum = ackNumMsg + 1;
          ackNum = seqNumMsg + dataLen + 1;

          tcp.create( *this, tcp.ip.eth.plen );
          return( true );
        }
      }
      seqNum = ackNumMsg;
      ackNum = seqNumMsg + dataLen;
      break;
  } 

  if( dataLen > 0 )
  {
    seqNum = ackNumMsg;
    ackNum = seqNumMsg + dataLen;

    tcp.buf = dataPtr;
    tcp.inPos = 0;
    tcp.inBufLen = dataLen;

    app.OnReceive();
  }

  return( true );
}


void cNetTCP::Socket::update( void )
{
  if(      state   == STATE_OPEN_WAIT_ARP
      && !(addrPhy == zeroAddrPhy) )
  {
    clear( );
    tcp.create( *this, tcp.ip.eth.plen );
    setTimeout( 3 );
    state = STATE_OPEN_WAIT_SERVER;
  }
}


void cNetTCP::Socket::timeout( void )
{
  if( timeOutTic && !(--timeOutTic) )
  {
   
    switch( state )
    {
      case STATE_PENDING:
      case STATE_OPEN_WAIT_SERVER:
      case STATE_OPEN_WAIT_ARP:
      case STATE_CONNECTED_WAIT_ACK:
      case STATE_FINISHING:

        state = STATE_WAITING;
        break;
    }
    app.OnError();
  }




    app.update();

}


void cNetTCP::handleARP( cNetAddr<4> addr, cNetAddr<6> addrPhy )
{
  Socket *ptr = (Socket *)appList.getFirst();
  while( ptr )
  {
    if(    ptr->addr == addr
        && (   ptr->state == Socket::STATE_WAITING
            || ptr->state == Socket::STATE_OPEN_WAIT_ARP ) )
    {
      ptr->addrPhy = addrPhy;
      ptr->state = Socket::STATE_OPEN_WAIT_ARP; 
    }
    ptr = (Socket *)ptr->getNext();
  }
}


#line 18 "..\\EmbSysLib\\Src\\Com/Hardware/Net/Net.cpp"
#line 1 "..\\EmbSysLib\\Src\\Com/Hardware/Net/NetUDP.cpp"




cNetUDP::cNetUDP( cNetIP &ipIn ) 

: cNetTransport( ),
  ip( ipIn )

{
  ip.setUDP( this );

}


void cNetUDP::create( Socket &con, WORD payloadLen )
{
  cNetUDP_Msg &msg = *(cNetUDP_Msg*)ip.eth.buf;

  msg.udp.sourcePort = con.myPort;
  msg.udp.destPort   = con.remotePort;
  msg.udp.length     = sizeof( cNetUDP_Header ) + payloadLen;

  ip.create( con.addrPhy,
             con.addr,
             payloadLen+sizeof(cNetUDP_Header),
             cNetIP::PROTOCOL_UDP );

  
  WORD  len = sizeof( cNetUDP_Header) + payloadLen;

  msg.udp.checksum = 0;
  msg.udp.checksum = Checksum( (BYTE*)&msg.ip.sourceAddr,
                                len + 8,
                                (DWORD)len + cNetIP::PROTOCOL_UDP );

  ip.eth.PacketSend( ip.eth.buf,
                     sizeof( cNetUDP_Msg) + payloadLen );
}





cNetUDP::Socket::Socket( cNetUDP         &udpIn,
                         cNetApplication &appIn,
                         cNetAddr<4>      inAddrIn,
                         WORD             portIn,
                         WORD             updateTime )

: cNetTransport::Socket( (cNetTransport &)udpIn,
                         appIn,
                         inAddrIn,
                         portIn ),
  udp( udpIn )
{
}



void cNetUDP::Socket::open( cNetAddr<4> addrIn,
                            WORD        portIn )
{
  addr = addrIn;
  remotePort = portIn;

  if( addrIn == broadcastAddr )
  {
    addrPhy = broadcastAddrPhy;
    state   = STATE_WAITING;
  }
  else
  {
    state = STATE_OPEN_WAIT_ARP;
    udp.ip.arp.request( addr );
  }
  setTimeout( 5 );
}


void cNetUDP::Socket::close( void )
{
  state = STATE_WAITING;
}


BYTE cNetUDP::Socket::isConnected( void )
{
  return( state == STATE_CONNECTED );
}


BYTE cNetUDP::Socket::isReady( void )
{
  return(    !(udp.ip.addr == zeroAddr)
          &&   state == STATE_WAITING );
}


void cNetUDP::Socket::clear( void )
{
  udp.ip.eth.plen = 0;
}


void cNetUDP::Socket::fillBuffer( const char c )
{
  WORD pos = sizeof( cNetUDP_Msg ) + udp.ip.eth.plen;

  if( pos < 1500 )
  {
    udp.ip.eth.buf[pos] = c;
    udp.ip.eth.plen++;
  }

  if( pos + 1 >= 1500 )
  {
    send( );
  }
}


void cNetUDP::Socket::send( void )
{
  udp.create( *this, udp.ip.eth.plen );

  udp.ip.eth.plen = 0;
}


BYTE cNetUDP::Socket::get( char *c )
{
  if( udp.inPos < udp.inBufLen )
  {
    *c = udp.buf[udp.inPos++];
    return( true );
  }
  return( false );
}


BYTE *cNetUDP::Socket::getDataPtr( void )
{
  return( (BYTE*)&udp.ip.eth.buf[ sizeof(cNetUDP_Msg) ] );
}


void cNetUDP::Socket::setDataLength( WORD len )
{
  udp.ip.eth.plen = len;
}



BYTE cNetUDP::Socket::process( void )
{
  cNetUDP_Msg &msg = *(cNetUDP_Msg*)udp.ip.eth.buf;

  if( !(myPort == msg.udp.destPort) )
  {
    return( false );
  }

  WORD  dataLen = msg.udp.length - sizeof(cNetUDP_Header);
  BYTE *dataPtr = 0;;

  if( dataLen > 0 )
  {
    WORD idx = sizeof( cNetUDP_Msg );
    dataPtr  = &udp.ip.eth.buf[ idx ];
  }

  if( state == STATE_WAITING
      && (   remoteAddr == broadcastAddr
          || remoteAddr == msg.ip.sourceAddr ) )
  {
    addrPhy = msg.eth.sourceAddr;
    addr    = msg.ip.sourceAddr;
    remotePort    = msg.udp.sourcePort;
    state   = STATE_CONNECTED;
  }
  if(    state == Socket::STATE_CONNECTED
      && dataLen > 0 )
  {
    udp.buf          = dataPtr;
    udp.inPos        = 0;
    udp.inBufLen     = dataLen;

    app.OnReceive();
  }

  return( true );
}


void cNetUDP::Socket::update( void )
{
  if(      state == STATE_OPEN_WAIT_ARP
      && !(addrPhy == zeroAddrPhy) )
  {
    state = STATE_CONNECTED;
  }






}


void cNetUDP::Socket::timeout( void )
{
  if( timeOutTic && !(--timeOutTic) )
  {

    switch( state )
    {
      case STATE_OPEN_WAIT_ARP:
        state = STATE_WAITING;
        break;
    }
    app.OnError();
  }




    app.update();

}


void cNetUDP::handleARP( cNetAddr<4> addr, cNetAddr<6> addrPhy )
{
  Socket *ptr = (Socket *)appList.getFirst();
  while( ptr )
  {
    if(    ptr->addr == addr
        && (   ptr->state == Socket::STATE_WAITING
            || ptr->state == Socket::STATE_OPEN_WAIT_ARP ) )
    {
      ptr->addrPhy = addrPhy;
      ptr->state = Socket::STATE_OPEN_WAIT_ARP;
    }
    ptr = (Socket *)ptr->getNext();
  }
}



#line 19 "..\\EmbSysLib\\Src\\Com/Hardware/Net/Net.cpp"



#line 55 "..\\EmbSysLib\\Src\\lib.cpp"













 











#line 1 "..\\EmbSysLib\\Src\\Com/Device/Analog/devAnalog.cpp"







 







cDevAnalog::cDevAnalog( BYTE  channelIn,
                        float gainIn,
                        float offsetIn )
{
  channel = channelIn;
  gain    = gainIn;
  offs    = offsetIn;
}


#line 81 "..\\EmbSysLib\\Src\\lib.cpp"
#line 1 "..\\EmbSysLib\\Src\\Com/Device/Analog/devAnalogIn.cpp"







 


#line 12 "..\\EmbSysLib\\Src\\Com/Device/Analog/devAnalogIn.cpp"







cDevAnalogIn::cDevAnalogIn( BYTE  channel,
                            float max,
                            float min )

: cDevAnalog( channel,
              (max-min)/(float)0xFFFF,
               min )

{
}


inline float cDevAnalogIn::get( void )
{
  return( gain*getRaw() + offs );
}


inline cDevAnalogIn::operator float( void )
{
  return( get() );
}


void cDevAnalogIn::calibrate( float x1, 
                              float y1,
                              float x2,
                              float y2
                            )
{
  if( x1 != x2 ) 
  {
    gain = (y2-y1)/(x2-x1);
    offs = y1 - gain*x1;
  }
}


#line 82 "..\\EmbSysLib\\Src\\lib.cpp"
#line 1 "..\\EmbSysLib\\Src\\Com/Device/Analog/devAnalogInADC.cpp"







 


#line 12 "..\\EmbSysLib\\Src\\Com/Device/Analog/devAnalogInADC.cpp"







cDevAnalogInADC::cDevAnalogInADC( cHwADC &adcIn,
                                  BYTE    channel,
                                  float   max,
                                  float   min,
                                  BYTE    para )

: cDevAnalogIn( channel, max, min ),
  adc         ( adcIn )

{
  adc.enable( channel, para );
}


WORD cDevAnalogInADC::getRaw( void )
{
  return( adc.get( channel ) );
}

void cDevAnalogInADC::enable()
{
    adc.enable( channel, 0 );
}

#line 83 "..\\EmbSysLib\\Src\\lib.cpp"
#line 1 "..\\EmbSysLib\\Src\\Com/Device/Analog/devAnalogOut.cpp"







 


#line 12 "..\\EmbSysLib\\Src\\Com/Device/Analog/devAnalogOut.cpp"







cDevAnalogOut::cDevAnalogOut( BYTE  channel,
                              float max,
                              float min )

: cDevAnalog( channel,
              (float)0xFFFF*( (max != min) ? 1.0F/(max-min) : 1.0F ),
              min )

{
}


void cDevAnalogOut::set( float value )
{
  setRaw( (WORD)RANGE( gain*(value - offs),
                      (float)0,
                      (float)0xFFFF) );
}


inline float cDevAnalogOut::operator=( float value )
{
  set( value );
  return( value );
}


#line 84 "..\\EmbSysLib\\Src\\lib.cpp"
#line 1 "..\\EmbSysLib\\Src\\Com/Device/Analog/devAnalogOutDAC.cpp"







 


#line 12 "..\\EmbSysLib\\Src\\Com/Device/Analog/devAnalogOutDAC.cpp"







cDevAnalogOutDAC::cDevAnalogOutDAC( cHwDAC &dacIn,
                                    BYTE    channel,
                                    float   max,
                                    float   min )

:cDevAnalogOut( channel, max, min ),
 dac          ( dacIn )

{
  dac.enable( channel );
}


void cDevAnalogOutDAC::setRaw( WORD value )
{
  dac.set( value, channel );
}


#line 85 "..\\EmbSysLib\\Src\\lib.cpp"
#line 1 "..\\EmbSysLib\\Src\\Com/Device/Analog/devAnalogOutPWM.cpp"








 


#line 13 "..\\EmbSysLib\\Src\\Com/Device/Analog/devAnalogOutPWM.cpp"







cDevAnalogOutPWM::cDevAnalogOutPWM( cHwTimer       &timerIn,
                                    cHwTimer::Mode  mode,
                                    BYTE            channel,
                                    float           max,
                                    float           min )

: cDevAnalogOut( channel, max, min ),
  timer        ( timerIn )

{
  timer.enablePWM( channel, mode );
}


void cDevAnalogOutPWM::setRaw( WORD value )
{
  timer.setPWM( value, channel );
}







cDevAnalogOutPWMemul::cDevAnalogOutPWMemul( cHwTimer    &timerIn,
                                            cDevDigital &portIn,
                                            BYTE         resIn,
                                            float        maxIn,
                                            float        minIn )
: cDevAnalogOut( 0, maxIn, minIn ),
  timer        ( timerIn         ),
  port         ( portIn          )

{
  shift = 16 - resIn;
  max   = (WORD)(0x0001L << resIn) - 1;
  t     = 0;
  timer.add(this);
}


void cDevAnalogOutPWMemul::setRaw( WORD value )
{
  limitBuf << (WORD)(value>>shift);
}


void cDevAnalogOutPWMemul::update( void )
{
  if( t >= max )
  {
    t = 0;
    port.set();
    limitBuf >> limit;
  }
  if( t == limit )
  {
    port.clr();
  }
  t++;
}


#line 86 "..\\EmbSysLib\\Src\\lib.cpp"




#line 1 "..\\EmbSysLib\\Src\\Com/Device/Digital/devDigital.cpp"







 


#line 12 "..\\EmbSysLib\\Src\\Com/Device/Digital/devDigital.cpp"







cDevDigital::cDevDigital( cHwPort &port,
                          BYTE     pinId,
                          Mode     mode,
                          bool     def  )
: pin( port, pinId )
{
  valueIn     = 0;
  valueOut    = 0;
  pinDefault  = def;

  pin.set( def );
  pin.setMode( (cHwPort::Mode)mode );
}


void cDevDigital::setMode( Mode mode )
{
  pin.setMode( (cHwPort::Mode)mode );
}


void cDevDigital::set( bool value )
{
  valueOut = value;
  pin.set( value ^ pinDefault );
}


bool cDevDigital::get( void )
{
  return( pin.get() != pinDefault );
}


#line 91 "..\\EmbSysLib\\Src\\lib.cpp"
#line 1 "..\\EmbSysLib\\Src\\Com/Device/Digital/devDigitalIndicator.cpp"







 


#line 12 "..\\EmbSysLib\\Src\\Com/Device/Digital/devDigitalIndicator.cpp"







cDevDigitalIndicator::cDevDigitalIndicator( cDevDigital &devDigitalIn,
                                            cHwTimer    &timerIn )
: devDigital( devDigitalIn ),
  timer     ( timerIn      )
{
  timeout   = 0;
  cycleTime = timer.getCycleTime();
  clr();
  timer.add(this);

    limit = 0;
    maxi  = 1000;
    pwr   = 1;
    mean  = 0;
    t = 0;
    p = 0;
    G = 25E3/cycleTime; 
    P=0;
    M=G;
    maxi = 1;
    limit = 0;
    pwr = 0;
    blink_flag=false;

}


void cDevDigitalIndicator::update( void )
{
  if( timeout > 0 )
  {
    timeout--;
    if( timeout == 0 )
    {
      clr();
    }
  }

  else if( blink_flag )
  {
    if( mean <= 0 )
    {
       devDigital.set(0);
       mean += P;
    }
    else
    {
       devDigital.set(1);
       mean -= M;
    }

    t++;
    if( t>=maxi)
    {
        P = pwr;
        M = G-pwr;
        t  = 0;
    }
    else if(t>limit)
    {
        P=0;
        M=G;
    }
  }
}


#line 92 "..\\EmbSysLib\\Src\\lib.cpp"




#line 1 "..\\EmbSysLib\\Src\\Com/Device/Display/devDisplay.cpp"







 







cDevDisplay::cDevDisplay( void )
{
}


#line 97 "..\\EmbSysLib\\Src\\lib.cpp"
#line 1 "..\\EmbSysLib\\Src\\Com/Device/Display/devDisplayChar.cpp"







 


#line 12 "..\\EmbSysLib\\Src\\Com/Device/Display/devDisplayChar.cpp"
#line 13 "..\\EmbSysLib\\Src\\Com/Device/Display/devDisplayChar.cpp"







cDevDisplayChar::cDevDisplayChar( cHwDisplay &displayIn )

: display( displayIn )

{
  display.clear();
}


void cDevDisplayChar::clear(void)
{
  display.clear();
}


void cDevDisplayChar::refresh(void)
{
  display.refresh();
}


void cDevDisplayChar::printf( BYTE        line,
                              BYTE        column,
                              BYTE        minLen,
                              const char *format,
                              ... )
{
  BYTE i;

  
  char str[32]; 

  va_list argzeiger;
  __va_start(argzeiger, format);
  vsnprintf( str, 31, format, argzeiger );
  __va_end(argzeiger);

  display.gotoTextPos( line, column );

  
  for( i = 0; str[i] != 0 && i<30; i++ )
  {
    display.putChar( str[i] );
  }

  
  for(   ; i < minLen; i++)
  {
    display.putChar( ' ' );
  }
}


void cDevDisplayChar::printf( BYTE        line,
                              BYTE        column,
                              const char *str )
{
  BYTE i;

  display.gotoTextPos( line, column );

  
  for( i = 0; str[i] != 0; i++ )
  {
    display.putChar( str[i] );
  }
}


#line 98 "..\\EmbSysLib\\Src\\lib.cpp"
#line 1 "..\\EmbSysLib\\Src\\Com/Device/Display/devDisplayGraphic.cpp"





 


#line 10 "..\\EmbSysLib\\Src\\Com/Device/Display/devDisplayGraphic.cpp"
#line 11 "..\\EmbSysLib\\Src\\Com/Device/Display/devDisplayGraphic.cpp"
#line 1 "C:\\Bin\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\math.h"




 





 












 






   









 






#line 61 "C:\\Bin\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\math.h"

#line 75 "C:\\Bin\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\math.h"







   




 















 
#line 112 "C:\\Bin\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\math.h"











 


      extern "C" {


extern __attribute__((__pcs__("aapcs"))) unsigned __ARM_dcmp4(double  , double  );
extern __attribute__((__pcs__("aapcs"))) unsigned __ARM_fcmp4(float  , float  );
    




 

extern __declspec(__nothrow) __attribute__((__pcs__("aapcs"))) int __ARM_fpclassifyf(float  );
extern __declspec(__nothrow) __attribute__((__pcs__("aapcs"))) int __ARM_fpclassify(double  );
     
     

inline __declspec(__nothrow) __attribute__((__pcs__("aapcs"))) int __ARM_isfinitef(float __x)
{
    return (((*(unsigned *)&(__x)) >> 23) & 0xff) != 0xff;
}
inline __declspec(__nothrow) __attribute__((__pcs__("aapcs"))) int __ARM_isfinite(double __x)
{
    return (((*(1 + (unsigned *)&(__x))) >> 20) & 0x7ff) != 0x7ff;
}
     
     

inline __declspec(__nothrow) __attribute__((__pcs__("aapcs"))) int __ARM_isinff(float __x)
{
    return ((*(unsigned *)&(__x)) << 1) == 0xff000000;
}
inline __declspec(__nothrow) __attribute__((__pcs__("aapcs"))) int __ARM_isinf(double __x)
{
    return (((*(1 + (unsigned *)&(__x))) << 1) == 0xffe00000) && ((*(unsigned *)&(__x)) == 0);
}
     
     

inline __declspec(__nothrow) __attribute__((__pcs__("aapcs"))) int __ARM_islessgreaterf(float __x, float __y)
{
    unsigned __f = __ARM_fcmp4(__x, __y) >> 28;
    return (__f == 8) || (__f == 2);  
}
inline __declspec(__nothrow) __attribute__((__pcs__("aapcs"))) int __ARM_islessgreater(double __x, double __y)
{
    unsigned __f = __ARM_dcmp4(__x, __y) >> 28;
    return (__f == 8) || (__f == 2);  
}
    


 

inline __declspec(__nothrow) __attribute__((__pcs__("aapcs"))) int __ARM_isnanf(float __x)
{
    return (0x7f800000 - ((*(unsigned *)&(__x)) & 0x7fffffff)) >> 31;
}
inline __declspec(__nothrow) __attribute__((__pcs__("aapcs"))) int __ARM_isnan(double __x)
{
    unsigned __xf = (*(1 + (unsigned *)&(__x))) | (((*(unsigned *)&(__x)) == 0) ? 0 : 1);
    return (0x7ff00000 - (__xf & 0x7fffffff)) >> 31;
}
     
     

inline __declspec(__nothrow) __attribute__((__pcs__("aapcs"))) int __ARM_isnormalf(float __x)
{
    unsigned __xe = ((*(unsigned *)&(__x)) >> 23) & 0xff;
    return (__xe != 0xff) && (__xe != 0);
}
inline __declspec(__nothrow) __attribute__((__pcs__("aapcs"))) int __ARM_isnormal(double __x)
{
    unsigned __xe = ((*(1 + (unsigned *)&(__x))) >> 20) & 0x7ff;
    return (__xe != 0x7ff) && (__xe != 0);
}
     
     

inline __declspec(__nothrow) __attribute__((__pcs__("aapcs"))) int __ARM_signbitf(float __x)
{
    return (*(unsigned *)&(__x)) >> 31;
}
inline __declspec(__nothrow) __attribute__((__pcs__("aapcs"))) int __ARM_signbit(double __x)
{
    return (*(1 + (unsigned *)&(__x))) >> 31;
}
     
     


      }  






      namespace std {

        extern "C" {










   
  typedef float float_t;
  typedef double double_t;
#line 251 "C:\\Bin\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\math.h"



extern const int math_errhandling;
#line 261 "C:\\Bin\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\math.h"

extern __declspec(__nothrow) double acos(double  );
    
    
    
extern __declspec(__nothrow) double asin(double  );
    
    
    
    

extern __declspec(__nothrow) __attribute__((const)) double atan(double  );
    
    

extern __declspec(__nothrow) double atan2(double  , double  );
    
    
    
    

extern __declspec(__nothrow) double cos(double  );
    
    
    
    
extern __declspec(__nothrow) double sin(double  );
    
    
    
    

extern void __use_accurate_range_reduction(void);
    
    

extern __declspec(__nothrow) double tan(double  );
    
    
    
    

extern __declspec(__nothrow) double cosh(double  );
    
    
    
    
extern __declspec(__nothrow) double sinh(double  );
    
    
    
    
    

extern __declspec(__nothrow) __attribute__((const)) double tanh(double  );
    
    

extern __declspec(__nothrow) double exp(double  );
    
    
    
    
    

extern __declspec(__nothrow) double frexp(double  , int *  ) __attribute__((__nonnull__(2)));
    
    
    
    
    
    

extern __declspec(__nothrow) double ldexp(double  , int  );
    
    
    
    
extern __declspec(__nothrow) double log(double  );
    
    
    
    
    
extern __declspec(__nothrow) double log10(double  );
    
    
    
extern __declspec(__nothrow) double modf(double  , double *  ) __attribute__((__nonnull__(2)));
    
    
    
    

extern __declspec(__nothrow) double pow(double  , double  );
    
    
    
    
    
    
extern __declspec(__nothrow) double sqrt(double  );
    
    
    




    inline double _sqrt(double __x) { return sqrt(__x); }


    inline float _sqrtf(float __x) { return __sqrtf(__x); }



    



 

extern __declspec(__nothrow) __attribute__((const)) double ceil(double  );
    
    
extern __declspec(__nothrow) __attribute__((const)) double fabs(double  );
    
    

extern __declspec(__nothrow) __attribute__((const)) double floor(double  );
    
    

extern __declspec(__nothrow) double fmod(double  , double  );
    
    
    
    
    

    









 



extern __declspec(__nothrow) double acosh(double  );
    

 
extern __declspec(__nothrow) double asinh(double  );
    

 
extern __declspec(__nothrow) double atanh(double  );
    

 
extern __declspec(__nothrow) double cbrt(double  );
    

 
inline __declspec(__nothrow) __attribute__((const)) double copysign(double __x, double __y)
    

 
{
    (*(1 + (unsigned *)&(__x))) = ((*(1 + (unsigned *)&(__x))) & 0x7fffffff) | ((*(1 + (unsigned *)&(__y))) & 0x80000000);
    return __x;
}
inline __declspec(__nothrow) __attribute__((const)) float copysignf(float __x, float __y)
    

 
{
    (*(unsigned *)&(__x)) = ((*(unsigned *)&(__x)) & 0x7fffffff) | ((*(unsigned *)&(__y)) & 0x80000000);
    return __x;
}
extern __declspec(__nothrow) double erf(double  );
    

 
extern __declspec(__nothrow) double erfc(double  );
    

 
extern __declspec(__nothrow) double expm1(double  );
    

 



    

 






#line 479 "C:\\Bin\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\math.h"


extern __declspec(__nothrow) double hypot(double  , double  );
    




 
extern __declspec(__nothrow) int ilogb(double  );
    

 
extern __declspec(__nothrow) int ilogbf(float  );
    

 
extern __declspec(__nothrow) int ilogbl(long double  );
    

 







    

 





    



 





    



 





    

 





    



 





    



 





    



 





    

 





    

 





    


 

extern __declspec(__nothrow) double lgamma (double  );
    


 
extern __declspec(__nothrow) double log1p(double  );
    

 
extern __declspec(__nothrow) double logb(double  );
    

 
extern __declspec(__nothrow) float logbf(float  );
    

 
extern __declspec(__nothrow) long double logbl(long double  );
    

 
extern __declspec(__nothrow) double nextafter(double  , double  );
    


 
extern __declspec(__nothrow) float nextafterf(float  , float  );
    


 
extern __declspec(__nothrow) long double nextafterl(long double  , long double  );
    


 
extern __declspec(__nothrow) double nexttoward(double  , long double  );
    


 
extern __declspec(__nothrow) float nexttowardf(float  , long double  );
    


 
extern __declspec(__nothrow) long double nexttowardl(long double  , long double  );
    


 
extern __declspec(__nothrow) double remainder(double  , double  );
    

 
extern __declspec(__nothrow) __attribute__((const)) double rint(double  );
    

 
extern __declspec(__nothrow) double scalbln(double  , long int  );
    

 
extern __declspec(__nothrow) float scalblnf(float  , long int  );
    

 
extern __declspec(__nothrow) long double scalblnl(long double  , long int  );
    

 
extern __declspec(__nothrow) double scalbn(double  , int  );
    

 
extern __declspec(__nothrow) float scalbnf(float  , int  );
    

 
extern __declspec(__nothrow) long double scalbnl(long double  , int  );
    

 




    

 



 
extern __declspec(__nothrow) __attribute__((const)) float _fabsf(float);  
inline __declspec(__nothrow) __attribute__((const)) float fabsf(float __f) { return _fabsf(__f); }
extern __declspec(__nothrow) float sinf(float  );
extern __declspec(__nothrow) float cosf(float  );
extern __declspec(__nothrow) float tanf(float  );
extern __declspec(__nothrow) float acosf(float  );
extern __declspec(__nothrow) float asinf(float  );
extern __declspec(__nothrow) float atanf(float  );
extern __declspec(__nothrow) float atan2f(float  , float  );
extern __declspec(__nothrow) float sinhf(float  );
extern __declspec(__nothrow) float coshf(float  );
extern __declspec(__nothrow) float tanhf(float  );
extern __declspec(__nothrow) float expf(float  );
extern __declspec(__nothrow) float logf(float  );
extern __declspec(__nothrow) float log10f(float  );
extern __declspec(__nothrow) float powf(float  , float  );
extern __declspec(__nothrow) float sqrtf(float  );
extern __declspec(__nothrow) float ldexpf(float  , int  );
extern __declspec(__nothrow) float frexpf(float  , int *  ) __attribute__((__nonnull__(2)));
extern __declspec(__nothrow) __attribute__((const)) float ceilf(float  );
extern __declspec(__nothrow) __attribute__((const)) float floorf(float  );
extern __declspec(__nothrow) float fmodf(float  , float  );
extern __declspec(__nothrow) float modff(float  , float *  ) __attribute__((__nonnull__(2)));

 
 













 
__declspec(__nothrow) long double acosl(long double );
__declspec(__nothrow) long double asinl(long double );
__declspec(__nothrow) long double atanl(long double );
__declspec(__nothrow) long double atan2l(long double , long double );
__declspec(__nothrow) long double ceill(long double );
__declspec(__nothrow) long double cosl(long double );
__declspec(__nothrow) long double coshl(long double );
__declspec(__nothrow) long double expl(long double );
__declspec(__nothrow) long double fabsl(long double );
__declspec(__nothrow) long double floorl(long double );
__declspec(__nothrow) long double fmodl(long double , long double );
__declspec(__nothrow) long double frexpl(long double , int* ) __attribute__((__nonnull__(2)));
__declspec(__nothrow) long double ldexpl(long double , int );
__declspec(__nothrow) long double logl(long double );
__declspec(__nothrow) long double log10l(long double );
__declspec(__nothrow) long double modfl(long double  , long double *  ) __attribute__((__nonnull__(2)));
__declspec(__nothrow) long double powl(long double , long double );
__declspec(__nothrow) long double sinl(long double );
__declspec(__nothrow) long double sinhl(long double );
__declspec(__nothrow) long double sqrtl(long double );
__declspec(__nothrow) long double tanl(long double );
__declspec(__nothrow) long double tanhl(long double );





 
extern __declspec(__nothrow) float acoshf(float  );
__declspec(__nothrow) long double acoshl(long double );
extern __declspec(__nothrow) float asinhf(float  );
__declspec(__nothrow) long double asinhl(long double );
extern __declspec(__nothrow) float atanhf(float  );
__declspec(__nothrow) long double atanhl(long double );
__declspec(__nothrow) long double copysignl(long double , long double );
extern __declspec(__nothrow) float cbrtf(float  );
__declspec(__nothrow) long double cbrtl(long double );
extern __declspec(__nothrow) float erff(float  );
__declspec(__nothrow) long double erfl(long double );
extern __declspec(__nothrow) float erfcf(float  );
__declspec(__nothrow) long double erfcl(long double );
extern __declspec(__nothrow) float expm1f(float  );
__declspec(__nothrow) long double expm1l(long double );
extern __declspec(__nothrow) float log1pf(float  );
__declspec(__nothrow) long double log1pl(long double );
extern __declspec(__nothrow) float hypotf(float  , float  );
__declspec(__nothrow) long double hypotl(long double , long double );
extern __declspec(__nothrow) float lgammaf(float  );
__declspec(__nothrow) long double lgammal(long double );
extern __declspec(__nothrow) float remainderf(float  , float  );
__declspec(__nothrow) long double remainderl(long double , long double );
extern __declspec(__nothrow) float rintf(float  );
__declspec(__nothrow) long double rintl(long double );



#line 875 "C:\\Bin\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\math.h"






  extern "C++" {
    inline int (fpclassify)(double __x) { return ((sizeof(__x) == sizeof(float)) ? __ARM_fpclassifyf(__x) : __ARM_fpclassify(__x)); }
    inline bool (isfinite)(double __x) { return ((sizeof(__x) == sizeof(float)) ? __ARM_isfinitef(__x) : __ARM_isfinite(__x)); }
    inline bool (isgreater)(double __x, double __y) { return (((sizeof(__x) == sizeof(float)) && (sizeof(__y) == sizeof(float))) ? ((__ARM_fcmp4((__x), (__y)) & 0xf0000000) == 0x20000000) : ((__ARM_dcmp4((__x), (__y)) & 0xf0000000) == 0x20000000)); }
    inline bool (isgreaterequal)(double __x, double __y) { return (((sizeof(__x) == sizeof(float)) && (sizeof(__y) == sizeof(float))) ? ((__ARM_fcmp4((__x), (__y)) & 0x30000000) == 0x20000000) : ((__ARM_dcmp4((__x), (__y)) & 0x30000000) == 0x20000000)); }
    inline bool (isinf)(double __x) { return ((sizeof(__x) == sizeof(float)) ? __ARM_isinff(__x) : __ARM_isinf(__x)); }
    inline bool (isless)(double __x, double __y) { return (((sizeof(__x) == sizeof(float)) && (sizeof(__y) == sizeof(float))) ? ((__ARM_fcmp4((__x), (__y)) & 0xf0000000) == 0x80000000) : ((__ARM_dcmp4((__x), (__y)) & 0xf0000000) == 0x80000000)); }
    inline bool (islessequal)(double __x, double __y) { return (((sizeof(__x) == sizeof(float)) && (sizeof(__y) == sizeof(float))) ? ((__ARM_fcmp4((__x), (__y)) & 0xc0000000) != 0) : ((__ARM_dcmp4((__x), (__y)) & 0xc0000000) != 0)); }
    inline bool (islessgreater)(double __x, double __y) { return (((sizeof(__x) == sizeof(float)) && (sizeof(__y) == sizeof(float))) ? __ARM_islessgreaterf((__x), (__y)) : __ARM_islessgreater((__x), (__y))); }
    inline bool (isnan)(double __x) { return ((sizeof(__x) == sizeof(float)) ? __ARM_isnanf(__x) : __ARM_isnan(__x)); }
    inline bool (isnormal)(double __x) { return ((sizeof(__x) == sizeof(float)) ? __ARM_isnormalf(__x) : __ARM_isnormal(__x)); }
    inline bool (isunordered)(double __x, double __y) { return (((sizeof(__x) == sizeof(float)) && (sizeof(__y) == sizeof(float))) ? ((__ARM_fcmp4((__x), (__y)) & 0x10000000) == 0x10000000) : ((__ARM_dcmp4((__x), (__y)) & 0x10000000) == 0x10000000)); }

  }



  extern "C++" {
    inline float abs(float __x)   { return fabsf(__x); }
    inline float acos(float __x)  { return acosf(__x); }
    inline float asin(float __x)  { return asinf(__x); }
    inline float atan(float __x)  { return atanf(__x); }
    inline float atan2(float __y, float __x)    { return atan2f(__y,__x); }
    inline float ceil(float __x)  { return ceilf(__x); }
    inline float cos(float __x)   { return cosf(__x); }
    inline float cosh(float __x)  { return coshf(__x); }
    inline float exp(float __x)   { return expf(__x); }
    inline float fabs(float __x)  { return fabsf(__x); }
    inline float floor(float __x) { return floorf(__x); }
    inline float fmod(float __x, float __y)     { return fmodf(__x, __y); }
    float frexp(float __x, int* __exp) __attribute__((__nonnull__(2)));
    inline float frexp(float __x, int* __exp)   { return frexpf(__x, __exp); }
    inline float ldexp(float __x, int __exp)    { return ldexpf(__x, __exp);}
    inline float log(float __x)   { return logf(__x); }
    inline float log10(float __x) { return log10f(__x); }
    float modf(float __x, float* __iptr) __attribute__((__nonnull__(2)));
    inline float modf(float __x, float* __iptr) { return modff(__x, __iptr); }
    inline float pow(float __x, float __y)      { return powf(__x,__y); }
    inline float pow(float __x, int __y)     { return powf(__x, (float)__y); }
    inline float sin(float __x)   { return sinf(__x); }
    inline float sinh(float __x)  { return sinhf(__x); }
    inline float sqrt(float __x)  { return sqrtf(__x); }
    inline float _sqrt(float __x) { return _sqrtf(__x); }
    inline float tan(float __x)   { return tanf(__x); }
    inline float tanh(float __x)  { return tanhf(__x); }

    inline double abs(double __x) { return fabs(__x); }
    inline double pow(double __x, int __y)
                { return pow(__x, (double) __y); }


    inline long double abs(long double __x)
                { return (long double)fabsl(__x); }
    inline long double acos(long double __x)
                { return (long double)acosl(__x); }
    inline long double asin(long double __x)
                { return (long double)asinl(__x); }
    inline long double atan(long double __x)
                { return (long double)atanl(__x); }
    inline long double atan2(long double __y, long double __x)
                { return (long double)atan2l(__y, __x); }
    inline long double ceil(long double __x)
                { return (long double)ceill( __x); }
    inline long double cos(long double __x)
                { return (long double)cosl(__x); }
    inline long double cosh(long double __x)
                { return (long double)coshl(__x); }
    inline long double exp(long double __x)
                { return (long double)expl(__x); }
    inline long double fabs(long double __x)
                { return (long double)fabsl(__x); }
    inline long double floor(long double __x)
                { return (long double)floorl(__x); }
    inline long double fmod(long double __x, long double __y)
                { return (long double)fmodl(__x, __y); }
    long double frexp(long double __x, int* __p) __attribute__((__nonnull__(2)));
    inline long double frexp(long double __x, int* __p)
                { return (long double)frexpl(__x, __p); }
    inline long double ldexp(long double __x, int __exp)
                { return (long double)ldexpl(__x, __exp); }
    inline long double log(long double __x)
                { return (long double)logl(__x); }
    inline long double log10(long double __x)
                { return (long double)log10l(__x); }
    long double modf(long double __x, long double* __p) __attribute__((__nonnull__(2)));
    inline long double modf(long double __x, long double* __p)
                { return (long double)modfl(__x, __p); }
    inline long double pow(long double __x, long double __y)
                { return (long double)powl(__x, __y); }
    inline long double pow(long double __x, int __y)
                { return (long double)powl(__x, __y); }
    inline long double sin(long double __x)
                { return (long double)sinl(__x); }
    inline long double sinh(long double __x)
                { return (long double)sinhl(__x); }
    inline long double sqrt(long double __x)
                { return (long double)sqrtl(__x); }
    inline long double _sqrt(long double __x)
                { return (long double)_sqrt((double) __x); }
    inline long double tan(long double __x)
                { return (long double)tanl(__x); }
    inline long double tanh(long double __x)
                { return (long double)tanhl(__x); }



    inline float acosh(float __x) { return acoshf(__x); }
    inline float asinh(float __x) { return asinhf(__x); }
    inline float atanh(float __x) { return atanhf(__x); }
    inline float cbrt(float __x) { return cbrtf(__x); }
    inline float erf(float __x) { return erff(__x); }
    inline float erfc(float __x) { return erfcf(__x); }
    inline float expm1(float __x) { return expm1f(__x); }
    inline float log1p(float __x) { return log1pf(__x); }
    inline float hypot(float __x, float __y) { return hypotf(__x, __y); }
    inline float lgamma(float __x) { return lgammaf(__x); }
    inline float remainder(float __x, float __y) { return remainderf(__x, __y); }
    inline float rint(float __x) { return rintf(__x); }


#line 1084 "C:\\Bin\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\math.h"

  }



        }   
      }   








    using ::std::__use_accurate_range_reduction;

      using ::std::abs;

    using ::std::acos;
    using ::std::asin;
    using ::std::atan2;
    using ::std::atan;
    using ::std::ceil;
    using ::std::cos;
    using ::std::cosh;
    using ::std::exp;
    using ::std::fabs;
    using ::std::floor;
    using ::std::fmod;
    using ::std::frexp;
    using ::std::ldexp;
    using ::std::log10;
    using ::std::log;
    using ::std::modf;
    using ::std::pow;
    using ::std::sin;
    using ::std::sinh;
    using ::std::sqrt;
    using ::std::_sqrt;
    using ::std::_sqrtf;
    using ::std::tan;
    using ::std::tanh;
    using ::std::_fabsf;
     
    using ::std::acosf;
    using ::std::acosl;
    using ::std::asinf;
    using ::std::asinl;
    using ::std::atan2f;
    using ::std::atan2l;
    using ::std::atanf;
    using ::std::atanl;
    using ::std::ceilf;
    using ::std::ceill;
    using ::std::cosf;
    using ::std::coshf;
    using ::std::coshl;
    using ::std::cosl;
    using ::std::expf;
    using ::std::expl;
    using ::std::fabsf;
    using ::std::fabsl;
    using ::std::floorf;
    using ::std::floorl;
    using ::std::fmodf;
    using ::std::fmodl;
    using ::std::frexpf;
    using ::std::frexpl;
    using ::std::ldexpf;
    using ::std::ldexpl;
    using ::std::log10f;
    using ::std::log10l;
    using ::std::logf;
    using ::std::logl;
    using ::std::modff;
    using ::std::modfl;
    using ::std::powf;
    using ::std::powl;
    using ::std::sinf;
    using ::std::sinhf;
    using ::std::sinhl;
    using ::std::sinl;
    using ::std::sqrtf;
    using ::std::sqrtl;
    using ::std::tanf;
    using ::std::tanhf;
    using ::std::tanhl;
    using ::std::tanl;

       
      using ::std::acosh;
      using ::std::asinh;
      using ::std::atanh;
      using ::std::cbrt;
      using ::std::copysign;
      using ::std::copysignf;
      using ::std::erf;
      using ::std::erfc;
      using ::std::expm1;
      using ::std::hypot;
      using ::std::ilogb;
      using ::std::ilogbf;
      using ::std::ilogbl;
      using ::std::lgamma;
      using ::std::log1p;
      using ::std::logb;
      using ::std::logbf;
      using ::std::logbl;
      using ::std::nextafter;
      using ::std::nextafterf;
      using ::std::nextafterl;
      using ::std::nexttoward;
      using ::std::nexttowardf;
      using ::std::nexttowardl;
      using ::std::remainder;
      using ::std::rint;
      using ::std::scalbln;
      using ::std::scalblnf;
      using ::std::scalblnl;
      using ::std::scalbn;
      using ::std::scalbnf;
      using ::std::scalbnl;
      using ::std::math_errhandling;
      using ::std::acoshf;
      using ::std::acoshl;
      using ::std::asinhf;
      using ::std::asinhl;
      using ::std::atanhf;
      using ::std::atanhl;
      using ::std::copysignl;
      using ::std::cbrtf;
      using ::std::cbrtl;
      using ::std::erff;
      using ::std::erfl;
      using ::std::erfcf;
      using ::std::erfcl;
      using ::std::expm1f;
      using ::std::expm1l;
      using ::std::log1pf;
      using ::std::log1pl;
      using ::std::hypotf;
      using ::std::hypotl;
      using ::std::lgammaf;
      using ::std::lgammal;
      using ::std::remainderf;
      using ::std::remainderl;
      using ::std::rintf;
      using ::std::rintl;
       
      using ::std::float_t;
      using ::std::double_t;
#line 1302 "C:\\Bin\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\math.h"


      using ::std::fpclassify;
      using ::std::isfinite;
      using ::std::isgreater;
      using ::std::isgreaterequal;
      using ::std::isinf;
      using ::std::isless;
      using ::std::islessequal;
      using ::std::islessgreater;
      using ::std::isnan;
      using ::std::isnormal;
      using ::std::isunordered;







 
#line 12 "..\\EmbSysLib\\Src\\Com/Device/Display/devDisplayGraphic.cpp"







cDevDisplayGraphic::cDevDisplayGraphic( cHwDisplayGraphic &displayIn )

: display( displayIn )

{
  clear();
}


void cDevDisplayGraphic::clear( void )
{
  
  display.clear();
}


void cDevDisplayGraphic::refresh( void )
{
  display.refresh();
}


void cDevDisplayGraphic::printf( BYTE        line,
                                 BYTE        column,
                                 BYTE        minLen,
                                 const char *format,
                                 ... )
{
  BYTE i;

  
  char str[31]; 

  va_list argzeiger;
  __va_start(argzeiger, format);
  vsprintf( str, format, argzeiger );
  __va_end(argzeiger);

  display.gotoTextPos( line, column );

  
  for( i = 0; str[i] != 0; i++ )
  {
    display.putChar( str[i] );
  }

  
  for(   ; i < minLen; i++)
  {
    display.putChar( ' ' );
  }
}


void cDevDisplayGraphic::setFont( cHwDisplayFont font,
                                  BYTE           zoom )
{
  display.setFont( font, zoom );
};


void cDevDisplayGraphic::setZoom( BYTE zoom )
{
  display.setZoom( zoom );
};


void cDevDisplayGraphic::setBackColor( WORD color )
{
  display.setBackColor( color );
}


void cDevDisplayGraphic::setTextColor( WORD color )
{
  display.setTextColor( color );
}


void cDevDisplayGraphic::drawText( WORD        x,
                                   WORD        y,
                                   BYTE        minLen,
                                   const char *format,
                                   ... )
{
  BYTE i;

  
  char str[31]; 

  va_list argzeiger;
  __va_start(argzeiger, format);
  vsprintf( str, format, argzeiger );
  __va_end(argzeiger);

  display.gotoPixelPos( x, y );

  
  for( i = 0; str[i] != 0; i++ )
  {
    display.putChar( str[i] );
  }

  
  for(  ; i < minLen; i++ )
  {
    display.putChar( ' ' );
  }
}


void cDevDisplayGraphic::drawText( WORD        x,
                                   WORD        y,
                                   const char *str )
{
  BYTE i;

  display.gotoPixelPos( x, y );

  
  for( i = 0; str[i] != 0; i++ )
  {
    display.putChar( str[i] );
  }
}


void cDevDisplayGraphic::drawPixel( WORD x,
                                    WORD y,
                                    WORD color )
{
   display.setPaintColor( color );
   display.putPixel( x, y );
}


void cDevDisplayGraphic::drawRectangle( WORD x,
                                        WORD y,
                                        WORD w,
                                        WORD h,
                                        WORD color )
{
   display.setPaintColor( color );
   display.putRectangle( x, y, w, h );
}


void cDevDisplayGraphic::drawFrame( WORD x,
                                    WORD y,
                                    WORD w,
                                    WORD h,
                                    WORD th,
                                    WORD color )
{
  
  drawRectangle( x, y     , w, th, color );
  drawRectangle( x, y+h-th, w, th, color );

  
  drawRectangle( x,      y, th, h, color );
  drawRectangle( x+w-th, y, th, h, color );
}


void cDevDisplayGraphic::drawCircle( WORD x0,
                                     WORD y0,
                                     WORD r,
                                     WORD color )
{
  for( WORD x = 0; x <= r; x++ )
  {
    int h = (int)sqrt( (float)r*r-(float)x*x );
    drawRectangle( x0+x, y0-h, 1, 2*h, color );
    drawRectangle( x0-x, y0-h, 1, 2*h, color );
  }
}


void cDevDisplayGraphic::drawLine( WORD x0,
                                   WORD y0,
                                   WORD x1,
                                   WORD y1,
                                   WORD th,
                                   WORD color )
{
  long t;
  int  x;
  int  y;
  int  dx = (int)x1-x0;
  int  dy = (int)y1-y0;

  if( dy == 0 ) 
  {
    x0 = (x0 < x1) ? x0 : x1;
    y0 = (y0 < y1) ? y0 : y1;
    drawRectangle( x0, y0-th/2, abs(dx), th, color );
  }
  else if( dx == 0 ) 
  {
    x0 = (x0 < x1) ? x0 : x1;
    y0 = (y0 < y1) ? y0 : y1;
    drawRectangle(x0-th/2, y0, th, abs(dy), color );
  }
  else if( abs(dx) <= abs(dy) )
  {
    for( t = abs(dy); t >= 0; t-- )  
    {
      x = x0 + t*dx/abs(dy);         
      y = y0 + ( (dy>0) ? +t : -t ); 
      for( int i = th; i >= 0; i-- )
      {
        drawPixel( x+i, y, color );
      }
    }
  }
  else
  {
    for( t = abs(dx); t >= 0; t-- )  
    {
      x = x0 + ( (dx>0) ? +t : -t ); 
      y = y0 + t*dy/abs(dx);         
      for( int i = th; i >= 0; i-- )
      {
        drawPixel( x, y+i, color );
      }
    }
  }
}


void cDevDisplayGraphic::drawBitmap( WORD        x,
                                     WORD        y,
                                     WORD        w,
                                     WORD        h,
                                     const WORD *bitmap )
{
  display.putBitmap( x, y, w, h, bitmap );
}


cHwDisplayFont cDevDisplayGraphic::getDefaultFont( void )
{
  return( display.getDefaultFont() );
}


#line 99 "..\\EmbSysLib\\Src\\lib.cpp"




#line 1 "..\\EmbSysLib\\Src\\Com/Device/Memory/devMemory.cpp"







 







cDevMemory::cDevMemory( cHwMemory &memIn,
                        WORD       addrIn )

: mem( memIn )

{
  addr   = addrIn;
  pos    = 1; 
}


WORD cDevMemory::allocate( WORD size )
{
  WORD ret = pos;

  pos += size;  
  return( ret );
}


void cDevMemory::write( BYTE *data,
                        WORD  size,
                        WORD  offs )
{
  mem.unlock();
  for( WORD i = 0; i < size; i++ )
  {
    mem.write( addr+offs+i, data[i] );
  }
  mem.lock();
}


void cDevMemory::read( BYTE *data,
                       WORD  size,
                       WORD  offs )
{
  for( WORD i = 0; i < size; i++ )
  {
    data[i] = mem.read( addr+offs+i );
  }
}


void cDevMemory::clear( void )
{
  mem.unlock();
  mem.clear();
  mem.lock();
}


void cDevMemory::setValid( void )
{
  mem.unlock();
  mem.write( addr, 0x55 );
  mem.unlock();
}


BYTE cDevMemory::isValid( void )
{
  return( ( mem.read( addr ) == 0x55 ) ? true : false );
}


#line 104 "..\\EmbSysLib\\Src\\lib.cpp"




#line 1 "..\\EmbSysLib\\Src\\Com/Device/TextIO/devTextIO.cpp"







 


#line 12 "..\\EmbSysLib\\Src\\Com/Device/TextIO/devTextIO.cpp"
#line 13 "..\\EmbSysLib\\Src\\Com/Device/TextIO/devTextIO.cpp"
#line 14 "..\\EmbSysLib\\Src\\Com/Device/TextIO/devTextIO.cpp"


#line 17 "..\\EmbSysLib\\Src\\Com/Device/TextIO/devTextIO.cpp"







cDevTextIO::cDevTextIO( BYTE        inBufSizeIn,
                        BYTE        outBufSizeIn,
                        const char *eosIn,
                        const char *keyIn )
{
  inBufSize  = inBufSizeIn;
  outBufSize = outBufSizeIn;
  strIn      = new char[ inBufSize + 1];
  strOut     = new char[outBufSize + 1];
  idx        = 0;
  eos        = eosIn;
  key        = keyIn;
  escape     = 0;
  last       = 0;
}


char* cDevTextIO::getString( void )
{
	BYTE c        = 0;
  BYTE complete = 0;

  while( get( &c ) && !complete )
  {
    switch( escape )
    {
      case 0: 
        switch( c )
        {
          case 27  : escape = 1;          break; 
          case 224 : escape = 2;          break; 
          default  : last = c;
                     strIn[idx++] = last; break; 
        }
        break;

      case 1: 
        switch( c )
        {
          case '[': escape = 2;          break; 
          case 27:  strIn[idx++] = last;        
                    escape = 0;          break;
          default:  escape = 0;          break; 
        }
        break;

      case 2: 
        last = c | 0x80;
        strIn[idx++] = last;
        escape = 0;
        break;
    }

    
    if(    (idx >= inBufSize-2)           
                                          
        || (   (idx == 1 )                
            && (   (last&0x80)            
                || strchr( key, last )) ) 
                                          
        || (strchr( eos, last ))          
      )
    {
      complete   = 1;
      strIn[idx] = 0;
      idx        = 0;
      return( strIn );
    }
  }
  return( 0 );
}


void cDevTextIO::printf( const char *format, ... )
{
  va_list argzeiger;

  __va_start(argzeiger, format);
  vsnprintf( strOut, outBufSize, format, argzeiger );
  __va_end(argzeiger);

  
  set( (BYTE*)strOut, strlen(strOut) );
}


#line 109 "..\\EmbSysLib\\Src\\lib.cpp"
#line 1 "..\\EmbSysLib\\Src\\Com/Device/TextIO/devTextIO_UART.cpp"







 


#line 12 "..\\EmbSysLib\\Src\\Com/Device/TextIO/devTextIO_UART.cpp"







cDevTextIO_UART::cDevTextIO_UART( cHwUART    &uartIn,
                                  BYTE        inBufSizeIn,
                                  BYTE        outBufSizeIn,
                                  const char *eosIn,
                                  const char *keyIn)

: cDevTextIO( inBufSizeIn,
              outBufSizeIn,
              eosIn,
              keyIn ),
                          
  uart      ( uartIn )

{
}


inline void cDevTextIO_UART::set( BYTE *str, BYTE size )
{
  uart.set( str, size );
}
    

inline bool cDevTextIO_UART::get( BYTE *c )
{
  return( uart.get( c ) );
}    


#line 110 "..\\EmbSysLib\\Src\\lib.cpp"




#line 1 "..\\EmbSysLib\\Src\\Com/Device/Control/devControlEncoder.cpp"





 







cDevControlEncoder::cDevControlEncoder( cDevDigital *btnCtrlIn,
                          cHwTimer    *timerPtr )

: fifo( 20 ),
  btnCtrl( btnCtrlIn )

{
  if(timerPtr)
  {
    timerPtr->add(this);
  }
}


cDevControlEncoder::tEvent cDevControlEncoder::get( void )
{
  if( fifo.isEmpty() )
  {
    return( NONE );
  }
  else
  {
    tEvent event = NONE;
    fifo >> event;
    return( event );
  }
}


void cDevControlEncoder::update( void )
{
  if( !fifo.isFull() )
  {
    switch( getIncrement() )
    {
      case LEFT:  fifo << LEFT;    break;
      case RIGHT: fifo << RIGHT;   break;
      default:                     break;
    }
  }

  if( !fifo.isFull() )
  {
    switch( getCtrl() )
    {
      case CTRL_DWN:  fifo << CTRL_DWN;  break;
      case CTRL_UP:   fifo << CTRL_UP;   break;
      default:                           break;
    }
  }
}


cDevControlEncoder::tEvent cDevControlEncoder::getCtrl( void )
{
  if( btnCtrl )
  {
    switch( btnCtrl->getEvent() )
    {
      case cDevDigital::ACTIVATED:
        return( CTRL_DWN );
      case cDevDigital::RELEASED:
        return( CTRL_UP );
    }
  }
  return( NONE );
}


#line 115 "..\\EmbSysLib\\Src\\lib.cpp"
#line 1 "..\\EmbSysLib\\Src\\Com/Device/Control/devControlEncoderJoystick.cpp"





 







cDevControlEncoderJoystick::cDevControlEncoderJoystick( cDevDigital *btnLeftIn,
                                          cDevDigital *btnRightIn,
                                          cDevDigital *btnCtrlIn,
                                          cHwTimer    *timerPtr,
                                          WORD         repeatTime )

: cDevControlEncoder( btnCtrlIn, timerPtr ),
  btnLeft    ( btnLeftIn ),
  btnRight   ( btnRightIn )
{
  if( timerPtr && timerPtr->getCycleTime() )
  {
    timerStart = 1000UL*repeatTime/timerPtr->getCycleTime();
    
  }
  else
  {
    timerStart = 0;
  }
  timerCnt = timerStart;
}


cDevControlEncoder::tEvent cDevControlEncoderJoystick::getIncrement( void )
{
  if( timerCnt )
  {
    timerCnt--;
  }

  if( btnLeft )
  {
    if(    btnLeft->getEvent() == cDevDigital::ACTIVATED
        || (!timerCnt && timerStart && btnLeft->get()) )
    {
      timerCnt = timerStart;
      return( LEFT );
    }
  }

  if( btnRight )
  {
    if(   btnRight->getEvent() == cDevDigital::ACTIVATED
       || (!timerCnt && timerStart && btnRight->get()) )
    {
      timerCnt = timerStart;
      return( RIGHT );
    }
  }
  return( NONE );
}


#line 116 "..\\EmbSysLib\\Src\\lib.cpp"
#line 1 "..\\EmbSysLib\\Src\\Com/Device/Control/devControlEncoderRotaryknob.cpp"





 








cDevControlEncoderRotaryKnob::cDevControlEncoderRotaryKnob( cDevDigital *btnLeftIn,
                                              cDevDigital *btnRightIn,
                                              cDevDigital *btnCtrlIn,
                                              cHwTimer    *timerPtr )
: cDevControlEncoder( btnCtrlIn, timerPtr ),
  btnLeft    ( btnLeftIn ),
  btnRight   ( btnRightIn )

{
}


cDevControlEncoder::tEvent cDevControlEncoderRotaryKnob::getIncrement( void )
{
  if( btnLeft && btnRight )
  {
    switch( btnLeft->getEvent() )
    {
      case cDevDigital::ACTIVATED:
          return( btnRight->get()?NONE:LEFT );

      case cDevDigital::RELEASED:
          return( btnRight->get()?LEFT:NONE );
    }

    switch( btnRight->getEvent() )
    {
      case cDevDigital::ACTIVATED:
          return( btnLeft->get()?NONE:RIGHT );

      case cDevDigital::RELEASED:
          return( btnLeft->get()?RIGHT:NONE );
    }
  }
  return( NONE );
}


#line 117 "..\\EmbSysLib\\Src\\lib.cpp"
#line 1 "..\\EmbSysLib\\Src\\Com/Device/Control/devControlPointer.cpp"





 







cDevControlPointer::cDevControlPointer( cHwTouch &touchIn )

: touch( touchIn )

{
  data.flags = cData::NONE;
  data.posX  = 0;
  data.posY  = 0;
  data.delta = 0;
}


cDevControlPointer::cData cDevControlPointer::get( void )
{
  touch.update();

  int x = RANGE((short)touch.getPosX(),(short)0,(short)0x7FFF);
  int y = RANGE((short)touch.getPosY(),(short)0,(short)0x7FFF);
  BYTE isTouched = touch.isTouched();

  if( isTouched && !isTouchedPrev )
  {
    data.flags = cData::CTRL_DWN;
    data.posX  = x;
    data.posY  = y;
    data.delta = 0;
    posXprev    = x;
    posYprev    = y;
  }
  else if( !isTouched  && isTouchedPrev )
  {
    data.flags = cData::CTRL_UP;
    data.posX  = x;
    data.posY  = y;
    data.delta = 0;
  }
  else if( isTouched  && isTouchedPrev )
  {
    data.flags = cData::PRESSED;
    data.posX  = x;
    data.posY  = y;
    data.delta = 0;

    if( x != posXprev || y != posYprev )
    {
      if( abs(posXprev-x) > 15 || abs(posYprev-y) > 15 )
      {
        int deltaX = x-posXprev;
        int deltaY = y-posYprev;
        if( abs(deltaX) > abs(deltaY) )
        {
          data.flags = cData::MOVE_X;
          data.delta = deltaX;
        }
        else
        {
          data.flags = cData::MOVE_Y;
          data.delta = -deltaY;
        }
        posXprev = x;
        posYprev = y;
      }
    }
  }
  else
  {
    data.flags = cData::NONE;
    data.delta = 0;
  }
  isTouchedPrev = isTouched ;
  return( data );
}


#line 118 "..\\EmbSysLib\\Src\\lib.cpp"




#line 1 "..\\EmbSysLib\\Src\\Com/Std/Std.cpp"







 


extern "C"
{
  void __cxa_pure_virtual( void )
  {
    abort();
  }
}


#line 123 "..\\EmbSysLib\\Src\\lib.cpp"
#line 1 "..\\EmbSysLib\\Src\\Com/Std/StaticArray.cpp"





 













#line 124 "..\\EmbSysLib\\Src\\lib.cpp"
#line 1 "..\\EmbSysLib\\Src\\Com/Std/CRC.cpp"





 


#line 10 "..\\EmbSysLib\\Src\\Com/Std/CRC.cpp"







cCRC::cCRC( MODE mode,
            WORD startCRC_In,
            WORD generatorPolynomIn )
{
  startCRC         = startCRC_In;
  crc              = startCRC;
  generatorPolynom = generatorPolynomIn;

  if( mode == FAST )
  {
    tabArray = new WORD[256];

    for( WORD i = 0; i < 256 && tabArray; i++ )
    {
      tabArray[i] = tabMethod( i );
    }
  }
  else
  {
    tabArray = 0;
  }
}


cCRC::~cCRC( void )
{
  if( tabArray )
  {
    delete tabArray;
  }
}


WORD cCRC::operator()( const BYTE  *ptr,
                       const DWORD  size )
{
  WORD crcLoc = startCRC;

  for( DWORD i = 0; i < size; i++ )
  {
    BYTE idx = ( *(ptr++) ) ^ crcLoc;

    if( tabArray )
    {
      crcLoc = (crcLoc>>8) ^ tabArray[idx];
    }
    else
    {
      crcLoc = (crcLoc>>8) ^ tabMethod( idx );
    }
  }
  return( crcLoc );
}


void cCRC::operator()( const BYTE data )
{
  BYTE idx = data ^ crc;

  if( tabArray )
  {
    crc = (crc>>8) ^ tabArray[idx];
  }
  else
  {
    crc = (crc>>8) ^ tabMethod( idx );
  }
  
}


inline WORD cCRC::tabMethod( BYTE idx )
{
  WORD crcLoc = 0;

  for( BYTE bit = 0; bit < 8; bit++ )
  {
    if( (crcLoc^idx) & 0x01 )
    {
      crcLoc = (crcLoc>>1) ^ generatorPolynom;
    }
    else
    {
      crcLoc = (crcLoc>>1);
    }
    idx = (idx>>1);
  }
  return( crcLoc );
}


#line 125 "..\\EmbSysLib\\Src\\lib.cpp"
#line 1 "..\\EmbSysLib\\Src\\Com/Std/List.cpp"







 


#line 12 "..\\EmbSysLib\\Src\\Com/Std/List.cpp"







cList::Item::Item( cList *list )
{
  PtrNext = 0;
  if( list )
  {
    list->add( this );
  }
}


cList::Item *cList::Item::getNext( void )
{
  return( PtrNext );
}


cList::Item *cList::Item::getPrev( cList &list )
{
  Item *tmp = list.getFirst();
  while( tmp && tmp->getNext() != this )
  {
    tmp = tmp->getNext();
  }
  return( (tmp==this)?0:tmp );
}







cList::cList( void )
{
  PtrFirst = 0;
}


BYTE cList::add(Item *itemPtr)
{
  Item *ptr;

  
  ptr = PtrFirst;

  while( ptr )
  {
    if( ptr == itemPtr )
    {
      return( false );
    }
    if(ptr->PtrNext) 
    {
      ptr = ptr->PtrNext;
    }
    else
    {
      break;
    }
  }

  
  
  if( ptr ) 
  {
    ptr->PtrNext = itemPtr;
  }
  else 
  {
    PtrFirst = itemPtr;
  }
  return( true );
}


cList::Item* cList::getFirst( void )
{
  return( PtrFirst );
}


cList::Item* cList::operator[](WORD index)
{
  Item* ptr = PtrFirst;
  while( ptr && index-- )
  {
    ptr = ptr->PtrNext;
  }
  return( ptr );
}


void cList::updateAll( void )
{
  Item* ptr = PtrFirst;

  while( ptr )
  {
    ptr->update();
    ptr = ptr->PtrNext;
  }
}


#line 126 "..\\EmbSysLib\\Src\\lib.cpp"
#line 1 "..\\EmbSysLib\\Src\\Com/Std/Fifo.cpp"







 












#line 127 "..\\EmbSysLib\\Src\\lib.cpp"
#line 1 "..\\EmbSysLib\\Src\\Com/Std/DataPointer.cpp"





 












#line 128 "..\\EmbSysLib\\Src\\lib.cpp"
#line 1 "..\\EmbSysLib\\Src\\Com/Std/SharedMem.cpp"







 












#line 129 "..\\EmbSysLib\\Src\\lib.cpp"
#line 1 "..\\EmbSysLib\\Src\\Com/Std/Timer.cpp"







 







cTimer::cTimer( void )

{
  running = false;
  timeToGo = 0;
}


void cTimer::start( WORD timeToWait_msec,
                    WORD timeToWait_usec )
{
  set( timeToWait_msec, timeToWait_usec );
  start();
}


void cTimer::start( void )
{
  startTime = getTics();
  running = true;
}


BYTE cTimer::timeout( WORD timeToWait_msec,
                      WORD timeToWait_usec )
{
  if( !running )
  {
    set( timeToWait_msec, timeToWait_usec );
  }
  return( timeout() );
}


BYTE cTimer::timeout( void )
{
  BYTE runState = false; 

  if( running )
  {
    if(getTics() - startTime >= timeToGo )
    {
      running = false;
    }
    runState = !running; 
  }

  if( !running )
  {
    start();
  }

  return( runState );
}


BYTE cTimer::isRunning( void )
{
  if( running && timeout() )
  {
    stop();
  }
  return( running );
}


void cTimer::stop( void )
{
  running = false;
}


void cTimer::set( WORD timeToWait_msec,
                  WORD timeToWait_usec )
{
  timeToGo =   ((DWORD)timeToWait_msec*1000L + timeToWait_usec)
             / getTimeOfTic();
}


#line 130 "..\\EmbSysLib\\Src\\lib.cpp"




#line 1 "..\\EmbSysLib\\Src\\Com/Task/TaskHandler.cpp"







 


#line 12 "..\\EmbSysLib\\Src\\Com/Task/TaskHandler.cpp"







cTaskHandler::cTaskHandler( cHwTimer *timerPtrIn )
{
  timerPtr = timerPtrIn;
  taskPtr  = 0;

  if( timerPtr )
  {
    timerPtr->add( this );

    cycleTime = timerPtr->getCycleTime();
  }
  else 
  {
    cycleTime = (unsigned long)(-1);
  }
}


cTaskHandler::cTaskHandler( cTaskHandler *taskPtrIn )
{
  timerPtr = 0;
  taskPtr  = taskPtrIn;
  if( taskPtr )
  {
    cycleTime = taskPtr->timerPtr->getCycleTime();
  }
  else 
  {
    cycleTime = (unsigned long)(-1);
  }
}


inline DWORD cTaskHandler::getCycleTime( void )
{
  return( cycleTime );
}


inline unsigned long cTaskHandler::getTics( void )
{
  return( tics );
}


inline void cTaskHandler::run( void )
{
  if( taskPtr )
  {
    cSystem::disableInterrupt();
    tics = taskPtr->getTics();
    cSystem::enableInterrupt();
  }
  idle.updateAll();
}


void cTaskHandler::addTask( Task *taskPtrIn )
{
  if( timerPtr )
  {
    timerPtr->add( taskPtrIn );
  }
  else
  {
    idle.add( taskPtrIn );
  }
}


inline void cTaskHandler::update( void )
{
  tics++;
}







cTaskHandler::Task::Task( cTaskHandler &taskHandler )
{
  taskHandler.addTask( this );
}







cTaskHandler::Timer::Timer( cTaskHandler &taskHandlerIn,
                            WORD          timeToWait_msec,
                            WORD          timeToWait_usec )

: taskHandler( taskHandlerIn )

{ 
  set( timeToWait_msec, timeToWait_usec ); 
}


DWORD cTaskHandler::Timer::getTics( void )
{
  return( taskHandler.getTics() );
}


DWORD cTaskHandler::Timer::getTimeOfTic( void )
{
  return( taskHandler.getCycleTime() );
}


#line 135 "..\\EmbSysLib\\Src\\lib.cpp"


