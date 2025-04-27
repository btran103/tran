#include <iostream>
#include <fstream>
#include <functional>
using namespace std;

struct tuvung
{
	string tienganh;
	string tiengviet;
};
struct tudienanhviet
{
	tuvung data;
	tudienanhviet *trai, *phai;
};

void themtuvung(tudienanhviet *&goc, tuvung data) {
	if (goc == NULL) {
	goc = new tudienanhviet;
	goc->data = data;
	goc->trai = goc->phai = NULL;

	} else if (data.tienganh < goc->data.tienganh) {
		themtuvung(goc->trai, data);
	} else if (data.tienganh > goc->data.tienganh) {
		themtuvung(goc->phai, data);
	}
}

void doctutep(tudienanhviet *&goc, string tenfile) {
	ifstream file(tenfile);
	string dong;
	while (getline(file, dong)) {
		int vitri = dong.find(':');
		string anh = dong.substr(0, vitri);
		string viet = dong.substr(vitri + 1);
		tuvung data = {anh, viet};
		themtuvung(goc, data);
	}
	file.close();
}

void intudien(tudienanhviet *goc) {
	if (goc) {
		intudien(goc->trai);
		cout << goc->data.tienganh <<" : "<< goc->data.tiengviet << endl;
		intudien(goc->phai);
	}
}

string tratu(tudienanhviet *goc, string anh) {
	if (goc == NULL) {
		return "";
	}
	if (goc->data.tienganh == anh) {
		return goc->data.tiengviet;
	}
	if (anh < goc->data.tiengviet) {
		return tratu(goc->trai, anh);
	} else {
		return tratu(goc->phai, anh);
	}
}

tudienanhviet *tim(tudienanhviet *goc) {
	if (goc->trai == NULL) {
		return goc;
	}
	return tim(goc->trai);
}

void xoatuvung(tudienanhviet *&goc, string anh) {
	if (goc == NULL) {
		return;
	}	
	if (anh < goc->data.tienganh) {
		xoatuvung(goc->trai, anh);
	} 
	else if (anh > goc->data.tienganh) {
		xoatuvung(goc->phai, anh);
	} else {
		if (goc->trai == NULL && goc->phai == NULL) {
			delete goc;
			goc = NULL;
		} else if (goc->trai == NULL) {
			tudienanhviet *temp = goc;
			goc = goc->phai;
			delete temp;
		} else if (goc->phai == NULL) {
			tudienanhviet *temp = goc;
			goc = goc->trai;
			delete temp;
		} else {
			tudienanhviet *temp = tim(goc->phai);
			goc->data = temp->data;
			xoatuvung(goc->phai, temp->data.tienganh);
		}
	}
}

void intubatdauH(tudienanhviet* goc)
{
	if (goc) {
        intubatdauH(goc->trai);
        if (goc->data.tienganh[0] == 'h' || goc->data.tienganh[0] == 'h') {
            cout << goc->data.tienganh << " : " << goc->data.tiengviet << endl;
        }
        intubatdauH(goc->phai);
    }
}

int demsautuT(tudienanhviet* goc, string tuvung)
{
	if (goc == NULL)
        return 0;
    if (goc->data.tienganh > tuvung)
        return 1 + demsautuT(goc->trai, tuvung) + demsautuT(goc->phai, tuvung);
    else if (goc->data.tienganh < tuvung)
        return  demsautuT(goc->phai, tuvung);
    else
        return demsautuT(goc->trai, tuvung);
}

void luuvaotep(tudienanhviet* goc, string tenfile)
{
    ofstream file(tenfile, ios::app);
    if (file.is_open()){
        if(goc){
            file << goc->data.tienganh << " : " << goc->data.tiengviet << endl;
            luuvaotep(goc->trai, tenfile);
            luuvaotep(goc->phai, tenfile);
        }
    }
    file.close();
}

int main(){
	tudienanhviet *goc = NULL;
	string anh, viet;
	
	doctutep(goc, "EVD.txt");
	
	intudien(goc);
	
	cout << "Nhap mot tu Tieng Anh de tra " ; 
	cin >> anh;
	viet = tratu(goc, anh);
	if (viet!="")
		cout << anh << ": " << viet << endl;
	else
		cout << anh << " khong co trong tu dien." << endl;
		
	xoatuvung(goc, "hello");
	intudien(goc);
	
    cout << "Tu bat dua bang chu h: ";
	intubatdauH(goc);
    cout << endl;

    int dem = demsautuT(goc, "begin");
    cout << "So tu sau tu: " << dem << endl;
    
    luuvaotep(goc, "EVD_output.txt");
	cout << "Da luu tu dien vao tep EVD_output.txt" << endl;

    
	return 0;
}

