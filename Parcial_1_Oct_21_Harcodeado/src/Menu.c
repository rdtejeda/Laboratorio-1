/*
 ============================================================================
 Name        : Parcial_1_14Octubre_2021.c
 Author      : Tejeda Roberto
 Version     : 1.1
 Copyright   : Your copyright notice
 Description : Estamos en el año 1990!
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

#include "Pedir.h"
#include "Salon.h"
#include "Arcade.h"
#include "Juego.h"
#include "Informes.h"

/**
* \brief Imprime el menu de INICIAL de opciones
* \param
* \return
*/
void imprimirMenuInicial()
{
	puts("MENU PRINCIPAL");
	puts("1- ALTA DE SALÓN");
	puts("2- ELIMINAR SALÓN");
	puts("3- IMPRIMIR SALONES");
	puts("4- INCORPORAR ARCADE");
	puts("5- MODIFICAR ARCADE");
	puts("6- ELIMINAR ARCADE");
	puts("7- IMPRIMIR ARCADES");
	puts("8- IMPRIMIR JUEGOS");
	puts("9- INFORMES");
	puts("10- SALIR");
}
/**
* \brief Imprime el menu de informes
* \param
* \return
*/
void imprimirMenuInformes()
{
	puts("A) Listar los salones con más de 4 arcades. Indicando ID de salón, nombre, dirección y tipo de salón.");
	puts("B) Listar los arcades para más de 2 jugadores, indicando ID de arcade, cantidad de jugadores, nombre del juego y nombre del salón al que pertenece.");
	puts("C) Listar toda la información de un salón en específico ingresando su ID. Imprimir nombre, tipo y dirección y cantidad de arcades que posee.");
	puts("D) Listar todos los arcades de un salón determinado ingresando su ID. Informar nombre y tipo de salón, listar todos los arcades con sus datos junto con el nombre del juego que lo compone.");
	puts("E) Imprimir el salón con más cantidad de arcades, indicando todos los datos del salón y la cantidad de arcades que posee.");
	puts("F) Ingresar el ID de un salón, y el valor en pesos de una ficha, e imprimir el monto máximo en pesos que puede recaudar el salón (sumar cantidad de fichas máximo de cada arcade del salón y multiplicarla por el valor en pesos ingresado)");
	puts("G) Ingresar el nombre de un juego e imprimir cuantos arcades lo contienen.");
	puts("H) SALIR DE INFORMES");
}
/**
* \brief Imprime el menu de modificacion
* \param
* \return
*/
void imprimirMenuModificar()
{
	puts("1- Cantidad de jugadores");
	puts("2- Juego que contiene");
	puts("3- SALIR");
}
