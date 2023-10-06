#include <iostream>
using namespace std;

void quickSort(int arr[], int left, int right) {
    if (left >= right) return; // 递归结束条件
    int i = left, j = right, pivot = arr[left]; // 初始化i、j、pivot
    while (i < j) {
        while (i < j && arr[j] >= pivot) j--; // 找到第一个小于pivot的元素
        if (i < j) arr[i++] = arr[j]; // 将小于pivot的元素放到左边
        while (i < j && arr[i] <= pivot) i++; // 找到第一个大于pivot的元素
        if (i < j) arr[j--] = arr[i]; // 将大于pivot的元素放到右边
    }
    arr[i] = pivot; // 将基准元素放到最终位置
    quickSort(arr, left, i - 1); // 对左半部分递归排序
    quickSort(arr, i + 1, right); // 对右半部分递归排序
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
