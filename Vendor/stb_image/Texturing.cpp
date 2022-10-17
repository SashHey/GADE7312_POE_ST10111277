#include "Texturing.h"
#include "Vendor/stb_image/stb_image.h"

Texturing::Texturing(const std::string& path) 
	: m_RenderID(0), m_FilePath(path), m_LocalBuffer(nullptr), m_Width(0), m_Height(0), m_BPP(0)
{
	stbi_set_flip_vertically_on_load(1);
	m_LocalBuffer = stbi_load(path.c_str(), &m_Width, &m_Height, &m_BPP, 4);

	GLCall(glGenTextures(1, &m_RenderID));
	GLCall(glBindTextures(GL_TEXTURE_2D, m_RenderID));
	GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
	GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
	GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP));
	GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP));
	GLCall(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, ))
}

Texturing::~Texturing()
{

}

void Texturing::Bind(unsigned int slot /*= 0*/) const
{

}

void Texturing::Unbind() const
{

}