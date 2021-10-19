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

static int dameUnIdNuevoA(void);

/**
* \brief Modifica un arcade con las opciones pedidas
* \param recibe un estructura por puntero, el largo
* \return Retorna -1 todo mal 0 todo bien
*/
 int modificarUnArcade(eArcade *pArcade, int len)
 {
	 int retorno=-1;
	 int idamodificar;
	 int posicion;
	 char bufferNomJuA[64];
	 int bufferCantJugA;
	 int opcion;

	 if(pArcade!=NULL && len>0)
	 {
		 imprimirArcadeCargado(pArcade,len);
		 pedirInt(&idamodificar,"Ingrese Id a modificar","Error Id no valido",MINIMO,CAN_ARCADE,INTENTOS);
		 posicion=buscarPosicionDeArcadeporSuId(pArcade, len, idamodificar);
		 if (posicion>=0)
			 {
			 do
				 {
					 puts("INGRESE OPCION A MOFIFICAR");
					 imprimirMenuModificar();
					 pedirInt(&opcion, "INGRESE OPCION A MOFIFICAR", "Ingrese entre 1 y 3",MINIMO,MAXIMO3,INTENTOS);
					 switch (opcion)
					 {
						case 1:
							pedirInt(&bufferCantJugA,"Ingrese Cantidad de Jugadores","Ingrese tipo valido",MINIMO,MAXIMO10,INTENTOS);
							pArcade[posicion].cantidadJugadorArcade=bufferCantJugA;
							break;
						case 2:
							imprimirListaJuegos(pArcade, CAN_ARCADE);
							pedirText(bufferNomJuA,sizeof(pArcade->nombreJuego),"Ingrese el Nombre del Juego","Nombre no valido",INTENTOS);
							strncpy(pArcade[posicion].nombreJuego,bufferNomJuA,sizeof(pArcade[posicion].nombreJuego));
							break;
						default:
							break;
					 }
					 imprimirUnArcadeCargado(pArcade,len,pArcade[posicion].idSalon);
					 retorno=0;
				 }while(opcion<3);
			 }else
				 puts("Id no Valido");
		 }else
			 puts("No se ha podido procesar");
	 return retorno;
 }
