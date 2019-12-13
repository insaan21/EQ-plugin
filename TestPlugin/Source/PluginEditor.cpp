/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
TestPluginAudioProcessorEditor::TestPluginAudioProcessorEditor (TestPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    sliderAttach = std::make_unique<AudioProcessorValueTreeState:: SliderAttachment>(processor.treeState, GAIN_ID, gainSlider);
    setSize (400, 400);
    gainSlider.setSliderStyle(Slider:: SliderStyle:: LinearVertical);
    gainSlider.setRange(-48.0f, 0.0f);
    // gainSlider.setValue(-1.0);
    gainSlider.setTextBoxStyle(Slider:: TextBoxBelow, true, 100, 25);
    gainSlider.addListener(this);
    addAndMakeVisible(gainSlider);
    
    
}

TestPluginAudioProcessorEditor::~TestPluginAudioProcessorEditor()
{
}

//==============================================================================
void TestPluginAudioProcessorEditor::paint (Graphics& g)
{
    g.fillAll(getLookAndFeel().findColour(ResizableWindow :: backgroundColourId));
}

void TestPluginAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    gainSlider.setBounds(getWidth()/3, getHeight()/3, 100, 100);
}

void TestPluginAudioProcessorEditor:: sliderValueChanged(Slider *slider){
    
    if(slider == &gainSlider){
        processor.rawVolume = gainSlider.getValue();
    }
}


// unused anymore

//double TestPluginAudioProcessorEditor:: volume(double currDB)
//    {
//        double volume = pow(10.0, (currDB/20.0));
//        return volume;
//    }
//

