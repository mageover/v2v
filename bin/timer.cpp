#include "timer.h"
#include <stdio.h>


public Timer::Timer() {
	this->which = ITIMER_REAL;
}

public void Timer::start() {
	int ret = setitimer(which, &t_interval, NULL);
	if(ret!=0) {
		printf("timer start failed!\n");
	}
}