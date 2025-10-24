/*Ejercicio 4
Una multinacional dedicada a la venta de automotores 
cuenta con la información de los 10 planes de 
financiación de las distintas unidades. 

Se cuenta con la siguiente información de cada 
adjudicatario a un plan: Numero de plan, DNI, Nombre y 
Apellido, cantidad de cuotas pagadas.
Se pide:*/
#include <stdio.h>
#include <alloc.h>
#include <string.h>
#define N 10

struct adjudicatario {
	int nPlan;
	int dni;
	char nombreApellido[30];
	int cCuotas;
	struct adjudicatario *sig;
};

struct nodo {
	adjudicatario dato;
	struct nodo *sig;
};

typedef struct nodo *puntero;

/*a) Cargar en una estructura de datos adecuada la 
información que se posee.*/
void crear(puntero &xc) {
	xc = NULL;
}

void carga(puntero &xc) {
	puntero nuevo;
	int xdni, cc;
	char nombreApellido[30];
	
	printf("Ingrese numero de plan:\n");
	scanf("%d", &nP);
	
	if (nP != 0) {
		nuevo = (puntero) malloc (sizeof(struct nodo));
		nuevo -> dato.nPlan = nP;
		
		printf("Ingrese DNI:\n");
		scanf("%d", &xdni);
		nuevo -> dato.dni = dni;
		
		printf("Ingrese Nombre y Apellido:\n");
		gets(nombreApellido);
		nuevo -> dato.nombreApellido = nombreApellido;
		
		printf("Ingrese cantidad de cuotas pagadas:\n");
		scanf("%d", &cc);
		nuevo -> dato.cCuotas = cc;
		
		nuevo -> sig = xc;
		xc = nuevo;
		carga(xc);
	}
	return;
}

/*b) Generar una nueva estructura con información de los planes que cuenten con adjudicatarios aptos para 
licitar un vehículo, es decir, con más de 30 cuotas pagadas.*/
void carga_b(puntero xc, puntero &xc2) {
	puntero nuevo;
	
	if (xc != NULL) {
		if (xc -> dato.cCuotas > 30) {
			nuevo = (puntero) malloc (sizeof(struct nodo));
			
			nuevo -> dato.nPlan = xc -> dato.nPlan;
			nuevo -> dato.dni = xc -> dato.dni;
			strcpy(nuevo -> dato.nombreApellido, xc -> dato.nombreApellido);
			nuevo -> dato.cCuotas = xc -> dato.cc;
			
			nuevo -> sig = xc2;
			xc2 = nuevo;
		}
		carga(xc -> sig, xc2);
	}
	return;
}

int main() {
	puntero cabeza, cabeza2;
	
	crear(&cabeza);
	carga(&cabeza);
	crear(&cabeza2);
	carga_b(cabeza, cabeza2);
}
