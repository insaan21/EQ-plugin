/*
  ==============================================================================

    SynthVoice.h
    Created: 13 Dec 2019 1:52:07am
    Author:  Ishaan  Guha

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "SynthSound.h"
#include "maximilian.h"

class SynthVoice : public SynthesiserVoice
{
public:
    bool canPlaySound(SynthesiserSound* sound){
        return dynamic_cast<SynthSound*>(sound) != nullptr;
    }
    
    void getParam(float* attack, float*release){
        env1.setAttack(double(*attack));
        env1.setRelease(double(*release));
    }
    void startNote(int midiNoteNumber, float velocity, SynthesiserSound* sound, int currentPitchWheelPosition){
        env1.trigger = 1;
        level = velocity;
        frequency = MidiMessage::getMidiNoteInHertz(midiNoteNumber);
        std::cout<<midiNoteNumber<<std::endl;
    }
    
    void stopNote(float velocity, bool allowTailOff){
        env1.trigger = 0;
        allowTailOff = true;
        
        if (velocity == 0){
             clearCurrentNote();
        }
       
    }
    
    bool isVoiceActive(){
        return true;
    }
    
    void pitchWheelMoved(int newPitchWheelValue){
        
    }
    
    void controllerMoved(int controllerNumber, int newControllerValue){
        
    }
    
    void afterTouchChanged(int newAfterTouchValue){
        
    }
    
    void channelPressureChanged(int newChannelPressureValue){
        
    }
    
    void renderNextBlock(AudioBuffer<float> &outputBuffer, int startSample, int numSamples){
        // env1.setAttack(2000);
        env1.setDecay(500);
        env1.setSustain(0.8);
        
        
        for (int sample = 0; sample < numSamples; ++sample){
                   double theWave = osc1.saw(frequency) * level;
                   double theSound = env1.adsr(theWave, env1.trigger) * level;
                   double filteredSound = filter1.lores(theSound, 40, 0.1);
            
                   for(int channel = 0; channel < outputBuffer.getNumChannels(); ++channel){
                       outputBuffer.addSample(channel, startSample, filteredSound);
                   }
                   ++startSample;
               }
    }
    
    void renderNextBlock(AudioBuffer<double> &outputBuffer, int startSample, int numSamples){
        
        
       
    }
    
    void setCurrentPlaybackSampleRate(double newRate){
        
    } 
    
    bool isPlayingChannel(int midiChannel){
        return true;
    }
    
private:
    double level;
    double frequency;
    
    maxiOsc osc1;
    maxiEnv env1;
    maxiFilter filter1;
};
