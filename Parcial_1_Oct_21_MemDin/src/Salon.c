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
* \brief reserva de forma dinamica memoria para un dato tipo eSalon
* \param es void
* \return Retorna *eSalon a direcion de memoria reservada
*/
eSalon* nuevoSalonM_D(void)
{
	eSalon* pDeSalon=(eSalon*)malloc(sizeof(eSalon));
	if(pDeSalon==NULL)
	{
		puts("No se ha podido reservar espacio en memoria");
	}
	return pDeSalon;
}

/**
 * \brief inicializa el array de punteros de salones coo valor NULL
 * \param  *plist recibo array por referencia, len tamaño del array
 * \return Retorna 0 si todo bien y -1 si no logro inicializar el array
 */
int iniciarEarrayS(eSalon* pSalones[],int len)
{
	int estado=-1;
	   if (pSalones!=NULL&&len>0)
	   {
		  for (int j = 0;  j<len; j++)
		   {
			  pSalones[j]=NULL;
			  estado=0;
		   }
	   }else
			 puts("No se ha podido procesar");
 return estado;
}

/*
* \brief da de alta un salon en el array de punteros de Display
* \param recibe un array de punteros a  estructura, el largo
* \return Retorna -1 todo mal 0 todo bien
*/
int altaSalon(eSalon* pSalones[],int len)
{
	int retorno=-1;
	int libre;
	if(pSalones!=NULL && len>0)
	{
		libre=buscarLugarLibreArrayS(pSalones,len);
		if(libre>=0)
			{
			eSalon* pSalon = nuevoSalonM_D();
			if(pSalon!=NULL)
				{
				pSalones[libre]=pSalon;
				if(pedirDatosSalon(pSalones[libre])==0)
					{
					imprimirUnSalonCargado(pSalones, len, pSalones[libre]->idSalon);
					retorno=0;
					puts("Se ha completado la carga");
					}else
						puts("No se ha completado la carga");
				}else
					puts("No hay espacio en memoria");
			}else
				puts("No hay espacio libre en el array");
	}else
		 puts("No se ha podido procesar");
return retorno;
}

/**
* \brief caraga de datos para Dar de alta un salon
* \param recibe un estructura por puntero
* \return Retorna 0 si se logor carga  y -1  si no
*/
int pedirDatosSalon(eSalon* pSalones)
{
	int estado=-1;
	int bufferTipoS;
	char bufferNomS[24];
	char bufferdireccioS[48];
	if(pedirInt(&bufferTipoS, "Ingrese tipo Salon Shopping 1 y Salon 2", "Ingrese tipo valido",SHOPPING,LOCAL,INTENTOS)==0)
		   {
			     if(pedirText(bufferNomS, sizeof(bufferNomS), "Ingrese el Nombre del Salon", "DNombre no valido",INTENTOS)==0)
			    	 {
			    		 if(pedirText(bufferdireccioS, sizeof(bufferdireccioS), "Ingrese la Direccion del Salon", "Direccion invalido",INTENTOS)==0)
			    		 {
			    			 salon_setTipo(pSalones, &bufferTipoS);
			    			 salon_setName(pSalones, bufferNomS);
			    			 salon_setDireeccion(pSalones, bufferdireccioS);
			    			 pSalones->idSalon=dameUnIdNuevoS();
			    			 estado=0;
			    		 }
			     }
	   }else
			 puts("No se ha www podido procesar");

	   return estado;
}

