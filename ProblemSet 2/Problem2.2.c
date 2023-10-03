#include <stdio.h>
#include <math.h>
// this code's purpose is to calculate the frequency of two notes in Hz using a formula and printing them out.
int main(){
    int C4 = 60, A4 = 69; // assigns variables to integers
    double fc, fa; // creates double variables 

    fc = pow(2.0, (C4 - 69.0) / 12.0) * 440; // performs a formula and then assigns it to the double variable 
    fa = pow(2.0, (A4 - 69.0) / 12.0) * 440;
        printf("The frequency for MIDI pitch %i is %f Hz.\n", C4, fc); // prints based on respective variable arguments
        printf("The frequency for MIDI pitch %i is %f Hz.\n", A4, fa);
}