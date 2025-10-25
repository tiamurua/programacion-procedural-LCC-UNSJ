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
		carga(a, i+1);
	}
	return;
}

/*b) Generar un subarreglo con las componentes del 
arreglo cargado, cuyo valor es mayor o igual al 
Promedio.*/
int promedio(int a[N], int i, int ac) {
	if (i < N) {
		ac += a[i];
		promedio(a, i+1, ac);
	} else {
		return acum / N;
	}
	return;
}

int carga_subarreglo(int a[N], int sa[N], int i, int xp, int c) {
	if (i < N) {
		if (a[i] >= xp) {
			sa[c] = a[i];
			c++;
			carga_subarreglo(a, sa, i + 1, xp, c);
		}
		carga_subarreglo(a, sa, i+1, xp, c);
	} else {
		return c;
	}
}

void mostrar_subarreglo(int sa[N], int i, int c) {
	if (i < c) {
		printf("[%d]\n", sa[i]);
		mostrar_subarreglo(sa, i+1, c);
	}
	return;
}

/*c) Indicar cuantas componentes del subarreglo son 
mayores al promedio y cuantas iguales a éste.*/
void mayores_menores(int sa[N], int i, int xc, int xp, int &cMax, int &cMin) {
	if (i < xc) {
		if (sa[i] > xp) {
			cMax++;
			mayores_menores(sa, i+1, xc, xp, cMax, cMin);
		} else if (sa[i] < xp) {
			cMin++;
			mayores_menores(sa, i+1, xc, xp, cMax, cMin);
		}
		mayores_menores(sa, i+1, xc, xp, cMax, cMin);
	}
	return;
}

/*d) Ingresar un número y decir si se encuentra en el 
subarreglo.*/
int buscar(int sa[N], int i, int xc, int n) {
	int i = 0, esta = 0;
	if (i < xc && esta == 0) {
		if ()
	}
}
int main() {
	int A[N], SA[N], acum = 0, componentes = 0, c, cMayores = 0, cMenores = 0;
	int numero, bandera;
	float p;
	
	carga(A, 0);
	
	p = promedio(A, 0, acum);
	c = carga_subarreglo(A, SA, 0, p, componentes);
	mostrar_subarreglo(SA, 0, c);
	
	mayores_menores(SA, 0, c, p, cMayores, cMenores);
	printf("Cantidad de componentes mayores al promedio: %d", cMayores);
	printf("Cantidad de componentes menores al promedio: %d", cMenores);
	
	printf("Ingrese un numero:\n");
	scanf("%d", &numero);
	bandera = busqueda(SA, 0, c, numero);
}

e)
Realice el ítem anterior si el arreglo original estuviera ordenado ascendentemente.
Nota: Hacer mapa de memoria para un subprograma
