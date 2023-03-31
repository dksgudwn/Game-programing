#include <iostream>
using namespace std;

int main()
{
	//*셔플*알고리즘을 이용해 겹치지 않는 무작위수를 고른다.
	int iNumber[9] = { };
	for (int i = 0; i < 9; i++)
		iNumber[i] = i + 1;
	int idx1, idx2, temp;
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 100; i++) {
		idx1 = rand() % 9;
		idx2 = rand() % 9;
		//cout << idx1 << " " << idx2 << endl;
		temp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = temp;
	}

	cout << "* * *" << endl;
	cout << iNumber[0] << " " << iNumber[1] << " " << iNumber[2] << endl;
	int iStrike = 0, iBall = 0;
	int iGamecount = 0;
	int iInputnum[3];

	while (true)
	{
		int player = iGamecount % 2+1;
		cout << "현재 플레이어 : " << player << endl;
		cout << iGamecount+1 << "회" << endl;
		cout << "1~9중3개입력(0: 종료) :";
		cin >> iInputnum[0] >> iInputnum[1] >> iInputnum[2];
		if (iInputnum[0] == 0 || iInputnum[1] == 0 || iInputnum[2] == 0)
			break;
		else if (iInputnum[0] < 0 || iInputnum[0]>9
			|| iInputnum[1] < 0 || iInputnum[1]>9
			|| iInputnum[2] < 0 || iInputnum[2]>9)
		{
			cout << "잘못된 숫자를 입력했습니다." << endl;
			continue;
		}

		iStrike = 0;
		iBall = 0;

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (iNumber[j] == iInputnum[i]) {
					if (i == j) {
						iStrike++;
					}
					else {
						iBall++;
					}
				}
			}
		}

		if (iStrike >= 3) {
			cout << "플레이어 : " << player << " 승리" << endl;
			return 0;
		}
		else if (iStrike == 0 && iBall == 0)
		{
			cout << "아웃" << endl;
			iGamecount++;
		}
		else {
			cout << "Strike: " << iStrike << " Ball: " << iBall << endl;
			iGamecount++;
		}
	}
}