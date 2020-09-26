/*
 ============================================================================
 Name        : COD_CLASE_06.c
 Author      : Unía, Ezequiel Matías
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "utn.h"

#define SIZE 5

int main(void) {
	setbuf(stdout, NULL);
	int variableInt;
	char aMensaje[200];
	int arrayInt[SIZE];
	int flagCargaCorrecta = 0;


	for(int i=0; i < SIZE ; i++)
	{
		sprintf(aMensaje,"Numero %d\n",i+1);
		if(utn_getInt(aMensaje,"Fuera de rango [0-1000]\n",&variableInt,SIZE,1000,0) != 0)
		{
			printf("GAME OVER");
			flagCargaCorrecta = -1;
			break;
		}
		else
		{
			arrayInt[i] = variableInt;

		}
	}

	utn_printArrayInt(arrayInt, SIZE);
	printf("\n");
	utn_ordenarArray(arrayInt, SIZE);
	utn_printArrayInt(arrayInt, SIZE);



	/*
	if(flagCargaCorrecta == 0)
	{
		int numeroMaximo;

		for (int i=0; i < 5;i++)
		{
			if (i == 0 || arrayInt[i] > numeroMaximo)
			{
				numeroMaximo = arrayInt[i];
			}
		}
		printf("\nEl número máximo ingresado es: %d", numeroMaximo);
	}
	*/
	return EXIT_SUCCESS;
}
