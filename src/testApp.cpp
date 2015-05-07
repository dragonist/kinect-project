#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup() {


    light.setPosition(ofGetWidth()/3, 0, 20);
    angle=0;

    openNIDevice.setup();//FromXML("openni/config/ofxopenni_config.xml");
    openNIDevice.addDepthGenerator();
    openNIDevice.addImageGenerator();
    openNIDevice.start();
    openNIDevice.setMirror(true);

    verdana.loadFont(ofToDataPath("verdana.ttf"), 24);
    
    pointl = ofPoint(100, 200);
    pointr = ofPoint(ofGetWidth()-100, 200);
    
}

//--------------------------------------------------------------
void testApp::update(){
    openNIDevice.update();
    
    if (depthl<700 && depthl>200) {
        angle-=1;
    }
    if (depthr<700 && depthr>200) {
        angle+=1;
    }
}

//--------------------------------------------------------------
void testApp::draw(){

	ofSetColor(255, 255, 255);
//    openNIDevice.drawDepth(0, 0, ofGetWidth(), ofGetHeight());
    openNIDevice.drawImage(0,0, ofGetWidth(), ofGetHeight());
    

    ofShortPixels depthMap = openNIDevice.getDepthRawPixels();
    depthl = depthMap[pointl.x+ pointl.y*640];
    depthr = depthMap[pointr.x+ pointr.y*640];
    
    ofSetColor(200, 100, 100);
    ofCircle(pointl.x+100, pointl.y, 30);
    ofCircle(pointr.x, pointr.y, 30);
    
    light.enable();
    ofSetColor(100, 100, 200);
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2,0);
    ofRotate(angle, 0.0, 0.0, 1.0);
    ofBox(200);
    ofPopMatrix();
    ofDisableLighting();
    
    
    
    ofSetColor(100, 256, 100);
    string msg = "left:"+ofToString(pointl.x)+","+ofToString(pointl.y)+","+ofToString(depthl)
    +"  right:"+ofToString(pointr.x)+","+ofToString(pointr.y)+","+ofToString(depthr);
    
//	string msg = " MILLIS: " + ofToString(ofGetElapsedTimeMillis()) + " FPS: " + ofToString(ofGetFrameRate());
    
	verdana.drawString(msg, 20, ofGetHeight() - 26);

}

//--------------------------------------------------------------
void testApp::exit(){
    openNIDevice.stop();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){


}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

