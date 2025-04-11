---
obsidianUIMode: preview
note_type: tips trick
tips_trick: template code cp
sumber: "buku: CP handbook by Antti Laaksonen & chatgpt.com"
tags:
  - introduction
  - template-code
---
#introduction #template-code

---
# Template code untuk CP
Dalam competitive programming, terdapat banyak cara yang bisa dilakukan untuk memaksimalkan kinerja kode program. Entah itu memudahkan dan mempercepat penulisan kode program, mempercepat eksekusi program, dan efisiensi lainya. Hal ini biasanya sudah tersusun sedemikian rupa dengan template code tertentu yang biasa digunakan dalam CP. 

Berikut diantaranya:

---
## Basic template kode 
Template kode C++:

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){	
	// kode program

	return 0;
}
```

**Header `<bits/stdc++.h>`** → Mengimpor semua pustaka STL sekaligus (hanya untuk CP, tidak dianjurkan di produksi). Sehingga kita tidak perlu lagi mengimpor satu persatu pustaka kedalam kode.

Penggunaan `using namespace std` mendeklarasikan bahwa kelas dan fungsi dari pustaka standar dapat digunakan langsung dalam kode. Tanpa baris ini, kita harus menulis, misalnya, `std::cout`, tetapi sekarang cukup menulis `cout`.

**\#include <bits/stdc++.h>** adalah sebuah header file "all-in-one" yang tersedia di banyak compiler berbasis GCC (GNU Compiler Collection). Header ini meng-include hampir semua pustaka standar C++ dalam satu perintah, yang membuatnya populer di kalangan programmer kompetitif untuk menghemat waktu saat menuliskan kode.
### Apa yang Ada di Dalam `bits/stdc++.h`?

Ketika Anda menuliskan `#include <bits/stdc++.h>`, ini akan menyertakan hampir seluruh pustaka C++ standar, termasuk:

- `<iostream>`: Untuk input dan output standar.
- `<vector>`, `<list>`, `<deque>`, `<queue>`, `<stack>`, `<map>`, `<set>`, `<unordered_map>`, `<unordered_set>`: Struktur data STL (Standard Template Library).
- `<algorithm>`: Fungsi-fungsi algoritmik seperti `sort`, `find`, `reverse`, dll.
- `<cmath>`, `<cstdio>`, `<cstdlib>`, `<cstring>`: Fungsi-fungsi matematika, manipulasi string C, dan fungsi I/O.
- `<string>`, `<sstream>`: Pustaka untuk memanipulasi string.
- `<functional>`: Mendukung pemrograman fungsional seperti `std::function`, `std::bind`, dll.
- `<utility>`: Struktur data `pair`, `std::swap`, dll.
### Keuntungan Menggunakan `#include <bits/stdc++.h>`

1. **Menghemat Waktu**: Dengan satu baris `#include <bits/stdc++.h>`, programmer mendapatkan akses ke hampir semua pustaka C++ standar yang mungkin diperlukan. Ini sangat berguna dalam kompetisi pemrograman, di mana waktu sangat penting.

2. **Kode Lebih Ringkas**: Karena mencakup semua header, kode menjadi lebih singkat dan mudah dibaca tanpa daftar panjang header yang perlu di-include satu per satu.
### Kekurangan Menggunakan `#include <bits/stdc++.h>`

1. **Membuat Kompilasi Lebih Lambat**: Menggunakan `#include <bits/stdc++.h>` meng-include semua pustaka standar, sehingga waktu kompilasi dapat menjadi lebih lambat karena harus memuat lebih banyak pustaka daripada yang sebenarnya diperlukan.

2. **Tidak Portabel**: Header ini tidak termasuk dalam standar C++ dan hanya tersedia di GCC. Jika Anda mencoba menjalankan kode ini di compiler lain (seperti MSVC atau Clang tanpa kompatibilitas GCC), kompilasi kemungkinan besar akan gagal.

3. **Pemakaian Memori yang Lebih Tinggi**: Karena banyak pustaka yang di-include, program mungkin akan menggunakan lebih banyak memori.
### Kesimpulan

