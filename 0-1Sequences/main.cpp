#include <iostream>
using namespace std;


long long calc(string str) {
    long long seen1 = 0;
    long long branch = 1;
    long long res = 0;
    for(char& c: str) {
        switch(c) {
            case '?':
                res = (2 * res + seen1) % 1000000007;
                seen1 = (2 * seen1 + branch) % 1000000007;
                branch = (2 * branch )% 1000000007;
                break;
            case '1':
                seen1 = (seen1 + branch) % 1000000007;
                break;
            case '0':
                res = (res + seen1) % 1000000007;
                break;
            default:
                break;
        }
    }
    return res;
}
int main() {
    string a;
    cin >> a;
    cout << calc(a) << endl;
    return 0;
}
