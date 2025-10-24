/*Ejercicio 1
Almacenar la información de los asistentes a unas jornadas de capacitación, de cada asistente se conoce su nombre y edad.
Utilizando funciones óptimas realice lo siguiente:*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nombre[30];
    int edad;
} asistente;

//a)Genere un archivo de acceso secuencial con la información de los asistentes a las jornadas.
void cargar(FILE *archi) {
    asistente a;

    printf("Ingrese el nombre del alumno (termina con FIN):\n");
    fflush(stdin);
    gets(a.nombre);

    while (strcmp((a.nombre), "FIN")) {
        printf("Ingrese la edad del asistente:\n");
        scanf("%d", &a.edad);

        fwrite(&a, sizeof(a), 1, archi);

        printf("Ingrese el nombre del alumno (termina con FIN):\n");
        fflush(stdin);
        gets(a.nombre);
    }
}

//b)Muestre los nombres de los asistentes mayores de 40 años.
void mostrar(FILE *xarchi) {
    asistente a;

    rewind(xarchi);
    fread(&a, sizeof(a), 1, xarchi);

    while (feof(xarchi)==0)
    {
        if (a.edad > 40) {
            printf("Nombre del asistente: %s\n", a.nombre);
            fread(&a, sizeof(a), 1, xarchi);
        }
    }
    return;
}

//c)Indique en el principal la edad promedio.
float promedio(FILE *xarchi) {
    asistente a;
    int acum = 0, cont = 0;
    rewind(xarchi);
    fread(&a, sizeof(a), 1, xarchi);

    while (feof(xarchi) == 0) { //Si es 0 -> NO LLEGUE AL FINAL
        acum += a.edad;
        cont++;

        fread(&a, sizeof(a), 1, xarchi);
    }

    return acum / cont;
}

int main() {
    FILE *archi;
    archi = fopen("jornada.dat", "w+");
    float prom;

    cargar(archi);
    mostrar(archi);
    prom = promedio(archi);
    printf("Edad promedio: %.1f", prom);
    fclose(archi);
}


