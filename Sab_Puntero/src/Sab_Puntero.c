/*
 ============================================================================
 Name        : Sab_Puntero.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

/******************************************************************************

Ejercicio 8.2
Realizar una función que reciba un puntero a char y dos char. La función deberá
reemplazar en la cadena cada ocurrencia del primer carácter recibido, por el segundo.
Retornando la cantidad de reemplazos o -1 en caso de error.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
// https://www.onlinegdb.com/eY9VEBPKo sabado 30!0

int funcionBuscarYReemplazar(int* pEntero,int* tamano, int valor);
int main(void) {

	int* pAuxiliar;
	int tamanoPunteros;

	tamanoPunteros=5;
	pAuxiliar=(int*)malloc(sizeof(int)*tamanoPunteros);


	if(pAuxiliar!=NULL)
	{
		for(int i=0;i<tamanoPunteros ;i++)
		{
			*(pAuxiliar+i)=i+1;
		}
	}

	for(int i=0;i<tamanoPunteros ;i++)
	{
		printf("%d\n",*(pAuxiliar+i));
	}

	funcionBuscarYReemplazar(pAuxiliar,&tamanoPunteros, 2);

	for(int i=0;i<tamanoPunteros ;i++)
	{
		printf("%d\n",*(pAuxiliar+i));
	}

	return EXIT_SUCCESS;
}

int funcionBuscarYReemplazar(int* pEntero,int* tamano, int valor)
{
	int retorno=-1;
	if(pEntero!=NULL)
	{
		for(int i=0;i<*tamano ;i++)
		{
			if(*(pEntero+i)==valor)
			{
				for(int j=i;j<*tamano-1;j++)
				{
					*(pEntero+j)=*(pEntero+j+1);
				}
				retorno=0;
				pEntero=(int*)realloc(pEntero,sizeof(int)*(*tamano-1));
				*tamano=*tamano-1;
				break;
			}

		}
	}

	return retorno;
}

/*
int ReemplazarCaracteres (char* cadena, int tamanioCadena, char caracterAReemplazar, char caracterQueVaAReemplazar);

int main()
{
    char cadenaDeChars[51] = "sabado";

   // char* p;
  //  p = cadenaDeChars;
  //  printf("%d %d", sizeof(p), sizeof(cadenaDeChars));

    int reemplazos;
    reemplazos = ReemplazarCaracteres (cadenaDeChars, sizeof(cadenaDeChars), 'a', 'i');
    printf("Cant. reemplazos: %d\nPalabra reemplazada: %s", reemplazos, cadenaDeChars);

    return 0;
}
*/
/*
int ReemplazarCaracteres (char* cadena, int tamanioCadena, char caracterAReemplazar, char caracterQueVaAReemplazar) {
    int cantidadReemplazos;
    int longitudDeCadena;

    cantidadReemplazos = -1;

    if (cadena != NULL) {
        cantidadReemplazos = 0;
        longitudDeCadena = strnlen(cadena, tamanioCadena);
        for (int i = 0; i < longitudDeCadena; i++) {
            if (*(cadena+i) == caracterAReemplazar)
            {
                *(cadena+i) = caracterQueVaAReemplazar;
                cantidadReemplazos++;
            }
        }
    }
    return cantidadReemplazos;
}
*/
