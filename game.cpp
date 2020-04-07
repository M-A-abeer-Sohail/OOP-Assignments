#include "game.hpp"

bool Game::init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}

		//Create window
		gWindow = SDL_CreateWindow("HU Life", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
			if (gRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}
			}
		}
	}

	return success;
}

bool Game::loadMedia()

{
	//Loading success flag
	bool successOut = true;
	bool success1 = titleScreen();

	assets = loadTexture("assets.png");
	// gTexture = loadTexture("title.png");
	if (assets == NULL || !success1)
	{
		printf("Unable to run due to error: %s\n", SDL_GetError());
		successOut = false;
	}

	return successOut;
}

bool Game::titleScreen()
{

	bool success = true;
	gTexture = loadTexture("title.png");

	SDL_Rect title;
	title.x = 0;
	title.y = 0;
	title.w = 800;
	title.h = 150;
	SDL_RenderSetViewport(gRenderer, &title);
	SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);

	SDL_DestroyTexture(gTexture);
	gTexture = loadTexture("hu.png");

	SDL_Rect hu;
	hu.x = SCREEN_WIDTH / 8;
	hu.y = SCREEN_HEIGHT / 4;
	hu.w = 200;
	hu.h = 200;
	SDL_RenderSetViewport(gRenderer, &hu);
	SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);

	SDL_DestroyTexture(gTexture);
	gTexture = loadTexture("ned.png");

	SDL_Rect ned;
	ned.x = (7 * SCREEN_WIDTH / 8) - 200;
	ned.y = SCREEN_HEIGHT / 4;
	ned.w = 200;
	ned.h = 200;
	SDL_RenderSetViewport(gRenderer, &ned);
	SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);

	if (gTexture == NULL)
	{
		printf("Unable to run due to error: %s\n", SDL_GetError());
		success = false;
	}

	return success;
}

void Game::close()
{
	// cout << "hello" << endl;
	//Free loaded images
	SDL_DestroyTexture(assets);
	assets = NULL;
	SDL_DestroyTexture(gTexture);
	// SDL_DestroyTexture(viewportTextures[0]);
	// viewportTextures[0] = NULL;

	//Destroy window
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

SDL_Texture *Game::loadTexture(std::string path)
{
	//The final texture
	SDL_Texture *newTexture = NULL;

	//Load image at specified path
	SDL_Surface *loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return newTexture;
}

void Game::updateEggs()
{
	//check the collision of eggs and nests here
	//If an egg is dropped in a nest, produce a new baby pigeon
	//if the egg is dropped on floor, remove it from list.
}
void Game::updatePigeons()
{
	//Iterate over the link list of pigeons and generated eggs with 2% probability
	//Remove such pigeons from the list which have laid 4 eggs.
}

void Game::drawAllObjects()
{
	//draw the objects here
}

void Game::run()
{
	SDL_RenderClear(gRenderer);
	//Main loop flag
	bool quit = false;

	//Event handler
	SDL_Event e;
	//While application is running
	// Pigeon p1(assets);
	// Nest n1(assets);
	// Egg e1(assets);
	Pigeon p1(assets);
	bool inTitleScreen = true;
	int bgIndex = 0;
	bool pause = false;
	while (!quit)
	{
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}

			if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT)
			{
				//this is a good location to add pigeon in linked list.
				int xMouse, yMouse;
				SDL_GetMouseState(&xMouse, &yMouse);
				// Dimensions for pigeon are 50,50
				// Dimensions for nest are 60,75
				// Dimensions for egg are 27,29
				if (!inTitleScreen && !pause) // only update the pigeon position if game is not paused
				{
					if (yMouse < 300)
					{
						// Create a new Pigeon
						// Enable check to limit cursor to SCREEN_WIDTH - 50, SCREEN_HEIGHT - 50
						p1.setMover(xMouse, yMouse, 50, 50);
					}
					else
					{
						// e1.setMover(xMouse, yMouse, 27, 29);
						// Create a new Nest
					}
				}
				else
				{
					if (yMouse > (SCREEN_HEIGHT / 4) && yMouse < ((SCREEN_HEIGHT / 4) + 200))
					{
						if (xMouse > ((SCREEN_WIDTH / 8)) && xMouse < ((SCREEN_WIDTH / 8) + 200))
						{
							bgIndex = 0;
							SDL_DestroyTexture(gTexture);
							gTexture = loadTexture("hu.png");
							inTitleScreen = false;
							SDL_Rect mainViewport;
							mainViewport.x = 0;
							mainViewport.y = 0;
							mainViewport.w = 800;
							mainViewport.h = 600;
							SDL_RenderSetViewport(gRenderer, &mainViewport);
							SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);
						}
						else if (xMouse > ((7 * SCREEN_WIDTH / 8) - 200) && xMouse < ((7 * SCREEN_WIDTH / 8)))
						{
							bgIndex = 1;
							inTitleScreen = false;
							SDL_DestroyTexture(gTexture);
							gTexture = loadTexture("ned.png");
							SDL_Rect mainViewport;
							mainViewport.x = 0;
							mainViewport.y = 0;
							mainViewport.w = 800;
							mainViewport.h = 600;
							SDL_RenderSetViewport(gRenderer, &mainViewport);
							SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);
						}
					}
				}
			}
			else if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_SPACE) // Using space key to pause
			{
				if (pause == true)
				{
					pause = false;
				}
				else if (pause == false)
				{
					pause = true;
				}
			}
		}

		SDL_RenderClear(gRenderer); //removes everything from renderer

		if (!inTitleScreen)
		{
			SDL_RenderCopy(gRenderer, gTexture, NULL, NULL); //Draws background to renderer
			p1.draw(gRenderer, pause);
			// here would come drawAllObjects with input of pause.						 //
		}
		else
		{
			titleScreen();
		}

		// p1.draw(gRenderer);
		// e1.draw(gRenderer);
		// // updatePigeons();
		// // updateEggs();
		// drawAllObjects(); //draws all objects

		SDL_RenderPresent(gRenderer); //displays the updated renderer
		//p1.draw(gRenderer);
		//SDL_RenderPresent(gRenderer);
		SDL_Delay(200); //causes sdl engine to delay for specified miliseconds
	}
}
