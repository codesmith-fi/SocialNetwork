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
}

void SocialNetworkTester::RunSocialNetworkTests(bool resetCount)
{
	LOG_INFO() << "Running all SocialNetwork class test cases";
	TestSocialNetworkAddRemovePerson();
	TestSocialNetworkSearchUserByAge();
	TestSocialNetworkSearchUserByName();
	TestSocialNetworkSearchUserByHobbies();
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
	SocialNetwork s;
	std::shared_ptr<Person> p1 = std::shared_ptr <Person>(new Person(constPersonName1));
	std::shared_ptr<Person> p2 = std::shared_ptr <Person>(new Person(constPersonName2));
	std::shared_ptr<Person> p3 = std::shared_ptr <Person>(new Person(constPersonName3));
	s.addPerson(p1);
	s.addPerson(p2);
	AssertCondition((*p1).getId() != (*p2).getId(), "Persons should have unique ids after adding to SocialNetwork");

	std::shared_ptr<Person> p1_get(s.getPerson((*p1).getId()));
	std::shared_ptr<Person> p1_get(s.getPerson((*p1).getId()));

	LOG_INFO() << "TestSocialNetworkAddRemovePerson() exit";
}

void SocialNetworkTester::TestSocialNetworkSearchUserByAge()
{
	LOG_INFO() << "TestSocialNetworkSearchUserByAge() enter";
	LOG_INFO() << "TestSocialNetworkSearchUserByAge() exit";
}

void SocialNetworkTester::TestSocialNetworkSearchUserByName()
{
	LOG_INFO() << "TestSocialNetworkSearchUserByName() enter";
	LOG_INFO() << "TestSocialNetworkSearchUserByName() exit";
}

void SocialNetworkTester::TestSocialNetworkSearchUserByHobbies()
{
	LOG_INFO() << "TestSocialNetworkSearchUserByHobbies() enter";
	LOG_INFO() << "TestSocialNetworkSearchUserByHobbies() exit";
}



/**
 * Helper method implementation
 */
void SocialNetworkTester::TestFailure(const std::string& description)
{
	m_testFailCount++;
	std::string msg("Failure testing: " + description);
	LOG_ERROR() << msg;
}

void SocialNetworkTester::TestSuccess(const std::string& description)
{
	m_testSuccessCount++;
	std::string msg("Success testing: " + description);
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

