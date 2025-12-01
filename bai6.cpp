#include <iostream>
using namespace std;

bool laNamNhuan(int nam) {
    return (nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0);
}

int soNgayTrongThang(int thang, int nam) {
    if (thang == 2) return laNamNhuan(nam) ? 29 : 28;
    if (thang == 4 || thang == 6 || thang == 9 || thang == 11) return 30;
    if (thang >= 1 && thang <= 12) return 31;
    return 0;
}

bool laNgayHopLe(int ngay, int thang, int nam) {
    if (nam < 1 || thang < 1 || thang > 12 || ngay < 1) return false;
    return ngay <= soNgayTrongThang(thang, nam);
}

void congNgay(int &ngay, int &thang, int &nam, int n) {
    ngay += n;
    while (ngay > soNgayTrongThang(thang, nam)) {
        ngay -= soNgayTrongThang(thang, nam);
        thang++;
        if (thang > 12) {
            thang = 1;
            nam++;
        }
    }
    while (ngay < 1) {
        thang--;
        if (thang < 1) {
            thang = 12;
            nam--;
        }
        ngay += soNgayTrongThang(thang, nam);
    }
}

int main() {
    int ngay, thang, nam;
    cout << "Nhap ngay: "; cin >> ngay;
    cout << "Nhap thang: "; cin >> thang;
    cout << "Nhap nam: "; cin >> nam;

    if (laNgayHopLe(ngay, thang, nam)) {
        cout << "Ngay hop le.\n";

        int ngayTruoc = ngay, thangTruoc = thang, namTruoc = nam;
        congNgay(ngayTruoc, thangTruoc, namTruoc, -1);
        cout << "Ngay hom truoc: " << ngayTruoc << "/" << thangTruoc << "/" << namTruoc << endl;

        int ngaySau = ngay, thangSau = thang, namSau = nam;
        congNgay(ngaySau, thangSau, namSau, 1);
        cout << "Ngay hom sau: " << ngaySau << "/" << thangSau << "/" << namSau << endl;
    } else {
        cout << "Ngay khong hop le.\n";
    }

    return 0;
}
