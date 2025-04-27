Chuy?n d?n n?i dung chính
Google L?p h?c
L?p h?c
C?U TRÚC D? LI?U
L?P HP: CNTT46D(242105033304)
Bài th?c hành s? 2.Bài th?c hành s? 2.
Bài th?c hành s? 2.
Dinh Thi Hong Huyen Khoa CNTT
•
24 thg 2 (Ðã ch?nh s?a 24 thg 2)
100 di?m
Ð?n h?n 23:59 1 thg 3

Bai thuc hanh so 2.pdf
PDF
Nh?n xét c?a l?p h?c
Bài t?p c?a b?n
Ðã n?p

baith2.cpp
Van b?n
Không th? n?p bài t?p sau ngày d?n h?n
Nh?n xét riêng tu
#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int age;
    double gpa;
};

void inputStudent(Student &s) {
    cout << "Name: "; getline(cin, s.name);
    cout << "Age: "; cin >> s.age;
    cout << "GPA: "; cin >> s.gpa;
    cin.ignore();
}

void inputListOfStudent(Student list[], int n) {
    for(int i = 0; i < n; i++) {
    	cout << "Nhap hoc sinh " << i + 1 << " chi tiet:" << endl;
        inputStudent(list[i]);
    }
}

void listOfGoodStudents(const Student list[], int n) {
    for (int i = 0; i < n; i++) {
        if(list[i].gpa >= 8) {
            cout << list[i].name << list[i].gpa << endl;
        }
    }
}

int appendStudent(Student list[], int n, Student s) {
    list[n] = s;
    return n + 1;
}

int countFirstName(Student list[], int n) {
    int count = 0; 
    string s = "Nguyen";
    for (int i = 0; i < n; i++) {
        if (list[i].name.substr(0, 6) == s) {
            count++;
        }
    }
    return count;
}

string convertName(string name) {
    int i = name.length() - 1;
    string ten = " ";
    while (name[i] != ' ') {
        ten = name[i] + ten;
        name.erase(i);
        i--;
    }
    return ten + name;
}

void sortVNName(Student list[], int n) {
    for (int i = 0; i < n; i++) {
        list[i].name = convertName(list[i].name);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (list[j].name > list[j + 1].name) {
                swap(list[j], list[j + 1]);
            }
        }
    }
}

void printListOfStudent(Student list[], int n) {
    for (int i = 0; i < n; i++) {
        cout << list[i].name << ", Age: " << list[i].age << ", GPA: " << list[i].gpa << endl;
    }
}

int main() {
    Student m[100];
    int n = 5;
    inputListOfStudent(m, n);
    
    cout << "Good Students (GPA >= 8):" << endl;
    listOfGoodStudents(m, n);
    
    Student newStudent = {"Le Van An", 20, 9.0};
    n = appendStudent(m, n, newStudent);
    
    cout << "Count of students with first name 'Nguyen': " << countFirstName(m, n) << endl;
    
    cout << "Sorted List of Students by Name:" << endl;
    sortVNName(m, n);
    printListOfStudent(m, n);
    
    return 0;
}

baith2.cpp
Ðang hiê?n thi? baith2.cpp.
