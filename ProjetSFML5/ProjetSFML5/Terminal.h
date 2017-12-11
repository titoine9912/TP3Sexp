#pragma once
#include <SFML/Graphics.hpp>
#include "textbox.h"
#include "Exchange.h"
#include <string.h>
#include <queue>
class Terminal
{
	//modification
public:
	Terminal();
	int Run();
private:
	const int LARGEUR = 1280;
	const int HAUTEUR = 720;

	std::queue<std::string> listeDesBilletsAcheter;
	Exchange semaphore;
	sf::Text choixJeu;
	sf::Text validation;
	sf::Text bankMoney;
	sf::Texture backgroundTexture;
	sf::Sprite background;
	Textbox poutine;
	Textbox uber;
	Textbox agent007;
	Textbox valider;
	Textbox fin;
	Textbox prochainTirage;
	Font font;

	bool active = false;
	bool callingPoutine;
	bool callingUber;
	bool callingAgent007;
	bool callingFin=false;
	bool callingProchainTirage = false;
	bool callingValider = false;
	int bank = 100;
	bool init();

	void getInputs();
	void update();
	void draw();
	void CallPoutine();
	void CallUber();
	void CallAgent007();
	void bankUpdate();
	void Validate(std::string billet);

	RenderWindow mainWin;
	View view;
	Event event;
};