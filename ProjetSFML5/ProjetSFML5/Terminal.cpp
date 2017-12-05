#include"Terminal.h"

Terminal::Terminal()
{
	//On place dans le contructeur ce qui permet à la game elle-même de fonctionner

	mainWin.create(VideoMode(LARGEUR, HAUTEUR, 32), "Terminale Lotto");  // , Style::Titlebar); / , Style::FullScreen);
	view = mainWin.getDefaultView();

	//Synchonisation coordonnée à l'écran!  Normalement 60 frames par secondes. À faire absolument
	mainWin.setVerticalSyncEnabled(true);
	//mainWin.setFramerateLimit(60);  //Équivalent... normalement, mais pas toujours. À utiliser si la synchonisation de l'écran fonctionne mal.
	//https://www.sfml-dev.org/tutorials/2.0/window-window.php#controlling-the-framerate
}


int Terminal::run()
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
	{
		return false;
	}

	poutine.init(400, 200, Vector2f(230, 100), font);
	valider.init(400, 200, Vector2f(1050, 100), font);
	poutine.insererTexte("poutine");
	valider.insererTexte("valider");
	validation.setFont(font);
	validation.setColor(Color::White);
	validation.setPosition(1000, 10);
	validation.setString("valider");
	ChoixJeu.setFont(font);
	ChoixJeu.setColor(Color::White);
	ChoixJeu.setPosition(120, 10);
	ChoixJeu.setString("Choisir un jeu");
	return true;
}

void Terminal::getInputs()
{
	//On passe l'événement en référence et celui-ci est chargé du dernier événement reçu!
	while (mainWin.pollEvent(event))
	{
		//x sur la fenêtre
		if (event.type == Event::Closed)
		{
			mainWin.close();
		}

		if (poutine.touche(Mouse::getPosition(mainWin)))
		{
			poutine.selectionner();
			valider.deSelectionner();
			poutine.ChangeTextboxColor(Color::Green);
		}

		if (valider.touche(Mouse::getPosition(mainWin)))
		{
			valider.selectionner();
			poutine.deSelectionner();
			valider.ChangeTextboxColor(Color::Green);
	    }
		else
		{
			poutine.deSelectionner();
			valider.deSelectionner();
			poutine.ChangeTextboxColor(Color::White);
			valider.ChangeTextboxColor(Color::White);
		}

		if (event.type == Event::MouseButtonPressed)
		{
			if (poutine.touche(Mouse::getPosition(mainWin)))
			{
				
			}

			if (valider.touche(Mouse::getPosition(mainWin)))
			{

			}
		}
	}
}

void Terminal::update()
{

}

void Terminal::draw()
{
	//Toujours important d'effacer l'écran précédent
	mainWin.clear();
	mainWin.draw(ChoixJeu);
	mainWin.draw(validation);
	valider.dessiner(&mainWin);
	poutine.dessiner(&mainWin);
	mainWin.display();

}