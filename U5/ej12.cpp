/*Ejercicio 12
Una empresa de desarrollo software relacionado a la música 
cuenta con un servicio de listas de reproducción. Las mismas 
son creadas por cada uno de sus usuarios. De cada una se 
conoce el nombre y la duración en horas. De cada canción se 
conoce el nombre de la lista a la que pertenece, autor y 
nombre, género y duración.
Realiza un programa que permita:*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

/*a)Generar una estructura adecuada para cada una de las 
listas como también las canciones que va a contener cada una 
de ellas.*/
typedef struct cancion {
    char playlist[30];
    char autor[20];
    char nombre[30];
    char genero[20];
    float duracion;
} cancion;

struct nodo {
    cancion dato;
    struct nodo *sig;
};

typedef struct nodo *puntero;

typedef struct playlist {
    char nombre[30];
    float duracion;
    puntero cabeza;
} playlist;

/*b) Ingresar los datos correspondientes a cada una de las 
listas de reproducción.*/
void crear_playlist(playlist p[], int xc) {
    int i;

    for (i = 0; i < xc; i++) {
        p[i].cabeza = NULL;
    }
    return;
}

void cargar_playlist(playlist p[], int xc, int i) {
    char nom[30];
    if (i < xc) {
        printf("Ingrese nombre de la playlist:\n");
        fflush(stdin);
        gets(p[i].nombre);

        p[i].duracion = 0;

        cargar_playlist(p, xc, i+1);
    }
    return;
}

/*c)Registrar el ingreso de las distintas canciones, el mismo 
no cuenta con un orden especifico.*/
void insertar_cancion(puntero_playlist cp, int c) {
    char nom[30];
    int i;

    printf("Ingrese nombre de la cancion (FIN para salir):\n");
    fflush(stdin);
    gets(nom);
    while (strcmp(nom, "FIN") != 0) {
        puntero p, nuevo, anterior;

        nuevo = (puntero)malloc(sizeof(struct nodo));

        printf("Ingrese nombre de la playlist a la que pertenece:\n");
        fflush(stdin);
        gets(nuevo->dato.playlist);

        printf("Ingrese autor:\n");
        fflush(stdin);
        gets(nuevo->dato.autor);

        strcpy(nuevo->dato.nombre, nom);

        printf("Ingrese genero:\n");
        fflush(stdin);
        gets(nuevo->dato.genero);

        printf("Ingrese duracion en minutos:\n");
        scanf("%f", &nuevo->dato.duracion);
        nuevo->dato.duracion /= 60;

        for (i = 0; i < c; i++) {
            if (strcmp(cp[i].nombre, nuevo->dato.playlist) == 0) {
                cp[i].duracion += nuevo->dato.duracion;
            }
        }

        nuevo->sig = NULL;
        if (cp[])

    }
    puntero_cancion nueva_cancion;
    

    nueva_cancion = (puntero_cancion)malloc(sizeof(struct nodo_cancion));
    
    printf("Ingrese nombre de la playlist");
    fflush(stdin);
    gets(n_playlist);

    if ((cp != NULL) && (strcmp(cp->dato.nombre, n_playlist) == 0)) {
        strcpy(nueva_cancion->dato.playlist, n_playlist);

        printf("Ingrese nombre del autor:\n");
        fflush(stdin);
        gets(nueva_cancion->dato.autor);

        printf("Ingrese el nombre de la cancion:\n");
        fflush(stdin);
        gets(nueva_cancion->dato.nombre);

        printf("Ingrese el genero de la cancion:\n");
        fflush(stdin);
        gets(nueva_cancion->dato.genero);

        printf("Ingrese la duracion de la cancion en minutos:\n");
        scanf("%d", &nueva_cancion->dato.duracion);
        nueva_cancion->dato.duracion /= 60;

        nueva_cancion->sig = cp->dato.cabeza;
        cp->dato.cabeza = nueva_cancion;

        cp->dato.duracion += nueva_cancion->dato.duracion;
        printf("Cancion agregada a %s. Duracion total: %.2f horas\n", cp->dato.nombre, cp->dato.duracion);
    } else {
        printf("Playlist no encontrado.\n");
    }
}

/*d)Dado un nombre y autor ingresado por el usuario realizar 
la eliminación de dicha canción de la lista correspondiente.*/
void eliminar_cancion(puntero_playlist &cp, char *nc, char *a) {
    puntero_playlist p;
    puntero_cancion actual = cp->dato.cabeza, anterior;

    if (strcmp(actual->dato.nombre, nc) == 0 && strcmp(actual->dato.autor, a) == 0) {
        if (anterior == NULL) { //Primera cancion de la lista
            cp->dato.cabeza = actual->sig;
        } else {
            anterior->sig = actual->sig;
        }
        
        cp->dato.duracion -= actual->dato.duracion; //Actualizar duracion de la playlist
        free(actual);
        printf("Cancion %s de %s eliminada.\n");
        return;
    } 
    anterior = actual;
    actual = actual->sig;
}
cp = cp->

/*e)Generar una nueva lista de reproducción llamada “Rock 
alternativo” y guardar todas aquellas canciones de las listas 
existentes cuyo genero sea “Rock alternativo”.*/
void generar_playlist_rock_nacional(puntero_playlist &cp, char *np) {
    puntero_playlist nuevo;
    puntero_cancion nueva_cancion;

    crear_playlist(cp);
    
    nuevo = (puntero_playlist) malloc (sizeof(struct nodo_playlist));

    strcpy(nuevo->dato.nombre, np);
    nuevo->dato.duracion = 0;
    nuevo->dato.cabeza = NULL;
    nuevo->sig = NULL;

    while (cp != NULL) {
        puntero_cancion nueva = cp->dato.cabeza;

        while (nueva != NULL) {
            if (strcmp(nueva->dato.genero, "Rock Nacional") == 0) {
                nueva_cancion = (puntero_cancion) malloc (sizeof(struct nodo_cancion));
                nueva_cancion = nueva;
                nueva_cancion->sig = nuevo->dato.cabeza;
                nuevo->dato.cabeza = nueva_cancion;
                nuevo->dato.duracion += nueva_cancion->dato.duracion / 60;
            }
            nueva = nueva->sig;
        }
        cp = cp->sig;
    }
}

int main() {
    playlist *P;
    int cant, i;
    char nom[30];

    printf("Ingrese cantidad de playlist:\n");
    scanf("%d", &cant);

    P = (playlist*)malloc(cant * sizeof(playlist));

    crear_playlist(P, cant);
    cargar_playlist(P, cant, 0);

    insertar_cancion(P, cant);
    while (strcmp(nom, "FIN") !=) {
        insertar_cancion(P);
    }
    
    char nombre_cancion[30], autor[20], nombre_playlist[30];

    
    
    

    

    printf("Ingrese un nombre de cancion:\n");
    fflush(stdin);
    gets(nombre_cancion);
    printf("Ingrese un autor:\n");
    fflush(stdin);
    gets(autor);
    eliminar_cancion(cabeza_playlist, nombre_cancion, autor);

    printf("Ingrese nombre de la playlist:\n");
    fflush(stdin);
    gets(nombre_playlist);
    generar_playlist_rock_nacional(cabeza_playlist, nombre_playlist);
}

f)
Mostrar la lista generada usando una función recursiva.