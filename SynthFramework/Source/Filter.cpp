/*
  ==============================================================================

    Filter.cpp
    Created: 15 Dec 2019 4:12:40pm
    Author:  Ishaan  Guha

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "Filter.h"

//==============================================================================
Filter::Filter(SynthFrameworkAudioProcessor& p): processor(p)

{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    setSize(200, 200);
    
    filterMenu.addItem("Low Pass", 1);
    filterMenu.addItem("High Pass", 2);
    filterMenu.addItem("Band Pass", 3);
    filterMenu.setJustificationType(Justification::centred);
    addAndMakeVisible(&filterMenu);
    filterTypeVal = std::make_unique<AudioProcessorValueTreeState::ComboBoxAttachment>(processor.treeState, FILTERTYPE_ID, filterMenu);
    
    filterCutoff.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    filterCutoff.setRange(20.0, 10000.0);
    filterCutoff.setValue(400.0);
    filterCutoff.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    //filterCutoff.setVelocityModeParameters(0.2, 20, 0.0, true, ModifierKeys::ctrlAltCommandModifiers);
    addAndMakeVisible(&filterCutoff);
    cutOffVal = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.treeState, CUTOFF_ID, filterCutoff);
    filterCutoff.setSkewFactorFromMidPoint(1000.0);
    
    
    
    filterResonance.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    filterResonance.setRange(1.0, 5.0);
    filterResonance.setValue(1.0);
    filterResonance.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    //filterResonance.setVelocityModeParameters(0.2, 20, 0.0, true, ModifierKeys::ctrlAltCommandModifiers);
    addAndMakeVisible(&filterResonance);
    resVal = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.treeState, RES_ID, filterResonance);
        
}

Filter::~Filter()
{
}

void Filter::paint (Graphics& g)
{
    Rectangle<int> titleArea(0, 10, getWidth(), 20);
    g.fillAll(Colours::black);
    g.setColour(Colours::white);
    g.drawText("Filter", titleArea, Justification::centredTop);
    
    Rectangle<float> area(25,25,150,150);
    g.setColour(Colours::orange);
    g.drawRoundedRectangle(area, 20.0f, 2.0f);
}

void Filter::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..
    Rectangle<int> area = getLocalBounds().reduced(40);
    
    filterMenu.setBounds(area.removeFromTop(20));
    filterCutoff.setBounds(30, 100, 70, 70);
    filterResonance.setBounds(100, 100, 70, 70);

}
