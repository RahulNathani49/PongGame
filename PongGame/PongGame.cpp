#include "PongGame.h"
#include <iostream>
#include<string>
using namespace std;
PongGame::PongGame()
	: reader(),
	writer(),
	walls(Coordinate(80, 30)),
	map(walls.getTopLeft() + Coordinate(1, 1), walls.getBottomRight() - Coordinate(1, 1)),
	leftPaddle(map, map.getTopLeft() + Coordinate(3, 0), 5),
	rightPaddle(map, map.getTopRight() - Coordinate(3, 0), 5),
	ball(map,Coordinate(40,1)),p1(0),p2(0),
	chaosBall(map,Coordinate(30,2))
{ }

void PongGame::start()
{
	writer.setCursorVisible(false);
	writer.setWindowSize(map.getSize()  + Coordinate(2, 6));
	writer.drawRectangle(walls.getTopLeft(), walls.getBottomRight());
	writer.drawRectangle(walls.getTopLeft(), walls.getBottomRight());
	writer.drawRectangle(walls.getTopLeft(), walls.getBottomRight());
	writer.drawRectangle(map.getBottomLeft()+Coordinate(0,3), map.getBottomLeft() + Coordinate(5, 5));
	writer.drawRectangle(map.getBottomRight() + Coordinate(-5, 3), map.getBottomRight() + Coordinate(0, 5));
	while (!reader.isEscapePressed())
	{
		eraseObjects();
		handleInput();
		updateObjects();
		displayObjects();
		Sleep(100);
	}
}

void PongGame::eraseObjects()
{
	// Use writer to erase previous paddles from console
	writer.clearRegion(leftPaddle.getTop(), leftPaddle.getBottom());
	writer.clearRegion(rightPaddle.getTop(), rightPaddle.getBottom());
	writer.clearRegion(ball.getPosition(), ball.getPosition());
	writer.clearRegion(chaosBall.getPosition(), chaosBall.getPosition());
	
}
void PongGame::handleInput()
{
	// Use reader to check up/down arrow keys
	// If W/S is pressed, then set left paddle position
	if (reader.isKeyPressed('W'))
		leftPaddle.move(-1);
	else if (reader.isKeyPressed('S'))
		leftPaddle.move(1);
	/*else if (reader.isKeyPressed('D'))
		leftPaddle.moveHorizontal(1);
	else if (reader.isKeyPressed('A'))
		leftPaddle.moveHorizontal(-1);*/

	// Use reader to check up/down arrow keys
	// If up/down is pressed, then set right paddle position
	if (reader.isUpArrowPressed())
		rightPaddle.move(-1);
	else if (reader.isDownArrowPressed())
		rightPaddle.move(1);

}

void PongGame::updateObjects()
{ 
	// Normal ball
	for (int i = 0; i <= leftPaddle.getHeight(); i++) {
		if (ball.getPosition().X > leftPaddle.getTop().X && leftPaddle.getTop().X == ball.getTargetPosition().X && leftPaddle.getTop().Y + i == ball.getTargetPosition().Y) {
			ball.BounceHorizontally();
		}
	}

	for (int i = 0; i <= rightPaddle.getHeight(); i++) {
		if (ball.getPosition().X < rightPaddle.getTop().X && rightPaddle.getTop().X == ball.getTargetPosition().X && rightPaddle.getTop().Y + i == ball.getTargetPosition().Y) {
			ball.BounceHorizontally();
		}
	}
	if (ball.getTargetPosition().X == map.getRight()) {
		p2.setScore(p2.getScore() + 1);
	}
	if (ball.getTargetPosition().X == map.getLeft()) {
		p1.setScore(p1.getScore() + 1);
	}
	ball.move();

	// chaos ball

	for (int i = 0; i <= leftPaddle.getHeight(); i++) {
		if (chaosBall.getPosition().X > leftPaddle.getTop().X && leftPaddle.getTop().X == chaosBall.getTargetPosition().X && leftPaddle.getTop().Y + i == chaosBall.getTargetPosition().Y) {
			chaosBall.BounceHorizontally();
		}
	}

	for (int i = 0; i <= rightPaddle.getHeight(); i++) {
		if (chaosBall.getPosition().X < rightPaddle.getTop().X && rightPaddle.getTop().X == chaosBall.getTargetPosition().X && rightPaddle.getTop().Y + i == chaosBall.getTargetPosition().Y) {
			chaosBall.BounceHorizontally();
		}
	}
	if (chaosBall.getTargetPosition().X == map.getRight()) {
		p2.setScore(p2.getScore() + 1);
	}
	if (chaosBall.getTargetPosition().X == map.getLeft()) {
		p1.setScore(p1.getScore() + 1);
	}
	chaosBall.move();
}

void PongGame::displayObjects()
{

	// Use writer to draw paddles in the console
	writer.fillRegion('X', leftPaddle.getTop(), leftPaddle.getBottom());
	writer.fillRegion('X', rightPaddle.getTop(), rightPaddle.getBottom());
	writer.fillRegion(ball.getSymbol(), ball.getPosition(),ball.getPosition());
	writer.fillRegion(chaosBall.getSymbol(), chaosBall.getPosition(), chaosBall.getPosition());
	writer.setCursorPosition(map.getBottomRight() + Coordinate(-3, 4));
	writer.write(p1.getScore());
	writer.setCursorPosition(map.getBottomLeft() + Coordinate(3, 4));
	writer.write(p2.getScore());
}

int PongGame::getPlayer1Score()
{
	return p1.getScore();
}
int PongGame::getPlayer2Score()
{
	return p2.getScore();
}
