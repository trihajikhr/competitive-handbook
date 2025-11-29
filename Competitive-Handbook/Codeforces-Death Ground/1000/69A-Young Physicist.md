---
obsidianUIMode: preview
note_type: death ground kilat
kode_soal: 69A
judul_DEATH: Young Physicist
teori_DEATH:
sumber:
  - codeforces.com
rating: 1000
ada_tips:
date_learned: 2025-11-29T12:59:00
tags:
  - implementation
  - math
---
Sumber: [Problem - 69A - Codeforces](https://codeforces.com/problemset/problem/69/A)

```ad-tip
title:⚔️ Teori Death Ground
```

<br/>

---
# 1 | 69A-Young Physicis

BUat 3 variabel untuk menampung 3 jenis inputan, atau buat saja array dengan ukuran 3. Setelah itu, setiap inputan yang dimasukan, tamabhkann kedalam variabel akumulasi tadi. Jika ketiga variabel tersebut bernilai sama, dan sama-sama bernilai $0$, maka outputkan `YES`. Sebaliknya, outputkan `NO`:

```cpp
#include<iostream>
#include<array>
using namespace std;

auto main() -> int {
    ios::sync_with_stdio(false);;
    cin.tie(nullptr);
    int t;
    cin >> t;
    array<int, 3> arr{0,0,0};
    while (t--) {
        for (int i=0, x; i<3; i++) {
            cin >> x;
            arr[i] += x;
        }
    }

    if ((arr[0] == arr[1]) && (arr[2] == 0) && (arr[0] == arr[2])) {
        cout << "YES";
    } else cout << "NO";

    return 0;
}
```



<br/>

---
# 2 | Analisis Singkat

Mayoritas menggunakan 3 jenis variabel, dan menambahkan inputan kedalam 3 variabel tersebut, lalu melakukan pemeriksaan apaka ketiganya adalah bernilai $0$ atau tidak. Simple.

```cpp
#include<iostream>
int n,a,b,c,d,e,f;
main(){
    std::cin>>n;
    while(n--){
        std::cin>>a>>b>>c,d+=a,e+=b,f+=c;
        
    }
    std::cout<<(d|e|f?"NO":"YES");
    
}
```

```cpp
#include<bits/stdc++.h>
int a,b,c,Ts,x,y,z;
int main(){
	std::cin>>Ts;
	while(Ts--){
	std::cin>>a>>b>>c;x+=a,y+=b,z+=c;}
	if(!x&&!y&&!z) std::puts("YES");
	else std::puts("NO");
	return 0;
}
```

```cpp
#include<iostream>
using namespace std;
 
int x,y,z,a,b,c;
int n;
 
int main() {
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a>>b>>c;
		x+=a,y+=b,z+=c; 
	}
	
	if(x||y||z) cout<<"NO"<<endl;
	else cout<<"YES"<<endl;
	return 0;
}
```

```cpp
#include <iostream>
#include <vector>
using namespace std;

#define int long long

signed main() 
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int a;
    cin >> a;
    
    vector<vector<int>> arr(a, vector<int>(3)); // Initialize 2D vector
    
    for(int i = 0; i < a; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> arr[i][j];
        }
    }
    
    int ans[3] = {0}; // Initialize ans array
    
    for(int i = 0; i < a; i++) {
        for(int j = 0; j < 3; j++) {
            ans[j] += arr[i][j];
        }
    }
    
    bool answer = true;
    
    for(int i = 0; i < 3; i++) {
        if(ans[i] != 0) {
            answer = false;
            break;
        }
    }
    
    if(answer) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
    
    return 0;
}
```

```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
 int x=0,y=0,z=0;
 int t;
 cin>>t;
 while(t--){
   int a,b,c;
   cin>>a>>b>>c;
   x+=a;
   y+=b;
   z+=c;
 }
 if(x==0 && y==0 && z==0)cout<<"YES"<<endl;
 else cout<<"NO"<<endl;
 
 return 0;
}
```