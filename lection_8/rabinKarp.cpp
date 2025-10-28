#include <iostream>
using namespace std;

vector<int> rabinKarp(string text, string pattern) {
    int n = text.size();
    int m = pattern.size();

    vector<int> res;

    if (m == 0 || m > n) return res;

    const long long BASE = 256;
    const long long MOD = 101;

    long long powBase = 1;
    for (int i = 1; i <= m - 1; ++i) {
        powBase = (powBase * BASE) % MOD;
    }

    long long hashP = 0; // pattern hash
    long long hashT = 0; // text window hash
    for (int i = 0; i < m; ++i) {
        hashP = (hashP * BASE + (unsigned char)pattern[i]) % MOD;
        hashT = (hashT * BASE + (unsigned char)text[i]) % MOD;
    }

    for (int i = 0; i <= n - m; ++i) {
        if (hashP == hashT) {
            bool equal = true;
            for (int j = 0; j < m; ++j) {
                if (text[i + j] != pattern[j]) { equal = false; break; }
            }
            if (equal) res.push_back(i);
        }

        if (i < n - m) {
            long long outgoing = (unsigned char)text[i];
            long long incoming = (unsigned char)text[i + m];

            long long withoutLeading = (hashT - (outgoing * powBase) % MOD);
            if (withoutLeading < 0) withoutLeading += MOD;

            hashT = (withoutLeading * BASE + incoming) % MOD;
        }
    }
    return res;
}

int main() {
    string text = "abracadabra";
    string pattern = "abra";

    vector<int> matches = rabinKarp(text, pattern);
    for (int idx : matches) {
        cout << "Match at index " << idx << "\n";
    }
    return 0;
}