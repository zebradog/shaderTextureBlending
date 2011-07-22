#pragma once

#include "ofMain.h"
#include "simpleColor.h"
#include <fstream>

class Readme {

    public:
        Readme ();
        void load ();
        void load ( string filname );

        void draw ();

        void show ();
        void hide ();
        void toggleView ();

        vector<string> mContent;
        string mNote;
        bool mHidden;

        string mFilename;

        bool mOverlay;

        simpleColor mColorContent;
        simpleColor mColorNote;
        simpleColor mColorBackground;
        simpleColor mColorBorder;
        simpleColor mColorOverlay;

        float mBorderWidth;
        float mPadding;
        float mLineHeight;

};
