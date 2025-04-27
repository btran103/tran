#include <iostream>
#include <fstream>
using namespace std;

struct Word {
    string english;
    string vietnamese;
};

struct EngVietDict {
    Word data;
    EngVietDictionary *left, *right;
};


void insertWord(EngVietDictionary *&root, Vocabulary data) {
    if (root == NULL) {
        root = new EngVietDictionary;
        root->data = data;
        root->left = root->right = NULL;
    }
    else if (data.english < root->data.english) {
        insertWord(root->left, data);
    }
    else if (data.english > root->data.english) {
        insertWord(root->right, data);
    }
}

void loadDictionaryFromFile(EngVietDictionary *&root, string filename) {
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        int pos = line.find(':');
        string eng = line.substr(0, pos);
        string viet = line.substr(pos + 1);
        Vocabulary data = {eng, viet};
        insertWord(root, data);
    }
    file.close();
}

void printDictionary(EngVietDictionary *root) {
    if (root) {
        printDictionary(root->left);
        cout << root->data.english << ": " << root->data.vietnamese << endl;
        printDictionary(root->right);
    }
}


string lookupWord(EngVietDictionary *root, string englishWord) {
    if (root == NULL) return "";
    if (root->data.english == englishWord) return root->data.vietnamese;
    if (englishWord < root->data.english)
        return lookupWord(root->left, englishWord);
    else
        return lookupWord(root->right, englishWord);
}

// Tìm node nh? nh?t bên ph?i (thay th? khi xóa node có 2 nhánh)
EngVietDictionary* findMin(EngVietDictionary *root) {
    if (root->left == NULL) return root;
    return findMin(root->left);
}

// Xoá t? kh?i t? di?n
void deleteWord(EngVietDictionary *&root, string englishWord) {
    if (root == NULL) return;

    if (englishWord < root->data.english) {
        deleteWord(root->left, englishWord);
    }
    else if (englishWord > root->data.english) {
        deleteWord(root->right, englishWord);
    }
    else {
        if (root->left == NULL && root->right == NULL) {
            delete root;
            root = NULL;
        }
        else if (root->left == NULL) {
            EngVietDictionary *temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == NULL) {
            EngVietDictionary *temp = root;
            root = root->left;
            delete temp;
        }
        else {
            EngVietDictionary *temp = findMin(root->right);
            root->data = temp->data;
            deleteWord(root->right, temp->data.english);
        }
    }
}

// In các t? b?t d?u b?ng ch? H ho?c h
void printWordsStartingWithH(EngVietDictionary *root) {
    if (root) {
        if (root->data.english[0] == 'H' || root->data.english[0] == 'h') {
            cout << root->data.english << ": " << root->data.vietnamese << endl;
        }
        printWordsStartingWithH(root->left);
        printWordsStartingWithH(root->right);
    }
}

// Ð?m s? lu?ng t? có giá tr? l?n hon t? cho tru?c
int countWordsAfter(EngVietDictionary* root, string word) {
    if (root == NULL) return 0;
    
    if (root->data.english > word)
        return 1 + countWordsAfter(root->left, word) + countWordsAfter(root->right, word);
    else if (root->data.english < word)
        return countWordsAfter(root->right, word);
    else
        return countWordsAfter(root->left, word);
}

// Luu t? di?n vào file
void saveDictionaryToFile(EngVietDictionary *root, string filename) {
    ofstream file(filename, ios::app);
    if (file.is_open()) {
        if (root) {
            file << root->data.english << ": " << root->data.vietnamese << endl;
            saveDictionaryToFile(root->left, filename);
            saveDictionaryToFile(root->right, filename);
        }
    }
    file.close();
}

int main() {
    EngVietDictionary *root = NULL;
    string english, vietnamese;

    loadDictionaryFromFile(root, "tdav.txt");
    printDictionary(root);

    cout << "Enter word to look up: ";
    cin >> english;

    vietnamese = lookupWord(root, english);
    if (!vietnamese.empty())
        cout << english << ": " << vietnamese << endl;
    else
        cout << english << " not found in the dictionary." << endl;

    deleteWord(root, "hello");
    printDictionary(root);

    cout << "Words starting with 'H': " << endl;
    printWordsStartingWithH(root);

    int count = countWordsAfter(root, "begin");
    cout << "Number of words after 'begin': " << count << endl;

    Vocabulary newWord = {"nice", "tuyet voi"};
    insertWord(root, newWord);

    string filename = "tdav.txt";
    saveDictionaryToFile(root, filename);
    cout << "Successfully added and saved!" << endl;

    return 0;
}

