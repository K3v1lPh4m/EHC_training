#include<iostream>
using namespace std;
// Hàm để đổi giá trị 
void swap(int &a, int &b){
    a = a + b;
    b = a - b;
    a = a - b;
}
//Hàm để chia LpR
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int left = low;
    int right = high - 1;
    while(true){
        while(left <= right && arr[left] < pivot) left++;
        while(right >= left && arr[right] > pivot) right--;
        if(left >= right) break;
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
    swap(arr[left], arr[high]);
    return left;
}
// Hàm Sắp xếp 
int quickSort(int arr[], int low, int high){

    if(low < high){

        int pi = partition(arr, low, high);

        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}
// Hàm in ra mảng 
void printArray(int arr[], int size){
    int i;
    for(i=0; i < size; i++){
        cout<<arr[i]<<" ";
    }
}

int main()
{
    int arr[] = {10, 80, 30, 90, 40, 50, 70};
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0, n-1);
    cout<<"Sorted array:"<<endl;
    printArray(arr, n);
    return 0;
}