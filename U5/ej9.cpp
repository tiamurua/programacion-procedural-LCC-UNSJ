/*Ejercicio 9
La clínica de la salud San Juan, necesita registrar los 
pacientes en espera para cada una de las 12 especialidades 
con la que cuenta la misma.
Realizar un programa, que a través de un menú de opciones 
permita:*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nodo {
	int dni;
	struct nodo *sig;
};

typedef struct nodo *puntero;

typedef struct especialidad {
	char nombre[30];
	puntero turnos;
} especialidad;

/*a)Ingresar los datos correspondientes a cada especialidad: 
Numero de especialidad (1-12) y nombre (cardiología, 
maternidad, laboratorio,…,etc.).*/
void crear_listas(especialidad e[12], int i) {
	if (i < 12) {
		e[i].turnos = NULL;
		crear_listas(e, i+1);
	}
	return;
}

void cargar_especialidades(especialidad e[12], int i) {
	int num;
	if (i < 12) {
		printf("Ingrese numero de especialidad:\n");
		scanf("%d", &num);
		printf("Ingrese nombre de especialidad:\n");
		fflush(stdin);
		gets(e[num-1].nombre);
		
		cargar_especialidades(e, i+1);
	}
}

/*b) Registrar los turnos, ingresando el DNI del paciente y 
el número de especialidad al que desea asistir.*/
void registrar_turnos(especialidad e[12]) {
	puntero nuevo;
	int dni, n;
	
	printf("Ingrese DNI del paciente (0 para finalizar).\n");
	scanf("%d", &dni);
	if (dni != 0) {
		nuevo = (puntero) malloc (sizeof(struct nodo));
		
		printf("Ingrese numero de especialidad a la que desea asistir:\n");
		scanf("%d", &n);
		nuevo->dni = dni;
		nuevo->sig = e[n-1].turnos;
		e[n-1].turnos = nuevo;
	} else {
		registrar_turnos(e);
	}
	return;
}

/*c)Eliminar el turno de un paciente que no podrá asistir, los datos del paciente y numero de especialidad se ingresan por teclado.*/
void suprimir(puntero &c, int xdni) {
	puntero anterior, p;
	
	if (c->dni == xdni) {
		p = c;
		c = c->sig;
		free(p);
	} else { 
		p = c;
		anterior = c;
		while ((p != NULL) && (p->dni != xdni)) {
			anterior = p;
			p = p->sig;
		}
		if (p != NULL) {
			anterior->sig = p->sig;
			free(p);
			printf("El turno fue eliminado.\n");
		} else {
			printf("No se encuentra el turno en la lista.\n");
			return;
		}
	}
}

//d)Dado el número de una especialidad, mostrar su nombre y la cantidad total de pacientes en cola de espera.
int mostrar_datos(puntero c) {
	if (c == NULL) {
		return 0;
	}
	return 1 + mostrar_datos(c->sig);	
}

//e)Dado el DNI de un paciente, informar la/las especialidades (número y nombre) en las que se anotó.
int busqueda_lista(puntero c, int elem) {
	if (c == NULL) {
		return 0;
	} else if (c->dni == elem) {
		return 1;
	} else {
		return busqueda_lista(c->sig, elem);
	}
}

void busqueda_arreglo(especialidad e[10], int xdni, int i) {
	int indice;
	if (i < 10) {
		indice = busqueda_lista(e[i].turnos, xdni);
		
		if (indice != 0) {
			printf("El usuario con DNI %d esta anotado en la especialidad: %d - %s.\n", xdni, i+1, e[i].nombre);
		} else {
			printf("El DNI no se encuentra en las listas.\n");
		}
		
		busqueda_arreglo(e, xdni, i+1);
	}
	return;
}

int main() {
	especialidad E[12];
	int num, dni, opcion, cantidad;
	
	printf("\nMenu de opciones:\n");
	printf("1. Opcion 1: Cargar datos de cada especialidad.\n");
	printf("2. Opcion 2: Registrar turnos.\n");
	printf("3. Opcion 3: Eliminar un turno.\n");
	printf("4. Opcion 4: Titulo y cantidad de inscriptos de un tutorial.\n");
	printf("5. Opcion 5: Especialidades en las que se anoto un paciente.\n");
	printf("6. Opcion 6: Salir.\n");
	printf("Elige una opcion: ");
	scanf("%d", &opcion);
	
	switch(opcion) {
		case 1:
			crear_listas(E, 0);
			cargar_especialidades(E, 0);
			break;
		case 2:
			registrar_turnos(E);
			break;
		case 3:
			printf("Ingrese numero de especialidad:");
			scanf("%d", &num);
			printf("Ingrese dni del paciente:\n");
			scanf("%d", &dni);
			suprimir(E[num-1].turnos, dni);
			break;
		case 4:
			printf("Ingrese un numero de especialidad:\n");
			scanf("%d", &num);
			cantidad = mostrar_datos(E[num-1].turnos);
			printf("especialidad: %s, Cantidad de pacientes en cola: %d", E[num-1].nombre, cantidad);
			break;
		case 5:
			printf("Ingrese un DNI:\n");
			scanf("%d", &dni);
			busqueda_arreglo(E, dni, 0);
			break;
		case 6:
			printf("Saliendo...\n");
			break;
		default:
			printf("Opcion no valida.\n");
			break;
	}
}
