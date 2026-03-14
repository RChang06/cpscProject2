/**
 * @file treasuremap.cpp
 * @description Implementations for PA2, TreasureMap class
 * @author (your CWLs)
**/

#include "treasuremap.h"
#include "queue.h"
using namespace std;

TreasureMap::TreasureMap(const PNG& baseim, const PNG& mazeim, pair<int, int> s) {
	start = s;
	base = baseim;
	maze = mazeim;
}

/**
     * Changes the pixel at position loc to consist of colour channel
     * values which are 50% of their original. Note that because of 
     * our encoding scheme which essentially invalidates the lower
     * order bits, you should compute each value as 2*(x/4), where
     * x is the integer value of a colour channel.
    **/
void TreasureMap::SetGrey(PNG& im, pair<int, int> loc) {
	int x = loc.first;
	int y = loc.second;

	RGBAPixel *pixel = im.getPixel(x, y);
	
	pixel->r = 2 * (pixel->r / 4);
    pixel->g = 2 * (pixel->g / 4);
    pixel->b = 2 * (pixel->b / 4);
}

void TreasureMap::SetLOB(PNG& im, pair<int, int> loc, int d) {
    RGBAPixel *pixel = im.getPixel(loc.first, loc.second);

    int d6bit = d % 64;

    unsigned char rbits = (d6bit >> 4) & 0x3; 
    unsigned char gbits = (d6bit >> 2) & 0x3; 
    unsigned char bbits = d6bit & 0x3;        

    pixel->r = (pixel->r & 0xFC) | rbits;
    pixel->g = (pixel->g & 0xFC) | gbits;
    pixel->b = (pixel->b & 0xFC) | bbits;
}

/*
	  * 0. Make a copy of the base image. You will change its pixels corresponding to 
     *      locations within the maze.
     * 1. Initialize working vectors: 
     *      a. Define a 2d vector whose dimensions are the same as the image, and whose 
     *      values are boolean. Use this vector to indicate whether or not a location
     *      has been visited by the traversal.
     *      b. Define a 2d vector whose dimensions are the same as the image, and whose
     *      values are integers. This structure will be used to store the length of the
     *      shortest path between the current location and the start location.
     * 2. Initialize a queue whose purpose is to orchestrate the traversal. As you search
     *      the maze, you will have to keep a list of locations to explore. The queue maintains
     *      that list.
     * 3. For the start location, do the following:
     *      a. mark the start location as visited (structure in step 1a)
     *      b. set the distance to the start to be 0 (structure in step 1b)
     *      c. encode the distance within the start location's lower order bits of the treasure map 
     *          (structure in step 0)
     *      d. enqueue the start location. (structure in step 2)
     * 4. While the queue is not empty:
     *      a. set the current location, curr, to the value at the front of the queue (and dequeue). 
     *      b. for each compass neighbor, p, of curr in the order of left, below, right, above:
     *          i. if p is "good" (defined below) then
     *              1) mark p's location as visited
     *              2) set p's distance to the start to be curr's distance, + 1. 
     *              3) encode the distance in the lower order bits of the treasure map
     *              4) enqueue p
     *      
     * 5. return the image
	 */
PNG TreasureMap::RenderMap() {
	
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
