#include <iostream>
#include <vector>

#define NUM 20

typedef int itemType;

using namespace std;

itemType *sorted;
void merge(itemType a[],int l,int mid, int r, int &compare, int &move){
    int i,j,k,n;
    i=l; j=mid+1; k=l;
    while (i<=mid && j<=r){
        if (a[i]<=a[j]) {
            compare++;
            sorted[k++] = a[i++];
            move++;
        }
        else{
            compare++;
            sorted[k++] = a[j++];
            move++;
        }
    }
    if (i>mid){
        for (n=j; n<=r; n++){
            sorted[k++] = a[n];
            move++;
        }
    }
    else{
        for (n=i; n<=mid; n++){
            sorted[k++] = a[n];
            move++;
        }
    }
    for (n=l; n<=r; n++){
        a[n] = sorted[n];
        move++;
    }
}

void mergesort(itemType a[],int l, int r, int &compare, int &move){
    int mid;
    if (l < r) {
        mid = ( l + r)/2;
        mergesort(a, l, mid, compare , move);
        mergesort(a, mid+1, r, compare,move);
        merge(a, l, mid, r, compare, move);
    }
}

int main(){
    int size;
    scanf("%d",&size);

    int *a = new int[size];
    int *b = new int[size];
    sorted = new int[size];
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

    int compareA=0,moveA=0;
    mergesort(a,0,size-1,compareA,moveA);
    cout<<"SortedData_A : ";
    for(int i=0;i<NUM;i++) cout << a[i] << " ";

    int compareB=0,moveB=0;
    mergesort(b,0,size-1,compareB,moveB);
    cout<< endl << "SortedData_B : ";
    for(int i=0;i<NUM;i++) cout << b[i] << " ";

    cout << endl <<  "Compare_Cnt_A : " << compareA << ", DataMove_Cnt_A : " << moveA << endl;
    cout << "Compare_Cnt_B : " << compareB << ", DataMove_Cnt_B : " << moveB << endl;

    return 0;
}
