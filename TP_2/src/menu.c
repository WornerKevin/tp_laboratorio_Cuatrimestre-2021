/*
 * menu.c
 *
 *  Created on: 15 oct. 2021
 *      Author: Kevin Worner
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#include "ArrayEmployees.h"
#include "menu.h"

int menu(int* respuesta)
{
	int ret = -1;
	int r;

	if(respuesta != NULL)
	{
		printf("1-ALTAS\n");
		printf("2-MODIFICAR\n");
		printf("3-BAJA\n");
		printf("4-INFORMAR\n");
		printf("5-Salir\n");
		printf("Ingrese una opcion: ");
		fflush(stdin);
		r = scanf("%d", respuesta);
		while(r==0 || *respuesta > 5)
		{
			printf("Error, reingrese una opcion valida: ");
			fflush(stdin);
			r = scanf("%d", respuesta);
		}
		ret=0;
	}
	return ret;
}

int subMenu(void)
{
	int respuesta = -1;

	printf("1-Mostrar los empleados en orden\n");
	printf("2-Informar el promedio del sueldo\n");
	printf("3-Atras\n");
	fflush(stdin);
	scanf("%d", &respuesta);
	while(respuesta <1 || respuesta>3)
	{
		printf("Error, reingrese una opcion valida: ");
		fflush(stdin);
		scanf("%d", &respuesta);
	}
	return respuesta;
}

int agregarEmpleado(Employee* list, int tamList, int* id)
{
	int ret = -1;
	char nombre[51];
	char apellido[51];
	float salario;
	int sector;
	if(list != NULL && tamList > 0 && id != NULL)
	{
		printf("ID: %d\n", *id);
		getString(nombre,"Escriba el nombre: ", "Escriba un nombre valido: ", 51);
		getString(apellido,"Escriba el apellido: ", "Escriba un apellido valido: ", 51);
		getFloat(&salario,"Escriba el salario: ","Escriba el salario nuevamente: ", 1, 9999999);
		getInteger(&sector, "Escriba el sector: ", "Escriba un sector valido", 1,1000000);
		addEmployee(list, tamList, *id, nombre, apellido, salario, sector);
		*id = *id + 1;
		printf("Se creo exitosamente\n");
		ret = 0;
	}

	return ret;
}
int modificarEmpleado(Employee* list, int tamList)
{
	int retorno = -1;
	int id;
	Employee nuevoEmpleado;
	int modificar;
	int i = -1;


	if(list != NULL && tamList > 0)
	{
		printEmployees(list, tamList);
		getInteger(&id, "Escriba el ID del empleado que desea modificar: ", "Escriba un ID valido: ", 0, 1000);

		i = findEmployeeById(list, tamList, id);

			if(i != -1)
			{
				nuevoEmpleado = list[i];
				getInteger(&modificar, "Que desea modificar:\n1.Nombre\n2.Apellido\n3.Salario\n4.Sector:","Error. Que desea modificar:\n1.Nombre\n2.Apellido\n3.Salario\n4.Sector:", 1, 4);
				switch(modificar)
				{
				case 1:
					getString(nuevoEmpleado.name,"Escriba el nuevo nombre: ","Error, escriba el nombre valido: ", 51);
					break;
				case 2:
					getString(nuevoEmpleado.lastName,"Escriba el nuevo apellido: ","Error, escriba el apellido valido: ", 51);
					break;
				case 3:
					getFloat(&nuevoEmpleado.salary,"Escriba el nuevo salario: ", "Error, escriba un salario valido: ", 1, 9999999);
					break;
				case 4:
					getInteger(&nuevoEmpleado.sector, "Escriba el nuevo sector: ", "Error, escriba el sector nuevamente: ", 0, 99999999);
					break;
				}
				list[i] = nuevoEmpleado;
				retorno = 0;
				printf("Se modifico con exito\n");
			}
			else
			{
				printf("No existe el ID\n");
			}
		}

	return retorno;
}

int eliminarEmpleado(Employee* list, int tamList)
{
	int ret = -1;
	int id;

	if(list != NULL && tamList > 0)
	{
		getInteger(&id,"Escriba el ID del empleado que desea eliminar: ", "Error, escriba el ID del empleado a eliminar: ", 0, 1000);
		findEmployeeById(list, tamList, id);
		if(findEmployeeById(list, tamList, id) != -1)
		{
			removeEmployee(list, tamList, id);
			printf("Se elimino con exito\n");
			ret = 0;
		}
		else
		{
			printf("El ID no existe\n");
		}
	}
	return ret;
}
int informarPromedios(Employee* list,int tamList)
{
	int retorno = -1;
	float salarioTotal = 0;
	int contadorEmpleados = 0;
	int superanPromedio = 0;
	float promedio;
	if(list != NULL && tamList > 0)
	{
		for(int i = 0; i < tamList; i++)
		{
			if(list[i].isEmpty == 0)
			{
				salarioTotal += list[i].salary;
				contadorEmpleados++;
			}
		}

		promedio = salarioTotal / contadorEmpleados;
		printf("Salario total: %.2f\n", salarioTotal);
		printf("El promedio de sueldo es %.2f\n", promedio);
		for(int i = 0; i < tamList; i++)
		{
			if(list[i].isEmpty == 0 && list[i].salary > promedio)
			{
				superanPromedio++;
			}
		}
		printf("La cantidad de empleados que superan el promedio son: %d\n", superanPromedio);
		retorno = 0;
	}
	return retorno;
}