/**
* \brief busca el primer index del array de punteros NULL o sea vacio
* \param recibe una lista de punteros y el largo
* \return Retorna lugar el primer lugar libre de la lista o -1 si no encuentra ninguno libre
*/
int buscarLugarLibreArrayS(eSalon* pSalones[],int len)
{
	int retorno=-1;
	if(pSalones!=NULL && len>0)
	{
		for (int i=0;i<len;++i)
		{
			if(pSalones[i]==NULL)
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
 * \brief Da de baja en forma logica un ID = NULL
 * \param recibe un ARRAY DE PUNTEROS, el largo y el id a dar de baja
 * \return Retorna -1 salio mal 0 todo bien
 */
 int bajaLogicaDeUnSalon(eSalon* pSalones[],int len,int idabajar)
 {
	 int retorno=-1;
	 int posicion;
	 posicion=buscarPosicionDeSalonporSuId(pSalones,len,idabajar);
	 if(pSalones[posicion]!=NULL && posicion>=0 && len>0)
	 {
		 free(pSalones[posicion]);
		 pSalones[posicion]=NULL;
		 organizar_arrayS(pSalones, len, posicion);
		 retorno=0;
	 }
	 if(posicion==-1)
		 puts("Debe Ingrese un Id valido");
	 return retorno;
 }

/**
* \brief Busca  la posicion en el array de salon de un Salon recibiendo como parámetro de búsqueda el Id.
* \param  * array por referencia,len tamaño del array, id
* \return Retorna la posicion en el array del id solicitado o -1 si el no exixte
*/

int buscarPosicionDeSalonporSuId(eSalon* pSalones[],int len,int id)
{
	int retorno=-1;
		if(pSalones!=NULL && len>0)
		{
			for (int i=0;i<len;++i)
			{
				if(pSalones[i]!=NULL && pSalones[i]->idSalon==id)
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
int ordenaSalonPorDireccion(eSalon* pSalones[], int len)
{
	int banderaSwapp=-1;
	eSalon* auxiliar=NULL;
	int limite=len;
	int estadostrcmp;
	nuevoArcadeM_D();

	if(pSalones!=NULL && len>0)
	{
		do
		{
			banderaSwapp=0;
			limite=limite-1;
			for (int i=0; i<limite; i++)
			{
				if(pSalones[i]!=NULL && pSalones[i+1]!=NULL)
				{
					estadostrcmp=strcmp(pSalones[i]->nombreSalon,pSalones[i+1]->nombreSalon);
					if(estadostrcmp>0)
						{
							banderaSwapp=1;
							auxiliar=pSalones[i];
							pSalones[i]=pSalones[i+1];
							pSalones[i+1]=auxiliar;
						}
				}
			}
		}while(banderaSwapp==1);

	}else
		 puts("No se ha podido procesar");
	return banderaSwapp;
}

/**
* \brief busca e Imprime el array Salon cargado con datos flag busy
* \param recibe un ARRAY DE PUNTEROS A ESTRUCTURA o y el largo
* \return Retorna cantidad de cargados y -1  si no hay
*/
int imprimirSalonCargado(eSalon* pSalones[], int len)
{
	int estado=-1;
	int contadordeCargados=0;
	ordenaSalonPorDireccion(pSalones, len);
	imprimirEncSalonCargado();
	if (pSalones!=NULL && len>0)
	{
		for (int i= 0;  i< len; i++)
		{
			if(pSalones[i]!=NULL)
			{
				printf(" %-30s %-30s \t%d\t\t%d\n",
				pSalones[i]->nombreSalon,pSalones[i]->direccionSalon,pSalones[i]->tipoSalon,
				pSalones[i]->idSalon);
				contadordeCargados++;
				estado=contadordeCargados;
			}
		}
		imprimirLinea();
		if(contadordeCargados==0)
			{
			puts("NO HAY Aracdes CARGADOS");
			}
	}else
		 puts("No se ha podido procesar");
	return estado;
}

int grabarSalonCargado(eSalon* pSalones[], int len)
{
	int estado=-1;
	ordenaSalonPorDireccion(pSalones, len);
	FILE* fp;
	fp=fopen("MisSalonesII.txt","w");//ABRIR
	if (pSalones!=NULL && len>0)
	{
		for (int i= 0;  i< len; i++)
			{
			if(pSalones[i]!=NULL)
				{

				if(fp!=NULL)
					{
					fprintf(fp,"%s,%s,%d,%d\n",
					pSalones[i]->nombreSalon,pSalones[i]->direccionSalon,pSalones[i]->tipoSalon,
					pSalones[i]->idSalon);
					}else
						printf("Error abriendo archivo\n");//escri en txt
				}
			}

	}else
					 puts("No se ha podido procesar");
	fclose(fp);//CERRAR Y GRABAR
return estado;
}

int leerSalonesGrabados(eSalon* pSalones[], int len)
{
	int estado=-1;
	FILE* fp;
	char auxName[60];
	char auxDir[60];
	int a;
	int b;
	int libre;
	if ((fp=fopen("MisSalonesII.txt","r"))!=NULL)
		{
			for (int i= 0;  i< len; i++)
				{
					//puts("Pase");
					if((fscanf(fp,"%[^,],%[^,],%d,%d\n",auxName,auxDir,&a,&b))==4)
					{
						printf("%s %s %d,%d\n",auxName,auxDir,a,b);
						if(pSalones!=NULL && len>0)
							{
								libre=buscarLugarLibreArrayS(pSalones,len);
								if(libre>=0)
									{
									eSalon* pSalon = nuevoSalonM_D();
									if(pSalon!=NULL)
										{
										pSalon->idSalon=b;
										pSalon->tipoSalon=a;
										strcpy(pSalon->nombreSalon,auxName);
										strcpy(pSalon->direccionSalon,auxDir);
										pSalon->idSalon=dameUnIdNuevoS();
										pSalones[libre]=pSalon;
										}else
											puts("No hay espacio en memoria");
									}else
										puts("No hay espacio libre en el array");
							}else
								 puts("No se ha podido procesar");
					}
				}
		}else
				printf("Error abriendo archivo\n");
	fclose(fp);//CERRAR Y GRABAR

	return estado;
}



/**
* \brief CALCULA LA CANTIDAD DE ELEMENTO NO null EN EL ARRAY DE PUNTEROS
* \param recibe un ARRAY DE puntero, el largo
* \return Retorna CANTIDAD DE ELEMNTODS O -1  si no
*/
int largoArrayS(eSalon* pSalones[],int len)
{
	int retorno=-1;
	int contBusy=0;
	if(pSalones!=NULL && len>0)
	{
		for (int i=0;i<len;++i)
		{
			if(pSalones[i]!=NULL)
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
* \param recibe un ARRAY DE PUNTEROS A estructura por puntero, el largo  y el id a imprimir
* \return Retorna 0 todo bien  y -1  si no
*/
int imprimirUnSalonCargado(eSalon* pSalones[], int len, int idmostrar)
{

	int estado=-1;
	int posicion;
	posicion=buscarPosicionDeSalonporSuId(pSalones, len, idmostrar);
	imprimirEncSalonCargado();
	if (posicion>=0)
	{
		printf(" %-30s %-30s \t%d\t\t%d\n",
		pSalones[posicion]->nombreSalon,pSalones[posicion]->direccionSalon,pSalones[posicion]->tipoSalon,
		pSalones[posicion]->idSalon);
		estado=0;
		imprimirLinea();
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

/**
* \brief setea tipo de salon
* \param recibe como PUNTEROS A estructura y valor de tipo
* \return Retorna 0 todo bien  y -1  si no
*/
int salon_setTipo(eSalon* pSalon,int* tipoS)
{
	int retorno=-1;
	if(pSalon!=NULL && tipoS!=NULL)
		{
		//pedirInt(&bufferTipoS, "Ingrese tipo Salon Shopping 1 y Salon 2", "Ingrese tipo valido",SHOPPING,LOCAL,INTENTOS)==0
		pSalon->tipoSalon=*tipoS;
		retorno=0;
		}
	return retorno;
}

/**
* \brief setea el nombre de salon
* \param recibe como PUNTEROS A estructura y nombre
* \return Retorna 0 todo bien  y -1  si no
*/
int salon_setName(eSalon* pSalon,char* nombreS)
{
	int retorno=-1;
	if(pSalon!=NULL && nombreS!=NULL)
		{
		strncpy(pSalon->nombreSalon,nombreS,sizeof(pSalon->nombreSalon));
		retorno=0;
		}
	return retorno;
}

/**
* \brief setea la direeccio de salon
* \param recibe como PUNTEROS A estructura y direccion
* \return Retorna 0 todo bien  y -1  si no
*/
int salon_setDireeccion(eSalon* pSalon,char* direccionS)
{
	int retorno=-1;
	if(pSalon!=NULL && direccionS!=NULL)
		{
		strncpy(pSalon->direccionSalon,direccionS,sizeof(pSalon->direccionSalon));
		retorno=0;
		}
	return retorno;
}

/**
* \brief organiza el array de salones luego de eliminar un elemento
* \param recibe como PUNTEROS array de punteros de estructura largo y posicion borrada
* \return Retorna 0 todo bien  y -1  si no
*/
int organizar_arrayS(eSalon* pSalones[],int len,int posicion)
{
	int retorno=-1;
	if(pSalones!=NULL && len>0 && posicion>=0)
	for (int i=posicion; i< len; ++i)
		{
		pSalones[posicion]=pSalones[posicion+1];
		pSalones[posicion+1]=NULL;
		retorno=0;
		}
	return retorno;
}

//========================================================================================
void harcodearunSalon(eSalon* pSalones[],char nombreSalon[24],char direccionSalon[48],int tipoSalon,int len)
{
	int libre=buscarLugarLibreArrayS(pSalones,len);
	if(libre>=0)
		{

				eSalon* pSalon = nuevoSalonM_D();
				pSalones[libre]=pSalon;
				strncpy(pSalones[libre]->nombreSalon, nombreSalon,sizeof(pSalones[libre]->nombreSalon));
				strncpy(pSalones[libre]->direccionSalon, direccionSalon,sizeof(pSalones[libre]->direccionSalon));
				pSalones[libre]->tipoSalon=tipoSalon;
				pSalones[libre]->idSalon=dameUnIdNuevoS();
		}
}
//====================================================================================
