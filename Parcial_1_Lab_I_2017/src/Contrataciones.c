/*
 * Contrataciones.c
 *
 *  Created on: 12 oct. 2021
 *      Author: usuario
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

#include "Pantalla.h"
#include "Pedir.h"
#include "Contrataciones.h"
#include "Menu.h"
#include "Info.h"

#define TAMANO_ARRAY 10
#define OCUPADO 0
#define LIBRE -1
#define MINIMO 1
#define MAXIMO 11
#define INTENTOS 3
#define MES 30

static int dameUnIdNuevo2(void);
//=========================================================================
/**
 * \brief inicializa todas las posiciones del array contrato como Libres pone la bander isEmpty en -1
 * \param  *plist recibo array por referencia, len tamaño del array
 * \return Retorna 0 si todo bien y -1 si no logro inicializar el array
 */
int iniciarEarrayC(Contrataciones *plistContrato,int len)
{
	int estado=-1;
	   if (plistContrato!=NULL && len>0)
	   {
		  for (int j = 0;  j<len; j++)
		   {
			  plistContrato[j].flagEmptyC=LIBRE;
			  estado=0;
		   }
	   }
	   return estado;
}
//=============================================================================
/**
* \brief da de alta una contratacion de un Display
* \param recibe un array de estructura, el largo
* \return Retorna -1 todo mal 0 todo bien
*/
int altaContrato(Contrataciones *pContrato,Display *pDispay, int len)
{
	int retorno=-1;
	int libre;
	if(pContrato!=NULL && len>0)
	{
		libre=buscarLugarLibreContrato(pContrato, TAMANO_ARRAY);
		if(buscarLugarLibreContrato(pContrato, TAMANO_ARRAY)>=0)
			{
				if(disp_loadContrato(&pContrato[libre], pDispay, TAMANO_ARRAY)==0)
				{
					puts("Se ha completado la carga");
				}else
				{
					puts("No se ha completado la carga");
				}
			}else
				{
					puts("No hay espacio libre en el array");
				}
	}
	retorno=0;
return retorno;
}
//=============================================================================
/**
* \brief Pide los datos para el alta una cotratacion de un display
* \param recibe un estructura por puntero y el largo
* \return Retorna 0 si se logor carga  y -1  si no
*/
int disp_loadContrato(Contrataciones *pContrato, Display * pDispla, int len)
{
	int estado=-1;
	char bufferCuit[32];
	char bufferNameArch[128];
	int cantidadDias;
	int idPantalla;
	   if(pContrato!=NULL && len>0)
	   {
		   if(pedirUnCUIT(bufferCuit,  sizeof(pContrato->cuit), "Ingrese CUIT-Sin espacios", "Ingrese tipo valido", INTENTOS)==0)
		    {
			     if(pedirInt(&cantidadDias, "Dias de la publicacion", "Ingrese menos de 30", MINIMO, MES,INTENTOS)==0)
			     {
			    	 if(pedirText(bufferNameArch, sizeof(pContrato->nombreArchivo), "ingrese el nombre del archivo", "Nombre invalido",INTENTOS)==0)
			    		 {
			    		 imprimirDisplayCargado(pDispla, len);
			    		 if(pedirInt(&idPantalla, "Ingrese Pantalla a contratatr", "Ingrese pantala valida", MINIMO, len, INTENTOS )==0)
			    		 {
			    			 strncpy(pContrato->cuit, bufferCuit,sizeof(pContrato->cuit));
			    			 pContrato->cantidadDias=cantidadDias;
			    			 strncpy(pContrato->nombreArchivo, bufferNameArch,sizeof(pContrato->nombreArchivo));
			    			 pContrato->idContratacion=dameUnIdNuevo2();
			    			 pContrato->flagEmptyC=OCUPADO;
			    			 pContrato->id=idPantalla;
			    			 estado=OCUPADO;
			    		 }

			    	 }
			     }
		   }
	   }
	   return estado;
}
//===========================================================================
/**
 * \brief busca cantidad de posiciones ocupadas en el array
* \param *plistEmployee recibo array por referencia, len tamaño del array
* \return Retorna cantidad de lugares o -1 si no encuentra ninguno lugar ocupados
 */
int largoArrayC(Contrataciones *plistContra,int len)
{
	int retorno=-1;
	int contBusy=0;
	if(plistContra!=NULL && len>0)
	{
		for (int i=0;i<len;++i)
		{
			if(plistContra[i].flagEmptyC==OCUPADO)
			{
				contBusy++;
			}
		}
		if(contBusy>0)
		{
			retorno=contBusy;
		}
	}
	return retorno;
}
//===================================================================================
/*
 * 7) Consulta facturación: Se deberá ingresar el cuit del cliente y se deberá listar el importe
a​ ​ pagar​ ​ por​ ​ cada​ ​ contratación
 */
