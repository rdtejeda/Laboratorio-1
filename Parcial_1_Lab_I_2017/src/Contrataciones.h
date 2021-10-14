/*
 * Contrataciones.h
 *
 *  Created on: 12 oct. 2021
 *      Author: usuario
 */

#ifndef CONTRATACIONES_H_
#define CONTRATACIONES_H_

typedef struct{
	char cuit[12];
	int cantidadDias;
	int idContratacion;
	char nombreArchivo[128];
	int id;
	int flagEmptyC;
}Contrataciones;

int iniciarEarrayC(Contrataciones *plistContrato,int len);
int buscarYModifPorCUIL(Contrataciones *pContra, int len, char cuitBusacado[]);
int buscarUnIdPantallaContrato(Contrataciones *pContrato,int len,int id);
int bajaLogicaUnContrato(Contrataciones *pContrato, int len, int idabajar);
int buscarPorCuityBajarPantalla(Contrataciones *pContra, Display *pDisplay, int len, char cuitBusacado[]);
int buscarLugarLibreContrato(Contrataciones *pContrato, int len);
int largoArrayC(Contrataciones *plistContra,int len);
int imprimirDisplayCargadoC(Contrataciones pContra[], int len);

int disp_loadContrato(Contrataciones *pContrato, Display * pDispla, int len);
int altaContrato(Contrataciones *pContrato,Display *pDispay, int len);
int buscarPorCuityOperar(Contrataciones *pContra, Display *pDisplay, int len, char cuitBusacado[]);

void harcodearunaltaC(Contrataciones *pContrato, int id,char ciut[], int flagEmtyc,int cantdias, int idContratacion, char nameArch[], int posicion);

#endif /* CONTRATACIONES_H_ */
