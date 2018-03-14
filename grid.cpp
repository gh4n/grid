/**
    CS-11 Asn 6
    grid.cpp
    Purpose: Generates an image of an n x n grid
	!! NOTE !! 
	only works for square dimensions as of yet
    @author Grace Han
    @version 1.0 09/02/18
*/

#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;


int main(int argc, char *argv[]) {
	
	if (argc != 4) {
		cout << "Usage: " << argv[0] << " <width> <height> <size>" << endl;
		cout << "(Width and Height should be greater than size)" << endl;
		return 1;
	}

	int width = atoi(argv[1]);
	int height = atoi(argv[2]);
	int size = atoi(argv[3]);
	int gridLine = width / size; 

	if(gridLine == 0) {
		cout << "Width must be greater than or equal to size" << endl;
		return 1;
	}

	ofstream img ("picture.ppm");
	img << "P3" << endl;
	img << width << " " << height << endl;
	img << "255" << endl;

	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			int r, g, b;
			r = g = b = ((x != 0 && x % gridLine == 0) ||  y % gridLine == 0) ? 1 : 255; 
			img << r << " " << g << " " << b << endl;
		}
	}
	return 0;
}

