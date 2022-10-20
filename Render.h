#pragma once

#include <GL/glew.h>

#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"

//#define ASSERT(x) if (!(x)) _debugbreak();
#define GLCall(x) GLClearError();\
	x;\
	//ASSERT(GLLogCall(#x, _FILE_, _LINE_))

void GLClearError();
bool GLLogCall(const char* function, const char* file, int line);

class Render
{
public:
	void Clear();
	void Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const;
private:
};