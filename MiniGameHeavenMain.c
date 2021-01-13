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
	//���� ����
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
	
	//����ȭ��
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
	printf("                ����Ͻ÷��� �ƹ� Ű�� �Է��ϼ���\n");
	char a = _getch();

	//���� ����
	while (1) {
		int gameNumber, input;
		system("cls");
		printf("��-------------------------------------------��\n");
		printf("��---������ �����ϼ���---                    ��\n");
		printf("��1�� ���� ç����                            ��\n");
		printf("��2�� ���� ç����                            ��\n");
		printf("��3�� �޾ƾ��� ç����                        ��\n");
		printf("��4�� ���������� ç����                      ��\n");
		printf("��5�� ���� �׽�Ʈ                          ��\n");
		printf("��6�� A ���ϱ� ����                          ��\n");
		printf("��7�� ���ھ� ����                            ��\n");
		printf("�������� �����Ͻ÷��� 8���� ��������         ��\n");
		printf("��-------------------------------------------��\n");

		//print top scores
		printf("-------Top Scores-------\n");
		strcpy(file, "plusscore.txt");
		strcpy(challenge, "���� ç����");
		PrintTopScore(file, challenge);
		strcpy(file, "mulscore.txt");
		strcpy(challenge, "���� ç����");
		PrintTopScore(file, challenge);
		strcpy(file, "writingscore.txt");
		strcpy(challenge, "�޾ƾ��� ç����");
		PrintTopScore(file, challenge);
		strcpy(file, "rspscore.txt");
		strcpy(challenge, "���������� ç����");
		PrintTopScore(file, challenge);
		strcpy(file, "memscore.txt");
		strcpy(challenge, "���� �׽�Ʈ");
		PrintTopScore(file, challenge);
		strcpy(file, "escscore.txt");
		strcpy(challenge, "A ���ϱ� ����");
		PrintTopScore(file, challenge);
		printf("------------------------\n");
		printf("�Է�: ");
		
		// choose game
		scanf("%d", &gameNumber);
		getchar();
		system("cls");

		if (gameNumber == 1) {
			RES send = SimplePlus();
			gotoxy(0, send.count);
			printf("\n����� ������ %d�� �Դϴ�\n", send.correct);
			strcpy(txt, "plusscore.txt");
			while (getchar() != '\n');
			SetScore(txt, send.correct);
		}
		else if (gameNumber == 2) {
			RES send = SimpleMul();
			gotoxy(0, send.count);
			printf("\n����� ������ %d�� �Դϴ�\n", send.correct);
			strcpy(txt, "mulscore.txt");
			while (getchar() != '\n');
			SetScore(txt, send.correct);
		}
		else if (gameNumber == 3) {
			RES send = SimpleWriting();
			gotoxy(0, send.count);
			printf("\n����� ������ %d�� �Դϴ�\n", send.correct);
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
			printf("��-------------------------------------------��\n");
			printf("��---���ھ Ȯ���� ������ �����ϼ���---    ��\n");
			printf("��1�� ���� ç����                            ��\n");
			printf("��2�� ���� ç����                            ��\n");
			printf("��3�� �޾ƾ��� ç����                        ��\n");
			printf("��4�� ���������� ç����                      ��\n");
			printf("��5�� ���� �׽�Ʈ                          ��\n");
			printf("��6�� A ���ϱ� ����                          ��\n");
			printf("���ڷ� ���÷��� 7���� ��������               ��\n");
			printf("��-------------------------------------------��\n");
			printf("�Է�: ");
			scanf("%d", &result);
			if (result == 1) {
				strcpy(file, "plusscore.txt");
				strcpy(challenge, "���� ç����");
				viewScoreboard(file, challenge);
				printf("�����÷��� 1���� �����ð� �����Ͻ÷��� 2���� ��������\n");
				while (1) {
					printf("�Է�: ");
					scanf("%d", &input);
					if (input == 1)
						break;
					else if (input == 2)
						exit(1);
					else
						printf("�ٽ� �Է��ϼ���\n");
				}
			}
			else if (result == 2) {
				strcpy(file, "mulscore.txt");
				strcpy(challenge, "���� ç����");
				viewScoreboard(file, challenge);
				printf("�����÷��� 1���� �����ð� �����Ͻ÷��� 2���� ��������\n");
				while (1) {
					printf("�Է�: ");
					scanf("%d", &input);
					if (input == 1)
						break;
					else if (input == 2)
						exit(1);
					else
						printf("�ٽ� �Է��ϼ���\n");
				}
			}
			else if (result == 3) {
				strcpy(file, "writingscore.txt");
				strcpy(challenge, "�޾ƾ��� ç����");
				viewScoreboard(file, challenge);
				printf("�����÷��� 1���� �����ð� �����Ͻ÷��� 2���� ��������\n");
				while (1) {
					printf("�Է�: ");
					scanf("%d", &input);
					if (input == 1)
						break;
					else if (input == 2)
						exit(1);
					else
						printf("�ٽ� �Է��ϼ���\n");
				}
			}
			else if (result == 4) {
				strcpy(file, "rspscore.txt");
				strcpy(challenge, "���������� ç����");
				viewScoreboard(file, challenge);
				printf("�����÷��� 1���� �����ð� �����Ͻ÷��� 2���� ��������\n");
				while (1) {
					printf("�Է�: ");
					scanf("%d", &input);
					if (input == 1)
						break;
					else if (input == 2)
						exit(1);
					else
						printf("�ٽ� �Է��ϼ���\n");
				}
			}
			else if (result == 5) {
				strcpy(file, "memscore.txt");
				strcpy(challenge, "���� �׽�Ʈ");
				viewScoreboard(file, challenge);
				printf("�����÷��� 1���� �����ð� �����Ͻ÷��� 2���� ��������\n");
				while (1) {
					printf("�Է�: ");
					scanf("%d", &input);
					if (input == 1)
						break;
					else if (input == 2)
						exit(1);
					else
						printf("�ٽ� �Է��ϼ���\n");
				}
			}
			else if (result == 6) {
				strcpy(file, "escscore.txt");
				strcpy(challenge, "A ���ϱ� ����");
				viewScoreboard(file, challenge);
				printf("�����÷��� 1���� �����ð� �����Ͻ÷��� 2���� ��������\n");
				while (1) {
					printf("�Է�: ");
					scanf("%d", &input);
					if (input == 1)
						break;
					else if (input == 2)
						exit(1);
					else
						printf("�ٽ� �Է��ϼ���\n");
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
			printf("�ٽ� �Է��ϼ���\n");
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
				printf("   1�� none 0��\n   2�� none 0��\n   3�� none 0��\n");
			}
			break;
		}
		count++;
		printf("   %d�� %s %d��\n", i + 1, name, rank);
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

	printf("�̸��� �Է��ϼ���: ");
	scanf("%s", username);
	FILE* des = fopen(str, "a");
	FILE* src = fopen(str, "rt");
	// ���ھ���� ��� ������ �迭��
	while (1) {
		ret = fscanf(src, "%s %d", savedname, &score);
		if (ret == EOF)
			break;
		strcpy(board[count].name, savedname);
		board[count].score = score;
		count++;
	}
	fclose(des);
	//���ھ�� ����
	FILE* fp = fopen(str, "w");
	count = 0;
	while (result < board[count].score) {
		count++;
		if (count > 14)
			break;
	}
	//�迭�� ���ھ� �߰�
	for (i = 13; i >= count; i--) {
		board[i + 1].score = board[i].score;
		strcpy(board[i + 1].name, board[i].name);
	}
	board[count].score = result;
	strcpy(board[count].name, username);
	//���Ͽ� ���ھ�� ���� / ���ھ�� ���
	system("cls");
	printf("----Score Board----\n");
	for (i = 0; i < 15; i++) {
		fprintf(des, "%s %d", board[i].name, board[i].score);
		printf("   %d�� %s %d��\n", i + 1, board[i].name, board[i].score);
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
					printf("   %d�� none 0��\n", j);
				}
			}
			break;
		}
		count++;
		printf("   %d�� %s %d��\n", i + 1, name, rank);
	}
	fclose(fp);
}