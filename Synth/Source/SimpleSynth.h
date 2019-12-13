/*
  ==============================================================================

    SimpleSynth.h
    Created: 13 Dec 2019 12:13:10am
    Author:  Ishaan  Guha

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class SimpleSynth : public Synthesiser {
public:
    void setup();
private:
    // manager object that finds an appropriate way to decode various audio files.  Used with SampleSound objects.
    AudioFormatManager audioFormatManager;
};
