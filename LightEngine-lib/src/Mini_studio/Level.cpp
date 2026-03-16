#include "Level.h"
#include "GameManager.h"
#include "MainScene.h"
#include <iostream>
#include <fstream>

bool Level::IsPlatformSymbol(char symbol) const
{
	int i = 0;

	while (mPlatformSymbols[i] != '\0')
	{
		if (symbol == mPlatformSymbols[i])
			return true;

		++i;
	}

	return false;
}

void Level::TryMergeCollider(ColliderDesc colliderDesc)
{
	if (mColliderDescs.size() == 0)
	{
		//Resize vector by adding a line
		mColliderDescs.resize(1);
		
		//Add colliderDesc to the new line
		mColliderDescs[0].push_back(colliderDesc);

		return;
	}
	
	int lastIndex1 = mColliderDescs.size() - 1;

	if (mColliderDescs[lastIndex1].size() == 0)
	{
		mColliderDescs[lastIndex1].push_back(colliderDesc);

		return;
	}
	
	int lastIndex2 = mColliderDescs[lastIndex1].size() - 1;

    ColliderDesc* cd = &mColliderDescs[lastIndex1][lastIndex2];

	if (cd->yMin != colliderDesc.yMin)
	{
		//Resize vector by adding a line
		mColliderDescs.resize(mColliderDescs.size() + 1);
		//Add colliderDesc to the new line
		mColliderDescs[mColliderDescs.size() - 1].push_back(colliderDesc);

		return;
	}

	if (cd->xMax == colliderDesc.xMin - 1)
	{
		//Resize the last ColliderDesc by merging it with the new ColliderDesc
		cd->xMax = colliderDesc.xMax;

		return;
	}

	mColliderDescs[lastIndex1].push_back(colliderDesc);
}

void Level::MergeVerticalCollider()
{
	for (int i = 0; i < mColliderDescs.size() - 1; ++i)
	{
		for (int j = 0; j < mColliderDescs[i].size() - 1; ++j)
		{
			if (mColliderDescs[i][j].active == false)
				continue;

			if (mColliderDescs[i][j].yMax != mColliderDescs[i + 1][j].yMin - 1)
				continue;

			if (mColliderDescs[i][j].xMin != mColliderDescs[i + 1][j].xMin)
				continue;
			if (mColliderDescs[i][j].xMax != mColliderDescs[i + 1][j].xMax)
				continue;

			mColliderDescs[i][j].active = false;
			mColliderDescs[i + 1][j].yMin = mColliderDescs[i][j].yMin;
		}
	}
}

void Level::ReadLevel(MainScene* scene)
{
	for (int i = 0; i < mLevel.size(); ++i)
	{
		for (int j = 0; j < mLevel[i].size(); ++j)
		{
			switch (mLevel[i][j])
			{
			case '1':
				scene->Spawn(MainScene::Enemy1, j * mPixelPerChar, i * mPixelPerChar);
				break;
			case '2':
				scene->Spawn(MainScene::Enemy2, j * mPixelPerChar, i * mPixelPerChar);
				break;
			case '3':
				scene->Spawn(MainScene::Enemy3, j * mPixelPerChar, i * mPixelPerChar);
				break;
			case '4':
				scene->Spawn(MainScene::Enemy4, j * mPixelPerChar, i * mPixelPerChar);
				break;
			case 'B':
				scene->Spawn(MainScene::Boss, j * mPixelPerChar, i * mPixelPerChar);
				break;
			case 'W':
				scene->Spawn(MainScene::Wall, j * mPixelPerChar, i * mPixelPerChar);
				break;
			case 'G':
				scene->Spawn(MainScene::Ground, j * mPixelPerChar, i * mPixelPerChar);
				break;
			case '=':
				scene->Spawn(MainScene::Platform, j * mPixelPerChar, i * mPixelPerChar);
				break;
				// ...
			}

			if (IsPlatformSymbol(mLevel[i][j])) 
			{
				ColliderDesc cdesc = {j, j, i, i};

				TryMergeCollider(cdesc);
			}

		}
	}

	//try merge vertical
	MergeVerticalCollider();
}

void Level::OpenFile()
{
	std::ifstream file(_path);

	if (file.is_open()) 
	{
		std::string line;
		while (std::getline(file, line)) 
		{
			mLevel.push_back(line);
		}
	}
	else
	{
		std::cout << "File : " << _path << " not found" << std::endl;
	}

	file.close();
}