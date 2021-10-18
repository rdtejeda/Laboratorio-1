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
#define MAXIMO500 500
#define MAXIMO3 3

/* 10) Informar:
1. Lista​ ​ de​ ​ cada​ ​ eJuegos​ ​ con​ ​ cantidad​ ​ de​ ​ eArcade​
	e​ ​ importe​ ​ a ​ ​ pagar​ ​ por​ ​ cada​ ​ una.
*/
/*
void informe_10_1_ListaeJuegosEImpote(eArcade *pArcades, eSalon *pSalones, int lenA)
{
	eJuegos eJuegoss[TAMANO_ARRAY];
	hacerListaeJuegos(eJuegoss, TAMANO_ARRAY, pArcades);
	int j;
	for (j = 0; j < lenA; ++j)
	{

		if(eJuegoss[j].flagIsEmpty==0 && pSalones!=NULL && lenA>0 && pArcades!=NULL)
			{
				printf("\nEl eJuegos %s y y el importe a pagar es %.2f\n",
				eJuegoss[j].cuit, calcularImportePoreJuegos(pSalones, pArcades, TAMANO_ARRAY, eJuegoss[j].cuit));

			}

	}
	if(eJuegoss[0].flagIsEmpty!=0)
		{
		puts("La lista de eJuegoss no ha sido inizialisado");
		}
}
*/
/*
* 10) Informar:
2. eJuegos​ ​ con​ ​ importe​ ​ más​ ​ alto​ ​ a ​ ​ facturar​
(si​ ​ hay​ ​ más​ ​ de​ ​ uno​ ​ indicar​ ​ el​ ​ primero)
 */
//========================================================================
/**
* \brief calcula el importe mayor y gaurda la posicion del cuit
* \param  *pSalones *pContrato recibo array por referencia, lenA tamaño del array
* \return
*/
/*
void informe_10_2_eJuegosMayorFacturacion(eArcade *pArcades, eSalon *pSalones, int lenA)
{
	eJuegos eJuegoss[TAMANO_ARRAY];
	hacerListaeJuegos(eJuegoss, TAMANO_ARRAY, pArcades);

	int j=0;
	float importeMax=0;
	int posicioneJuegosMaximo;
	if(eJuegoss[0].flagIsEmpty==0 && pSalones!=NULL && lenA>0 && pArcades!=NULL)
	{
		importeMax=calcularImportePoreJuegos(pSalones, pArcades, TAMANO_ARRAY, eJuegoss[0].cuit);
		posicioneJuegosMaximo=0;
			for (j=0;j<lenA;j++)
			{
				if(eJuegoss[j].flagIsEmpty==0 && calcularImportePoreJuegos(pSalones, pArcades, TAMANO_ARRAY, eJuegoss[j].cuit)>importeMax)
				{
						importeMax=calcularImportePoreJuegos(pSalones, pArcades, TAMANO_ARRAY, eJuegoss[j].cuit); //SEGUIR MAXIMO
						posicioneJuegosMaximo=j;
				}else
				{
					break;
				}

			}
			printf("\nEl eJuegos con mayor facturacion es %s\n",eJuegoss[posicioneJuegosMaximo].cuit);
			printf("\nEl monto es %f\n",calcularImportePoreJuegos(pSalones, pArcades, TAMANO_ARRAY, eJuegoss[posicioneJuegosMaximo].cuit));

	}else
	{
		puts("La lista de eJuegoss no ha sido inizialisado");
	}
}
*/
//========================================================================
/**
* \brief calcula el importe total de uin cuit
* \param  *pSalones *pContrato recibo array por referencia, lenA tamaño del array
* \return Retorna acumulado del cuit y -1 si no lo encuentra
*/
/*
float calcularImportePoreJuegos(eSalon *pSalones, eArcade *pContrato, int lenA, char cuit[])
{
	float retorno=-1;
	float importeAcumulado=0;
	float importe;
	int j;
	if(pSalones!=NULL && lenA>0 && pContrato!=NULL)
	{
		for (j=0;j<lenA;j++)
		{
			if(pContrato[j].flagEmptyC==0 && strcmp(pContrato[j].cuit,cuit)==0)
			{
				importe=pContrato[j].cantidadDias*precioPorDiaDeeSalon(pSalones,lenA,pContrato[j].id);
				importeAcumulado=importeAcumulado+importe;
				retorno=importeAcumulado;
			}
		}
	}
return retorno;
}
*/
//========================================================================
/**
* \brief busca el precio por dia de un ideSalon
* \param  *peJuegos *pContrato recibo array por referencia, lenA tamaño del array
* \return Retorna 0 si encontro el cuit y -1 si no lo encuentra
*/
/*
float precioPorDiaDeeSalon(eSalon *pSalones, int lenA, int ideSalon)
{
	float retorno=-1;
	int posicioeSalon;
	if (pSalones!=NULL && lenA>0 && ideSalon>0)
	{
		posicioeSalon=buscarUnId(pSalones, lenA, ideSalon);
			if(posicioeSalon>=0)
			{
				retorno=pSalones[posicioeSalon].price;
			}
	}
return retorno;
}*/
/*
int informeA_SalonMascuatroArcade(eArcade *pArcades,int lenA,eSalon *pSalones,int lenS)
{
	int retorno=-1;
	int contadordeIdSalon=0;
	int auxIdSalon=0;
	int idSalonesainformar[CAN_SALON];
		printf("_________________________________________________\n");
		printf("Nombre del Juego\n");
		printf("__________________________________________________\n");
		if(pArcades!=NULL && lenA>0 && pSalon!=0 && lenS>0)
			{
			for (int i= 0;  i< lenA; i++)
				{
				if(pArcades[i]->isEmptyArcade==0)
					{
					pArcades[i].idSalon=auxIdSalon
						for (int j = 0; j < lenA; ++j)
							{
								if(pArcades[j].idSalon==auxIdSalon)
								{
									contadordeIdSalon++;
								}
								if(contadordeIdSalon>4)
								{
									idSalonesainformar[i]=auxIdSalon;
								}
							}
					}
				}
			}
		if(idSalonesainformar[0]=)

								{
								printf(" %-30s %-30s \t%d\t\t%d\t   %d\n",
								pSalones[i].nombreSalon,pSalones[i].direccionSalon,pSalones[i].tipoSalon, pSalones[i].idSalon,pSalones[i].isEmptySalon);
								}

					if(pArcades[i].isEmptyArcade==OCUPADO)
					{
						if()
						printf("%-30s\n",listaJuegos[i].nombreJuego);
						contadordeCargados++;
					}
				}
				printf("______________________________________________\n");
				estado=0;
				if(contadordeCargados==0)
					{
						puts("NO HAY DATOS CARGADOS");
					}
			}
	return retorno;
}
*/
/**
 * \brief imprime la lista de eJuegos con juegos  activos sin repetir
 * \param  *pArcade recibo array por referencia, len tamaño del array
 * \return Retorna 0 si encontro el cuit y -1 si no lo encuentra
 */
