#include <iostream>
using namespace std;
int main() {
	int tongsogiay; //nhap tong so giay nguoi dung
	int gio, phut, giay; //bien luu gio, phut, giay
	
	//nhap tong so giay
	cout <<"Nhap thoi gian da qua tinh bang giay: ";
	cin >> tongsogiay;
	
	//tinh so gio bang cach lay tong so giay chia cho 3600 (vì 1 gio = 3600 giay)
	gio = tongsogiay/3600;
	
	//tinh so phut bang cach tinh phan du cua phep chia roi chia cho 60 
	phut = (tongsogiay % 3600) / 60;
	
	//tinh so giay con lai bang cach 
	giay = tongsogiay % 60;
	
	//in ket qua theo gio:phut:giay
	cout <<"Thoi gian la: " << gio << ":" << phut << ":" << giay << endl;
	
	return 0;
	
}
