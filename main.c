#include <stdio.h>

int main(int argc, char **argv)
{
	int num; // pedimos al usuario que introduzca un numero entero
    scanf("%d", &num);
    
    //declaramos las variables que vamos a utilizar
    int sec;
    int min;
    int hours;
    int day;
    
    
    //hacemos las operaciones matematicas
    min = num/60;
    sec = num % 60;
    hours = min/60;
    min = min-hours*60;
    day = hours/24;
    hours = hours-day*24;
    
    
    //mostramos el input del usuario
    printf("INPUT\n");
    printf("SECONDS?\n");
    printf("%d\n", num);
    
    //mostramos el output pedido 
    printf("OUTPUT\n");
    printf("%d DAYS\n", day);
    printf("%d HOURS\n", hours);
    printf("%d MINUTES\n", min);
    printf("%d SECONDS\n", sec);

	return 0;
}
