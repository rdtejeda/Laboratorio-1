/*
 * controller.c
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

#include "LinkedList.h"
#include "controller.h"
#include "arcade.h"
#include "parser.h"
#include "pedirValidar.h"
#include "Menu.h"
#include "Juego.h"

#define MONO 1
#define STEREO 2
#define CERO 0
#define MINIMO 1
#define MAXIMO10 10
#define INTENTOS 3
#define MAXIMO4 4
#define MAXIMO500 500

/*
 * brief lee el archivo CSV y realiza la carga inicial de la lista
 * param pLinkedListArcade
 * \return 0 si lo logro la carga y -1 si salio mal
 */
int controller_leerArchivo(LinkedList* listaArcades)
{
	int retorno=-1;
	if(listaArcades!=NULL)
		{
			controller_loadFromText("arcades.csv",listaArcades);
			retorno=0;
		}
		decimeElUltimoIdArcade();
return retorno;
}
/*
 * brief da el alta a un arcade
 * param pLinkedList LinkedList*
 * \return 0 si lo logro la carga y -1 si salio mal
 */
int controller_AgregarArcade(LinkedList* pLinkedList)
{
	int retorno=-1;
	int idNew;
	char idArcadeStr[8];
	char nacionalidad[64];
	int tipoSonido;
	char tipoSonidoStr[8];
	int cantidadJugadores;
	char cantidadJugadoresStr[8];
	int capMaxFichas;
	char capMaxFichasStr[8];
	char salon[64];
	char nombreJuego[64];
	Arcade* pBufferArcade;

	if(pLinkedList!=NULL)
	{
		idNew=dameUnIdNuevoArcade();
		sprintf(idArcadeStr,"%d",idNew);
		pedirNombre(nacionalidad,sizeof(nacionalidad),"Ingrese Nacionalidad del Arcade","Error- La nacionalidad debe empezar con mayuscula",INTENTOS);
		pedirTextoAlfanumerico(salon,sizeof(salon),"Ingrese Nombre del Salon","Error- El nombre debe empezar con mayuscula",INTENTOS);
		pedirTextoAlfanumerico(nombreJuego, sizeof(nombreJuego),"Ingrese Nombre de el Juego","Eror- El nombre debe empezar con mayuscula",INTENTOS);
		pedirInt(&cantidadJugadores, "Ingrese cantidad de jugadores del Arcade","Error - Maximo 10",MINIMO,MAXIMO10,INTENTOS);
		sprintf(cantidadJugadoresStr,"%d",cantidadJugadores);
		pedirInt(&capMaxFichas, "Ingrese cantidad Maxima de Fichas del Arcade","Error- Entre 10 y 100",MAXIMO10,MAXIMO500,INTENTOS);
		sprintf(capMaxFichasStr,"%d",capMaxFichas);
		pedirInt(&tipoSonido,"Ingrese Tipo de Sonido del Arcade 1-MONO o 2-STEREO","Error-Ingrese 1 0 2",MONO,STEREO,INTENTOS);
		if(tipoSonido==1)
		{
			strcpy(tipoSonidoStr,"MONO");
		}else
			{
			strcpy(tipoSonidoStr,"STEREO");
			}
		pBufferArcade=arcade_newParametros(idArcadeStr, nacionalidad, tipoSonidoStr, cantidadJugadoresStr, capMaxFichasStr, salon, nombreJuego);
		if(pBufferArcade!=NULL)
			{
			if(!ll_add(pLinkedList,pBufferArcade))
				{
				puts("Se ha dado de alta al siguiente empleado");
				controller_ListUnArcade(pLinkedList,ll_indexOf(pLinkedList,pBufferArcade));
				retorno=0;
				}else
					puts("No se ha podio agrega a la lista");
			}else
				puts("No se ha podido agregar a la lista");
		controller_saveAsText("arcades.csv", pLinkedList);
	}else
		puts("La lista no esta iniciada");
return retorno;
}
/** \brief Modificar datos de arcade
 * \param pLinkedList LinkedList*
 * \return 0 si lo logro la carga y -1 si salio mal
 */
