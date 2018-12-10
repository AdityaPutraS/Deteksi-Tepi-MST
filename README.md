# Deteksi-Tepi-MST
**Nama    : Aditya Putra Santosa**<br />
**NIM     : 13517013**<br />
**Jurusan : Teknik Informatika**<br />

Program Deteksi Tepi Citra Digital menggunakkan pendekatan Minimum Spanning Tree<br>

### Contoh hasil program<br>
Before<br>
![before](gambar/itb.png)<br>
After<br>
![after](hasil/itb.png)

## Compile
Compile program dengan command
```
g++ -Wall -g -I. src/disjointSetUnion.cpp src/edgeMST.cpp src/graf.cpp main.cpp -o main.out `pkg-config --cflags --libs opencv`
```
Lalu run program dengan membuka main.out melalui terminal<br>
  
Program ini membutuhkan library OpenCV agar bisa dicompile<br>

### Kontak
Jika ada masalah, bisa ditulis di bagian **Issue** di repo ini, atau bisa juga dengan mengontak saya di:<br />
    - **Line  : adityaputrasantosa** <br />
    - **Email : adityaputra159@gmail.com**<br />
