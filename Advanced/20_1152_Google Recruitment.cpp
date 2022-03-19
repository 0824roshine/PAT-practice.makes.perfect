#include<iostream>
#include<string>
using namespace std;
bool isP(int x) {
    if (x == 1 || (x > 2 && x % 2 == 0))
        return false;
    for (int i = 3; i * i <= x; i += 2) {
        if (x % i == 0) return false;
    }
    return true;
}
int main() {
    int len;
    int k;
    string s;
    cin >> len >> k;
    getline(cin, s);
    int flag = 0;
    for (int i = 0; i <= (len - k); i++) {
        string sp = s.substr(i, k);
        cout << sp;
        int k = stoi(sp);
        if (isP(k)) {
            cout << sp;
            flag = 1;
            break;
        }
    }
    if (flag == 0) cout << "404";
    return 0;
}