/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
Omenkeukwu_Sochima_compressorAudioProcessorEditor::Omenkeukwu_Sochima_compressorAudioProcessorEditor (Omenkeukwu_Sochima_compressorAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    
    
    //Setting the width and height of the window
    auto width = 500;
    auto height = 600;
    setSize (width, height);
    
    //Making the window non resizable
    setResizable(false, false);
    
    //Custom colours using hex values
    auto myOrange = 0xffcb4509;
    auto myPurple = 0xff8904ba;
    
    getLookAndFeel().setColour(juce::Slider::thumbColourId, juce::Colour(myPurple));
    getLookAndFeel().setColour(juce::Slider::rotarySliderFillColourId, juce::Colour(myOrange));
    getLookAndFeel().setColour(juce::Slider::textBoxOutlineColourId, juce::Colour(myOrange));
   
//
    //Plugin Label
    pluginLabel.setText("Dreaded Dynamics", juce::dontSendNotification);
    pluginLabel.setFont(juce::Font("Creepster",48.0f, juce::Font::bold ));
    pluginLabel.setJustificationType(juce::Justification::horizontallyCentred);
    pluginLabel.setColour(juce::Label::textColourId, juce::Colour(myOrange));
    addAndMakeVisible(pluginLabel);
    
    //Presets
    presetsMenu.setText("Presets");
    presetsMenu.addItem("Preset 1", 1);
    presetsMenu.addItem("Preset 2", 2);
    presetsMenu.addItem("Preset 3", 3);
    presetsMenu.setJustificationType(juce::Justification::centred);
    presetsMenu.setColour(juce::ComboBox::backgroundColourId, juce::Colour(myOrange));
    presetsMenu.setColour(juce::ComboBox::buttonColourId, juce::Colour(myOrange));
    presetsMenu.setColour(juce::ComboBox::textColourId, juce::Colours::white);
   
    addAndMakeVisible(presetsMenu);
    
    
    
    
    //Bypass Button
    bypassButton.setButtonText("Bypass");
    bypassButton.setClickingTogglesState(true);
    bypassButton.setColour(juce::TextButton::buttonColourId, juce::Colour(myPurple));
    bypassButton.setColour(juce::TextButton::buttonOnColourId, juce::Colour(myOrange));
    addAndMakeVisible(bypassButton);
    
    
    
    //Mute Button
    muteButton.setButtonText("Mute");
    muteButton.setClickingTogglesState(true);
    muteButton.setColour(juce::TextButton::buttonColourId, juce::Colour(myPurple));
    muteButton.setColour(juce::TextButton::buttonOnColourId, juce::Colour(myOrange));
    addAndMakeVisible(muteButton);
    
   
    
    //Threshold Knob label
    
    thresholdLabel.setText("Threshold", juce::dontSendNotification);
   thresholdLabel.setFont(juce::Font("Coustard",16.0f, juce::Font::plain ));
    thresholdLabel.setJustificationType(juce::Justification::horizontallyCentred);
    thresholdLabel.setColour(juce::Label::textColourId, juce::Colours::white);
    addAndMakeVisible(thresholdLabel);
    
    
    //Threshold Knob
    
    thresholdKnob.setSliderStyle(juce::Slider::Rotary);
    thresholdKnob.setTextBoxStyle(juce::Slider::TextBoxBelow, true, width*0.2, height*0.05);
    thresholdKnob.setTextBoxIsEditable(true);
    thresholdKnob.setTextValueSuffix(" dB");
    thresholdKnob.setRange(-60, 0, 0.1);
    addAndMakeVisible(thresholdKnob);
    
    
    
    //Ratio Knob label
    
   ratioLabel.setText("Ratio", juce::dontSendNotification);
   ratioLabel.setFont(juce::Font("Coustard",16.0f, juce::Font::bold  ));
   ratioLabel.setJustificationType(juce::Justification::horizontallyCentred);
    ratioLabel.setColour(juce::Label::textColourId, juce::Colours::white);
    addAndMakeVisible(ratioLabel);
    
    
    //Ratio Knob
    ratioKnob.setSliderStyle(juce::Slider::Rotary);
    ratioKnob.setTextBoxStyle(juce::Slider::TextBoxBelow, true, width*0.2, height*0.05);
    ratioKnob.setTextBoxIsEditable(true);
    ratioKnob.setTextValueSuffix(" : 1");
    ratioKnob.setRange(1, 20, 1);
    addAndMakeVisible(ratioKnob);
    
    
    //Attack Knob label
    
   attackLabel.setText("Attack", juce::dontSendNotification);
   attackLabel.setFont(juce::Font("Coustard",16.0f, juce::Font::plain  ));
    attackLabel.setJustificationType(juce::Justification::horizontallyCentred);
    attackLabel.setColour(juce::Label::textColourId, juce::Colours::white);
    addAndMakeVisible(attackLabel);
    
    
    //Attack Knob
   attackKnob.setSliderStyle(juce::Slider::Rotary);
    attackKnob.setTextBoxStyle(juce::Slider::TextBoxBelow, true, width*0.2, height*0.05);
    attackKnob.setTextBoxIsEditable(true);
    attackKnob.setTextValueSuffix("ms");
   attackKnob.setRange(0.0,10.0, 0.01);
    addAndMakeVisible(attackKnob);
    
    
    //Release Knob label
    
    releaseLabel.setText("Release", juce::dontSendNotification);
   releaseLabel.setFont(juce::Font("Coustard",16.0f, juce::Font::plain  ));
    releaseLabel.setJustificationType(juce::Justification::horizontallyCentred);
    releaseLabel.setColour(juce::Label::textColourId, juce::Colours::white);
    addAndMakeVisible(releaseLabel);
    
    
    //Release Knob
    releaseKnob.setSliderStyle(juce::Slider::Rotary);
    releaseKnob.setTextBoxStyle(juce::Slider::TextBoxBelow, true, width*0.2, height*0.05);
    releaseKnob.setTextBoxIsEditable(true);
    releaseKnob.setTextValueSuffix(" ms");
    releaseKnob.setRange(0.0, 10.0, 0.01);
    addAndMakeVisible(releaseKnob);
    
    
    //Knee Knob label
    
    kneeLabel.setText("Knee", juce::dontSendNotification);
  kneeLabel.setFont(juce::Font("Coustard",16.0f, juce::Font::plain  ));
    kneeLabel.setJustificationType(juce::Justification::horizontallyCentred);
    kneeLabel.setColour(juce::Label::textColourId, juce::Colours::white);
    addAndMakeVisible(kneeLabel);
    
    
    //Knee Knob
    kneeKnob.setSliderStyle(juce::Slider::Rotary);
    kneeKnob.setTextBoxStyle(juce::Slider::TextBoxBelow, true, width*0.2, height*0.05);
    kneeKnob.setTextBoxIsEditable(true);
    kneeKnob.setRange(0.0, 1.0, 0.01);
    addAndMakeVisible(kneeKnob);
    
    
    //Wet/Dry Knob label
    
    wetDryLabel.setText("Wet/Dry", juce::dontSendNotification);
   wetDryLabel.setFont(juce::Font("Coustard",16.0f, juce::Font::plain  ));
   wetDryLabel.setJustificationType(juce::Justification::horizontallyCentred);
   wetDryLabel.setColour(juce::Label::textColourId, juce::Colours::white);
    addAndMakeVisible(wetDryLabel);
    
    
    //Wet/Dry Knob
   wetDryKnob.setSliderStyle(juce::Slider::Rotary);
    wetDryKnob.setTextBoxStyle(juce::Slider::TextBoxBelow, true, width*0.2, height*0.05);
    wetDryKnob.setTextBoxIsEditable(true);
    wetDryKnob.setRange(0.0, 1.0, 0.01);
    addAndMakeVisible(wetDryKnob);
    
    
    //Listeners for combobox, buttons and sliders
    presetsMenu.addListener(this);
    bypassButton.addListener(this);
    muteButton.addListener(this);
    thresholdKnob.addListener(this);
    ratioKnob.addListener(this);
    thresholdKnob.addListener(this);
    attackKnob.addListener(this);
    releaseKnob.addListener(this);
    wetDryKnob.addListener(this);
    kneeKnob.addListener(this);
    
    //Background Image
    myImage = juce::ImageCache::getFromMemory(BinaryData::eyestetixstudioVbsxhnDGlPIunsplash_jpg, BinaryData::eyestetixstudioVbsxhnDGlPIunsplash_jpgSize);
    
    
    
    DBG("AudioProcessorEditorConstructor");
}

