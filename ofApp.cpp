#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetColor(39);
	ofSetLineWidth(3);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
	this->locations.clear();

	vector<glm::vec2> centers;
	for (int i = 0; i < 10; i++) {

		centers.push_back(glm::vec2(
			ofMap(ofNoise(ofRandom(100), ofGetFrameNum() * 0.005), 0, 1, 0, ofGetWidth()),
			ofMap(ofNoise(ofRandom(100), ofGetFrameNum() * 0.005), 0, 1, 0, ofGetHeight())
		));
	}
	
	int radius = 80;
	for (auto& center : centers) {

		for (int deg = 0; deg < 360; deg += 30) {

			this->locations.push_back(center + glm::vec2(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD)));
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw() {

	for (auto& location : this->locations) {

		ofDrawCircle(location, 5);
		for (auto& other : this->locations) {

			float distance = glm::distance(location, other);
			if (distance < 78) {

				ofDrawLine(location, other);
			}
		}
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}