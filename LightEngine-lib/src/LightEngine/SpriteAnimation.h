#pragma once
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <vector>
#include "GameManager.h"

using namespace std;

class SpriteAnimation
{
    public:
        sf::Texture* Textures;
        vector<int> Delays;
        bool isLoop;

        int frameWidth;
        int frameHeight;
        int line;
        int column;

        sf::Sprite* sprite;

        float timeRemaining;
        int frame = 0;

        void Start();

        void Update();
};