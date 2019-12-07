/*
  ==============================================================================

    DoorComponent.h
    Created: 29 Nov 2019 9:56:22pm
    Author:  Ishaan Guha

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class DoorComponent    : public Component
{
public:
    DoorComponent();
    ~DoorComponent();

    void paint (Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DoorComponent)
};
