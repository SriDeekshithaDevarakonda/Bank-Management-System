#include <stdio.h>
#include <string.h>

struct Bank {
    char surname[50];
    char name[50];
    char add[100];
    char num[11];
    char type;
    float balance;
    int acc_created;
};

void open_account(struct Bank *acc) {
    printf("Enter Your full surname: ");
    getchar(); // Clear input buffer
    fgets(acc->surname, sizeof(acc->surname), stdin);
    acc->surname[strcspn(acc->surname, "\n")] = '\0'; // Remove newline

    printf("Enter your name: ");
    fgets(acc->name, sizeof(acc->name), stdin);
    acc->name[strcspn(acc->name, "\n")] = '\0'; // Remove newline

    printf("Enter your address: ");
    fgets(acc->add, sizeof(acc->add), stdin);
    acc->add[strcspn(acc->add, "\n")] = '\0'; // Remove newline

    printf("Enter your mobile number: ");
    fgets(acc->num, sizeof(acc->num), stdin);
    acc->num[strcspn(acc->num, "\n")] = '\0'; // Remove newline

    while (strlen(acc->num) != 10) {
        printf("Invalid number. Please enter a 10-digit number: ");
        fgets(acc->num, sizeof(acc->num), stdin);
        acc->num[strcspn(acc->num, "\n")] = '\0'; // Remove newline
    }

    printf("What type of account you want to open? Saving (s) or Current (C): ");
    scanf(" %c", &acc->type);

    printf("Enter amount for deposit: ");
    scanf("%f", &acc->balance);

    printf("Your account is successfully created\n");
    acc->acc_created = 1;
}

void deposit_money(struct Bank *acc) {
    float a;
    printf("Enter how much money you want to deposit: ");
    scanf("%f", &a);
    acc->balance += a;
    printf("Your current total balance: %.2f\n", acc->balance);
}

void display_account(struct Bank *acc) {
    if (acc->acc_created == 1) {
        printf("Your full name: %s %s\n", acc->surname, acc->name);
        printf("Your address: %s\n", acc->add);
        printf("Your mobile number: %s\n", acc->num);
        printf("Type of account: %c\n", acc->type);
        printf("Amount you deposited: %.2f\n", acc->balance);
    } else {
        printf("Oops, no account found! Create one!\n");
    }
}

void withdraw_money(struct Bank *acc) {
    float amount;
    printf("WITHDRAW\n");
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);
    if (acc->balance >= amount) {
        acc->balance -= amount;
        printf("Now total amount left in your account: %.2f\n", acc->balance);
    } else {
        printf("Sorry! Insufficient balance\n");
    }
}

int main() {
    int choice;
    char option;
    struct Bank account;
    account.acc_created = 0;

    do {
        printf("1. Open Account\n");
        printf("2. Deposit money\n");
        printf("3. Withdraw money\n");
        printf("4. Display Account\n");
        printf("5. Exit\n");
        printf("Select an option from the above: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf(">> Open Account\n");
                open_account(&account);
                break;
            case 2:
                printf(">> Deposit money\n");
                deposit_money(&account);
                break;
            case 3:
                printf(">> Withdraw money\n");
                withdraw_money(&account);
                break;
            case 4:
                printf(">> Display Account\n");
                display_account(&account);
                break;
            case 5:
                printf("Thank you!!!\nHope you had a safe transaction :)\n");
                return 0;
            default:
                printf("This option doesn't exist. Please try again!\n");
        }

        printf("Do you want to select any other option? Press Y/N\n");
        printf("If you want to exit then press 'N'\n");
        scanf(" %c", &option);

        if (option == 'N' || option == 'n') {
            printf("Thank you!!!\nHope you had a safe transaction :)\n");
            return 0;
        }
    } while (option == 'Y' || option == 'y');

    return 0;
}
