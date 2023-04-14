#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 50
int main()
{
    // todos los elementos del arreglo v
    // cada casilla es un puntero que apunta a un char.
    char *V[N];
    char nombre[N];
    int longitud, cantidad;
    printf("Ingrese la cantidad de nombres que desea: ");
    scanf("%d", &cantidad);
    for (int i = 0; i < cantidad; i++)
    {

        printf("Ingrese un nombre: ");
        scanf("%s", nombre);

        longitud = strlen(nombre);
        // reserva de memoria para el elemento v[i].
        V[i] = (char *)malloc(sizeof(char) * longitud);
        // copiar la cadena almacenada en nombre a V[i].
        strcpy(V[i], nombre);
    }

    // recorrer el arreglo
    printf("\n----Nombres-----\n");
    for (int i = 0; i < cantidad; i++)
    {
        printf("\n Nombre: ");
        puts(V[i]);
    }

    free(*V);
    return 0;
}
