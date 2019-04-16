#include <iostream>
#include <vector>

#define MAX 20
typedef int itemType;
using namespace std;

class MAKE_HEAP{
private:
    itemType *a;
    int N;
    int compare;
    int move;
public:
    MAKE_HEAP(int max){ a = new itemType[max]; N = 0; compare = 0; move = 0; }
    ~MAKE_HEAP(){ delete a; }
    void swap(itemType a[], int i, int j){
        int temp;
        temp = a[j]; a[j] = a[i]; a[i] = temp; move+=3;
    }
    void MakeHeap(itemType a[], int Root, int LastNode){
        int Parent, LeftSon, RightSon, Son; itemType RootValue;
        Parent = Root;
        RootValue = a[Root];
        move++;
        LeftSon = 2*Parent;
        RightSon = LeftSon + 1;
        while(LeftSon < LastNode) {
            //자식 노드끼리 비교해주는 거
            compare++;
            if (RightSon <= LastNode && a[LeftSon] < a[RightSon]) {
                Son = RightSon;}
            else Son = LeftSon;
            // root node 값이랑 비교하는 거
            compare++;
            if (RootValue < a[Son]) {
                a[Parent] = a[Son];
                move++;
                Parent = Son;
                LeftSon = Parent * 2;
                RightSon = LeftSon + 1;
            } else break;
        }
        a[Parent] = RootValue;
        move++;
    }
    void heapsort(itemType a[], int N){
        int i;
        for(i = N/2;i>=1;i--) MakeHeap(a,i,N);
        for(i = N;i>=1; i--){ swap(a,0,i); MakeHeap(a,0,i-1);}

        for(i = 0;i<MAX;i++) cout << a[i] <<" ";
        cout << endl;
    }

    int getCompare(){
        return compare;
    }
    int getMove(){
        return move;
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
    for(int i=0;i<size;i++) c[i+1] = v[i].first;
    sort(v.begin(), v.end());
    for(int i=0;i<size;i++){
        a[i+1] = size - i;
        b[i+1] = v[i].second;
    }

    MAKE_HEAP heap = MAKE_HEAP(size);
    int counts[6];
    cout << "SortedData_A : ";
    heap.heapsort(a,size);
    counts[0] = heap.getCompare();
    counts[1] = heap.getMove();
    cout << "SortedData_B : ";
    heap.heapsort(b,size);
    counts[2] = heap.getCompare();
    counts[3] = heap.getMove();
    cout << "SortedData_C : ";
    heap.heapsort(c,size);
    counts[4] = heap.getCompare();
    counts[5] = heap.getMove();

    cout << "Compare_Cnt_A : " << counts[0] << ", DataMove_Cnt_A : " << counts[1] << endl;
    cout << "Compare_Cnt_B : " << counts[2] << ", DataMove_Cnt_B : " << counts[3] << endl;
    cout << "Compare_Cnt_C : " << counts[4] << ", DataMove_Cnt_C : " << counts[5] << endl;

    return 0;
}