Omenkeukwu_Sochima_compressorAudioProcessorEditor::~Omenkeukwu_Sochima_compressorAudioProcessorEditor()
{
    DBG("AudioProcessorEditorDeconstructor");
}

//==============================================================================
void Omenkeukwu_Sochima_compressorAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
//    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
    
    //Border and corner radio for main rectangles
    auto border = 5;
    auto cornerRadius = 10;
    
    auto area = getLocalBounds().toFloat().reduced(border*4);
    auto areaRatioH = 0.2;
    
    
    auto areaHeight = area.getHeight();
    
   
    
    //First sub rectangle
    auto upperArea = area.removeFromTop(areaHeight*areaRatioH);
    
    //Second sub rectangle
    auto lowerArea = area.removeFromBottom(areaHeight*(areaRatioH*3.5));
    
    
    
    
    
    //Adding the background Image and making it fit in the window
    g.drawImage(myImage, getLocalBounds().toFloat());
    
    
    //Setting the color of the main upper rectangle and adding a corner radius
    g.setColour(juce::Colour(0xD9160518));
    g.fillRoundedRectangle(upperArea, cornerRadius);

   
   
   
    //Setting the color of the main lower rectangle and adding a corner radius
    g.setColour(juce::Colour(0xD9160518));
    g.fillRoundedRectangle(lowerArea, cornerRadius);
    
    

   
    
    

   
   
    
}

