/*
 *  Pedir.c
 *  Created on: 7 oct. 2021
 *  Author: Tejeda Roberto
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include <ctype.h>

#include "Pantalla.h"
#include "Pedir.h"
#include "Contrataciones.h"
#include "Menu.h"
#include "Info.h"

#define TAMANO_ARRAY 10
#define OCUPADO 0
#define LIBRE -1
#define MINIMO 1
#define MAXIMO 11
#define INTENTOS 3
//==========================================================
/**
* \brief Imprime el menu de INICIAL de opciones
* \param
* \return
*/
void imprimirMenuInicial()
{
	puts("MENU PRINCIPAL");
	puts("1- Alta de pantalla");
	puts("2- Modificar datos de pantalla");
	puts("3- Baja de pantalla");
	puts("4- Contratar una publicidad");
	puts("5- Modificar condiciones de publicación");
	puts("6- Cancelar contratación");
	puts("7-Consulta facturación");
	puts("8- Listar contrataciones");
	puts("9- Listar​ ​ pantallas");
	puts("10- Informar");
	puts("11- SALIR");
}
//===========================================================
/**
* \brief Imprime el menu de informes
* \param
* \return
*/
void imprimirMenuInformes()
{
	puts("1- Lista​ ​ de​ ​ cada​ ​ cliente​ ​ con​ ​ cantidad​ ​ de​ ​ contrataciones​ ​ e ​ ​ importe​ ​ a ​ ​ pagar​ ​ por​ ​ cada​ ​ una");
	puts("2- Cliente​ ​ con​ ​ importe​ ​ más​ ​ alto​ ​ a ​ ​ facturar​ ​ (si​ ​ hay​ ​ más​ ​ de​ ​ uno​ ​ indicar​ ​ el​ ​ primero");
	puts("3- SALIR DE INFORMES");
}
//===========================================================
/**
* \brief Imprime el menu de modificacion
* \param
* \return
*/
void imprimirMenuModificar()
{
	puts("1- TIPO DE DIPLAY");
	puts("2- PRECIO DE LA PUBLICACION");
	puts("3- NOMBRE DE LA PUBLICACION");
	puts("4- DIRECCION DE LA PANTALLA");
	puts("5- SALIR");
}
//============================================================
