/*
 ============================================================================
 Name        : CONSTRUCTOR.c
 Author      : Unía, Ezequiel Matías
 Version     :
 Copyright   :
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#ifndef MODEL_H_
#define MODEL_H_
#define TRUE 1
#define FALSE 0
#define LONG_STRUCT 20
#define LONG_ARRAY 55


#define MSG_START "-----------------------------------\nXXXXXXX| INICIANDO PROGRAMA |XXXXXXX\n-----------------------------------\n"
#define MSG_OFF  "------------------------------------\nXXXXXXX| APAGANDO PROGRAMA |XXXXXXX\n-----------------------------------\n"
#define MSG_QTY_FIELD 		   "\n---| CANTIDAD DE CAMPOS QUE TENDRÁ LA ESTRUCTURA |------------------\n"
#define MSG_OPTION_ERROR       "\n---| XXX ERROR XXX |------------------------------------------------\n"
#define MSG_FIELD_TYPE         "\n---| INGRESE TIPO DE LA ESTRUCTURA |--------------------------------\n"
#define MSG_NAME_TYPE_FIELD    "\n---| INGRESE TIPO DEL CAMPO |---------------------------------------\n\n[1] > INT\n[2] > FLOAT\n[3] > CHAR\n"
#define MSG_NAME_TYPE          "\n---| INGRESE EL NOMBRE DE LA ESTRUCTURA |---------------------------\n"
#define MSG_FIELD_TYPE_FIELD   "\n---| INGRESE EL NOMBRE DEL CAMPO |----------------------------------\n"
#define MSG_ERROR 		 	   "\n---| XXX DATO NO VÁLIDO XXX |---------------------------------------\n"
#define MSG_NUMBER_FIELD 	   "\n---| INGRESE EL %dº |-----------------------------------------------\n"


typedef struct
{
	char typeField[LONG_ARRAY];
	char nameField[LONG_ARRAY];
	int isEmpty;
}Field;

int model_menu();
void model_initArray(Field* list);
void model_new(Field* list);
void model_delete(Field* list);
void model_getField(Field* list);
void model_isValid(Field* list);
void model_setField(Field* list);

#endif /* MODEL_H_ */
