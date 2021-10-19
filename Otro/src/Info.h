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
int flagIsEmpty;
}Cliente;

int inicializarListaCliente(Cliente *pCliente,int len);
int estaUnCuitListaCliente(Cliente *pCliente, int len, char cuit[]);
int hacerListaCliente(Cliente *pCliente, int len, Contrataciones *pContrato);
float precioPorDiaDeDisplay(Display *pDisplay, int len, int idDisplay);
void informe_10_2_ClienteMayorFacturacion(Contrataciones *pContato, Display *pDisplay, int len);
void informe_10_1_ListaClienteEImpote(Contrataciones *pContato, Display *pDisplay, int len);



float calcularImportePorCliente(Display *pDisplay, Contrataciones *pContrato, int len, char cuit[]);

#endif /* INFO_H_ */
