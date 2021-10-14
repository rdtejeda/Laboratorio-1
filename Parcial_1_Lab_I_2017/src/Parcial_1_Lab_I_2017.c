/*
 ============================================================================
 Name        : Parcial_1_Lab_I_2017.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

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

int main(void)
{
	Display displays[TAMANO_ARRAY];
	Contrataciones contrataciones[TAMANO_ARRAY];
	Cliente clientes[TAMANO_ARRAY];

	int menuPrincipal;
	int menuInformes;
	int cargadoD;
	int cargadoC;
	int idBaja;
	int confirmarBaja;
	iniciarEarray(displays, TAMANO_ARRAY);
	iniciarEarrayC(contrataciones, TAMANO_ARRAY);
	char cuitModificar[12];

	do
	{
		imprimirMenuInicial();
		pedirInt(&menuPrincipal, "Ingrese opción deseada", "Entre 1 y 11", MINIMO, MAXIMO, INTENTOS);
		cargadoD=largoArrayD(displays, TAMANO_ARRAY);
		cargadoC=largoArrayC(contrataciones, TAMANO_ARRAY);
		switch (menuPrincipal)
		{
			case 1:
				harcodearunaltaD(displays, 1, 0, 0, 1, "Calle Principal", "Corriente 23", 0);
				harcodearunaltaD(displays, 2, 1, 0, 10, "Calle Principal", "Corriente 23", 1);
				harcodearunaltaD(displays, 3, 0, 0, 100, "Calle Principal", "Corriente 23", 2);
				harcodearunaltaD(displays, 4, 1, 0, 2, "Calle Principal", "Corriente 23", 3);
				harcodearunaltaD(displays, 5, 0, 0, 4, "Calle Principal", "Corriente 23", 4);
				//altaDisplay(displays, TAMANO_ARRAY);
				break;
			case 2:
				if(cargadoD>0)
				{
					modificarUnDisplay(displays, TAMANO_ARRAY);
				}else
					puts("NO HYA DATOS CARGADOS");
				break;
			case 3:
				if(cargadoD>0)
				{
					imprimirDisplayCargado(displays, TAMANO_ARRAY);
					pedirInt(&idBaja, "Ingrese BAja", "Id no valido", 1, TAMANO_ARRAY, INTENTOS);
					if(buscarUnIdPantallaContrato(contrataciones, TAMANO_ARRAY, idBaja)>=0)
					{
						printf("\nLa pantalla tiene un Contrato asociado ¿desa darla de baja?\n");
						pedirInt(&confirmarBaja, "Ingrese 1-Para Dar de Baja Ó 2-Para cancelar la Baja", "Ingrese 1 o 2", MINIMO, 2, INTENTOS);
						if(confirmarBaja==1)
						{
							bajaLogicaUnDisplay(displays, TAMANO_ARRAY, idBaja);
						}else
							puts("SE ha cancelado la baja");
					}else
					bajaLogicaUnDisplay(displays, TAMANO_ARRAY, idBaja);
				}else
					puts("NO HYA DATOS CARGADOS");
				break;
			case 4:
				harcodearunaltaC(contrataciones, 1, "20182231258", 0, 1, 1, "Ptte", 0);
				harcodearunaltaC(contrataciones, 2, "20182231259", 0, 1, 2, "Prte", 1);
				harcodearunaltaC(contrataciones, 3, "20182231258", 0, 1, 3, "Pepe", 2);
				harcodearunaltaC(contrataciones, 3, "20182231259", 0, 1, 4, "Luis", 3);
				harcodearunaltaC(contrataciones, 4, "20182231259", 0, 1, 5, "Luis", 4);
				//altaContrato(contrataciones, displays, TAMANO_ARRAY);
				break;
			case 5:
				if(cargadoC>0)
					{
						pedirUnCUIT(cuitModificar, 12, "Ingrese CUIT a modificar", "Ingrese CUIT valido", INTENTOS);
						buscarYModifPorCUIL(contrataciones, TAMANO_ARRAY, cuitModificar);
					}
				break;
			case 6:
				if(cargadoC>0)
					{
						 pedirUnCUIT(cuitModificar, 12, "Ingrese CUIT a modificar", "Ingrese CUIT valido", INTENTOS);
						 buscarPorCuityBajarPantalla(contrataciones, displays, TAMANO_ARRAY, cuitModificar);
					}
				break;
			case 7:
				if(cargadoC>0)
					{
						 pedirUnCUIT(cuitModificar, 12, "Ingrese CUIT a modificar", "Ingrese CUIT valido", INTENTOS);
						 buscarPorCuityOperar(contrataciones, displays, TAMANO_ARRAY, cuitModificar);
					}
				break;
			case 8:
				if(cargadoC>0)
				{
					imprimirDisplayCargadoC(contrataciones, TAMANO_ARRAY);
				}else
					puts("NO HYA DATOS CARGADOS");
				break;
			case 9:
				if(cargadoD>0)
				{
				ordenaDisplayPorDireccioYPrecio(displays, TAMANO_ARRAY);
				imprimirDisplayCargado(displays, TAMANO_ARRAY);
				}else
					puts("NO HYA DATOS CARGADOS");
				break;
			case 10:
				imprimirMenuInformes();
				pedirInt(&menuInformes, "Ingrese Opcion deseada 1 a 3", "Ingrese Opcion valida", MINIMO, INTENTOS, INTENTOS);
				switch (menuInformes) {
					case 1:
						listClientesYContrator(contrataciones, displays, clientes, TAMANO_ARRAY);
						//listClientesYContrator(contrataciones, displays, TAMANO_ARRAY);
						break;
					case 2:

						break;
					case 3:
						break;
					default:
						break;
				}
				break;
			default:
				break;
		}
	}while(menuPrincipal!=11);
	puts("!!!Usted ha salido del menu de Pantallas y contratos!!!");
	return EXIT_SUCCESS;
}
/*
 * typedef struct{
	int type; //0 LCD 1 LED
	float price;
	int id;
	char name[128];
	char address[128];
	int flagEmpty; //0 ocupada 1 vacia
}Display;
typedef struct{
	int cuit; //0 LCD 1 LED
	int cantidadDias;
	int idContratacion;
	char nombreArchivo[128];
	int id;
	int flagEmptyC; //0 ocupada 1 vacia
}Contrataciones;
 */
