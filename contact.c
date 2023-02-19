#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
struct Contact{
    struct Contact *prev,*next;
    char name[50];
    unsigned long long int phone;
};
struct Contact *head = NULL;
char info[50];
unsigned long long int number;
int i;



void bubbleSort()
{
    struct Contact *temp;
    int count=0,i;
    temp=head;
    while(temp->next!=NULL)
    {
        count++;
        temp=temp->next;
    }
   

    if(count)
    {
        for(i=0;i<count;i++)
        {
           temp=head;
           while(temp->next!=NULL)
           {
                if(strcmp(temp->name,temp->next->name)>0)
                {
                    strcpy(info,temp->name);
                    number=temp->phone;
                    strcpy(temp->name,temp->next->name);
                    temp->phone=temp->next->phone;
                    strcpy(temp->next->name,info);
                    temp->next->phone=number;            
                }
                temp=temp->next;
           }
        }
    }
    
}

void addContact(){
    struct Contact *newnode,*temp;
    newnode = (struct Contact *)malloc(sizeof(struct Contact));
    printf("\nEnter contact name: ");
    fflush(stdin);
    gets(info);
     for (i = 0; info[i]; i++) {
        if (info[i] >= 'A' && info[i] <= 'Z') {
            info[i] = info[i] - 'A' + 'a';
        }
    }
    printf("Phone Number: ");
    scanf("%llu",&number);
    if(head==NULL)
    {
        head = newnode;
        newnode->prev = NULL;
        newnode->next = NULL;
        strcpy(newnode->name,info);
        newnode->phone=number;
    }else{

        temp=head;
       
        do{
            if(strcmp(temp->name,info)==0)
            {
                printf("\n********************************************\n");
                printf("Duplicate Contact");
                printf("\n********************************************\n"); 
                return;
            }
            temp=temp->next;
        }
        while(temp!=NULL);
        temp=head;
          while(temp->next!=NULL)
        {
            temp=temp->next; 
        }
        temp->next = newnode;
        newnode->prev = temp;
        newnode->next = NULL;
        strcpy(newnode->name,info);
        newnode->phone=number;
        }
        printf("\n********************************************\n");
        printf("Contact Added Successfully");
        printf("\n********************************************\n"); 
        
    
}
void deleteContactBeg(){
    struct Contact *temp;
    if(head==NULL)
    {
        printf("\n********************************************\n");
        printf("Contact is Empty");
        printf("\n********************************************\n"); 
    }else{
        // bubbleSort();
        temp=head;
        head=temp->next;
        printf("\n********************************************\n");
        printf("Deleted Contact\n");
        printf("Name: %s\nPhone Number: %llu",temp->name,temp->phone);
        printf("\n********************************************\n");

    free(temp);
}
}
void deleteContactEnd(){
    struct Contact *temp;
    if(head==NULL)
    {
        printf("\n********************************************\n");
        printf("Contact is Empty");
        printf("\n********************************************\n"); 
    }else if(head->next==NULL)
    {
        // bubbleSort();
        temp=head;
        head=NULL;
        printf("\n********************************************\n");
        printf("Deleted Contact\n");
        printf("Name: %s\nPhone Number: %llu",temp->name,temp->phone);
        printf("\n********************************************\n");
        free(temp);
    }else{
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->prev->next=NULL;
        printf("\n********************************************\n");
        printf("Deleted Contact\n");
        printf("Name: %s\nPhone Number: %llu",temp->name,temp->phone);
        printf("\n********************************************\n");
        free(temp);
    }
    
}
void findContact(){
    struct Contact *temp;
   
    if(head==NULL)
    {
        printf("\n********************************************\n");
        printf("Contact is Empty");
        printf("\n********************************************\n"); 
    }else{
         printf("Enter contact name: ");
         fflush(stdin);
         gets(info);
          for (i = 0; info[i]; i++) {
        if (info[i] >= 'A' && info[i] <= 'Z') {
            info[i] = info[i] - 'A' + 'a';
        }
    }
         temp=head;
    do{
        if((strcmp(temp->name,info)==0))
        {
            printf("\n********************************************\n");
            printf("Contact Found:\n");
            printf("Name: %s\nPhone Number: %llu",temp->name,temp->phone);
            printf("\n********************************************\n");
            return;
            // break;
        }
        temp=temp->next;
    }while(temp!=NULL);
        printf("\n********************************************\n");
        printf("Contact not found");
        printf("\n********************************************\n");

    }
    
}
void updateContact(){
     struct Contact *temp;
   
    if(head==NULL)
    {
        printf("\n********************************************\n");
        printf("Contact is Empty");
        printf("\n********************************************\n");
    }else{
         printf("Enter contact name: ");
         fflush(stdin);
         gets(info);
          for (i = 0; info[i]; i++) {
        if (info[i] >= 'A' && info[i] <= 'Z') {
            info[i] = info[i] - 'A' + 'a';
        }
    }
         temp=head;
    do{
        if((strcmp(temp->name,info)==0))
        {
            printf("\n********************************************\n");
            printf("Contact Found:\n");
            printf("Name: %s\nPhone Number: %llu",temp->name,temp->phone);
            printf("\n********************************************\n");
            printf("\nEnter Contact Updates:\n");
            printf("\nContact name: ");
            fflush(stdin);
            gets(temp->name);
            printf("Phone Number: ");
            scanf("%llu",&temp->phone);
            printf("\n********************************************\n");
            printf("Contact Updated Successfully");
            printf("\n********************************************\n");
            return;
            // break;
        }
        temp=temp->next;
    }while(temp!=NULL);
        printf("\n********************************************\n");
        printf("Contact not found");
        printf("\n********************************************\n");

    }
    
}
void deleteContactByName(){
     struct Contact *temp;
    if(head==NULL)
    {
        printf("\n********************************************\n");
        printf("Contact is Empty");
        printf("\n********************************************\n");
    }else{
         printf("Enter contact name to be deleted: ");
         fflush(stdin);
         gets(info);
          for (i = 0; info[i]; i++) {
        if (info[i] >= 'A' && info[i] <= 'Z') {
            info[i] = info[i] - 'A' + 'a';
        }
    }
         temp=head;
    do{
        if((strcmp(temp->name,info)==0))
        {
            printf("\n********************************************\n");
            printf("Deleting Contact:\n");
            printf("Name: %s\nPhone Number: %llu",temp->name,temp->phone);
            printf("\n********************************************\n");
            if(temp->prev==NULL)
            {
            head=temp->next;
            free(temp);
            printf("\n********************************************\n");
            printf("Contact Deleted Successfully");
            printf("\n********************************************\n");
            return;
            }
            temp->prev->next=temp->next;
            printf("\n********************************************\n");
            printf("Contact Deleted Successfully");
            printf("\n********************************************\n");
            free(temp);
            return;
            // break;
        }
        temp=temp->next;
    }while(temp!=NULL);
        printf("\n********************************************\n");
        printf("Contact not found");
        printf("\n********************************************\n");

    }
    
}


