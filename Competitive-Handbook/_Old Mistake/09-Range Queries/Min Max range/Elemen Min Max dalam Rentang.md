---
obsidianUIMode: preview
note_type: book theory
judul_materi: Elemen Min dan Max dalam Rentang
sumber:
  - myself
  - "buku: CP handbook by Antti Laaksonen"
  - cp-algorithms.com
date_learned: 2026-02-14T00:24:00
tags:
  - range-queries
---
Link Sumber: 

---

> [!IMPORTANT]

# Elemen Min dan Max dalam Rentang

Misalkan kita diberikan array dengan ukuran $n$, dan terdapat $n$ elemen integer. Lalu kita diminta untuk menentukan elemen dengan nilai maksimum atau minimum dalam rentang $l$ hingga $r$ yang diberikan, dengan $l \leq r \leq n$. Kira-kira, algoritma apa yang paling tepat untuk digunakan?

Pada materi kali ini, kita akan membahas algoritma ranges queri untuk mengatasi  masalah ini, mulai dari pendekatan naif[^1], hingga pendekatan yang lebih efisien.

## 1. Pendekatan Naif

Algoritma penyelesaian yang akan kita gunakan mungkin adalah mengandalkan iterasi, yang dimulai dari posisi indeks $l$, dan berakhir di posisi $r$. Ini adalah metode penyelesaian yang bisa digunakan jika soal yang diberikan tidak memiliki beberapa test case yang perlu diselesaikan.

Misal diberikan inputan berikut:

```
10
1 6 4 8 9 3 5 4 7 6
3 5
```

Baris pertama menyatakan $n$ atau ukuran array, baris kedua adalah elemen array, dan baris ketiga adalah $l$ dan $r$, rentang yang diminta untuk kita cari nilai elemen maksimal atau minimalnya.

Misal kita perlu mencari elemen maksimalnya, maka pendekatan naif adalah sebagai berikut:

```cpp
#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

auto main() -> int {
    int n;
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    int l, r;
    cin >> l >> r;

    int maks = INT_MIN;
    for (int i = l; i <= r; i++) {
        maks = max(maks, v[i]);
    }

    cout << maks;
    return 0;
}
```

Perhatikan bahwa array yang digunakan adalah 1-based index, sehingga array yang dibuat harus dibuat berukuran $n+1$. ini menjadikan indeks $0$ tidak digunakan, tetapi nilai dari $l$ dan $r$ bisa langsung digunakan sebagai indexing.

Dengan algoritma ini, kita cukup mencari rentang pencarian dari $l$ hingga $r$, dan memfilter nilai tertinggi dari rentang tersebut. Maka kompleksitas dari algoritma ini, pada worst case skenarionya $(l=1, r=n)$ adalah $O(n)$.

Namun jika soal memberikan beberapa test case, misal seperti ini:

> Diberikan array berukuran $n$, dengan $n$ integer pada beris kedua. Pada baris ketiga diberikan $t$ yang menyatakan banyaknya test case, dan kemudian pada $t$ baris berikutnya diberikan $l$ dan $r$ sebagai lingkup rentang array yang kita perlu cari elemen maksimalnya. Tentukan elemen maksimal dari rentang-rentang yang diberikan dari setiap test case.

Maka, pendekatan naif, misal memodifikasi kode diatas supaya bisa menangani beberapa test case seperti ini:

```cpp
#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

auto main() -> int {
    int n;
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;

        int maks = INT_MIN;
        for (int i = l; i <= r; i++) {
            maks = max(maks, v[i]);
        }

        cout << maks << "\n";
    }

    return 0;
}
```

tidak lagi menjadi algoritma yang tepat untuk digunakan. Jika nilai $n$ atau ukuran array berukuran besar, misal $10^9$, maka pada worst-case skenario, kita akan diminta untuk mencari elemen maksimal pada rentang $l=1$ dan $r=n$ berkali-kali. Dan ini jelas tidak efisien, karena kompleksitasnya menjadi $O(nt)$. Jika nilai dari $n$ dan $t$ besar, pendekatan ini akan menjadi lambat.

Maka dibutuhkan algoritma yang mampu menangani ini dengan lebih cepat.

