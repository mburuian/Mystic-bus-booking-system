#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <stdbool.h>
#include <conio.h> 

void booking();
void cancel_reservation();
void exit();
void Admin();
 void review();
 //this file is used to store all the bus  information
 
 
#define bookingDetails
void booking() {
    int rows = 10, cols = 4;
    char seats[rows][cols];
    int i, j;
    char name[50];
    char from[50];
    char to[50];
    float price;
    float kilometers;
    float bus_number;
	char content[1000];
// Structure to hold bus information
struct Bus {
    int busNumber;
    char startLocation[50];
    char destination[50];
    char driverName[50];
    char departureTime[20];
    char newBooking;
    char passengerName[50];
    int seatRow;
    char seatColumn;
    float price;
};

    // Array of structures to store bus information
    //store this information in the content array
    struct Bus buses[] = {
        {1, "Nairobi City", "Kisumu County", "Mr. Nganga", "8:00 AM"},
        {2, "Nairobi City", "Kakamega County", "Mr. Samson", "10:00 AM"},
        {3, "Nairobi City", "Kajiado County", "Mr. Paul", "9:00 AM"},
        {4, "Nairobi City", "Muranga County", "Mr. Waithaka", "6:00 AM"}
        // Add more buses as needed
    };

    int numBuses = sizeof(buses) / sizeof(buses[0]); // Calculate the number of buses

    // Display all available buses for the user to choose
    printf("Available Buses:\n");
    for (int i = 0; i < numBuses; i++) {
        printf("Bus No: %d\n", buses[i].busNumber);
        printf("Start Location: %s\n", buses[i].startLocation);
        printf("Destination: %s\n", buses[i].destination);
        printf("Driver: %s\n", buses[i].driverName);
        printf("Departure Time: %s\n", buses[i].departureTime);
        printf("----------------------------\n");
    }

    // Ask the user to choose the bus they want to travel in
    int selectedBusNumber;
    printf("Enter the bus number you want to travel in: ");
    scanf("%d", &selectedBusNumber);

    // Find the selected bus and display its information
    int selectedBusIndex = -1;
    for (int i = 0; i < numBuses; i++) {
        if (buses[i].busNumber == selectedBusNumber) {
            selectedBusIndex = i;
            break;
        }
    }

    if (selectedBusIndex != -1) {
        printf("\nYou have chosen Bus No %d:\n", buses[selectedBusIndex].busNumber);
        printf("Start Location: %s\n", buses[selectedBusIndex].startLocation);
        printf("Destination: %s\n", buses[selectedBusIndex].destination);
        printf("Driver: %s\n", buses[selectedBusIndex].driverName);
        printf("Departure Time: %s\n", buses[selectedBusIndex].departureTime);
        // Proceed with the booking process for this selected bus...
    } else {
        printf("\nInvalid bus number. Please select a valid bus.\n");
    }




	
    //getting details from the user
  
    printf("Enter passenger name: ");
    scanf("%s", name);

   
    // Initialize the seats to 'O' for available
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            seats[i][j] = 'O';
        }
    }

    // Display the seats
    printf("\n\n");
    printf("   A B C D\n");
    for (i = 0; i < rows; i++) {
        printf("%2d ", i + 1);
        for (j = 0; j < cols; j++) {
            printf("%c ", seats[i][j]);
        }
        printf("\n");
    }

    // Ask the user which seat they want to book
    printf("\nEnter the row number of the seat you want to book: ");
    scanf("%d", &i);
    printf("Enter the column letter of the seat you want to book: ");
    scanf(" %c", &j);

    // Convert the column letter to a zero-based index
    j -= 'A';

    // Check if the seat is available
    if (seats[i - 1][j] == 'O') {
        seats[i - 1][j] = 'X';
        printf("\nSeat %c%d has been booked.\n", j + 'A', i);
        
        // Assume booking details
        struct Bus newBooking; // Creating a booking instance

        // Assigning booking details
        strcpy(newBooking.passengerName, name);
        newBooking.busNumber = selectedBusNumber; // Assuming selectedBusNumber is defined
        newBooking.seatRow = i;
        newBooking.seatColumn = j + 'A';
        newBooking.price = 500.00;

        // Open busdetails file for appending
        FILE *busdetails;
        busdetails = fopen("busdetails.txt", "a+");
        if (busdetails == NULL) {
            perror("Error opening busdetails.txt");
            return;
        }

        // Write booking details to the file
        fprintf(busdetails, "Passenger Name: %s, Bus Number: %d, Seat: %c%d, Price: %.2f\n",
                newBooking.passengerName, newBooking.busNumber, newBooking.seatColumn, newBooking.seatRow, newBooking.price);

        // Close the file
        fclose(busdetails);

        // Display receipt
        printf("\n----- Receipt -----\n");
        printf("Passenger Name: %s\n", newBooking.passengerName);
        printf("Bus Number: %d\n", newBooking.busNumber);
        printf("Seat Booked: %c%d\n", newBooking.seatColumn, newBooking.seatRow);
        printf("Total Price: $%.2f\n", newBooking.price);
        printf("--------------------\n");
    } else {
        printf("\nSeat %c%d is already booked please book another one..\n", j + 'A', i);
        // Hence return the user back to choose another seat
    }
}






