# Software-Timer-Framework-STM32

Construction timer framework with using Systick timer of STM32 family. It can be used for projects that need lots of timing. If the project needs several peripheral-timers for timing tasks, this frame can be much more useful. In default, the systick timer generates an interrupt every 1ms. Thanks to this feature, fixed-size timers can be created.  # of available timers can be configured by giving values to TIMER_COUNT in timerFrame.h file.
