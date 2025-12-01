#include <bits/stdc++.h>
using namespace std;

int main() {
    int soTaiKhoan;
    char loai;
    int soPhut, phutNgay, phutDem;
    double tongTien = 0;

    cout << "Nhap so tai khoan: ";
    cin >> soTaiKhoan;
    cout << "Nhap loai dich vu (R = thuong, P = cao cap): ";
    cin >> loai;

    if (loai == 'R' || loai == 'r') {
        cout << "Nhap tong so phut da su dung: ";
        cin >> soPhut;
        tongTien = 10;
        if (soPhut > 50) tongTien += (soPhut - 50) * 0.2;
    }
    else if (loai == 'P' || loai == 'p') {
        cout << "Nhap so phut goi ban ngay: ";
        cin >> phutNgay;
        cout << "Nhap so phut goi ban dem: ";
        cin >> phutDem;
        tongTien = 25;
        if (phutNgay > 75) tongTien += (phutNgay - 75) * 0.1;
        if (phutDem > 100) tongTien += (phutDem - 100) * 0.05;
    }
    else {
        cout << "Loai dich vu khong hop le!";
        return 0;
    }

    cout << "\n=== HOA DON DIEN THOAI ===\n";
    cout << "So tai khoan: " << soTaiKhoan << endl;
    if (loai == 'R' || loai == 'r') cout << "Loai dich vu: Thong thuong\n";
    else cout << "Loai dich vu: Cao cap\n";
    cout << "Tong tien phai tra: $" << tongTien << endl;

    return 0;
}

