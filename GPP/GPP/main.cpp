#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<string.h>
#include<Windows.h>
#include "StartScene.h"
#include "console.h"
#include <mmsystem.h>
#include <Digitalv.h>
#pragma comment(lib, "winmm.lib")

using namespace std;
MCI_OPEN_PARMS openBgm; //여는거
MCI_PLAY_PARMS playBgm; //재생용
MCI_OPEN_PARMS OoenEffect; //여는거
MCI_PLAY_PARMS playEffect; //재생용
UINT Bgmid, Effectid;

#define MAX_N 4

#define RIGHT 77
#define DOWN 80
#define LEFT 75
#define UP 72

void game();
void draw(int board[][MAX_N], int score);
void generateNewNumber(int(*board)[MAX_N]);
bool isNewScore(int board[][MAX_N]);
bool isGameOver(int board[][MAX_N]);
void PlayEffect();
void PlayE();
int maxValue = 63;


int main() {
	cout.tie(nullptr);
	while (true)
	{
		system("cls");
		GameTitle();
		cout << "스페이스바를 누르세요";
		if (_getch() == 32)
		{
			break;
		}
	}
	game();
	system("cls");
	printf("\n\n게임 오버\n\n");
	return 0;
}


void game() {
	int board[MAX_N][MAX_N] = { 0 }; // 게임 보드
	int score = 0; // 게임 점수
	bool gameEnd = false; // 게임 종료 여부
	bool cellChecked[MAX_N][MAX_N] = { false };

	// 초기화
	generateNewNumber(board);
	generateNewNumber(board);
	draw(board, score);
	// 종료

	while (!gameEnd) {
		int key = _getch();
		bool action = false;
		if (key == 0xE0 || key == 0) {
			key = _getch();
			switch (key) {
			case UP:
				PlayEffect();
				PlayE();
				// 모든 열에 대해 검사
				for (int j = 0; j < MAX_N; j++) {
					for (int i = 1; i < MAX_N; i++) {
						for (int k = i; k > 0; k--) {
							// 움직이는 블록과 같지 않거나 이미 체크한 경우,
							if ((board[k - 1][j] != 0 && board[k - 1][j] != board[k][j]) ||
								board[k][j] == 0 || cellChecked[k][j] || cellChecked[k - 1][j])
								break;

							// 0이면 그냥 이동
							if (board[k - 1][j] == 0)
								board[k - 1][j] = board[k][j];
							// 같은 숫자면 2배로 병합
							else if (board[k - 1][j] == board[k][j]) {
								board[k - 1][j] *= 2;
								score += board[k - 1][j];
								cellChecked[k - 1][j] = true;
								score += board[k - 1][j];
							}

							board[k][j] = 0;
							action = true;
						}
					}
				}
				break;
			case RIGHT:
				PlayEffect();
				PlayE();


				for (int i = 0; i < MAX_N; i++) {
					for (int j = MAX_N - 2; j >= 0; j--) {
						for (int k = j; k < MAX_N - 1; k++) {
							if ((board[i][k + 1] != 0 && board[i][k] != board[i][k + 1]) ||
								board[i][k] == 0 || cellChecked[i][k] || cellChecked[i][k + 1])
								break;

							if (board[i][k + 1] == 0)
								board[i][k + 1] = board[i][k];
							else if (board[i][k + 1] == board[i][k]) {
								board[i][k + 1] *= 2;
								cellChecked[i][k + 1] = true;
								score += board[i][k + 1];
							}

							board[i][k] = 0;
							action = true;
						}
					}
				}
				break;
			case DOWN:
				PlayEffect();
				PlayE();

				for (int j = 0; j < MAX_N; j++) {
					for (int i = MAX_N - 2; i >= 0; i--) {
						for (int k = i; k < MAX_N - 1; k++) {
							if ((board[k + 1][j] != 0 && board[k][j] != board[k + 1][j]) ||
								board[k][j] == 0 || cellChecked[k][j] || cellChecked[k + 1][j])
								break;

							if (board[k + 1][j] == 0)
								board[k + 1][j] = board[k][j];
							else if (board[k + 1][j] == board[k][j]) {
								board[k + 1][j] *= 2;
								cellChecked[k + 1][j] = true;
								score += board[k + 1][j];
							}

							board[k][j] = 0;
							action = true;
						}
					}
				}
				break;
			case LEFT:
				PlayEffect();
				PlayE();

				for (int i = 0; i < MAX_N; i++) {
					for (int j = 1; j < MAX_N; j++) {
						for (int k = j; k > 0; k--) {
							if ((board[i][k - 1] != 0 && board[i][k] != board[i][k - 1]) ||
								board[i][k] == 0 || cellChecked[i][k] || cellChecked[i][k - 1])
								break;

							if (board[i][k - 1] == 0)
								board[i][k - 1] = board[i][k];
							else if (board[i][k - 1] == board[i][k]) {
								board[i][k - 1] *= 2;

								cellChecked[i][k - 1] = true;
								score += board[i][k - 1];
							}

							board[i][k] = 0;
							action = true;
						}
					}
				}
				break;
			default:
				action = false;
				break;
			}
		}
		memset(cellChecked, 0, sizeof(cellChecked));
		if (action)
			generateNewNumber(board);
		gameEnd = isGameOver(board);
		draw(board, score);
		Sleep(300);
	}
}


