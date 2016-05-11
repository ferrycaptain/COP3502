/*
Brian Batinchok
COP3502 Spring 2015
Assignment One: Linked List

This program reads in a file with student names and id numbers and puts 
them into the list.  The user can add students, display the students 
in the list, and remove students by ID number or by student name.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXNAMELENGTH 50
#define MAXIDLENGTH 10

//struct that holds student info and points to next in the list
struct node{
    char studentName[MAXNAMELENGTH];
    int studentID;
    struct node *next;
} *head;

//prototypes for functions used
int deleteByStudentID(int num);
int deleteByStudentName(char *deleteName);
void displayStudents(struct node *displayNode);
void insertStudent(char *inputName, char *inputId);
void programOptions();
void readDataFile();


int main(){
   	char studentNameDelete[MAXNAMELENGTH];
   	char studentNameInsert[MAXNAMELENGTH];
   	char studentID[MAXIDLENGTH];
   	int studentIDDelete;
   	int userInput;
   	struct node *n;

   	//list initialized
   	head = NULL;
	
   	//read in data from AssignmentOneInput.txt
   	readDataFile();

   	while(true){
   		
		programOptions();
	
		if(scanf("%d", &userInput) <= 0){
        	printf("Enter only an Integer\n");
           	exit(0);
       	}//if
       
	   	else{
        	switch(userInput){
            	case 1:
                	printf("Enter the name to insert: ");
                    scanf(" %[^\n]s", studentNameInsert);
                    printf("What is the ID number for %s? ", studentNameInsert);
                    scanf(" %[^\n]s", studentID);
                    insertStudent(studentNameInsert, studentID); 
                    break;
                    
                case 2:
                    if(head == NULL){
                        printf("The list is Empty.\n");
                    }//if
                    else{
                        printf("Element(s) in the list are : ");
                        displayStudents(n);
                    }//else 
                    break;
                    
                case 3:
                    if(head == NULL){
                        printf("The list is Empty.\n");
                    }//if
                    
                    else{
                        printf("Enter the ID number to delete : ");
                        scanf("%d", &studentIDDelete);

                        if(deleteByStudentID(studentIDDelete))
                            printf("%d deleted successfully.\n", studentIDDelete);
                        else
                            printf("%d not found in the list.\n", studentIDDelete);
                    }//else
                    break;
                    
                case 4:
                    if(head == NULL){
                        printf("The list is Empty.\n");
                    }//if
                    
                    else{
                        printf("Enter the name to delete : ");
                        scanf(" %[^\n]s", studentNameDelete);

                        if(deleteByStudentName(studentNameDelete))
                            printf("%s deleted successfully.\n", studentNameDelete);
                        else
                            printf("%s not found in the list.\n", studentNameDelete);
                    }//else
                    break;
                    
                case 5:
                    return 0;
                    
                default:
                    printf("Invalid Option.\n");
			}//switch
       }//else
    }//while
    
    return 0;
}//main

//deletes the student based on the ID number
int deleteByStudentID(int num){
    //temporary and previous nodes
    struct node *tempNode, *prevNode;

    //initialize
    tempNode = head;

    printf("checking for %d ...\n", num);

    //loop while tempNode is not NULL
    while(tempNode != NULL){
        //is the id value of temp equal to the passed in value
        if(tempNode->studentID == num){
            //is the current location at the beginning of the linked list
            if(tempNode == head){
                //beginning of the linked list is the new node
                head = tempNode->next;
                //free up the memory used
                free(tempNode);
                //return true
                return 1;
            }//if
            else{
                //the current location was not at the first node
                prevNode->next = tempNode->next;
                //free up the memory used
                free(tempNode);
                //return true
                return 1;
            }//else
        }//if
        else{
            //set prev equal to temp
            prevNode = tempNode;
            //move temp to the next node
            tempNode = tempNode->next;
        }//else
    }//while
    return 0;
}//deleteByStudentID

//delete the node based on the student's name
int deleteByStudentName(char *name){
    //temporary and previous nodes
    struct node *tempNode, *prevNode;

    //initialize
    tempNode = head;

    printf("checking for name %s ...\n", name);

    //loop while temp is not equal to null
    while(tempNode != NULL){
        //is there is a string comparison match?
        if(strcmp(tempNode->studentName, name) == 0){
            printf("found %s!\n", name);
            if(tempNode == head){
                //beginning of the linked list to equal the next node
                head = tempNode->next;
                //free up memory used
                free(tempNode);
                //return true
                return 1;
            }//if
            //the current location was not at the first node
            else{
                //set prev to temp
                prevNode->next = tempNode->next;
                //free up memory
                free(tempNode);
                //return true
                return 1;
            }//else
        }//if
        else{
            //set prev to temp
            prevNode = tempNode;
            //move temp to the next node
            tempNode = tempNode->next;
        }//else
    }//while
    return 0;
}//deleteByStudentName

void displayStudents(struct node *displayNode){
    displayNode = head;

    if(displayNode == NULL){
        return;
    }//if

    while(displayNode != NULL){
        printf("Student: %s    ID: %d\n", displayNode->studentName, displayNode->studentID);
        displayNode = displayNode->next;
    }//while

    printf("\n");
}//displayStudents

//adds a new node at the end of the list
void insertStudent(char *inputStudentName, char *inputStudentID){
    //temporary and helper nodes
    struct node *tempNode, *helperNode;

    //allocate memory for temp node
    tempNode = (struct node*)malloc(sizeof(struct node));

    //make student ID an int value
    int intStudentID = atoi(inputStudentID);

    strcpy(tempNode->studentName, inputStudentName);
    tempNode->studentID = intStudentID;
    tempNode->next = NULL;

    //add first node
    if(head == NULL){
        head = tempNode;
    }//if
    //or find the end and add the new node
    else{
        helperNode = head;

        //loop until the end
        while(helperNode->next != NULL){
            helperNode = helperNode->next;
        }//while

        //add a new node at the end of the list
        helperNode->next = tempNode;
    }//else
    
    printf("Added: %s     ID: %s", inputStudentName, inputStudentID);
}//insertStudent

//calls program options to main
void programOptions(){
	printf("\n\n===============\n");
	printf("List Operations\n");
    printf("===============\n\n");
    printf("1. Insert\n");
    printf("2. Display\n");
    printf("3. Delete by ID\n");
    printf("4. Delete by Name\n");
    printf("5. Exit\n\n");
    printf("Enter your choice: ");
}//programOptions

//function to read in the data file
void readDataFile(){
    const char comma[2] = ",";
    char *studentName;
    char *studentID;
    char dataLine[MAXNAMELENGTH];
    char fileName[] = "AssignmentOneInput.txt";
    FILE *filePointer;

    printf("Trying to open file %s\n", fileName);
    filePointer = fopen(fileName ,"r"); //read mode

    if(filePointer == NULL){
        perror("Error while opening the file.\n");
        exit (0);
    }//if

    //loop until the end of the file
    while((fgets(dataLine, MAXNAMELENGTH, filePointer)) != NULL){
        // string tokenizes the data line to space out the name and the id
        studentName = strtok(dataLine, comma);
        studentID = strtok(NULL, comma);

        //call function insert to add the data as a node to the linked list
        insertStudent(studentName, studentID);
    }//while
    
    fclose(filePointer);
}//readDataFile
