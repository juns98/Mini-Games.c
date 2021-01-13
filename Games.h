#ifndef GAMES_H
#define GAMES_H

//기억력 테스트용 word 구조체
typedef struct {
	int x;
	char str[20];
}Word;

//결과 구조체
typedef struct {
	int correct;
	int count;
}RES;

void gotoxy(int x, int y);

//게임 목록
RES SimplePlus();
RES SimpleMul();
RES SimpleWriting();
int SimpleRSP();
int SimpleTest();
int SimpleMemory();
int SimpleEscape();

#endif
