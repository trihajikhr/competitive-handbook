---
obsidianUIMode: preview
note_type: Book Theory
judul_materi: You WILL Understand Recursion After Watching This
sumber: youtube.com
date_learned: 2025-05-28T21:37:00
tags:
  - recursion
---
#recursion 

---
# You WILL Understand Recursion After Watching This
Kali ini aku akan menjelaskan apa itu recursion. 

Recursion, atau rekursi, atau rekursif, adalah fungsi yang memanggil dirinya sendiri. Biasanya digunakan dalam perulangan seperti mencari nilai dari faktorial, fibonacci, dan semacamnya. Algoritma seperti binary search, merge sort, dan graph juga sering menggunakan teknik rekursi.

Jadi kali ini, aku akan menjelaskan bagaimana cara kerja rekursi dengan cara yang lebih ilustratif:

Tonton video ini: [You WILL Understand Recursion After Watching This](https://www.youtube.com/watch?v=DUC1qg7ZaRg&ab_channel=b001)

Katakanlah aku memiliki sebuah fungsi rekursi untuk menghitung nilai faktorial dari $n$. Semisal seperti ini kodenya (C++):

```cpp
#include<iostream>
using namespace std;

int faktorial(int n){
	if(n==1) return 1;
	return n * faktorial(n-1);
}

int main(){
	cout << faktorial(3);
	return 0;
}
```

Output:
```
6
```

Program ini akan menghasilkan output berupa $6$. Jadi, bagaimana cara kerjanya, dan prosesnya untuk mencapai angka 6 ini?

Untuk mengetahuinya, kita bisa membuat *pohon rekursi* untuk memperjelas bagaimana program ini bekerja.

---
![[You WILL Understand Recursion After Watching This-1.png]]

Kita memiliki sebuah fungsi rekursi, seperti diatas. Ketika kita memanggilanya, kita akan memberikan nilai $n$, yaitu $3$. Sekarang kita masukan angka 3 kedalamnya:

![[You WILL Understand Recursion After Watching This-2.png]]

Sekarang, rekursi kita akan menjadi seperti ini, karena nilai $n$ adalah 3. Sekarang fungsi sudah terpanggil, dan kita akan eksekusi setiap perintah yang ada di fungsi ini.

Pernyataan kondisional akan kita eksekusi, dan hasilnya adalah nilai $n$ yang bernilai 3. Tentu ini tidak sama dengan nilai 1, sehingga kita skip.

![[You WILL Understand Recursion After Watching This-3.png]]

Sekarang, satu baris terakhir dari fungsi kita eksekusi. Karena didalam `return` terdapat fungsi faktorial lagi yang dipanggil, sekarang kita jalankan lagi fungsi faktorial tersebut, yaitu `faktorial(2)`:

![[You WILL Understand Recursion After Watching This-4.png]]

Baris pertama dari fungsi yang baru kita panggil ini tidak terpenuhi, sehingga kita skip:

![[You WILL Understand Recursion After Watching This-5.png]]

Sekarang, kita panggil lagi fungsi `faktorial(1)`, karena fungsi ini dipanggil lagi:

![[You WILL Understand Recursion After Watching This-6.png]]

Setelah pemanggilan fungsi rekursi yang ketiga, nilai dari $n$ sekarang adalah $1$, dan nilai ini memenuhi kondisi `n == 1`. Oleh karena itu, kita return nilai `1`. 

Program kita sudah berhenti memanggil fungsi dirinya sendiri, atau mencapai *base case*, sehingga rekursi berhenti. Dan sekarang kita akan mengalikan tiap nilai-nilai yang didapat dari setiap pemanggilan rekursi.

![[You WILL Understand Recursion After Watching This-7.png]]

Maka didapat hasil berupa $3 \times 2 \times 1=6$. 

Nilai-nilai ini berasal dari nilai-nilai yang direturn oleh setiap fungsi rekursi yang dipanggil.

![[You WILL Understand Recursion After Watching This-8.png]]

---
Baiklah, semoga penjelasan ini membantumu untuk memahami lebih baik tentang apa itu rekursi dan bagaimana cara kerja rekursi. Terima kasih 😊