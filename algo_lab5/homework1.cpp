#include <iostream>
#include <vector>

#define MAX 20
typedef int itemType;
using namespace std;

class MAKE_HEAP{
private:
    itemType *a;
    int N;
public:
    MAKE_HEAP(int max){ a = new itemType[max]; N = 0;}
    ~MAKE_HEAP(){ delete a; }
    void swap(itemType a[], int i, int j){
        int temp;
        temp = a[j]; a[j] = a[i]; a[i] = temp;
    }
    void MakeHeap(itemType a[], int Root, int LastNode){
        int Parent, LeftSon, RightSon, Son; itemType RootValue;
        Parent = Root;
        RootValue = a[Root];
        LeftSon = 2*Parent +1;
        RightSon = LeftSon + 1;
        while(LeftSon < LastNode) {
            if (RightSon <= LastNode && a[LeftSon] < a[RightSon]) {
                Son = RightSon;}
            else Son = LeftSon;
            if (RootValue < a[Son]) {
                a[Parent] = a[Son];
                Parent = Son;
                LeftSon = Parent * 2 + 1;
                RightSon = LeftSon + 1;
            } else break;
        }
        a[Parent] = RootValue;
    }
    void heapsort(itemType a[], int N){
        int i;
        for(i = N/2;i>=1;i--) MakeHeap(a,i-1,N-1);
        for(i = N;i>=1; i--){ swap(a,0,i); MakeHeap(a,0,i-1);}

        for(i = 0;i<N;i++) cout << a[i] <<" ";
    }
};

int main() {
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

    MAKE_HEAP heap = MAKE_HEAP(size);
    heap.heapsort(a,size);

    return 0;
}