/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
RapidAudioProcessorEditor::RapidAudioProcessorEditor (RapidAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    {
        // Make sure that before the constructor has finished, you've set the
        // editor's size to whatever you need it to be.
        setSize (400, 300);
        
        //Set the parameters of the gain slider
        gainSlider.setSliderStyle (juce::Slider::LinearVertical);
        gainSlider.setRange (0.0, 1.0, 0.01);
        gainSlider.setValue (0.5);
        gainSlider.setTextBoxStyle (juce::Slider::NoTextBox, false, 90, 0);
        gainSlider.setPopupDisplayEnabled (true, false, this);
        gainSlider.setTextValueSuffix (" Gain");
        gainSlider.addListener (this);
        addAndMakeVisible (gainSlider);

        // Create a tremolo depth slider
        depthSlider.setSliderStyle (juce::Slider::LinearVertical);
        depthSlider.setRange (0.0, 1.0, 0.01);
        depthSlider.setValue (0.5);
        depthSlider.setTextBoxStyle (juce::Slider::NoTextBox, false, 90, 0);
        depthpthSlider.setPopupDisplayEnabled (true, false, this);
        depthSlider.setTextValueSuffix (" Depth");
        depthSlider.addListener (this);
        addAndMakeVisible (depthSlider);
        
    }

    DistortionAudioProcessorEditor::~DistortionAudioProcessorEditor()
    {
        gain.removeListener (this);
        depth.removeListener (this);
    }

}

RapidAudioProcessorEditor::~RapidAudioProcessorEditor()
{
}

//==============================================================================
void RapidAudioProcessorEditor::sliderValueChanged (juce::Slider* slider)
{
        
    audioProcessor.setGain = gainSlider.getValue());
    audioProcessor.setTremoloDepth = depthSlider.getValue());
}
