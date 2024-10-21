#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSPORTS 100
#define FILENAME "passports.txt"

typedef struct {
    char name[50];
    char dob[15];
    char address[100];
    char nationality[50];
    char passport_number[20];
    char expiration_date[15];
} Passport;

Passport passports[MAX_PASSPORTS];
int passport_count = 0;

// Function prototypes
void load_passports();
void save_passports();
void create_passport();
void view_passport();
void filter_passport();
void update_passport();
void delete_passport();
void display_menu();

int main() {
    load_passports(); // Load data from file
    int choice;
    do {
        display_menu(); // Show menu options
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character

        switch (choice) {
            case 1: create_passport(); break;
            case 2: view_passport(); break;
            case 3: filter_passport(); break;
            case 4: update_passport(); break;
            case 5: delete_passport(); break;
            case 6: save_passports(); break;
            case 7: printf("Exiting the program.\n"); break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}

//  To load passports from file
void load_passports() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("No existing passport records found. Starting fresh.\n");
        return; //  no file exists, exit function
    }

    while (fscanf(file, "%49[^,],%14[^,],%99[^,],%49[^,],%19[^,],%14[^\n]\n",
                  passports[passport_count].name,
                  passports[passport_count].dob,
                  passports[passport_count].address,
                  passports[passport_count].nationality,
                  passports[passport_count].passport_number,
                  passports[passport_count].expiration_date) == 6) {
        passport_count++;
    }
    fclose(file);
}

//   save passports to file
void save_passports() {
    FILE *file = fopen(FILENAME, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < passport_count; i++) {
        fprintf(file, "%s,%s,%s,%s,%s,%s\n",
                passports[i].name,
                passports[i].dob,
                passports[i].address,
                passports[i].nationality,
                passports[i].passport_number,
                passports[i].expiration_date);
    }
    fclose(file);
    printf("Passport records saved successfully.\n");
}

// create a new passport
void create_passport() {
    if (passport_count >= MAX_PASSPORTS) {
        printf("Maximum passport limit reached.\n");
        return;
    }

    printf("Enter Name: ");
    fgets(passports[passport_count].name, sizeof(passports[passport_count].name), stdin);
    strtok(passports[passport_count].name, "\n"); // Remove newline

    printf("Enter Date of Birth (DD/MM/YYYY): ");
    fgets(passports[passport_count].dob, sizeof(passports[passport_count].dob), stdin);
    strtok(passports[passport_count].dob, "\n");

    printf("Enter Address: ");
    fgets(passports[passport_count].address, sizeof(passports[passport_count].address), stdin);
    strtok(passports[passport_count].address, "\n");

    printf("Enter Nationality: ");
    fgets(passports[passport_count].nationality, sizeof(passports[passport_count].nationality), stdin);
    strtok(passports[passport_count].nationality, "\n");

    printf("Enter Passport Number: ");
    fgets(passports[passport_count].passport_number, sizeof(passports[passport_count].passport_number), stdin);
    strtok(passports[passport_count].passport_number, "\n");

    printf("Enter Expiration Date (DD/MM/YYYY): ");
    fgets(passports[passport_count].expiration_date, sizeof(passports[passport_count].expiration_date), stdin);
    strtok(passports[passport_count].expiration_date, "\n");

    passport_count++;
    printf("Passport created successfully.\n");
}

//  view a passport by its number
void view_passport() {
    char passport_number[20];
    printf("Enter Passport Number to view: ");
    fgets(passport_number, sizeof(passport_number), stdin);
    strtok(passport_number, "\n");

    for (int i = 0; i < passport_count; i++) {
        if (strcmp(passports[i].passport_number, passport_number) == 0) {
            printf("Passport Details:\n");
            printf("Name: %s\n", passports[i].name);
            printf("Date of Birth: %s\n", passports[i].dob);
            printf("Address: %s\n", passports[i].address);
            printf("Nationality: %s\n", passports[i].nationality);
            printf("Passport Number: %s\n", passports[i].passport_number);
            printf("Expiration Date: %s\n", passports[i].expiration_date);
            return;
        }
    }
    printf("Passport not found.\n");
}

//  filter passports by nationality
void filter_passport() {
    char nationality[50];
    printf("Enter Nationality to filter: ");
    fgets(nationality, sizeof(nationality), stdin);
    strtok(nationality, "\n");

    printf("Filtered Passports:\n");
    for (int i = 0; i < passport_count; i++) {
        if (strcmp(passports[i].nationality, nationality) == 0) {
            printf("Name: %s, Passport Number: %s, Expiration Date: %s\n",
                   passports[i].name,
                   passports[i].passport_number,
                   passports[i].expiration_date);
        }
    }
}

// update a passport by its number
void update_passport() {
    char passport_number[20];
    printf("Enter Passport Number to update: ");
    fgets(passport_number, sizeof(passport_number), stdin);
    strtok(passport_number, "\n");

    for (int i = 0; i < passport_count; i++) {
        if (strcmp(passports[i].passport_number, passport_number) == 0) {
            printf("Updating details for passport number: %s\n", passport_number);
            printf("Enter New Name: ");
            fgets(passports[i].name, sizeof(passports[i].name), stdin);
            strtok(passports[i].name, "\n");

            printf("Enter New Date of Birth (DD/MM/YYYY): ");
            fgets(passports[i].dob, sizeof(passports[i].dob), stdin);
            strtok(passports[i].dob, "\n");

            printf("Enter New Address: ");
            fgets(passports[i].address, sizeof(passports[i].address), stdin);
            strtok(passports[i].address, "\n");

            printf("Enter New Nationality: ");
            fgets(passports[i].nationality, sizeof(passports[i].nationality), stdin);
            strtok(passports[i].nationality, "\n");

            printf("Enter New Expiration Date (DD/MM/YYYY): ");
            fgets(passports[i].expiration_date, sizeof(passports[i].expiration_date), stdin);
            strtok(passports[i].expiration_date, "\n");

            printf("Passport updated successfully.\n");
            return;
        }
    }
    printf("Passport not found.\n");
}

//  delete a passport by its number
void delete_passport() {
    char passport_number[20];
    printf("Enter Passport Number to delete: ");
    fgets(passport_number, sizeof(passport_number), stdin);
    strtok(passport_number, "\n");

    for (int i = 0; i < passport_count; i++) {
        if (strcmp(passports[i].passport_number, passport_number) == 0) {
            for (int j = i; j < passport_count - 1; j++) {
                passports[j] = passports[j + 1]; // Shift records
            }
            passport_count--;
            printf("Passport deleted successfully.\n");
            return;
        }
    }
    printf("Passport not found.\n");
}

//  display the menu
void display_menu() {
    printf("\n--- Passport Management System ---\n");
    printf("1. Create Passport\n");
    printf("2. View Passport\n");
    printf("3. Filter Passport\n");
    printf("4. Update Passport\n");
    printf("5. Delete Passport\n");
    printf("6. Save Passports\n");
    printf("7. Exit\n");
}