void Omenkeukwu_Sochima_compressorAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    
    auto border = 5;
    
    //area is the area of the main rectangle reduced by a certain amount
    auto area = getLocalBounds().toFloat().reduced(border*4);
    auto areaRatioH = 0.2;
    
    
   //Getting the area width and height of main area
    
    auto areaHeight = area.getHeight();
    
    
    
    auto upperRatioHeight = 0.65;
    auto upperRatioWidth = 0.4;
    
    //Creating the reactangle for the upper area
    auto upperArea = area.removeFromTop(areaHeight*areaRatioH);
    auto upperAreaHeight = upperArea.getHeight();
    auto upperAreaWidth = upperArea.getWidth();
    
    //Creating the rectangle for the plugin label
    auto pluginLabelArea = upperArea.removeFromTop(upperAreaHeight*upperRatioHeight);
    
    
    //Creating the rectangle for the presets menu
    auto presetsMenuArea = upperArea.removeFromRight(upperAreaWidth*upperRatioWidth);
    
    
    //Creating the rectangle for the lower rectangle
    auto lowerArea = area.removeFromBottom(areaHeight*(areaRatioH*3.5));
    
    //Defining the ratio of lower rectangle columns
    auto lowerAreaRatioWidth = 1.0/3.0;
    
    //Getting the width and height of he lower rectangle
    auto lowerAreaHeight = lowerArea.getHeight();
    auto lowerAreaWidth = lowerArea.getWidth();
    
   
    
    //Defining the first row of the lower rectangpe and its components
    auto upperLowerArea = lowerArea.removeFromTop(lowerAreaHeight*0.2);
    auto bypassButtonArea = upperLowerArea.removeFromLeft(lowerAreaWidth*0.475);
    auto muteButtonArea = upperLowerArea.removeFromRight(lowerAreaWidth*0.475);
    
    
    
    
    
    //Defining the second row of the lower rectangle and its components
    auto middleLowerArea = lowerArea.removeFromTop(lowerAreaHeight*0.4);
    
    auto thresHoldArea = middleLowerArea.removeFromLeft(lowerAreaWidth*lowerAreaRatioWidth);
    auto thresHoldLabelArea = thresHoldArea.removeFromTop(thresHoldArea.getHeight()*0.175);
    
    auto ratioArea = middleLowerArea.removeFromLeft(lowerAreaWidth*lowerAreaRatioWidth);
    auto ratioLabelArea = ratioArea.removeFromTop(ratioArea.getHeight()*0.175);
    
    auto kneeArea = middleLowerArea;
    auto kneeLabelArea = kneeArea.removeFromTop(kneeArea.getHeight()*0.175);
    
    
    
    //Defing the third row of the lower rectangle and its components
    auto lowestArea = lowerArea;
    
    auto attackArea = lowestArea.removeFromLeft(lowerAreaWidth*lowerAreaRatioWidth);
    auto attackLabelArea = attackArea.removeFromTop(attackArea.getHeight()*0.175);
    
    auto releaseArea = lowestArea.removeFromLeft(lowerAreaWidth*lowerAreaRatioWidth);
    auto releaseLabelArea = releaseArea.removeFromTop(releaseArea.getHeight()*0.175);
    
    auto wetDryArea = lowestArea;
    auto wetDryLabelArea = wetDryArea.removeFromTop(wetDryArea.getHeight()*0.175);
    
    
    
    
    
    
    

   
    

    //Setting the bounds for all components
    pluginLabel.setBounds(pluginLabelArea.toNearestInt().reduced(border));
    presetsMenu.setBounds(presetsMenuArea.toNearestInt().reduced(border));
    bypassButton.setBounds(bypassButtonArea.toNearestInt().reduced(border));
    muteButton.setBounds(muteButtonArea.toNearestInt().reduced(border));
    
    thresholdLabel.setBounds(thresHoldLabelArea.toNearestInt().reduced(border));
    thresholdKnob.setBounds(thresHoldArea.toNearestInt().reduced(border));
    
    ratioLabel.setBounds(ratioLabelArea.toNearestInt().reduced(border));
    ratioKnob.setBounds(ratioArea.toNearestInt().reduced(border));
    
    attackLabel.setBounds(attackLabelArea.toNearestInt().reduced(border));
    attackKnob.setBounds(attackArea.toNearestInt().reduced(border));
    
    releaseLabel.setBounds(releaseLabelArea.toNearestInt().reduced(border));
    releaseKnob.setBounds(releaseArea.toNearestInt().reduced(border));
   
    kneeLabel.setBounds(kneeLabelArea.toNearestInt().reduced(border));
    kneeKnob.setBounds(kneeArea.toNearestInt().reduced(border));
    
    wetDryLabel.setBounds(wetDryLabelArea.toNearestInt().reduced(border));
    wetDryKnob.setBounds(wetDryArea.toNearestInt().reduced(border));
    
    
    //Setting the fill type of the image
    myImage = myImage.rescaled(getWidth(), getHeight(),juce::Graphics::highResamplingQuality);
    
    
    
}


