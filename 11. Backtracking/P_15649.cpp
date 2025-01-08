#include <iostream>
#include <vector>

int N, M;
int number[9];

void func(int cnt) {
	if (cnt == M)
		return;

	for (int i = 1; i <= N; i++) {
		if (number[i] == 0) {
			std::cout << i << " ";

			number[i] = 1;
			func(cnt + 1);
			number[i] = 0;
		}
	}
}

int main(void) {
	// 1 <= M <= N <= 8 
	std::cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		std::cout << i << " ";

		int cnt = 1;

		number[i] = 1;
		func(cnt);
		number[i] = 0;

		std::cout << "\n";
	}

	return 0;
}