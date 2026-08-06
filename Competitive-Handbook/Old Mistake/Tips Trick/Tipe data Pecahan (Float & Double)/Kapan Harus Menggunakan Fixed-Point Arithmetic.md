---
obsidianUIMode: preview
note_type: tips trick
tips_trick: Kapan Harus Menggunakan Fixed-Point Arithmetic
sumber: Google.com, AI
tags:
  - tipe-data
  - float
  - double
---

---

# 💰 Kapan Harus Menggunakan Fixed-Point Arithmetic (Misalnya di Keuangan)

Dalam dunia pemrograman, representasi angka pecahan umumnya menggunakan **floating-point** (`float`, `double`, `long double`). Namun untuk aplikasi tertentu seperti **keuangan**, penggunaan tipe ini bisa menimbulkan **kesalahan presisi** yang berbahaya.

Alternatifnya adalah menggunakan **fixed-point arithmetic** — teknik representasi pecahan dengan **presisi tetap** dan **tanpa kesalahan pembulatan biner** seperti pada `float` atau `double`.

---

## 📉 Masalah Floating-Point dalam Keuangan

```cpp
#include <iostream>
using namespace std;

int main() {
    double saldo = 0.0;

    for (int i = 0; i < 10; ++i)
        saldo += 0.1;

    cout << "Saldo akhir: " << saldo << endl;
    return 0;
}
````

**Output:**

```
Saldo akhir: 0.9999999999999999
```

### 😱 Apa yang Salah?

- Kita ingin hasilnya `1.0`.
    
- Tapi karena `0.1` tidak bisa direpresentasikan secara eksak dalam biner, kesalahan kecil **terakumulasi**.
    
- Dalam konteks keuangan, ini bisa menyebabkan **selisih pajak, potongan gaji, atau bunga** yang tidak akurat.
    

---

## 💡 Solusi: Gunakan Fixed-Point Arithmetic

Fixed-point menyimpan angka dalam bentuk **integer** yang mewakili **nilai riil dikalikan faktor skala**.

Contoh:

- 1.25 dolar → simpan sebagai `125` sen (dikalikan 100).
    
- 0.1 dolar → simpan sebagai `10` sen.
    
- Tidak ada pecahan biner → **tidak ada error pembulatan**.
    

---

## ✅ Contoh Implementasi Fixed-Point Sederhana

```cpp
#include <iostream>
using namespace std;

int main() {
    int saldo_sen = 0;

    for (int i = 0; i < 10; ++i)
        saldo_sen += 10;  // Tambah 10 sen

    cout << "Saldo akhir: " << saldo_sen << " sen" << endl;
    cout << "Dalam dolar: $" << saldo_sen / 100.0 << endl;

    return 0;
}
```

**Output:**

```
Saldo akhir: 100 sen
Dalam dolar: $1
```

✅ Akurat, tanpa kesalahan biner.

---

## 🏦 Kapan Harus Gunakan Fixed-Point?

|Gunakan Fixed-Point Saat...|Penjelasan|
|---|---|
|💵 Aplikasi keuangan|Transaksi, bunga bank, akuntansi → uang harus tepat|
|🎮 Game dengan skor tetap atau stabil|Angka kecil tapi sensitif → skor, damage, kecepatan|
|🧮 Sistem tertanam (embedded) tanpa FPU|Mikrokontroler tanpa Floating Point Unit (FPU)|
|⏱️ Perhitungan waktu real-time yang deterministik|Untuk menghindari akumulasi error dalam waktu|
|🔐 Aplikasi blockchain/smart contract|Setiap angka harus presisi dan tidak ambigu|

---

## ⚠️ Kapan Floating-Point Lebih Cocok?

|Gunakan Floating-Point Saat...|Penjelasan|
|---|---|
|🔬 Perhitungan ilmiah|Presisi tinggi, bilangan sangat besar/kecil|
|🎲 Simulasi fisika atau probabilitas|Tidak masalah dengan error kecil|
|📈 Grafik komputer dan rendering|Perubahan presisi kecil tidak berdampak besar|
|🤖 Algoritma AI atau Machine Learning|Floating-point sangat umum dan didukung GPU|

---

## 🧠 Tips Praktis

- Gunakan **`int` atau `long long`** untuk menyimpan jumlah uang dalam satuan terkecil (sen, rupiah, cent).
    
- Selalu tampilkan hasil dengan membagi ke bentuk desimal:
    
    ```cpp
    cout << fixed << setprecision(2) << sen / 100.0;
    ```
    
- Buat fungsi konversi agar tidak mengulang:
    
    ```cpp
    double toDollar(int sen) { return sen / 100.0; }
    int toSen(double dolar) { return (int)(dolar * 100 + 0.5); } // pembulatan
    ```
    

---

## 📦 Library / Tools yang Mendukung Fixed-Point

|Tools / Library|Deskripsi|
|---|---|
|Boost.Multiprecision (`cpp_dec_float`)|Presisi desimal arbitrary|
|Fixed-point libraries di embedded (CMSIS, Arduino)|Untuk mikrokontroler|
|Decimal type di bahasa lain (Python, Java, Rust)|Python: `decimal.Decimal`, Rust: `rust_decimal`|

---

## 🔚 Kesimpulan

- Floating-point (`float`, `double`) **bisa menimbulkan error presisi** dalam keuangan.
    
- Gunakan **fixed-point arithmetic** (angka disimpan sebagai `int`) untuk **perhitungan uang** yang aman dan presisi.
    
- Hindari perbandingan langsung $==$ untuk angka pecahan — pakai integer jika memungkinkan.
    
- Pilihan tipe data = keputusan desain yang krusial dalam aplikasi presisi tinggi.
    

---

> 💬 **"Dalam dunia uang, presisi bukan kemewahan — melainkan keharusan."**

