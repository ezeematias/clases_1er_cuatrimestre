/*
 ============================================================================
 Name        : COD_CLASE_04.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);

	int numeroIngresado;
	int resultadoScanf;

	printf("Ingrese un n�mero entero:");
	fflush(stdin);
	resultadoScanf = scanf("%d",&numeroIngresado);
	printf("%d", numeroIngresado);
	printf("\n%d", resultadoScanf);

	return EXIT_SUCCESS;
}



int utn_getNumber (void)
{
	int retorno =-1;
	int numeroIngresado;

	printf("Ingrese un n�mero entero:");
	fflush(stdin);
	scanf("%d",numeroIngresado);



	return retorno;
}



