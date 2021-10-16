#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#include "ArrayEmployees.h"
#include "menu.h"
#define TAMSTRING 51
#define TAM 1000



int main(void)
{
	setbuf(stdout, NULL);
	Employee arrayEmployees[TAM];
	int order;
	int id;
	int contadorEmpleados=0;
	int respuesta;

	initEmployees(arrayEmployees, TAM);
	do
	{
		menu(&respuesta);
		switch(respuesta)
		{
			case 1:
				if(contadorEmpleados < TAM)
				{
					agregarEmpleado(arrayEmployees, TAM, &id);
					contadorEmpleados++;
				}
				else
				{
					printf("No hay lugar disponible\n");
				}
				break;

			case 2:
				if(contadorEmpleados > 0)
				{
					modificarEmpleado(arrayEmployees, TAM);
				}
				else
				{
					printf("No hay empleados en la lista\n");
				}
				break;

			case 3:
				if(contadorEmpleados > 0)
				{
					printEmployees(arrayEmployees,TAM);
					respuesta = eliminarEmpleado(arrayEmployees, TAM);
					if(!respuesta)
					{
						contadorEmpleados--;
					}
				}
				else
				{
					printf("No hay empleados para eliminar\n");
				}
				break;
			case 4:
				do
				{
					switch(subMenu())
					{
					case 1:
						if(contadorEmpleados > 0)
						{
							getInteger(&order, "\nIngrese 1 para ordenar apellido de forma Descendente o 0 para Ascendente: ", "\nError, ingrese 1 para ordenar de manera Descendente o 0 para Ascendente: ", 0, 1);
							sortEmployees(arrayEmployees, TAM, order);
							printEmployees(arrayEmployees, TAM);
							system("pause");
						}else
						{
							printf("No hay empleados para mostrar\n");
							system("pause");
						}
						break;
					case 2:
					    if(contadorEmpleados > 0)
                        {
                          	informarPromedios(arrayEmployees, TAM);
                            system("pause");
                        }else
                        {
                            printf("No hay empleados para informar el promedio\n");
                            system("pause");
                        }
						break;

					case 3:
						respuesta = 3;
						break;
					}
				}while(respuesta != 3);

				break;
		}
		system("PAUSE");
	}while(respuesta != 5);

	return EXIT_SUCCESS;
}

