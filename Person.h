/*
 * Person.h
 *
 *  Created on: Nov 18, 2019
 *      Author: erno
 */

#ifndef PERSON_H
#define PERSON_H

#include <vector>
#include <string>
#include "Hobby.h"

namespace codesmith {
	
	/**
	* Class which encapsulates data and operations for a Person
	* Person describes one entity in social network. Persons have
	* friendship reations through Friendships class instance owned
	* by the SocialNetwork class.
	*/
	class Person
	{
	public: // Class constants/Enums
		// Gender enumeration
		enum class PersonGender : int {
			Male = 0,
			Female,
			Undefined
		};

		// Indicates that a certain attribute was undefined
		static const int AttributeUndefined = -1;

	public: // Construction
		Person(const std::string& name) :
			Person(AttributeUndefined, name, 
				AttributeUndefined, AttributeUndefined, 
				PersonGender::Undefined) { };
		Person(int id, const std::string& name) :
			Person(id, name, AttributeUndefined, AttributeUndefined, PersonGender::Undefined) { };
		Person(int id, const std::string& name, 
			int age, int height, 
			const PersonGender& gender) :
				m_id(id), m_name(name),
				m_hobbies(), m_age(age), m_height(height), m_gender(gender) { };
		virtual ~Person() { };

	public: // Operations
		int getId() const { return m_id; }
		const std::string& getName() const { return m_name; };
		std::vector<Hobby>& getHobbies() { return m_hobbies; }
		int getAge() const { return m_age; }
		int getHeight() const { return m_height; }
		const PersonGender getGender() const { return m_gender; }

		void setId(int id) { m_id = id; }
		void setName(const std::string& name) { m_name = name; }
		void setGender(const PersonGender& gender) { m_gender = gender; }
		void setAge(int age) { m_age = age; }
		void setHeight(int height) { m_height = height; }

		void addHobby(const Hobby& hobby);
		void addHobby(const std::string& hobbyName);
		void addHobbies(const std::vector<std::string> hobbyNames);

		void removeHobby(const Hobby& hobby);
		void removeHobby(const std::string& hobbyName);
		bool hasHobby(const std::string& hobbyName);
		bool hasHobby(const Hobby & hobby);
		bool hasAllHobbies(const std::vector<Hobby>& hobbies);
		bool hasAllHobbies(const std::vector<std::string>& hobbyNames);
		bool operator==(const Person& other);
		void operator=(const Person& other);

	private: // Operations
		// Default constructor is private because Name is always required
		Person() : Person("") { };

		/**
		* Get a iterator for a specific hobby
		* @param hobby hobby to be fetched
		* @return iterator to hobbies. If hobby not found iterator is at the end.
		*/
		std::vector<Hobby>::iterator getHobbyIter(const Hobby& hobby);

	private: // Data
		int m_id;
		std::string m_name;
		std::vector<Hobby> m_hobbies;
		PersonGender m_gender;
		int m_age;
		int m_height;
	};
}

#endif PERSON_H_
