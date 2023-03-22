#include <iostream>

using namespace std;

int main() {
#pragma region 내 코드

	int num;
	cin >> num;

	int numReverse = 0;
	int sum = 0;

	/*for (int i = 0; i < a; i++) {
		int b = a % 10;
		sum += b;
		numReverse = numReverse * 10 + b;
		a /= 10;
	}*/

	while (num != 0) {
		int b = num % 10; // 10으로 나누는 이유는 우리가 10진수를 쓰기 때문에
		sum += b;
		numReverse = numReverse * 10 + b;
		num /= 10;
	}

	cout << numReverse << endl;
	cout << sum;

#pragma endregion

#pragma region 선생님 코드

	int n, sum = 0, rev = 0; //초기화를 안 해주면 쓰레기 값이 들어감
	cin >> n;
	while (n != 0) {
		rev = rev * num % 10;
		sum += n % 10;
		n /= 10;
	}
	cout << rev << endl << sum;

#pragma endregion
}