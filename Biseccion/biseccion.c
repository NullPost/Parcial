
/* 
Autor: Mario Guerra
Compilador: gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
Compilado: gcc biseccion.c -o biseccion
Fecha: Sat Apr 25 12:03:33 CST 2020
Resumen: Encuentra x tal que 2 +cos(e^x - 2) -e^x = 0
Entrada: un rango tal que donde sabemos que x se encuentra
Salida:  una aproximacion de la raiz x, grafica de f(x) y el punto
*/

//librerias
#include <stdio.h>
#include <math.h>
//numerar los pasos de pseudocodigo
// prototipo de las funciones 
float f(float x);
float bis(float a,float b, float pres);
void main(){
	// iniciando variables
	float rangInf;
	float rangSup;
	int pres;
	// preguntarle al usuario el rango donde se encuentre la raiz, la funcion bis chequea si el rango es valido
	printf("Tenemos la funcion f(x) = 2 + cos(e^x - 2)- e^x\nIngrese un rango donde la raiz de esta funcion se encuentre (ejemplo [0,2])\n");
	printf("\nIngrese cota inferor del rango: ");
	scanf("%f", &rangInf);
	printf("Ingrese cota superior del rango: ");
	scanf("%f", &rangSup);
	// se pregunta hasta que decimal se necesita la presicion, esto es con el fin 
	// que el usuario dicte cuanto tiempo tome el programa
	printf("Ingrese hasta que decimal se requiere la presicion (numero entero, maximo 6): ");
	scanf("%d", &pres);

	float x0 = bis(rangInf, rangSup, pres);

	printf("\nMejor aproximacion: f(%.6f) = %.6f\n", x0, f(x0));

/*	GENERANDO CONFIGURACION DE GNUPLOT	*/
	FILE * fPtf;
	fPtf = fopen("configgp.gp", "w");
	fprintf(fPtf,"f(x) = 2 + cos(exp(x) - 2) -exp(x)\nset arrow from %f,graph(0,0) to %f,graph(1,1) nohead",x0,x0);
	fclose(fPtf);

}
// utilizamos esta funcion para no tener que escribir la funcion de este problema
// cada vez que es necesario
float f(float x){
	float res = 2.0 + cos(exp(x) - 2.0) - exp(x);
	return res;
}

float bis(float a, float b, float pres){
	//chequando que el rango sea valido
	//si f(a) y f(b) tienen los mismos signos el rango elegido no es apropiado
	//los calculos tambien dependen de que a < b
	if(f(a)*f(b) > 0 || a > b){
		printf("\nRango invalido, intentar de nuevo\n");
		//rango inapropiado nos regresa al inicio
		main();
	}
	//metodo de biseccion
	//si la diferencia entre a y b es menor que un rango de sensibilidad
	//despues de varios ciclos del sitema
	//los consideramos lo suficientemente parecidos para decir que la raiz 
	//es el promedio entre a y b 
	while ((b - a) > pow(10,-pres)){
		float c0 = 0.5*(a+b);
		//si f(c) es menor a cero lo hacemos la nueva cota inferior y reevaluamos el promedio
		if(f(c0) > 0){
			a = c0;
			continue;
		}
		//si f(c) es mayor a cero lo hacemos la nueva cota superior y reevaluamos el promedio
		if(f(c0) < 0){
			b = c0;
			continue;
		}
		
	}
	return 0.5*(a+b);
	
}




		
