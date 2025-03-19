#include <stdio.h>

int main() {
    FILE* archivo; // Identificamos el fichero

  //Creamos las variables que vamos a usar:
    char matriz[3][3]; // Matriz de 3x3
    int contadorO = 0; // Contador de 'O'
    char nombreArchivo[50]; // Para almacenar el nombre del archivo

    // Pedimos al usuario el nombre del archivo
    printf("FILENAME?\n");
    scanf("%49s", nombreArchivo); // Leer el nombre del archivo desde teclado

    // Abrimos el archivo en modo lectura
    archivo = fopen(nombreArchivo, "r");
  

    // Leemos la matriz 3x3 desde el archivo
    // Añadimos espacios entre caracteres porque es lo que se va a encontrar el fscan cuando lea el archivo
    fscanf(archivo, " %c %c %c", &matriz[0][0], &matriz[0][1], &matriz[0][2]); 
    fscanf(archivo, " %c %c %c", &matriz[1][0], &matriz[1][1], &matriz[1][2]); 
    fscanf(archivo, " %c %c %c", &matriz[2][0], &matriz[2][1], &matriz[2][2]);

    // Cerramos el archivo
    fclose(archivo);

    // Contamos cuántas 'O' hay en la matriz
    contadorO = (matriz[0][0] == 'O') + (matriz[0][1] == 'O') + (matriz[0][2] == 'O') +
                (matriz[1][0] == 'O') + (matriz[1][1] == 'O') + (matriz[1][2] == 'O') +
                (matriz[2][0] == 'O') + (matriz[2][1] == 'O') + (matriz[2][2] == 'O');

    // Determinamos el valor de la cara del dado comparando los patrones
    int valor = 0;

    if (contadorO == 1 && matriz[1][1] == 'O') {
        valor = 1; //Si hay una sola O y está en la posición que nos interesa
    } 
    if (contadorO == 2 && ((matriz[0][0] == 'O' && matriz[2][2] == 'O') || (matriz[0][2] == 'O' && matriz[2][0] == 'O'))) {
        valor = 2; //Si hay dos O y están en la posición que nos interesa y así sucesivamente. Lo mismo que con el 4 y el 6 separamos con OR las opciones
    } 
    if (contadorO == 3 && ((matriz[0][0] == 'O' && matriz[1][1] == 'O' && matriz[2][2] == 'O') || 
                            (matriz[0][2] == 'O' && matriz[1][1] == 'O' && matriz[2][0] == 'O'))) {
        valor = 3; //Añadimos las dos opciones que tenemos para obtener un 4 y las separamos con un OR
    } 
    if (contadorO == 4 && matriz[0][0] == 'O' && matriz[0][2] == 'O' && matriz[2][0] == 'O' && matriz[2][2] == 'O') {
        valor = 4;
    } 
    if (contadorO == 5 && matriz[0][0] == 'O' && matriz[0][2] == 'O' && matriz[1][1] == 'O' && matriz[2][0] == 'O' && matriz[2][2] == 'O') {
        valor = 5;
    } 
    if (contadorO == 6 && ((matriz[0][0] == 'O' && matriz[0][2] == 'O' && matriz[1][0] == 'O' && matriz[1][2] == 'O' && matriz[2][0] == 'O' && matriz[2][2] == 'O') ||
                            (matriz[0][0] == 'O' && matriz[0][1] == 'O' && matriz[0][2] == 'O' && matriz[2][0] == 'O' && matriz[2][1] == 'O' && matriz[2][2] == 'O'))) {
        valor = 6; //Lo mismo que para el numero 4
    } 

    // Mostramos el resultado
    printf("OUTPUT\nVALUE: %d\n", valor);

    return 0;
}
