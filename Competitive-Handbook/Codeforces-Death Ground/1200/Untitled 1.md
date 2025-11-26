---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal:
judul_DEATH:
teori_DEATH:
sumber:
rating:
ada_tips:
date_learned:
tags:
---
Sumber:

```ad-tip
title:⚔️ Teori Death Ground
```

<br/>

---
# 1 | Judul

<br/>

---
# 2 | Sesi Death Ground ⚔️

<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

Ini hanyalah masalah implementasi.

Pertama, mari kita tetapkan **$s$** (total berat perahu). Nilai $s$ bisa berada dalam rentang $[2; 2n]$. Kita cari jumlah maksimum perahu yang bisa kita peroleh dengan nilai $s$ ini, dan kemudian pilih nilai maksimum dari semua nilai yang ditemukan.

Untuk menemukan jumlah pasangan, mari kita ulangi (iterasi) untuk berat terkecil dalam satu tim, yang berada dalam rentang 
$$\left[1; \left\lfloor\frac{s+1}{2}\right\rfloor - 1\right]$$

1.  Misalkan berat terkecil ini adalah **$i$**.

2.  Maka (karena jumlah beratnya adalah $s$), berat terbesar haruslah **$s - i$**.

3.  Jumlah pasangan yang dapat kita peroleh dengan dua berat seperti itu dan total berat $s$ adalah $\min(cnt_i, cnt_{s-i})$, di mana $cnt_i$ adalah jumlah kemunculan berat $i$ dalam daftar berat $w$.

4.  Dan ada kasus tambahan (berbeda): jika $s$ genap, kita perlu menambahkan:
    $$\left\lfloor\frac{cnt_{s/2}}{2}\right\rfloor$$
     (ini adalah jumlah pasangan yang dapat dibuat dari perahu yang memiliki berat tepat $s/2$).

> **Penting:** Jangan lupa bahwa ada kasus di mana $s - i > n$ (berat maksimum yang mungkin), jadi Anda perlu berasumsi bahwa nilai $cnt$ untuk berat-berat ini adalah nol.

## 3.2 | Analisis Pribadi
## 3.3 | Analisis Jawaban User Lain

### 1 | Jawaban Pertama

```cpp
```
### 2 | Jawaban Kedua

```cpp
```
### 3 | Jawaban Ketiga

```cpp
```