/**
* \brief da de alta un salon en el array de arcade
* \param recibe un array de estructura, el largo
* \return Retorna -1 todo mal 0 todo bien
*/
int altaArcade(eArcade *pArcades,eSalon *pSalones,int lenA,int lenS)
{
	int retorno=-1;
	int libre;
	if(pArcades!=NULL && lenA>0 && pSalones!=NULL&&lenS>0)
	{
		libre=buscarLugarLibreArrayA(pArcades, CAN_ARCADE);
		if(libre>=0)
			{
				if(pedirDatosArcade(&pArcades[libre], pSalones, lenA, lenS)==0)
					{
					retorno=0;
					puts("Se ha completado la carga");
					}else
						puts("No se ha completado la carga");
			}else
				puts("No hay espacio libre en el array");
	}else
		 puts("No se ha podido procesar");
return retorno;
}
/**
* \brief caraga de datos para Dar de alta un arcde
* \param recibe un estructura por puntero y el largo
* \return Retorna 0 si se logor carga  y -1  si no
*/
int pedirDatosArcade(eArcade *pArcades,eSalon *pSalones,int lenA,int lenS)
{
	int estado=-1;
	char bufferNacA[24];
	char bufferNomJuA[64];
	int bufferTipoSonA;
	int bufferCantJugA;
	int bufferCantMAxFA;
	int idSalon;
	if(pArcades!=NULL && lenA>0 && pSalones!=NULL&&lenS>0)
		{
		 if(pedirInt(&bufferTipoSonA,"Ingrese tipo Sonido Mono 1 y Stereo 2", "Ingrese tipo valido",MONO,STEREO,INTENTOS)==0)
		 	 {
			  if(pedirText(bufferNomJuA, sizeof(pArcades->nombreJuego),"Ingrese el Nombre del Juego","Nombre no valido",INTENTOS)==0)
			  	  {
				  if(pedirText(bufferNacA, sizeof(pArcades->nacionalidadArcade), "Ingrese la Nacionalidad", "Nacionalidad invalido",INTENTOS)==0)
				   	  {
					  if(pedirInt(&bufferCantJugA,"Ingrese Cantidad de Jugadores","Ingrese Cantidad valido",MINIMO,MAXIMO10,INTENTOS)==0)
					  	  {
						  if(pedirInt(&bufferCantMAxFA,"Ingrese Cantidad Maxima de fichas", "Ingrese tipo valido",MAXIMO10,MAXIMO500,INTENTOS)==0)
						  	  {
							 imprimirSalonCargado(pSalones,lenS);
			    			 if(pedirInt(&idSalon,"Ingrese Salon","Ingrese Salon valida",MINIMO,CAN_SALON,INTENTOS)==0 && buscarPosicionDeSalonporSuId(pSalones,lenS,idSalon)>=0)
			    			 {
			    			 pArcades->tipoSonidoArcade=bufferTipoSonA;
			    			 pArcades->capMaxFichaArcade=bufferCantMAxFA;
			    			 pArcades->cantidadJugadorArcade=bufferCantJugA;
			    			 strncpy(pArcades->nombreJuego,bufferNomJuA,sizeof(pArcades->nombreJuego));
			    			 strncpy(pArcades->nacionalidadArcade,bufferNacA,sizeof(pArcades->nacionalidadArcade));
			    			 pArcades->idSalon=idSalon;
			    			 pArcades->idArcade=dameUnIdNuevoA();
			    			 pArcades->isEmptyArcade=OCUPADO;
			    			 estado=0;
			    			 }else
			    			puts("Salon Invalido");
			    		 }
					  	 }
			    	 }
			  	  }
			  }
	   }else
			 puts("No se ha podido procesar");
   return estado;
}
/**
* \brief busca el primer index del array con flag emty
* \param recibe un estructura por puntero y el largo
* \return Retorna lugar el primer lugar libre de la lista o -1 si no encuentra ninguno libre
*/
int buscarLugarLibreArrayA(eArcade *pArcades, int len)
{
	int retorno=-1;
	if(pArcades!=NULL && len>0)
	{
		for (int i=0;i<len;++i)
		{
			if(pArcades[i].isEmptyArcade==LIBRE)
			{
				retorno=i;
				break;
			}
		}
	}else
		 puts("No se ha podido procesar");
	return retorno;
}
/**
* \brief elimina un arcade, imprime lista y da la baja pidiendo confirmacion
* \param recibe un estructura por puntero, el largo
* \return Retorna si logor eliminar y -1 si no
*/
int eliminarArcadeDeLista(eArcade *pArcades,int lenArcade)
{
	int retorno=-1;
	int idBaja;
	int auxPosArcade;
	int confirmar;
	if(pArcades!=NULL && lenArcade>0)
	{
		imprimirArcadeCargado(pArcades, CAN_ARCADE);
		pedirInt(&idBaja, "Ingrese ID de ARCADE a dar de baja", "Ingrese ID valido",MINIMO,CAN_ARCADE,INTENTOS);
		auxPosArcade=buscarPosicionDeArcadeporSuId(pArcades, CAN_ARCADE,idBaja);
		if(pArcades[auxPosArcade].isEmptyArcade==OCUPADO && auxPosArcade>=0)
		{

			printf("Esta por dar de baja este Arcade\n");
			imprimirUnArcadeCargado(pArcades, lenArcade, pArcades[auxPosArcade].idArcade);
			pedirInt(&confirmar, "Para confirma la baja ingrese 1 sino 2","Ingrese 1 o 2", MINIMO,2,INTENTOS);
			if(confirmar==1)
			{
				bajaLogicaDeUnArcade(pArcades, CAN_ARCADE, idBaja);
				retorno=0;
			}else
				puts("Se ha cancelado el pedido baja");
			puts("LA LISTA DE ARCDES HA QUEDADO ASI");
			imprimirArcadeCargado(pArcades, CAN_ARCADE);
		}else
			puts("Debe ingresar un Id de Arcade valido");
	}else
		 puts("No se ha podido procesar");
	return retorno;
}
 /**
 * \brief Da de baja en forma logica un ID de arcade = Emty
 * \param recibe un estructura por puntero, el largo y el id a dar de baja
 * \return Retorna -1 salio mal 0 todo bien
 */
 int bajaLogicaDeUnArcade(eArcade *pArcades,int len,int idabajar)
 {
	 int retorno=-1;
	 int posicion;
	 posicion=buscarPosicionDeArcadeporSuId(pArcades, CAN_ARCADE,idabajar);
	if(pArcades!=NULL && posicion>=0 && len>0)
	 {
		 pArcades[posicion].isEmptyArcade=LIBRE;
		 retorno=0;
	 }else
		 puts("No se ha podido procesar");
	 return retorno;
 }
