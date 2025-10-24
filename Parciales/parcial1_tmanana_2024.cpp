#include <stdio.h>
#include <string.h>
#define N 3 //para prueba, deberia ser 50
#define M 15

typedef struct {
    int numero;
    char nombre[50];
    int precio_alquiler;
    char estado;
} herramienta;

void cargar_herramientas(herramienta h[N]) {
    int i;

    for (i=0; i<N; i++) {
        printf("Ingrese el numero de herramienta: \n");
        scanf("%d", &h[i].numero);
        printf("Ingrese nombre: \n");
        scanf("%s", h[i].nombre);
        printf("Ingrese precio de alquiler: \n");
        scanf("%d", &h[i].precio_alquiler);
        printf("Ingrese estado (S: alquilada / N: no alquilada): \n");
        scanf(" %c", &h[i].estado);
    }
    return;
}

void cereo(int a[N][M]) {
    int i, j;

    for (i=0; i<N; i++) {
        for (j=0; j<M; j++) {
            a[i][j] = 0;
        }
    }
    return;
}

void carga_tabla(herramienta h[N], int a[N][M]) {
    int num, dia, cant_horas;

    printf("Ingrese numero de herramienta (0 para salir): \n");
    scanf("%d", &num);
    while (num != 0) {
        printf("Ingrese dia: \n");
        scanf("%d", &dia);
        printf("Ingrese cantidad de horas de alquiler: \n");
        scanf("%d", &cant_horas);

        if (h[num-1].estado == 'N') {
            h[num-1].estado = 'S';
            a[num-1][dia-1] += cant_horas;
        } else {
            printf("La herramienta ya se encuentra alquilada.");
        }

        printf("Ingrese numero de herramienta (0 para salir): \n");
        scanf("%d", &num);
    }
    return;
}

void listar(herramienta h[N], int n, int i) {
    if (i==0) {
        printf("Numero | Nombre | Precio de alquiler | Estado de alquiler");
        printf("----------------------------------------------------------\n");
    }
    if (i < n) {
        printf("%d | %s | %d | %c\n", h[i].numero, h[i].nombre, h[i].precio_alquiler, h[i].estado);
        listar(h, n, i+1);
    }
}

void procesar_tabla(herramienta h[N], int a[N][M]) {
    int num, i, acum;

    acum = 0;
    printf("Ingrese un numero de herramienta:\n");
    scanf("%d", &num);
    for (i=0; i<M; i++) {
        acum += a[num-1][i];
    }
    printf("Cantidad total de horas alquiladas: %d\n", acum);
    printf("Importe total a cobrar: $%d", acum * h[num-1].precio_alquiler);
}

void alquiladas(herramienta h[N], int a[N][M], int *ca, int *ah) {
    int dia, i;
    printf("Ingrese un numero de dia: \n");
    scanf("%d", &dia);
    for (i=0; i<N; i++) {
        if (a[i][dia-1] > 0) { //esa herramienta se alquilo ese dia
            (*ca) ++;
            (*ah) += a[i][dia-1];
        }
    }
}

void inciso_5(int a[N][M]) {
    int acum, i, j;

    acum = 0;

    for (i=0; i<N; i++) {
        for (j=0; j<M; j++) {
            acum += a[i][j];
        }
    }
    printf("Total de horas de alquiler en la quincena: %d", acum);
    return;
}

int main() {
    herramienta H[N];
    int A[N][M], cont_alquiladas, acum_horas;

    cont_alquiladas = 0;
    acum_horas = 0;

    cargar_herramientas(H);
    cereo(A);
    carga_tabla(H, A);
    listar(H, N, 0);
    procesar_tabla(H, A);
    alquiladas(H, A, &cont_alquiladas, &acum_horas);
    printf("Cantidad de herraientas alquiladas: %d", cont_alquiladas);
    printf("Cantidad de horas de alquiler: %d", acum_horas);

    inciso_5(A);
}