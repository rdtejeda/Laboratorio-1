/*
 * controller.h
 *
 *  Created on: 20 nov. 2021
 *      Author: usuario
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_


int controller_leerArchivo(LinkedList* listaArcades);

int controller_AgregarArcade(LinkedList* pLinkedList);
int controller_EliminarArcade(LinkedList* pLinkedList);
int controller_modificarArcade(LinkedList* pLinkedList);

int controller_loadFromText(char* path , LinkedList* pLinkedList);
int controller_shotdown(LinkedList* pLinkedList,int estadoBin,int estadoCsv);
int controller_AgregarArcade(LinkedList* pLinkedList);

int controller_ListarArcade(LinkedList* pLinkedList);
int controller_ListUnArcade(LinkedList* pLinkedList,int posicion);
int controller_sortArcades(LinkedList* pLinkedList);

int controller_ListarJuegos(LinkedList* pLinkedList);

int controller_saveAsText(char* path , LinkedList* pLinkedList);
int controller_saveJuegosText(char* path , LinkedList* pLinkedList);

int controller_MultiJugador(LinkedList* listaArcades);
int controller_ActualizarMapearCantFichas(LinkedList* listaArcades);

#endif /* CONTROLLER_H_ */
