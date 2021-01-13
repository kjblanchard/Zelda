////////////////////////////////////////////////////////////
//
// Super Goon Games - 2D Game Engine
// Copyright (C) 2020-2021 - Kevin Blanchard
//
////////////////////////////////////////////////////////////

#pragma once
#ifdef SGGENGINE_EXPORTS
#define SGGENGINE_API __declspec(dllexport)
#else
#define SGGENGINE_API __declspec(dllimport)
#endif
#include <memory>
#include <SDL_video.h>
#include <vector>

#include "Point.h"


namespace SG
{
	class GameObjectList;
	class GameObject;
	class Input;
	class Graphics;
	class GameClock;


	/**
	 * \brief This class is used to perform the main game loop, and initialize the proper components needed to initialize the game.  Also currently has a FPS counter in it.
	 */
	class SGGENGINE_API World
	{

	public:
		World(const Point& screenSize = Point(640, 480));
		virtual ~World();

		/**
		 * \brief Used to initialize the proper components to start the game, this is ran after the constructor and prior to the loop being called.
		 * \return Returns true if things were initialized successfully
		 */
		bool SetupWorldComponents();
		/**
		 * \brief Main Game loop, this is called by the main function when the program is started.
		 */
		void Loop();
		static World* GetGame() { return _instance; }
		static Graphics* GetGraphics() { return _graphics.get(); }




	private:
		Point _screenSize;
		/**
		 * \brief Game window,  we can use a Raw pointer here, as this has built in destroy functionality that we will put in the Game destructor
		 */
		SDL_Window* _gameWindow;
		std::unique_ptr<GameClock> _gameClock;

		bool shouldQuit{};
		static std::unique_ptr<Graphics> _graphics;
		static World* _instance;
		std::unique_ptr<Input> _input;

		GameObjectList* _gameObjectList;


	private:

		/**
		 * \brief Used to Initialize SDL as a whole and it's subsystems, needs to be ran at startup vor video and joystick.
		 */
		static bool InitializeSdl();


		/**
		 * \brief Checks the event queue, and if there are any quit events (like from clicking the X) the game will quit.
		 */
		bool HandleEvents();

		/**
		 * \brief Handles the Input for everything that needs their input handled.
		 */
		void HandleInput();

		virtual void Startup() = 0;

		/**
		 * \brief This will run the update function for all game objects
		 * \param deltaTime Milliseconds that have passed since the last frame
		 */
		virtual void Update(const double& deltaTime) = 0;
		/**
		 * \brief This will run the draw function for all game objects.
		 */
		 void Draw();

	};

};
