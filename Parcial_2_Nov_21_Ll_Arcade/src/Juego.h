/*
 * Juego.h
 *
 *  Created on: 20 nov. 2021
 *      Author: usuario
 */

#ifndef JUEGO_H_
#define JUEGO_H_

int juego_hacerListaDeJuegos(LinkedList* listaArcades);
int juego_estaUnJuegoEnLista(LinkedList* pLinkedListFiltrada, char* nombreJuego,int size);

int filtrarCantidadJugadoresMasUno(void* auxArcade);

//void actualizarCantidadFichas(void* pArcade);
void actualizarCantidadFichas(void* auxArcade,int* factor);

int cantidadFichas(void* auxArcade);


#endif /* JUEGO_H_ */
