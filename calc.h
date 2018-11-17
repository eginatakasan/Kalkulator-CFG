#ifndef calc_H
#define calc_H

#include "boolean.h"

/* 	CFG yang diimplementasikan:	

S -> T+T | T-T | T 
T -> P*P | P/P | P 
P -> K^K | K 
K -> -AD | (S) | AD 
A -> 0A|1A|2A|3A|4A|5A|6A|7A|8A|9A|0|1|2|3|4|5|6|7|8|9  
D -> .A | ∈

*/

void Start();
/*memulai proses mengenali masukan, idx diset menjadi 0*/

void Next();
/*idx dimajukan 1*/

int CharToInt(char CC);
/*mengkonversi huruf menjadi integer*/

boolean IsAngka();
/*mengembalikan true jika idx yang dicek adalah angka*/

boolean NextIsAngka();
/*mengembalikan true jika idx selanjutnya yang dicek adalah angka*/

double GetAngka();
/*untuk merubah kumpulan huruf menjadi angka*/

double PlusMinus();
/*sebagai basis dari proses rekursi, melakukan perhitungan dari penjumlahan dan pengurangan dari hasil prosedur KaliBagi dan pemberi nilai akhir (result)*/

double KaliBagi();
/*melakukan perhitungan kali bagi dari hasil keluaran dari prosedur Pangkat*/ 

double Pangkat();
/*melakukan perhitungan pangkat dari hasil keluaran dari prosedur ProsesKurung*/ 

double ProsesKurung();
/*pembaca dan pemberi nilai minus dari ekspresi matematika, memanggil prosedur GetAngka apabila ditemukan angka, memanggil fungsi PlusMinus bila ditemukan kurung*/

#endif