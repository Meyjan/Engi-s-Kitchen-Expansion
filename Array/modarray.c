/* Nama Kelompok	: Jangan Skip Ujay */
/* NIM/Nama			: 13516080/Putra Hardi Ramadhan, 13517059/Nixon Andhika, 13517116/Ferdy Santoso, 13517131/Jan Meyer Saragih, 13517137/Vincent Budianto */
/* Nama file 		: modarray.h */
/* Topik			: Tugas Besar IF2110 - Algoritma dan Struktur Data */
/* Tanggal			: 26 November 2018 */
/* Deskripsi		: */

#include "modarray.h"
#include <string.h>
#include <stdio.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void CreateEmptyArray (TabInt *T)
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
{
	//KAMUS LOKAL
	int i = 0;

	//ALGORITMA
	for(i = 1; i < IdxMax+1; i++){
		No(*T, i) = -1;
		FakeStrCpy(Food(*T, i), "");
		Kesabaran(*T, i) = -1;
	}
	Neff(*T) = 0;
}

IdxType GetFirstIdxArray (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
{
	//KAMUS LOKAL

	//ALGORITMA
	return (IdxMin);
}
IdxType GetLastIdxArray (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
{
	//KAMUS LOKAL

	//ALGORITMA
	return (Neff(T));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmptyArray (TabInt T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
{
	//KAMUS LOKAL

	//ALGORITMA
	return (Neff(T) == 0);
}
boolean IsFullArray (TabInt T)
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
{
	//KAMUS LOKAL

	//ALGORITMA
	return (Neff(T) == IdxMax);
}

void TulisIsiArray (TabInt T)
/* Proses : Menuliskan isi tabel dengan traversal */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah */
/*      Jika T kosong : Hanya menulis "Tabel kosong" */
/* Contoh: Jika isi Tabel: [1, 20, 30, 50]
   Maka tercetak di layar:
   [1]1
   [2]20
   [3]30
   [4]50 */
{
	//Kamus
	IdxType i;

	//Algoritma
	if (IsEmptyArray(T) == true)
	{
		printf ("Tabel kosong\n");
	}
	else
	{
		for (i = GetFirstIdxArray(T); i <= GetLastIdxArray(T); i++)
		{
			printf("[%d] %-15d. %-15s %-15d\n", i, No(T,i), Food(T,i), Kesabaran(T,i));
		}
	}
}

void DelEli (TabInt *T, IdxType i, ElType * X)
/* Menghapus elemen ke-i tabel tanpa mengganggu kontiguitas */
/* I.S. Tabel tidak kosong, i adalah indeks efektif yang valid */
/* F.S. X adalah nilai elemen ke-i T sebelum penghapusan */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
/* Proses : Geser elemen ke-i+1 s.d. elemen terakhir */
/*          Kurangi elemen efektif tabel */
{
	//Kamus
	IdxType j;
 	//Algoritma
	*X = Elmt(*T, i);
	if (IsEmptyArray(*T) == false)
	{
		for(j = i; j < GetLastIdxArray(*T); j++)
		{
			Elmt(*T, j) = Elmt(*T, (j + 1));
		}
		Neff(*T) -= 1;
		No(*T,j) = -1;
		FakeStrCpy(Food(*T,j),"");
		Kesabaran(*T,j) = -1;
	}
}

void KurangSabarArray(TabInt *O, int *Life)
/* I.S. Q terdefinisi, mengurangi kesabaran sebanyak 1 satuan */
/* F.S. Kesabaran customer berkurang satu */
{

	//KAMUS LOKAL
	ElType X;

	//ALGORITMA
	if (IsEmptyArray(*O))
	{
		//do nothing
	}
	else
	{
		int i = GetFirstIdxArray(*O);
		while(i <= GetLastIdxArray(*O))
		{
			Kesabaran(*O,i)--;
			if (Kesabaran(*O,i) == 0)
			{
				DelEli(O,i,&X);
			}
			i++;
		}
	}
}
