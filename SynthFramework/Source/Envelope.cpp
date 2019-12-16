/*
  ==============================================================================

    Envelope.cpp
    Created: 15 Dec 2019 3:43:27pm
    Author:  Ishaan  Guha

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "Envelope.h"

//==============================================================================
Envelope::Envelope(SynthFrameworkAudioProcessor& p): processor(p)
{
    setSize(200,200);
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
     attackSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
     attackSlider.setRange(0.1, 5000.0);
     attackSlider.setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
     addAndMakeVisible(&attackSlider);
     attackAttach = std::make_unique<AudioProcessorValueTreeState:: SliderAttachment>(processor.treeState, ATTACK_ID, attackSlider);

     releaseSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
     releaseSlider.setRange(0.1, 10000.0);
     releaseSlider.setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
     addAndMakeVisible(&releaseSlider);
     releaseAttach = std::make_unique<AudioProcessorValueTreeState:: SliderAttachment>(processor.treeState, RELEASE_ID, releaseSlider);

     decaySlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
     decaySlider.setRange(0.1, 10000.0);
     decaySlider.setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
     addAndMakeVisible(&decaySlider);
     decayAttach = std::make_unique<AudioProcessorValueTreeState:: SliderAttachment>(processor.treeState, DECAY_ID, decaySlider);

     sustainSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
     sustainSlider.setRange(0.0, 1.0);
     sustainSlider.setTextBoxStyle(Slider::NoTextBox, true, 0,0);
     addAndMakeVisible(&sustainSlider);
     sustainAttach = std::make_unique<AudioProcessorValueTreeState:: SliderAttachment>(processor.treeState, SUSTAIN_ID, sustainSlider);

}

Envelope::~Envelope()
{
}

void Envelope::paint (Graphics& g)
{
    g.fillAll(Colours::black);
    
    Rectangle<int> titleArea(0,10,getWidth(), 20);
    g.setColour(Colours::white);
    g.drawText("Envelope", titleArea, Justification::centredTop);
    
    g.drawText("A", 53, 150, 20, 20,  Justification::centredTop);
    g.drawText("D", 77, 150, 20, 20,  Justification::centredTop);
    g.drawText("S", 103, 150, 20, 20,  Justification::centredTop);
    g.drawText("R", 128, 150, 20, 20,  Justification::centredTop);
    
    Rectangle<float> area(25,25,150, 150);
    g.setColour(Colours::orange);
    g.drawRoundedRectangle(area, 20.0f, 2.0f);
}

void Envelope::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..
    Rectangle<int> area =getLocalBounds().reduced(40);
    int sliderWidth = 25;
    int sliderHeight = 175;
    attackSlider.setBounds(area.removeFromLeft(sliderWidth).removeFromTop(sliderHeight).withTrimmedTop(10));
    decaySlider.setBounds(area.removeFromLeft(sliderWidth).removeFromTop(sliderHeight).withTrimmedTop(10));
    sustainSlider.setBounds(area.removeFromLeft(sliderWidth).removeFromTop(sliderHeight).withTrimmedTop(10));
    releaseSlider.setBounds(area.removeFromLeft(sliderWidth).removeFromTop(sliderHeight).withTrimmedTop(10));
    
    
    

}


