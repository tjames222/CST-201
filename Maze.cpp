// Maze.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Author: Tim James
// Course: CST-201
// Date: 1/3/19
// Professor: Bass
// Description: Maze program - Displays a maze to the console based on input from user. Writes a maze to a file based on user input.
// Program was designed by Tim James and inspired by professor Brandon Bass' code.

#include "pch.h"
#include <iostream>
#include <fstream>
#include <array>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <list>
#include "Maze.h"

using namespace std;

// Declare variables for maze
// Start row and start column
int startRow;
int startCol;

// Row size and column size
int rowSize;
int colSize;

// Wall Row and column
int wallRow;
int wallCol;

// End row and column
int endRow;
int endCol;

// Checks for input error from file for start, end, and size input
int CheckStartData() {
	if (startRow < 0 || startRow > rowSize || colSize < 0 ||
		rowSize < 0 || startCol < 0 || startCol > colSize ||
		endCol < 0 || endCol > colSize || endRow < 0 || endRow > rowSize) {
		cout << "Error!" << " File contents invalid." << endl
			<< "*** Check start, end, and size input data. ***" << endl;

		return 1;
	}
}

// Checks for input error from file for wall input
int CheckFileIn() {
	if (wallCol < 0 || wallCol > colSize || wallRow < 0 || wallRow > rowSize) {
		cout << "Error!" << " File contents invalid." << endl
			<< endl << "*** Check wall input data. ***" << endl;

		return 1;
	}
}

class Group {

	// Declaring variables to be used
	protected: char contArray[3][3]; // used for default constructor to be loaded
	protected: list<char> contListRow; // list for building the row
	protected: list<char> contListCol; // list for building the columns
			   list<char>::iterator it_R = contListRow.begin(); // iterator for the row list
			   list<char>::iterator it_C = contListCol.begin(); // iterator for the col list

	protected: int x_Location; // x location
	protected: int y_Location; // y location
	
	// Start, end, and blocked booleans 
	protected: bool start;
	protected: bool end;
	protected: bool blocked;

	//function for printing the elements in a list 
	// not in use at this time
	void showlist(list <char> g)
	{
		list <char> ::iterator it;
		for (it = g.begin(); it != g.end(); ++it)
			cout << *it;
		
	}

	// Creates constructor of blank 3x3 group
	public: Group() {

		// Fills the contArray with the default start character '.'
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				
				contArray[i][j] = '.';
			}
		}

		// Fills the contList with the default start character '.'
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {

				contListCol.assign(i, '.');
				contListRow.assign(j, '.');
			}
		}
		start = false;
		end = false;
		blocked = false;
				
		x_Location = 0;
		y_Location = 0;
	}

	// overloaded constructor that accepts a char to add to Group (index 1,1)
	public:	Group(char brand) {

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				// Checks to see if a wall exists and assigns 'X'
				if (brand == 'X' || brand == 'x') { // Converts to all Caps
					
					// Fills the contList with the wall char
					contListCol.assign(i, 'X');
					contListRow.assign(j, 'X');

					// Fills the contArray with the wall char
					contArray[i][j] = 'X'; 

					// Setting blocked to true
					blocked = true; 
				}
				// if no wall assign '.'
				else { 
					
					// Fills contList with default char if not a wall
					contListCol.assign(i, '.');
					contListRow.assign(j, '.');

					// Fills contArray with default char if not a wall
					contArray[i][j] = '.'; 
				}
			}
		}
		
		// Start position assignment
		if (brand == 'S' || brand == 's') { // Converts to all Caps
			
			// Sets Start position for contList coordinates
			contListCol.insert(it_C, 'S');
			contListRow.insert(it_R, 'S');

			// Sets Start position for contArray coordinates
			contArray[1][1] = 'S'; 

			start = true; 
		}
		// End possition assignment
		else if (brand == 'E' || brand == 'e') { // Converts to all Caps
			
			// Sets End position for contList coordinates
			contListCol.insert(it_C, 'E');
			contListRow.insert(it_R, 'E');

			// Sets End position for contArray coordinates
			contArray[1][1] = 'E'; 

			end = true; 
		}

		x_Location = 0;
		y_Location = 0;
	}

	// Returns values
	char ReturnBrand(int row, int col) {

		// This is where I get lost. How do I retrun the data from contList?
		//return contListCol.(col);
		//return contListRow.operator = row;
		//showlist(contListCol);
		//showlist(contListRow);
		return contArray[row][col];
	}

	// Sets the Brand 
	public:	void SetBrand(char brand) {

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				// Checks to see if a wall exists and assigns 'X'
				if (brand == 'X' || brand == 'x') { // Converts to all Caps
					
					// Fills the contList with the wall char
					contListCol.assign(i, 'X');
					contListRow.assign(j, 'X');

					// Fills the contArray with the wall char
					contArray[i][j] = 'X';

					// Setting blocked to true
					blocked = true;
				}
				// if no wall assign '.'
				else { 
					// Fills contList with default char if not a wall
					contListCol.assign(i, '.');
					contListRow.assign(j, '.');

					// Fills contArray with default char if not a wall
					contArray[i][j] = '.';
				}
			}
		}
		// Start position assignment
		if (brand == 'S' || brand == 's') { // Converts to all Caps
			
			// Sets Start position for contList coordinates
			contListCol.insert(it_C, 'S');
			contListRow.insert(it_R, 'S');

			// Sets Start position for contArray coordinates
			contArray[1][1] = 'S';

			start = true;
		}
		// End possition assignment
		else if (brand == 'E' || brand == 'e') { // Converts to all Caps
			
			// Sets End position for contList coordinates
			contListCol.insert(it_C, 'E');
			contListRow.insert(it_R, 'E');

			// Sets End position for contArray coordinates
			contArray[1][1] = 'E';

			end = true;
		}

		x_Location = 0;
		y_Location = 0;
	}
};

