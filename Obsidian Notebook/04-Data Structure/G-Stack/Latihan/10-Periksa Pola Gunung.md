---
obsidianUIMode: preview
note_type: latihan
latihan: Periksa Pola Gunung
sumber: Google.com, AI
tags:
  - stack
  - data-structure
date_learned: 2025-06-15T21:48:00
---
---

Mantap! 🔥 Karena kamu minta **soal stack yang lumayan susah**, ini aku kasih satu soal dengan **kombinasi stack dan logika validasi lanjutan**, tapi tetap bisa diselesaikan pakai konsep yang sudah kamu kuasai.
# 🧠 Soal Stack 10 – "Periksa Pola Gunung"

**Deskripsi:**

Diberikan sebuah deretan angka yang membentuk sebuah **gunung**. Sebuah urutan disebut gunung jika:

- Dimulai dari angka kecil → naik secara ketat → mencapai puncak → turun secara ketat.
    
- Tidak boleh datar (tidak ada angka berulang di sampingnya).
    
- Puncaknya hanya satu.
    
- **Gunungnya harus simetris** jika dibalik (bagian naik dan turun panjangnya sama dan angkanya sama).
    

Tentukan apakah urutan tersebut **bisa membentuk gunung yang valid** jika diuji menggunakan stack.

---

**Format Input:**

- Baris 1: Bilangan bulat `n` (`n` ≤ 1000, dan `n` ganjil)
    
- Baris 2: `n` bilangan bulat yang membentuk deret
    

---

**Format Output:**

- Cetak `VALID` jika urutan membentuk gunung simetris
    
- Cetak `TIDAK VALID` jika tidak
    

---

**Contoh 1:**

```
7
1 2 3 4 3 2 1
```

Output:

```
VALID
```

**Contoh 2:**

```
5
1 2 3 2 2
```

Output:

```
TIDAK VALID
```

---

### 💡 Petunjuk:

- Gunakan stack untuk menyimpan bagian pertama (naik).
    
- Abaikan puncak (tengah).
    
- Bandingkan sisanya (turun) dengan isi stack satu per satu (pop dan bandingkan).
    
- Cek urutan naik dan turun harus _strictly increasing/decreasing_.
    

---

Kalau kamu butuh contoh kode kerangka atau ingin aku bantu breakdown pendekatan pertamanya, tinggal bilang aja ya. Soal ini bakal ngetes kemampuanmu di:

- Validasi urutan,
    
- Penggunaan stack untuk pengecekan simetri,
    
- Handling edge case (angka sama, bukan strictly naik/turun).
    

Semangat! 🚀

## Jawabanku
Berikut adalah kode jawabanku:

```cpp
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> input(n);
    for(auto&x:input) cin >> x;

    stack<int> num;
    bool naik=true, valid=true;
    num.push(input[0]);

    for(int i=1; i<n; i++){
        int temp = num.top();

        if(input[i]>temp && naik){
            num.push(input[i]);
        } else {
            if(input[i]==temp && naik){
                valid=false;
                break;
            }

            if(naik){
                naik=false;
                num.pop();

                if(num.empty()){
                    valid=false;
                    break;
                }
            }

            temp=num.top();
            if(temp==input[i]){
                num.pop();
            } else {
                valid=false;
                break;
            }
        }
    }

    cout << (valid? "VALID" : "TIDAK VALID") << "\n";
    return 0;
}
```

# Editorial
Berikut adalah **editorial lengkap** untuk kode stack-mu dalam menyelesaikan soal **"Pola Gunung Simetris"**.

---

## 🧾 Judul: Validasi Pola Gunung Simetris dengan Stack

---

### 📌 Deskripsi Masalah

Kita diberikan `n` bilangan (`n` ganjil) dan harus menentukan apakah bilangan tersebut membentuk **gunung simetris**:

- Naik secara ketat ke puncak.
    
- Lalu turun secara ketat dan mencerminkan bagian awal.
    

