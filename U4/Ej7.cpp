//Ej 7 U4
#include <stdio.h>
#define N 6

//subprogramas
void carga(int a[N],int i){
	if(i<N){
		printf("\n\n Ingrese un numero entero: ");
		scanf("%d", &a[i]);
		carga(a,i+1);
	}
}
void mayorValor(int a[N], int i, int &max){

	
	if(i<N){
		if(a[i]>max){
			max=a[i];
		
		}
		mayorValor(a,i+1,max);
		if(a[i]==max){
		printf("\n\n %d  es igual al maximo %d ", a[i], max);
		}
	}
	
}
//Porgrama ppal
int main(){
	int a[N], max=-1;
	carga(a,0);
	mayorValor(a,0,max);
}
