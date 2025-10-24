/*Desarrolle un programa en C que gestione un catalogo de
productos utilizando un archivo "Productos.dat" para generar
una lista enlazada. Cada registro del archivo contiene los 
siguientes atributos: codigo de producto (entero mayor-igual 
a 100), nombre de producto, categoria (1...5), precio y stock
disponible.
Hacer un programa que a traves de funciones optimas realice 
las siguientes tareas:*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	int cod;
	char nombre[30];
	int categoria;
	int precio;
	int stock;
} producto;

struct nodo {
	producto datos;
	struct nodo *sig;
};

typedef struct nodo *puntero;

/*1.Ingresar codigos de productos por teclado y a partir de 
la informacion del archivo "Productos.dat" generar una lista
enlazada con la informacion de los productos del codigo
ingresado*/
void insertar(puntero &c, FILE *a) {
	int cod;
	puntero nuevo;
	producto p;
	
	printf("Ingrese codigo de producto (0 para finalizar):\n");
	scanf("%d", &cod);
	while (cod != 0) {
		fseek(a, (cod - 100) * sizeof(p), SEEK_SET);
		fread(&p, sizeof(p), 1, a);
		nuevo = (puntero) malloc (sizeof(struct nodo));
		nuevo->datos = p;
		nuevo->sig = c;
		c = nuevo;
		
		printf("Ingrese codigo de producto (0 para finalizar):\n");
		scanf("%d", &cod);
	}
	return;
}

/*2.Implementa una funcion que, a partir de la lista
enlazada, realice un listado ordenado alfabeticamente por 
nombre de producto. Indicar en la funcion main la cantidad
total en stock*/
void ordenar(puntero c) {
	puntero k, cota, p;
	producto aux;
	
	cota = NULL;
	k = NULL;
	while (k != c) {
		k = c;
		p = c;
		while (p->sig != cota) {
			if (strcmp(p->datos.nombre, p->sig->datos.nombre) > 1) {
				aux = p->sig->datos;
				p->sig->datos = p->datos;
				p->datos = aux;
				k = p;
			}
			p = p->sig;
		}
		cota = k->sig;
	}
}

void calculo_stock(puntero c, int &t) {
	while (c != NULL) {
		t++;
		
		c = c->sig;
	}
	return;
}

/*Crea una funcion que, a partir de la listaa enlazada,
genere un arreglo que contenga la cantidad de productos
disponibles por cada categoria. Mostrar el arreglo generado
en el main.*/
void cereo(int a[5]) {
	int i;
	
	for (i = 0; i < 5; i++) {
		a[i] = 0;
	}
	return;
}

void carga_arreglo(puntero c, int a[5]) {
	int i;
	puntero aux;
	
	for (i = 0; i < 5; i++) {
		aux = c;
		
		while (aux != NULL) {
			a[aux->datos.categoria - 1] += aux->datos.stock;
			
			aux = aux->sig;
		}
	}
	return;
}

/*4.Calcula el valor total del inventario, considerando el 
precio y el stock disponible de cada producto. Muestra el
resultado en el main. Implementa esta funcion de forma
recursiva.*/
int calculo_inventario(puntero c) {
	if (c != NULL) {
		return (c->datos.precio * c->datos.stock) + calculo_inventario(c->sig);
	} else {
		return 0;
	}
}

/*5.Crea una funcion que, a partir de la informacion del
archivo "Productos.dat", indique cuantos productos tiene
cargados*/
void recorrer_archivo(FILE *a) {
	producto p;
	int cont = 0;
	
	rewind(a);
	while (fread(&p, sizeof(p), 1, a)) {
		cont++;
	}
	
	printf("Cantidad de productos cargados: %d", cont);
	return;
}

int main() {
	FILE *archivo;
	puntero cabeza;
	int total = 0, arreglo[5], i, inventario;
	
	//1.
	archivo = fopen("Productos.dat", "w+");
	cabeza = NULL;
	insertar(cabeza, archivo);
	
	//2.
	ordenar(cabeza);
	calculo_stock(cabeza, total);
	
	//3.
	carga_arreglo(cabeza, arreglo);
	for (i = 0; i < 5; i++) {
		printf("Cantidad de productos disponibles de categoria %d: %d", i+1, arreglo[i]);
	}
	
	//4.
	inventario = calculo_inventario(cabeza);
	printf("Valor total del inventario: %d", inventario);
	
	//5.
	recorrer_archivo(archivo);
}
