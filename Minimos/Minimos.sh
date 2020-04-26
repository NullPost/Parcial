#!/bin/bash
#compilando codigo
gcc minimoscuad.c -o min -lm
#ejecutando codigo
./min
#creando preferencias para la grafica de ggnuplot
printf "\nset xrange [1:10]\nset xlabel 'Semanas'\nset title 'Precio de gasolina por semana'\nset ylabel 'Valor de gasolina'" >> configgp.gp
#graficando f(x), defninido por el codigo
printf "\nplot f(x)" >> configgp.gp
#graficando los datos con la linea calculada
printf "\nreplot 'semanas.dat'" >> configgp.gp
#utilizando todas las preferencias para graficar con gnuplot
gnuplot -p "configgp.gp"
#borrando las preferencias
rm configgp.gp

