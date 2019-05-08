#include <iostream>
#include <string>

using namespace std;

int main(){
    string sampleT="";
    for(int i=0;i<100;i++) sampleT += 'A';
    string T[100];
    for(int i=0;i<100;i++) T[i] = sampleT;

    string sampleP="";
    for(int i=0;i<9;i++) sampleP += 'A';
    string P[10];
    for(int i=0;i<9;i++) P[i] = sampleP + 'A';
    P[9] = sampleP + 'B';

    //bruteforce
}