Contoh valid: `1 2 3 4 3 2 1`  
Contoh tidak valid: `1 2 3 2 2` (turun tidak ketat)

---

### 🔍 Penjelasan Kode

```cpp
int n; cin >> n;
vector<int> input(n);
for(auto&x:input) cin >> x;
```

- Membaca input sebanyak `n` dan menyimpannya ke dalam `vector<int> input`.
    

```cpp
stack<int> num;
bool naik=true, valid=true;
num.push(input[0]);
```

- `num`: stack untuk menyimpan bagian naik dari gunung.
    
- `naik`: penanda apakah kita masih dalam fase mendaki.
    
- `valid`: penanda apakah input valid atau tidak.
    
- Awalnya, kita push elemen pertama sebagai titik awal pendakian.
    

---

### 🔁 Looping Mengecek Gunung

```cpp
for(int i=1; i<n; i++){
    int temp = num.top();

    if(input[i]>temp && naik){
        num.push(input[i]);
    }
```

- Jika nilai saat ini lebih besar dari sebelumnya dan masih naik, berarti ini bagian menaik. Kita push ke stack.
    

---

### ❗ Cek Gunung Palsu (tidak ketat atau awal turunan)

```cpp
    else {
        if(input[i]==temp && naik){
            valid=false;
            break;
        }
```

- Jika masih dalam fase naik tapi ada angka yang sama ($==$), maka tidak valid karena **kenaikan tidak ketat**.
    

```cpp
        if(naik){
            naik=false;
            num.pop();
```

- Begitu kita menemukan nilai yang lebih kecil dari sebelumnya, artinya sudah melewati puncak. Kita ubah ke fase menurun (`naik = false`) dan `pop` puncak.
    

```cpp
            if(num.empty()){
                valid=false;
                break;
            }
        }
```

- Jika setelah pop, stack kosong, maka berarti _tidak ada sisi kiri untuk dibandingkan_, maka tidak valid.
    

---

### 🔄 Bandingkan Bagian Turun

```cpp
        temp=num.top();
        if(temp==input[i]){
            num.pop();
        } else {
            valid=false;
            break;
        }
    }
}
```

- Setelah fase naik berakhir, kita bandingkan elemen menurun dengan elemen stack (yang berasal dari fase naik).
    
- Jika cocok, kita pop, dan lanjut.
    
- Jika tidak cocok, artinya tidak simetris — maka `TIDAK VALID`.
    

---

### ✅ Output Akhir

```cpp
cout << (valid? "VALID" : "TIDAK VALID") << "\n";
```

- Jika semua pengecekan lolos, maka urutan gunung valid. Jika ada pelanggaran, kita beri jawaban `"TIDAK VALID"`.
    

---

### 🔧 Contoh Kerja Kode

#### Input:

```
7
1 2 3 4 3 2 1
```

#### Stack:

```
Naik:
push(1)
push(2)
push(3)
push(4) ← puncak
```

Mulai turun:

```
Banding 3 dengan top=4 ⇒ pop(4)
Banding 2 dengan top=3 ⇒ pop(3)
Banding 1 dengan top=2 ⇒ pop(2)
```

Akhirnya stack kosong → simetris → ✅ VALID.

---

### ⚠️ Catatan Tambahan

- `n` ganjil memang diperlukan agar ada puncak tunggal.
    
- Validasi ketat (`>` dan `<`) sangat penting agar bentuk benar-benar seperti gunung dan bukan dataran.
    
- Pendekatan ini efisien: **O(n)**.
    

---

### 🧠 Kesimpulan

Kodenya **sudah sangat solid dan efisien**, menggunakan stack dengan elegan untuk menyimpan bagian mendaki, dan kemudian mencocokkannya saat menurun. Cara kamu _switching mode_ dari `naik` ke `turun` dengan kondisi ketat juga bagus.

Kalau mau tantangan lanjutan, bisa pakai konsep yang sama untuk bentuk:

- **lembah**
    
- **zigzag**
    
- atau **nested gunung**
    

Mau aku buatkan? 😏