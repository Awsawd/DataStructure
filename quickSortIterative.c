#include <iostream>
using namespace std;

void quickSortIterative(int arr[], int left, int right) {
    int stack[right - left + 1]; // 栈用于存储待排序区间的左右边界
    int top = -1; // 栈顶指针
    stack[++top] = left; // 将左边界入栈
    stack[++top] = right; // 将右边界入栈
    while (top >= 0) { // 当栈不为空时循环
        int i = stack[top--], j = stack[top--]; // 取出当前待排序区间的左右边界
        int pivot = arr[i]; // 将基准元素设为当前待排序区间的第一个元素
        int temp;
        while (i <= j) { // 将小于等于基准元素的数移到左边，大于基准元素的数移到右边
            while (arr[++i] < pivot); // 找到第一个大于基准元素的位置
            while (arr[--j] > pivot); // 找到第一个小于等于基准元素的位置
            if (i < j) { // 如果左边还有元素，则交换这两个元素
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        if (i < j) { // 如果左边还有元素，则将它们依次放到已排序部分的末尾
            stack[++top] = j + 1;
            stack[++top] = i;
        } else { // 如果左边没有元素，则将基准元素放到已排序部分的末尾
            stack[++top] = j + 1;
        }
    }
}

int main() {
    int arr[] = {5, 3, 8, 4, 2, 7, 1, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSortIterative(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
