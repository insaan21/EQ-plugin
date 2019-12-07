/*
  ==============================================================================

    DoorComponent.cpp
    Created: 29 Nov 2019 9:56:22pm
    Author:  Ishaan Guha

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "DoorComponent.h"

//==============================================================================
DoorComponent::DoorComponent()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

}

DoorComponent::~DoorComponent()
{
}

void DoorComponent::paint (Graphics& g)
{
    
    Rectangle <float> door(getWidth(), getHeight());
    g.setColour(Colours:: black);
    g.fillRect(door);
}

void DoorComponent::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}
