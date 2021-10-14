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
 * typedef struct{
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
 */
/*
 * 10)
Informar:
1. Lista​ ​ de​ ​ cada​ ​ cliente​ ​ con​ ​ cantidad​ ​ de​ ​ contrataciones​ ​ e ​ ​ importe​ ​ a ​ ​ pagar​ ​ por​ ​ cada​ ​ una.
 */
	/**
	* \brief busca el cuil e imprime los costos por pantalla
	* \param recibe un estructura por puntero, el largo y el idbuscado
	* \return Retorna posicion en el array del id buscado o -1 si no lo alla
	*/
int listClientesYContrator(Contrataciones *pContra, Display *pDisplay, Cliente *pClientes, int len)
{
		int retorno=-1;
		char bufferCUIT[12];
		int bufferCantidadContra;
		int sumaporcliente;
		int bufferMontoporCliente;
		int k=-1;
		int i=0;
		int j=0;
		if(pContra!=NULL && pDisplay!=NULL && len>0)
		{
			for (i=0;i<len;++i)
			{
				strncpy(bufferCUIT, pContra[i].cuit, sizeof(bufferCUIT));
				bufferCantidadContra=0;

						printf("\nCLIENTE CUIT numero %s\n",bufferCUIT);
						for (j = 0; j < len; ++j)
							{
							if(strcmp(bufferCUIT, pContra[j].cuit)==0 && esNumericaCUIT(pContra[j].cuit)==0)
								{
									bufferMontoporCliente=buscarPorCuityOperar2(pContra, pDisplay, TAMANO_ARRAY, pContra[j].cuit, pContra[j].id);
									bufferCantidadContra++;
									sumaporcliente=bufferMontoporCliente+sumaporcliente;
								}
							}
						printf("\nEl CLIENTE CUIT numero %s tiene %d contratos\n",bufferCUIT, bufferCantidadContra);
						strncpy(pClientes[k+1].cuit, bufferCUIT, sizeof(pClientes[k+1].cuit));
						pClientes[k+1].facturacion=sumaporcliente;
						pClientes[k+1].idContrtacion=pContra[j].idContratacion;
						k++;
			}
		retorno=0;
		}
return retorno;
}
/*
 * typedef struct
{
char cuit[12];
float facturacion;
int idContrtacion;
}Cliente;
 */
/**
* \brief busca un cuit y un id de pantalla imprime los costos de la misma
* \param recibe un estructura por puntero, el largo y el idbuscado
* \return Retorna costo del contrato  o -1 si no lo alla
*/
int buscarPorCuityOperar2(Contrataciones *pContra, Display *pDisplay, int len, char cuitBusacado[], int idpantalla)
{
	int retorno=-1;
	int posPantalla;
	float importe;
	if(pContra!=NULL && pDisplay!=NULL && len>0)
	{
		for (int i=0;i<len;++i)
		{
			if(strcmp(pContra[i].cuit, cuitBusacado)==0 && idpantalla==pContra[i].id && pContra[i].flagEmptyC==OCUPADO)
			{
				posPantalla=buscarUnIdDisplay(pDisplay,len,pContra[i].id);
				importe=pContra[i].cantidadDias*pDisplay[posPantalla].price;
				printf("\nEL IMPORTE A PAGAR POR El CONTRATO %d ES %.2f\n",pContra[i].idContratacion,importe);
			}
		}
		retorno=importe;
	}
	return retorno;
}
/*
if(strcmp(pContra[i].cuit, cuitBusacado)==0 && pContra[i].flagEmptyC==OCUPADO)
									{




										printf("\n\t%d \t%d \t%d \t%s \t%s \t%d\n",
											pContra[i].flagEmptyC,pContra[i].id,pContra[i].cantidadDias,
											pContra[i].cuit,pContra[i].nombreArchivo,pContra[i].idContratacion);

										//posPantalla=buscarUnIdDisplay(pDisplay, len,pContra[i].id);
										//importe=pContra[i].cantidadDias*pDisplay[posPantalla].price;
										//printf("\nEL IMPORTE A PAGAR POR ESTA PUBLICACION ES %.2f\n",importe);
									}
*/
//==============================================================================
/**
* \brief Ordena el array de Cont por orden CUIT ascendente
* \param recibe un array de estructura, el largo
* \return Retorna -1 todo mal 0 todo bien
*/
int ordenaContrPorDireccioYPrecio(Display *pDisplay, int len)
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


