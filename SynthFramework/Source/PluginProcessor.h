/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "SynthSound.h"
#include "SynthVoice.h"

#define ATTACK_ID "attack"
#define ATTACK_NAME "Attack"

#define RELEASE_ID "release"
#define RELEASE_NAME "Release"

#define DECAY_ID "decay"
#define DECAY_NAME "Decay"

#define SUSTAIN_ID "sustain"
#define SUSTAIN_NAME "Sustain"

#define WAVE_ID "wavetype"
#define WAVE_NAME "Wavetype"

#define CUTOFF_ID "cutoff"
#define CUTOFF_NAME "Cutoff"

#define RES_ID "res"
#define RES_NAME "Res"

#define FILTERTYPE_ID "filtertype"
#define FILTERTYPE_NAME "Filtertype"

class Visualizer : public AudioVisualiserComponent
{
public:
    Visualizer() : AudioVisualiserComponent(2)
    {
        setBufferSize(128);
        setSamplesPerBlock(16);
        setColours(Colours::black, Colours::indianred);
    }
    
};
//==============================================================================
/**
*/
class SynthFrameworkAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    SynthFrameworkAudioProcessor();
    ~SynthFrameworkAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (AudioBuffer<float>&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
    
    
    float attackTime;
    float releaseTime;
    float decayTime;
    float sustain;
    Visualizer visualizer;
    AudioProcessorValueTreeState treeState;
private:
    Synthesiser mySynth;
    SynthVoice* myVoice;
    
    

    
    double lastSampleRate;
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SynthFrameworkAudioProcessor)
};
