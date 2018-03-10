reset
set ylabel 'time(sec)'
set style fill solid
set title 'performance comparison'
set term png enhanced font 'Verdana,10'
set output 'runtime.png'

plot [:][:0.250]'output.txt' using 2:xtic(1) with histogram title 'original', \
'' using 3:xtic(1) with histogram title 'optimized'  , \
'' using 4:xtic(1) with histogram title 'hash'       , \
'' using 5:xtic(1) with histogram title 'trie'       , \
'' using ($0-0.43):(0.1):2 with labels title ' ' textcolor lt 1, \
'' using ($0-0.43):(0.12):3 with labels title ' ' textcolor lt 2, \
'' using ($0-0.43):(0.14):4 with labels title ' ' textcolor lt 3, \
'' using ($0-0.43):(0.16):5 with labels title ' ' textcolor lt 4

