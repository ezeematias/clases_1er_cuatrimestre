/*
 * booking.h
 *
 *  Created on: 1 oct. 2020
 *      Author: peque
 */

#ifndef BOOKING_H_
#define BOOKING_H_
#define SIZE_NAME 51
#define SIZE_LOCATION 51

struct
{
 int idBooking;
 char nameFileBooking[SIZE_NAME];
 int quantityDays;
 int cuitClient;
 int isEmpty;
 int idDisplay;
}typedef Booking;

#endif /* BOOKING_H_ */
