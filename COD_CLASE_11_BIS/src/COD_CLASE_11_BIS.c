/*
 ============================================================================
 Name        : COD_CLASE_11_BIS.c
 Author      : Unía, Ezequiel Matías
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "nationality.h"

int main(void) {
	setbuf(stdout, NULL);
	int retorno = -1;
	Nationality listNationality[SIZE_NATIONALITY];
	menuNationality(listNationality);
	return retorno;

	return EXIT_SUCCESS;
}
