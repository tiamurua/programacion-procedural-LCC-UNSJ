#include <stdio.h>
#define N 3

//1.
void carga(int a[N][N]) {
    int i, j;

    for (i=0;i<N;i++) {
        for (j=0;j<N;j++) {
            printf("Ingrese un num entero: \n");
            scanf("%d", &a[i][j]);
        }
    }
    return;
}

//2.
int inciso_2(int a[N], int &sm) {
    int i, acum;

    acum = 0;
    for (i=0; i<N; i++) {
        if(a[i] > 100) {
            sm += a[i];
        } else {
            acum += a[i];
        }
    }
    return acum;
}

/*
int inciso_2(int a[N], int *sm) {
    int i, acum;

    acum = 0;
    for (i=0; i<N; i++) {
        if(a[i] > 100) {
            *sm += a[i];
        } else {
            acum += a[i];
        }
    }
    return acum;
}
*/
//3.
void inciso_3(int a[N][N]) {               [8][0][5] i = 1 --> i < 3? SI ademas bandera es falsa? SI
                                           [6][7][0]
                                           [3][6][2]
    int i, j;
    bool bandera;
    for (j=0; j<N; j++) {
        bandera = false;
        i = 0;
        while (i < N && bandera == 0) {
            if(a[i][j] == 0) {
                bandera = true;
            }
            i++;
        }
        printf("esta columna tiene 0.");
    }
    return;
}

int contarNegativas(int arre) {
    int contando, i;
    contando = 0;
    for (i=0; i<N; i++){
        for(
            contando;
        )
    }
    return contando;
}
int main() {
    int A[N][N], fila, suma_mayores, suma_menores, cantidad;

    suma_mayores = 0;
    carga(A);

    printf("Ingrese un num de fila: \n");
    scanf("%d", &fila);
    suma_menores = inciso_2(A[fila], suma_mayores);
    printf("La suma de las componentes mayores a 100 en el arreglo es de: %d", suma_mayores);
    printf("La suma de las componentes menores a 100 en el arreglo es de: %d", suma_menores);
    inciso_3(A);

    cantidad = contarNegativas(arre);

    /*-------------------------------------------------------------*/

    
}