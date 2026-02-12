---
obsidianUIMode: preview
note_type: latihan
latihan: Hitung Elemen Unik dalam Array
sumber: Google.com, AI
tags:
  - data-structure
  - array
date_learned: 2025-06-13T21:43:00
---
---
# Hitung Elemen Unik dalam Array
🔥 WUHHH!! Semangatmu benar-benar **tak tergoyahkan**!! Saatnya naik level lagi 😎

---

## 💥 Tantangan Berikutnya: "Hitung Elemen Unik dalam Array"

### 🧠 Deskripsi Soal:

Buatlah sebuah program C++ yang:

- Menerima sebuah `std::array` berisi bilangan bulat (boleh ada yang duplikat).
    
- Mengembalikan **jumlah elemen unik** (tidak dihitung duplikatnya).
    
- Boleh menggunakan `std::set`, atau logika hash manual (`array<int, 101> hash` misalnya jika datanya kecil).
    

---

### 📥 Contoh Input:

```cpp
array<int, 10> data = {3, 1, 2, 3, 2, 4, 5, 5, 6, 7};
```

### 📤 Contoh Output:

```
Jumlah elemen unik: 7
```

> Karena elemen uniknya: 1, 2, 3, 4, 5, 6, 7

---

### 🎯 Tujuan:

- Melatih penggunaan struktur data untuk frekuensi atau unik-elemen.
    
- Boleh `template` jika kamu mau fleksibelin array-nya 💡
    

---

Kalau siap, langsung GASKAN kode legendamu!!  
Aku standby buat evaluasi dan tantangan lanjutan 🫡

## Jawaban
Kode program untuk jawabanku adalah sebagai berikut:

```cpp
#include<iostream>
#include<array>
#include<unordered_map>
using namespace std;

template <typename T, size_t N>
int uniqueChar(const array<T, N>& data){
    unordered_map<int, int> freq;

    for(size_t i=0; i<N; i++){
        freq[data[i]]++;
    }

    int count=0;
    for(size_t i=0; i<N; i++){
        if(freq[i]>0) count++;
    }

    return count;
}

int main() {
    array<int, 10> data = {3, 1, 2, 3, 2, 4, 5, 5, 6, 7};
    int rest = uniqueChar(data);

    cout << "Jumlah elemen unik: " << rest << "\n";
    return 0;
}
```

## Editorial
🔥🔥🔥 Kamu benar-benar **gasss poll!**  
Kodenya udah nyaris mantap — pakai `unordered_map`, readable, dan efektif untuk counting! Tapi... ada **satu jebakan kecil** yang kamu terlewat 😏

---

### 🕵️‍♂️ Masalahnya:

Loop **pengecekan `freq[i] > 0`** kamu **salah arti**.

```cpp
for(size_t i=0; i<N; i++){
    if(freq[i]>0) count++;
}
```

👆 Ini salah, karena `i` adalah **indeks array**, bukan elemen uniknya.  
Misalnya `freq[1] = 2` → berarti nilai `1` muncul dua kali, tapi kamu ngecek `freq[0], freq[1], ..., freq[9]`, padahal yang benar kamu harus **hitung banyak key unik** di `unordered_map`.

---

### ✅ Perbaikan (cukup ganti bagian akhir):

```cpp
int count = freq.size();
```

Kenapa? Karena `unordered_map` hanya menyimpan **key unik**, jadi langsung aja ambil ukurannya.

---

### 🔧 Perbaikan Lengkap:

```cpp
template <typename T, size_t N>
int uniqueChar(const array<T, N>& data){
    unordered_map<T, int> freq;

    for(const auto& x : data){
        freq[x]++;
    }

    return freq.size();
}
```

- `unordered_map` sangat efisien untuk operasi frekuensi seperti ini, rata-rata O(1) per operasi.
    
- Implementasi ini sudah optimal dan idiomatik untuk C++ modern.
- Naming `uniqueChar()` boleh diganti jadi `countUniqueElements()` kalau mau lebih representatif secara umum (karena kamu pakai array of `int` di sini, bukan `char`, tapi itu hanya kosmetik).
---

### 🧪 Output:

```
Jumlah elemen unik: 7
```

✅ Sesuai yang diharapkan!

---

### 🏁 Status:

💯 Kamu lulus dengan minor revisi!  
Bersiaplah untuk tantangan berikutnya... **yang lebih menguji kekuatan hatimu!**

---

Mau lanjut tantangan berikutnya? Atau mau kuangkat ke level _"penyortiran dengan comparator custom"_? 😈