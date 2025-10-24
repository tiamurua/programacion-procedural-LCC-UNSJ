/*ENUNCIADO
Se procesa los datos de los empleados de una tienda. De cada 
uno se conoce: nombre, DNI, sueldo.
Realizar un programa en lenguaje C, que usando funciones 
óptimas realice lo siguiente:*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct empleado
{
    char nombre[30];
    int dni;
    float sueldo;    
} empleado;

struct nodo
{
    empleado dato;
    struct nodo *sig;
};

typedef struct nodo *puntero;

void crear(puntero &c)
{
    c = NULL;
    return;
}

/*Generar una lista enlazada con punteros para cargar los 
datos de los empleados.*/
void insertarAlFinal(puntero &c)
{
    puntero nuevo, actual;
    int dni;

    printf("Ingrese DNI del empleado (0 para finalizar):\n");
    scanf("%d", &dni);

    if (dni != 0)
    {
        nuevo = (puntero) malloc (sizeof(struct nodo));
        nuevo -> dato.dni = dni;

        printf("Ingrese Nombre del empleado:\n");
        gets(nuevo -> dato.nombre);

        printf("Ingrese Sueldo del empleado:\n");
        scanf("%.2f", &nuevo -> dato.sueldo);

        nuevo -> sig = NULL;

        if (c == NULL)
        {
            c = nuevo;
        } else {
            actual = c;
            while (actual -> sig != NULL)
            {
                actual = actual -> sig;
            }
            actual -> sig = nuevo;
        }

        insertarAlFinal(c);
    }
}

/*Mostrar los datos de los empleados sueldo mayor a 
$ 400.000. (Hacer una función recursiva)*/
void mostrar(puntero c)
{
    if (c != NULL)
    {
        if (c->dato.sueldo > 400000)
        {
            printf("Nombre: %s, DNI: %d, Sueldo: %.2f\n", c ->dato.nombre, c->dato.dni, c->dato.sueldo);
        }
        mostrar(c->sig);
    }
}

//Ingresar el DNI de un empleado y decir su nombre.
void busqueda(puntero c, int elem)
{
    while (c != NULL)
    {
        if (c -> dato.dni == elem)
        {
            printf("El nombre del empleado con DNI %d es: %s\n", elem, c->dato.nombre);
            return;
        }
        c = c->sig;
    }
    printf("No se encontro ningun empleado con el DNI %d\n", elem);
}

/*Eliminar los datos de los empleados con sueldo menor a 
$250.000 y mostrar la lista actualizada.*/
void eliminar(puntero &c)
{
    puntero actual = c, anterior = NULL;
    
    while (actual != NULL && actual -> dato.sueldo < 250000)
    {
    	c = actual -> sig;
    	free(actual);
    	actual = c;
	}
	
	while (actual != NULL)
	{
		while (actual != NULL && actual -> dato.sueldo >= 250000)
		{
			anterior = actual;
			actual = actual -> sig;
		}
		
		if (actual != NULL)
		{
			anterior -> sig = actual -> sig;
			free(actual);
			actual = anterior -> sig;
		}
	}
}

void mostrar2(puntero c)
{
	printf("Lista actualizada\n");
	while (c != NULL)
	{
		printf("Nombre: %s\n", c -> dato.nombre);
		printf("DNI: %d\n", c -> dato.dni);
		printf("Sueldo: %.2f\n", c -> dato.sueldo);
		
		c = c -> sig;
	}
	return;
}
int main()
{
    puntero cabeza;
    int dni;

    crear(cabeza);
    insertarAlFinal(cabeza);
    
    printf("Datos de los empleados con sueldo mayor a $ 400.000:\n");
    mostrar(cabeza);

    printf("Ingrese un DNI para la busqueda:\n");
    scanf("%d", &dni);
    busqueda(cabeza, dni);

    eliminar(cabeza);
    mostrar2(cabeza);
}
