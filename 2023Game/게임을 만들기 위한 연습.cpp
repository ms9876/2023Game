#include <iostream>
using namespace std;

int add(int, int);
int main() {
	cout << add(10, 20) << "\n";
}
int add(int a, int b) {
	return a + b;
}