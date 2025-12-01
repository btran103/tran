#include <iostream>
using namespace std;

void insertRec(int a[], int n)
{
    
    if (n <= 1)
        return;

   
    insertRec(a, n - 1);

    
    int last = a[n - 1];
    int j = n - 2;

    while (j >= 0 && a[j] > last)
    {
        a[j + 1] = a[j];
        j--;
    }
    a[j + 1] = last;
}

int partitionArray(int a[], int low, int high)
{
    int pivot = a[high]; 
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[high]);
    return i + 1;
}

void quickSort(int a[], int low, int high)
{
    if (low < high)
    {
        int pi = partitionArray(a, low, high);

        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}


int main()
{
    int a[100], n;

    cout << "Nhap so phan tu: ";
    cin >> n;

    cout << "Nhap day so: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << "\n1. InsertSort de quy";
    cout << "\n2. QuickSort de quy";
    cout << "\nChon thuat toan: ";

    int chon;
    cin >> chon;

    if (chon == 1)
        insertRec(a, n);
    else if (chon == 2)
        quickSort(a, 0, n - 1);

    cout << "\nDay sau khi sap xep tang dan: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}

