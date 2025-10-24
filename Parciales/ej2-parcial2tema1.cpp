/*Un comercio almacena informacion de productos nuevos para
la venta, por cada uno se conoce: codigo, tipo (1: bazar,
2: muebles, 3:manteleria), precio de venta y stock.
Se pide que usando funciones para cada item resuelva:*/
#include <stdio.h>
#include <stdlib.h>

typedef struct producto {
    int cod;
    int tipo;
    float precio_venta;
    int stock;
} producto;

struct nodo {
    producto datos;
    struct nodo *sig;
};

typedef struct nodo *puntero;

/*a)Generar una lista enlazada con punteros para almacenar
esta informacion.*/
void crear(puntero &c) {
    c = NULL;
    return;
}

void insertar(puntero &c) {
    puntero nuevo;
    int cod;

    printf("Ingrese codigo del producto (0 para finalizar):\n");
    scanf("%d", &cod);
    while (cod != 0) {
        nuevo = (puntero) malloc (sizeof(struct nodo));

        printf("Ingrese tipo de producto:\n");
        scanf("%d", &nuevo->datos.tipo);

        printf("Ingrese el precio de venta del producto:\n");
        scanf("%f", &nuevo->datos.precio_venta);

        printf("Ingrese el stock del producto:\n");
        scanf("%d", &nuevo->datos.stock);

        nuevo->sig = c;
        c = nuevo;

        printf("Ingrese codigo del producto (0 para finalizar):\n");
        scanf("%d", &cod);
    }
}

/*b)Mostrar en forma recursiva los codigos de producto de
tipo 3.*/
void mostrar(puntero c) {
    if (c != NULL) {
        if (c->datos.tipo == 3) {
            printf("Cod: %d", c->datos.cod);
        }
        mostrar(c->sig);
    }
}

/*c)Indicar en el programa principal cual es el mayor precio
registrado.*/
float mayor_precio(puntero c) {
    float max = -1;

    while (c != NULL) {
        if (c->datos.precio_venta > max) {
            max = c->datos.precio_venta;
        }

        c = c->sig;
    }

    return max;
}

/*d)Mostrar el codigo y stock de los productos con el mayor
precio.*/
void mostrar_mayores(puntero c, float m) {
    while (c != NULL) {
        if (c->datos.precio_venta == m) {
            printf("Codigo: %d, Stock: %d", c->datos.cod, c->datos.stock);
        }
        c = c->sig;
    }
}

int main() {
    puntero cabeza;
    float mayor;

    crear(cabeza);
    insertar(cabeza);

    printf("Codigos de productos de tipo 3:\n");
    mostrar(cabeza);

    mayor = mayor_precio(cabeza);
    printf("Mayor precio de venta registrdo: %.2f", mayor);

    printf("Codigo y Stock de los productos con el mayor precio:\n");
    mostrar_mayores(cabeza, mayor);
}