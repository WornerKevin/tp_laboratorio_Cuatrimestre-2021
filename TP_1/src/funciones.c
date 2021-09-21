#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
//Creo una funcion para que en el menu se separen los printf al momento de ir interactuando con la calculadora
void MostrarSeparador(void)
{
	printf("-------------------------------\n");
}
//La funcion para lograr tomar el numero flotante por scanf de los operandos 1 y 2
float PedirNumero(float numero)
{
	float numeroIngresado;
	printf("Ingrese el operando: \n");
	fflush(stdin);
	scanf("%f", &numeroIngresado);
	return numeroIngresado;
}
//Funcion de suma para que tome los operandos ingresados y realice el calculo
float Suma(float numero1, float numero2)
{
	float resultado;
	resultado = numero1 + numero2;
	return resultado;
}
//Funcion de resta para que realice el calculo con los operandos ingresados
float Resta(float resta1, float resta2)
{
	float resultadoR;
	resultadoR = resta1 - resta2;
	return resultadoR;
}
//Funcion de division para que realice el calculo pedido
float Dividir(float division1, float division2)
{
	float resultadoD;
	resultadoD = division1 / division2;
	return resultadoD;
}
//Funcion de multiplicacion para que realice el calculo pedido
float Multiplicacion(float multiplicacion1, float multiplicacion2)
{
	float resultadoM;
	resultadoM = multiplicacion1 * multiplicacion2;
	return resultadoM;
}
//Realizo la logica del factorial por recursividad
int Factorial(int numero1)
{
	int factorial = 1;

	if (numero1 != 1 && numero1 != 0)
	{
		factorial = numero1 * Factorial(numero1-1);
	}

	return factorial;
}
