#include <bits/stdc++.h>

using namespace std;

// Hàm sắp xếp nửa đầu mảng
void insertionSort(int arr[], int left, int right) {
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

void heapify(int a[], int left, int right) {
	int save = a[left];
	while (left <= right / 2) {
		int k = 2 * left;
		while (k < right && a[k] < a[k + 1]) k++;
		if (save >= a[k])
			break;
		a[left] = a[k];
		left = k;
	}
	a[left] = save;
}

// Hàm sắp xếp đoạn lớn hơn 16 phần tử bằng Heap Sort
void heapSort(int arr[], int left, int right) {
    for (int i = (right - 1) / 2; i >= left; --i) 
        heapify(arr, i, right - 1);
    for (int i = right - 1; i > left; --i) {
        swap(arr[i], arr[left]);
        heapify(arr, left, i - 1);
    }
}

// Hàm phân vùng cho Quick Sort
int partition(int arr[], int low, int high) {
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
// Hàm Quick Sort với cơ chế tránh trường hợp xấu nhất
void introSort(int arr[], int left, int right) {
    int maxDepth = 2 * log(right - left);
    
    // Sắp xếp nửa đầu mảng bằng Insertion Sort
    insertionSort(arr, left, min(left + 15, right));
    
    // Sử dụng Insertion Sort nếu đoạn nhỏ
    if (right - left <= 16) {
        insertionSort(arr, left, right);
        return;
    }
    
    // Sử dụng Heap Sort nếu đoạn vừa
    if (right - left > 16 && right - left <= 2 * 32) {
        heapSort(arr, left, right);
        return;
    }
    
    // Sử dụng Quick Sort với cơ chế tránh trường hợp xấu nhất
    if (maxDepth == 0) {
        heapSort(arr, left, right);
    } else {
        int pivot = partition(arr, left, right);
        introSort(arr, left, pivot);
        introSort(arr, pivot + 1, right);
    }
}
int main() {
    int arr[] = {3, 2, 5, 1, 0, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    introSort(arr, 0, n - 1);
    for(int i : arr) cout << i << ' ';
}