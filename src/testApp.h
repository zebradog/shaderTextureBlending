#pragma once

#include "ofMain.h"
#include "ofxControlPanel.h"
#include "ofxShader.h"
#include "readme.h"

class testApp : public ofSimpleApp{

	public:

		void setup();
		void update();
		void draw();

		void guiEvents(guiCallbackData & data);

		void keyPressed  (int key);
		void keyReleased (int key);

		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased();

		ofxControlPanel gui;
		simpleFileLister listerBase;
		simpleFileLister listerBlend;
		simpleLogger logger;

		float elapsedTime;
		int appFrameCount;
		float appFrameRate;

		ofTrueTypeFont TTF;

		ofImage imgBase;
		ofImage imgBlend;

		ofxShader shader;

		float shadeBlendMix;
		int shadeBlendMode;
		float shadeBrightness;
		float shadeContrast;

		Readme readme;


};


