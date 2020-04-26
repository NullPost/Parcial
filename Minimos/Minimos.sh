#!/bin/bash
gcc minimoscuad.c -o min -lm
./min
printf "\nset xrange [1:10]\nset xlabel 'Semanas'\nset title 'Precio de gasolina por semana'\nset ylabel 'Valor de gasolina'" >> configgp.gp
printf "\nplot f(x)" >> configgp.gp
printf "\nreplot 'semanas.dat'" >> configgp.gp
gnuplot -p "configgp.gp"
rm configgp.gp

