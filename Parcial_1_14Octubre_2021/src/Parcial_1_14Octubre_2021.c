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
#include "IdArcade.h"

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
	/*
	int idBaja;
	int confirmarBaja;

	printf("\ncargdoa dice%d\n",cargadoA);
	*/

	iniciarEarrayS(salones, CAN_SALON);

	harcodearunSalon(salones,"Alavarez","Laprida 430",SHOPPING,7,6);
	harcodearunSalon(salones,"Tejeda","Triunvirato 1239",SHOPPING,2,1);
	harcodearunSalon(salones,"Arrúa","Urquiza 234",SHOPPING,3,2);
	harcodearunSalon(salones,"Perez","La plata 2345",LOCAL,4,3);
	harcodearunSalon(salones,"Lopez","Guemes 1234",LOCAL,5,4);
	harcodearunSalon(salones,"Kirchner","Sin Nombre SN",LOCAL,6,5);

	iniciarEarrayA(arcades, CAN_ARCADE);

	harcodearunArcade(arcades, "Chino","El juego del calamar",MONO,10,100,2,2,1);
	harcodearunArcade(arcades, "Peruano","El abominable",MONO,1,200,3,3,2);
	harcodearunArcade(arcades, "Cubano","La invensible",MONO,2,300,4,4,3);
	harcodearunArcade(arcades, "Ruso","Formula 1",STEREO,3,400,5,5,4);
	harcodearunArcade(arcades, "Hungaro","Raly Mundial",STEREO,4,500,6,6,5);
	harcodearunArcade(arcades, "Criollo","Age of imperior",STEREO,5,1000,7,7,6);
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
					imprimirSalonCargado(salones, CAN_SALON);
					/*
					 * 1) ALTA DE SALÓN Se deberá dar de alta un salón con los siguientes datos: Nombre, dirección y tipo.
						Se generará un ID único para gestionar los SALONES.Este salón se imprimirá por pantalla si el alta es correcta
					 */

					break;
				case 2:
					/*
					 * 2) ELIMINAR SALÓN Se imprime la lista de salas listando ID, nombre y dirección.
						Se ingresa un ID y la misma generará la baja del salón, junto con todos los arcades que lo componen.
					 */
					if(cargadoS>0)
					{
						eliminarSalonDeLista(salones, CAN_SALON);
					}else
						puts("NO HYA DATOS CARGADOS");
					break;
				case 3:
					// 3) IMPRIMIR SALONES Se imprime la lista completa de salas con todos sus datos. Nombre, dirección y tipo.
					if(cargadoS>0)
					{
						imprimirSalonCargado(salones, CAN_SALON);
					}else
						puts("NO HYA DATOS CARGADOS");

					break;
				case 4:
					altaArcade(arcades, salones, CAN_ARCADE, CAN_SALON);
					imprimirArcadeCargado(arcades, CAN_ARCADE);
					/*
					 * 4) INCORPORAR ARCADE Se da de alta un arcade con la nacionalidad, tipo de sonido, cantidad de jugadores, capacidad máxima de
						fichas, ID del salón al que pertenece (Validar que exista) y nombre del juego que contiene (hasta 63 caracteres).
						Se generará un ID único para gestionar los ARCADE.
					 */
					break;
				case 5:
					/*
					 * 5) MODIFICAR ARCADE Se imprime la lista de arcades con los ID y datos que lo componen. Se pide que se ingrese un ID y se pueda modificar los campos cantidad de jugadores o juego que contiene.
						Al elegir modificar el juego que contiene este arcade, mostrar en un listado los nombres de los juegos ya
						cargados en el sistema y se permitirá ingresar un texto con el nombre del nuevo juego.
					 */
					/*
					if(cargadoC>0)
						{
							pedirUnCUIT(cuitModificar, 12, "Ingrese CUIT a modificar", "Ingrese CUIT valido", INTENTOS);
							buscarYModifPorCUIL(contrataciones, TAMANO_ARRAY, cuitModificar);
						}
						*/
					break;
				case 6:
					/*
					 * 6) ELIMINAR ARCADE Se imprime la lista de arcades con sus ID y datos que lo componen, junto con la información del salón y el juego que contiene.
						Se ingresa un ID y previo a dar de baja se deberá solicitar confirmación, imprimiendo el arcade a dar de baja y
						confirmando si está seguro dar de baja esté mismo.
					 */

					if(cargadoA>0)
						{
							eliminarArcadeDeLista(arcades,CAN_ARCADE);
						}else
							puts("NO HYA DATOS CARGADOS");
					break;
				case 7:
					//7) IMPRIMIR ARCADES Se imprime la lista de arcades con ID, y sus datos.
					 if(cargadoA>0)
						{
							imprimirArcadeCargado(arcades, CAN_ARCADE);
						}else
							puts("NO HYA DATOS CARGADOS");
					break;
				case 8:
					/*
					 * 8) IMPRIMIR JUEGOS Se imprime la lista de juegos que contienen todos los arcades sin repetir.
					 */
					/*
					if(cargadoC>0)
					{
						imprimirDisplayCargadoC(contrataciones, TAMANO_ARRAY);
					}else
						puts("NO HYA DATOS CARGADOS");
						*/
					break;
				case 9:
					/*
					9) INFORMES - Aparecerá un submenú con las siguientes opciones:
					*/
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
								puts("PUSO A");
								break;
							case 66:
								puts("PUSO B");
								break;
							case 67:
								puts("PUSO C");
								break;
							case 68:
								puts("PUSO D");
								break;
							case 69:
								puts("PUSO E");
								break;
							case 70:
								puts("PUSO F");
								break;
							case 71:
								puts("PUSO H");
								break;
							default:
								break;
							}
						}else
						{
							puts("ERROR - INGRESE UNA MAYUSCULA");
						}

						}while(menuInformes!=72);
					}
					break;

				default:
					break;
			}
		}while(menuPrincipal!=10);
	puts("!!!Usted ha salido del menu de SLONES Y ARCADES!!!");
	puts("!!!Que hay de buevo viejo!!!");
	return EXIT_SUCCESS;
}
