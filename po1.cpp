#include <stdio.h>
#define F 3   // negocios
#define C 4   // tipos de cerveza

void cereo(int a[F][C]){
    int i,j;
    for(i=0;i<F;i++){
        for(j=0;j<C;j++){
            a[i][j]=0;
        }
    }
}

void carga(int a[F][C]){
    int tipocer, negocio, cant;
    printf("Ingrese el tipo de cerveza (1-4, 0 para terminar): ");
    scanf("%d",&tipocer);
    while(tipocer!=0){
        printf("Ingrese el negocio (1-3): ");
        scanf("%d",&negocio);
        printf("Ingrese la cantidad de unidades: ");
        scanf("%d",&cant);
        a[negocio-1][tipocer-1]+=cant;
        printf("Ingrese el tipo de cerveza (1-4, 0 para terminar): ");
        scanf("%d",&tipocer);
    }
}

void mostrar(int a[F][C]){
    int i,j;
    for(i=0;i<F;i++){
        printf("\nNegocio %d\n", i+1);
        printf("Tipo de Cerveza   Cantidad de Unidades\n");
        for(j=0;j<C;j++){
            printf("%-16d %d\n", j+1, a[i][j]);
        }
    }
    return;
}
int inciso_4(int a[F][C], int c) {
    int i, acum;

    acum = 0;

    for (i=0; i<F; i++) {
        acum += a[i][c-1];
    }
    return acum;
}
int main(){
    int arre[F][C], cod, acum;
    cereo(arre);
    carga(arre);
    mostrar(arre);
    printf("Ingrese un cod de cerveza: ");
    scanf("%d", &cod);
    acum = inciso_4(arre, cod);
    printf("Cantidad total de unidades vendidas de la cerveza %d en todos los negocios: %d unidades.", cod, acum);
    
}