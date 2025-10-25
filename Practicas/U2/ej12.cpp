/*Ejercicio 12
Se cuenta con los datos de 350 encuestados sobre satisfacción del servicio ofrecido por la telefónica. Los 
datos ingresados no tienen ningún orden en particular y son: código de departamento, importe de la última 
factura y grado de satisfacción por el servicio que recibió: (1- óptimo, 2- bueno, 3- malo).
Generar una estructura con los nombres de departamento, sabiendo que la provincia tiene 19 departamentos.
Redactar un programa que procese la información y a través de funciones permita:*/
#include <stdio.h>
#include <string.h>

#define N 19
#define M 3
#define O 350

typedef struct departamento {
	char dep[50];
	int cantidad_encuestados;
	float mayor_facturacion;
} departamento;

/*a) Almacenar en una estructura adecuada, la cantidad de encuestados por cada departamento y la mayor facturación 
registrada por los encuestados de ese departamento. Además a medida que se procesa la información se debe actualizar una 
tabla que por cada uno de los 19 departamentos almacena el total de encuestados que reciben un servicio óptimo, bueno y 
malo.*/
void cereo(departamento d[N], int a[N][M]) {
	int i, j;
	
	for (i = 0; i < N; i++) {
		printf("Ingrese nombre del departamento: \n");
		gets(d[i].dep);
		d[i].cantidad_encuestados = 0;
		d[i].mayor_facturacion = -1;
		
		for(j = 0; j < M; j++) {
			a[i][j] = 0;
		}
	}
	return;
}

void carga_tabla(int a[N][M], departamento d[N]) {
	int i, j, codP, gSatisfaccion;
	float importe;
	
	for (i = 0; i < O; i++) {
		printf("Ingrese codigo de departamento (1 a 19): \n");
		scanf("%d", &codP);
		printf("Ingrese grado de satisfaccion (1, 2 o 3): \n");
		scanf("%d", &gSatisfaccion);
		
		a[codP - 1][gSatisfaccion - 1]++;
		
		printf("Ingrese ultima facturacion registrada: \n");
		scanf("%f", &importe);
		if(importe > d[codP - 1].mayor_facturacion) {
			d[codP - 1].mayor_facturacion = importe;
		}
		
		d[codP - 1].cantidad_encuestados++;
	}
	return;
}

//b) Mostrar el/los nombres del departamento con máxima facturación.
void mostrar_maximo(departamento d[N]) {
	int i;
	float max = -1;
	
	for (i = 0; i < N; i++) {
		if (d[i].mayor_facturacion > max) {
			max = d[i].mayor_facturacion;
		}
	}
	
	printf("Nombre del departamento con maxima facturacion: \n");
	for (i = 0; i < N; i++) {
		if (d[i].mayor_facturacion == max) {
			printf("%s", d[i].mayor_facturacion);
		}
	}
}

//c) Emitir un listado indicando el nombre del departamento y cantidad de usuarios con grado de satisfacción 1, 2 y 3.
void mostrar_satisfaccion(int a[N][M], departamento d[N]) {
	int i;
	
	for (i = 0; i < N; i++) {
		printf("Departamento: %s\n", d[i].dep);
		printf("Cantidad de usuarios con grado de satisfaccion 1: %d\n", a[i][0]);
		printf("Cantidad de usuarios con grado de satisfaccion 2: %d\n", a[i][1]);
		printf("Cantidad de usuarios con grado de satisfaccion 3: %d\n", a[i][2]);
		printf("\n");
	}
}
int main (){
	departamento D[N];
	int A[N][M];
	
	cereo(D, A);
	carga_tabla(A, D);
	mostrar_maximo(D);
	mostrar_satisfaccion(A, D);
}
