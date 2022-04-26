#include <iostream>
using namespace std;
/*
	ººÅµËþÎÊÌâ£º
		
*/
void hanoi(int n, char A, char B, char C) {
	if (n == 1) {
		printf("%c -> %c", A, C);
	}
	else {
		hanoi(n - 1, A, C, B);
		printf("%c -> %c\n", A, C);
		hanoi(n - 1, B, A, C);
	}
}
int main01() {
	hanoi(2, 'A', 'B', 'C');
	return 0;
}