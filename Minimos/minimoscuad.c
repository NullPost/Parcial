
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
	float numDatos = 10;
	float datosY[10] = {20.2 , 20.9, 20.6 ,21.3 ,21.75 ,22.05 ,23.62 ,22.92 ,23.8 ,23.85};
	double sumX = 0;
	double sumY = 0;
	double sumX2 = 0;
	double sumY2 = 0;
	double sumXY = 0;
	printf("Este programa calcula el mejor fit lineal para una serie de datos que cambian semana por semana\n");
	printf("Datos en memoria: \n");
	for(int i = 0; i < numDatos; i++){
		printf("semana %d:\tQ %.2f\n", i+1, datosY[i]);
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
		sumX2 += i*i;
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
	printf("mejor linea de fit para los datos: %.5lf*x + %.5lf\n", b, a);
	printf("semana que el combustible llega a Q 30.00: semana %.1f\n", (30 - a)/b);

/* GENERANDO DATOS */
	FILE * fPtf;

	fPtf = fopen("semanas.dat", "w");
	for(int i = 0; i < 10; i++){
		fprintf(fPtf,"%d\t%.2f\n", i+1, datosY[i]);
	}
	fclose(fPtf);
/* GENERANDO ARCHIVO DE CONFIGURACION GNUPLO*/
	fPtf = fopen("configgp.gp", "w");
	fprintf(fPtf,"f(x) = %f*x + %f", b, a);
	fclose(fPtf);

}
		
