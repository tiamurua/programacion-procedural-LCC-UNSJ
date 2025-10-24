#include <stdio.h>
#include <string.h>

#define N 28

carga(char s[N]) {
	printf("Ingrese frase: \n");
	gets(s);
}

void cambio(char s[N], char e) {
	int i = 0;
	
	while (i < N && e != s[i]) {
		i++;
	}
	
	s[i] = '0';
	
	return;
}

carga_subcadena(char s[N], char ss[N]) {
	int i;
	for (i = 0; i < 12; i++) {
		ss[i] = s[i];
	}
}

void vocales(char s[N]) {
	int i, cont = 0;
	for (i = 0; i < N; i++) {
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
			cont++;
		}
	}
	
	printf("Cantidad de vocales en la frase: %d", cont);
	return;
}

int main () {
	char S[N], SS[N];
	char elemento = '2';
	
	carga(S);
	cambio(S, elemento);
	
	printf("Frase cambiada: \n");
	puts(S);
	
	carga_subcadena(S, SS);
	
	printf("Nueva frase generada: \n");
	puts(SS);
	
	vocales(S);
}
