set terminal png
set output "test.png"
set xrange[-0.001:0.001]
set yrange[0.9999:1.0001]
plot "./data.txt" u 3:1 , "./data.txt" u 3:2
