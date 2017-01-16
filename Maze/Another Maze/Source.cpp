#include<iostream>
#include"Point2D.h"
#include"Stack.h"
#include<fstream>
#include<string>

using namespace std;

void main()
{
	ifstream myFile;
	Point2D character(1, 0);
	Point2D nextSpace;
	Point2D lastSpot;
	Stack<Point2D> lastStep = Stack<Point2D>(100);
	int check = 0;
	const int rows = 24;
	const int columns = 20;
	char maze[columns][rows];
	char emptySpace = ' ';
	char onStack = '.';
	char moveDown = 'V';
	char moveUp = '^';
	char moveRight = '>';
	char moveLeft = '<';
	int counter;
	int direction = 1;
	const int down = 1;
	const int left = 2;
	const int right = 3;
	const int up = 4;
	myFile.open("Maze.txt");

	for (int y = 0; y < rows; ++y)
	{
		for (int x = 0; x < columns; ++x)
		{
			myFile >> maze[x][y];
			maze[character.getX()][character.getY()] = moveDown;

			if (maze[x][y] == '_')
				maze[x][y] = ' ';
				
			cout << maze[x][y];
		}
		cout << endl;
	}

	system("pause");

	while (maze[3][23] != moveDown && maze[3][23]!= moveUp && maze[3][23] != moveLeft && maze[3][23] != moveRight)
	{
		switch (direction)
		{
		case down:
			nextSpace = Point2D(character.getX(), character.getY() + 1);

			if (maze[nextSpace.getX()][nextSpace.getY()] == emptySpace)
			{
				system("cls");
				check = 0;
				lastStep.push(character);
				maze[character.getX()][character.getY()] = onStack;
				character = nextSpace;
				maze[character.getX()][character.getY()] = moveDown;

				for (int y = 0; y < rows; ++y)
				{
					for (int x = 0; x < columns; ++x)
					{
						cout << maze[x][y];
					}
					cout << endl;
				}
				
				system("pause");
			}
			else if (maze[nextSpace.getX()][nextSpace.getY()] == 'x' || maze[nextSpace.getX()][nextSpace.getY()] == '.')
			{
				system("cls");
				direction = 2;
				check += 1;
				maze[character.getX()][character.getY()] = moveLeft;
				for (int y = 0; y < rows; ++y)
				{
					for (int x = 0; x < columns; ++x)
					{
						cout << maze[x][y];
					}
					cout << endl;
				}
				
				system("pause");
			}

			break;

		case left:

			nextSpace = Point2D(character.getX() - 1, character.getY());

			if (maze[nextSpace.getX()][nextSpace.getY()] == emptySpace)
			{
				system("cls");
				check = 0;
				lastStep.push(character);
				maze[character.getX()][character.getY()] = onStack;
				character = nextSpace;
				maze[character.getX()][character.getY()] = moveLeft;

				for (int y = 0; y < rows; ++y)
				{
					for (int x = 0; x < columns; ++x)
					{
						cout << maze[x][y];
					}
					cout << endl;
				}
				
				system("pause");
			}
			else if (maze[nextSpace.getX()][nextSpace.getY()] == 'x' || maze[nextSpace.getX()][nextSpace.getY()] == '.')
			{
				system("cls");
				direction = 3;
				check += 1;
				maze[character.getX()][character.getY()] = moveRight;
				for (int y = 0; y < rows; ++y)
				{
					for (int x = 0; x < columns; ++x)
					{
						cout << maze[x][y];
					}
					cout << endl;
				}
				
				system("pause");
			}

			break;

		case right:

			nextSpace = Point2D(character.getX() + 1, character.getY());

			if (maze[nextSpace.getX()][nextSpace.getY()] == emptySpace)
			{
				system("cls");
				check = 0;
				lastStep.push(character);
				maze[character.getX()][character.getY()] = onStack;
				character = nextSpace;
				maze[character.getX()][character.getY()] = moveRight;

				for (int y = 0; y < rows; ++y)
				{
					for (int x = 0; x < columns; ++x)
					{
						cout << maze[x][y];
					}
					cout << endl;
				}
				
				system("pause");
			}
			else if (maze[nextSpace.getX()][nextSpace.getY()] == 'x' || maze[nextSpace.getX()][nextSpace.getY()] == '.')
			{
				system("cls");
				direction = 4;
				check += 1;
				maze[character.getX()][character.getY()] = moveUp;
				for (int y = 0; y < rows; ++y)
				{
					for (int x = 0; x < columns; ++x)
					{
						cout << maze[x][y];
					}
					cout << endl;
				}
				
				system("pause");
			}
			break;

		case up:
			nextSpace = Point2D(character.getX(), character.getY() - 1);

			if (maze[nextSpace.getX()][nextSpace.getY()] == emptySpace)
			{
				system("cls");
				check = 0;
				direction = 1;
				lastStep.push(character);
				maze[character.getX()][character.getY()] = onStack;
				character = nextSpace;
				maze[character.getX()][character.getY()] = moveUp;

				for (int y = 0; y < rows; ++y)
				{
					for (int x = 0; x < columns; ++x)
					{
						cout << maze[x][y];
					}
					cout << endl;
				}
				
				system("pause");
			}
			else if (maze[nextSpace.getX()][nextSpace.getY()] == 'x' || maze[nextSpace.getX()][nextSpace.getY()] == '.')
			{
				system("cls");
				direction = 1;
				check += 1;
				maze[character.getX()][character.getY()] = moveDown;
				for (int y = 0; y < rows; ++y)
				{
					for (int x = 0; x < columns; ++x)
					{
						cout << maze[x][y];
					}
					cout << endl;
				}
			
				system("pause");
			}
			break;

		}
		if (check >= 4)
		{
			system("cls");
			lastSpot = lastStep.peak();
			maze[character.getX()][character.getY()] = onStack;
			character = lastSpot;
			lastStep.pop();
			check = 1;
			direction = 1;
			maze[character.getX()][character.getY()] = moveDown;

			for (int y = 0; y < rows; ++y)
			{
				for (int x = 0; x < columns; ++x)
				{
					cout << maze[x][y];
				}
				cout << endl;
			}
			
			system("pause");
		}
	}
	
	system("cls");


	for (int y = 0; y < rows; ++y)
	{
		for (int x = 0; x < columns; ++x)
		{
			maze[14][11] = 'V';
			cout << maze[x][y];
		}
		cout << endl;
	}
	cout << "Victory" << endl;
	
	myFile.close();
	system("pause");
}

