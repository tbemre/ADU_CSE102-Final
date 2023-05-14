#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FLIGHTS 100

void Menu();

struct Flight {
    int number;
    int type;
    char from[50];
    char to[50];
    char date[20];
    char time[10];
};

void Menu();
int first_process(struct Flight *flight);
void add_flight(struct Flight *flight,int num_flights, int* ptr);
void update_flight(struct Flight *flight,const int num_flights);
void search_departure_city(struct Flight *flight);
void search_arrival_city(struct Flight *flight);
void list_of_flight(struct Flight *flight);

int main() {
    Menu();
    return 0;
}
void Menu(){
    struct Flight flights[MAX_FLIGHTS];
    int num_flights = first_process(flights);
    int *num_flights_ptr = &num_flights;
    int temp;
    printf("MENU:\n1. Add a new flight\n2. Update a flight\n3. Search for a flight with departure city\n4. Search for a flights with arrival city\n5. List all flights\n6. Exit\nEnter your choice(1-6): ");
    scanf("%d",&temp);
    switch (temp)
    {
    case 1:
        add_flight(flights,num_flights,num_flights_ptr);
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        break;
    default:
        break;
    }
}
int first_process(struct Flight *flights){ 
    FILE *fp; 
    int num_flights = 0;
    char filename[] = "flights.txt"; 
    char line[200]; 
    char *token;
    int i;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(0);
    }

    while (fgets(line, 100, fp) != NULL) {
        token = strtok(line, ",");
        flights[num_flights].number=atoi(token);
        token = strtok(NULL, ",");
        flights[num_flights].type=atoi(token);
        token = strtok(NULL, ",");
        strcpy(flights[num_flights].from, token);
        token = strtok(NULL, ",");
        strcpy(flights[num_flights].to, token);
        token = strtok(NULL, ",");
        strcpy(flights[num_flights].date, token);
        token = strtok(NULL, ",");
        strcpy(flights[num_flights].time, token);
        num_flights++;
    }
    fclose(fp);
    return num_flights;
}

void add_flight(struct Flight *flight,int num_flights, int* ptr){
    int number,type;
    char from[50],to[50],date[20],time[10];
    printf("Enter flight number: ");
    scanf("%d",&number);
    printf("Enter flight type 1 for domestic 0 for international flights : ");
    scanf("%d",&type);
    printf("Enter the departure city of the flight: ");
    scanf("%s",from);
    printf("Enter the arrival city of the flight: ");
    scanf("%s",to);
    printf("Enter the flight date: ");
    scanf("%s",date);
    printf("Enter the flight time: ");
    scanf("%s",time);
    num_flights++;
    flight[num_flights].number=number;
    flight[num_flights].type=type;
    strcpy(flight[num_flights].from,from);
    strcpy(flight[num_flights].to, to);
    strcpy(flight[num_flights].date, date);
    strcpy(flight[num_flights].time, time);
    FILE *fp; 
    char filename[] = "flights.txt";
    fp = fopen(filename, "a+");
    fprintf(fp,"\n%d%c%d%c%s%c%s%c%s%c%s",number,',',type,',',from,',',to,',',date,',',time);
    printf("Flight inserted successfully.\n");
    *ptr = num_flights;
}
void update_flight(struct Flight *flight,const int num_flights){
    int temp,i,check = 0;
    printf("Enter flight number to update: ");
    scanf("%d",&temp);
    for(i=0;i<num_flights;i++){
        if(temp == flight[i].number)
            check = 1;
            break;
    }
    if(!check){
        printf("BURAYA OLUMZUSUNU YAZACAKSIN !!!!!!!!!!!");
    }
    else{
        printf("Flight found. Which field would you like to update?\n1. Type\n2. From\n3. To\n4. Date\n5. Time\nEnter your choice (1-5): ");
        scanf("%d",&temp);
        switch (temp)
        {
        case 1:
            printf("Enter new type : ");
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        default:
            break;
        }
    }
}
