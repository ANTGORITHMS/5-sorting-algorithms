#include <bits/stdc++.h>

using namespace std;

// Hàm phân vùng (partition)
int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[high]; // Chọn phần tử cuối cùng làm pivot
    int i = low - 1;       // Chı̉ số của phần tử nhỏ nhất
    for (int j = low; j < high; j++) {
        // Nếu phần tử hiện tại nhỏ hơn pivot
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]); // Hoán đổi arr[i] và arr[j]
        }
    }
    swap(arr[i + 1], arr[high]); // Đưa chốt về đúng vị trí của nó
    return i + 1;                // Trả về vị trí của pivot
}
// Hàm QuickSort đệ quy
void quick_sort(vector<int> &arr, int low, int high) {
    if (low < high) {
        // Phân vùng dữ liệu
        int pivotIndex = partition(arr, low, high);
        // Sắp xếp đệ quy các phần dữ liệu bên trái và bên phải pivot
        quick_sort(arr, low, pivotIndex - 1);
        quick_sort(arr, pivotIndex + 1, high);
    }
}

int main() {
    vector<int> arr = {3, 2, 5, 1, 0, 4};
    quick_sort(arr, 0, arr.size() - 1);
    for(int i : arr) cout << i << ' ';
}