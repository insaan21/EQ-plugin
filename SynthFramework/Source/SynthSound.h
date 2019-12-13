/*
  ==============================================================================

    SynthSound.h
    Created: 13 Dec 2019 1:51:59am
    Author:  Ishaan  Guha

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class SynthSound : public SynthesiserSound
{
public:
    bool appliesToNote (int midiNoteNumber){
        return true;
    }
    
    bool appliesToChannel( int midiChannel){
        return true;
    }
};
