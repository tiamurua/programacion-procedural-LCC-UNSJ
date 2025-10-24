#include <stdio.h>

#define F 3
#define C 5

void carga(int t[F][C], int i, int j)
{
	if (i < F)
	{
		if (j < C)
		{
			printf("Ingrese Monto:\n");
			scanf("%f", &t[i][j]);
			carga(t, i, j + 1);
		}
		else
		{
			carga(t, i + 1, 0);	
		}
	}
}

/*a) Indicar el monto total financiado para una 
categoría ingresada por teclado.*/
void total_para_categoria(float t[C], int i, int &a)
{
	if (i < C)
	{
		a += t[i];
		total_para_categoria(t, i + 1, a);
	}
	return;
}

/*b) Indicar el monto total financiado para el 
sector de Servicios, sin importar la categoría de 
la empresa.*/
void total_sector_servicios(float t[F][C], int i, int &a)
{
	if (i < F)
	{
		a += t[i][3];
		total_sector_servicios(t, i + 1, a);
	}
	return;
}

/*c) Emitir el total financiado, sin importar la 
categoría/sector.*/
void total(float t[F][C], int i, int j, float &a)
{
	if (i < F)
	{
		if (j < C)
		{
			a += t[i][j];
			total(t, i, j, a);
		}
	}
	return;
}

/*d) Emitir un listado con los montos superiores 
a uno ingresado por teclado, y a continuación los 
inferiores e iguales, indicando sector y 
categoría.*/
void inferiores(float t[F][C], int i, int j, float m)
{
	if (i < F)
	{
		if (j < C)
		{
			printf("Montos superiores al monto ingresado por teclado:\n");
			if (t[i][j] > m)
			{
				printf("%.2f\n", t[i][j]);
			}
			else 
			  if (t[i][j] <= m)
		     	{
				printf("Monto menor o igual al ingresado: %.2f", t[i][j]);
				printf("Sector: %d", j);
				printf("Categoria: %d", i);
		    	}
			inferiores(t, i, j + 1, m);
		}
		else
		{
			inferiores(t, i + 1, 0, m);
		}
	}
	return;
}

//Principal
int main()
{
	float T[F][C], monto, acum3 = 0;
	int categoria, acum = 0, acum2 = 0;
	
	printf("Ingrese una categoria para saber el monto total financiado (1, 2 o 3):\n");
	scanf("%d", &categoria);
	total_para_categoria(T[categoria - 1], 0, acum);
	printf("Monto total financiado para la categoria %d: %.2f\n", categoria, acum);
	
	total_sector_servicios(T, 0, acum2);
	printf("Monto total financiado para el sector de Servicios: %2.f\n", acum2);
	
	total(T, 0, 0, acum3);
	printf("Total financiado: %.2f", acum3);
	
	printf("Ingrese un monto para encontrar inferiores y superiores a el:\n");
	scanf("%f", &monto)
	inferiores(T, 0, 0, monto);
}
