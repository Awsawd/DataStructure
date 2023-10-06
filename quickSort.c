#include <iostream>
using namespace std;

void quickSort(int* a,int low,int high)
{
    if (low >= high) return ;
    int i = low, j = high;
    int temp = a[i];

    while (i<j)
    {
        while (i < j && a[j] >= temp) j--;
        if (i < j) a[i++] = a[j];
        while (i < j && a[i] <= temp) i++;
        if (i < j) a[j--] = a[i];
    }
    a[i] = temp;
    quickSort(a, low, i - 1); 
    quickSort(a, i + 1, high); 

}

int main() {
    int arr[] = {5, 3, 8, 4, 2, 7, 1, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
