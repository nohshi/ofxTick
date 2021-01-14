#pragma once

#include "ofMain.h"

class ofxTick {
public:
    
    struct Args {
        int numTasks;
        int taskId;
        float elapsedTimef;
        float deltaTime;
    };
    
    ofxTick() {};
    ~ofxTick() {};
    
    float interval = 1.0f;
    
    void setIntervalFromFps(float _fps) {
        interval = 1.f / _fps;
    }
    
    float getFps() {
        return 1.f / interval;
    }
    
    template <class ListenerClass>
    void addListener(ListenerClass  * listener, void (ListenerClass::*listenerMethod)(Args&)){
        ofAddListener(event, listener, listenerMethod);
    }
    
    template <class ListenerClass>
    void removeListener(ListenerClass  * listener, void (ListenerClass::*listenerMethod)(Args&)){
        ofRemoveListener(event, listener, listenerMethod);
    }
    
    void resetTimer() {
        timer = 0.0f;
    }
    
    bool getIsActive() {
        return isActive;
    }
    
    void activate() {
        isActive = true;
    }
    
    void deactivate() {
        isActive = false;
        resetTimer();
    }
    
    void switchActiveMode() {
        if (!isActive) {
            activate();
        } else {
            deactivate();
        }
    }
    
    void update() {
        if (isActive) {
            
            if (interval < FLT_MIN) {
                ofLog(OF_LOG_NOTICE, "ofxTick:: interval must be a positive number, otherwise update() does not work.");
                return;
            }
        
            float dt = ofGetLastFrameTime();
            timer += dt;
            
            if (timer > interval) {
                int numTasks = timer / interval; // How many inteval are contained in time
                float subDt = dt / numTasks;
                float currTime = ofGetElapsedTimef();
                
                for (int i=0; i < numTasks; i++) {
                    Args args;
                    
                    if (numTasks > 1) {
                        args.deltaTime = subDt;
                    } else if (isActive != prevIsActive) {
                        args.deltaTime = dt;
                    } else {
                        args.deltaTime = currTime - lastTaskTime;
                    }
                    
                    args.elapsedTimef = currTime + subDt * i;
                    args.numTasks = numTasks;
                    args.taskId = i;
                    
                    ofNotifyEvent(event, args, this);
                }
                timer -= interval * numTasks;
                lastTaskTime = currTime;
            }
            
        }
        prevIsActive = isActive;
    }
    
    static void log(const Args & args);
    
    static void log(const Args & args, const string & identifier);
    
protected:
    ofEvent<Args> event;
    bool isActive = false;
    bool prevIsActive = false;
    float timer = 0.0f;
    float lastTaskTime = 0.0f;
};
