#include <bits/stdc++.h>
using namespace std;

struct Point {
    float x, y;
};

float khoangCach(Point a, Point b) {
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

int main() {
    int n;
    cout << "Nhap so diem: ";
    cin >> n;

    Point p[100];
    for (int i = 0; i < n; i++) {
        cout << "Nhap toa do diem thu " << i + 1 << " (x y): ";
        cin >> p[i].x >> p[i].y;
    }

    float minD = 1e9;
    int a = 0, b = 1;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            float d = khoangCach(p[i], p[j]);
            if (d < minD) {
                minD = d;
                a = i;
                b = j;
            }
        }
    }

    cout << "\nHai diem gan nhau nhat la:\n";
    cout << "Diem 1: (" << p[a].x << ", " << p[a].y << ")\n";
    cout << "Diem 2: (" << p[b].x << ", " << p[b].y << ")\n";
    cout << "Khoang cach: " << fixed << setprecision(4) << minD << endl;

    return 0;
}

