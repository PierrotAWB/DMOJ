#include <iostream>
#include <math.h>

using namespace std;
typedef long long ll;

bool isPrime(ll k) {
    if (k == 1) {
        return false;
    } else if (k == 2 || k == 3){
        return true;
    }

    if (k % 2 == 0){
        return false;
    }

    for (int i = 3; i < (ll) pow(k, 0.5) + 1; i+=2) {
        if (k % i == 0){ // not prime; immediately reject
            return false;
        }
    }
    return true;
}

int main(){
     N;
    cin >> N;

    bool found = false;
    while (!found) {
        if (isPrime(N) == true) {
            found = true;
        } else {
            N++;
        }
    }
    cout << N;
    return 0;
}
