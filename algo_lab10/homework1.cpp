#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;

int *skip;
int *SP;

int bruteCount = 0;
int kmpCount = 0;
int bmCount = 0;

void initSP(char *p) {
    int i, j, m = strlen(p);
    SP = (int*)malloc(sizeof(int)*m);
    SP[0] = -1;
    for (i = 1, j = -1; i <= m - 1; i++) {
        while ((j >= 0) && (p[j + 1] != p[i]))
            j = SP[j];
        if (p[j + 1] == p[i])
            j++;
        SP[i] = j;
    }
}

const int alphabet_count = 26;

int index(char a)
{
    return toupper(a) - 'A';
}

int *lp;

void LastPos(char *p) {
    int i;
    lp = new int[alphabet_count];
    for (i = 0; i < alphabet_count; i++) lp[i] = -1;
    for (i = 0; i < strlen(p); i++) lp[index(p[i])] = i;
}

void GoodSuffix(char *p) {
    int i, k, m = strlen(p);
    skip = new int[m];
    char *r_p = new char[m];
    for (i = 0; i < m; i++) {
        r_p[m - i - 1] = p[i];
    }
    initSP(r_p);
    for (i = -1; i <= m - 1; i++) skip[i] = m - 1 - SP[m - 1];
    for (k = 0; k <= m - 1; k++) {
        i = m - 1 - SP[k] - 1;
        if (skip[i] > k - SP[k]) skip[i] = k - SP[k];
    }
}

void boyermoore(char *p, char *a) {
    int i, j, m = strlen(p), n = strlen(a);
    LastPos(p);
    GoodSuffix(p);
    j = 0;
    while (j <= n - m) {
        for (i = m - 1; i >= 0 && p[i] == a[j + i]; i--) bmCount++;
        if (i != -1) bmCount++;
        if (i == -1) {
            bmCount++;
            cout << j << " ";
            j = j + skip[-1];
        }
        else {
            j = j + max(skip[i], i - lp[index(a[j + i])]);
        }
    }
}

void brutesearch(char *p, char *a) {
    int i, j, m = strlen(p), n = strlen(a);
    for (i = 0; i <= n - m; i++) {
        for (j = 0; j < m; j++) {
            bruteCount++;
            if (a[i + j] != p[j]) break;
        }
        if (j == m) cout << i << " ";
    }
    cout << endl;
}

void kmpsearch(char *p, char *a) {
    int i, j, m = strlen(p), n = strlen(a);
    initSP(p);
    for (i = 0, j = -1; i <= n - 1; i++) {
        while ((j >= 0) && (p[j + 1] != a[i])) {
            j = SP[j];
            kmpCount++;
        }

        if (p[j + 1] == a[i]) j++;
        if (j == m - 1) {
            kmpCount++;
            j = SP[j];
            cout << i - m + 1 << " ";
        }
    }
    cout << endl;
}

int main()
{
    ifstream fin("");

    char input[10000];
    char TString[300];
    char PString[300];
    cin.getline(input, 10000);
    cout << "Pattern String : ";
    gets(PString);

    cout<<endl;
    brutesearch(PString, input);
    kmpsearch(PString, input);
    boyermoore(PString, input);


    cout << "\nBrute-Force 문자 비교 횟수 : " << bruteCount << endl;
    cout << "KMP 문자 비교 횟수 : " << kmpCount << endl;
    cout << "Boyer-Moore 문자 비교 횟수 : " << bmCount << endl;
    cout << endl;
}