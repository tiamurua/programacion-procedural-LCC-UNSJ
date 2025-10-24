/*Desarrolla un programa en C que gestione un catalogo de
libros utilizando una lista enlazada. Cada nodo de la lista
representara un libro con los siguientes atributos: codigo
(entero mayor-igual a 1), titulo, categoria (1...5), precio y
cantidad disponible.
Hacer un programa que a traves de funciones optimas realice
las siguientes tareas.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int cod;
	char titulo[30];
	int categoria;
	float precio;
	int stock;
} libro;

struct nodo {
	libro datos;
	struct nodo *sig;
};

typedef struct nodo *puntero;

/*1.Generar una lista enlazada que almacene la informacion de
varios libros que se compraron. Dicha informacion se ingresa
por teclado.*/
void crear(puntero &c) {
	c = NULL;
	return;
}

void insertar(puntero &c, FILE *a) {
	puntero nuevo;
	libro l;
	int cod;
	
	printf("Ingrese codigo del libro (0 para finalizar):\n");
	scanf("%d", &cod);
	while (cod != 0) {
		fseek(a, (cod-100) * sizeof(l), SEEK_SET);
		fread(&l, sizeof(l), 1, a);
		
		nuevo = (puntero) malloc (sizeof(struct nodo));
		nuevo->datos = l;
		nuevo->sig = c;
		c = nuevo;
		
		printf("Ingrese codigo del libro (0 para finalizar):\n");
		scanf("%d", &cod);
	}
}

/*2.Implementa una funcion que permita buscar un libro por
su titulo y mostrar su informacion (codigo, titulo,
categoria, precio, cantidad disponible) en el main si se
encuentra en la lista. Si no se encuentra, mostrar un 
mensaje indicando que el libro no existe.*/
puntero busqueda(puntero c, char *titulo) {
	puntero aux;
	
	while ((c != NULL) && (strcmp(c->datos.titulo, titulo) == 1)) {
		aux = c;
		c = c->sig;
	}
	
	if (c == NULL) {
		printf("El numero no esta en la lista.\n");
	} else {
		return aux;	
	}
}

/*3.Calcula el valor total del inventario multiplicando los
productos de precio de cada libro por su cantidad
disponible. Muestra el resultado en el main. Hacer una
funcion recursiva.*/
float calculo_inventario(puntero c) {
	if (c != NULL) {
		return (c->datos.precio * c->datos.stock) + calculo_inventario(c->sig);
	} else {
		return 0;
	}
}

/*4.Crear una funcion que, a partir de la lista enlazada, 
genere un arreglo de enteros que contenga la cantidad de
libros disponibles por cada categoria. Mostrar el arreglo
cargado en otra funcion.*/
void carga_arreglo(puntero c, int a[5]) {
	int i;
	puntero aux;
	
	for (i = 0; i < 5; i++) {
		aux = c;
		
		while (aux != NULL) {
			a[aux->datos.categoria - 1] += aux->datos.stock;
			aux = c->sig;
		}
	}
	return;
}

void mostrar(int a[5]) {
	int i;
	
	for (i = 0; i < 5; i++) {
		printf("Cantidad de libros disponibles de la categoria %d: %d", i+1, a[i]);
	}
	return;
}

/*5.Se posee un archivo "catalogo.dat", donde cada registro
contiene codigo, titulo, categoria, precio, cantidad 
disponible; esta indexado por codigo a partir de 1. Con la
informacion de la lista actualizar la cantidad 
disponible.*/
void modi_stock(FILE *a, puntero c) {
	libro p;
	fpos_t x;
	
	rewind(a);
	fread(&p, sizeof(p), 1, a);
	while (!feof(a) && (c->datos.cod == p.cod)) {
		fread(&p, sizeof(p), 1, a);
	}
	
	if (!feof(a)) {
		p.cod = c->datos.cod;
		fseek(a, -sizeof(p), SEEK_CUR);
		fwrite(&p, sizeof(p), 1, a);
		fclose(a);
	}
}

int main() {
	FILE *archivo;
	puntero cabeza, aux;
	char titulo[30];
	float inventario;
	int arreglo[5];
	
	//1.
	archivo = fopen("Libros.dat", "w+");
	crear(cabeza);
	insertar(cabeza, archivo);
	
	//2.
	printf("Ingrese titulo del libro para la busqueda:\n");
	fflush(stdin);
	gets(titulo);
	aux = busqueda(cabeza, titulo);
	if (aux != 0) {
		printf("Libro encontrado en la lista:\n");
		printf("Codigo: %d\n", aux->datos.cod);
		printf("Titulo: %s\n", titulo);
		printf("Categoria: %d\n", aux->datos.categoria);
		printf("Precio: %.2f\n", aux->datos.precio);
		printf("Ejemplares disponibles: %d\n", aux->datos.stock);
	} else {
		printf("El libro no existe en la lista.\n");
	}
	
	//3.
	inventario = calculo_inventario(cabeza);
	printf("Valor total del inventario: %.2f", inventario);
	
	//4.
	carga_arreglo(cabeza, arreglo);
	mostrar(arreglo);
	
	//5.
	modi_stock(archivo, cabeza);
	
	fclose(archivo);
}
