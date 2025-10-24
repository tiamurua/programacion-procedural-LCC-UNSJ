/*Ejercicio 2
Se cuenta con información de los socios de un club 
provincial: DNI, edad, tipo y estado: “Activo “ o 
“Inactivo”. 

Los tipos de socios están determinados por letras: 
‘A’: Socio deportivo, …, ‘J’: Socio Jubilado.
 
La cantidad de socios se ingresa por teclado.

Escribir un programa en C que permita:*/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

typedef struct {
	int dni;
	int edad;
	char tipo;
	char estado[8];
} socio;

/*a) Cargar los datos en una estructura adecuada. 
(Validar el ingreso, suponiendo que el tipo de socio 
varía entre ‘A’ y ‘J ‘)*/
void carga(socio s[], int cs, int i) {
	if (i < cs) {
		printf("Ingrese DNI del socio:\n");
		scanf("%d", &s[i].dni);
		printf("Ingrese edad del socio:\n");
		scanf("%d", &s[i].edad);
		printf("Ingrese tipo de socio (letra de la 'A' a la 'J'):\n");
		scanf("%c", &s[i].tipo);
		printf("Ingrese estado del socio ('Activo' o 'Inactivo'):\n");
		gets(s[i].estado);
		carga(s, cs, i + 1);
	}
	return;
}

/*b) Para un tipo de socio determinado, mostrar los 
DNI de los socios que tienen edad mayor a 40. Generar 
una estructura auxiliar.*/
int carga_subarreglo(socio s[], int ss[], char tipo, int cs) {
	int i, c = 0;
	
	for (i = 0; i < cs; i++) {
		if (s[i].tipo == tipo && s[i].edad > 40) {
			ss[c] = s[i].dni;
			c++;
		}
	}
	return c;
}

void mostrar(int ss[], int cs) {
	int i;
	
	for (i = 0; i < cs; i++) {
		printf("%d\n", ss[i]);
	}
	return;
}

/*c) Realizar un listado que muestre, cuantas personas 
se encuentran activas, para cada tipo de socio. 
Generar una estructura auxiliar.*/
void cereo(int a[10]) {
	int i;
	for (i = 0; i < 10; i++) {
		a[i] = 0;
	}
	return;
}

void contar_activos(socio s[], int a[10], int cs) {
	int i;
	
	for (i = 0; i < cs; i++) {
		if (strcmp(s[i].estado, "Activo") == 0) {
			a[s[i].tipo - 'A']++;
		}
	}
	return;
}

void mostrar_activos(int a[10]) {
	char tipo;
	
	for (tipo = 'A'; tipo <= 'J'; tipo++) {
		printf("Tipo %c: %d socios activos\n", tipo, a[tipo - 'A']);
	}
	return;
}

int main() {
	socio *S;
	int cSocios, *SS, cSubarreglo, activos[10];
	char tipo;
	
	printf("Ingrese la cantidad de socios:\n");
	scanf("%d", &cSocios);
	
	S = (socio*)malloc(cSocios * sizeof(socio));
	carga(S, cSocios, 0);
	
	SS = (int*)malloc(cSocios * sizeof(int));
	
	printf("Ingrese un tipo de socio:\n");
	scanf(" %c", &tipo);
	
	cSubarreglo = carga_subarreglo(S, SS, tipo, cSocios);
	
	if (cSubarreglo != 0) {
		printf("DNI de los socios del tipo %c que tienen edad mayor a 40:\n", tipo);
		mostrar(SS, cSubarreglo);
	} else {
		printf("Ningun socio de tipo %c tiene mas de 40 años.\n", tipo);
	}
	
	cereo(activos);
	contar_activos(S, activos, cSocios);
	mostrar_activos(activos);
	
	free(S);
	free(SS);
}
