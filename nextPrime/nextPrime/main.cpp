//
//  main.cpp
//  nextPrime
//
//  Created by Andrew Wang on 2017-07-04.
//  Copyright © 2017 Andrew Wang. All rights reserved.
//

#include <iostream>
#include <bitset>
#include <vector>
#include <cmath>
using namespace std;

bitset<10000> candidate;
vector<int> prime;

void initPrime() {
	candidate[0] = candidate[1] = 0;
	
	for (int i = 2; i < candidate.size(); i++) {
		candidate[i] = candidate[i]|1;
	}
	
	for (int i = 2; i < candidate.size(); i++) {
		if (candidate[i]){
			for (int j = 2; j <= candidate.size() / i; j++) {
				candidate[i * j] = candidate[i * j] & 0;
			}
		}
	}
	
	// these primes will never need to divide the candidates
	candidate[2] = candidate[5] = 0;
	
	for (int i = 0; i < candidate.size(); i++) {
		if (candidate[i]) prime.push_back(i);
	}
}

int main(int argc, const char * argv[]) {
	
	initPrime();
	
	int Q;
	cin >> Q;
	
	for (int i = 0; i < Q; i++) {
		int lastDig;
		long long N;
		cin >> N;
		
		lastDig = (N) % 10;
		
		if (lastDig % 2 == 0) {
			if (lastDig != 4) {
				N += 1; // start at {1, 3, 7, 9}
				lastDig += 1;
			} else if (N != 4){
				N += 3; // start at 7
				lastDig += 3;
			} else {
				N += 1; // if the number is 4, return 5.
				lastDig += 1;
			}
		} else {
			if (lastDig != 3) {
				N += 2;
				lastDig += 2; // start at next valid odd number
			} else {
				N += 4;
				lastDig += 4;
			}
		}
		
		bool foundPrime = false;
		while (!foundPrime) {
			for (int j = 0; j < prime.size(); j++) {
				if (N % prime[j] == 0) {
					if (N / prime[j] != 1) goto increment; // not a prime; skip to next contender
				}
			}
			
			for (int j = 10001; j <= pow(N, 0.5); j+= 2) {
				if (N % j == 0) {
					goto increment; // not a prime; skip to next contender
				}
			}
		
			// if it has not skipped to the increment label, it is prime
			foundPrime = true;
			goto finish;
			
		increment:
			// increment to search possible primes
			if (lastDig == 3) {
				N += 4;
				lastDig += 4;
			} else if (lastDig == 9) {
				N += 2;
				lastDig -= 8;
			} else {
				N += 2;
				lastDig += 2;
			}
		finish:
			continue;
		}
		cout << N << endl;
	}
	return 0;
}
