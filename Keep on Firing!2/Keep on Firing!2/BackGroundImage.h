#pragma once

#include<Siv3D.hpp>
using Texture_p = Texture*;

class BackGroundImage
{
public:
	BackGroundImage();
	~BackGroundImage();

	void init(String path);
	void update();
	void draw()const;

private:
	Array<Texture> textures=Array<Texture>(6);
	Texture_p textures_p[6];
	Array<Vec2>texturesPos = Array<Vec2>(6);
	Image image;
	Array<Image> images;
	
};

