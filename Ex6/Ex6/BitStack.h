#pragma once
#include <stdint.h>
// #include <stdlib.h>
#include <malloc.h>
class CBitStack
{
	uint8_t *m_data, *m_top, top_pointer;

public:
	CBitStack():m_data(nullptr), m_top(nullptr), top_pointer('\0') {}
	~CBitStack();
	void push(bool value);
	void pop();
	inline bool back() const
	{
		return top_pointer & *m_top;
	}
	inline bool empty() const
	{
		return !m_data;
	}
	inline bool notEmpty() const
	{
		return m_data;
	}
};

