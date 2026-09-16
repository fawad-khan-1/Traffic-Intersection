#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"

#define REDLED1_PORT    GPIO_PORTB_BASE  //N-S red on Port B, pin 0
#define REDLED1_PIN     GPIO_PIN_0
#define YELLOWLED1_PORT    GPIO_PORTB_BASE  //N-S yellow on Port B, pin 1
#define YELLOWLED1_PIN     GPIO_PIN_1
#define GREENLED1_PORT    GPIO_PORTB_BASE  //N-S green on Port B, pin 2
#define GREENLED1_PIN     GPIO_PIN_2
#define REDLED2_PORT    GPIO_PORTB_BASE  //E-W red on Port B, pin 3
#define REDLED2_PIN     GPIO_PIN_3
#define YELLOWLED2_PORT    GPIO_PORTB_BASE  //E-W yellow on Port B, pin 4
#define YELLOWLED2_PIN     GPIO_PIN_4
#define GREENLED2_PORT    GPIO_PORTB_BASE  //E-W green on Port B, pin 5
#define GREENLED2_PIN     GPIO_PIN_5
#define REDLED3_PORT    GPIO_PORTE_BASE  //Pedestrian red on Port E, pin 0
#define REDLED3_PIN     GPIO_PIN_0
#define GREENLED3_PORT    GPIO_PORTE_BASE  //Pedestrian green on Port E, pin 1
#define GREENLED3_PIN     GPIO_PIN_1
#define BUTTONPIN1_PORT   GPIO_PORTA_BASE  //Pedestrian crosswalk
#define BUTTONPIN1_PIN    GPIO_PIN_2
#define BUTTONPIN2_PORT   GPIO_PORTA_BASE  //N-S traffic
#define BUTTONPIN2_PIN    GPIO_PIN_3
#define BUTTONPIN3_PORT   GPIO_PORTA_BASE  //E-W traffic
#define BUTTONPIN3_PIN    GPIO_PIN_4

int pedButton = 0; //Pedestrian crosswalk closed by default
int sensorNS;
int sensorEW;
bool nsFlag;  //state of North-South lights
bool ewFlag;  //state of East-West lights

void setup()
{
	// 1. Enable GPIO Port A, B and E 
  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
	while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOA))
{
}
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOB))
{
}
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOE))
{
}
  	
	GPIOPinTypeGPIOOutput(REDLED1_PORT, REDLED1_PIN);  //N-S Red
	GPIOPinTypeGPIOOutput(YELLOWLED1_PORT, YELLOWLED1_PIN);  //N-S Yellow
	GPIOPinTypeGPIOOutput(GREENLED1_PORT, GREENLED1_PIN);  //N-S Green
	GPIOPinTypeGPIOOutput(REDLED2_PORT, REDLED2_PIN);  //E-W Red
	GPIOPinTypeGPIOOutput(YELLOWLED2_PORT, YELLOWLED2_PIN);  //E-W Yellow
	GPIOPinTypeGPIOOutput(GREENLED2_PORT, GREENLED2_PIN);  //E-W Green
	GPIOPinTypeGPIOOutput(REDLED3_PORT, REDLED3_PIN);  //Pedestrian Red
	GPIOPinTypeGPIOOutput(GREENLED3_PORT, GREENLED3_PIN);  //Pedestrian Green
	GPIOPinTypeGPIOInput(BUTTONPIN1_PORT, BUTTONPIN1_PIN); //Pedestrian Crosswalk Inpu
	GPIOPinTypeGPIOInput(BUTTONPIN2_PORT, BUTTONPIN2_PIN); //N-S Traffic Input
	GPIOPinTypeGPIOInput(BUTTONPIN3_PORT, BUTTONPIN3_PIN); //E-W Traffic Input
  GPIOPinWrite(GREENLED1_PORT, GREENLED1_PIN, GREENLED1_PIN);
  GPIOPinWrite(REDLED2_PORT, REDLED2_PIN, REDLED2_PIN);
  GPIOPinWrite(REDLED3_PORT, REDLED3_PIN, REDLED3_PIN);
  
  sensorNS = 1;
  sensorEW = 0;
	nsFlag = 1;
	ewFlag = 0;
}

