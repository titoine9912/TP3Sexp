#pragma once
#include <SFML/Graphics.hpp>
#include "textbox.h"
#include <string.h>
class Terminal
{
//modification
public:
	Terminal();
	int run();
	int call669();
	int callLotoMax();
	int callPoutine();
	int callUber();
	int call007();
	int Validate(std::string billet);
private:
	const int LARGEUR = 1280;
	const int HAUTEUR = 720;
	sf::Text ChoixJeu;
	sf::Text validation;
	Textbox poutine;
	Textbox valider;
	Font font;
	bool active = false;
	bool init();
	void getInputs();
	void update();
	void draw();

	RenderWindow mainWin;
	View view;
	Event event;
};