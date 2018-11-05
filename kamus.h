/* Nama Kelompok	: Jangan Skip Ujay */
/* NIM/Nama			: 13516080/Putra Hardi Ramadhan, 13517059/Nixon Andhika, 13517116/Ferdy Santoso, 13517131/Jan Meyer Saragih, 13517137/Vincent Budianto */
/* Nama file 		: kamus.h */
/* Topik			: Tugas Besar IF2110 - Algoritma dan Struktur Data */
/* Tanggal			: 26 November 2018 */
/* Deskripsi		: Definisi Modul Kamus */

#ifndef kamus_H
#define kamus_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "modboolean.h"
#include "modjam.h"			// digunakan untuk menyimpan waktu saat save
#include "modpoint.h"			// digunakan untuk merepresentasikan posisi
#include "modarray.h"			// digunakan untuk merepresentasikan pesanan (order)
#include "modmatriks.h"		// digunakan untuk merepresentasikan ruangan
#include "modmesinkar.h"		// digunakan untuk membaca informasi dari file eksternal, membaca command dari user dan membaca state permainan yang pernah disimpan
#include "modmesinkata.h"		// digunakan untuk membaca informasi dari file eksternal, membaca command dari user dan membaca state permainan yang pernah disimpan
#include "modqueue.h"			// digunakan untuk merepresentasikan antrian pelanggan
//#include "modprioqueue.h"	// digunakan untuk merepresentasikan antrian pelanggan
#include "modstacks.h"			// digunakan untuk merepresentasikan tumpukan makanan di tangan dan nampan
#include "modlistlinier.h"		// digunakan untuk mengimplementasikan graf
#include "modtree.h"			// digunakan untuk merepresentasikan resep
#include "modgraph.h"			// digunakan untuk menghubungkan bagian-bagian dari peta agar terbentuk satu peta besar

/* ********** Definisi ********** /
boolean.h
	#define true 1
	#define false 0
jam.h
point.h
array.h
	Indeks maksimum array, sekaligus ukuran maksimum array dalam C
	#define IdxMax 100
	Indeks minimum array
	#define IdxMin 1
	Indeks tak terdefinisi
	#define IdxUndef -999
matriks.h
	Ukuran minimum dan maksimum baris dan kolom
	#define BrsMin 1
	#define BrsMax 100
	#define KolMin 1
	#define KolMax 100
mesinkar.h
	#define MARK '.'
mesinkata.h
	#define NMax 50
	#define BLANK ' '
queue.h
	#define Nil 0
stackt.h
	#define Nil 0
	#define MaxEl 10
listlinier.h
	#define Nil NULL
tree.h
graph.h
*/

/* ********** Notasi Akses ********** /
boolean.h
jam.h
	#define Hour(J)		(J).HH
	#define Minute(J)	(J).MM
	#define Second(J)	(J).SS
point.h
	#define Absis(P)	(P).X
	#define Ordinat(P)	(P).Y
array.h
	#define Neff(T)		(T).Neff
	#define TI(T)		(T).TI
	#define Elmt(T,i)	(T).TI[(i)]
matriks.h
	#define Name(M)		(M).Name
	#define NBrsEff(M)	(M).NBrsEff
	#define NKolEff(M)	(M).NKolEff
	#define Elmt(M,i,j)	(M).Mem[(i)][(j)]
mesinkar.h
mesinkata.h
queue.h
	#define Head(Q)		(Q).HEAD
	#define Tail(Q)		(Q).TAIL
	#define InfoHead(Q)	(Q).T[(Q).HEAD]
	#define InfoTail(Q)	(Q).T[(Q).TAIL]
	#define MaxEl(Q)	(Q).MaxEl
stackt.h
	#define Top(S)		(S).TOP
	#define InfoTop(S)	(S).T[(S).TOP]
listlinier.h
	#define Info(P)		(P)->info
	#define Next(P)		(P)->next
	#define First(L)	(L).First
tree.h
graph.h
*/
/* ********** TIPE BENTUKAN STAT PEMAIN  ********** */
typedef struct {
	char name[12];		//nama pemain
	int money;			//uang dalam game
	int life;			//nyawa dalam game
	int time;			//waktu dalam game
} Stat;
	#define Name(P)		(P).name[12]
	#define Money(P)	(P).money
	#define Life(P)		(P).life
	#define Time(P)		(P).time

/* ********** Kamus Umum  ********** */
extern JAM waktu;			//waktu saat melakukan save
extern POINT pos;			//posisi player
extern TabInt order;		//pesanan pengunjung
extern MATRIKS room1;		//ruangan 1
extern MATRIKS room2;		//ruangan 2
extern MATRIKS room3;		//ruangan 3
extern MATRIKS kitchen;		//ruangan kitchen
//extern char CC;			
//extern boolean EOP;		
//extern boolean EndKata;	
//extern Kata CKata;		
extern Queue antrian;		//antrian pengunjung
extern Stack food;			//makanan pada nampan (maks 5 1x jalan)
extern Stack hand;			//makanan pada tangan (maks 5 1x jalan)
extern List graf;			//list untuk menyambungkan ruangan
extern Stat s;				//status pemain

#endif
