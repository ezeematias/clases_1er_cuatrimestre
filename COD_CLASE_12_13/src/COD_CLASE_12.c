/*
 ============================================================================
 Name        : COD_CLASE_12.c
 Author      : Un�a, Ezequiel Mat�as
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "display.h"

int main(void) {
	setbuf(stdout, NULL);
	Display listDisplay[SIZE_QTYDISPLAY];
	menuDisplay(listDisplay);
	return EXIT_SUCCESS;
}
