#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>

int numOfLines;

int main(int argc, char * argv[]) {
    
    FILE *fp;
    char* filename = argv[argc-1];
    char ch;
    
    int opt;
    while((opt = getopt(argc, argv, "n:")) != -1) {
        switch(opt) {
            case 'n':
                numOfLines = atoi(optarg);
                break;
            case ':':
                printf("option needs a value\n"); break;
            case '?':
                printf("unknown option: %c\n", optopt); break;
        }
        
    }
        
    fp = fopen(filename, "r");
    
    if(fp == NULL)
    {
        perror("Error opening the file...");
    }
    else
    {
        do {
    
            ch = fgetc(fp);
            
            if (feof(fp)) break;

            if(ch == '\n') --numOfLines;
            
            printf("%c", ch);
        
        } while(numOfLines > 0);
        
    }
    
    fclose(fp);
    
    return 0;
}

