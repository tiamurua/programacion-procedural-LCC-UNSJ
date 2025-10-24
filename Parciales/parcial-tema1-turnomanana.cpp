/*Desarrolla un programa en C que gestione un inventario de
productos utilizando una lista enlazada. Cada nodo de la 
lista representara un producto con los siguientes atributos: 
codigo (entero mayor-igual a 100), nombre de producto, rubro 
(1...6), precio y cantidad en stock.
Hacer un programa que a traves de funciones optimas realice 
las siguientes tareas:*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	int cod;
	char nombre[30];
	int rubro;
	float precio;
	int stock;
} producto;

struct nodo {
	producto datos;
	struct nodo *sig;
};

typedef struct nodo *puntero;

/*2.Generar una lista enlazada que almacene la informacion de
varios productos cuya informacion se ingresa por teclado.*/
void crear(puntero &c) {
	c = NULL;
	return;
}

void insertar(puntero &c) {
	int cod;
	puntero nuevo;
	
	printf("Ingrese codigo de producto (0 para finalizar):\n");
	scanf("%d", &cod);
	while (cod != 0) {
		nuevo = (puntero) malloc (sizeof(struct nodo));
		
		nuevo->datos.cod = cod;
		
		printf("Ingrese Nombre del producto:\n");
		fflush(stdin);
		gets(nuevo->datos.nombre);
		
		printf("Ingrese rubro:\n");
		scanf("%d", &nuevo->datos.rubro);
		
		printf("Ingrese precio:\n");
		scanf("%f", &nuevo->datos.precio);
		
		printf("Ingrese stock disponible:\n");
		scanf("%d", &nuevo->datos.stock);
		
		nuevo->sig = c;
		c = nuevo;
		
		printf("Ingrese codigo de producto (0 para finalizar):\n");
		scanf("%d", &cod);
	}
	return;
}

/*2.Implementa una funcion que permita buscar un producto
por su nombre, si se encuentra en la lista mostrar su 
informacion en el main. Si no se encuentra, mostrar un
mensaje en el main indicando que el producto no existe.*/
int busqueda(puntero cab, char *n, int &c, int &r, int &s, float &p) {
	while ((c != NULL) && (strcmp(cab->datos.nombre, n) == 0)) {
		cab = cab->sig;
	}
	
	if (cab == NULL) {
		return 1;
	} else {
		c = cab->datos.cod;
		r = cab->datos.rubro;
		s = cab->datos.stock;
		p = cab->datos.precio;
		return 0;
	}
}

/*3.Calcula el valor total del inventario sumando el
resultado de multiplicar el precio de cada producto por su 
cantidad en stock. Hacer una funcion recursiva.*/
float calculo_inventario(puntero c) {
	if (c != NULL) {
		return (c->datos.stock * c->datos.precio) + calculo_inventario(c->sig);
	} else {
		return 0;
	}
}

/*4.Crea una funcion que a partir de la lista enlazada
almacene en un arreglo la cantidad de productos por rubro.
Mostrar el arreglo cargado en el main.*/
void cargar_arreglo(puntero c, int a[6]) {
	int i;
	puntero aux;
	
	for (i = 0; i < 6; i++) {
		aux = c;
		
		while (aux != NULL) {
			a[aux->datos.rubro-1] += aux->datos.stock;
			
			aux = aux->sig;
		}
	}
	return;
}

/*5.Se posee un archivo "Inventario.dat", donde cada
registro contiene codigo, nombre de producto, rubro,
precio, cantidad en stock; esta indexado por codigo a
partir de 100. Con la informacion de la lista actualizar el
stock de cada producto.*/
void actualizar_archivo(FILE *xarchi, puntero c) {
	producto a;
	
	fpos_t x;
	rewind(xarchi);
	fread(&a, sizeof(a), 1, xarchi);
	while (!feof(xarchi) && (c->datos.cod == a.cod)) {
		fread(&a, sizeof(a), 1, xarchi);
	}
	
	if (!feof(xarchi)) {
		a.stock = c->datos.stock;
		fseek(xarchi, -sizeof(a), SEEK_CUR);
		fwrite(&a, sizeof(a), 1, xarchi);
		fclose(xarchi);
	}
	return;
}

int main() {
	puntero cabeza;
	char nombre[30];
	int cod, rubro, stock, bandera, arreglo[6], i;
	float precio, inventario;
	FILE *archivo;
	
	//1.
	crear(cabeza);
	insertar(cabeza);
	
	//2.
	printf("Ingrese nombre del producto para buscarlo en la lista:\n");
	fflush(stdin);
	gets(nombre);
	bandera = busqueda(cabeza, nombre, cod, rubro, stock, precio);
	if (bandera == 0) {
		printf("Producto encontrado. Informacion del producto:\n");
		printf("Codigo: %d\n", cod);
		printf("Nombre: %s\n", nombre);
		printf("Rubro: %d\n", rubro);
		printf("Precio: %.2f\n", precio);
		printf("Stock: %d\n", stock);
	} else {
		printf("Producto no encontrado.\n");
	}
	
	//3.
	inventario = calculo_inventario(cabeza);
	printf("Valor total del inventario: %.2f\n", inventario);
	
	//4.
	cargar_arreglo(cabeza, arreglo);
	for (i = 0; i < 6; i++) {
		printf("Stock del rubro %d: %d\n", i+1, arreglo[i]);
	}
	
	//5.
	archivo = fopen("Inventario.dat", "w+");
	actualizar_archivo(archivo, cabeza);
}
