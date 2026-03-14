/**
 * @file decoder.cpp
 * @description Implementations for PA2, Decoder class
 * @author (your CWLs)
**/

#include "decoder.h"
#include "queue.h"
#include "stack.h"
using namespace std;

Decoder::Decoder(const PNG & tm, pair<int, int> s) : start(s), mapImg(tm) {
    /* YOUR CODE HERE */
    
}

PNG Decoder::RenderSolution(){
    /* REPLACE THE LINE BELOW WITH YOUR CODE */
    return PNG();
}

PNG Decoder::RenderMaze(){
    /* REPLACE THE LINE BELOW WITH YOUR CODE */
    return PNG();
}

void Decoder::SetGrey(PNG& im, pair<int, int> loc){
    /* YOUR CODE HERE */
    
}

pair<int, int> Decoder::FindSpot(){
    /* REPLACE THE LINES BELOW WITH YOUR CODE */
    pair<int, int> spot;
    return spot;
}

int Decoder::PathLength(){
    /* REPLACE THE LINE BELOW WITH YOUR CODE */
    return -1;
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

bool Decoder::Compare(RGBAPixel p, int d) {
    // 1. Extract the bits (same logic as SetLOB, but in reverse)
    // Red has bits 5,4 | Green has 3,2 | Blue has 1,0
    int r_bits = p.r & 0x03; // 00000011
    int g_bits = p.g & 0x03;
    int b_bits = p.b & 0x03;

    // 2. Reconstruct the 6-bit value
    // Shift Red left by 4, Green left by 2, and leave Blue at the end
    int maze_value = (r_bits << 4) | (g_bits << 2) | b_bits;

    // 3. Compare to (d + 1) mod 64
    return maze_value == (d + 1) % 64;
}

/*******************************************
* IF YOU DECLARED ANY ADDITIONAL PRIVATE   *
* FUNCTIONS IN decoder-private.h, COMPLETE *
* THEIR IMPLEMENTATIONS BELOW              *
*******************************************/

