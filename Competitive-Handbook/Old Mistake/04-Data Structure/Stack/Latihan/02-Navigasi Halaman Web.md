---
obsidianUIMode: preview
note_type: latihan
latihan: Navigasi Halaman Web
sumber: chatgpt.com
tags:
  - stack
  - data-structure
date_learned: 2025-06-15T21:46:00
---
---
Berikut **Soal 2: Simulasi Navigasi Browser (Back & Forward)** — latihan paket dua `stack` sekaligus!

# 🧩 Soal 2: Navigasi Halaman Web

### 📖 Latar Belakang

Saat kamu browsing, browser menyimpan **riwayat “Back”** dan **“Forward”**.

- Setiap kali kamu membuka URL baru, halaman itu menjadi **current**, “Back” stack menampung halaman sebelumnya, dan “Forward” stack dikosongkan.
    
- Klik **BACK** → pindah ke halaman paling atas di Back‑stack, halaman saat ini masuk ke Forward‑stack.
    
- Klik **FORWARD** → kebalikannya.
    

Kamu akan mensimulasikan mekanisme ini.

---

### 📥 Input

1. Baris pertama: integer `n` (1 ≤ n ≤ 10⁵), jumlah perintah.
    
2. Baris kedua: string `home` — URL awal (tidak ada spasi).
    
3. `n` baris perintah, masing‑masing format:
    
    - `VISIT url` → buka URL baru `url`.
        
    - `BACK` → klik tombol “Back”.
        
    - `FORWARD` → klik tombol “Forward”.
        
    - `CURRENT` → cetak URL yang sedang aktif.
        
    - `HISTORY` → cetak isi Back‑stack dan Forward‑stack.
        

---

### 📤 Output

- Untuk setiap `CURRENT`, cetak satu baris URL saat ini.
    
- Untuk setiap `HISTORY`, cetak dua baris:
    
    1. `Back:` diikuti daftar isi Back‑stack (dari bottom ke top), atau `EMPTY` jika kosong.
        
    2. `Forward:` diikuti daftar isi Forward‑stack (dari bottom ke top), atau `EMPTY` jika kosong.
        

---

### 📑 Contoh

**Input:**

```
9
home.com
VISIT page1.com
VISIT page2.com
CURRENT
BACK
CURRENT
VISIT page3.com
HISTORY
FORWARD
```

**Output:**

```
page2.com
page1.com
Back: home.com page1.com
Forward: EMPTY
```

**Penjelasan Singkat:**

1. Mulai di `home.com`
    
2. VISIT `page1.com` → Back=[home.com], Forward=[]
    
3. VISIT `page2.com` → Back=[home.com,page1.com], Forward=[]
    
4. CURRENT → `page2.com`
    
5. BACK → pindah ke `page1.com`, Back=[home.com], Forward=[page2.com]
    
6. CURRENT → `page1.com`
    
7. VISIT `page3.com` → Back=[home.com,page3.com], Forward dikosongkan
    
8. HISTORY → cetak kedua stack
    
9. FORWARD → Forward kosong, jadi abaikan
    

---

### 🎯 Tujuan & Fungsi Stack

- `std::stack<string> backStk, forwardStk;`
    
- **VISIT**:
    
    ```cpp
    backStk.push(current);
    current = url;
    while(!forwardStk.empty()) forwardStk.pop();
    ```
    
- **BACK**:
    
    ```cpp
    if(!backStk.empty()){
      forwardStk.push(current);
      current = backStk.top();
      backStk.pop();
    }
    ```
    
- **FORWARD**: simetri dengan BACK, swap stack
    
- **CURRENT**: `cout << current`
    
- **HISTORY**: iterasi isi stack dengan bantuan container adaptor (misal, transfer ke vector sementara) untuk print bottom→top
    

---

Coba implementasikan, lalu kirim kodenya — aku akan cek dan bantu beri editorial! 🚀

## Editorial
Berikut jawabanku, yang ternyata masih sedikit keliru:

