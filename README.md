# Deteksi-Tepi-MST
Program Deteksi Tepi Citra Digital menggunakkan Minimum Spanning Tree<b>

## Compile
Compile program dengan command
```
g++ -Wall -g -I. src/disjointSetUnion.cpp src/edgeMST.cpp src/graf.cpp main.cpp -o main.out `pkg-config --cflags --libs opencv`
```
Lalu run program dengan membuka main.out melalui terminal<b>
Program ini membutuhkan library OpenCV agar bisa dicompile<b>

Segala bug / issue pada program ini dapat dilaporkan di kolom issue repo ini.
