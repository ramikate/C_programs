#include <stdio.h>

int main(int argc, char **argv)
{
	int num;
    scanf("%d", &num);
    
    int sec = 0;
    int min = 0;
    int hours = 0;
    int day = 0;
    
    min = num/60;
    sec = num % 60;
    hours = min/60;
    min = min-hours*60;
    day = hours/24;
    hours = hours-day*24;
    
    
    
    printf("INPUT\n");
    printf("SECONDS?\n");
    printf("%d\n", num);
    printf("OUTPUT\n");
    printf("%d DAYS\n", day);
    printf("%d HOURS\n", hours);
    printf("%d MINUTES\n", min);
    printf("%d SECONDS\n", sec);

	return 0;
}