int controller_modificarArcade(LinkedList* pLinkedList)
{
	int retorno=-1;
	if(pLinkedList!=NULL&&ll_len(pLinkedList)>0)
		{
		controller_ListarArcade(pLinkedList);
		arcade_modificar(pLinkedList);
		controller_saveAsText("arcades.csv", pLinkedList);
		retorno=0;
		}else
			puts("No se puede Editar ya que La Lista esta vacía");
return retorno;
}
/** \brief Elimina un arcade
 * \param pLinkedListEmpleados LinkedList*
 * \return 0 si lo logro la carga y -1 si salio mal
 */
int controller_EliminarArcade(LinkedList* pLinkedList)
{
	int retorno=-1;
	if(pLinkedList!=NULL&&ll_len(pLinkedList)>0)
	{
		controller_ListarArcade(pLinkedList);
		arcade_remover(pLinkedList);
		controller_saveAsText("arcades.csv", pLinkedList);
		retorno=0;
	}else
	puts("No se puede Eliminar ya que La Lista esta vacía");
return retorno;
}
/**
 * \brief hace la LinkedlistaMultijugador con los arcdes de mas de un jugador
 * \param  *plinkedlist
 * \return Retorna 0 si encontro el cuit y -1 si no lo encuentra
 */
int controller_MultiJugador(LinkedList* listaArcades)
{
	int retorno=-1;
	//Arcade* auxiliarArcade; OJOTA
	LinkedList* pLinkedListMultJugador;
	pLinkedListMultJugador=ll_newLinkedList();
		if(listaArcades!=NULL && ll_len(listaArcades)>0 && pLinkedListMultJugador!=NULL)
		{
		pLinkedListMultJugador=ll_filterNewList(listaArcades, filtrarCantidadJugadoresMasUno);
		retorno=0;
		}else
			 puts("No se ha podido procesar");
		controller_ListarArcade(pLinkedListMultJugador);
		controller_saveAsText("Multijugador.csv",pLinkedListMultJugador);
		printf("La lista Tiene %d\n",ll_len(pLinkedListMultJugador));
return retorno;
}
/**
 * \brief actualizar el valor del campo capacidad de fichas
 * de todos los arcades
 * \param  *plinkedlist
 * \return Retorna 0 si encontro el cuit y -1 si no lo encuentra
 */
int controller_ActualizarMapearCantFichas(LinkedList* listaArcades)
{
	int retorno=-1;
	if(listaArcades!=NULL && ll_len(listaArcades)>0)
		{
		ll_map(listaArcades,actualizarCantidadFichas);
		retorno=0;
		controller_ListarArcade(listaArcades);
		}else
			 puts("No se ha podido procesar");
		controller_ListarArcade(listaArcades);
return retorno;
}
/** \brief Listar empleados
 * \param pLinkedListEmpleados LinkedList*
 * \return 0 si lo logro la carga y -1 si salio mal
 */
int controller_ListarArcade(LinkedList* pLinkedList)
{
    int retorno=-1;
	Arcade* pAuxiliarArcde;
	char nacionalidad[64];
	char salon[64];
	char nombreJuego[64];

	if(pLinkedList!=NULL)
    {
    	if(ll_len(pLinkedList)>0)
    	{
    		imprimirEncArcadeCargado();
    		for (int i = 0; i <ll_len(pLinkedList); ++i)//10
			{
				pAuxiliarArcde=ll_get(pLinkedList,i);
				arcade_getNacionalidad(pAuxiliarArcde,nacionalidad);
				arcade_getSalon(pAuxiliarArcde,salon);
				arcade_getNombreJuego(pAuxiliarArcde,nombreJuego);
				printf("%d\t%-30s%d\t\t%d\t%d\t%-30s%-30s\n",arcade_getIdRet(pAuxiliarArcde),nacionalidad,
						arcade_getTipoSonidoRet(pAuxiliarArcde),arcade_getCantidadJugadoresRet(pAuxiliarArcde),
						arcade_getCapFichasRet(pAuxiliarArcde),salon,nombreJuego);
			}
    		imprimirLineaLarga();
			retorno=0;
    	}else
    		puts("No se puede Listar ya que La Lista esta vacía");
    }
return retorno;
}
/** \brief Listar un arcde
 * \param pLinkedList LinkedList*
 * \return 0 si lo logro la carga y -1 si salio mal
 */
