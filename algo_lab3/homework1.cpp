//TODO 상수정의하기 20

#include <iostream>
#include <time.h>
#include <algorithm>
#include <vector>

typedef int itemType;

using namespace std;

int* insertion(itemType a[], int n){
    int i,j; itemType v;
    int *cnt = new int[2];
    cnt[0] = 0;
    cnt[1] = 0;
    a[-1] = 0;
    for(i = 1 ; i < n; i++){
        v = a[i]; j=i;
        //TODO 데이터를 빼는 것도 이동인가?
        cnt[1]++;
        while(1){
            if(a[j-1] > v){
                cnt[0]++;
                a[j] = a[j-1];
                j--;
                cnt[1]++;
            }
            else{
                cnt[0]++;
                // TODO cnt[1]--;
                break;
            }
        }
        a[j] = v;
        cnt[1]++;
    }
    for(int i=0;i<20;i++){
        cout<<a[i]<<" ";
    }
    cout << endl;
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
    cntA = insertion(a,size);
    printf("SortedData_B : ");
    cntB = insertion(b,size);
    printf("Compare_Cnt_A : %d, DataMove_Cnt_A : %d\n",cntA[0],cntA[1]);
    printf("Compare_Cnt_B : %d, DataMove_Cnt_B : %d\n",cntB[0],cntB[1]);

    return 0;
}