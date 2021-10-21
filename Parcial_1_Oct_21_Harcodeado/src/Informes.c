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

/**
 * brief I) Imprimir el promedio de arcades por salón. (Cantidad de arcades totales / Cantidad de salones totales).
* \param  *parcade y *pSalon recibo array por referencia,y sus len tamaño del array
* \return Retorna cantidad de arcdes -1 si el no exixte
*/
int informeI1(eArcade *pArcades,int lenA,eSalon *pSalones,int lenS)
{
	int estado=-1;
	float promedio;

	if(pArcades!=NULL && lenS>0 && lenA>0&& pSalones!=NULL)
	{
		promedio=(float)largoArrayA(pArcades, lenA)/(float)largoArrayS(pSalones, lenS);
		printf("\nEl promedio es %.2f\n\n",promedio);
	}else
		 puts("No se ha podido procesar");

	estado=0;
	return estado;
}
/**
* \brief H) Un salón se encuentra equipado por completo si posee al menos 8 arcades de mas de 2 jugadores. Listar los
salones que cumplan con este mínimo de requisito.
* \param  *parcade y *pSalon recibo array por referencia,y sus len tamaño del array
* \return Retorna cantidad de arcdes -1 si el no exixte
*/
int informeH1(eArcade *pArcades,int lenA,eSalon *pSalones,int lenS)
{
	int estado=-1;
	int posSalon;
	int cantidad=0;
	eCantArcadeSalon listaSalones[CAN_SALON];
	hacerListaSalon(listaSalones,lenS,pArcades,lenA);
	/*
	for (int l = 0; l < lenS; ++l)
	{

			printf("ID %d Cant %d IsEmt %d\n",listaSalones[l].idSalon,listaSalones[l].cantidaArcade,listaSalones[l].isEmptySalon);


	}
	*/
	if(pArcades!=NULL && lenS>0 && lenA>0 && pSalones!=NULL)
		{

		for (int i = 0; i < lenS; i++)
			{
				if(listaSalones[i].isEmptySalon==0 && listaSalones[i].cantidaArcade>=8)
				{
					posSalon=buscarPosicionDeSalonporSuId(pSalones,lenS,listaSalones[i].idSalon);
					printf("_____________________________________________________________________________________________________\n");
					printf("\nNombre del Salon\t\tDirección\t\t\tTipo de Salon\tId Salon Cantidad de Arcade\n");
					printf("_____________________________________________________________________________________________________\n");
					printf(" %-30s %-30s \t%d\t\t%d\t   %d\n",
							pSalones[posSalon].nombreSalon,pSalones[posSalon].direccionSalon,pSalones[posSalon].tipoSalon,
							pSalones[posSalon].idSalon,listaSalones[i].cantidaArcade);
					cantidad++;
				}
			}
		if(cantidad==0)
			puts("No hay NINGUN salon que cumplan la consigna");
		printf("_____________________________________________________________________________________________________\n");
		estado=0;

		}else
			 puts("No se ha podido procesar");
	return estado;
}
/**
* \brief Listar los salones con más de 4 arcades. Indicando ID de salón, nombre, dirección y tipo de salón
* \param  *parcade y *pSalon recibo array por referencia,y sus len tamaño del array
* \return Retorna cantidad de arcdes -1 si el no exixte
*/
int informeA(eArcade *pArcades,int lenA,eSalon *pSalones,int lenS)
{
	int estado=-1;
	int auxCantArcades;
	int cantidad=0;
	int posicion2;
	if(pArcades!=NULL && lenA>0 && pSalones!=0 && lenS>0)
		{
		printf("________________________________________________________________________________\n");
		printf("Nombre del Salon\t\tDireccio del Salon\tTipo de salon\tId Salon\n");
		printf("_________________________________________________________________________________\n");
		for (int i=0;i<lenS;i++)
			{
			if(pSalones[i].isEmptySalon==0)
			{
			auxCantArcades=(cantidadArcadesDeUnSalon(pArcades,lenA,pSalones[i].idSalon));
			if(auxCantArcades>4)
				{
				posicion2=buscarPosicionDeSalonporSuId(pSalones,lenS,pSalones[i].idSalon);
				printf(" %-30s %-30s \t%d\t\t%d\n",
				pSalones[posicion2].nombreSalon,pSalones[posicion2].direccionSalon,
				pSalones[posicion2].tipoSalon, pSalones[posicion2].idSalon);
				cantidad++;
				estado=0;
				}
			}
			}
		if(cantidad==0)
		{
			puts("No hay salones que cumplan la consigna");
			estado=-1;
		}
		printf("________________________________________________________________________________\n");
		}else
			 puts("No se ha podido procesar");
	return estado;
}
/**
* \brief Lista los arcades para más de 2 jugadores, indicando ID de arcade, cantidad de jugadores,
* nombre del juego y nombre del salón al que pertenece.
* \param  *parcade y *pSalon recibo array por referencia,y sus len tamaño del array
* \return Retorna cantidad de arcdes -1 si el no exixte
*/
int informeB(eArcade *pArcades,int lenA,eSalon *pSalones,int lenS)
{
	int retorno=-1;
	int auxposIdSalon;
	int cantidad=0;
	if(pSalones!=NULL && lenS>0 && pArcades!=NULL && lenA>0)
	{
		printf("____________________________________________________________________________________________________________________\n");
		printf("Id Jugadores Nombre del juego\t\tSalon\n");
		printf("____________________________________________________________________________________________________________________\n");
		for (int i = 0; i <CAN_ARCADE; ++i)
		{
			if(pArcades[i].isEmptyArcade==OCUPADO && pArcades[i].cantidadJugadorArcade>2)
			{
				auxposIdSalon=buscarPosicionDeSalonporSuId(pSalones, lenS, pArcades[i].idSalon);
				printf("%d\t\%d %-30s %-30s\n",
				pArcades[i].idArcade,pArcades[i].cantidadJugadorArcade,pArcades[i].nombreJuego,pSalones[auxposIdSalon].nombreSalon);
				cantidad++;
				retorno=0;
			}
		}
		if(cantidad==0)
				{
					puts("No hay salones que cumplan la consigna");
					retorno=-1;
				}
		printf("________________________________________________________________________________\n");
	}else
		 puts("No se ha podido procesar");
return retorno;
}
/**
* \brief Lista toda la información de un salón en específico ingresando su ID.
*  Imprime nombre, tipo y dirección y cantidad de arcades que posee.
* \param  *parcade y *pSalon recibo array por referencia,y sus len tamaño del array
* \return Retorna cantidad de arcdes -1 si el no exixte
*/
int informeC(eSalon *pSalones,int lenS,eArcade *pArcades,int lenA)
{
	int estado=-1;
	int idSalon;
	int posSalon;
	int auxCantidadArcades;
	if(pArcades!=NULL && lenA>0 && pSalones!=NULL && lenS>0)
	{
	imprimirSalonCargado(pSalones, lenS);
	pedirInt(&idSalon, "Ingrese Id de Salon","Id invalido",MINIMO,CAN_SALON,INTENTOS);
	posSalon=buscarPosicionDeSalonporSuId(pSalones, lenS, idSalon);
	if(pSalones[posSalon].isEmptySalon==OCUPADO)
				{
					auxCantidadArcades=cantidadArcadesDeUnSalon(pArcades,CAN_ARCADE,idSalon);
					printf("_____________________________________________________________________________________________________\n");
					printf("\nNombre del Salon\t\tDirección\t\t\tTipo de Salon\tId Salon Cantidad de Arcade\n");
					printf("_____________________________________________________________________________________________________\n");
					printf(" %-30s %-30s \t%d\t\t%d\t   %d\n",
					pSalones[posSalon].nombreSalon,pSalones[posSalon].direccionSalon,pSalones[posSalon].tipoSalon,
					pSalones[posSalon].idSalon,auxCantidadArcades);
					printf("_____________________________________________________________________________________________________\n");
					estado=0;
				}else
		puts("No es un salon Elegible");
	}else
		 puts("No se ha podido procesar");
	return estado;
}
/**
* \brief Listar todos los arcades de un salón determinado ingresando su ID. Informar nombre y tipo de salón,
*  listar todos los arcades con sus datos junto con el nombre del juego que lo compone.
*  indicando todos los datos del salón y la cantidad de arcades que posee.
*  e imprimir el monto máximo en pesos que puede recaudar el salón.
* \param  *parcade y *pSalon recibo array por referencia,y sus len tamaño del array
* \return Retorna cantidad de arcdes -1 si el no exixte
*/
int informeD(eArcade *pArcades,int lenA,eSalon *pSalones,int lenS)
{
	int estado=-1;
	int idSalon;
	int posSalon=-1;
	if(pArcades!=NULL && lenA>0 && pSalones!=0 && lenS>0)
	{
		imprimirSalonCargado(pSalones, lenS);
		pedirInt(&idSalon, "Ingrese Id de Salon","Id invalido",MINIMO,CAN_SALON,INTENTOS);
		posSalon=buscarPosicionDeSalonporSuId(pSalones, lenS, idSalon);
		if(posSalon>=0)
		{
			printf("_________________________________________________________________\n");
			printf("\nNombre del Salon\t\tId Salon\n");
			printf("__________________________________________________________________\n");
			printf(" %-30s \t%d\n",pSalones[posSalon].nombreSalon,pSalones[posSalon].idSalon);
			printf("__________________________________________________________________\n");
			printf("Id Nacionalidad de Arcade\t  Nombre Juego\t\t\tSonido Jugadores Max.Fichas Id Salon\n");
			printf("__________________________________________________________________________________________________________\n");
		}else
			puts("Ingrese Id Valido");
		for (int j=0;j<lenA; ++j)
		{
			if(pArcades[j].idSalon==idSalon&&pArcades[j].isEmptyArcade==0)
			{
				printf(" %d %-30s %-30s %d\t%d\t  %d\t\t%d\n",
				pArcades[j].idArcade,pArcades[j].nacionalidadArcade,pArcades[j].nombreJuego,pArcades[j].tipoSonidoArcade,pArcades[j].cantidadJugadorArcade,
				pArcades[j].capMaxFichaArcade,pArcades[j].idSalon);
			}
		}
		printf("__________________________________________________________________________________________________________\n");
		estado=0;
	}else
		 puts("No se ha podido procesar");
	return estado;
}
/**
* \brief Imprimir el salón con más cantidad de arcades,
*  indicando todos los datos del salón y la cantidad de arcades que posee.
*  e imprimir el monto máximo en pesos que puede recaudar el salón.
* \param  *parcade y *pSalon recibo array por referencia,y sus len tamaño del array
* \return Retorna cantidad de arcdes -1 si el no exixte
*/
int informeE(eArcade *pArcades,int lenA,eSalon *pSalones,int lenS)
{
	int estado=-1;
	int posSalon;
	eCantArcadeSalon listaSalones[CAN_SALON];
	hacerListaSalon(listaSalones,lenS,pArcades,lenA);
	int banderaSwapp=-1;
	eCantArcadeSalon auxiliar;
	int limite=lenS;
		if(pArcades!=NULL && lenS>0 && lenA>0&& pSalones!=NULL)
		{
			do
			{
				banderaSwapp=0;
				limite=limite-1;
				for (int i=0; i<limite; i++)
				{
						if(listaSalones[i].isEmptySalon==0&&listaSalones[i+1].isEmptySalon==0&&(listaSalones[i].cantidaArcade<listaSalones[i+1].cantidaArcade))
					{
						banderaSwapp=1;
						auxiliar=listaSalones[i];
						listaSalones[i]=listaSalones[i+1];
						listaSalones[i+1]=auxiliar;
					}
				}
			}while(banderaSwapp==1);
		posSalon=buscarPosicionDeSalonporSuId(pSalones,lenS,listaSalones[0].idSalon);
		printf("_____________________________________________________________________________________________________\n");
		printf("\nNombre del Salon\t\tDirección\t\t\tTipo de Salon\tId Salon Cantidad de Arcade\n");
		printf("_____________________________________________________________________________________________________\n");
		printf(" %-30s %-30s \t%d\t\t%d\t   %d\n",
		pSalones[posSalon].nombreSalon,pSalones[posSalon].direccionSalon,pSalones[posSalon].tipoSalon,
		pSalones[posSalon].idSalon,listaSalones[0].cantidaArcade);
		printf("_____________________________________________________________________________________________________\n");
		estado=0;

		}else
			 puts("No se ha podido procesar");
	return estado;
}
/**
 * \brief hace la lista de eCantArcdeSalo con juegos  activos sin repetir
 * \param  *pJuegos *pArcade recibo array por referencia, len tamaño del array
 * \return Retorna 0 si encontro el cuit y -1 si no lo encuentra
 */
