#ifndef MARSH_H
#define MARSH_H
using namespace std;
struct Marsh {
    char begin[80];
    char end[80];
    int number;
};
void SetMarsh(Marsh* marsh, int n) {
    for (int i(0); i < n; i++) {
        cout << "Entry^:" << i + 1 << endl;
        cout << "Enter the beginning of the route:" << endl;
        cin.getline(marsh[i].begin, 80);
        cout << "Enter the end of the route:" << endl;
        cin.getline(marsh[i].end, 80);
        char str[1000];
        cout << "Enter route number:" << endl;
        cin.getline(str, 1000);
        marsh[i].number = atoi(str);
    }
};
void printMarsh(Marsh* marsh, int n) {
    cout << "\tStart: " << marsh[n].begin
        << "\n\tFinish: " << marsh[n].end
        << "\n\tRoute number: " << marsh[n].number
        << endl;
}
void Sort(Marsh* marsh, int n) {
    bool flag = true;
    while (flag) {
        flag = false;
        for (int i = 1; i < n; i++) {
            if (marsh[i].number < marsh[i - 1].number) {
                swap(marsh[i].begin, marsh[i - 1].begin);
                swap(marsh[i].end, marsh[i - 1].end);
                swap(marsh[i].number, marsh[i - 1].number);
                flag = true;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << "Entry#" << i + 1 << ": " << endl;
        printMarsh(marsh, i);
    }
}

void Serch(Marsh* marsh, int n) {
    cout << "****Route search****" << endl;
    int begin;
    bool flag;
    do {
        cout << "Enter item name: ";
        string naz;
        getline(cin, naz);
        flag = false;
        for (int i = 0; i < n; i++) {
            if ((marsh[i].begin == naz) || (marsh[i].end == naz)) {
                printMarsh(marsh, i);
                flag = true;
            }
        }
        if (!flag) {
            cout << "No such item found" << endl;
        }
        cout << endl << "\n Repeat ? (1(Yes) or 0(No)): ";
        cin >> begin; cin.ignore();
    } while (begin != 0);
}
#endif