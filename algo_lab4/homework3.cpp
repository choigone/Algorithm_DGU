#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;


inline void swap(vector<pair<string,int>> &a, int i, int j){
    pair<string,int> t = a[i]; a[i] = a[j]; a[j] = t;
}

int partition(vector<pair<string,int>> &a, int l, int r){
    int i,j; pair<string,int> v;
    if(r > l){
        v = a[l]; i = l; j = r +1;
        for (;;) {
            while (a[++i].second < v.second) ;
            while (a[--j].second > v.second) ;
            if (i >= j) break;
            swap(a, i, j);
        }
        swap(a,j,l);
    }
    return j;
}

void quicksort(vector<pair<string,int>> &a, int l, int r){
    int j;
    if(r>l){
        j = partition(a,l,r);
        quicksort(a,l,j-1);
        quicksort(a,j+1,r);
    }
}

//insertion sort
void stringSort(vector<pair<string,int>> &a, int first, int n){
    pair<string,int> temp;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[i+first].first.compare(a[j+first].first) < 0 ){
                temp = a[i+first];
                a[i+first] = a[j+first];
                a[j+first] = temp;
            }
        }
    }
}

vector<string> &StrSplit( string inStr, string sepStr, vector<string> &outStrVec) {
    char * comp;
    char * buffer = new char[ strlen( inStr.c_str() ) ];
    strcpy( buffer, inStr.c_str() );
    comp = strtok ( buffer, sepStr.c_str() );
    while ( comp != NULL ) {
        outStrVec.push_back(comp);
        comp = strtok ( NULL, sepStr.c_str() );
    }
    delete[]  comp;
    delete[]  buffer;
    return outStrVec;
}

vector<string> StrSplit( string inStr, string sepStr ) {
    vector<string> outStrVec;
    return StrSplit( inStr, sepStr, outStrVec );
}

int main(){
    vector<string> str;
    ifstream openfile("/Users/gounchoi/Desktop/동대생최고운/3학년1학기/컴퓨터알고리즘과실습/Algorithm_DGU/algo_lab4/datafile.txt");
    if(!openfile.is_open()){
        cout<<"file open error";
        exit(1);
    }

    int i = 0, j = 0;
    string temp;
    while(!openfile.eof()){
        getline(openfile,temp);
        if(temp!="") str.push_back(temp);
    }

    vector<vector<string>> result;
    //모든 특수문자 처리
    string del = "";
    for(int i=32;i<=47;i++) del+=i;
    for(int i=58;i<=64;i++) del+=i;
    for(int i=91;i<=96;i++) del+=i;
    for(int i=123;i<=126;i++) del+=i;
    for(int i=0;i<str.size();i++){
        vector<string> temp;
        temp = StrSplit(str[i],del);
        result.push_back(temp);
    }

    vector<string> finalStr;
    vector<int> finalCnt;
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            if(finalStr.size()==0){
                finalStr.push_back(result[i][j]);
                finalCnt.push_back(0);
            }
            else{
                vector<string>::iterator it = find(finalStr.begin(),finalStr.end(),result[i][j]);
                if(it == finalStr.end()){
                    finalStr.push_back(result[i][j]);
                    finalCnt.push_back(0);
                }
                else{
                    auto index = distance(finalStr.begin(),it);
                    finalCnt[index]++;
                }
            }
        }
    }

    vector<pair<string,int>> final;
    for(int i=0;i<finalStr.size();i++){
        final.push_back(make_pair(finalStr[i],finalCnt[i]));
    }
    quicksort(final,0,final.size()-1);

    int k = 0;
    int compare = final[0].second;
    int first = 0;
    int count= 0;
    while(k <= final.size()-1){
        count++;
        if(final[k].second != compare){
            stringSort(final,first,count-1);
            first = k;
            count = 1;
            compare = final[k].second;
        }
        k++;
    }

    for(int i=final.size()-1;i>=0;i--){
        cout << final[i].first << " : " << final[i].second+1 << endl;
    }
}