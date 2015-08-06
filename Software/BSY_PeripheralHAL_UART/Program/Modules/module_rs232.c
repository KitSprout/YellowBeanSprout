/*====================================================================================================*/
/*====================================================================================================*/
#include "Dirvers\stm32f4_system.h"
#include "Dirvers\stm32f4_usart.h"

#include "Algorithms\algorithm_string.h"

#include "module_rs232.h"
/*====================================================================================================*/
/*====================================================================================================*/
#define UARTx                       USART1
#define UARTx_CLK                   RCC_APB2Periph_USART1
#define UARTx_CLK_ENABLE()          __HAL_RCC_USART1_CLK_ENABLE()

#define UARTx_TX_PIN                GPIO_PIN_6
#define UARTx_TX_GPIO_PORT          GPIOB
#define UARTx_TX_AF                 GPIO_AF7_USART1
#define UARTx_TX_GPIO_CLK_ENABLE()  __HAL_RCC_GPIOB_CLK_ENABLE()

#define UARTx_RX_PIN                GPIO_PIN_7
#define UARTx_RX_GPIO_PORT          GPIOB
#define UARTx_RX_AF                 GPIO_AF7_USART1
#define UARTx_RX_GPIO_CLK_ENABLE()  __HAL_RCC_GPIOB_CLK_ENABLE()

