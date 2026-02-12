---
obsidianUIMode: preview
note_type: book theory
judul_materi: Arithmetic Priority
sumber:
  - google.com
date_learned: 2026-01-28T22:47:00
tags:
  - number-theory
---
Link Sumber: [Operator precedence](https://www.promotic.eu/en/pmdoc/ScriptLangs/VBScript/Operat/PrioritsOfOperators.htm)

---

> [!IMPORTANT]
>  
# Arithmetic Priority

Prioritas perhitungan (*order of operations*) adalah aturan yang menentukan urutan pengerjaan operasi dalam suatu ekspresi agar hasilnya tidak ambigu. Operasi di dalam tanda kurung dikerjakan lebih dahulu; tanpa kurung, operasi dikerjakan menurut prioritas: pemangkatan, lalu perkalian/pembagian (kiri-ke-kanan), lalu penjumlahan/pengurangan (kiri-ke-kanan). Pemangkatan bersifat asosiatif kanan-ke-kiri.

## 1. Aturan urutan operasi

1. Operasi di dalam tanda kurung diselesaikan terlebih dahulu. Jika ada beberapa tingkat kurung, kerjakan dari dalam ke luar.
    
2. Pemangkatan $a^b$ dikerjakan setelah semua kurung yang relevan. Pemangkatan bertingkat bersifat kanan-ke-kiri: $a^{b^c}=a^{(b^c)}$.
    
3. Perkalian dan pembagian ($\times, \div$) memiliki prioritas yang sama; ketika keduanya muncul dalam satu urutan, selesaikan dari kiri ke kanan. Contoh: $8\div4\times2=(8\div4)\times2$.
    
4. Penjumlahan dan pengurangan ($+,\ -$) memiliki prioritas yang sama; selesaikan dari kiri ke kanan. Contoh: $10-3+2=(10-3)+2$.
## 2. Contoh singkat

- $3+4\times2=3+(4\times2)=11$.
    
- $(3+4)\times2=7\times2=14$.
    
- $2^{3^2}=2^{(3^2)}=512$.
    
- $8\div4\times2=(8\div4)\times2=4$.
    
- $-3^2=-(3^2)=-9$, sedangkan $(-3)^2=9$.
    
- $\dfrac{1+2}{3+4}=\dfrac{3}{7}$ (garis pecahan memperlakukan pembilang/penyebut sebagai kelompok).
    

## 3. Catatan khusus dan praktik aman

- Perkalian dan pembagian tidak memiliki prioritas berbeda satu sama lain; urutkan sesuai kemunculan dari kiri ke kanan.
    
- Penjumlahan dan pengurangan sama; urutkan kiri-ke-kanan.
    
- Unary minus dieksekusi setelah pemangkatan pada notasi umum, sehingga untuk mengkuadratkan bilangan negatif gunakan kurung: $(-x)^2$.
    
- Garis pecahan (*fraction bar*) berfungsi seperti tanda kurung; seluruh pembilang dan penyebut diperlakukan sebagai kelompok.
    
- Notasi perkalian implisit (mis. $2x$ atau $2(1+3)$) sebaiknya dijelaskan dengan kurung bila bercampur dengan pemangkatan atau fungsi untuk menghindari ambiguitas.
    

## 4. Rekomendasi praktis  
Gunakan tanda kurung secara eksplisit untuk menyatakan maksud ketika ada potensi kebingungan. Untuk kode program, tuliskan struktur eksplisit (kurung) agar urutan operasi tidak bergantung pada implementasi atau aturan parsing bahasa.