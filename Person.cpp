#include "Person.h"

namespace codesmith
{

bool Person::operator==(const Person& other)
{
	// Really naive implementation, checks only the name for equality
	// Should be updated to check other properties if needed, left for
	// "future expansion" :-)
	return(m_name == other.m_name);
}

void Person::operator=(const Person& other)
{
	m_id = other.m_id;
	m_name = other.m_name;
	m_age = other.m_age;
	m_height = other.m_height;
	m_gender = other.m_gender;
	m_hobbies = other.m_hobbies;
}

void Person::addHobby(const Hobby& hobby)
{
	// Hobby should be unique, no duplicates
	if (!hasHobby(hobby)) {
		m_hobbies.push_back(hobby);
	}
}

void Person::addHobby(const std::string& hobbyName)
{
	// Hobby should be unique, no duplicates
	if (!hasHobby(hobbyName)) {
		m_hobbies.push_back(Hobby(hobbyName));
	}
}

void Person::addHobbies(const std::vector<std::string> hobbyNames)
{
	for (auto n : hobbyNames) {
		addHobby(n);
	}
}

void Person::removeHobby(const std::string& hobbyName)
{
	Hobby tmp(hobbyName);
	removeHobby(tmp);
}

void Person::removeHobby(const Hobby& hobby)
{
	auto it = getHobbyIter(hobby);
	if (it != m_hobbies.end()) {
		m_hobbies.erase(it);
	}
}

bool Person::hasHobby(const std::string& hobbyName) 
{
	Hobby h(hobbyName); // temp hobby for searching
	if(hasHobby(h)) {
		return true;
	}
	else {
		return false;
	}
}

bool Person::hasHobby(const Hobby& hobby) 
{
	std::vector<Hobby>::iterator it = getHobbyIter(hobby);
	if (it != m_hobbies.end()) {
		return true;
	}
	else {
		return false;
	}
}

bool Person::hasAllHobbies(const std::vector<std::string>& hobbyNames) 
{
	bool res = true;
	for (auto n : hobbyNames) {
		if (!hasHobby(n)) {
			res = false;
			break;
		}
	}
	return res;
}

bool Person::hasAllHobbies(const std::vector<Hobby>& hobbies) 
{
	bool res = true;
	for(auto h : hobbies) {
		if(!hasHobby(h)) {
			res = false;
			break;
		}
	}
	return res;
}

std::vector<Hobby>::iterator Person::getHobbyIter(const Hobby& hobby)
{
	std::vector<Hobby>::iterator it = m_hobbies.begin();
	for (; it != m_hobbies.end(); it++) {
		if ((*it) == hobby) {
			break;
		}
	}
	return it;
}


} // namespace codesmith
