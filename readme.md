# ofxTick
ofxTickは一定時間毎に動作する関数を実装するためのアドオンです。
フレーム間の経過時間に対して短すぎる間隔である場合、その関数を1フレームで複数回実行し、その際の回数やデルタタイムなどを得ることができます。
openFrameworks v0.10.1 以上で動作を確認しています。

ofxTick is an addon to implement a function that runs at regular intervals.
If the interval is too short for the time between frames, the function can be called multiple times in a single frame to get the number of times, delta time, etc.
It has been tested with openFrameworks v0.10.1 and above.

# usage 使い方
```
// oxfTickと結びつける関数を作る
// Create a function that connects to oxfTick
void ofApp::TickEvent(ofxTick::Args & args) {
    //任意の処理。argsにはΔtや1フレームでの実行回数などが入っています。
    //arbitrary processing。The args contains Δt, the number of times it is called in one frame, etc.
}
//
void ofApp::setup(){
    tick.addListener(this, &ofApp::TickEvent); // don't forget add event listener
    tick.setIntervalFromFps(120); // TickEvent() is called 120 times per frame
    tick.activate(); // start tick timer
}
// update()を呼び続けることで、一定時間毎にTickEvent()関数が呼ばれる
// By continuing to call update(), the TickEvent() function will be called at regular intervals.
void ofApp::update(){
    tick.update();
}
```