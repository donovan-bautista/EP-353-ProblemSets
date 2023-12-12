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
class RapidAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    RapidAudioProcessorEditor (RapidAudioProcessor&);
    ~RapidAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    RapidAudioProcessor& audioProcessor;
    juce::Slider gain;
    juce::Slider depth;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (RapidAudioProcessorEditor)
};
