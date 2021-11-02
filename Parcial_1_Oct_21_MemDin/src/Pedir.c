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

/**
* \brief pide un char al ususario
* \param puntero cahr, reintentos y textos de pedido y erro
* \return Retorna -1  salio mal, 0 salio bien y 2 sin reintento
*/
int pedirCharAUsuario(char *pChar, int reintentos, char *txt, char *txtError)
{

	int retorno=-1;
	int i;
	char bufferCadenaAux[2];
	if(pChar != NULL && reintentos >=0 && txt != NULL && txtError != NULL)
	{
		for (i=0; i<=reintentos; i++)
		{
			printf("\n%s\n", txt);
			__fpurge(stdin);
			if(myGets(bufferCadenaAux,sizeof(bufferCadenaAux))==0)
				{
				if(esAlfabetica(pChar)==0)
				strncpy(pChar, bufferCadenaAux,1);
					retorno = 0;
					break;
				}else
				{
						printf("%s", txtError);

				}
		}
	}else
		 puts("No se ha podido procesar");
	return retorno;
}
/**
* \brief pide un texto al ususario
* \param *pResultado, len tamaño del array, *mensaje, *mensajeError, intentos
* \return Retorna -1  salio mal, 0 salio bien
*/
int pedirText(char *pResultado, int len, char *mensaje, char *mensajeError, int intentos)
{
	int retorno = -1;
	int i;
	char bufferCadenaAux[128];
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && intentos >= 0)
	{
		for(i=0; i<=intentos; i++)
		{

			printf("\n%s\n", mensaje);
			__fpurge(stdin);
			if(myGets(bufferCadenaAux,sizeof(bufferCadenaAux))==0  && strlen(bufferCadenaAux)>0)
			{
				strncpy(pResultado, bufferCadenaAux,len);
				if (esAlfaumerica(pResultado)==0)
				{
					retorno = 0;
				break;
				}
			}else
				{
					printf("%s", mensajeError);
				}
		}
	}else
		 puts("No se ha podido procesar");
	return retorno;
}
/**
  * \brief Solicita un numero al usuario, leuego de verificarlo devuelve el resultado
  * \param *pResultado, *mensaje, *mensajeError, minimo, maximo, intentos
  * \return Retorna 0 si se obtuvo el numero y -1 si no
  */
 int pedirInt(int *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo, int intentos)
 {
 	int retorno = -1;
 	int bufferInt;
 	int i;
 	char bufferCadenaAux[32];

 	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && intentos >= 0)
 	{
 		for(i=0; i<=intentos; i++)
 		{
 			printf("\n%s\n", mensaje);
 			__fpurge(stdin);
 			if(myGets(bufferCadenaAux,sizeof(bufferCadenaAux))==0)
 			{
 				if(esNumericaInt(bufferCadenaAux)==0)
 					{
 					bufferInt = atoi(bufferCadenaAux);
 					if(bufferInt >= minimo && bufferInt <= maximo)
 						{
 							*pResultado = bufferInt;
 							retorno = 0;
 							break;
 						}else
 							{
 							printf("%s", mensajeError);
 							}
 					}
 				else
 					{
 					printf("%s", mensajeError);
 					}
 			}
 			else
 				{
 				printf("%s", mensajeError);
 				}
 		}
 		if(retorno==-1)
 		{
 			printf("\nTe quedaste sin intentos\n");
 		}
 	}else
		 puts("No se ha podido procesar");
 	return retorno;
 }
