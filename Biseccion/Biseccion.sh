#!/bin/bash
gcc biseccion.c -o bis -lm
./bis
printf "\nset xrange [-1:3]\nset xlabel 'x'\nset title 'Aproximacion de la raiz de la funcion por medio de metodo de biseccion'" >> configgp.gp
printf "\nplot f(x), 0" >> configgp.gp
gnuplot -p configgp.gp 
rm configgp.gp 
