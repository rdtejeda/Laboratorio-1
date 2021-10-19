/*
 ============================================================================
 Name        : Parcial_1_14Octubre_2021.c
 Author      : Tejeda Roberto
 Version     : 1.1
 Copyright   : Your copyright notice
 Description : Estamos en el año 1990!
 ============================================================================
 */

#ifndef SALON_H_
#define SALON_H_

typedef struct{
	char nombreSalon[24];
	char direccionSalon[48];
	int tipoSalon;
	int idSalon;
	int isEmptySalon;
}eSalon;

int iniciarEarrayS(eSalon *pSalones,int len);
int largoArrayS(eSalon *pSalones,int len);
int imprimirSalonCargado(eSalon *pSalones, int len);
int ordenaSalonPorDireccion(eSalon *pSalones, int len);
int buscarPosicionDeSalonporSuId(eSalon *pSalones,int len,int id);
int imprimirUnSalonCargado(eSalon *pSalones, int len, int idmostrar);
int buscarLugarLibreArrayS(eSalon *pSalones, int len);
int altaSalon(eSalon *pSalones,int len);
int pedirDatosSalon(eSalon *pSalones, int len);
int bajaLogicaDeUnSalon(eSalon *pSalones,int len,int idabajar);
int eliminarSalonDeLista(eSalon *pSalones,int len);

#endif /* SALON_H_ */
