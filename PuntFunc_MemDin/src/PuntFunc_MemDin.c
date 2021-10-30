/*
 ============================================================================
 Name        : PuntFunc_MemDin
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define AGRANDO 10

int initArray(int *pArray, int len, int valor);
int imprimirArray(int *pArray, int len);
int resizeArray(int** pArray,int* sizeActual,int sizeNuevo);

int main(void)
{

	int* pArrayEdades=NULL; //Verificar inicio OK
	//int* pArrayTemp=NULL;
	int sizeArrayEdades=10;//va en yunta puede ser tipo de dato

	pArrayEdades=(int*)malloc(sizeof(int)*sizeArrayEdades);

	if (pArrayEdades!=NULL)
	{
		if(!initArray(pArrayEdades, sizeArrayEdades,0)) //==(initArray(pArrayEdades, sizeArrayEdades,0)==0)
		{
			printf("INIT OK\n");
			imprimirArray(pArrayEdades, sizeArrayEdades);
		}
		/*
		//vamos a agrandra el array y almemoria que ocupa
		pArrayTemp=realloc(pArrayEdades,sizeof(int)*(sizeArrayEdades+50));//de 10 a 60 realloc me devuelve
		if(pArrayTemp!=NULL)
		{
			sizeArrayEdades=sizeArrayEdades+50;
			pArrayEdades=pArrayTemp;
		}
		*/
		//vamoa a agrnadra ahora desded la funcion
		resizeArray(&pArrayEdades, &sizeArrayEdades,25 );

		if(!initArray(pArrayEdades, sizeArrayEdades,10)) //==(initArray(pArrayEdades, sizeArrayEdades,0)==0)
		{
			printf("INIT OK\n");
			imprimirArray(pArrayEdades, sizeArrayEdades);
		}

	}
	//Realloc necesita si o si un puntero temporal hasta verificar


return EXIT_SUCCESS;
}

int resizeArray(int** pArray,int* sizeActual,int sizeNuevo) //metemos el reizse ebnn una funcion
{
	int retorno=-1;
	int* pArrayTemp=NULL;
		if(pArray!=NULL && sizeActual!=NULL && sizeNuevo>0)
		{
			pArrayTemp=realloc(*pArray,sizeof(int)*sizeNuevo);//de 10 a 60 realloc me devuelve
			if(pArrayTemp!=NULL)
			{
				*sizeActual=sizeNuevo;
				*pArray=pArrayTemp;
				pArrayTemp=NULL;
			}
		retorno=0;
		}
		return retorno;
}

int imprimirArray(int *pArray, int len)
{
	int retorno=-1;
	if(pArray!=NULL && len>0)
	{
		retorno=0;
		for (int i = 0; i < len; ++i)
		{
			printf("%d\n",*(pArray+i));// == pArray[i];
		}
	}
	return retorno;
}

int initArray(int *pArray, int len, int valor)
{
	int retorno=-1;
	if(pArray!=NULL && len>0)
	{
		retorno=0;
		for (int i = 0; i < len; ++i)
		{
			*(pArray+i)=valor;//pArray[i]=valor;
		}
	}
	return retorno;
}

/*

	a=(int*)malloc(sizeof(int));
	if(a!=NULL)
	*a=22;

	free(a);///libero


	int *b;
	int *pAux;
	b=(int*)malloc(sizeof(int)*20);

	pAux=(int*)realloc(b,sizeof(int)*200);
	//Ojo que los carga en pAux
	//si consigue lo saca de b
	//y los pone en puntero que luego asigno
	//si no trabajo con aux y me devuelve un NULL pierdo todo
	//ademas genera un bloque somby de memoria
	//esta pero no puedo acceder
	if (pAux!=NULL)
	{
		b=pAux;
	}

	if(pAux!=NULL)
	{
		for (int l=0;l< 200; ++l)
		{
			*(b+l)=22;
		}
	}

	*/

