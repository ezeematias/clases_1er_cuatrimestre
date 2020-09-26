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
int utn_contarIntEnArray(int* pArray, int limite, int numero);
int utn_contarIntEnArrayReferencia(int* pArray, int limite, int numero, int* pContador);
int utn_contarCharEnArray(char* pArray, int limite, char letra);
int utn_contarCharEnArrayReferencia(char* pArray, int limite, char letra, int* pContador);
int utn_verificarCharEnArray(char* pArray);
int utn_getNombre(char* aNombre);

#endif /* UTN_H_ */
