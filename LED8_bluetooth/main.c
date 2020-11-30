/*
 * LED8_bluetooth.c
 *
 * Created: 26/05/2020 16:43:03
 * Author : bee
 */ 
#define F_CPU 16000000L
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "USART_M328P.h"
uint8_t buffer;
volatile uint8_t StrRX_flag = 0;

// led function
int led_0();
int led_1();
int led_2();
int led_3();
int led_4();
int led_5();
int led_6();
int led_7();

int led_A();
int led_B();
int led_C();
int led_D();
int led_E();
int led_F();
int led_G();
int led_H();







ISR(USART_RX_vect){
	buffer = UDR0;
	StrRX_flag = 1;
}

int main(void)
{
	DDRB = 0b11111111; // set port b0,1,2,3,4,5 as output led0-5
	DDRD = 0b11000000; // set port d0,1 as input for tx and rx; set port d06,7 as output for led6-7
	USART0Init();
	sei();
	USART_putstring("A");
	USART_send_char(10);

	
   
    while (1) 
    {
		if (StrRX_flag == 1){
			// led on
			led_0();
			led_1();
			led_2();
			led_3();
			led_4();
			led_5();
			led_6();
			led_7();
			// led off
			led_A();
			led_B();
			led_C();
			led_D();
			led_E();
			led_F();
			led_G();
			led_H();
			
		StrRX_flag =0;
		}
		
	
    }//end while
}//end main



led_0(){
	if(buffer == 48){
		PORTB |= (1<<PORTB0); //led0 on
		USART_putstring("led0 on");
		USART_send_char(10);
	}
}

led_A(){
	if(buffer == 65){
		PORTB &=~ (1<<PORTB0); //led0 off
		USART_putstring("led0 off");
		USART_send_char(10);
	}
}
led_1(){
	if(buffer == 49){
		PORTB |= (1<<PORTB1); //led1 on
		USART_putstring("led1 on");
		USART_send_char(10);
	}
}

led_B(){
	if(buffer == 66){
		PORTB &=~ (1<<PORTB1); //led1 off
		USART_putstring("led1 off");
		USART_send_char(10);
	}	
}
led_2(){
	if(buffer == 50){
		PORTB |= (1<<PORTB2); //led2 on
		USART_putstring("led2 on");
		USART_send_char(10);
	}
}

led_C(){
	if(buffer == 67){
		PORTB &=~ (1<<PORTB2); //led2 off
		USART_putstring("led2 off");
		USART_send_char(10);
	}
}
led_3(){
	if(buffer == 51){
		PORTB |= (1<<PORTB3); //led3 on
		USART_putstring("led3 on");
		USART_send_char(10);
	}
}

led_D(){
	if(buffer == 68){
		PORTB &=~ (1<<PORTB3); //led3 off
		USART_putstring("led3 off");
		USART_send_char(10);
	}
}

led_4(){
	if(buffer == 52){
		PORTB |= (1<<PORTB4); //led4 on
		USART_putstring("led4 on");
		USART_send_char(10);
	}
}

led_E(){
	if(buffer == 69){
		PORTB &=~ (1<<PORTB4); //led4 off
		USART_putstring("led4 off");
		USART_send_char(10);
	}
}
led_5(){
	if(buffer == 53){
		PORTB |= (1<<PORTB5); //led5 on
		USART_putstring("led5 on");
		USART_send_char(10);
	}
}

led_F(){
	if(buffer == 70){
		PORTB &=~ (1<<PORTB5); //led5 off
		USART_putstring("led5 off");
		USART_send_char(10);
	}
}
led_6(){
	if(buffer == 54){
		PORTD |= (1<<PORTD6); //led6 on
		USART_putstring("led6 on");
		USART_send_char(10);
	}
}
led_G(){
	if(buffer == 71){
		PORTD &=~ (1<<PORTD6); //led6 off
		USART_putstring("led6 off");
		USART_send_char(10);
	}
}

led_7(){
	if(buffer == 55){
		PORTD |= (1<<PORTD7); //led7 on
		USART_putstring("led7 on");
		USART_send_char(10);
	}
}

led_H(){
	if(buffer == 72){
		PORTD &=~ (1<<PORTD7); //led7 off
		USART_putstring("led7 off");
		USART_send_char(10);
	}
}