#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {
    int num, num2,num3, op;

    do {
        FILE *archivo = fopen("salida.txt", "r");

        
        if (archivo == NULL) {
            printf("No se pudo abrir el archivo para leer.\n");
            return 1; 
        }

        
        printf("\n------------------\n");
        printf("\nMenu:\n");
        printf("1. Jugar el gran 8\n");
        printf("2. Ver historial\n");
        printf("3. Borrar historial\n");
        printf("4. Salida\n");
        printf("Elije una opcion: ");
        scanf("%d", &op); 

        switch (op) {
            case 1:
                printf("\n*****El gran 8*****\n");
                srand(time(NULL));
                num = rand () % (8-1+1)+1;
                num2 = rand() % (8-1+1)+1;

                num3 = num + num2;
                if(num3 == 8) {
                FILE *archivo = fopen("salida.txt", "a"); 
                if (archivo == NULL) {
                    printf("No se pudo abrir el archivo para escribir.\n");
                    return 1; 
                }
                fprintf(archivo,"\nDado 1: %d\n", num);
                fprintf(archivo,"\nDado 2: %d\n", num2);
                fprintf(archivo,"\nFelicidades, GANASTE\n");
                fclose(archivo);
                printf("\nDado 1: %d\n", num);
                printf("\nDado 2: %d\n", num2);
                printf("\nFelicidades, GANASTE\n");
                fprintf(archivo,"\n------------------\n");
                }
                else if (num3 == 7){
                FILE *archivo = fopen("salida.txt", "a"); 
                if (archivo == NULL) {
                    printf("No se pudo abrir el archivo para escribir.\n");
                    return 1; 
                    }
                fprintf(archivo,"\nDado 1: %d\n", num);
                fprintf(archivo,"\nDado 2: %d\n", num2);
                fprintf(archivo,"\nLo siento, PERDISTE\n");
                fclose(archivo);
                printf("\nDado 1: %d\n", num);
                printf("\nDado 2: %d\n", num2);
                printf("\nLo siento, PERDISTE\n");
                fprintf(archivo,"\n------------------\n");
                }
                else{

                FILE *archivo = fopen("salida.txt", "a");
                if (archivo == NULL) {
                    printf("No se pudo abrir el archivo para escribir.\n");
                    return 1; 
                }
                fprintf(archivo,"\nDado 1: %d\n", num);
                fprintf(archivo,"\nDado 2: %d\n", num2);
                fprintf(archivo,"\nVuelves a tirar\n");
                fprintf(archivo,"\n------------------\n");
                fclose(archivo);
                printf("\nDado 1: %d\n", num);
                printf("\nDado 2: %d\n", num2);
                printf("Vuelves a tirar");
                }
                break;

            case 2:
                printf("Historial de jugadas:\n");
                char linea[100]; 
                while (fgets(linea, sizeof(linea), archivo) != NULL) {
                    printf("%s", linea); 
                }
                fclose(archivo); 

                break;

            case 3:
                archivo = fopen("salida.txt", "w");
                if (archivo == NULL) {
                    printf("No se pudo abrir el archivo para escribir.\n");
                    return 1; 
                }
                fclose(archivo); 
                printf("Historial borrado.\n");
                break;

            case 4:
                printf("Saliendo del programa.\n");
                break;

            default:
                printf("Opcion invalida. Por favor, elija una opcion valida.\n");
                break;
        }
    } while (op != 4); 

    return 0;

}


