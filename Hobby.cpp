#include "Hobby.h"

namespace codesmith
{
	bool Hobby::operator==(const Hobby& other)
	{
		return m_hobby == other.m_hobby;
	}

	void Hobby::operator=(const Hobby& other)
	{
		m_hobby = other.m_hobby;
	}
}