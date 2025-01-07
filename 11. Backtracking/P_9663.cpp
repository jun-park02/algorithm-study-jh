﻿#include <iostream>

int N;
int px[15], py[15];

int bc(int y, int x) {
	px[y] = x; py[y] = y;

	for (int i = 0; i < y; i++) {
		if (y == py[i]) return 0;
		if (std::abs(x - px[i]) == std::abs(y - py[i])) return 0;
	}

	if (y == N - 1) return 1;

	int r = 0;

	for (int i = 0; i < N; i++)
		r += bc(y + 1, i);

	return r;
}

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> N;
	int r = 0;
	for (int i = 0; i < N; i++)
		r += bc(0, i);
	std::cout << r;
}