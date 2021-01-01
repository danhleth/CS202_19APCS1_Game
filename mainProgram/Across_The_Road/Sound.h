#pragma once
#include "includePath.h"


class SoundComponent {
private:
	sf::SoundBuffer& soundBuffer;
	sf::Sound& sound;
	void initBuffer();
public:
	SoundComponent(sf::Sound& a, sf::SoundBuffer& b);
	void play();
	void load(string a);
};
