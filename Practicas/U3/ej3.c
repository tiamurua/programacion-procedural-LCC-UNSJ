/*Ejercicio 3
Un laboratorio abastece a 30 farmacias de la provincia.
 
Dicho laboratorio comercializa 80 medicamentos (1..80) 
de los que se debe registrar: Código de medicamento, 
nombre y precio unitario.

Se ingresan las ventas realizadas ordenada por 
farmacia. Por cada venta a una farmacia se ingresa: 
código de medicamento y cantidad de unidades, 
finalizando con código de medicamento igual a 0 (cero), 
como lo muestra el siguiente ejemplo:

Codificar un programa en C, que utilizando funciones 
permita:*/

#include <stdio.h>
#include <string.h>

#define F 30
#define C 80

typedef struct medicamento {
	char nombre[50];
	float pUnitario;
	float tRecaudado;
} medicamento;

void cereo(int t[F][C], medicamento m[C]) {
	int i, j;
	for (i = 0; i < F; i++) {
		for (j = 0; j < C; j++) {
			t[i][j] = 0;
			m[j].tRecaudado = 0;
			
			printf("Ingrese datos del medicamento: \n");
			fgets(m[j].nombre, sizeof(m[j].nombre), stdin);
			m[j].nombre[strcspn(m[j].nombre, "\n")] = '\0'; //Eliminar el salto de linea
			scanf("%f", &m[j].pUnitario);
			getchar(); //Limpiar el buffer de entrada
		}
	}
	return;
}

void carga(int t[F][C]) {
	int cod, unidades, i;
	
	for (i = 0; i < F; i++) {
		printf("Ingrese codigo del medicamento (0 para finalizar): \n");
		scanf("%d", &cod);
		
		while (cod != 0) {
			printf("Ingrese cantidad de unidades vendidas: \n");
			scanf("%d", &unidades);
			
			t[i][cod - 1] += unidades;
			
			printf("Ingrese codigo del medicamento (0 para finalizar): \n");
			scanf("%d", &cod);
		}
	}
	return;
}

//1. Calcular y mostrar total de unidades vendidas de cada uno de los medicamentos.
void total_unidades(int t[F][C]) {
	int i, j, acum;
	
	printf("Total de unidades vendidas por medicamento: \n");
	
	for (j = 0; j < C; j++) {
		acum = 0;
		
		for (i = 0; i < F; i++) {
			if (t[i][j] != 0) {
				acum += t[i][j];
			}
		}
		printf("Medicamento %d: %d unidades totales vendidas.\n", j + 1, acum);
	}
	return;
}

//2. Escribir el/los códigos/s del/los medicamento/s por el que se recaudó mayor importe.
void total_importes(int t[F][C], medicamento m[C]) {
	int i, j;
	for (i = 0; i < F; i++) {
		for (j = 0; j < C; j++) {
			m[j].tRecaudado += (t[i][j] * m[j].pUnitario);
		}
	}
	return;
}

void mayor_importe(medicamento m[C]) {
	int i;
	float max = -1;
	
	for (i = 0; i < C; i++) {
		if (m[i].tRecaudado > max) {
			max = m[i].tRecaudado;
		}
	}
	
	printf("Codigo/s de medicamento/s por el que se recaudo mayor importe: \n");
	for (i = 0; i < C; i++) {
		if (m[i].tRecaudado == max) {
			printf("%d\n", i + 1);
		}
	}
}

//3. Indicar la cantidad de unidades vendidas para un código de medicamento ingresado por teclado.
void acumulador(int t[F][C], int c) {
	int i, acum = 0;
	
	
	for (i = 0; i < F; i++) {
		acum += t[i][c - 1];
	}
	
	printf("Cantidad de unidades vendidas: %d", acum);
	return;
}

//4. Dado el nombre de un medicamento indicar el importe total recaudado y la cantidad de unidades vendidas.
int busqueda(medicamento m[C], const char* n) {
	int i = 0;
	while ((i < C) && (strcmp(m[i].nombre, n) != 0)) {
		i++;
	}
	return i;
}

//5. Indicar la cantidad de unidades vendida a cada farmacia y el importe total que pagó cada una.
void unidades_x_farmacia(int t[F][C], medicamento m[C]) {
	int i, j, acum;
	float total;
	
	for(i = 0; i < F; i++) {
		acum = 0;
		total = 0;
		
		for (j = 0; j < C; j++) {
			acum += t[i][j];
			total += t[i][j] * m[j].pUnitario;
		}
		
		printf("Farmacia %d: \n", i + 1);
		printf("Cantidad de unidades vendidas a esta farmacia: %d\n", acum);
		printf("Importe total pagado: %2.f", total);
	}
	return;
}

int main() {
	int T[F][C], codigo, indice;
	medicamento M[C];
	char nombre[50];
	
	cereo(T, M);
	carga(T);
	total_unidades(T);
	total_importes(T, M);
	mayor_importe(M);
	
	
	printf("Ingrese codigo de medicamento: \n");
	scanf("%d", &codigo);
	acumulador(T, codigo);
	
	getchar(); //Limpiar el buffer de entrada
	printf("Ingrese el nombre de un medicamento para saber el total recaudado y la cantidad de unidades vendidas: \n");
	fgets(nombre, sizeof(nombre), stdin);
	nombre[strcspn(nombre, "\n")] = '\0'; //Eliminar el salto de linea
	
	indice = busqueda(M, nombre);
	if (indice < C) {
		printf("%2.f\n", M[indice].tRecaudado);
		acumulador(T, indice + 1);
	} else {
		printf("Nombre de medicamento no valido.\n");
	}
	
	unidades_x_farmacia(T, M);
}
