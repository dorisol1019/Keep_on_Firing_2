#include "BackGroundImage.h"

#include<utility>
#include<algorithm>
BackGroundImage::BackGroundImage()
{
	
}
void LoopIncrement(Texture_p old[6])
{
	Texture_p newTextures[6];
	for (auto& i : step(5))
	{
		newTextures[i + 1] = old[i];
	}
	newTextures[0] = old[5];
	//copy
	for (auto& i : step(6))
	{
		old[i]=newTextures[i];
	}
	return;
}

BackGroundImage::~BackGroundImage()
{
}

void BackGroundImage::init(String path)
{
	image = Image(path);
	for (auto& i : step(5))
	{
		images.emplace_back(image.clip(0, 120 * i, 480, 120 + 120 * i));
	}
	std::pair<int, String>pis[] =
	{
		{ 0,L"Loop" },
		{ 1,L"Loop" },
		{ 2,L"Loop" },
		{ 3,L"Loop" },
		{ 4,L"Loop" },
		{ 0,L"Loop" },
	};

	for (auto& i : step(6))
	{
		textures[i] = Texture(images[pis[i].first]);
		textures_p[i]=&textures[i];
		texturesPos[i] = { 160,-120 + 120 * i };
	}
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
		LoopIncrement(textures_p);
	}
}

void BackGroundImage::draw() const
{
	for (auto& i : step(6))
	{
		textures_p[i]->draw(texturesPos[i]);
	}
}