void draw(int board[][MAX_N], int score) {
	system("cls");

	if (isNewScore(board))
	{
		for (int k = 0; k < 1; k++)
		{
			SetColor((int)COLOR::WHITE, (int)COLOR::WHITE);
			system("cls");
			for (int i = 0; i < MAX_N; i++)
			{
				for (int j = 0; j < MAX_N; j++)
				{
					cout << "                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     ";

				}
				SetColor((int)COLOR::WHITE, (int)COLOR::BLACK);
				Sleep(200);
				cout << "                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     ";
				cout << endl;
			}
			SetColor((int)COLOR::WHITE, (int)COLOR::BLACK);
			Sleep(200);
			for (int i = 0; i < MAX_N; i++)
			{
				for (int j = 0; j < MAX_N; j++)
				{
					if (!board[i][j])
					{
						cout << "\t0";
					}
					else
					{
						cout << "\t" << board[i][j];
					}
				}
			}
		}
		system("cls");
	}
	for (int i = 0; i < MAX_N; i++) {
		for (int j = 0; j < MAX_N; j++) {
			if (!board[i][j])
			{
				SetColor((int)COLOR::WHITE, (int)COLOR::BLACK);
				cout << "\t0";
			}
			else if (board[i][j] == 2)
			{
				SetColor((int)COLOR::WHITE, (int)COLOR::BLUE);
				cout << "\t" << board[i][j];
				SetColor((int)COLOR::WHITE, (int)COLOR::BLACK);
			}
			else if (board[i][j] == 4)
			{
				SetColor((int)COLOR::WHITE, (int)COLOR::GREEN);
				cout << "\t" << board[i][j];
				SetColor((int)COLOR::WHITE, (int)COLOR::BLACK);
			}
			else if (board[i][j] == 8)
			{
				SetColor((int)COLOR::WHITE, (int)COLOR::SKYBLUE);
				cout << "\t" << board[i][j];
				SetColor((int)COLOR::WHITE, (int)COLOR::BLACK);
			}
			else if (board[i][j] == 16)
			{
				SetColor((int)COLOR::WHITE, (int)COLOR::RED);
				cout << "\t" << board[i][j];
				SetColor((int)COLOR::WHITE, (int)COLOR::BLACK);
			}
			else if (board[i][j] == 32)
			{
				SetColor((int)COLOR::WHITE, (int)COLOR::VIOLET);
				cout << "\t" << board[i][j];
				SetColor((int)COLOR::WHITE, (int)COLOR::BLACK);
			}
			else if (board[i][j] == 64)
			{
				SetColor((int)COLOR::WHITE, (int)COLOR::YELLOW);
				cout << "\t" << board[i][j];
				SetColor((int)COLOR::WHITE, (int)COLOR::BLACK);
			}
			else if (board[i][j] == 128)
			{
				SetColor((int)COLOR::BLACK, (int)COLOR::LIGHT_GRAY);
				cout << "\t" << board[i][j];
				SetColor((int)COLOR::WHITE, (int)COLOR::BLACK);
			}
			else if (board[i][j] == 256)
			{
				SetColor((int)COLOR::WHITE, (int)COLOR::GRAY);
				cout << "\t" << board[i][j];
				SetColor((int)COLOR::WHITE, (int)COLOR::BLACK);
			}
			else if (board[i][j] == 512)
			{
				SetColor((int)COLOR::WHITE, (int)COLOR::LIGHT_BLUE);
				cout << "\t" << board[i][j];
				SetColor((int)COLOR::WHITE, (int)COLOR::BLACK);
			}
			else if (board[i][j] == 1024)
			{
				SetColor((int)COLOR::WHITE, (int)COLOR::LIGHT_GREEN);
				cout << "\t" << board[i][j];
				SetColor((int)COLOR::WHITE, (int)COLOR::BLACK);
			}
			else if (board[i][j] == 2048)
			{
				SetColor((int)COLOR::WHITE, (int)COLOR::MINT);
				printf("\t%d", board[i][j]);
				SetColor((int)COLOR::WHITE, (int)COLOR::BLACK);
			}
			else if (board[i][j] == 4096)
			{
				SetColor((int)COLOR::WHITE, (int)COLOR::LIGHT_RED);
				cout << "\t" << board[i][j];
				SetColor((int)COLOR::WHITE, (int)COLOR::BLACK);
			}
			else if (board[i][j] == 8192)
			{
				SetColor((int)COLOR::WHITE, (int)COLOR::LIGHT_YELLOW);
				cout << "\t" << board[i][j];
				SetColor((int)COLOR::WHITE, (int)COLOR::BLACK);
			}
			else
			{
				SetColor((int)COLOR::WHITE, (int)COLOR::BLACK);
				cout << "\t" << board[i][j];
			}
		}
		cout << "\n";
	}

	SetColor((int)COLOR::WHITE, (int)COLOR::BLACK);
	cout << "\n\n점수: " << score;
}


