
/* 
Autor: Mario Guerra
Compilador: gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
Compilado: gcc biseccion.c -o biseccion
Fecha: Sat Apr 25 12:03:33 CST 2020
Resumen: Encuentra x tal que 2 +cos(e^x - 2) -e^x
Entrada: un rango tal que donde sabemos que x se encuentra
Salida:  una aproximacion de la raiz x
*/

//librerias
#include <stdio.h>
#include <math.h>
//numerar los pasos de pseudocodigo
// prototipo de la funcion 
float f(float x);
float bis(float a,float b, float pres);
void main(){
	float rangInf;
	float rangSup;
	int pres;
	printf("Tenemos la funcion f(x) = 2 + cos(e^x - 2)- e^x\nIngrese un rango donde la raiz de esta funcion se encuentre (ejemplo [0,2])\n");
	printf("\nIngrese cota inferor del rango: ");
	scanf("%f", &rangInf);
	printf("Ingrese cota superior del rango: ");
	scanf("%f", &rangSup);
	printf("Ingrese hasta que decimal se requiere la presicion (numero entero, maximo 6): ");
	scanf("%d", &pres);
	float x0 = bis(rangInf, rangSup, pres);

	printf("\nMejor aproximacion: f(%.6f) = %.6f\n", x0, f(x0));

	FILE * fPtf;
	fPtf = fopen("configgp.gp", "w");
	fprintf(fPtf,"f(x) = 2 + cos(exp(x) - 2) -exp(x)\nset arrow from %f,graph(0,0) to %f,graph(1,1) nohead",x0,x0);
	fclose(fPtf);

}

float f(float x){
	float res = 2.0 + cos(exp(x) - 2.0) - exp(x);
	return res;
}

float bis(float a, float b, float pres){
	//chequando que el rango sea valido
	if(f(a)*f(b) > 0 || a > b){
		printf("\nRango invalido, intentar de nuevo\n");
		main();
	}
	
	while ((b - a) > pow(10,-pres)){
		float c0 = 0.5*(a+b);	
		if(f(c0) > 0){
			a = c0;
			continue;
		}
		if(f(c0) < 0){
			b = c0;
			continue;
		}
		
	}
	return 0.5*(a+b);
	
}




		
