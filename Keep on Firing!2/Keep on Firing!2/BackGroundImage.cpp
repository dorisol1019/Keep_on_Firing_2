#include "BackGroundImage.h"

#include<utility>

BackGroundImage::BackGroundImage()
{
	image = Image(L"Data/picture/stage1.png");
	for (auto& i : step(5))
	{
		images.emplace_back(image.clip(0, 120 * i, 480, 120 + 120 * i));		
	}
	std::pair<int,String>pis[]=
	{
		{0,L"Loop"},
		{1,L"Loop"},
		{2,L"Loop"},
		{3,L"Loop"},
		{4,L"Loop"},
		{0,L"Loop"},
	};

	for (auto& i : step(6))
	{
		textures[i] = Texture(images[pis[i].first]);
		texturesPos[i]={160,-120 + 120 * i };
	}
}
Array<Texture>LoopIncrement(Array<Texture>&&old)
{
	Array<Texture>newTextures(6);
	for (auto& i : step(5))
	{
		newTextures[i + 1] = std::move(old[i]);
	}
	newTextures[0] = std::move(old[5]);
	return newTextures;
}

BackGroundImage::~BackGroundImage()
{
}

void BackGroundImage::update()
{
	bool f = false;
	for (auto& i : step(6))
	{
		texturesPos[i] += {0, 5};
		if (texturesPos[i].y == 120 * i)
		{
			texturesPos[i].y -= 120;
			f = true;
		}
	}
	if (f)
	{
		textures = LoopIncrement(std::move(textures));
	}
}

void BackGroundImage::draw() const
{
	for (auto& i : step(6))
	{
		textures[i].draw(texturesPos[i]);
	}
}
