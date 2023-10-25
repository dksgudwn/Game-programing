//#include <iostream>
//#include <vector>
//using namespace std;
//
//typedef int INT;
//typedef int* INTPTR;
//class Test
//{
//
//};
//typedef int(FUNC_TYPE)(int, int);
////using FUNC_TYPE2 = int(int, int);
//
//int Add(int a, int b)
//{
//	return a + b;
//}
//int Sub(int a, int b)
//{
//	return a - b;
//}
//
//class Item
//{
//public:
//	Item() :m_itemid(0), m_rarity(0), m_userid(0) {};
//	int m_itemid; //id
//	int m_rarity; //등급
//	int m_userid; //누가 가지고 있나
//};
//bool IsRareitem(Item* _item)
//{
//	return _item->m_rarity >= 2;
//}
//bool IsUseritem(Item* _item, int _userid)
//{
//	return _item->m_userid == _userid;
//}
//typedef bool (SELECTOR)(Item*, int);
//Item* Finditem(Item _items[], int _itemcnt, SELECTOR* _select)
//{
//	for (int i = 0; i < _itemcnt; i++)
//	{
//		Item* item = &_items[i];
//		//if (item->m_itemid == _itemid)
//		if (_select(item, 5))
//			return item;
//	}
//	return nullptr;
//}
//
//int main()
//{
//	Item items[5] = {};
//	items[1].m_rarity = 3;
//	items[2].m_userid = 5;
//	Item* find = Finditem(items, 5, IsUseritem);
//	cout << find->m_rarity << endl;
//	////cout << Add(1, 2) << endl;
//	////cout << Add << endl; //함수는 주소를 가지고 있다.
//	//int a;
//	//float b;
//	//FUNC_TYPE* t;
//	//t = Sub;
//	//int result = t(1, 2);
//	//int result2 = (*t)(1, 2);
//	//cout << result << endl;
//	//cout << result2 << endl;
//	////t(3, 4); // 선언되지 않음
//	////int test = 0;
//	///*Test test;
//	//INT a = 10;
//	//INTPTR ptr = &a;
//	//*ptr = 5;*/
//}