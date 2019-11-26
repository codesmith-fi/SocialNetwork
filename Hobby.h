/* Created on : Nov 18, 2019
* Author : erno
*/

#ifndef HOBBY_H
#define HOBBY_H

#include <string>

namespace codesmith {
	class Hobby
	{
	public: // Construction
		Hobby() : m_hobby("") { };
		Hobby(const std::string hobby) :
			m_hobby(hobby) { };
		virtual ~Hobby() { };

	public: // Operations
		const std::string& getName() const { return m_hobby; }
		void setName(const std::string& name) { m_hobby = name; }
		bool operator==(const Hobby& other);
		void operator=(const Hobby& other);
	private: // Data
		std::string m_hobby;
	};
}

#endif PERSON_H_
