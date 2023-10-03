#include <stdio.h>
// this code's purpose is to check what octave a MIDI pitch is in or if the MIDI pitch is within range.
// the user inputs a MIDI pitch and the code will either print the pitch and octave, or print that the value is invalid.
int main(){
    int pitch = 0; // assigning an integer to pitch

    printf("Enter a MIDI pitch: "); // prints a message 
    scanf("%i", &pitch); // recieves the typed number and reassigns it to the pitch vairable 

    if (pitch >= 0 && pitch <= 127){ // if pitch is within this range 
        int octave = (pitch / 12) - 1; // perform this formula and assign it to the octave variable  
        printf("the octave for MIDI pitch %i is %i.\n", pitch, octave); // print a message with respective variables 
    }
    else { // if the pitch is not within this range
        printf("Invalid MIDI pitch. It should be between 0 and 127\n"); // print this message
    }

}