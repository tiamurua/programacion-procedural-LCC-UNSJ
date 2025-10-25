/*Ejercicio 6
Realizar un programa que mediante funciones recursivas permita:*/
#include <stdio.h>
#include <stdlib.h>

struct nodo {
	int num;
	struct nodo *sig;
};

typedef struct nodo *puntero;

//a)Generar una lista enlazada de números enteros positivos, ordenada en forma ascendente. Validar la entrada.
puntero insertarAdentroRecursivo(puntero &xp) {
	int n;
    // Crear un nuevo nodo
    printf("Ingrese un numero entero positivo (0 para terminar):\n");
    scanf("%d", &n);
    
    if (n == 0) {
    	return xp;
	}
	
    if (n > 0) {
    	puntero nuevo;
		nuevo = (puntero)malloc(sizeof(struct nodo));
    	nuevo->num = n;
    	nuevo->sig = NULL;

    	// Caso 1: La lista está vacía, insertar al inicio
    	if (xp == NULL || n <= xp->num) {
        	nuevo->sig = xp;
			xp = nuevo;
    	} else {
    		xp->sig = insertarAdentroRecursivo(xp->sig);
		}
	} else {
		printf("ERROR! El numero ingresado no es positivo.\n");
	}
	insertarAdentroRecursivo(xp);
}

void mostrarLista(puntero c) {
	if (c != NULL) {
		printf("%d\n", c->num);
		mostrarLista(c->sig);
	}
}

//b)Escribir un mensaje indicando si el número del último nodo de la lista es par.
void esPar(puntero &c) {
	if (c != NULL) {
		if (c -> sig == NULL) {
			if (c -> num % 2 == 0) {
				printf("El numero del ultimo nodo de la lista es par.");
			} else {
				printf("El numero del ultimo nodo de la lista no es par.");
			}
		} else {
			esPar(c->sig);
		}
	}
}

//c)Mostrar la lista generada en forma inversa.
void listar(puntero c) {
	if (c != NULL) {
		listar(c->sig);
		printf("%d\n", c->num);
	}
	return;
}

//d)Ingresar un número y decir en qué lugar se encuentra.
int busqueda(puntero c, int n, int i) {
	if (c != NULL) {
		if (c->num == n) {
			return i;
		} else {
			return busqueda(c->sig, n, i+1);
		}
	} else {
		return -1;
	}
}

int main() {
	puntero cabeza;
	int numero, resultado;
	
	cabeza = NULL;
	
	cabeza = insertarAdentroRecursivo(cabeza);
	printf("Lista generada:\n");
	mostrarLista(cabeza);
	
	esPar(cabeza);
	
	printf("Lista en orden inverso:\n");
	listar(cabeza);
	
	printf("Ingresar un numero para buscarlo en la lista:\n");
	scanf("%d", &numero);
	resultado = busqueda(cabeza, numero, 0);
	if (resultado != -1) {
		printf("El elemento se encontro en la posicion %d.\n", resultado);
	} else {
		printf("Elemento no encontrado.\n");
	}
}
