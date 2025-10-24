#include <stdio.h>
#include <strings.h>

#define F 6
#define C 10

typedef struct {
    int cod;
    char nombre[50];
    int precio;
    int stock;
} producto;

void carga_productos(producto p[C]) {
    int i;

    for (i=0; i<C; i++) {
        printf("Ingrese datos del producto: \n");
        scanf("%d", &p[i].cod);
        scanf("%s", &p[i].nombre);
        scanf("%d", &p[i].precio);
        scanf("%d", &p[i].stock);
    }
    return;
}

void cereo(int a[F][C]) {
    int i, j;

    for (i=0; i<F; i++) {
        for (j=0; j<C; j++) {
            a[i][j] = 0;
        }
    }
    return;
}

void inciso1(int a[F][C], producto p[C]) {
    int cod, area, venta;

    printf("Ingrese codigo del producto (codigo del 1 al 10, 0 para terminar): \n");
    scanf("%d", &cod);
    while (cod != 0) {
        if (p[cod-1].stock > 0) {
            printf("Ingrese area de la venta (1 al 6): ");
            scanf("%d", &area);
            printf("Ingrese cantidad vendida: \n");
            scanf("%d", &venta);

            a[cod-1][area-1] += venta;
            p[cod-1].stock -= venta;
        } else {
            printf("Stock insuficiente.");
        }
        
        printf("Ingrese codigo del producto (codigo del 1 al 10, 0 para terminar): \n");
        scanf("%d", &cod);
    }
    return;
}

int inciso2(producto p[C], char n[50], int a[F][C]) {
    int encontrado, i;
    encontrado = -1;
    i = 0;
    while (i < C && encontrado != -1) {
        if(strcmp(p[i].nombre, n) == 0) {
            encontrado = 1;
        } else {
            i++;
        }
    }

    if (encontrado != -1) {
        return i;
    }
}

int maximo(int a[F][C], int c) {
    int max, i, z;
    max = -1;

    for (i=0; i<F; i++) {
        if (a[i][c] > max) {
            max = a[i][c];
            z = i;
        }
    }
    return z;
}

int inciso3(int z, int a[F][C], int &tr, producto p[C]) {
    int i, acum;

    acum = 0;
    for (i=0; i<C; i++) {
        acum += a[z-1][i];
        tr += p[i].precio * a[z-1][i];
    }
    return acum;
}

void inciso4(producto p[C], int i) {
    printf("Datos del producto: \n");
    if (i < C) {
        if (p[i].precio < 9000) {
            printf("Codigo: %d\n", p[i].cod);
            printf("Nombre: %s\n", p[i].nombre);
            printf("Precio: %d\n", p[i].precio);
            printf("Stock: %d\n", p[i].stock);
        }
    } else {
        inciso4(p, i+1);
    }
}
int main() {
    char nombre[50];
    int A[F][C], cod, zona, unidades_v, total_r;
    producto P[C];

    total_r = 0;

    cereo(A);
    carga_productos(P);
    inciso1(A, P);
    printf("Ingrese nombre del producto: \n");
    fgets(nombre);
    cod = inciso2(P, nombre, A);
    zona = maximo(A, cod);
    printf("Codigo de la zona con mayor ventas del producto %s: %d\n", nombre, zona);

    printf("Ingrese un numero de zona: \n");
    scanf("%s", &zona);
    unidades_v = inciso3(zona, A, total_r, P);
    printf("Cantidad de unidades vendidas: %d - Total recaudado: %d", unidades_v, total_r);

    inciso4(P, 0);
    
}