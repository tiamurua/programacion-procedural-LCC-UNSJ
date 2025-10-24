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

void stock_nulo(articulo a[N]) {
	int i;
	
	printf("Articulos con stock nulo: \n");
	for (i = 0; i < N; i++) {
		if (a[i].stock == 0) {
			printf("Nombre: %s\n", a[i].nombre);
		}
	}
	return;
}

void busqueda_por_cod(articulo a[N], int e) {
	int i;
	i = 0;
	while (i < N && a[i].cod != e) {
		i++;
	}
	
	if (i < N) {
		printf("Stock: %d", a[i].stock);
	}
	return;
}

void total(articulo a[N]) {
	int i;
	float acum = 0;
	
	for (i = 0; i < N; i++) {
		acum += a[i].tVendido;
	}
	
	printf("Monto total obtenido por la venta de productos: %.2f", acum);
	return;
}

int main() {
	articulo A[N];
	int elemento;
	
	procesarVentas(A);
	stock_nulo(A);
	printf("Ingrese codigo del articulo para saber el stock: \n");
	scanf("%d", &elemento);
	busqueda_por_cod(A, elemento);
	total(A);
}
