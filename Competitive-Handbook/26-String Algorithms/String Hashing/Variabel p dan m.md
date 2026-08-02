---
obsidianUIMode: preview
note_type: book theory
judul_materi:
sumber:
date_learned:
tags:
---
Link Sumber: 

---

> [!IMPORTANT]
>  
# Variabel p dan m
Di dalam fungsi _string hashing_, $p$ dan $m$ adalah dua parameter paling krusial yang menentukan keunikan dan validitas nilai _hash_ yang dihasilkan.

## 1. Kegunaan $p$ (Basis / Base)

Konstanta $p$ bertindak sebagai **basis bilangan** (seperti basis 10 pada sistem desimal atau basis 2 pada sistem biner) untuk menaruh setiap karakter pada posisi bobot nilai yang berbeda.

- **Menjaga Urutan Karakter:** Jika kita tidak menggunakan perpangkatan $p$ (misal hanya menjumlahkan nilai karakter saja), maka kata `"kasur"` dan `"rusak"` akan menghasilkan nilai _hash_ yang sama karena huruf penyusunnya sama.
    
- **Posisi Pangkat:** Dengan adanya $p$, karakter pertama dikali $p^0$, karakter kedua dikali $p^1$, karakter ketiga dikali $p^2$, dan seterusnya. Ini memastikan urutan karakter terekam secara unik di dalam nilai _hash_.
    
- **Aturan Pemilihan:** Nilai $p$ disarankan berupa **bilangan prima** yang nilainya sedikit lebih besar dari jumlah variasi karakter (ukuran alfabet) yang digunakan. Itulah mengapa $p = 31$ digunakan untuk huruf kecil (`a-z` yang berjumlah 26 karakter).

## 2. Kegunaan $m$ (Modulus)

Konstanta $m$ bertindak sebagai **pembatas ruang nilai** agar angka hasil perhitungan _hash_ tidak mengalami _integer overflow_ yang tidak terkontrol pada komputer.

- **Menjaga Batas Memori:** Melakukan perpangkatan string panjang (misal string dengan 100 karakter berarti ada operasi $p^{99}$) akan menghasilkan angka yang sangat besar yang tidak muat ditampung oleh tipe data komputer mana pun (`long long` sekalipun). Operasi `% m` memastikan nilai _hash_ selalu berada di rentang $0$ hingga $m - 1$.
    
- **Menentukan Probabilitas Kolisi:** Ukuran $m$ berbanding lurus dengan keamanan fungsi _hash_. Semakin besar nilai $m$, semakin banyak "kotak nilai" yang tersedia, sehingga kemungkinan dua string berbeda menempati nilai _hash_ yang sama (kolisi) menjadi semakin kecil ($\approx \frac{1}{m}$).
    
- **Aturan Pemilihan:** Nilai $m$ disarankan berupa **bilangan prima besar** (seperti $10^9 + 7$ atau $10^9 + 9$) agar distribusi nilai _hash_ menyebar secara merata dan tidak mudah ditebak atau dimanipulasi.