//<비슷한 단어> - 2607
#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<n; i++)
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, cnt = 0;
    cin >> N;
    vector<string> str(N);
    rep(i, 0, N) cin >> str[i];
    rep(i, 0, N) {
        sort(str[i].begin(), str[i].end());
    }

    rep(i, 1, N) {
        if (str[0].compare(str[i]) == 0) cnt++;
        else {
            if (abs((int)str[0].length() - (int)str[i].length()) == 0) {
                int n = 0;
                rep(j, 0, str[0].length()) {
                    if (n > 1) break;
                    int idx = str[i].find(str[0][j]);
                    if (idx != -1) str[i][idx] = '0';
                    else n++;
                }
                if (n <= 1) cnt++;
            }
            else if (abs((int)str[0].length() - (int)str[i].length()) == 1) {
                int n = 0;
                rep(j, 0, str[0].length()) {
                    int idx = str[i].find(str[0][j]);
                    if (idx != -1) str[i][idx] = '0';
                    else n++;
                }
                if (str[0].length() > str[i].length() && n == 1) cnt++;
                else if (str[0].length() < str[i].length() && n == 0) cnt++;
            }
        }
    }
    cout << cnt;
}

/*
<비슷한 단어> - 2607

input(1) : 
4
DOG
GOD
GOOD
DOLL

ouput(1) : 
2
--------------

input(2) : 
ABB
AAA

output(2) : 
0

*/