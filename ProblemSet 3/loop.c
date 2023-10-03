#include <stdio.h> 

int main(){

    for(int i = 0; i < 11; i++ ) {
        for(int j = 10; j >= 0; j-- ){
            if(j >= i)
                printf("%i\n", j);
        }
        
    }

}