void NSTraffic()
	{
		//Function Code
		GPIOPinWrite(REDLED3_PORT, REDLED3_PIN, REDLED3_PIN);  //turn on red LED on pedestrian crosswalk
		SysCtlDelay(16000000 * 5 / 3);    //wait 5 seconds
		GPIOPinWrite(GREENLED2_PORT, GREENLED2_PIN, 0);   //turn off green LED on E-W traffic
		for(int i=0;i<3;i++)   //blink yellow LED on E-W traffic 3 times
		{
			SysCtlDelay(16000000 /3 / 2);  //wait 0.5 seconds
			GPIOPinWrite(YELLOWLED2_PORT, YELLOWLED2_PIN, YELLOWLED2_PIN);  //turn on yellow LED on E-W traffic
			SysCtlDelay(16000000 /3 / 2);  //wait 0.5 seconds
			GPIOPinWrite(YELLOWLED2_PORT, YELLOWLED2_PIN, 0);  //turn off yellow LED on E-W traffic
		}
		SysCtlDelay(16000000 / 3 / 2);     //wait 0.5 seconds
		GPIOPinWrite(REDLED2_PORT, REDLED2_PIN, REDLED2_PIN);  //turn on red LED on E-W traffic
		GPIOPinWrite(GREENLED1_PORT, GREENLED1_PIN, GREENLED1_PIN);  //turn on green LED on N-S traffic
		nsFlag = 1;
		ewFlag = 0;
		GPIOPinWrite(REDLED1_PORT, REDLED1_PIN, 0);  //turn off red LED on N-S traffic
	}
	
	void EWTraffic()
	{
		//Function Code
		GPIOPinWrite(REDLED3_PORT, REDLED3_PIN, REDLED3_PIN); //turn on red LED on pedestrian crosswalk
		SysCtlDelay(16000000 * 5 / 3);  //wait 5 seconds
		GPIOPinWrite(GREENLED1_PORT, GREENLED1_PIN, 0);  //turn off green LED on N-S traffic
		for(int i=0;i<3;i++)  //blink yellow LED on N-S traffic 3 times
		{
			SysCtlDelay(16000000 /3 / 2);  //wait 0.5 seconds
			GPIOPinWrite(YELLOWLED1_PORT, YELLOWLED1_PIN, YELLOWLED1_PIN);  //turn on yellow LED on N-S traffic
			SysCtlDelay(16000000 /3 / 2);  //wait 0.5 seconds
			GPIOPinWrite(YELLOWLED1_PORT, YELLOWLED1_PIN, 0);  //turn off yellow LED on N-S traffic
		}
		SysCtlDelay(16000000 / 3 / 2);     //wait 0.5 seconds
		GPIOPinWrite(REDLED1_PORT, REDLED1_PIN, REDLED1_PIN);  //turn on red LED on N-S traffic
		GPIOPinWrite(GREENLED2_PORT, GREENLED2_PIN, GREENLED2_PIN);  //turn on green LED on E-W traffic
		nsFlag = 0;
		ewFlag = 1;
		GPIOPinWrite(REDLED2_PORT, REDLED2_PIN, 0);  //turn off red LED on E-W traffic
	}
	
	void PedCrossWalk()
	{
		//Function Code
		if (nsFlag != 0)  //If North-South light is green
		{
			GPIOPinWrite(GREENLED1_PORT, GREENLED1_PIN, 0);  //turn off green LED on N-S traffic
			for(int i=0;i<3;i++)  //blink yellow LED on N-S traffic 3 times
			{
				SysCtlDelay(16000000 / 3 / 2);     //wait 0.5 seconds
				GPIOPinWrite(YELLOWLED1_PORT, YELLOWLED1_PIN, YELLOWLED1_PIN);  //turn on yellow LED on N-S traffic
				SysCtlDelay(16000000 / 3 / 2);     //wait 0.5 seconds
				GPIOPinWrite(YELLOWLED1_PORT, YELLOWLED1_PIN, 0);  //turn off yellow LED on N-S traffic
			}
			SysCtlDelay(16000000 / 3 / 2);     //wait 0.5 seconds
			GPIOPinWrite(REDLED1_PORT, REDLED1_PIN, REDLED1_PIN);  //turn on red LED on N-S traffic
		}
		else if (ewFlag != 0)  //If East-West light is green
		{
		  GPIOPinWrite(GREENLED2_PORT, GREENLED2_PIN, 0);  //turn off green LED on E-W traffic
			for(int i=0;i<3;i++)   //blink yellow LED on E-W traffic
			{
				SysCtlDelay(16000000 / 3 / 2);     //wait 0.5 seconds
				GPIOPinWrite(YELLOWLED2_PORT, YELLOWLED2_PIN, YELLOWLED2_PIN);  //turn on yellow LED on E-W traffic
				SysCtlDelay(16000000 / 3 / 2);     //wait 0.5 seconds
				GPIOPinWrite(YELLOWLED2_PORT, YELLOWLED2_PIN, 0);  //turn off yellow LED on E-W traffic
			}
			SysCtlDelay(16000000 / 3 / 2);     //wait 0.5 seconds
			GPIOPinWrite(REDLED2_PORT, REDLED2_PIN, REDLED2_PIN);  //turn on red LED on E-W traffic
		}
		GPIOPinWrite(REDLED3_PORT, REDLED3_PIN, 0);  //turn off red LED on pedestrian crosswalk
		GPIOPinWrite(GREENLED3_PORT, GREENLED3_PIN, GREENLED3_PIN);  //turn on green LED on pedestrian crosswalk
		SysCtlDelay(16000000 * 5 / 3);  //wait 5 seconds
		for(int i=0;i<5;i++)     //blink green LED on pedestrian crosswalk 5 times
			{
				SysCtlDelay(16000000 / 3 / 2);     //wait 0.5 seconds
				GPIOPinWrite(GREENLED3_PORT, GREENLED3_PIN, GREENLED3_PIN);  //turn on green LED on pedestrian crosswalk
				SysCtlDelay(16000000 / 3 / 2);     //wait 0.5 seconds
				GPIOPinWrite(GREENLED3_PORT, GREENLED3_PIN, 0);  //turn off green LED on pedestrian crosswalk
			}
		pedButton = 0;
		GPIOPinWrite(REDLED3_PORT, REDLED3_PIN, REDLED3_PIN);
    GPIOPinWrite(REDLED1_PORT, REDLED1_PIN, 0); 
    GPIOPinWrite(GREENLED1_PORT, GREENLED1_PIN, GREENLED1_PIN); 
    nsFlag = 1;
		ewFlag = 0;	
	}
		

int main(void){
	setup();
	while(1) 
	{
		pedButton = GPIOPinRead(BUTTONPIN1_PORT, BUTTONPIN1_PIN);
		sensorNS = GPIOPinRead(BUTTONPIN2_PORT, BUTTONPIN2_PIN);
		sensorEW = GPIOPinRead(BUTTONPIN3_PORT, BUTTONPIN3_PIN);
		
		if (sensorEW != 0)
		{
			if (ewFlag == 0)
			{ //EWTraffic function goes here
				EWTraffic();
			}
		}
		else if (sensorNS != 0)
		{ 
			if (nsFlag == 0)
			{ //NSTraffic function goes here
				NSTraffic();
			}
		}
		else if (pedButton != 0)
		{
			//PedCrossWalk function goes here
			PedCrossWalk();
		}
	}
}
	
	
	
		
				
				
			
		
	



