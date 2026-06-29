#include <iostream>
using namespace std;

int mySum(int* arr, int n) {
    int sum = 0;
    for (int i = 1; i < n - 1; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int nums[100];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    int *arr = nums;
    cout << mySum(arr, n) << endl;
    return 0;
}