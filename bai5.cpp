#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double soTienVay;
    double laiSuatNam;
    double tienTraHangThang;

    cin >> soTienVay >> laiSuatNam >> tienTraHangThang;

    double laiSuatThang = laiSuatNam / 12.0 / 100.0;

    int soThang = 0;

    while (soTienVay > 0) {
        double tienLai = soTienVay * laiSuatThang;

        if (tienTraHangThang <= tienLai) {
            cout << "Canh bao khong bao gio tra het no\n";
            return 0;
        }

        double tienTraGoc = tienTraHangThang - tienLai;
        soTienVay -= tienTraGoc;

        soThang++;
    }

    cout << "Mat " << soThang << " thang de tra no xong.\n";

    return 0;
}
