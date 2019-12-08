/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    // Make sure you set the size of the component after
    // you add any child components.
    setSize (800, 600);
    
    freqSlider.setSliderStyle(Slider::SliderStyle::LinearHorizontal);
    freqSlider.setRange(50.0, 500.0);
    freqSlider.addListener(this);
    freqSlider.setValue(200.0);
    freqSlider.setTextValueSuffix("Hz");
    addAndMakeVisible(freqSlider);
    freqLabel.setText("Frequency", dontSendNotification);
    freqLabel.attachToComponent(&freqSlider, true);
    
    
    ampSlider.setSliderStyle(Slider::SliderStyle::LinearHorizontal);
    ampSlider.setRange(0.0, 1.0);
    ampSlider.addListener(this);
    ampSlider.setValue(0.25);
    // ampSlider.setTextValueSuffix("Hz");
    addAndMakeVisible(ampSlider);
    ampLabel.setText("Amplitude", dontSendNotification);
    ampLabel.attachToComponent(&ampSlider, true);

    // Some platforms require permissions to open input channels so request that here
    if (RuntimePermissions::isRequired (RuntimePermissions::recordAudio)
        && ! RuntimePermissions::isGranted (RuntimePermissions::recordAudio))
    {
        RuntimePermissions::request (RuntimePermissions::recordAudio,
                                     [&] (bool granted) { if (granted)  setAudioChannels (2, 2); });
    }
    else
    {
        // Specify the number of input and output channels that we want to open
        setAudioChannels (2, 2);
    }
}

MainComponent::~MainComponent()
{
    // This shuts down the audio device and clears the audio source.
    shutdownAudio();
}

//==============================================================================
void MainComponent::prepareToPlay (int samplesPerBlockExpected, double sampleRate)
{
    frequency = freqSlider.getValue();
    phase = 0;
    waveTableLength = 1024;
    amplitude = ampSlider.getValue();
    currSampleRate = sampleRate;
    
    for (int i = 0; i < waveTableLength; ++i){
        waveTable.insert(i, sin(2.0 * double_Pi * i/waveTableLength));
    }
}

void MainComponent::getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill)
{
    
    
        float* const leftSpeaker = bufferToFill.buffer -> getWritePointer(0, bufferToFill.startSample);
        float* const rightSpeaker = bufferToFill.buffer -> getWritePointer(1, bufferToFill.startSample);
        //fills buffer w output
        for(int sample = 0; sample < bufferToFill.numSamples; ++sample)
        {
            leftSpeaker[sample] = waveTable[(int) phase] * amplitude;
            rightSpeaker[sample] = waveTable[(int) phase] * amplitude;
            updateFreq();
        }
    
    
    
} 

void MainComponent::releaseResources()
{
    // This will be called when the audio device stops, or when it is being
    // restarted due to a setting change.

    // For more details, see the help for AudioProcessor::releaseResources()
}

//==============================================================================
void MainComponent::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    // You can add your drawing code here!
}



void MainComponent::resized()
{
    // This is called when the MainContentComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
    freqSlider.setBounds(getWidth()/3, getHeight()/3, getWidth()/3, getHeight()/3);
    ampSlider.setBounds(getWidth()/3, 2*getHeight()/3, getWidth()/3, getHeight()/3);
    
}
