/*Ejercicio 10
Una empresa constructora posee la cantidad de litros de combustible que utilizó cada una de las 20 máquinas 
motoniveladoras en los últimos 12 meses.

Generar una tabla y guardar dicha información, donde las filas representen los meses.

Realizar un programa en C, que usando funciones recursivas muestre:*/
#include <stdio.h>

#define F 3
#define C 4

void carga(float t[F][C], int i, int j)
{
	if (i < F)
	{
		if (j < C)
		{
			printf("Ingrese cantidad de combustible:\n");
			scanf("%f", &t[i][j]);
			carga(t, i, j+1);
		}
		else
		{
			carga(t, i+1, 0);
		}
	}
	return;
}

/*a) La cantidad total de combustible que la empresa utilizó en el mes 5. (La función recursiva solo debe 
recibir como parámetro la fila del mes indicado).*/
float cantidad_combustible(float t[C], int i, float a)
{
	if (i < C)
	{
		a += t[i];
		return cantidad_combustible(t, i + 1, a);
	}
	else
	{
		return a;
	}
}

//b) El gasto promedio de combustible de cada una de las máquinas.
void promedio(float t[F][C], int i, int j, float acum)
{
	if (i < C)
	{
		if (j < F)
		{
			acum += t[j][i];
			promedio(t, i, j+1, acum);
		}
		else
		{
			printf("Gasto promedio de combustible de la maquina %d: %f\n", i + 1, acum/C);
			promedio(t, i+1, 0, 0);
		}
	}
	return;
}

//c) El mes con mayor gasto de combustible de cada una de las máquinas.
void mayor_gasto(float t[F][C], int i, int j, float m, int mes)
{
	if (i < C)
	{
		if (j < F)
		{
			if (t[j][i] > m)
			{
				m = t[j][i];
				mes = j + 1;
			}
			mayor_gasto(t, i, j+1, m, mes);
		}
		else
		{
			printf("El mes con mayor gasto de combustible de la maquina %d: %d\n", i + 1, mes);
			mayor_gasto(t, i+1, 0, -1, -1);
		}
	}
	return;
}
//Principal
int main()
{
	float T[F][C];
	
	carga(T, 0, 0);
	
	float total = cantidad_combustible(T[2], 0, 0);
    printf("La cantidad total de combustible utilizado en el mes es: %.2f\n", total);
	cantidad_combustible(T[4], 0, 0);
	promedio(T, 0, 0, 0);
	mayor_gasto(T, 0, 0, -1, -1);
	
}
