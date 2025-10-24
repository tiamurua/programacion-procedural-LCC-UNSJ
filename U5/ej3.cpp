/*Ejercicio 3
El Instituto Provincial de la Vivienda ha implementado 
un sistema que consta de 5 planes de pago distintos, 
con el fin de que los adjudicatarios de sus viviendas 
puedan cancelar sus deudas. Se ingresa la cantidad de 
adjudicatarios y por cada uno de ellos el DNI, código 
de plan al que adhiere (1..5) y monto adeudado.
Se pide:*/

#include <stdio.h>
#include <malloc.h>

typedef struct {
	int dni;
	int cod;
	float monto;
} adjudicatario;

/*a) Cargar en una estructura de datos adecuada la 
información que se posee.*/
void carga_datos(adjudicatario a[], int n, int i) {
	if (i < n) {
		printf("Ingrese DNI del adjudicatario:\n");
		scanf("%d", &a[i].dni);
		printf("Ingrese codigo del plan al que adhiere el adjudicatario:\n");
		scanf("%d", &a[i].cod);
		printf("Ingrese monto adeudado del adjudicatario:\n");
		scanf("%f", &a[i].monto);
		carga_datos(a, n, i + 1);
	}
	return;
}

/*b) Para un adjudicatario cuyo DNI se ingresa por 
teclado, indicar el número de plan al cual se adhirió 
y el monto adeudado.*/
int indicar_plan_monto(adjudicatario a[], int inicio, int fin, int valor) {
	int medio = (inicio + fin) / 2;
	if (inicio > fin) {
		return -1;
	}
	if (a[medio] == valor) {
		return medio;
	} else if (valor < a[medio]) {
		return indicar_plan_monto(a, inicio, medio - 1, valor);
	} else {
		return indicar_plan_monto(a, medio + 1, fin, valor);
	}
}

void mostrar_plan_monto(adjudicatario a[], int n, int i) {
	printf("")
}
int main() {
	adjudicatario *A;
	int N, dni, indice;
	
	printf("Ingrese cantidad de adjudicatarios:\n");
	scanf("%d", &N);
	
	A = (int*)malloc(N * sizeof(int));
	
	carga_datos(A, N, 0);
	
	printf("Ingrese un numero de DNI:\n");
	scanf("%d", &dni);
	
	indice = indicar_plan_monto(A, 0, N - 1, dni);
	mostrar_plan_monto(A, N, indice);
}
c)
Indicar para cada plan cuantos adjudicatarios adhirieron.
d)
Mostrar el mapa de memoria, después de ejecutar la función que carga los datos.
