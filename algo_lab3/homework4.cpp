#include<iostream>

typedef int itemType;

using namespace std;

int insertionSort(int a[],int n){
    int count = 0;
    int i,j; itemType v;
    a[-1] = 0;
    for(i=1;i<n;i++){
        v = a[i];
        count += v;
        j=i;
        while(a[j-1] > v) {
            a[j] = a[j-1];
            count+=a[j];
            j--;
        }
        a[j] = v;
        count+=v;
    }
    return count;
}

int* Bubble(int sorted, itemType *a){
    int *result = new int[2];
    int count = 0;
    int temp;
    if(*(a-1)>*a){
        temp = *a;
        count += temp;
        *a = *(a-1);
        count += *a;
        *(a-1) = temp;
        count += temp;
        sorted = false;
    }
    result[0] = sorted;
    result[1] = count;
    return result;
}

int bubbleSort(itemType a[],int n){
    int *result = new int[2];
    int count = 0;
    int i, Sorted;
    Sorted = false;
    while(!Sorted){
        Sorted = true;
        for(i =1;i<n;i++){
            result = Bubble(Sorted, &a[i]);
            Sorted = result[0];
            count += result[1];
        }
    }
    return count;
}

int shellSort(itemType a[],int n){
    int count=0;
    int i,j,h; itemType v;
    h = 1;
    do {h = 3*h+1;
    } while (h < n );
    do{
        h = h/3;
        for(i=h;i<n;i++){
            v = a[i]; j = i;
            while(a[j-h] > v){
                count+=v;
                a[j] = a[j-h];
                count+=a[j];
                j-=h;
                if(j<=h-1) break;
            }
            a[j] = v;
            count+=v;
        }
    } while(h>1);

    return count;
}

int main(){
    int size;
    int insertion, bubble, shell;
    scanf("%d",&size);
    int *a = new int[size];
    for(int i=0;i<size;i++){
        a[i] = size - i;
    }
    insertion = insertionSort(a,size);
    printf("Insertion Sort : %d\n",insertion);
    for(int i=0;i<size;i++){
        a[i] = size - i;
    }
    bubble = bubbleSort(a,size);
    printf("Bubble Sort : %d\n",bubble);
    for(int i=0;i<size;i++){
        a[i] = size - i;
    }
    shell = shellSort(a,size);
    printf("Shell Sort : %d\n",shell);
}