#include <stdio.h>
#include <stdbool.h>

typedef enum {MOTORCYCLE, CAR, VAN, TRUCK} tvehicle;
typedef enum {MON, TUE, WED, THU, FRI, SAT, SUN} tday;

int main(int argc, char **argv)
{
    printf("INPUT\n");
    //declaramos las variables que vamos a utilizar:
    
     
    tvehicle vehicle; 
    int userEntryVeh; //usamos una variable para que el usuario nos diga el tipo
    printf("VEHICLE (0-MOTORCYCLE, 1-CAR, 2-VAN, 3-TRUCK)?\n");
    scanf("%d", &userEntryVeh); // guardamos la entrada como integer
    vehicle = (tvehicle)userEntryVeh; //hacemos cast al enumerativo
    
    int electric; 
    printf("IS AN ELECTRIC VEHICLE (0-FALSE, 1-TRUE)?\n");
    scanf("%d", &electric); // pedimos al usuario que introduzca si es electrico
    
    int passengers; 
    printf("PASSENGERS?\n");
    scanf("%d", &passengers);// pedimos al usuario que introduzca el numero de pasageros
    
     
    tday day; 
    int userEntryDay; //usamos una variable para que el usuario nos diga el dia que es
    printf("DAY (0-MON, 1-TUE, 2-WED, 3-THU, 4-FRI, 5-SAT, 6-SUN)?\n");
    scanf("%d", &userEntryDay); // guardamos la entrada como integer
    day = (tday)userEntryDay; //hacemos cast al enumerativo
    
    
    
    
    //hacemos las operaciones que nos diran el valor de la variable discount
    bool discount;
    discount = 
        ((vehicle == MOTORCYCLE || vehicle == CAR || vehicle == VAN) && (day == MON || day == TUE)) ||
        ((vehicle == TRUCK) && (day >= MON && day <= FRI)) ||
        ((vehicle == CAR) && (passengers >=4)) || 
        (electric);

    
    //mostramos si le pertenece o no descuento
    printf("OUTPUT\n");
    printf("HAS DISCOUNT (0-FALSE, 1-TRUE): %d\n", discount);
        
    
	return 0;
}
