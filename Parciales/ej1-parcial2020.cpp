/*Ejercicio 1
En un Instituto se dictará un curso de Desarrollador Web. Se 
registra la siguiente información de los inscriptos: Número de 
inscripción (es secuencial y comienza en 1), Nombre y Apellido, 
DNI, Domicilio, Numero de celular y Edad.
Codificar un programa en Lenguaje C que usando funciones 
óptimas permita:*/
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct {
    int n_inscripcion;
    char nom_ape[50];
    int dni;
    char domicilio[30];
    int n_celular;
    int edad;
} inscripto;

struct nodo {
    inscripto datos;
    struct nodo *sig;
};

typedef struct nodo *puntero;

/*a) Generar una lista con la información de los inscriptos.*/
void crear(puntero &c) {
    c = NULL;
    return;
}

void insertar(puntero &c) {
    puntero p, nuevo, anterior;
    int numero = 1;

    nuevo = (puntero) malloc (sizeof(struct nodo));

    nuevo->datos.n_inscripcion = numero++;

    printf("Ingrese Nombre y Apellido:\n");
    fflush(stdin);
    gets(nuevo->datos.nom_ape);

    printf("Ingrese DNI:\n");
    scanf("%d", &nuevo->datos.dni);

    printf("Ingrese Domicilio:\n");
    fflush(stdin);
    gets(nuevo->datos.domicilio);

    printf("Ingrese numero de celular:\n");
    scanf("%d", &nuevo->datos.n_celular);

    printf("Ingrese Edad:\n");
    scanf("%d", &nuevo->datos.edad);

    nuevo->sig = NULL;

    if (c == NULL) {
        c = nuevo;
    } else {
        p = c;

        while (p != NULL) {
            anterior = p;
            p = p->sig;
        }

        anterior->sig = nuevo;
    }
    return;
}

/*b) A partir de la lista generada, indicar en el main la 
cantidad de total de inscriptos y la cantidad de inscriptos 
mayores de 40 años. Realizar una función recursiva que 
devuelva los dos valores, uno a través del retorno y otro por 
parámetro.*/
int recorrer(puntero c, int &m40) {
    
    if (c != NULL) {
        if (c->datos.edad > 40) {
            m40++;
        } else {
            return 1 + recorrer(c->sig, m40);
        }
    } else {
        return 0;
    }
}

/*c) Generar y mostrar un arreglo dinámico con la información 
de los inscriptos mayores de 40 años.*/
void carga_arreglo(puntero c, inscripto xi[], int m40) {
    int i = 0;

    while (c != NULL) {
        if (c->datos.edad > 40) {
            xi[i] = c->datos;
            i++;
        }
        c = c->sig;
    }
}

void mostrar(inscripto xi[], int m40) {
    int i;

    for (i = 0; i < m40; i++) {
        printf("---------------------------------------------------\n");
        printf("Numero de inscripcion: %d\n", xi[i].n_inscripcion);
        printf("Nombre y apellido: %s\n", xi[i].nom_ape);
        printf("Domicilio: %s\n", xi[i].domicilio);
        printf("Numero de celular: %d\n", xi[i].n_celular);
        printf("Edad: %d\n", xi[i].edad);
    }
    return;
}

/*d) General un archivo con la información de los inscriptos, 
el archivo debe quedar ordenado ascendentemente por número de 
inscripción.*/
void cargar_archivo(FILE *xarchi, puntero cab) {
    inscripto ins;

    while (cab != NULL)
    {
        ins = cab->datos;

        fwrite(&ins, sizeof(ins), 1, xarchi);

        cab = cab->sig;
    }
}

int main() {
    puntero cabeza;
    int t_inscriptos = 0, max_40 = 0;
    inscripto *I;
    FILE *archi;

    crear(cabeza);
    insertar(cabeza);

    t_inscriptos = recorrer(cabeza, max_40);
    printf("Cantidad total de inscriptos: %d, Cantidad de inscriptos mayores de 40 años: %d\n", t_inscriptos, max_40);

    I = (inscripto*) malloc (max_40 * (sizeof(inscripto)));
    carga_arreglo(cabeza, I, max_40);
    free(I);
    
    if ((archi = fopen("inscriptos.dat", "w+")) == NULL) {
        printf("Hay error\n");
    } else {
        cargar_archivo(archi, cabeza);
        fclose(archi);
    }
}

