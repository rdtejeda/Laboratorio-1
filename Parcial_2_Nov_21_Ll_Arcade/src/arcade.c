/*
 * arcade.c
 *
 *  Created on: 20 nov. 2021
 *      Author: usuario
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

#include "LinkedList.h"//
#include "controller.h"//
#include "arcade.h"//
#include "parser.h"//
#include "pedirValidar.h"//
#include "Menu.h"//
#include "Juego.h"//

#define MONO 1
#define STEREO 2
#define MINIMO 1
#define MAXIMO10 10
#define INTENTOS 3
#define MAXIMO4 4
#define MAXIMO100 100

/**
* \brief reserva de forma dinamica memoria para un dato tipo Arcade
* \param es void
* \return Retorna *pArcade a direcion de memoria reservada
*/
Arcade* arcade_new()
{
	Arcade* pArcade=(Arcade*)malloc(sizeof(Arcade));
	if(pArcade==NULL)
		{
			puts("No se ha podido reservar espacio en memoria");
		}
return pArcade;
}
/**
* \brief libera memoria reservada de forma dinamica que no pudo ser utilizada
* \param *pArcade
* \return es void
*/
void arcade_delete(Arcade* pArcade)
{
	if(pArcade!=NULL)
	{
		free(pArcade);
	}
}
/**
* \brief Realiza un *pArcade, carga los valores en todos los campos de una entidad Arcade
* \param es recibe puntero a char de los cuatro campos
* \return Retorna *pArcade a direcion de memoria reservada
*/
Arcade* arcade_newParametros(char* idArcadeStr,char* nacionalidad,char* tipoSonidoStr,
		char* cantidadJugadoresStr,char* capMaxFichasStr,char* salon,char* nombreJuego)
{
	Arcade* pArcade;
	pArcade=arcade_new();
	if(pArcade!=NULL && idArcadeStr!=NULL && nacionalidad!=NULL && tipoSonidoStr!=NULL
			&& cantidadJugadoresStr!=NULL && capMaxFichasStr!=NULL && salon!=NULL && nombreJuego!=NULL)
	{
		if(arcade_setIdChar(pArcade,idArcadeStr)!=0 ||arcade_setNacionalidadChar(pArcade,nacionalidad)!=0 ||
		arcade_setTipoSonidoChar(pArcade,tipoSonidoStr)!=0 || arcade_setCantidadJugadoresChar(pArcade,cantidadJugadoresStr)!=0 ||
		arcade_setCapMaxFichasChar(pArcade,capMaxFichasStr) || arcade_setSalonChar(pArcade,salon) || arcade_setNombreJuegoChar(pArcade,nombreJuego))
		{
			arcade_delete(pArcade);
			pArcade=NULL;
			puts("Algun dato no ha sido valido - Intentelo nuevamente");
		}
	}else
			puts("No se ha podido crear nuevo empleado");
return pArcade;
}
/**
* \brief Busca posicion en LnkedList de un Arcade por su Id y lo modifica
* \param es recibe *pLinkedList id buscado
* \return Retorna posicion si lo encontro y -1 si no existe Employee
*/
int arcade_modificar(LinkedList* pLinkedList)
{
	int posicion;
	int idModif;
	int retorno=-1;
	int opcion;
	char bufferNombreJuego[64];
	int bufferCantidadJugadores;
	if(pLinkedList!=NULL)
		{
		pedirInt(&idModif,"Ingrese el Id del arcade a MODIFICAR","Error ingrese Id valido",MINIMO,decimeElUltimoIdArcade(),INTENTOS);
		posicion=arcade_findById(pLinkedList, idModif);
		if(posicion>=0 && ll_get(pLinkedList,posicion)!=NULL )
			{
			puts("Se modificara el arcade");
			controller_ListUnArcade(pLinkedList,posicion);
			pedirInt(&retorno,"Para Modificar ingrese 1 si no 2","Error ingrese 1 Baja o 2 Mantener",MONO,STEREO,INTENTOS);
			if(retorno==1)
				{
				do
					{
					opcion=menuOpcion();
					switch(opcion)
						{
						case 1://"1. Nombre Juego"
						puts("Los juegos excistentes son:");
						juego_hacerListaDeJuegos(pLinkedList);
						pedirTextoAlfanumerico(bufferNombreJuego,sizeof(bufferNombreJuego),"Ingres nuevo nombre de Juego","Nombre invalido", INTENTOS);
						arcade_setNombreJuegoChar(ll_get(pLinkedList,posicion),bufferNombreJuego);
						puts("La nueva lista de juegos es");
						juego_hacerListaDeJuegos(pLinkedList);
						puts("Su modificacion es");
						controller_ListUnArcade(pLinkedList, posicion);
							break;
						case 2://"2. Cantidad de Jugadores"
						pedirInt(&bufferCantidadJugadores,"Ingres cantidad de jugadores","Error ingrese entre 1 y 4",MINIMO,MAXIMO4,INTENTOS);
						arcade_setCantidadJugadoresInt(ll_get(pLinkedList,posicion),bufferCantidadJugadores);

						puts("Su modificacion es");
						controller_ListUnArcade(pLinkedList, posicion);
							break;
						default:
							break;
						}
					}while(opcion!=3);//"3. Salir"

				printf("Se ha modificado el arcade con Id %d\n",idModif);
				retorno=0;
				}else
					puts("Se cancelo la modificacion");
			}else
				puts("El arcade ya fue eliminado");
		}
return retorno;
}
/*
 * brief permite eliminar un employee lo elige, busca posición
 * param *pLinkedListEmpleados a LinkedList
 * return o si todo bien y 1 si salio mal
 */
