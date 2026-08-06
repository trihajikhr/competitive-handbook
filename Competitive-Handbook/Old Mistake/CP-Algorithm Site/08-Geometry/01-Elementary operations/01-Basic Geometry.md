---
obsidianUIMode: preview
note_type: Book Theory
judul_materi: Basic Geometry
sumber:
  - cp-algorithms.com
date_learned: 2025-11-05T21:44:00
tags:
  - geometry
  - cp-algorithms
---
Link Sumber: [Basic Geometry - Algorithms for Competitive Programming](https://cp-algorithms.com/geometry/basic-geometry.html)

---
# Basic Geometry

Dalam artikel ini kita akan membahas operasi dasar pada titik (_points_) dalam ruang Euklides (_Euclidean space_) yang menjadi fondasi dari keseluruhan geometri analitik. Kita akan mempertimbangkan untuk setiap titik $\mathbf{r}$ vektor $\vec{\mathbf{r}}$ yang diarahkan dari $\mathbf{0}$ ke $\mathbf{r}$. Selanjutnya kita tidak akan membedakan antara $\mathbf{r}$ dan $\vec{\mathbf{r}}$ dan menggunakan istilah **titik** sebagai sinonim untuk **vektor**.

## 1 | Linear operations

Baik titik 2D maupun 3D mempertahankan ruang linear (_linear space_), yang berarti bahwa untuk mereka, penjumlahan titik-titik dan perkalian titik dengan suatu bilangan terdefinisi. Berikut adalah implementasi dasar untuk 2D:

```cpp
struct point2d {
    ftype x, y;
    point2d() {}
    point2d(ftype x, ftype y): x(x), y(y) {}
    point2d& operator+=(const point2d &t) {
        x += t.x;
        y += t.y;
        return *this;
    }
    point2d& operator-=(const point2d &t) {
        x -= t.x;
        y -= t.y;
        return *this;
    }
    point2d& operator*=(ftype t) {
        x *= t;
        y *= t;
        return *this;
    }
    point2d& operator/=(ftype t) {
        x /= t;
        y /= t;
        return *this;
    }
    point2d operator+(const point2d &t) const {
        return point2d(*this) += t;
    }
    point2d operator-(const point2d &t) const {
        return point2d(*this) -= t;
    }
    point2d operator*(ftype t) const {
        return point2d(*this) *= t;
    }
    point2d operator/(ftype t) const {
        return point2d(*this) /= t;
    }
};
point2d operator*(ftype a, point2d b) {
    return b * a;
}
```

Dan titik 3D:

```cpp
struct point3d {
    ftype x, y, z;
    point3d() {}
    point3d(ftype x, ftype y, ftype z): x(x), y(y), z(z) {}
    point3d& operator+=(const point3d &t) {
        x += t.x;
        y += t.y;
        z += t.z;
        return *this;
    }
    point3d& operator-=(const point3d &t) {
        x -= t.x;
        y -= t.y;
        z -= t.z;
        return *this;
    }
    point3d& operator*=(ftype t) {
        x *= t;
        y *= t;
        z *= t;
        return *this;
    }
    point3d& operator/=(ftype t) {
        x /= t;
        y /= t;
        z /= t;
        return *this;
    }
    point3d operator+(const point3d &t) const {
        return point3d(*this) += t;
    }
    point3d operator-(const point3d &t) const {
        return point3d(*this) -= t;
    }
    point3d operator*(ftype t) const {
        return point3d(*this) *= t;
    }
    point3d operator/(ftype t) const {
        return point3d(*this) /= t;
    }
};
point3d operator*(ftype a, point3d b) {
    return b * a;
}
```


Di sini, **`ftype`** adalah tipe (_type_) yang digunakan untuk koordinat, biasanya `int`, `double`, atau `long long`.

## 2 | Dot product

### 2.1 | Definition

Produk titik (*dot product*) (atau produk skalar (_scalar product_)) $\mathbf{a} \cdot \mathbf{b}$ untuk vektor $\mathbf{a}$ dan $\mathbf{b}$ dapat didefinisikan dalam dua cara yang identik. Secara geometris, ini adalah perkalian panjang vektor pertama dengan panjang proyeksi (_projection_) vektor kedua ke vektor pertama. Seperti yang dapat Anda lihat dari gambar di bawah, proyeksi ini hanyalah $|\mathbf{a}| \cos \theta$, di mana $\theta$ adalah sudut antara $\mathbf{a}$ dan $\mathbf{b}$. Jadi, $\mathbf{a} \cdot \mathbf{b} = |\mathbf{a}| \cos \theta \cdot |\mathbf{b}|$.


![[01-Basic Geometry-1.png]]


Produk titik memiliki beberapa properti penting:

1. $\mathbf{a} \cdot \mathbf{b} = \mathbf{b} \cdot \mathbf{a}$
2. $(\alpha \cdot \mathbf{a}) \cdot \mathbf{b} = \alpha \cdot (\mathbf{a} \cdot \mathbf{b})$
3. $(\mathbf{a} + \mathbf{b}) \cdot \mathbf{c} = \mathbf{a} \cdot \mathbf{c} + \mathbf{b} \cdot \mathbf{c}$

Artinya, ini adalah fungsi komutatifyang bersifat linear sehubungan dengan kedua argumen. Mari kita notasikan vektor satuan (_unit vectors_) sebagai

$$\mathbf{e}_x = \begin{pmatrix} 1 \\ 0 \\ 0 \end{pmatrix}, \mathbf{e}_y = \begin{pmatrix} 0 \\ 1 \\ 0 \end{pmatrix}, \mathbf{e}_z = \begin{pmatrix} 0 \\ 0 \\ 1 \end{pmatrix}.$$

Dengan notasi ini kita dapat menulis vektor $\mathbf{r} = (x;y;z)$ sebagai $\mathbf{r} = x \cdot \mathbf{e}_x + y \cdot \mathbf{e}_y + z \cdot \mathbf{e}_z$. Dan karena untuk vektor satuan

$$\mathbf{e}_x \cdot \mathbf{e}_x = \mathbf{e}_y \cdot \mathbf{e}_y = \mathbf{e}_z \cdot \mathbf{e}_z = 1,$$
$$\mathbf{e}_x \cdot \mathbf{e}_y = \mathbf{e}_y \cdot \mathbf{e}_z = \mathbf{e}_z \cdot \mathbf{e}_x = 0$$

kita dapat melihat bahwa dalam hal koordinat untuk $\mathbf{a} = (x_1;y_1;z_1)$ dan $\mathbf{b} = (x_2;y_2;z_2)$ berlaku

$$\mathbf{a} \cdot \mathbf{b} = (x_1 \cdot \mathbf{e}_x + y_1 \cdot \mathbf{e}_y + z_1 \cdot \mathbf{e}_z) \cdot (x_2 \cdot \mathbf{e}_x + y_2 \cdot \mathbf{e}_y + z_2 \cdot \mathbf{e}_z) = x_1 x_2 + y_1 y_2 + z_1 z_2$$

Itu juga merupakan definisi aljabar (_algebraic definition_) dari produk titik. Dari sini kita dapat menulis fungsi-fungsi yang menghitungnya.

```cpp
ftype dot(point2d a, point2d b) {
    return a.x * b.x + a.y * b.y;
}
ftype dot(point3d a, point3d b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}
```

Saat memecahkan masalah, seseorang harus menggunakan definisi aljabar untuk menghitung produk titik, tetapi tetap mengingat definisi dan properti geometris untuk menggunakannya.

### 2.2 | Properties

Kita dapat mendefinisikan banyak properti geometris melalui produk titik. Sebagai contoh:

1. Norma dari $\mathbf{a}$ (panjang kuadrat): $|\mathbf{a}|^2 = \mathbf{a} \cdot \mathbf{a}$
2. Panjang dari $\mathbf{a}$: $|\mathbf{a}| = \sqrt{\mathbf{a} \cdot \mathbf{a}}$
3. Proyeksi $\mathbf{a}$ ke $\mathbf{b}$: $\dfrac{\mathbf{a} \cdot \mathbf{b}}{|\mathbf{b}|}$
4. Sudut antara vektor: $\arccos \left(\dfrac{\mathbf{a} \cdot \mathbf{b}}{|\mathbf{a}| \cdot |\mathbf{b}|}\right)$

5. Dari poin sebelumnya kita dapat melihat bahwa produk titik adalah positif jika sudut di antara keduanya adalah lancip (_acute_), negatif jika tumpul (_obtuse_), dan sama dengan nol jika keduanya ortogonal (_orthogonal_), yaitu keduanya membentuk sudut siku-siku (_right angle_).

Perhatikan bahwa semua fungsi ini tidak bergantung pada jumlah dimensi, oleh karena itu, fungsi-fungsi ini akan sama untuk kasus 2D maupun 3D:

```cpp
ftype norm(point2d a) {
    return dot(a, a);
}
double abs(point2d a) {
    return sqrt(norm(a));
}
double proj(point2d a, point2d b) {
    return dot(a, b) / abs(b);
}
double angle(point2d a, point2d b) {
    return acos(dot(a, b) / abs(a) / abs(b));
}
```


Untuk melihat properti penting berikutnya, kita harus melihat himpunan titik (_set of points_) $\mathbf{r}$ di mana $\mathbf{r} \cdot \mathbf{a} = C$ untuk beberapa konstanta tetap $C$. Anda dapat melihat bahwa himpunan titik ini persis sama dengan himpunan titik di mana proyeksi (_projection_) ke $\mathbf{a}$ adalah titik $C \cdot \dfrac{\mathbf{a}}{|\mathbf{a}|^2}$, dan titik-titik tersebut membentuk hiperbidang (_hyperplane_) yang ortogonal terhadap $\mathbf{a}$. Anda dapat melihat vektor $\mathbf{a}$ bersama dengan beberapa vektor seperti itu yang memiliki produk titik yang sama dengannya dalam 2D pada gambar di bawah:


![[01-Basic Geometry-2.png]]


Dalam 2D, vektor-vektor ini akan membentuk garis, dalam 3D, mereka akan membentuk bidang (_plane_). Perhatikan bahwa hasil ini memungkinkan kita untuk mendefinisikan garis dalam 2D sebagai $\mathbf{r} \cdot \mathbf{n} = C$ atau $(\mathbf{r} - \mathbf{r}_0) \cdot \mathbf{n} = 0$, di mana $\mathbf{n}$ adalah vektor yang ortogonal  terhadap garis, $\mathbf{r}_0$ adalah setiap vektor yang sudah ada pada garis, dan $C = \mathbf{r}_0 \cdot \mathbf{n}$. Dengan cara yang sama, bidang dapat didefinisikan dalam 3D.

## 2 | Cross product

### 3.1 | Definition

Asumsikan Anda memiliki tiga vektor $\mathbf{a}$, $\mathbf{b}$, dan $\mathbf{c}$ dalam ruang 3D yang disatukan dalam sebuah paralelepipedum (_parallelepiped_) seperti pada gambar di bawah:


![[01-Basic Geometry-3.png]]

Bagaimana Anda akan menghitung volumenya? Dari sekolah kita tahu bahwa kita harus mengalikan luas alas dengan tinggi, yang merupakan proyeksi (_projection_) $\mathbf{a}$ ke arah yang ortogonal terhadap alas. Ini berarti bahwa jika kita mendefinisikan $\mathbf{b} \times \mathbf{c}$ sebagai vektor yang ortogonal terhadap $\mathbf{b}$ maupun $\mathbf{c}$ dan yang panjangnya sama dengan luas jajaran genjang yang dibentuk oleh $\mathbf{b}$ dan $\mathbf{c}$, maka $|\mathbf{a} \cdot (\mathbf{b} \times \mathbf{c})|$ akan sama dengan volume paralelepipedum. Untuk integritas, kita akan mengatakan bahwa $\mathbf{b} \times \mathbf{c}$ akan selalu diarahkan sedemikian rupa sehingga rotasi dari vektor $\mathbf{b}$ ke vektor $\mathbf{c}$ dari sudut pandang $\mathbf{b} \times \mathbf{c}$ selalu berlawanan arah jarum jam (_counter-clockwise_) (lihat gambar di bawah).

![[01-Basic Geometry-4.png]]


Ini mendefinisikan produk silang (cross product) (atau produk vektor (_vector product_)) $\mathbf{b} \times \mathbf{c}$ dari vektor $\mathbf{b}$ dan $\mathbf{c}$, dan produk tripel (_triple product_) $\mathbf{a} \cdot (\mathbf{b} \times \mathbf{c})$ dari vektor $\mathbf{a}$, $\mathbf{b}$, dan $\mathbf{c}$.

Beberapa properti penting dari produk silang dan produk tripel:

1.  $\mathbf{a} \times \mathbf{b} = - \mathbf{b} \times \mathbf{a}$
2.  $(\alpha \cdot \mathbf{a}) \times \mathbf{b} = \alpha \cdot (\mathbf{a} \times \mathbf{b})$
3.  Untuk setiap $\mathbf{b}$ dan $\mathbf{c}$, terdapat tepat satu vektor $\mathbf{r}$ sedemikian sehingga $\mathbf{a} \cdot (\mathbf{b} \times \mathbf{c}) = \mathbf{a} \cdot \mathbf{r}$ untuk setiap vektor $\mathbf{a}$. Memang, jika ada dua vektor seperti itu, $\mathbf{r}_1$ dan $\mathbf{r}_2$, maka $\mathbf{a} \cdot (\mathbf{r}_1 - \mathbf{r}_2) = 0$ untuk semua vektor $\mathbf{a}$, yang hanya mungkin terjadi ketika $\mathbf{r}_1 = \mathbf{r}_2$.
4.  $\mathbf{a} \cdot (\mathbf{b} \times \mathbf{c}) = \mathbf{b} \cdot (\mathbf{c} \times \mathbf{a}) = - \mathbf{a} \cdot (\mathbf{c} \times \mathbf{b})$
5.  $(\mathbf{a} + \mathbf{b}) \times \mathbf{c} = \mathbf{a} \times \mathbf{c} + \mathbf{b} \times \mathbf{c}$. Memang, untuk semua vektor $\mathbf{r}$, rangkaian persamaan berikut berlaku:
    $$\mathbf{r} \cdot ((\mathbf{a} + \mathbf{b}) \times \mathbf{c}) = (\mathbf{a} + \mathbf{b}) \cdot (\mathbf{c} \times \mathbf{r}) = \mathbf{a} \cdot (\mathbf{c} \times \mathbf{r}) + \mathbf{b} \cdot (\mathbf{c} \times \mathbf{r}) = \mathbf{r} \cdot (\mathbf{a} \times \mathbf{c}) + \mathbf{r} \cdot (\mathbf{b} \times \mathbf{c}) = \mathbf{r} \cdot (\mathbf{a} \times \mathbf{c} + \mathbf{b} \times \mathbf{c})$$
    Yang membuktikan $(\mathbf{a} + \mathbf{b}) \times \mathbf{c} = \mathbf{a} \times \mathbf{c} + \mathbf{b} \times \mathbf{c}$ berdasarkan poin 3.
6.  $|\mathbf{a} \times \mathbf{b}| = |\mathbf{a}| \cdot |\mathbf{b}| \sin \theta$ di mana $\theta$ adalah sudut antara $\mathbf{a}$ dan $\mathbf{b}$, karena $|\mathbf{a} \times \mathbf{b}|$ sama dengan luas jajaran genjang yang dibentuk oleh $\mathbf{a}$ dan $\mathbf{b}$.

Mengingat semua ini dan bahwa persamaan berikut berlaku untuk vektor satuan (_unit vectors_):

$$\mathbf{e}_x \times \mathbf{e}_x = \mathbf{e}_y \times \mathbf{e}_y = \mathbf{e}_z \times \mathbf{e}_z = \mathbf{0},$$
$$\mathbf{e}_x \times \mathbf{e}_y = \mathbf{e}_z, \quad \mathbf{e}_y \times \mathbf{e}_z = \mathbf{e}_x, \quad \mathbf{e}_z \times \mathbf{e}_x = \mathbf{e}_y$$

kita dapat menghitung produk silang $\mathbf{a} = (x_1;y_1;z_1)$ dan $\mathbf{b} = (x_2;y_2;z_2)$ dalam bentuk koordinat (_coordinate form_):

$$\mathbf{a} \times \mathbf{b} = (x_1 \cdot \mathbf{e}_x + y_1 \cdot \mathbf{e}_y + z_1 \cdot \mathbf{e}_z) \times (x_2 \cdot \mathbf{e}_x + y_2 \cdot \mathbf{e}_y + z_2 \cdot \mathbf{e}_z) =$$
$$(y_1 z_2 - z_1 y_2) \mathbf{e}_x + (z_1 x_2 - x_1 z_2) \mathbf{e}_y + (x_1 y_2 - y_1 x_2) \mathbf{e}_z$$

Yang juga dapat ditulis dalam bentuk yang lebih elegan:

$$\mathbf{a} \times \mathbf{b} = \begin{vmatrix}\mathbf{e}_x & \mathbf{e}_y & \mathbf{e}_z \\ x_1 & y_1 & z_1 \\ x_2 & y_2 & z_2 \end{vmatrix}, \quad \mathbf{a} \cdot (\mathbf{b} \times \mathbf{c}) = \begin{vmatrix} x_1 & y_1 & z_1 \\ x_2 & y_2 & z_2 \\ x_3 & y_3 & z_3 \end{vmatrix}$$

Di sini, $|\cdot|$ adalah determinan dari suatu matriks.


Semacam produk silang (_cross product_) (yaitu produk pseudo-skalar (_pseudo-scalar product_)) juga dapat diimplementasikan dalam kasus 2D. Jika kita ingin menghitung luas jajaran genjang  yang dibentuk oleh vektor $\mathbf{a}$ dan $\mathbf{b}$, kita akan menghitung $|\mathbf{e}_z \cdot (\mathbf{a} \times \mathbf{b})| = |x_1 y_2 - y_1 x_2|$. Cara lain untuk mendapatkan hasil yang sama adalah dengan mengalikan $|\mathbf{a}|$ (alas jajaran genjang) dengan tinggi, yang merupakan proyeksi (_projection_) vektor $\mathbf{b}$ ke vektor $\mathbf{a}$ yang dirotasi sebesar $90^\circ$, yang pada gilirannya adalah $\widehat{\mathbf{a}} = (-y_1; x_1)$. Artinya, kita menghitung $|\widehat{\mathbf{a}} \cdot \mathbf{b}| = |x_1 y_2 - y_1 x_2|$.

Jika kita mempertimbangkan tanda, maka luasnya akan positif jika rotasi dari $\mathbf{a}$ ke $\mathbf{b}$ (yaitu dari sudut pandang titik $\mathbf{e}_z$) dilakukan berlawanan arah jarum jam (_counter-clockwise_) dan negatif jika sebaliknya. Ini mendefinisikan produk pseudo-skalar (_pseudo-scalar product_). Perhatikan bahwa ini juga sama dengan $|\mathbf{a}| \cdot |\mathbf{b}| \sin \theta$, di mana $\theta$ adalah sudut dari $\mathbf{a}$ ke $\mathbf{b}$ yang dihitung berlawanan arah jarum jam (dan negatif jika rotasi searah jarum jam).

Mari kita implementasikan semua hal ini!

```cpp
point3d cross(point3d a, point3d b) {
    return point3d(a.y * b.z - a.z * b.y,
                   a.z * b.x - a.x * b.z,
                   a.x * b.y - a.y * b.x);
}
ftype triple(point3d a, point3d b, point3d c) {
    return dot(a, cross(b, c));
}
ftype cross(point2d a, point2d b) {
    return a.x * b.y - a.y * b.x;
}
```

### 3.2 | Properties

Seperti halnya produk silang (_cross product_), produk ini sama dengan vektor nol (_zero vector_) jika dan hanya jika vektor $\mathbf{a}$ dan $\mathbf{b}$ adalah kolinear (keduanya membentuk satu garis, yaitu mereka sejajar (_parallel_)). Hal yang sama berlaku untuk produk tripel (_triple product_), produk ini sama dengan nol jika dan hanya jika vektor $\mathbf{a}$, $\mathbf{b}$, dan $\mathbf{c}$ adalah koplanar (_coplanar_) (keduanya membentuk satu bidang).

Dari sini kita dapat memperoleh persamaan universal yang mendefinisikan garis dan bidang. Sebuah garis dapat didefinisikan melalui vektor arahnya (_direction vector_) $\mathbf{d}$ dan titik awalnya (_initial point_) $\mathbf{r}_0$ atau oleh dua titik $\mathbf{a}$ dan $\mathbf{b}$. Garis tersebut didefinisikan sebagai $(\mathbf{r} - \mathbf{r}_0) \times \mathbf{d} = 0$ atau sebagai $(\mathbf{r} - \mathbf{a}) \times (\mathbf{b} - \mathbf{a}) = 0$. Sedangkan untuk bidang, bidang dapat didefinisikan oleh tiga titik $\mathbf{a}$, $\mathbf{b}$, dan $\mathbf{c}$ sebagai $(\mathbf{r} - \mathbf{a}) \cdot ((\mathbf{b} - \mathbf{a}) \times (\mathbf{c} - \mathbf{a})) = 0$, atau oleh titik awal $\mathbf{r}_0$ dan dua vektor arah $\mathbf{d}_1$ dan $\mathbf{d}_2$ yang terletak pada bidang ini: $(\mathbf{r} - \mathbf{r}_0) \cdot (\mathbf{d}_1 \times \mathbf{d}_2) = 0$.

Dalam 2D, produk pseudo-skalar (_pseudo-scalar product_) juga dapat digunakan untuk memeriksa orientasi (_orientation_) antara dua vektor karena nilainya positif jika rotasi (_rotation_) dari vektor pertama ke vektor kedua adalah searah jarum jam (_clockwise_) dan negatif jika sebaliknya. Dan, tentu saja, produk ini dapat digunakan untuk menghitung luas poligon (_areas of polygons_), yang dijelaskan dalam artikel yang berbeda. Produk tripel (_triple product_) dapat digunakan untuk tujuan yang sama dalam ruang 3D.

## 4 | Exercises

### 4.1 | Line intersection

Ada banyak cara yang mungkin untuk mendefinisikan garis (_line_) dalam 2D, dan Anda tidak perlu ragu untuk menggabungkannya. Misalnya, kita memiliki dua garis dan kita ingin menemukan titik perpotongan (_intersection points_) keduanya.

Kita dapat mengatakan bahwa semua titik dari garis pertama dapat diparameterkan sebagai $\mathbf{r} = \mathbf{a}_1 + t \cdot \mathbf{d}_1$, di mana $\mathbf{a}_1$ adalah titik awal (_initial point_), $\mathbf{d}_1$ adalah vektor arah (_direction vector_), dan $t$ adalah parameter riil (_real parameter_) tertentu. Sedangkan untuk garis kedua, semua titiknya harus memenuhi $(\mathbf{r} - \mathbf{a}_2) \times \mathbf{d}_2 = 0$. Dari sini, kita dapat dengan mudah menemukan parameter $t$:
$$(\mathbf{a}_1 + t \cdot \mathbf{d}_1 - \mathbf{a}_2) \times \mathbf{d}_2 = 0 \quad \Rightarrow \quad t = \dfrac{(\mathbf{a}_2 - \mathbf{a}_1) \times \mathbf{d}_2}{\mathbf{d}_1 \times \mathbf{d}_2}$$

Mari kita implementasikan fungsi untuk mempertemukan dua garis.

```cpp
point2d intersect(point2d a1, point2d d1, point2d a2, point2d d2) {
    return a1 + cross(a2 - a1, d2) / cross(d1, d2) * d1;
}
```

### 4.2 | Planes intersection

Namun, terkadang mungkin sulit menggunakan beberapa wawasan geometris (_geometric insights_). Misalnya, Anda diberikan tiga bidang (_three planes_) yang didefinisikan oleh titik awal (_initial points_) $\mathbf{a}_i$ dan vektor arah (_directions_) $\mathbf{d}_i$, dan Anda ingin menemukan titik perpotongan (_intersection point_) ketiganya.

Anda dapat mencatat bahwa Anda hanya perlu menyelesaikan sistem persamaan (_solve the system of equations_):

$$\begin{cases}\mathbf{r} \cdot \mathbf{n}_1 = \mathbf{a}_1 \cdot \mathbf{n}_1, \\ \mathbf{r} \cdot \mathbf{n}_2 = \mathbf{a}_2 \cdot \mathbf{n}_2, \\ \mathbf{r} \cdot \mathbf{n}_3 = \mathbf{a}_3 \cdot \mathbf{n}_3\end{cases}$$

Alih-alih memikirkan pendekatan geometris (_geometric approach_), Anda dapat mengerjakan pendekatan aljabar (_algebraic one_) yang dapat diperoleh dengan segera. Misalnya, karena Anda telah mengimplementasikan kelas titik (_point class_), akan mudah bagi Anda untuk menyelesaikan sistem ini menggunakan aturan Cramer (_Cramer's rule_) karena produk tripel (_triple product_) hanyalah determinan (_determinant_) dari matriks yang diperoleh dari vektor-vektor yang menjadi kolomnya:

```cpp
point3d intersect(point3d a1, point3d n1, point3d a2, point3d n2, point3d a3, point3d n3) {
    point3d x(n1.x, n2.x, n3.x);
    point3d y(n1.y, n2.y, n3.y);
    point3d z(n1.z, n2.z, n3.z); 
    point3d d(dot(a1, n1), dot(a2, n2), dot(a3, n3));
    return point3d(triple(d, y, z),
                   triple(x, d, z),
                   triple(x, y, d)) / triple(n1, n2, n3);
}
```


Sekarang Anda dapat mencoba mencari tahu sendiri pendekatan (_approaches_) untuk operasi geometris (_geometric operations_) umum agar terbiasa dengan semua materi ini.
