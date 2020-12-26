#ifndef __TIMER_FRAME_EO
#define __TIMER_FRAME_EO

#define TIMER_COUNT 4

typedef enum{
	
	reset=0x00,
	set=0xff,
	
}Bool;

typedef enum{
	
	eTimerID1=0x01,
	eTimerID2,
	eTimerID3,
	
	eTimerIDMax=0xff,
	
}eTimerID_t;

typedef struct{

	Bool isRunning;
	volatile Bool timeout;
	unsigned long setTime;
	unsigned long Time;
	
}stTimer_t;

static stTimer_t SoftTimer[TIMER_COUNT];

void SoftTimer_ISR(void);
void SoftTimer_Init(eTimerID_t TimerID, unsigned long time);
Bool SoftTimer_GetStatus(eTimerID_t TimerID);
void SoftTimer_Reset(eTimerID_t TimerID);

#endif 
