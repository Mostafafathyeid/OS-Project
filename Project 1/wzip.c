#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>


  int times;
  char ch;

int main(int argc,char** argv)
{
	int x=0;
	
	char* str =(char*)malloc(1);
	
	if (argc ==1) {
		
	printf("wzip: file1 [file2 ...]\n");
	return 1;
		
	}
	
	int k;
	
	for(k=1;k<argc;k++){
		
		FILE *fileread=fopen(argv[k],"r");

		if(fileread==NULL){

		    printf("ERROR FILE OPENING\n");
		    exit(1);

		}else{

		char c;

		while ((c = fgetc(fileread)) != EOF){              // reading char by char.

			x++;
			str=realloc(str,x+1);
			str[x-1]=c;                                 //append new character in the array
			str[x]='\0';                                //add '\0' at the end 
		}

		fclose(fileread);

		}

	}
       	
        int i;
        int j=1;
	
  	for(i=0;((str[i]) != '\0'); i++){
    	
		if((str[i])!=(str[i+1])){
		    times=j;
		    ch=str[i];
		    fwrite(&times,sizeof(int),1,stdout);    //print times of character appearence.
		    fwrite(&ch,sizeof(char),1,stdout);      //print the character in the file.
		    j=1;
		}

		 else j++;
    	}
	

}








