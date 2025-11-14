---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: 1380A
judul_DEATH: Three Indices
teori_DEATH:
sumber:
  - codeforces.com
rating: 900
ada_tips?:
date_learned: 2025-10-08T23:37:00
tags:
---
Sumber: [Problem - 1380A - Codeforces](https://codeforces.com/problemset/problem/1380/A)

```ad-tip
title:⚔️ Teori Death Ground
```

<br/>

---
# 1 | 1380A-Three Indices

Diberikan sebuah array permutasi berukuran $n$. Tentukan titik $i,j,k$, dimana $p_i < p_j > p_k$. Jika jawaban ada, maka outputkan `YES` dan tampilkan titik-titik indeks array dari $i,j,k$ (array 1-based index). 

Jika tidak ada jawaban yang memnuhi, maka outputkan `NO`.

<br/>

---
# 2 | Sesi Death Ground ⚔️

Karena array yang diberikan adalah array permutasi, maka hal yang harus diketahui adalah jelas tidak mungkin ada elemen duplikat, semua elemen pasti unik.

Hal pertama yang bisa dilakukan adalah menemukan letak index elemen terbesar. Jika indexnya ada di selain index pertama dan index terakhir, maka kita bisa langsung mengoutputkan nilainya, dengan nilai disebelah kiri dikurangi 1, dan sebelah kanan ditambah 1, dengan intuisi bahwa elemen terbesar ini bersifat unik.

Jika tidak, maka periksa lagi elemen yang lain. Dimana setiap elemen tersebut, kita traversal ke kiri dan kekanan, mencari apakah terdapat elemen yang lebih kecil di kedua arah. Jika ada, maka outputkan `YES`, dan letak elemen yang lebih kecil tadi.

Tapi jika pencarian ini tidak membuahkan hasil, maka outputkan saja `NO`.

Berikut adalah pendekatanku yang pertama kali benar:

```cpp
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    int maks = -1, idx = -1;
    for (int i=0; i<n; i++) {
        cin >> v[i];
        maks = max(maks, v[i]);
        if (maks == v[i]) {
            idx = i+1;
        }
    }

    if (idx != 1 && idx != n) {
        cout << "YES\n" << idx-1 << " " << idx << " " << idx+1 << '\n';
    } else {
        for (int i=1; i<n-1; i++) {
            int l=i-1, r=i+1;
            bool left=false, right = false;
            while (l>=0) {
                if (v[l] < v[i]) {
                    left = true;
                    break;
                }
                l--;
            }

            while (r<n) {
                if (v[r] < v[i]) {
                    right = true;
                    break;
                }
                r++;
            }

            if (left && right) {
                cout << "YES\n" << l+1 << " " << i+1 << " " << r+1 << '\n';
                return;
            }
        }

        cout << "NO\n";
    }
}

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
```

<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

**Solusi dalam $O(n^2)$**: ulangi (*iterate*) pada $j$, periksa bahwa terdapat elemen yang lebih rendah dari $a_j$ di sebelah kirinya, dan periksa bahwa terdapat elemen yang lebih rendah dari $a_j$ di sebelah kanannya. Ini dapat dioptimalkan menjadi **$O(n)$** dengan minima *prefix/suffix*.

**Solusi dalam $O(n)$**: perhatikan bahwa jika ada jawaban, kita dapat menemukan sebuah indeks $j$ sedemikian rupa sehingga $a_{j-1} < a_j$ dan $a_j > a_{j+1}$ (jika tidak ada rangkap tiga (triple) seperti itu, larik tersebut menurun hingga titik tertentu dan menaik setelah itu, jadi tidak ada jawaban). Jadi, kita hanya perlu memeriksa $n-2$ rangkap tiga yang berurutan.

Implementasi:

```cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 1000;

int n;
int a[N];

void solve() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 1; i < n - 1; ++i) {
		if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
			cout << "YES" << endl;
			cout << i << ' ' << i + 1 << ' ' << i + 2 << endl;
			return;
		}
	}
	cout << "NO" << endl;
}

int main() {
	int T;
	cin >> T;
	while (T--)
		solve();
}
```

## 3.2 | Analisis Pribadi

Aku melupakan bahwa ada kemungkinan deret array yang langsung memenuhi syarat dari problem. Walaupun aku berhasil dengan caraku, namun cara editorial mungkin lebih baik, karena kompleksitasnya lebih efisien, yaitu $O(n)$.
## 3.3 | Analisis Jawaban User Lain

### 1 | Jawaban Pertama

```cpp
#include<bits/stdc++.h>
using namespace std;

int a[10005];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        int p = 0;
        for (int i = 2; i <= n - 1; i++) {
            if (a[i] > a[i - 1] && a[i] > a[i + 1]) p = i;
        }
        if (p) cout << "YES" << endl << p - 1 << " " << p << " " << p + 1 << endl;
        else cout << "NO" << endl;
    }
}
```

Oalah, aku kelupaan satu hal. Pencarian nilai $i,j,k$ sebenarnya akan jauh lebih singkat jika dilakukan dengan perulangan biasa, alias kompleksitas $O(n)$. Pasti akan ada tiga deret elemen yang memenuhi kondisi ini, tanpa harus melakukan pengecekan jauh-jauh. 

Tapi, pendekatanku juga memiliki keuntungan sendiri, dimana mampu mendeteksi nilai $i$ dan $k$ yang lebih jauh, tanpa harus berdekatan.
### 2 | Jawaban Kedua

```cpp
#include <bits/stdc++.h>
using namespace std;

int w, n, pos, t[1002];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n, pos = 0;
        for (int i = 1; i <= n; i++) cin >> t[i];
        for (int i = 2; i < n; i++)
            if (t[i] > max(t[i - 1], t[i + 1])) pos = i;
        if (!pos) cout << "NO\n";
        else cout << "YES\n" << pos - 1 << " " << pos << " " << pos + 1 << "\n";
    }
    return 0;
}
```

Cara yang cukup cerdik, langsung saja gunakan fungsi `max` untuk menentukan apakah elemen sekarang, lebih besar dari kedua elemen yang bersampingan denganya.
### 3 | Jawaban Ketiga

```cpp
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;

#define endl '\n'
#define pb push_back
#define ff first
#define ss second
#define all(a) (a).begin(),(a).end()
#define mem(a,b) memset(a, b, sizeof(a) )

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)

void solution(){
        int n; cin>>n;
        vi a(n+1);
        rep1(i,n) cin>>a[i];
        for(int i=2;i<=n-1;i++){
            if(a[i]>a[i-1] && a[i]>a[i+1]){
                cout<<"YES"<<endl;
                cout<<i-1<<" "<<i<<" "<<i+1<<endl;
                return;
            }
        }
        cout<<"NO"<<endl;
}

int main()
{
    optimize();
    int t; cin>>t;
    while(t--){
        solution();
    }
    return 0;
}
```

Sekali lagi, cara yang simple memang ada, mungkin aku bisa mempersingkat kodeku, untuk membuat waktu penulisan menjadi lebih singkat. Kode ini juga hampir mirip dengan contoh pertama kode orang lain juga, yang menggunakan pendekatan mencari elemen dengan 2 tetangga yang lebih kecil. 