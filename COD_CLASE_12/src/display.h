/*
 * display.h
 *
 *  Created on: 1 oct. 2020
 *      Author: peque
 */

#ifndef DISPLAY_H_
#define DISPLAY_H_
#define SIZE_NAME 51
#define SIZE_LOCATION 51
#define SIZE_QTYDISPLAY 100
#define TRUE 1
#define FALSE 0


struct
{
 int idDisplay;
 char nameDisplay[SIZE_NAME];
 int typeDisplay;
 float priceDay;
 char locationAddress[SIZE_LOCATION];
 int isEmpty;
}typedef Display;

int menuDisplay(Display* aNationality);

#endif /* DISPLAY_H_ */