void generateNewNumber(int(*board)[MAX_N]) { //생성
	int count = 0;
	int* p[MAX_N * MAX_N];
	for (int i = 0; i < MAX_N; i++) {
		for (int j = 0; j < MAX_N; j++) {
			if (!board[i][j])
				p[count++] = &board[i][j];
		}
	}
	srand(time(NULL));
	*p[rand() % count] = rand() % 100 > 80 ? 4 : 2;
}

bool isNewScore(int board[][MAX_N])
{
	for (int i = 0; i < MAX_N; i++)
	{
		for (int j = 0; j < MAX_N; j++)
		{
			if (board[j][i] > maxValue)
			{
				maxValue = board[j][i];
				return true;
			}
		}
	}
	return false;
}


bool isGameOver(int board[][MAX_N]) {
	// 0이 남아있으면 게임 계속 진행
	for (int i = 0; i < MAX_N; i++) {
		for (int j = 0; j <= MAX_N; j++) {
			if (board[i][j] == 0)
				return false;
		}
	}
	// 같은 숫자가 남아있으면 게임 계속 진행
	for (int i = 0; i < MAX_N; i++) {
		for (int j = 0; j <= MAX_N; j++) {
			if ((j + 1 < MAX_N && board[i][j] == board[i][j + 1]) ||
				(i + 1 < MAX_N && board[i][j] == board[i + 1][j]))
				return false;
		}
	}
	// 게임 종료
	return true;
}
void PlayEffect()
{
	OoenEffect.lpstrDeviceType = TEXT("mpegvideo");
	OoenEffect.lpstrElementName = TEXT("random.mp3");
	mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD_PTR)&OoenEffect);
	OoenEffect.wDeviceID;
	Effectid = OoenEffect.wDeviceID;
	mciSendCommand(Effectid, MCI_PLAY, MCI_NOTIFY, (DWORD_PTR)&OoenEffect);
	Sleep(100);
	mciSendCommand(Effectid, MCI_SEEK, MCI_SEEK_TO_START, (DWORD_PTR)&OoenEffect);
}
void PlayE() {
	Beep(523.25f, 20);
	Beep(1046.50f, 20);
}