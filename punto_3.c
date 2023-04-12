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
    int longitud;
    for (int i = 0; i < 5; i++)
    {

        printf("Ingrese un nombre: ");
        scanf("%s", nombre);
        //ver la longitud del nombre para saber el tamaño que debemos reservarle al elemento i del arreglo.
        longitud = strlen(nombre);
        //reserva de memoria para el elemento v[i].
        V[i] = (char *)malloc(sizeof(char)*longitud);
        //copiar la cadena almacenada en nombre a V[i].
        strcpy(V[i],nombre);

    }

    //recorrer el arreglo
    printf("\n----Nombres-----\n");
    for (int i = 0; i < 5; i++)
    {
        printf("\n Nombre: ");
        puts(V[i]);
    }
    
  
    return 0;
}

//strlen devuelve la longitud de la cadena.No toma en cuenta el caracter de final de la cadena.