/**
* \brief busca el cuil e imprime los costos por pantalla
* \param recibe un estructura por puntero, el largo y el idbuscado
* \return Retorna posicion en el array del id buscado o -1 si no lo alla
*/
int buscarPorCuityOperar(Contrataciones *pContra, Display *pDisplay, int len, char cuitBusacado[])
{
	int retorno=-1;
	int contcuit=0;
	int posPantalla;
	float importe;
	if(pContra!=NULL && len>0)
	{
		for (int i=0;i<len;++i)
		{
			if(strcmp(pContra[i].cuit, cuitBusacado)==0 && pContra[i].flagEmptyC==OCUPADO)
			{
				printf("\n\t%d \t%d \t%d \t%s \t%s \t%d\n",
					pContra[i].flagEmptyC,pContra[i].id,pContra[i].cantidadDias,
					pContra[i].cuit,pContra[i].nombreArchivo,pContra[i].idContratacion);
				contcuit++;
				posPantalla=buscarUnIdDisplay(pDisplay, len,pContra[i].id);
				importe=pContra[i].cantidadDias*pDisplay[posPantalla].price;
				printf("\nEL IMPORTE A PAGAR POR ESTA PUBLICACION ES %.2f\n",importe);
			}
		}
		retorno=0;
	}
	return retorno;
}
//==============================================================================
/*
 * 6) Cancelar contratación: ​ Se pedirá que se ingrese el cuit del cliente y se listaran todas las
pantallas de video que el cliente tiene contratadas mostrando todos sus campos. Luego
ingresar​ ​ el​ ​ ID​ ​ de​ ​ la​ ​ pantalla​ ​ de​ ​ la​ ​ cual​ ​ se​ ​ quiere​ ​ cancelar​ ​ la​ ​ contratación
 */
/**
* \brief busca contrato por cuil e imprime pantallas contratadas y da de baja pantalla contatada
* \param recibe un estructura por puntero, el largo y el idbuscado
* \return Retorna posicion en el array del id buscado o -1 si no lo alla
*/
int buscarPorCuityBajarPantalla(Contrataciones *pContra, Display *pDisplay, int len, char cuitBusacado[])
{
	int retorno=-1;
	int posPantalla;
	int idBaja;
	if(pContra!=NULL && len>0)
	{
		printf("\nFlagEmpt\t Id\t Type\t Price\t Name\t Address\t\n");
		for (int i=0;i<len;++i)
		{
			if(strcmp(pContra[i].cuit, cuitBusacado)==0 && pContra[i].flagEmptyC==OCUPADO)
			{

				posPantalla=buscarUnIdDisplay(pDisplay,len,pContra[i].id);

				printf("\n\t%d \t%d \t%d \t%.2f \t%s \t%s\n",
					pDisplay[posPantalla].flagEmpty,pDisplay[posPantalla].id,pDisplay[posPantalla].type,
					pDisplay[posPantalla].price,pDisplay[posPantalla].name,pDisplay[posPantalla].address);
			}
		}
		pedirInt(&idBaja, "Ingrese ID de pantalla a dar de baja", "Ingrese ID valido", MINIMO, TAMANO_ARRAY, INTENTOS);
		bajaLogicaUnContrato(pContra, TAMANO_ARRAY, idBaja);
		retorno=0;
	}
	return retorno;
}
//=========================================================================
 /**
 * \brief Da de baja en forma logica un ID = Emty
 * \param recibe un estructura por puntero, el largo y el id a dar de baja
 * \return Retorna -1 salio mal 0 todo bien
 */
 int bajaLogicaUnContrato(Contrataciones *pContrato, int len, int idabajar)
 {
	 int retorno=-1;
	 int posicion;
	 printf("\n int idabajar %d\n",idabajar);
	 posicion=buscarUnIdPantallaContrato(pContrato, len, idabajar);
	 printf("\nposicion dice %d\n",posicion);
	 if(pContrato!=NULL && posicion>=0 && len>0)
	 {
		 pContrato[posicion].flagEmptyC=LIBRE; // podemos hacer un estados de baja para llevar un control
		 retorno=0;
	 }
	 return retorno;
 }
