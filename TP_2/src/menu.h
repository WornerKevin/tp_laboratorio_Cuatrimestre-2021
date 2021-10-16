/*
 * menu.h
 *
 *  Created on: 11 oct. 2021
 *      Author: Kevin Worner
 */

#ifndef MENU_H_
#define MENU_H_

/**
 * @fn int menu(int*)
 * @brief esta funcion muestra con printf el menu y  toma la respuesta por scanf
 * validando el numero entero ingresado
 *
 * @param respuesta variable que pasa como puntero al main con el valor ingresado
 * @return devuelve 0 en caso de estar OK y -1 en caso de tener un error
 */
int menu(int* respuesta);

/**
 * @fn int subMenu(void)
 * @brief esta funcion es para el submenu que necesita la opcion 4
 * toma la respuesta ingresada y la valida
 *
 * @return devuelve 0 en caso de estar OK y -1 en caso de tener un error
 */
int subMenu(void);

/**
 * @fn int agregarEmpleado(Employee*, int, int*)
 * @brief esta funcion toma por parametro el id, el tamaño
 * de la lista y la lista del empleado
 *
 * @param list variable que pasa como parametro para almacenar los datos de la estructura
 * @param tamList tamaño de la lista
 * @param id
 * @return devuelve 0 en caso de estar OK y -1 en caso de tener un error
 */
int agregarEmpleado(Employee* list, int tamList, int* id);

/**
 * @fn int modificarEmpleado(Employee*, int)
 * @brief funcion que modifica empleado ingresado obteniendo
 * por parametro la lista de la estructura y el tamaño
 *
 * @param list variable que pasa como parametro para almacenar los datos de la estructura
 * @param tamList tamaño de la lista
 * @return devuelve 0 en caso de estar OK y -1 en caso de tener un error
 */
int modificarEmpleado(Employee* list, int tamList);

/**
 * @fn int eliminarEmpleado(Employee*, int)
 * @brief funcion que elimina un empleado ingresado, pasando por
 * parametro la lista y el tamaño
 *
 * @param list variable que pasa como parametro para almacenar los datos de la estructura
 * @param tamList tamaño de la lista
 * @return devuelve 0 en caso de estar OK y -1 en caso de tener un error
 */
int eliminarEmpleado(Employee* list, int tamList);

/**
 * @fn int informarPromedios(Employee*, int)
 * @brief funcion que informa los promedios pasando por parametro la lista
 * y el tamaño
 *
 * @param list variable que pasa como parametro para almacenar los datos de la estructura
 * @param tamList tamaño de la lista
 * @return devuelve 0 en caso de estar OK y -1 en caso de tener un error
 */
int informarPromedios(Employee* list,int tamList);

#endif /* MENU_H_ */
