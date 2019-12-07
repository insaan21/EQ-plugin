/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

class OtherLookAndFeel : public LookAndFeel_V4
{
public:
    void drawRotarySlider(Graphics &g, int x, int y, int width, int height, float sliderPosProportional, float rotaryStartAngle, float rotaryEndAngle, Slider &slider) override
    {
        Rectangle<float> dialArea (x, y, width, height);
        
        g.setColour(Colours:: red);
        g.fillEllipse(dialArea);
        g.drawRect(dialArea);
    }
        
        
};

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent   : public Component,
                        public Slider::Listener
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    
    void sliderValueChanged(Slider*slider) override
    {
        if(slider == &frequencyslider){
            durationSlider.setValue(1.0/ frequencyslider.getValue());
        }
        else if(slider == &durationSlider){
            frequencyslider.setValue(1.0/ durationSlider.getValue());
        }
    }

private:
    //==============================================================================
    // Your private member variables go here...

    Slider frequencyslider;
    Label frequencyLabel;
    
    Slider durationSlider;
    Label durationLabel;
    
    Slider dial1;
    Slider dial2;
    
    OtherLookAndFeel otherLook;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