//Listener function definition for Prset Menu

void Omenkeukwu_Sochima_compressorAudioProcessorEditor::comboBoxChanged (juce::ComboBox* comboBoxThatHasChanged)
{
    if(comboBoxThatHasChanged->getText() == "Preset 1")
    {
        
        DBG("Preset 1");
    }
    
    else if(comboBoxThatHasChanged->getText() == "Preset 2")
    {
        DBG("Preset 2");
    }

    else
    {
        DBG("Preset 3");
    }

   
}

//Listener function definition for Buttons

void Omenkeukwu_Sochima_compressorAudioProcessorEditor::buttonStateChanged(juce::Button * button)
{
    if (button == &bypassButton)
    {
        if(bypassButton.getToggleState() == true)
        {
            DBG("bypass on");
        
        }
        
        else
        {
            DBG("bypass off");
        }
    }
    
    
    else if(button == &muteButton)
    {
        if(muteButton.getToggleStateValue() == true)
        {
            DBG("mute");
            
        }
        else
        {
            DBG("unmute");
        }
        
        
    }
}


//Listener function definition for click button listener
void Omenkeukwu_Sochima_compressorAudioProcessorEditor::buttonClicked(juce::Button* button)
{
    DBG("button Clicked!");


}


//Listener function definition for rotary sliders
void Omenkeukwu_Sochima_compressorAudioProcessorEditor::sliderValueChanged(juce::Slider* slider)
{
    if(slider == &thresholdKnob)
    {
        DBG("threshold = " <<(*slider).getValue() <<" dB");
        
    }
    else if(slider == &ratioKnob)
    {
        DBG("ratio = " <<(*slider).getValue() << ":1");
        
    }
    
    else if(slider == &attackKnob)
    {
        DBG("attack = " <<(*slider).getValue() << " ms");
        
    }
    
    else if(slider == &releaseKnob)
    {
        DBG("release = " <<(*slider).getValue() << " ms");
        
    }
    
    else if(slider == &kneeKnob)
    {
        DBG("knee = " <<(*slider).getValue());
        
    }
    
    else
    {
        DBG("wet/dry = " <<(*slider).getValue());
        
    }
}
