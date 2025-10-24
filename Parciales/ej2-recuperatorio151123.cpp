#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct {
    int cod;
    int c_inscriptos;
} materia;

typedef struct {
    int cod;
    char carrera[4];
} inscripto;

struct nodo {
    inscripto datos;
    struct nodo *sig;
};

typedef struct nodo *puntero;

void crear(puntero &c) {
    c = NULL;
}

void insertar(puntero &c) {
    puntero nuevo;

    if (c != NULL) {
        nuevo = (puntero) malloc (sizeof(struct nodo));

        printf("Ingrese el codigo de materia:\n");
        scanf("%d", &nuevo->datos.cod);

        printf("Ingrese carrera:\n");
        fflush(stdin);
        gets(nuevo->datos.carrera);

        nuevo->sig = c;
        c = nuevo;

        insertar(c->sig);
    }
}

void actualizar(FILE *a, puntero c) {
    materia i;
    while (c != NULL) {
        fseek(a, (c->datos.cod - 100) * sizeof(materia), SEEK_SET);
        fread(&i, sizeof(i), 1, a);

        i.c_inscriptos++;

        fseek(a, (c->datos.cod - 100) * sizeof(materia), SEEK_SET);
        fwrite(&i, sizeof(i), 1, a);

        c = c->sig;
    }
}

int main() {
    puntero cabeza;
    FILE *archivo;

    crear(cabeza);
    insertar(cabeza);

    if ((archivo = fopen("EXAMEN.dat", "w+")) == 0) {
        printf("Hay error\n");
    } else {
        actualizar(archivo, cabeza);
    }

}