#include "stm32f4xx_hal.h"          // change to whatever MCU you use
#include "timerFrame.h"

void SoftTimer_ISR(void){

		for(uint8_t i=0; i<TIMER_COUNT; i++){
			if(SoftTimer[i].isRunning==set){
				if(SoftTimer[i].setTime <= SoftTimer[i].Time){
					SoftTimer[i].timeout=set;
				}
				else {
					SoftTimer[i].Time++;
				}	
			}
			else {
				SoftTimer[i].timeout=reset;
				SoftTimer[i].Time=0;
			}
		}
	}
	
	void SoftTimer_Init(eTimerID_t TimerID, unsigned long time){
		SoftTimer[TimerID].Time=0;
		SoftTimer[TimerID].isRunning=set;
		SoftTimer[TimerID].setTime=time;
		SoftTimer[TimerID].timeout=reset;
	}
	
	Bool SoftTimer_GetStatus(eTimerID_t TimerID){
		return (SoftTimer[TimerID].isRunning);
	}

	void SoftTimer_Reset(eTimerID_t TimerID){
		SoftTimer[TimerID].Time=0;
		SoftTimer[TimerID].isRunning=set;
		SoftTimer[TimerID].timeout=reset;
	}