int arcade_remover(LinkedList* pLinkedList)
{
	int posicion;
	int idbaja;
	int retorno=-1;
	if(pLinkedList!=NULL)
		{
		pedirInt(&idbaja,"Ingrese el Id del arcade a dar de baja","Error ingrese Id valido",MINIMO,decimeElUltimoIdArcade(),INTENTOS);
		posicion=arcade_findById(pLinkedList, idbaja);
		if(posicion>=0 && ll_get(pLinkedList,posicion)!=NULL )
			{
			puts("Se ha dara de baja al arcade");
			controller_ListUnArcade(pLinkedList, posicion);
			pedirInt(&retorno,"Para dar de baja ingrese 1 si no 2","Error ingrese 1 Baja o 2 Mantener",MONO,STEREO,INTENTOS);
				if(retorno==1)
				{
				free(ll_get(pLinkedList,posicion));
				ll_remove(pLinkedList,posicion);
				printf("Se ha dado de baja al arcade con Id %d\n",idbaja);
				retorno=0;
				}else
					puts("Se cancelo la baja");

			}else
				puts("El arcade ya estaba eliminado");
		}
return retorno;
}
/**
* \brief Busca posicion en LnkedList de un Arcade por su Id
* \param es recibe *pLinkedList e id buscado
* \return Retorna posicion si lo encontro y -1 si no existe Employee
*/
int arcade_findById(LinkedList* pLinkedList, int id)
{
	int retorno=-1;
	int posicion;
	Arcade* pAuxiliarArcade;
	if(pLinkedList!=NULL && id>0)
		{

		for (int i = 0; i < ll_len(pLinkedList); i++)
			{
				pAuxiliarArcade=ll_get(pLinkedList,i);
				if(pAuxiliarArcade->idArcade==id)
				{
					if(pAuxiliarArcade!=NULL)
					{
						posicion=i;
						break;
					}
				}
			}
		retorno=posicion;
		}
return retorno;
}
/**
* \brief setea valor de Id en una entidad *Arcade
* \param *pEmployee y *id char
* \return 0 si lo logro y -1 todo mal
*/
int arcade_setIdChar(Arcade* this,char* idArcadeStr)
{
 int retorno=-1;
 if(this!=NULL && idArcadeStr!=NULL && esNumericaInt(idArcadeStr)==0)
	 {
	 	 this->idArcade=atoi(idArcadeStr);
		 retorno=0;
	 }
 return retorno;
}
/**
* \brief setea valor de nacionalidad de en una entidad *arcade
* \return 0 si lo logro y -1 todo mal
*/
int arcade_setNacionalidadChar(Arcade* this,char* nacionalidad)
{
int retorno=-1;
if(this!=NULL && nacionalidad!=NULL && esNombre(nacionalidad)==0)
	{
	strncpy(this->nacionalidad,nacionalidad,sizeof(this->nacionalidad));
	retorno=0;
	}
return retorno;
}
/**
* \brief setea valor de tipo de sonido en una entidad *Arcade
* \param *pEmployee y *id char
* \return 0 si lo logro y -1 todo mal
*/
int arcade_setTipoSonidoChar(Arcade* this,char* tipoSonidoStr)
{
 int retorno=-1;
 char mono[5]="MONO";
 char stereo[8]="STEREO";
 if(this!=NULL && tipoSonidoStr!=NULL && esNombre(tipoSonidoStr)==0)
	 {
	 	 if(strcmp(tipoSonidoStr,mono)==0)
	 		this->tipoSonido=MONO;
	 	 if(strcmp(tipoSonidoStr,stereo)==0)
	 		 this->tipoSonido=STEREO;
	 	 retorno=0;
	 }
 return retorno;
}
/**
* \brief setea valor de cantidad de jugadores en una entidad *Arcade
* \param *pEmployee y *id char
* \return 0 si lo logro y -1 todo mal
*/
int arcade_setCantidadJugadoresChar(Arcade* this,char* cantidadJugadoresStr)
{
 int retorno=-1;
 if(this!=NULL && cantidadJugadoresStr!=NULL && esNumericaInt(cantidadJugadoresStr)==0)
	 {
		 this->cantidadJugadores=atoi(cantidadJugadoresStr);
		 retorno=0;
	}
 return retorno;
}
/**
* \brief setea valor de cantidad de jugadores en una entidad *Arcade
* \param *pEmployee y *id char
* \return 0 si lo logro y -1 todo mal
*/
int arcade_setCapMaxFichasChar(Arcade* this,char* capMaxFichasStr)
{
 int retorno=-1;
 if(this!=NULL && capMaxFichasStr!=NULL && esNumericaInt(capMaxFichasStr)==0)
	 {
		 this->capMaxFichas=atoi(capMaxFichasStr);
		 retorno=0;
	 }
 return retorno;
}
/**
* \brief setea valor de salon de en una entidad *arcade
* \return 0 si lo logro y -1 todo mal
*/
int arcade_setSalonChar(Arcade* this,char* salon)
{
int retorno=-1;
if(this!=NULL && salon!=NULL && esAlfaumerica(salon)==0)
	{
	strncpy(this->salon,salon,sizeof(this->salon));
	retorno=0;
	}
return retorno;
}
/**
* \brief setea valor de nombre de juego de en una entidad *arcade
* \return 0 si lo logro y -1 todo mal
*/
int arcade_setNombreJuegoChar(Arcade* this,char* nombreJuego)
{
int retorno=-1;
if(this!=NULL && nombreJuego!=NULL && esAlfaumerica(nombreJuego)==0)
	{
	strncpy(this->nombreJuego,nombreJuego,sizeof(this->nombreJuego));
	retorno=0;
	}
return retorno;
}
/**
* \brief setea valor de cantidad de jugadores en una entidad *Arcades
* \param *pEmployee y valor horasTrabajadas
* \return o si lo logro y -1 todo mal
*/
int arcade_setCantidadJugadoresInt(Arcade* this,int cantidadJugadores)
{
int retorno=-1;
if(this!=NULL && (cantidadJugadores>0 && cantidadJugadores<5))
	{
		this->cantidadJugadores= cantidadJugadores;
		retorno=0;
	}
return retorno;
}
/**
* \brief setea valor de numero de fichas  en una entidad *Arcades
* \param *pEmployee y valor horasTrabajadas
* \return o si lo logro y -1 todo mal
*/
int arcade_setNumeroFichasInt(Arcade* this,int numerofichas)
{
int retorno=-1;
if(this!=NULL && (numerofichas>=MAXIMO10 && numerofichas<=MAXIMO100))
	{
		this->capMaxFichas= numerofichas;
		retorno=0;
	}
return retorno;
}
/**
* \brief setea valor de tipo de sonido  en una entidad *Arcades
* \param *pEmployee y valor horasTrabajadas
* \return o si lo logro y -1 todo mal
*/
int arcade_setTipoSonidoInt(Arcade* this,int tiposonido)
{
int retorno=-1;
if(this!=NULL && (tiposonido>=MONO && tiposonido<=STEREO))
	{
		this->tipoSonido= tiposonido;
		retorno=0;
	}
return retorno;
}
/**
* \brief entrega el valor de Id en una entidad *Arcade
* \param *pEmployee
* \return id si lo logro y -1 todo mal
*/
int arcade_getIdRet(Arcade* this)
{
int retorno=-1;
if(this!=NULL)
	{
		retorno=this->idArcade;
	}
return retorno;
}
/**
* \brief entrega el valor de tipo de soinido en una entidad *Arcade
* \param *pEmployee
* \return tipo de sonido si lo logro y -1 todo mal
*/
int arcade_getTipoSonidoRet(Arcade* this)
{
int retorno=-1;
if(this!=NULL)
	{
		retorno=this->tipoSonido;
	}
return retorno;
}
/**
* \brief entrega el valor cantidad de jugadores en una entidad *Arcade
* \param *pEmployee
* \return tipo de sonido si lo logro y -1 todo mal
*/
int arcade_getCantidadJugadoresRet(Arcade* this)
{
int retorno=-1;
if(this!=NULL)
	{
		retorno=this->cantidadJugadores;
	}
return retorno;
}
/**
* \brief entrega el valor cantidad de jugadores en una entidad *Arcade
* \param *pEmployee
* \return tipo de sonido si lo logro y -1 todo mal
*/
int arcade_getCapFichasRet(Arcade* this)
{
int retorno=-1;
if(this!=NULL)
	{
		retorno=this->capMaxFichas;
	}
return retorno;
}
/**
* \brief entrega el valor de nacionalidad de una entidad *Arcade
* \param *pEmployee y *nombre chart
* \return 0 si lo logro y -1 todo mal
*/
int arcade_getNacionalidad(Arcade* this,char* nacionalidad)
{
	int retorno=-1;
	if(this!=NULL && nacionalidad!=NULL )
	{
		strcpy(nacionalidad,this->nacionalidad);
		retorno=0;
	}
return retorno;
}
/**
* \brief entrega el valor de salon de una entidad *Arcade
* \param *pEmployee y *nombre chart
* \return 0 si lo logro y -1 todo mal
*/
int arcade_getSalon(Arcade* this,char* salon)
{
	int retorno=-1;
	if(this!=NULL && salon!=NULL )
	{
		strcpy(salon,this->salon);
		retorno=0;
	}
return retorno;
}
/**
* \brief entrega el valor de nombre de juego  de una entidad *Arcade
* \param *pEmployee y *nombre chart
* \return 0 si lo logro y -1 todo mal
*/
int arcade_getNombreJuego(Arcade* this,char* nombreJuego)
{
	int retorno=-1;
	if(this!=NULL && nombreJuego!=NULL )
	{
		strcpy(nombreJuego,this->nombreJuego);
		retorno=0;
	}
return retorno;
}
/*
 * brief permite eliminar todos los arcades y los espacios de memiria asiganados
 * param *pLinkedListEmpleados a LinkedList
 * return o si todo bien y -1 si salio mal
 */
