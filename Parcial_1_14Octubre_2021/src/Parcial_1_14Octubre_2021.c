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
#include "Menu.h"
#include "Juego.h"
#include "Informes.h"

#define CAN_SALON 100
#define CAN_ARCADE 1000
#define OCUPADO 0
#define LIBRE -1
#define INTENTOS 5
#define SHOPPING 1
#define LOCAL 2
#define MONO 1
#define STEREO 2
#define MINIMO 1
#define MAXIMO10 10

int main(void)
{
	eSalon salones[CAN_SALON];
	eArcade arcades[CAN_ARCADE];
	int menuPrincipal;
	char menuInformes;
	int cargadoS;
	int cargadoA;
	iniciarEarrayS(salones, CAN_SALON);
	iniciarEarrayA(arcades, CAN_ARCADE);

	do
		{
			imprimirMenuInicial();
			pedirInt(&menuPrincipal, "Ingrese opción deseada", "Entre 1 y 10", MINIMO, MAXIMO10, INTENTOS);
			cargadoS=largoArrayS(salones, CAN_SALON);
			cargadoA=largoArrayA(arcades, CAN_ARCADE);
			switch (menuPrincipal)
			{
				case 1:
					altaSalon(salones, CAN_SALON);
					break;
				case 2:
					if(cargadoS>0)
					{
						bajaDeSalonYsusArcadesDeLista(salones,CAN_SALON,arcades,CAN_ARCADE);
					}else
						puts("NO HYA DATOS CARGADOS");
					break;
				case 3:
					if(cargadoS>0)
					{
						imprimirSalonCargado(salones, CAN_SALON);
					}else
						puts("NO HYA DATOS CARGADOS");
					break;
				case 4:
					if(cargadoS>0)
					{
					altaArcade(arcades, salones, CAN_ARCADE, CAN_SALON);
					imprimirArcadeCargado(arcades, CAN_ARCADE);
					}else
						puts("No hay salones cargados por lo cual no es posible dar de alta un arcade");
					break;
				case 5:
					if(cargadoA>0)
						{
						modificarUnArcade(arcades, CAN_ARCADE);
						}else
							puts("NO HYA DATOS CARGADOS");
					break;
				case 6:
					if(cargadoA>0)
						{
							eliminarArcadeDeLista(arcades,CAN_ARCADE);
						}else
							puts("NO HYA DATOS CARGADOS");
					break;
				case 7:
					if(cargadoA>0)
						{
							imprimirArcadeCargado(arcades, CAN_ARCADE);
						}else
							puts("NO HYA DATOS CARGADOS");
					break;
				case 8:
					if(cargadoA>0)
					{
						imprimirListaJuegos(arcades, CAN_ARCADE);
					}else
						puts("NO HYA DATOS CARGADOS");
					break;
				case 9:
					if(cargadoA>0 && cargadoS>0)
					{
						do
						{
						imprimirMenuInformes();
						pedirCharAUsuario(&menuInformes, INTENTOS, "Ingrese opcion deseada entres A y H", "Ingesa opcion correcta");
						if(menuInformes>=65 && menuInformes<=72)
						{
						switch (menuInformes)
							{
							case 65:
								informeA(arcades,CAN_ARCADE,salones,CAN_SALON);
								break;
							case 66:
								informeB(arcades,CAN_ARCADE,salones,CAN_SALON);
								break;
							case 67:
								informeC(salones, CAN_SALON,arcades,CAN_ARCADE);
								break;
							case 68:
								informeD(arcades,CAN_ARCADE,salones,CAN_SALON);
								break;
							case 69:
								informeE(arcades,CAN_ARCADE,salones,CAN_SALON);
								break;
							case 70:
								informeF(arcades, CAN_ARCADE,salones,CAN_SALON);
								break;
							case 71:
								informeG(arcades, CAN_ARCADE);
								break;
							default:
								break;
							}
						}else
						{
							puts("ERROR - INGRESE UNA MAYUSCULA");
						}

						}while(menuInformes!=72);
					}else
						puts("NO HYA DATOS CARGADOS");
					break;
				default:
					break;
			}
		}while(menuPrincipal!=10);
	puts("!!!Usted ha salido del menu de SALONES Y ARCADES!!!");
	return EXIT_SUCCESS;
}
