#include <bits/stdc++.h>

using namespace std;

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

// Hàm MergeSort đệ quy
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;  // Tính điểm giữa

        // Sắp xếp đệ quy hai nửa
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Trộn hai nửa đã sắp xếp
        merge(arr, left, mid, right);
    }
}

int main() {
    vector<int> arr = {3, 2, 5, 1, 0, 4};
    mergeSort(arr, 0, arr.size() - 1);
    for(int i : arr) cout << i << ' ';
}