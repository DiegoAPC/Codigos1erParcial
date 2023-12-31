#include <stdio.h>

int main () {
    int cont, cant, nota, suma = 0, opcion;
    float prom;
    char nombre[50];
    char materia[50];
    do {
        FILE *archivo = fopen("salida.txt", "r");

        
        if (archivo == NULL) {
            printf("No se pudo abrir el archivo para leer.\n");
            return 1; 
        }

        
        printf("\n------------------\n");
        printf("Menu:\n");
        printf("1. Registrar nuevo estudiante y sus notas\n");
        printf("2. Ver el historial de las notas\n");
        printf("3. Borrar historial de las notas\n");
        printf("4. Salida\n");
        printf("Elije una opcion: ");
        scanf("%d", &opcion); 

        switch (opcion) {
            case 1:
                printf("\nIntroduzca el nombre del alumno\n");
                scanf("%s", &nombre);
                
                printf("\nIntroduzca la cantidad de materias\n");
                scanf("%d", &cant);

                for(cont=0;cont<cant;cont++)
                {
                    printf("\nIntroduzca el nombre de la materia\n");
                    scanf("%s", &materia);
                    printf("\nIntroduzca nota de la materia\n");
                    scanf("%d", &nota);
                    suma = suma + nota;

                    FILE *archivo = fopen("salida.txt", "a");
                    if (archivo == NULL) {
                    printf("No se pudo abrir el archivo para escribir.\n");
                    return 1; 
                    }
                    fprintf(archivo,"Nombre del alumno: %s\n", nombre);
                    fprintf(archivo,"Nombre de la materia: %s\n", materia);
                    fprintf(archivo,"Nota correspondiente: %d\n", nota);
                    fprintf(archivo,"---------------------\n");
                    fclose(archivo); 
                }
                    FILE *archivo = fopen("salida.txt", "a");
                    if (archivo == NULL) {
                    printf("No se pudo abrir el archivo para escribir.\n");
                    return 1; 
                    }
                    prom = suma / cant;
                    fprintf(archivo,"El promedio de las notas es: %.2f\n", prom);
                    fprintf(archivo,"\n---------------------\n");
                    fclose(archivo); 
                    printf("\nNotas registradas en archivo de texto");
                break;

            case 2:
                printf("Historial de notas:\n");
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
    } while (opcion != 4); 

    return 0;

}