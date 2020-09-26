/*
 * utn.h
 *
 *  Created on: 5 sept. 2020
 *      Author: peque
 */

#ifndef UTN_H_
#define UTN_H_

int utn_getNumber (int* pNumeroIngresado, int minimo, int maximo, char* mensaje, char* mensajeError, int reintentos);
int utn_getNumbreFloat (float* pNumeroFloatIngresado, float minimo, float maximo, char* mensaje, char* mensajeError, int reintentos);
int utn_getChar (char* pNombreIngresado, char* mensaje, char* mensajeError, int reintentos);
int  get_factorial(int numeroX, int *resultado);
#endif /* UTN_H_ */
