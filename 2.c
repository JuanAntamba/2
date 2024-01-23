#include <stdio.h>
#include <stdlib.h>

// Estructura para representar un registro de datos
struct Registro {
    char nombre[50];
    int edad;
    char direccion[100];
    long long telefono;
    char email[50];
    // Agrega más campos según tus necesidades
};

int main() {
    FILE *archivo;
    int opcion;

    do {
        // Menú de opciones
        printf("\n1. Agregar registro\n");
        printf("2. Mostrar registros\n");
        printf("0. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: {
                struct Registro nuevoRegistro;

                printf("Ingrese el nombre: ");
                scanf("%s", nuevoRegistro.nombre);

                printf("Ingrese la edad: ");
                scanf("%d", &nuevoRegistro.edad);

                printf("Ingrese la dirección: ");
                scanf("%s", nuevoRegistro.direccion);

                printf("Ingrese el teléfono: ");
                scanf("%lld", &nuevoRegistro.telefono);

                printf("Ingrese el email: ");
                scanf("%s", nuevoRegistro.email);

                // Abre el archivo en modo de escritura (agregar al final) o crea uno nuevo
                archivo = fopen("datos.txt", "a");

                if (archivo == NULL) {
                    printf("Error al abrir el archivo o no se pudo crear.\n");
                    exit(1);
                }

                // Escribe el registro en el archivo
                fprintf(archivo, "%s %d %s %lld %s\n", nuevoRegistro.nombre, nuevoRegistro.edad, nuevoRegistro.direccion, nuevoRegistro.telefono, nuevoRegistro.email);

                // Cierra el archivo
                fclose(archivo);

                printf("Registro agregado con éxito.\n");
                break;
            }

            case 2: {
                char nombre[50];
                int edad;
                char direccion[100];
                long long telefono;
                char email[50];

                // Abre el archivo en modo de lectura
                archivo = fopen("datos.txt", "r");

                if (archivo == NULL) {
                    printf("El archivo no existe o no se puede abrir.\n");
                    exit(1);
                }

                // Lee y muestra cada registro del archivo
                while (fscanf(archivo, "%s %d %s %lld %s", nombre, &edad, direccion, &telefono, email) != EOF) {
                    printf("Nombre: %s, Edad: %d, Dirección: %s, Teléfono: %lld, Email: %s\n", nombre, edad, direccion, telefono, email);
                }

                // Cierra el archivo
                fclose(archivo);
                break;
            }

            case 0:
                printf("Saliendo del programa.\n");
                break;

            default:
                printf("Opción no válida. Intente de nuevo.\n");
        }

    } while (opcion != 0);

    return 0;
}
