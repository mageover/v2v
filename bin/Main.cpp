#include "timer.h"
#include <stdio.h>
#include <signal.h>
#include <pthread.h>
#include <sys/types.h>

void* proc_thread1(void* arg) {
	Timer t1;
	struct itimerval value;
	
	struct timeval it_interval;
	it_interval.tv_sec = 1;
	it_interval.tv_usec = 0;
	
	struct timeval it_value;
	it_value.tv_sec = 0;
	it_value.tv_usec = 1;
	
	value.it_interval = it_interval;
	value.it_value = it_value;
	
	t1.setTInterval(value);
	t1.start();
}

void* proc_thread2(void* arg) {
	Timer t2;
	struct itimerval value;
	
	struct timeval it_interval;
	it_interval.tv_sec = 2;
	it_interval.tv_usec = 0;
	
	struct timeval it_value;
	it_value.tv_sec = 0;
	it_value.tv_usec = 1;
	
	value.it_interval = it_interval;
	value.it_value = it_value;
	
	t2.setTInterval(value);
	t2.start();
}

void handler_alarm(int signo) {
	switch(signo) {
		case SIGALRM:
			printf("recv SIGALRM.\n");
			break;
		default:
			break;
	}
	
}

int main() {
	pthread_t p1, p2;
	signal(SIGALRM, handler_alarm);
	
	
	int ret = pthread_create(&p1, NULL, proc_thread1, NULL);
	if(ret!=0) {
		printf("thread1 create failed!\n");
		exit(-1);
	}
	
	ret = pthread_create(&p2, NULL, proc_thread2, NULL);
	if(ret!=0) {
		printf("thread2 create failed!\n");
		exit(-1);
	}
	
	return 0;
}