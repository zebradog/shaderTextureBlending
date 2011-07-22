This program demonstrates the use of ofxShader to mix multiple textures in a 
GLSL shader. It uses ofxControlPanel as a GUI to set the paramaters. The blend
modes you'll find in this program are similar to those in Adobe Photoshop.

 - How to use - 
In the control panel you can set a (different) Base or Blend image by double-
clicking on a file listed in the appropriate 'Chooser' just below the preview.
In the right column of the control panel you find sliders and a dropdown list
that will allow you to change the shader parameters.
The contrast and brightness is applied after blending the Base and Blend image.
The Blend Mix parameter allows you to dim the effect of the blending where a 0.0
value represents the original Base image and 1.0 value the blended Base + Blend
image.

ofxControlPanel: 9af6e4719fdc0c4ab47b by ofTheo (Theo Watson) September 01, 2010
github.com/ofTheo/ofxControlPanel/tree/156b498f3ad621fd35f920d2a420ee1f3dcd1511

ofxSahder: r81 by kylecimcdonald on August 08, 2010
code.google.com/p/kyle/source/browse/trunk/openframeworks/addons/ofxShader/

Photoshop Math Shaders by Romain Dura on January 05, 2009
http://blog.mouaif.org/?p=94

more info: http://blog.ruudbijnen.nl/