/**
* \brief Busca  un Arcade recibiendo como parámetro de búsqueda el Id de pantalla.
* \param  *parcade recibo array por referencia,len tamaño del array, id
* \return Retorna la posicion en el array del id solicitado o -1 si el no exixte
*/
int buscarPosicionDeArcadeporSuId(eArcade *pArcades,int len,int id)
{
	int retorno=-1;
		if(pArcades!=NULL && len>0)
		{
			for (int i=0;i<len;++i)
			{
				if(pArcades[i].idArcade==id && pArcades[i].isEmptyArcade==OCUPADO)
				{
					retorno=i;
					break;
				}
			}
		}else
			 puts("No se ha podido procesar");
		return retorno;
}
/**
* \brief Ordena el array de Salon por orden alfabetico ascendente de nombren de juego
* \param recibe un array de estructura, el largo
* \return Retorna -1 todo mal 0 todo bien
*/
int ordenaArcadePorNombreJuego(eArcade *pArcades, int len)
{
	int banderaSwapp=-1;
	eArcade auxiliar;
	int limite=len;
	int estadostrcmp;
	if(pArcades!=NULL && len>0)
	{
		do
		{
			banderaSwapp=0;
			limite=limite-1;
			for (int i=0; i<limite; i++)
			{
				estadostrcmp=strcmp(pArcades[i].nombreJuego, pArcades[i+1].nombreJuego);
				if(estadostrcmp>0)
				{
					banderaSwapp=1;
					auxiliar=pArcades[i];
					pArcades[i]=pArcades[i+1];
					pArcades[i+1]=auxiliar;
				}
			}
		}while(banderaSwapp==1);
	}else
		 puts("No se ha podido procesar");
	return banderaSwapp;
}
/**
* \brief busca e Imprime el array Arcade cargado con datos flag busy
* \param recibe un estructura por puntero y el largo
* \return Retorna cantidad de cargados y -1  si no hay
*/
int imprimirArcadeCargado(eArcade *pArcades, int len)
{
	int estado=-1;
	int contadordeCargados=0;
	ordenaArcadePorNombreJuego(pArcades, CAN_ARCADE);
	printf("____________________________________________________________________________________________________________\n");
	printf("Id Nacionalidad de Arcade\t  Nombre Juego\t\t\tSonido Jugadores Max.Fichas Id Salon\n");
	printf("____________________________________________________________________________________________________________\n");
	if (pArcades!=NULL && len>0)
	{
		for (int i= 0;  i< len; i++)
		{
			if(pArcades[i].isEmptyArcade==OCUPADO)
			{
				printf(" %d %-30s %-30s %d\t%d\t  %d\t\t%d\n",
				pArcades[i].idArcade,pArcades[i].nacionalidadArcade,pArcades[i].nombreJuego,pArcades[i].tipoSonidoArcade,pArcades[i].cantidadJugadorArcade,
				pArcades[i].capMaxFichaArcade,pArcades[i].idSalon);
				contadordeCargados++;
			}
		}
		printf("___________________________________________________________________________________________________________\n");
		estado=contadordeCargados;
		if(contadordeCargados==0)
			{
				puts("NO HAY DATOS CARGADOS");
			}
	}else
		 puts("No se ha podido procesar");
	return estado;
}
/**
* \brief imprime un arcade  cargado con datos flag busy
* \param recibe un estructura por puntero,el id y el largo
* \return Retorna 0 todo bien  y -1  si no
*/
int imprimirUnArcadeCargado(eArcade *pArcades,int len,int idmostrar)
{
	int estado=-1;
	int posicion;
	posicion=buscarPosicionDeArcadeporSuId(pArcades, len, idmostrar);
	printf("____________________________________________________________________________________________________________\n");
	printf("Id Nacionalidad de Arcade\t  Nombre Juego\t\t\tSonido Jugadores Max.Fichas Id Salon\n");
	printf("____________________________________________________________________________________________________________\n");
	if (pArcades!=NULL && len>0 && idmostrar>0 && pArcades[posicion].isEmptyArcade==OCUPADO)
	{
		printf(" %d %-30s %-30s %d\t%d\t  %d\t\t%d\n",
		pArcades[posicion].idArcade,pArcades[posicion].nacionalidadArcade,pArcades[posicion].nombreJuego,pArcades[posicion].tipoSonidoArcade,pArcades[posicion].cantidadJugadorArcade,
		pArcades[posicion].capMaxFichaArcade,pArcades[posicion].idSalon);
		printf("___________________________________________________________________________________________________________\n");
		estado=0;
	}else
		puts("NO HAY DATOS CARGADOS");
	return estado;
}
/**
 * \brief inicializa todas las posiciones del array arcades como Libres pone la bander isEmpty en -1
 * \param  *plist recibo array por referencia, len tamaño del array
 * \return Retorna 0 si todo bien y -1 si no logro inicializar el array
 */
