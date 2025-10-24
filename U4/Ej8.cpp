//Ej 8 U4
#include <stdio.h>
#include <string.h>
#define N 30
//subprogramas
void esPalindromo(char c[N], int inicio, int fin){
	
	if (inicio>=fin){
		printf("\n La palabra ingresada es un palindromo. ");
		return;
		
	}
	
	//printf("\n\n Comparando %c con %c \n", c[inicio], c[fin]);
	
	//Comparar el primer y el ultimo caracter
	if(c[inicio]==c[fin]){
		esPalindromo(c,inicio+1,fin-1);
	}
	else{
		printf("\n La palabra ingresada no es un palindromo");
		return;
	}
}

//p.ppal
int main(){
	char cadena[N];
	printf("\n Ingrese un palindromo o una palabra: ");
	gets(cadena);
	
	esPalindromo(cadena,0,strlen(cadena)-1);
}