int controller_ListUnArcade(LinkedList* pLinkedList,int posicion)
{
    int retorno=-1;
	Arcade* pAuxiliarArcde;
	char nacionalidad[64];
	char salon[64];
	char nombreJuego[64];

	if(pLinkedList!=NULL)
    {
    	if(ll_len(pLinkedList)>0)
    	{
    		imprimirEncArcadeCargado();
    		pAuxiliarArcde=ll_get(pLinkedList,posicion);
			arcade_getNacionalidad(pAuxiliarArcde,nacionalidad);
			arcade_getSalon(pAuxiliarArcde,salon);
			arcade_getNombreJuego(pAuxiliarArcde,nombreJuego);
			printf("%d\t%-30s%d\t\t%d\t%d\t%-30s%-30s\n",arcade_getIdRet(pAuxiliarArcde),nacionalidad,
						arcade_getTipoSonidoRet(pAuxiliarArcde),arcade_getCantidadJugadoresRet(pAuxiliarArcde),
						arcade_getCapFichasRet(pAuxiliarArcde),salon,nombreJuego);

    		imprimirLineaLarga();
			retorno=0;
    	}else
    		puts("No se puede Listar ya que La Lista esta vacía");
    }
return retorno;
}
/** \brief Listar juegos excistenetes en la lista
 * \param pLinkedListEmpleados LinkedList*
 * \return 0 si lo logro la carga y -1 si salio mal
 */
int controller_ListarJuegos(LinkedList* pLinkedList)
{
    int retorno=-1;
	Arcade* pAuxiliarArcde;
	char nombreJuego[64];
	if(pLinkedList!=NULL)
    {
    	if(ll_len(pLinkedList)>0)
    	{
    		imprimirJuegoCargado();
    		for (int i = 0; i <ll_len(pLinkedList); ++i)//10
			{
				pAuxiliarArcde=ll_get(pLinkedList,i);
				arcade_getNombreJuego(pAuxiliarArcde,nombreJuego);
				printf("%s\n",nombreJuego);
			}
    		imprimirLineaLarga();
			retorno=0;
    	}else
    		puts("No se puede Listar ya que La Lista esta vacía");
    }
return retorno;
}
/** \brief Ordenar empleados
 * \param pLinkedListEmpleados LinkedList*
 * \return 0 si lo logro la carga y -1 si salio mal
 */
int controller_sortArcades(LinkedList* pLinkedList)
{
	int retorno=-1;
	int criterio=-1;//OJOTA!!!!!!
	LinkedList* listaOrdenadaJuegos;
	if(pLinkedList!=NULL && ll_len(pLinkedList)>1)
	{
		pedirInt(&criterio, "Para ordenar de Mayor a Menor Ingrese 0\nDe Menor a Mayor Ingrese 1","ERROR - Ingrese 0 o 1",CERO,MINIMO,INTENTOS);
		listaOrdenadaJuegos=ll_clone(pLinkedList);
		ll_sort(listaOrdenadaJuegos,arcade_CriterioOrdenaJuego,criterio);
		controller_ListarArcade(listaOrdenadaJuegos);
		puts("LA LISTA HA SIDO ORDENADA");
		retorno=0;

	}else
		puts("Para poder ordenar la lista debe tener mas de un Empleado");
return retorno;
}
/*
 * brief abre el archivo CSV (modo texto), solicita el parseo y cierra el archivo.
 * param *char path de archivo y *pLinkedList a LinkedList
 * return 0 si lo logro la carga y -1 si salio mal
 */
int controller_loadFromText(char* path , LinkedList* pLinkedList)
{
	int retorno=-1;
	if(path!=NULL && pLinkedList!=NULL)
		{
		FILE* pFileCsv;
		pFileCsv=fopen(path,"r");
		if(pFileCsv!=NULL)
			{
				parser_ArcadeFromText(pFileCsv, pLinkedList);
				fclose(pFileCsv);
				retorno=0;
				puts("La lista se ha cargado desde el *.csv");
			}else
				puts("El archivo CSV no exciste");
		}else
			puts("Parametros erroneos");
return retorno;
}
/*
 * brief Guarda los datos de los arcades en el archivo *.csv (modo texto).
 * param param *char path de archivo y *pLinkedListEmpleados a LinkedList
 * return  0 si lo logro la carga y -1 si salio mal
 */
