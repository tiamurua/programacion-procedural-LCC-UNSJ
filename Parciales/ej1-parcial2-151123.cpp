/*Se tiene el archivo CLIENTES.dat con la informacion de las
personas que compraron paquetes turisticos para grupos
familiares. De cada uno se conoce Nombre y Apellido, Destino
y cantidad de personas del grupo familiar.
Hacer un programa en lenguaje C que usando funciones optimas
permita:*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nom_ape[30];
    char destino[20];
    int cant_personas;
} cliente;

/*Hacer un listado de los clientes con cantidad de personas
del grupo familiar mayor a 5.*/
void listar(FILE *a) {
    cliente c;

    rewind(a);
    fread(&c, sizeof(c), 1, a); //Lectura anticipada

    while (feof(a) == 0) {
        if (c.cant_personas >= 5) {
            printf("Nombre y Apellido: %s, Destino: %s, Cantidad de personas del grupo familiar: %d", c.nom_ape, c.destino, c.cant_personas);
        }
        fread(&c, sizeof(c), 1, a);
    }
}

/*Generar un arreglo dinamico con la informacion de los
clientes con cantidad de personas del grupo familiar igual a
2.*/
int contar(FILE *a) {
    cliente c;
    int cont = 0;

    rewind(a);
    fread(&c, sizeof(c), 1, a);

    while (feof(a) == 0) {
        if (c.cant_personas == 2) {
            cont++;
        }
        fread(&c, sizeof(c), 1, a);
    }
    return cont;
}

void carga_arreglo(cliente c[], FILE *a, int xc) {
    cliente b;
    int i = 0;

    rewind(a);
    fread(&b, sizeof(b), 1, a);
    while (feof(a) == 0) {
        if (b.cant_personas == 2) {
            c[i].cant_personas = b.cant_personas;
            strcpy(c[i].destino, b.destino);
            strcpy(c[i].nom_ape, b.nom_ape);

            i++;
        }
        fread(&b, sizeof(b), 1, a);
    }
}

/*A partir del arreglo generado decir el total de personas
que viajan a Mar del Plata. Resolver este item con funcion
recursiva*/
void mostrar(cliente c[], int xc, int i, int &a) {
    if (i < xc) {
        if (strcmp(c[i].destino, "Mar del Plata") == 0) {
            a += c[i].cant_personas;
        }
        mostrar(c, xc, i+1, a);
    }
    return;
}
int main() {
    FILE *archi;
    int cantidad, acum = 0;
    cliente *C;

    if ((archi = fopen("CLIENTES.dat", "w+")) == NULL) {
        printf("Hay ERROR\n");
    } else {
        listar(archi);

        cantidad = contar(archi);
        C = (cliente*) malloc (cantidad * sizeof(cliente));
        carga_arreglo(C, archi, cantidad);

        mostrar(C, cantidad, 0, acum);
        printf("Total de personas que viajan a Mar del Plata.");

        fclose(archi);
        free(C);
    }
}