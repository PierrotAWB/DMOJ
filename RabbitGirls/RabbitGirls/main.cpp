//
//  main.cpp
//  RabbitGirls
//
//  Created by Andrew Wang on 2017-07-16.
//  Copyright © 2017 Andrew Wang. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(int argc, const char * argv[]) {
	
	ios::sync_with_stdio();
	cin.tie(0);
	
	int N, K;
	long double ans;
	cin >> N >> K;
	
	long double divRes = N / (long double) K;
	bool roundUp = 1 - (remainder(divRes, 1)) >= 0.5;
	
	if (roundUp) {
		ans = (ceil(divRes) - divRes) * K;
	} else {
		ans = (divRes - floor(divRes)) * K;
	}
	
	cout << fixed << setprecision(0) << ans;
	return 0;
}
