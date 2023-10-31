#include <stdio.h>

int main(){
    char notename = 'A';

    printf("Enter a note name ");
    scanf("%c", &notename); //need &

    switch (notename) {
        case 'A':
            printf("That's a note A\n");
            break;
        case 'B':
            printf("That's a note B\n");
        default:
            printf("Pick a better note\n");
    }


  
    
}