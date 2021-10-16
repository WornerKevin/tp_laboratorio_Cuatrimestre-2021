#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#include "ArrayEmployees.h"
#include "menu.h"

int initEmployees(Employee* list, int len)
{
	int ret = -1;
	int i;

	if(list != NULL && len < 1001 && len > 0)
	{
		for(i=0; i<len; i++)
		{
			list[i].id = -1;
			list[i].isEmpty = 1;
		}
		ret = 0;
	}
	return ret;
}

int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
	int ret = -1;

	if(list != NULL && len <1001 && len > 0 && name != NULL && lastName != NULL && salary > 0 && id > -1)
	{
		for(int i=0 ; i < len; i++)
		{
			if(list[i].isEmpty == 1)
			{
				strcpy(list[i].name, name);
				strcpy(list[i].lastName, lastName);
				list[i].id = id;
				list[i].salary = salary;
				list[i].sector = sector;
				list[i].isEmpty = 0;
				ret = 0;

				break;
			}
 		}
	}
	return ret;
}


int findEmployeeById(Employee* list, int len,int id)
{
	int ret = -1;
	int i;

	if(list != NULL && len < 1001 && len > 0 && id > -1)
	{
		for(i=0; i<len; i++)
		{
			if(list[i].id == id && list[i].isEmpty == 0)
			{
				ret = i;
				break;
			}
		}
	}
	return ret;
}

int removeEmployee(Employee* list, int len, int id)
{
	int ret = -1;
	int index = findEmployeeById(list, len, id);
	if(list != NULL && len < 1001 && len > 0 && id > -1)
	{
		if(index != -1)
		{
			list[index].isEmpty = 1;
			ret = 0;
		}
	}
	return ret;
}

int sortEmployees(Employee* list, int len, int order)
{
	int rtn = -1;
	int i;
	int j;
	Employee aux;

	if (list != NULL && len > 0 && len < 1001)
	{
		switch(order)
		{
		case 0:
			for (i = 0; i < len - 1; i++)
			{
				for (j = i + 1; j < len; j++)
				{

					if (list[i].isEmpty == 0 && list[j].isEmpty == 0)
					{

						if (list[i].lastName > list[j].lastName)
						{

							aux = list[i];
							list[i] = list[j];
							list[j] = aux;
						}
					}
				}
			}
			rtn = 0;
			break;
		case 1:
			for (i = 0; i < len - 1; i++)
			{
				for (j = i + 1; j < len; j++)
				{

					if (list[i].isEmpty == 0 && list[j].isEmpty == 0)
					{

						if (list[i].lastName < list[j].lastName)
						{

							aux = list[i];
							list[i] = list[j];
							list[j] = aux;
						}
					}
				}
			}
			rtn = 0;
			break;
		default:
			rtn = -1;
			break;
		}
	}
	return rtn;
}


int printEmployees(Employee* list, int length)
{
	printf("ID  |   Name   |   Last Name  |   Salary   |  Sector\n");
	for(int i = 0; i < length; i++)
	{
		if(list[i].isEmpty == 0)
		{
			printf("%2d  |%9s |%9s     |   %5.2f  |     %d\n", list[i].id, list[i].name, list[i].lastName, list[i].salary, list[i].sector);
		}
	}
	return 0;
}


