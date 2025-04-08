#include <stdio.h>

// Constantes para los días y límites
const int DAYS_OF_THE_WEEK = 7;
const float HEAVY_RAIN_THRESHOLD = 50.0;
const float TEMP_CHANGE_THRESHOLD = 10.0;

// Enumeración sencilla para días de la semana
enum tDays {MONDAY=1, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY};

int main() {
    // Variables básicas para almacenar datos
    float avgTemperatures[DAYS_OF_THE_WEEK];
    float avgRainFall[DAYS_OF_THE_WEEK];
    int heavyRainfallDays[DAYS_OF_THE_WEEK];
    int abruptChangeDays[DAYS_OF_THE_WEEK];

    int abruptChangeCount = 0;
    int heavyRainCount = 0;
    float sumTemperature = 0.0;
    float sumRain = 0.0;

    char filename[50];
    FILE *fileToRead;

    // Inicialización de arrays
    for (int i = 0; i < DAYS_OF_THE_WEEK; i++) {
        heavyRainfallDays[i] = 0;
        abruptChangeDays[i] = 0;
    }

    // Pedir el nombre del archivo
    printf("LOAD DATA FROM FILE. ENTER FILE NAME >>");
    scanf("%s", filename);
    printf("\n");
    fileToRead = fopen(filename, "r");

    // Verificación de apertura del archivo
    if (fileToRead == NULL) {
        printf("Error opening file '%s'. Please check the file name and location.\n", filename);
        return 1;
    }

    // Leer los datos del archivo
    for (int i = 0; i < DAYS_OF_THE_WEEK; i++) {
        if (fscanf(fileToRead, "%f %f", &avgTemperatures[i], &avgRainFall[i]) != 2) {
            printf("Error reading data from file.\n");
            fclose(fileToRead);
            return 1;
        }
    }

    fclose(fileToRead);

    // Hacer cálculos necesarios
    for (int i = 0; i < DAYS_OF_THE_WEEK; i++) {
        sumTemperature += avgTemperatures[i];
        sumRain += avgRainFall[i];

        if (i > 0) {
            float tempChange = avgTemperatures[i] - avgTemperatures[i - 1];
            if (tempChange >= TEMP_CHANGE_THRESHOLD || tempChange <= -TEMP_CHANGE_THRESHOLD) {
                abruptChangeDays[i] = 1;
                abruptChangeCount++;
            }
        }

        if (avgRainFall[i] >= HEAVY_RAIN_THRESHOLD) {
            heavyRainfallDays[i] = 1;
            heavyRainCount++;
        }
    }

    // Sacar promedios
    sumTemperature /= DAYS_OF_THE_WEEK;
    sumRain /= DAYS_OF_THE_WEEK;

    // Mostrar resultados al usuario
    printf("ESTIMATED WEEKLY AVERAGE TEMPERATURE (CELSIUS): %.2f\n", sumTemperature);
    printf("ESTIMATED WEEKLY AVERAGE RAINFALL (MILLIMETERS): %.2f\n", sumRain);

    if (abruptChangeCount > 0 || heavyRainCount > 0) {
        printf("WEATHER ALERTS (1-MONDAY, 2-TUESDAY, 3-WEDNESDAY, 4-THURSDAY, 5-FRIDAY, 6-SATURDAY, 7-SUNDAY):\n");

        if (abruptChangeCount > 0) {
            printf("DAYS WITH ESTIMATED ABRUPT TEMPERATURE CHANGES:\n");
            for (int i = 0; i < DAYS_OF_THE_WEEK; i++) {
                if (abruptChangeDays[i] == 1) {
                    printf("%d\n", i + 1);
                }
            }
        }

        if (heavyRainCount > 0) {
            printf("ESTIMATED HEAVY RAINFALL DAYS:\n");
            for (int i = 0; i < DAYS_OF_THE_WEEK; i++) {
                if (heavyRainfallDays[i] == 1) {
                    printf("%d\n", i + 1);
                }
            }
        }
    } else {
        printf("NO WEATHER ALERTS\n");
    }

    return 0;
}
