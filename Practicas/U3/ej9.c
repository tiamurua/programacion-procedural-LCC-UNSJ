/*Ejercicio 9
Una empresa de seguros procesa la información de las ventas que han realizado sus 10 promotores. 

De cada uno de los 10 promotores se conoce el código de sector donde trabaja (número entre 30 y 37) codificado: 30: Moto - 31: Auto - 
32: Camioneta - 33: Camión - 34: Ómnibus de Corta distancia - 35: Ómnibus de larga distancia - 36: Combis de pasajeros - 37: taxis.

De cada seguro (son 3 tipos de seguros distintos) se conoce el tipo (una letra entre “A” y “C”), el nombre y su precio. Los tipos de 
seguro se codifican: “A”: Seguro contra terceros, “B”: Seguro de Incendio y “C”: Seguro Total.

Nota: Leer la información que se pide, y de acuerdo a eso, ¿Qué estructura es la más adecuada para el almacenamiento de los datos?
Se pide realizar un programa que permita (utilizando Menú de opciones):*/

#include <stdio.h>

#define NP 10
#define NT 3
#define NS 8

typedef struct {
	char tipo;
	char nombre[40];
	float precio;
} seguro;

typedef struct {
	int sector;
	int venta[NT];
} promotor;

void cereo(promotor p[NP]) {
	int i;
	for (i = 0; i < NP; i++) {
		for (j = 0; j  < NT; j++) {
			p[i].venta[j] = 0;
		}
	}
}

/*1. Ingresar las ventas de seguros realizadas. Por cada venta se ingresa número de promotor (de 1...10) y tipo de seguro(“A”…“C”). Las 
ventas no traen ningún orden específico y termina el ingreso con número de promotor igual a 0.*/
void carga(promotor p[NP]) {
	int nPromotor, i;
	char tSeguro;
	
	printf("Ingrese numero de promotor (0 para finalizar): \n");
	scanf("%d", &nPromotor);
	while (nPromotor != 0) {
		printf("Ingresar tipo de seguro: \n");
		scanf("%c", %tSeguro);
		if (tSeguro == 'A') {
			p[nPromotor - 1].venta[0]++;
		} else if (tSeguro == 'B') {
			p[nPromotor - 1].venta[1]++;
		} else if (tSeguro == 'C') {
			p[nPromotor - 1].venta[2]++;
		} else {
			printf("Tipo de seguro inexistente o incorrecto.\n");
		}
		
		printf("Ingrese numero de promotor: \n");
		scanf("%d", &nPromotor);
	}
}

//2. Ingresar un tipo de seguro e indicar en qué sector se lo vende más y cuantos promotores tiene ese sector.
int seguro(promotor p[NP], int t) {
	int i, j, max = -1, indice;
	for (i = 0; i < NP; i++) {
		for (j = 0; j < NT; j++) {
			if (p[i].venta[j] > max) {
				max = p[i].venta[j];
				indice = i;
			}
		}
	}
	
	printf("El tipo de seguro se vendio mas en el sector %d", p[indice].sector);
	return indice;
}

void cantidad_promotores_sector(promotor p[NP], int in) {
	int i, cont = 0;
	for (i = 0; i < NP; i++) {
		if (p[i].sector == p[in].sector) {
			cont++;
		}
	}
	
	printf("Cantidad de promotores que tiene el sector donde se venden mas seguros del ingresado anteriormente: %d", cont);
	return;
}

//4. Dado un número de sector, indicar cuál es el seguro que más se consume.
void seguro_mas_consumido(promotor p[NP], int s) {
	int i, j, maxVentas = 0, tipoSeguroMax = -1;
	for (i = 0; i < NP; i++) {
		if (p[i].sector == s) {
			for (j = 0; j < NT; j++) {
				maxVentas = p[i].ventas[j];
				tipoSeguroMax = j;
			}
		}
	}
	
	printf("El seguro mas consumido en el sector %d es: %c\n", s, 'A' + tipoSeguroMax);
	return;
}

//5. Indicar para cada tipo de seguro, el nombre y el importe total de venta.
void datos_por_seguro (promotor p[NP], seguro s[NT]) {
	int i, j;
	for (i = 0; i < NP; i++) {
		
	}
}
int main() {
	seguro S[NT];
	promotor P[NP];
	int tipo, indice, sector;
	
	cereo(P);
	
	printf("\nMenu\n");
	printf("1. Ingresar las ventas de seguros realizadas.\n");
	printf("2. Ingresar un tipo de seguro para saber en que sector se vende mas.\n");
	printf("3. Cantidad de promotores en el sector que vende mas el seguro ingresado.\n");
	printf("4. Ingresar un numero de sector para saber cual es el seguro que mas se consume.\n");
	printf("5. Nombre e importe total de venta por tipo de seguro.\n");
	
	switch (opcion) {
		case 1:
			carga(P);
			break;
		
		case 2:
			printf("Ingrese un tipo de seguro (0: A, 1: B o 2: C): \n");
			scanf("%d", &tipo);
			indice = tipo_sector_promotor(P, tipo);
			break;
			
		case 3:
			cantidad_promotores_sector(P, indice);
			break;
			
		case 4:
			printf("Ingrese un numero de sector: \n");
			scanf("%d", &sector);
			seguro_mas_consumido(P, sector);
			
		case 5:
			datos_por_seguro(P, S);
	}
}




