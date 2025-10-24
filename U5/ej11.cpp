/*Ejercicio 11
La biblioteca de la facultad cuenta con una cantidad variable 
de libros de Programación Procedural en calidad de préstamo 
en la sala de lectura que puede modificarse. Una vez 
prestados los libros, de los cuales se registra el código, se 
confecciona para cada uno una lista de alumnos que están en 
cola de espera. Por cada alumno se guarda: nombre y carrera 
(LSI, LCC)
Se pide realizar un programa, que a través de un menú de 
opciones y mediante el uso de funciones, de respuesta a las 
siguientes situaciones:*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct alumno {
    char nombre[30];
    char carrera[3];
} alumno;

struct nodo {
    alumno dato;
    struct nodo *sig;
};

typedef struct nodo *puntero_alumno;

typedef struct {
    int cod;
    puntero_alumno cabeza;
} libro;

struct nodoLibro {
    libro dato;
    struct nodoLibro *sig;
} nodoLibro;

typedef struct nodoLibro *puntero_libro;

/*a)Crear una lista de listas inicializadas en NULL. Para 
almacenar la información de los libros*/
void crear(puntero_libro &cb) {
    cb = NULL;
    return;
}

/*b)Para un código de libro solicitado, insertar un alumno a 
la cola de espera correspondiente. Usar una función 
recursiva.*/
void insertar_alumno(puntero_libro &cb, int cod) {
    if (cb != NULL) {
        if (cb->dato.cod == cod) {
            puntero_alumno nuevo = (puntero_alumno) malloc (sizeof(struct nodo));

            printf("Ingrese Nombre del alumno:\n");
            fflush(stdin);
            gets(nuevo->dato.nombre);
            printf("Ingrese Carrera del alumno:\n");
            fflush(stdin);
            gets(nuevo->dato.carrera);
            nuevo->sig = NULL;
        } else {
            insertar_alumno(cb->sig, cod);
        }
    }
    printf("Libro no encontrado.\n");
}

/*c)Ingresar un nuevo libro para que esté en calidad de 
préstamo en la biblioteca.*/
void insertar_biblioteca(puntero_libro &cb) {
    puntero_libro nuevo;
    int cod;

    printf("Ingrese codigo del libro:\n");
    scanf("%d", &cod);

    nuevo = (puntero_libro) malloc (sizeof(struct nodoLibro));

    nuevo->dato.cod = cod;
    nuevo->dato.cabeza = NULL;
    nuevo->sig = cb;
    cb = nuevo;

    printf("Libro agregado a la biblioteca.\n");
}

/*d)Suponiendo devuelto un libro cuyo código se lee, realizar 
un préstamo al primer alumno de la lista correspondiente y 
actualizar la misma (Esto es eliminarlo de la lista)*/
void prestar_libro(puntero_libro &cb, int xcod) {
    if (cb != NULL) {
        if (cb->dato.cod == xcod) {
            if (cb->dato.cabeza != NULL) {
                puntero_alumno primero = cb->dato.cabeza;
                printf("Prestando el libro al alumno:\n");
                printf("Nombre: %s\n", primero->dato.nombre);
                printf("Carrera: %s\n", primero->dato.carrera);

                cb->dato.cabeza = primero->sig;
                free(primero);

                printf("El alumno fue removido de la lista de espera.\n");
            } else {
                printf("No hay alumnos en la lista de espera para este libro.\n");
            }
        } else {
            prestar_libro(cb->sig, xcod);
        }
    } else {
        printf("Libro no encontrado en la biblioteca.\n");
    }
    return;
}

/*e)Ingresar un código de libro y una carrera, mostrar los 
nombres de los alumnos de dicha carrera que están en cola de 
espera.*/
void mostrar(puntero_libro cb, int xcod, char *xcarrera) {
    if (cb != NULL) {
        if (cb->dato.cod == xcod) {
            puntero_alumno actual = cb->dato.cabeza;
            printf("Alumnos de la carrera %s en cola de espera:\n");

            while (actual != NULL) {
                if (strcmp(actual->dato.carrera, xcarrera) == 0) {
                    printf("Nombre: %s\n", actual->dato.nombre);
                }
                actual = actual->sig;
            }
        } else {
            mostrar(cb->sig, xcod, xcarrera);
        }
    } else {
        printf("Libro no encontrado.\n");
    }
}


int main() {
    puntero_libro cabeza_biblioteca;
    int opcion, cod;
    char carrera[4];

    printf("\nMenu de opciones\n");
    printf("1. Opcion 1: Inicializar Biblioteca.\n");
    printf("2. Opcion 2: Agregar un nuevo libro.\n");
    printf("3. Opcion 3: Agregar un alumno a la cola de espera de un libro.\n");
    printf("4. Opcion 4: Prestar libro al primero de la lista de espera.\n");
    printf("5. Opcion 5: Mostrar alumnos en cola de espera de una carrera especifica.\n");
    printf("Ingrese una opcion:\n");
    scanf("%d", &opcion);
    
    
    switch (opcion)
    {
    case 1:
        //a)
        crear(cabeza_biblioteca);
        break;
    case 2:
        insertar_biblioteca(cabeza_biblioteca);
    case 3:
        //b
        printf("Ingrese el codigo del libro solicitado:\n");
        scanf("%d", &cod);
        insertar_alumno(cabeza_biblioteca, cod);
    case 4:
        //d
        printf("Ingrese codigo del libro para prestar:\n");
        scanf("%d", &cod);
        prestar_libro(cabeza_biblioteca, cod);
    case 5:
        //e
        printf("Ingrese un codigo de libro:\n");
        scanf("%d", &cod);
        printf("Ingrese una carrera:\n");
        fflush(stdin);
        gets(carrera);
        mostrar(cabeza_biblioteca, cod, carrera);
    case 0:
        printf("Saliendo...\n");
        break;
    default:
        printf("Opcion incorrecta. Intente nuevamente.\n");
        break;
    }
}
