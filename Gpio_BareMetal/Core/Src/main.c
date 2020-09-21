#include "stm32f4xx.h"

// PA5

// AHB1

// Enable clock for IO port A: Set GPIOAEN (bit 0) in RCC_AHB1ENR to 1
#define GPIOA_EN (1<<0)	// 0b 0000 0000 0000 0000 0000 0000 0000 0001

// Enable output mode at PA5: Set MODER5 to output in GPIOA_MODER
#define MODER_5_OUT (1<<10)
// Write data to pin PA5: Write ODR5 in GPIOA_ODR
#define ODR_5_SET	(1<<5)
#define ODR_5_RESET (0<<5)

// LED PIN: PA5
#define LED_PIN (1<<5)
int main(void)
{
	RCC->AHB1ENR |= GPIOA_EN;
	GPIOA->MODER |= MODER_5_OUT;
	while(1) {
		for (int i = 0; i < 900000; i++){}
		GPIOA->ODR ^= ODR_5_SET;
	}
}
