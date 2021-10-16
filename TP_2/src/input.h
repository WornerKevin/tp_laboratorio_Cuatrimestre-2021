/*
 * input.h
 *
 *  Created on: 11 oct. 2021
 *      Author: Kevin Worner
 */

#ifndef INPUT_H_
#define INPUT_H_

/**
 * @fn int getInteger(int*, char*, char*, int, int)
 * @brief function in which by parameter allows me to enter whole
 * numbers with a maximum, minimum and a message
 * @param integer by parameter took the value an integer
 * @param message pass a message by parameter
 * @param messageMistake pass by parameter a message in case of error
 * @param min pass a minimum parameter
 * @param max pass by parameter a maximum
 * @return return 0 in case of being OK and -1 in case of having an error
 */
int getInteger(int* integer, char* message, char* messageMistake, int min, int max);

/**
 * @fn int getString(char*, char*, char*, int)
 * @brief in this function by parameter
 * take the input of a string with a maximum size and with messages to the user
 * @param chain for parameter, take a string
 * @param message  generate a message to the user
 * @param messageMistake generate an error message to the user
 * @param max generate a maximum of space in the array
 * @return return 0 in case of being OK and -1 in case of having an error
 */
int getString(char* chain, char* message, char* messageMistake, int max);

/**
 * @fn int getFloat(float*, char*, char*, float, float)
 * @brief function in which by parameter allows me
 * to pass floating numbers with a maximum, minimum and a message
 *
 * @param number by parameter took the value an float
 * @param message pass a message by parameter
 * @param messageMistake pass by parameter a message in case of error
 * @param min pass a minimum parameter
 * @param max pass by parameter a maximum
 * @return return 0 in case of being OK and -1 in case of having an error
 */
int getFloat(float* number, char* message, char* messageMistake, float min, float max);


#endif /* INPUT_H_ */
