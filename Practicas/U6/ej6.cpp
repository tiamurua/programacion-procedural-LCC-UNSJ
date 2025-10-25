/*Ejercicio 6
Una sala de cines procesa diariamente el archivo 
“TITULOS.DAT”. Este archivo almacena la información de cada 
película proyectada: Código de la película, Título, Director 
y Cantidad de personas que la vieron. El archivo está 
ordenado en forma secuencial por código a partir del numero 1.
Se pide realizar un programa óptimo que a través del uso de 
funciones genere un menú de opciones que responda a las 
siguientes solicitudes:*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>


typedef struct {
    int cod;
    char titulo[50];
    char director[30];
    int c_personas;
} pelicula;

void cargar(FILE *xarchi) {
    pelicula p;
    fpos_t x; //almacena la posicion del puntero expresada en bite

    printf("Ingrese titulo (termina con FIN):\n");
    fflush(stdin);
    gets(p.titulo);
    while(strcmp(p.titulo, "FIN") != 0) {
        fseek(xarchi, 0, SEEK_END);
        fgetpos(xarchi, &x);
        int cod = (int)(x/sizeof(pelicula)) + 1;

        printf("El codigo del nuevo titulo es %d", cod);
        p.cod = cod;

        printf("Ingrese el director de la pelicula:\n");
        fflush(stdin);
        gets(p.director);

        printf("Ingrese la cantidad de personas que vieron la pelicula:\n");
        scanf("%d", &p.c_personas);

        fwrite(&p, sizeof(p), 1, xarchi); //guardo un solo struct al archivo

        printf("Ingrese titulo (termina con FIN):\n");
        fflush(stdin);
        gets(p.titulo);
    }
}

/*a)Listar por cada película el título y la cantidad de 
personas que la vieron.*/
void mostrar(FILE *xarchi) {
    pelicula p;

    rewind(xarchi);
    while (fread(&p, sizeof(p), 1, xarchi)) {
        printf("Titulo de pelicula: %s, Cantidad de personas que la vieron: %d", p.titulo, p.c_personas);
    }
}

/*b)Dado el código de una película, mostrar el título y el 
director.*/
void mostrar2(FILE *xarchi, int pos) {
    pelicula p;

    rewind(xarchi);
    fseek(xarchi, pos * sizeof(pelicula), SEEK_SET);
    fread(&p, sizeof(p), 1, xarchi);

    printf("Titulo de la pelicula: %s, Director: %s\n", p.titulo, p.director);
}

/*c)Ingresar un titulo por teclado y mostrar el código y 
director.*/
void buscar(FILE *xarchi, char *xt) {
    pelicula p;
    int b = 0;

    rewind(xarchi);
    fread(&p, sizeof(p), 1, xarchi);
    while ((!feof(xarchi)) && (b == 0)) 
    {
        if (strcmp(p.titulo, xt) == 0) {
            printf("Codigo: %d, Director: %s\n", p.cod, p.director);
            b = 1;
        } else {
            fread(&p, sizeof(p), 1, xarchi);
        }
    }
    if (b == 0) {
        printf("Pelicula no encontrada.\n");
        getch();
    }
}

/*d)Genere un nuevo archivo con la información de las películas 
que fueron vistas por más de 1000 personas.*/
void carga_subarchivo(FILE *xarchi, FILE *xarchi2) {
    pelicula p;
    rewind(xarchi);
    while (fread(&p, sizeof(p), 1, xarchi)) {
        if (p.c_personas > 1000) {
            fwrite(&p, sizeof(p), 1, xarchi2);
        }
    }
}


int main() {
    FILE *archi, *archi2;
    int cod;
    char titulo[50];

    if ((archi = fopen("TITULOS.dat", "w+")) == NULL) {
        printf("Hay error!\n");
    } else {
        cargar(archi);
        //a
        mostrar(archi);
        //b
        printf("Ingrese un codigo:\n");
        scanf("%d", &cod);
        mostrar2(archi, cod);
        //c
        printf("Ingrese un titulo de pelicula:\n");
        fflush(stdin);
        gets(titulo);
        buscar(archi, titulo);
        //d
        archi2 = fopen("subTITULOS.dat", "w+");
        carga_subarchivo(archi, archi2);
    }
}

e)
Dado un código de película, modificar la cantidad de personas que la vieron.