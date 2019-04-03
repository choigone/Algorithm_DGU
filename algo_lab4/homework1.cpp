#include <iostream>
#include <vector>

#define NUM 20

typedef int itemType;

using namespace std;

inline void swap(itemType a[], int i, int j){
    itemType t = a[i]; a[i] = a[j]; a[j] = t;
}

int partition(itemType a[], int l, int r, int &compare, int &move){
    int i,j; itemType v;
    if(r > l){
        v = a[l]; i = l; j = r +1;
        move++;
        while(1){
            while(1){
                if(a[++i] < v){ compare++; }
                else {
                    compare++;
                    break;
                }
            }
            while(1){
                if(a[--j]>v){ compare++; }
                else{
                    compare++;
                    break;
                }
            }
            if(i>=j) break;
            else{
                swap(a,i,j);
                move+=3;
            }
        }
        swap(a,j,l);
        move+=3;
    }
    return j;
}

void quicksort(itemType a[], int l, int r, int &compare, int &move){
    int j;
    if(r>l){
        j = partition(a,l,r,compare,move);
        quicksort(a,l,j-1,compare,move);
        quicksort(a,j+1,r,compare,move);
    }
}

int main() {
    int size;
    scanf("%d",&size);

    int *a = new int[size];
    int *b = new int[size];
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
    int compareB=0,moveB=0;
    quicksort(a,0,size-1,compareA,moveA);
    quicksort(b,0,size-1,compareB,moveB);

    cout<<"SortedData_A : ";
    for(int i=0;i<NUM;i++) cout << a[i] << " ";
    cout<< endl << "SortedData_B : ";
    for(int i=0;i<NUM;i++) cout << b[i] << " ";

    cout << endl <<  "Compare_Cnt_A : " << compareA << ", DataMove_Cnt_A : " << moveA << endl;
    cout << "Compare_Cnt_B : " << compareB << ", DataMove_Cnt_B : " << moveB << endl;

    return 0;
}