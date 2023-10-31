#include <stdio.h>
//The purpose of the program is to combine structures with arrays by using the array of a structure and printing out the results
//To do this the user inputs how many notes they want to input. From there they fill out the pitch, velocity, and channel of each note
//From there the program prints out the respective values of each note


// Creating a structure
struct MIDInote {
    int pitch;
    int velocity;
    int channel;
};

//defining the structure 
typedef struct MIDInote MIDInote;

//this function is void and doesn't return anything
void print_note(MIDInote note) { //takes in MIDInote note and prints using the structure
    printf("The MIDI note has pitch %i, velocity %i, and channel %i.\n", note.pitch, note.velocity, note.channel);
}

int main() {
    //creates integers pit, vel, chan, and size
    int pit, vel, chan, size;
    
    //instructs the user to enter how many notes they want to input
    printf("Enter how many midi notes you want to input:\n ");
    scanf("%i", &size);
    
    //creates an array with a size equal to the size integer
    MIDInote Notes[size];
    
    //for each instance in the size array, the program instructs the user to input the respective values
    for (int i = 0; i < size; ++i) {

        printf("Enter a pitch value: ");
        scanf("%i", &pit); 

        printf("Enter a velocity value: ");
        scanf("%i", &vel);

        printf("Enter a channel value: ");
        scanf("%i", &chan);

        //specifies which values go where in the structure
         MIDInote note = {pit, vel, chan};
        
        //specifies that the Notes array at each respective instance of i equals the note structure that was just input
        Notes[i] = note;

    }

    //for each instance of i the program will use the print_note function
    for (int i = 0; i < size; ++i) {
        print_note(Notes[i]);
    }
}
