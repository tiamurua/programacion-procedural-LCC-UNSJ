//Ejercicio 9
//En la Facultad se realiza un congreso para el cual se destinan 6 salas de conferencias y cada una representa un área 
//temática. En cada sala se dictan 4 conferencias en distintos turnos. Por cada interesado se ingresa número del área 
//temática (1-6), y turno al que quiere asistir (1-4). La Facultad desea llevar un registro de la cantidad de alumnos 
//inscriptos en cada área y en cada turno, para ello realizar los siguientes items:
#include <stdio.h>

#define M 6
#define N 4

void cereo(int a[M][N]) {
	int i, j; 
	
	for (i = 0; i < M; i++) {
		for (j = 0; j < N; j++) {
			a[i][j] = 0;
		}
	}
}

//a) Carga de los datos. La carga es desordenada, cada alumno indica área y turno. No se sabe la cantidad de alumnos.
void carga(int a[M][N]) {
	int area, turno;
	
	printf("Ingrese numero (1 - 6) del area tematica a la que quiere asistir (0 para terminar): \n");
	scanf("%d", &area);
	while (area != 0) {
		printf("Ingrese turno (1 - 4) al que quiere asistir: \n");
		scanf("%d", &turno);
		
		a[area - 1][turno - 1]++;
		
		printf("Ingrese numero (1 - 6) del area tematica a la que quiere asistir (0 para terminar): \n");
		scanf("%d", &area);
	}
	return;	
}

//b) Indicar la cantidad de inscriptos en cada turno de cada área.
void mostrar(int a[M][N]) {
	int i, j;
	
	printf("Cantidad de inscriptos en cada turno de cada area: \n");
	for (i = 0; i < M; i++) {
		for (j = 0; j < N; j++) {
			printf(" [%d] ", a[i][j]);
		}
		
		printf("\n");
	}
	return;
}

//c) Dada un área temática, indicar el promedio de inscriptos.
void promedio(int a[M][N], int ar) {
	int i, acum;
	
	for (i = 0; i < M; i++) {
		acum += a[ar - 1][i];
	}
	
	printf("Promedio de inscriptos en el area %d: %d", ar, acum / 6);
	return;
}
int main() {
	int A[M][N], area;
	
	cereo(A);
	carga(A);
	mostrar(A);
	
	printf("Ingrese un area (1 - 6) para calcular el promedio de inscriptos: \n");
	scanf("%d", &area);
	promedio(A, area);
}
