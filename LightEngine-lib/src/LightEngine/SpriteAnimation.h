#pragma once
#include <SFML/Graphics/Texture.hpp>
#include <vector>

using namespace std;

class SpriteAnimation
{
    public:
        vector<sf::Texture> Textures;
        vector<int> Delays;
        bool isLoop;
};