#define MAX_SEATS 32  
struct Bus {
    char number[10];
    char driver[20];
    char origin[20];
    char destination[20];
    char departure[10];
    char arrival[10];
    int  seats[MAX_SEATS];
    
};
#define MAX_BOOKINGS 100
struct Booking {
    int bookingID;
    char destination[50];
    char date[20];
    // Add other necessary booking details here
};

struct Booking bookingHistory[MAX_BOOKINGS];
int totalBookings = 0;

void view_booking_history() {
    printf("\nBooking History:\n");

    FILE *busDetailsFile = fopen("busdetails.txt", "r");
    if (busDetailsFile == NULL) {
        perror("Error opening busdetails.txt");
        return;
    }

    printf("Booking ID\tDestination\tDate\n");
    printf("----------------------------------------------\n");

    int bookingID;
    char destination[50];
    char date[20];

    while (fscanf(busDetailsFile, "%d %s %s", &bookingID, destination, date) == 3) {
        printf("%d\t\t%s\t\t%s\n", bookingID, destination, date);

        // Add booking to the history array
        if (totalBookings < MAX_BOOKINGS) {
            bookingHistory[totalBookings].bookingID = bookingID;
            strcpy(bookingHistory[totalBookings].destination, destination);
            strcpy(bookingHistory[totalBookings].date, date);
            totalBookings++;
        } else {
            printf("Booking history is full. Cannot add more bookings.\n");
            break; // Break if the history is full
        }
    }

    fclose(busDetailsFile);

    if (totalBookings == 0) {
        printf("No bookings found.\n");
    }
}

// Function to simulate booking and adding it to history



#define MAX_BUSES 100
 struct Bus buses[MAX_BUSES]; // store the information in the content array
 int numBuses = 0;
 void displayBuses() {
    if (numBuses == 0) {
        printf("No buses available.\n");
        return;
    }

    printf("\n==========================\n");
    printf("  Available Bus Schedules\n");
    printf("==========================\n");
    for (int i = 0; i < numBuses; i++) {
        printf("Bus Number: %s\n", buses[i].number);
        printf("Driver: %s\n", buses[i].driver);
        printf("Origin: %s\n", buses[i].origin);
        printf("Destination: %s\n", buses[i].destination);
        printf("Departure: %s\n", buses[i].departure);
        printf("Arrival: %s\n", buses[i].arrival);
        printf("Seats: %d\n", buses[i].seats);
        printf("--------------------------\n");
    }
}



