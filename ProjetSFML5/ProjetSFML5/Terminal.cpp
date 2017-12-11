#include"Terminal.h"

//TODO
//ajouter bouton skip tirage
//ajouter liste de string
//ajouter affichage
//ajouter tableau billet acheter ou bloc note
//Server

//11 = créer billet
//22 = valider billet
//66 = prochain tirage
//99 = FIN




using namespace std;

Terminal::Terminal()
{
	//On place dans le contructeur ce qui permet à la game elle-même de fonctionner

	mainWin.create(VideoMode(LARGEUR, HAUTEUR, 32), "Terminale Lotto");  // , Style::Titlebar); / , Style::FullScreen);
	view = mainWin.getDefaultView();

	//Synchonisation coordonnée à l'écran!  Normalement 60 frames par secondes. À faire absolument
	mainWin.setVerticalSyncEnabled(true);
	//mainWin.setFramerateLimit(60);  //Équivalent... normalement, mais pas toujours. À utiliser si la synchonisation de l'écran fonctionne mal.
	//https://www.sfml-dev.org/tutorials/2.0/window-window.php#controlling-the-framerate
	callingAgent007 = false;
	callingPoutine = false;
	callingUber = false;
}


int Terminal::Run()
{
	if (!init())
	{
		return EXIT_FAILURE;
	}

	while (mainWin.isOpen())
	{
		getInputs();
		update();
		draw();
	}

	return EXIT_SUCCESS;
}

bool Terminal::init()
{
	if (!font.loadFromFile("Ressources\\fonts\\Peric.ttf"))
		return false;
	if (!backgroundTexture.loadFromFile("Ressources\\Background.jpg"))
		return false;
	background.setTexture(backgroundTexture);

	poutine.init(400, 200, Vector2f(230, 100), font);
	poutine.insererTexte("Poutine	2$");
	uber.init(400, 200, Vector2f(230, 150), font);
	uber.insererTexte("Uber	5$");
	agent007.init(400, 200, Vector2f(230, 200), font);
	agent007.insererTexte("Agent 007	8$");
	valider.init(400, 200, Vector2f(1050, HAUTEUR - 100), font);
	valider.insererTexte("valider");
	fin.init(400, 200, Vector2f(1050, HAUTEUR - 50), font);
	fin.insererTexte("Fermer");
	prochainTirage.init(400, 200, Vector2f(1050, HAUTEUR - 150), font);
	prochainTirage.insererTexte("Prochain tirage");

	validation.setFont(font);
	validation.setColor(Color::White);
	validation.setPosition(1000, 10);
	validation.setString("valider");
	bankMoney.setFont(font);
	bankMoney.setColor(Color::White);
	bankMoney.setPosition(20, HAUTEUR - 50);
	bankMoney.setString("Votre argent : " + to_string(bank) + "$");
	choixJeu.setFont(font);
	choixJeu.setColor(Color::White);
	choixJeu.setPosition(120, 10);
	choixJeu.setString("Choisir un jeu");

	bank = 100;
	return true;
}

void Terminal::getInputs()
{
	//On passe l'événement en référence et celui-ci est chargé du dernier événement reçu!
	while (mainWin.pollEvent(event))
	{
#pragma region Réaction Bouton
		//x sur la fenêtre
		if (event.type == Event::Closed)
		{
			mainWin.close();
		}

		if (poutine.touche(Mouse::getPosition(mainWin)))
		{
			poutine.selectionner();
			poutine.ChangeTextboxColor(Color::Green);
		}
		else
		{
			poutine.deSelectionner();
			poutine.ChangeTextboxColor(Color::White);
		}

		if (agent007.touche(Mouse::getPosition(mainWin)))
		{
			agent007.selectionner();
			agent007.ChangeTextboxColor(Color::Green);
		}
		else
		{
			agent007.deSelectionner();
			agent007.ChangeTextboxColor(Color::White);
		}

		if (uber.touche(Mouse::getPosition(mainWin)))
		{
			uber.selectionner();
			uber.ChangeTextboxColor(Color::Green);
		}
		else
		{
			uber.deSelectionner();
			uber.ChangeTextboxColor(Color::White);
		}

		if (valider.touche(Mouse::getPosition(mainWin)))
		{
			valider.selectionner();
			valider.ChangeTextboxColor(Color::Green);
		}
		else
		{
			valider.deSelectionner();
			valider.ChangeTextboxColor(Color::White);
		}

		if (fin.touche(Mouse::getPosition(mainWin)))
		{
			fin.selectionner();
			fin.ChangeTextboxColor(Color::Green);
		}
		else
		{
			fin.deSelectionner();
			fin.ChangeTextboxColor(Color::White);
		}

		if (prochainTirage.touche(Mouse::getPosition(mainWin)))
		{
			prochainTirage.selectionner();
			prochainTirage.ChangeTextboxColor(Color::Green);
		}
		else
		{
			prochainTirage.deSelectionner();
			prochainTirage.ChangeTextboxColor(Color::White);
		}
#pragma endregion 
#pragma region événement sur clique
		if (event.type == Event::MouseButtonPressed)
		{
			if (poutine.touche(Mouse::getPosition(mainWin)))
			{
				callingPoutine = true;
			}
			if (uber.touche(Mouse::getPosition(mainWin)))
			{
				callingUber = true;
			}
			if (agent007.touche(Mouse::getPosition(mainWin)))
			{
				callingAgent007 = true;
			}
			if (valider.touche(Mouse::getPosition(mainWin)))
			{
				//TODO
			}
			if (agent007.touche(Mouse::getPosition(mainWin)))
			{
				callingAgent007 = true;
			}
		}
#pragma endregion
	}
}

void Terminal::update()
{
	if (semaphore.semaphore == semaphoreState::toReadByTerminal)
	{
		//TODO
		//save new lotto
	}

	if (callingPoutine)
	{
		CallPoutine();
		callingPoutine = false;
	}
	if (callingUber)
	{
		CallUber();
		callingUber = false;
	}
	if (callingAgent007)
	{
		CallAgent007();
		callingAgent007 = false;
	}

	//TODO go through list of proceding

}

void Terminal::draw()
{
	//Toujours important d'effacer l'écran précédent
	mainWin.clear();
	mainWin.draw(background);
	mainWin.draw(choixJeu);
	mainWin.draw(validation);
	mainWin.draw(bankMoney);
	valider.dessiner(&mainWin);
	poutine.dessiner(&mainWin);
	uber.dessiner(&mainWin);
	prochainTirage.dessiner(&mainWin);
	fin.dessiner(&mainWin);
	agent007.dessiner(&mainWin);
	mainWin.display();
}

void Terminal::bankUpdate()
{
	bankMoney.setString("Votre argent : " + to_string(bank) + "$");
}


void Terminal::CallPoutine()
{
	string ask = "11POUT";
	if (bank - 2 > 0)
	{
		bank -= 2;
		bankUpdate();
		//TODO
		//Add to list of proceding
	}
}

void Terminal::CallUber()
{
	string ask = "11UBER";
	if (bank - 5 > 0)
	{
		bank -= 5;
		bankUpdate();
		//TODO
		//Add to list of proceding
	}
}

void Terminal::CallAgent007()
{
	string ask = "11A007";
	if (bank - 8 > 0)
	{
		bank -= 8;
		bankUpdate();
		//TODO
		//Add to list of proceding
	}
}
