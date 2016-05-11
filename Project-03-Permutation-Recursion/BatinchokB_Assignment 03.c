/*
Brian Batinchok
COP3502 Spring 2015
Assignment Three
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readDataInputFile();
void exchangeCharacters(char *stringValue, int i, int j);
void recursivePermutation(char *stringValue, int k);

int main(){
	readDataInputFile();
	printf("Processed input file and wrote to output.\n");
	return 0;
}//main

void readDataInputFile(){
	const int LENGTH = 50;
	char dataInput[LENGTH];
	char fileInputName[] = "AssignmentThreeInput.txt";
	
	FILE *fileInputPointer = fopen(fileInputName, "r");
	printf("Attempting to open file %s...\n", fileInputName);
	
	if(fileInputPointer == NULL){
		perror("Error while opening file, closing program.\n");
		exit(0);
	}//if
	
	while((fgets(dataInput, LENGTH, fileInputPointer)) != NULL){
		strtok(dataInput, "\n");
		printf("Permutating %s \n", dataInput);
		recursivePermutation(dataInput, 0);
	}//while
	
	fclose(fileInputPointer);
}//readDataInputFile

void recursivePermutation(char *stringValue, int k){
	int j;
	
	char *fileName = "AssignmentThreeOutput.txt";
	FILE *fileOutputPointer = fopen(fileName, "a");
	
	if(fileOutputPointer == NULL){
		perror("Error while attempting to open file, closing program.\n");
		exit(0);
	}//if
	
	if(k == strlen(stringValue)){
		fprintf(fileOutputPointer, "%s\n", stringValue);
	}//if
	
	else{
		for(j = k; j < strlen(stringValue); j++){	
			exchangeCharacters(stringValue, k, j);
			recursivePermutation(stringValue, k + 1);
			exchangeCharacters(stringValue, j, k);
		}//for	
	}//else
	
	fclose(fileOutputPointer);	
}//recursivePermutation

void exchangeCharacters(char *stringValue, int i, int j){
	char temp = stringValue[i];
	stringValue[i] = stringValue[j];
	stringValue[j] = temp;
}//exchangeCharacters
