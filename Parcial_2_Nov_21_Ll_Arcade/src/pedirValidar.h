/*
 * pedirValidar.h
 *
 *  Created on: 20 nov. 2021
 *      Author: usuario
 */

#ifndef PEDIRVALIDAR_H_
#define PEDIRVALIDAR_H_

int esNombre(char *cadena);

int pedirInt(int *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo, int intentos);
int pedirFloat(float *pResultado, char *mensaje, char *mensajeError, float minimo, float maximo, int intentos);

int esNumericaInt(char *cadena);
int esAlfaumerica(char *cadena);
int esNumericaFloat(char *cadena);

int myGets(char *pResultado, int len);

int pedirNombre(char *pResultado, int len, char *mensaje, char *mensajeError, int intentos);
int pedirTextoAlfanumerico(char *pResultado, int len, char *mensaje, char *mensajeError, int intentos);

int esAlfaumerica(char *cadena);
//int esSoloMayuscula(char *cadena);

#endif /* PEDIRVALIDAR_H_ */