int arcade_removeAllList(LinkedList* pLinkedList)
{
	int retorno=-1;
	Node* auxNode;
	Arcade* auxArcade;
	auxNode=pLinkedList->pFirstNode;
	if(pLinkedList!=NULL)
		{
		for (int j = 0; j < ll_len(pLinkedList); ++j)
			{
			auxArcade=auxNode->pElement;
			free(auxArcade);
			auxNode=auxNode->pNextNode;
			}
		retorno=0;
		}
return retorno;
}
/**
  * \brief me da un id consecutivo y no repetido memorizando el ultimolvalor
  * crea archivo bin para sobrevivir la info en el apagado de la aplicación
  * \param void
  * \return Retorna nuevo id si todo bien  y -1 si no logro
  */
int dameUnIdNuevoArcade(void)
{
	//TEMPORAL se Ejcutó una sola vez al principio
	/*
	int id=500;
	int cantidadt;
	FILE* pFileBinTemp;
	pFileBinTemp=fopen("UltimoId.bin","w");
	if(pFileBinTemp!=NULL)
		{
			cantidadt=fwrite(&id,sizeof(int),1,pFileBinTemp);
			printf("Cantidad de fwrite dice %d\n",cantidadt);
			fclose(pFileBinTemp);
		}else
				 puts("No se ha podido inizilizar el archivo");
	*/
	//TEMPORAL
	int estado=-1;
	int contador;
	FILE* pFileBin;
	pFileBin=fopen("UltimoId.bin","r");
	if(pFileBin!=NULL)
		{
			fread(&contador,sizeof(int),1,pFileBin);
			fclose(pFileBin);
			printf("El ultimo id generado fue: %d\n",contador);
			contador++;
			printf("El nuevo id generado es: %d\n",contador);
			estado=contador;
		}else
			puts("No se ha podido abrir el archivo");

	pFileBin=fopen("UltimoId.bin","w");
	if(pFileBin!=NULL)
		{
			fwrite(&contador,sizeof(int),1,pFileBin);
			fclose(pFileBin);
		}else
			puts("No se ha podido inizilizar el archivo");
	return estado;
}
/**
  * \brief me da el id mas alto generado
  * abre, lee y cierra el archivo
  * \param void
  * \return Retorna nuevo id si todo bien  y -1 si no logro
  */
