#include <iostream>
#include <vector>

#define MAX 20
typedef int itemType;
using namespace std;

int CountSort(itemType *a, itemType *b, itemType *N, int n, int k){
    int i,j;
    int moveCnt=0;
    // 빈도수??? 0으로 초기화
    // 초기화 하는 것도 무브야???????
    for(i=0; i<k; i++){
        N[i]=0;
    }
    // N배열에 빈도 값 넣어줌
    for(i=0; i<n; i++){
        N[a[i]-1]++;
    }
    // N배열 누적해서 더하기
    for(i=1; i<k; i++){
        N[i] = N[i] + N[i-1];
    }
    for(j=n-1; j>=0; j--) {
        b[N[a[j]-1]-1] = a[j];
        moveCnt++;
        //N의 값 줄여주는 것도 무브야........?
        N[a[j]-1]--;
    }
    for(int i=0;i<MAX;i++) cout << b[i] << " ";
    cout << endl;

    return moveCnt;
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
    for(int i=0;i<size;i++) c[i] = v[i].first;
    sort(v.begin(), v.end());
    for(int i=0;i<size;i++){
        a[i] = size - i;
        b[i] = v[i].second;
    }
    //범위도 1부터 size까지므로 가
    itemType *B = new itemType[size];
    itemType *N = new itemType[size];

    int count[3];
    cout << "SortedData_A : ";
    count[0] = CountSort(a,B,N,size,size);
    cout << "SortedData_B : ";
    count[1] = CountSort(b,B,N,size,size);
    cout << "SortedData_C : ";
    count[2] = CountSort(c,B,N,size,size);

    cout << "Compare_Cnt_A : 0" << ", DataMove_Cnt_A : " << count[0] << endl;
    cout << "Compare_Cnt_B : 0" << ", DataMove_Cnt_B : " << count[1] << endl;
    cout << "Compare_Cnt_C : 0" << ", DataMove_Cnt_C : " << count[2] << endl;

    return 0;
}