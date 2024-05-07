//*******************************************************************
/*!
\file   UART_MCU.cpp
\author Thomas Breuer
\date   14.02.2011
*/

//*******************************************************************

#include <conio.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>

//*******************************************************************
//
// cHwUART_Stdio
//
//*******************************************************************
//-------------------------------------------------------------------
cHwUART_Stdio::cHwUART_Stdio( BYTE echoIn )

: cHwUART(1 , 1 ) // FIFO not used

{
  echo      = echoIn;
  ctrlState = 0;
}

//-------------------------------------------------------------------
bool cHwUART_Stdio::get( BYTE *c )
{
  if( ctrlState == 1)
  {
    ctrlState = 2;
    *c = '[';
    return( true );
  }
  if( _kbhit() )
  {
    *c = _getch();

    if( *c == 224 )
    {
      ctrlState  = 1;
      *c = 27;
      return( true );
    }
    else if( ctrlState == 2)
    {
      ctrlState = 0;
      switch( *c )
      {
        case 'H': *c = 'A'; return( true );
        case 'P': *c = 'B'; return( true );
        case 'M': *c = 'C'; return( true );
        case 'K': *c = 'D'; return( true );
        default:            return( true );
      }
    }
    else
    {
      if( echo )
      {
        putch( *c );
        if( *c == '\r' )
        {
          putch( '\n' );
        }
      }
      return( true );
    }
  }
  else
  {
    return( false );
  }
}

//-------------------------------------------------------------------
void cHwUART_Stdio::transmitByte( BYTE c )
{
  putch( c );
}

//-------------------------------------------------------------------
/*
void cHwUART_Stdio::set( const char *str )
{
  cHwUART::set( str );
}
*/
//-------------------------------------------------------------------
BYTE cHwUART_Stdio::getByte( void )
{
  return( false );
}

//-------------------------------------------------------------------
void cHwUART_Stdio::setByte( BYTE c )
{
}

//*******************************************************************
//
// cHwUART_File
//
//*******************************************************************
//-------------------------------------------------------------------
cHwUART_File::cHwUART_File(const char *fileNameRxD, const char *fileNameTxD )

: cHwUART( 1, 1 ) // FIFO not used

{
  //
  // receive file
  //
  if( fileNameRxD && strlen(fileNameRxD) > 0 )
  {
    fhRxD = open( fileNameRxD, O_RDONLY );
  }
  else
  {
    fhRxD = 0;
  }

  if( fhRxD <= 0 )
  {
      fhRxD = STDIN_FILENO;
  }

  //
  // transmit file
  //
  if( fileNameTxD && strlen(fileNameTxD) > 0 )
  {
    fhTxD = open( fileNameTxD, O_WRONLY|O_CREAT|O_TRUNC, S_IREAD|S_IWRITE );
  }
  else
  {
    fhTxD = 0;
  }

  if( fhTxD <= 0)
  {
      fhTxD = STDOUT_FILENO;
  }
}

//-------------------------------------------------------------------
bool cHwUART_File::get( BYTE *c )
{
  BYTE tmp = 0;

  if( read( fhRxD, &tmp, 1 ) == 1 )
  {
    *c = tmp;
    return(true);
  }
  else
  {
    return(false);
  }
}

//-------------------------------------------------------------------
void cHwUART_File::transmitByte( BYTE c )
{
  write( fhTxD, &c, 1 );
}

//-------------------------------------------------------------------
BYTE cHwUART_File::getByte( void )
{
  return( false );
}

//-------------------------------------------------------------------
void cHwUART_File::setByte( BYTE c )
{
}


//*******************************************************************
//
// cHwUART_Serial
//
//*******************************************************************
//-------------------------------------------------------------------
cHwUART_Serial::cHwUART_Serial(const char *portNameIn )

: cHwUART( 1, 1 ) // FIFO not used

{
  isOpenFlag = false;
  hSerial = INVALID_HANDLE_VALUE;
  if( portNameIn )
  {
    open( portNameIn );
  }
  else
    strncpy( portName, "", 32);
}

//-------------------------------------------------------------------
void cHwUART_Serial::setPortName( const char *portNameIn )
{
  if( portNameIn == 0 || strlen(portNameIn) == 0)
  {
    return;
  }
  else
  {
    strncpy( portName, portNameIn, 32);
  }
}

