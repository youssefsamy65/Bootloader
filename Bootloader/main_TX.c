

#include "../../MCAL/gpio/gpio.h"
#include "../../MCAL/RCC/RCC.h"
#include "../../common/hex_file.h"
#include "../../MCAL/USART/USART_Driver.h"

// Global variables
u8 one_time_flag = 1;
u8 x = 0;
u8 flag_2 = 0;

// Function to toggle an LED on/off
void on_offLED() {
    flag_2++;
    if (flag_2 % 2 != 0) {
        MGPIO_SetPinValue(GPIO_PORTA, PIN1, VALUE_HIGH);
    } else {
        MGPIO_SetPinValue(GPIO_PORTA, PIN1, VALUE_LOW);
    }
}

// Delay function
void DELAY(u32 ms) {
    for (u32 i = 0; i < 1600 * ms; i++);
}

int main() {
    // Initialize clocks and GPIO
//	  MRCC_SelectCLK(clk_HSI);
	MRCC_EnableClk(clk_HSI);
	MRCC_SelectCLK(clk_HSI);
    MRCC_EnablePeripheralCLK(peri_AHB1_GPIOA, peri_busAHB1);
    MRCC_EnablePeripheralCLK(peri_APB2_USART1, peri_busAPB2);

    // Configure GPIO pins
    MGPIO_SetPinMode(GPIO_PORTA, PIN1, Mode_OUTPUT);
    MGPIO_SetPinMode(GPIO_PORTA, PIN3, Mode_OUTPUT);
    MGPIO_SetPinMode(GPIO_PORTA, PIN9, Mode_AF);
    MGPIO_SetPinMode(GPIO_PORTA, PIN10, Mode_AF);
    MGPIO_Setalternate_function(GPIO_PORTA, PIN9, AF7);
    MGPIO_Setalternate_function(GPIO_PORTA, PIN10, AF7);

    // Initialize USART
    MUSART_Init(USART_1);

    // Calculate the number of rows in 'joe' array


    /* Sending a dummy byte
    MUSART_SendByteSynch(USART_1, '3');
    DELAY(100);*/
    MGPIO_SetPinValue(GPIO_PORTA, PIN3, VALUE_HIGH);
    u16 numRows = sizeof(joe) / sizeof(joe[0]);
    for (u16 i = 0; i < numRows; i++) {
          on_offLED();
            u16 j = 0;
            if (!one_time_flag) {
                while (!MUSART_ReciveByteSynch(USART_1));
            }
            one_time_flag = 0;

            while (joe[i][j] != '\0') {
                MUSART_SendByteSynch(USART_1, joe[i][j]);
DELAY(100);
                j++;
            }
 }
    MGPIO_SetPinValue(GPIO_PORTA, PIN3, VALUE_LOW);

    return 0;
}