#define UARTx_BAUDRATE              115200
#define UARTx_BYTESIZE              UART_WORDLENGTH_8B
#define UARTx_STOPBITS              UART_STOPBITS_1
#define UARTx_PARITY                UART_PARITY_NONE
#define UARTx_HARDWARECTRL          UART_HWCONTROL_NONE
#define UARTx_MODE                  UART_MODE_TX_RX
#define UARTx_OVERSAMPLE            UART_OVERSAMPLING_16
/*====================================================================================================*/
/*====================================================================================================*/
static UART_HandleTypeDef UART_HandleStruct;
/*====================================================================================================*/
/*====================================================================================================*
**函數 : RS232_Config
**功能 : RS232 Config
**輸入 : None
**輸出 : None
**使用 : RS232_Config();
**====================================================================================================*/
/*====================================================================================================*/
void RS232_Config( void )
{
  GPIO_InitTypeDef GPIO_InitStruct;

  /* UARTx Clk */
  UARTx_TX_GPIO_CLK_ENABLE();
  UARTx_RX_GPIO_CLK_ENABLE();
  UARTx_CLK_ENABLE();

  /* UARTx Pin */
  GPIO_InitStruct.Mode      = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull      = GPIO_PULLUP;
  GPIO_InitStruct.Speed     = GPIO_SPEED_HIGH;

  GPIO_InitStruct.Pin       = UARTx_TX_PIN;
  GPIO_InitStruct.Alternate = UARTx_TX_AF;
  HAL_GPIO_Init(UARTx_TX_GPIO_PORT, &GPIO_InitStruct);

  GPIO_InitStruct.Pin       = UARTx_RX_PIN;
  GPIO_InitStruct.Alternate = UARTx_RX_AF;
  HAL_GPIO_Init(UARTx_RX_GPIO_PORT, &GPIO_InitStruct);

  /* UART Init *****************************************************************/
  UART_HandleStruct.Instance          = UARTx;
  UART_HandleStruct.Init.BaudRate     = UARTx_BAUDRATE;
  UART_HandleStruct.Init.WordLength   = UARTx_BYTESIZE;
  UART_HandleStruct.Init.StopBits     = UARTx_STOPBITS;
  UART_HandleStruct.Init.Parity       = UARTx_PARITY;
  UART_HandleStruct.Init.HwFlowCtl    = UARTx_HARDWARECTRL;
  UART_HandleStruct.Init.Mode         = UARTx_MODE;
//  UART_InitStruct.OverSampling = UARTx_OVERSAMPLE;
  HAL_UART_Init(&UART_HandleStruct);

  __HAL_UART_ENABLE(&UART_HandleStruct);
  __HAL_UART_CLEAR_FLAG(&UART_HandleStruct, UART_FLAG_TC);
}
/*====================================================================================================*/
/*====================================================================================================*
**函數 : RS232_SendByte
**功能 : Send Byte
**輸入 : SendByte
**輸出 : None
**使用 : RS232_SendByte('A');
**====================================================================================================*/
/*====================================================================================================*/
void RS232_SendByte( uint8_t SendByte )
{
  UART_SendByte(UARTx, &SendByte);
}
/*====================================================================================================*/
/*====================================================================================================*
**函數 : RS232_RecvByte
**功能 : Recv Byte
**輸入 : None
**輸出 : RecvByte
**使用 : RecvByte = RS232_RecvByte();
**====================================================================================================*/
/*====================================================================================================*/
uint8_t RS232_RecvByte( void )
{
  uint8_t RecvByte = 0;
  UART_RecvByte(UARTx, &RecvByte);
  return RecvByte;
}
/*====================================================================================================*/
/*====================================================================================================*
**函數 : RS232_SendData
**功能 : Send Bytes
**輸入 : *SendData, DataLen
**輸出 : None
**使用 : RS232_SendData(SendData, DataLen);
**====================================================================================================*/
/*====================================================================================================*/
void RS232_SendData( uint8_t *SendData, uint16_t DataLen )
{
  UART_SendData(UARTx, SendData, DataLen);
}
/*====================================================================================================*/
/*====================================================================================================*
**函數 : RS232_RecvData
**功能 : Recv Bytes
**輸入 : *RecvData, DataLen
**輸出 : None
**使用 : RS232_RecvData(RecvData, DataLen);
**====================================================================================================*/
/*====================================================================================================*/
void RS232_RecvData( uint8_t *RecvData, uint16_t DataLen )
{
  UART_RecvData(UARTx, RecvData, DataLen);
}
/*====================================================================================================*/
/*====================================================================================================*
**函數 : RS232_RecvDataWTO
**功能 : Recv Bytes with Timeout
**輸入 : *RecvData, DataLen, TimeoutMs
**輸出 : State
**使用 : RS232_RecvDataWTO(RecvData, DataLen, 200);
**====================================================================================================*/
/*====================================================================================================*/
int8_t RS232_RecvDataWTO( uint8_t *RecvData, uint16_t DataLen, uint32_t TimeoutMs )
{
  return UART_RecvDataWTO(UARTx, RecvData, DataLen, TimeoutMs);
}
/*====================================================================================================*/
/*====================================================================================================*
**函數 : RS232_SendStr
**功能 : Send String
**輸入 : *pWord
**輸出 : None
**使用 : RS232_SendStr("Hello World!");
**====================================================================================================*/
/*====================================================================================================*/
void RS232_SendStr( char *pWord )
{
  do {
    UART_SendByte(UARTx, (uint8_t*)pWord++);
  } while(*pWord != '\0');
}
/*====================================================================================================*/
/*====================================================================================================*
**函數 : RS232_RecvStr
**功能 : Recv String
**輸入 : *pWord
**輸出 : None
**使用 : RS232_RecvStr(RecvStirng);
**====================================================================================================*/
/*====================================================================================================*/
void RS232_RecvStr( char *pWord )
{
  do {
    UART_RecvByte(UARTx, (uint8_t*)pWord++);
  } while(*(pWord-1) != '\0');
  *pWord = '\0';
}
/*====================================================================================================*/
/*====================================================================================================*
**函數 : RS232_RecvStrWTO
**功能 : Recv String with Timeout
**輸入 : *pWord, TimeoutMs
**輸出 : State
**使用 : RS232_RecvStrWTO(RecvStirng, 200);
**====================================================================================================*/
/*====================================================================================================*/
int8_t RS232_RecvStrWTO( char *pWord, uint32_t TimeoutMs )
{
  int8_t State = ERROR;

  do {
    State = UART_RecvByteWTO(UARTx, (uint8_t*)pWord++, TimeoutMs);
    if(State == ERROR)
      return ERROR;
  } while(*(pWord-1) != '\0');
  *pWord = '\0';

  return SUCCESS;
}
/*====================================================================================================*/
/*====================================================================================================*
**函數 : RS232_SendNum
**功能 : 將數值轉字串發送
**輸入 : Type, NumLen, SendData
**輸出 : None
**使用 : RS232_SendNum(Type_O, 6, 1024);
**====================================================================================================*/
/*====================================================================================================*/
void RS232_SendNum( StrType Type, uint8_t NumLen, int32_t SendData )
{
  char TrData[32] = {0};
  char *pWord = TrData;

  Str_NumToChar(Type, NumLen, TrData, SendData);

  do {
    UART_SendByte(UARTx, (uint8_t*)pWord++);
  } while(*pWord != '\0');
}
/*====================================================================================================*/
/*====================================================================================================*/
int fputc( int ch, FILE *f )
{
  UARTx->DR = ((uint8_t)ch & (uint16_t)0x00FF);
  while(!(USART1->SR & UART_FLAG_TXE));
  return (ch);
}
/*====================================================================================================*/
/*====================================================================================================*/
