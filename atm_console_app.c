#include <stdio.h>
#include <stdlib.h>
// funtion prototypes (UI)
void displayWelcomeMessage(void);
void displayMainMenu(void);

// funtion prototypes (Atm functionality)
void getPinNumber(void);
int readFile(void);
double withdrawCash(double balance); //
double checkAccountBalance(double deposite);
double getDepositAmount(void);
double mobileTopUp();
void transactions(double, double);
void stopAtm(void);

// function prototype (User input validation)
int readInteger(void);
int readDouble(void);
void clearBuffer(void);

// main function begins the program execution
int main()
{
    double balance = 0;        // balance before deposite
    double currentBalance = 0; // balance after withdrawal

    // print welcome message to the user
    displayWelcomeMessage();

    // ask card pin from the user user
    getPinNumber();

    int selection; // hold user selections value

    do
    {
        // dispaly selection menu and prompt user for a selection
        // if user pin number is correct
        printf("%s", "\tSelect\n");

        // invoke menu display
        displayMainMenu();

        // read user selection
        scanf("%d", &selection);

        // switch according to the users selection
        switch (selection)
        {
        case 1:; // empty statement

            // make accout deposite and store user deposite
            double deposite = getDepositAmount();

            // add deposite to existing balance
            balance += deposite;
            break;

        case 2:; // empty statement

            // invoke withdraw cash
            currentBalance = withdrawCash(balance);
            printf("balance after withdrawal = %.2lf\n", currentBalance);

            // set assign current balance to balnce after a withdrawal
            balance = currentBalance;

            break;

        case 3:
            // call balance
            double balReturn = checkAccountBalance(balance); // should take current balance

            printf("account balance is  = %.2lf\n", balance); // 980
            break;

        case 4:; // empty statement

            // top up mobile phone
            mobileTopUp();
            break;

        case 5:; // empty statement
            //  transactions(balance  );
            break;

        case 6:
            // stop using atm
            stopAtm();
            break;

        default:
            puts("invalid selection ");
            break;
        }

    } while (selection != 6);

    return 0;
}

// display an invitation messager  and check if the card is inserted
void displayWelcomeMessage(void)
{
    int cardStatus = 0; // store card status

    // Prompt user untill the card is isterted
    while (cardStatus != 1)
    {
        printf("%s", "\tWelcome inserts card, thank you \n\t(Enter 1 to insert card)\n");
        cardStatus = readInteger();

        // scanf("%d", &cardStatus);
    }
}

// get user pin number to continue with atm operation
void getPinNumber(void)
{
    // get stored password
    int pinRecord = readFile();
    while (pinRecord == -1)
    {
        // read the file the continue
        ; // do notnig
    }

    int pinNumber = 0;
    // prompt user for pin input and check for invalid pin
    while (pinNumber != pinRecord)
    {
        printf("%s", "\nEnter pin number and press enter\n");
        scanf("%d", &pinNumber);

        if (pinNumber != pinRecord) // check if pin is correct
        {
            puts("Invalid pin number\n");
        }
    }
}

// dispaly main menu for a choice selection if pin number is correct
void displayMainMenu(void)
{
    // print options to the user
    printf("%s", "\t[1] Deposit\n");
    printf("%s", "\t[2] withdraw cash\n");
    printf("%s", "\t[3] Check balancen\n");
    printf("%s", "\t[4] Mobile top up\n");
    printf("%s", "\t[5] Transactions\n");
    printf("%s", "\t[6] Stop Atm \n");
}
// add user deposit to the current account balance
double getDepositAmount(void)
{
    // initialize  deposite
    double deposite = 0;

    while (deposite <= 0)
    {
        // prompt user for deposite input
        printf("%s", "Enter deposite amount\n ");
        deposite = readDouble();

        //scanf("%lf", &deposite);
        // check for non-negative values
        if (deposite <= 0)
        {
            printf("Invalid deposite \n"); // print error
        }                                  // end if

    } // end while

    return deposite;
} // end function getDepositeAmount

// check account balance will return double to printen on a riceipt
double checkAccountBalance(double currentBalance)
{
    // on screen or receipt
    printf("Your balance is  :\t EUR %.2lf\n", currentBalance);
    return currentBalance;
} // end funciton check account  balace

