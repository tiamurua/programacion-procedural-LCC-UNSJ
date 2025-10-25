/*Ejercicio 5
En la Facultad se realiza un congreso para el cual se destinan 6 salas de conferencias y cada una representa un área 
temática.

En cada sala se dictarán 4 conferencias en distintos turnos. Para procesar la información, en un primer momento y por única 
vez se ingresa el nombre de cada una de las 6 áreas temáticas que se tratarán en el congreso y el cupo de personas para la 
sala donde se dictará la misma. 

Por cada interesado se ingresa su nombre, nombre del área temática, y número correspondiente a la conferencia a la que 
quiere asistir.

La inscripción se realiza previa verificación del cupo de la sala. 
A partir de la información ingresada generar una tabla que permita responder los siguientes ítems:*/
#include <stdio.h>
#include <string.h>

#define F 6
#define C 4
typedef struct {
	char nArea[20];
	int cupo;
	int cAsistentes;
} area;

void cereo(area a[F], int t[F][C]) {
	int i, j;
	for (i = 0; i < F; i++) {
		a[i].cAsistentes = 0;
		for (j = 0; j < C; j++) {
			t[i][j] = 0;
		}
	}
	return;
}
void procesarInfo(area a[F]) {
	int i;
	for (i = 0; i < F; i++) {
		printf("Ingrese nombre del area y cupo de personas para la sala donde se dictara la misma: \n");
		fgets(a[i].nArea, 20, stdin);
		scanf("%d", &a[i].cupo);
	}
	return;
}

int busqueda_x_area(area a[F], char elem) {
	int i;
	i = 0;
	while ((i < F) && (strcmp(a[i].nArea, elem) == 0)) {
		i = i + 1;
	}
	return i;
}
void carga(area a[F], int t[F][C]) {
	char nombre[30], area[20];
	int indice, conferencia;
	
	printf("Ingrese su nombre (FIN para terminar): \n");
	fgets(nombre, 30, stdin);
	while (nombre != "FIN") {
		printf("Ingrese Area tematica a la que desea asistir: \n");
		fgets(area, 20, stdin);
		indice = busqueda_x_area(a, area);
		if (indice < F) {
			if (indice > 0) {
				printf("Ingrese numero de conferencia a la que va a asistir: \n");
				scanf("%d", &conferencia);
				if (conferencia < a[indice].cupo) {
					a[indice].cAsistentes++;
					t[indice][conferencia - 1]++;
				} else {
					printf("Esta conferencia no tiene cupo.\n");
				}
			}
		} else {
			printf("Area no existente.\n");
		}
	}
}

//1. Decir para cada área temática qué conferencia tuvo menos asistentes y cuál la mayor
void mas_asistentes(int t[F][C]) {
	int i, j, max, conferencia;
	for (i = 0; i < F; i++) {
		max = -1;
		for (j = 0; j < C; j++) {
			if (t[i][j] > max) {
				max = t[i][j];
				conferencia = j + 1;
			}
		}
		
		printf("Area tematica %d\n", i + 1);
		printf("Conferencia con mayor cantidad de asistentes: %d\n", conferencia);
	}
	return;
}

void menos_asistentes(int t[F][C]) {
	int i, j, min, conferencia;
	for (i = 0; i < F; i++) {
		min = 99999999;
		for (j = 0; j < C; j++) {
			if (t[i][j] < min) {
				min = t[i][j];
				conferencia = j + 1;
			}
		}
		
		printf("Area tematica %d\n", i + 1);
		printf("Conferencia con menor cantidad de asistentes: %d\n", conferencia);
	}
	return;
}

//3. Indicar el nombre del área temática con menos inscriptos.
void area_menos_inscriptos(area a[F]) {
	int i, min = 9999, indice = -1;
	
	for (i = 0; i < F; i++) {
		if (a[i].cAsistentes < min) {
			min = a[i].cAsistentes;
			indice = i;
		}
	}
	
	printf("Area tematica con menos inscriptos: %s\n", a[indice].nArea);
	return;
}

//4. Dado un nombre de área temática decir cuál fue el promedio de inscriptos.
void promedio(int t[F][C], area a[F], char *elem) {
	int i, indice, acum = 0;
	
	indice = busqueda_x_area(a, elem);
	
	for(i = 0; i < F; i++) {
		acum += t[indice][i];
	}
	
	printf("Promedio de inscriptos al area tematica %s: %d", elem, (acum / C));
	return;
}

//5. Indicar la/s áreas temáticas que en algún turno tuvieron la sala completa, si las hubiera.
void sala_completa(int t[F][C], area a[F]) {
	int i, j;
	
	for (i = 0; i < F; i++) {
		for (j = 0; j < C; j++) {
			if (a[i].cupo == t[i][j]) {
				printf("Area tematica: %s", a[i].nArea);
				printf("Tuvo algun turno con sala completa.");
				break; //No es necesario verificar otras conferencias de este area
			}
		}
	}
	return;
}

int main () {
	area A[F];
	int tabla[F][C];
	char elemento[50];
	
	cereo(A, tabla);
	procesarInfo(A);
	carga(A, tabla);
	mas_asistentes(tabla);
	menos_asistentes(tabla);
	area_menos_inscriptos(A);
	
	printf("Ingrese un area tematica para saber el promedio de inscriptos: \n");
	fgets(elemento, 50, stdin);
	promedio(tabla, A, elemento);
	
	sala_completa(tabla, A);
}
