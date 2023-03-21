//#include <iostream>
//using namespace std;
//
//int main()
//{
//	cout << "==================" << endl;
//	cout << "스타포스 강화 게임" << endl;
//	cout << "==================" << endl;
//	srand((unsigned int)time(NULL));
//	cout << "현재 무기는 몇성인가요?" << endl;
//	int iUpgrade = 0;
//	cin >> iUpgrade;
//
//	float fPersent = rand() % 10001 / 100.f;
//	cout << fPersent;
//	cout << "현재 무기 Upgrade:" << iUpgrade << "성" << endl;
//	cout << "강화 확률 Persent: " << fPersent << endl;
//	cout << "강화하시겠습니까? 예: 1, 아니요: 0" << endl;
//	int iInput;
//	cin >> iInput;
//	if (iInput == 0)
//		return 0;
//	//0~2성:90%, 3~5성: 50, 6~9성: 10%, 10~: 1%;
//	if (iUpgrade <= 2) {
//		if (fPersent <= 90.f)
//			cout << "강화 성공!" << endl;
//		else
//			cout << "강화 실패" << endl;
//	}
//	else if (3 <= iUpgrade && iUpgrade <= 5) {
//		if (fPersent <= 50.f)
//			cout << "강화 성공!" << endl;
//		else
//			cout << "강화 실패" << endl;
//	}
//	else if (6 <= iUpgrade && iUpgrade <= 9) {
//		if (fPersent <= 10.f)
//			cout << "강화 성공!" << endl;
//		else
//			cout << "강화 실패" << endl;
//	}
//	else if (iUpgrade >= 10) {
//		if (fPersent <= 1.f)
//			cout << "강화 성공!" << endl;
//		else
//			cout << "강화 실패" << endl;
//	}
//
//	rand();
//}