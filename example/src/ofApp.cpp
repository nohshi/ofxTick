#include "ofApp.h"
#include "ofxTick.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetBackgroundColor(50);
    
    int numBalls = 100;
    float velAmp = 200;
    for (int i=0; i<numBalls; i++) {
        float x = ofRandomWidth();
        float y = ofRandomHeight();
        float u = ofRandomf() * velAmp;
        float v = ofRandomf() * velAmp;
        balls.emplace_back(x, y, u, v);
    }
    
    tick.addListener(this, &ofApp::TickEvent);
    tick.setIntervalFromFps(120);
    tick.activate();
    
}

//--------------------------------------------------------------
void ofApp::update(){
    tick.update();
}

//--------------------------------------------------------------
void ofApp::TickEvent(ofxTick::Args & args) {
    for (auto & ball : balls) {
        ball.update(args.deltaTime);
    }
    if (args.taskId == 0) cout << endl;
    ofxTick::log(args, "frame" + ofToString(ofGetFrameNum()));
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    for (auto & ball : balls) {
        ball.draw();
    }
    ofDrawBitmapStringHighlight("fps : " + ofToString(ofGetFrameRate()), 10, 20);
    ofDrawBitmapStringHighlight("tick.getFps() : " + ofToString(tick.getFps()), 10, 45);
    ofDrawBitmapStringHighlight("tick.interval : " + ofToString(tick.interval), 10, 70);
    ofDrawBitmapStringHighlight("press key LEFT  : make tick.interval smaller", 10, 95);
    ofDrawBitmapStringHighlight("press key RIGHT : make tick.interval greater", 10, 115);
    ofDrawBitmapStringHighlight("press key SHIFT : call tick.switchActiveMode()", 10, 140);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    float shift = 0.001;
    if (key == OF_KEY_LEFT)  tick.interval -= shift;
    if (key == OF_KEY_RIGHT) tick.interval += shift;
    
    if (key == OF_KEY_SHIFT) tick.switchActiveMode();
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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
