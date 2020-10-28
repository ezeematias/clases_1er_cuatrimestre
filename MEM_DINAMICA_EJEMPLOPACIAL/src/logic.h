/*
 ============================================================================
 Name        : PRIMER_PARCIAL_LABO1
 Author      : Un�a, Ezequiel Mat�as
 Version     :
 Copyright   :
 Description : Primer Parcial Laboratorio 1
 ============================================================================
*/

#ifndef LOGIC_H_
#define LOGIC_H_
#include "client.h"
#include "publicity.h"
#include "utn.h"

#define MSG_START "-----------------------------------\nXXXXXXX| INICIANDO PROGRAMA |XXXXXXX\n-----------------------------------\n"
#define MSG_OFF  "------------------------------------\nXXXXXXX| APAGANDO PROGRAMA |XXXXXXX\n------------------------------------\n"
#define MSG_OPTION_MENU "\n------ SELECCIONE UNA OPCI�N ------\n\n[1] -> AGREGAR NUEVO CLIENTE\n[2] -> MODIFICAR CLIENTE\n[3] -> BAJA DE CLIENTE\n[4] -> NUEVA PUBLICACI�N\n[5] -> PAUSAR PUBLICACI�N\n[6] -> REANUDAR PUBLICACI�N\n[7] -> IMPRIMIR CLIENTES\n[8] -> INFORMES\n\n[0] -> SALIR\n\n[OPCI�N SELECCIONADA]"
#define MSG_REPORT_MENU "\n------ SELECCIONE UNA OPCI�N ------\n\n[1] -> CLIENTE CON M�S PUBLICACIONES\n[2] -> CLIENTE CON M�S PUBLICACIONES ACTIVAS\n[3] -> CLIENTE CON M�S PUBLICACIONES PAUSADAS\n[4] -> CANTIDAD DE PUBLICACIONES PAUSADAS\n[5] -> RUBRO CON M�S PUBLICACIONES\n\n[0] -> SALIR\n\n[OPCI�N SELECCIONADA]"
#define MSG_OPTION_ISACTIVE "\n------ SELECCIONE UNA OPCI�N ------\n\n[1] -> CONFIRMAR CAMBIO\n[0] -> ATRAS\n\n[OPCI�N SELECCIONADA]"
#define MSG_OPTION_ERROR "------------ ERROR ------------"
#define MSG_CLIENT_FAIL    "------------------------------------\nX [DEBE INGRESAR CLIENTES PRIMERO] X\n------------------------------------\n"
#define MSG_PUBLICITY_FAIL "------------------------------------\nX [NO HAY PUBLICIDADES INGRESADAS] X\n------------------------------------\n"
#define MSG_ACTIVE_FAIL "\n-----------------------------------\nXX| NO HAY PUBLICIDADES ACTIVAS |XX\n-----------------------------------\n"
#define MSG_PAUSED_FAIL "\n-----------------------------------\nXX| NO HAY PUBLICIDADES PAUSADAS |XX\n-----------------------------------\n"
#define MSG_ADD_OK "\n----- [CARGADO CORRECTAEMTNE] -----\n"
#define MSG_ADD_FAIL 	"\n------ [NO SE CARG� CLIENTE] ------\n"
#define MSG_MODIFY_OK   "\n---- [MODIFICADO CORRECTAMENTE] ---\n"
#define MSG_MODIFY_FAIL "\n----- [NO SE MODIFIC� CLIENTE] ----\n"
#define MSG_REMOVE_OK   "\n---- [ELIMINADO CORRECTAMENTE] ----\n"
#define MSG_REMOVE_FAIL "\n----- [NO SE ELIMIN� CLIENTE] -----\n"
#define MSG_REMOVE_CLIENT "\n----- CLIENTE A DAR DE BAJA ------\n\n[ID] -------> %d\n[NOMBRE] ---> %s\n[APELLIDO] -> %s\n[CUIT] --> %s\n[INDEX] ----> %d\n"
#define MSG_ADD_PUBLICITY_OK  "\n----- [CREADO CORRECTAMENTE] -----\n"
#define MSG_ADD_PUBLICITY_FAIL   "\n---- [NO SE CARG� PUBLICIDAD] ----\n"
#define MSG_PAUSED_PUBLICITY_OK  "\n----- CANTIDAD DE PUBLICIDADES PAUSADAS ------\n> %d\n"
#define MSG_PAUSED_PUBLICITY_FAIL "\n- [NO HAY PUBLICACIONES PAUSADAS]-\n"
#define MSG_PRINT_CLIENT "\n---------------------------------------------------------------------------------------------------------------\n|| --[ID]-- || ------[NOMBRE]------ || -----[APELLIDO]----- || -----[CUIT]------ || -[PUBLICIDADES ACTIVAS]- ||\n---------------------------------------------------------------------------------------------------------------"
#define MSG_PRINT "\n|| > %d   || %-20s || %-20s || %17s ||            %4d          ||"
#define MSG_PRINT_OUT "\n---------------------------------------------------------------------------------------------------------------\n"

int logic_menu (void);
int logic_addPublicity (Client* listClient[], int lenClient, Publicity* listPublicity, int lenPublicity);
int logic_isActivePublicity (Client* listClient[], int lenClient, Publicity* listPublicity, int lenPublicity);
int logic_removeClient (Client* listClient[], int lenClient, Publicity* listPublicity, int lenPublicity);
int logic_print(Client* listClient[], int lenClient, Publicity* listPublicity, int lenPublicity);
int logic_report(Client* listClient[], int lenClient, Publicity* listPublicity, int lenPublicity);
int logic_isPausedPublicity (Client* listClient[], int lenClient, Publicity* listPublicity, int lenPublicity);
int logic_clientMorePublicity(Client* listClient[], int lenClient, Publicity* listPublicity, int lenPublicity);
int logic_manualPublicity (Publicity* listPublicity);
int logic_manualClient (Client* listClient);
int logic_clientMorePublicityActive(Client* listClient[], int lenClient, Publicity* listPublicity, int lenPublicity);
int logic_clientMorePublicityPaused(Client* listClient[], int lenClient, Publicity* listPublicity, int lenPublicity);
void client_delete(Client* pc);

#endif /* LOGIC_H_ */
