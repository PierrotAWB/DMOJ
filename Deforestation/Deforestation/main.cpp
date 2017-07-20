//
//  main.cpp
//  Deforestation
//
//  Created by Andrew Wang on 2017-07-16.
//  Copyright © 2017 Andrew Wang. All rights reserved.
//

#include <stdio.h>

#define p(k) ((k) & (-k))

int num[1000001];

void fen_init(int *a, int size) {
	for (unsigned int i = 0; i < size; i++) {
		unsigned int j = i + p(i + 1);
		if (j < size)
			num[j] += num[i];
	}
}

int Fen_range(int *a, unsigned int i, unsigned int j)
{
	int sum = 0;
	
	while (j > i) {
		sum += a[j-1];
		j -= p(j);
	}
	
	while (i > j) {
		sum -= a[i-1];
		i -= p(i);
	}
	return sum;
}

int main(int argc, const char * argv[]) {
	int N;
	scanf("%d", &N);
	
	num[0] = 0;
	scanf("%d", &num[1]);
	
	for (int i = 2; i <= N; i++) {
		int m;
		scanf("%d", &m);
		num[i] = num[i - 1] + m;
	}
	
	fen_init(num, N + 1);
	
	int Q;
	scanf("%d", &Q);
	
	for (unsigned int i = 0; i < Q; i ++){
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", Fen_range(num, a + 1, b + 1));
	}
	
	return 0;
}
