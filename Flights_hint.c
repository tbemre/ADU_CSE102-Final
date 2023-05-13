#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FLIGHTS 100 // Maximum number of flights that can be stored

// Define a struct to hold flight information
struct Flight {
    int number;
    int type;
    char from[50];
    char to[50];
    char date[20];
    char time[10];
};

int main() {
    struct Flight flights[MAX_FLIGHTS]; // Array of flights
    int num_flights = 0; // Number of flights currently in the array
    FILE *fp; // Pointer to file
    char filename[] = "flights.txt"; // Name of file containing flight information
    char line[200]; // Buffer for reading each line of the file
    char *token; // Pointer to token within line
    int i;

    // Open file for reading
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        return 1;
    }

    // Read each line of file, parse flight information, and store in array
    while (fgets(line, 100, fp) != NULL) {
        token = strtok(line, ",");
        flights[num_flights].number=atoi(token);
        token = strtok(NULL, ",");
        flights[num_flights].type=atoi(token);
        token = strtok(NULL, ",");
        strcpy(flights[num_flights].from, token);
        printf("from=%s", flights[num_flights].from);
        token = strtok(NULL, ",");
        strcpy(flights[num_flights].to, token);
        printf(" to=%s\n", flights[num_flights].to);
        token = strtok(NULL, ",");
        strcpy(flights[num_flights].date, token);
        token = strtok(NULL, ",");
        strcpy(flights[num_flights].time, token);
        num_flights++;
    }
    // Close file
    fclose(fp);
    return 0;
}