int hacerListaSalon(eCantArcadeSalon *pCantSalones,int lenC,eArcade *pArcades,int lenA)
{
	int retorno=0;
	inicializarListaSalon(pCantSalones, lenC);
	int j=0;
	int iListaeJuegos=0;
	if(pCantSalones!=NULL && lenC>0 && pArcades!=NULL && lenA>0)
		{
			for (j=0;j<lenC;j++)
			{
				if(pArcades[j].isEmptyArcade==0 && estaUnIdSalonEnLista(pCantSalones, lenC,pArcades[j].idSalon)==-1)
				{
					pCantSalones[iListaeJuegos].isEmptySalon=0;
					pCantSalones[iListaeJuegos].idSalon=pArcades[j].idSalon;
					pCantSalones[iListaeJuegos].cantidaArcade=cantidadArcadesDeUnSalon(pArcades,lenA,pArcades[j].idSalon);
					iListaeJuegos++;
				}
			}
		retorno=0;
		}else
			 puts("No se ha podido procesar");
			/*
			for (int l = 0; l < lenC; ++l)
		   	{
		   	printf("ID %d Cant %d IsEmt %d\n",pCantSalones[l].idSalon,pCantSalones[l].cantidaArcade,pCantSalones[l].isEmptySalon);
		   	}
			*/
	return retorno;
}
/**
 * \brief busca un id en la lista de salon ides
 * \param  *peJuegos recibo array por referencia, lenA tamaño del array y el cuit buscado
 * \return Retorna 0 si encontro el if y -1 si no lo encuentra
 */
