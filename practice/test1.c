#include <stdio.h>
struct test1
{
    /* data */
};

int main () {
    struct node *ptr, *cpt;
    ptr = head;
    while (&ptr != NULL)
    { 
        cpt = &ptr;
            while (cpt!=NULL)
            { 
                        if ( *ptr >  *cpt )
                    {
                        temp = *ptr;
                        *ptr = *cpt;
                        *cpt = temp;

                        cpt = &cpt;

                    }
            
                ptr = &ptr;
            }
    
        
    }
    



    return 0;
}