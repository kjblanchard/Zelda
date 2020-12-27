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
#include "Point.h"
#include <memory>
#include <SDL_video.h>

#include "Graphics.h"


namespace SG
{


	/**
	 * \brief This class is used to perform the main game loop, and initialize the proper components needed to initialize the game.  Also currently has a FPS counter in it.
	 */
	class SGGENGINE_API Game
	{

	public:
		Game(const Point& screenSize = Point(640, 480));
		~Game();
		/**
		 * \brief Main Game loop, this is called by the main function when the program is started.
		 */
		void Loop();

		static Game* GetGame();

		static Graphics* GetGraphics();


	private:
		Point _screenSize;

		/**
		 * \brief Game window,  we can use a Raw pointer here, as this has built in destroy functionality that we will put in the Game destructor
		 */
		SDL_Window* _gameWindow;

		//TODO Finish adding in the FPS calculation.
		double _previousClockInMs;
		double _currentClockInMs;
		double _elapsedTimeInMs;
		double _lagTimeInMs;
		float _fps;
		const double _updateTime = 1000.00 / 60.00;
		static std::unique_ptr<Graphics> _graphics;
		static Game* _instance;

	private:

		/**
		 * \brief Used to initialize the proper components to start the game, this is ran after the constructor and prior to the loop being called.
		 * \return Returns true if things were initialized successfully
		 */
		bool Startup();
		/**
		 * \brief Used to Initialize SDL as a whole, needs to be ran at startup.
		 */
		static bool InitializeSdl();



		/**
		 * \brief Calculates the amount of time between this frame and the last frame and updates the Game member variables.
		 */
		void CalculateFrameTime();
		/**
		 * \brief Handles the Input for everything that needs their input handled.
		 */
		void HandleInput();
		/**
		 * \brief Runs the update function a specific number of times, based on the Update Time Variable and tries to run Draw just as often
		 */
		void Tick();
		/**
		 * \brief This is a very crude FPS counter
		 * \return Current Fps as a float
		 */
		float CalculateFps();
		/**
		 * \brief This will run the update function for all game objects
		 * \param deltaTime Milliseconds that have passed since the last frame
		 */
		void Update(const double& deltaTime);
		/**
		 * \brief This will run the draw function for all game objects.
		 */
		void Draw();
	};
};
