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

static int dameUnIdNuevoS(void);

/**
* \brief da de alta un salon en el array de Display
* \param recibe un array de estructura, el largo
* \return Retorna -1 todo mal 0 todo bien
*/
int altaSalon(eSalon *pSalones,int len)
{
	int retorno=-1;
	int libre;
	if(pSalones!=NULL && len>0)
	{
		libre=buscarLugarLibreArrayS(pSalones,CAN_SALON);
		if(libre>=0)
			{
			if(pedirDatosSalon(&pSalones[libre],len)==0)
				{
				imprimirUnSalonCargado(pSalones,len,pSalones[libre].idSalon);
				retorno=0;
				puts("Se ha completado la carga");
				}else
				{
					puts("No se ha completado la carga");
				}
			}else
				{
					puts("No hay espacio libre en el array");
				}
	}else
		 puts("No se ha podido procesar");
return retorno;
}
/**
* \brief caraga de datos para Dar de alta un salon
* \param recibe un estructura por puntero y el largo
* \return Retorna 0 si se logor carga  y -1  si no
*/
int pedirDatosSalon(eSalon *pSalones, int len)
{
	int estado=-1;
	int bufferTipoS;
	char bufferNomS[24];
	char bufferdireccioS[48];
	if(pSalones!=NULL && len>0)
	   {
		   if(pedirInt(&bufferTipoS, "Ingrese tipo Salon Shopping 1 y Salon 2", "Ingrese tipo valido",SHOPPING,LOCAL,INTENTOS)==0)
		   {
			     if(pedirText(bufferNomS, sizeof(pSalones->nombreSalon), "Ingrese el Nombre del Salon", "DNombre no valido",INTENTOS)==0)
			    	 {
			    		 if(pedirText(bufferdireccioS, sizeof(pSalones->direccionSalon), "Ingrese la Direccion del Salon", "Direccion invalido",INTENTOS)==0)
			    		 {

			    			 pSalones->tipoSalon=bufferTipoS;
			    			 strncpy(pSalones->nombreSalon,bufferNomS,sizeof(pSalones->nombreSalon));
			    			 strncpy(pSalones->direccionSalon,bufferdireccioS,sizeof(pSalones->direccionSalon));
			    			 pSalones->idSalon=dameUnIdNuevoS();
			    			 pSalones->isEmptySalon=OCUPADO;
			    			 estado=0;
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
int buscarLugarLibreArrayS(eSalon *pSalones, int len)
{
	int retorno=-1;
	if(pSalones!=NULL && len>0)
	{
		for (int i=0;i<len;++i)
		{
			if(pSalones[i].isEmptySalon==LIBRE)
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
* \brief Se imprime la lista de salas listando ID, nombre y dirección.
* Se ingresa un ID y la misma generará la baja del salón,
* \param recibe un estructura por puntero, el largo
* \return Retorna si logor eliminar y -1 si no
*/
int eliminarSalonDeLista(eSalon *pSalones,int len)
{
	int retorno=-1;
	int idBaja;
	int auxPos;
	if(pSalones!=NULL && len>0)
	{
		imprimirSalonCargado(pSalones, len);
		pedirInt(&idBaja, "Ingrese ID de SALON a dar de baja", "Ingrese ID valido",MINIMO,CAN_SALON,INTENTOS);
		auxPos=buscarPosicionDeSalonporSuId(pSalones, len, idBaja);
		if(auxPos>=0)
		{
			bajaLogicaDeUnSalon(pSalones, len, idBaja);
			retorno=0;
		}else
			puts("Debe ingresar un Id de Salon valido");
		imprimirSalonCargado(pSalones, len);
	}else
		 puts("No se ha podido procesar");
	return retorno;
}
 /**
 * \brief Da de baja en forma logica un ID = Emty
 * \param recibe un estructura por puntero, el largo y el id a dar de baja
 * \return Retorna -1 salio mal 0 todo bien
 */
 int bajaLogicaDeUnSalon(eSalon *pSalones,int len,int idabajar)
 {
	 int retorno=-1;
	 int posicion;
	 posicion=buscarPosicionDeSalonporSuId(pSalones, len, idabajar);
	 if(pSalones!=NULL && posicion>=0 && len>0)
	 {
		 pSalones[posicion].isEmptySalon=LIBRE;
		 retorno=0;
	 }else
		 puts("No se ha podido procesar");
	 return retorno;
 }
/**
* \brief Busca  la posicion en el array de salon de un Salon recibiendo como parámetro de búsqueda el Id.
* \param  *parcade recibo array por referencia,len tamaño del array, id
* \return Retorna la posicion en el array del id solicitado o -1 si el no exixte
*/
int buscarPosicionDeSalonporSuId(eSalon *pSalones,int len,int id)
{
	int retorno=-1;
		if(pSalones!=NULL && len>0)
		{
			for (int i=0;i<len;++i)
			{
				if(pSalones[i].idSalon==id && pSalones[i].isEmptySalon==OCUPADO)
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
* \brief Ordena el array de Salon por orden alfabetico ascendente de nombre
* \param recibe un array de estructura, el largo
* \return Retorna -1 todo mal 0 todo bien
*/
int ordenaSalonPorDireccion(eSalon *pSalones, int len)
{
	int banderaSwapp=-1;
	eSalon auxiliar;
	int limite=len;
	int estadostrcmp;
	if(pSalones!=NULL && len>0)
	{
		do
		{
			banderaSwapp=0;
			limite=limite-1;
			for (int i=0; i<limite; i++)
			{
				estadostrcmp=strcmp(pSalones[i].nombreSalon, pSalones[i+1].nombreSalon);
				if(estadostrcmp>0)
				{
					banderaSwapp=1;
					auxiliar=pSalones[i];
					printf("Salon %s\n",auxiliar.nombreSalon);
					pSalones[i]=pSalones[i+1];
					pSalones[i+1]=auxiliar;
				}
			}
		}while(banderaSwapp==1);
	}else
		 puts("No se ha podido procesar");
	return banderaSwapp;
}
/**
* \brief busca e Imprime el array Salon cargado con datos flag busy
* \param recibe un estructura por puntero y el largo
* \return Retorna cantidad de cargados y -1  si no hay
*/
int imprimirSalonCargado(eSalon *pSalones, int len)
{
	int estado=-1;
	int contadordeCargados=0;
	ordenaSalonPorDireccion(pSalones, CAN_SALON);
	printf("______________________________________________________________________________________________\n");
	printf("\nNombre del Salon\t\tDirección\t\t\tTipo de Salon\tId Salon\n");
	printf("______________________________________________________________________________________________\n");
	if (pSalones!=NULL && len>0)
	{
		for (int i= 0;  i< len; i++)
		{
			if(pSalones[i].isEmptySalon==OCUPADO)
			{
				printf(" %-30s %-30s \t%d\t\t%d\n",
				pSalones[i].nombreSalon,pSalones[i].direccionSalon,pSalones[i].tipoSalon,
				pSalones[i].idSalon);
				contadordeCargados++;
				estado=contadordeCargados;
			}
		}
		printf("______________________________________________________________________________________________\n");
		if(contadordeCargados==0)
			{
				puts("NO HAY Aracdes CARGADOS");
			}
	}else
		 puts("No se ha podido procesar");
	return estado;
}
/**
 * \brief inicializa todas las posiciones del array salones como Libres pone la bander isEmpty en -1
 * \param  *plist recibo array por referencia, len tamaño del array
 * \return Retorna 0 si todo bien y -1 si no logro inicializar el array
 */
int iniciarEarrayS(eSalon *pSalones,int len)
{
	int estado=-1;
	   if (pSalones!=NULL && len>0)
	   {
		  for (int j = 0;  j<len; j++)
		   {
			  pSalones[j].isEmptySalon=LIBRE;
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
int largoArrayS(eSalon *pSalones,int len)
{
	int retorno=-1;
	int contBusy=0;
	if(pSalones!=NULL && len>0)
	{
		for (int i=0;i<len;++i)
		{
			if(pSalones[i].isEmptySalon==OCUPADO)
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
* \brief Imprime un Salon cargado con datos flag busy
* \param recibe un estructura por puntero, el largo  y el id a imprimir
* \return Retorna 0 todo bien  y -1  si no
*/
int imprimirUnSalonCargado(eSalon *pSalones, int len, int idmostrar)
{
	int estado=-1;
	int posicion;
	posicion=buscarPosicionDeSalonporSuId(pSalones, len, idmostrar);
	printf("______________________________________________________________________________________________\n");
	printf("\nNombre del Salon\t\tDirección\t\t\tTipo de Salon\tId Salon\n");
	printf("______________________________________________________________________________________________\n");
	if (pSalones!=NULL && idmostrar>0 && posicion>=0)
	{
		printf(" %-30s %-30s \t%d\t\t%d\n",
		pSalones[posicion].nombreSalon,pSalones[posicion].direccionSalon,pSalones[posicion].tipoSalon,
		pSalones[posicion].idSalon);
		estado=0;
		printf("______________________________________________________________________________________________\n");
	}else
		puts("NO HAY Arcade CARGADOS");
	return estado;
}
/**
  * \brief me da un id consecutivo y no repetido memorizando el ultimolvalor
  * \param void
  * \return Retorna 0 si todo bien  y -1 si no numero de id
  */
static int dameUnIdNuevoS(void)
{
	static int contador=0; //varable Global y solo de esta funcio y no olvida el valor mientra corre
	contador++;
	return contador;
}
//=======================================================================================
void harcodearunSalon(eSalon *pSalones,char nombreSalon[24],char direccionSalon[48],int tipoSalon,int posicion)
{
	strncpy(pSalones[posicion].nombreSalon, nombreSalon,sizeof(pSalones[posicion].nombreSalon));
	strncpy(pSalones[posicion].direccionSalon, direccionSalon,sizeof(pSalones[posicion].direccionSalon));
	pSalones[posicion].tipoSalon=tipoSalon;
	pSalones[posicion].idSalon=dameUnIdNuevoS();
	pSalones[posicion].isEmptySalon=OCUPADO;
}
//====================================================================================

