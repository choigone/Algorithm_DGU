#include <iostream>
#include <time.h>
#include <algorithm>
#include <vector>

typedef int itemType;

using namespace std;

int* Bubble(int sorted, itemType *a){
    int temp;
    int *result = new int[3];
    result[0] = sorted;
    result[1] = 0;
    result[2] = 0;
    if(*(a-1)>*a){
        result[1]++;
        // TODO 데이터 빼는 것도 이동인가요?
        temp = *(a-1);
        *(a-1) = *a;
        result[2]++;
        *a = temp;
        result[2]++;
        sorted = false;
    }
    result[0] = sorted;

    return result;
}

int* bubbleSort(itemType a[],int n){
    int i, Sorted;
    int *result = new int[3];
    int *cnt = new int[2];
    cnt[0]=0;
    cnt[1]=0;
    Sorted = false;
    while(!Sorted){
        Sorted = true;
        for(i =1;i<n;i++){
            result = Bubble(Sorted, &a[i]);
            Sorted = result[0];
            cnt[0] += result[1];
            cnt[1] += result[2];
        }
    }
    for(int i=0;i<20;i++){
        cout<<a[i];
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
    for(int i=0;i<size;i++) {
        a[i] = size - i;
        b[i] = v[i].second;
    }
    printf("SortedData_A : ");
    cntA = bubbleSort(a,size);
    printf("SortedData_B : ");
    cntB = bubbleSort(b,size);
    printf("Compare_Cnt_A : %d, DataMove_Cnt_A : %d\n",cntA[0],cntA[1]);
    printf("Compare_Cnt_B : %d, DataMove_Cnt_B : %d\n",cntB[0],cntB[1]);

    return 0;
}