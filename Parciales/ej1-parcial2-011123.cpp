/*Una casa de comercio procesa las ventas realizadas en el
ultimo feriado. De cada venta se conoce importe de venta y
numero de caja (1...5).
Hacer un programa en lenguaje C que usando funciones optimas
permita:*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float importe;
    int caja;
} venta;

/*a)Ingresar la cantidad de ventas realizadas y generar un
arreglo dinamico con la informacion de las mismas.*/
void cargar_ventas(venta v[], int c) {
    int i;

    for (i = 0; i < c; i++) {
        printf("Ingrese importe de venta:\n");
        scanf("%f", &v[i].importe);

        printf("Ingrese numero de caja:\n");
        scanf("%d", &v[i].caja);
    }
    return;
}

/*b)Decir el importe promedio de las ventas. Resolver este
item con al menos 1 funcion recursiva.*/
float acumulador(venta v[], int c, int i) {
    if (i >= c) {
        return 0;
    }
    return v[i].importe + acumulador(v, c, i+1);
}

/*c)Generar un archivo Ventas.dat que almacene las ventas
de las cajas 4 y 5*/
void cargar(FILE *xarchi, venta v[], int c) {
    venta a;
    int i;

    for (i = 0; i < c; i++) {
        if (v[i].caja == 4 || v[i].caja == 5) {
            a.caja = v[i].caja;
            a.importe = v[i].importe;

            fwrite(&a, sizeof(a), 1, xarchi);
        }
    }
}

int main() {
    venta *V;
    int cantidad;
    float importe_total;
    FILE *archi;

    //a)
    printf("Ingrese cantidad de ventas:\n");
    scanf("%d", &cantidad);
    V = (venta*) malloc (cantidad * sizeof(venta));
    cargar_ventas(V, cantidad);

    //b)
    importe_total = acumulador(V, cantidad, 0);
    printf("El importe promedio de las ventas es de: %.2f\n", importe_total / cantidad);

    //c)
    if ((archi = fopen("Ventas.dat", "w+")) == NULL) {
        printf("Hay error\n");
    } else {
        cargar(archi, V, cantidad);
        fclose(archi);
    }

    free(V);
}