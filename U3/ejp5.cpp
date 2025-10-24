/*Ejercicio 5
Se tienen las notas de 10 materias de 25 alumnos que 
cursan 3er año de secundaria. Además, se cuenta con 
los nombres de los alumnos almacenados en un arreglo.
Realizar un programa en C, que permita:*/

#include <stdio.h>

#define F 25
#define C 10

typedef struct {
	char nombre[50];
} alumno;

/*1. Cargar y mostrar por cada alumno la calificación 
obtenida en cada materia.*/
void carga(alumno a[F], float t[F][C]) {
	int i, j;
	
	for (i = 0; i < F; i++) {
		printf("Ingresar nombre del alumno:\n");
		fgets(a[i].nombre, 50, stdin);
		
		for (j = 0; j < C; j++) {
			printf("Ingrese nota de la materia %d:\n", j+1);
			scanf("%f", &t[i][j]);
		}
		getchar(); //limpia el buffer de entrada para evitar problemas con fgets
	}
	return;
}

void mostrar_notas(alumno a[F], float t[F][C]) {
	int i, j;
	
	printf("Calificaciones:\n");
	for (i = 0; i < F; i++) {
		printf("Alumno: %s", a[i].nombre);
		for (j = 0; j < C; j++) {
			printf("Materia %d: %f\n", j+1, t[i][j]);
		}
	}
	return;
}

//2. Calcular la nota promedio por cada alumno.
void promedios(alumno a[F], float t[F][C]) {
	int i, j;
	float acum;
	
	for (i = 0; i < F; i++) {
		acum = 0;
		
		for (j = 0; j < C; j++) {
			acum += t[i][j];
		}
		
		printf("Alumno: %sNota promedio: %.2f\n", a[i].nombre, acum / C);
	}
	return;
}

/*3. Calcular la nota máxima y mínima en cada 
materia.*/
void maximo_minimo(alumno a[F], float t[F][C]) {
	int i, j;
	float max, min;
	
	for (i = 0; i < C; i++) {
		max = -1;
		min = 9999;
		
		for (j = 0; j < F; j++) {
			if (t[j][i] > max) {
				max = t[j][i];
			} else if (t[j][i] < min) {
				min = t[j][i];
			}
		}
		
		printf("Nota maxima de la materia %d: %.2f", i+1, max);
		printf("Nota minima de la materia %d: %.2f", i+1, min);
	}
}

//4. Imprimir el nombre del alumno con mejor promedio.
void promedio_general(alumno a[F], float t[F][C]) {
	int i, j, indice;
	float acum, max = -1, p;
	
	for (i = 0; i < F; i++) {
		acum = 0;
		for (j = 0; j < C; j++) {
			acum += t[i][j];
		}
		
		p = acum / C;
		if (p > max) {
			max = p;
			indice = i;
		}
	}
	
	printf("El alumno con mejor promedio es: %s con un promedio de %.2f\n", a[indice].nombre, max);
	
	return;
}

int main() {
	alumno A[F];
	float T[F][C];
	
	carga(A, T);
	mostrar_notas(A, T);
	
	promedios(A, T);
	
	maximo_minimo(A, T);
	
	promedio_general(A, T);
}
