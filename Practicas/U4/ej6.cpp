/*Ejercicio 6
Construir un programa en lenguaje C que a través de 
funciones recursivas resuelva los siguientes ítems:*/

#include <stdio.h>

#define N 5

//a) Cargar un arreglo de enteros, de N componentes.
void carga(int a[N], int i) {
	if (i < N) {
		printf("Ingrese un numero entero:\n");
		scanf("%d", &a[i]);
		carga(a, i + 1);
	}
	return;
}

/*b) Generar un subarreglo con las componentes del 
arreglo cargado, cuyo valor es mayor o igual al 
Promedio.*/
int promedio(int a[N], int i, int xa) {
	if (i < N) {
		xa += a[i];
		promedio(a, i + 1, xa);
	}
	return;
}
int carga_subarreglo(int a[N], int sa[N], int i, int c, int xp) {
	if (i < N) {
		if(a[i] >= xp) {
			sa[c] = a[i];
			c++;
			carga_subarreglo(a, sa, i + 1, c, xp);
		}
		carga_subasrreglo(a, sa, i + 1, c, xp);
	}
	return c;
}

void mostrar_subarreglo(sa[N], int xc, int i) {
	if (i < xc) {
		printf("[%d]", sa[i]);
		mostrar_subarreglo(sa, xc, i + 1);
	}
	return;
}

/*c) Indicar cuantas componentes del subarreglo son 
mayores al promedio y cuantas iguales a éste.*/
int mayores_al_promedio(int sa[N], int xc, int xp, int xmp, int &xip, int i) {
	if (i < N) {
		if (sa[i] > xp) {
			xmp++;
			mayores_al_promedio(sa, xc, xp, xmp, xip, i + 1);
		} else if (sa[i] == xp) {
			xip++;
			mayores_al_promedio(sa, xc, xp, xmp, xip, i + 1);
		}
		mayores_al_promedio(sa, xc, xp, xmp, xip, i + 1);
	}
	return xmp;
}

/*d) Ingresar un número y decir si se encuentra en el subarreglo.*/

int main() {
	int A[N], SA[N], c, p, acum = 0, mProm = 0, iProm = 0;
	
	carga(A, 0);
	
	p = promedio(A, 0, acum) / N;
	c = carga_subarreglo(A, SA, 0, 0, p);
	mostrar_subarreglo(SA, c, 0);
	
	mProm = mayores_al_promedio(SA, c, p, mProm, iProm, 0);
}


e)
Realice el ítem anterior si el arreglo original estuviera ordenado ascendentemente.
Nota: Hacer mapa de memoria para un subprograma
