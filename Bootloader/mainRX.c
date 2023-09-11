#include "../../MCAL/gpio/gpio.h"
#include "../../MCAL/RCC/RCC.h"
#include "../../MCAL/USART/USART_Driver.h"
#include "../MCAL/STK/STK_Driver.h"
#include"main.h"

#define APP_entry_address 0x08004004 //
#define APP_vector_adress 0x08004000 //
void clear_data(u8* data_cleared);
typedef void (*Function_t)(void);
Function_t AppCall = NULL;

//*pnter func=0;

u8 RecBuffer[100]={0};

u32  Rec_couter=0;

u8 erase_flag=1;

u8 flag_2=0;

void on_offLED() {
    flag_2++;
    if (flag_2 % 2 != 0) {
        MGPIO_SetPinValue(GPIO_PORTA, PIN1, VALUE_HIGH);
    } else {
        MGPIO_SetPinValue(GPIO_PORTA, PIN1, VALUE_LOW);
    }
}

void DELAY(u32 ms) {
    for (u32 i = 0; i < 1600 * ms; i++);
}



int main(){
	u8 record=0;
	MRCC_EnableClk(clk_HSI);
	MRCC_SelectCLK(clk_HSI);
	MRCC_EnablePeripheralCLK(peri_AHB1_GPIOA,peri_busAHB1);
	MRCC_EnablePeripheralCLK(peri_APB2_USART1,peri_busAPB2);
	MRCC_EnablePeripheralCLK(peri_APB1_USART2,peri_busAPB1);


	 MGPIO_SetPinMode(GPIO_PORTA,PIN1,Mode_OUTPUT);
	 MGPIO_SetPinMode(GPIO_PORTA,PIN2,Mode_OUTPUT);
		MGPIO_SetPinValue(GPIO_PORTA, PIN2, VALUE_HIGH);

	 MGPIO_SetPinMode(GPIO_PORTA,PIN9,Mode_AF);
   MGPIO_SetPinMode(GPIO_PORTA,PIN10,Mode_AF);
   MGPIO_Setalternate_function(GPIO_PORTA,PIN9,AF7);
   MGPIO_Setalternate_function(GPIO_PORTA,PIN10,AF7);


   MUSART_Init(USART_1);

   STK_PeriodMS(15000);
   STK_CallBack(&func_app);

   STK_StartInit();

   while(1)
   {


	   record=MUSART_ReciveByteSynch(USART_1);

	   if(record)
	   {
		 //  task_2();
		   STK_Stop();
		 if( record !='Q' ){
		   RecBuffer[Rec_couter] =record;
		 }

		   if(record=='Q')
		   {

			   Rec_couter=0;
			   if(erase_flag)
			   {
			   flash_AreaErase(sector1,sector7);
			   erase_flag=0;
			   }

			   ParseRecord(RecBuffer);

			   clear_data(RecBuffer);
			   on_offLED();
			       MUSART_SendByteSynch(USART_1, '1');

		   }
		   else
		   {

			Rec_couter++;
		   }

	   }
	   else
	   {
		/*do nothing*/

	   }
   }
	return 0;
}

void clear_data(u8* data_cleared)
{
    u8 LOC_u8Iterator1 = 0 ;

    for( LOC_u8Iterator1 = 0 ; LOC_u8Iterator1 < 60 ; LOC_u8Iterator1++ ){

        data_cleared[ LOC_u8Iterator1 ] = 0 ;

    }
}
void func_app()
{


		//1-set vector table address
	    #define SCB_VTOR  *((volatile u32*) 0xE000ED08)
		SCB_VTOR=APP_vector_adress;

		//2-set entry point address
		AppCall=*(Function_t*)APP_entry_address;
		AppCall();

}


