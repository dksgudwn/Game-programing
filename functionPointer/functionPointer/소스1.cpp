//#include <iostream>
////함수 객체(Functor): 객체를 함수처럼 쓰고 싶은거야;
////함수 포인터의 단점: typedef 귀찮아 형식이 안맞으면 쓸 수 없다
////람다
//using namespace std;
//
//class Functor
//{
//public:
//	void operator()(int _val)
//	{
//		cout << "함수 객체" << endl;
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
//	int m_rarity; //등급
//	int m_userid; //누가 가지고 있나
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