int controller_saveAsText(char* path , LinkedList* pLinkedList)
{
	int estado=-1;
	char bufferNacionalidad[128];
	char bufferSalon[128];
	char bufferGame[128];
	char bufferTipoSonido[128];
	char mono[5]="MONO";
	char stereo[8]="STEREO";
	int paso=0;
	FILE* pFileCsv;
	Arcade* pAuxiliarArcade;
	pFileCsv=fopen(path,"w");
	if(pFileCsv!=NULL&&path!=NULL&&pLinkedList!=NULL)
	{
		fprintf(pFileCsv,"id,nacionalidad,tipo_sonido,cant_jug,fichas_max,salon,game\n");
		for (int i=0; i<ll_len(pLinkedList); ++i)
		{
			pAuxiliarArcade=ll_get(pLinkedList, i);
			arcade_getNacionalidad(pAuxiliarArcade, bufferNacionalidad);
			arcade_getSalon(pAuxiliarArcade, bufferSalon);
			arcade_getNombreJuego(pAuxiliarArcade, bufferGame);
			if(arcade_getTipoSonidoRet(pAuxiliarArcade)==1)
					{
						strcpy(bufferTipoSonido,mono);
					}else
						{
						strcpy(bufferTipoSonido,stereo);
						}
			paso++;
			fprintf(pFileCsv,"%d,%s,%s,%d,%d,%s,%s\n",arcade_getIdRet(pAuxiliarArcade),bufferNacionalidad,
					bufferTipoSonido,arcade_getCantidadJugadoresRet(pAuxiliarArcade),
					arcade_getCapFichasRet(pAuxiliarArcade),bufferSalon,bufferGame);
		}
		fclose(pFileCsv);
		estado=0;
		printf("Se han guardado en el archivo %d arcades\n",paso);
	}else
		 puts("No se ha podido inizilizar el archivo");

return estado;
}
/*
 * brief Guarda los datos de los empleados en el archivo *.csv (modo texto).
 * param param *char path de archivo y *pLinkedListEmpleados a LinkedList
 * return  0 si lo logro la carga y -1 si salio mal
 */
int controller_saveJuegosText(char* path , LinkedList* pLinkedList)
{
	int estado=-1;
	char bufferGame[128];
	int paso=0;
	FILE* pFileCsv;
	Arcade* pAuxiliarArcade;
	pFileCsv=fopen(path,"w");
	if(pFileCsv!=NULL&&path!=NULL&&pLinkedList!=NULL)
	{
		fprintf(pFileCsv,"game\n");
		for (int i=0; i<ll_len(pLinkedList); ++i)
		{
			pAuxiliarArcade=ll_get(pLinkedList, i);
			arcade_getNombreJuego(pAuxiliarArcade, bufferGame);
			paso++;
			fprintf(pFileCsv,"%s\n",bufferGame);
		}
		fclose(pFileCsv);
		estado=0;
		printf("Se han guardado en el archivo %d arcades\n",paso);
	}else
		 puts("No se ha podido inizilizar el archivo");

return estado;
}
/*
 * brief da la baja del programa chequea el grabdo final y elimina la LinkedList
 * param *pLinkedListEmpleados a LinkedList estado de crag de archivo csv y bin
 * return 0 si todo bien y -1 si salio mal
 */
int controller_shotdown(LinkedList* pLinkedList,int estadocsv)
{
	int retorno=-1;
	if(pLinkedList!=NULL && estadocsv==0)
		{
		juego_hacerListaDeJuegos(pLinkedList);
		controller_MultiJugador(pLinkedList);
		controller_saveAsText("arcades.csv",pLinkedList);
		puts("SE HA GURDADO TODA LA INFORMACION");
		}
	arcade_removeAllList(pLinkedList);
	ll_deleteLinkedList(pLinkedList);
	retorno=0;
return retorno;
}