```cpp
#include<iostream>
#include<vector>
#include<stack>
#include<utility>
#include<sstream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    stack<string> back, forward;
    vector<string> clip;
    string temp;

    while(n--){
        string s;
        getline(cin >> ws, s);

        stringstream ss(s);
        string cmd;
        ss >> cmd;

        if(cmd=="home.com"){
            back.push(cmd);
        } else if(cmd=="VISIT"){
            string url;
            getline(ss >> ws, url);
            back.push(url);

            while(!forward.empty()){
                forward.pop();
            }
        } else if(cmd=="CURRENT"){
            cout << back.top() << "\n";
        } else if (cmd=="BACK"){
            if(!back.empty()){
                temp = back.top();
                back.pop();
                forward.push(temp);
            }
        } else if (cmd=="FORWARD"){
            if(!forward.empty()){
                temp = forward.top();
                forward.pop();
                back.push(temp);
            }
        } else if(cmd=="HISTORY"){
            cout << "BACK: ";
            if(back.empty()) cout << "EMPTY\n";
            else {
                while(!back.empty()){
                    clip.push_back(back.top());
                    back.pop();
                }

                for(int i=clip.size()-1; i>=0; i--){
                    cout << clip[i] << " ";
                }cout << "\n";

                for(int i=clip.size()-1; i>=0; i--){
                    back.push(clip[i]);
                }
                clip.clear();
            }

            cout << "FORWARD: ";
            if(forward.empty()) cout << "EMPTY\n";
            else {
                while(!forward.empty()){
                    clip.push_back(forward.top());
                    forward.pop();
                }

                for(int i=forward.size()-1; i>=0; i--){
                    cout << clip[i] << " ";
                }cout << "\n";

                for(int i=clip.size()-1; i>=0; i--){
                    forward.push(clip[i]);
                }
                clip.clear();
            }
        }
    }
    return 0;
}
```

# Editorial
Kode kamu hampir benar, tetapi ada **beberapa kekeliruan utama** yang menyebabkan hasilnya tidak sesuai harapan:

---

## ❌ **Kesalahan & Perbaikan**

### 1. 🔧 `home.com` harus dimasukkan **sebelum** loop

Baris:

```cpp
if(cmd=="home.com"){
    back.push(cmd);
}
```

Salah tempat. Seharusnya `home.com` dibaca **di awal program**, bukan sebagai perintah `cmd`. Contoh benar:

```cpp
string current;
cin >> current;
```

### 2. ⚠️ Saat `VISIT`, kamu **tidak update `current`**, malah langsung `back.push(url)`

Akibatnya: `CURRENT` selalu menunjuk `back.top()` bahkan jika hanya satu elemen — logika ini salah saat `BACK` karena `back.top()` bisa bukan `current`.

### ✅ Solusi yang Lebih Rapi:

Gunakan satu `string current`, dan stack hanya menyimpan histori (back & forward), `current` adalah halaman aktif.

---

## ✅ **Versi yang Dibenarkan**

```cpp
#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    string current;
    cin >> current;

    stack<string> back, forward;
    vector<string> clip;
    string line;

    getline(cin, line); // clear newline after reading current

    while(n--) {
        getline(cin, line);
        stringstream ss(line);
        string cmd;
        ss >> cmd;

        if(cmd == "VISIT") {
            string url;
            getline(ss >> ws, url);
            back.push(current);
            current = url;
            while(!forward.empty()) forward.pop();
        }
        else if(cmd == "CURRENT") {
            cout << current << "\n";
        }
        else if(cmd == "BACK") {
            if(!back.empty()) {
                forward.push(current);
                current = back.top();
                back.pop();
            }
        }
        else if(cmd == "FORWARD") {
            if(!forward.empty()) {
                back.push(current);
                current = forward.top();
                forward.pop();
            }
        }
        else if(cmd == "HISTORY") {
            cout << "Back: ";
            if(back.empty()) cout << "EMPTY\n";
            else {
                clip.clear();
                stack<string> temp = back;
                while(!temp.empty()) {
                    clip.push_back(temp.top());
                    temp.pop();
                }
                for(int i=clip.size()-1; i>=0; i--)
                    cout << clip[i] << " ";
                cout << "\n";
            }

            cout << "Forward: ";
            if(forward.empty()) cout << "EMPTY\n";
            else {
                clip.clear();
                stack<string> temp = forward;
                while(!temp.empty()) {
                    clip.push_back(temp.top());
                    temp.pop();
                }
                for(int i=clip.size()-1; i>=0; i--)
                    cout << clip[i] << " ";
                cout << "\n";
            }
        }
    }

    return 0;
}
```

---

## 🧠 **Editorial Ringkas**

### 🔹 Struktur yang Dipakai:

- `current`: menyimpan halaman aktif sekarang.
    
- `stack<string> back`: histori halaman sebelumnya.
    
- `stack<string> forward`: halaman yang bisa dikunjungi lagi setelah `BACK`.
    

### 🔹 Fungsi Stack yang Digunakan:

- `push()`: saat `VISIT`, `BACK`, `FORWARD`
    
- `pop()`: menghapus top saat pindah
    
- `top()`: membaca halaman atas
    
- `empty()`: validasi sebelum akses
    

### 🔹 Teknik Khusus:

- `getline(cin >> ws, s)` membaca seluruh baris dengan aman.
    
- `stringstream` memecah baris jadi perintah dan parameter.
    
- `vector<string>` sementara untuk menampilkan stack dari bawah ke atas (karena stack hanya bisa top-down).
    

---

Kalau kamu sudah paham, kita lanjut ke **Soal 3** yang memperkenalkan kombinasi `stack` dan validasi ekspresi, cocok untuk penguatan pemahaman berikutnya. Gas?