/**
  * \brief Verifica si la cadena ingresada es numerica
  * \param *cadena Puntero al espacio de memoria donde se dejara el resultado de la funcion
  * \return Retorna 0 si se obtiene un numero  y -1 si no
 */
 int esNumericaInt(char *cadena)
 {
 	int i=0;
 	int retorno=-1;
 	if(cadena!=NULL && strlen(cadena)> 0)
 	{
 		retorno=0;
 		while(cadena[i]!='\0')
 			{
 				if(cadena[i]<'0'||cadena[i]> '9')
 					{
 					retorno=-1;
 					break;
 					}
 				i++;
 			}
 	}else
		 puts("No se ha podido procesar");
 	return retorno;
 }
 /**
  * \brief Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena un máximo de 'longitud - 1' caracteres.
  * \param *pResultado paso por referncia el array, len tamaño del array
  * \return Retorna 0 si se obtiene una cadena y -1  si no
 */
 int myGets(char *pResultado, int len)
 {
 	int retorno=-1;
 	int indexFinal;
 	if(fgets(pResultado,len,stdin)!=NULL)
 	{
 		__fpurge(stdin);
 		indexFinal = strlen(pResultado)-1;
 		if(pResultado[indexFinal] == '\n')
 			{
 			pResultado[indexFinal] = '\0';
 			}
 		retorno = 0;
 	}else
		 puts("No se ha podido procesar");
 	return retorno;
 }
  /**
  * \brief Solicita un numero al usuario, leuego de verificarlo devuelve el resultado
  * \param *pResultado, *mensaje, *mensajeError, minimo, maximo, intentos
  * \return Retorna 0 si se obtuvo el numero y -1 si no
  */
 int pedirFloat(float *pResultado, char *mensaje, char *mensajeError, float minimo, float maximo, int intentos)
 {
 	int retorno = -1;
 	float bufferInt;
 	int i;
 	char bufferCadenaAux[32];

 	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && intentos >= 0)
 	{
 		for(i=0; i<=intentos; i++)
 		{
 			printf("\n%s\n", mensaje);
 			__fpurge(stdin);
 			if(myGets(bufferCadenaAux,sizeof(bufferCadenaAux))==0)
 			{
 				if(esNumericaFloat(bufferCadenaAux)==0)
 					{
 					bufferInt = atof(bufferCadenaAux);
 					if(bufferInt >= minimo && bufferInt <= maximo)
 						{
 							*pResultado = bufferInt;
 							retorno = 0;
 							break;
 						}else
 							{
 							printf("%s", mensajeError);
 							}
 					}
 				else
 					{
 					printf("%s", mensajeError);
 					}
 			}
 			else
 				{
 				printf("%s", mensajeError);
 				}
 		}
 		if(retorno==-1)
 		{
 			printf("\nTe quedaste sin intentos\n");
 		}
 	}else
		 puts("No se ha podido procesar");
 	return retorno;
 }
 /**
 * \brief Verifica si la cadena ingresada es numerica
 * \param *cadena paso por referencia Cadena de caracteres a ser analizada
 * \return Retorna 0  si la cadena es numerica y -1  si no lo es
 */
 int esNumericaFloat(char *cadena)
 {
 	int i=0;
 	int retorno = -1;
 	int contNeg=0;
 	int contPuntos=0;
 	if(cadena != NULL && strlen(cadena) > 0)
 	{
 		retorno=0;
 		while(cadena[i] != '\0')
 			{
 				if(cadena[i] < '0' || cadena[i] > '9')
 					{
 					if(cadena[i]=='-' || cadena[i]=='.')
 						{
 							if(cadena[i]=='-')
 							{
 								contNeg++;
 								if(i!=0)
 								{
 									retorno = -1;
 									break;
 								}
 							}
 							if(cadena[i]=='.')
 							{
 								contPuntos++;
 							}
 						}else
 						{
 							retorno = -1;
 							break;
 						}
 					}
 				i++;
 			}
 		if(contNeg>1 ||contPuntos>1)
 		{
 			retorno=-1;
 		}
 	}else
		 puts("No se ha podido procesar");
 	return retorno;
 }
/**
* \brief Verifica si la cadena ingresada es alfanumerica
* \param *cadena Paso por referencia Cadena de caracteres a ser analizada
* \return Retorna 0 si la cadena es alfa numerica y -1 si no lo es
*/
int esAlfaumerica(char *cadena)
{
	int i=0;
	int retorno = 0;
	if(cadena != NULL && strlen(cadena) > 0)
	{
		while(cadena[i] != '\0')
			{
				if((cadena[i]<'0'||cadena[i]>'9')&&(cadena[i]<'A'||cadena[i]>'Z')&&(cadena[i]<'a'||cadena[i]>'z')&&cadena[i]==164&&cadena[i]==165)
					{
						if (cadena[i]==' ')
						{
							if(i==0)
							{
								retorno=-1;
								break;
							}
						}else
						{
							retorno = -1;
							break;
						}
					}
				i++;
			}
	}else
		 puts("No se ha podido procesar");
	return retorno;
}
/**
* \brief Verifica si la cadena ingresada es alfabetica
* \param *cadena Paso por referencia Cadena de caracteres a ser analizada
* \return Retorna 0 si la cadena es alfa numerica y -1 si no lo es
*/
int esAlfabetica(char *cadena)
{
	int i=0;
	int retorno = 0;
	if(cadena != NULL)
	{
		while(cadena[i] != '\0')
			{
				if((cadena[i]<'A'||cadena[i]>'Z')&&(cadena[i]<'a'||cadena[i]>'z')&&cadena[i]==164&&cadena[i]==165)
					{
						if (cadena[i]==' ')
						{
							if(i==0)
							{
								retorno=-1;
								break;
							}
						}else
						{
							retorno = -1;
							break;
						}
					}
				i++;
			}
	}else
		 puts("No se ha podido procesar");
	return retorno;
}
