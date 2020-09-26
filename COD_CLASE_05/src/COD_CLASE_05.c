/*
 ============================================================================
 Name        : COD_CLASE_05.c
 Author      : Unía, Ezequiel Matías
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
/*
 Pedir 5 numeros


 - OP1 - Calcular Maximo
 - OP2 - Calcular Promedio
 - OP3 - Calcular Minimo
 -
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "utn.h"

int main(void) {
	setbuf(stdout, NULL);
	int variableInt;
	char aMensaje[200];
	int arrayInt[5];
	int flagCargaCorrecta = 0;

	for(int i=0; i < 5 ; i++)
	{
		sprintf(aMensaje,"Numero %d\n",i+1);
		if(getInt(aMensaje,"Fuera de rango [0-1000]\n",&variableInt,5,1000,0) != 0)
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
	return EXIT_SUCCESS;
}
