---
obsidianUIMode: preview
note_type: tips trick
tips_trick: Apa itu Mantissa
sumber: Google.com, AI
tags:
  - tipe-data
  - float
  - double
---

---
# Apa itu Mantissa

Dalam konteks **representasi bilangan floating-point** (seperti `float` atau `double` di C++), **mantissa** (juga dikenal sebagai **significand**) adalah bagian yang menyimpan **angka-angka signifikan** dari suatu bilangan.

---

## 📦 Struktur Floating Point (IEEE 754)

Bilangan pecahan seperti `float` dan `double` disimpan dalam tiga bagian utama:

|Bagian|Fungsi|
|---|---|
|**Sign (1 bit)**|Menyimpan tanda: positif (0) atau negatif (1)|
|**Exponent**|Menyimpan pangkat 2 (bias)|
|**Mantissa (Significand)**|Menyimpan digit-digit penting dari bilangan|

Contoh untuk `float` (32-bit):

- 1 bit tanda
    
- 8 bit eksponen
    
- **23 bit mantissa**
    

Contoh untuk `double` (64-bit):

- 1 bit tanda
    
- 11 bit eksponen
    
- **52 bit mantissa**
    

---

## 🔍 Analogi Sederhana

Misalnya kamu punya bilangan desimal:

```
5.75 = 1.011 × 2²   → Dalam bentuk floating point biner
```

- `1.011` adalah bagian **mantissa** (nilai penting dari bilangan)
    
- `2²` adalah bagian **eksponen**
    
- Bilangan ini juga punya tanda (positif/negatif)
    

---

## 🧪 Kenapa Mantissa Penting?

- Mantissa menentukan **seberapa presisi** angka kamu.
    
- Semakin banyak bit untuk mantissa, semakin banyak **angka penting** yang bisa disimpan.
    
- Misalnya:
    
    - `float` (23 bit mantissa) hanya bisa menyimpan ~7 digit desimal akurat.
        
    - `double` (52 bit mantissa) bisa menyimpan ~15-16 digit desimal akurat.
        

---

## 📝 Kesimpulan

> **Mantissa adalah bagian dari bilangan floating point yang menyimpan digit-digit penting (angka signifikan).** Semakin besar ukuran mantissa, semakin tinggi **presisi** angka yang bisa disimpan.
