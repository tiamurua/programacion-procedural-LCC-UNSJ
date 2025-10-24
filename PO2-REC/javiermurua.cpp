//JTP: Silvina Balmaceda - Alumno: Javier Murua
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int patente;
	char marca[7];
	char modelo[6];
	int ano;
} Auto;

struct nodo {
	Auto datos;
	struct nodo *sig;
};

typedef struct nodo *puntero;

/*1. Creación de una lista enlazada: Crea una función que 
reciba una cabeza de lista y genere una lista enlazada en la 
cual registre información de autos: patente (número entero), 
marca, modelo y año.*/
void crear(puntero &c) {
    c = NULL;
    return;
}

void insertar(puntero &c) {
    puntero nuevo;
    int patente;

    printf("Ingrese la patente del auto (0 para terminar):\n");
    scanf("%d", &patente);

    if (patente != 0) {
        nuevo = (puntero) malloc (sizeof(struct nodo));

        nuevo->datos.patente = patente;
        printf("Ingrese marca del auto:\n");
        fflush(stdin);
        gets(nuevo -> datos.marca);
        
        printf("Ingrese modelo del auto:\n");
        fflush(stdin);
        gets(nuevo -> datos.modelo);
        
        printf("Ingrese año del auto:\n");
        scanf("%d", &nuevo->datos.ano);

        nuevo->sig = c;
        c = nuevo;

        insertar(c->sig);
    }
    return;
}

/*2. Búsqueda recursiva de un elemento: Crea una función 
recursiva que reciba una patente y si se encuentra en la 
lista enlazada mostrar en el principal los datos del auto.*/
int busqueda(puntero c, int p, int &a, char *xmarca, char *xmodelo)
{
	if (c != NULL) {
		if (c->datos.patente == p) {
			a = c->datos.ano;
			strcpy(xmarca, c->datos.marca);
			strcpy(xmodelo, c->datos.modelo);
			return c->datos.patente;
		} else {
			return busqueda(c->sig, p, a, xmarca, xmodelo);
		}
	}
	return 0;
}

/*3. Impresión recursiva de la lista: Crear una función que 
reciba una marca e imprima todos los autos de esa marca.*/
void mostrar(puntero c, char *m) {
	if (c != NULL) {
		if (strcmp(c->datos.marca, m) == 0) {
			printf("PATENTE: %d\n", c->datos.patente);
			printf("MARCA: %s\n", c->datos.marca);
			printf("MODELO: %s\n", c->datos.modelo);
			printf("AÑO: %d\n", c->datos.ano);
		}
		
		mostrar(c->sig, m);
	}
	return;
}

/*4. Eliminación de un elemento por valor: Crea una función 
que, dado una patente elimine el nodo que contiene dicho 
valor en la lista enlazada.*/ 
void suprimir(puntero &c, int xpatente)
{
	puntero anterior, p;
	
	if (c->datos.patente == xpatente)
	{
		p = c;
		c = c -> sig;
		free(p);
	} else {
		p = c;
		anterior = c;
		while ((p != NULL) && (p -> datos.patente != xpatente))
		{
			anterior = p;
			p = p -> sig;
		}
		if (p != NULL)
		{
			anterior -> sig = p -> sig;
			free(p);
			printf("El auto fue eliminado de la lista.\n");
		} else {
			printf("No se encuentra el auto en la lista.\n");
			return;
		}
	}
}

/*5. Procesamiento de la lista: Crea una función recursiva 
que indique cual es el auto más antiguo. Mostrar el 
resultado en el principal.*/
int procesamiento(puntero c, int &am) {
	if (c != NULL) {
		if (c->datos.ano < am) {
			am = c->datos.ano;
		}
		procesamiento(c->sig, am);
		return am;
	} else {
		return 0;
	}
}
 
int main() {
	puntero cabeza;
	int patente, ano, p_encontrada, a_min = 9999, antiguo;
	char marca[7], modelo[6];
	
	//1
	crear(cabeza);
	insertar(cabeza);
	
	//2
	printf("Ingrese una patente para buscarla en la lista:\n");
	scanf("%d", &patente);
	p_encontrada = busqueda(cabeza, patente, ano, marca, modelo);
	if (p_encontrada != 0) {
		printf("Encontrado.\n");
		printf("PATENTE: %d\n", p_encontrada);
		printf("MARCA: %s\n", marca);
		printf("MODELO: %s\n", modelo);
		printf("AÑO: %d\n", ano);
	} else {
		printf("Auto no encontrado en la lista.\n");
	}
	
	//3
	printf("Ingrese una marca de auto:\n");
	fflush(stdin);
	gets(marca);
	printf("Autos de la marca ingresada:\n");
	mostrar(cabeza, marca);
	
	//4
	printf("Ingrese una patente para eliminarla de la lista:\n");
	scanf("%d", &patente);
	suprimir(cabeza, patente);
	
	//5
	antiguo = procesamiento(cabeza, a_min);
	if (antiguo != 0) {
		printf("El auto mas antiguo es del año: %d\n", antiguo);
	}
	
}
