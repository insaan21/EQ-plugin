/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    setSize (600, 400);
    dial1.setSliderStyle(Slider:: SliderStyle:: Rotary);
    dial1.setTextBoxStyle(Slider::TextBoxBelow, false,50, 20);
    addAndMakeVisible(wall);
    addAndMakeVisible(dial1);
}

MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::paint (Graphics& g)
{
    
}

void MainComponent::resized()
{
    wall.setBounds(0,0, (getWidth()/3), (getHeight()/3));
    Rectangle<int> area = getLocalBounds();
    area.removeFromTop((area.getHeight()/2));
    dial1.setBounds(area);
    
}
/Users/ishaanguha/ISM/JUCE/House/Builds/MacOSX