int imprimirListaJuegos(eArcade *pArcades,int len)
{
	int estado=-1;
	eJuego listaJuegos[CAN_ARCADE];
	hacerListaDeJuegos(listaJuegos,len,pArcades);
	int contadordeCargados=0;
	ordenaArcadePorNombreJuego(pArcades, CAN_ARCADE);
	printf("_________________________________________________\n");
	printf("Nombre del Juego\n");
	printf("__________________________________________________\n");
	if(pArcades!=NULL && len>0)
		{
			for (int i= 0;  i< len; i++)
			{
				if(listaJuegos[i].isEmptyJuego==OCUPADO)
				{
					printf("%-30s\n",listaJuegos[i].nombreJuego);
					contadordeCargados++;
				}
			}
			printf("______________________________________________\n");
			estado=0;
			if(contadordeCargados==0)
				{
					puts("NO HAY DATOS CARGADOS");
				}
		}
		return estado;
}
//========================================================================
/**
 * \brief hace la lista de eJuegos con juegos  activos sin repetir
 * \param  *pJuegos *pArcade recibo array por referencia, len tamaño del array
 * \return Retorna 0 si encontro el cuit y -1 si no lo encuentra
 */
int hacerListaDeJuegos(eJuego *pJuegos,int len,eArcade *pArcades)
{
	int retorno=-1;
	int j=0;
	int iListaeJuegos=0;

	inicializarListaJuegos(pJuegos, len);
	if(pJuegos!=NULL && len>0 && pArcades!=NULL)
	{
		for (j=0;j<len;j++)
		{
			if(pArcades[j].isEmptyArcade==0 && estaUnJuegoEnLista(pJuegos,len,pArcades[j].nombreJuego)==-1)
			{
				pJuegos[iListaeJuegos].isEmptyJuego=0;
				strcpy(pJuegos[iListaeJuegos].nombreJuego,pArcades[j].nombreJuego);
				iListaeJuegos++;
			}
		}
	retorno=0;
	}

return retorno;
}
//========================================================================
/**
 * \brief busca un cuit en la lista de eJuegoss
 * \param  *peJuegos recibo array por referencia, lenA tamaño del array y el cuit buscado
 * \return Retorna 0 si encontro el juego y -1 si no lo encuentra
 */
int estaUnJuegoEnLista(eJuego *pJuegos, int lenJ, char nombreJuego[])
{
	int estado=-1;
	int j;
	if (pJuegos!=NULL && lenJ>0)
		{
		  for (j=0;j<lenJ;j++)
			  {
				  if(pJuegos[j].isEmptyJuego==0 && strcmp(pJuegos[j].nombreJuego,nombreJuego)==0)
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
 * \param  *peJuegos recibo array por referencia, lenA tamaño del array
 * \return Retorna 0 si todo bien y -1 si no logro inicializar el array
 */
int inicializarListaJuegos(eJuego *pJuegos,int lenJ)
{
	int estado=-1;
	int j;
	   if (pJuegos!=NULL && lenJ>0)
	   {
		  for (j=0;j<lenJ;j++)
		   {
			  pJuegos[j].isEmptyJuego=LIBRE;
			  estado=0;
		   }
	   }
return estado;
}
//=======================================================================

