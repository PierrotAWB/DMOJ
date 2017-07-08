#include <iostream>
#include <math.h>
#include <map>

using namespace std;

map<int, long long> m = {{1, 1}};

long long fact(long long k) {
    if (m.find(k) == m.end()) {
        m[k] = k * fact(k - 1);
        return k * fact(k - 1);
    }
    return m[k];
}

int main()
{
    int N;
    cin >> N;

    for (int i = 0; i < N; i++){
        long long k;
        cin >> k;
        cout << remainder(fact(k), pow(2, 32))<< "\n";
    }
    return 0;
}
