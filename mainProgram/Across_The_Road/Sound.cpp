#include "Sound.h"

void SoundComponent::initBuffer()
{
	this->sound.setBuffer(this->soundBuffer);
}

SoundComponent::SoundComponent(sf::Sound& a, sf::SoundBuffer& b) : sound(a), soundBuffer(b)
{
	initBuffer();
}

void SoundComponent::play()
{
	this->sound.play();
}

void SoundComponent::load(string a)
{
	this->soundBuffer.loadFromFile(a);
}
