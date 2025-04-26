#include <iostream>
#include <vector>
#include <numeric>

using namespace std;
int makanLumpia(int A, int B, int C, int D) {

    // Inisialisasi lumpia dalam urutan menggunakan vector
    vector<int> lumpia = {A,B,C,D};

    int hari = 0;

    // Loop terus selama lumpia masih tersedia
    // Fungsi accumulate menjumlahkan semua lumpia dan jika hasil akumulasi lebih dari 0 maka lumpia dianggap tersedia
    // lumpia.begin() -> Pointer awal vector lumpia, akumulasi dari awal index lumpia
    // lumpia.end() -> Pointer akhir vector lumpia, akumulasi sampai akhir index lumpia
    while (accumulate(lumpia.begin(), lumpia.end(), 0) > 0) {

        int index = 0;
        int jumlah = 0;

       // printVector(lumpia);

        // Loop seluruh lumpia selama belum termakan sebanyak 3
        while (index < lumpia.size() && jumlah < 3) {

            // Kalo lumpianya masih ada
            if (lumpia[index]> 0) {
                
                // Selama lumpia masih ada dan jumlah dimakan belom sampe 3
                while (lumpia[index] > 0 && jumlah < 3) {
                    jumlah++;
                    lumpia[index]--;
                };

                // Jika sekarang lagi makan Lumpia A dan lumpia B masih ada, stop loopnya biar ga ngemakan lumpia B
                // Kasus sama jika sekarang lagi makan lumpia C dan lumpia D masih ada
                // index=0 --> Lumpia A    index+1 --> B
                // index=2 --> Lumpia C    index+1 --> D
                if ((index == 0 || index == 2) && (lumpia[index+1] > 0)) {
                    break;
                }
            };

            // Next lumpia
            index++;

        };

        // Sudah kemakan 3 lumpia atau ketemu lumpia yang gabisa dimakan bersamaan, Hari ditambah dan lanjut loop selanjutnya
        hari++;
    };


    return hari;


}



int main() {

    cout << "3 3 3 3 = " << makanLumpia(3,3,3,3);
    cout << "\n2 1 2 1 = " << makanLumpia(2,1,2,1);
    cout << "\n9 0 0 0 = " << makanLumpia(9,0,0,0);
    cout << "\n5 2 7 2 = " << makanLumpia(5,2,7,2);
    cout << endl;

    return 0;
}
