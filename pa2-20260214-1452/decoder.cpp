/**
 * @file decoder.cpp
 * @description Implementations for PA2, Decoder class
 * @author (your CWLs)
**/

#include "decoder.h"
#include "queue.h"
#include "stack.h"
using namespace std;

Decoder::Decoder(const PNG& tm, pair<int, int> s) : start(s), mapImg(tm) {
    unsigned int width = mapImg.width();
    unsigned int height = mapImg.height();

    vector<vector<bool>> visited(width, vector<bool>(height, false));
    vector<vector<int>> distance(width, vector<int>(height, 0));
    vector<vector<pair<int, int>>> parent(width, vector<pair<int, int>>(height, make_pair(-1, -1)));

    Queue<pair<int, int>> q;

    visited[start.first][start.second] = true;
    distance[start.first][start.second] = 0;
    q.Enqueue(start);

    pair<int, int> farthestPoint = start;
    int maxDist = 0;

    while (!q.IsEmpty()) {
        pair<int, int> curr = q.Dequeue();
        vector<pair<int, int>> neighbors = Neighbours(curr);

        for (pair<int, int> next : neighbors) {
            if (Good(visited, distance, curr, next)) {
                visited[next.first][next.second] = true;
                distance[next.first][next.second] = distance[curr.first][curr.second] + 1;
                parent[next.first][next.second] = curr;
                
                if (distance[next.first][next.second] >= maxDist) {
                    maxDist = distance[next.first][next.second];
                    farthestPoint = next;
                }
                
                q.Enqueue(next);
            }
        }
    }

    pair<int, int> currTrace = farthestPoint;
    while (currTrace != make_pair(-1, -1)) {
        pathPts.push_back(currTrace);
        currTrace = parent[currTrace.first][currTrace.second];
    }
    
    int n = pathPts.size();

    for (int i = 0; i < n / 2; i++) {   
        pair<int, int> temp = pathPts[i];
        pathPts[i] = pathPts[n - 1 - i];
        pathPts[n - 1 - i] = temp;
    }   
}

PNG Decoder::RenderSolution() {
    PNG map = mapImg;

    for (size_t i = 0; i < pathPts.size(); i++) {
        pair<int, int> curr = pathPts[i];
        
        RGBAPixel* pixel = map.getPixel(curr.first, curr.second);
        
        pixel->r = 255;
        pixel->g = 0;
        pixel->b = 0;
    }

    return map;
}

PNG Decoder::RenderMaze(){
    
    PNG res = mapImg;
    unsigned int width = res.width();
    unsigned int height = res.height();

    vector<vector<bool>> visited(width, vector<bool>(height, false));
    vector<vector<int>> distance(width, vector<int>(height, 0)); // Needed for Good()
    Queue<pair<int, int>> q;

    visited[start.first][start.second] = true;
    distance[start.first][start.second] = 0;
    q.Enqueue(start);
    //traversal bfs

    while (!q.IsEmpty()) {
        pair<int, int> curr = q.Dequeue();
        
        // Darken the current maze pixel
        SetGrey(res, curr);

        vector<pair<int, int>> neighbors = Neighbours(curr);
        for (pair<int, int> next : neighbors) {
            if (Good(visited, distance, curr, next)) {
                visited[next.first][next.second] = true;
                distance[next.first][next.second] = distance[curr.first][curr.second] + 1;
                q.Enqueue(next);
            }
        }
    }
    //draw a 7x7 red dot
    for (int i = -3; i <= 3; i++) {
        for (int j = -3; j <= 3; j++) {
            int x = start.first + i;
            int y = start.second + j;

            //boundary check 
            if (x >= 0 && x < (int)width && y >= 0 && y < (int)height) {
                RGBAPixel* pixel = res.getPixel(x, y);
                pixel->r = 255;
                pixel->g = 0;
                pixel->b = 0;
            }
        }
    }

    return res;
}

void Decoder::SetGrey(PNG& im, pair<int, int> loc){
	int x = loc.first;
	int y = loc.second;

	RGBAPixel *pixel = im.getPixel(x, y);
	
	pixel->r = 2 * (pixel->r / 4);
    pixel->g = 2 * (pixel->g / 4);
    pixel->b = 2 * (pixel->b / 4);
}

pair<int, int> Decoder::FindSpot(){
    return pathPts.back();
}

int Decoder::PathLength(){
    return pathPts.size();
}

bool Decoder::Good(vector<vector<bool>>& v, vector<vector<int>>& d, pair<int, int> curr, pair<int, int> next){
    /* REPLACE THE LINE BELOW WITH YOUR CODE */
    if (next.first < 0 || next.first >= (int)mapImg.width() || 
        next.second < 0 || next.second >= (int)mapImg.height()) {
        return false;
    }

    // 2. Check if already visited
    if (v[next.first][next.second]) {
        return false;
    }
    RGBAPixel* pNext = mapImg.getPixel(next.first, next.second);
    int expectedValue = d[curr.first][curr.first];
    return Compare(*pNext, expectedValue);
    
}

vector<pair<int, int>> Decoder::Neighbours(pair<int, int> curr) {
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

bool Decoder::Compare(RGBAPixel p, int d) {
    int r_bits = p.r & 0x03; 
    int g_bits = p.g & 0x03;
    int b_bits = p.b & 0x03;

    int maze_value = (r_bits << 4) | (g_bits << 2) | b_bits;

    return maze_value == (d + 1) % 64;
}

/*******************************************
* IF YOU DECLARED ANY ADDITIONAL PRIVATE   *
* FUNCTIONS IN decoder-private.h, COMPLETE *
* THEIR IMPLEMENTATIONS BELOW              *
*******************************************/

