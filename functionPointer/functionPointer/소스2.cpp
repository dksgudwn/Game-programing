#include <iostream>
#include <vector>
#include <memory>
using namespace std;
//람다: 함수객체를 복잡하면 한 1~2분 걸리는걸 10초 짜리로 만드는거
enum class ItemType
{
	None,
	Weapon,
	Armor
};
class Item
{
public:
	Item(int _itemid, int _rarity, ItemType _type)
		:m_itemid(_itemid)
		, m_rarity(_rarity)
		, m_type(_type)
	{};
	void Upgrade(int _val)
	{
		m_rarity += 1;
	}

	int m_itemid; //id
	int m_rarity; //등급
	int m_type; //누가 가지고 있나
};
//람다 표현식
[](){}
int main()
{
	vector<Item> v;
	//아이템번호 1, 등급1, 타입없음
	Item i1, i2;
	i1.m_itemid = 1;
	i1.m_rarity = 2;
	v.push_back(i1);
	v.push_back(Item(1, 1, ItemType::None));
	unique_ptr<Item> uptr = std::make_unique<Item>();
	unique_ptr<Item> uptr2 = std::move(uptr);
}