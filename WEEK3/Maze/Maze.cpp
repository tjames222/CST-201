// Maze.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Author: Tim James
// Course: CST-201
// Date: 1/14/19
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
#include <stack>
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



// Figure out up, down, left, right movement with iterators
// build a Node overloaded constructor that allows for list<list<Group>>, rowSize, colSize
// add a Group object to the stack once visited and mark visited as True
// print location of iterators at each location


//class Node {
//
//	
//
//	
//
//	// direction for the 
//	int dir;
//
//	// Up movement
//
//
//public: Node() {
//
//}
//};

//class Stack {
//
//	int top;
//
//public:
//	int stkArray[200];
//
//	Stack() {
//		top = -1;
//	}
//
//	int pop();
//	int size();
//
//	bool push(int el);
//	bool isEmpty();
//};
//
//int Stack::pop() {
//
//	if (top < 0) {
//
//		cout << "Stack Underflow" << endl;
//		return 0;
//	}
//	else {
//
//		int el = stkArray[top--];
//		return el;
//	}
//}
//
//int Stack::size() {
//	return top + 1;
//}
//
//bool Stack::push(int el) {
//
//	if (top >= (50 - 1)) {
//
//		cout << "Stack Overflow" << endl;
//		return false;
//	}
//	else {
//
//		stkArray[++top] = el;
//		cout << el << " was pushed onto the stack" << std::endl;
//	}
//}
//
//bool Stack::isEmpty() {
//	return (top < 0);
//}


//Node(int i, int j)
//{
//	x_Location = i;
//	y_Location = j;
//
//	// Initially direction  
//	// set to 0 
//	dir = 0;
//}

//struct MazeWalk {
//	int x;
//	int y;
//	
//	Group* temp;
//};

class MazeWalk {
public:
	int x;
	int y;
	int dir;
	bool visited;

	//Group *temp;

	MazeWalk(int i, int j) {
		x = i;
		y = j;
		visited = false;

		dir = 0;
	}
};


