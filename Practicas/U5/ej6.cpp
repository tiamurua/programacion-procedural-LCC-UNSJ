/*Ejercicio 6
Realizar un programa que mediante funciones recursivas 
permita:*/
#include <stdio.h>
#include <stdlib.h>

/*a) Generar una lista enlazada de números enteros 
positivos, ordenada en forma ascendente. Validar la 
entrada.*/
struct nodo {
	int nro;
	struct nodo *sig;
};
typedef struct nodo *puntero;

void crear(puntero &xp) {
	xp = NULL;
}

nodo insertarOrdenado(puntero &xp, int xd) {
	puntero nuevo;
	malloc
	
	if (cabeza == NULL)
	malloc
	else cabeza != nulle
	if (xd > 0) {
		if (xd < cabeza -> xd) {
			nuevo = (puntero) malloc (sizeof(struct nodo));
			nuevo -> xd = xd;
			nuevo -> siguiente = cabeza;
			return nuevo;	
		} else {
			cabeza -> siguiente = insertarOrdenado(cabeza -> siguiente, dato);
			return cabeza;
		}
		nuevo = (puntero) malloc (sizeof(struct nodo));
		nuevo -> nro = dato;
		nuevo -> sig = xp;
		xp = nuevo;
	}
	return;
}

void ordenamiento(puntero xc) {
	puntero k, cota, p;
	int aux;
	
	cota = NULL;
	K = NULL;
	while (k != xc) {
		k = xc;
		p = xc;
		while (p -> sig != cota) {
			if (p -> nro > p -> sig -> nro) {
				aux = p -> sig -> nro;
				p -> sig -> nro = p -> nro;
			}
		}
	}
}

/*b) Escribir un mensaje indicando si el número del 
último nodo de la lista es par.*/
void esPar(puntero xc) {
	if (cabeza != NULL && cabeza -> siguiente != NULL) {
		if (cabeza -> dato %2 == 0) {
			printf("El numero del ultimo nodo de la lista es par.\n");
		} else {
			printf("El numero del ultimo nodo de la lista no es par.\n");
		}
	} else {
		printf("Lista vacia.");
	}
	return;
}

//c) Mostrar la lista generada en forma inversa.

int main() {
	puntero cabeza;
	int dato;
	
	crear(cabeza);
	printf("Ingrese un numero entero positivo:\n");
	scanf("%d", &dato);
	cabeza = insertarOrdenado(cabeza, dato);
	esPar(cabeza);
	
	
	insertar(cabeza);
	ordenamiento(cabeza);
}

d)
Ingresar un número y decir en qué lugar se encuentra.
