/*
 * parser.c
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

/*
 *brief Parsea los datos los datos de arcdes el archivo *.csv (modo texto).
 *param *PFile al archivo, *pArray a la LInkedList
 *return 0 si lo logro la carga y -1 si salio mal
 */
int parser_ArcadeFromText(FILE* pFile , LinkedList* pLinkedList)
{
	int retorno=-1;
	int paso=0;
	Arcade* pAuxiliarArcade;
	char idArcade[4];
	char nacionalidad[64];
	char tipoSonido[24];
	char cantidadJugadores[4];
	char capMaxFichas[4];
	char salon[64];
	char nombreJuego[64];
	if(pFile!=NULL && pLinkedList!=NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
				idArcade,nacionalidad,tipoSonido,cantidadJugadores,capMaxFichas,salon,nombreJuego);// salteo la 1era
		do
		{
			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
					idArcade,nacionalidad,tipoSonido,cantidadJugadores,capMaxFichas,salon,nombreJuego)==7)
				{
				pAuxiliarArcade=arcade_newParametros(idArcade,nacionalidad,tipoSonido,cantidadJugadores,capMaxFichas,salon,nombreJuego);
				if(pAuxiliarArcade!=NULL)
					ll_add(pLinkedList, pAuxiliarArcade);
				}else
					break;
		paso++;
		}while(feof(pFile)==0 );
		retorno=0;
		printf("Se han agregado a la lista %d arcadess\n",paso);
	}else
		puts("No se ha podido cargar la informacion desde *.csv");
return retorno;
}

