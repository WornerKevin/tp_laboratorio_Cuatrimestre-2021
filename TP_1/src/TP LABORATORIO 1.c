//KEVIN WORNER
#include <stdio.h>
#include <stdlib.h>
#include "funciones.h" //LLAMO A LA BIBLIOTECA DE FUNCIONES.H

/**
 * @fn int main(void)
 * @brief
 * MostrarSeparador() : genera un printf con guiones para dividir el menu y que sea mas legible
 * PedirNumero() : tomo el valor por scanf de lo que se ingrese como primer operando y segundo operando para luego ser utilizado
 * Suma() : funcion para que tome por parametro los valores de los operandos y los sume, retornando el resultado.
 * Resta() : funcion que toma por parametro los valores de los operandos, los resta y retorna el resultado.
 * Dividir() : funcion que toma por parametro los valores de los operandos, los divide y retorna el resultado(en caso de ser 0 el segundo operando no se muestran).
 * Multiplicacion() : funcion que toma por parametro los valores de los operandos, los multiplica y retorna el resultado.
 * Factorial() : funcion para calcular el factorial por recursividad(la cual se llama a si misma) y retorna el resultado(en caso de que lo pueda calcular, se muestra).
 * @return
 */
int main(void)
{
	//DECLARACION DE VARIABLES
	setbuf(stdout, NULL);
	int opcion;
	float primerOperando=0;
	float segundoOperando=0;
	float resultadoSuma;
	float resultadoResta;
	float resultadoDivision;
	float resultadoMultiplicacion;
	unsigned long int resultadoFactorial;
	unsigned long int resultadoFactorial2;


	do
	{
		printf("Bienvenido a la Calculadora!!\n");
		MostrarSeparador();
		printf("Seleccione una opcion \n1-.Ingresar 1er operando %.2f\n2-.Ingresar 2do operando %.2f\n", primerOperando, segundoOperando);
		printf("3-.Calcular todas las operaciones\n-Sumar\n-Restar\n-Dividir\n-Multiplicar\n-Factorial\n4-.Informar resultados\n5-.Salir\n");
		printf("Ingrese la opcion: ");
		fflush(stdin);
		scanf("%d", &opcion);
		MostrarSeparador();

		switch(opcion) //MENU
		{
		case 1:
			primerOperando = PedirNumero(primerOperando);
			break;
		case 2:
			segundoOperando = PedirNumero(segundoOperando);
			break;
		case 3:
			printf("Eligio calcular las operaciones\n");
			resultadoSuma = Suma(primerOperando, segundoOperando);
			resultadoResta = Resta(primerOperando, segundoOperando);
			resultadoDivision = Dividir(primerOperando, segundoOperando);
			resultadoMultiplicacion = Multiplicacion(primerOperando, segundoOperando);
			if(primerOperando > -1)
			{
				resultadoFactorial = Factorial(primerOperando);
			}
			if(segundoOperando >-1)
			{
				resultadoFactorial2 = Factorial(segundoOperando);
			}
				break;
		case 4:
			printf("Eligio informar los resultados\n");
			printf("El resultado de la suma de %.2f + %.2f es: %.2f\n", primerOperando, segundoOperando, resultadoSuma);
			printf("El resultado de la resta de %.2f - %.2f es: %.2f\n", primerOperando, segundoOperando, resultadoResta);
			if(segundoOperando != 0)
			{
				printf("El resultado de la division de %.2f ÷ %.2f es: %.2f\n", primerOperando, segundoOperando, resultadoDivision);
			}
			else
			{
				printf("No se puede dividir por 0\n");//Al no poder dividir por 0 se le informa al usuario en caso de que el segundo operador sea 0
			}

				printf("El resultado de la multiplicacion de %.2f x %.2f es: %.2f\n", primerOperando, segundoOperando, resultadoMultiplicacion);
				if(primerOperando > -1 && primerOperando < 33)
				{
					printf("El resultado del factorial de %.2f es: %ld\n", primerOperando, resultadoFactorial);
					//No permito que muestre el factorial de numeros negativos ni mayores a 32 para que no rompa el programa
				}
				else
				{
					printf("No se pudo calcular el factorial de %.2f\n", primerOperando);
				}
				if(segundoOperando > -1 && segundoOperando < 33)
				{
				    printf("El resultado del factorial de %.2f es: %ld \n", segundoOperando, resultadoFactorial2);
				}
				else
				{
				    printf("No se pudo calcular el factorial de %.2f\n", segundoOperando);
				}
				MostrarSeparador();
				system("pause");
					break;
		case 5:
			printf("Eligio salir, fin del programa\n");
			break;
		default:
			printf("No selecciono ninguna opcion valida. Reintente nuevamente\n");
			break;
		}

	}while(opcion !=5);

	return EXIT_SUCCESS;
}
