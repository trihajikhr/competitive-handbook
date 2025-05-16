#include <iostream>
#include <vector>
#include <conio.h>

using namespace std;

/**
 * 
 *  Warung makan 
 *  bisa pesen makanan, delivery, slip pembayaran
 * 
 * 
 *  diskon kalau harga diatas 50000
 * 
 *  slip pembayaran bisa ada banyak pesenan
 * 
 *  pajak 5%
 * 
 *  untuk delivery input KM
 *  jika KM > 3 maka ongkir 25000
 *  kalau engga maka ongkir 15000
 * 
 *  menu makanan:
 *  1. nasi goreng 15000
 *  2. mie ayam 12000
 *  3. ayam krispi 10000
 *  
 */

struct menu {
    string nama;
    int harga;

    menu (string n, int h) {
        nama = n;
        harga = h;
    };
};  

vector<menu> listMenu;

void buatMenu(const string& nama, const int& harga) {
    listMenu.emplace_back(nama, harga);
};

    
 
int main () {
    
    buatMenu("Nasi goreng", 15000);
    buatMenu("Mie ayam", 15000);
    buatMenu("Ayam krispi", 15000);
    buatMenu("Cumi goreng", 25000);

    vector<int> listPesenan;
    
    pesen:

    cout << "## ================| Warung Makan |================ ##\n\n";

    for (int i = 0; i < listMenu.size(); i++) {
        cout << i + 1 << ". " << listMenu[i].nama << " -- Rp. " << listMenu[i].harga << endl;
    };
    
    cout << "Menu yang dipilih: "; 
    short id; cin >> id;
    id--;

    if (id >= listMenu.size() || id < 0) {
        cout << "Tidak ada menunya coy";
        getch();
        system("cls");
        goto pesen;
    } else {
        
        listPesenan.push_back(id);
        
        cout << "Apakah anda ingin memesan lagi? (Y/n)";
        char T;
        cin >> T;
        if (T == 'Y' || T=='y') {
            system("cls");
            goto pesen;
        } else {

            int Km;
            cout << "Input jarak dari rumah kesini (km): ";
            cin >> Km;

            int ongkir = Km > 3 ? 25000 : 15000;

            
            int totalHarga = 0;

            cout << "## ================| SLIP PEMBAYARAN |================ ##\n\n";


            for (int i = 0; i < listPesenan.size(); i++) {
                int id = listPesenan[i];
                cout << i + 1 << ". " << listMenu[id].nama << " -- Rp. " << listMenu[id].harga << endl;
                totalHarga += listMenu[id].harga;
            };

            cout << endl << "Pajak: 5%" << endl;
            
            cout << endl << "Total harga: " << totalHarga + ongkir + ((totalHarga + ongkir) * 0.05)<<endl; 
            
            cout << "## ================| =============== |================ ##\n\n";

            cout << endl << endl;

        }
    }


    return 0;   

}