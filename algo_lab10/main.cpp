#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;
int *skip; // SP와 같은 크기로 동적 할당해 주어야함
int *SP;  // SP에 대한 메모리는 p의 크기만큼 동적 할당 해야함
int *lp;
const int q = 33554393;
const int d = 26;
const int alphabet_count = 26;
int Brute_comp = 0;
int KMP_comp = 0;
int Boyer_comp = 0;

void LastPos(char *p);
void GoodSuffix(char *p);
void initSP(char *p);

int index(char a)
{
    return toupper(a) - 'A';
}

void initSP(char *p) {
    int i, j, m = strlen(p);
    SP = (int*)malloc(sizeof(int)*m);
    SP[0] = -1;
    for (i = 1, j = -1; i <= m - 1; i++) {
        while ((j >= 0) && (p[j + 1] != p[i]))
            j = SP[j]; //불일치할 경우 SP
        if (p[j + 1] == p[i])
            j++;
        SP[i] = j;
    }
}

//가장 끝에 있는 문자 index를 lp에 저장
void LastPos(char *p) {
    int i;
    lp = new int[alphabet_count];
    for (i = 0; i < alphabet_count; i++) lp[i] = -1;
    for (i = 0; i < strlen(p); i++) lp[index(p[i])] = i;
}

//Boyer-Moore
void boyermoore(char *p, char *a) {
    int i, j, m = strlen(p), n = strlen(a);
    LastPos(p);
    GoodSuffix(p);
    j = 0;
    while (j <= n - m) {
        for (i = m - 1; i >= 0 && p[i] == a[j + i]; i--) Boyer_comp++; //뒤에서부터 비교
        if (i != -1) Boyer_comp++;
        if (i == -1) {//pattern 찾은 경우
            Boyer_comp++;
            cout << j << " ";
            j = j + skip[-1];
        }
        else {//매치 실패시 skip과 lp 중 큰 값으로 jump
            j = j + max(skip[i], i - lp[index(a[j + i])]);
        }
    }
}

void GoodSuffix(char *p) {
    int i, k, m = strlen(p);
    skip = new int[m];
    char *r_p = new char[m];
    for (i = 0; i < m; i++) {
        r_p[m - i - 1] = p[i];
    }
    initSP(r_p); //역순 문자열로 SP table 생성
    for (i = -1; i <= m - 1; i++) skip[i] = m - 1 - SP[m - 1];
    for (k = 0; k <= m - 1; k++) {
        i = m - 1 - SP[k] - 1;
        if (skip[i] > k - SP[k]) skip[i] = k - SP[k];
    }
}

//Brute-Force
void brutesearch(char *p, char *a) {  //p : Pattern String, a : Text String
    int i, j, m = strlen(p), n = strlen(a);
    for (i = 0; i <= n - m; i++) {
        //Pattern String의 첫 글자부터 Text String과 비교
        for (j = 0; j < m; j++) {
            Brute_comp++; //비교하였으므로 비교 횟수 증가
            if (a[i + j] != p[j]) {
                break; //일치되지 않으면 break
            }
        }
        //일치할 경우 문자열이 시작하는 index값 출력
        if (j == m) {
            cout << i << " ";
        }
    }
    cout << endl;
}

//KMP
void kmpsearch(char *p, char *a) {
    int i, j, m = strlen(p), n = strlen(a);
    initSP(p);
    for (i = 0, j = -1; i <= n - 1; i++) {
        while ((j >= 0) && (p[j + 1] != a[i])) {
            j = SP[j]; //문자열을 failure function 이후 부터 비교를 해줌
            KMP_comp++;
        }
        //비교하는 문자가 같은 경우
        if (p[j + 1] == a[i]) {
            j++;
        }
        if (j == m - 1) {
            KMP_comp++;
            j = SP[j]; //다음 탐색을 위해 문자열을 failure function 이후 부터 비교를 해줌0
            cout << i - m + 1 << " "; // 결과값 출력
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


    cout << "\nBrute-Force 문자 비교 횟수 : " << Brute_comp << endl;
    cout << "KMP 문자 비교 횟수 : " << KMP_comp << endl;
    cout << "Boyer-Moore 문자 비교 횟수 : " << Boyer_comp << endl;
    cout << endl;
}