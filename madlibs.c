//Peter Sheikman, Darell Acebu, Maya Muha
//12/2/24
//Madlibs Final Project - CS 135

#include <stdio.h>
#define FILENAME "madlib2.txt"
#define COL 100
#define ROW 100
#define LENGTH 100
#define WORDLENGTH 50
#define AMTWORDS 25

int countLines(FILE* fin, char str[][COL]);
void getWordType(FILE* fin, char wordType[], int numLines, char charIndex[][COL]);
void enterWords(int length, char letterArray[], char wordArray[][WORDLENGTH]);
void printStory(char fileScanned[][COL], char wordArray[][WORDLENGTH], int lines);
void printWord(char fileScanned[][COL], char wordArray[][WORDLENGTH], int place);

int main(){

	FILE* fptr;
	int lines;
	char str[ROW][COL];
	char wordType[LENGTH];
	char wordArray[AMTWORDS][WORDLENGTH];
	
	fptr = fopen(FILENAME, "r");
	
	if(fptr == NULL){
		printf("File could not open.\n");
		return 0;
	}
	
	lines = countLines(fptr, str);
	
	getWordType(fptr, wordType, lines, str);
	
	fclose(fptr);
	
	enterWords(AMTWORDS, wordType, wordArray);
	
	printStory(str, wordArray, lines);
	
	printf("\n");

	return 0;
}

int countLines(FILE* fin, char str[][COL]){

	int lines = 0;
	int indR, indC;
	
	for(indR = 0; fgets(str[indR], ROW, fin) != 0; indR++){
		lines++;
	} 
	
	return lines;
}

void getWordType(FILE* fin, char wordType[], int numLines, char charIndex[][COL]){

	int i;
	
	for(i = 0; i < numLines; i++){
		if(charIndex[i][0] == 'A'){
			wordType[i] = charIndex[i][0];
		}
		else if(charIndex[i][0] == 'N'){
			wordType[i] = charIndex[i][0];
		}
		else if(charIndex[i][0] == 'V'){
			wordType[i] = charIndex[i][0];
		}
	}
	
}

void enterWords(int length, char letterArray[], char wordArray[][WORDLENGTH]){
	for(int i = 0; i < length; i++){
		if(letterArray[i] == 'A'){
			printf("Please enter an adjective: ");
			scanf(" %s", &wordArray[i]);
		}
		if(letterArray[i] == 'N'){
			printf("Please enter a noun: ");
			scanf(" %s", &wordArray[i]);
		}
		if(letterArray[i] == 'V'){
			printf("Please enter a verb: ");
			scanf(" %s", &wordArray[i]);
		}
	}
}

void printStory(char fileScanned[][COL], char wordArray[][WORDLENGTH], int lines){
	
	for(int i = 0; i < lines; i ++){
		if(fileScanned[i][0] == 'A' || fileScanned[i][0] == 'N' || fileScanned[i][0] == 'V'){
			printWord(fileScanned, wordArray, i);
		}
		else{
			for(int j = 0; fileScanned[i][j] != '\n'; j ++){
				printf("%c", fileScanned[i][j]);
			}
		}
		
	}
	
}

void printWord(char fileScanned[][COL], char wordArray[][WORDLENGTH], int place){
	if(fileScanned[place+1][0] == '.' || fileScanned[place+1][0] == '!' || fileScanned[place+1][0] == ','){
		printf(" %s", wordArray[place]);
	}
	else{
		printf(" %s ", wordArray[place]);
	}
}
