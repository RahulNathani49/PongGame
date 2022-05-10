#pragma once
#include "ConsoleReader.h"
#include "ConsoleWriter.h"
#include "Region.h"
#include "Paddle.h"
#include "Ball.h"
#include "ChaosBall.h"
#include "Player.h"
using namespace utility;

class PongGame
{
private:
	ConsoleReader reader;
	ConsoleWriter writer;
	Region walls;
	Region map;
	Paddle leftPaddle;
	Paddle rightPaddle;
	Player p1;
	Player p2;
	Ball ball;
	ChaosBall chaosBall;

public:
	PongGame();
	void start();
	int getPlayer1Score();
	int getPlayer2Score();
private:
	void eraseObjects();
	void handleInput();
	void updateObjects();
	void displayObjects();
};
