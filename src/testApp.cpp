#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    cout << "WARNING: this program may take a while to load" << endl;

	ofBackground(127,127,127);

	ofSetWindowTitle( "Shader Texture Blending by Ruud Bijnen" );

    ofSetFrameRate ( 30 );
	ofSetVerticalSync(true);

	shadeBlendMix = 1.0;
	shadeBlendMode = 0;
	shadeContrast = 1.0;
	shadeBrightness = 0.0;

	readme.load();
	readme.mOverlay = true;

	ofxControlPanel::setBackgroundColor(simpleColor(0, 0, 0, 200));
	ofxControlPanel::setTextColor(simpleColor(255, 0, 128, 255));
	ofxControlPanel::setForegroundColor(simpleColor(64, 64, 64, 255));

	//gui.loadFont("monaco.ttf", 8);
	gui.setup("Shader Texture Blending", 10, 10, 570, ofGetHeight()-40);
	ofxControlPanel::setBackgroundColor(simpleColor(0, 0, 0, 50));
	gui.addPanel("Shader settings", 3, false);

	ofxControlPanel::setBackgroundColor(simpleColor(255, 255, 255, 10));

	//--------- PANEL 1
	gui.setWhichPanel(0);

	gui.setWhichColumn(0);
	gui.addDrawableRect("Base Texture", &imgBase, 150, 150);

	listerBase.listDir("images/");
	listerBase.setSelectedFile(0);
	imgBase.loadImage( listerBase.getSelectedPath() );
	guiTypeFileLister * guiBaseLister = gui.addFileLister("Base Chooser", &listerBase, 150, 300);
	guiBaseLister->selection = 0;
	guiBaseLister->notify();

	//--------------------

	gui.setWhichColumn(1);
	gui.addDrawableRect("Blend Texture", &imgBlend, 150, 150);

	listerBlend.listDir("images/");
	listerBlend.setSelectedFile(1);
	imgBlend.loadImage( listerBlend.getSelectedPath() );
	guiTypeFileLister * guiBlendLister = gui.addFileLister("Blend Chooser", &listerBlend, 150, 300);
	guiBlendLister->selection = 1;

	//some dummy vars we will update to show the variable lister object
	elapsedTime		= ofGetElapsedTimef();
	appFrameCount	= ofGetFrameNum();
	appFrameRate	= ofGetFrameRate();

	//--------------------

	gui.setWhichColumn(2);

	//gui.addSlider("motion threshold", "MOTION_THRESHOLD", 29.0, 1.0, 255.0, false);
	gui.addSlider("Contrast","SHADER_CONTRAST", shadeContrast, 0.0, 5.0, false);
	gui.addSlider("Brightness","SHADER_BRIGHTNESS", shadeBrightness, -1.0, 1.0, false);
    gui.addSlider("Blend Mix","SHADER_BLENDMIX", shadeBlendMix, 0.0, 1.0, false);

	vector <string> blendmodes;
    blendmodes.push_back("Normal");
    blendmodes.push_back("Lighten");
    blendmodes.push_back("Darken");
    blendmodes.push_back("Multiply");
    blendmodes.push_back("Average");
    blendmodes.push_back("Add");
    blendmodes.push_back("Substract");
    blendmodes.push_back("Difference");
    blendmodes.push_back("Negation");
    blendmodes.push_back("Exclusion");
    blendmodes.push_back("Screen");
    blendmodes.push_back("Overlay");
    blendmodes.push_back("SoftLight");
    blendmodes.push_back("HardLight");
    blendmodes.push_back("ColorDodge");
    blendmodes.push_back("ColorBurn");
    blendmodes.push_back("LinearDodge");
    blendmodes.push_back("LinearBurn");
    blendmodes.push_back("LinearLight");
    blendmodes.push_back("VividLight");
    blendmodes.push_back("PinLight");
    blendmodes.push_back("HardMix");
    blendmodes.push_back("Reflect");
    blendmodes.push_back("Glow");
    blendmodes.push_back("Phoenix");

	//ofxControlPanel::setBackgroundColor(simpleColor(0, 0, 0, 255));
    gui.addTextDropDown("Blendmode", "SHADER_BLENDMODE", shadeBlendMode, blendmodes);
	//ofxControlPanel::setBackgroundColor(simpleColor(255, 255, 255, 10));

	//SETTINGS AND EVENTS

	//load from xml!
	gui.loadSettings("controlPanelSettings.xml");

	//if you want to use events call this after you have added all your gui elements
	gui.setupEvents();
	gui.enableEvents();

//  -- this gives you back an ofEvent for all events in this control panel object
	ofAddListener(gui.guiEvent, this, &testApp::guiEvents);

    shader.setup( "shaders/myShader" );
}


//this captures all our control panel events - unless its setup differently in testApp::setup
//--------------------------------------------------------------
void testApp::guiEvents(guiCallbackData & data){

    if ( data.getDisplayName() == "Base Chooser" ) {
        imgBase.loadImage( data.getString(1) );
    } else if ( data.getDisplayName() == "Blend Chooser" ) {
        imgBlend.loadImage( data.getString(1) );
    }
}

//--------------------------------------------------------------
void testApp::update(){
	//some dummy vars we will update to show the variable lister object
	elapsedTime		= ofGetElapsedTimef();
	appFrameCount	= ofGetFrameNum();
	appFrameRate	= ofGetFrameRate();

    shadeBlendMode = gui.getValueI("SHADER_BLENDMODE");
    shadeBlendMix = gui.getValueF("SHADER_BLENDMIX");
	shadeContrast = gui.getValueF("SHADER_CONTRAST");
	shadeBrightness = gui.getValueF("SHADER_BRIGHTNESS");

	gui.update();
}

//--------------------------------------------------------------
void testApp::draw(){
	ofSetColor(0xffffff);

    //------------------ image
    shader.begin();
    shader.setUniform( "contrast", shadeContrast );
    shader.setUniform( "brightness", shadeBrightness );
    shader.setUniform( "blendmix", shadeBlendMix );
    shader.setUniform( "blendmode", shadeBlendMode );
    //shader.setTexture( "texBase", imgBase, 0 );
    shader.setTexture( "texBlend", imgBlend, 1 );

	imgBase.draw ( 650, 10 );

    shader.end();

    //----------------- gui
	ofSetLineWidth(2);
	ofDisableSmoothing();
	gui.draw();

	//----------------- readme
	readme.draw();
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){
    readme.hide();
}

//--------------------------------------------------------------
void testApp::keyReleased  (int key){
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	gui.mouseDragged(x, y, button);
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	gui.mousePressed(x, y, button);
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
	gui.mouseReleased();
}
