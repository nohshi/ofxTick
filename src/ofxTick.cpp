#include "ofxTick.h"


void ofxTick::log(const Args & args) {
    cout << "ofxTick:: numTasks:" << args.numTasks << ", taskId:" << args.taskId << ", elapsedTimef:" << args.elapsedTimef << ", deltaTime:" << args.deltaTime << endl;
}

void ofxTick::log(const Args & args, const string & identifier) {
    cout << "ofxTick:" << identifier << ":: numTasks:" << args.numTasks << ", taskId:" << args.taskId << ", elapsedTimef:" << args.elapsedTimef << ", deltaTime:" << args.deltaTime << endl;
}
