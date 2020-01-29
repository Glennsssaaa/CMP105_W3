#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include <string.h>
#include <iostream>


class Level{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput(float dt);
	void update(float dt);
	void render();

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;

	sf::RectangleShape rect;
	sf::RectangleShape player;
	sf::CircleShape circ;
	sf::Font font;
	sf::Text text;
	float speed;
	float circSpeed;
	int dir;
	int circX;
	int circY;
};