#include <iostream>
#include <iomanip>
using namespace std;

const int SIZE = 6;

int calcAverage(int img[SIZE][SIZE]) {
    int sum = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            sum += img[i][j];
        }
    }
    return sum / (SIZE * SIZE);
}

void binarize(int img[SIZE][SIZE], int average) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (img[i][j] > average) {
                img[i][j] = 255;
            }
            else {
                img[i][j] = 0;
            }
        }
    }
}

int main() {
    int img[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cin >> img[i][j];
        }
    }
    int average = calcAverage(img); // 计算均值
    cout << average << endl;
    binarize(img, average); // 二值化
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << setw(3) << img[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}