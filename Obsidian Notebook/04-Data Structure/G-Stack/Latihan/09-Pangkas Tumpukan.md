---
obsidianUIMode: preview
note_type: latihan
latihan: Pangkas Tumpukan
sumber: Google.com, AI
tags:
  - stack
  - data-structure
date_learned: 2025-06-15T21:47:00
---
---
# 🧠 Soal Stack 9 – Pangkas Tumpukan

**Deskripsi:**  
Diberikan sejumlah bilangan yang dimasukkan ke dalam stack, lalu diminta untuk memangkas stack sebanyak `k` elemen dari atas. Cetak semua elemen yang **tersisa di stack**, dari atas ke bawah.

---

**Format Input:**  
Baris 1: dua bilangan bulat `n` dan `k` (`0 ≤ k ≤ n ≤ 100`)  
Baris 2: `n` bilangan bulat (dari bawah ke atas stack)

**Format Output:**  
Cetak semua isi stack setelah `k` elemen teratas di-_pop_, satu per baris (dari atas ke bawah). Jika kosong, cetak `KOSONG`.

---

**Contoh 1**  
Input:

```
5 2
10 20 30 40 50
```

Output:

```
30
20
10
```

**Contoh 2**  
Input:

```
3 3
7 8 9
```

Output:

```
KOSONG
```

---

**Petunjuk:**

1. Gunakan `stack<int>`
    
2. Baca semua angka dan `push` satu per satu
    
3. Lakukan `k` kali `pop()`
    
4. Cetak sisa isi stack
    

---

Kalau kamu sudah siap lanjut ke soal lainnya, tinggal bilang saja — bisa versi lanjutan, visual, bahkan berbentuk game kecil. Semangat terus!

## Jawabanku
Berikut adalah jawabanku yang lebih fokus ke outputnya, lewati prosesnya ya kan haha:

```cpp
#include<iostream>
#include<stack>
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    stack<int> angka;
    
    for(int i=0, x; i<n; i++){
        cin >> x;
        if(i<=k) angka.push(x);
    }
    
    if(n==k){
        cout << "KOSONG\n";
        return 0;
    }

    while(!angka.empty()){
        cout << angka.top() << "\n";
        angka.pop();
    }

    return 0;
}
```

# Editorial
Berikut adalah **editorial lengkap** dari kode C++ milikmu untuk soal “Pangkas Tumpukan”:

---

## 🧾 Judul: Pangkas Tumpukan (Versi: Out-of-Spec)

### 📌 Deskripsi Kode

Program ini membaca `n` bilangan bulat dan sebuah bilangan `k`. Dari ke-`n` bilangan tersebut, hanya `k+1` bilangan pertama yang dimasukkan ke dalam stack. Jika jumlah `n` sama dengan `k`, maka stack dianggap kosong, dan program mencetak `"KOSONG"`. Jika tidak, program mencetak isi stack dari atas ke bawah.

---

## 🔍 Penjelasan Baris per Baris

```cpp
int n, k; cin >> n >> k;
```

- Membaca jumlah elemen `n` dan jumlah elemen yang akan “dibuang” (dipangkas) `k`.
    

```cpp
stack<int> angka;
```

- Membuat stack `angka` untuk menyimpan bilangan bulat.
    

```cpp
for(int i=0, x; i<n; i++){
    cin >> x;
    if(i<=k) angka.push(x);
}
```

- Membaca `n` buah angka, tetapi hanya memasukkan ke stack jika `i <= k` (yaitu, hanya `k+1` angka pertama).
    
- Artinya, elemen ke-`k+1` sampai ke-`n-1` _tidak dimasukkan sama sekali_ ke stack.
    

```cpp
if(n==k){
    cout << "KOSONG\n";
    return 0;
}
```

- Jika jumlah input sama dengan jumlah yang dibuang, maka tidak akan ada yang dimasukkan ke stack (karena `i <= k` hanya valid sampai `i==k` → artinya hanya `k+1` elemen dimasukkan).
    
- Dalam kasus ini, program langsung mencetak `"KOSONG"`.
    

```cpp
while(!angka.empty()){
    cout << angka.top() << "\n";
    angka.pop();
}
```

- Jika stack tidak kosong, cetak semua isi stack dari atas ke bawah.
    

---

## 📉 Analisis

### 🔧 Kompleksitas Waktu:

- **O(n)** untuk pembacaan input.
    
- **O(k)** untuk mencetak isi stack.
    

### 💡 Catatan Kritis:

- **Logika program tidak sesuai dengan deskripsi soal aslinya.**  
    Soal meminta kita untuk:
    
    1. Menyimpan _seluruh_ `n` elemen ke stack.
        
    2. Kemudian melakukan `k` kali `pop()`.
        
- Tetapi kode ini justru hanya memasukkan `k+1` elemen pertama dan **mengabaikan** sisanya.
    
- Dalam beberapa kasus, hasil akhirnya mungkin kebetulan cocok, tapi secara logika, pendekatan ini tidak bisa diandalkan secara umum.
    

---

## ✅ Alternatif Perbaikan (Sesuai Spesifikasi Soal Asli)

Untuk membuat kode sesuai spesifikasi asli, seharusnya:

```cpp
for(int i=0, x; i<n; i++){
    cin >> x;
    angka.push(x);
}

while(k-- && !angka.empty()){
    angka.pop();
}
```

---

## 🧠 Penutup

Meskipun pendekatan ini bisa terlihat seperti “jalan pintas” atau upaya mengakali soal, pemahaman yang benar tetap penting terutama saat menangani struktur data dengan sifat LIFO seperti stack. Eksperimen seperti ini tetap bermanfaat untuk mengasah insting ngodingmu — asal tahu kapan harus nurut aturan, dan kapan boleh ngulik jalan alternatif. 😉

Kalau kamu mau tantangan lanjutan, bisa aku kasih soal yang lebih terbuka untuk **"diakali dengan strategi cerdas"**. Mau?