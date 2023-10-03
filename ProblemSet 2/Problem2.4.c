#include <stdio.h>
// this code expands upon Problem2.3.
// It now includes a switch statement to determine the note name and octave through two formulas.
// The user inputs a MIDI pitch and the code will print the note name, pitch, and octave.
// If the value is outside of the range, then a separate message print.
int main(){ 
    int pitch = 0; // making a pitch integer variable

    printf("Enter a MIDI pitch: "); // prints a message to instruct user to enter a MIDI pitch
    scanf("%i", &pitch); // recieves the typed number and reassigns it to the pitch vairable 

    int note = pitch % 12; // creates the note integer variable based the formula, which involves pitch
    int octave = ((pitch / 12) - 1); // creates the octave integer variable based the formula, which involves pitch

    if (pitch >= 0 && pitch <= 127){ // if the pitch value is in this range 
        switch(note) { // looks at the note variable
            case 0: // if the value of the note variable is the number, it will print out the respective message 
                printf("The MIDI pitch %i is C%i.\n", pitch, octave); // print message which includes pitch, note name, and octave 
                break; // break statement makes the flow jump to the next line of code after the switch statment
            case 1: // the variable 'note' will switch between all the cases until it matches the case
                printf("The MIDI pitch %i is C#%i.\n", pitch, octave);
                break;
            case 2:
                printf("The MIDI pitch %i is D%i.\n", pitch, octave);
                break;
            case 3:
                printf("The MIDI pitch %i is D#%i.\n", pitch, octave);
                break;
            case 4:
                printf("The MIDI pitch %i is E%i.\n", pitch, octave);
                break;
            case 5:
                printf("The MIDI pitch %i is F%i.\n", pitch, octave);
                break;
            case 6:
                printf("The MIDI pitch %i is F#%i.\n", pitch, octave);
                break;
            case 7:
                printf("The MIDI pitch %i is G%i.\n", pitch, octave);
                break;
            case 8:
                printf("The MIDI pitch %i is G#%i.\n", pitch, octave);
                break;
            case 9:
                printf("The MIDI pitch %i is A%i.\n", pitch, octave);
                break;
            case 10:
                printf("The MIDI pitch %i is A#%i.\n", pitch, octave);
                break;
            case 11:
                printf("The MIDI pitch %i is B%i.\n", pitch, octave); 
                break;
            default: // this is optional. it is excecuted if none of the cases match the variable 
                printf("something's not right.\n"); //in this scenario, a default is unlikely to happen//
        }
    }
    else { // if the pitch is not within this range
        printf("Invalid MIDI pitch. It should be between 0 and 127\n"); // print this message
    }
}