//Peter Sheikman, NAME, NAME
//12/2/24
//Madlibs Final Project

#include <stdio.h>
#define FILENAME "madlib1.txt"
#define COL 50
#define ROW 100
#define LENGTH 100
#define WORDLENGTH 50

int countLines(FILE* fin, char str[][COL]);
void everyOtherLine(FILE* fin, char wordType[], int numLines);
void enterWords(int length, char letterArray[], char wordArray[][WORDLENGTH]);

int main(){

	FILE* fptr;
	int lines;
	char str[ROW][COL];
	char wordType[LENGTH];
	int amtWords = 1; //will be updated
	char wordArray[amtWords][WORDLENGTH];
	
	fptr = fopen(FILENAME, "r");
	
	if(fptr == NULL){
		printf("Nope\n");
	}
	
	lines = countLines(fptr, str);
	
	printf("There are %d lines\n", lines);
	
	printf("%s\n", str[0]);
	
	everyOtherLine(fptr, wordType, lines);
	
	enterWords(amtWords, wordType, wordArray);
	
	fclose(fptr);

	return 0;
}

int countLines(FILE* fin, char str[][COL]){

	int lines = 0;
	int indR, indC;

	/*while(fgets(str[indR], 50, fin) != 0){
		indR ++;
	} */
	
	for(indR = 0; fgets(str[indR], ROW, fin) != 0; indR++){
		lines++;
	} 
	
	return lines;
}

void everyOtherLine(FILE* fin, char wordType[], int numLines){

	/*int i;
	char charArray[LENGTH];
	
	for(i = 0; i < numLines; i++){
		if(fgets(charArray, LENGTH, fin) != '\0'){
			if(i % 2 == 1){
				wordType[i / 2] = charArray[0];
			}
		}
	}*/
	
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
