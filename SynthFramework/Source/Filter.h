/*
  ==============================================================================

    Filter.h
    Created: 15 Dec 2019 4:12:40pm
    Author:  Ishaan  Guha

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
//==============================================================================
/*
*/
class Filter    : public Component
{
public:
    Filter(SynthFrameworkAudioProcessor&);
    ~Filter();

    void paint (Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    SynthFrameworkAudioProcessor& processor;
    
    ComboBox filterMenu;
    
    
    Slider filterCutoff;
    Slider filterResonance;
    
    std::unique_ptr<AudioProcessorValueTreeState::ComboBoxAttachment> filterTypeVal;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> cutOffVal;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> resVal;
    
    
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Filter)
};
