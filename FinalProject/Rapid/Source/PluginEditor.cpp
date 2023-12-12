/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
RapidAudioProcessorEditor::RapidAudioProcessorEditor(RapidAudioProcessor& p)
    : AudioProcessorEditor(&p), audioProcessor(p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize(400, 300);

    // Create a gain slider
    gain.setSliderStyle(juce::Slider::LinearVertical);
    gain.setRange(0.0, 1000.0, 1.0);
    gain.setValue(0.0);
    gain.setTextBoxStyle(juce::Slider::NoTextBox, false, 90, 0);
    gain.setPopupDisplayEnabled(true, false, this);
    gain.setTextValueSuffix(" Gain");
    gain.addListener(this);
    addAndMakeVisible(&gain);

    // Create a tremolo depth slider
    depth.setSliderStyle(juce::Slider::LinearVertical);
    depth.setRange(0.0, 2.0, 0.01);
    depth.setValue(1.0);
    depth.setTextBoxStyle(juce::Slider::NoTextBox, false, 90, 0);
    depth.setPopupDisplayEnabled(true, false, this);
    depth.setTextValueSuffix(" Depth");
    depth.addListener(this);
    addAndMakeVisible(&depth);

    // Create a tremolo rate slider
    rate.setSliderStyle(juce::Slider::LinearVertical);
    rate.setRange(0.0, 10.0, 0.01);
    rate.setValue(1.0);
    rate.setTextBoxStyle(juce::Slider::NoTextBox, false, 90, 0);
    rate.setPopupDisplayEnabled(true, false, this);
    rate.setTextValueSuffix(" Rate");
    rate.addListener(this);
    addAndMakeVisible(&rate);
}

RapidAudioProcessorEditor::~RapidAudioProcessorEditor()
{
    gain.removeListener(this);
    depth.removeListener(this);
    rate.removeListener(this);
}

void RapidAudioProcessorEditor::paint(juce::Graphics& g)
{
    // Give color to the text and background
    g.fillAll(juce::Colour(0xff008b8b));

    g.setColour(juce::Colours::aqua);
    g.setFont(15.0f);
    g.drawFittedText("Rapid", getLocalBounds(), juce::Justification::centred, 1);
}

void RapidAudioProcessorEditor::resized()
{
    // Set the bounds for the sliders
    int sliderWidth = 100;
    int sliderHeight = getHeight() - 20;
    int xPosition = 50;

    // Set positions of the sliders
    gain.setBounds(xPosition, 10, sliderWidth, sliderHeight);
    depth.setBounds(xPosition + 150, 10, sliderWidth, sliderHeight);
    rate.setBounds(xPosition + 250, 10, sliderWidth, sliderHeight);
}

void RapidAudioProcessorEditor::sliderValueChanged(juce::Slider* slider)
{
    
    //Get values from the sliders so they can be used in the equation
    audioProcessor.gain = gain.getValue();
    audioProcessor.depth = depth.getValue();
    audioProcessor.rate = rate.getValue();
}
