//계수정

#include <iostream>
#include <vector>

#define MAX 20
typedef int itemType;
using namespace std;

itemType *a, *b, *N;
void CountSort(itemType *a, itemType *b, itemType *N, int n, int k){
    int i,j;
    for(i=1; i<=k; i++) N[i]=0;
    for(i=1; i<=n; i++) N[a[i]] = N[a[i]] + 1;
    for(i=2; i<=k; i++) N[i] = N[i] + N[i-1];
    for(j=n; j>=1; j--) {
        b[N[a[j]]] = a[j];
        N[a[j]] = N[a[j]] - 1;
    }
}

int main(){
    int size;
    scanf("%d",&size);

    int *a = new int[size];
    int *b = new int[size];
    int *c = new int[size];
    // 조건에 맞는 배열 A, B 생성
    srand((unsigned)time(NULL));
    vector<pair<int,int>> v;
    for(int i=0; i<size;i++){
        v.push_back(pair<int,int>(rand()%size+1,i+1));
    }
    for(int i;i<size;i++) c[i] = v[i].first;
    sort(v.begin(), v.end());
    for(int i=0;i<size;i++){
        a[i] = size - i;
        b[i] = v[i].second;
    }

    a = new itemType[size]; b = new itemType[size]; N = new itemType[size];
//    CountSort()
}