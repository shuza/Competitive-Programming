#include <iostream>
#include <cstdio>
using namespace std;

int a[100];

void mergeFuntion(int low, int mid, int high){
    int temp[100];
    int i = low;
    int j = mid+1;
    int k = 0;
    while(i <= mid && j <= high){
        if(a[i] < a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }
    while(i <= mid)
        temp[k++] = a[i++];
    while(j <= high)
        temp[k++] = a[j++];
    for(i = 0; i < k; i++)
        a[low+i] = temp[i];
}

void mergeSort(int low, int high){
    if(low < high){
        int mid = (low + high) / 2;
        mergeSort(low, mid);
        mergeSort(mid+1, high);
        mergeFuntion(low, mid, high);
    }
}

int main()
{
    int n;
    cout << "Enter the number of element: ";
    cin >> n;
    cout << "Enter " << n << "numbers: ";
    for(int i = 0; i < n; i++)
        cin >> a[i];
    mergeSort(0, n-1);
    cout << "sorted array: ";
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}
