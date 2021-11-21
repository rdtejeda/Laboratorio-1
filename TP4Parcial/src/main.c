//SORT		: ORDENAR
//MAP		: Permite Transformar los elementos de una lista
//REDUCE	: Ejecuta una funcion reductora sobre cada elemento, devolviendo como unico resultado un unico valor
//FILTER	: Filtra todos los elementos que cumplan la condicion implementada por la funcion dada

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

typedef struct{
	int nota1;
	int nota2;
	float promedio;
} Alumno;

void SetNota1(void*);
void SetNota2(void*);
void CalcularPromedio(void*);

int OrdenamientoPorPromedio(void*, void*);

int OrdenamientoPorNota1(void*, void*);

int FiltrarPromedioMayor6(void*);

int main(void)
{
	LinkedList* listaAlumnos = ll_newLinkedList();
	Alumno* a;
	LinkedList* listaFiltrada;
	for(int i = 0; i<5; i++)
	{
		a = (Alumno*)calloc(sizeof(Alumno), 1);
		if(a != NULL)
		{
			a->nota1=rand()%10 + 1;
			a->nota2=rand()%10 + 1;
			a->promedio=(float)(((Alumno*)a)->nota1 + ((Alumno*)a)->nota2)/2;
			ll_add(listaAlumnos, a);
		}
	}
	//IMPRIMO LISTA
	for(int i = 0; i<ll_len(listaAlumnos); i++)
	{
	a = ll_get(listaAlumnos, i);
	printf("A%d)\tNota1: %d\tNota2: %d\tPromedio: %.2f\n", i+1, a->nota1, a->nota2, a->promedio);
	}
	puts("___________________________________________________________");
	//MAPEO NOTAS Y PROMEDIO
	ll_map(listaAlumnos, SetNota1);
	ll_map(listaAlumnos, SetNota2);
	ll_map(listaAlumnos, CalcularPromedio);

	//FILTRO PROMEDIOS MAYORES A 6 INCLUSIVE
	//ll_filter(listaAlumnos, FiltrarPromedioMayor6);
	listaFiltrada=ll_filterNewList(listaAlumnos, FiltrarPromedioMayor6);

	//IMPRIMO LISTA
	for(int i = 0; i<ll_len(listaFiltrada); i++)
	{
	a = ll_get(listaFiltrada, i);
	printf("A%d)\tNota1: %d\tNota2: %d\tPromedio: %.2f\n", i+1, a->nota1, a->nota2, a->promedio);
	}
	puts("___________________________________________________________");

	//ORDENO LISTA POR PROMEDIO
	ll_sort(listaFiltrada, OrdenamientoPorNota1, 1);//0 MAYO A MENOR 1 DE menor a mayor

	//IMPRIMO LISTA
	for(int i = 0; i<ll_len(listaFiltrada); i++)
	{
	a = ll_get(listaFiltrada, i);
	printf("A%d)\tNota1: %d\tNota2: %d\tPromedio: %.2f\n", i+1, a->nota1, a->nota2, a->promedio);
	}
	puts("___________________________________________________________");

	return 0;
}

void SetNota1(void* a)
{
	((Alumno*)a)->nota1 = rand()%10 + 1;
}
void SetNota2(void* a)
{
	((Alumno*)a)->nota2 = rand()%10 + 1;
}
void CalcularPromedio(void* a)
{
	((Alumno*)a)->promedio = (float)(((Alumno*)a)->nota1 + ((Alumno*)a)->nota2)/2;
}

int OrdenamientoPorNota1(void* a, void* b)
{
	int rtn = 0;
	if(((Alumno*)a)->nota1 > ((Alumno*)b)->nota1){
		rtn = 1;
	}else{
		if(((Alumno*)a)->nota1 < ((Alumno*)b)->nota1){
			rtn = -1;
		}
	}
	return rtn;
}

int OrdenamientoPorPromedio(void* a, void* b)
{
	int rtn = 0;
	if(((Alumno*)a)->promedio > ((Alumno*)b)->promedio){
		rtn = 1;
	}else{
		if(((Alumno*)a)->promedio < ((Alumno*)b)->promedio){
			rtn = -1;
		}
	}
return rtn;
}
int FiltrarPromedioMayor6(void* a)
{
	int rtn = 1;
	if(((Alumno*)a)->promedio < 5)
	{
		rtn = 0;
	}
	return rtn;
}

/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"

int main(void)
{
	startTesting(1);  // ll_newLinkedList
    startTesting(2);  // ll_len
	startTesting(3);  // getNode - test_getNode
	startTesting(4);  // addNode - test_addNode
	startTesting(5);  // ll_add
	startTesting(6);  // ll_get
	startTesting(7);  // ll_set
	startTesting(8);  // ll_remove
	startTesting(9);  // ll_clear
	startTesting(10); // ll_deleteLinkedList
	startTesting(11); // ll_indexOf
	startTesting(12); // ll_isEmpty
	startTesting(13); // ll_push
	startTesting(14); // ll_pop
	startTesting(15); // ll_contains
	startTesting(16); // ll_containsAll
	startTesting(17); // ll_subList
	startTesting(18); // ll_clone
	startTesting(19); // ll_sort
 return 0;
}

*/































