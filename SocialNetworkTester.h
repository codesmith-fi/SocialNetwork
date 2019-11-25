/*
 * SocialNetworkTester.h
 *
 *  Created on: Nov 18, 2019
 *      Author: erno
 */

#ifndef SOCIALNETWORKTESTER_H_
#define SOCIALNETWORKTESTER_H_

#include <string>
#include <memory>
#include "Person.h"
#include "SocialNetwork.h"

namespace codesmith {

/**
 * Simple "unit" test for Storyboard project classes
 * This runner class is a singleton and contains operations to run tests cases
 * and get the success and failure counts after running
 */
class SocialNetworkTester {
	public: // Singleton accessor
		static SocialNetworkTester& instance() {
			static SocialNetworkTester tester;
			return tester;
		}

	private: //
		SocialNetworkTester() : m_testFailCount(0), m_testSuccessCount(0), m_network() { };

	public: // helpers
		int FailCount() { return m_testFailCount; };
		int SuccessCount() { return m_testSuccessCount; };
		void TestFailure(const std::string& description);
		void TestSuccess(const std::string& description);
		void AssertCondition(bool condition, const std::string& testMessage);

	public: // Test runners
		void RunAll();
		void RunHobbyTests(bool resetCount = false);
		void RunPersonTests(bool resetCount = false);
		void RunFriendshipTests(bool resetCount = false);
		void RunSocialNetworkTests(bool resetCount = false);

		// Hobby test cases
		void TestHobbyNewInstance();
		void TestHobbyEqualOperator();
		void TestHobbyAssignmentOperator();
		void TestHobbySetGetName();

		// Person test cases
		void TestPersonNewInstance();
		void TestPersonAssignmentOperation();
		void TestPersonEqualOperation();
		void TestPersonHobbies();
		void TestPersonPropertyGettersAndSetters();

		// Friendships test cases
		void TestFriendshipsNewInstance();
		void TestFriendshipsClearAndSize();
		void TestFriendshipsAddAndAreFriends();
		void TestFriendshipsUnfriend();
		void TestFriendshipsGetFriends();

		// SocialNetwork test cases
		void TestSocialNetworkNewInstance();
		void TestSocialNetworkAddRemovePerson();
		void TestSocialNetworkSearchPersonByAge();
		void TestSocialNetworkSearchPersonByName();
		void TestSocialNetworkSearchPersonByHobbies();
		void TestSocialNetworkManageFriendships();

	private: // Setup methods for test cases
		void setupSocialNetwork();
	private: // Data
		int m_testFailCount;
		int m_testSuccessCount;

		SocialNetwork m_network;
		std::shared_ptr<Person> m_person1;
		std::shared_ptr<Person> m_person2;
};


} /* namespace codesmith */

#endif // SOCIALNETWORKTESTER_H_

