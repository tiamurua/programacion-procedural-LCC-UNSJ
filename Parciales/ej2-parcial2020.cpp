/*Ejercicio 3
Una Agencia de Turismo posee la siguiente información de 
circuitos turísticos en un archivo “Circuitos.dat” (cuya 
estructura de registro es: código de circuito, código de guía 
turístico, tiempo del recorrido, precio). También tiene la 
información de los guías turísticos un archivo “Guias.dat” 
(cuya estructura de registro es: código de guía turístico, 
nombre y apellido, número de celular)
Las funcionalidades para un sistema que requiere son:*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int cod_circuito;
    int cod_guia;
    int tiemp_recorrido;
    float precio;
} circuito;

typedef struct {
    int cod_guia;
    char nom_ape[30];
    int n_celular;
} guia;

/*Altas, bajas, modificaciones y listado del archivo 
“Circuitos.dat”*/
//Alta del circuito
void alta_circuitos(FILE *xarchi) {
    circuito c;
    
    printf("Ingrese codigo del circuito (0 para terminar):\n");
    scanf("%d", &c.cod_circuito);
    while (c.cod_circuito != 0) {
        printf("Ingrese codigo del guia");
        scanf("%d", &c.cod_guia);

        printf("Ingrese tiempo del recorrido en horas:\n");
        scanf("%d", &c.tiemp_recorrido);

        printf("Ingrese precio:\n");
        scanf("%f", &c.precio);

        fwrite(&c, sizeof(c), 1, xarchi);

        printf("Ingrese codigo del circuito (0 para terminar):\n");
        scanf("%d", &c.cod_circuito);
    }
}

//Baja de un circuito
void baja_circuito(FILE *xarchi, FILE *xaux) {
    circuito c;
    int cod;

    printf("Ingrese codigo del cicuito a eliminar:\n");
    scanf("%d", &cod);

    fseek(xarchi, 0, SEEK_SET);
    fread(&c, sizeof(c), 1, xarchi);

    while (!feof(xarchi)) {
        if (c.cod_circuito == cod) {
            fwrite(&c, sizeof(c), 1, xaux);
            fread(&c, sizeof(c), 1, xarchi);
        }
    }
}

//Modificacion
void modificacion(FILE * xarchi, int xcod) {
    circuito c;
    fpos_t x;

    rewind(xarchi);
    fread(&c, sizeof(c), 1, xarchi);
    while (!feof(xarchi) && (c.cod_circuito == xcod)) {
        fread(&c, sizeof(c), 1, xarchi);

        if (!feof(xarchi)) {
            printf("Codigo del circuito: %d\n", c.cod_circuito);
            printf("Codigo del guia: %d\n", c.cod_guia);
            printf("Tiempo de recorrido: %d\n", c.tiemp_recorrido);
            printf("Precio: %f\n", c.precio);

            printf("Ingrese el nuevo codigo del circuito:\n");
            scanf("%d", &c.cod_circuito);
            printf("Ingrese el nuevo codigo del guia:\n");
            scanf("%d", &c.cod_guia);
            printf("Ingrese el nuevo tiempo de recorrido:\n");
            scanf("%d", &c.tiemp_recorrido);
            printf("Ingrese el nuevo precio:\n");
            scanf("%d", &c.precio);

            fseek(xarchi, -sizeof(c), SEEK_CUR);
            fwrite(&c, sizeof(c), 1, xarchi);
            fclose(xarchi);
        }
    }
}

//Listar
void mostrar(FILE * xarchi) {
    circuito c;

    if ((xarchi == fopen("Circuito.dat", "rb")) == NULL) {
        printf("Error al abrir el archivo\n");
    } else {
        while (fread(&c, sizeof(c), 1, xarchi)) {
            printf("Codigo del circuito: %d, Codigo del guia: %d, Tiempo de recorrido: %d, Precio: %f", c.cod_circuito, c.cod_guia, c.tiemp_recorrido, c.precio);
        }
    }
}

int main() {
    FILE *archi, *archi2, *aux;
    int cod;

    archi = fopen("Circuitos.dat", "w+");
    archi2 = fopen("Guias.dat", "w+");

    alta_circuitos(archi);

    aux = fopen("aux.dat", "wb");
    baja_circuito(archi, aux);

    printf("Ingrese codigo de circuito para modificarlo:\n");
    scanf("%d", &cod);    
    modificacion(archi, cod);
}
 Altas, bajas, modificaciones y listado del archivo “Guias.dat”
 Listar para cada Circuito la Tiempo de recorrido, precio y nombre del guía.
 Ingresar un código de guía de turismo y hacer un listado que muestre los datos de cada circuito que acompaña, ordenado ascendentemente por precio de circuito.
Con esta información hacer tres módulos, indicar para cada uno la cohesión que tiene (explicar brevemente porque tiene la cohesión que señala) y también indicar el acoplamiento intermodular.