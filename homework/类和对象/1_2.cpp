#include <iostream>
using namespace std;

int main() {
    int year, month, day;
    cin >> year >> month >> day;

    // 每个月的天数，注意 0 号占位，方便后续计算
    int MonthDay[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int sum = 0;

    // 计算从 1 月 1 日到输入日期的天数
    for (int i = 1; i < month; i++) {
        sum += MonthDay[i];
    }
    sum += day;

    // 如果是闰年，并且月份大于 2 月，则需要加一天
    if (month > 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) {
        sum++;
    }

    cout << sum << endl;

    return 0;
}