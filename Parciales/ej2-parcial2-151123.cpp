/*Una agencia de autos tiene un archivo AUTOS.dat con la
informacion de 50 planes de ahorro suscriptos por sus
clientes. De cada plan de ahorro se tiene registrado: Codigo
de cliente (a partir de 1000), DNI, Tipo de plan (1...5) y
Cantidad de cuotas a pagar. El archivo esta ordenado por
codigo de cliente y permite su acceso directo.
Hacer un programa en lenguaje C que usando funciones optimas
permita:*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int cod;
    int dni;
    int tipo;
    int c_cuotas;
} plan;

typedef struct {
    int cod_cliente;
    int cuotas_pagadas;
} pago;

struct nodo {
    pago datos;
    struct nodo *sig;
};

typedef struct nodo *puntero;

/*Generar una lista implementada con punteros, que almacene
los pagos realizados en los ultimos meses. De cada pago se 
registra Codigo de cliente y cantidad de cuotas pagadas.
Hacerlo con una funcion recursiva.*/
void crear(puntero &c) {
    c = NULL;
    return;
}

void insertar(puntero &c) {
    puntero nuevo;
    int cod;
    if (c != NULL) {
        puntero nuevo = (puntero) malloc (sizeof(struct nodo));

        printf("Ingrese codigo de cliente (0 para finalizar):\n");
        scanf("%d", &nuevo->datos.cod_cliente);

        printf("Ingrese cantidad de cuotas pagadas:\n");
        scanf("%d", &nuevo->datos.cuotas_pagadas);

        nuevo->sig = c;
        c = nuevo;

        insertar(c->sig);
    }
}

/*Con la informacion contenida en la lista, actualizar en el
archivo, para cada cliente la cantidad de cuotas a pagar.*/
void actualizar(FILE *a, puntero c) {
    plan p;
    int cont = 1;

    while (c != NULL) {
        if (c->sig != NULL && c->datos.cod_cliente == c->sig->datos.cod_cliente) {
            cont++;
        } else {
            rewind(a);
            fread(&p, sizeof(plan), 1, a);
            while (feof(a)) {
                if (p.cod == c->datos.cod_cliente) {
                    
                }
            }
        }
    }
}
int main() {
    puntero cabeza;
    FILE *archi;

    crear(cabeza);
    insertar(cabeza);
    
    if ((archi = fopen("AUTOS.dat", "w+")) == 0) {
        printf("Hay error!\n");
    } else {
        actualizar(archi, cabeza);
    }
}