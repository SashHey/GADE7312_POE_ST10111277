#pragma once
#include "Pixel.h"

class Texture
{
public:
	Texture(const char* path);
	~Texture();
	void use();
	Pixel getPixelAt(int x, int y);

private:
	unsigned char* image;
	int width;
	int height;
	int channels;
	bool loaded = false;
	void loadTexture(const char* path);
};