/*Ejercicio 4
Se conoce la edad y el sexo (codificado F: femenino, 
M: masculino) de 32 personas que trabajan en una 
empresa.
Realizar un programa que a través de funciones 
recursivas permita:*/

#include <stdio.h>

#define N 32

typedef struct {
	int edad;
	char sexo;
} trabajador;

//a) Cargar la información en una estructura optima.
void carga(trabajador t[N], int i) {
	if (i < N) {
		printf("Ingrese edad del trabajador:\n");
		scanf("%d", &t[i].edad);
		
		getchar();
		
		printf("Ingrese sexo del trabajador (F: femenino / M: maculino):\n");
		scanf("%c", &t[i].sexo);
		carga(t, i + 1);
	}
	return;
}

/*b) Indicar en el programa principal cantidad de 
personas mayores de 30 años.*/
void mayores(trabajador t[N], int i, int &c) {
	if (i < N) {
		if (t[i].edad > 30) {
			c++;
		}
		mayores(t, i + 1, c);
	}
	return;
}

/*c) Calcular y mostrar en el programa principal la 
edad promedio de las mujeres.*/
void promedio(trabajador t[N], int i, int &a, int &c) {
	if (i < N) {
		if (t[i].sexo == 'F') {
			c++;
			a += t[i].edad;
		}
		promedio(t, i + 1, a, c);
	}
	return;
}

int main () {
	trabajador T[N];
	int cont = 0, acum = 0, contP = 0;
	
	carga(T, 0);
	
	mayores(T, 0, cont);
	printf("Cantidad de personas mayores de 30 años: %d\n", cont);
	
	promedio(T, 0, acum, contP);
	if (contP > 0) {
		printf("Edad promedio de las mujeres: %d", acum / contP);
	} else {
		printf("No hay mujeres en el grupo:\n");
	}
}


