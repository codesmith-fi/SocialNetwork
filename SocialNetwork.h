/*
 * SocialNetwork.h
 *
 *  Created on: Nov 18, 2019
 *      Author: erno
 */

#ifndef SOCIALNETWORK_H_
#define SOCIALNETWORK_H_

#include <memory>
#include <vector>
#include "Friendships.h"
#include "Person.h"
#include "Hobby.h"

namespace codesmith {

	class SocialNetwork
	{
	public: // Construction
		SocialNetwork() : m_people(), m_lastPersonId(-1), m_friendships() { };
		virtual ~SocialNetwork() { };

	public: // New methods
		/**
		* @return Person count in this SocialNetwork
		*/
		size_t size() const { return m_people.size(); }

		/**
		* Clear the whole network and friendships
		*/
		void clear();

		/**
		* Add a person to the SocialNetwork
		* @param person A pointer to the person to be added
		*/
		void addPerson(std::shared_ptr<Person> person);

		/**
		* Remove a person from the SocialNetwork
		* Does nothing if the person is not to be found
		* @param person Person to be removed
		*/
		void removePerson(int id);

		/**
		* Search people by a specified Age
		* @param age age of the person to be searched for
		* @return array of Person pointers, contains zero or more entries
		*/
		std::vector<std::shared_ptr<Person>> searchPersonByAge(int age);

		/**
		* Search people by a specified name
		* @param name Name of the person to be searched for
		* @return array of Person pointers, contains zero or more entries
		*/
		std::vector<std::shared_ptr<Person>> searchPersonByName(const std::string& name);

		/**
		* Search people by a specified list of hobbies, all much match
		* @param hobbies List of hobbies to be searched for
		* @return array of Person pointers, contains zero or more entries
		*/
		std::vector<std::shared_ptr<Person>> searchPersonByHobbies(const std::vector<Hobby>& hobbies);

		/**
		* Search people by a specified list of hobbies, all much match
		* @param hobbies List of hobby names
		* @return array of Person pointers, contains zero or more entries
		*/
		std::vector<std::shared_ptr<Person>> searchPersonByHobbies(const std::vector<std::string>& hobbyNames);

		/**
		* Check if the SocialNetwork has a person with the given id
		* @param id id of the person to be verified
		* @return true if person exists, otherwise false
		*/
		bool hasPerson(int id);

		/**
		* Get a person with given id
		* @param id id of the person
		* @return a pointer to the person
		* @throws PersonNotFoundException if the person was not found
		*/
		std::shared_ptr<Person> getPerson(int id);

		/**
		* Get friends for a specific Person
		* @return a list of friend ids, contains 0 or more entries
		*/
		std::vector<int> getFriendsOfPerson(const Person& person);

		/**
		* @return all friend relations as a Friendships class instance
		*/
		Friendships& getFriendships() { return m_friendships; }

	private:
		std::vector<std::shared_ptr<Person>>::iterator findPersonIterById(int id);
	
	private: // Data
		std::vector < std::shared_ptr<Person> > m_people;
		Friendships m_friendships;
		int m_lastPersonId;
	};
}

#endif // SOCIALNETWORK_H_

