set autoscale
unset log 
unset label
set xtic auto
set ytic auto
set xr [-1.0:1.0]
set yr [-1.0:1.0]
set xzeroaxis
set yzeroaxis
set style line 1 \
    linecolor rgb '#0060ad' \
    linetype 1 linewidth 2 \
    pointtype 7 pointsize 1.5
plot "qubit.dat" with linespoints notitle linestyle 1