int iniciarEarrayA(eArcade *pArcades,int len)
{
	int estado=-1;
	   if (pArcades!=NULL && len>0)
	   {
		  for (int j = 0;  j<len; j++)
		   {
			  pArcades[j].isEmptyArcade=LIBRE;
			  estado=0;
		   }
	   }else
			 puts("No se ha podido procesar");
	   return estado;
}
/**
 * \brief busca cantidad de posiciones ocupadas en el array
* \param *plistEmployee recibo array por referencia, len tamaño del array
* \return Retorna cantidad de lugares o -1 si no encuentra ninguno lugar ocupados
 */
int largoArrayA(eArcade *pArcades,int len)
{
	int retorno=-1;
	int contBusy=0;
	if(pArcades!=NULL && len>0)
	{
		for (int i=0;i<len;++i)
		{
			if(pArcades[i].isEmptyArcade==OCUPADO)
			{
				contBusy++;
			}
		}
		if(contBusy>0)
		{
			retorno=contBusy;
		}
	}else
		 puts("No se ha podido procesar");
	return retorno;
}
/**
  * \brief me da un id consecutivo y no repetido memorizando el ultimolvalor
  * \param void
  * \return Retorna 0 si todo bien  y -1 si no numero de id
  */
static int dameUnIdNuevoA(void)
{
	static int contador=0;
	contador++;
	return contador;
}
/**
  * \brief da de baja los arcades de un salon por el id salon
  * \param pSalones, lenS, *pArcades lenA id Salon Baja
  * \return Retorna 0 si todo bien  y -1 si no numero de id
  */
int bajaArcadesDeUnSalon(eSalon *pSalones,int lenS,eArcade *pArcades,int lenA, int idSBaja)
 {
 	int retorno=-1;
 	if(pSalones!=NULL && lenA>0)
 	{
 		for (int i=0;i<lenA;++i)
 			{
 				if(pArcades[i].idSalon==idSBaja)
 				{
 					bajaLogicaDeUnArcade(pArcades,lenA,pArcades[i].idArcade);
 				}
 			}
 			retorno=0;
 	}else
 		 puts("No se ha podido procesar");
 	return retorno;
 }
/**
 * \brief Se imprime la lista de salas listando ID, nombre y dirección.
 * Se ingresa un ID y la misma generará la baja del salón,
 * junto con todos los arcades que lo componen.
 * \param recibe un estructura por puntero, el largo
 * \return Retorna si logor eliminar y -1 si no
 */
 int bajaDeSalonYsusArcadesDeLista(eSalon *pSalones,int lenS,eArcade *pArcades,int lenA)
 {
 	int retorno=-1;
 	int idSBaja;
 	int auxPos;
 	if(pSalones!=NULL && lenA>0)
 	{
 		imprimirSalonCargado(pSalones, lenS);
 		pedirInt(&idSBaja, "Ingrese ID de SALON a dar de baja", "Ingrese ID valido",MINIMO,CAN_SALON,INTENTOS);
 		auxPos=buscarPosicionDeSalonporSuId(pSalones, lenS, idSBaja);
 		if(auxPos>=0)
 		{
 			bajaLogicaDeUnSalon(pSalones,lenS,idSBaja);
 			for (int i=0;i<lenA;++i)
 			{
 				if(pArcades[i].idSalon==idSBaja)
 				{
 					bajaLogicaDeUnArcade(pArcades,lenA,pArcades[i].idArcade);
 				}
 			}
 			puts("SE HAN ELIMINADO EL SALON Y SUS ARCADES CORRESPONDIENTES");
 			retorno=0;
 		}else
 			puts("Debe ingresar un Id de Salon valido");
 		imprimirSalonCargado(pSalones, lenS);
 	}else
 		 puts("No se ha podido procesar");
 	return retorno;
 }
