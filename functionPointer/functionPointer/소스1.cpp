//#include <iostream>
////�Լ� ��ü(Functor): ��ü�� �Լ�ó�� ���� �����ž�;
////�Լ� �������� ����: typedef ������ ������ �ȸ����� �� �� ����
////����
//using namespace std;
//
//class Functor
//{
//public:
//	void operator()(int _val)
//	{
//		cout << "�Լ� ��ü" << endl;
//		m_val += _val;
//		cout << m_val << endl;
//	}
//public:
//	int m_val = 0;
//};
//
//class Item
//{
//public:
//	Item() :m_itemid(0), m_rarity(0), m_userid(0) {};
//	void Upgrade(int _val)
//	{
//		m_rarity += 1;
//	}
//
//	int m_itemid; //id
//	int m_rarity; //���
//	int m_userid; //���� ������ �ֳ�
//	void Test()
//	{
//
//	}
//};
//
//typedef void(Item::* TEST_FUNC)();
//void Test2()
//{
//
//}
//int main()
//{
//	Test2();
//	Functor func;
//	func(10);
//
//	//TEST_FUNC fn;
//	//fn = &Item::Test;
//	//Item i1;
//	////i1.Test();
//	//(i1.*fn)();
//	//Item* i2 = new Item;
//	//(*(i2).*fn)();
//	//(i2->*fn)();
//}