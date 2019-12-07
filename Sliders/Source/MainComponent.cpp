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
    addAndMakeVisible(frequencyslider);
    frequencyslider.setRange(50, 5000);
    frequencyslider.setTextValueSuffix("Hz");
    addAndMakeVisible(frequencyLabel);
    frequencyLabel.setText("Frequency", dontSendNotification);
    frequencyLabel.attachToComponent(&frequencyslider, true);
    
    addAndMakeVisible(durationSlider);
    durationSlider.setRange((1.0/frequencyslider.getMaximum()), 1.0/(frequencyslider.getMinimum()));
    frequencyslider.setTextValueSuffix("s");
    addAndMakeVisible(durationLabel);
    durationLabel.setText("Duration", dontSendNotification);
    durationLabel.attachToComponent(&durationSlider, true);
    
    frequencyslider.addListener(this);
    durationSlider.addListener(this);
    
    frequencyslider.setValue(500.0);
    
    frequencyslider.setSkewFactorFromMidPoint(500.0);
    durationSlider.setSkewFactorFromMidPoint(0.002);
    
    addAndMakeVisible(dial1);
    addAndMakeVisible(dial2);
    dial1.setSliderStyle(Slider:: SliderStyle :: RotaryHorizontalVerticalDrag);
    dial2.setSliderStyle(Slider:: SliderStyle :: Rotary);
    dial1.setTextBoxStyle(Slider::TextBoxBelow, true, 100, 25);
    dial2.setTextBoxStyle(Slider::TextBoxBelow, true, 100, 25);
    
    // getLookAndFeel().setColour(Slider::thumbColourId, Colours:: purple);
    
    otherLook.setColour(Slider::thumbColourId, Colours:: purple);
    otherLook.setColour(Slider:: rotarySliderFillColourId, Colours:: azure);
    dial1.setLookAndFeel(&otherLook);
    
    
    
    
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
    frequencyslider.setBounds(getWidth()/3, getHeight()/3, (getWidth())/3, (getHeight())/3);
    durationSlider.setBounds(getWidth()/3, (2*getHeight()/3), (getWidth())/3, (getHeight())/3);
    dial1.setBounds(getWidth()/3, getHeight()/5, 100, 100);
    dial2.setBounds((2*getWidth()/3), getHeight()/5, 100, 100);
    
}
