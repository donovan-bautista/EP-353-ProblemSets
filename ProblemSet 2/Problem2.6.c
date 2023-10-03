#include <stdio.h>
// the main purpose of this code is to use nested for loops to create a table of musical intervals
// when you excecute the program it will print out the aforementioned table
int main(){
    int note1, note2; // create integers for the two note values
        for (note1 = 0; note1 <= 11; note1++) { //increments note1 to no more than 11
            for (note2 = 0; note2 <= 11; note2++) { //increments note2 to no more than 11
                int interval = (note2 - note1 + 12) % 12; // this calculates the interval between the two notes
                switch(interval){ // looks at the interval value
                    case 0: // the message will print when the number equals the interval value 
                        printf("The interval from note %i to note %i is a unison\n", note1, note2);
                        break; // the print message takes in the arguments note1 and note2
                    case 1:
                        printf("The interval from note %i to note %i is a minor second\n", note1, note2);
                        break;
                    case 2:
                        printf("The interval from note %i to note %i is a major second\n", note1, note2);
                        break;
                    case 3:
                        printf("The interval from note %i to note %i is a minor third\n", note1, note2);
                        break;
                    case 4:
                        printf("The interval from note %i to note %i is a major third\n", note1, note2);
                        break;
                    case 5:
                        printf("The interval from note %i to note %i is a perfect fourth\n", note1, note2);
                        break;
                    case 6:
                        printf("The interval from note %i to note %i is a tritone\n", note1, note2);
                        break;
                    case 7:
                        printf("The interval from note %i to note %i is a perfect fifth\n", note1, note2);
                        break;
                    case 8:
                        printf("The interval from note %i to note %i is a minor sixth\n", note1, note2);
                        break;
                    case 9:
                        printf("The interval from note %i to note %i is a major sixth\n", note1, note2);
                        break;
                    case 10:
                        printf("The interval from note %i to note %i is a minor seventh\n", note1, note2);
                        break;
                    case 11:
                        printf("The interval from note %i to note %i is a major seventh\n", note1, note2);
                        break;
                    default: // this is optional. it is excecuted if none of the cases match the variable 
                    printf("something's not right.\n"); //in this scenario, a default is unlikely to happen//
                }
            }
        printf("\n"); //this separates each iteration of the first loop by a single line
       
        }
}