`#include <bits/stdc++.h>` adalah header praktis yang digunakan dalam pemrograman kompetitif untuk menghemat waktu. Namun, untuk proyek yang lebih besar atau produksi, disarankan untuk meng-include pustaka yang benar-benar diperlukan saja agar kompilasi lebih cepat, memori lebih efisien, dan kode lebih portabel.

---
## Advanced template code

> Untuk bisa memahami dengan baik Advanced template code ini, pelajari terlebih dahulu materi bab **01-Introduction** hingga selesai! 

Template kode dalam _competitive programming_ biasanya dirancang agar ringkas, cepat, dan mempermudah pengambilan input serta pemrosesan data. Berikut adalah **template umum** yang sering digunakan:

### 1. Template Dasar Competitive Programming (CP)

```cpp
#include <bits/stdc++.h> 
using namespace std;

#define fastio() ios_base::sync_with_stdio(0); cin.tie(0);
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rev(i, a, b) for (int i = a; i >= b; i--)

const int MOD = 1e9 + 7;
const int INF = INT_MAX;

void solve() {
	// kode program
}

int main() {

    fastio();
	// kode program
	
    return 0;
}
```

Contoh Penggunaan:

```cpp
#include <bits/stdc++.h> 
using namespace std;

#define fastio() ios_base::sync_with_stdio(0); cin.tie(0);
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rev(i, a, b) for (int i = a; i >= b; i--)

const int MOD = 1e9 + 7;
const int INF = INT_MAX;

void solve() {
    int n;
    cin >> n;
    vi arr(n);
    for (int &x : arr) cin >> x;

    sort(all(arr)); // Contoh operasi
    cout << arr[n / 2] << "\n"; // Contoh output
}

int main() {
    fastio();
    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
```

---

### 2. Penjelasan dan Fitur:

1. **Header `<bits/stdc++.h>`** → Mengimpor semua pustaka STL sekaligus (hanya untuk CP, tidak dianjurkan di produksi).
2. **`fastio()`** → Mempercepat input/output untuk menghindari _TLE_ (Time Limit Exceeded).
3. **Alias & Macro (`#define`)**
    - `ll` → `long long`
    - `vi` → `vector<int>`
    - `vll` → `vector<long long>`
    - `pii` → `pair<int, int>`
    - `pb` → `push_back()`
    - `all(x)` → `x.begin(), x.end()` (memudahkan penggunaan `sort()` dan lainnya)
    - `sz(x)` → `x.size()`
4. **Looping Cepat**
    - `rep(i, a, b)` → Loop dari `a` sampai `b-1`
    - `rev(i, a, b)` → Loop mundur dari `a` sampai `b`
5. **`solve()` function** → Struktur umum dalam CP untuk menangani satu kasus uji.
6. **Modular Arithmetic** → `const int MOD = 1e9 + 7;` sering digunakan dalam perhitungan besar.

---

### 3. Variasi Template untuk CP

#### (a) Jika Butuh Graph / BFS / DFS

```cpp
vector<vector<int>> adj;
vector<bool> visited;

void dfs(int node) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}
```

#### (b) Jika Butuh Binary Search

```cpp
int binary_search(vector<int>& arr, int target) {
    int l = 0, r = sz(arr) - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) l = mid + 1;
        else r = mid - 1;
    }
    return -1; // Tidak ditemukan
}
```

#### (c) Jika Butuh Modular Exponentiation

```cpp
ll mod_exp(ll base, ll exp, ll mod) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}
```

---

### 4. Kapan Menggunakan Template Ini?

✅ **CP Kontes Online (Codeforces, AtCoder, CodeChef, dsb.)**  
✅ **Soal yang butuh banyak optimasi input/output**  
✅ **Soal yang butuh struktur data kompleks (Graph, Segment Tree, dsb.)**

Template ini dapat disesuaikan dengan kebutuhan spesifikmu. 🚀

---

## Real man Template code

Haha, diluar sana juga ada banyak praktisi CP yang berbagi template codenya, jadi kita juga bisa mengambil tempalte code tersebut, dan merubahnya atau menggunakanya sesuai selera kita. Berikut diantaranya:


> [!NOTE] Jangan terlalu kaku!
> Template code dari orang lain ini mungkin terlalu banyak jika benar-benar digunakan. Tidak semua template code ini benar-benar dibutuhkan. Jadi, gunakan sebagai bahan referensi, dan tulis template code yang sesuai dengan kondisi dan kebutuhanmu saat ini!

