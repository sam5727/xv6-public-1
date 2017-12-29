#include "types.h"
#include "user.h"
#include "date.h"

int main(int argc, char *argv[])
{
	struct rtcdate r;
	if(date(&r))
	{
		printf(2, "date failed\n");
		exit();
	}

	if(argc == 2)
	{
		if(atoi(argv[1]) > 12 || atoi(argv[1]) <-12)
		{
			printf(2, "TimeArea Error\n");
			exit();
		}
		
		int newHour = r.hour + atoi(argv[1]);

		if(newHour >= 24)
		{
			r.hour = newHour - 24;
			r.day += 1;
		}
		else if(newHour < 0)
		{	
			r.hour = r.hour + 24 - atoi(argv[1]);
			r.day -= 1;
		}
		else
		{
			r.hour = newHour;
		}
	}
	else
	{
		r.hour += 8;
		if(r.hour >= 24)
		{
			r.hour -= 24;
			r.day += 1;
		}
	}
	printf(1, "The time is: ");
	pulseZero(r.year, "/");
	pulseZero(r.month, "/");
	pulseZero(r.day, " ");
	pulseZero(r.hour, ":");
	pulseZero(r.minute, ":");
	pulseZero(r.second, " ");
	printf(1, "\n");

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