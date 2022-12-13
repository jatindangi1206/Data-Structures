#include<stdlib.h>
#include<stdio.h>
#include<math.h>
    struct node{
        int data;
        struct node* linkNext;
    };  
    
    typedef struct node Node; //making a node structure better abstraction and less typing.

    void printList(Node* head){
        Node* temp = head; //temp node to traverse the list
        while(temp != NULL){ //while the temp node is not null
            printf((temp==head)?"%d":"->%d", temp->data); //prints the data of the node.
            temp = temp->linkNext; //sets the value of the temporary node to the next node.
        }
        printf("->NULL"); //prints the null value at the end of the list.
    }

    void appendLast(Node **headAddress, int input)
    {
        // memory allocation for the new node
        Node *newNode = malloc(sizeof(Node)); 
        newNode->data = input; //sets the data of the new node to the input value
        newNode->linkNext = NULL;
        if(*headAddress == NULL)
        {
            *headAddress= newNode; //if the head is null, the new node is the head.
        }
        else 
        {
            Node *lastNode = *headAddress; //points to the head address or the first node
            while(lastNode -> linkNext != NULL) //checks for the lastNode since the last node will reference to the next Node which wil be null
            { 
                lastNode = lastNode -> linkNext;
            }
            lastNode -> linkNext = newNode; //adds the new node ahead of the last node at the end of the list

        }


    }

 // insertion sort algorithm for linked list
    void insertion_sort_link_list(Node **headAddress) 
    {
        // store the head node
        Node *currentNode= malloc(sizeof(Node)); //creates a new node to store the current node
        Node *next;
        Node *temp; //creates a temporary node to store the previous node
        // outer loop
        while((*headAddress)==NULL) 
        {
            next=(*headAddress)->linkNext; 
            while(temp->linkNext->data<(*headAddress)->data && temp->linkNext)
            {
                temp=temp->linkNext;
            }  
            // swap the data of the current node and the min node
            (*headAddress)->linkNext=temp->linkNext;
        

        
        }

    

        

    }
    // main function
    int main()
    {
        // create a linked list
        Node *head= NULL; 
        
        int lengthList;
        int point = 0;
        



        do{
            //asks the user for the length of the list
            printf("Enter the length of the list: ");
            scanf("%d", &lengthList);
            if(lengthList<=0){
                 //invalid for negative input since length should be positive
                printf("Invalid input. Please input a positive integer.\n");
                point=1; //sets the point to 1 to repeat the loop
            }
            else{
                point=0; //exits the loop if the length is correct
            }
           


        }while(point == 1);
        
        int i = 0;
    //asks the user for the elements of the list
        while(i<lengthList)
        {
            int value;
            printf("Enter the value of the node %d:", i+1);
            scanf("%d", &value);
            appendLast(&head, value); //appends the value to the end of the list
            i++;
            }
//prints the list before sorting
        printList(head); 
        printf("\n");
        insertion_sort_link_list(&head); //sorts the list
//prints the list after sorting       
        printList(head); 
        
        return 0;

            
        }