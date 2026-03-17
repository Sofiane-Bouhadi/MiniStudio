#pragma once
#include "Scene.h"
#include "Player.h"
#include "Parallaxe.h"

class MainScene : public Scene
{
private:
    Player* m_Player;
    Entity* pEntity4;

    Parallaxe* mParallaxFar = nullptr;
    Parallaxe* mParallaxMid = nullptr;
    Parallaxe* mParallaxNear = nullptr;
    Parallaxe* mParallaxClose = nullptr;

    bool MoveRight = false;

public:
    Player* GetPlayer() { return m_Player; }

    void OnInitialize() override;
    void OnEvent(const sf::Event& event) override;
    void OnUpdate() override;
};