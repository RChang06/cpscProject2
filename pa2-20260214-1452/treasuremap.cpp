/**
 * @file treasuremap.cpp
 * @description Implementations for PA2, TreasureMap class
 * @author (your CWLs)
**/

#include "treasuremap.h"
#include "queue.h"
using namespace std;

TreasureMap::TreasureMap(const PNG& baseim, const PNG& mazeim, pair<int, int> s) {
	/* YOUR CODE HERE */

}

void TreasureMap::SetGrey(PNG& im, pair<int, int> loc) {
	/* YOUR CODE HERE */

}

void TreasureMap::SetLOB(PNG& im, pair<int, int> loc, int d) {
	/* YOUR CODE HERE */

}

PNG TreasureMap::RenderMap() {
	/* REPLACE THE LINE BELOW WITH YOUR CODE */
	return PNG();
}


PNG TreasureMap::RenderMaze() {
	/* REPLACE THE LINE BELOW WITH YOUR CODE */
	return PNG();
}

bool TreasureMap::Good(vector<vector<bool>>& v, pair<int, int> curr, pair<int, int> next) {
	/* REPLACE THE LINE BELOW WITH YOUR CODE */
	//check for boundries
	if (next.first < 0 || next.first >= base.width() 
		|| next.second < 0 || next.second >= (int)base.height()){
		return false;
	}
	if (v[next.first][next.second] == true) {
		return false; 
	}
	RGBAPixel* currColor = maze.getPixel(curr.first, curr.second);
	RGBAPixel* nextColor = maze.getPixel(next.first, next.second);

	if (*currColor == *nextColor) {
		return true; 
	}
	
	return false;
}

vector<pair<int, int>> TreasureMap::Neighbours(pair<int, int> curr) {
	/* REPLACE THE LINES BELOW WITH YOUR CODE */
	vector<pair<int, int>> v;
	return v;
}

/***********************************************
* IF YOU DECLARED ANY ADDITIONAL PRIVATE       *
* FUNCTIONS IN treasuremap-private.h, COMPLETE *
* THEIR IMPLEMENTATIONS BELOW                  *
***********************************************/
