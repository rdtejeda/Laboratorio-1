/*
 ============================================================================
 Name        : Parcial_1_Lab_I_2017.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
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
/*
typedef struct{
	char cuit[12];
	int cantidadDias;
	int idContratacion;
	char nombreArchivo[128];
	int id;
	int flagEmptyC;
}Contrataciones;

typedef struct{
	int type; //0 LCD 1 LED
	float price;
	int id;
	char name[128];
	char address[128];
	int flagEmpty; //0 ocupada 1 vacia
}Display;

typedef struct
{
char cuit[12];
int flaisEmpty;
}Cliente;
*/

/* 10) Informar:
1. Lista​ ​ de​ ​ cada​ ​ cliente​ ​ con​ ​ cantidad​ ​ de​ ​ contrataciones​
	e​ ​ importe​ ​ a ​ ​ pagar​ ​ por​ ​ cada​ ​ una.
*/
void informe_10_1_ListaClienteEImpote(Contrataciones *pContato, Display *pDisplay, int len)
{
	Cliente clientes[TAMANO_ARRAY];
	hacerListaCliente(clientes, TAMANO_ARRAY, pContato);
	int j;
	for (j = 0; j < len; ++j)
	{

		if(clientes[j].flagIsEmpty==0 && pDisplay!=NULL && len>0 && pContato!=NULL)
			{
				printf("\nEl Cliente %s y y el importe a pagar es %.2f\n",
				clientes[j].cuit, calcularImportePorCliente(pDisplay, pContato, TAMANO_ARRAY, clientes[j].cuit));

			}

	}
	if(clientes[0].flagIsEmpty!=0)
		{
		puts("La lista de clientes no ha sido inizialisado");
		}
}
/*
* 10) Informar:
2. Cliente​ ​ con​ ​ importe​ ​ más​ ​ alto​ ​ a ​ ​ facturar​
(si​ ​ hay​ ​ más​ ​ de​ ​ uno​ ​ indicar​ ​ el​ ​ primero)
 */
//========================================================================
/**
* \brief calcula el importe mayor y gaurda la posicion del cuit
* \param  *pDisplay *pContrato recibo array por referencia, len tamaño del array
* \return
*/
void informe_10_2_ClienteMayorFacturacion(Contrataciones *pContato, Display *pDisplay, int len)
{
	Cliente clientes[TAMANO_ARRAY];
	hacerListaCliente(clientes, TAMANO_ARRAY, pContato);

	int j=0;
	float importeMax=0;
	int posicionClienteMaximo;
	if(clientes[0].flagIsEmpty==0 && pDisplay!=NULL && len>0 && pContato!=NULL)
	{
		importeMax=calcularImportePorCliente(pDisplay, pContato, TAMANO_ARRAY, clientes[0].cuit);
		posicionClienteMaximo=0;
			for (j=0;j<len;j++)
			{
				if(clientes[j].flagIsEmpty==0 && calcularImportePorCliente(pDisplay, pContato, TAMANO_ARRAY, clientes[j].cuit)>importeMax)
				{
						importeMax=calcularImportePorCliente(pDisplay, pContato, TAMANO_ARRAY, clientes[j].cuit); //SEGUIR MAXIMO
						posicionClienteMaximo=j;
				}else
				{
					break;
				}

			}
			printf("\nEl cliente con mayor facturacion es %s\n",clientes[posicionClienteMaximo].cuit);
			printf("\nEl monto es %f\n",calcularImportePorCliente(pDisplay, pContato, TAMANO_ARRAY, clientes[posicionClienteMaximo].cuit));

	}else
	{
		puts("La lista de clientes no ha sido inizialisado");
	}
}
//========================================================================
/**
* \brief calcula el importe total de uin cuit
* \param  *pDisplay *pContrato recibo array por referencia, len tamaño del array
* \return Retorna acumulado del cuit y -1 si no lo encuentra
*/
float calcularImportePorCliente(Display *pDisplay, Contrataciones *pContrato, int len, char cuit[])
{
	float retorno=-1;
	float importeAcumulado=0;
	float importe;
	int j;
	if(pDisplay!=NULL && len>0 && pContrato!=NULL)
	{
		for (j=0;j<len;j++)
		{
			if(pContrato[j].flagEmptyC==0 && strcmp(pContrato[j].cuit,cuit)==0)
			{
				importe=pContrato[j].cantidadDias*precioPorDiaDeDisplay(pDisplay,len,pContrato[j].id);
				importeAcumulado=importeAcumulado+importe;
				retorno=importeAcumulado;
			}
		}
	}
return retorno;
}
//========================================================================
/**
* \brief busca el precio por dia de un iddisplay
* \param  *pCliente *pContrato recibo array por referencia, len tamaño del array
* \return Retorna 0 si encontro el cuit y -1 si no lo encuentra
*/
float precioPorDiaDeDisplay(Display *pDisplay, int len, int idDisplay)
{
	float retorno=-1;
	int posicioDisplay;
	if (pDisplay!=NULL && len>0 && idDisplay>0)
	{
		posicioDisplay=buscarUnId(pDisplay, len, idDisplay);
			if(posicioDisplay>=0)
			{
				retorno=pDisplay[posicioDisplay].price;
			}
	}
return retorno;
}
//========================================================================
/**
 * \brief hace la lista de Clientes con CUIT activos sin repetir
 * \param  *pCliente *pContrato recibo array por referencia, len tamaño del array
 * \return Retorna 0 si encontro el cuit y -1 si no lo encuentra
 */
int hacerListaCliente(Cliente *pCliente, int len, Contrataciones *pContrato)
{
	int retorno=-1;
	int j=0;
	int iListaCliente=0;

	inicializarListaCliente(pCliente, len);
	if(pCliente!=NULL && len>0 && pContrato!=NULL)
	{
		for (j=0;j<len;j++)
		{
			if(pContrato[j].flagEmptyC==0 && estaUnCuitListaCliente(pCliente,len,pContrato[j].cuit)==-1)
			{
				pCliente[iListaCliente].flagIsEmpty=0;
				strcpy(pCliente[iListaCliente].cuit, pContrato[j].cuit);
				iListaCliente++;
			}
		}
	}

return retorno;
}

//========================================================================
/**
 * \brief busca un cuit en la lista de Clientes
 * \param  *pCliente recibo array por referencia, len tamaño del array y el cuit buscado
 * \return Retorna 0 si encontro el cuit y -1 si no lo encuentra
 */
int estaUnCuitListaCliente(Cliente *pCliente, int len, char cuit[])
{
	int estado=-1;
	int j;
	if (pCliente!=NULL && len>0)
		{
		  for (j=0;j<len;j++)
			  {
				  if(pCliente[j].flagIsEmpty==0 && strcmp(pCliente[j].cuit,cuit)==0)
						{
							estado=0;
							break;
						}
			  }
		 }
return estado;
}
//=========================================================================
/**
 * \brief inicializa todas las posiciones del array contrato como Libres pone la bander isEmpty en -1
 * \param  *pCliente recibo array por referencia, len tamaño del array
 * \return Retorna 0 si todo bien y -1 si no logro inicializar el array
 */
int inicializarListaCliente(Cliente *pCliente,int len)
{
	int estado=-1;
	int j;
	   if (pCliente!=NULL && len>0)
	   {
		  for (j=0;j<len;j++)
		   {
			  pCliente[j].flagIsEmpty=LIBRE;
			  estado=0;
		   }
	   }
return estado;
}
//=======================================================================

