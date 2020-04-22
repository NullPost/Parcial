
/* 
Autor: Mario Guerra
Compilador: gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
Compilado: gcc minimoscuad.c -o minimoscuad
Fecha: Wed Apr 22 13:59:13 CST 2020
Resumen: calcula el mejor fit lineal para una serie de datos 
Entrada: rango de semanas y datos para cada semana
Salida: los mejores coeficientes a y b que describen a los datos como una linea a*x + b
*/

//librerias
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
//numerar los pasos de pseudocodigo

void main(){
	float numDatos;
	float datosY[40];
	double sumX = 0;
	double sumY = 0;
	double sumX2 = 0;
	double sumY2 = 0;
	double sumXY = 0;
	printf("Este programa calcula el mejor fit lineal para una serie de datos que cambian semana por semana\n");
	printf("Ingrese para cuantas semanas se tienen datos: ");
	scanf("%f", &numDatos);
	for(int i = 0; i < numDatos; i++){
		printf("Ingresar dato para semana %d: ", i+1);
		scanf("%f", &datosY[i]);
	}
//Sumatoria de datos xi
	for(int i = 1; i <= numDatos; i++){
		sumX += i;
	}
//	printf("sumX %.5lf\n", sumX);
//Sumatorioa de datos yi
	for(int i = 0; i < numDatos; i++){
		sumY += datosY[i];
	}
//	printf("sumY %.5lf\n", sumY);
//Sumatoria Xi^2
	for(int i = 1; i <= numDatos; i++){
//		sumX2 += i*i;
	}
	//printf("sumX2 %.5lf\n", sumX2);
//Sumatoria Yi^2
	for(int i = 0; i < numDatos; i++){
		sumY2 += datosY[i]*datosY[i];
	}
//	printf("sumY2 %.5lf\n", sumY2);
//Sumatoria Xi*Yi
	for(int i = 0; i < numDatos; i++){
		sumXY += datosY[i]*(i + 1);
	}
//	printf("sumXY %.5lf\n", sumXY);
	
//	Demoniminador de a y b
	double Den = numDatos*sumX2 - sumX*sumX; 

//	coeficientes
//	a
	double a = (sumY*sumX2 - sumX*sumXY)/Den;
//	b
	double b = (numDatos*sumXY - sumX*sumY)/Den;
	printf("mejor linea de fit para los datos: %.5lf*x + %.5lf\n", a, b);

	system("gnuplot");
	system("plot [-3:3] x**2");











}
		
