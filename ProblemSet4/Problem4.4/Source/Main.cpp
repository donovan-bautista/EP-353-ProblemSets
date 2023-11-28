#include <iostream>
#include <JuceHeader.h>
//the purpose of this program is to add an envelope to a wav file
//to do this the user inputs the path for the wav file they want to use
//and the path for where the new wav file should go

//declaring functions
double readSoundFile(const char* filePath, juce::AudioBuffer<float>& buffer);
int writeSoundFile(const char* filePath, const juce::AudioBuffer<float>& buffer, double sampleRate);
void applyLinearADEnvelope(juce::AudioBuffer<float>& buffer, double attackTime, double decayTime, double sampleRate);

int main()
{
    // Prompt for the input file path
    std::cout << "Enter the path to the wave file to process: ";
    std::string sourceFilePath;
    std::getline(std::cin, sourceFilePath);

    // Prompt for the output file path
    std::cout << "Enter the path to save the enveloped wave file: ";
    std::string destFilePath;
    std::getline(std::cin, destFilePath);

    // Create an audio buffer
    juce::AudioBuffer<float> sampleBuffer;

    // Read the sound file into the buffer
    double sampleRate;
    if ((sampleRate = readSoundFile(sourceFilePath.c_str(), sampleBuffer)))
    {
        //adding the envelope to the buffer
        applyLinearADEnvelope(sampleBuffer, 0.1, 0.9, sampleRate);

        //writes enveloped sound files to the output file
        if (writeSoundFile(destFilePath.c_str(), sampleBuffer, sampleRate) == 0)
        {
            std::cout << "Enveloped wave file written successfully." << std::endl;
        }
        else
        {
        
        //error messages
            std::cout << "Failed to write enveloped wave file." << std::endl;
        }
    }
    else
    {
        std::cout << "Failed to read the source wave file." << std::endl;
    }

    return 0;
}

void applyLinearADEnvelope(juce::AudioBuffer<float>& buffer, double attackTime, double decayTime, double sampleRate)
{
    int numChannels = buffer.getNumChannels();
    int numSamples = buffer.getNumSamples();

    //creating attack and decay
    int attackLength = static_cast<int>(attackTime * sampleRate);
    int decayLength = static_cast<int>(decayTime * sampleRate);

    //applies envelope to each channel
    for (int channel = 0; channel < numChannels; ++channel)
    {
        for (int sample = 0; sample < numSamples; ++sample)
        {
            //calculates value using interpolation
            double envelopeValue;
            if (sample < attackLength)
            {
                envelopeValue = static_cast<double>(sample) / attackLength;
            }
            else if (sample >= numSamples - decayLength)
            {
                envelopeValue = static_cast<double>(numSamples - sample) / decayLength;
            }
            else
            {
                envelopeValue = 1.0;
            }

            //applies envelope to the sample
            buffer.setSample(channel, sample, buffer.getSample(channel, sample) * static_cast<float>(envelopeValue));
        }
    }
}

double readSoundFile(const char* filePath, juce::AudioBuffer<float>& buffer)
{
    juce::File file(filePath);

    // Create an audio format manager and register basic formats (especially WAV)
    juce::AudioFormatManager formatManager;
    formatManager.registerBasicFormats();

    // Create a unique_ptr for the reader
    std::unique_ptr<juce::AudioFormatReader> reader(formatManager.createReaderFor(file));

    // Check if the reader was created
    if (reader)
    {
        // Set the size of buffer
        buffer.setSize(reader->numChannels, static_cast<int>(reader->lengthInSamples));

        // Read the samples from the file into the buffer
        reader->read(&buffer, 0, static_cast<int>(reader->lengthInSamples), 0, true, true);

        // Return the sample rate for this file
        return reader->sampleRate;
    }

    std::cout << "Failed to read the source wave file." << std::endl;
    return 0;
}

int writeSoundFile(const char* filePath, const juce::AudioBuffer<float>& buffer, double sampleRate)
{
    juce::File file(filePath);

    // Create an audio format manager and register basic formats (especially WAV)
    juce::AudioFormatManager formatManager;
    formatManager.registerBasicFormats();

    // Create a unique_ptr for the writer (WAV format)
    std::unique_ptr<juce::AudioFormatWriter> writer(formatManager.findFormatForFileExtension("wav")
                                                    ->createWriterFor(new juce::FileOutputStream(file),
                                                                       sampleRate,
                                                                       buffer.getNumChannels(),
                                                                       16,
                                                                       {},
                                                                       0));

    // Check if the writer was created
    if (writer)
    {
        writer->writeFromAudioSampleBuffer(buffer, 0, buffer.getNumSamples());
        return 0;
    }

    std::cout << "Failed to create a writer for the destination file." << std::endl;
    return 1;
}
