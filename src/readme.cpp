#include "readme.h"

Readme::Readme () {
    mHidden = true;
    mFilename = "readme.txt";
    mNote = "Press any key to hide this message.";
    mLineHeight = 12.0f;
    mBorderWidth = 1.0f;
    mPadding = 10.0f;
    mOverlay = false;
    mColorContent = simpleColor ( 255,  255,  255,  255 );
    mColorNote = simpleColor ( 170,  170,  170,  255 );
    mColorBorder = simpleColor ( 255,  255,  255,  255 );
    mColorBackground = simpleColor ( 0,  0,  0,  230 );
    mColorOverlay = simpleColor ( 0,  0,  0,  128 );
}

void Readme::load () {
    load ( mFilename );
}

void Readme::load ( string filename ) {

    ifstream fin;

    fin.open( ofToDataPath(filename).c_str() );
    while( fin!=NULL ) //as long as theres still text to be read
    {
        string str; //declare a string for storage
        getline(fin, str); //get a line from the file, put it in the string
        mContent.push_back(str); //push the string onto a vector of strings
    }
    if ( mContent.size() > 0 ) mHidden = false;
}

void Readme::draw ( ) {

    if ( !mHidden ) {
        float heightInternal = (mContent.size() + 2) * mLineHeight;
        float widthInternal = 81 * 8;

        ofPushMatrix ();
        ofPushStyle ();
        ofEnableAlphaBlending ();

        // draw overlay (if needed)
        if ( mOverlay ) {
            glColor4fv ( mColorOverlay.getColorF() );
            ofFill ();
            ofRect ( 0, 0, ofGetWidth(), ofGetHeight() );
        }

        ofTranslate ( ( ofGetWidth() - widthInternal ) / 2, ( ofGetHeight() - heightInternal ) / 2, 0 );

        // draw background
        glColor4fv ( mColorBackground.getColorF() );
        ofFill ();
        ofRect ( -mPadding, -mPadding, widthInternal + mPadding, heightInternal + mPadding );

        // draw border
        glColor4fv ( mColorBorder.getColorF() );
        ofNoFill ();
        ofRect ( -mPadding, -mPadding, widthInternal + mPadding, heightInternal + mPadding );

        // draw content (lines)
        glColor4fv ( mColorContent.getColorF() );
        for( int i = 0; i < mContent.size(); i++ ) {
            ofDrawBitmapString ( mContent[i], 0, mLineHeight + i * mLineHeight );
        }

        glColor4fv ( mColorNote.getColorF() );
        ofDrawBitmapString ( "Press any key to hide this message", 0, mLineHeight + mContent.size() * mLineHeight );

        ofDisableAlphaBlending ();
        ofPopStyle ();
        ofPopMatrix ();
    }
}

void Readme::show () {
    mHidden = false;
}
void Readme::hide () {
    mHidden = true;
}
void Readme::toggleView () {
    mHidden = !mHidden;
}
