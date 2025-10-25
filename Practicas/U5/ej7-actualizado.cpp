/*Ejercicio 7
La Federación Internacional de Futbol FIFA tiene el objetivo 
de recopilar información de los futbolistas de 4 mundiales 
(años 2022,2018,2014 y 2010). Para ello se está generando una 
nueva base de datos con información acotada de dichos 
acontecimientos. De cada mundial se conoce: Nombre del país 
de realización y cantidad de estadios, de cada futbolista: 
Nombre y apellido, país de residencia y cantidad de goles 
registrados.
Realizar un programa en C que a través de funciones óptimas 
permita:*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct futbolista {
	char nya[30];
	char pais[20];
	int goles;
} futbolista;

struct nodo {
	futbolista dato;
	struct nodo *sig;
};

typedef struct nodo *puntero;

typedef struct mundial {
	char pais[20];
	int cant_estadios;
	puntero jugadores;
} mundial;

/*a)Generar un arreglo de lista a través de punteros con los 
datos de los jugadores para los distintos mundiales. El 
ingreso de información se encuentra ordenada por año de 
mundial. Para cada mundial el ingreso de información finaliza 
con el nombre de país igual a FIN.*/
void crear_listas(mundial m[4], int i) {
	if (i < 4) {
		m[i].jugadores = NULL;
		crear_listas(m, i+1);
	}
	return;
}

void carga_insercion(mundial m[4], int i) {
	puntero nuevo;
	
	if (i < 4) {
		printf("Ingrese nombre del pais donde se realizo el mundial (FIN para terminar):\n");
		fflush(stdin);
		gets(m[i].pais);
		
		if (strcmp(m[i].pais, "FIN") != 0) { // Se sigue si no es FIN
			printf("Ingrese cantidad de estadios:\n");
			scanf("%d", &m[i].cant_estadios);
			
			nuevo = (puntero) malloc (sizeof(struct nodo));
			
			printf("Ingrese nombre y apellido del jugador:\n");
			fflush(stdin);
			gets(nuevo->dato.nya);
			printf("Ingrese pais de residencia del jugador:\n");
			fflush(stdin);
			gets(nuevo->dato.pais);
			printf("Ingrese cantidad de goles registrados:\n");
			scanf("%d", &nuevo->dato.goles);
			
			nuevo->sig = m[i].jugadores;
			m[i].jugadores = nuevo;
		}
		
		carga_insercion(m, i+1);
	}
}

/*b)Para un mundial ingresado por teclado, realizar una 
función que devuelva al programa principal la cantidad de 
jugadores de Argentina y cantidad de jugadores con más de 5 
goles realizados. Realizar una función recursiva que devuelva 
un dato por parámetro y el otro que lo calcule la función.*/
void calculo_jugadores(puntero c, int &c_a, int &c_g) {
	if (c != NULL) {
		if (strcmp(c->dato.pais, "Argentina") == 0) {
			c_a++;
		}
		
		if (c->dato.goles > 5) {
			c_g++;
		}
		
		calculo_jugadores(c->sig, c_a, c_g);
	}
}

/*c)Eliminar un jugador cuyo nombre y apellido es ingresado 
por teclado.*/
void suprimir(mundial m[4], char n[]) {
	puntero anterior, actual;
	int i, encontrado = 0;
	
	for (i = 0; i < 4; i++) {
		anterior = NULL;
		actual = m[i].jugadores;
		
		while (actual != NULL && encontrado == 0) {
			if (strcmp(actual->dato.nya, n) == 0) { //Encontrado
				encontrado = 1;
				
				if(anterior == NULL) { //Primer nodo
					m[i].jugadores = actual->sig;
				} else {
					anterior->sig = actual->sig;
				}
				free(actual);
				printf("Jugador %s eliminado del mundial %s.\n", n, m[i].pais);
			} else {
				anterior = actual;
				actual = actual->sig;
			}
		}
	}
	
	if (!encontrado) {
		printf("Jugador no encontrado en ningun mundial.\n");
	}	
}

/*d)Generar una nueva estructura con todos aquellos 
jugadores que por mundial hayan convertido 3 o más goles.*/
void crear_nueva_lista(mundial m[4], puntero &c) {
	puntero nuevo, actual;
	int i;
	
	for (i = 0; i < 4; i++) {
		actual = m[i].jugadores;
		
		while (actual != NULL) {
			if (actual->dato.goles >= 3) {
				nuevo = (puntero) malloc (sizeof(struct nodo));
				nuevo->dato = actual->dato;
				nuevo->sig = c;
				c = nuevo;
			}
			
			actual = actual->sig;
		}
	}
	return;
}

void mostrar(puntero &nc) {
	while (nc != NULL) {
		printf("%s - %s - %d goles\n", nc->dato.nya, nc->dato.pais, nc->dato.goles);
		nc = nc->sig;
	}
	return;
}

int main() {
	mundial M[4];
	int n_mundial, cont_argentinos = 0, cont_5goles = 0;
	char nom[30];
	puntero cabeza_nueva = NULL;
	
	//a)
	crear_listas(M, 0);
	carga_insercion(M, 0);
	
	//b)
	printf("Ingrese un numero de mundial (1: 2010, 2: 2014, 3: 2018, 4: 2022):\n");
	scanf("%d", &n_mundial);
	calculo_jugadores(M[n_mundial-1].jugadores, cont_argentinos, cont_5goles);
	printf("Cantidad de jugadores argentinos: %d\n", cont_argentinos);
	printf("Cantidad de jugadores con mas de 5 goles registrados: %d\n", cont_5goles);
	
	//c
	printf("Ingrese el nombre y apellido del jugador que va a eliminar de la lista:\n");
	fflush(stdin);
	gets(nom);
	suprimir(M, nom);
	
	//d)
	crear_nueva_lista(M, cabeza_nueva);
	printf("Lista de jugadores con 3 o mas goles:\n");
	mostrar(cabeza_nueva);
}

