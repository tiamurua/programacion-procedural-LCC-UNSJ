#include <stdio.h>

#define N 50

struct postulante {
	char nombre;
	char sexo;
	int dni;
	int edad;
	int cod;
};

void carga(postulante p[N]) {
	int i;
	for (i = 0; i < N; i++) {
		printf("Ingrese datos del postulante: \n");
		scanf("%s", p[i].nombre);
		scanf("%s", &p[i].sexo);
		scanf("%d", &p[i].dni);
		scanf("%d", &p[i].edad);
		scanf("%d", &p[i].cod);
	}
	return;
}

void menos_30(postulante p[N]) {
	int i, cont = 0;
	for (i = 0; i < N; i++) {
		if (p[i].sexo == 'F' && p[i].edad < 30) {
			cont++;
		}
	}
	
	printf("Cantidad de mujeres de menos de 30 años: %d\n", cont);
	
	return;
}

void promedio(postulante p[N]) {
	int i, cont = 0, acum = 0;
	float prom;
	for (i = 0; i < N; i++) {
		if (p[i].sexo == 'M') {
			cont++;
			acum += p[i].edad;
		}
	}
	
	prom = acum/cont;
	printf("Edad promedio de los postulantes varones: %.2f\n", prom);
	return;
}

void mostrar(postulante p[N]) {
	int i;
	
	printf("Postulantes que viven en la localidad 14: \n");
	
	for (i = 0; i < N; i++) {
		if (p[i].cod == 14) {
			printf("Nombre: %s\n", p[i].nombre);
			printf("DNI: %d\n", p[i].dni);
		}
	}
	return;
}
int main() {
	postulante P[N];
	
	carga(P);
	menos_30(P);
	promedio(P);
	mostrar(P);
}
