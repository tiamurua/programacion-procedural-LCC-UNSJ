/*Ejercicio 2
Se cuenta con información de los socios de un club provincial: DNI, edad, tipo y estado: “Activo “o “Inactivo”. 
Los tipos de socios están determinados por letras: ‘A’: Socio deportivo, …, ‘J’: Socio Jubilado. La cantidad de 
socios se ingresa por teclado.
Escribir un programa en C que permita:*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct socio {
    int dni;
    int edad;
    char tipo;
    char estado[8];
} socio;

//a)Cargar los datos en una estructura adecuada. (Validar el ingreso, suponiendo que el tipo de socio varía entre ‘A’ y ‘J‘)
void carga(socio s[], int cs, int i) {
    if (i < cs) {
        char ts;
        printf("Ingrese tipo de socio (letra entre 'A' y 'J'):\n");
        scanf(" %c", &ts);

        if (ts >= 'A' && ts <= 'J') {
            s[i].tipo = ts;
            printf("Ingrese DNI del socio:\n");
            scanf("%d", &s[i].dni);
            printf("Ingrese edad del socio:\n");
            scanf("%d", &s[i].edad);
            printf("Ingrese estado del socio (Activo o Inactivo):\n");
            scanf("%s", s[i].estado);

            carga(s, cs, i + 1);
        } else {
            printf("Tipo de socio invalido. Intente nuevamente\n");
            carga(s, cs, i + 1);
        }   
    }
    return;
}

//b)Para un tipo de socio determinado, mostrar los DNI de los socios que tienen edad mayor a 40. Generar una estructura auxiliar.
void carga_dni(socio s[], int **dnis, int cs, int *tam) {
    int i, cont = 0;

    for (i = 0; i < cs; i++) {
        if (s[i].edad > 40) {
            cont++;
        }
    }

    *dnis = (int*) malloc (cont * sizeof(int));

    *tam = cont;

    cont = 0;

    for (i = 0; i < cs; i++) {
        if (s[i].edad > 40) {
            (*dnis)[cont] = s[i].dni;
            cont++;
        }
    }
    return;
}

//c)Realizar un listado que muestre, cuantas personas se encuentran activas, para cada tipo de socio. Generar una estructura auxiliar.
void cereo(int a[10]) {
    int i;

    for (i = 0; i < 10; i++) {
        a[i] = 0;
    }
    return;
}

void carga_activos(socio s[], int a[10], int cs) {
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
    int i, cant_socios, *DNIs = NULL, tam_dnis = 0, activos[10];

    printf("Ingrese cantidad de socios:\n");
    scanf("%d", &cant_socios);

    S = (socio*) malloc (cant_socios * sizeof(socio));

    carga(S, cant_socios, 0);

    carga_dni(S, &DNIs, cant_socios, &tam_dnis);
    printf("DNI de los socios con edad mayor a 40:\n");
    for (i = 0; i < tam_dnis; i++) {
        printf("%d ", DNIs[i]);
    }
    printf("\n");

    cereo(activos);
    carga_activos(S, activos, cant_socios);
    printf("Cantidad de socios activos por tipo:\n");
    mostrar_activos(activos);

    free(S);
}