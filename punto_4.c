#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
char *TiposProductos[] = {"Galletas", "Snack", "Cigarrillos", "Caramelos", "Bebidas"};

struct Producto
{
    int ProductoID;       // Numerado en ciclo iterativo
    int Cantidad;         // entre 1 y 10
    char *TipoProducto;   // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
} typedef Productos;

struct Cliente
{
    int ClienteID;               // Numerado en el ciclo iterativo
    char *NombreCliente;         // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    Productos *Productos;        // El tamaño de este arreglo depende de la variable
};
void mostrarProductos(int cantidadProductos, Productos *produ);
void cargarProductos(int cantidadProductos, Productos *Productos);
void cargarClientes(struct Cliente *punt, int cantClientes);
void mostrarClientes(struct Cliente *punt, int cantClientes);
float costoTotal(Productos *Product);
int main()
{

    int cantClientes;
    struct Cliente *punt; // puntero de tipo struct cliente

    // cantidad de clientes
    printf("Ingrese la cantidad de clientes: ");
    scanf("%d", &cantClientes);
    fflush(stdin);

    // reservar la memoria para mis clientes.
    punt = (struct Cliente *)malloc(sizeof(struct Cliente) * cantClientes);
    // necesitar una funcion para cargar los clientes.
    cargarClientes(punt, cantClientes);
    mostrarClientes(punt, cantClientes);

    return 0;
}



void cargarProductos(int cantidadProductos, Productos *Productos)
{
    srand(time(NULL));
    for (int i = 0; i < cantidadProductos; i++)
    {
        (*(Productos + i)).ProductoID = i;
        (*(Productos + i)).Cantidad = 1 + rand() % 10;
        (*(Productos + i)).TipoProducto = *(TiposProductos + (rand() % 5));
        (*(Productos + i)).PrecioUnitario = 10 + rand() % 91;
    }
}

void cargarClientes(struct Cliente *punt, int cantClientes)
{
    srand(time(NULL));
    char nombre[50];

    for (int i = 0; i < cantClientes; i++)
    {
        (*(punt + i)).ClienteID = i;

        printf("ingrese el nombre del cliente: ");
        scanf("%s", nombre);

        // hago una reserva de memoria, y copio el nombre en la cadena.
        (*(punt + i)).NombreCliente = malloc(sizeof(char) * strlen(nombre) + 1);

        strcpy((*(punt + i)).NombreCliente, nombre);

        (*(punt + i)).CantidadProductosAPedir = 1 + rand() % 5;

        int cantidadProductos = (*(punt + i)).CantidadProductosAPedir;

        // una vez definida la cantidad de productos que necesito
        // debo reservar la memoria para mis estructuras de productos
        // puntProducto = (Productos *)malloc(sizeof(Productos) * cantidadProductos);
        (*(punt + i)).Productos = malloc(sizeof(Productos) * cantidadProductos);

        cargarProductos(cantidadProductos, (*(punt + i)).Productos);
    }
}

void mostrarProductos(int cantidadProductos, Productos *produ)
{
    for (int i = 0; i < cantidadProductos; i++)
    {
        printf("\n----- Productos %d -----\n", i);
        printf("Id: %d \n", (*(produ + i)).ProductoID);
        printf("Cantidad: %d \n", (*(produ + i)).Cantidad);
        printf("Tipo Producto: %s \n", (*(produ + i)).TipoProducto);
        printf("Precio unitario: %2.f \n", (*(produ + i)).PrecioUnitario);
    }
}

void mostrarClientes(struct Cliente *punt, int cantClientes)
{
    float costoPorCliente = 0;
    for (int i = 0; i < cantClientes; i++)
    {
        
        printf("\n---------CLIENTE %d-----------\n", i + 1);
        printf("Id: %d \n", (*(punt + i)).ClienteID);
        printf("Nombre: %s \n", (*(punt + i)).NombreCliente);
        printf("Cantidad de Productos pedidos: %d \n", (*(punt + i)).CantidadProductosAPedir);
        int cantidad = (*(punt + i)).CantidadProductosAPedir;
        printf("\n-----------PEDIDOS CLIENTE [%d]------------\n", i + 1);
        mostrarProductos(cantidad, (*(punt + i)).Productos);

        for (int j = 0; j < cantidad; j++)
        {
            costoPorCliente = costoTotal((*(punt + i)).Productos+j) + costoPorCliente;
        }
        printf("\n\nEl total a pagar del Cliente [%d] es: $ %2.f",i+1,costoPorCliente);
        costoPorCliente = 0;
        printf("\n\n");
    }

    free(punt);
}



float costoTotal(Productos *Productos){
   float  costoPorCliente = ((*(Productos)).PrecioUnitario) * ((*(Productos)).Cantidad);
  printf("\n\n.....Entro a la funcion costo total y devolvera: %2.f",costoPorCliente);

     return (((*(Productos)).PrecioUnitario) * ((*(Productos)).Cantidad));
}