// Name: Riddhima Duthade
// Roll no: SEA26
// Dynamic Text Editor Using Singly Linked List

#include<stdio.h>
#include <stdlib.h>

typedef struct SLL{
    char data[10];
    struct SLL *next;
}SLL;

void main(){
    SLL *head, *p, *q, *r, *nw, *temp;
    head = NULL;
    int ans, op, loc;
    do{
        printf("\n1. Create\n2. Insert\n3. Display\n4. Delete\n5. Reverse\n6. Exit\n");
        printf("Enter option: ");
        scanf("%d", &op);
        switch(op){
            case 1:
            do{
                nw = (SLL*)malloc(sizeof(SLL));
                printf("Enter data: ");
                scanf("%s", &nw->data);
                nw -> next = NULL;
                if(head == NULL){
                    p = head = nw;
                }else{
                    p ->next = nw;
                    p = nw;
                }
                printf("Do you want to continue: ");
                scanf("%d", &ans);
            }while(ans==1);
            break;
            
            case 2:
            printf("Enter location: ");
            scanf("%d", &loc);
            p = (SLL*)malloc(sizeof(SLL));
            printf("Enter data: ");
            scanf("%s", &p->data);
            if(loc == 1){
                p -> next = head;
                head = p;
            }else{
                q = head;
                for(int i = 1; i < loc-1; i++){
                    q = q -> next;
                    if(q == NULL){
                        printf("underflow");
                    }
                }
                p -> next = q -> next;
                q -> next = p;
            }
            break;
            
            case 3:
            for(p = head; p != NULL; p = p -> next){
                if(p == NULL){
                    printf("EMPTY");
                }
                printf("%s->", p -> data);
            }
            printf("NULL\n");
            break;

            case 4:
            printf("Enter location: ");
            scanf("%d", &loc);
            if(loc == 1){
                head = head -> next;
                free(p);
            }else{
                q = head;
                for(int i = 1; i < loc-1; i++){
                    q = q -> next;
                    if(q == NULL){
                        printf("underflow");
                    }
                }
                p = q -> next;
                q -> next = p -> next;
                free(p);
            }
            break; 

            case 5:
            p = NULL; //previous node
            q = head; //current node
            r = NULL; // next node
            while(q != NULL){
                r = q -> next;
                q -> next = p;
                p = q;
                q = r;
            }
            head = p;
            for(temp = head; temp != NULL; temp = temp -> next){
                if(temp == NULL){
                    printf("underflow");
                }
                printf("%s->", temp -> data);
            }
            printf("NULL\n");
            break;

            case 6:
            printf("EXITED SUCCESSFULLY");
            break;

            default:
            printf("Invalid option");
        }
    }while(op != 6);
}
