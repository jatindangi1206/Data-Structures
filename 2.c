#include<stdio.h>

int main(){
    // 10 names with each name having 10 characters of input
    char names[10][10];
    int age[10];
    
    printf("enter details of 10 people\n");
    int i=0;
    while (i<3){
        printf("Name: ");
        
    //accepting 10 characters for input
        scanf("%s",names[i]);
        printf("Age: ");
        scanf("%d",&age[i]);
        i++;
    }
    printf("the ages are:");
    printf("\n %d",age[0]);
    printf("\n %d",age[1]);
    printf("\n %d",age[2]);
    
    printf("\nthe names are:");
    printf("\n %s",names[0]);
    printf("\n %s",names[1]);
    printf("\n %s",names[2]);
    
 
    return(0);
}