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
#define LONG_ARRAY 55


#define MSG_START "-----------------------------------\nXXXXXXX| INICIANDO PROGRAMA |XXXXXXX\n-----------------------------------\n"
#define MSG_OFF  "------------------------------------\nXXXXXXX| APAGANDO PROGRAMA |XXXXXXX\n-----------------------------------\n"
#define MSG_OPTION_MENU "\n-------- SELECCIONE FUNCION -------\n\n[1] -> type_new(); \n[2] -> type_newParametros();\n[3] -> type_delete();\n[4] -> type_getField();\n[5] -> type_setCampo();\n[6] -> isValidField();\n[0] -> SALIR\n\n[OPCIÓN SELECCIONADA]"
#define MSG_OPTION_ERROR "------------ ERROR ------------"
#define MSG_NAME_TYPE  "\n---------- INGRESE TIPO -----------"
#define MSG_FIELD_TYPE  "\n------- INGRESE TIPO CAMPO --------"
#define MSG_FIELD  "\n--------- INGRESE CAMPO -----------"
#define MSG_THIS  "\n---------- INGRESE THIS -----------"
#define MSG_ERROR "\nXXXXXXX|  DATO NO VÁLIDO  |XXXXXXXX\n"

typedef struct
{
	char typeField[LONG_ARRAY];
	char nameField[LONG_ARRAY];
	char field[LONG_ARRAY];
	char nameFieldFuntion[LONG_ARRAY];
	char thisField[LONG_ARRAY];

}Field;

int model_menu();
void model_new(char* msgType);
void model_delete(char* msgType, char* msgThis);
void model_getField(char* msgTypeField, char* msgType,char* msgThis, char* msgField);

#endif /* MODEL_H_ */
