#include <iostream>
using namespace std;

int main()
{
	int iNumber[8] = { };
	for (int i = 0; i < 9; i++)
		iNumber[i] = i + 1;
	int idx1, idx2, temp;
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 100; i++) {
		idx1 = rand() % 9;
		idx2 = rand() % 9;
		cout << idx1 << " " << idx2 << endl;
		temp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = temp;
	}
	cout << "* * *" << endl;
	cout << iNumber[0] << " " << iNumber[1] << " " << iNumber[2] << endl;
	int iStrike = 0, iBall = 0;
	int iGamecount = 1;
	int iInputnum[3];

	while (true)
	{
		cout << iGamecount << "ȸ" << endl;
		cout << "1~9��3���Է�(0: ����) :";
		cin >> iInputnum[0] >> iInputnum[1] >> iInputnum[2];
		if (iInputnum[0] == 0 || iInputnum[1] == 0 || iInputnum[2] == 0)
			break;
		else if (iInputnum[0] < 0 || iInputnum[0]>9
			|| iInputnum[1] < 0 || iInputnum[1]>9
			|| iInputnum[2] < 0 || iInputnum[2]>9)
		{
			cout << "�߸��� ���ڸ� �Է��߽��ϴ�." << endl;
			continue;
		}
	}
}