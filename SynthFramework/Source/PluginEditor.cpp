/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SynthFrameworkAudioProcessorEditor::SynthFrameworkAudioProcessorEditor (SynthFrameworkAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
    
    attackSlider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    attackSlider.setRange(0.1, 5000.0);
    attackSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 100, 25);
    attackSlider.addListener(this);
    addAndMakeVisible(attackSlider);
    sliderAttach = std::make_unique<AudioProcessorValueTreeState:: SliderAttachment>(processor.treeState, ATTACK_ID, attackSlider); 
    
    releaseSlider.setSliderStyle(Slider::SliderStyle::RotaryHorizontalDrag);
    releaseSlider.setRange(0.1, 10000.0);
    releaseSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 100, 25);
    releaseSlider.addListener(this);
    addAndMakeVisible(releaseSlider);
    releaseAttach = std::make_unique<AudioProcessorValueTreeState:: SliderAttachment>(processor.treeState, RELEASE_ID, releaseSlider);
}


SynthFrameworkAudioProcessorEditor::~SynthFrameworkAudioProcessorEditor()
{
}

//==============================================================================
void SynthFrameworkAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

}

void SynthFrameworkAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    attackSlider.setBounds(getWidth()/3, getHeight()/3, getWidth()/3, getHeight()/3);
    releaseSlider.setBounds(2*getWidth()/3, 2*getHeight()/3, getWidth()/3, getHeight()/3);
}

void SynthFrameworkAudioProcessorEditor::sliderValueChanged(Slider *slider){
    if(slider == &attackSlider){
        processor.attackTime = attackSlider.getValue();
    }
    else if(slider == &releaseSlider){
        processor.releaseTime = releaseSlider.getValue();
    }
}
