/*
 ============================================================================
 Name        : Noviembre_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
//MODO ESCRITURA Y LECTURA TEXTO
int main(void)
{
		//fopen
		//fprintf
		//fscanf
		//fclose
		//feof()

	FILE* fp;

	int i=99;
	int j[10];
	int paso=0;

	if((fp=fopen("MiPrimerArchivoTxt.txt","w"))!=NULL)
	{
		for (int a = 0; a<10; ++a)
		{
			fprintf(fp,"%d\n",i);
			i=(i+a)+i;
		}
	}else
		{
			printf("Error abriendo archivo\n");
		}
	if(fclose(fp)==-1)
	{
		puts("No se ha podido cerrar el archivo");
	}else
		{
			puts("El archivo se cerro correctamente");
		}


	if((fp=fopen("MiPrimerArchivoTxt.txt","r"))!=NULL)
	{
		while(!feof(fp))
				{
					if(fscanf(fp,"%d\n",&j[paso])!=1)
					{
						if(feof(fp))
							break;
						else
						{
							puts("no leyo todos");
							break;
						}
					}
				printf("El valor de j[%d] es %d\n",paso,j[paso]);
				paso++;//fread
				}
	}else
		puts("No se ha podido abrir el archivo");

	if(fclose(fp)==-1)
		{
			puts("No se ha podido cerrar el archivo");
		}else
			{
				puts("El archivo se cerro correctamente");
			}

	puts("!!!Que hay de nuevo viejo!!!");
	return EXIT_SUCCESS;
}
/* MODO ESCRITURA Y LECTURA BINARIO
 int main(void)
{
		//fopen
		//fwrite
		//fread
		//fclose
		//feof()

	FILE* fp;

	int i=99;
	int j[10];
	int paso=0;

	if((fp=fopen("MiPrimerArchivo.txt","w"))!=NULL)
	{
		for (int a = 0; a < 10; ++a)
		{
			if(fwrite(&i,sizeof(int),1,fp)!=1)
				break;
		i=(i+a)+i;
		}
	}else
		{
			printf("Error abriendo archivo\n");
		}
	if(fclose(fp)==-1)
	{
		puts("No se ha podido cerrar el archivo");
	}else
		{
			puts("El archivo se cerro correctamente");
		}

	if((fp=fopen("MiPrimerArchivo.txt","r"))!=NULL)
	{
		while(!feof(fp))
		{
			if(fread(&j[paso],sizeof(int),1,fp)!=1)
			{
				if(feof(fp))
					break;
				else
				{
					puts("no leyo todos");
					break;
				}
			}
		printf("El valor de j[%d] es %d\n",paso,j[paso]);
		paso++;
		}
	}else
		puts("No se ha podido abrir el archivo");
	if(fclose(fp)==-1)
		{
			puts("No se ha podido cerrar el archivo");
		}else
			{
				puts("El archivo se cerro correctamente");
			}
	puts("!!!Que hay de nuevo viejo!!!");
	return EXIT_SUCCESS;
}
*/
