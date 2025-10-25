/*ACTIVIDAD 3
Se ingresa el registro y la nota obtenida (valor 
entero entre 1 y 10) por los alumnos que rindieron en 
la última mesa de examen de la materia Programación 
Procedural. 

Escribir un programa en C que permita:*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int registro;
	int nota;
} alumno;

/*Definir una función carga que almacene toda la 
información de la mesa de examen. Por teclado se 
ingresa la cantidad de alumnos que rindieron el 
examen.*/
void carga(alumno a[], int c) {
	int i;
	
	for (i = 0; i < c; i++) {
		printf("Ingrese numero de registro del alumno %d:\n", i + 1);
		scanf("%d", &a[i].registro);
		printf("Ingrese nota del alumno %d:\n");
		scanf("%d", &a[i].nota);
	}
	return;
}

/*Mostrar la nota promedio y el número de 
registro de quienes obtuvieron en el examen una 
nota mayor o igual al promedio*/
int promedio(alumno a[], int c) {
	int i, sum = 0;
	for (i = 0; i < c; i++) {
		sum += a[i].nota;
	}
	return sum / c;
}

void mayorIgual(alumno a[], int c, int prom) {
	int i;
	
	for (i = 0; i < c; i++) {
		if (a[i].nota >= prom) {
			printf("Numero de registro: %d", a[i].registro);
		}
	}
	return;
}

/*Construir una función que usando la menor y la 
mayor nota obtenidas, indique la cantidad de 
alumnos que obtuvieron cada nota entera 
comprendida en ese rango.*/
int menorMayor(alumno a[], int c, int &xmin, int &xmax, int &cmax) {
	int i, cmin = 0;
	for (i = 0; i < c; i++) {
		if (a[i].nota < xmin) {
			xmin = a[i].nota;
			cmin++;
		} else if (a[i].nota > xmax) {
			xmax = a[i].nota;
			cmax++;
		}
	}
	return cmin;
}

void notasEntre(alumno a[], int c, int cmax, int cmin) {
	int i, cont = 0;
	
	for (i = 0; i < c; i++) {
		if (a[i].nota >= cmin && a[i].nota <= cmax) {
			cont++;
		}
	}
	
	printf("Cantidad de alumnos que obtuvieron nota dentro del rango entre la nota minima y la nota maxima registrada: %d", cont);
	return;
}

int main() {
	alumno *A
	int cantidadA, prom, min = 99, max = -1, contMax, contMin;
	
	printf("Ingrese la cantidad de alumnos:\n");
	scanf("%d", &cantidadA);
	A = (alumno *) malloc (cantidadA * sizeof(alumno));
	
	carga(A, cantidadA);
	prom = promedio(A, cantidadA);
	printf("Nota promedio: %d", prom);
	mayorIgual(A, cantidadA, prom);
	
	contMin = menorMayor(A, c, min, max, contMax);
	notasEntre(A, cantidadA, contMax, contMin);
}
