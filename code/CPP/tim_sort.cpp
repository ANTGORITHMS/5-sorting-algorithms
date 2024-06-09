#include <bits/stdc++.h>

using namespace std;

// Chọn giá trị RUN
const int RUN = 32;

// Hàm sắp xếp bằng InsertionSort
void insertionSort(vector<int>& arr, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int temp = arr[i];
        int j = i - 1;

        while (j >= left && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = temp;
    }
}

// Hàm trộn hai mảng con đã sắp xếp
void merge(vector<int>& arr, int left, int mid, int right) {
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    // Tạo hai mảng tạm để lưu trữ các nửa
    vector<int> leftArr(leftSize);
    vector<int> rightArr(rightSize);

    // Sao chép dữ liệu vào hai mảng tạm
    for (int i = 0; i < leftSize; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < rightSize; j++)
        rightArr[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;  // Các chỉ số của mảng con và mảng đầu vào

    // Trộn hai mảng con vào mảng đầu vào
    while (i < leftSize && j < rightSize) {
        if (leftArr[i] <= rightArr[j])
            arr[k++] = leftArr[i++];
        else
            arr[k++] = rightArr[j++];
    }

    // Sao chép các phần tử còn lại của mảng con (nếu có)
    while (i < leftSize)
        arr[k++] = leftArr[i++];
    while (j < rightSize)
        arr[k++] = rightArr[j++];
}

// Hàm TimSort
void timSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; i += RUN)
        insertionSort(arr, i, min((i + RUN - 1), (n - 1)));

    for (int size = RUN; size < n; size = 2 * size) {
        for (int left = 0; left < n; left += 2 * size) {
            int mid = left + size - 1;
            int right = min((left + 2 * size - 1), (n - 1));

            if (mid < right)
                merge(arr, left, mid, right);
        }
    }
}
int main() {
    vector<int> arr = {3, 2, 5, 1, 0, 4};
    timSort(arr);
    for(int i : arr) cout << i << ' ';
}