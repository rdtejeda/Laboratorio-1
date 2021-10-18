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
#include "IdArcade.h"
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

/*
 * \brief imprime la lista de arcades para mas de 2 jugadores
 * \param  *pArcade y  +pSalon por referencia, lenA y lenS tamaño del array
 * \return Retorna 0 si encontro arcdes para mas de 2 jugadorees y -1 si no lo encuentra
 */
int informeB(eArcade *pArcades,int lenA,eSalon *pSalones,int lenS)
{
	int retorno=-1;
	int auxposIdSalon;
	if(pSalones!=NULL && lenS>0 && pArcades!=NULL && lenA>0)
	{
		printf("____________________________________________________________________________________________________________________\n");
		printf("Id Jugadores Nombre del juego\t\tSalon\n");
		printf("____________________________________________________________________________________________________________________\n");
		for (int i = 0; i <CAN_ARCADE; ++i)
		{
			if(pArcades[i].isEmptyArcade==OCUPADO && pArcades[i].cantidadJugadorArcade>2)
			{
				auxposIdSalon=buscarPosicionDeSalonporSuId(pSalones, lenS, pArcades[i].idSalon);
				printf("%d\t\%d %-30s %-30s\n",
				pArcades[i].idArcade,pArcades[i].cantidadJugadorArcade,pArcades[i].nombreJuego,pSalones[auxposIdSalon].nombreSalon);
				retorno=0;
			}
		}
	}
return retorno;
}




