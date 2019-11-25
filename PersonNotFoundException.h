/*
 * PersonNotFoundException.h
 *
 *  Created on: Nov 24, 2019
 *      Author: erno
 */

#ifndef PERSONNOTFOUNDEXCEPTION_H_
#define PERSONNOTFOUNDEXCEPTION_H_

#include <exception>
#include <string>

namespace codesmith {
	class PersonNotFoundException: public std::exception
	{
	public: // Methods
		PersonNotFoundException(int id) : m_requestedId(id) { };
		virtual ~PersonNotFoundException() { };
		virtual const char* what() const throw()
		{
			std::string msg = "Note with requested id not found, id: " + m_requestedId;
			return msg.c_str();
		}

		int getRequestedId() { return m_requestedId; }

	private: // data
		int m_requestedId;
	}; 

} // namespace codesmith

#endif // PERSONNOTFOUNDEXCEPTION_H_
