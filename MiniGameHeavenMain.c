#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>
#include "Games.h"

typedef struct forscoring {
	char name[10];
	int score;
}Scoreboard;

void PrintTopScore(char* filename, char* challengename);
void SetScore(char* str, int result);
void viewScoreboard(char* filename, char* challengename);

int main(void) {
	int result;
	int *resultarr;
	char txt[20], file[20], challenge[20];
	//파일 선언
	FILE* plus = fopen("plusscore.txt", "a+");
	FILE* mul = fopen("mulscore.txt", "w+");
	FILE* write = fopen("writingscore.txt", "a+");
	FILE* rsp = fopen("rspscore.txt", "a+");
	FILE* mem = fopen("memscore.txt", "a+");
	FILE* esc = fopen("escscore.txt", "a+");
	fclose(plus);
	fclose(mul);
	fclose(write);
	fclose(rsp);
	fclose(mem);
	fclose(esc);
	
	//시작화면
	printf("    00000000    0   0     000     0     0     0   0000000	\n");
	printf("           0    0   0    0   0    0   00000   0         0	\n");
	printf("           0    0   0   0     0   0     0   000         0	\n");
	printf("           0    0   0    0   0    0    0 0    0  0000000000	\n");
	printf("           0  000   0     000     0   0   0   0      0      \n");
	printf("           0    0   0             0							\n");
	printf("                0   0     000000        0          00000 	\n");
	printf("                0   0     0    0        0              0	\n");
	printf("                0   0     000000        0000000        0	\n");
	printf("\n\n");
	printf("                계속하시려면 아무 키나 입력하세요\n");
	char a = _getch();

	//게임 선택
	while (1) {
		int gameNumber, input;
		system("cls");
		printf("┌-------------------------------------------┐\n");
		printf("│---게임을 선택하세요---                    │\n");
		printf("│1번 덧셈 챌린지                            │\n");
		printf("│2번 곱셈 챌린지                            │\n");
		printf("│3번 받아쓰기 챌린지                        │\n");
		printf("│4번 가위바위보 챌린지                      │\n");
		printf("│5번 기억력 테스트                          │\n");
		printf("│6번 A 피하기 게임                          │\n");
		printf("│7번 스코어 보드                            │\n");
		printf("│게임을 종료하시려면 8번을 누르세요         │\n");
		printf("└-------------------------------------------┘\n");

		//print top scores
		printf("-------Top Scores-------\n");
		strcpy(file, "plusscore.txt");
		strcpy(challenge, "덧셈 챌린지");
		PrintTopScore(file, challenge);
		strcpy(file, "mulscore.txt");
		strcpy(challenge, "곱셈 챌린지");
		PrintTopScore(file, challenge);
		strcpy(file, "writingscore.txt");
		strcpy(challenge, "받아쓰기 챌린지");
		PrintTopScore(file, challenge);
		strcpy(file, "rspscore.txt");
		strcpy(challenge, "가위바위보 챌린지");
		PrintTopScore(file, challenge);
		strcpy(file, "memscore.txt");
		strcpy(challenge, "기억력 테스트");
		PrintTopScore(file, challenge);
		strcpy(file, "escscore.txt");
		strcpy(challenge, "A 피하기 게임");
		PrintTopScore(file, challenge);
		printf("------------------------\n");
		printf("입력: ");
		
		// choose game
		scanf("%d", &gameNumber);
		getchar();
		system("cls");

		if (gameNumber == 1) {
			RES send = SimplePlus();
			gotoxy(0, send.count);
			printf("\n당신의 점수는 %d점 입니다\n", send.correct);
			strcpy(txt, "plusscore.txt");
			while (getchar() != '\n');
			SetScore(txt, send.correct);
		}
		else if (gameNumber == 2) {
			RES send = SimpleMul();
			gotoxy(0, send.count);
			printf("\n당신의 점수는 %d점 입니다\n", send.correct);
			strcpy(txt, "mulscore.txt");
			while (getchar() != '\n');
			SetScore(txt, send.correct);
		}
		else if (gameNumber == 3) {
			RES send = SimpleWriting();
			gotoxy(0, send.count);
			printf("\n당신의 점수는 %d점 입니다\n", send.correct);
			strcpy(txt, "writingscore.txt");
			while (getchar() != '\n');
			SetScore(txt, send.correct);
		}
		else if (gameNumber == 4) {
			result = SimpleRSP();
			strcpy(txt, "rspscore.txt");
			while (getchar() != '\n');
			SetScore(txt, result);
		}
		else if (gameNumber == 5) {
			result = SimpleMemory();
			strcpy(txt, "memscore.txt");
			while (getchar() != '\n');
			SetScore(txt, result);
		}
		else if (gameNumber == 6) {
			result = SimpleEscape();
			gotoxy(0, 22);
			strcpy(txt, "escscore.txt");
			SetScore(txt, result);
		}
		else if (gameNumber == 7) {
			printf("┌-------------------------------------------┐\n");
			printf("│---스코어를 확인할 게임을 선택하세요---    │\n");
			printf("│1번 덧셈 챌린지                            │\n");
			printf("│2번 곱셈 챌린지                            │\n");
			printf("│3번 받아쓰기 챌린지                        │\n");
			printf("│4번 가위바위보 챌린지                      │\n");
			printf("│5번 기억력 테스트                          │\n");
			printf("│6번 A 피하기 게임                          │\n");
			printf("│뒤로 가시려면 7번을 누르세요               │\n");
			printf("└-------------------------------------------┘\n");
			printf("입력: ");
			scanf("%d", &result);
			if (result == 1) {
				strcpy(file, "plusscore.txt");
				strcpy(challenge, "덧셈 챌린지");
				viewScoreboard(file, challenge);
				printf("나가시려면 1번을 누르시고 종료하시려면 2번을 누르세요\n");
				while (1) {
					printf("입력: ");
					scanf("%d", &input);
					if (input == 1)
						break;
					else if (input == 2)
						exit(1);
					else
						printf("다시 입력하세요\n");
				}
			}
			else if (result == 2) {
				strcpy(file, "mulscore.txt");
				strcpy(challenge, "곱셈 챌린지");
				viewScoreboard(file, challenge);
				printf("나가시려면 1번을 누르시고 종료하시려면 2번을 누르세요\n");
				while (1) {
					printf("입력: ");
					scanf("%d", &input);
					if (input == 1)
						break;
					else if (input == 2)
						exit(1);
					else
						printf("다시 입력하세요\n");
				}
			}
			else if (result == 3) {
				strcpy(file, "writingscore.txt");
				strcpy(challenge, "받아쓰기 챌린지");
				viewScoreboard(file, challenge);
				printf("나가시려면 1번을 누르시고 종료하시려면 2번을 누르세요\n");
				while (1) {
					printf("입력: ");
					scanf("%d", &input);
					if (input == 1)
						break;
					else if (input == 2)
						exit(1);
					else
						printf("다시 입력하세요\n");
				}
			}
			else if (result == 4) {
				strcpy(file, "rspscore.txt");
				strcpy(challenge, "가위바위보 챌린지");
				viewScoreboard(file, challenge);
				printf("나가시려면 1번을 누르시고 종료하시려면 2번을 누르세요\n");
				while (1) {
					printf("입력: ");
					scanf("%d", &input);
					if (input == 1)
						break;
					else if (input == 2)
						exit(1);
					else
						printf("다시 입력하세요\n");
				}
			}
			else if (result == 5) {
				strcpy(file, "memscore.txt");
				strcpy(challenge, "기억력 테스트");
				viewScoreboard(file, challenge);
				printf("나가시려면 1번을 누르시고 종료하시려면 2번을 누르세요\n");
				while (1) {
					printf("입력: ");
					scanf("%d", &input);
					if (input == 1)
						break;
					else if (input == 2)
						exit(1);
					else
						printf("다시 입력하세요\n");
				}
			}
			else if (result == 6) {
				strcpy(file, "escscore.txt");
				strcpy(challenge, "A 피하기 게임");
				viewScoreboard(file, challenge);
				printf("나가시려면 1번을 누르시고 종료하시려면 2번을 누르세요\n");
				while (1) {
					printf("입력: ");
					scanf("%d", &input);
					if (input == 1)
						break;
					else if (input == 2)
						exit(1);
					else
						printf("다시 입력하세요\n");
				}
			}
			else {
				continue;
			}
		}
		else if (gameNumber == 8) {
			exit(1);
		}
		else {
			printf("다시 입력하세요\n");
		}
	}
	while (getchar() != '\n');
}

