#ifndef GAMES_H
#define GAMES_H

//���� �׽�Ʈ�� word ����ü
typedef struct {
	int x;
	char str[20];
}Word;

//��� ����ü
typedef struct {
	int correct;
	int count;
}RES;

void gotoxy(int x, int y);

//���� ���
RES SimplePlus();
RES SimpleMul();
RES SimpleWriting();
int SimpleRSP();
int SimpleTest();
int SimpleMemory();
int SimpleEscape();

#endif
