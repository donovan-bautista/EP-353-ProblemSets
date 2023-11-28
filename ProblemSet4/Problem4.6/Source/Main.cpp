/*
  ==============================================================================

    The template DAFx file.

  ==============================================================================
*/

#include <JuceHeader.h>
//the purpose of this code is to make a bit quantization/reduction effect
//to do this the user inputs the input and output file, and the new file is created

// Function prototypes
int readSoundFile(juce::AudioBuffer<short>& buffer);
int writeSoundFile(const juce::AudioBuffer<short>& buffer, float sampleRate);
void process(const juce::AudioBuffer<short>& inBuffer, juce::AudioBuffer<short>& outBuffer, int keepBits);
short keep_bits_from_16(short input, int keepBits);

//==============================================================================
int main() {
    // Read the source file into a buffer for processing
    juce::AudioBuffer<short> inBuffer;
    float sampleRate = readSoundFile(inBuffer);
    if (sampleRate == 0)
        return 1;

    // Create a buffer for processing audio data
    juce::AudioBuffer<short> outBuffer(inBuffer.getNumChannels(), inBuffer.getNumSamples());

    // Process the audio data with bit reduction
    int keepBits = 8; // Adjust the number of bits to keep (1 ~ 16)
    process(inBuffer, outBuffer, keepBits);

    // Write the processed audio data to a sound file
    if (writeSoundFile(outBuffer, sampleRate))
        return 1;

    return 0;
}
//processes each sample in the input audio buffer using the keep_bits_from_16 function
void process(const juce::AudioBuffer<short>& inBuffer, juce::AudioBuffer<short>& outBuffer, int keepBits) {
    for (int sample = 0; sample < inBuffer.getNumSamples(); ++sample) {
        for (int channel = 0; channel < inBuffer.getNumChannels(); ++channel) {
            short inputSample = inBuffer.getSample(channel, sample);
            short outputSample = keep_bits_from_16(inputSample, keepBits);
            outBuffer.setSample(channel, sample, outputSample);
        }
    }
}
//reduced bit depth according to keepBits
short keep_bits_from_16(short input, int keepBits) {
    short prevent_offset = static_cast<short>(-1) >> (16 - keepBits + 1);
    input &= (-1 << (16 - keepBits));
    return input + prevent_offset;
}

int writeSoundFile(const juce::AudioBuffer<short>& buffer, float sampleRate) {
    // Prompt for the output file path
    std::cout << "Enter the path to the wave file to save: ";
    std::string filePath;
    std::getline(std::cin, filePath);
    juce::File file(filePath);

    // Create an audio format manager and register basic formats (especially WAV)
    juce::AudioFormatManager formatManager;
    formatManager.registerBasicFormats();

    // Create a temporary buffer to hold converted float samples
    juce::AudioBuffer<float> floatBuffer(buffer.getNumChannels(), buffer.getNumSamples());

    // Convert short samples to float
    for (int channel = 0; channel < buffer.getNumChannels(); ++channel) {
        for (int sample = 0; sample < buffer.getNumSamples(); ++sample) {
            floatBuffer.setSample(channel, sample, buffer.getSample(channel, sample) / 32768.0f);
        }
    }

    // Create a unique_ptr for the writer (WAV format)
    std::unique_ptr<juce::AudioFormatWriter> writer(formatManager.findFormatForFileExtension("wav")
                                                    ->createWriterFor(new juce::FileOutputStream(file),
                                                                       sampleRate,
                                                                       buffer.getNumChannels(),
                                                                       16,
                                                                       {},
                                                                       0));
    // Check if the writer was created
    if (writer) {
        // Write the mixed samples to the output file
        bool success = writer->writeFromAudioSampleBuffer(floatBuffer, 0, floatBuffer.getNumSamples());
        if (success)
            return 0;

        std::cout << "Failed to write samples into the buffer to the destination wave file." << std::endl;
        return 1;
    }

    std::cout << "Failed to create a writer for the destination file." << std::endl;
    return 1;
}
