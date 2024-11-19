#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Define structure for linked list nodes
struct Node {
    char* data;
    struct Node* next;
};

// Function to create a new linked list node
struct Node* createNode(char* data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = strdup(data);
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
void insertNode( struct Node** head, char* data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to print the linked list
void printList(struct Node* ptr) {
    while (ptr != NULL) {
        printf("%s ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

// Function to generate computer's choice
int ComputerChoice() {
    return (rand() % 3) + 1;
}

// Function to determine the winner
char* Winner(int userChoice, int compChoice) {
    if (userChoice == compChoice)
        return "DRAW";

    if ((userChoice == 1 && compChoice == 2) || (compChoice == 1 && userChoice == 2))
        return "Paper";
    if ((userChoice == 1 && compChoice == 3) || (compChoice == 1 && userChoice == 3))
        return "Rock";
    if ((userChoice == 2 && compChoice == 3) || (compChoice == 2 && userChoice == 3))
        return "Scissors";
}

int main() {
    srand(time(NULL)); // Seed for random number generation

    struct Node* choices = NULL;
    insertNode(&choices, "Rock");
    insertNode(&choices, "Paper");
    insertNode(&choices, "Scissors");

    while (1) {
        printf("Winning rules of the game ROCK PAPER SCISSORS are:\n");
        printf("Rock vs Paper -> Paper wins \n");
        printf("Rock vs Scissors -> Rock wins \n");
        printf("Paper vs Scissors -> Scissors wins \n\n");

        printf("Enter your choice \n");
        printList(choices);

        int userChoice;
        printf("Enter your choice (1-3): ");
        scanf("%d", &userChoice);

        // Validate user input
        while (userChoice < 1 || userChoice > 3) {
            printf("Enter a valid choice (1-3): ");
            scanf("%d", &userChoice);
        }

        struct Node* ptr = choices;
        int count = 1;
        while (ptr != NULL) {
            if (count == userChoice) {
                printf("User choice is: %s\n", ptr->data);
            }
            ptr = ptr->next;
            count++;
        }
        printf("\n");

        printf("Now it's Computer's Turn...\n");

        int compChoice = ComputerChoice();
        ptr = choices;
        count = 1;
        while (ptr != NULL) {
            if (count == compChoice) {
                printf("Computer choice is: %s\n", ptr->data);
            }
            ptr = ptr->next;
            count++;
        }

        char* result = Winner(userChoice, compChoice);
        printf("%s vs %s\n", choices->data, choices->next->data);

        if (strcmp(result, "DRAW") == 0)
            printf("<== It's a tie! ==>\n");
        else if (strcmp(result, choices->data) == 0)
            printf("<== User wins! ==>\n");
        else
            printf("<== Computer wins! ==>\n");

        printf("Do you want to play again? (Y/N): ");
        char playAgain;
        scanf(" %c", &playAgain);

        if (playAgain == 'n' || playAgain == 'N')
            break;
    }
    printf("\n");

    printf("Thanks for playing!\n");

    // Free the linked list memory
    struct Node* ptr = choices;
    while (ptr != NULL) {
       struct Node* next = ptr->next;
        free(ptr->data);
        free(ptr);
        ptr= next;
    }

    return 0;
}


