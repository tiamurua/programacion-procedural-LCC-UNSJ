//Programa 3:
#include <stdio.h>
#include <string.h>

/*Codificar una función que permita mostrar Número de Registro y Nombre de alumnos que aprobaron ambas materias.*/
typedef struct {
    char nombre[30];
    int registro;
    char nota;
} alumno;


void mostrar(FILE *xarchi1, FILE *xarchi2) {
    alumno a;
    alumno b;

    rewind(xarchi1);
    rewind(xarchi2);
    fread(&a, sizeof(a), 1, xarchi1);
    fread(&b, sizeof(b), 1, xarchi2);

    if (a.nota == 'A' && b.nota == 'A') {
        if (a.registro == b.registro) {
            printf("Registro: %d\n", a.registro);
            printf("Nombre: %s\n", a.nombre);
        } else if (xarchi1 > xarchi2) {
            fread(&b, sizeof(b), 1, xarchi2);
            if (a.registro == b.registro) {
                printf("Registro: %d\n", a.registro);
                printf("Nombre: %s\n", a.nombre);
            }
        }
    }
}

int main() {
    FILE *archi1;
    FILE *archi2;
    
    archi1 = fopen("alumnosAL.dat", "w+")) == NULL;
    archi2 = fopen("alumnosPP", "w+")) == NULL;
    

}
