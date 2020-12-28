#pragma once

#include "ofMain.h"
#include "ofxTick.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    struct Ball {
        float x, y, u, v, r;
        
        Ball() {}
        
        Ball(float _x, float _y, float _u, float _v) {
            x = _x; y = _y; u = _u; v = _v; r = 20;
        }
        
        void update(float dt) {
            x += u * dt;
            y += v * dt;
            wall();
        }
        
        void draw() {
            ofDrawCircle(x, y, r);
        }
        
        void wall() {
            if (x <= 0.f) {
                x = 0.f;
                u = -u;
            }
            if (x >= ofGetWidth()) {
                x = ofGetWidth();
                u = -u;
            }
            if (y <= 0.f) {
                y = 0.f;
                v = -v;
            }
            if (y >= ofGetHeight()) {
                y = ofGetHeight();
                v = -v;
            }
        }
    };
    
    vector<Ball> balls;
		
    void TickEvent(ofxTick::Args & args);
    ofxTick tick;
    
};
