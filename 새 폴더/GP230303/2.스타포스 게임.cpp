//#include <iostream>
//using namespace std;
//
//int main()
//{
//	cout << "==================" << endl;
//	cout << "��Ÿ���� ��ȭ ����" << endl;
//	cout << "==================" << endl;
//	srand((unsigned int)time(NULL));
//	cout << "���� ����� ��ΰ���?" << endl;
//	int iUpgrade = 0;
//	cin >> iUpgrade;
//
//	float fPersent = rand() % 10001 / 100.f;
//	cout << fPersent;
//	cout << "���� ���� Upgrade:" << iUpgrade << "��" << endl;
//	cout << "��ȭ Ȯ�� Persent: " << fPersent << endl;
//	cout << "��ȭ�Ͻðڽ��ϱ�? ��: 1, �ƴϿ�: 0" << endl;
//	int iInput;
//	cin >> iInput;
//	if (iInput == 0)
//		return 0;
//	//0~2��:90%, 3~5��: 50, 6~9��: 10%, 10~: 1%;
//	if (iUpgrade <= 2) {
//		if (fPersent <= 90.f)
//			cout << "��ȭ ����!" << endl;
//		else
//			cout << "��ȭ ����" << endl;
//	}
//	else if (3 <= iUpgrade && iUpgrade <= 5) {
//		if (fPersent <= 50.f)
//			cout << "��ȭ ����!" << endl;
//		else
//			cout << "��ȭ ����" << endl;
//	}
//	else if (6 <= iUpgrade && iUpgrade <= 9) {
//		if (fPersent <= 10.f)
//			cout << "��ȭ ����!" << endl;
//		else
//			cout << "��ȭ ����" << endl;
//	}
//	else if (iUpgrade >= 10) {
//		if (fPersent <= 1.f)
//			cout << "��ȭ ����!" << endl;
//		else
//			cout << "��ȭ ����" << endl;
//	}
//
//	rand();
//}