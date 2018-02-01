#include <iostream>
using namespace std;

// maze size
#define N 4

void printSolution(int sol[N][N])
{
	cout<<"\n";
	for (int i=0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout<<sol[i][j]<<" ";
		}
		 cout<<"\n";
	}
}

bool isPath(int maze[N][N], int i, int j) {

	if (i >= 0 && i < N && j >= 0 && j < N && maze[i][j] == 1)
		return true;
	return false;
}

bool solveMazeUtil(int maze[N][N], int i, int j, int sol[N][N]) {

	// if i, j is the goal, return true
	if (i == N-1 && j == N-1) {
		sol[i][j] = 1;
		return true;
	}

	// check if i,j path is valid
	if (isPath(maze, i, j) == true) {
		sol[i][j] = 1;

		// move down in i direction
		if (solveMazeUtil(maze, i+1, j, sol)){
			return true;
		}

		// if moving down in x direction does not give solution, then
		// move forward in j direction
		if (solveMazeUtil(maze, i, j+1, sol))
			return true;

		// if none of the above movements work, then backtrack.
		// unmark i,j as part of the solution path
		sol[i][j] = 0;
		return false;
	}

	return false;
}

bool solveMaze(int maze[N][N]) {
	int sol[N][N] = {
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0}
	};

	if (solveMazeUtil(maze, 0, 0, sol) == false) {
		printf("Solution does not exist");
		return false;
	}

	printSolution(sol);
	return true;
}

int main() {

	int maze[N][N] = {
		{1, 0, 0, 0},
		{1, 1, 0, 1},
		{0, 1, 1, 1},
		{1, 1, 0, 1}
	};

	solveMaze(maze);

	return 0;
}