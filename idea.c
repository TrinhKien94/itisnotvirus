#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void formatString(char* string){
	int i = 0;
	while(string[i] != '\0'){
		string[i] = '\0';
		i++;
	}
}

void createFileName(char* fileName, int number){
	char nName[20];
	sprintf(nName, "%d", number);
	strcpy(fileName,"codes/test");
	strcat(fileName,nName);
	strcat(fileName,".c");
}

void genFile(char* sourceFileName){
	FILE *f = fopen(sourceFileName,"w");
	fprintf(f,"#include <stdio.h>\n#include <stdlib.h>\nint main(){\nint i;\nprintf(\"Hello Boss\\n\");\n}");
	fclose(f);
}

int buildFile(char* sourceFileName, char* errorLogFileName){
	char command[50];
	strcpy(command, "gcc -o bot ");
	strcat(command, sourceFileName);
	strcat(command, " 2>>");
	strcat(command, errorLogFileName); //command = gcc -o a /*fileName*/ 2>> /*errorLogFileName*/
	if(system(command)==256){
		return -1; //build error, error mess in errorLogFileName
	}
	return 1; //build success
}

int runFile(char* fileName, char* errorLogFileName){
	char command[50];
	strcpy(command, "./bot >run.out 2>>");
	strcat(command, errorLogFileName);
	return system(command);
}

void createBotDirectory(char* errorLogFileName){
	char command[50];
	strcpy(command, "mkdir codes 2>>");
	strcat(command, errorLogFileName);
	system(command);
}

int main(){
	char fileName[20];
	char errorLogFileName[20];
	createBotDirectory(errorLogFileName);
	createFileName(fileName, 1);
	genFile(fileName);
	if(buildFile(fileName, errorLogFileName)!=-1){
		runFile(fileName, errorLogFileName);
	}else{
		printf("Build error\n");
	}
}
