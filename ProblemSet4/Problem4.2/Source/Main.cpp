/*
  ==============================================================================

    This file contains the basic startup code for a JUCE application.

  ==============================================================================
*/

#include <JuceHeader.h>
//The purpose of this code is to generate a triangle wave
//To do this the user enters the path the triangle wave wav file goes to and the code creates a wav and sends it to said path

//defining constant global variables
const float kSampleRate = 44100.0f;
const float kSec = 1.0f;
const float kNumFrames = kSampleRate * kSec;
const int kNumChannels = 2;
const float kFrequency = 440.0f;
const float kAmplitude = 0.25f;
const int kNumHarmonics = 16;

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
    
    //createing the triangle wave
    for (int channel = 0; channel < buffer.getNumChannels(); ++channel)
    {
        float *channelData = buffer.getWritePointer(channel);
        for (int sample = 0; sample < buffer.getNumSamples(); ++sample)
        {
            //generates kNumHarmonics sine waves and adds them all together
            for (int harmonic = 1; harmonic <= kNumHarmonics; harmonic += 2)
                {
                    float sign = (harmonic % 4 == 1) ? 1.0f : -1.0f;
                    float y = (sign * kAmplitude) / (harmonic * harmonic) * std::sin(2.0 * M_PI * (kFrequency * harmonic / kSampleRate) * sample);
                    channelData[sample] += y;
                }
        }
    }
    
    //creates a unique_ptr for the writer
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