void display()
{
    struct Contact *temp;
    temp=head;
    if(temp==NULL)
    {
        printf("\n********************************************\n");
        printf("Contact is empty");
        printf("\n********************************************\n");

    }else{
        bubbleSort();
        i=0;
        printf("\n********************************************\n");
        printf("Contacts are: \n");
        do{
            printf("\nName: %s\nPhone Number: %llu\n",temp->name,temp->phone);
            temp=temp->next;
        }while(temp!=NULL);
        printf("\n********************************************\n");
    }
    

}
void deleteSpecificContact()
{
    int j=0,k;
    struct Contact *ptr;
    display();
    if(head==NULL)
    {
        return;
    }
    printf("\nEnter the index of the contact that you want to delete: ");
    scanf("%d",&i);
    ptr=head;
    do{
        j++;   
        ptr=ptr->next;
    }while(ptr!=NULL);
    ptr=head;
    if(i<=j && i>0)
    {
        if(i==1)
        {
            deleteContactBeg();
            return;
        }
        if(i==j)
        {
        deleteContactEnd();
        return;
        }
        for(k=1;k<i;k++)
        {
            ptr=ptr->next;
        } 
        
        printf("\n********************************************\n");
        printf("Deleted Contact\n");
        printf("Name: %s\nPhone Number: %llu",ptr->name,ptr->phone);
        printf("\n********************************************\n");
        ptr->prev->next=ptr->next;
        free(ptr);
    }else{
        printf("\n********************************************\n");
        printf("No Contact Exist At That Index");
        printf("\n********************************************\n");
    }
}
void saveContact() {
    FILE *fp = fopen("contacts.txt", "w");
    struct Contact *curr = head;
    if (fp == NULL) {
        printf("\n********************************************\n");
        printf("Error while opening the file.");
        printf("\n********************************************\n");
        return;
    }
    if(curr==NULL)
    {
        printf("\n********************************************\n");
        printf("Nothing to save as contact is empty.");
        printf("\n********************************************\n");
        return;
    }
    while (curr != NULL) {
        fprintf(fp, "%s%llu\n", curr->name, curr->phone);
        curr = curr->next;
    }

        fclose(fp);
        printf("\n********************************************\n");
        printf("Contact saved successfully.");
        printf("\n********************************************\n");
}

void fetchContact() {
    struct Contact *tail = NULL;
    struct Contact *node;

    FILE *fp = fopen("contacts.txt", "r");
    if (fp == NULL) {
        printf("\n********************************************\n");
        printf("No previous contact found.");
        printf("\n********************************************\n");
        return;
    }

    while (fscanf(fp, "%[^0-9]%llu\n", info, &number) == 2) {
        node = (struct Contact*) malloc(sizeof(struct Contact));
        if (node == NULL) {
           printf("\n********************************************\n");
           printf("Failed to allocate memory.");
           printf("\n********************************************\n");
           return;
        }

        strcpy(node->name,info);
        node->phone=number;
        node->prev = tail;
        node->next = NULL;

        if (head == NULL) {
            head = node;
        } else {
            tail->next = node;
        }
        tail = node;
    }

    fclose(fp);
    return;
}

int main()
{
    int choice;
    fetchContact();
    while(1)
    {
        printf("\nEnter\n1. Add Contact\n2. Delete Contact From Beginning\n3. Delete Contact From End\n4. Delete Contact By Name\n5. Delete Specific Contact\n6. Find Contact\n7. Update Contact\n8. Display Contacts\n9. Save Contacts\n10. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: addContact();
                    getch();
                    break;
            case 2: deleteContactBeg();
                    getch();
                    break;
            case 3: deleteContactEnd();
                    getch();
                    break;
            case 4: deleteContactByName();
                    getch();
                    break;
            case 5: deleteSpecificContact();
                    getch();
                    break;
            case 6: findContact();
                    getch();
                    break;
            case 7: updateContact();
                    getch();
                    break;
            case 8: display();
                    getch();
                    break;
            case 9: saveContact();
                    getch();
                    break;
            case 10: exit(1);
                    break;
            default: printf("Invalid Input");
        }
    }
    return 0;
}