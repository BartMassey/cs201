#!/bin/sh
cat <<'EOF' |
set terminal png;
set output "avg.png";
plot "avg.dat" using 1, '' using 2 with lines, '' using 3 with lines;
EOF
gnuplot
