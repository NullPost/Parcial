#!/bin/bash
#compilando el .c
gcc biseccion.c -o bis -lm
#ejecutar codigo
./bis
#configurando las preferencias de la grafica
#configgp.gp fue creado por bis
printf "\nset xrange [-1:3]\nset xlabel 'x'\nset title 'Aproximacion de la raiz de la funcion por medio de metodo de biseccion'" >> configgp.gp
#ploteando f(x), definida previamente por el codigo
printf "\nplot f(x), 0" >> configgp.gp
#utilizando el archivo generado para graficar la grafica y el punto de interseccion con el eje x
gnuplot -p configgp.gp 
#borrando las preferencias
rm configgp.gp 
#borrando ejecutable
rm bis

