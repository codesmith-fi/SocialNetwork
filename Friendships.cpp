#include "Friendships.h"

namespace codesmith
{
	bool Friendships::areFriends(const Person& p1, const Person& p2) const
	{
		return areFriends(p1.getId(), p2.getId());
	}

	bool Friendships::areFriends(int p1_id, int p2_id) const
	{
		bool res = false;
		for (auto p : m_friendRelations) {
			if ((p1_id == p.m_id1 && p2_id == p.m_id2) ||
				(p1_id == p.m_id2 && p2_id == p.m_id1)) {
				res = true;
				break;
			}
		}
		return res;
	}

	std::vector<int> Friendships::getFriends(int id)
	{
		std::vector<int> friends;
		for (auto r : m_friendRelations) {
			if (r.m_id1 == id) {
				friends.push_back(r.m_id1);
			}
			else if (r.m_id2 == id) {
				friends.push_back(r.m_id2);
			}
		}
		return friends;
	}

	std::vector<int> Friendships::getFriends(const Person& person)
	{
		return getFriends(person.getId());
	}

	void Friendships::add(const Person& p1, const Person& p2)
	{
		if (!areFriends(p1, p2)) {
			m_friendRelations.push_back(FriendPair(p1.getId(), p2.getId()));
		}
	}

	void Friendships::add(int p1_id, int p2_id)
	{
		if (!areFriends(p1_id, p2_id)) {
			m_friendRelations.push_back(FriendPair(p1_id, p2_id));
		}
	}

	void Friendships::unfriend(int p1_id, int p2_id)
	{
		std::vector<Friendships::FriendPair>::iterator it = findFriendshipIterByPair(FriendPair(p1_id, p2_id));
		if (it != m_friendRelations.end()) {
			m_friendRelations.erase(it);
		}
	}
	
	void Friendships::unfriend(const Person& p1, const Person& p2)
	{
		unfriend(p1.getId(), p2.getId());
	}

	std::vector<Friendships::FriendPair>::iterator Friendships::findFriendshipIterByPair(const FriendPair& pair)
	{
		std::vector<FriendPair>::iterator it = m_friendRelations.begin();
		for (; it != m_friendRelations.end(); it++) {
			if (areFriends((*it).m_id1, (*it).m_id2)) {
				break;
			}
		}
		return it;
	}

}
