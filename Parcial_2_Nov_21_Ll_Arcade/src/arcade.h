/*
 * arcade.h
 *
 *  Created on: 20 nov. 2021
 *      Author: usuario
 */

#ifndef ARCADE_H_
#define ARCADE_H_

typedef struct
{
	int idArcade;
	char nacionalidad[64];
	int tipoSonido;
	int cantidadJugadores;
	int capMaxFichas;
	char salon[64];
	char nombreJuego[64];
}Arcade;

Arcade* arcade_new();
void arcade_delete(Arcade* pArcade);
Arcade* arcade_pedirParametros();
Arcade* arcade_newParametros(char* idArcade,char* nacionalidad,char* tipoSonido,char* cantidadJugadores,char* capMaxFichas,char* salon,char* nombreJuego);

int arcade_modificar(LinkedList* pLinkedList);
int arcade_remover(LinkedList* pLinkedList);
int arcade_findById(LinkedList* pLinkedList, int id);

int arcade_setIdChar(Arcade* this,char* idArcadeStr);
int arcade_setTipoSonidoChar(Arcade* this,char* tipoSonidoStr);
int arcade_setCantidadJugadoresChar(Arcade* this,char* cantidadJugadoresStr);
int arcade_setCapMaxFichasChar(Arcade* this,char* capMaxFichasStr);
int arcade_setSalonChar(Arcade* this,char* salon);
int arcade_setNombreJuegoChar(Arcade* this,char* nombreJuego);
int arcade_setNacionalidadChar(Arcade* this,char* nacionalidad);

int arcade_setCantidadJugadoresInt(Arcade* this,int cantidadJugadores);
int arcade_setNumeroFichasInt(Arcade* this,int numerofichas);
int arcade_setTipoSonidoInt(Arcade* this,int tiposonido);

int arcade_getIdRet(Arcade* this);
int arcade_getTipoSonidoRet(Arcade* this);
int arcade_getCantidadJugadoresRet(Arcade* this);
int arcade_getCapFichasRet(Arcade* this);
int arcade_getNacionalidad(Arcade* this,char* nacionalidad);
int arcade_getSalon(Arcade* this,char* salon);
int arcade_getNombreJuego(Arcade* this,char* nombreJuego);

int arcade_removeAllList(LinkedList* pLinkedListEmpleados);

int dameUnIdNuevoArcade(void);
int decimeElUltimoIdArcade(void);

int arcade_CriterioOrdenaJuego(void* pVoidUno, void* pVoidCero);
int arcade_CriterioOrdenaId(void* pVoidUno, void* pVoidCero);

#endif /* ARCADE_H_ */
