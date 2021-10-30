/*
 ============================================================================
 Name        : Clase16_MemDin.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int variableGlobal;

void funcionblabla(void)
{
	puts("D");
}

int main(void)
{
	int variableLocal;
	int size=10;
	int* pDireccion=(int*)malloc(sizeof(int));

	printf("El valor float es en dirrreccion %d\n",&variableGlobal);
	printf("El valor float es en dirrreccion %d\n",&variableLocal);
	printf("El valor float es en dirrreccion %d\n",pDireccion);
	printf("El valor float es en dirrreccion %d\n",funcionblabla);


	int* pNuevoEspacio=realloc(pDireccion,sizeof(int)*size);//PIDO PARA MAS PARA 5
	if(pNuevoEspacio!=NULL)//SI ME CONSIGUIO EL ESAPACIO
	{
		pDireccion=pNuevoEspacio;//LE ASIGNOP EL PUNTERO
		printf("El valor float es en dirrreccion %d\n",pDireccion);
	}
	free(pDireccion);//	LIBERAR EL ESPACIO
	pDireccion=NULL;//BORRAR EL PUNETRO PARA NO PODER USARLO




	/*
	//malloc devuelve un puntero tipo (void*)
	float* pDireccion=(float*)malloc(sizeof(float));//me devuelve la direccion de memoria
	printf("Dirrrecion de memoria allocada%d\n ",pDireccion);

	*pDireccion=3.14;

	printf("El valor float es en dirrreccion %f\n",*pDireccion);
	//printf("El valor int es en dirrreccion %d\n",*pDireccion);//NO MAL COCEPTUAL ersto no interpreta como float
	*/

	//ARRAY DE 10 FLOAT
/*
	float* pDireccion=(float*)malloc(sizeof(float)*10); //direcion donde empieza el array

	pDireccion[3]=3.14;//ESTA SINTAXIUS YA SE DESPLAZA 3 X4 BITS
	printf("Dirrrecion de memoria allocada%d\n ",pDireccion);
	printf("Dirrrecion de memoria allocada%d\n ",pDireccion+1);//+1 SUMA 4 BITS
	*(pDireccion+2)=3,29;//ESCRIBO EN LA DOS
	printf("Dirrrecion de memoria allocada%f\n ",pDireccion[3]);
	printf("Dirrrecion de memoria allocada%f\n ",pDireccion+2);
*/

	return EXIT_SUCCESS;
}
