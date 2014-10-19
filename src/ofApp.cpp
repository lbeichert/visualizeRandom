#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofEnableDepthTest();

	keyWasPressed = false;
	nadded = 0;
	zeit = ofGetElapsedTimeMillis();
	mesh.enableIndices();
	ofColor color(255,255,0);
	

	a = ofVec3f(0,0,0);
	b =	ofVec3f(100,0,0);
	c = ofVec3f(50,86.6,0);
	d = ofVec3f(50,43.3,75);
	mesh.addVertex(a);
	allvectors.push_back(a);
	mesh.addColor(ofColor(255,0,0));

	mesh.addVertex(b);
	allvectors.push_back(b);
	mesh.addColor(ofColor(0,255,0));

	mesh.addVertex(c);
	allvectors.push_back(c);
	mesh.addColor(ofColor(0,0,255));

	mesh.addVertex(d);
	allvectors.push_back(d);
	mesh.addColor(ofColor(255,0,255));
	
	mesh.addTriangle(0,2,1);
	mesh.addTriangle(0,1,3);
	mesh.addTriangle(2,0,3);
	mesh.addTriangle(1,2,3);

}

//--------------------------------------------------------------
void ofApp::update(){


	if (ofGetElapsedTimeMillis()-zeit > nadded*300)
	{
		/*
		// Select one of the three faces that were last created
		indicesTemp = mesh.getIndices();
		nIndices = mesh.getNumIndices();
		nRand = nIndices - floor(ofRandom(1,4))*3 ;
		*/
		
		
		// Select one random face
		indicesTemp = mesh.getIndices();
		nIndices = mesh.getNumIndices();
		nRand = floor(ofRandom(0,nIndices/3))*3 ;
		

		//cout<<"first index of face:"<<nRand<<endl;

		int indA, indB, indC, indD;
		indA = indicesTemp[nRand];
		indB = indicesTemp[nRand+1];
		indC = indicesTemp[nRand+2];


		// vertices that make up the face
		a = mesh.getVertex(indA);
		b = mesh.getVertex(indB);
		c = mesh.getVertex(indC);

		/*
		cout<<"first vertex selected: "<<a<<endl;
		cout<<"second vertex selected: "<<b<<endl;
		cout<<"third vertex selected: "<<c<<endl;
		*/

		// create new vertex in order to build pyramid
		ofVec3f v1 = (b-a);
		ofVec3f v2 = (c-a);
		ofVec3f v3 = (c-b);
		ofVec3f n = v1.crossed(v2); //normal
		ofVec3f m = (a+b+c)/2; //barycentre
		float l = (v1.length()+v2.length()+v3.length())/3; //average length of sides
		float h = ofRandom(0.25*l, 0.75*l);
		ofVec3f d = m + n.normalized()*h; //new vector, tip of pyramid

		/*
		cout<<"normal: "<<n<<endl;
		cout<<"barycentre: "<<m<<endl;
		cout<<"new vector added: "<<d<<endl;
		*/

		// Add vector to mesh
		mesh.addVertex(d);
		allvectors.push_back(d);
		mesh.addColor(ofColor(ofRandom(0,255),ofRandom(0,255),ofRandom(0,255)));

		indD = mesh.getVertices().size()-1; //d is last element added

		//remove old face from mesh
		mesh.removeIndex(nRand);
		mesh.removeIndex(nRand);
		mesh.removeIndex(nRand);

		// add new faces
		mesh.addTriangle(indA, indB, indD);
		mesh.addTriangle(indC, indA, indD);
		mesh.addTriangle(indB, indC, indD);

		nadded++;
		keyWasPressed = false;
	}

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(122,122,122);
	cam.begin();
	mesh.draw();
	cam.end();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	keyWasPressed = true;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