int estaUnIdSalonEnLista(eCantArcadeSalon *pCantSalones,int lenC, int idSalon)
{
	int estado=-1;
	int j;
	if (pCantSalones!=NULL && lenC>0)
		{
		  for (j=0;j<lenC;j++)
			  {
				  if(pCantSalones[j].isEmptySalon==0 && pCantSalones[j].idSalon==idSalon)
						{
							estado=0;
							break;
						}
			  }
		 }else
			 puts("No se ha podido procesar");
	return estado;
}
/**
 * \brief inicializa todas las posiciones del array contrato como Libres pone la bander isEmpty en -1
 * \param  *peJuegos recibo array por referencia, lenA tamaño del array
 * \return Retorna 0 si todo bien y -1 si no logro inicializar el array
 */
int inicializarListaSalon(eCantArcadeSalon *pCantSalones,int lenC)
{
	int estado=-1;
	int j;
	   if (pCantSalones!=NULL && lenC>0)
	   {
		  for (j=0;j<lenC;j++)
		   {
			  pCantSalones[j].isEmptySalon=LIBRE;
			  pCantSalones[j].idSalon=OCUPADO;
			  pCantSalones[j].cantidaArcade=OCUPADO;
			  estado=0;
		   }
	   }else
			 puts("No se ha podido procesar");
return estado;
}
/**
* \brief Ingresar el ID de un salón, y el valor en pesos de una ficha,
*  e imprimir el monto máximo en pesos que puede recaudar el salón.
* \param  *parcade y *pSalon recibo array por referencia,y sus len tamaño del array
* \return Retorna cantidad de arcdes -1 si el no exixte
*/
int informeF(eArcade *pArcades,int lenA,eSalon *pSalones,int lenS)
{
	int estado=-1;
	int idSalon;
	int posSalon=-1;
	float valorFicha;
	int sumatoriaDeFichas=0;
	float montoMaximo;
	if(pArcades!=NULL && lenA>0 && pSalones!=0 && lenS>0)
	{
		imprimirSalonCargado(pSalones, lenS);
		pedirInt(&idSalon, "Ingrese Id de Salon","Id invalido",MINIMO,CAN_SALON,INTENTOS);
		posSalon=buscarPosicionDeSalonporSuId(pSalones, lenS, idSalon);
		if(posSalon>=0)
		{
			pedirFloat(&valorFicha,"Ingrese valor de la ficha en Pesos","Error Valor entre 1 y 10 Pesos",MINIMO,MAXIMO10,INTENTOS);
			for (int j=0;j<lenA; ++j)
					{
						if(pArcades[j].idSalon==idSalon)
						{
							sumatoriaDeFichas=sumatoriaDeFichas+pArcades[j].capMaxFichaArcade;
							estado=0;
						}
					}
					montoMaximo=valorFicha*sumatoriaDeFichas;
					printf("\n\tEl monto máximo que puede facturar el Salon es %.2f Pesos\n\n",montoMaximo);
		}else
			puts("Ingrese Id Valido");

	}else
		 puts("No se ha podido procesar");
	return estado;
}
/**
* \brief se Ingresar el nombre de un juego e imprimir cuantos arcades lo contienen.
* \param  *parcade recibo array por referencia,len tamaño del array, id
* \return Retorna cantidad de arcdes -1 si el no exixte
*/
int informeG(eArcade *pArcades,int lenA)
{
	int estado=-1;
	char auxNombreJuego[63];
	int esta;
	int cantidad=0;
	if(pArcades!=NULL && lenA>0)
	{
		pedirText(auxNombreJuego,sizeof(auxNombreJuego),"Ingrese el Nombre del Juego","Nombre no valido",INTENTOS);
		esta=estaUnJuegoEnListaDeArcade(pArcades,CAN_ARCADE,auxNombreJuego);
		if(esta==0)
		{
			for (int j=0;j<lenA; ++j)
			{
				if(pArcades[j].isEmptyArcade==0 && strcmp(pArcades[j].nombreJuego,auxNombreJuego)==0)
				{
					cantidad++;
					estado=0;
				}
			}
		if(cantidad==1)
			{
			printf("\n\tEl juego %s esta contenido en %d arcade\n\n",auxNombreJuego,cantidad);
			}else
				{
				printf("\n\tEl juego %s esta contenido en %d arcades\n\n",auxNombreJuego,cantidad);
				}

		}else
		{
			puts("El juego buscado no esta en la lista de Arcades disponibles");
		}
	}else
		 puts("No se ha podido procesar");
return estado;
}
/**
* \brief Busca cantidad de arcades de un Salon búsqueda por IdSalon.
* \param  *parcade recibo array por referencia,len tamaño del array, id
* \return Retorna cantidad de arcdes -1 si el no exixte
*/
int cantidadArcadesDeUnSalon(eArcade *pArcades, int lenA, int iDSalon)
{
	int estado=-1;
	int j;
	int cantidadArcades=0;
	if (pArcades!=NULL && lenA>0 && iDSalon>0)
		{
		  for (j=0;j<lenA;j++)
			  {
				  if(pArcades[j].isEmptyArcade==0 && pArcades[j].idSalon==iDSalon)
						{
							cantidadArcades++;
					  	  	estado=cantidadArcades;
						}
			  }
		 }else
			 puts("No se ha podido procesar");
	return estado;
}
/**
 * \brief busca un Juego en la lista de eJuegoss
 * \param  *peJuegos recibo array por referencia, lenA tamaño del array y el juego buscado
 * \return Retorna 0 si encontro el juego y -1 si no lo encuentra
 */
int estaUnJuegoEnListaDeArcade(eArcade *pArcades, int lenA, char nombreJuego[])
{
	int estado=-1;
	int j;
	if (pArcades!=NULL && lenA>0)
		{
		  for (j=0;j<lenA;j++)
			  {
				  if(pArcades[j].isEmptyArcade==0 && strcmp(pArcades[j].nombreJuego,nombreJuego)==0)
						{
							estado=0;
							break;
						}
			  }
		 }else
			 puts("No se ha podido procesar");
return estado;
}
