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
    
    return PNG();
}

PNG Decoder::RenderMaze(){
    /* REPLACE THE LINE BELOW WITH YOUR CODE */
    return PNG();
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
    // returns treasure spot
    pair<int, int> spot;
    return spot;
}

int Decoder::PathLength(){
    //returns distance from start to treasure in manhattan distance
    return -1;
}

bool Decoder::Good(vector<vector<bool>>& v, vector<vector<int>>& d, pair<int, int> curr, pair<int, int> next){
    /* REPLACE THE LINE BELOW WITH YOUR CODE */
    return false;
}

vector<pair<int, int>> Decoder::Neighbours(pair<int, int> curr) {
    /* REPLACE THE LINES BELOW WITH YOUR CODE */
    vector<pair<int, int>> v;
    return v;
}

bool Decoder::Compare(RGBAPixel p, int d){
    /* REPLACE THE LINE BELOW WITH YOUR CODE */
    return false;
}

/*******************************************
* IF YOU DECLARED ANY ADDITIONAL PRIVATE   *
* FUNCTIONS IN decoder-private.h, COMPLETE *
* THEIR IMPLEMENTATIONS BELOW              *
*******************************************/

