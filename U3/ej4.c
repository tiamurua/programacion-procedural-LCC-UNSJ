/*Ejercicio 4
Una industria comercializa 70 productos codificados entre 100 y 169. De cada producto se conoce el código de producto y 
precio unitario. Además, se cuenta con la información de las ventas realizadas durante el fin de semana. Por cada venta se 
ingresa código de producto y cantidad de unidades, finalizando el ingreso con código de producto igual a cero.
Se pide realizar un programa en C, que utilizando funciones óptimas y estructuras adecuadas permita:*/

#include <stdio.h>

#define N 70

typedef struct {
	float pUnitario;
	int cUVendidas;
	float tVendido;
} producto;

void cereo(producto p[N]) {
	int i;
	for (i = 0; i < N; i++) {
		printf("Ingrese precio Unitario para el producto %d: ", i + 100);
		scanf("%f", &p[i].pUnitario);
		p[i].cUVendidas = 0;
		p[i].tVendido = 0;
	}
	return;
}

void procesamiento_ventas(producto p[N]) {
	int cod, cUnidades;
	
	printf("Ingrese codigo del producto (0 para finalizar): \n");
	scanf("%d", &cod);
	while (cod != 0) {
		printf("Ingrese cantidad de unidades vendidas: \n");
		scanf("%d", &cUnidades);
		p[cod - 100].cUVendidas += cUnidades;
		p[cod - 100].tVendido += (cUnidades * p[cod - 100].pUnitario);
		
		printf("Ingrese codigo del producto (0 para finalizar): \n");
		scanf("%d", &cod);
	}
	return;
}

//1. Total de unidades vendidas de cada uno de los productos.
void total_vendido(producto p[N]) {
	int i;
	for (i = 0; i < N; i++) {
		printf("Total de unidades vendidas del producto %d: %d\n", i + 100, p[i].cUVendidas);
	}
	return;
}

/*2. Indicar en el main el código del producto que recaudó mayor importe, el mayor importe y la cantidad de unidades 
vendidas.*/
int mayor_venta(producto p[N], float *m, int *u) {
	int i, cod = -1;
	
	*m = -1;
	
	for (i = 0; i < N; i++) {
		if (p[i].tVendido > *m) {
			*m = p[i].tVendido;
			cod = i + 100;
			*u = p[i].cUVendidas;
		}
	}
	return cod;
}

//3. En función del total de unidades vendidas, decir de cuantos productos se vendieron 20, 21, 22.. 50 unidades.
void productos_entre(producto p[N]) {
	int i, cont = 0;
	
	for (i = 0; i < N; i++) {
		if(p[i].cUVendidas >= 20 && p[i].cUVendidas <= 50) {
			cont++;
		}
	}
	
	printf("Se vendieron entre 20 y 50 unidades de %d productos.", cont);
	return;
}

int main() {
	producto P[N];
	int i, unidades, cod_mayor_venta;
	float max;
	
	cereo(P);
	procesamiento_ventas(P);
	total_vendido(P);
	
	cod_mayor_venta = mayor_venta(P, &max, &unidades);
	printf("Codigo del producto que recaudo el mayor importe: %d\n", cod_mayor_venta);
	printf("Mayor importe recaudado: %2.f\n", max);
	printf("Cantidad de unidades vendidas: %d\n", unidades);
	
	
}



