#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#define lenght 100
#define countofSub 20
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
	
	

	char subarr[countofSub] , ch2;
	printf("Vedite subname:\n");
	int count = 0;
	while (1) {
		ch2 = getchar();
		if (ch2 == '\n')
			break;
		if (count >= lenght) {
			printf("ERROR: Vi vveli mnogo simvolov\n");
			break;
		}
		arr[count++] = ch2;
	}


	int checkerM = 0;
	int checkerO = 0;
	int checkerS = 0;
	int checkerK = 0;
	int checkerA = 0;
	int checkerL = 0;
	int checkerE = 0;
	int checkerV = 0;
	//Москалев Moscalev

	for (int count = 0; arr[count] != '\0'; count++) {
		for (int COUNT = 0; subarr[COUNT] != '\0'; COUNT++) {
				if (arr[count] == 'M' || arr[count] == 'm')
					checkerM++;
				else if (arr[count] == 'O' || arr[count] == 'o')
					checkerO++;
				else if (arr[count] == 'S' || arr[count] == 's')
					checkerS++;
				else if (arr[count] == 'K' || arr[count] == 'k')
					checkerK++;
				else if (arr[count] == 'A' || arr[count] == 'a')
					checkerA++;
				else if (arr[count] == 'L' || arr[count] == 'l')
					checkerL++;
				else if (arr[count] == 'E' || arr[count] == 'e')
					checkerE++;
				else if (arr[count] == 'V' || arr[count] == 'v')
					checkerV++;
		}
	}

	if ((checkerM >= 1) && (checkerO>=1) && (checkerS>=1) && (checkerK>=1) && (checkerA>=1) && (checkerL>=1) && (checkerE>=1) && (checkerV>=1))
		printf("My secondame est' v stroke\n");
	else
		printf("My secondame net v stroke\n");

	return 0;
}
