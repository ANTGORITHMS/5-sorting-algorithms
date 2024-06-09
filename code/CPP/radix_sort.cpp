#include <bits/stdc++.h>

using namespace std;

void radixSort(vector<int>& a) {
    int maxNumber = *max_element(a.begin(), a.end()); 
    int exp = 1; // Khởi tạo giá trị exp = 1 (để bắt đầu từ chữ số đơn vị)
    vector<int> res(a.size()); 
    int n = a.size(); 

    while (maxNumber / exp > 0) { // Lặp lại cho đến khi xử lý hết các chữ số
        vector<int> dem(10, 0); 
        // Đếm số lượng số có chữ số tương ứng
        for (int i = 0; i < n; i++) dem[(a[i] / exp) % 10]++; 
        for (int i = 1; i < 10; i++) dem[i] += dem[i - 1]; 

        for (int i = n - 1; i >= 0; i--) {
            res[dem[(a[i] / exp) % 10] - 1] = a[i]; 
            dem[(a[i] / exp) % 10]--; 
        }

        for (int i = 0; i < n; i++) a[i] = res[i];
        exp *= 10; 
    }
}

int main() {
    vector<int> arr = {3, 2, 5, 1, 0, 4};
    radixSort(arr);
    for(int i : arr) cout << i << ' ';
}