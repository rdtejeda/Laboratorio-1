/*
 ============================================================================
 Name        : Parcial_1_14Octubre_2021.c
 Author      : Tejeda Roberto
 Version     : 1.1
 Copyright   : Your copyright notice
 Description : Estamos en el año 1990!
 ============================================================================
 */

#ifndef INFORMES_H_
#define INFORMES_H_

int informeA(eArcade *pArcades,int lenA,eSalon *pSalones,int lenS);
int informeB(eArcade *pArcades,int lenA,eSalon *pSalones,int lenS);
int informeC(eSalon *pSalones,int lenS,eArcade *pArcades,int lenA);
int informeD(eArcade *pArcades,int lenA,eSalon *pSalones,int lenS);
int informeE(eArcade *pArcades,int lenA,eSalon *pSalones,int lenS);
int informeF(eArcade *pArcades,int lenA,eSalon *pSalones,int lenS);
int informeG(eArcade *pArcades,int lenA);

int estaUnJuegoEnListaDeArcade(eArcade *pArcades, int lenA, char nombreJuego[]);
int cantidadArcadesDeUnSalon(eArcade *pArcades, int lenA, int iDSalon);



#endif /* INFORMES_H_ */
