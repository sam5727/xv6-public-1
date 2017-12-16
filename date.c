#include "types.h"
#include "user.h"
#include "date.h"

int main(int argc, char *argv[])
{
	struct rtcdate r;
	//char tmp[1];
	if(date(&r))
	{
		printf(2, "date failed\n");
		exit();
	}
	r.hour += 8;
	if(r.hour >= 24){
		r.hour -= 24;
		r.day += 1;
	}

	printf(1, "The time is: ");
	pulseZero(r.year, "/");
	pulseZero(r.month, "/");
	pulseZero(r.day, " ");
	pulseZero(r.hour, ":");
	pulseZero(r.minute, ":");
	pulseZero(r.second, " ");
	printf(1, "\n");

	// // printf(1, "%d-%d %d %d:%d:%d\n", r.month, r.day, r.year, r.hour, r.minute, r.second);

	exit();
}

void pulseZero(int num, char* c)
{

	if(num < 10)
		printf(1,"0%d", num);
	else
		printf(1,"%d", num);

	printf(1, "%s", c);

}