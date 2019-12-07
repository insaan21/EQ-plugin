/*
  ==============================================================================

    Wall.h
    Created: 29 Nov 2019 11:24:30am
    Author:  Ishaan Guha

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "DoorComponent.h"


//==============================================================================
/*
*/
class Wall    : public Component
{
public:
    Wall();
    ~Wall();

    void paint (Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Wall)
     DoorComponent door;
};
