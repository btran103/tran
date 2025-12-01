#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <conio.h> // thêm d? dùng getch()
using namespace std;

struct HocSinh {
    string maSV, hoTen, queQuan;
    int namSinh;
};

// Nhap danh sach
void nhapDS(vector<HocSinh> &ds) {
    int n;
    cout << "Nhap so luong hoc sinh: ";
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        HocSinh hs;
        cout << "\nHoc sinh thu " << i + 1 << ":\n";
        cout << "Ma SV: "; getline(cin, hs.maSV);
        cout << "Ho ten: "; getline(cin, hs.hoTen);
        cout << "Nam sinh: "; cin >> hs.namSinh;
        cin.ignore();
        cout << "Que quan: "; getline(cin, hs.queQuan);
        ds.push_back(hs);
    }
}

// Ghi file
void ghiFile(vector<HocSinh> ds) {
    ofstream f("DATA.INP");
    for (int i = 0; i < (int)ds.size(); i++) {
        f << ds[i].maSV << ";" << ds[i].hoTen << ";"
          << ds[i].namSinh << ";" << ds[i].queQuan << endl;
    }
    f.close();
    cout << "Da luu vao file DATA.INP\n";
}

// Doc file
void docFile(vector<HocSinh> &ds) {
    ifstream f("DATA.INP");
    if (!f.is_open()) {
        cout << "Khong mo duoc file!\n";
        return;
    }
    ds.clear();
    string line;
    while (getline(f, line)) {
        HocSinh hs;
        int p1 = line.find(';');
        int p2 = line.find(';', p1 + 1);
        int p3 = line.find(';', p2 + 1);
        if (p1 == -1 || p2 == -1 || p3 == -1) continue;
        hs.maSV = line.substr(0, p1);
        hs.hoTen = line.substr(p1 + 1, p2 - p1 - 1);
        hs.namSinh = atoi(line.substr(p2 + 1, p3 - p2 - 1).c_str());
        hs.queQuan = line.substr(p3 + 1);
        ds.push_back(hs);
    }
    f.close();
    cout << "Da doc du lieu tu file.\n";
}

// Hien thi danh sach
void hienThi(vector<HocSinh> ds) {
    if (ds.empty()) {
        cout << "Danh sach rong!\n";
        return;
    }
    cout << "\n----- DANH SACH HOC SINH -----\n";
    for (int i = 0; i < (int)ds.size(); i++) {
        cout << ds[i].maSV << " - " << ds[i].hoTen
             << " - " << ds[i].namSinh
             << " - " << ds[i].queQuan << endl;
    }
}

// Tim hoc sinh
void timHS(vector<HocSinh> ds) {
    string ma;
    cout << "Nhap ma can tim: ";
    cin >> ma;
    for (int i = 0; i < (int)ds.size(); i++) {
        if (ds[i].maSV == ma) {
            cout << "Tim thay: " << ds[i].hoTen << ", " << ds[i].queQuan << endl;
            return;
        }
    }
    cout << "Khong tim thay!\n";
}

// Chen hoc sinh
void chenHS(vector<HocSinh> &ds) {
    HocSinh hs;
    cin.ignore();
    cout << "Nhap ma SV: "; getline(cin, hs.maSV);
    cout << "Ho ten: "; getline(cin, hs.hoTen);
    cout << "Nam sinh: "; cin >> hs.namSinh;
    cin.ignore();
    cout << "Que quan: "; getline(cin, hs.queQuan);
    ds.push_back(hs);
    cout << "Da them hoc sinh!\n";
}

// Xoa hoc sinh
void xoaHS(vector<HocSinh> &ds) {
    string ma;
    cout << "Nhap ma can xoa: ";
    cin >> ma;
    for (int i = 0; i < (int)ds.size(); i++) {
        if (ds[i].maSV == ma) {
            ds.erase(ds.begin() + i);
            cout << "Da xoa!\n";
            return;
        }
    }
    cout << "Khong tim thay!\n";
}

// Sap xep giam dan theo ma
void sapXep(vector<HocSinh> &ds) {
    for (int i = 0; i < (int)ds.size() - 1; i++)
        for (int j = i + 1; j < (int)ds.size(); j++)
            if (ds[i].maSV < ds[j].maSV)
                swap(ds[i], ds[j]);
    cout << "Da sap xep giam dan theo ma SV!\n";
}

// Chuong trinh chinh
int main() {
    vector<HocSinh> ds;
    char ch;
    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Nhap danh sach\n";
        cout << "2. Luu vao file\n";
        cout << "3. Hien thi danh sach\n";
        cout << "4. Doc tu file\n";
        cout << "5. Tim hoc sinh theo ma\n";
        cout << "6. Chen mot hoc sinh\n";
        cout << "7. Xoa hoc sinh theo ma\n";
        cout << "8. Sap xep giam dan theo ma\n";
        cout << "ESC. Thoat\n";
        cout << "================\n";
        cout << "Nhap lua chon: ";
        ch = getch();  // doc phim
        cout << ch << endl;

        switch (ch) {
        case '1's: nhapDS(ds); break;
        case '2': ghiFile(ds); break;
        case '3': hienThi(ds); break;
        case '4': docFile(ds); break;
        case '5': timHS(ds); break;
        case '6': chenHS(ds); break;
        case '7': xoaHS(ds); break;
        case '8': sapXep(ds); break;
        case 27: cout << "Thoat chuong trinh!\n"; break;
        default: cout << "Nhap sai, vui long chon lai!\n";
        }
    } while (ch != 27);

    return 0;
}

