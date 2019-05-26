#include <iostream>
#include <string>
#include <sstream>
#include <map>
using namespace std;

map<string, int> memo;

int mochila_rec(const string& number, int i, int peso_restante) {
    // retorna el maximo valor, con el limite de peso
    if (peso_restante <= 0) {
        return 0;
    }
    if (i < 0) {
        return 0;
    }
    stringstream ss;
    ss << number.substr(0, i + 1) << ":" << peso_restante;
    // cout << ss.str() << endl;
    if (memo.count(ss.str())) {
        return memo[ss.str()];
    }
    // if (memo.size() % 1000 == 0) {
    //     cout << "memo size: " << memo.size() << endl;
    // }
    int digit = number[i] - '0';
    int a = mochila_rec(number, i-1, peso_restante);
    int ret = a;
    if (digit <= peso_restante) {
        int b = mochila_rec(number, i-1, peso_restante - digit) + digit;
        ret = max(a, b);
    }
    memo[ss.str()] = ret;
    return ret;
}

int mc(int i) {
    stringstream ss;
    ss << i;
    string number = ss.str();
    int sum = 0;
    for (int i = 0; i < number.size(); ++i) {
        sum += number[i] - '0';
    }
    int ret = mochila_rec(number, number.size() - 1, sum/2);
    // cout << "@@" << ret << endl;
    return sum - 2*ret;
}

// int main() {
//     cout << mc(12345) << endl;
//     return 0;
// }

int main() {
    int test_cases;
    cin >> test_cases;
    while (test_cases--) {
        int l, r, k;
        cin >> l >> r >> k;
        int count = 0;
        for (int i = l; i <= r; ++i) {
            // cout << "#" << mc(i) << endl;
            if (mc(i) <= k) {
                count++;
            } else {
                // cout << "error  k " << k << " " << i << endl;
            }
        }
        cout << count << endl;
    }
    return 0;
}
