/*Ejercicio 8
La Facultad de Ciencias Exactas organizó el Congreso de 
Informática, y necesita administrar la información relativa a 
los 10 tutoriales que se proponen en dicho evento.
Realizar un programa, que a través de un menú de opciones 
permita:*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nodo {
	int dni;
	struct nodo *sig;
};

typedef struct nodo *puntero;

typedef struct tutorial {
	char titulo[30];
	puntero inscriptos;
};

/*a)Ingresar los datos correspondientes a cada tutorial: 
número de tutorial (1-10) y título.*/
void cargar_tutoriales(tutorial t[10], int i) {
	int num;
	if (i < 10) {
		printf("Ingrese numero del tutorial:\n");
		scanf("%d", &num);
		printf("Ingrese nombre del tutorial:\n");
		fflush(stdin);
		gets(t[i].titulo);
		
		cargar_tutoriales(t, i+1);
	}
	return;
}

/*b)Registrar las inscripciones, ingresando el DNI del 
inscripto y el número de tutorial al que desea asistir.*/
void crear_listas(tutorial t[10], int i) {
	if (i < 10) {
		t[i].inscriptos = NULL;
		
		crear_listas(t, i+1);
	}
	return;
}

void registrar_inscripciones(tutorial t[10]) {
	puntero nuevo;
	int dni, n;
	
	printf("Ingrese DNI (0 para finalizar):\n");
	scanf("%d", &dni);
	if (dni != 0) {
		nuevo = (puntero) malloc (sizeof(struct nodo));
		
		nuevo->dni = dni;
		printf("Ingrese numero de curso al que se quiere inscribir:\n");
		scanf("%d", &n);
		nuevo->sig = t[n-1].inscriptos;
		t[n-1].inscriptos = nuevo;
	}
	return;
}

/*c)Eliminar alguna inscripción, en cuyo caso se ingresarán 
los mismos datos que en el ítem anterior.*/
void suprimir(puntero &c, int xdni) {
	puntero anterior, p;
	
	if (c->dni == xdni) {
		p = c;
		c = c->sig;
		free(p);
	} else { 
		p = c;
		anterior = c;
		while ((p != NULL) && (p->dni != xdni)) {
			anterior = p;
			p = p->sig;
		}
		if (p != NULL) {
			anterior->sig = p->sig;
			free(p);
			printf("La inscripcion fue eliminada de la lista.\n");
		} else {
			printf("No se encuentra la inscripcion en la lista.\n");
			return;
		}
	}
}

/*d)Dado el número de un tutorial, mostrar su título y la 
cantidad de inscriptos en él.*/
int mostrar_datos(puntero c) {
	if (c == NULL) {
		return 0;
	}
	return 1 + mostrar_datos(c->sig);	
}

/*e)Dado el DNI de una persona, informar el/los tutoriales 
(número y título) en los que se inscribió.*/
int busqueda_lista(puntero c, int elem) {
	if (c == NULL) {
		return 0;
	} else if (c->dni == elem) {
		return 1;
	} else {
		return busqueda_lista(c->sig, elem);
	}
}

void busqueda_arreglo(tutorial t[10], int xdni, int i) {
	int indice;
	if (i < 10) {
		indice = busqueda_lista(t[i].inscriptos, xdni);
		
		if (indice != 0) {
			printf("El usuario con DNI %d esta inscripto en el tutorial: %d - %s.\n", xdni, i+1, t[i].titulo);
		} else {
			printf("El DNI no se encuentra en las listas.\n");
		}
		
		busqueda_arreglo(t, xdni, i+1);
	}
	return;
}

int main() {
	int opcion, dni, num, cantidad;
	tutorial T[10];
	
	printf("\nMenu de opciones:\n");
	printf("1. Opcion 1: Cargar datos de los tutoriales.\n");
	printf("2. Opcion 2: Registrar inscripciones.\n");
	printf("3. Opcion 3: Eliminar una inscripcion.\n");
	printf("4. Opcion 4: Titulo y cantidad de inscriptos de un tutorial.\n");
	printf("5. Opcion 5: Tutoriales en los que se inscribio un asistente.\n");
	printf("6. Opcion 6: Salir.\n");
	printf("Elige una opcion: ");
	scanf("%d", &opcion);
	
	switch(opcion) {
		case 1:
			crear_listas(T, 0);
			cargar_tutoriales(T, 0);
			break;
		case 2:
			crear_listas(T, 0);
			registrar_inscripciones(T);
			break;
		case 3:
			printf("Ingrese DNI");
			scanf("%d", &dni);
			printf("Ingrese numero de tutorial al que pertenece:\n");
			scanf("%d", &num);
			suprimir(T[num-1].inscriptos, dni);
			break;
		case 4:
			printf("Ingrese un numero de tutorial:\n");
			scanf("%d", &num);
			cantidad = mostrar_datos(T[num-1].inscriptos);
			printf("Titulo del tutorial %d: %s, Cantidad de inscriptos: %d", num+1, T[num-1].titulo, cantidad);
			break;
		case 5:
			printf("Ingrese un DNI:\n");
			scanf("%d", &dni);
			busqueda_arreglo(T, dni, 0);
			break;
		case 6:
			printf("Saliendo...\n");
			break;
		default:
			printf("Opcion no valida.\n");
			break;
	}
}
