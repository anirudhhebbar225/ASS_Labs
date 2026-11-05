#!/bin/bash
echo "Enter a b c:"
read a b c
d=`expr $b \* $b - 4 \* $a \* $c`
if [ $d -gt 0 ]; then t=pos; elif [ $d -eq 0 ]; then t=zero; else t=neg; fi
case $t in
  pos)  r1=`echo "scale=2; (-($b) + sqrt($d)) / (2*$a)" | bc -l`
        r2=`echo "scale=2; (-($b) - sqrt($d)) / (2*$a)" | bc -l`
        echo "Real and distinct roots: $r1, $r2" ;;
  zero) r=`echo "scale=2; -($b) / (2*$a)" | bc -l`
        echo "Real and equal roots: $r, $r" ;;
  neg)  re=`echo "scale=2; -($b) / (2*$a)" | bc -l`
        im=`echo "scale=2; sqrt(-($d)) / (2*$a)" | bc -l`
        echo "Imaginary roots: $re + i$im, $re - i$im" ;;
esac
