#include <stdio.h>

#define N 10

struct alumno {
	char nombre[20];
	char apellido[20];
	int dni;
};

void carga(alumno a[N]) {
	int i;
	for (i = 0; i < N; i++) {
		printf("Ingrese datos del alumno: \n");
		scanf("%s", a[i].nombre);
		scanf("%s", a[i].apellido);
		scanf("%d", a[i].dni);
	}
	return;
}

void lista(alumno a[N]) {
	int i;
	for (i = 0; i < N; i++) {
		printf("Alumnos cargados: \n");
		printf("Nombre: %s", a[i].nombre);
		printf("Apellido: %s", a[i].apellido);
		printf("DNI: %d", a[i].dni);
	}
	return;
}

void dni_mayor(alumno a[N]) {
	int i, cont = 0;
	for (i = 0; i < N; i++) {
		if (a[i].dni > 40000000) {
			cont++;
		}
	}
	
	printf("Cantidad de alumnos con DNI mayor a 40 millones: %d", cont);
	return;
}
int main() {
	alumno A[N];
	
	carga(A);
	lista(A);
	dni_mayor(A);
}
