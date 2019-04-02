#include <iostream>
#include <vector>

typedef int itemType;

using namespace std;

inline void swap(itemType a[], int i, int j){
    itemType t = a[i]; a[i] = a[j]; a[j] = t;
}

int partition(itemType a[], int l, int r){
    int i,j; itemType v;
    if(r > l){

        v = a[l]; i = l; j = r +1;
        for(;;){
            while(a[++i] < v);
            while(a[--j] > v);
            if(i>=j) break;
            else swap(a,i,j);
        }
        swap(a,j,l);
    }
    return j;
}

void quicksort(itemType a[], int l, int r){
    int j;
    if(r>l){
        j = partition(a,l,r);
        quicksort(a,l,j-1);
        quicksort(a,j+1,r);
    }
}

int main() {
    int size;
    scanf("%d",&size);

    int *a = new int[size];
    int *b = new int[size];
    int *cntA = new int[2];
    int *cntB = new int[2];
    // 조건에 맞는 배열 A, B 생성
    srand((unsigned)time(NULL));
    vector<pair<int,int>> v;
    for(int i=0; i<size;i++){
        v.push_back(pair<int,int>(rand()%size+1,i+1));
    }
    sort(v.begin(), v.end());
    for(int i=0;i<size;i++){
        a[i] = size - i;
        b[i] = v[i].second;
    }

    return 0;
}