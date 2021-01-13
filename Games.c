#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <math.h>
#include "Games.h"

Word words[11];
char block[20][15];
char youranswer[100][20];
char answer[30][20];
char list[100][100] = { "korea", "papa", "apple", "hawaii", "germany", "banana", "soccer",
					"baseball", "cellphone", "cup", "book", "airplane", "doll", "doctor", "trophy", "pencil",
					"water", "cloud", "angle", "queen", "clarinet", "plastic", "pushup", "desk" };

void gotoxy(int x, int y) {
	COORD c = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

//게임 함수들
RES SimplePlus() {
	srand((unsigned)time(NULL));
	int pressNum, i;
	printf("5초 후에 게임이 시작됩니다\n");
	for (i = 5; i > 0; i--) {
		printf("%d ", i);
		Sleep(1000);
	}
	printf("\n");
	clock_t start = clock();
	clock_t end = clock();
	int stage = 1;
	int correct = 0;
	int count = 0;
	RES send;
	while (1) {
		int front = (int)rand() % (int)pow(10, stage);
		int back = (int)rand() % (int)pow(10, stage);
		int answer;
		gotoxy(0, 3 + count);
		printf("%d + %d = ? ", front, back);
		gotoxy(20, 6);
		printf("답: ");
		count++;
		do {
			gotoxy(20, 5);
			if (40 - (int)(double)(end - start) / CLOCKS_PER_SEC >= 10)
				printf("남은시간: %d", 40-(int)(double)(end - start) / CLOCKS_PER_SEC);
			else
				printf("남은시간:  %d", 40 - (int)(double)(end - start) / CLOCKS_PER_SEC);			
			end = clock();
			Sleep(100);
			if ((int)(double)(end - start) / CLOCKS_PER_SEC > 40) {
				send.correct = correct;
				send.count = count;
				return send;
			}
		} while (!_kbhit());
		gotoxy(20, 6);
		printf("답: ");
		scanf("%d", &answer);
		gotoxy(22, 6);
		printf("       ");
		if (answer == front + back) {
			correct++;
		}
		if (correct % 12 == 0 && correct > 1) {
			stage++;
		}
		gotoxy(20, 7);
		printf("정확도: %d / %d  %.2f%%", correct, count,(double) correct / count*100);
	}
}

RES SimpleMul() {
	srand((unsigned)time(NULL));
	int pressNum, i;
	printf("5초 후에 게임이 시작됩니다\n");
	for (i = 5; i > 0; i--) {
		printf("%d ", i);
		Sleep(1000);
	}
	printf("\n");
	clock_t start = clock();
	clock_t end = clock();
	int stageA = 1, stageB = 1;
	int count = 0;
	int correct = 0;
	RES send;
	while (1) {
		int front = (int)rand() % (int)pow(10, stageA);
		int back = (int)rand() % (int)pow(10, stageB);
		int answer;
		gotoxy(0, 3 + count);
		printf("%d * %d = ? ", front, back);
		gotoxy(20, 6);
		printf("답: ");
		count++;
		do {
			gotoxy(20, 5);
			if (40 - (int)(double)(end - start) / CLOCKS_PER_SEC >= 10)
				printf("남은시간: %d", 40 - (int)(double)(end - start) / CLOCKS_PER_SEC);
			else
				printf("남은시간:  %d", 40 - (int)(double)(end - start) / CLOCKS_PER_SEC);
			end = clock();
			Sleep(100);
			if ((int)(double)(end - start) / CLOCKS_PER_SEC > 40) {
				send.correct = correct;
				send.count = count;
				return send;
			}
		} while (!_kbhit());
		gotoxy(20, 6);
		printf("답: ");
		scanf("%d", &answer);
		gotoxy(22, 6);
		printf("             ");
		if (answer == front * back) {
			correct++;
		}
		if (correct % 12 == 0 && correct > 1 && correct%24 != 0) {
			stageA++;
		}
		if (correct % 24 == 0 && correct > 1) {
			stageB++;
		}
		gotoxy(20, 7);
		printf("정확도: %d / %d  %.2f%%", correct, count, (double)correct / count * 100);
	}
}

RES SimpleWriting() {
	srand((unsigned)time(NULL));
	int i, ran;
	char answer[100];
	int count = 0;
	int correct = 0;
	RES send;
	printf("제한 시간 40초 안에 보이는 단어를 최대한 빨리 적으세요\n");
	printf("5초 후에 게임이 시작됩니다\n");
	for (i = 5; i > 0; i--) {
		printf("%d ", i);
		Sleep(1000);
	}
	printf("\n");
	clock_t start = clock();
	clock_t end = clock();
	while (1) {
		ran = (int)rand() % 24;
		gotoxy(0, 3 + count);
		printf("%s ", list[ran]);
		gotoxy(20, 6);
		printf("답: ");
		count++;
		do {
			gotoxy(20, 5);
			if (40 - (int)(double)(end - start) / CLOCKS_PER_SEC >= 10)
				printf("남은시간: %d", 40 - (int)(double)(end - start) / CLOCKS_PER_SEC);
			else
				printf("남은시간:  %d", 40 - (int)(double)(end - start) / CLOCKS_PER_SEC);
			end = clock();
			Sleep(500);
			if ((int)(double)(end - start) / CLOCKS_PER_SEC > 40) {
				send.correct = correct;
				send.count = count;
				return send;
			}
		} while (!_kbhit());
		gotoxy(20, 6);
		printf("답: ");
		scanf("%s", answer);
		gotoxy(22, 6);
		printf("                    ");
		if (!strcmp(answer, list[ran])) {
			correct++;
		}
		gotoxy(20, 7);
		printf("정확도: %d / %d  %.2f%%", correct, count, (double)correct / count * 100);
	}
}

int SimpleRSP() {
	srand((unsigned)time(NULL));
	int i, ran;
	char RSP[10];
	int win = 0, draw = 0, lose = 0;
	char str[3][10] = { "가위", "바위", "보" };
	printf("컴퓨터를 상대로 이겨보세요. 총 10번 붙게 됩니다.\n");
	printf("가위, 바위, 또는 보를 입력하세요\n");
	printf("5초 후에 게임이 시작됩니다\n");
	for (i = 5; i > 0; i--) {
		printf("%d ", i);
		Sleep(1000);
	}
	printf("\n");
	for (i = 0; i < 10; i++) {
		printf("입력: ");
		scanf("%s", RSP);
		ran = (int)rand() % 3 + 1;
		if (!strcmp(RSP, "가위")) {
			if (ran == 1) {
				printf("컴퓨터: %s ", str[ran - 1]);
				printf("Draw\n"); draw++;
			}
			else if (ran == 2) {
				printf("컴퓨터: %s ", str[ran - 1]);
				printf("Lose\n"); lose++;
			}
			else if (ran == 3) {
				printf("컴퓨터: %s ", str[ran - 1]);
				printf("Win\n"); win++;
			}
		}
		else if (!strcmp(RSP, "바위")) {
			if (ran == 1) {
				printf("컴퓨터: %s ", str[ran - 1]);
				printf("Win\n"); win++;
			}
			else if (ran == 2) {
				printf("컴퓨터: %s ", str[ran - 1]);
				printf("Draw\n"); draw++;
			}
			else if (ran == 3) {
				printf("컴퓨터: %s ", str[ran - 1]);
				printf("Lose\n"); lose++;
			}
		}
		else if (!strcmp(RSP, "보")) {
			if (ran == 1) {
				printf("컴퓨터: %s ", str[ran - 1]);
				printf("Lose\n"); lose++;
			}
			else if (ran == 2) {
				printf("컴퓨터: %s ", str[ran - 1]);
				printf("Win\n"); win++;
			}
			else if (ran == 3) {
				printf("컴퓨터: %s ", str[ran - 1]);
				printf("Draw\n"); draw++;
			}
		}
		else {
			printf("다시 입력하세요\n");
			i--;
		}
	}
	printf("\n당신의 결과는 %d 승 %d 무 %d 패 입니다\n", win, draw, lose);
	return win * 2 + draw;
}

void CreateQuiz(int round ,int count) {
	int i=0, j =0, k, num=0;

	for (i = 10; i >= 1; i--) {
		strcpy(words[i].str, words[i - 1].str);
		words[i].x = words[i - 1].x;
		words[i - 1].x = 0;
		strcpy(words[i - 1].str, " ");
	}
	if (count < round) {
		words[0].x = (int)rand() % 12 + 2;
		strcpy(words[0].str, list[(int)rand() % 24]);
		strcpy(answer[count], words[0].str);
	}
}

void Show(int round) {
	int i;
	for (i = 0; i < 10; i++) {
		gotoxy(words[i].x, i);
		printf("%s", words[i].str);
	}
	printf("\n");
	printf("--------------------\n");
	printf("%d단계\n", round);
}
	
int SimpleMemory( ) {
	srand((unsigned)time(NULL));
	int i, count, score = 0;
	char sheet[20];
	printf("5초 후에 게임이 시작됩니다\n내려 오는 단어를 순서대로 오차 없이 적어야 다음 단계로 넘어갑니다\n");
	for (i = 5; i > 0; i--) {
		printf("%d ", i);
		Sleep(1000);
	}
	int round = 3, wordcount = 0;
	int speed = 500;
	while (1) {
		for (i = 0; i < 10; i++) {
			words[i].x = 0;
			strcpy(words[i].str, " ");
		}
		for (i = 0; i < 30; i++) {
			strcpy(answer[i], " ");
		}
		wordcount = 0;
		count = 0;
		for (i = 0; i < round + 10; i++) {
			system("cls");
			CreateQuiz(round, wordcount);
			Show(score+1);
			Sleep(speed);
			wordcount++;
		}
		printf("\n단어들을 입력하세요\n:");
		for (i = 0; i < round; i++) {
			scanf("%s", sheet);
			if (strcmp(sheet, answer[i]) == 0) {
				count++;
			}
		}
		if (count == round) {
			score++;
			if (score % 2 != 0) {
				speed -= 200;
			}
			else {
				round++;
				speed += 200;
			}
		}
		else {
			break;
		}
	}
	return score;
}

void CreateBlock() {
	int i = 0, j = 0;
	for (i = 15; i >= 1; i--) {
		for (j = 0; j < 15; j++) {
			block[i][j] = block[i - 1][j];
		}
	}
	for (i = 0; i < 15; i++) {
		block[0][i] = 'B';
	}
	for (i = 0; i<(int)rand()%5; i++)
		block[0][(int)rand() % 15] = 'A';
}

void ShowBlock() {
	int i, j;
	for (i = 0; i < 15; i++) {
		for (j = 0; j < 15; j++) {
			gotoxy(j, i);
			if (block[i][j] == 'A') {
				printf("A");
			}
			else
				printf(" ");
		}
	}
	printf("\n");
	printf("---------------\n");
}

int SimpleEscape() {
	srand((unsigned)time(NULL));
	int i, j, x = 7, y = 14, t = 1, pl = 7, score = 0;;
	char player[15];
	printf("5초 후에 게임이 시작됩니다\n내려 오는 벽돌을 피하세요!\n");
	for (i = 5; i > 0; i--) {
		printf("%d ", i);
		Sleep(1000);
	}
	for (i = 0; i < 15; i++) {
		for (j = 0; j < 15; j++) {
			block[i][j] = 'B';
		}
	}
	while (1) {
		gotoxy(20, 10);
		printf("점수: %d", score);
		gotoxy(x, y);
		printf("P");
		do {
			if (block[14][pl] == 'A') {
				gotoxy(0, 21);
				printf("당신의 점수는 %d 점 입니다\n", score-1);
				return score-1;
			}
			gotoxy(20, 10);
			printf("점수: %d", score);
			system("cls");
			CreateBlock();
			gotoxy(x, y);
			printf("P");
			ShowBlock();
			gotoxy(20, 10);
			printf("점수: %d", score);
			gotoxy(x, y);
			printf("P");
			Sleep(500*pow(0.99, t));
			score++;
			t++;
		} while (!_kbhit());
		unsigned char c = _getch();
		gotoxy(x, y);
		if (c == 224) {
			c = _getch();
			if (c == 75 && x > 0) {
				gotoxy(x, y);
				printf(" ");
				x--;
				pl--;
			}
			else if (c == 77 && x < 14) {
				gotoxy(x, y);
				printf(" ");
				x++;
				pl++;
			}
		}
		gotoxy(x, y);
		printf("P");
	}
	printf("당신의 점수는 %d 점 입니다\n", score-1);
	gotoxy(0, 21);
	return score-1;
}
