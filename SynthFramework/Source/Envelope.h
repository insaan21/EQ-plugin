/*
  ==============================================================================

    Envelope.h
    Created: 15 Dec 2019 3:43:27pm
    Author:  Ishaan  Guha

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================
/*
*/
class Envelope    : public Component

{
public:
    Envelope(SynthFrameworkAudioProcessor&);
    ~Envelope();

    void paint (Graphics&) override;
    void resized() override;

private:
    SynthFrameworkAudioProcessor& processor;
    
    Slider attackSlider;
    Slider releaseSlider;
    Slider decaySlider;
    Slider sustainSlider;
    
    Label attackLabel;
    Label releaseLabel;
    Label decayLabel;
    Label sustainLabel;
    
    
    std::unique_ptr <AudioProcessorValueTreeState:: SliderAttachment> attackAttach;
    std::unique_ptr <AudioProcessorValueTreeState:: SliderAttachment> releaseAttach;
    std::unique_ptr <AudioProcessorValueTreeState:: SliderAttachment> decayAttach;
    std::unique_ptr <AudioProcessorValueTreeState:: SliderAttachment> sustainAttach;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Envelope)
};
