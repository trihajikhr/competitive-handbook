---
obsidianUIMode: preview
note_type: Book Theory
judul_materi: "\r5 Simple Steps for Solving Any Recursive Problem"
sumber: youtube.com
date_learned: 2025-05-28T22:11:00
tags:
  - recursion
---
#recursion 

---
# 5 Simple Steps for Solving Any Recursive Problem

Link materi: [5 Simple Steps for Solving Any Recursive Problem - YouTube](https://www.youtube.com/watch?v=ngCos392W4w&ab_channel=Reducible)

Hari ini, kita akan berbicara tentang rekursi.

Saya pikir sebagian besar mahasiswa ilmu komputer akan setuju bahwa rekursi terasa lebih membingungkan daripada topik ilmu komputer pada umumnya.

Jadi kali ini aku akan memberikan 5 simple steps yang dapat anda gunakan untuk mengatasi masalah rekursi apapun. Dan mudah-mudahan langkah-langkah ini akan membantu anda menyadari bahwa pada kenyataanya, rekursif tidak seburuk itu.

Saya akan menunjukan kepada anda cara menerapkan langkah-langkah ini dalam konteks penyelesaian tiga masalah rekursif tertentu yang masing-masing secara progresif lebih sulit daripada sebelumnya. Jadi, pastikan anda mempelajari materi ini dari awal hingga akhir.

# Problem 1
Katakanlah kita memiliki soal seperti ini:

> Buatlah fungsi rekursif yang akan menjumlahkan semua bilangan integer non-negatif hingga $n$.

Berikut adalah hasil dari setiap nilai $n$ sebelum kita mulai mengimplementasikanya:
$$sum(0) ⇾0$$
$$sum(1)⇾1$$
$$sum(4)⇾(1+2+3+4)⇾10$$
$$sum(5)⇾(1+2+3+ \dots +n)$$
Beberapa dari kalian mungkin tahu bagaimana melakukan operasi ini dengan cara perulangan atau matematikal seperti cara-cara berikut:

```cpp
// cara iteratif
int sum(int n) {
    int sum=0;
    for(int i=1;i<=n;i++){
    	sum+=i;
    }
    return sum;
}
```

```cpp
// cara matematis
int sum(int n) {
	return n * (n+1)/2;
}
```

Namun, jika kita menggunakan cara rekursif, bagaimana cara melakukanya?

Sederhana, *rekursi adalah tentang mengambil masalah, dan menyelesaikanya menggunakan versi masalah yang lebih sederhana*.

Langkah pertama dalam menyelesaikan masalah secara rekursif, mengharuskan anda menanyakan kepada diri sendiri, 

> **Apa input paling sederhana, yang mungkin untuk fungsi tersebut.**



