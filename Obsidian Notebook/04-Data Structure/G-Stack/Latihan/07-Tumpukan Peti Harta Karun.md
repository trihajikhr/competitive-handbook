---
obsidianUIMode: preview
note_type: latihan
latihan: Tumpukan Peti Harta Karun
sumber: Google.com, AI
tags:
  - stack
  - data-structure
date_learned: 2025-06-15T21:47:00
---
---
# 🔥 Versi Game: "Tumpukan Peti Harta Karun"

Kamu adalah seorang petualang yang menemukan sebuah **gua penuh peti**. Peti disusun dalam tumpukan (stack). Kamu hanya bisa:

- `AMBIL` → mengambil peti teratas dari tumpukan dan membawanya
    
- `BUANG` → membuang peti teratas (karena jebakan)
    
- `INTIP` → melihat isi peti teratas
    
- `CEK` → cetak jumlah peti dan apakah kosong
    

---

### Format Input:

```
9
AMBIL EMAS
AMBIL PERAK
INTIP
BUANG
INTIP
BUANG
BUANG
CEK
AMBIL PERMATA
```

### Output:

```
PERAK
EMAS
TUMPUKAN KOSONG
Jumlah: 0, Kosong: YES
```

---

Kalau ini lebih fresh dan seru, kita lanjut aja ke soal ini sebagai **Stack #7** ya.

Atau... kamu mau tantangan lain kaya:

- Validasi tag HTML `<div><b></b></div>`?
    
- Simulasi rekursi faktorial dengan stack?
    
- Interpretasi bahasa mini?
    

You call the shot — biar kita lanjut dengan gaya belajar yang kamu suka! 😎

## Jawabanku

Berikut adalah jawabanku:

```cpp
#include<iostream>
#include<stack>
#include<sstream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    stack<string> harta;

    while(n--){
        string s;
        getline(cin >> ws, s);

        stringstream ss(s);
        string cmd;
        ss >> cmd;

        if(cmd=="AMBIL"){
            string rest;
            getline(ss >> ws, rest);
            harta.push(rest);
        } else if (cmd=="INTIP"){
            if(!harta.empty()) cout << harta.top() << "\n";
            else cout << "TUMPUKAN KOSONG\n";
        } else if (cmd=="BUANG"){
            if(!harta.empty()) harta.pop();
            else cout << "TUMPUKAN KOSONG\n";
        } else if (cmd=="CEK"){
            bool isi = harta.empty();
            cout << "Jumlah: " << harta.size() << ", Kosong: " << (isi ? "YES":"NO") << "\n";
        }
    }
    return 0;
}
```

# Editorial
Berikut editorial lengkap untuk program simulasi “Tumpukan Peti Harta Karun” berdasarkan kode yang kamu tulis:

---

## 1. Tujuan Program

Mensimulasikan operasi pada sebuah stack (`harta`) yang menampung nama peti (tipe `string`) dengan empat perintah:

- **AMBIL X**: menambahkan peti “X” ke puncak tumpukan.
    
- **INTIP**: menampilkan peti teratas (tanpa mengeluarkannya).
    
- **BUANG**: menghapus peti teratas.
    
- **CEK**: menampilkan jumlah peti dan status kosong/tidak.
    

---

## 2. Struktur Data & I/O

- **Stack**: menggunakan `stack<string> harta;` dari STL C++.
    
- **Fast I/O**: `ios::sync_with_stdio(false); cin.tie(nullptr);`.
    
- **Pembacaan perintah**:
    
    1. Baca `n` (jumlah perintah).
        
    2. Untuk tiap perintah, baca seluruh baris dengan
        
        ```cpp
        getline(cin >> ws, s);
        ```
        
        agar bisa menangani spasi dalam nama peti.
        
    3. Tokenisasi perintah via
        
        ```cpp
        stringstream ss(s);
        ss >> cmd;
        ```
        

---

## 3. Penanganan Masing‑Masing Perintah

1. **`AMBIL`**
    
    - Baca sisa baris (`rest`) melalui
        
        ```cpp
        getline(ss >> ws, rest);
        ```
        
    - `harta.push(rest);`
        
2. **`INTIP`**
    
    - Jika stack tidak kosong → `cout << harta.top()`.
        
    - Jika kosong → `cout << "TUMPUKAN KOSONG"`.
        
3. **`BUANG`**
    
    - Jika tidak kosong → `harta.pop()`.
        
    - Jika kosong → menulis `"TUMPUKAN KOSONG"`.
        
4. **`CEK`**
    
    - Ambil `harta.size()` dan `harta.empty()`, lalu cetak:
        
        ```plaintext
        Jumlah: <size>, Kosong: <YES/NO>
        ```
        
    - (Kode-mu menggunakan YES/NO; bisa disesuaikan ke YA/TIDAK bila diinginkan.)
        

---

## 4. Kompleksitas

- **Waktu**: O(n × L)
    
    - n = jumlah perintah
        
    - L = rata‑rata panjang string perintah (untuk parsing & push/pop)
        
- **Memori**: O(k × M)
    
    - k = maksimum jumlah peti yang disimpan pada satu waktu
        
    - M = rata‑rata panjang nama peti
        

---

## 5. Edge Cases & Robustness

- **Nama peti dengan spasi**: tertangani oleh `getline(ss >> ws, rest)`.
    
- **Perintah INTIP/BUANG saat kosong**: dicek via `empty()` untuk menghindari pop() pada stack kosong.
    
- **Output konsisten**: pastikan format `TUMPUKAN KOSONG` dan baris baru (`\n`) selalu tercetak.
    

---

## 6. Poin‑poin Pembelajaran

- Pemanfaatan **stack** untuk operasi LIFO.
    
- Teknik **robust input parsing** campuran angka dan teks (menggunakan `ws`, `getline`, dan `stringstream`).
    
- Handling **conditonal branching** untuk berbagai perintah.
    

Dengan struktur ini, kamu bisa memperluas simulasi atau mengganti jenis perintah dengan mudah—karena semua logika dispatch terpusat di satu loop utama. Semoga membantu memperdalam pemahamanmu!