//==========================================================================================
/**
* \brief Busca  un contrato recibiendo como parámetro de búsqueda el Id de pantalla.
* \param  *plistEmployee recibo array por referencia,len tamaño del array, id
* \return Retorna la posicion en el array del id solicitado o -1 si el no exixte
*/
int buscarUnIdPantallaContrato(Contrataciones *pContrato,int len,int id)
{
	int retorno=-1;
		if(pContrato!=NULL && len>0)
		{
			for (int i=0;i<len;++i)
			{
				if(pContrato[i].id==id && pContrato[i].flagEmptyC==OCUPADO)
				{
					retorno=i;
					break;
				}
			}
		}
		return retorno;
}
//=============================================================================
/**
* \brief busca e Imprime el array Display cargado con datos flag busy
* \param recibe un estructura por puntero y el largo
* \return Retorna 0 si se logor carga  y -1  si no
*/
int imprimirDisplayCargadoC(Contrataciones pContra[], int len)
{
	int estado=-1;
	int contadordeCargados=0;
	if (pContra!=NULL && len>0)
	{
		printf("\nFlagEmpt\t IdPan\t Dia\t CUIT\t NameA\t IdCon\t\n");
		for (int i= 0;  i< len; i++)
		{
			if(pContra[i].flagEmptyC==OCUPADO)
			{
				printf("\n\t%d \t%d \t%d \t%s \t%s \t%d\n",
				pContra[i].flagEmptyC,pContra[i].id,pContra[i].cantidadDias,
				pContra[i].cuit,pContra[i].nombreArchivo,pContra[i].idContratacion);
				contadordeCargados++;
			}
		}
		if(contadordeCargados==0)
			{
				puts("NO HAY DIPLAYS CARGADOS");
			}
	}
	estado=0;
	return estado;
}
//==============================================================================
 /**
 * \brief busca por cuil e imprime contratos y modifica dia de contratacion
 * \param recibe un estructura por puntero, el largo y el idbuscado
 * \return Retorna posicion en el array del id buscado o -1 si no lo alla
 */
 int buscarYModifPorCUIL(Contrataciones *pContra, int len, char cuitBusacado[])
 {
 	int retorno=-1;
 	int contcuit=0;
 	int idDiplayModificar;
 	int posicionIdPantalla;
 	if(pContra!=NULL && len>0)
 	{
 		printf("\nFlagEmpt\t IdPan\t Dia\t CUIT\t NameA\t IdCon\t\n");
 		for (int i=0;i<len;++i)
 		{
 			if(strcmp(pContra[i].cuit, cuitBusacado)==0 && pContra[i].flagEmptyC==OCUPADO)
 			{
 				printf("\n\t%d \t%d \t%d \t%s \t%s \t%d\n",
 					pContra[i].flagEmptyC,pContra[i].id,pContra[i].cantidadDias,
 					pContra[i].cuit,pContra[i].nombreArchivo,pContra[i].idContratacion);
 				contcuit++;
 			}
 		}
 		if(contcuit>0)
 		{
 			do
 			{
 				pedirInt(&idDiplayModificar, "Ingrese ID de pantalla a modificar dias de contratación", "Ingrese ID valido", MINIMO, len, INTENTOS);
 				posicionIdPantalla=buscarUnIdPantallaContrato(pContra, len, idDiplayModificar);
 				if(pContra[posicionIdPantalla].flagEmptyC==OCUPADO && strcmp(pContra[posicionIdPantalla].cuit, cuitBusacado)==0 )
 				{
 				 pedirInt(&pContra[posicionIdPantalla].cantidadDias,"Ingrese cantidad de dias de contratación", "Ingrese dias valido", MINIMO, MES, INTENTOS);
 				 retorno=0;
 				}else
 					puts("Ingresaste id erroneo, volve a intenrlo");
 			}while(pContra[posicionIdPantalla].flagEmptyC==OCUPADO && strcmp(pContra[posicionIdPantalla].cuit, cuitBusacado)!=0);
 		}else
 			puts("El cuit ingresado no posee contrataciones");

 	}
 	return retorno;
 }

//==========================================================================================
/**
* \brief busca el primer index del array con flag emty
* \param recibe un estructura por puntero y el largo
* \return Retorna lugar el primer lugar libre de la lista o -1 si no encuentra ninguno libre
*/
int buscarLugarLibreContrato(Contrataciones *pContrato, int len)
{
	int retorno=-1;
	if(pContrato!=NULL && len>0)
	{
		for (int i=0;i<len;++i)
		{
			if(pContrato[i].flagEmptyC==LIBRE)
			{
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}
//=============================================================================
/**
  * \brief me da un id consecutivo y no repetido memorizando el ultimolvalor
  * \param void
  * \return Retorna 0 si todo bien  y -1 si no numero de id
  */
static int dameUnIdNuevo2(void)
{
	static int contador=0; //varable Global y solo de esta funcio y no olvida el valor mientra corre
	contador++;
	return contador;
}
//============================================================
void harcodearunaltaC(Contrataciones *pContrato, int id,char ciut[], int flagEmtyc,int cantdias, int idContratacion, char nameArch[], int posicion)
{
		strncpy(pContrato[posicion].cuit, ciut,sizeof(pContrato[posicion].cuit));
		pContrato[posicion].cantidadDias=cantdias;
		pContrato[posicion].idContratacion=idContratacion;
		strncpy(pContrato[posicion].nombreArchivo, nameArch,sizeof(pContrato[posicion].nombreArchivo));
		pContrato[posicion].id=id;
		pContrato[posicion].flagEmptyC=OCUPADO;
}
//==============================================================