void addBus() {
    if (numBuses < MAX_BUSES) {
        struct Bus newBus;

        printf("Enter bus number: ");
        scanf("%s", newBus.number);

        printf("Enter driver name: ");
        scanf("%s", newBus.driver);

        printf("Enter origin: ");
        scanf("%s", newBus.origin);

        printf("Enter destination: ");
        scanf("%s", newBus.destination);

        printf("Enter departure time: ");
        scanf("%s", newBus.departure);

        printf("Enter arrival time: ");
        scanf("%s", newBus.arrival);

        // Initialize all seats to available
        for (int i = 0; i < MAX_SEATS; i++) {
            newBus.seats[i] = 0;
        }

        buses[numBuses++] = newBus; // Store the new bus in the buses array
        printf("Bus schedule added successfully.\n");

        // Open the busses file for appending
        FILE *bussesFile = fopen("busses.txt", "a");
        if (bussesFile == NULL) {
            perror("Error opening busses.txt");
            return;
        }

        // Write new bus details to the file
        fprintf(bussesFile, "Bus Number: %s\nDriver: %s\nOrigin: %s\nDestination: %s\nDeparture Time: %s\nArrival Time: %s\n\n",
                newBus.number, newBus.driver, newBus.origin, newBus.destination, newBus.departure, newBus.arrival);

        // Close the file
        fclose(bussesFile);
    } else {
        printf("Cannot add more bus schedules. Maximum limit reached.\n");
    }
}


#define MAX_BUSES 100
struct search {
    char source[50];
    char destination[50];
    int availableSeats;
};

void search() {
	
    FILE *bussesFile = fopen("busses.txt", "r");
    if (bussesFile == NULL) {
        perror("Error opening busses.txt");
        return;
    }

    struct Bus buses[MAX_BUSES];
    int numBuses = 0;
    int Seats;

    // Read bus information from the file
    while (fscanf(bussesFile, "%s %s %d", buses[numBuses].origin, buses[numBuses].destination, &buses[numBuses].seats[MAX_SEATS]) == 3) {
        numBuses++;
    }

    fclose(bussesFile);

    char destination[50];
    printf("Enter destination: ");
    scanf("%s", destination);

    printf("Available buses to %s:\n", destination);
    int found = 0;
    for (int i = 0; i < numBuses; i++) {
        if (strcmp(buses[i].destination, destination) == 0) {
            printf("%d. From %s (%d seats available)\n", i + 1, buses[i].origin, buses[i].seats[MAX_SEATS]);
            found = 1;
        }
    }

    if (!found) {
        printf("No buses available to %s.\n", destination);
    }
}


// Function to modify a bus schedule
void modifyBus() {
    char numberToModify[10];
    int found = 0;

    printf("Enter bus number to modify: ");
    scanf("%s", numberToModify);

    for (int i = 0; i < numBuses; i++) {
        if (strcmp(buses[i].number, numberToModify) == 0) {
            // Get new details for the modified bus schedule
            printf("Enter new driver name: ");
            scanf("%s", buses[i].driver);

            // Get other modified details as needed
            // ...

            found = 1;
            printf("Bus schedule with number %s has been modified.\n", numberToModify);
            break;
        }
    }

    if (!found) {
        printf("Bus schedule with number %s not found.\n", numberToModify);
    }
}


#include <stdio.h>

void cancel_reservation(){
    int rows = 10, cols = 4;
    char seats[rows][cols];

    printf("Enter the row number of the seat you want to cancel: ");
    int row_input;
    scanf("%d", &row_input);

    printf("Enter the column number of the seat you want to cancel: ");
    int col_input;
    scanf("%d", &col_input);

    if (row_input < 1 || row_input > rows || col_input < 1 || col_input > cols) {
        printf("Invalid seat selection.\n");
    } else if (seats[row_input - 1][col_input - 1] == 'O') {
        printf("This seat is already empty.\n");
    } else {
        seats[row_input - 1][col_input - 1] = 'O';
        printf("Seat %c%d has been cancelled.\n", col_input + 'A' - 1, row_input);
    }
}


#define MAX_USERNAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 50


