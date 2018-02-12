//
//  main.c
//  HW2_1
//
//  Created by Gabriel Barros on 2/11/18.
//  Copyright © 2018 Gabriel Barros. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>

int numOfLines;

int main(int argc, char * argv[]) {
    
    FILE *fp;
    char* filename = argv[argc-1];
    
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
    
    int ch;
    int lines = 0;
    
    fp = fopen(filename, "r");
    
    if(fp == NULL)
    {
        perror("Error opening the file...");
    }
    else
    {
        do {
            if( feof(fp) ) {
                break ;
            }
            
            ch = fgetc(fp);
            
            if(ch == '\n') ++lines;
            
            printf("%c", ch);
            
            if(lines == numOfLines) break;
            
            
        } while(1);
    }
    
    fclose(fp);
    
    return 0;
}






