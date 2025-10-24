/*Desarrolla un programa en C que gestione un catalogo de
peliculas que se han presentado en un cine que utilizando el
archivo "pelicula.dat" genere una lista enlazada. Cada
componente del archivo tiene los siguientes atributos: codigo
de pelicula (a partir de 100), titulo, genero (1...6) y
cantidad de entradas vendidas.
Hacer un programa que a traves de funciones optimas realice las
siguientes tareas:*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	int cod;
	char titulo[30];
	int genero;
	int entradas_vendidas;
} pelicula;

struct nodo {
	pelicula datos;
	struct nodo *sig;
};

typedef struct nodo *puntero;

/*1. Ingresar codigos de peliculas por teclado a partir del
archivo "pelicula.dat" generar una lista enlazada con la
informacion de las peliculas del codigo ingresado.*/
void crear(puntero &c) {
	c = NULL;
	return;
}

void insertar(puntero &c, FILE *a) {
	int cod;
	puntero nuevo;
	pelicula p;
	
	printf("Ingrese codigo de pelicula (0 para finalizar):\n");
	scanf("%d", &cod);
	while (cod != 0) {
		fseek(a, (cod - 100) * sizeof(p), SEEK_SET);
		fread(&p, sizeof(p), 1, a);
		nuevo = (puntero) malloc (sizeof(struct nodo));
		nuevo->datos = p;
		nuevo->sig = c;
		c = nuevo;
		
		printf("Ingrese codigo de pelicula (0 para finalizar):\n");
		scanf("%d", &cod);
	}
	return;
}

/*2. Implementa una funcion que a partir de la lista realice 
un listado ordenado alfabeticamente por titulo. Indicar en el
main la cantidad total de peliculas.*/
void ordenar(puntero c) {
	puntero k, cota, p;
	pelicula aux;
	
	cota = NULL;
	k = NULL;
	while (k != c) {
		k = c;
		p = c;
		while (p->sig != cota) {
			if (strcmp(p->datos.titulo, p->sig->datos.titulo) > 1) {
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

void cantidad(puntero p, int &t) {
	while (p != NULL) {
		t++;
		p = p->sig;
	}
	return;
}

/*3.Crear una funcion que, a partir de la lista enlazada
genere un arreglo de enteros que contenga la cantidad de
entradas vendidas por cada genero. Mostrar el arreglo
cargado en otra funcion*/
void cereo(int a[6]) {
	int i;
	
	for (i = 0; i < 6; i++) {
		a[i] = 0;
	}
	return;
}

void carga_arreglo(puntero c, int a[6]) {
	int i;
	puntero aux;
	
	for (i = 0; i < 6; i++) {
		aux = c;
		
		while (aux != NULL) {
			a[aux->datos.genero-1] += aux->datos.entradas_vendidas;
			aux = aux->sig;
		}
	}
	return;
}

void mostrar(int a[6]) {
	int i;
	
	for (i = 0; i < 6; i++) {
		printf("Cantidad de entradas vendidas del genero %d: %d", i+1, a[i]);
	}
	return;
}

/*4.Ingresa el precio de la entrada (valor unico para todas
las peliculas) y calcula el valor total recaudado en
entradas vendidas. Muestra el resultado en el main.
Implementa una funcion de forma recursiva.*/
int recaudado(puntero c, int e) {
	if (c != NULL) {
		return (c->datos.entradas_vendidas * e) + recaudado(c->sig, e);
	} else {
		return 0;
	}
}

/*5.Ingresar un nombre de pelicula y a partir de la
informacion del archivo "pelicula.dat" si se encuentra en
el archivo, mostrar su informacion en el main.*/
void busqueda(FILE *a, char *n, int &c, char *t, int &g, int &ev) {
	pelicula p;
	rewind(a);
	fread(&p, sizeof(p), 1, a);
	
	while(feof(a) == 0) {
		if (strcmp(p.titulo, n) == 0) {
			c = p.cod;
			strcpy(t, p.titulo);
			g = p.genero;
			ev = p.entradas_vendidas;
		}
		
		fread(&p, sizeof(p), 1, a);
	}
	return;
}

int main() {
	puntero cabeza, aux;
	FILE *archivo;
	int total = 0, arreglo[6], entrada, cod, genero, entradas_vendidas;
	char nombre[30], titulo[30];
	
	//1.
	archivo = fopen("Peliculas.dat", "w+");
	crear(cabeza);
	insertar(cabeza, archivo);
	
	//2.
	ordenar(cabeza);
	cantidad(cabeza, total);
	printf("Cantidad total de peliculas: %d\n", total);
	
	//3.
	cereo(arreglo);
	carga_arreglo(cabeza, arreglo);
	mostrar(arreglo);
	
	//4.
	printf("Ingrese el valor de la entrada:\n");
	scanf("%d", &entrada);
	total = recaudado(cabeza, entrada);
	printf("Total recaudado en entradas: %d\n", total);
	
	//5.
	printf("Ingrese el nombre de una pelicula para la busqueda:\n");
	fflush(stdin);
	gets(nombre);
	busqueda(archivo, nombre, cod, titulo, genero, entradas_vendidas);
	if (aux != NULL) {
		printf("Pelicula encontrada:\n");
		printf("Codigo: %d", cod);
		printf("Titulo: ");
		puts(titulo);
		printf("\n");
		printf("Genero: %d", genero);
		printf("Entradas vendidas: %d", entradas_vendidas);
	} else {
		printf("Pelicula no encontrada:\n");
	}
	
	fclose(archivo);
}

