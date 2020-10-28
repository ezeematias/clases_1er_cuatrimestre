/*
 ============================================================================
 Name        : GHOST.c
 Author      : Unía, Ezequiel Matías
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "arrayEmployee.h"
#include "utn.h"

int main(void) {
	setbuf(stdout, NULL);
	Employee listEmployee[LONG_EMPLOYEE];
	menuEmployee(listEmployee);
	return EXIT_SUCCESS;
}
