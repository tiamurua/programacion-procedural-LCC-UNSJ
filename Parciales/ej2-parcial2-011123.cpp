/*Se tiene el archivo CONFERENCIA.dat con la informacion de
las conferencias que se daran en un congreso. De cada
conferencia se conoce: codigo (a partir de 100), nombre y 
cantidad de asistentes. El archivo esta ordenado por codigo
y permite su acceso directo.
Por otro lado se registran nuevos inscriptos en las
distintas conferencias. De cada inscripto se registra:
codigo de conferencia.
Hacer un programa en lenguaje C que usando funciones
optimas permita:*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int cod;
    char nombre[30];
    int c_asistentes;
} conferencia;

struct nodo {
    int n_conferencia;
    struct nodo *sig;
};

typedef struct nodo *puntero;

/*a)Generar una lista implementada con punteros, que
almacene por cada inscripto, el codigo de conferenica.
Hacerlo con una funcion recursiva.*/
void crear(puntero &c) {
    c = NULL;
    return;
}

void insertar(puntero &c) {
    puntero nuevo;

    if (c != NULL) {
        nuevo = (puntero) malloc (sizeof(struct nodo));
        printf("Ingrese numero de conferencia\n");
        scanf("%d", &nuevo->n_conferencia);
        nuevo->sig = c;
        c = nuevo;

        insertar(c->sig);
    }
}

/*b)Con la informacion contenida en la lista actualizar el
archivo*/
void actualizar(FILE *xarchi, puntero c) {
    conferencia a;
    int cont = 1; //Se empieza contando el nodo actual
    
    while (c != NULL) {
        //Si el siguiente nodo es igual al actual, se incrementa el contador
        if (c->sig != NULL && c->n_conferencia == c->sig->n_conferencia) {
            cont++;//No es necesario, ya tengo el codigo y puedo aceder directamente
        } else {
            //Posiciona en el archivo buscando el codigo de conferencia
            rewind(xarchi); //Asegura que empiece desde el inicio en cada busqueda
            while (fread(&a, sizeof(conferencia), 1, xarchi) == 1) {
                if (a.cod == c->n_conferencia) {
                    //Actualiza los asistentes en el registro correspondiente
                    a.c_asistentes += cont;
                    fseek(xarchi, -sizeof(conferencia), SEEK_CUR); //Vuelve al inicio del registro
                    fwrite(&a, sizeof(conferencia), 1, xarchi);
                }
            }
            cont = 1; //Reinicia el contador para el proximo codigo de conferencia
        }
        c = c->sig; //Avanza al siguiente nodo de la lista
    }
}

int main() {
    puntero cabeza;
    FILE *archi;
    
    crear(cabeza);
    insertar(cabeza);

    if ((fopen("CONFERENCIA.dat", "r+b")) == NULL) {
        printf("ERROR\n");
    } else {
        actualizar(archi, cabeza);
        fclose(archi);
    }
}