int decimeElUltimoIdArcade(void)
{
	int estado=-1;
	int contador;
	FILE* pFileBin;
	pFileBin=fopen("UltimoId.bin","r");
	if(pFileBin!=NULL)
		{
		fread(&contador,sizeof(int),1,pFileBin);
		fclose(pFileBin);
		estado=contador;
		printf("el ultimo es %d\n",estado);
		}else
			puts("No se ha podido abrir el archivo");

return estado;
}

/*
 * brief  transfiere los valores de nombre dos entidades employee
 * brief recibe dos punteros *void
 * return 1 o -1 segun el criterio establecido
 */
int arcade_CriterioOrdenaJuego(void* pVoidUno, void* pVoidCero)
{
	int retorno=0;
	char namecero[64];
	char nameuno[64];

	Arcade* pArcadeCero;
	Arcade* pArcadeUno;

	pArcadeCero=(Arcade*)pVoidCero;
	pArcadeUno=(Arcade*)pVoidUno;

	strncpy(namecero,pArcadeCero->nombreJuego,sizeof(namecero));
	strncpy(nameuno,pArcadeUno->nombreJuego,sizeof(nameuno));

	if(strcmp(namecero,nameuno)<0)
		{
			retorno=1;
		}
	if(strcmp(namecero,nameuno)>0)
		{
			retorno=-1;
		}
return retorno;
}
