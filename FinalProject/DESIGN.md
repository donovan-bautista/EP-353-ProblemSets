# Design Document

Before I begin I want to say Rapid would not be possible without Professor Akito's help. I would like to thank him not only for assisting me with this project, but for this semester and everything he has contributed here at Berklee.

The core of Rapid started off of Akito's Distortion audio effect. This provided an example of how to process audio in Juce. Using this as a template, I removed the distortion part and started with making the code, and it took awhile to finalize the code and get it working (thanks to Akito's help). During initialization, several variables are set based on properties such as gain, depth, and rate, which represent parameters of the audio processor determining amplification, tremolo depth, and tremolo rate, respectively. Additionally, the deltaPhase variable is calculated to represent the change in phase for each sample, considering the tremolo rate and the sample rate.

The core processing loop iterates over each sample in the audio buffer. For each sample, the algorithm calculates the tremolo factor using a sinusoidal function, adjusting the factor based on the current phase. The phase is then updated for the next sample, with periodic wrapping to avoid exceeding a full cycle. The current gain for the sample is determined by multiplying the base gain with the tremolo factor. Because of this, the algorithm retrieves the input sample from the audio buffer, multiplies it by the current gain, and writes the resulting output sample back to the audio buffer for the specified channel. The PluginEditor I also had trouble figuring out but thanks to Akito I had it working. I believe I wanted to start off with only 2 parameters but afterwards 3 made the most sense. 

The UI is pretty barebones, as I was not able to get into it as much as I wanted to. As mentioned before, there are three parameters, gain, depth, and rate that correspond to affecting their respective parameters. I went with a blue background and text to go with the "Rapid" idea, like river rapids. I experimented with a lot of blue colors and decided on the aqua asthethic. I at least wanted a little color in my project! What's life without some color? 






