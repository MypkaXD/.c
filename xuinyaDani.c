#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#define lenght 10

int main() {

	char arr[lenght], ch;//массив char'ов
	printf("Vedite stroky:\n");
	int i = 0;
	while (1) {
		ch = getchar();
		if (ch == '\n')
			break;
		if (i >= lenght) {
			printf("ERROR: Vi vveli mnogo simvolov\n");
			break;
		}
		arr[i++] = ch;
	}
	
	bool checkerM{ false };
	bool checkerO{ false };
	bool checkerS{ false };
	bool checkerK{ false };
	bool checkerA{ false };
	bool checkerL{ false };
	bool checkerE{ false };
	bool checkerV{ false };
	//Москалев Moscalev

	for (int count = 0; arr[count] != '\0'; count++) {
		if (arr[count] == 'M')
			checkerM = true;
		else if (arr[count] == 'O')
			checkerO = true;
		else if (arr[count] == 'S')
			checkerS = true;
		else if (arr[count] == 'K')
			checkerK = true;
		else if (arr[count] == 'A')
			checkerA = true;
		else if (arr[count] == 'L')
			checkerL = true;
		else if (arr[count] == 'E')
			checkerE = true;
		else if (arr[count] == 'V')
			checkerV = true;
	}

	if (checkerM and checkerO and checkerS and checkerK and checkerA and checkerL and checkerE and checkerV)
		printf("My secondame est' v stroke\n");
	else
		printf("My secondame net v stroke\n");

	return 0;
}
