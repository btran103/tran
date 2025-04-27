#include <iostream>
#include <string>

using namespace std;

struct Person {
    string name;
    int yearOfBirth;
};

struct FT {
    Person data;
    FT *child, *sibling;
};

// a) �em so nguoi trong c�y gia pha
int countPersons(FT *root) {
    if (root == nullptr) 
        return 0;

    int d = 1;
    FT *p = root->child;
    while (p != nullptr) {
        d += countPersons(p);
        p = p->sibling;
    }
    return d;
}

// b) T�nh so the he cua c�y gia pha
int height(FT *root) {
    if (root == nullptr) a
        return 0;

    int h, maxH = 0;
    FT *p = root->child;
    while (p != nullptr) {
        h = height(p);
        if (h > maxH) 
            maxH = h;
        p = p->sibling;
    }
    return maxH + 1;
}

// c) T�m 1 nguoi t�n x trong c�y gia pha
FT* search(FT *root, string name) {
    if (!root) 
        return nullptr;

    if (root->data.name == name)
        return root;

    FT *p = root->child;
    FT *result = nullptr;
    while (p) {
        result = search(p, name);
        if (result) 
            return result;
        p = p->sibling;
    }
    return nullptr;
}

// d) Kiem tra nguoi t�n y c� phai con nguoi t�n x kh�ng?
bool isParent(FT* root, string x, string y) {
    FT* r = search(root, x);
    if (r == nullptr) 
        return false;

    FT* p = r->child;
    while (p != nullptr) {
        if (p->data.name == y) 
            return true;
        p = p->sibling;
    }
    return false;
}

// e) T�nh the he cua nguoi t�n x
int level(FT* root, string x) {
    if (root == nullptr) 
        return 0;

    if (root->data.name == x) 
        return 1;

    FT* p = root->child;
    while (p != nullptr) {
        int h = level(p, x);
        if (h > 0) 
            return h + 1;
        p = p->sibling;
    }
    return 0;
}

// f) Liet k� tat ca nhung nguoi con cua nguoi t�n x
void printChildren(FT* root, string x) {
    FT* r = search(root, x);
    if (r != nullptr) {
        FT* p = r->child;
        while (p != nullptr) {
            cout << p->data.name << endl;
            p = p->sibling;
        }
    }
}

// g) Liet k� nhung nguoi thuoc the he thu k
void printLevel(FT* root, int k) {
    if (root != nullptr) {
        if (k == 1)
            cout << root->data.name << endl;
        else {
            FT* p = root->child;
            while (p != nullptr) {
                printLevel(p, k - 1);
                p = p->sibling;
            }
        }
    }
}

// h) Kiem tra nguoi t�n x v� y c� phai anh em kh�ng?
bool isSibling(FT* root, string x, string y) {
    if (root == nullptr) 
        return false;

    FT* r = root->child;
    bool chkx = false, chky = false;
    while (r != nullptr) {
        if (r->data.name == x) 
            chkx = true;
        if (r->data.name == y) 
            chky = true;
        if (chkx && chky) 
            return true;
        r = r->sibling;
    }

    r = root->child;
    while (r != nullptr) {
        if (isSibling(r, x, y)) 
            return true;
        r = r->sibling;
    }
    return false;
}

// i) In nhung nguoi thuoc the he thu k (d� gop tu c�u g)
void printByLevel(FT* root, int k) {
    printLevel(root, k);
}

// j) Kiem tra x c� phai con y kh�ng?
bool isChild(FT* root, string x, string y) {
    FT* r = search(root, y);
    if (r == nullptr)
        return false;

    FT* p = r->child;
    while (p != nullptr) {
        if (p->data.name == x)
            return true;
        p = p->sibling;
    }
    return false;
}

// k) Liet k� con, ch�u cua mot nguoi c� ho t�n x
void printDescendants(FT* root, string x) {
    FT* r = search(root, x);
    if (r != nullptr) {
        FT* p = r->child;
        while (p != nullptr) {
            cout << p->data.name << endl;
            printDescendants(p, p->data.name);
            p = p->sibling;
        }
    }
}

// Th�m met nguoi con moi
void insertChild(FT* root, Person p, string x) {
    FT* r = search(root, x);
    if (r != nullptr) {
        FT *q = new FT{p, nullptr, nullptr};
        FT* p1 = nullptr, *p2 = r->child;
        while (p2 != nullptr && p2->data.yearOfBirth < p.yearOfBirth) {
            p1 = p2;
            p2 = p2->sibling;
        }
        if (p1 == nullptr) {
            q->sibling = r->child;
            r->child = q;
        } else {
            q->sibling = p2;
            p1->sibling = q;
        }
    }
}

// X�a to�n bo c�y de tr�nh r� ri bo nho
void deleteTree(FT* root) {
    if (root == nullptr) return;

    FT* p = root->child;
    while (p != nullptr) {
        FT* next = p->sibling;
        deleteTree(p);
        p = next;
    }
    delete root;
}

int main() {
    FT* root = new FT{{"Grandparent", 1945}, nullptr, nullptr};

    insertChild(root, {"Parent1", 1970}, "Grandparent");
    insertChild(root, {"Parent2", 1972}, "Grandparent");
    insertChild(root, {"Child1", 1995}, "Parent1");
    insertChild(root, {"Child2", 1998}, "Parent1");
    insertChild(root, {"Child3", 2001}, "Parent2");

    cout << "Tong so nguoi: " << countPersons(root) << endl;
    cout << "So the he (chieu cao): " << height(root) << endl;

    cout << "\nCac con cua Parent1:\n";
    printChildren(root, "Parent1");

    cout << "\nCo phai Parent1 la cha cua Child1? " << (isParent(root, "Parent1", "Child1") ? "Yes" : "No") << endl;
    cout << "Co phai Child1 va Child2 la anh em? " << (isSibling(root, "Child1", "Child2") ? "Yes" : "No") << endl;
    cout << "Co phai Child1 la con cua Parent1? " << (isChild(root, "Child1", "Parent1") ? "Yes" : "No") << endl;

    cout << "\nCac nguoi o the he thu 1:\n";
    printByLevel(root, 1);

    cout << "\nCac nguoi o the he thu 2:\n";
    printByLevel(root, 2);

    cout << "\nCac nguoi o the he thu 3:\n";
    printByLevel(root, 3);

    cout << "\nTat ca con chau cua Grandparent:\n";
    printDescendants(root, "Grandparent");

    deleteTree(root);
    return 0;
}

