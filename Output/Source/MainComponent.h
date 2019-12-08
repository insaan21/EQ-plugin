/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent   : public AudioAppComponent,
                        public Slider:: Listener

{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent();

    //==============================================================================
    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override;
    void getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill) override;
    void releaseResources() override;

    //==============================================================================
    void paint (Graphics& g) override;
    void resized() override;
    
    
    void sliderValueChanged (Slider * slider) override
    {
        if(slider == &freqSlider){
            
            frequency = freqSlider.getValue();
        }
        else if(slider == &ampSlider){
            amplitude = ampSlider.getValue();
        }
        
    }
    
    void updateFreq()
    {
        increment = frequency * waveTableLength/currSampleRate;
        phase = fmod((phase + increment), waveTableLength);
    }
    
    float updateAmp(){
        
        float value = waveTable[(int) phase] * amplitude;
        return value;
    }

    

private:
    //==============================================================================
    // Your private member variables go here...
    
    Slider freqSlider;
    Slider ampSlider;
    
    Label freqLabel;
    Label ampLabel;
    
    Random random;
    Array<float> waveTable;
    double waveTableLength;
    double frequency;
    double phase;
    double increment;
    double amplitude;
    double currSampleRate;
    
    float* leftSpeaker;
    float* rightSpeaker;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
