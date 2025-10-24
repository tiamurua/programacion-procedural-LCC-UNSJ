/*Ejercicio 10
La UNSJ todos los años otorga becas, para lo cual se ingresa 
el número de facultades participantes, de las misma se 
ingresan los nombres y de cada una las inscripciones de los 
alumnos aspirantes a las becas de ayuda económica. Se 
ingresa, en forma ordenada por facultad, los datos de cada 
alumno: Nombre, promedio y año que cursa.
Se pide, un programa que permita:*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char nombre[30];
	float prom;
	int ano;
} inscriptos;

struct nodo {
	inscriptos dato;
	struct nodo *sig;
};

typedef struct nodo *puntero;

typedef struct {
	char nombre[30];
	int c_inscriptos;
	puntero inscripto;
} facultad;

/*a)Realizar un listado ordenado por promedio, de los 
alumnos inscriptos en una determinada facultad cuyo nombre 
se ingresa por teclado. (Mostrar nombre del alumno, promedio 
y año que cursa).*/
void crear(facultad f[], int xcant, int i) {
	if (i < xcant) {
		f[i].inscripto = NULL;
		f[i].c_inscriptos = 0;
		crear(f, xcant, i+1);
	}
	return;
}

void insertar(facultad f[], int xcant) {
	puntero nuevo;
	char nom[30];
	int i;
	
	for (i = 0; i < xcant; i++) {
		printf("Ingrese nombre de la facultad:\n");
		fflush(stdin);
		gets(f[i].nombre);
		printf("Ingrese nombre (FIN para terminar):\n");
		fflush(stdin);
		gets(nom);
		
		while (strcmp(nom, "FIN") != 0) {
			nuevo = (puntero) malloc (sizeof(struct nodo));
		
			f[i].c_inscriptos++;
			strcpy(nuevo->dato.nombre, nom);
			printf("Ingrese Promedio:\n");
			scanf("%f", &nuevo->dato.prom);
			printf("Ingrese año que cursa:\n");
			scanf("%d", &nuevo->dato.ano);
		
			nuevo->sig = f[i].inscripto;
			f[i].inscripto = nuevo;
			
			printf("Ingrese nombre (FIN para terminar):\n");
			fflush(stdin);
			gets(nom);
		}
	}
	return;
}

int encontrar_indice(facultad f[], int xcant, char *elem) {
	int i = 0;
	
	while ((i < xcant) && (strcmp(f[i].nombre, elem) != 0)) {
		i++;
	}
	
	return i;
}

void ordenamiento(puntero c) {
	puntero k, cota, p;
	inscriptos aux;
	
	cota = NULL;
	k = NULL;
	
	while (k != c) {
		k = c;
		p = c;
		
		while (p->sig != cota) {
			if (p->dato.prom > p->sig->dato.prom) {
				aux = p->sig->dato;
				p->sig->dato = p->dato;
				p->dato = aux;
				k = p;
			}
			p = p->sig;
		}
		cota = k->sig;
	}
}

void mostrar_lista_ordenada(puntero c) {
	printf("Lista ordenada:\n");
	
	while (c != NULL) {
		printf("Nombre: %s\n", c->dato.nombre);
		printf("Promedio: %.2f\n", c->dato.prom);
		printf("Año que cursa: %d\n", c->dato.ano);
		c = c->sig;
	}
	return;
}

/*b)Indicar el nombre de la facultad que tiene menos 
inscriptos y la cantidad de inscriptos suponer único).*/
void menos_inscriptos(facultad f[], int xcant, int &m, char *nom) {
	int i;
	
	for (i = 0; i < xcant; i++) {
		if (f[i].c_inscriptos < m) {
			m = f[i].c_inscriptos;
			strcpy(nom, f[i].nombre);
		}
	}
	return;
}

/*c)Mostar por cada facultad la cantidad de alumnos con 
promedio mayor o igual a 7, que cursan de segundo año en 
adelante. Usar una función recursiva.*/
int contar_alumnos_promedio(puntero p) {
	if (p == NULL) {
		return 0;
	} else if (p->dato.prom >= 7 && p->dato.ano >= 2) {
		return 1 + contar_alumnos_promedio(p->sig); 
	} else {
		return contar_alumnos_promedio(p->sig);
	}
}

void promedio(facultad f[], int xcant, int i) {
	int cont;
	if (i < xcant) {
		cont = contar_alumnos_promedio(f[i].inscripto);
		printf("Facultad: %s\n", f[i].nombre);
		printf("Cantidad de alumnos con promedio mayor o igual a 7 desde 2do año: %d\n", cont);
	}
	return;
}

int main() {
	facultad *F;
	int cant, indice, min = -1;
	char nombre[30];
	
	printf("Ingrese cantidad de facultades:\n");
	scanf("%d", &cant);
	
	F = (facultad*) malloc (cant * sizeof(facultad));
	
	//a)
	crear(F, cant, 0);
	insertar(F, cant);
	printf("Ingrese nombre de la facultad para ordenar la lista de inscriptos:\n");
	fflush(stdin);
	gets(nombre);
	indice = encontrar_indice(F, cant, nombre);
	
	if (indice < cant) {
		ordenamiento(F[indice].inscripto);
		mostrar_lista_ordenada(F[indice].inscripto);
	} else {
		printf("Facultad no encontrada.\n");
	}
	
	//b)
	menos_inscriptos(F, cant, min, nombre);
	printf("Facultad con menos inscriptos: %s (%d inscriptos)\n", nombre, min);
	
	//c)
	promedio(F, cant, 0);
	
	free(F);
}