/*
int main(void)
{

	int *a; //asigon
	a=(int*)malloc(sizeof(int));
	if(a!=NULL)
	*a=22;

	free(a);///libero


	int *b;
	int *pAux;
	b=(int*)malloc(sizeof(int)*20);

	pAux=(int*)realloc(b,sizeof(int)*200);
	//Ojo que los carga en pAux
	//si consigue lo saca de b
	//y los pone en puntero que luego asigno
	//si no trabajo con aux y me devuelve un NULL pierdo todo
	//ademas genera un bloque somby de memoria
	//esta pero no puedo acceder
	if (pAux!=NULL)
	{
		b=pAux;
	}

	if(pAux!=NULL)
	{
		for (int l=0;l< 200; ++l)
		{
			*(b+l)=22;
		}
	}





	return EXIT_SUCCESS;
}
*/

/*
#define UNO 1
#define DOS 10

typedef int (*tpfSaludar)(char*,int); //creo el TIPO puntero a funcion *tpfSaludar


int saludarEsp(char *mensaje,int numero)
{
	printf("\nHOLA %s %d",mensaje,numero);
	return 0;
}
int saludarIng(char *mensaje,int numero)
{
	printf("\nHELLO %s %d",mensaje,numero);
	return 0;
}

void saludo(char *mensaje,int numero,tpfSaludar pFuncSaludar)//crea el puntero a funcion con elk tipo de dat lo implementa
//ESTA FUNCION RECIBE UNA FUNCION COMO PÀRAMETRO
{
	pFuncSaludar(mensaje,numero);
}

int main(void)
{
	int uno=UNO;
	int dos=DOS;
	saludo("Pepe",uno,saludarEsp);
	saludo("Marina",dos,saludarIng);

	return EXIT_SUCCESS;
}

*/

/*
#define UNO 1
#define DOS 10


int saludarEsp(char *mensaje,int numero)
{
	printf("\nHOLA %s %d",mensaje,numero);
	return 0;
}
int saludarIng(char *mensaje,int numero)
{
	printf("\nHELLO %s %d",mensaje,numero);
	return 0;
}

void saludo(char *mensaje,int numero,int (*pFuncSaludar)(char*,int))//crea el puntero a funcion t lo implementa
//ESTA FUNCION RECIBE UNA FUNCION COMO PÀRAMETRO
{
	pFuncSaludar(mensaje,numero);
}

int main(void)
{
	int uno=UNO;
	int dos=DOS;
	saludo("Pepe",uno,saludarEsp);
	saludo("Marina",dos,saludarIng);

	return EXIT_SUCCESS;
}
*/

/*
int saludar(char *mensaje,int numero)
{
	printf("%s %d",mensaje,numero);
	return 0;
}

int main(void)
{
	int (*pFuncSaludar)(char*,int); //puntero saludar
	pFuncSaludar=saludar;				//Asigno direrccion de memoria al punero

	if(pFuncSaludar("HOLA",22)==0) //Aca lo uso
	{
		printf("\nSALIO OK");
	}
	return EXIT_SUCCESS;
}
*/

/*
void saludar(void)
{
	puts("!!!Que hay de nuevo viejo!!!");
}

void sumar(int parametroA, int parametroB,int *pResultado)
{
	*pResultado=parametroA+parametroB;
}
void restar(int parametroA, int parametroB,int *pResultado)
{
	*pResultado=parametroA-parametroB;
}
int calcular(int parametroA, int parametroB,void(*pFuncion)(int,int,int*))//A
{
	int auxResultado; //Calcular llama a la funcion que recibio como parametro
	pFuncion(parametroA,parametroB,&auxResultado); //C
	return auxResultado;
}


int main(void)
{
	void(*pFuncionVoidVoid)(void);//firma del punetr //A
		//que recibe y que devuelve dependiendo
		//ES UN TRAJE A MEDIDA mientra devuelve y recibe lo mismo
	pFuncionVoidVoid=saludar;	//pido direccion de memoria de la funcion saludar //B
		//echo a medida de la funcion void void
		//el puntero pFun.. apunta al dirccio de memoria de la funcion
		//esta asignacion no es estatica es dinamica
	pFuncionVoidVoid(); //C

	int auxiliar;

	auxiliar=calcular(10,5,restar);//B
	printf("\nEl resultado de la resta es %d\n",auxiliar);

	auxiliar=calcular(10,5,sumar);
	printf("\nEl resultado de la resta es %d\n",auxiliar);

	//CLASE 16 MINUTO 20
	return EXIT_SUCCESS;
}
*/
