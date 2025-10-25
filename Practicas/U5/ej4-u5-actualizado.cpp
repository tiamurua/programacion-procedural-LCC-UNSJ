/*Ejercicio 4
Una multinacional dedicada a la venta de automotores cuenta 
con la informacion de los 10 planes de financiacion de las 
distintas unidades. Se cuenta con la siguiente información 
de cada adjudicatario a un plan: Numero de plan, DNI, Nombre 
y Apellido, cantidad de cuotas pagadas. Se pide:*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int n_plan;
    int dni;
    char nom_ap[30];
    int c_cuotas;
} adjudicatario;

struct nodo
{
    adjudicatario dato;
    struct nodo *sig;
};

typedef struct nodo *puntero;

//a)Cargar en una estructura de datos adecuada la información que se posee.
void crear(puntero &c)
{
    c = NULL;
    return;
}

void insertar(puntero &c)
{
    puntero nuevo;
    int n_plan;

    printf("Ingrese numero de plan:\n");
    scanf("%d", &n_plan);

    if (n_plan)
    {
        nuevo = (puntero) malloc (sizeof(struct nodo));
        nuevo -> dato.n_plan = n_plan;
        printf("Ingrese DNI del adjudicatario:\n");
        scanf("%d", &nuevo -> dato.dni);
        printf("Ingrese Nombre y Apellido del adjudicatario:\n");
        gets(nuevo -> dato.nom_ap);
        printf("Ingrese cantidad de cuotas pagadas:\n");
        scanf("%d", &nuevo -> dato.c_cuotas);

        nuevo -> sig = c;
        c = nuevo;
        insertar(c);
    }
    return;
}

/*b)Generar una nueva estructura con información de los planes que cuenten con adjudicatarios aptos para licitar un vehículo, es decir, con más 
de 30 cuotas pagadas.*/
void insertar2(puntero c, puntero &c2)
{
    puntero nuevo;

    if (c != NULL)
    {
        if (nuevo -> dato.c_cuotas > 30)
        {
            nuevo = (puntero) malloc (sizeof(struct nodo));
            nuevo -> dato = c -> dato;
            nuevo -> sig = c2;
            c2 = nuevo;
        }
        insertar(c->sig, c2);
    }
    return;
}

int main()
{
    puntero cabeza, cabeza2;

    crear(cabeza);
    insertar(cabeza);
    
    crear(cabeza2);
    insertar2(cabeza, cabeza2);
}
