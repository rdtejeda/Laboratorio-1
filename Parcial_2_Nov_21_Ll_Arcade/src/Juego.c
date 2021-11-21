/*
 * Juego.c
 *
 *  Created on: 20 nov. 2021
 *      Author: usuario
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

#include "LinkedList.h"//
#include "controller.h"//
#include "arcade.h"//
#include "parser.h"//
#include "pedirValidar.h"//
#include "Menu.h"//
#include "Juego.h"//

#define MONO 1
#define STEREO 2
#define MINIMO 1
#define MAXIMO10 10
#define INTENTOS 3
#define MAXIMO4 4
#define MAXIMO100 100

/**
 * \brief hace la LinkedlistaFiltrada de Juegos activos sin repetir
 * \param  *plinkedlist filtrada *plistaArcades
 * \return Retorna 0 si encontro el cuit y -1 si no lo encuentra
 */
int juego_hacerListaDeJuegos(LinkedList* listaArcades)
{
	int retorno=-1;
	Arcade* auxiliarArcade;
	LinkedList* pLinkedListFiltrada;
	pLinkedListFiltrada=ll_newLinkedList();
	if(listaArcades!=NULL && ll_len(listaArcades)>0 && pLinkedListFiltrada!=NULL)
	{
		for (int j=0;j<ll_len(listaArcades);j++)
		{
			auxiliarArcade=ll_get(listaArcades,j);
			if(juego_estaUnJuegoEnLista(pLinkedListFiltrada,auxiliarArcade->nombreJuego,ll_len(pLinkedListFiltrada))==-1)
			{
				ll_add(pLinkedListFiltrada, auxiliarArcade);
			}
		}
	retorno=0;
	}else
		 puts("No se ha podido procesar");
	controller_ListarJuegos(pLinkedListFiltrada);
	controller_saveJuegosText("Juegos.txt",pLinkedListFiltrada);
	printf("La lista Tiene %d\n",ll_len(pLinkedListFiltrada));
	return retorno;
}
/**
 * \brief busca si un juego ya esta en la listafiltrada de juegos
 * \param  recibe punteros a *pLinkedListfiltrada y el nombre del juego
 * \return Retorna 0 si encontro el juego y -1 si no lo encuentra
 */
int juego_estaUnJuegoEnLista(LinkedList* pLinkedListFiltrada, char* nombreJuego,int size)
{
	int estado=-1;
	Arcade* auxiliarArcade;
	if (pLinkedListFiltrada!=NULL)
		{
		for (int j=0;j<size;j++)
			{
				auxiliarArcade=ll_get(pLinkedListFiltrada,j);
				if(auxiliarArcade!=NULL && strcmp(auxiliarArcade->nombreJuego,nombreJuego)==0)
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
 * \brief funcion pasada por parametro a Filter para definir
 * criterio de filtdao de arcades de mas de un jugador
 * \param  Void*
 * \return Retorna 0 si cumple con la condicion
 *    				y -1 si no
 */
int filtrarCantidadJugadoresMasUno(void* auxArcade)
{
	int estado=0;
	Arcade* pAuxArcade;
	pAuxArcade=(Arcade*)auxArcade;

	if(pAuxArcade->cantidadJugadores>1)//if(((Arcade*)auxArcade)->cantidadJugadores>1)
	{
		estado=1;
	}
	return estado;
}
void actualizarCantidadFichas(void* auxArcade)
{
	Arcade* pAuxArcade;
	pAuxArcade=(Arcade*)auxArcade;
	pAuxArcade->capMaxFichas=pAuxArcade->capMaxFichas*2;//((Arcade*)auxArcade)->capMaxFichas=rand()%1000;

}





