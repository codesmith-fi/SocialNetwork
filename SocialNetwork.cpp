#include "SocialNetwork.h"
#include "Friendships.h"
#include "PersonNotFoundException.h"

namespace codesmith {

	void SocialNetwork::clear()
	{
		m_friendships.clear();
		m_people.clear();
	}

	void SocialNetwork::addPerson(std::shared_ptr<Person> person)
	{
		if (!hasPerson((*person).getId())) {
			(*person).setId(++m_lastPersonId);
			m_people.push_back(person);
		}
	}

	void SocialNetwork::removePerson(int id)
	{
		std::vector<std::shared_ptr<Person>>::iterator it = 
			findPersonIterById(id);
		if (it != m_people.end()) {
			m_people.erase(it);
		}
	}

	std::vector<std::shared_ptr<Person>> SocialNetwork::searchPersonByAge(
		int age)
	{
		std::vector<std::shared_ptr<Person>> result;
		for (auto it = m_people.begin(); it != m_people.end(); ++it) {
			Person& person = *(*it);
			if (person.getAge() == age) {
				result.push_back(*it);
			}
		}
		return result;
	}

	std::vector<std::shared_ptr<Person>> SocialNetwork::searchPersonByName(const std::string& name)
	{
		std::vector<std::shared_ptr<Person>> result;
		for (auto it = m_people.begin(); it != m_people.end(); ++it) {
			Person& person = *(*it);
			if (person.getName() == name) {
				result.push_back(*it);
			}
		}

		return result;
	}

	std::vector<std::shared_ptr<Person>> SocialNetwork::searchPersonByHobbies(const std::vector<Hobby>& hobbies)
	{
		std::vector<std::shared_ptr<Person>> result;
		for (auto it = m_people.begin(); it != m_people.end(); ++it) {
			Person& person = *(*it);
			if (person.hasAllHobbies(hobbies)) {
				result.push_back(*it);
			}
		}

		return result;
	}

	std::vector<std::shared_ptr<Person>> SocialNetwork::searchPersonByHobbies(const std::vector<std::string>& hobbyNames)
	{
		std::vector<std::shared_ptr<Person>> result;
		for (auto it = m_people.begin(); it != m_people.end(); ++it) {
			Person& person = *(*it);
			if (person.hasAllHobbies(hobbyNames)) {
				result.push_back(*it);
			}
		}

		return result;
	}

	std::shared_ptr<Person> SocialNetwork::getPerson(int id)
	{
		std::vector<std::shared_ptr<Person>>::iterator it =
			findPersonIterById(id);
		if (it != m_people.end()) {
			return *it;
		}
		else {
			throw PersonNotFoundException(id);
		}
	}

	bool SocialNetwork::hasPerson(int id)
	{
		bool res = false;
		for(auto p : m_people) {
			if ((*p).getId() == id) {
				res = true;
				break;
			}
		}
		return res;
	}

	std::vector<int> SocialNetwork::getFriendsOfPerson(const Person& person)
	{
		return m_friendships.getFriends(person);
	}

	std::vector<std::shared_ptr<Person>>::iterator SocialNetwork::findPersonIterById(int id)
	{
		auto it = m_people.begin();
		for (; it != m_people.end(); it++) {
			Person& p = *(*it);
			if (p.getId() == id) {
				break;
			}
		}
		return it;
	}


}
