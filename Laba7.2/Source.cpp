#include <iostream>
#include <string>
#include "marsh.h"
using namespace std;
int main() {
    char str[1000];
    int n;
    cout << "Enter the number of routes:" << endl;
    cin.getline(str, 1000);
    n = atoi(str);
    if (n <= 0)return 1;
    Marsh* trafic = new Marsh[n];
    SetMarsh(trafic, n);
    Sort(trafic, n);
    Serch(trafic, n);
    system("pause");
    delete[]trafic;
    return 0;
}