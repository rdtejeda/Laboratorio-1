/*
 * Info.h
 *
 *  Created on: 14 oct. 2021
 *      Author: usuario
 */

#ifndef INFO_H_
#define INFO_H_
typedef struct
{
char cuit[12];
int facturacion;
int idContrtacion;
}Cliente;

int listClientesYContrator(Contrataciones *pContra, Display *pDisplay, Cliente *pClientes, int len);
int buscarPorCuityOperar2(Contrataciones *pContra, Display *pDisplay, int len, char cuitBusacado[], int idpantalla);
//int listClientesYContrator(Contrataciones *pContra, Display *pDisplay, Cliente *pClientes, int len);

#endif /* INFO_H_ */
