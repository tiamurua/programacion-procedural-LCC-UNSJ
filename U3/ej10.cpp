/*Ejercicio 10
Una fábrica de ropa comercializa 50 prendas que son vendidas a 35 comercios del país. Por cada venta realizada se cuenta con los siguientes 
datos: Código de comercio (60..94), Nombre de la prenda vendida y cantidad de unidades. Las ventas no traen ningún orden en particular.

En una estructura se registra por cada prenda que se comercializa su nombre y precio unitario, ordenado alfabéticamente.
Además, por cada comercio se almacena su CUIL y Nombre.

Se pide realizar un programa en C, que utilizando funciones óptimas y estructuras adecuadas permita (utilizar Menú de opciones):*/

#include <stdio.h>
#include <string.h>

#define F 35
#define C 50

typedef struct {
    char nombre[30];
    float pUnitario;
    int uVendidas;
} prenda;

typedef struct {
    int cuil;
    char nombre[30];
} comercio;

void inicializar_estructuras(prenda p[C], comercio c[F])
{
    int i, j;
    for (i = 0; i < F; i++) {
        printf("Ingrese CUIL del comercio: ");
        scanf("%d", &c[i].cuil);
        printf("Ingrese nombre del comercio: ");
        scanf("%[^\n]s", c[i].nombre);// Para leer cadenas con espacios

        for (j = 0; j < C; j++) {
            {
                printf("Ingrese nombre de la prenda: ");
                scanf("%[^\n]s", p[j].nombre);
                printf("Ingrese precio unitario: ");
                scanf("%f", &p[j].pUnitario);

                p[j].uVendidas = 0;
            }
        }
    }
    return;
}

void cereo(int t[F][C])
{
    int i, j;
    for (i = 0; i < F; i++)
    {
        for (j = 0; j < C; j++)
        {
            t[i][j] = 0;
        }
    }
    return;
}

void ordenar_prendas(prenda p[C])
{
    int i, j, min, aux;
    for (i = 0; i < C-2; i++)
    {
        min = i;
        for (j = i+1; j < C-1; j++)
        {
            if (strcmp(p[j].nombre, p[min].nombre) > 0)
            {
                min = j;
            }
        }
        aux = p[i];
        p[i] = p[min];
        p[min] = aux;
    }
    return;
}

/*1. Almacenar los datos de las ventas en una estructura que 
posea por cada comercio la cantidad de unidades vendidas de 
cada prenda.*/
int busqueda_indice(prenda p[C], char nombre[30])
{
    int inf = 0, sup = C-1, medio;
    while (inf <= sup)
    {
        medio = (inf + sup) / 2;
        int cmp = strcmp(nombre, p[medio].nombre);
        if (cmp == 0) 
        {
            return medio;
        } 
        else if (cmp < 0)
        {
            sup = medio - 1;
        }
        else 
        {
            inf = medio + 1;
        }
    }
    return -1;
}

void cargar_ventas(int t[F][C], prenda p[C])
{
    int codigo, indice, unidades;
    char nombre[30];
    printf("Ingrese Codigo de Comercio (0 para finalizar): \n");
    scanf("%d", &codigo);
    while (codigo != 0) {
        printf("Nombre de la prenda vendida: \n");
        scanf(" %[^\n]s", nombre);
        indice = busqueda_indice(p, nombre);
        if (indice != -1) {
            printf("Ingrese cantidad de unidades vendidas: \n");
            scanf("%d", &unidades);
            t[codigo - 60][indice] += unidades;
        }
        else
        {
            printf("Prenda no encontrada.\n");
        }
        printf("Ingrese Codigo de Comercio (0 para finalizar): \n");
        scanf("%d", &codigo);
    }
}

/*2. Indicar por cada comercio; CUIL, Nombre e importe total 
a pagar.*/
void datos(int t[F][C], comercio c[F], prenda p[C])
{
    int i, j; 
    float tUnidades;
    for (i = 0; i < F; i++)
    {
        tUnidades = 0;
        printf("Comercio %d\n", i + 1);
        printf("CUIL: %d\n", c[i].cuil);
        printf("Nombre: %s\n", c[i].nombre);
        for (j = 0; j < C; j++)
        {
            tUnidades += (t[i][j] * p[j].pUnitario);
        }
        printf("Importe total a pagar: $%.2f\n", tUnidades);
    }
}

/*3. Realizar un listado que contenga por cada producto, 
nombre y cantidad de unidades vendidas, este listado debe 
estar ordenado descendentemente por cantidad de unidades.*/
void calculo_totales(prenda p[C], int t[F][C])
{
    int i, j, acum;
    for (i = 0; i < C; i++)
    {
        acum = 0;
        for (j = 0; j < F; j++)
        {
            acum += t[j][i];
        }
        p[i].uVendidas = acum;
    }
    return;
}

void ordenamiento_descendente(prenda p[C])
{
    int k, i, cota;
    prenda aux;
    cota = C-1;
    k = 1;
    while (k != -1)
    {
        k = -1
        for (i = 0; i < cota-1; i++)
        {
            if (p[i].uVendidas > p[i+1].uVendidas)
            {
                aux = p[i];
                p[i] = p[i+1];
                p[i+1] = aux;
                k = i;
            }
        }
        cota = k;
    }
    return;
}

void listar(prenda p[C])
{
    int i;
    printf("Lista de productos: \n");
    for (i = 0; i < C; i++)
    {
        printf("Producto %d:\n", i+1);
        printf("Nombre: %s\n", p[i].nombre);
        printf("Cantidad de unidades vendidas: %d\n", p[i].uVendidas);
    }
    return;
}

/*4. Mostrar el nombre de los 5 productos que más se 
vendieron.*/
void mas_vendidos(prenda p[C])
{
    int i;
    printf("Nombre de los 5 productos mas vendidos: \n");
    for (i = 0; i < 5; i++)
    {
        printf("Nombre del producto: %s\n", p[i].nombre);
    }
    return;
}
int main() 
{
    prenda P[C];
    comercio Co[F];
    int T[F][C], opcion;
    inicializar_estructuras(P, Co);
    cereo(T)
    ordenar_prendas(P);

    printf("\nMenu\n");
    printf("1. Almacenar datos de las ventas.\n");
    printf("2. CUIL, Nombre e Importe total a pagar por comercio.\n");
    printf("3. Lista ordenada descendentemente por cantidad de unidades de prendas.\n");
    printf("4. Mostrar los 5 productos mas vendidos.\n");
    printf("5. Salir.\n");
    printf("Seleccione una opcion:\n");
    scanf("%d", &opcion);

    switch (opcion)
    {
        case 1:
            cargar_ventas(T, P);
            break;
        case 2:
            datos(T, Co, P);
            break;
        case 3:
            calculo_totales(P, T);
            ordenamiento_descendente(P);
            listar(P);
            break;
        case 4:
            mas_vendidos(P);
            break;
    }

}