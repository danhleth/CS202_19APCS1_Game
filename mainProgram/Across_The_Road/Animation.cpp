#include "Animation.h"


AnimationComponent::AnimationComponent(sf::Texture& textureSheet, sf::Sprite& sprite)
	:textureSheet(textureSheet), sprite(sprite)
{
}

AnimationComponent::~AnimationComponent()
{
	for (auto& i : this->animations) {
		delete i.second;
	}
}

void AnimationComponent::addAnimation(const string key, 
	float speed, 
	int start_x, int start_y, int end_x, int end_y, int width, int height
)
{
	this->animations[key] = new Animation(
		this->textureSheet, this->sprite,
		speed,
		start_x, start_y, end_x, end_y, width, height
	);
}

void AnimationComponent::play(const string key)
{
	this->animations[key]->play();
}
