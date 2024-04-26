/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class Omenkeukwu_Sochima_compressorAudioProcessorEditor  : public juce::AudioProcessorEditor
, private juce::Slider::Listener
, private juce::TextButton::Listener
, private juce::ComboBox::Listener
{
public:
    Omenkeukwu_Sochima_compressorAudioProcessorEditor (Omenkeukwu_Sochima_compressorAudioProcessor&);
    ~Omenkeukwu_Sochima_compressorAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    Omenkeukwu_Sochima_compressorAudioProcessor& audioProcessor;
    
    //Look and feeel Object
    juce::LookAndFeel_V4 otherLookAndFeel;
    
    
    //Label Objects
    juce::Label pluginLabel;
    juce::Label thresholdLabel;
    juce::Label ratioLabel;
    juce::Label attackLabel;
    juce::Label releaseLabel;
    juce::Label kneeLabel;
    juce::Label wetDryLabel;
    
    //ComboBox Menu Object
    juce::ComboBox presetsMenu;
    
    //Text Button Objects
    juce::TextButton bypassButton;
    juce::TextButton muteButton;
    
    //Rotary Slider Objects
    juce::Slider thresholdKnob;
    juce::Slider ratioKnob;
    juce::Slider attackKnob;
    juce::Slider releaseKnob;
    juce::Slider kneeKnob;
    juce::Slider wetDryKnob;
    
    juce::Image myImage;
    
    
    
    
    //Listening function prototypes

    void comboBoxChanged (juce::ComboBox* comboBoxThatHasChanged) override;
    void buttonClicked (juce::Button*) override;
    void buttonStateChanged (juce::Button *) override;
    void sliderValueChanged (juce::Slider* slider) override;

    
    
    
    
    
    

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Omenkeukwu_Sochima_compressorAudioProcessorEditor)
};
