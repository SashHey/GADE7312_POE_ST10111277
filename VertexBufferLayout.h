#pragma once

#include <vector>
#include <GL/glew.h>
#include "Render.h"
#include <cassert>



struct VertexBufferElement
{
	unsigned int count;
	unsigned int type;
	unsigned char norm;

	static unsigned int GetSizeType(unsigned int type)
	{
		switch (type)
		{
		case GL_FLOAT:		   return 4;
		case GL_UNSIGNED_INT:  return 4;
		case GL_UNSIGNED_BYTE: return 1;
		}

		assert(false);
		return 0;
	}
};

class VertexBufferLayout
{
private:
	std::vector<VertexBufferElement> m_Element;
	unsigned int m_Stride;
public:
	VertexBufferLayout()
		: m_Stride(0){}

	template<typename T>
	void Push(unsigned int count)
	{
		assert(false);
	}

	template<>
	void Push<float>(unsigned int count)
	{
		m_Element.push_back({GL_FLOAT, count, GL_FALSE});
		m_Stride += count * VertexBufferElement::GetSizeType(GL_FLOAT);
	}

	template<>
	void Push<unsigned int>(unsigned int count)
	{
		m_Element.push_back({ GL_UNSIGNED_INT, count, GL_FALSE });
		m_Stride += count * VertexBufferElement::GetSizeType(GL_UNSIGNED_INT);
	}

	template<>
	void Push<unsigned char>(unsigned int count)
	{
		m_Element.push_back({ GL_UNSIGNED_BYTE, count, GL_TRUE });
		m_Stride += count * VertexBufferElement::GetSizeType(GL_UNSIGNED_BYTE);
	}

	inline const std::vector<VertexBufferElement> GetElements() const { return m_Element; }
	inline unsigned int GetStride() const { return m_Stride; }
};