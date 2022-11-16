#include <stdio.h>
#include <stdlib.h>


    int main(int argc, char**argv){
        // took 20 zeros to get to 1.0e-20
        float a, i=0.000000000000000000001; 
        float n= 0.00000000000000000001;
        int j = 1;

        for(a=0.0; a<n; a+=i){
            printf("Loop count: %d\n", j);
            j++;
        }
        return 0;
    }
    
