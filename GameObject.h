#pragma once
#include <glm/glm.hpp>


class GameObject
{
private:
	glm::vec3 position;
	void drawOrigin();
	virtual void drawGeometry();
	
public:
	void draw();

};

