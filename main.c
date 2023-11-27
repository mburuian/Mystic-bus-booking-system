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

#define bookingDetails
void booking() {
    int rows = 10, cols = 4;
    char seats[rows][cols];
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
};

    // Array of structures to store bus information
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
 

   
    // Initialize the seats to 'O' for available
    for ( int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            seats[i][j] = 'O';
        }
    }

    // Display the seats
    printf("\n\n");
    printf("   A B C D\n");
    for (int i = 0; i < rows; i++) {
        printf("%2d ", i + 1);
        for (int j = 0; j < cols; j++) {
            printf("%c ", seats[i][j]);
        }
        printf("\n");
    }
    int i,j;
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
        char passengerName[50];
        int seatRow = 3;
        char seatColumn = 'B';
        float price = 500.00;
        
        // Display receipt
        printf("\n----- Receipt -----\n");
        printf("Passenger Name: %s\n", passengerName);
        printf("Bus Number: %d\n", selectedBusNumber);
        printf("Seat Booked: %c%d\n", seatColumn, seatRow);
        printf("Total Price: $%.2f\n", price);
        printf("--------------------\n");


    } else {
        printf("\nSeat %c%d is already booked please book another one..\n", j + 'A', i);
        //hence return the user back to  choose another seat
      
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
struct Booking {
    int bookingID;
    char destination[50];
    char date[20];
    // Add other necessary booking details here
};

// Array to store booking history (assuming a maximum of 100 bookings)
struct Booking bookingHistory[100];
int totalBookings = 0; // Counter to keep track of total bookings

void view_booking_history() {
    printf("\nBooking History:\n");

    if (totalBookings == 0) {
        printf("No bookings found.\n");
        return;
    }

    printf("Booking ID\tDestination\tDate\n");
    printf("----------------------------------------------\n");

    for (int i = 0; i < totalBookings; i++) {
        printf("%d\t\t%s\t\t%s\n", bookingHistory[i].bookingID,
               bookingHistory[i].destination, bookingHistory[i].date);
        // Print other booking details if necessary
    }
}

void addBookingToHistory(int bookingID, const char* destination, const char* date) {
    if (totalBookings < 100) {
        bookingHistory[totalBookings].bookingID = bookingID;
        strcpy(bookingHistory[totalBookings].destination, destination);
        strcpy(bookingHistory[totalBookings].date, date);
        // Assign other booking details here

        totalBookings++;
    } else {
        printf("Booking history is full. Cannot add more bookings.\n");
    }
}
// Function to simulate booking and adding it to history
void simulateBooking() {
    int bookingID = 1001; // Example booking ID
    const char* destination = "Example Destination";
    const char* date = "2023-11-17"; // Example date

    addBookingToHistory(bookingID, destination, date);
}

#define MAX_BUSES 100
 struct Bus buses[MAX_BUSES]; // Array to store bus schedules
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

        buses[numBuses++] = newBus; // Store the new bus in the array
        printf("Bus schedule added successfully.\n");
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

void search () {
    
    struct Bus buses[MAX_BUSES] = {{"Nairobi", "Mombasa", 40},
                                   {"Nairobi", "Kisumu", 30},
                                   {"Nairobi", "Eldoret", 20}};
    int numBuses = sizeof(buses) / sizeof(buses[0]);
    
    char destination[50];
    printf("Enter destination: ");
    scanf("%s", destination);
    
    printf("Available buses to %s:\n", destination);
    for (int i = 0; i < numBuses; i++) {
        if (strcmp(buses[i].destination, destination) == 0) {
            printf("%d. From %s (%d seats available)\n", i + 1 );
        }
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


void cancel_reservation(){
	 int row = 10, col = 4;
	 char seats [row][col];
    printf("Enter the row number of the seat you want to cancel: ");
    scanf("%d", &row);
    printf("Enter the column number of the seat you want to cancel: ");
    scanf("%d", &col);
    
    if (seats[row - 1][col - 1] == 'O') {
        printf("This seat is already empty.\n");
    } else {
        seats[row - 1][col - 1] = 'O';
        printf("Seat %c%d has been cancelled.\n", col + 'A' - 1, row);
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
void employeeMenu() {
    int choice;

    do {
        printf("\n\n");
        printf("========================================\n");
        printf("               MENU                     \n");
        printf("========================================\n");
        printf("1. Add a  new  bus schedule\n"); 
        printf("2. delet bus schedules or  \n");
         printf("3.view all list of busses\n");
         printf("4. modify a bus schedule");
         printf("5. Exit\n");

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
            	
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    } while (choice != 3);
}

void customerMenu() {
    int choice;

    do {
        printf("\n\n");
        printf("========================================\n");
        printf("               MENU                     \n");
        printf("========================================\n");
        printf("6. Book a seat\n");
        printf("7. Search for a bus\n");
        printf("8. Cancel booking\n");
        printf("9. View booking history\n");
        printf("10. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 6:
                booking();
                break;
            case 7:
                search();
                break;
            case 8: 
                cancel_reservation();
                break;
            case 9:
                view_booking_history();
                break;
            case 10:
                // Exit the switch and return to the main menu
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    } while (choice != 10); // Include the condition for the do-while loop
}


#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20
#define getch
// Structure to hold user information

void hidePassword(char *password) {
    int i = 0;
    char ch;

    printf("Enter your password: ");
    while (i < MAX_PASSWORD_LENGTH - 1) {
        

        if (ch == '\r' || ch == '\n') {
            password[i] = '\0';
            break;
        } else if (ch == 127 || ch == 8) { // ASCII codes for backspace/delete
            if (i > 0) {
                printf("\b \b"); // Move cursor back, erase character, move cursor back again
                i--;
            }
        } else {
            password[i] = ch;
            printf("X"); // Print 'X' instead of the actual character
            i++;
        }
    }
}

#define tolower

int main() {
    struct User employee = {"employee", "GAMEOVER"}; // Example user data
    struct User customer = {"customer", "Mburuian"}; // Example user data
    char input_choice[10];

    printf("WELCOME TO MYSTIC FALLS TRAVELLING SACCO\n");
    printf("Do you want to [login] or [register]? ");
    scanf("%s", input_choice);

    for (int i = 0; input_choice[i]; i++) {
        input_choice[i] = tolower(input_choice[i]); // Convert choice to lowercase
    }

    if (strcmp(input_choice, "login") == 0) {
        char input_username[MAX_USERNAME_LENGTH];
        char input_password[MAX_PASSWORD_LENGTH];

        printf("Enter your username: ");
        scanf("%s", input_username);

        printf("Enter your password: ");
        getchar(); // consume the newline character left by the previous scanf
        fgets(input_password, sizeof(input_password), stdin);
        input_password[strcspn(input_password, "\n")] = '\0'; // Remove newline character

        if (strcmp(input_username, employee.username) == 0 && strcmp(input_password, employee.password) == 0) {
            printf("\nWelcome Employee!\n");
            employeeMenu(); // Call the employee menu function
        } else if (strcmp(input_username, customer.username) == 0 && strcmp(input_password, customer.password) == 0) {
            printf("\nWelcome Customer!\n");
            customerMenu(); // Call the customer menu function
        } else {
            printf("\nInvalid username or password.\n");
            // Return the user to enter the correct credentials
        }
    } else if (strcmp(input_choice, "register") == 0) {
        printf("Registration functionality not implemented in this example.\n");
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}
