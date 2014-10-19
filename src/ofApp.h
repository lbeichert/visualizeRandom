#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		ofMesh	mesh;
		ofEasyCam cam;

		ofVec3f a, b, c, d;
		vector<ofVec3f> allvectors;
		vector<ofIndexType> indicesTemp;

		bool keyWasPressed;

		int nRand;
		int nIndices;
		int nadded;
		long zeit;
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};
