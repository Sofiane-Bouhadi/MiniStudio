#include "AssetManager.h"
#include "AssetManager.h"
#include <iostream>

AssetManager* AssetManager::Instance = nullptr;

AssetManager::AssetManager() {
    Instance = nullptr;
}

AssetManager::~AssetManager() {
    for (int i = 0; i < mTexturePaths.size(); ++i) {
        delete mTexturePaths.begin()->second;
    }

    mTexturePaths.clear();

    delete Instance;
}

sf::Texture* AssetManager::LoadTexture(const char* path, float width, float height)
{
    sf::Texture* pTexture = new sf::Texture;

    if (pTexture->loadFromFile(path, sf::IntRect(0, 0, width, height)))
    {
        mTexturePaths[path] = pTexture;

        return pTexture;
    }

    std::cout << "Couldn't load texture." << std::endl;
}

sf::Texture* AssetManager::GetTexture(const char* path, float width, float height)
{
    auto it = mTexturePaths.find(path);

    if (it == mTexturePaths.end())
        return LoadTexture(path, width, height);

    return it->second;
}