#include <sys/time.h>

class Timer{
	private:
		struct itimerval t_interval;
		int which;
		
	public:
		Timer();
		void start();
		void setTInterval(struct itimerval t) {
			t_interval = t;
		}
		void setType(int i) {
			which = i;
		}
		
};