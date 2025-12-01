#include <iostream>
using namespace std;
int main() {
	float mucluongmoigio = 15.50;
	float tongsothue = 0.14;
	float tylechimuaquanao = 0.10;
	float tylechimuadodunghoctap = 0.01;
	float tylemuatraiphieutietkiem = 0.25;
	float tylechamechimuatraiphieubosung = 0.50;
	
	float sogiolamviecmoituan;
	float thunhaptruocthue, thunhapsauthue;
	float sotienchimuaquanaso, sotienchimuadodunghoctap, sotienmuatraiphieutietkiem;
	float sotienchamechimuatraiphieu;
	
	//nhap so gio lam viec moi tuan
	cout <<"Nhap so gio lam viec moi tuan: ";
	cin >> sogiolamviecmoituan;
	
	//tinh thu nhap truoc thue
	thunhaptruocthue = sogiolamviecmoituan * mucluongmoigio * 5;
	
	//tinh thu nhap sau thue
	thunhapsauthue = thunhaptruocthue * (1 - tongsothue);
	
	//tinh cac khoan chi tieu
	sotienchimuaquanao = thunhapsauthue * tylechimuaquanao;
	sotienchimuadodunghoctap = thunhapsauthue * tylechimuadodunghoctap;
	sotienmuatraiphieutietkiem = thunhapsauthue * tylemuatraiphieutietkiem;
	
	//tinh so tien cha me chi mua trai phieu
	sotienchamechimuatraiphieu = tylemuatraiphieutietkiem * tylechamechimuatraiphieubosung;
	
	//in ket qua
	cout << "Thu nhap truoc thue: $" << thunhaptruocthue << endl;
    cout << "Thu nhap sau thue: $" << thunhapsauthue << endl;
    cout << "So tien chi cho quan ao va phu kien: $" << sotienchimuaquanaso << endl;
    cout << "So tien chi cho do dung hoc tap: $" << sotienchimuadodunghoctap << endl;
    cout << "So tien chi cho trai phieu tiet kiem: $" << sotienmuatraiphieutietkiem << endl;
    cout << "So tien bo me chi cho trai phieu tiet kiem bo sung: $" << sotienchamechimuatraiphieu << endl;

    return 0;
}
