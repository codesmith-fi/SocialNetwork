/*
 * StoryboardTester.cpp
 *
 *  Created on: Nov 18, 2019
 *      Author: erno
 */

#include "SocialNetworkTester.h"
#include "DebugLogger.h"

#include "Hobby.h"
#include "Person.h"
#include "Friendships.h"
#include "SocialNetwork.h"
#include "PersonNotFoundException.h"

namespace codesmith {

// Test constants
const std::string constHobbyName1 = "Programming";
const std::string constHobbyName2 = "Karaoke";
const std::string constHobbyName3 = "Robbing elderly people";
const std::string constPersonName1 = "John Doe";
const std::string constPersonName2 = "Jane Doe";
const std::string constPersonName3 = "Isaac Newton";
const int constPersonId1 = 42;
const int constPersonId2 = 1001;
const int constPersonAge1 = 24;
const int constPersonAge2 = 18;
const int constPersonAge3_not_exist = 100;
const int constPersonHeight1 = 176;

void SocialNetworkTester::RunAll()
{
	LOG_INFO() << "Unit tests for SocialNetwork project";
	m_testFailCount = 0;
	m_testSuccessCount = 0;
	RunHobbyTests();
	std::cout << std::endl;
	RunPersonTests();
	std::cout << std::endl;
	RunFriendshipTests();
	std::cout << std::endl;
	RunSocialNetworkTests();
	std::cout << std::endl;
}

void SocialNetworkTester::RunHobbyTests(bool resetCount)
{
	LOG_INFO() << "Running all Hobby class test cases";
	TestHobbyNewInstance();
	TestHobbyEqualOperator();
	TestHobbyAssignmentOperator();
	TestHobbySetGetName();
}

void SocialNetworkTester::RunPersonTests(bool resetCount)
{
	LOG_INFO() << "Running all Person class test cases";
	TestPersonNewInstance();
	TestPersonAssignmentOperation();
	TestPersonEqualOperation();
	TestPersonHobbies();
	TestPersonPropertyGettersAndSetters();
}

void SocialNetworkTester::RunFriendshipTests(bool resetCount)
{
	LOG_INFO() << "Running all Friendships class test cases";
	TestFriendshipsNewInstance();
	TestFriendshipsClearAndSize();
	TestFriendshipsAddAndAreFriends();
	TestFriendshipsUnfriend();
	TestFriendshipsGetFriends();
}

void SocialNetworkTester::RunSocialNetworkTests(bool resetCount)
{
	LOG_INFO() << "Running all SocialNetwork class test cases";
	TestSocialNetworkAddRemovePerson();
	TestSocialNetworkSearchPersonByAge();
	TestSocialNetworkSearchPersonByName();
	TestSocialNetworkSearchPersonByHobbies();
	TestSocialNetworkManageFriendships();
}

/**
* Hobby test case implementation
*/
void SocialNetworkTester::TestHobbyNewInstance()
{
	LOG_INFO() << "TestHobbyNewInstance() enter";

	Hobby h1;
	Hobby h2(constHobbyName1);

	AssertCondition(h1.getName().empty(), "Hobby h1 should have an empty name");
	AssertCondition(!h2.getName().empty(), "Hobby h2 should not have an empty name");
	AssertCondition(h2.getName() == constHobbyName1, "Hobby h2 should have a correct name");
	LOG_INFO() << "TestHobbyNewInstance() exit";
}

void SocialNetworkTester::TestHobbyEqualOperator()
{
	LOG_INFO() << "TestHobbyEqualOperator() enter";
	Hobby h1(constHobbyName1);
	Hobby h2(constHobbyName2);
	Hobby h3(constHobbyName1);

	AssertCondition(!(h1 == h2), "Hobby h1 and h2 should not be equal");
	AssertCondition(h1 == h3, "Hobby h1 and h3 should be equal");
	LOG_INFO() << "TestHobbyEqualOperator() exit";

}

void SocialNetworkTester::TestHobbyAssignmentOperator()
{
	LOG_INFO() << "TestHobbyAssignmentOperator() enter";
	Hobby h1(constHobbyName1);
	Hobby h2;
	AssertCondition(!(h1 == h2), "Hobby h1 and h2 should not be equal at this point");
	h2 = h1;
	AssertCondition(h1 == h2, "Hobby h1 and h2 should be equal after assignment");

	LOG_INFO() << "TestHobbyAssignmentOperator() exit";
}

void SocialNetworkTester::TestHobbySetGetName()
{
	LOG_INFO() << "TestSetGetName() enter";
	Hobby h1(constHobbyName1);
	AssertCondition(h1.getName() == constHobbyName1, 
		"Hobby should have a correct name after initialization");
	h1.setName(constHobbyName2);
	AssertCondition(h1.getName() == constHobbyName2, "Hobby should have a correct name after setName()");
	LOG_INFO() << "TestSetGetName() exit";
}

/**
 * Person test cases
 */
void SocialNetworkTester::TestPersonNewInstance()
{
	LOG_INFO() << "TestPersonNewInstance() enter";
	Person p1(constPersonName1);
	AssertCondition(p1.getId() == Person::AttributeUndefined, "Person p1 id should be undefined");
	AssertCondition(p1.getName() == constPersonName1, "Person p1 should have a correct name after instantiation");
	AssertCondition(p1.getAge() == Person::AttributeUndefined, "Person p1 Age should be undefined");
	AssertCondition(p1.getHeight() == Person::AttributeUndefined, "Person p1 height should be undefined");
	AssertCondition(p1.getHobbies().size() == 0, "Person p1 should have no hobbies");
	AssertCondition(p1.getGender() == Person::PersonGender::Undefined, "Person p1 gender should be undefined");

	Person p2(constPersonId1, constPersonName2);
	AssertCondition(p2.getId() == constPersonId1, "Person p2 id should correct");
	AssertCondition(p2.getName() == constPersonName2, "Person p2 should have a correct name after instantiation");
	AssertCondition(p2.getAge() == Person::AttributeUndefined, "Person p2 Age should be undefined");
	AssertCondition(p2.getHeight() == Person::AttributeUndefined, "Person p2 Height should be undefined");
	AssertCondition(p2.getHobbies().size() == 0, "Person p2 should have no hobbies");
	AssertCondition(p2.getGender() == Person::PersonGender::Undefined, "Person p2 gender should be undefined");

	Person p3(constPersonId2, constPersonName2, constPersonAge1, constPersonHeight1, Person::PersonGender::Female);
	AssertCondition(p3.getId() == constPersonId2, "Person p3 id should correct");
	AssertCondition(p3.getName() == constPersonName2, "Person p3 should have a correct name after instantiation");
	AssertCondition(p3.getAge() == constPersonAge1, "Person p3 Age should be correct");
	AssertCondition(p3.getHeight() == constPersonHeight1, "Person p3 Height should be correct");
	AssertCondition(p3.getHobbies().size() == 0, "Person p3 should have no hobbies");
	AssertCondition(p3.getGender() == Person::PersonGender::Female, "Person p3 gender should be Female");

	LOG_INFO() << "TestPersonNewInstance() exit";
}

void SocialNetworkTester::TestPersonAssignmentOperation()
{
	LOG_INFO() << "TestPersonAssignmentOperation() enter";
	Person p1(constPersonId1, constPersonName1);
	AssertCondition(p1.getName() == constPersonName1, "Person p1 should have a correct name before assignment");
	Person p2(constPersonId2, constPersonName2);
	p1 = p2;
	AssertCondition(p1.getName() == constPersonName2, "Person p1 should have a correct name after assignment");
	LOG_INFO() << "TestPersonAssignmentOperation() exit";
}

void SocialNetworkTester::TestPersonEqualOperation()
{
	LOG_INFO() << "TestPersonEqualOperation() enter";
	Person p1(constPersonId1, constPersonName1);
	Person p2(constPersonId2, constPersonName2);
	Person p3(constPersonId1, constPersonName1);
	AssertCondition(p1 == p3, "Person p1 and p3 should be equal");
	AssertCondition(!(p1 == p2), "Person p1 and p2 should not be equal");
	LOG_INFO() << "TestPersonEqualOperation() exit";
}

void SocialNetworkTester::TestPersonHobbies() 
{
	LOG_INFO() << "TestPersonHobbies() enter";
	Person p1(constPersonName1);
	AssertCondition(p1.getHobbies().size() == 0, "Person p1 should have no hobbies yet");
	Hobby h1(constHobbyName1);
	Hobby h2(constHobbyName2);
	Hobby h3(constHobbyName3);
	p1.addHobby(h1); // add new hobby by Hobby value
	p1.addHobby(constHobbyName2); // Add a new hobby by string value
	AssertCondition(p1.getHobbies().size() == 2, "Person p1 should have two hobbies");

	// Tests for checking single hobby by Hobby instance and by name string
	AssertCondition(p1.hasHobby(h1), "Person should have a hobby: Programming");
	AssertCondition(p1.hasHobby(h1.getName()), "String value test: Person should have a hobby: Programming");
	AssertCondition(p1.hasHobby(h2), "Person should have a hobby: Karaoke");
	AssertCondition(p1.hasHobby(h1.getName()), "String value test: Person should have a hobby: Karaoke");
	AssertCondition(!p1.hasHobby(h3), "Person should not have a hobby: Robbing elderly people");
	AssertCondition(!p1.hasHobby(h3.getName()), "String value test: Person should not have a hobby: Robbing elderly people");

	// Tests for verifying a list of hobbies
	std::vector<Hobby> hobbies({ constHobbyName1, constHobbyName2 });
	AssertCondition(p1.hasAllHobbies(hobbies), "Person should have all hobbies: Programming, Karaoke");
	std::vector<std::string> hobbyNames({constHobbyName1, constHobbyName2});
	AssertCondition(p1.hasAllHobbies(hobbyNames), "Person should have all hobbies: Programming, Karaoke");
	std::vector<Hobby> hobbiesFail({ constHobbyName1, constHobbyName2, constHobbyName3 });
	AssertCondition(!p1.hasAllHobbies(hobbiesFail), "Person should not have all hobbies: Programming, Karaoke, Robbin elderly people");

	// Test for removing hobbies
	p1.removeHobby(constHobbyName1); // Remove the first hobby, by string value
	AssertCondition(p1.getHobbies().size() == 1, "Person p1 should have one hobby after removing one");
	AssertCondition(!p1.hasHobby(h1), "Person should not have a hobby anymore: Programming");
	AssertCondition(p1.hasHobby(h2), "Person should still have a hobby anymore: Karaoke");
	p1.removeHobby(h2); // remove the last remaining hobby, by Hobby value
	AssertCondition(p1.getHobbies().size() == 0, "Person p1 should have no hobbies");

	LOG_INFO() << "TestPersonHobbies() exit";
}

void SocialNetworkTester::TestPersonPropertyGettersAndSetters()
{
	LOG_INFO() << "TestPersonPropertyGettersAndSetters() enter";
	Person p(constPersonName3);
	p.setId(constPersonId1);
	p.setName(constPersonName1);
	p.setAge(constPersonAge1);
	p.setGender(Person::PersonGender::Male);
	p.setHeight(constPersonHeight1);
	AssertCondition(p.getId() == constPersonId1, "Id should be correct after setId()");
	AssertCondition(p.getName() == constPersonName1, "Name should be correct after setName()");
	AssertCondition(p.getAge() == constPersonAge1, "Age should be correct after setAge()");
	AssertCondition(p.getGender() == Person::PersonGender::Male, "Gender should be correct after setGender()");
	AssertCondition(p.getHeight() == constPersonHeight1, "Height should be correct after setHeight()");

	LOG_INFO() << "TestPersonPropertyGettersAndSetters() exit";
}

/**
 * Friendships test cases
 */
void SocialNetworkTester::TestFriendshipsNewInstance()
{
	LOG_INFO() << "TestFriendshipsNewInstance() enter";
	Friendships f;
	AssertCondition(f.size() == 0, "New friendships instance should not have any friendships");
	LOG_INFO() << "TestFriendshipsNewInstance() enter";
}

void SocialNetworkTester::TestFriendshipsClearAndSize()
{
	LOG_INFO() << "TestFriendshipsClearAndSize() enter";
	Friendships f;
	for (int i = 0; i < 10; ++i) {
		f.add(i, i+100);
	}
	AssertCondition(f.size() == 10, "There should be 10 friend relations");
	f.clear();
	AssertCondition(f.size() == 0, "Friendships should not have any friendships after clear()");
	LOG_INFO() << "TestFriendshipsClearAndSize() enter";
}

void SocialNetworkTester::TestFriendshipsAddAndAreFriends()
{
	LOG_INFO() <<"TestFriendshipsAddAndAreFriends() enter";
	Friendships f;
	for(int i = 0; i < 10; ++i) {
		f.add(i, i + 100);
	}
	AssertCondition(f.size() == 10, "There should be 10 friendship relations");

	std::ostringstream buf;
	for (int i = 0; i < 10; ++i) {
		buf.str("");
		buf << "Person with id " << i << " should be a friend with person with id " << i+100;
		AssertCondition(f.areFriends(i, i + 100), buf.str());
		buf.str("");
		// reverse id's should also work
		buf << "(reverse order) Person with id " << i+100 << " should be a friend with person with id " << i;
		AssertCondition(f.areFriends(i + 100, i), buf.str());
	}

	for (int i = 0; i < 10; ++i) {
		buf.str("");
		// reverse id's should also work
		buf << "Person with id " << i << " should not be a friend with person with id " << i+200;
		AssertCondition(!f.areFriends(i, i+200), buf.str());
	}

	// Try to add a duplicate friendship
	f.add(0, 100);
	AssertCondition(f.size() == 10, "There should be 10 friendship relations after trying to add a duplicate entry");

	LOG_INFO() <<"TestFriendshipsAddAndAreFriends() enter";
}


void SocialNetworkTester::TestFriendshipsUnfriend()
{
	LOG_INFO() << "TestFriendshipsUnfriend() enter";
	Friendships f;
	for (int i = 0; i < 10; ++i) {
		f.add(i, i + 100);
	}

	AssertCondition(f.size() == 10, "There should be 10 friendship connections");
	AssertCondition(f.getFriends(0).size()==1, "Person 0 should have one connection (100)");

	LOG_INFO() << "Removing frienship connection between 0 and 100";
	f.unfriend(0, 100);
	AssertCondition(f.size() == 9, "There should be 9 friendship connections");
	AssertCondition(f.getFriends(0).size()==0, "Person 0 should have no friend connections");

	LOG_INFO() << "Removing frienship connection between 4 and 104";
	f.unfriend(0, 100);
	AssertCondition(f.size() == 8, "There should be 8 friendship connections");
	AssertCondition(!f.getFriends(4).size()==0, "Person 4 should have no friend connections");
	
	LOG_INFO() << "TestFriendshipsUnfriend() enter";
}

void SocialNetworkTester::TestFriendshipsGetFriends()
{
	LOG_INFO() << "TestFriendshipsGetFriends() enter";
	Friendships f;
	for (int i = 0; i < 10; ++i) {
		f.add(i, i + 100);
	}
	AssertCondition(f.size() == 10, "There should be 10 friendship connections");
	AssertCondition(f.areFriends(0, 100), "Person should have one connection");

	// Should return only one friend for each id
	for (int i = 0; i < 10; ++i) {
		std::ostringstream buf;
		buf << "Person with id " << i << " should only have one friend connection";
		AssertCondition(f.getFriends(i).size() == 1, buf.str());
	}

	LOG_INFO() << "Adding 3 more connections for person with id 0";
	f.add(0, 1);
	f.add(0, 2);
	f.add(3, 0);
	AssertCondition(f.getFriends(0).size() == 4, "There should now be 4 friend connections for Person with id 0");
	// Ensure that other connections are not changed
	AssertCondition(f.getFriends(1).size() == 2, "There should be 2 friend connections for Person with id 1");
	AssertCondition(f.getFriends(2).size() == 2, "There should be 2 friend connections for Person with id 2");
	AssertCondition(f.getFriends(3).size() == 2, "There should be 2 friend connections for Person with id 3");

	LOG_INFO() << "TestFriendshipsGetFriends() enter";
}

/**
 * Social Network test case implementation
 */
void SocialNetworkTester::TestSocialNetworkNewInstance()
{
	LOG_INFO() << "TestSocialNetworkNewInstance() enter";
	SocialNetwork s;
	AssertCondition(s.size() == 0, "There should not be people after new instance");
	LOG_INFO() << "TestSocialNetworkNewInstance() exit";
}

void SocialNetworkTester::TestSocialNetworkAddRemovePerson()
{
	LOG_INFO() << "TestSocialNetworkAddRemovePerson() enter";
	setupSocialNetwork();

	std::shared_ptr<Person> p1_get(m_network.getPerson((*m_person1).getId()));
	std::shared_ptr<Person> p2_get(m_network.getPerson((*m_person2).getId()));

	AssertCondition((*p1_get).getName() == constPersonName1, "Person p1 should exist and have a correct name");
	AssertCondition((*p2_get).getName() == constPersonName2, "Person p2 should exist and have a correct name");

	m_network.removePerson((*m_person1).getId());
	AssertCondition(m_network.size() == 1, "There should be only one person after removePerson()");
	bool foundFlag = true;
	try {
		std::shared_ptr<Person> p1_get_shouldNotExist(m_network.getPerson((*m_person1).getId()));
	}
	catch (const PersonNotFoundException& e) {
		foundFlag = false;
		AssertCondition(e.getRequestedId() == (*m_person1).getId(), 
			"PersonNotFoundExceptione exception should occur and the id should be correct with getRequestedId()");
	}
	AssertCondition(!foundFlag, "PersonNotFoundException should occur when trying to find not existing person");

	m_network.removePerson((*m_person2).getId());
	AssertCondition(m_network.size() == 0, "There should not be people after removing the last entry");

	LOG_INFO() << "TestSocialNetworkAddRemovePerson() exit";
}

void SocialNetworkTester::TestSocialNetworkSearchPersonByAge()
{
	LOG_INFO() << "TestSocialNetworkSearchPersonByAge() enter";
	setupSocialNetwork();
	std::vector<std::shared_ptr<Person>> res1(m_network.searchPersonByAge(constPersonAge1));
	AssertCondition(res1.size() == 1, "SearchPersonByAge should return one match for age 24");
	AssertCondition((*res1[0]).getName() == constPersonName1, "Name for the person found should be correct");
	std::vector<std::shared_ptr<Person>> res2(m_network.searchPersonByAge(constPersonAge2));
	AssertCondition(res2.size() == 1, "SearchPersonByAge should return one match for age 18");
	AssertCondition((*res2[0]).getName() == constPersonName2, "Name for the person found should be correct");

	std::vector<std::shared_ptr<Person>> res3(m_network.searchPersonByAge(constPersonAge3_not_exist));
	AssertCondition(res3.size() == 0, "SearchPersonByAge should not return matches for age 100 ");

	LOG_INFO() << "Adding 10 more persons with name Jane Doe and age of 18";
	for (int i = 0; i < 10; i++) {
		m_network.addPerson(std::shared_ptr<Person>(
			new Person(-1, constPersonName2, constPersonAge2, -1, Person::PersonGender::Female)));
	}
	AssertCondition(m_network.size() == 12, "Network should now contain 12 persons");
	std::vector<std::shared_ptr<Person>> res4(m_network.searchPersonByAge(constPersonAge2));
	AssertCondition(res3.size() == 0, "SearchPersonByAge should return 11 matches for age 18");


	LOG_INFO() << "TestSocialNetworkSearchPersonByAge() exit";
}

void SocialNetworkTester::TestSocialNetworkSearchPersonByName()
{
	LOG_INFO() << "TestSocialNetworkSearchPersonByName() enter";
	setupSocialNetwork();
	std::vector<std::shared_ptr<Person>> res1(m_network.searchPersonByName(constPersonName1));
	AssertCondition(res1.size() == 1, "SearchPersonByName should return one match for name: John Doe");

	std::vector<std::shared_ptr<Person>> res2(m_network.searchPersonByName(constPersonName2));
	AssertCondition(res2.size() == 1, "SearchPersonByName should return one match for name: Jane Doe");

	std::vector<std::shared_ptr<Person>> res3(m_network.searchPersonByName(constPersonName3));
	AssertCondition(res3.size() == 0, "SearchPersonByName should not return a match for name: Isaac Newton");

	// And few more entries with duplicate name
	LOG_INFO() << "Adding 9 more persons with name Jane Doe";
	for (int i = 0; i < 9; i++) {
		m_network.addPerson(std::shared_ptr<Person>(new Person(constPersonName2)));
	}
	AssertCondition(m_network.size() == 11, "Network should now contain 11 persons");
	std::vector<std::shared_ptr<Person>> res4(m_network.searchPersonByName(constPersonName2));
	AssertCondition(res4.size() == 10, "SearchPersonByName should return ten matches for name Jane Doe");

	LOG_INFO() << "TestSocialNetworkSearchPersonByName() exit";
}

void SocialNetworkTester::TestSocialNetworkSearchPersonByHobbies()
{
	LOG_INFO() << "TestSocialNetworkSearchPersonByHobbies() enter";
	setupSocialNetwork();

	std::vector<std::string> hobbies1({ constHobbyName1, constHobbyName2 });
	std::vector<std::string> hobbies2({ constHobbyName1, constHobbyName3 });
	std::vector<std::string> hobbies3({ constHobbyName1, constHobbyName3, "Intelligent discussion" });

	std::vector<std::shared_ptr<Person>> res1(m_network.searchPersonByHobbies(hobbies1));
	AssertCondition(res1.size() == 1, "SearchPersonByHobbies should return one match for: Programming and Karaoke");

	std::vector<std::shared_ptr<Person>> res2(m_network.searchPersonByHobbies(hobbies2));
	AssertCondition(res1.size() == 1, "SearchPersonByHobbies should return one match for: Programming and Robbing elderly people");

	std::vector<std::shared_ptr<Person>> res3(m_network.searchPersonByHobbies(hobbies3));
	AssertCondition(res3.size() == 0, "SearchPersonByHobbies should not return matches for: Programming, Robbing elderly people and Intelligent discussion");
	
	LOG_INFO() << "TestSocialNetworkSearchPersonByHobbies() exit";
}

void SocialNetworkTester::TestSocialNetworkManageFriendships()
{
	LOG_INFO() << "TestSocialNetworkManageFriendships() enter";
	SocialNetwork n;
	for (int i = 0; i < 10; ++i) {
		std::string name = "Person " + i;
		std::shared_ptr<Person> person(new Person(name));
		n.addPerson(person);
		AssertCondition((*person).getId() == i, "Id should be correct after adding person to SocialNetwork");
	}

	Friendships friendships = n.getFriendships();
	AssertCondition(friendships.size() == 0, "There should not be friend connections yet");
	
	// Add connections
	friendships.add((*n.getPerson(0)).getId(), (*n.getPerson(5)).getId());
	friendships.add((*n.getPerson(0)).getId(), (*n.getPerson(6)).getId());
	friendships.add((*n.getPerson(0)).getId(), (*n.getPerson(7)).getId());
	friendships.add((*n.getPerson(0)).getId(), (*n.getPerson(8)).getId());
	friendships.add((*n.getPerson(0)).getId(), (*n.getPerson(9)).getId());

	AssertCondition(friendships.getFriends(0).size() == 5, "Person 0 should have 5 friends");
	AssertCondition(friendships.getFriends(1).size() == 0, "Person 1 should have 0 friends");
	AssertCondition(friendships.areFriends(0, 5), "Person 0 should be a friend with person 5");
	AssertCondition(friendships.areFriends(0, 6), "Person 0 should be a friend with person 6");
	AssertCondition(friendships.areFriends(0, 7), "Person 0 should be a friend with person 7");
	AssertCondition(friendships.areFriends(0, 8), "Person 0 should be a friend with person 8");
	AssertCondition(friendships.areFriends(0, 9), "Person 0 should be a friend with person 9");

	LOG_INFO() << "TestSocialNetworkManageFriendships() exit";
}

/**
 * Helper method implementation
 */
void SocialNetworkTester::setupSocialNetwork()
{
	m_network.clear();

	std::vector<std::string> hobbies1({ constHobbyName1, constHobbyName2 });
	std::vector<std::string> hobbies2({ constHobbyName1, constHobbyName3 });
	m_person1 = std::shared_ptr<Person>(
		new Person(-1, constPersonName1, constPersonAge1, constPersonHeight1, Person::PersonGender::Male));
	(*m_person1).addHobbies(hobbies1);
	m_person2 = std::shared_ptr<Person>(
		new Person(-1, constPersonName2, constPersonAge2, constPersonHeight1, Person::PersonGender::Female));
	(*m_person2).addHobbies(hobbies2);
	m_network.addPerson(m_person1);
	m_network.addPerson(m_person2);
	AssertCondition((*m_person1).getId() != (*m_person2).getId(), 
		"Persons m_person1 and m_person2 should have a unique id after adding to SocialNetwork");
}

void SocialNetworkTester::TestFailure(const std::string& description)
{
	m_testFailCount++;
	std::string msg("Failure: " + description);
	LOG_ERROR() << msg;
}

void SocialNetworkTester::TestSuccess(const std::string& description)
{
	m_testSuccessCount++;
	std::string msg("Success: " + description);
	LOG_INFO() << msg;
}

void SocialNetworkTester::AssertCondition(bool condition, const std::string& testMessage)
{
	if(condition) {
		TestSuccess(testMessage);
	} else {
		TestFailure(testMessage);
	}
}


} // namespace codesmith

