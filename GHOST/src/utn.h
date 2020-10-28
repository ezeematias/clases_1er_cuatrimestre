/*
 ============================================================================
 Name        : Ghost
 Author      : Unía, Ezequiel Matías
 Version     :
 Copyright   :
 Description : ABM Fantasma
 ============================================================================
 */

#ifndef UTN_H_
#define UTN_H_

int utn_sortArrayInt(int* pArray, int len);
int utn_printArrayInt(int* pArray, int len);
int utn_getInt(int *pArray, int len, int attempts, char* msg, char* msgError, int max, int min);
int utn_getFloat(float *pArray, int len, int attempts, char* msg, char* msgError, int max, int min);
int utn_getName (char* pArray, int len, char* msg, char* msgError, int attempts);
int utn_getAddress (char* pArray, int len, char* msg, char* msgError, int attempts);
int utn_getEmail (char* pArray, int len, char* msg, char* msgError, int attempts);

#endif /* UTN_H_ */
