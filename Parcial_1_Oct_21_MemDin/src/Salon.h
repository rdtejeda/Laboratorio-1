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
}eSalon;

//MEM DIN ROMPE TODO PEPE!!!

eSalon* nuevoSalonM_D(void);
int altaSalon(eSalon* pSalones[],int len);
int iniciarEarrayS(eSalon* pSalones[],int len);
int buscarLugarLibreArrayS(eSalon* pSalones[],int len);
int buscarPosicionDeSalonporSuId(eSalon* pSalones[],int len,int id);
int ordenaSalonPorDireccion(eSalon* pSalones[], int len);
int imprimirUnSalonCargado(eSalon* pSalones[], int len, int idmostrar);
int pedirDatosSalon(eSalon* pSalones);
int bajaLogicaDeUnSalon(eSalon* pSalones[],int len,int idabajar);
int largoArrayS(eSalon* pSalones[],int len);
int imprimirSalonCargado(eSalon* pSalones[], int len);

void harcodearunSalon(eSalon* pSalones[],char nombreSalon[24],char direccionSalon[48],int tipoSalon,int len);

int salon_setTipo(eSalon* pSalon,int* tipoS);
int salon_setName(eSalon* pSalon,char* nombreS);
int salon_setDireeccion(eSalon* pSalon,char* direccionS);
int organizar_arrayS(eSalon* pSalones[],int len,int posicion);

int grabarSalonCargado(eSalon* pSalones[], int len);

#endif /* SALON_H_ */
