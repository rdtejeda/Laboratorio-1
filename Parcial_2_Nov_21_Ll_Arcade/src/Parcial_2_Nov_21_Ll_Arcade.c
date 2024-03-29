/*============================================================================
 Name        : Parcial_2_Nov_21_Ll_Arcade.c
 Author      : Tejeda Roberto
 Version     :	1.1
 Copyright   : Your copyright notice
 Description : LinkedList de Arcades
 ============================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

#include "LinkedList.h"
#include "controller.h"
#include "arcade.h"
#include "parser.h"
#include "pedirValidar.h"
#include "Menu.h"
#include "Juego.h"

int main(void)
{
	LinkedList* listaArcades;
	int opcion;
	int estadoCsv=-1;
	listaArcades=ll_newLinkedList();
	if(listaArcades!=NULL)
		{
		estadoCsv=controller_leerArchivo(listaArcades);//1-LEER ARCADES DESDE ARCHIVO
		do
			{
			opcion=imprimirMenuInicial();
			switch (opcion)
				{
				case 1://2- INCORPORAR ARCADE
					controller_AgregarArcade(listaArcades);
					break;
				case 2://3- MODIFICAR ARCADE
					controller_modificarArcade(listaArcades);
					break;
				case 3://4- ELIMINAR ARCADE
					controller_EliminarArcade(listaArcades);
					break;
				case 4://5- IMPRIMIR ARCADES ORDENADOS
					controller_sortArcades(listaArcades);
					break;
				case 5://6-GENERAR ARCHIVO .TXT CON JUEGOS
					controller_ListaDejuegos(listaArcades);
					break;
				case 6://7- GENERAR ARCHIVO .CSV CON ARCDE “Multijugador”(mas de 1 jugador)
					controller_MultiJugador(listaArcades);
					break;
				case 7://8- ACTUALIZAR CANTIDAD MAXIMA DE FICHA DE TODOS LOS ARCADES
					controller_ActualizarMapearCantFichas(listaArcades);
					break;
				case 8://9- GRABAR ARCHIVO .CSV LISTA DEARCADES YOOOO
					controller_saveAsText("arcades.csv", listaArcades);
					break;
				case 9://Del programado JAJA
					//controller_sublist(listaArcades);
					//controller_reduce(listaArcades);
					break;
				default:
					break;
				}
			}while(opcion!=10);//10- SALIR
		controller_shotdown(listaArcades,estadoCsv);
		}
	puts("¡SALIO DE LA APLICACION 'NOMINA DE ARCADES'!");
	puts("!!!Que hay de nuevo viejo!!!");
return EXIT_SUCCESS;
}
