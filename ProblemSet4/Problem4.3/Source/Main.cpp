/*
  ==============================================================================

    This file contains the basic startup code for a JUCE application.

  ==============================================================================
*/

#include <JuceHeader.h>
//The purpose of this code is to add a tremolo effect to a sine wave
//to do this the user inputs paths for the output file and the tremolo file is created

//creating constant global varibles
const float kSampleRate = 44100.0f;
const float kSec = 1.0f;
const float kNumFrames = kSampleRate * kSec;
const int kNumChannels = 2;
const float kFrequency = 250.0f;
const float kAmplitude = 0.25f;
const float kLFOfrequency = 2.0f;

//==============================================================================
int main (int argc, char* argv[])
{
    // Prompt for the output file path
    std::cout << "Enter the path for the destination wave file: ";
    std::string destFilePath;
    std::getline(std::cin, destFilePath);

    // Create a File object from the path
    juce::File destFile(destFilePath);
    
    // Create an audio format manager and register the wav format
    juce::AudioFormatManager formatManager;
    formatManager.registerBasicFormats();
    
    // Create a buffer to hold the samples
    juce::AudioBuffer<float> buffer(kNumChannels, kNumFrames);
    
    //creating a sine wave
    for (int channel = 0; channel < buffer.getNumChannels(); ++channel)
        {
            float *channelData = buffer.getWritePointer(channel);
            for (int sample = 0; sample < buffer.getNumSamples(); ++sample)
            {
                //creating the lfp
                float lfo = 0.5f * (1.0f + std::sin(2.0 * M_PI * kLFOfrequency * sample / kSampleRate));

                //applying the lfo to the sine wave
                float y = kAmplitude * lfo * std::sin(2.0 * M_PI * (kFrequency / kSampleRate) * sample);
                channelData[sample] = y;
            }
        }

    
    // Create a unique_ptr for the writer
    std::unique_ptr<juce::AudioFormatWriter> writer(formatManager.findFormatForFileExtension("wav")
                                          ->createWriterFor(new juce::FileOutputStream(destFile),
                                                             kSampleRate,
                                                             kNumChannels,
                                                             16,
                                                             {},
                                                             0));

    if (writer)
    {
       writer->writeFromAudioSampleBuffer(buffer, 0, buffer.getNumSamples());
    }
    else
    {
       std::cout << "Failed to create a writer for the mixed file." << std::endl;
    }
}