## 2. Pendekatan yang Efisien

Kita perlu mempertimbangkan, apakah array yang diberikan static atau tidak. Jika array yang diberikan tidak mengalami perubahan selama pengaksesan query, maka penyelesaianya akan lebih mudah. Tapi jika array mengalami update disaat program berjalan, maka algoritma lain perlu digunakan.

Jadi, kita akan mempelajari 2 algoritma untuk mengatasi kedua kondisi tersebut.

### 2.1. Static: Sparse Table

Untuk mencari elemen maksimum atau minimum dalam rentang, pelajari [Sparse Table](Sparse%20Table.md) pada bab data structure, aku sudah membuatnya disana 😀, beserta penjelasan mendetailnya.


> [!NOTE]
> Algoritma ini bisa digunakan untuk operasi yang bersifat idempotent, yaitu suatu operasi yang jika diterapkan berulang pada nilai yang sama, hasilnya tidak berubah, contoh:
> - $max(x,x)=x$
> - $min(x,x)=x$
> - $gcd(x,x)=x$
>   
>  Sifat idempotent memungkinkan hasil penggabungan dua interval yang tumpang tindih tetap benar, karena pengulangan elemen tidak mengubah hasil operasi.
>  
>  Jadi, cukup rubah operasi pada algoritma, dan sesuaikan ingin menggunakan sparse table untuk mencari nilai apa dalam rentang.
#### 2.1.1. Bahan latihan

Sebagai bahan latihan, gunakan sparse table berikut yang sudah dilengkapi dengan output untuk melihat bentuk dari array dua dimensi dari sparse table:

```cpp
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

struct SparseTable {
	int n, K;
	vector<vector<int>> st;
	vector<int> lg;

	SparseTable(const vector<int>& a) {
		n = (int)a.size();
		K = (int)floor(log2(n)) + 1;

		st.assign(K, vector<int>(n));
		lg.assign(n + 1, 0);

		// Precompute log
		for (int i = 2; i <= n; i++) lg[i] = lg[i / 2] + 1;

		// Level 0 = original array
		st[0] = a;

		// Build table
		for (int k = 1; k < K; k++) {
			for (int i = 0; i + (1 << k) <= n; i++) {
				st[k][i] = max(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
			}
		}
	}

	// Query maximum on range [L, R] inclusive
	int query(int L, int R) {
		int len = R - L + 1;
		int k = lg[len];
		return max(st[k][L], st[k][R - (1 << k) + 1]);
	}

	void print() {
		cout << "\nsparse table:\n";
		for (const auto& row : st) {
			for (const auto& x : row) {
				cout << x << " ";
			}
			cout << "\n";
		}

		cout << "\n";
		cout << "log table:\n";
		for (const auto& x : lg) {
			cout << x << " ";
		}
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q;
	cin >> n >> q;

	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	SparseTable rmq(a);

	// untuk mempermudah belajar, lihat hasil arraynya juga:
	rmq.print();

	while (q--) {
		int l, r;
		cin >> l >> r;
		l--, r--;
		// asumsi input 1-based
		cout << "\n\nHasil: " << rmq.query(l, r) << "\n";
	}
}
```

Jika diberikan inputan berikut:

```
10 1
45 93 57 30 75 58 49 53 96 2
1 10
```

Maka outputnya adalah sebagai berikkut:

```
sparse table:
45 93 57 30 75 58 49 53 96 2
93 93 57 75 75 58 53 96 96 0
93 93 75 75 75 96 96 0 0 0
93 96 96 0 0 0 0 0 0 0

log table:
0 0 1 1 2 2 2 2 3 3 3

Hasil: 96
```

#### 2.1.2. Algoritma sparse table

Berikut adalah versi ku untuk sparse table, ini adalah versi yang siap tempur competitive programming:

