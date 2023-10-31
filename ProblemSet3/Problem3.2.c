#include <stdio.h>
// The purpose of the code is to give the frequency of a group of MIDI note
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
// this function is voic so it does not return anything
void print_chord_frequencies(int chord[], int size) { //takes in the chord array and size
    for (int i = 0; i < size; ++i) {
        float freq = midi_to_frequency(chord[i]); // for each value in the array it is sent to the midi_to_frequency function
        printf("The frequency of MIDI note %i is %.2f Hz.\n", chord[i], freq); // prints out the message with respective results
    }
}

int main() {
    // creating variable for the amount of midi notes the user inputs
    int size;

    // print message to instruct the user
    printf("Enter how many MIDI notes you want to print: ");
    // scan message so the user can input amount of MIDI notes
    scanf("%i", &size);

    // creating an array based on the amount of MIDI notes
    int chord[size];

    // this for loop prompts the user to enter MIDI values based on the amount
    for (int i = 0; i < size; ++i) {
        printf("Enter the MIDI note value: ");
        scanf("%i", &chord[i]);
    }
    // using the print_chord_frequencies function
    print_chord_frequencies(chord, size);
}