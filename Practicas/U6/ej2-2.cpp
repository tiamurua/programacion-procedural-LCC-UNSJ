//Programa 2:
#include <stdio.h>
#include <string.h>

/*a)Generar un archivo alumnosAL.dat que contiene la siguiente información correspondiente a los alumnos que cursan la materia 
Algebra Lineal: Nombre, Numero de Registro y Resultado de un parcial (‘A’: Aprobado – ‘R’: Reprobado). El archivo debe estar 
ordenado por Número de Registro.*/
typedef struct {
    char nombre[30];
    int registro;
    char nota;
} alumno;

void carga(FILE *xarchi) {
    alumno a;

    printf("Ingrese numero de registro (0 para terminar):\n");
    scanf("%d", &a.registro);

    while (a.registro != 0) {
        printf("Ingrese nombre del alumno:\n");
        fflush(stdin);
        gets(a.nombre);

        fwrite(&a, sizeof(a), 1, xarchi);

        printf("Ingrese nota del alumno (A: aprobado - R:reprobado\n");
        a.nota = getchar();
    }
}

//b)Codificar una función que permita mostrar la información de cada uno de los alumnos.
void mostrar(FILE *xarchi) {
    alumno a;

    rewind(xarchi);
    fread(&a, sizeof(a), 1, xarchi);

    printf("Informacion de alumnos");
    while (feof(xarchi)==0)
    {
        printf("Nombre: %s\n", a.nombre);
        printf("Registro: %d\n", a.registro);
        printf("Nota: %c\n", a.nota);

        fread(&a, sizeof(a), 1, xarchi);
    }
    return;
}

int main() {
    FILE *archi;
    if ((archi = fopen("alumnosAL.dat", "w+")) == NULL) {
        printf("Hay error!\n");
    } else {
        carga(archi);
        mostrar(archi);
        fclose(archi);
    }
}