/*
  ==============================================================================

    Wall.cpp
    Created: 29 Nov 2019 11:24:30am
    Author:  Ishaan Guha

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "Wall.h"

//==============================================================================
Wall::Wall()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    addAndMakeVisible(door);

}

Wall::~Wall()
{
}

void Wall::paint (Graphics& g)
{
    Rectangle <float> wall(getWidth(), getHeight());
    g.fillCheckerBoard(wall, 20, 10, Colours:: sandybrown, Colours:: salmon);
    g.drawRect(wall);
    
}

void Wall::resized()
{
    door.setBounds((getWidth()/3), (getHeight()/1.5) ,(getWidth()/6), (getHeight()/3));
}
