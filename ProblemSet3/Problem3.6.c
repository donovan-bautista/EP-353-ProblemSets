#include <stdio.h>

// Creating a structure
struct MIDInote {
    int pitch;
    int velocity;
    int channel;
};

//defining the structure 
typedef struct MIDInote MIDInote;

//this function is void and doesn't return anything
void transpose_notes(MIDInote* notes, int steps, int size){
      for (int i = 0; i < size; ++i) { //for each instance of i in the array
        

        //transposes each value by the step variable 
        notes[i].pitch += steps;
        notes[i].velocity += steps;
        notes[i].channel += steps;
    }
}

int main() {
    //creates integers pit, vel, chan, size, and steps
    int pit, vel, chan, size, steps;

    //instructs and scans how many midi notes the user wants to input
    printf("Enter how many midi notes you want to input:\n ");
    scanf("%i", &size);
    
    //creates an array based on the size variable 
    MIDInote Notes[size];
    
    //for each instance in the size variable 
    for (int i = 0; i < size; ++i) {

        //instructs and scans each respective value
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

    //instructs the user to input how many steps they want to transpose by
    printf("Enter the number of steps (0 to 11) you want to transpose by:\n ");
    scanf("%i", &steps);  //scans the amount

    //excecutes the transpose_notes function using the Notes array, size variable, and steps variabl
    transpose_notes(Notes, size, steps); 
    
    //prints out the results using the respective variables.
    for (int i = 0; i < size; ++i) {
        printf("The MIDI note has pitch %d, velocity %d, and channel %d.\n", Notes->pitch, Notes->velocity, Notes->channel);
    }
}
