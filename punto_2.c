#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define F 5
#define C 12

void cargarMatriz(int matriz[F][C]);
void mostrarMatriz(int matriz[F][C]);
void promedioGananciaPorAnio(int matriz[F][C]);
void valorMaximoValorMinimo(int matriz[F][C]);
int main()
{
    int j, i;
    srand(time(NULL));

    int matriz[F][C];
    cargarMatriz(matriz);
    mostrarMatriz(matriz);
    // promedioGananciaPorAnio(matriz);
    valorMaximoValorMinimo(matriz);
    return 0;
}

// hay que indicarle filas y columnas
void cargarMatriz(int matriz[F][C])
{
    for (int i = 0; i < F; i++)
    {
        for (int j = 0; j < C; j++)
        {
            matriz[i][j] = 10000 + rand() % 40001;
        }
    }
}
void mostrarMatriz(int matriz[F][C])
{
    for (int i = 0; i < F; i++)
    {
        for (int j = 0; j < C; j++)
        {
            printf("%10d", matriz[i][j]);
        }
        printf("\n");
    }
}

void promedioGananciaPorAnio(int matriz[F][C])
{
    float ganancia = 0;
    float promedio;
    for (int i = 0; i < F; i++)
    {

        for (int j = 0; j < C; j++)
        {
            ganancia = matriz[i][j] + ganancia;
        }
        promedio = (ganancia / 12);
        printf("\n\n La ganancia del anio %d es: $ %2.f", i + 1, ganancia);
        printf("\n\n El promedio de ganancias de el ano %d es de: $%.2f ", i + 1, promedio);
        ganancia = 0;
    }
}

void valorMaximoValorMinimo(int matriz[F][C])
{
    float vMax = 0, vMin = 50000;
    int anioMax, mesMax, anioMin, mesMin;
    for (int i = 0; i < F; i++)
    {

        for (int j = 0; j < C; j++)
        {
            if (matriz[i][j] > vMax)
            {
                vMax = matriz[i][j];
                anioMax = i + 1;
                mesMax = j + 1;
            }
            if (matriz[i][j] < vMin)
            {
                vMin = matriz[i][j];
                anioMin = i + 1;
                mesMin = j + 1;
            }
        }
    }
    printf("\nEl maximo valor obtenido es: $%2.f \n Mes: %d \n Anio:%d \n", vMax, mesMax, anioMax);
    printf("\nEl minimo valor obtenido es: $%2.f \n Mes: %d \n Anio:%d \n", vMin, mesMin, anioMin);
}