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
		for (int j = 0; j < mColliderDescs[i].size(); ++j)
		{
			ColliderDesc& cd1 = mColliderDescs[i][j];

			if (cd1.active == false)
				continue;

			for (int k = 0; k < mColliderDescs[i + 1].size(); ++k)
			{
				ColliderDesc& cd2 = mColliderDescs[i + 1][k];

				if (cd1.active == false)
					continue;
				if (cd2.active == false)
					continue;

				if (cd1.yMax != cd2.yMin - 1)
					continue;

				if (cd1.xMin != cd2.xMin)
					continue;
				if (cd1.xMax != cd2.xMax)
					continue;

				cd1.active = false;
				cd2.yMin = cd1.yMin;
			}
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
			/*case 'C':
				scene->Spawn(MainScene::JazzWall1, j * mPixelPerChar, i * mPixelPerChar);
				break;
			case 'D':
				scene->Spawn(MainScene::JazzWall2, j * mPixelPerChar, i * mPixelPerChar);
				break;
			case 'E':
				scene->Spawn(MainScene::HubWall1, j * mPixelPerChar, i * mPixelPerChar);
				break;
			case 'F':
				scene->Spawn(MainScene::HubWall2, j * mPixelPerChar, i * mPixelPerChar);
				break;
			case 'G':
				scene->Spawn(MainScene::MetalWall1, j * mPixelPerChar, i * mPixelPerChar);
				break;
			case 'H':
				scene->Spawn(MainScene::MetalWall2, j * mPixelPerChar, i * mPixelPerChar);
				break;
			case 'I':
				scene->Spawn(MainScene::LeftJazzPlatform, j * mPixelPerChar, i * mPixelPerChar);
				break;*/
			case 'J':
				scene->Spawn(MainScene::DestructiblePlatform, j * mPixelPerChar, i * mPixelPerChar);
				break;
			}

			if (IsPlatformSymbol(mLevel[i][j])) 
			{
				ColliderDesc cdesc = {j, j, i, i};

				TryMergeCollider(cdesc);
			}

		}
	}

	MergeVerticalCollider();

	// Create Colliders in scene
	for (int i = 0; i < mColliderDescs.size(); ++i)
	{
		for (int j = 0; j < mColliderDescs[i].size(); ++j)
		{
			if (mColliderDescs[i][j].active == false)
				continue;

			float posX = mColliderDescs[i][j].xMin * mPixelPerChar;
			float posY = mColliderDescs[i][j].yMin * mPixelPerChar;

			float width = (mColliderDescs[i][j].xMax - mColliderDescs[i][j].xMin + 1) * mPixelPerChar;
			float height = (mColliderDescs[i][j].yMax - mColliderDescs[i][j].yMin + 1) * mPixelPerChar;

			scene->SpawnCollider(posX, posY, width, height);
		}
	}
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