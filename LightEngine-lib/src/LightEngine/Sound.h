#pragma once
#include <SFML/Audio/Sound.hpp>

class Sound
{
private:
	sf::Sound* mSound;

public:
	Sound(const char* path);
	
	void Play();
	void Pause();
	void Stop();
	void SetLoop(bool isLoop);
};

