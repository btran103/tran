#include <iostream>
using namespace std;


struct Date {
    int d, m, y;  
};


bool isLeap(int y) {
    return (y%400==0) || (y%4==0 && y%100!=0);
}


int daysInMonth(int m, int y) {
    if(m==2) return isLeap(y)?29:28;
    if(m==4||m==6||m==9||m==11) return 30;
    return 31;
}


istream& operator>>(istream& in, Date &a) {
    in >> a.d >> a.m >> a.y;
    return in;
}
ostream& operator<<(ostream& out, const Date &a) {
    out << a.d << "/" << a.m << "/" << a.y;
    return out;
}

Date operator+(Date a, int k) {
    a.d += k;
    while(a.d > daysInMonth(a.m,a.y)) {  
        a.d -= daysInMonth(a.m,a.y);
        a.m++;
        if(a.m>12) { a.m=1; a.y++; }
    }
    return a;
}


Date operator-(Date a, int k) {
    return a+(-k); 
}


long toDays(Date a) {
    long res=a.d;
    for(int y=1;y<a.y;y++) res+=isLeap(y)?366:365;
    for(int m=1;m<a.m;m++) res+=daysInMonth(m,a.y);
    return res;
}


long operator-(Date a, Date b) {
    return toDays(a)-toDays(b);
}

string dayOfWeek(Date a) {
    int q=a.d, m=a.m, y=a.y;
    if(m<3){ m+=12; y--; }
    int h=(q + (13*(m+1))/5 + y + y/4 - y/100 + y/400) % 7;
    string w[]={"Sat","Sun","Mon","Tue","Wed","Thu","Fri"};
    return w[h];
}


int main() {
    Date d1,d2;
    cout<<"Nhap ngay thang nam d1: "; cin>>d1;
    cout<<"Nhap ngay thang nam d2: "; cin>>d2;

    cout<<"d1 = "<<d1<<" ("<<dayOfWeek(d1)<<")\n";
    cout<<"d2 = "<<d2<<" ("<<dayOfWeek(d2)<<")\n";
    cout<<"Khoang cach giua d1 va d2: "<<(d2-d1)<<" ngay\n";
    cout<<"d1+10 ngay = "<<(d1+10)<<"\n";
    cout<<"d2-5 ngay = "<<(d2-5)<<"\n";
}
