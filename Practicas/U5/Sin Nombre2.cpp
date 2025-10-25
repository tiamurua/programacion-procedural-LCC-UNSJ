/*Ejercicio 7
La Federación Internacional de Futbol FIFA tiene el objetivo de recopilar información de los futbolistas de 4 mundiales 
(años 2022,2018,2014 y 2010). Para ello se está generando una nueva base de datos con información acotada de dichos 
acontecimientos. De cada mundial se conoce: Nombre del país de realización y cantidad de estadios, de cada futbolista: 
Nombre y apellido, país de residencia y cantidad de goles registrados.
Realizar un programa en C que a través de funciones óptimas permita:*/
#include <stdio.h>
#include <string.h>

#define N 4

struct futbolista {
	char nYa[50];
	char pais[30];
	int cGoles;
};

struct nodo {
	futbolista datos;
	struct nodo *sig;
};

typedef struct nodo *puntero;

struct mundial {
	char nPais[20];
	int cEstadios;
	puntero cabeza;
};
/*a) Generar un arreglo de lista a través de punteros con los datos de los jugadores para los distintos mundiales. El 
ingreso de información se encuentra ordenada por año de mundial. Para cada mundial el ingreso de información finaliza con 
el nombre de jugador igual a FIN.*/
void crear(mundial m[N]) {
	int i;
	
	for (i = 0; i < N; i++) {
		m[i].cabeza = NULL;
	}
	return;
}

void insertar(puntero &c, char nj[30]) {
	puntero nuevo;
	nuevo = (puntero) malloc (sizeof(struct nodo));
	printf("Ingrese pais del jugador:\n");
	gets(&nuevo -> datos.pais);
	printf("Ingrese cantidad de goles realizados por el jugador:\n");
	scanf("%d", &nuevo -> datos.cGoles);
	nuevo -> datos.nYa = cj;
	nuevo -> sig = c;
	c = nuevo;
	return;
}

void carga(mundial m[N]) {
	int i;
	char nJugador[30];
	
	crear (m);
	for (i = 0; i < N; i++) {
		printf("Ingrese el nombre del pais anfitrion:\n");
		gets(m[i].nPais);
		printf("Ingrese cantidad de estadios:\n");
		scanf("%d", &m[i].cEstadios);
		
		printf("Ingrese nombre del jugador ('FIN' para terminar)");
		gets(nJugador);
		
		while (strcmp(nJugador, "FIN") == 0) {
			insertar(m[i].cabeza, nJugador);
			
			printf("Ingrese nombre del jugador ('FIN' para terminar)");
			gets(nJugador);
		}
	}
	return;
}

/*b) Para un mundial ingresado por teclado, realizar una función que devuelva al programa principal la cantidad de 
jugadores de Argentina y cantidad de jugadores con más de 5 goles realizados. Realizar una función recursiva que devuelva 
un dato por parámetro y el otro que lo calcule la función.*/
int contadores (puntero m, int &cg, int i) {
	int contG;
	if (m != NULL) {
		contG = 0;
		if (m -> datos.)
	}
}

//d) Generar una nueva estructura con todos aquellos jugadores que por mundial hayan convertido 3 o más goles.
void carga_nueva_lista(mundial &m[N], puntero &c2) {
	puntero nuevo;
	int i;
	
	for (i = 0; i < N; i++) {
		if (m[i] -> datos.cGoles >= 3) {
			nuevo = (puntero) malloc (sizeof(struct nodo));
			
			nuevo -> datos = m->datos;
			nuevo -> sig = c2;
			c2 = nuevo;
		}
	}
	
	return;
}
int main() {
	mundial M[N];
	puntero cabeza;
	int aMundial, cArgentinos, cGoles = 0;
	
	carga(M);
	printf("Ingrese un mundial (0: 2010, 1: 2014, 2: 2018, 3: 2022)\n");
	scanf("%d", &aMundial);
	cArgentinos = contadores(M[aMundial].cabeza, cGoles, 0);
	carga_nueva_lista(M, cabeza);
}
c)
Eliminar un jugador cuyo nombre y apellido es ingresado por teclado.

