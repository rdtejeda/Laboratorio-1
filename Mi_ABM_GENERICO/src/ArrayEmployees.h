/*
 * ArrayEmployees.h
 *
 *  Created on: 7 oct. 2021
 *      Author: usuario
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

typedef struct{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;
}eGenerico;

int iniciarEarray(eGenerico *plistGenerica,int len);
int imprimirEarray(eGenerico *plistGenerica,int len);
int agregarEarray(eGenerico *plistGenerica,int len,int id,char name[],char lastName[],float salary,int sector);
int buscarUnIdArray(eGenerico *plistGenerica,int len,int id);
int eliminarLogIdArray(eGenerico *plistGenerica,int len,int id);
int ordenarArray(eGenerico *plistGenerica,int len,int order);

int modificarUnDatodelArray(eGenerico *plistGenerica, int len);
int operateSalaryEmployees(eGenerico *plistGenerica,int len,float *totalSalary, float *promSalary, int *overProm);
int largoArray(eGenerico *plistGenerica,int len);
int buscarLugarArray(eGenerico *plistGenerica,int len);

#endif /* ARRAYEMPLOYEES_H_ */