// Coordinates of end
//int fx, fy;
//bool visited;
//
//bool isReachable(MazeWalk *maze, int startR, int startC) {
//	
//	list<list<Group>>::iterator it_R = maze.begin();
//	list<Group>::iterator it_C = it_R->begin();
//
//	// Initially starting at (0, 0). 
//	int i = 0, j = 0;
//	int n = rowSize, m = colSize;
//
//	//Stack(Group s)
//
//	stack<Group> s;
//	 
//	Group temp;
//
//	temp = it_C->MazeWalk(i, j); // or possibly temp.MazeWalk(i, j);
//
//	s.push(temp);
//
//	while (!s.empty()) {
//
//		// Pop the top node and move to the 
//		// left, right, top, down or retract  
//		// back according the value of Group's
//		// dir variable. 
//		temp = s.top();
//		int d = temp.dir;
//		i = temp.x_Location, j = temp.y_Location;
//
//		// Increment the direction and 
//		// push the node in the stack again. 
//		temp.dir++;
//		s.pop();
//		s.push(temp);
//
//		// If we reach the end coordinates
//		// return true 
//		if (i == fx and j == fy) {
//			return true;
//		}
//
//		// Checking the Up direction. 
//		if (d == 0) {
//			if (i - 1 >= 0 && it_C->x_Location - 1 && it_C->y_Location &&
//				visited[&i - 1][&j]) {
//
//				Group temp1 = it_C->MazeWalk(i - 1, j);
//				visited[&i - 1][&j] = false;
//				s.push(temp1);
//			}
//		}
//
//		// Checking the left direction 
//		else if (d == 1) {
//			if (j - 1 >= 0 and it_C->x_Location && it_C->y_Location - 1 &&
//				visited[&i][&j - 1]) {
//
//				Group temp1 = it_C->MazeWalk(i, j - 1);
//				visited[&i][&j - 1] = false;
//				s.push(temp1);
//			}
//		}
//
//		// Checking the down direction 
//		else if (d == 2) {
//			if (i + 1 < n && it_C->x_Location + 1 && it_C->y_Location &&
//				visited[&i + 1][&j]) {
//
//				Group temp1 = it_C->MazeWalk(i + 1, j);
//				visited[&i + 1][&j] = false;
//				s.push(temp1);
//			}
//		}
//		// Checking the right direction 
//		else if (d == 3) {
//			if (j + 1 < m && it_C->x_Location && it_C->y_Location + 1 &&
//				visited[&i][&j + 1]) {
//
//				Group temp1 = it_C->MazeWalk(i, j + 1);
//				visited[&i][&j + 1] = false;
//				s.push(temp1);
//			}
//		}
//
//		// If none of the direction can take  
//		// the rat to the Food, retract back  
//		// to the path where the rat came from. 
//		else {
//			visited[&temp.x_Location][&temp.y_Location] = true;
//			s.pop();
//		}
//	}
//
//	// If the stack is empty and 
//	// no path is found return false. 
//	return false;
//}

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
	
	// Start, end, and blocked booleans 
	protected: bool start;
	protected: bool end;
	protected: bool blocked;
	protected: bool visited;

	// Direction for movement
	public: int dir;

	// Current Location
	public: int x_Location; // x location
	public: int y_Location; // y location
			   

	// Creates constructor of blank 3x3 group
	public: Group() {

		// Fills the contArray with the default start character '.'
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				
				contArray[i][j] = '.';
			}
		}
		
		visited = false;
		start = false;
		end = false;
		blocked = false;
				
		x_Location = 0;
		y_Location = 0;
		dir = 0;
	}

	// overloaded constructor that accepts a char to add to Group (index 1,1)
	public:	Group(char brand) {

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				// Checks to see if a wall exists and assigns 'X'
				if (brand == 'X' || brand == 'x') { // Converts to all Caps

					// Fills the contArray with the wall char
					contArray[i][j] = 'X'; 

					// Setting blocked to true
					blocked = true; 
				}
				// if no wall assign '.'
				else { 

					// Fills contArray with default char if not a wall
					contArray[i][j] = '.'; 
				}
			}
		}
		
		// Start position assignment
		if (brand == 'S' || brand == 's') { // Converts to all Caps

			// Sets Start position for contArray coordinates
			contArray[1][1] = 'S'; 

			start = true; 
		}
		// End possition assignment
		else if (brand == 'E' || brand == 'e') { // Converts to all Caps

			// Sets End position for contArray coordinates
			contArray[1][1] = 'E'; 

			end = true; 
		}

		visited = false;
		x_Location = 0;
		y_Location = 0;
		dir = 0;
	}

	//public: int MazeWalk(int i, int j) {
	//	x_Location = i;
	//	y_Location = j;
	//
	//	// Initial direction  
	//	// set to 0 
	//	dir = 0;
	//}

	// future functionality
	bool VisitedTrue() {
		visited = true;
	}

	// Returns values
	char ReturnBrand(int row, int col) {
		return contArray[row][col];
	}

	// Sets the Brand 
	public:	void SetBrand(char brand) {

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				// Checks to see if a wall exists and assigns 'X'
				if (brand == 'X' || brand == 'x') { // Converts to all Caps

					// Fills the contArray with the wall char
					contArray[i][j] = 'X';

					// Setting blocked to true
					blocked = true;
				}
				// if no wall assign '.'
				else { 

					// Fills contArray with default char if not a wall
					contArray[i][j] = '.';
				}
			}
		}
		// Start position assignment
		if (brand == 'S' || brand == 's') { // Converts to all Caps

			// Sets Start position for contArray coordinates
			contArray[1][1] = 'S';

			start = true;
		}
		// End possition assignment
		else if (brand == 'E' || brand == 'e') { // Converts to all Caps

			// Sets End position for contArray coordinates
			contArray[1][1] = 'E';

			end = true;
		}

		visited = false;
		x_Location = 0;
		y_Location = 0;
		dir = 0;
	}
};

// Writes the maze to a file
void WriteMaze(list<list<Group>> mazeBucket, int rowSize, int colSize) {

	// Declaring iterators
	list<list<Group>>::iterator it_R = mazeBucket.begin();
	list<Group>::iterator it_C = it_R->begin();

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

			for (int j = 0; j < colSize; j++) { // determines the amount of columns
				for (int n = 0; n < 3; n++) { // used for the loading of a Group object
					it_R = mazeBucket.begin(); // the iterator to select the row list
					for (int o = 0; o < i; o++) it_R++; // cycles through the row lists
					it_C = it_R->begin(); // sets the column iterator to the begining of the row list 
					for (int p = 0; p < j; p++) it_C++; // cycles through the column list 
					fileOut << it_C->ReturnBrand(m, n) << " "; // loads the group object at it_C location with appropriate brand and prints to file
				}
			}
			fileOut << endl; // adds a new line for next set of data
		}
	}
	fileOut.close(); // closes output file stream
}

