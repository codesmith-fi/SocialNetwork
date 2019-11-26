/*
 * Friendships.h
 *
 *  Created on: Nov 18, 2019
 *      Author: erno
 */

#ifndef FRIENDSHIPS_H
#define FRIENDSHIPS_H

#include <vector>
#include "Person.h"

namespace codesmith {
	/**
	* A class to hold friend relations between two Persons
	* Only Ids of persons are kept here
	*/
	class Friendships
	{
		// Simple class to hold a pair of person ids to indicate if they are friends
		class FriendPair
		{
		public:
			FriendPair(int id1, int id2) : m_id1(id1), m_id2(id2) { };
			bool operator==(const FriendPair& other);
			bool operator!=(const FriendPair& other);
			int m_id1;
			int m_id2;
		};

	public: // Construction
		Friendships() : m_friendRelations() {};
		virtual ~Friendships() {};

	public: // Operations
		size_t size() { return m_friendRelations.size(); }
		void clear() { m_friendRelations.clear(); }
		void add(const Person& p1, const Person& p2);
		void add(int p1_id, int p2_id);
		bool areFriends(const Person& p1, const Person& p2) const;
		bool areFriends(int p1_id, int p2_id) const;
		void unfriend(const Person& p1, const Person& p2);
		void unfriend(int p1_id, int p2_id);
		std::vector<int> getFriends(const Person& person);
		std::vector<int> getFriends(int id);
	private: // Operations
		std::vector<FriendPair>::iterator findFriendshipIterByPair(const FriendPair& pair);

	private: // Data
		std::vector<FriendPair> m_friendRelations;
	};
}

#endif FRIENDSHIPS_H_