//-------------------------------------------------------------------
void cHwUART_Serial::open( const char *portNameIn )
{
  char portNameLoc[33];

  if( portNameIn == 0 || strlen(portNameIn) == 0)
  {
    if( portName == 0  || strlen(portName) == 0)
    {
      return;
    }
  }
  else
  {
    strncpy( portName, portNameIn, 32);
  }

  sprintf( portNameLoc, "\\\\.\\%s", portName );
  if( isOpenFlag)
  {
    close();
  }

  isOpenFlag = false;

  DCB          dcbSerialParams = {0};
  COMMTIMEOUTS timeouts        = {0};
//  DWORD        dwBytesWritten  = 0;

  // Open serial port
  hSerial = CreateFile(strtok(portNameLoc," "), GENERIC_READ|GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
  if (hSerial == INVALID_HANDLE_VALUE)
  {
    fprintf(stderr, "Error 0x%x\n", (unsigned int)GetLastError());
    return;
  }
//  fprintf(stderr, "OK\n");

  // Set device parameters
  dcbSerialParams.DCBlength = sizeof(dcbSerialParams);
  if( GetCommState(hSerial, &dcbSerialParams) == 0 )
  {
    fprintf(stderr, "Error getting device state\n");
    CloseHandle(hSerial);
    return;
  }

  dcbSerialParams.BaudRate = CBR_115200;
  dcbSerialParams.ByteSize = 8;
  dcbSerialParams.StopBits = ONESTOPBIT;
  dcbSerialParams.Parity   = NOPARITY;
  if( !SetCommState(hSerial, &dcbSerialParams) )
  {
      fprintf(stderr, "Error setting device parameters\n");
      CloseHandle(hSerial);
      return;
  }

  // Set COM port timeout settings
  timeouts.ReadIntervalTimeout = MAXDWORD;
  timeouts.ReadTotalTimeoutMultiplier = 0;
  timeouts.ReadTotalTimeoutConstant = 0;
  timeouts.WriteTotalTimeoutMultiplier = 10;
  timeouts.WriteTotalTimeoutConstant = 50;
  if( !SetCommTimeouts( hSerial, &timeouts ) )
  {
    fprintf(stderr, "Error setting timeouts\n");
    CloseHandle(hSerial);
    return;
  }
  isOpenFlag = true;
}

//-------------------------------------------------------------------
void cHwUART_Serial::close()
{
  if (hSerial != INVALID_HANDLE_VALUE)
  {
     Sleep(100);
     CloseHandle(hSerial);
     hSerial = INVALID_HANDLE_VALUE;
  }
  isOpenFlag = false;
}

//-------------------------------------------------------------------
bool cHwUART_Serial::get( BYTE *c )
{
//  BYTE tmp = 0;

  if( !isOpenFlag || hSerial == INVALID_HANDLE_VALUE )
  {
    return( false );
  }

  DWORD dwBytesRead = 0;
  if(    !ReadFile( hSerial, c, 1, &dwBytesRead, NULL )
      || dwBytesRead == 0 )
  {
    return( false );
  }
  return( true );
}

//-------------------------------------------------------------------
void cHwUART_Serial::transmitByte( BYTE c )
{
  DWORD dwBytesWritten = 0;

  if( !isOpenFlag || hSerial == INVALID_HANDLE_VALUE )
  {
    return;
  }

  if( !WriteFile( hSerial, &c, 1, &dwBytesWritten, NULL ) )
  {
    close();
//    fprintf(stderr, "Error writing text \n");
  }
}

//-------------------------------------------------------------------
void cHwUART_Serial::set( const BYTE *c, BYTE size )
{
  DWORD dwBytesWritten = 0;

  if( !isOpenFlag || hSerial == INVALID_HANDLE_VALUE )
  {
    return;
  }

  if( !WriteFile( hSerial, c, size, &dwBytesWritten, NULL ) || size != dwBytesWritten)
  {
    close();
//    fprintf(stderr, "Error writing text \n");
  }
}

//-------------------------------------------------------------------
BYTE cHwUART_Serial::getByte( void )
{
  return( false );
}

//-------------------------------------------------------------------
void cHwUART_Serial::setByte( BYTE c )
{
}


//*******************************************************************
//
// cHwUART_MCU
//
//*******************************************************************
//-------------------------------------------------------------------
cHwUART_MCU::cHwUART_MCU( cNetAddr<4> addr, WORD port )

: cHwUART( 1, 1 ), // FIFO not used
  client( addr, port )

{
}

//-------------------------------------------------------------------
bool cHwUART_MCU::get( BYTE *c )
{
  Data data;
  data.cmd = 0; // 0 = READ

  client.transceive((BYTE*)&data, sizeof(Data),(BYTE*)&data, sizeof(Data));
  if( data.cmd == 1 )
  {
    *c = data.value;
    return( true );
  }
  return( false );
}

//-------------------------------------------------------------------
void cHwUART_MCU::transmitByte( BYTE c )
{
  Data data;
  data.cmd = 1; // 1 = WRITE
  data.value = c;

  client.transceive((BYTE*)&data, sizeof(Data),(BYTE*)&data, sizeof(Data));
}

//-------------------------------------------------------------------
BYTE cHwUART_MCU::getByte( void )
{
  return( false );
}

//-------------------------------------------------------------------
void cHwUART_MCU::setByte( BYTE c )
{
}

//EOF
