/*
  ==============================================================================

    Oscillator.h
    Created: 15 Dec 2019 1:57:52pm
    Author:  Ishaan  Guha

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"


//==============================================================================
/*
*/
class Oscillator    : public Component,
                      private ComboBox::Listener
{
public:
    Oscillator(SynthFrameworkAudioProcessor&);
    ~Oscillator();

    void paint (Graphics&) override;
    void resized() override;
    void comboBoxChanged(ComboBox*) override;

private:
   ComboBox oscMenu;
    
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    SynthFrameworkAudioProcessor& processor;
    std::unique_ptr<AudioProcessorValueTreeState::ComboBoxAttachment> waveSelection;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Oscillator)
};
