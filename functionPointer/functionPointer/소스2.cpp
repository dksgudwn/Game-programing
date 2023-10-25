#include <iostream>
#include <vector>
#include <memory>
using namespace std;
//����: �Լ���ü�� �����ϸ� �� 1~2�� �ɸ��°� 10�� ¥���� ����°�
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
	int m_rarity; //���
	int m_type; //���� ������ �ֳ�
};
//���� ǥ����
[](){}
int main()
{
	vector<Item> v;
	//�����۹�ȣ 1, ���1, Ÿ�Ծ���
	Item i1, i2;
	i1.m_itemid = 1;
	i1.m_rarity = 2;
	v.push_back(i1);
	v.push_back(Item(1, 1, ItemType::None));
	unique_ptr<Item> uptr = std::make_unique<Item>();
	unique_ptr<Item> uptr2 = std::move(uptr);
}