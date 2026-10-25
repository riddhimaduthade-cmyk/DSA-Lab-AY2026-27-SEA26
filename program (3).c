// Name: Riddhima Duthade
// Roll no: SEA26
//Practical 5: Circular Queue Implementation Using Array
//for Parcel Handling System

#include <stdio.h>
#define SIZE 5
int main(void)
{
    int arr[SIZE];
    int op;
    int front = -1, rear = -1;

    do
    {
        printf("1. Add\n");
        printf("2. Dispatch\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter an option: ");
        scanf("%d", &op);

        switch (op)
        {
            case 1:
                if (front == (rear + 1) % SIZE)
                {
                    printf("Parcel queue is Full\n\n");
                    break;
                }

                if (front == -1)
                {
                    front = 0;
                }

                rear = (rear + 1) % SIZE;

                printf("Enter parcel no. to add: ");
                scanf("%d", &arr[rear]);
                printf("\n");
                break;

            case 2:
                if (front == -1)
                {
                    printf("Parcel queue is Empty\n\n");
                    break;
                }

                printf("Parcel %d is dispatched\n\n", arr[front]);

                if (front == rear)
                {
                    front = -1;
                    rear = -1;
                }
                else
                {
                    front = (front + 1) % SIZE;
                }
                break;

            case 3:
                if (front == -1)
                {
                    printf("Parcel queue is Empty\n\n");
                    break;
                }

                {
                    int i = front;

                    printf("Parcel no. left in queue are: ");

                    while (1)
                    {
                        printf("%d ", arr[i]);

                        if (i == rear)
                        {
                            break;
                        }

                    i = (i + 1) % SIZE;
                    }

                    printf("\n\n");
                }
                break;

            case 4:
                printf("EXITED SUCCESSFULLY\n");
                break;

            default:
                printf("Invalid option! Please try again.\n\n");
        }

    } while (op != 4);

    return 0;
} 


