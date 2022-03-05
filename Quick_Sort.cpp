/*
 độ phức tạp thuật toán sẽ là O(log(n))

Bước 1: Lấy phần tử chốt là phần tử ở cuối danh sách.

Bước 2: Chia mảng theo phần tử chốt.

Bước 3: Sử dụng sắp xếp nhanh một cách đệ qui với mảng con bên trái.

Bước 4: Sử dụng sắp xếp nhanh một cách đệ qui với mảng con bên phải.

*/
#include<iostream>
using namespace std;
// Hàm để đổi giá trị 
void swap(int &a, int &b){
    int t = a;
        a = b;
        b = t;
}
//Hàm partition để chia LpR
//Với việc chọn pivot là phần tử cuối cùng

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int left = low;
    int right = high - 1;
    /*
    Mảng ban đầu:
              left                   right  pi
               |                       |    |  
               v                       v    v                                                                          
    array : | 10 | 80 | 30 | 90 | 40 | 50 | 70 |
    index :    0    1    2    3   4    5    6
*/
    while(true){
        if(left <= right && arr[left] < pivot) left++;
        if(right >= left && arr[right] > pivot) right--;
        if(left >= right) 
            break;
        else { 
            swap(arr[left], arr[right]);
        }
            left++;
            right--;
    }
    swap(arr[left], arr[high]);
    return left;
}
/*
    Mảng sau lần lặp 1:  (left = 2, right = 4, pivot = 6)
                        left     right   pi/high
                         |         |        |  
                         v         v        v                                                                          
    array : | 10 | 50 | 30 | 90 | 40 | 80 | 70 |
    index :    0    1    2    3    4    5    6

    Mảng sau lần lặp 2:  (left = 4, right = 3, pivot = 6)
                            right left   pi/high
                              |    |        |  
                              v    v        v                                                                          
    array : | 10 | 50 | 30 | 40 | 90 | 80 | 70 |
    index :    0    1    2    3   4    5    6 

    Mảng sau lần lặp 3:  (left = 4, right = 3, pivot = 6)
                            right left   pi/high
                              |    |        |  
                              v    v        v                                                                          
    array : | 10 | 50 | 30 | 40 | 70 | 80 | 90 |
    index :    0    1    2    3   4    5    6 

    sau dó thì trả về left = 70 = pivot(lúc đầu)
*/

// Hàm Sắp xếp 
void quickSort(int arr[], int low, int high){

    if(low < high){
        /* pi là chỉ số nơi phần tử này đã đứng đúng vị trí
         và là phần tử chia mảng làm 2 mảng con trái & phải */
        int pi = partition(arr, low, high);
        // Gọi đệ quy sắp xếp 2 mảng con trái và phải
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