/*Una agencia de empleo registra datos de postulantes a un
puesto de trabajo. De cada uno registra nombre, dni, sexo,
edad y codigo de localidad donde vive (1...19).
Se pide que usando funciones para cada item, resuelva lo
siguiente:*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char nombre[30];
    int dni;
    char sexo[20];
    int edad;
    int cod_localidad;
} postulante;

/*a)Ingresar una cantidad de postulantes y generar un arreglo
dinamico para almacenar los datos de cada uno.*/
void cargar(postulante p[], int c) {
    int i;

    for (i = 0; i < c; i++) {
        printf("Ingrese el nombre del postulante:\n");
        fflush(stdin);
        gets(p[i].nombre);

        printf("Ingrese DNI:\n");
        scanf("%d", &p[i].dni);

        printf("Ingrese sexo del postulante:\n");
        fflush(stdin);
        gets(p[i].sexo);

        printf("Ingrese edad:\n");
        scanf("%d", &p[i].edad);

        printf("Ingrese codigo de localidad (1 ... 19):\n");
        scanf("%d", &p[i].cod_localidad);
    }
    return;
}

/*Decir cuantos postulantes varones viven en la localidad 3
y 16 (hacer una funcion que devuelva amboss resultados).*/
int contadores(postulante p[], int c, int &c16) {
    int cont = 0, i;

    for (i = 0; i < c; i++) {
        if (strcmp(p[i].sexo, "Masculino") == 0) {
            if (p[i].cod_localidad == 3) {
                cont++;
            } else if (p[i].cod_localidad == 16) {
                c16++;
            }
        }
    }
    return cont;
}

//c)Indicar la edad promedio de los varones.
int edad_promedio(postulante p[], int c) {
    int i, cont = 0, acum = 0;

    for (i = 0; i < c; i++) {
        if (strcmp(p[i].sexo, "Masculino") == 0) {
            cont++;
            acum += p[i].edad;
        }
    }
    return acum / cont;
}

/*d)Mostrar los nombres de los postulantes y el dni de
quienes viven en la localidad 10 (hacer una funcion
recursiva)*/
void incisoD(postulante p[], int c, int i) {
    if (i < c) {
        if (p[i].cod_localidad == 10) {
            printf("Nombre: %s, DNI: %d\n", p[i].nombre, p[i].dni);
        }
        incisoD(p, c, i+1);
    }
}

int main() {
    postulante *P;
    int cantidad, cont3 = 0, cont16 = 0;

    //a
    printf("Ingrese cantidad de postulantes:\n");
    scanf("%d", &cantidad);
    P = (postulante*) malloc (cantidad * sizeof(postulante));
    cargar(P, cantidad);

    //b
    cont3 = contadores(P, cantidad, cont16);
    printf("Cantidad de postulantes varones que viven en la localidad 3: %d", cont3);
    printf("Cantidad de postulantes varones que viven en la localidad 16: %d", cont16);

    //c
    printf("Edad promedio de los varones: %d", edad_promedio(P, cantidad));

    //d
    printf("Nombres y DNI de postulantes que viven en la localidd 10:\n");
    incisoD(P, cantidad, 0);

    free(P);
}