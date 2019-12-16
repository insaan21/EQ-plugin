/*
  ==============================================================================

    Oscillator.cpp
    Created: 15 Dec 2019 1:57:52pm
    Author:  Ishaan  Guha

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "Oscillator.h"

//==============================================================================
Oscillator::Oscillator(SynthFrameworkAudioProcessor& p):
processor(p)
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    setSize(200, 200);
    oscMenu.addItem("Sine", 1);
    oscMenu.addItem("Saw", 2);
    oscMenu.addItem("Square", 3);
    oscMenu.setJustificationType(Justification::centred);
    addAndMakeVisible(&oscMenu);
    oscMenu.addListener(this);
    
    waveSelection = std::make_unique<AudioProcessorValueTreeState::ComboBoxAttachment>(processor.treeState, "wavetype", oscMenu);
}

Oscillator::~Oscillator()
{
}

void Oscillator::paint (Graphics& g)
{
    g.fillAll(Colours::black);
    
    Rectangle<int> titleArea (0, 10, getWidth(), 20);
    
    g.fillAll(Colours::black);
    g.setColour(Colours::white);
    g.drawText("Oscillator", titleArea, Justification::centredTop);
    
//    Rectangle<float> area (25,25,75,75);
 //   g.setColour(Colours::orange);
 //   g.drawRect(getLocalBounds());
}

void Oscillator::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..
    Rectangle<int> area = getLocalBounds().reduced(40);
    
    oscMenu.setBounds(area.removeFromTop(20));
    
}

void Oscillator::comboBoxChanged(ComboBox *comboBoxThatHasChanged){
    
}
