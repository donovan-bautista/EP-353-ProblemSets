#include <stdio.h>
// The purpose of the code is to give the frequency of a MIDI note
// To do this the user enters a MIDI note value and the code prints out the frequency in Hz

// math.h is needed for the formula to calculate frequency
#include <math.h> 

// declaring the midi_to_frequency function for the compiler
float midi_to_frequency(float); 

// defining the function
float midi_to_frequency(float z) { 
    // formula to calculate the frequency of a midi note
    return 440.0 * pow(2.0, (z - 69) / 12.0); 
}

int main() {
    // Declaring an integer for note and float for freq
    int note; 
    float freq;

    // Instructs the user to enter a MIDI note
    printf("Enter a MIDI note: \n"); 
    scanf("%i", &note);

    // calls the function and uses 'note' for z
    freq = midi_to_frequency(note); 

    // prints the message with the given frequency for the midi note
    printf("The frequency of MIDI note %i is %.2f Hz.\n", note, freq); 
}