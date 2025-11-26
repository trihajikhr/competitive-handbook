---
obsidianUIMode: preview
note_type: Book Theory
judul_materi: This is a Better Way to Understand Recursion
sumber: youtube.com
date_learned: 2025-05-28T21:06:00
tags:
  - recursion
---

#recursion 

---
# This is a Better Way to Understand Recursion
Materi: [This is a Better Way to Understand Recursion - YouTube](https://www.youtube.com/watch?v=Q83nN97LVOU&pp=ygUbaG93IHRvIHVuZGVyc3RhbmQgcmVjdXJzaW9u)

Orang-orang suka bercanda tentang rekursi. Seperti:
*Untuk memahami rekursi, pertama-tama pahami apa itu rekursi*.

Oleh karena itu, mari kita perjelas apa itu rekursi dengan cara yang lebih menarik. Sebenarnya kita semua mungkin tahu bahwa rekursi adalah *fungsi yang memanggil dirinya sendiri*. Tapi sebenarnya tidak sesederhana memanggil fungsi dirinya sendiri berkali-kali.

Yahhh, aku memiliki sebuah film yang akan menjelaskan rekursi dengan cara yang mudah, yaitu film *Inception*. Tapi tenang saja, jika kamu belum pernah menontonya, aku akan menjelaskanya disini.

## 🎬 1 | Analogi Inception: Dunia di dalam dunia

Dalam film _Inception_, ada konsep mimpi di dalam mimpi. Ketika seseorang tertidur, mereka bisa masuk ke mimpi, lalu tidur lagi dalam mimpi itu dan masuk ke mimpi lainnya, dan seterusnya... **Sampai akhirnya ada cara untuk "keluar" dari mimpi terdalam dan kembali ke dunia nyata.**

Alex menggunakan analogi ini untuk menjelaskan **rekursi**:

> Fungsi rekursif seperti seseorang yang masuk ke mimpi (memanggil dirinya sendiri), hingga pada titik tertentu (base case), dia bangun satu per satu sampai kembali ke dunia nyata (keluar dari rekursi).

---

## 🔄 2 | Apa itu Rekursi?

Rekursi adalah ketika sebuah fungsi memanggil dirinya sendiri untuk menyelesaikan versi yang lebih kecil dari masalah yang sama.

Contohnya:

```cpp
int factorial(int n) {
    if (n == 1) return 1;
    return n * factorial(n - 1);
}
```

- `factorial(5)` → `5 * factorial(4)`
    
- `factorial(4)` → `4 * factorial(3)`
    
- ...
    
- Sampai `factorial(1)` → 1 → dan semua hasilnya di-_unwind_ kembali ke atas.
    

---

## ⛔ 3 | Base Case adalah Kunci!

Dalam _Inception_, kalau tidak ada cara untuk keluar dari mimpi, kamu akan terus terjebak.

Begitu juga dalam rekursi: **tanpa base case, kamu akan mengalami infinite loop dan stack overflow.**

```cpp
if (n == 1) return 1; // base case
```

Base case itu seperti totem di Inception — penanda bahwa kamu kembali ke kenyataan.

---

## 🧱 4 | Stack Memory & Call Stack

Rekursi bekerja menggunakan struktur **stack**.

Setiap kali fungsi memanggil dirinya sendiri, ia menumpuk di stack memory seperti ini:

```
factorial(5)
 └── factorial(4)
      └── factorial(3)
           └── factorial(2)
                └── factorial(1)
```

Ketika base case tercapai, hasil mulai dihitung dan dikembalikan satu per satu.

---

## 🧠 5 | Cara Paham Rekursi: “Think like the computer”

Alex menganjurkan untuk **berhenti berpikir dari atas ke bawah**, tapi dari **base case ke atas**.

Coba pahami dari contoh kecil:

```cpp
factorial(2) = 2 * factorial(1)
             = 2 * 1 = 2
```

Kemudian naik ke `factorial(3) = 3 * 2 = 6`, dst.

---

## 📚 6 | Rekursi ≠ Selalu Solusi Terbaik

Kadang-kadang rekursi **terlihat elegan**, tapi tidak efisien, contohnya pada **Fibonacci**:

```cpp
int fib(int n) {
    if (n <= 1) return n;
    return fib(n-1) + fib(n-2);
}
```

- Ini sangat lambat karena banyak submasalah dihitung berulang.
    
- Solusinya: **memoization** atau pakai versi iteratif.
    

---

## ✅ 7 | Tips Alex Hyett: Belajar Rekursi

1. Pahami base case terlebih dahulu.
    
2. Gunakan kertas untuk menggambar pohon rekursi.
    
3. Jangan takut untuk melacak fungsi manual.
    
4. Pakai debugger untuk melihat bagaimana stack berubah.
    
5. Jangan langsung ke soal sulit; mulai dari factorial, Fibonacci, atau jumlah array.
    

---

## 🧾 Kesimpulan (Gaya Alex Hyett)

> Rekursi bukan sihir. Ini hanyalah fungsi yang menyelesaikan bagian kecil dari masalah dan percaya bahwa dirinya sendiri bisa menangani sisanya.

Bayangkan kamu seperti Cobb di _Inception_, masuk ke dalam mimpi demi mimpi. Tapi jangan lupa — kamu **butuh base case** untuk bisa bangun.


