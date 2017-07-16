//
//  main.cpp
//  CCC96S3
//
//  Created by Andrew Wang on 2017-07-16.
//  Copyright © 2017 Andrew Wang. All rights reserved.
//

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
using namespace std;

vector<string> DP[31][9];

//if (N == 1) {
//	if (K == 1) {
//		bitPatterns.push_back("1");
//	} else if (K == 0) {
//		bitPatterns.push_back("0");
//	}
//	return bitPatterns;
//} else

vector<string> createBitPatterns(int N, int K) {
	vector<string> bitPatterns;
	
	if (K > N) return bitPatterns; // Do not continue down this path.
	
	if (!DP[N][K].empty()) {
		return DP[N][K];
	}
	
	if (N == 1) {
		if (K == 1) {
			bitPatterns.push_back("1");
		} else if (K == 0) {
			bitPatterns.push_back("0");
		}
		return bitPatterns;
	} 

	vector<string> beginWith1;
	vector<string> beginWith0;
	
	beginWith1 = createBitPatterns(N - 1, K - 1) = DP[N - 1][K - 1];
	beginWith0 = createBitPatterns(N - 1, K) = DP[N - 1][K];
	
	for (int i = 0; i < beginWith1.size(); i++) {
		bitPatterns.push_back("1" + beginWith1[i]);
	}
	
	for (int i = 0; i < beginWith0.size(); i++) {
		bitPatterns.push_back("0" + beginWith0[i]);
	}
	
	DP[N][K] = bitPatterns;
	return bitPatterns;
}

int main(int argc, const char * argv[]) {
	ios::sync_with_stdio();
	cin.tie(0);
	int T;
	cin >> T;
	
	DP[1][1].push_back("1");
	DP[1][0].push_back("0");
	
	for (int i = 0; i < T; i++){
		int N, K;
		cin >> N >> K;
		
		cout << "The bit patterns are" << endl;
		
		if (K != 0) {
			vector<string> bitPattern = createBitPatterns(N, K);
//			for (int j = 0; j < bitPattern.size(); j++){
//				if (count(bitPattern[j].begin(), bitPattern[j].end(), '1') != K) {
//					bitPattern.erase(bitPattern.begin() + distance(bitPattern.begin(), find(bitPattern.begin(), bitPattern.end(), bitPattern[j])));
//				}
//			}
			for (int j = 0; j < bitPattern.size(); j++){
				cout << bitPattern[j] << endl;
			}
		} else {
			string s(N, '0');
			cout << s << endl;
		}
	}
	return 0;
}
