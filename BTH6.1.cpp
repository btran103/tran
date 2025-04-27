#include<iostream>
#include<fstream>
using namespace std;

struct tuVung
{
    string tiengAnh;
    string tiengViet;
};

struct tuDienAnhViet {
    tuVung data;
    tuDienAnhViet *trai, *phai;
};

//them tu vao tu dien
void themTu(tuDienAnhViet *&goc, tuVung data){
    if (goc == NULL) {
        goc = new tuDienAnhViet;
        goc->data = data;
        goc->trai = goc->phai = NULL;
    }
    else if (data.tiengAnh < goc->data.tiengAnh){
        themTu(goc->trai, data);
    }
    else if (data.tiengAnh > goc->data.tiengAnh){
        themTu(goc->phai, data);
    }
}

//doc tu dien tu tep
void docTuTep(tuDienAnhViet *&goc, string tenFile){
    ifstream file(tenFile);
    string dong;
    while (getline(file, dong))
    {
        int vitri = dong.find(':');
        string anh = dong.substr(0, vitri);
        string viet = dong.substr(vitri + 1);
        tuVung data = {anh, viet};
        themTu(goc, data);
    }
    file.close();
}

//in tu dien
void inTuDien(tuDienAnhViet *goc){
    if (goc){
        inTuDien (goc->trai);
        cout << goc->data.tiengAnh << ": " << goc->data.tiengViet << endl;
        inTuDien(goc->phai); 
    }
}

//tra tu dien
string traTu(tuDienAnhViet *goc, string anh){
    if (goc == NULL)
        return "";
    if (goc->data.tiengAnh == anh)
        return goc->data.tiengViet;
    if (anh < goc->data.tiengAnh)
        return traTu(goc->trai, anh);
    else    
        return traTu(goc->phai, anh);
}

//xoa tu trong tu dien
tuDienAnhViet *tim(tuDienAnhViet *goc){
    if (goc->trai == NULL){
        return goc;
    }
    return tim(goc->trai);
}

void xoaTu(tuDienAnhViet *&goc, string anh){
    if (goc == NULL)
        return;
    if (anh < goc->data.tiengAnh){
        return xoaTu(goc->trai, anh);
    }
    else if (anh > goc->data.tiengAnh){
        return xoaTu(goc->phai, anh);
    }
    else {
        if (goc->trai == NULL && goc->phai == NULL){
            delete goc;
            goc = NULL;
        }
        else if (goc->trai == NULL){
            tuDienAnhViet *tmp = goc;
            goc = goc->phai;
            delete tmp;
        }
        else if (goc->phai == NULL){
            tuDienAnhViet *tmp = goc;
            goc = goc->trai;
            delete tmp;
        }
        else{
            tuDienAnhViet *tmp = tim(goc->phai);
            goc->data = tmp->data;
            xoaTu(goc->phai, tmp->data.tiengAnh);
        }
    }
}

// in tu bat dau bang chu h
void inTuBatDauH(tuDienAnhViet *goc){
    if(goc){
        if (goc->data.tiengAnh[0] == 'H' || goc->data.tiengAnh[0] == 'h'){
            cout << goc->data.tiengAnh << ": " << goc->data.tiengViet << endl;
        }
        inTuBatDauH(goc->trai);
        inTuBatDauH(goc->phai);        
    }
    
}

//dem bao nhieu tu sau tu t
int demSauTuT(tuDienAnhViet* goc, string tuvung){
    if (goc == NULL)
        return 0;
    if (goc->data.tiengAnh > tuvung)
        return 1 + demSauTuT(goc->trai, tuvung) + demSauTuT(goc->phai, tuvung);
    else if (goc->data.tiengAnh < tuvung)
        return  demSauTuT(goc->phai, tuvung);
    else
        return demSauTuT(goc->trai, tuvung);
}

//luu tu dien vao tep
void luuVaoTep(tuDienAnhViet *goc, string tenFile){
    ofstream file(tenFile, ios::app);
    if (file.is_open()){
        if(goc){
            file << goc->data.tiengAnh << ": " << goc->data.tiengViet << endl;
            luuVaoTep(goc->trai, tenFile);
            luuVaoTep(goc->phai, tenFile);
        }
    }
    file.close();
}

int main() {
    tuDienAnhViet *goc = NULL;
    string anh, viet;

    docTuTep(goc, "tdav.txt");

    inTuDien(goc);

    cout << "Nhap tu can tra: ";
    cin >> anh;
    viet = traTu(goc, anh);
    if (viet!="")
        cout << anh << ": " << viet << endl;
    else
        cout << anh << " khong co trong tu dien" << endl;
    
    xoaTu(goc, "hello");
    inTuDien(goc);

    cout << "Tu bat dau bang chu H: ";
    inTuBatDauH(goc);
    cout << endl;

    int dem = demSauTuT(goc, "begin");
    cout << "So tu sau tu: " << dem << endl;
    
    tuVung tu1 = {"nice", "tuyet voi"};
    themTu(goc, tu1);
    string tenFile = "tdav.txt";
    luuVaoTep(goc, tenFile);
    cout << "Da them thanh cong" << endl;
    
    return 0;
}