### 1. Neilblaze (Github)
Source: [CP Template — C++ \</\> · GitHub](https://gist.github.com/Neilblaze/dcf6113fa5e63fc938502f1d742365c4#file-cpp_template-cpp)

```cpp
#include <bits/stdc++.h>
using namespace std;

/* clang-format off */

/* TYPES  */
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>

/* FUNCTIONS */
#define f(i,s,e) for(long long int i=s;i<e;i++)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)
#define rf(i,e,s) for(long long int i=e-1;i>=s;i--)
#define pb push_back
#define eb emplace_back

/* PRINTS */
template <class T>
void print_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}"; }

/* UTILS */
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define read(type) readInt<type>()
ll min(ll a,int b) { if (a<b) return a; return b; }
ll min(int a,ll b) { if (a<b) return a; return b; }
ll max(ll a,int b) { if (a>b) return a; return b; }
ll max(int a,ll b) { if (a>b) return a; return b; }
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

/*  All Required define Pre-Processors and typedef Constants */
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;


/* clang-format on */

/* Main()  function */
int main()
{

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	#endif

	int tc;
	tc = read(int);

	while(tc--){
		write(tc);
	}
	return 0;
}
/* Main() Ends Here */
```

Dengan ekstras:

```cpp
#define f first
#define s second
#define endl '\n'
#define sp <<" "<<
#define pb push_back
#define MOD 1000000007
#define fora(a) for(auto u:a)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b)))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define test int tc; cin>>tc; while(tc--)
#define forn(i,n) for(auto i=0; i<n; i++)
#define printv(a) {for(auto u:a) cout<<u<<" "; cout<<endl;}
#define printm(a) {for(auto u:a) cout<<u.f sp u.s<<endl;}
#define op() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fori(a,b,c) {for(a = c.begin(); a!=b; a++) cout<< *a<< " "; cout<<endl;}
#define fraction(a) cout.unsetf(ios::floatfield); cout.precision(a); cout.setf(ios::fixed,ios::floatfield);
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<int>::iterator vit;
typedef set<int> si;
typedef map<int, int> mii;
const double eps = 1e-9;
```

### 2. ncduy0303 (Github)

Source: [Competitive-Programming/Contest Template](https://github.com/ncduy0303/Competitive-Programming/blob/master/Contest%20Template/main.cpp)

```cpp
#include <bits/stdc++.h>

using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;



void solve() {
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}
```

### 3. 7oSkaaa (Github)

Source: [CP-Templates/Template.cpp at main · 7oSkaaa/CP-Templates · GitHub](https://github.com/7oSkaaa/CP-Templates/blob/main/Template.cpp#L39)

```cpp
#include <bits/stdc++.h>

using namespace std;

#define fixed(n) fixed << setprecision(n)
#define ceil(n, m) (((n) + (m) - 1) / (m))
#define add_mod(a, b, m) (((a % m) + (b % m)) % m)
#define sub_mod(a, b, m) (((a % m) - (b % m) + m) % m)
#define mul_mod(a, b, m) (((a % m) * (b % m)) % m)
#define all(vec) vec.begin(), vec.end()
#define rall(vec) vec.rbegin(), vec.rend()
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << (x) << "\n";
#define fi first
#define se second
#define ll long long
#define ull unsigned long long
#define EPS 1e-9
constexpr int INF = 1 << 30, Mod = 1e9 + 7;
constexpr ll LINF = 1LL << 62;
#define PI acos(-1)
template < typename T = int > using Pair = pair < T, T >;
vector < string > RET = {"NO", "YES"};

template < typename T = int > istream& operator >> (istream &in, vector < T > &v) {
    for (auto &x : v) in >> x;
    return in;
}

template < typename T = int > ostream& operator << (ostream &out, const vector < T > &v) { 
    for (const T &x : v) out << x << ' '; 
    return out;
}

void Solve(){
    
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int test_cases = 1;
    // cin >> test_cases;
    for(int tc = 1; tc <= test_cases; tc++){
        // cout << "Case #" << tc << ": ";
        Solve();
    }
    return 0;
}
```