/*
 * Pantalla.c
 *
 *  Created on: 30 sep. 2021
 *      Author: usuario
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include <ctype.h>

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



//=============================================================================
/*typedef struct{
	int type; //0 LCD 1 LED
	float price;
	int id;
	char name[128];
	char address[128];
	int flagEmpty; //0 ocupada 1 vacia
}Display;
 */
//==============================================================================

static int dameUnIdNuevo(void);

/**
 * \brief inicializa todas las posiciones del array como Libres pone la bander isEmpty en -1
 * \param  *plistEmployee recibo array por referencia, len tamaño del array
 * \return Retorna 0 si todo bien y -1 si no logro inicializar el array
 */
int iniciarEarray(Display *plistDisplay,int len)
{
	int estado=-1;
	   if (plistDisplay!=NULL && len>0)
	   {
		  for (int j = 0;  j<len; j++)
		   {
			  plistDisplay[j].flagEmpty=LIBRE;
			  estado=0;
		   }
	   }
	   return estado;
}
//=============================================================================
/**
* \brief da de alta un display en el array de Display
* \param recibe un array de estructura, el largo
* \return Retorna -1 todo mal 0 todo bien
*/
int altaDisplay(Display *pDisplay,int len)
{
	int retorno=-1;
	int libre;
	if(pDisplay!=NULL && len>0)
	{
		libre=buscarLugarLibreArrayS(pDisplay, TAMANO_ARRAY);
		if(buscarLugarLibreArrayS(pDisplay, TAMANO_ARRAY)>=0)
			{
				printf("\nEl primer lugar libre es %d\n",libre);
				if(disp_loadDisplay(&pDisplay[libre], TAMANO_ARRAY)==0)
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
* \brief caraga de datos para Dar de alta un display
* \param recibe un estructura por puntero y el largo
* \return Retorna 0 si se logor carga  y -1  si no
*/
int disp_loadDisplay(Display *pDisplay, int len)
{
	int estado=-1;
	int bufferType;
	char bufferAddres[128];
	char bufferName[128];
	float bufferPrice;
	   if(pDisplay!=NULL && len>0)
	   {
		   if(pedirInt(&bufferType, "Ingrese tipo 0 para LCD y 1 LED", "Ingrese tipo valido", 0, 1, INTENTOS)==0)
		   {
			     if(pedirFloat(&bufferPrice, "Valor de la publicación", "Ingrese un numero correcto", 0, 100000, INTENTOS)==0)
			     {
			    	 if(pedirText(bufferAddres, sizeof(pDisplay->address), "Ingrese la dirrecion de la pantalla", "Direccion no valida", INTENTOS)==0)
			    	 {
			    		 if(pedirText(bufferName, sizeof(pDisplay->name), "ingrese el nombre de la pantala", "Nombre invalido",INTENTOS)==0)
			    		 {

			    			 pDisplay->type=bufferType;
			    			 pDisplay->price=bufferPrice;
			    			 strncpy(pDisplay->address, bufferAddres,sizeof(pDisplay->address));
			    			 strncpy(pDisplay->name, bufferName,sizeof(pDisplay->name));
			    			 pDisplay->id=dameUnIdNuevo();
			    			 pDisplay->flagEmpty=OCUPADO;
			    			 estado=OCUPADO;
			    		 }
			    	 }
			     }
		   }
	   }
	   return estado;
}
//==========================================================================================

/**
* \brief Busca un dispplay recibiendo como parámetro de búsqueda su Id.
* \param  *plistEmployee recibo array por referencia,len tamaño del array, id
* \return Retorna la posicion en el array del id solicitado o -1 si el no exixte
*/
int buscarUnIdDisplay(Display *pDisplay,int len,int id)
{
	int retorno=-1;
		if(pDisplay!=NULL && len>0)
		{
			for (int i=0;i<len;++i)
			{
				if(pDisplay[i].id==id && pDisplay[i].flagEmpty==OCUPADO)
				{
					retorno=i;
					break;
				}
			}
		}
		return retorno;
}
//==============================================================================
/**
* \brief Ordena el array de Display por orden alfabetico ascendente de nombre y precio
* \param recibe un array de estructura, el largo
* \return Retorna -1 todo mal 0 todo bien
*/
int ordenaDisplayPorDireccioYPrecio(Display *pDisplay, int len)
{
	int banderaSwapp=-1;
	Display auxiliar;
	int limite=len;
	int estadostrcmp;
	if(pDisplay!=NULL && len>0)
	{
		do
		{
			banderaSwapp=0;
			limite=limite-1;
			for (int i=0; i<limite; i++)
			{
				estadostrcmp=strcmp(pDisplay[i].address, pDisplay[i+1].address);
				if(estadostrcmp>0)
				{
					banderaSwapp=1;
					auxiliar=pDisplay[i];
					pDisplay[i]=pDisplay[i+1];
					pDisplay[i+1]=auxiliar;
				}
				if (estadostrcmp==0)
				{
					if(pDisplay[i].price>pDisplay[i+1].price)
						{
							banderaSwapp=1;
							auxiliar=pDisplay[i];
							pDisplay[i]=pDisplay[i+1];
							pDisplay[i+1]=auxiliar;
						}
				}
			}
		}while(banderaSwapp==1);
	}
	return banderaSwapp;
}
//=============================================================================
/**
* \brief Modifica un display dando opciones
* \param recibe un estructura por puntero, el largo
* \return Retorna -1 todo mal 0 todo bien
*/
 int modificarUnDisplay(Display *pDisplay, int len)
 {
	 int retorno=-1;
	 int idamodificar;
	 int posicion;
	 int bufferType;
	 char bufferAddres[128];
	 char bufferName[128];
	 float bufferPrice;
	 int opcion;
	 Display auxiliar;
	 if(pDisplay!=NULL && len>0)
	 {
		 imprimirDisplayCargado(pDisplay, len);
		 pedirInt(&idamodificar, "Ingrese Id a modificar", "Error", MINIMO, len, INTENTOS);
		 posicion=buscarUnId(pDisplay, len, idamodificar);
		 printf("\nposicion dice%d\n",posicion);
		 if (posicion>=0)
			 {
			 do
				 {
					 puts("INGRESE OPCION A MOFIFICAR");
					 imprimirMenuModificar();
					 pedirInt(&opcion, "INGRESE OPCION A MOFIFICAR", "Ingrese entre 1 y 5", 1,5,INTENTOS);
					 switch (opcion)
					 {
						case 1:
							pedirInt(&bufferType, "Ingrese tipo 0 para LCD y 1 LED", "Ingrese tipo valido", 0, 1, INTENTOS);
							pDisplay->type=bufferType;
							break;
						case 2:
							pedirFloat(&bufferPrice, "Valor de la publicación", "Ingrese un numero correcto", 0, 100000, INTENTOS);
							pDisplay->price=bufferPrice;
							break;
						case 3:
							pedirText(bufferName, sizeof(auxiliar.name), "ingrese el nombre de la pantala", "Nombre invalido",INTENTOS);
							strncpy(pDisplay->name, bufferName, sizeof(pDisplay->name));
							break;
						case 4:
							pedirText(bufferAddres, sizeof(auxiliar.address), "Ingrese la dirrecion de la pantalla", "Direccion no valida", INTENTOS);
							strncpy(pDisplay->address, bufferAddres, sizeof(pDisplay->address));
							break;
						default:
							break;
					 }
				 }while(opcion<5);
			 retorno=0;
			 }else
				 puts("Id no hallado");
		 }
	 return retorno;
 }
 //=========================================================================
 /**
 * \brief Da de baja en forma logica un ID display
 * \param recibe un estructura por puntero, el largo y el id a dar de baja
 * \return Retorna -1 salio mal 0 todo bien
 */
 int bajaLogicaUnDisplay(Display *pDisplay, int len, int idabajar)
 {
	 int retorno=-1;
	 int posicion;
	 posicion=buscarUnId(pDisplay, len, idabajar);
	 printf("\nposicion dice %d\n",posicion);
	 if(pDisplay!=NULL && posicion>=0 && len>0)
	 {
		 pDisplay[posicion].flagEmpty=LIBRE; // podemos hacer un estados de baja para llevar un control
		 retorno=0;
	 }
	 return retorno;
 }
//==============================================================================
/**
* \brief busca la posiscion de un ID displa
* \param recibe un estructura por puntero, el largo y el idbuscado
* \return Retorna posicion en el array del id buscado o -1 si no lo alla
*/
int buscarUnId(Display *pDisplay, int len, int idbuscado)
{
	int retorno=-1;
	if(pDisplay!=NULL && len>0)
	{
		for (int i=0;i<len;++i)
		{
			if(pDisplay[i].id==idbuscado && pDisplay[i].flagEmpty==OCUPADO)
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
* \brief Imprime todo el arraay del Display
* \param recibe un estructura por puntero y el largo
* \return Retorna 0 si se logor carga  y -1  si no
*/
int imprimirDisplay(Display *pDisplay, int len)
{
	int estado=-1;
	printf("\nFlagEmpt\t Id\t Type\t Price\t Name\t Address\t\n");
	if (pDisplay!=NULL && len>0)
	{
		for (int i=0;i<len;i++)
		{
			printf("\n\t%d \t%d \t%d \t%.2f \t%s \t%s\n",
			pDisplay[i].flagEmpty,pDisplay[i].id,pDisplay[i].type, pDisplay[i].price,pDisplay[i].name,pDisplay[i].address);
		}
	}
	estado=0;
	return estado;
}
//=============================================================================
/**
* \brief busca e Imprime el array Display cargado con datos flag busy
* \param recibe un estructura por puntero y el largo
* \return Retorna 0 si se logor carga  y -1  si no
*/
int imprimirDisplayCargado(Display *pDisplay, int len)
{
	int estado=-1;
	int contadordeCargados=0;
	printf("\nFlagEmpt\t Id\t Type\t Price\t Name\t Address\t\n");
	if (pDisplay!=NULL && len>0)
	{
		for (int i= 0;  i< len; i++)
		{
			if(pDisplay[i].flagEmpty==OCUPADO)
			{
				printf("\n\t%d \t%d \t%d \t%.2f \t%s \t%s\n",
				pDisplay[i].flagEmpty,pDisplay[i].id,pDisplay[i].type, pDisplay[i].price,pDisplay[i].name,pDisplay[i].address);
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
//===========================================================================
/**
 * \brief busca cantidad de posiciones ocupadas en el array
* \param *plistEmployee recibo array por referencia, len tamaño del array
* \return Retorna cantidad de lugares o -1 si no encuentra ninguno lugar ocupados
 */
int largoArrayD(Display *plistDisplay,int len)
{
	int retorno=-1;
	int contBusy=0;
	if(plistDisplay!=NULL && len>0)
	{
		for (int i=0;i<len;++i)
		{
			if(plistDisplay[i].flagEmpty==OCUPADO)
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
//=============================================================================
/**
* \brief busca el primer index del array con flag emty
* \param recibe un estructura por puntero y el largo
* \return Retorna lugar el primer lugar libre de la lista o -1 si no encuentra ninguno libre
*/
int buscarLugarLibreArrayS(Display *pDisplay, int len)
{
	int retorno=-1;
	if(pDisplay!=NULL && len>0)
	{
		for (int i=0;i<len;++i)
		{
			if(pDisplay[i].flagEmpty==LIBRE)
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
static int dameUnIdNuevo(void)
{
	static int contador=0; //varable Global y solo de esta funcio y no olvida el valor mientra corre
	contador++;
	return contador;
}
//============================================================
void harcodearunaltaD(Display *pDisplay, int id, int type, int flagEmty,float price, char name[], char adrees[], int posicion)
{
		pDisplay[posicion].type=type;
		pDisplay[posicion].price=price;
		strncpy(pDisplay[posicion].address, adrees,sizeof(pDisplay[posicion].address));
		strncpy(pDisplay[posicion].name, name,sizeof(pDisplay[posicion].name));
		pDisplay[posicion].id=id;
		pDisplay[posicion].flagEmpty=OCUPADO;
}
//================================================================================