```cpp
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> st;
vector<int> lg;

void precompute(const vector<int>& vec, int n) {
    int lego = static_cast<int>(floor(log2(n)) + 1);
    st.assign(lego, vector<int>(n));
    st[0] = vec;
    for (int k = 1; k < lego; k++) {
        for (int i = 0; i + (1 << k) <= n; i++) {
            st[k][i] = max(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
        }
    }

    lg.assign(n + 1, 0);
    for (int i = 2; i <= n; i++) {
        lg[i] = lg[i / 2] + 1;
    }
}

int query(int L, int R) {
    int len = lg[R - L + 1];
    return max(st[len][L], st[len][R - (1 << len) + 1]);
}

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;

    cin >> n >> q;
    vector<int> vec(n);
    for (auto& x : vec) {
        cin >> x;
    }

    precompute(vec, n);
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        cout << query(l, r) << "\n";
    }

    return 0;
}
```

Baiklah, disini aku akan membuat penjelasan mengenai algoritma ini dengan menggunakan bahasaku sendiri, terlepas aku sudah membuat materinya di bab terpisah.

Terdapat sebuah intuisi yang perlu kita pahami, yaitu adalah bahwa semua angka non-negatif integer, itu bisa dibentuk dari varian perpangkatan $2$. Misal:

- $13 = 2^3 + 2^2 + 2^0$
- $14 = 2^3 + 2^2 + 2^1$
- $15 = 2^3 + 2^2 + 2^1 + 2^0$
- dst...

Katakanlah kita memiliki kumpulan lego yang merupakan hasil dari $2^k$ dengan $k$ adalah angka yang unik. Maka kita bisa mendapatkan semua angka yang ada, cukup dengan menyusun lego-lego yang tepat. Dengan kata lain, semua angka yang ada adalah susunan lego-lego terpisah tadi. 

Lalu, jika diberikan angka berupa $x$, berapa banyak lego yang dibutuhkan untuk menyusun angka tersebut? Jawabanya mudah, kita cukup mencari nilai dari $\text{log}_{2} x$ yang dibulatkan keatas, yaitu paling banyak dibutukan $\lceil \text{log}_2 x \rceil$ lego.

Ide utama di balik sparse table adalah melakukan pra-penghitungan (_precompute_) semua jawaban untuk range queries dengan panjang lego-lego tadi. Setelah itu, range query yang berbeda dapat dijawab dengan membagi range tersebut menjadi beberapa range dengan panjang lego yang tepat, mencari jawaban yang telah dihitung sebelumnya, dan menggabungkannya untuk mendapatkan jawaban lengkap.

Mari kita telusuri bagaimana kita membuat array 2 dimensi sebagai precompute sparse table dari inputan berikut:

```
10 1
45 93 57 30 75 58 49 53 96 2
```

Sparse table yang terbentuk kira-kira adalah seperti ini:

```
45 93 57 30 75 58 49 53 96 2
93 93 57 75 75 58 53 96 96 0
93 93 75 75 75 96 96 0 0 0
93 96 96 0 0 0 0 0 0 0
```

Diberikan ukuran $n$ adalah $10$. Disini kita perlu tentukan, berapa banyak lego yang dibutuhkan untuk menyusun angka $10$. Maka kita bisa menggunakan rumus $\lfloor \text{log}_2 n \rfloor$, untuk mendapatkan $\lfloor \text{log}_2 10 \rfloor = 3$. Ukuran ini akan kita gunakan sebagai tinggi dari array sparse table tersebut (*kita bulatkan kebawah untuk kepentingan operasi selanjutnya!*).

Tapi disini kita perlu memasukan salinan dari array asli untuk diletakan di baris pertama array sparse table kita, ini karena sparse table harus dibangun dengan cara dynamic programming, sehingga harus ada data awal untuk membangun jawaban. Sehingga, kita perlu menambahkan satu baris lagi pada total tinggi array sparse table, sehingga rumusnya diganti menjadi $\lfloor \text{log}_2 n \rfloor + 1$, sehingga didapat $\lfloor \text{log}_2 10 \rfloor +1 = 4$:

Kode berikut bisa digunakan:

```cpp
int lego = static_cast<int>(floor(log2(n)) + 1);

// cara cepat
int lego = __lg(n) + 1;
```

Setelah itu, tetapkan ukuran dari array dua dimensi sparse table sebagai $a \times b$, dengan $a = \lfloor \text{log}_2 n \rfloor +1$, dan $b=n$, dimana $n$ adalah ukuran array asli yang diberikan.

