#include "uart.h"
#include "PWM.h"
#include "system.h"
#include "gpio.h"
#include "interrupt.h"
#include "app.h"
static int check_uart_mode = 0;
uint8_t msg;
static int status;
int i ;
int j ;
typedef struct {
  int stx;
  int id;
  int len;
  int data[10];
  int etx;
}frameMsg;
void SW_Mode()
{
  Off_Red_Led();
  SW_Init();
}
void Uart_Mode()
{
  On_Red_Led();
  speed(0);
}
void control()
{
    frameMsg frame;
    status = 0;
    switch(status)
    {
      
      case 0:
          msg = UartRxByte();
          if(msg == '2'){
            frame.stx = msg;
            status = 1;
          }
          else{
            break;
            status = 0;
          }
      case 1:
          msg =  UartRxByte();
          frame.id = msg;
          status = 2;
      case 2:
          msg =  UartRxByte();
          if(msg == 0){
            status = 0;
            break;
          }
          else{
            frame.len = msg;
            status = 3;
          }
      case 3:
          char str[] = frame.len;
          int a = atoi(str); // Convert string to integer
          for(i=0;i < a;i++){
            frame.data[i] = UartRxByte();
          }
          status = 4;
    case 4:
          msg = UartRxByte();
          if(msg == '3'){
            frame.etx = msg;
            status =0;
           }
          break;
      default:
      status = 0;
    }

    /* Mode selection */
   if(frame.stx == '2' && frame.id == '1' && frame.len == '1' && frame.etx == '3')
      {
          switch(frame.data[0])
          {
          case '0':
            Uart_Mode();
            check_uart_mode == 1;
            UART_putstr("0x02 0x81 0x01 0x00 0x03 \n");
            break;
          case '1':
            check_uart_mode == 0;
            SW_Mode();
            UART_putstr("0x02 0x82 0x01 0x00 0x03 \n");
            break;
          default:
            check_uart_mode == 0;
            Uart_Mode();
          }
      }
    
    /* Speed */
   if(frame.stx == '2' && frame.id == '2' && frame.len == '1' && frame.etx == '3' && check_uart_mode == 1)
      {
          switch(frame.data[0])
          {
          case '0':
            speed(0);
          case '1':
            speed(1);
          case '2':
            speed(2);
          case '3':
            speed(3);
          default:
            speed(0);
          }
      } 
  }