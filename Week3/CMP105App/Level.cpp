#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	if (!font.loadFromFile("font/arial.ttf")) {
		std::cout << "Error loading font\n";
	}
	text.setFont(font);
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::Red);

	// initialise game objects
	rect.setSize(sf::Vector2f(25, 25));
	rect.setPosition(100, 100);
	rect.setFillColor(sf::Color::Black);

	player.setSize(sf::Vector2f(25, 25));
	player.setPosition(200, 200);
	player.setFillColor(sf::Color::Red);


	circ.setRadius(25);
	circ.setPosition(300, 300);
	circ.setFillColor(sf::Color::White);

	circSpeed = 100.f;
	speed = 100.f;
	dir = 2;
	
	circX=1;
	circY=1;

}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{

}

// Update game objects
void Level::update(float dt)
{
	//Player Movement
	if (input->isKeyDown(sf::Keyboard::Up) && player.getPosition().y>0) {
		player.move(0, -(speed * dt));
	}
	else if (input->isKeyDown(sf::Keyboard::Down) && player.getPosition().y < window->getSize().y-25) {
		player.move(0, (speed * dt));
	}

	if (input->isKeyDown(sf::Keyboard::Left) && player.getPosition().x > 0) {
		player.move(-(speed * dt),0);
	}
	else if (input->isKeyDown(sf::Keyboard::Right) && player.getPosition().x < window->getSize().x - 25) {
		player.move((speed * dt), 0);
	}

	//Rectangle Movement

	if (rect.getPosition().x > ((window->getSize().x) - 25)) {
		dir = 2;
	}
	else if (rect.getPosition().x < (0)) {
		dir = 1;
	}


	if (dir == 1) {
		rect.move(speed * dt, 0);
	}
	else if (dir == 2) {
		rect.move(-(speed * dt), 0);
	}


	//Circle Movement

	if (input->isKeyPressed(sf::Keyboard::Equal) && circSpeed <= 500) {
		circSpeed = circSpeed + 25;
	}
	else if (input->isKeyPressed(sf::Keyboard::Hyphen) && circSpeed >= 0) {
		circSpeed = circSpeed - 25;
	}
	if (circSpeed > 500) {
		circSpeed = 500;
	}
	else if (circSpeed < 0) {
		circSpeed = 0;
	}

	if (circ.getPosition().x > ((window->getSize().x) - 50)) {
		circX = 2;
	}
	else if (circ.getPosition().x < (0)) {
		circX = 1;
	}
	if (circ.getPosition().y > ((window->getSize().y) - 50)) {
		circY = 2;
	}
	else if (circ.getPosition().y < (0)) {
		circY = 1;
	}

	if (circX == 1) {
		circ.move(circSpeed * dt, 0);
	}
	else if (circX == 2) {
		circ.move(-(circSpeed * dt), 0);
	}
	if (circY == 1) {
		circ.move(0, circSpeed * dt);
	}
	else if (circY == 2) {
		circ.move(0, -(circSpeed * dt));
	}

	text.setString("The Circles speed is " + std::to_string(circSpeed));
	
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(rect);
	window->draw(player);
	window->draw(circ);
	window->draw(text);
	endDraw();
}

// clear back buffer
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}