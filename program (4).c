//practical 6
// Name: Riddhima Duthade
// Roll no: SEA26
// Train Ticket Booking System Using Queue 
 
#include <stdio.h> 
#define SIZE 5 
 
int q[SIZE]; int wait[SIZE]; int front = -1, rear = -1; int wcount = 0; 
 
void book(){ 
    int t; 
    printf("Enter ticket number: ");     scanf("%d", &t);     if ((rear + 1) % SIZE == front){         if (wcount == SIZE){             printf("Waiting list full\n"); 
        }else{             wait[wcount] = t;             wcount++;             printf("Added to waiting list\n"); 
        } 
    }else{         if (front == -1){             front = 0; 
        } 
        rear = (rear + 1) % SIZE;         q[rear] = t;         printf("Ticket booked\n"); 
    } 
} 
 
void cancel(){ 
    int t, i, j, found = 0;     printf("Enter ticket number to cancel: ");     scanf("%d", &t);     if (front == -1){         printf("No tickets\n");         return; 
    } 
    i = front;     while (1){         if (q[i] == t){             found = 1;             break; 
        } 
        if (i == rear){         break; 
        } 
        i = (i + 1) % SIZE; 
    } 
    if (!found){         printf("Ticket not found\n");         return; 
    } 
    while(i != rear){         q[i] = q[(i + 1) % SIZE];         i = (i + 1) % SIZE; 
    } 
    if(front == rear){     front = rear = -1;     }else{ 
    rear = (rear - 1 + SIZE) % SIZE; 
    } 
    printf("Ticket cancelled\n");     if (wcount > 0){         if (front == -1){             front = rear = 0;         }else{             rear = (rear + 1) % SIZE; 
        } 
        q[rear] = wait[0]; 
        printf("Waiting ticket %d confirmed\n", wait[0]);         for (j = 0; j < wcount - 1; j++){             wait[j] = wait[j + 1];             wcount--; 
        } 
    } 
} 
 
void display(){ 
    int i; 
    printf("\nConfirmed Tickets: ");     if (front != -1){         i = front;         while (1){             printf("%d ", q[i]);             if (i == rear){ 
            break; 
            } 
            i = (i + 1) % SIZE; 
        } 
    } 
    printf("\nWaiting List: ");     for (i = 0; i < wcount; i++){         printf("%d ", wait[i]); 
    } 
    printf("\n"); 
} 
 
void main(){ 
    int op;     do{ 
        printf("\n1. Book Ticket\n2. Cancel Ticket\n3. Display Bookings\n4. Exit\n");         printf("Enter option: ");         scanf("%d", &op);         switch (op){             case 1:             book();             break; 
 
            case 2:             cancel();             break; 
 
            case 3:             display();             break;             case 4: 
            printf("EXITED SUCCESSFULLY\n"); 
            break; 
 
            default: 
            printf("Invalid option\n"); 
        } 
    }while(op != 4); 
} 
 
