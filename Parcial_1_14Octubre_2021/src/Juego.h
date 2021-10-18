/*
 ============================================================================
 Name        : Parcial_1_14Octubre_2021.c
 Author      : Tejeda Roberto
 Version     : 1.1
 Copyright   : Your copyright notice
 Description : Estamos en el año 1990!
 ============================================================================
 */

#ifndef JUEGO_H_
#define JUEGO_H_

typedef struct{
	char nombreJuego[64];
	int isEmptyJuego;
}eJuego;

int inicializarListaJuegos(eJuego *pJuegos,int lenJ);
int estaUnJuegoEnLista(eJuego *pJuegos, int lenJ, char nombreJuego[]);
int hacerListaDeJuegos(eJuego *pJuegos,int len,eArcade *pArcades);
int imprimirListaJuegos(eArcade *pArcades,int len);

#endif /* JUEGO_H_ */
