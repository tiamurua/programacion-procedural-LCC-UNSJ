/*Ejercicio 7
Una consultora contable realiza la liquidacion de haberes 
de los empleados de varias PYMES. Para ello posee un archivo 
con informacion de empleados "EMPLEADOS.dat"�de diferentes 
empresas: Nombre del Empleado, Nombre de la Empresa, DNI, 
CUIT y sueldo neto. El archivo esta ordenado por nombre de 
empresa.
Se pide realizar un programa que:*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct empleado {
    char nombre_empleado[30];
    char nombre_empresa[20];
    int dni;
    int cuil;
    float sueldo_neto;
} empleado;

typedef struct empresa {
    char nombre[30];
    int c_empleados;
    float total_liquidacion;
} empresa;

void cargar(FILE *a) {
	empleado e;
	
	printf("Ingrese nombre de la empresa (FIN para finalizar):\n");
	fflush(stdin);
	gets(e.nombre_empresa);
	while (strcmp(e.nombre_empresa, "FIN")) {
		printf("Ingrese DNI del empleado (0 para finalizar):\n");
		scanf("%d", &e.dni);
		while (e.dni != 0) {
			printf("Ingrese nombre del empleado:\n");
			fflush(stdin);
			gets(e.nombre_empleado);
			
			printf("Ingrese cuil del empleado:\n");
			scanf("%d", e.cuil);
		
			printf("Ingrese sueldo neto del empleado:\n");
			scanf("%f", &e.sueldo_neto);
			
			fwrite(&e, sizeof(c), 1, a);
			
			printf("Ingrese DNI del empleado (0 para finalizar):\n");
			scanf("%d", &e.dni);
		}
		printf("Ingrese DNI del empleado (0 para finalizar):\n");
		scanf("%d", &e.dni);
	}
}

/*a)Emita un listado ordenado por empresa con la liquidacion 
de haberes de cada empleado. Ademas, el listado debe incluir 
el total a pagar en concepto de sueldo por cada empresa.*/
void listar(FILE *xarchi) {
    empleado e;
    float acum; //para el total a pagar de sueldo por cada empresa
    char aux[30];

    rewind(xarchi);
    fread(&e, sizeof(e), 1, xarchi); //Lectura anticipada
    printf("******LISTADO DE LIQUIDACION*****\n");
    printf("Listado de empleados de %s.\n", e.nombre_empresa);
    while (!feof(xarchi)) {
        if (strcmp(aux, e.nombre_empresa)) {
            printf("DNI: %d, Nombre: %s, Sueldo: %.2f\n", e.dni, e.nombre_empleado, e.sueldo_neto);
            acum += e.sueldo_neto;
        } else {
            printf("Total pagado por %s es $%.2f.\n", e.nombre_empresa, acum);
        }
    }
}

/*b)Generar el archivo “EMPRESAS.dat” que almacena para cada 
empresa la siguiente información: Nombre, total de empleados, 
total pagado en concepto de liquidación.*/
void cargar_empresas(FILE *xarchi, FILE *xarchi2) {
    empleado xe;
    empresa xem;
    char aux[30];
    int cont = 0;

    rewind(xarchi);
    while (fread(&xe, sizeof(xe), 1, xarchi)) {
        strcpy(xe.nombre_empresa, xem.nombre);

        if (strcmp(xe.nombre_empresa, xem.nombre) != 0) {
            cont++;
        } else {
            xem.c_empleados = cont;
            fwrite(&xem, sizeof(xem), 1, xarchi2);
        }
    }
}

int main() {
    FILE *archi, *archi2;
    
    if ((archi = fopen("EMPLEADOS.dat", "w+")) == NULL) {
        printf("ERROR\n");
    } else {
        cargar(archi);
        listar(archi);

        archi2 = fopen("EMPRESAS.dat", "w+");
        cargar_empresas(archi, archi2);

        fclose(archi);
        fclose(archi2);
    }
}
