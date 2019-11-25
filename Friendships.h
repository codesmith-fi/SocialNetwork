/*
 * Friendships.h
 *
 *  Created on: Nov 18, 2019
 *      Author: erno
 */

#ifndef FRIENDSHIPS_H
#define FRIENDSHIPS_H

#include <map>
#include <memory>
#include "Person.h"

namespace codesmith {

	class Friendships
	{
	public: // Construction and accessor
		static Friendships& instance() {
			static Friendships m_friendRelations;
			return m_friendRelations;
		}

		Friendships() : m_friendRelations() {};
		virtual ~Friendships() {};

	public: // Operations
		void add(std::shared_ptr<Person> p1, std::shared_ptr<Person> p2);
		bool areFriends(const Person& p1, const Person& p2) const;
		void unfriend(const Person& p1, const Person& p2);
	private: // Operations


	private: // Data
		std::map < std::shared_ptr<Person>, std::shared_ptr<Person> > m_friendRelations;
	};
}

#endif FRIENDSHIPS_H_
