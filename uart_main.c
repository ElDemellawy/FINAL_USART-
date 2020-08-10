/*
 * File:   uart_main.c
 * Author: ELDEMELAWY
 *
 * Created on August 10, 2020, 2:27 AM
 */

#include <avr/io.h>

void UART_INTI () // USART INITAILZATION FUNCATION 
{
    UCSRB |= (1<<TXEN);// TRANSMITTER ENABLE 
    UCSRB |= (1<<RXEN); // RECEIVER ENABLE 
    UCSRC |= (1<<URSEL); // REGISER SELECTOR 
    UCSRC |= (1<<UCSZ1);
    UCSRC |= (1<<UCSZ0);// IT MEANS THAT I WILL USE 8 BIT IN FRAME 
    UCSRB |= (1<<RXCIE) ; // RECIVE INTERRUPT 
    UBRRL = 51; // BUDE RATE 9600 MBPS 
}


void UART_TRANSMITCHAR (char data)
{
    while (!(UCSRA & (1<<UDRE))) // (pooling) wait register to be empty 
    {
        UDR = data ;
    }
}

int UART_Recieve_data()
{
	while(!(UCSRA) & (1<<RXC)); // pooling to check if the recieve  is completed 
    
	return 1 ;	
}

int main(void) {
    while (1) {
       
    }
}
