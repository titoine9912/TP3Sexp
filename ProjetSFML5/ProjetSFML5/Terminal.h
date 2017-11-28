#pragma once
#include <SFML/Graphics.hpp>
#include "textbox.h"
class Terminal
{

public:
	Terminal();
	int run();
private:
	const int LARGEUR = 1280;
	const int HAUTEUR = 720;
	sf::Text ChoixJeu;
	Textbox poutine;
	Font font;
	bool init();
	void getInputs();
	void update();
	void draw();

	RenderWindow mainWin;
	View view;
	Event event;
};