// Prints the maze graphically to the console
void showMaze(list<list<Group>> mazeBucket, int rowSize, int colSize) {

	// Declaring iterators
	list<list<Group>>::iterator it_R = mazeBucket.begin();
	list<Group>::iterator it_C = it_R->begin();

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
			
			// prints the maze
			for (int j = 0; j < colSize; j++) {	// determines the amount of columns
				for (int n = 0; n < 3; n++) { // used for the loading of a Group object
					it_R = mazeBucket.begin(); // the iterator to select the row list
					for (int o = 0; o < i; o++) it_R++; // cycles through the row lists
					it_C = it_R->begin(); // sets the column iterator to the begining of the row list 
					for (int p = 0; p < j; p++) it_C++; // cycles through the column list 
					cout << it_C->ReturnBrand(m, n) << " "; // loads the group object at it_C location with appropriate brand and prints to console
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



	// mazeBucket is a list of lists holding Group objects
	list<list<Group>> mazeBucket;

	// Creates the list of lists holding Group objects
	for (int i = 0; i < rowSize; i++) {
		list<Group> newRow;
		mazeBucket.push_back(newRow); // creates new row list in the mazeBucket
		for (int j = 0; j < colSize; j++) {
			Group newCell('.'); // default start character
			mazeBucket.back().push_back(newCell); // adds a Group object to the row list in the mazeBucket
		}
	}

	// instantiating iterators for col and row lists
	list<list<Group>>::iterator it_R = mazeBucket.begin();
	list<Group>::iterator it_C = it_R->begin();

	// brand as walls from input file data
	for (int h = 0; h < 79; h++) {
		fileIn >> wallCol >> wallRow;

		// iterates through the list row and col and loads a group object with the correct
		// brand based on input file coordinates
		it_R = mazeBucket.begin();
		for (int i = 0; i < wallRow; i++) it_R++;
		it_C = it_R->begin();
		for (int j = 0; j < wallCol; j++) it_C++;

		// Checks for errors with wall input
		CheckFileIn();

		// Loads wall brand
		it_C->SetBrand('X');
	}

	// iterates through the list row and col and loads a group object with the correct
	// brand based on input file coordinates
	it_R = mazeBucket.begin();
	for (int i = 0; i < startRow; i++) it_R++;
	it_C = it_R->begin();
	for (int j = 0; j < startCol; j++) it_C++;

	// Loads Start brand
	it_C->SetBrand('S');

	// This does what maze[startCol][startRow].SetBrand('S'); does 
	// iterates through the list row and col and loads a group object with the correct
	// brand based on input file coordinates
	it_R = mazeBucket.begin();
	for (int i = 0; i < endCol; i++) it_R++;
	it_C = it_R->begin();
	for (int j = 0; j < endRow; j++) it_C++;

	// Loads End brand
	it_C->SetBrand('E');

	// Writes the maze to a file
	WriteMaze(mazeBucket, rowSize, colSize);

	// Prints the maze to the console
	showMaze(mazeBucket, rowSize, colSize);
	cout << endl;
	//cout << "X Loc: " << x_Location << " Y Loc: " << y_Location;


	//// Down movement
	//it_R = mazeBucket.begin(); // not sure if I need this
	//int currentY = it_C->y_Location; // will grab the current ylocation, why is this staying 0 y is the row
	////currentY = 6; // practice
	//int currentX = it_C->x_Location; // will grab the current xlocation, why is this staying 0 x is th column
	//currentX = 3; // practice
	//it_R++; // moving to the row below
	//it_C = it_R->begin(); // is this resetting it_C before the loop runs each time?
	//for (int i = 0; i < currentX; i++) { it_C++; it_C->x_Location++; } // move the column iterator to the same column below the previous point
	//int nextY = it_C->y_Location; // sets the new y location
	//int nextX = it_C->x_Location; // sets the new x location, why are they not incrementing correctly
	//// need a line that will push previous group object to stack
	//cout << "current xLoc: " << currentX << " current yLoc: " << currentY << endl;
	//cout << "nextX: " << nextX << " nextY: " << nextY << endl;
	//cout << "itXLoc: " << it_C->x_Location << " itYLoc: " << it_C->y_Location << endl;


	// Walk maze and load to stack
	// use if statements to test if x and y coordinates match the end coordinates
	// if they do not match cycle through up, down, left, right movements eg(x, y+1)
	// while moving through the maze print path coordinates and backtracking results
	// stack functionality: if x and y coordinates do not equal end coordinates
	// add current xy coordinates to the stack
	// use wallRow and wallCol to ensure path is blocked at those points
	// if the next movement is hitting a wall, try moving in a different direction (up, down, left, right
	// if deadend is found pop element off of stack and back track. repeat looking for alternate
	// routes on each popped element until new path is found. Ensure that the position you are backtracking
	// from gets added to the stack so we don't go back to that position later. use mark as visited once added to 
	// stack maybe.
	// look at using a 2d array for the stack for loading coordinates or make a list stack and use x and y as a struct
	//int sX = startCol;
	//int sY = startRow;
	//int eX = endCol;
	//int eY = endRow;

	// Press a key
	cout << endl << "Press <Enter> to continue..." << endl;
	cin.get();

	it_R = mazeBucket.begin();
	for (int i = 0; i < startRow; i++) it_R++;
	it_C = it_R->begin();
	for (int j = 0; j < startCol; j++) it_C++;

	
	int n = rowSize;
	int m = colSize;

	int fc = endCol;
	int fr = endRow;

	int c = startCol;
	int r = startRow;



	stack<MazeWalk> s;

	MazeWalk temp(c, r);

	s.push(temp);

	while (c != fc || r != fr) {

		// Pop the top node and move to the 
		// left, right, top, down or retract  
		// back according the value of node's 
		// dir variable. 
		temp = s.top();
		int d = temp.dir;
		c = temp.x, r = temp.y;
		//int itC = it_C->x_Location;
		//int itR = it_C->y_Location;

		// Increment the direction and 
		// push the node in the stack again. 
		temp.dir++;
		s.pop();
		s.push(temp);

		// If we reach the end coordinates
		// return true 
		if (c == fc && r == fr) {
			//return true;
			cout << "you made it! " << endl;
			
		}

		// Checking the Up direction. 
		if (d == 0) {
			if (c - 1 != wallRow - 1 && r != wallCol - 1 && c - 1 > colSize) {

				//it_C--;
				MazeWalk temp1(c - 1, r);
				//temp.visited = false;
				s.push(temp1);
				cout << "X: " << temp1.x << " Y: " << temp1.y << endl;
			}
		}

		// Checking the left direction 
		else if (d == 1) {
			if (r - 1 != wallCol - 1 && c != wallRow - 1 && r - 1 > rowSize) {

				//it_R--;
				MazeWalk temp1(c, r - 1);
				//temp.visited = false;
				s.push(temp1);
				cout << "X: " << temp1.x << " Y: " << temp1.y << endl;
			}
		}

		// Checking the down direction 
		else if (d == 2) {
			if (c + 1 != wallRow - 1 && r != wallCol - 1 && c + 1 < colSize) {

				//it_C++;
				MazeWalk temp1(c + 1, r);
				//temp.visited = false
				s.push(temp1);
				cout << "X: " << temp1.x << " Y: " << temp1.y << endl;
			}
		}

		// Checking the right direction 
		else if (d == 3) {
			if (r + 1 != wallCol - 1 && c != wallRow - 1 && r + 1 < rowSize) {

				//it_R++;
				MazeWalk temp1(c, r + 1);
				//temp.visited = false;
				s.push(temp1);
				cout << "X: " << temp1.x << " Y: " << temp1.y << endl;
			}
		}

		// If none of the direction can take  
		// the rat to the Food, retract back  
		// to the path where the rat came from. 
		else {
			//visited[temp.x][temp.y] = true;
			s.pop();
		}
	}

	// If the stack is empty and 
	// no path is found return false. 
	//return false;

	
	

	//// While current position does not equal end move through the maze
	//while (sX != eX || sY != eY) {
	//	sX + 1; // move right one 
	//	
	//	// If the route is blocked or visited try a different path
	//	if (sX == wallCol || sY == wallRow) {
	//		
	//		sY - 1; // try moving up

	//		// If route is still blocked or visited
	//		if (sX == wallCol || sY == wallRow) {

	//			sY + 1; // move position back to original location
	//			sY + 1; // try to move down
	//		}
	//		// If route is still blocked or visisted
	//		if (sX == wallCol || sY == wallRow) {

	//			sY - 1; // move position back to original location
	//			sX - 1; // try to move left
	//		}
	//	}
	//	cout << "sX position after moving: " << sX << " sY position after moving: " << sY << endl;

	//	if (sX == eX && sY == eY) {

	//		cout << "Found end point!!" << endl;
	//		cout << "sX position after moving: " << sX << " sY position after moving: " << sY << endl;
	//	}
	//	cout << "sX position after moving: " << sX << " sY position after moving: " << sY << endl;
	//}
	

	// Marks as visited
	//it_C->VisitedTrue();

	/*if (isReachable(mazeBucket)) {
		
		cout << "Path is found" << endl;
	}
	else {

		cout << "No path was found" << endl;
	}*/

	// Close File
	fileIn.close();



	return 0;
}
