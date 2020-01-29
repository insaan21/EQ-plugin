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
    
    void getParam(float* attack, float*release, float* decay, float*sustain){
        env1.setAttack(double(*attack));
        env1.setRelease(double(*release));
        env1.setDecay(double(*decay));
        env1.setSustain(double(*sustain));
        
        //2nd envelope
        env2.setAttack(double(*attack));
        env2.setRelease(double(*release));
        env2.setDecay(double(*decay));
        env2.setSustain(double(*sustain));
        
    }
    
    void getFilterParams(float* filterType, float* cutoff, float*res){
        filter = *filterType;
        cutOff = *cutoff;
        resonance = *res;
    }
    
    double setFilter(double input){
        //this overrides the cutOff slider
        cutOff = (env2.adsr(1, env2.trigger)*5000) + 100;
        
        if(filter == 0){
            return filter1.lores(input, cutOff, resonance);
        }
        else if(filter == 1){
            return filter1.hires(input, cutOff, resonance);
        }
        else if(filter == 2){
            return filter1.bandpass(input, cutOff, resonance);
        }
        else{
            return filter1.lores(input, cutOff, resonance);
        }
    }
    
    
    void getOscType(float* selection){
        theWave = *selection;
    }
    
    double setOscType(){
        if(theWave == 0){
            return osc1.sinewave(frequency);
        }
        else if(theWave  == 1){
            return osc1.saw(frequency);
        }
        else if(theWave == 2){
            return osc1.square(frequency);
        }
        else{
            return osc1.sinewave(frequency);
        }
    }
    void startNote(int midiNoteNumber, float velocity, SynthesiserSound* sound, int currentPitchWheelPosition){
        env1.trigger = 1;
        level = velocity;
        frequency = MidiMessage::getMidiNoteInHertz(midiNoteNumber);
        // std::cout<<midiNoteNumber<<std::endl;
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
        
        
        
        for (int sample = 0; sample < numSamples; ++sample){
                   double theSound = env1.adsr(setOscType(), env1.trigger);
                   theSound = (setFilter(theSound)*0.3f);
                   for(int channel = 0; channel < outputBuffer.getNumChannels(); ++channel){
                       outputBuffer.addSample(channel, startSample, theSound);
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
    int theWave;
    int filter;
    double cutOff;
    double resonance;
    maxiOsc osc1;
    maxiEnv env1;
    maxiFilter filter1;
    maxiEnv env2;
};
