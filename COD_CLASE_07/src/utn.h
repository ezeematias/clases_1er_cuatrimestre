/*
 * utn.h
 *
 *  Created on: 8 sept. 2020
 *      Author: peque
 */

#ifndef UTN_H_
#define UTN_H_

int utn_getInt(char* mensaje, char* mensajeError, int* pResultado,int reintentos,int maximo,int minimo);
void utn_ordenarArray(int array[], int len);
int utn_printArrayInt(int* pArray, int limite);

#endif /* UTN_H_ */
