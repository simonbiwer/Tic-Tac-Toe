#ifndef ENC28J60_H
   #define ENC28J60_H

//#define BUFFER_SIZE 500

//#include "net.h"
#include "Com/Hardware/Ethernet.h"

//*****************************************************************************
class cHwEthernet_Enc28j60 : public cHwEthernet
{
	public:
	  cHwEthernet_Enc28j60( const cNetAddr<6>  &addrPhy, cHwSPImaster::Device &spi );



public:


    virtual void create( const cNetAddr<6> destAddr, const WORD type );


    virtual void     PacketSend   (BYTE* packet, WORD len);
		virtual bool     PacketReceive();

    virtual WORD getType(  );


  private:
		void Init(const cNetAddr<6>  &addrPhy);
    void InitPhy (void);

	  BYTE ReadOp(BYTE op, BYTE address);
		void WriteOp(BYTE op, BYTE address, BYTE data);
		void ReadBuffer(WORD len, BYTE* data);
		void WriteBuffer(WORD len, BYTE* data);
		void SetBank(BYTE address);
		BYTE Read(BYTE address);
		void WriteByte(BYTE address, BYTE data);
		void WriteWord(BYTE address, WORD data);
		void PhyWrite(BYTE address, WORD data);
		void clkout(BYTE clk);
		BYTE getrev(void);



		private:
      cHwSPImaster::Device &spi;
    
    const cNetAddr<6>  &addrPhy;

    BYTE  Bank;
    WORD NextPacketPtr;
  public:


};
#endif

