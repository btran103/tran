#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Word {
    string english;
    string vietnamese;
};

struct EngVietDict {
    Word data;
    EngVietDict *left, *right;
};

// Insert a word into the dictionary (BST)
void insertWord(EngVietDict *&root, Word data) {
    if (!root) {
        root = new EngVietDict{data, nullptr, nullptr};
    } else if (data.english < root->data.english) {
        insertWord(root->left, data);
    } else if (data.english > root->data.english) {
        insertWord(root->right, data);
    }
}

// Read dictionary from a text file
void readDictFromFile(EngVietDict *&root, const string &fileName) {
    ifstream file(fileName);
    if (!file.is_open()) {
        cerr << "Error: Cannot open file '" << fileName << "'\n";
        return;
    }

    string line;
    while (getline(file, line)) {
        int pos = line.find(':');
        if (pos == string::npos) {
            cerr << "Skipped invalid line: " << line << endl;
            continue;
        }

        string eng = line.substr(0, pos);
        string viet = line.substr(pos + 1);

        // Trim spaces
        eng.erase(0, eng.find_first_not_of(" \t"));
        eng.erase(eng.find_last_not_of(" \t") + 1);
        viet.erase(0, viet.find_first_not_of(" \t"));
        viet.erase(viet.find_last_not_of(" \t") + 1);

        if (!eng.empty() && !viet.empty()) {
            insertWord(root, {eng, viet});
        }
    }

    file.close();
}

// Print dictionary (in-order traversal)
void printDict(EngVietDict *root) {
    if (root) {
        printDict(root->left);
        cout << root->data.english << " : " << root->data.vietnamese << endl;
        printDict(root->right);
    }
}

// Find the Vietnamese meaning of an English word
string findVietnamese(EngVietDict *root, const string &eng) {
    if (!root) return "";
    if (root->data.english == eng) return root->data.vietnamese;
    if (eng < root->data.english) return findVietnamese(root->left, eng);
    else return findVietnamese(root->right, eng);
}

// Find the minimum node (used in deletion)
EngVietDict *findMin(EngVietDict *root) {
    while (root && root->left) {
        root = root->left;
    }
    return root;
}

// Delete a word from the dictionary
void deleteWord(EngVietDict *&root, const string &eng) {
    if (!root) return;

    if (eng < root->data.english) {
        deleteWord(root->left, eng);
    } else if (eng > root->data.english) {
        deleteWord(root->right, eng);
    } else {
        if (!root->left) {
            EngVietDict *temp = root;
            root = root->right;
            delete temp;
        } else if (!root->right) {
            EngVietDict *temp = root;
            root = root->left;
            delete temp;
        } else {
            EngVietDict *temp = findMin(root->right);
            root->data = temp->data;
            deleteWord(root->right, temp->data.english);
        }
    }
}

// Save dictionary to text file (pre-order traversal)
void preOrder(EngVietDict *node, ofstream &outFile) {
    if (!node) return;
    outFile << node->data.english << ":" << node->data.vietnamese << endl;
    preOrder(node->left, outFile);
    preOrder(node->right, outFile);
}

void saveDictToFile(EngVietDict *dict, const string &fileName) {
    ofstream outFile(fileName);
    if (!outFile.is_open()) {
        cerr << "Error: Cannot open file '" << fileName << "' for writing.\n";
        return;
    }
    preOrder(dict, outFile);
    outFile.close();
    cout << "Dictionary saved to '" << fileName << "' successfully.\n";
}

// Free memory
void freeMemory(EngVietDict *&root) {
    if (root) {
        freeMemory(root->left);
        freeMemory(root->right);
        delete root;
        root = nullptr;
    }
}

int main() {
    EngVietDict *root = nullptr;
    readDictFromFile(root, "EVD.txt");

    cout << "\n=== English-Vietnamese Dictionary ===\n";
    printDict(root);

    string eng;
    cout << "\nInput an English word to look up: ";
    cin >> eng;

    string viet = findVietnamese(root, eng);
    if (!viet.empty()) {
        cout << eng << " : " << viet << endl;
    } else {
        cout << "'" << eng << "' not found in dictionary.\n";
    }

    cout << "\nDeleting 'Hello' from dictionary...\n";
    deleteWord(root, "Hello");

    cout << "\nUpdated Dictionary:\n";
    printDict(root);

    saveDictToFile(root, "UpdatedEVD.txt");

    freeMemory(root);
    return 0;
}

