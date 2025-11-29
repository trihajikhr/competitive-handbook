---
obsidianUIMode: preview
note_type: death ground kilat
kode_soal: 58A
judul_DEATH: Chat room
teori_DEATH:
sumber:
  - codeforces.com
rating: 1000
ada_tips:
date_learned: 2025-11-29T13:12:00
tags:
  - greedy
  - strings
---
Sumber: [Problem - 58A - Codeforces](https://codeforces.com/problemset/problem/58/A)

```ad-tip
title:⚔️ Teori Death Ground
```

<br/>

---
# 1 | 58A-Chat room

Menggunakan string bantu, misal string $hel$ yang berisi kata `hello`, dan variabel indexing. Lakukan traversal terhadap string $s$. Setiap $s[i] \equiv hel[idx]$, maka lakukan increment terhadap $idx$. Jika $idx = 5$ pada proses traversal tersebut, maka artinya terdapat karakter yang dapat disusun menjadi `hello`, dan hentikan perulangan. Kenapa $idx=5$ baru di `break`? Karena `hello` memiliki 5 karakter, jadi harus pas $idx = 5$ untuk menandai bahwa karakter terakhir sudah dilewati:

```cpp
#include<iostream>  
using namespace std;  
  
auto main() -> int {  
    string s;  
    cin >> s;  
    string hel = "hello";  
    int idx = 0;  
    for (int i=0; i<s.length(); i++) {  
        if (s[i] == hel[idx]) idx++;  
        if (idx == 5) break;  
    }  
    cout << (idx == 5 ? "YES" : "NO");  
    return 0;  
}
```

<br/>

---
# 2 | Analisis Singkat

Banyak user yang memiliki solusi yang sama denganku, yaitu menggunakan string bantu yang menyimpang `hello`, dan lakukan pengecekan satu persatu hingga nilai dari variabel indexing bernilai tepat $5$.

```cpp
#include <bits/stdc++.h>
int main()
{
    char i{0}, c;
    while (std::cin >> c && i != 5)
        i += c == "hello"[i];
    std::cout << ((i == 5) ? "YES" : "NO");
}
```

```cpp
#include<bits/stdc++.h>
using namespace std;
int main() {
    string s, h = "hello";
    cin >> s;
    int j = 0;
    for (char c : s) 
        if (c == h[j]) j++;
    cout << (j == 5 ? "YES" : "NO");
}
```

```cpp
#include<iostream>
using namespace std;
int main(){
	string s="hello";
	string ss;
	cin>>ss;
	int i,j;
	for( i=0,j=0 ;i<ss.size();i++){
		if(ss[i]==s[j])
		j++;
	}
	if(j==5)cout<<"YES";
	else cout<<"NO";
	return 0;
}
```

```cpp
#include<iostream>
using namespace std;
int main(){
    string a,b;
    cin>>a;
    b="hello";
    int j=0,count=0;
    for(int i=0;i<a.length();i++)
    {
        if(a[i]==b[j])
        {
            j++;
            count++;
        }
    }
    if(count==5)
    {
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
}
```

```cpp
#include <bits/stdc++.h>
#include <string>
using namespace std;
    
int main(){
    
    string word, hello="hello";
    cin >> word;
    int j=0, count=0;
   
    for(int i=0; i<word.length();i++){
        if(word[i]==hello[j]){
            j++;
            count++;
        }
    }
    
    if(count==5){
        cout<<"YES";
    }
    else {
        cout<<"NO";
    }
    return 0;
}
```

```cpp
#include <iostream>
using namespace std;
int main() {
string st;cin>>st;
string st1="hello";
int c=0;
for(int i=0;i<st.size();++i){
    if(st1[c]==st[i])
    {
        c++;
     if(c==5){
        break;
     }
    }
}
 if(c==5){
      cout<<"YES\n";
     }
     else{
        cout<<"NO\n";
     }


    return 0;
}
```