```cpp
st.assign(lego, vector<int>(n));
```

Maka array sparse table kita sekarang menjadi seperti ini:

```
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
```

Lalu, tetapkan baris pertama array sparse table dengan array asli dengan $st[0] = vec$, semisal $st$ adalah nama array sparse table, dan $vec$ adalah nama array asli. 

```cpp
st[0] = vec;
```

Maka, sekarang sparse table kita menjadi seperti berikut:

```
45 93 57 30 75 58 49 53 96 2
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
```

Tahap selanjutnya adalah menggunakan dynamic programming, untuk mengisi data pada baris kedua hingga baris terakhir:

```cpp
for (int k = 1; k < lego; k++) {
	for (int i = 0; i + (1 << k) <= n; i++) {
		st[k][i] = max(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
	}
}
```

Intuisi yang perlu digunakan disini adalah, pada baris ke-$k$, kita membandingkan elemen pada baris diatasnya atau $k-1$, ini bisa dilihat pada penggunaan $st[k-1]$. Lalu, elemen yang dibandingkan adalah elemen pada kolom yang sama yaitu kolom ke-$i$ , dengan elemen pada kolom ke-$i + 2^{k-1}$.

Disini, kita perlu menentukan, yang dicari adalah elemen maksimum atau minimum. Jika maksimum, maka gunakan operasi $st[k][i] = max(x,y)$, dan jika elemen yang dicari adalah elemen minimum, maka gunakan $st[k][i] = min(x,y)$, dengan $x=st[k-1][i]$, dan $y=st[k-1][i+2^{k-1}]$.

Untuk mempercepat mendapatkan hasil dari $2^k$, kita bisa mengandalkan operasi bitwise, dengan melakukan pergeseran bit $1$ sebanyak $k$ kali, atau dengan menggunakan aturan $1 << k \equiv 2^k$. Ini adalah cara yang lebih efisien secara kompleksitas waktu daripada menghitung secara manual, atau dengan fungsi bawaan $pow(2,k)$.

Pada iterasi pertama, hasil dari sparse table kita menjadi seperti ini:

```
45 93 57 30 75 58 49 53 96 2
93 93 57 75 75 58 53 96 96 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
```

Ketika iterasi pertama atau saat $k=1$, nilai dari $i + 2^{1-1} \rightarrow 0 + 2^{0}=1$. Ini artinya kita hanya perlu membandingkan elemen ke-$i$ dengan $i+1$, atau bersebelahan.

Pada iterasi kedua, hasil dari sparse table kita menjadi seperti ini:

```
45 93 57 30 75 58 49 53 96 2
93 93 57 75 75 58 53 96 96 0
93 93 75 75 75 96 96 0 0 0
0 0 0 0 0 0 0 0 0 0
```

Ketika iterasi kedua atau saat $k=2$, nilai dari $i + 2^{2-1} \rightarrow 0 + 2^{1}=2$. Ini artinya kita hanya perlu membandingkan elemen ke-$i$ dengan $i+2$, atau tepat elemen ke $2$ didepanya.

Pada iterasi ketiga, hasil dari sparse table kita menjadi seperti ini:

```
45 93 57 30 75 58 49 53 96 2
93 93 57 75 75 58 53 96 96 0
93 93 75 75 75 96 96 0 0 0
93 96 96 0 0 0 0 0 0 0
```

Ketika iterasi ketiga atau saat $k=3$, nilai dari $i+2^{3-1} \rightarrow 0+2^2 = 4$. Ini artinya kita hanya perlu membandingkan elemen ke-$i$ dengan $i+4$, atau tepat elemen ke $4$ didepanya.

Berikut ilustrasi alur pembuatan sparse table:

![](Elemen%20Min%20dan%20Max%20dalam%20Rentang-1.png)

