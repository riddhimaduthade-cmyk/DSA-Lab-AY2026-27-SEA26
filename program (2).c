// Searching contact name using Sequential and Binary Search
// Name: Riddhima Duthade
// Roll no: SEA26

#include <stdio.h>
#include <string.h>

typedef struct contact{
    char name[20];
    char phone[20];
    char address[20];
}contact;

void main(){
    contact c[20];
    int n, i;
    int lincom = 0;
    int linfound = 0;
    int bincom = 0;
    char key[20];
    
    printf("Enter number of contacts: ");
    scanf("%d", &n);
    
    printf("\n---//ENTER CONTACT DETAILS (A-Z)//---\n");
    for(i = 0; i < n; i++){
        printf("\n~~~Contact %d~~~\n", i+1);
        printf("Name: ");
        scanf("%s", &c[i].name);
        printf("Contact: ");
        scanf("%s", &c[i].phone);
        printf("Address: ");
        scanf("%s", &c[i].address);
    }

    printf("\n---//DISPLAYING CONTACTS//---\n");
    for(i = 0; i < n; i++){
        printf("\n~~~Contact %d~~~", i+1);
        printf("\nName: %s", c[i].name);
        printf("\nContact: %s", c[i].phone);
        printf("\nAddress: %s", c[i].address);
    }
    printf("\n\n---//END//---\n\n");

    printf("Enter name of contact to search: ");
    scanf("%s", &key);

    printf("\n---//Linear Search//---");
    for(i = 0; i < n; i++){
        lincom++;
        if(strcasecmp(key, c[i].name)==0){
            printf("\nCONTACT FOUND");
            printf("\nName: %s", c[i].name);
            printf("\nContact: %s ", c[i].phone);
            printf("\nAddress: %s", c[i].address);
            linfound = 1;
            break;
        }
    }
    if(linfound == 0){
        printf("\nCONTACT NOT FOUND");
    }

    printf("\nLinear comparisons: %d", lincom);
    printf("\n\n---//Binary Search//---");

    //Sorting Contact List to apply binary search
    char temp[20]; 
    strcpy(temp, c[0].name);
    for(int i = 0; i < n; i++){
        for(int j = 0; j <  n-i-1; j++){
            if(strcasecmp(c[j].name, c[j+1].name) > 0){
                strcpy(temp, c[j].name);
                strcpy(c[j].name, c[j+1].name);
                strcpy(c[j+1].name, temp);
            }
        }
    }

    int high = n-1;
    int low = 0;
    int mid;

    while(low <= high){
        mid = (high+low)/2;
        if(strcasecmp(c[mid].name, key) == 0){
            bincom++;
            printf("\nContact found at location %d", mid+1);
            break;
        }else if(strcasecmp(c[mid].name, key)<0){
            bincom++;
            low = mid+1;
        }else{
            bincom++;
            high = mid-1;
        }
    }
    if(low>high){
        printf("\nContact not found");
    }

    printf("\nNumber of binary comparisons: %d", bincom);

}

//Output
Enter number of contacts: 5

---//ENTER CONTACT DETAILS (A-Z)//---

~~~Contact 1~~~
Name: Neel
Contact: 9874125630
Address: Satara

~~~Contact 2~~~
Name: Abhishek
Contact: 9632014587
Address: Nagpur

~~~Contact 3~~~
Name: Pushpak
Contact: 9874563210
Address: Pune

~~~Contact 4~~~
Name: Utkarsh
Contact: 8520147963
Address: Mumbai

~~~Contact 5~~~
Name: Chaitanya
Contact: 5203698741
Address: Pune

---//DISPLAYING CONTACTS//---

~~~Contact 1~~~
Name: Neel
Contact: 9874125630
Address: Satara
~~~Contact 2~~~
Name: Abhishek
Contact: 9632014587
Address: Nagpur
~~~Contact 3~~~
Name: Pushpak
Contact: 9874563210
Address: Pune
~~~Contact 4~~~
Name: Utkarsh
Contact: 8520147963
Address: Mumbai
~~~Contact 5~~~
Name: Chaitanya
Contact: 5203698741
Address: Pune

---//END//---

Enter name of contact to search: utkarsh

---//Linear Search//---
CONTACT FOUND
Name: Utkarsh
Contact: 8520147963 
Address: Mumbai
Linear comparisons: 4

---//Binary Search//---
Contact found at location 5
Number of binary comparisons: 3
