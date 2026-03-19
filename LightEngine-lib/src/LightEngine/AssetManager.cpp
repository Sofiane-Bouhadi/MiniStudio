#include "AssetManager.h"
#include <iostream>

using namespace std;

AssetManager* AssetManager::Instance = nullptr;

AssetManager::AssetManager() {
}

AssetManager::~AssetManager() {
    for (auto& pair : mTexturePaths) {
        delete pair.second;
    }

    mTexturePaths.clear();
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
    delete pTexture;
    return nullptr;
}

sf::Texture* AssetManager::GetTexture(const char* path, float width, float height)
{
    auto it = mTexturePaths.find(path);

    if (it == mTexturePaths.end())
        return LoadTexture(path, width, height);

    return it->second;
}