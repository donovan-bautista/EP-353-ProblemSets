#include <stdio.h>
// The purpose of the code is to create a structure related to the pitch, velocity, and channel of a midi note
// To do this the user inputs the respective values and the results are printed


// Creating a structure
struct MIDInote {
    int pitch;
    int velocity;
    int channel;
}; //need semicolon

//defining the structure 
typedef struct MIDInote MIDInote;

//this function is void and doesn't return anything
void print_note(MIDInote note) { //takes in MIDInote note and prints using the structure
    printf("The MIDI note has pitch %i, velocity %i, and channel %i.\n", note.pitch, note.velocity, note.channel);
}

int main() {
    //creates integers pit, vel, and chan
    int pit, vel, chan;

    //instructs the user to enter specific values
    printf("Enter a pitch value: ");
    scanf("%i", &pit); 

    printf("Enter a velocity value: ");
    scanf("%i", &vel);

    printf("Enter a channel value: ");
    scanf("%i", &chan);

    //specifies which values go where in the structure
    MIDInote note = {pit, vel, chan};

    //uses the print_note fuction using the note structure
    print_note(note);
    
}