// Writes the maze to a file
void WriteMaze(Group ** mazeArray, int rowSize, int colSize) {

	// Declares new ofstream variable
	ofstream fileOut;

	// Opens a file to be written to 
	fileOut.open("C:\\Users\\mrtim\\Documents\\GCU\\CST-201\\WEEK 1\\Maze project 1\\fileOut.txt");

	// Used for Header Columns
	char header[] = { 'A', 'B', 'C', 'D', 'E', 'F', 
		'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 
		'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 
		'Y', 'Z' };

	cout << "   "; // used for spacing between headers

	// Header Letter spacing
	for (int i = 0; i < colSize; i++) {

			fileOut << "     " << header[i] << "";
	}

	// Formating
	fileOut << endl;

	// Row headers and loads the array with the maze data
	for (int i = 0; i < rowSize; i++) {
		for (int m = 0; m < 3; m++) {
			// Row number added to left header column
			if (m == 1) {
				if (i < 10) { 

					fileOut << i << "  "; // spacing for formating
				}
				else { 

					fileOut << i << " ";  // alternate spacing for formating
				}
			}
			else { 
				
				fileOut << "   "; 
			}
			for (int j = 0; j < colSize; j++) {
				for (int n = 0; n < 3; n++) {
					fileOut << mazeArray[i][j].ReturnBrand(m, n) << " "; // loads the array with maze data
				}
			}
			fileOut << endl; // adds a new line for next set of data
		}
	}
	fileOut.close(); // closes output file stream
}

// Prints the maze graphically to the console
void showMaze(Group ** mazeArray, int rowSize, int colSize) {

	// Used for Header Columns
	char header[] = { 'A', 'B', 'C', 'D', 'E', 'F',
		'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O',
		'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
		'Y', 'Z' };

	// Formatting
	cout << endl;

	// Header Letter spacing
	for (int i = 0; i < colSize; i++) {

		cout << "     " << header[i];
	}

	cout << endl;

	// Row headers and loads the array with the maze data
	for (int i = 0; i < rowSize; i++) {
		for (int m = 0; m < 3; m++) {
			// Row number added to left header column
			if (m == 1) {
				if (i < 10) {

					cout << i << "  "; // spacing for formating
				}
				else {

					cout << i << " ";  // alternate spacing for formating
				}
			}
			else {

				cout << "   ";
			}
			for (int j = 0; j < colSize; j++) {
				for (int n = 0; n < 3; n++) {
					cout << mazeArray[i][j].ReturnBrand(m, n) << " "; // loads the array with maze data
				}
			}
			cout << endl; // adds a new line for next set of data
		}
	}
}

int main() {

	// Variable for new input file stream
	ifstream fileIn;

	// open new file and read data
	fileIn.open("C:\\Users\\mrtim\\Documents\\GCU\\CST-201\\WEEK 1\\Maze project 1\\test.txt");

	//Check if file open is a success
	if (!fileIn) {
		cerr << "*** Unable to open file." << " Check file path. ***" << endl;
		exit(1); // system stop
	}

	// read input
	fileIn >> colSize >> rowSize;
	fileIn >> startCol >> startRow >> endCol >> endRow;

	// Calling the error function to action for start, end, and size input
	CheckStartData();

	// Maze array 
	Group** maze;

	maze = new Group*[rowSize];

	for (int i = 0; i < rowSize; i++) {
		
		maze[i] = new Group[colSize]; 
	}


	// brand as walls from input file data
	for (int h = 0; h < 79; h++) {
		fileIn >> wallCol >> wallRow;

		// Checks for errors with wall input
		CheckFileIn();

		// Loads wall brand
		maze[wallRow][wallCol].SetBrand('X');
	}

	// Brand as start or end points on the maze
	maze[startCol][startRow].SetBrand('S');
	maze[endCol][endRow].SetBrand('E');

	// Close File
	fileIn.close();

	// Writes the maze to a file
	WriteMaze(maze, rowSize, colSize);

	// Prints the maze to the console
	showMaze(maze, rowSize, colSize);

	return 0;
}
