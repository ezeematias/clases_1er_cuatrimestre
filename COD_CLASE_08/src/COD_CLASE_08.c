/*
 ============================================================================
 Name        : COD_CLASE_08.c
 Author      : Unía, Ezequiel Matías
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

//#define ARRAY_NUMEROS 12  // 1-2-3
// #define ARRAY_LETRAS 8   // 4


int main(void) {
	setbuf(stdout, NULL);
	/*
	1)
	int numeros[ARRAY_NUMEROS]={3,7,4,5,2,3,7,1,7,3,2,7};
	utn_printArrayInt(numeros, ARRAY_NUMEROS);  // 1)

	2)
	utn_contarIntEnArray(numeros, ARRAY_NUMEROS, 7); // 2)

	3)
	int contadorNumeros;
	utn_contarIntEnArrayReferencia(numeros, ARRAY_NUMEROS, 7, &contadorNumeros);
	printf("La cantidad de numeros entonctrados es \n > %d", contadorNumeros);

	4)
	char aNombre[8] = {'p','e','p','e','1','2','3','\0'};
	int contadorChar;
	utn_contarCharEnArray(aNombre, ARRAY_LETRAS, 'e');
	printf("\n\n");
	utn_contarCharEnArrayReferencia(aNombre, ARRAY_LETRAS, 'e', &contadorChar);
	printf("La cantidad de 'e' en su array es de:\n> %d",contadorChar);

	5)
	char aNombre[8] = {'p','e','p','e','1','2','3','\0'};
	if(utn_verificarCharEnArray(aNombre)==0)
	{
		printf("Nombre es válido");
	}else
	{
		printf("Su nombre no es válido");
	}

    */
	char aNombre[1024];

	if(utn_getNombre(aNombre)==0)
	{
		if(utn_verificarCharEnArray(aNombre)==0)
		{
			printf("Nombre es válido");
		}else
		{
			printf("Su nombre no es válido");
		}
	}
	return EXIT_SUCCESS;
}


/*
1) Se tiene el siguiente array de variables del tipo int
int numeros[12]={3,7,4,5,2,3,7,1,7,3,2,7};
Hacer una funcion que reciba el array y su tamaño, y lo imprima. Escribir un programa para probar la funcion.


2) Hacer una funcion que reciba el array del punto 1 y su tamaño, y cuente cuantas veces aparece el numero 7.
Al terminar de contar, la funcion deberá imprimir por pantalla el valor contado. Escribir un programa para probar la funcion.


3) Modificar la funcion del punto 2 para que NO imprima el valor contado, sino que lo devuelva por referencia
(recibiendo la direccion de memoria de una variable donde escribirá el valor contado). Escribir un programa para probar la funcion.

4) Dada la siguiente cadena de caracteres:
char nombre[8]={'p','e','p','e','1','2','3','\0'};
​
Hacer una funcion que reciba el array y su tamaño, y cuente cuantas veces aparece la letra 'e'.Al terminar de contar,
la funcion deberá imprimir por pantalla el valor contado. Escribir un programa para probar la funcion.

5) Hacer una funcion que reciba el array del punto 4, y verifique que las letras dentro del mismo esten en el rango de 'a' a 'z' o de 'A' a 'Z'.
Si estan dentro del rango la funcion deberá devolver por valor(usando el return) un 0, de lo contrario devolverá -1.

6) 6) Realizar un programa para probar la funcion del punto 5, permitiendo que el usuario ingrese un texto y luego validando si lo
ingresado es un nombre válido. Usar scanf para tomar el texto.


*/
