/*
 * Pantalla.h
 *
 *  Created on: 30 sep. 2021
 *      Author: usuario
 */
#ifndef PANTALLA_H_
#define PANTALLA_H_

typedef struct{
	int type; //0 LCD 1 LED
	float price;
	int id;
	char name[128];
	char address[128];
	int flagEmpty; //0 ocupada 1 vacia
}Display;

int iniciarEarray(Display *plistDisplay,int len);
int altaDisplay(Display *pDisplay,int len);
int buscarLugarLibreArrayS(Display *pDisplay, int len);
int disp_loadDisplay(Display *pDisplay, int len);
int buscarUnIdDisplay(Display *pDisplay,int len,int id);
int largoArrayD(Display *plistDisplay,int len);
int ordenaDisplayPorDireccioYPrecio(Display *pDisplay, int len);
int modificarUnDisplay(Display *pDisplay, int len);
int bajaLogicaUnDisplay(Display *pDisplay, int len, int idabajar);
int buscarUnId(Display *pDisplay, int len, int idbuscado);
int imprimirDisplay(Display *pDisplay, int len);
int imprimirDisplayCargado(Display *pDisplay, int len);

void harcodearunaltaD(Display *pDisplay, int id, int type, int flagEmty,float price, char name[], char adrees[], int posicion);

#endif /* PANTALLA_H_ */
