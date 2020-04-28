set terminal pngcairo size 720,720
#set terminal png enhanced size 720,720

# Format of the axis
if(exist("n") == 0) n = 0
set xrange [-2.0:2.0]
set yrange [-2.0:2.0]
set xlabel "x" font ", 24"
set ylabel "y" font ", 24"
set xtics 1.0 font ", 18"
set ytics 1.0 font ", 18"
set format x "%.0f"
set format y "%.0f"
set size square

inputFile  = sprintf("../result/result%05d.dat", n)
outputFile = sprintf("image/result%05d.png", n)

print outputFile
set output outputFile

al = 0.2

set cbrange [0.5:1.5]
set cblabel "w_0" font ", 24"
set cbtics 0.5 font ", 18"

set palette defined (0 '#2166AC', 1 '#4393C3', 2 '#92C5DE', 3 '#D1E5F0', 4 '#FDDBC7', 5 '#F4A582', 6 '#D6604D', 7 '#B2182B')

plot inputFile using 1:2:(0.05):3 with circles fill solid lc palette notitle

clear

n=n+1
if(n <= 500) reread
