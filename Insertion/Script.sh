#!/bin/bash

gcc -c tiempo.c -o tiempo.o
gcc tiempo.o Insercion_TIME.c -o INSERCION_TIME

for N in { 1000 2000 3000 4000 5000 8000 10000 50000 100000 150000 200000 300000 400000 500000 600000 700000 800000 900000 1000000 1500000 2000000 }
do
    echo "Corriendo Insertion-Sort con $N datos" 
    ./INSERCION_TIME $N < numeros10millones.txt >> INSERCION_TIME.txt
    echo "Terminado Insertion-Sort con $N datos" 
done
