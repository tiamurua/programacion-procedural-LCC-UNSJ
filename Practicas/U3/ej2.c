/*Ejercicio 2
Un local comercial de ventas de repuestos de automotores 
desea obtener cierta información sobre todas las ventas 
registradas en un periodo de tiempo dado. El comercio 
cuenta con 250 artículos, almacenados en una estructura y 
de los cuales se conocen los siguientes datos: Código, 
Nombre, Precio Unitario y Stock.
Se procesan las ventas y los datos ingresados de cada una 
son: Nombre del artículo, Cantidad de unidades vendidas 
(con esta información actualizar el stock de cada 
artículo). El ingreso de ventas termina con nombre igual 
“FIN”.
Se pide realizar un programa en C, que utilizando 
subprogramas óptimos y estructuras adecuadas permita:*/

#include <stdio.h>
#include <string.h>

#define N 250

typedef struct {
	int cod;
	char nombre[100];
	float pUnitario;
	int stock;
	float tVendido;
} articulo;

//1. Procesar las ventas registradas en ese periodo de tiempo.
void procesarVentas (articulo a[N]) {
	char nombre[100];
	int cantidad, i;
	
	printf("Ingrese nombre del articulo: \n");
	scanf("%s", nombre);
	while (strcmp(nombre, "FIN") != 0) { //Si nombre y "FIN" son iguales, el resultado sera 0
		printf("Ingrese cantidad de unidades vendidas: \n");
		scanf("%d", &cantidad);
		
		for (i = 0; i < N; i++) {
			if (strcmp(a[i].nombre, nombre) == 0) {
				if(a[i].stock >= cantidad) {
					a[i].stock -= cantidad;
					a[i].tVendido += (cantidad * a[i].pUnitario);
				} else {
					printf("Stock insuficiente.\n");
				}
			}
		}
		printf("Ingrese nombre del articulo: \n");
		scanf("%s", nombre);
	}
	return;
}

//2.Mostrar en el main la cantidad de artículos que quedaron con stock nulo y cuantos tienen 
//un precio mayor a $7000.
void stock_precio (articulo a[N], *cS, *mP) {
	int i;
	*cS = 0;
	*mP = 0;
	for (i = 0; i < N; i++) {
		if (a[i].stock == 0) {
			*cS++;
		}
		
		if (a[i].pUnitario > 7000) {
			*mP++;
		}
	}
}

//3. Imprimir los nombres de los 20 artículos que quedaron con mayor stock.
void ordenamiento(articulo a[N]) {
	int i, j;
	articulo valor;
	for (i = 0; i < N; i++) {
		valor = a[i].stock;
		j = i - 1;
		while ((j >= 0) && (valor < a[j].stock)) {
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + 1] = a[j];
	}
	return;
}

void mostrar_20(articulo a[N]) {
	int i;
	for (i = 0; i < 21; i++) {
		puts(a[i].nombre);
	}
	return;
}

//4. Indicar para cada artículo el monto total obtenido por ventas.
void monto_total(articulo a[i]) {
	int i;
	for (i = 0; i < N; i++) {
		printf("Monto total obtenido por ventas del articulo %s: %f", a[i].nombre, a[i].tVendido);
	}
	return;
}
void total_por_venta()
int main() {
	articulo A[N];
	int cStock, mPrecio;
	
	procesarVentas(A);
	
	stock_precio(A, &cStock, &mPrecio);
	printf("Cantidad de articulos con que quedaron con stock nulo: %d", cStock);
	printf("Cantidad de articulos con precio unitario mayor a $7000: %d", mPrecio);
	
	ordenamiento(A);
	
	total_por_venta(A);
	mostrar_20(A);
	
	monto_total(A);
}


