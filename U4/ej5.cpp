/*Ejercicio 5
Si quieres conseguir un buen trabajo vas a necesitar 
buenas habilidades. Uno de los perfiles profesionales 
más demandados son los programadores, pero ¿qué 
lenguaje de programación merece la pena aprender? 
Aprender a programar te abrirá puertas a otros empleos. 
Son muchas las empresas las que valoran esta habilidad, 
pese a que no sea necesario para el puesto, por la 
agilidad mental que denota. Por todo ello, la 
comunidad de desarrolladores Stack Overflow llevó a 
cabo encuestas sobre las tendencias del sector, sobre 
cuál de los siguientes lenguajes utilizan.

1. Javascript: A pesar de tener nombres similares, 
Javascript no está relacionado con Java. Permite a los 
desarrolladores crear elementos interactivos en los 
sitios web, convirtiéndolo en uno de los lenguajes más 
omnipresentes de la web y el más popular del mundo.

2. HTML: Aunque técnicamente no es un lenguaje de 
programación - es un "lenguaje de marcas" - HTML es la 
base para la estructura de cada sitio web.

3. Cascading Style Sheets, o CSS: Es el lenguaje de 
programación más utilizado para diseñar sitios web y 
aplicaciones basadas en navegadores.

4. Java: Fue inventado originalmente por Sun 
Microsystems en 1991 como lenguaje de programación 
para sistemas de televisión interactiva. Desde la 
compra de Sun, Oracle ha convertido a Java en una 
potencia. El lenguaje de programación es la forma más 
común de construir aplicaciones en Android.

5. Python: Python data de 1989 y es amado por sus fans 
por su código altamente legible. Muchos programadores 
creen que es el lenguaje más fácil de usar.

6. C: Es uno de los lenguajes de programación más 
antiguos aún en uso común, fue creado a principios de 
la década de los 70. En 1978, el legendario manual del 
lenguaje, "The C Programming Language", fue publicado 
por primera vez. 

Esta es a información compartida en una encuesta. Para 
procesarla se ingresa por cada encuestado el número de 
lenguaje elegido. Realizar un programa en C que, 
utilizando solo funciones recursivas, permita:*/

#include <stdio.h>

#define N 6

/*a) Generar un arreglo que cuente para cada lenguaje, 
los encuestados que lo eligieron.*/
void cereo(int a[N], int i) {
	if (i < N) {
		a[i] = 0;
		cereo(a, i + 1);
	}
	return;
}

void carga(int a[N], int i) {
	int cod;
	printf("Elija un lenguaje (0 para finalizar):\n1. Javascript\n2. HTML\n3. CSS\n4. Java\n5. Python\n6. C\n");
	scanf("%d", &cod);
	
	if (cod != 0) {
		a[cod - 1]++;
		carga(a, i + 1);
	}
	return;
}

/*b) Mostrar el/los lenguajes/s que se eligió por 
menos de 4000 encuestados.*/
void mostrar_lenguajes(int a[N], int i) {
	if (i < N) {
		if (a[i] < 4000) {
			printf("Lenguaje %d.", i + 1);
		}
		mostrar_lenguajes(a, i + 1);
	}
}

//c) Indicar el lenguaje más elegido. (suponer único)
void mas_elegido(int a[N], int i, int m, int &j) {
	if (i < N) {
		if (a[i] > m) {
			m = a[i];
			j = i;
		}
		mas_elegido(a, i + 1, m, j);
	}
	return;
}

//d) Mostrar el total de encuestas realizadas.
void total_encuestas(int a[N], int i, int &ac) {
	if (i < N) {
		ac += a[i];
		total_encuestas(a, i + 1, ac);
	}
	return;
}

/*e) Mostrar la cantidad de lenguajes que fueron 
elegidos por menos de 5000 encuestados y cuantos por 
más de 9000 encuestados (hacer una función recursiva 
que devuelva las dos cantidades).*/
void mas_menos(int a[N], int i, int &contMas, int &contMenos) {
	if (i < N) {
		if (a[i] < 5000) {
			contMenos++;
			mas_menos(a, i + 1, contMas, contMenos);
		} else if (a[i] > 9000) {
			contMas++;
			mas_menos(a, i + 1, contMas, contMenos);
		}
		mas_menos(a, i + 1, contMas, contMenos);
	}
	return;
}

int main() {
	int A[N], max = -1, indice, acum = 0, cMas = 0, cMenos = 0;
	
	cereo(A, 0);
	carga(A, 0);
	
	printf("Lenguajes que se eligieron con menos de 4000 encuestados:\n");
	mostrar_lenguajes(A, 0);
	
	mas_elegido(A, 0, max, indice);
	printf("El lenguaje mas elegido fue: %d\n", indice + 1);
	
	total_encuestas(A, 0, acum);
	printf("Total de encuestados: %d\n", acum);
	
	mas_menos(A, 0, cMas, cMenos);
	printf("Cantidad de lenguajes que fueron elegidos por menos de 5000 encuestados: %d\n", cMenos);
	printf("Cantidad de lenguajes que fueron elegidos por mas de 9000 encuestados: %d\n", cMas);
}
