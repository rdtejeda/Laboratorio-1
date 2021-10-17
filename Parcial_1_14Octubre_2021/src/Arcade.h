/*
 ============================================================================
 Name        : Parcial_1_14Octubre_2021.c
 Author      : Tejeda Roberto
 Version     : 1.1
 Copyright   : Your copyright notice
 Description : Estamos en el año 1990!
 ============================================================================
 */

#ifndef ARCADE_H_
#define ARCADE_H_

typedef struct{
	char nacionalidadArcade[24];
	char nombreJuego[64];
	int tipoSonidoArcade;
	int cantidadJugadorArcade;
	int capMaxFichaArcade;
	int idArcade;
	int idSalon;
	int isEmptyArcade;
}eArcade;

int iniciarEarrayA(eArcade *pArcades,int len);
int largoArrayA(eArcade *pArcades,int len);
int ordenaArcadePorNombreJuego(eArcade *pArcades, int len);
int imprimirArcadeCargado(eArcade *pArcades, int len);
int buscarPosicionDeArcadeporSuId(eArcade *pArcades,int len,int id);
int bajaLogicaDeUnArcade(eArcade *pArcades,int len,int idabajar);
int eliminarArcadeDeLista(eArcade *pArcades,int lenArcade);
int buscarLugarLibreArrayA(eArcade *pArcades, int len);
int altaArcade(eArcade *pArcades,eSalon *pSalones,int lenA,int lenS);
int pedirDatosArcade(eArcade *pArcades,eSalon *pSalones,int lenA,int lenS);


void harcodearunArcade(eArcade *pArcades,char nacionalidadArcade[24],char nombreJuego[64],int tipoSonidoArcade,int cantidadJugadorArcade,int capMaxFichaArcade,int idArcade,int idSalon,int posicion);

#endif /* ARCADE_H_ */
