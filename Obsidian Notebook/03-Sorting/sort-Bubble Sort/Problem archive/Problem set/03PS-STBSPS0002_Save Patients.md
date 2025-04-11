---
obsidianUIMode: preview
note_type: problem set
id_problem: 03PS-STBSPS0002
judul_problem: Save Patients
sumber: hackerearth.com
kategori_problem: 📊 problem_statement
kesulitan: 🥉 easy
time_complexity: 🟣 O(n²)
memory_complexity: 🟢 O(1) ✅ → Stable
status: 🏆 solved
date_solved: 2025-03-03T14:50:00
pendekatan: bubble sort algorithm
tags:
  - array
  - bubble-sort
  - sorting
---
Link problem: [Save Patients \| Practice Problems](https://www.hackerearth.com/practice/algorithms/sorting/bubble-sort/practice-problems/algorithm/save-patients/)

#array #bubble-sort #sorting 

---
# Save Patients
Time limit: 1 s
Memory limit: 256 megabyte

Sebuah virus mematikan telah menginfeksi populasi besar di sebuah planet. Seorang ilmuwan brilian menemukan strain virus baru yang dapat menyembuhkan penyakit ini. Vaksin yang diproduksi dari virus tersebut memiliki kekuatan yang berbeda-beda berdasarkan jumlah **midichlorian**.

Seorang pasien hanya bisa sembuh jika jumlah midichlorian dalam satu batch vaksin **lebih besar** daripada jumlah midichlorian dalam tubuh pasien.

Seorang dokter menerima laporan yang berisi jumlah midichlorian dari setiap pasien yang terinfeksi. **Practo** menyimpan semua vaksin yang dimiliki dokter beserta jumlah midichloriannya. Tugas Anda adalah menentukan apakah dokter dapat menyembuhkan **semua pasien** dengan vaksin yang tersedia. Jumlah vaksin dan pasien **selalu sama**.

### Input
- Baris pertama berisi satu bilangan bulat **N** — jumlah vaksin yang tersedia.
- Baris kedua berisi **N** bilangan bulat yang menyatakan **kekuatan vaksin** (jumlah midichlorian dalam vaksin).
- Baris ketiga berisi **N** bilangan bulat yang menyatakan **jumlah midichlorian dalam tubuh pasien**.

**Batasan input:**
$1 < N < 10$, Kekuatan vaksin dan jumlah midichlorian pasien termasuk dalam rentang bilangan bulat.
### Output
Cetak **"Yes"** jika semua pasien dapat disembuhkan, **"No"** jika tidak.
### Examples
Input:
```
5
123 146 454 542 456
100 328 248 689 200
```

Output:
```bash
No
```

### Note

# Jawaban
Jika kita buat problem statement menjadi sederhana, kita hanya perlu mengurutkan array vaksin dan array pasien, lalu setelah diurutkan, kita tentukan, apakah di indeks yang sama, nilai elemen vaksin lebih besar dari nilai elemen pasien. Jika iya, maka berarti pasien dapat disembuhkan, dan perulangan berlanjut. Jika sampai indeks terakhir semua nilai vaksin lebih besar dari nilai elemen pasien, maka semua pasien dapat disembuhkan, dan outputkan `Yes`.

Tapi ketika ada salah satu indeks elemen yang tidak memenuhi. Maka berarti ada pasien yang tidak terselamatkan, dan kita keluarkan `No`.

```cpp
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> bubbleSort(int n, vector<int>&arr){

    for(int i=0;i<n; i++){
        bool swapped=false;
        for(int j=0;j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped=true;
            }
        }
        if(!swapped) break;
    }
    return arr;
}

string result(int n, vector<int>&vac, vector<int>&pat){
    bubbleSort(n, vac);
    bubbleSort(n, pat);

    for(int i=0; i<n;i++){
        if(vac[i]<=pat[i]){
            return "No";
        }
    }
    return "Yes";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie();

    int n; cin >> n;
    vector<int> vac(n);
    vector<int> pat(n);

    for(int &x:vac) cin >> x;
    for(int &x:pat) cin >> x;

    cout << result(n, vac, pat) << "\n";

    return 0;
}
```

Time complexity: $O(n^2)$
Memory complexity: $O(1)$
## Jawaban efektif
Walaupun bab ini membahas tentang bubble sort, mungkin seperti ini implementasinya jika kita langsung menggunakan built-in sort, atau fungsi `sort` bawaan header `<algorithm>`:

```cpp
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 
string result(int n, vector<int>&vac, vector<int>&pat){
    sort(vac.begin(), vac.end());
    sort(pat.begin(), pat.end());
 
    for(int i=0; i<n;i++){
        if(vac[i]<=pat[i]){
            return "No";
        }
    }
    return "Yes";
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie();
 
    int n; cin >> n;
    vector<int> vac(n);
    vector<int> pat(n);
 
    for(int &x:vac) cin >> x;
    for(int &x:pat) cin >> x;
 
    cout << result(n, vac, pat) << "\n";
 
    return 0;
}
```

Time complexity: $O(n \,log \,n)$
Memory complexity: $O(1)$

Fungsi bawaan ini memiliki kompleksitas waktu terbaik untuk sorting, dibandingkan implementasi standar, yaitu $O(n \,log \,n)$.
# Editorial 
Berikut step-stepnya:
1. Program menerima inputan $n$, yaitu nilai yang digunakan untuk menentukan banyaknya elemen pada array.
   <br/>
2. Buat 2 array, array pertama untuk array vaksin, dan array kedua untuk array pasien.
   <br/>
3. Program akan menerima elemen array dengan jumlah yang sesuai. Tapi ada kemungkinan, bahkan sangat mungkin array yang diberikan tidak terurut, sehingga perlu diurutkan terlebih dahulu.
   <br/>
4. Sorting bisa dilakukan dengan algoritma sorting (karena sedang belajar bubble sort), atau fungsi `sort` milik header `<algorithm>` yang jelas merupakan pilihan yang lebih baik.
   <br/>
5. Setelah disorting, maka bandingkan dengan perulangan, apakah nilai elemen di indeks yang sama, antara array vaksin lebih besar dari array pasien? Lakukan perulangan ini hingga akhir indeks, dan jika ditemukan satu saja elemen dari array vaksin yang lebih kecil atau sama dengan nilai elemen pada array pasien, maka kembalikan nilai `No`. Ini karena ada pasien yang tidak selamat.
   <br/>
6. Tapi jika semua kondisi terpenuhi hingga akhir indeks, kembalikan nilai `Yes`, karena semua pasien pasti selamat.
# Informasi tambahan