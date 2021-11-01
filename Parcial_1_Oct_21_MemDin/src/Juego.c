/*
 ============================================================================
 Name        : Parcial_1_14Octubre_2021.c
 Author      : Tejeda Roberto
 Version     : 1.1
 Copyright   : Your copyright notice
 Description : Estamos en el año 1990!
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

#include "Pedir.h"
#include "Salon.h"
#include "Arcade.h"
#include "Menu.h"
#include "Juego.h"
#include "Informes.h"

#define CAN_SALON 100
#define CAN_ARCADE 1000
#define OCUPADO 0
#define LIBRE -1
#define INTENTOS 5
#define SHOPPING 1
#define LOCAL 2
#define MONO 1
#define STEREO 2
#define MINIMO 1
#define MAXIMO10 10
#define MAXIMO500 500
#define MAXIMO3 3

/**
 * \brief imprime la lista de eJuegos con juegos  activos sin repetir
 * \param  *pArcade recibo array por referencia, len tamaño del array
 * \return Retorna 0 si encontro el cuit y -1 si no lo encuentra
 */
int imprimirListaJuegos(eArcade* pArcades[],int len)
{
	int estado=-1;
	eJuego listaJuegos[CAN_ARCADE];
	hacerListaDeJuegos(listaJuegos,len,pArcades);
	int contadordeCargados=0;
//	ordenaArcadePorNombreJuego(pArcades, CAN_ARCADE);
	printf("_________________________________________________\n");
	printf("Nombre del Juego\n");
	printf("__________________________________________________\n");
	if(pArcades!=NULL && len>0)
		{
			for (int i= 0;  i< len; i++)
			{
				if(listaJuegos[i].isEmptyJuego==OCUPADO)
				{
					printf("%-30s\n",listaJuegos[i].nombreJuego);
					contadordeCargados++;
				}
			}
			printf("______________________________________________\n");
			estado=0;
			if(contadordeCargados==0)
				{
					puts("NO HAY DATOS CARGADOS");
				}
		}else
			 puts("No se ha podido procesar");
		return estado;
}
/**
 * \brief hace la lista de eJuegos con juegos  activos sin repetir
 * \param  *pJuegos *pArcade recibo array por referencia, len tamaño del array
 * \return Retorna 0 si encontro el cuit y -1 si no lo encuentra
 */
int hacerListaDeJuegos(eJuego *pJuegos,int len,eArcade* pArcades[])
{
	int retorno=-1;
	int j=0;
	int iListaeJuegos=0;

	inicializarListaJuegos(pJuegos, len);
	if(pJuegos!=NULL && len>0 && pArcades!=NULL)
	{
		for (j=0;j<len;j++)
		{
			if(pArcades[j]!=NULL && estaUnJuegoEnLista(pJuegos,len,pArcades[j]->nombreJuego)==-1)
			{
				pJuegos[iListaeJuegos].isEmptyJuego=0;
				strcpy(pJuegos[iListaeJuegos].nombreJuego,pArcades[j]->nombreJuego);
				iListaeJuegos++;
			}
		}
	retorno=0;
	}else
		 puts("No se ha podido procesar");
	return retorno;
}
/**
 * \brief busca un juego en la lista de eJuegoss
 * \param  *peJuegos recibo array por referencia, lenA tamaño del array y el cuit buscado
 * \return Retorna 0 si encontro el juego y -1 si no lo encuentra
 */
int estaUnJuegoEnLista(eJuego *pJuegos, int lenJ, char nombreJuego[])
{
	int estado=-1;
	int j;
	if (pJuegos!=NULL && lenJ>0)
		{
		  for (j=0;j<lenJ;j++)
			  {
				  if(pJuegos[j].isEmptyJuego==0 && strcmp(pJuegos[j].nombreJuego,nombreJuego)==0)
						{
							estado=0;
							break;
						}
			  }
		 }else
			 puts("No se ha podido procesar");
	return estado;
}
/**
 * \brief inicializa todas las posiciones del array contrato como Libres pone la bander isEmpty en -1
 * \param  *peJuegos recibo array por referencia, lenA tamaño del array
 * \return Retorna 0 si todo bien y -1 si no logro inicializar el array
 */
int inicializarListaJuegos(eJuego *pJuegos,int lenJ)
{
	int estado=-1;
	int j;
	   if (pJuegos!=NULL && lenJ>0)
	   {
		  for (j=0;j<lenJ;j++)
		   {
			  pJuegos[j].isEmptyJuego=LIBRE;
			  estado=0;
		   }
	   }else
			 puts("No se ha podido procesar");
return estado;
}