struct User {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};
void deleteBus() {
    char numberToDelete[10];
    int found = 0;

    printf("Enter bus number to delete: ");
    scanf("%s", numberToDelete);

    for (int i = 0; i < numBuses; i++) {
        if (strcmp(buses[i].number, numberToDelete) == 0) {
            for (int j = i; j < numBuses - 1; j++) {
                buses[j] = buses[j + 1];
            }
            numBuses--;
            found = 1;
            printf("Bus schedule with number %s has been deleted.\n", numberToDelete);
            break;
        }
    }

    if (!found) {
        printf("Bus schedule with number %s not found.\n", numberToDelete);
    }
}

 int main_menu(){
	char addbus;
	char deletbuses;
    int choice;
     while (1){
    printf("\n\n");
    printf("========================================\n");
    printf("               MENU                     \n");
    printf("========================================\n");
    printf("1. Add a  new  bus schedule\n"); 
    printf("2. delet bus schedules or  \n");
    printf("3. view all list of busses\n");
    printf("4. modify a bus schedule\n");
    printf("5. Book a seat\n");
    printf("6. Search for a bus\n");
    printf("7. Cancel booking\n");
    printf("8. View booking history\n");
    printf("9. Exit\n");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            addBus();
            break;
        case 2:
            // Code to delet new bus schedules
            deleteBus();
            break;
        case 3:
            // Code to view all list of busses
            displayBuses();
            break;
        case 4:
            // code to modify a bus list
            modifyBus();
            break;
        case 5:
            booking();
            break;
        case 6:
            search();
            break;
        case 7: 
            cancel_reservation();
            break;
        case 8:
            view_booking_history();
            break;
        case 9:
            // Exit the switch and return to the main menu
            break;
        default:
            printf("\nInvalid choice. Please try again.\n");
            break;
    
    
	}
}
 }


int login(FILE *credential){
    char username[50];
    char password[50];
    char ch;
    int i = 0;
    char fileUsername[50];
    char filePassword[50];
    int loggedIn;
    printf("|----------------------------------------------------------------------------------|\n");
    printf("| Enter your username: ");
    scanf("   %s", username);
    printf("|----------------------------------------------------------------------------------|\n");
    printf("| Enter your password: ");
    while((ch = getch())!= 13){
        password[i] = ch;
        i++;
        printf("*");
    }
    password[i] = '\0';
    i = 0;
    
    rewind(credential); // Reset file pointer to the beginning

    while (fscanf(credential, "%s %s", fileUsername, filePassword) != EOF){
        if (strcmp(username, fileUsername) == 0 && strcmp(password, filePassword) == 0){
            printf("|----------------------------------------------------------------------------------|\n");
            printf("| Login successful!                                                                |\n");
            printf("|----------------------------------------------------------------------------------|\n");
              if (loggedIn) {
        main_menu(); // Call main menu function if login was successful
			  }
        }
    }
    printf("|----------------------------------------------------------------------------------|\n");
    printf("| Login unsuccessful. Please check your credentials.\n                             |");
    printf("|----------------------------------------------------------------------------------|\n");
    return 0;
}

void sign_up(FILE * credentials){
	char username[50];
    char password[50];
      printf("|==================================================================================|\n");
    printf("| Enter a username: ");
    scanf("%s", username);
     printf("|==================================================================================|\n");
    printf("| Enter a password: ");
    scanf("%s", password);
     printf("|==================================================================================|\n");

    fprintf(credentials, "%s %s\n", username, password);
      printf("|==================================================================================|\n");
    printf("| Registration successful!\n");
    printf("|==================================================================================|\n");
    system("cls");
}

	



int main() {
	
	FILE * credentials;
	credentials = fopen("credentials.txt", "a+");
	
	FILE * busdetails;
	busdetails = fopen("busdetails.txt","a+");
	
	FILE * busses;
	busses = fopen("busses.txt", "a+");
	
    struct User employee = {"employee", "GAMEOVER"}; // Example user data
    struct User customer = {"customer", "Mburuian"}; // Example user data
    int input_choice;

    printf("WELCOME TO MYSTIC FALLS TRAVELLING SACCO\n");
    printf("Do you want to 1[login] or 2[register]? ");
    scanf("%d", &input_choice);
    
    if (input_choice == 1){
	      login(credentials);
	      
	} else if(input_choice == 2){
		  sign_up(credentials);

	} else {
		printf("invalid choice");
	}

    return 0;
}

    