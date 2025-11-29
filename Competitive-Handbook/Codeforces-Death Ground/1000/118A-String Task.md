---
obsidianUIMode: preview
note_type: death ground kilat
kode_soal: 118A
judul_DEATH: String Task
teori_DEATH:
sumber:
  - codeforces.com
rating: 1000
ada_tips:
date_learned: 2025-11-29T12:44:00
tags:
  - implementation
  - strings
---
Sumber: [Just a moment...](https://codeforces.com/problemset/problem/118/A)

```ad-tip
title: 🛡️ Review Death Ground
Gunakan variabel bantu yang menyimpan kumpulan karakter yang ingin digunakan sebagai filter, dan andalkan fungsi `find()`.
```

<br/>

---
# 1 | 118A-String Task

Mudah, cukup buat string bantu misal $vow$ yang berisi daftar karakter yang merupakan karakter huruf vokal, dan lakukan traversal pada string. Jika vokal, maka skip, jika tidak, maka outputkan `.` dan karakter konsonan:

```cpp
#include<iostream>
#include<string>
#include<cctype>
using namespace std;
 
auto main() -> int {
    string s;
    cin >> s;
 
    string vow = "aoyeui";
    for (char&c : s) {
        c = tolower(c);
        if (vow.find(c) != string::npos) {
            continue;
        }
        cout << "." << c;
    }
    return 0;
}
```

<br/>

---
# 2 | Analisis Singkat

Menggunakan string bantu dan mengandalkan fungsi seperti `strchr()` atau `find()`, atau menggunakan kondisional manual dengan menggunakan operator `or`. Keduanya bisa digunakan dan sama-sama efisien. Ada juga yang membuat fungsi `isVowel()` yang isinya adalah pengecekan apakah karakter `x` adalah karakter vokal atau tidak.

```cpp
#import <bits/stdc++.h>
char a[] = "aoyeui", c;
main()
{
    while (std::cin >> c)
        if (!strchr(a, c |= 32))
            std::cout << '.' << c;
}
```

```cpp
#include<bits/stdc++.h>
int main(){
char str[100];
int i;
scanf("%s",str);
for(i=0;i<strlen(str);i++)
    if(!strchr("AEIOUYyaeiou",str[i]))
        printf(".%c",tolower(str[i]));
}
```

```cpp
#include <iostream>
using namespace std;
 
int main() {
	char x;
	while(cin>>x){
		x=tolower(x);
		if(x!='a' && x!='o' && x!='y' && x!='e' && x!='u' && x!='i'){
			cout<<'.'<<x;
		}
	}
	return 0;
}
```

```cpp
#include <iostream>
#include <cstring>
using namespace std;

int main() {
	string s;
	cin>>s;
	string result;
	for(int i=0;i<s.size();i++){
	    char ch=tolower(s[i]);
	    if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='y'){
	       continue; 
	    }else{
	       cout<<"."<<ch;
	    }
	}
	cout<<result;
	return 0;
}
```

```cpp
#include <bits/stdc++.h>
#define MAXN 100
using namespace std;

char s[MAXN + 10];

bool isVowel(char x) {
    return x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' || x == 'y';
}

int main() {
    scanf("%s", s + 1);
    for (int i = 1; s[i]; i++) {
        int x;
        if (s[i] >= 'A' && s[i] <= 'Z') x = s[i] - 'A';
        else x = s[i] - 'a';
        if (isVowel(x + 'a')) continue;
        printf(".%c", x + 'a');
    }
    printf("\n");
    return 0;
}

```