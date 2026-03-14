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

PNG TreasureMap::RenderMap() {
    PNG map = base;

    unsigned int width = map.width();
    unsigned int height = map.height();

    vector<vector<bool>> visited(width, vector<bool>(height, false));
    vector<vector<int>> distance(width, vector<int>(height, 0));

    Queue<pair<int, int>> traversal;

    visited[start.first][start.second] = true;
    distance[start.first][start.second] = 0;
    SetLOB(map, start, 0); 
    traversal.Enqueue(start);

    while (!traversal.IsEmpty()) {
        pair<int, int> curr = traversal.Dequeue();
        vector<pair<int, int>> neighbors = Neighbours(curr);

        for (pair<int, int> pos : neighbors) {
            if (Good(visited, curr, pos)) {
                visited[pos.first][pos.second] = true;
                distance[pos.first][pos.second] = distance[curr.first][curr.second] + 1;
                
                SetLOB(map, pos, distance[pos.first][pos.second]);
                
                traversal.Enqueue(pos);
            }
        }
    }
    return map;
}


PNG TreasureMap::RenderMaze() {
	PNG res = base;
	int width = res.width();
	int height = res.height();
	vector<vector<bool>> visited(width, vector<bool>(height, false));
	vector<vector<int>> distance(width, vector<int>(height, 0));
	Queue<pair<int, int>> q;
	visited[start.first][start.second] = true;
	distance[start.first][start.second] = 0;
	SetLOB(res, start, 0);
	q.Enqueue(start);

	while (!q.IsEmpty()){
		pair<int, int> curr = q.Dequeue();
		vector<pair<int,int>> neighs = Neighbours(curr);
		for (pair<int, int>p : neighs) {
			if (Good(visited, curr, p)) {
				visited[p.first][p.second] = true; 
				distance[p.first][p.second] = distance[curr.first][curr.second] + 1;
				SetLOB(res, p, distance[p.first][p.second]);
				q.Enqueue(p);
			}
		}
	}
	/* REPLACE THE LINE BELOW WITH YOUR CODE */
	return res;
}

bool TreasureMap::Good(vector<vector<bool>>& v, pair<int, int> curr, pair<int, int> next) {
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
	vector<vector<int>> dirs {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
	for (auto pos: dirs) {
		pair<int, int> add;
		add.first = pos[0] + curr.first;
		add.second = pos[1] + curr.second;
		v.push_back(add);
	}
	return v;
}

/***********************************************
* IF YOU DECLARED ANY ADDITIONAL PRIVATE       *
* FUNCTIONS IN treasuremap-private.h, COMPLETE *
* THEIR IMPLEMENTATIONS BELOW                  *
***********************************************/
