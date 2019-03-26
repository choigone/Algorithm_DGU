//TODO compare and move count 수정하기
//TODO 알고리즘 이해하기

#include <iostream>
#include <time.h>
#include <algorithm>
#include <vector>

typedef int itemType;

using namespace std;

int* shellSort(itemType a[],int n){
    int i,j,h; itemType v;
    int *cnt = new int[2];
    cnt[0] = 0;
    cnt[1] = 0;
    h = 1;
    do {h = 3*h+1;
    } while (h < n );
    do{
        h = h/3;
        for(i=h;i<n;i++){
            v = a[i]; j = i;
            while(1){
                if(a[j-h] > v){
                    cnt[0]++;
                    a[j] = a[j-h]; j-=h;
                    cnt[1]++;
                    if(j<=h-1) break;
                }
                else{
                    cnt[0]++;
                    break;
                }
            }
            a[j] = v;
            cnt[1]++;
        }
    } while(h>1);

    for(int i=0; i<20;i++){
        cout << a[i];
    }
    cout<<endl;
    return cnt;
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

    printf("SortedData_A : ");
    cntA = shellSort(a,size);
    printf("SortedData_B : ");
    cntB = shellSort(b,size);
    printf("Compare_Cnt_A : %d, DataMove_Cnt_A : %d\n",cntA[0],cntA[1]);
    printf("Compare_Cnt_B : %d, DataMove_Cnt_B : %d\n",cntB[0],cntB[1]);

    return 0;
}