//print top scores
void PrintTopScore(char* filename, char* challengename) {
	int ret, i, rank;
	int count = 0;
	char name[10];
	FILE* fp = fopen(filename, "rt");
	printf("---Top Scorers for %s---\n", challengename);
	for (i = 0; i < 3; i++) {
		ret = fscanf(fp, "%s %d", name, &rank);
		if (ret == EOF) {
			if (count == 0) {
				printf("   1등 none 0점\n   2등 none 0점\n   3등 none 0점\n");
			}
			break;
		}
		count++;
		printf("   %d위 %s %d점\n", i + 1, name, rank);
	}
	fclose(fp);
}

//set score to scoreboard
void SetScore(char* str, int result) {
	int i, score, ret, count;
	char username[10];
	char savedname[10];
	Scoreboard board[20];
	count = 0;
	for (i = 0; i < 20; i++) {
		board[i].score = 0;
	}
	for (i = 0; i < 20; i++) {
		strcpy(board[i].name, "none");
	}

	printf("이름을 입력하세요: ");
	scanf("%s", username);
	FILE* des = fopen(str, "a");
	FILE* src = fopen(str, "rt");
	// 스코어보드의 모든 내용을 배열로
	while (1) {
		ret = fscanf(src, "%s %d", savedname, &score);
		if (ret == EOF)
			break;
		strcpy(board[count].name, savedname);
		board[count].score = score;
		count++;
	}
	fclose(des);
	//스코어보드 비우기
	FILE* fp = fopen(str, "w");
	count = 0;
	while (result < board[count].score) {
		count++;
		if (count > 14)
			break;
	}
	//배열에 스코어 추가
	for (i = 13; i >= count; i--) {
		board[i + 1].score = board[i].score;
		strcpy(board[i + 1].name, board[i].name);
	}
	board[count].score = result;
	strcpy(board[count].name, username);
	//파일에 스코어보드 저장 / 스코어보드 출력
	system("cls");
	printf("----Score Board----\n");
	for (i = 0; i < 15; i++) {
		fprintf(des, "%s %d", board[i].name, board[i].score);
		printf("   %d위 %s %d점\n", i + 1, board[i].name, board[i].score);
	}
	fclose(fp);
	fclose(src);
	Sleep(3000);
}

//view score board
void viewScoreboard(char* filename, char* challengename) {
	int ret, i, j, rank;
	int count = 0;
	char name[10];
	FILE* fp = fopen(filename, "rt");
	printf("---Top Scorers for %s---\n", challengename);
	for (i = 0; i < 15; i++) {
		ret = fscanf(fp, "%s %d", name, &rank);
		if (ret == EOF) {
			if (count == 0) {
				for (j = 1; j <= 15; j++) {
					printf("   %d등 none 0점\n", j);
				}
			}
			break;
		}
		count++;
		printf("   %d위 %s %d점\n", i + 1, name, rank);
	}
	fclose(fp);
}