// withdrawing cash from the account will reduce the balance
double withdrawCash(double balance)
{
    int selection = 0; // store user selection

    // wait for the user to make a selection
    while (selection != 1 && selection != 2 && selection != 3 &&
           selection != 4 && selection != 5 && selection != 6 && selection != 7 &&
           selection != 8)
    {
        printf("\tWithdraw\n");
        printf("\n%s", "\t[1] 20");
        printf("\n%s", "\t[2] 40");
        printf("\n%s", "\t[3] 60");
        printf("\n%s", "\t[4] 90");
        printf("\n%s", "\t[5] 140");
        printf("\n%s", "\t[6] 240");
        printf("\n%s", "\t[7] Other amount");
        printf("\n%s", "\t[8] Go to start\n");

        scanf("%d", &selection);
    }
    // switch user selection
    switch (selection)
    {
    case 1:; // empty statement  to  avoid error label can only be part of a statment
        double withdrawalAmount_1 = 20.0;

        // check for overdraft
        if (withdrawalAmount_1 > balance)
        {
            printf("Your balance is EU %.2lf \n", balance); // amount to withdraw
        }
        else
        {
            balance -= withdrawalAmount_1; // withdrawal option one
        }

        break;

    case 2:; // empty statement  to  avoid error label can only be part of a statment
        double withdrawalAmount_2 = 40.0;

        // check for overdraft
        if (withdrawalAmount_2 > balance)
        {
            printf("Your balance is EU %.2lf \n", balance); // amount to withdraw
        }
        else
        {
            balance -= withdrawalAmount_2; // withdrawal option one
        }

        break;

    case 3:; // empty statement  to  avoid error label can only be part of a statment
        double withdrawalAmount_3 = 60.0;

        // check for overdraft
        if (withdrawalAmount_3 > balance)
        {
            printf("Your balance is EU %.2lf \n", balance); // amount to withdraw
        }
        else
        {
            balance -= withdrawalAmount_3; // withdrawal option one
        }

        break;

    case 4:; // empty statement  to  avoid error label can only be part of a statment
        double withdrawalAmount_4 = 90.0;

        // check for overdraft
        if (withdrawalAmount_4 > balance)
        {
            printf("Your balance is EU %.2lf \n", balance); // amount to withdraw
        }
        else
        {
            balance -= withdrawalAmount_4; // withdrawal option one
        }

    case 5:; // empty statement  to  avoid error label can only be part of a statment
        double withdrawalAmount_5 = 140.0;

        // check for overdraft
        if (withdrawalAmount_5 > balance)
        {
            printf("Your blance is EU %.2lf \n", balance); // amount to withdraw
        }
        else
        {
            balance -= withdrawalAmount_5; // withdrawal option one
        }

        break;

    case 6:; // empty statement  to  avoid error label can only be part of a statment
        double withdrawalAmount_6 = 240.0;

        // check for overdraft
        if (withdrawalAmount_6 > balance)
        {
            printf("Your balance is  EU %.2lf \n", balance); // amount to withdraw
        }
        else
        {
            balance -= withdrawalAmount_6; // withdrawal option one
        }

        break;

    case 7:; // empty statement  to  avoid error label can only be part of a statment
        double otherAmount = 0;

        // prompt user for other amount
        printf("%s", "Other amount\n");
        scanf("%lf", &otherAmount);

        // check for overdraft
        if (otherAmount > balance)
        {
            printf("Your balance is EU %.2lf \n", balance); // amount to withdraw
        }
        else
        {
            balance -= otherAmount; // withdrawal option one
        }
        break;

    case 8:
        displayMainMenu();
        break;

    default:
        printf("invalid input\n");
        break;
    }
    return balance;

} // end function withdraw cash

// user mobile to up
double mobileTopUp()
{
    double mobile = 15.0;
    printf(" aomunt  :\t EUR %.2lf\n", mobile);
    return mobile;

} // end functionmobileToUp

void transactions(double deposite, double withdrawals)
{
    printf("EU\t: +%.2lf\n", deposite);
    printf("EU\t: -%.2lf\n", withdrawals);

} // end function transtactions

// stom usint the atm machine
void stopAtm(void)
{
    int stopAtm = 0; // input  status

    do
    {
        printf("%s", "\nTo stop atm (Enter -1 ) \n");
        scanf("%d", &stopAtm);

    } while (stopAtm != -1);
}

// open and read file content for password
int readFile(void)
{
    FILE *fp;
    char data[5]; // store number of char
    // char str[5];  // copy chars
    int value; // integer veision of str

    fp = fopen("password_file.txt", "r");
    if (fp == NULL)
    {
        printf("Error! opening data file");
        return (-1);
    }

    if (fgets(data, 5, fp) != NULL)
    {
        // puts(data);
        value = atoi(data); // convert string to integer
    }
    fclose(fp);

    return value;
}

// validate every user integer input
int readInteger(void)
{
    int number;
    char character;
    int status;

    while ((status = scanf("%d%c", &number, &character)) == 0 || (2 == status && character != '\n'))
    {
        clearBuffer();
        printf("You did not enter an integer value, Try again > ");
    }

    return number;
}
// validate every user double value input
int readDouble(void)
{
    double number;
    char character;
    int status;

    while ((status = scanf("%lf%c", &number, &character)) == 0 || (2 == status && character != '\n'))
    {
        clearBuffer();
        printf("You did not enter a real number, Try again > ");
    }

    return number;
}



// clear previous input
void clearBuffer(void)
{
    while (fgetc(stdin) != '\n')
        ; // do nothing
}
