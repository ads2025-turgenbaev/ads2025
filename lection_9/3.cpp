#include <iostream>

using namespace std;

vector<int> naiveStringMatching(string pattern, string text) {
    int n = text.length();
    int m = pattern.length();

    vector<int> res;

    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }

        if (j == m) {
            res.push_back(i);
        }
    }

    return res;
}


vector<int> prefix_f(string s) { //
    int n = s.size();

    vector<int> pi(n, 0);

    for (int i = 0; i < n; i++) {
        for (int k = 0; k <= i; k++) {
            if (s.substr(0, k) == s.substr(i - k + 1, k)) {
                pi[i] = k;
            }
        }
    }

    return pi;
}

vector<int> prefix_f2(string s) {
    int n = s.size();

    vector<int> pi(n, 0);

    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];

        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }

        if (s[i] == s[j]) {
            j++;
        }

        pi[i] = j;
    }


    return pi;
}

vector<int> KMP(string pattern, string text) {
    int n = text.length();
    int m = pattern.length();

    vector<int> pi = prefix_f2(pattern);
    vector<int> res;

    int i = 0;
    int j = 0;

    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {
            res.push_back(i - j);
            j = pi[j - 1];
        }
        else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = pi[j - 1];
            }
            else {
                i++;
            }
        }
    }

    return res;
}


int main() {
    string text = "ababab";
    string pattern = "ab";

    vector<int> res = KMP(pattern, text);

    for (auto c : res) {
        cout << c << " ";
    }

    // string s = "abab";//p[i] = {0012}

    // for (auto r : prefix_f(s)) {
    //     cout << r << " ";
    // }
    return 0;
}