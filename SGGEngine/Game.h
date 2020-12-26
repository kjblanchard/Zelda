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



namespace SG
{
	/**
 * \brief This class is used to perform the main game loop, and initialize the proper components needed to initialize the game.  Also currently has a FPS counter in it.
 */
	class SGGENGINE_API Game
	{

			public:
				Game();
				~Game();
				/**
				 * \brief Main Game loop, this is called by the main function when the program is started.
				 */
				void Loop();
			private:
				double _previousClockInMs;
				double _currentClockInMs;
				double _elapsedTimeInMs;
				double _lagTimeInMs;
				float _fps;
				const double _updateTime = 1000.00 / 60.00;

			private:

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