> [!CAUTION]
> Pada perulangan kedua, kita menggunakan kondisional berikut:
> ```cpp
> for (int i = 0; i + (1 << k) <= n; i++)
> ```
> 
> Kenapa? Karena saat kita membandingkan $st[k][i] = min(x,y)$ atau $st[k][i] = max(x,y)$, kita perlu memastikan bahwa elemen $y$ dapat diambil dengan menggunakan indeks yang tepat, dengan tidak melebihi ukuran array atau *out-of-bound*, maupun tidak mengambil elemen dengan nilai $0$ atau kosong yang sengaja dibiarkan di sisi kanan array.
> 
> Misal pada saat $k=1$, perulangan terakhir yang dijalankan adalah ketika kondisional perulangan kedua $i + 2^1 \leq n$ berada pada nilai $8 + 2^1 \leq 10$. Pengambilan kolom untuk $y$, menggunakan aturan $i+2^{k-1}$, atau saat $8+2^{1-1} \rightarrow 8+2^0 \rightarrow 8+1 = 9$. Ini tepat mengenai indeks terakhir untuk array berukuran $n=10$, sehingga perhitungan menjadi tepat!

#### 2.1.3. Pengambilan nilai query

Perhatikan kode berikut, yang berada tepat dibawah nested loop pembuatan sparse table:

```cpp
lg.assign(n + 1, 0);
for (int i = 2; i <= n; i++) {
	lg[i] = lg[i / 2] + 1;
}
```

Apa kegunaan dari kode ini? Aku akan menjelaskanya nanti, karena terlebih dahulu, kita perlu mengetahui bagaimana kode dibawah ini bekerja:

```cpp
int query(int L, int R) {
    int len = lg[R - L + 1];
    return max(st[len][L], st[len][R - (1 << len) + 1]);
}
```

Ketika kita diberikan batasan rentang untuk mencari elemen maksimum dan minimum, yaitu adalah $L$ untuk batas kiri dan $R$ untuk batas kanan, dengan $L \leq R \leq n$, maka kita harus tahu bagaimana mengambil jawaban yang tepat dari sparse table yang sudah kita bangun.

Ingat ini! Dengan menggunakan sparse table, kompleksitas waktu untuk pencarian elemen maksimum dan minimum dari range queries adalah konstan atau $O(1)$, sangat efisien! Jadi kita harus tahu bagaimana cara mengambil jawaban dari sparse table kita.

Sparse table dibangun berdasarkan aturan bahwa suatu angka dapat disusun dari beberapa lego berbeda dengan nilai $2^k$. Penerapan ini tidak hanya digunakan untuk membangun sparse table, tapi juga untuk menyederhanakan panjang queries yang diberikan, dengan menjadikan nilai dari $\lfloor \text{log}_{2} \text{ } R-L+1 \rfloor$ sebagai penentu baris yang perlu digunakan pada sparse table.

Pertama-tama, untuk mengetahui panjang sebenarnya dari range queries, kita bisa mengambil nilai $R-L+1$. Kenapa menggunakan aturan ini? Karena jika semisal kita menghitung rentang queries dengan menghitung selisihnya saja, maka salah satu elemen akan tertinggal. Misal diberikan array $n=5$ dengan elemen $[1,2,3,4,5]$, dan $L=1$, dengan $R=4$. Rentang tersebut meminta kita untuk mengawasi elemen-elemen dari $[1,4]$ berikut: $[1,2,3,4]$. Disini kita tahu bahwa banyaknya elemen adalah $4$, bukan $R-L=3$. Supaya didapat panjang range yang sesuai, tambahkan $1$ pada selisih $R$ dan $L$, sehingga didapat rumus:

$$\text{len} = R - L + 1$$
Nilai dari panjang range sudah kita ketahui, selanjutnya adalah mencari nilai dari $\lfloor \text{log}_{2} \text{ len} \rfloor$, semisal kodenya adalah sebagai berikut:

```cpp
int len = static_cast<int>(floor(log2(R - L + 1)));
```

Kenapa kita mencari nilai $\lfloor \text{log}_{2} \text{ len} \rfloor$? 

Sparse Table hanya menyimpan jawaban untuk interval dengan panjang pangkat dua $2^k$.  
Saat query range $[L, R]$ dengan panjang $len$, kita harus memilih interval terbesar yang masih muat di dalam range, yaitu $2^k \le len$. Nilai $k$ terbesar yang memenuhi ini adalah $k = \lfloor \log_2(len) \rfloor$.

