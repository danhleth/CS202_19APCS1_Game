#pragma once
#include "includePath.h"

class AnimationComponent
{
private:
	class Animation{
	public:
		//Variable
		sf::Texture& textureSheet;
		sf::Sprite& sprite;
		float speed, timer;
		int width, height;
		sf::IntRect startRect, currentRect, endRect;
		//Constructor
		Animation(sf::Texture& textureSheet, sf::Sprite& sprite, 
			float speed, 
			int start_x, int start_y, int end_x, int end_y, int width, int height)
			:textureSheet(textureSheet), sprite(sprite), speed(speed), height(height), width(width)
		{
			this->timer = 0.f;
			this->startRect = sf::IntRect(start_x * width, start_y * height, width, height);
			this->currentRect = this->startRect;
			this->endRect = sf::IntRect(end_x * width, end_y * height, width, height);
			this->sprite.setTexture(this->textureSheet);
			this->sprite.setTextureRect(this->startRect);
		}
		//Functions
		void play() {
			this->timer += 10.f;
			if (this->timer >= speed) {
				timer = 0.f;
				if (this->currentRect != endRect) {
					this->currentRect.left += this->width;
				}
				else {
					this->currentRect.left = startRect.left;
				}
				this->sprite.setTextureRect(this->currentRect);
			}
		}

		void reset() {
			this->timer = 0.f;
			this->currentRect = startRect;
		}
	};

	sf::Texture& textureSheet;
	sf::Sprite& sprite;

	map<string, Animation*> animations;

public:
	AnimationComponent(sf::Texture& textureSheet, sf::Sprite& sprite);
	virtual ~AnimationComponent();

	//Funtion
	void addAnimation(const string key,
		float speed,
		int start_x, int start_y, int end_x, int end_y, int width, int height);
	void play(const string key);
};

