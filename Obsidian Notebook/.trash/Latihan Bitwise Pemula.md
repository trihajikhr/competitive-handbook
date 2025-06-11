---
obsidianUIMode: preview
note_type: latihan
latihan: bitwise
sumber: chatgpt.com
tags:
  - bits
  - bitwise
---
---
# Latihan Bitwise Pemula


### ✅ **Soal 3: Apakah Hanya Ada Satu Bit yang Aktif?**

**Deskripsi:**  
Diberikan `x`, tentukan apakah hanya ada **satu bit 1** dalam bentuk binernya (misalnya: 1, 2, 4, 8, 16, ...).

**Contoh:**

```
Input: 16
Output: YES

Input: 10
Output: NO
```

💡 _Hint:_ Jika `x > 0 && (x & (x - 1)) == 0`, maka jawabannya adalah `YES`.

---

### ✅ **Soal 4: Temukan Bit yang Aktif di Posisi Ke-3**

**Deskripsi:**  
Diberikan bilangan `x`, tentukan apakah bit ke-3 (dari kanan, 0-based index) adalah 1.

**Contoh:**

```
Input: 13
Output: YES  // 13 = 1101, bit ke-3 adalah 1

Input: 5
Output: NO   // 5 = 0101, bit ke-3 adalah 0
```

💡 _Hint:_ Gunakan `(x & (1 << 3))`.

---

### ✅ **Soal 5: Jumlah Seluruh Subset yang Memiliki XOR = K**

**Deskripsi:**  
Diberikan array `arr` dengan `N ≤ 20` bilangan, dan sebuah bilangan `K`. Hitung ada berapa **subset** dari array tersebut yang XOR totalnya sama dengan `K`.

**Contoh:**

```
Input:
arr = {1, 2, 3}
K = 0

Output: 2
// Subset dengan XOR = 0: {}, {1, 2, 3}
```

💡 _Hint:_ Gunakan bitmasking untuk mengecek semua `2^N` kemungkinan subset.

---

Kalau kamu mau, aku bisa bantu siapkan **template awal kode C++** untuk salah satu dari soal di atas. Mau mulai dari soal nomor berapa?