Dengan $k$ tersebut, range $[L, R]$ bisa dijawab memakai dua interval panjang $2^k$ (dari kiri dan kanan). Karena operasinya idempotent (min/max/gcd), overlap tidak masalah, dan hasilnya tetap benar dalam $O(1)$.

Setelah itu, kita cukup membandingkan elemen yang ada disparse table, yaitu elemen $max(x,y)$ jika mencari elemen maksimum, atau $min(x,y)$ jika mencari elemen minimum, dengan:

$$x = st[len][L] \;\;\;\;\;\;\; y=st[len][R-2^{len}+1]$$

Kita memakai $R - 2^{len}+1$ agar blok kanan yang memiliki panjang $2^{len}$, tetap berada di dalam range $[L, R]$, dan tepat menutup ujung kanan $R$, sehingga dua blok tersebut pasti mencakup seluruh query. Operasi $+1$ digunakan karena interval $[L,R]$ bersifat inklusif[^2], sehingga panjangnya dihitung sebagai $R-L+1$.

#### 2.1.4. Precompute nilai $\text{log}_2$

Oke, jika pengambilan data di sparse table bisa dilakukan dengan kompleksitas $O(1)$, lalu bagaimana dengan operasi menentukan nilai dari $len = \lfloor \text{log}_2 \; R-L+1 \rfloor$? Sayangnya operasi ini justru tidak memiliki kompleksitas konstan. 

Oleh karena itu, kita juga harus melakukan precompute nilai $\text{log}_2$ dari setiap nilai dari $[1,n]$, dengan menampung nilainya pada sebuah array berukuran $n+1$. Caranya adalah sebagai berikut:

```cpp
lg.assign(n + 1, 0);
for (int i = 2; i <= n; i++) {
	lg[i] = lg[i / 2] + 1;
}
```

Ini akan membangun nilai $\text{log}_2$ dari $[1,n]$ secara dynamic programming, hasilnya nanti seperti ini:

```
0 0 1 1 2 2 2 2 3 3 3
```

Pastikan juga bahwa ukuran dari array adalah $n+1$, ini akan mengcover semua ukuran range, termasuk ketika $len \equiv n$, atau ketika $L=1$ dan $R=n$.

Setelah itu, operasi pencarian $\lfloor \text{log}_2 \; R-L+1 \rfloor$ bisa dilakukan dengan kompleksitas $O(1)$, dengan hanya mengakses array precompute yang sudah kita buat, dengan $lg[R-L+1]$, dimana $lg$ adalah array precompute logaritma tersebut.

Berikut kodenya:

```cpp
int query(int L, int R) {
    int len = lg[R - L + 1];
    return max(st[len][L], st[len][R - (1 << len) + 1]);
}
```


#### 2.1.5. Array 1-based 

Perhatikan kode ini pada bagian `main()`:

```cpp
while (q--) {
	int l, r;
	cin >> l >> r;
	l--, r--;
	cout << query(l, r) << "\n";
}
```

Kenapa menggunakan `l--` dan `r--`?

Biasanya, soal memberikan indeks $l$ dan $r$ dengan penomoran dimulai dari $1$ (1-based indexing), sedangkan pada implementasi array di C++ indeks dimulai dari $0$ (0-based indexing). Oleh karena itu, dilakukan operasi `l--` dan `r--` untuk mengonversi indeks dari 1-based menjadi 0-based, sehingga akses elemen array dan perhitungan range pada fungsi `query` menjadi konsisten dan bebas dari kesalahan indeks.

Konversi ini diperlukan agar interval $[l, r]$ pada input sesuai dengan representasi interval $[l-1, r-1]$ pada array, sehingga algoritma dapat bekerja dengan benar.



### 2.2. Dynamic: Segment Tree



[^1]:Solusi pertama yang muncul dalam pikiran, biasanya pendekatan brute force.
[^2]:Suatu rentang atau interval dikatakan inklusif apabila kedua batasnya—batas awal dan batas akhir—diikutsertakan sebagai bagian dari rentang tersebut. Akibatnya, ukuran atau jumlah elemen dalam rentang inklusif dihitung dengan memasukkan kedua batas tersebut.