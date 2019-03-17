#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>
#define MAX 50;
using namespace std;

vector<int> intersectionset(vector<int> a, vector<int> b);
vector<int> unionset(vector<int> a, vector<int> b);
void displaySet(vector<int> set);


int main()
{
    int size1, size2;
    cout << "두 개의 자연수를 입력하세요 : ";
    cin >> size1 >> size2;

    srand((unsigned int)time(0));

    vector<int> A(size1);
    for(int i = 0 ; i < size1 ; i++)
    { A[i] = rand()%MAX; }

    vector<int> B(size2);
    for(int i = 0 ; i < size2 ; i++)
    { B[i] = rand()%MAX; }

    sort(A.begin(),A.end());
    sort(B.begin(),B.end());

    A.erase(unique(A.begin(),A.end()),A.end());
    B.erase(unique(B.begin(),B.end()),B.end());

    int random;
    while (A.size() != size1 || B.size() != size2){
        for(int i = 0; i < size1 - A.size(); i++){
            random = rand()%MAX;
            A.push_back(random);
        }
        for(int i = 0; i < size2 - B.size(); i++){
            random = rand()%MAX;
            B.push_back(random);
        }

        sort(A.begin(),A.end());
        sort(B.begin(),B.end());

        A.erase(unique(A.begin(),A.end()),A.end());
        B.erase(unique(B.begin(),B.end()),B.end());
    }

    vector<int> union_set;
    vector<int> intersection_set;
    //A집합의 크기가 작거나 같은 경우
    if(size1 <= size2)
    {
        union_set = unionset(A,B);
        intersection_set = intersectionset(A,B);
    }
    //B집합의 크기가 작은 경우
    else{
        union_set = unionset(B,A);
        intersection_set = intersectionset(B,A);
    }


    sort(union_set.begin(), union_set.end());
    sort(intersection_set.begin(), intersection_set.end());

    cout << "집합A - ";
    displaySet(A);
    cout << "\n집합B - ";
    displaySet(B);
    cout << "\n합집합 - ";
    displaySet(union_set);
    cout << "\n교집합 - ";
    displaySet(intersection_set);

    return 0;
}

// 집합을 출력하는 함수
void displaySet(vector<int> set)
{
    for(int i=0; i<set.size();i++)
    {
        cout << set.at(i);
        if(i != set.size()-1)
        {
            cout << ", ";
        }
    }
}

// 매개변수 a, b 의 교집합을 벡터로 반환하는 함수
vector<int> intersectionset(vector<int> a, vector<int> b)
{
    int size1 = a.size();
    int size2 = b.size();

    vector<int> v;

    for(int i = 0 ; i < size1 ; i++)
    {
        for(int j = 0 ; j < size2 ; j++)
        {
            if(a[i] == b[j])
            {
                v.push_back(a[i]);
                break;
            }
        }
    }
    return v;
}

// a, b의 합집합을 배열로 반환하는 함수
vector<int> unionset(vector<int> a, vector<int> b) {
    vector<int> v = intersectionset(a, b);
    vector<int> result;

    int size1;
    int size2 = b.size();
    int size3 = v.size();

    for (int i = 0; i < size3; i++) {
        for (int j = 0; j < a.size(); j++) {
            if (v[i] == a[j]) {
                a.erase(a.begin() + j);
                break;
            }
        }
    }
    size1 = a.size();
    for (int i = 0; i < size1; i++) {
        result.push_back(a[i]);
    }
    for (int i = 0; i < size2; i++) {
        result.push_back(b[i]);
    }
    return result;
}

