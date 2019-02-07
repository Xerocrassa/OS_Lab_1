/*
 * MyShell Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2017, <GROUP MEMBERS>
 * All rights reserved.
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>
#include "utility.h"
#include "myshell.h"

// Put macros or constants here using #define
#define BUFFER_LEN 256
#define MAX_INPUT 16

// Put global environment variables here

// Define functions declared in myshell.h here

int main(int argc, char *argv[])
{
    // Input buffer and and commands
    char buffer[BUFFER_LEN] = {0};
    char command[BUFFER_LEN] = {0};
    char arg[BUFFER_LEN] = {0};
    char input[MAX_INPUT][BUFFER_LEN];
    char pwd[BUFFER_LEN];
    const char s[3] = " \n";

    // Perform an infinite loop getting command input from users
    while (fgets(buffer, BUFFER_LEN, stdin) != NULL)
    {
        int i = 0;
        // Perform string tokenization to get the command and argument
        char *token = strtok(buffer, s);
        while (token != NULL) {
            sprintf (input[i], "%s", token);
            token = strtok(NULL, s);
            i++;
        }
        sprintf (command, "%s", input[0]);
        
        // Check the command and execute the operations for each command
        // cd command -- change the current directory
        if (strcmp(command, "cd") == 0)
        {
            system("pwd");
            printf ("cd work\n");
        }

        else if (strcmp(command, "clr") == 0)
        {
            clr();
        }

        else if (strcmp(command, "dir") == 0)
        {
            return EXIT_SUCCESS;
        }

        else if (strcmp(command, "environ") == 0)
        {
            return EXIT_SUCCESS;
        }

        else if (strcmp(command, "echo") == 0)
        {
            return EXIT_SUCCESS;
        }

        else if (strcmp(command, "help") == 0)
        {
            return EXIT_SUCCESS;
        }

        else if (strcmp(command, "pause") == 0)
        {
            return EXIT_SUCCESS;
        }

        // other commands here...

        // quit command -- exit the shell
        else if (strcmp(command, "quit") == 0)
        {
            return EXIT_SUCCESS;
        }

        // Unsupported command
        else
        {
            fputs("Unsupported command, use help to display the manual\n", stderr);
        }
        //add directory thing here
        
    }
    return EXIT_SUCCESS;
}
