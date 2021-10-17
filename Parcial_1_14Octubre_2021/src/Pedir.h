/*
 ============================================================================
 Name        : Parcial_1_14Octubre_2021.c
 Author      : Tejeda Roberto
 Version     : 1.1
 Copyright   : Your copyright notice
 Description : Estamos en el año 1990!
 ============================================================================
 */

#ifndef PEDIR_H_
#define PEDIR_H_

int esAlfaumerica(char *cadena);
int pedirInt(int *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo, int intentos);
int esNumericaInt(char *cadena);
int myGets(char *pResultado, int len);
int esNumericaFloat(char *cadena);
int esAlfabetica(char *cadena);
int pedirFloat(float *pResultado, char *mensaje, char *mensajeError, float minimo, float maximo, int intentos);
int pedirText(char *pResultado, int len, char *mensaje, char *mensajeError, int intentos);
int pedirCharAUsuario(char *pChar, int reintentos, char *txt, char *txtError);

#endif /* PEDIR_H_ */
