#include <stdio.h>
#include <alloc.h>

struct nodo {
	int nro;
	struct nodo *sig;
};

typedef struct nodo *puntero;

void crear(puntero &xp) {
	xp = NULL;
	return;
}

void insertar (puntero &xp) {
	puntero nuevo;
	nuevo = (puntero) malloc (sizeof(struct nodo));
	
	printf("Ingrese un nuevo valor:\n");
	scanf("%d", &nuevo -> nro);
	
	nuevo -> sig = xp;
	xp = nuevo;
	return;
}

void main(void) {
	puntero cabeza;
	
	crear(cabeza);
	insertar(cabeza);
	getch();
}
