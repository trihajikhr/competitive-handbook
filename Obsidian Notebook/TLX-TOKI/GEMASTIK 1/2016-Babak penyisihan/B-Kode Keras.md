---
obsidianUIMode: preview
note_type: latihan
latihan: Kode Keras
sumber:
  - tlx-toki
tags:
  - gemastik
date_learned: 2025-07-19T18:47:00
---
Link sumber: [Gemastik2016 Kode Keras](https://tlx.toki.id/problems/gemastik-2016-pemrograman-penyisihan/B)

---
# Kode Keras
### Deskripsi
Niken adalah seorang gadis yang sedang amat mendambakan pasangan hidup. Niken sebenarnya punya banyak teman yang ia harapkan bisa menjadi pasangan hidupnya. Namun, Niken adalah tipe orang yang tidak berkata langsung, melainkan melalui kode-kode.

Niken melakukan kode dengan cara menulis status-status bertemakan cinta pada sosial media (misalnya Facebook), dan berharap sang pujaan hati melihat postingan tersebut dan tergerak hatinya. Jika Niken menulis status pada suatu waktu tertentu, maka semua teman Niken yang _online_ pada waktu tersebut akan melihat status tersebut. Tentu Niken tidak mau kode ini salah sasaran. Oleh karena itu, ia berniat menulis status berkali-kali, dengan tujuan sang pujaan hati melihat kode Niken lebih banyak dibandingkan teman-teman Niken yang lain. Tetapi Niken juga tidak mau menulis status terlalu banyak, karena khawatir dinilai terlalu galau oleh teman- temannya.

Anda diberikan $N$ yang menyatakan banyaknya teman Niken, serta rentang waktu kapan teman ke-$i$ tersebut _online_ dalam $S[i]$ dan $E[i]$. Suatu status akan dibaca oleh teman ke-$i$ apabila status tersebut ditulis pada waktu $X$ yang memenuhi

$$S[i] ≤ X < E[i]$$

Karena Niken merahasiakan kepada Anda siapa pujaan hatinya, Anda harus mencari tahu untuk setiap $i$, berapa status minimum yang harus ditulis jika Niken ingin melakukan kode terhadap teman ke-$i$. Dengan kata lain, Anda ingin mencari tahu untuk setiap $i$, berapa status minimum yang harus ditulis agar teman ke-$i$ melihat status Niken **lebih banyak** daripada setiap teman lainnya.
### Format Masukan
Baris pertama berisi sebuah bilangan bulat $T$ yang menyatakan banyaknya kasus uji.

Untuk setiap kasus uji, baris pertama berisi sebuah bilangan bulat $N$. $N$ baris berikutnya masing-masing berisi dua buah string $S[i]$ dan $E[i]$, yang ditulis dalam format waktu `hh:mm:ss`. Waktu paling awal adalah 00:00:00 dan waktu paling akhir adalah 23:59:59.

### Format Keluaran
Untuk setiap kasus uji:

Keluarkan sebuah baris berisi banyaknya status minimum yang harus ditulis untuk melakukan kode kepada teman ke-$i$, atau $-1$ apabila hal tersebut tidak mungkin.
### Contoh Masukan
```
2
4
08:00:00 09:00:00
08:20:00 08:45:00
08:05:00 09:40:00
08:15:00 10:00:00
3
00:00:00 00:00:01
00:00:01 00:00:10
00:00:02 00:00:10
```

### Contoh Keluaran

```
1
-1
2
1
1
1
-1
```

### Penjelasan
Untuk contoh masukan pertama:

1. Untuk memberi kode pada teman 1, Niken dapat menulis status pada 08:00:00:
    - Teman 1 melihat status Niken 1 kali.
    - Teman 2, 3, dan 4 tidak pernah melihat status Niken.
2. Niken tidak mungkin memberi kode pada teman 2 karena setiap kali teman 2 melihat status Niken, teman 1 dan 3 pasti juga melihatnya. Tidak mungkin membuat teman 2 melihat status Niken lebih banyak daripada teman 1 dan 3.
3. Untuk memberi kode pada teman 3, Niken dapat menulis status pada 08:10:00 dan 09:20:00:
    - Teman 1 dan 4 melihat status Niken 1 kali.
    - Teman 2 tidak pernah melihat status Niken.
    - Teman 3 melihat status Niken 2 kali.
4. Untuk memberi kode pada teman 4, Niken dapat menulis status pada 09:59:59:
    - Teman 1, 2, dan 3 tidak pernah melihat status Niken.
    - Teman 4 melihat status Niken 1 kali.

Untuk contoh masukan kedua:

1. Untuk memberi kode pada teman 1, Niken dapat menulis status pada suatu waktu sebelum 00:00:01 (tidak harus bulat).
2. Untuk memberi kode pada teman 2, Niken dapat menulis status pada 00:00:01.
3. Niken tidak mungkin memberi kode pada teman 3.

### Batasan

- $1≤T≤10$
- $1 ≤ N ≤ 50000$
- Waktu yang direpresentasikan oleh $S[i]$ < waktu yang direpresentasikan oleh $E[i]$

# Editorial Resmi
Pertama-tama, perhatikan bahwa hanya ada 3 kemungkinan jawaban: $-1$, $1$, dan $2$.

- $-1$ artinya tidak mungkin. Ini terjadi jika interval $i$ berada di dalam interval lain $j$. Dengan kata lain, terdapat $j\; != \;i$ dengan $S[j] ≤ S[i] < E[i] ≤ E[j]$.  
- $1$ artinya ada waktu $X$ dengan $S[i] ≤ X < E[i]$, dan tidak ada orang lain selain $i$ yang online pada waktu $X$.
- Jika kondisi $-1$ dan $1$ tidak terjadi, maka jawabannya pasti $2$. Pembaca dipersilakan untuk membuktikan sendiri kenapa jawaban tidak mungkin lebih dari 2.

Berdasarkan analisis tersebut, kita tinggal mendeteksi apakah setiap interval $i$ termasuk pada kasus $-1$ atau $1$.


#### Kasus -1:
Terdapat $86.400$ kemungkinan waktu (1 hari = $86.400$ detik). Untuk setiap waktu $X$, carilah interval $k$ yang melingkupi $X$ dan memiliki nilai $E$ terbesar. Hal ini dapat dilakukan dengan metode *line sweep* atau *sliding window*.

Pada setiap waktu $X$, asumsikan variabel $k$ adalah suatu interval dengan $S[k] \leq X \leq E[k]$ yang mana $E[k]$ adalah terbesar di antara semua $k$.

Setiap kali kita iterasi nilai $X$ baru, jika itu sama dengan suatu $S[i]$, cek apakah nilai $E[i]$ lebih besar daripada $E[k]$. Jika iya, perbarui nilai $k$ dengan $i$. Jika tidak, maka dapat dijamin bahwa interval $i$ tertutup oleh interval $k$. Artinya, interval $i$ masuk dalam kasus $-1$.

Perlu diperhatikan juga, jika ada dua interval yang identik, maka kedua interval tersebut masuk dalam kasus $-1$.

#### Kasus 1:
Kita bisa melakukan *line sweep* serupa dengan kasus $-1$.

1. Pertama-tama, kumpulkan semua titik $S[i]$ dan $E[i]$, kemudian urutkan.
2. Siapkan juga sebuah struktur data berupa set.
3. Iterasi semua titik secara berurutan.

Untuk setiap titik:

* Jika itu adalah $S[i]$, maka masukkan $i$ ke dalam set.
* Jika itu adalah $E[i]$, maka keluarkan $i$ dari set.

Jika pada suatu waktu $X$, set tersebut tepat berisi satu anggota, maka anggota set tersebut masuk ke dalam kasus 1.

## Jawaban User 
Aku mengambil salah satu jawaban peserta, dimana jawabanya sudah benar. Jawaban ini juga menempati salah satu peringkat penggunaan memory dan runtime paling efisien di leaderboard:

```cpp
#include<map>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

bool comp(pair<pair<int, int>, int> A, pair<pair<int, int>, int> B){
    if(A.first.first == B.first.first){
        return A.first.second > B.first.second;
    } else return A.first.first < B.first.first;
}

int convert(string &s){
    int sum = 3600 * stoi(s.substr(0,2));
    sum += 60 * stoi(s.substr(3,2));
    sum += stoi(s.substr(6,2));
    return sum;
}

void solve(){
    int n; cin >> n;
    pair<pair<int, int>, int> arr[50055];

    for(int i=1; i<= n; i++){
        string S, E;
        cin >> S >> E;
        arr[i].first = {convert(S), convert(E)-1};
        arr[i].second = i;
    }

    arr[n+1].first = {86401, 86401};
    int m = 86455;
    vector<int> coor(m, 0);
    vector<int> ans (n+5,0);

    for(int i=1; i<=n; i++){
        coor[arr[i].first.first]++;
        coor[arr[i].first.second+1]--;
    }

    vector<int> kosong;
    for(int i=0; i<m; i++){
        if(i != 0) coor[i] += coor[i-1];
        if(coor[i] == 1) kosong.push_back(i);
    }

    sort(arr+1, arr+n+1, comp);

    int mx = -1;
    for(int i=1; i<=n; i++){
        if(arr[i].first.second <= mx) ans[arr[i].second] = -1;
        if(arr[i].first == arr[i+1].first) ans[arr[i].second] = -1;
        mx = max(arr[i].first.second, mx);
    }

    for(int i=1; i<= n; i++){
        auto it = lower_bound(kosong.begin(), kosong.end(), arr[i].first.first);
        if(it != kosong.end() && *it <= arr[i].first.second){
            ans[arr[i].second] = 1;
        } 
    }

    for(int i=1; i<=n; i++){
        if(ans[i] == 1 || ans[i] == -1){
            cout << ans[i] << endl;
        } else cout << 2 << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
```