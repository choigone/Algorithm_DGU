#include <iostream>
#include <vector>

#define MAX 20
typedef int itemType;
using namespace std;

typedef struct node *node_pointer;
typedef struct node{
    itemType value;
    node_pointer next;
};

node_pointer TABLE[10],x,z,temp;

void radixSort(itemType *a, int n){
    int i,j,cnt,radix, radix_mod=10,cipher=0;
    i = n;
    while(i>0){i=i/10; cipher++;} // cipher : 입력 데이터의 자리수 (ex. 450 -> 3)
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cnt = 0; radix = (a[j]%radix_mod)/(radix_mod/10);
            /* radix_mod = 10 이면 radix는 a[j]의 일의 자리수
            radix_mod = 100 이면 radix는 a[j]의 십의 자리수 */
            temp = new node; temp -> value = a[j]; temp -> next =z;
            if(TABLE[radix] == z){
                // z는 list의 끝을 확인하기 위한 노드 포인터 (NULL에 해당)
                TABLE[radix] = temp;
            }
            else{
                x = TABLE[radix];
                while(x->next!=z){
                    x = x->next;
                }
                x->next = temp;
            }
        }

        for(j=0;j<10;j++){
            if(TABLE[j]!=z){
                x = TABLE[j];
                while(x!=z){
                    a[cnt++] = x->value;
                    temp = x; // 메모리에서 노드를 삭제하기 위해 임시저장
                    x = x->next;
                    delete temp;
                }
            }
            TABLE[j] = z;
        }
        radix_mod*=10;
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

}