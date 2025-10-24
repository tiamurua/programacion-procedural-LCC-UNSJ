/*Desarrolle un programa en C que gestione un inventario de
productos utilizando una lista enlazada. Cada nodo de la
lista representara un producto con los siguientes atributos:
codigo (entero mayor-igual a 100), nombre de producto, rubro
(1...6), precio y cantidad de stock.
Hacer un programa que a traves de funciones optimas realice 
las siguientes tareas:*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int cod;
    char nombre[50];
    int rubro;
    float precio;
    int stock;
} producto;

struct nodo {
    producto datos;
    struct nodo *sig;
};

typedef struct nodo *puntero;

/*Generar una lista enlazada que almacene la informacion de
varios productos cuya informacion se ingresa por teclado.*/
void crear(puntero &c) {
    c = NULL;
    return;
}

void insertar(puntero &c) {
    int cod;
    puntero nuevo;

    printf("Ingrese codigo del producto (0 para finalizar):\n");
    scanf("%d", &cod);
    while (cod != 0) {
        nuevo = (puntero) malloc (sizeof(struct nodo));

        nuevo->datos.cod = cod;

        printf("Ingrese nombre del producto:\n");
        fflush(stdin);
        gets(nuevo->datos.nombre);

        printf("Ingrese rubro del producto (1...6):\n");
        scanf("%d", &nuevo->datos.rubro);

        printf("Ingrese precio del producto:\n");
        scanf("%f", &nuevo->datos.precio);

        printf("Ingrese stock del producto:\n");
        scanf("%d", &nuevo->datos.stock);

        nuevo->sig = c;
        c = nuevo;

        printf("Ingrese codigo del producto (0 para finalizar):\n");
        scanf("%d", &cod);
    }
}

/*Implementa una funcion que permita buscar un producto por
su nombre, si se encuentra en la lista mostrar su
informacion en el main. Si no se encuentra, mostrar un
mensaje en el main indicando que el producto no existe.*/
int busca(puntero p, char *n, int &r, int &s, float &pr) {
    while ((p != NULL) && (strcmp(p->datos.nombre, n))) {
        p = p->sig;
    }

    if (p != NULL) {
        strcpy(n, p->datos.nombre);
        r = p->datos.rubro;
        s = p->datos.stock;
        pr = p->datos.precio;
        return p->datos.cod;
    } else {
        return 0;
    }
}

/*Calcula el valor total del inventario sumando el resultado
de multiplicar el precio de cada producto por su cantidad en 
stock. Hacer una funcion recursiva.*/
void calculo_total(puntero p) {
    if (p != NULL) {
        return (p->datos.precio * p->datos.stock) + calculo_total(p->sig);
    } else {
        return 0;
    }
}

/*Crear una funcion que a partir de la lista enlazada
almacene en un arreglo la cantidad de productos por rubro.
Mostrar el arreglo cargado en el main.*/

int main() {
    puntero cabeza;
    char nombre[50];
    int cod, rubro, stock, c_productos[6];
    float precio, i_total = 0;

    crear(cabeza);
    insertar(cabeza);

    printf("Ingrese nombre del producto:\n");
    fflush(stdin);
    gets(nombre);
    cod = busca(cabeza, nombre, rubro, stock, precio);
    if (cod == 0) {
        printf("No se encontro el producto en la lista.\n");
    } else {
        printf("Producto encontrado:\n");
        printf("Codigo: %d\n", cod);
        printf("Nombre: %s\n", nombre);
        printf("Rubro: %d\n", rubro);
        printf("Precio: %.2f\n", precio);
        printf("Stock: %d\n", stock);
    }

    calculo_total(cabeza, i_total);
    printf("Valor total del inventario: %.2f", i_total);

    carga_arreglo(cabeza, c_productos);
}