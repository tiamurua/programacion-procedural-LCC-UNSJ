/*Ejercicio 4
Una empresa desea realizar un control de 700 productos 
distintos que comercializa, de los mismos posee: 
Código de identificación del producto, cantidad de 
productos con ese código y precio unitario.
Realizar un programa en C que permita:*/

#include <stdio.h>

#define N 700

typedef struct {
	int cod;
	int cantidad;
	float pUnitario;
} producto;

//1. Almacenar los datos de todos los productos.
void carga (producto p[N]) {
	int i;
	for (i = 0; i < N; i++) {
		printf("Ingrese codigo del producto:\n");
		scanf("%d", &p[i].cod);
		printf("Ingrese cantidad de productos con ese codigo:\n");
		scanf("%d", &p[i].cantidad);
		printf("Ingrese precio unitario del producto:\n");
		scanf("%f", &p[i].pUnitario);
	}
	return;
}

/*2. Calcular el monto total del stock por producto 
(precio por cantidad).*/
void monto_total(producto p[N]) {
	int i;
	for (i = 0; i < N; i++) {
		printf("Monto total del stock del produto %d: $%.2f\n", p[i].cantidad * p[i].pUnitario);
	}
	return;
}

/*4. Mostrar el código de identificación de los 
productos con mayor precio unitario y cuyo código de 
identificación esté comprendido entre 250 y 300.*/
float maximo(producto p[N]) {
	int i;
	float max = -1;
	for (i = 0; i < N; i++) {
		if (p[i].pUnitario > max) {
			max = p[i].pUnitario;
		}
	}
	return max;
}

void identificacion(producto p[N], float xm) {
	int i;
	for (i = 0; i < N; i++) {
		if (p[i].pUnitario == xm && p[i].cod >= 250 && p[i].cod <= 300) {
			printf("Codigo de identificacion del producto: %d", p[i].cod);
		}
	}
	return;
}

/*4. Ingresar un valor correspondiente a una cantidad 
de stock mínima y generar un arreglo que contenga los 
códigos de aquellos productos cuya cantidad sea menor 
que la ingresada.*/
int generar_sub(producto p[N], producto sp[N], int s) {
	int i, c = 0;
	for (i = 0; i < N; i++) {
		if (p[i].cantidad < s) {
			sp[c] = p[i];
			c++;
		}
	}
	return c;
}

int main() {
	producto P[N], SP[N];
	float m;
	int stock, c;
	
	carga(P);
	
	monto_total(P);
	
	m = maximo(P);
	identificacion(P, m);
	
	printf("Ingrese un valor correspondiente a una cantidad de stock minima:\n");
	scanf("%d", &stock);
	c = generar_sub(P, SP, stock);
}
