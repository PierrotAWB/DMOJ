//
//  main.cpp
//  CCC06S4
//
//  Created by Andrew Wang on 2017-07-03.
//  Copyright © 2017 Andrew Wang. All rights reserved.
//

#include <iostream>
#include <algorithm> // std::find()

using namespace std;

int main(int argc, const char * argv[]) {
	int x;
	while (cin >> x) {
		if (x == 0) break;
		else {
			int n = x;
			int mtable[n + 1][n + 1];
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					cin >> mtable[i][j];
				}
			}
			
			// test if mtable displays a group
			
			// identity
			for (int i = 1; i <= n; i++) {
				if (find(mtable[i], mtable[i] + n + 1, i) == mtable[i].end()){
					cout << "no" << endl;
				}
			}
		}
	}
	return 0;
}
