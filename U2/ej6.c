//Ejercicio 6
//Una tienda de ropa comercializa 50 productos diferentes. Por 
//cada producto se conoce: c�digo (n�mero entero que var�a 
//entre 1 y 50), precio de costo y stock.
//La tienda hace compras a 22 proveedores, de los cuales se 
//conoce: Nombre y N�mero de Proveedor (es un n�mero entre 
//1000 y 1022).
//Se pide redactar un algoritmo en C que, usando estructuras de 
//datos �ptimas y subprogramas eficientes, permita:
#include <stdio.h>

#define N 50
#define M 22

typedef struct {
	int cod;
	float pCosto;
	int stock;
} producto;

typedef struct {
	char nombre[50];
	int numero;
	int cCompras;
} proveedor;

//a) Almacenar en estructuras de datos adecuadas la informaci�n 
// de los Productos y de los Proveedores.
void carga_productos(producto p[N]) {
	int i;
	
	for (i = 0; i < N; i++) {
		printf("Ingrese producto: \n");
		scanf("%d", &p[i].cod);
		scanf("%f", &p[i].pCosto);
		scanf("%d", &p[i].stock);
	}
	return;
}

void carga_proveedores(proveedor pr[M]) {
	int i;
	
	for(i = 0; i < M; i++) {
		printf("Ingrese datos del proveedor: \n");
		scanf("%s", pr[i].nombre);
		scanf("%d", &pr[i].numero);
		pr[i].cCompras = 0;
	}
	
	return;
}

//b) Procesar las compras realizadas a los Proveedores, sabiendo que por cada compra se conoce el N�mero de Proveedor, C�digo de Producto 
//y Cantidad de unidades compradas. Con la informaci�n de cada compra se debe actualizar el stock del producto y contar para cada 
//proveedor la compra realizada.
void procesamiento_compras (producto p[N], proveedor pr[M]) {
	int i, numero, cod, unidades, prodIndice, provIndice;
	
	printf("Ingrese numero del proveedor (0 para terminar): \n");
	scanf("%d", &numero);
	
	while (numero != 0) {
		printf("Ingrese codigo del producto: \n");
		scanf("%d", &cod);
		printf("Ingrese cantidad de unidades compradas: \n");
		scanf("%d", &unidades);
		
		prodIndice = -1;
		provIndice = -1;
		
		//buscar producto por codigo
		for (i = 0; i < N; i++) {
			if (p[i].cod == cod) {
				if (p[i].stock < unidades) {
					prodIndice = i;
				} else {
					printf("Stock Insuficiente");
				}
			}
		}
		
		//buscar proveedor por numero
		for (i = 0; i < M; i++) {
			if (pr[i].numero == numero) {
				provIndice = i;
			}
		}
		
		if (prodIndice != -1 && provIndice != -1) {
			p[prodIndice].stock -= unidades;
			pr[provIndice].cCompras++;
		}
		
		printf("Ingrese numero del proveedor (0 para terminar): \n");
		scanf("%d", &numero);	
	}
	return;
}

//c) Informar cu�nto dinero hay invertido en cada producto.
void dinero_por_producto(producto p[N]) {
	int i, total;
	
	for (i = 0; i < N; i++) {
		total = p[i].pCosto * p[i].stock;
		
		printf("Dinero invertido en %d: %2.f\n", p[i].cod, total);
	}
	return;
}

//d) Generar una nueva estructura de datos que contenga todos los datos de aquellos Proveedores a quienes se les haya realizado m�s de 
//10 compras.
int carga_subarreglo(proveedor pr[M], proveedor spr[M]) {
	int i, c = 0;
	
	for (i = 0; i < M; i++) {
		if (pr[i].cCompras > 10) {
			spr[c].nombre = pr[i].nombre;
			spr[c].numero = pr[i].numero;
			spr[c].cCompras = pr[i].cCompras;
			c++;
		}
	}
	return c;
}

void mostrar_subarreglo (proveedor spr[M], int can) {
	int i;
	
	for (i = 0; i < (can - 1); i++) {
		printf("%s\n", spr[i].nombre);
		printf("%d\n", spr[i].numero);
		printf("%d\n", spr[i].cCompras);
	}
	return;
}

//e) Mostrar la estructura de datos generada en el inciso d) ordenada alfab�ticamente por Nombre de proveedor.
f) Ingresar por teclado un Nombre de proveedor e informar su N�mero y cantidad de compras realizadas. Nota: Utilizar la estructura de datos generada en el inciso d).
int main () {
	producto P[N];
	proveedor PR[M], subPR[M];
	int c;
	
	carga_productos(P);
	carga_proveedores(PR);
	procesamiento_compras(P, PR);
	dinero_por_producto(P);
	c = carga_subarreglo(PR, subPR);
	mostrar_subarreglo (subPR, c);
}
