/*Ejercicio 3
El Instituto Provincial de la Vivienda ha implementado un sistema que consta de 5 planes de pago distintos, con el fin de que los 
adjudicatarios de sus viviendas puedan cancelar sus deudas. Se ingresa la cantidad de adjudicatarios y por cada uno de ellos el DNI, 
código de plan al que adhiere (1..5) y monto adeudado.
Se pide:*/
#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int dni;
    int cod;
    float monto;
} adjudicatario;

//a)Cargar en una estructura de datos adecuada la información que se posee.
void carga(adjudicatario a[], int ca, int i)
{
    if (i < ca)
    {
        printf("Ingrese DNI del adjudicatario:\n");
        scanf("%d", &a[i].dni);
        printf("Ingrese codigo de plan al que adhiere:\n");
        scanf("%d", &a[i].cod);
        printf("Ingrese monto adeudado:\n");
        scanf("%f", &a[i].monto);

        carga(a, ca, i + 1);
    }
}

//b)Para un adjudicatario cuyo DNI se ingresa por teclado, indicar el número de plan al cual se adhirió y el monto adeudado.
void busqueda(adjudicatario a[], int ca, int xdni, int i)
{
    if (i < ca)
    {
        if (a[i].dni == xdni)
        {
            printf("Numero de plan al que se adhirio: %d\n", a[i].cod);
            printf("Monto adeudado: %.2f", a[i].monto);
            return;
        }
        busqueda(a, ca, xdni, i + 1);
    }
    else
    {
        printf("El DNI no se encuentra registrado.\n");
    }
}

//c)Indicar para cada plan cuantos adjudicatarios adhirieron.
void adjudicatario_por_plan(adjudicatario a[], int ca)
{
    int i, cont, plan;

    for (plan = 1; plan <= 5; plan++)
    {
        cont = 0;

        for (i = 0; i < ca; i++)
        {
            if (a[i].cod == plan)
            {
                cont++;
            }
        }

        printf("Cantidad de adjudicatarios adheridos al plan %d: %d", plan, cont);
    }
    return;    
}

int main()
{
    adjudicatario *A;
    int can_adj, dni;

    printf("Ingrese cantidad de adjudicatarios:\n");
    scanf("%d", &can_adj);

    A = (adjudicatario*) malloc (can_adj * sizeof(adjudicatario));

    carga(A, can_adj, 0);

    printf("Ingrese DNI de un adjudicatario:\n");
    scanf("%d", &dni);

    busqueda(A, can_adj, dni, 0);

    adjudicatario_por_plan(A, can_adj);

    free(A);
}
