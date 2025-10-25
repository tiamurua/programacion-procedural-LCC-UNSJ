/*Ejercicio 1
Escribir un programa en lenguaje C que usando funciones permita:*/
#include <stdio.h>
#include <stdlib.h>

//a)Crear y cargar 2 arreglos dinamicos de componentes enteras MxM (mismo tamaño) ingresada por teclado.
void carga(int x[], int t, int i) {
    if (i < t) {
        printf("Ingrese un numero entero:\n");
        scanf("%d", &x[i]);

        carga(x, t, i + 1);
    }
    return;
}

/*b)Calcular el producto escalar.
El producto escalar es una operación donde al multiplicar dos arreglos se obtiene un único valor.
A * B = A[0] * B[0] + A[1] * B[1] +…+ A[N-1] * B[N-1]*/
void producto_escalar(int a[], int b[], int t) {
    int i, acum = 0;

    for (i = 0; i < t; i++) {
        acum += a[i] * b[i];
    }

    printf("El producto escalar entre A y B es: %d", acum);
    return;
}

/*c)Generar una nueva estructura con los 
valores pares contenidos en uno de los 
arreglos (realizar un subprograma que 
solicite memoria para la nueva estructura 
y la devuelva cargada).*/
int* carga_subarreglo(int a[], int t, int &nt) {
    int i, count = 0, *pares, j = 0;

    for (i = 0; i < t; i++) {
        if (a[i] % 2 == 0) {
            count++;
        }
    }

    pares = (int*) malloc (count * sizeof(int));

    for (i = 0; i < t; i++) {
        if (a[i] % 2 == 0) {
            pares[j] = a[i];
            j++;
        }
    }

    nt = count;
    return pares;
}

void mostrar_subarreglo(int c[], int nt) {
    int i;

    printf("Nuevo arreglo de numeros pares:\n");

    for (i = 0; i < nt; i ++) {
        printf("%d, ", c[i]);
    }
    return;
}

int main() {
    int *A, *B, tamano, *C, nuevo_tamano;

    printf("Ingrese el tamaño de los arreglos:\n");
    scanf("%d", &tamano);

    A = (int*) malloc (tamano * sizeof (int));
    B = (int*) malloc (tamano * sizeof (int));

    carga(A, tamano, 0);
    carga(B, tamano, 0);

    producto_escalar(A, B, tamano);

    C = carga_subarreglo(A, tamano, nuevo_tamano);

    mostrar_subarreglo(C, nuevo_tamano);
       
}
