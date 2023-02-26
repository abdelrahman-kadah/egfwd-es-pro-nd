/*
* GeeksForGeeks Website under CC License 

https://www.geeksforgeeks.org/clearing-the-input-buffer-in-cc/

I used this helper code to clear the input buffer:

while(getchar() != '\n'); //Busy wait until the newline is written

*/


#include "server.h"

//#define DATABASE_SIZE 255

ST_accountsDB_t accountsDB[255] = {
	{2000.0, RUNNING, "8989374615436851"},
	{100000.0, BLOCKED, "5807007076043875"},
	{50000.0, RUNNING, "7898752989745067"},
	{10000.0, BLOCKED, "9698753989845067"},
	{3000.0, RUNNING, "6987529897457698"} };

ST_transaction_t transactionDB[255] = {0};

uint32_t sequenceNumber = 0; //transaction database is empty


EN_connectionStatus_t serverStatus = CONNECTED; //To simulate the server connection



EN_serverError_t isValidAccount(ST_cardData_t* cardData, ST_accountsDB_t* accountReference)
{
	
	for (uint8_t i = 0; i < 5; i++)
	{
		if (strcmp(cardData->primaryAccountNumber, accountsDB[i].primaryAccountNumber) == 0)
		{
			
			(accountReference->balance) = accountsDB[i].balance;
			strcpy(accountReference->primaryAccountNumber, accountsDB[i].primaryAccountNumber);
			(accountReference->state) = accountsDB[i].state;
			
			return SERVER_OK;
		}
	}
	accountReference = NULL;
	return ACCOUNT_NOT_FOUND;
}

void isValidAccountTest(void)
{
	ST_cardData_t cardData;
	ST_accountsDB_t accountReference;
	EN_serverError_t serverError;

	printf("Tester Name: Abd El-Rahman Kadah\n");
	printf("Function Name: isValidAccountTest\n\n");

	printf("Test Case 1: Primary account number doesn't exist in the database\n");

	printf("Input Data: \n");
	printf("PAN: ");
	gets(cardData.primaryAccountNumber);
	serverError = isValidAccount(&cardData, &accountReference);
	printf("Expected Result: ACCOUNT_NOT_FOUND\n");
	printf("Actual Result: %s\n\n", (serverError ? "ACCOUNT_NOT_FOUND" : "SERVER_OK"));

	printf("Test Case 2: Primary account number exists in the database\n");

	printf("Input Data: \n");
	printf("PAN: ");
	gets(cardData.primaryAccountNumber);
	serverError = isValidAccount(&cardData, &accountReference);
	printf("Expected Result: SERVER_OK\n");
	printf("Actual Result: %s\n\n", (serverError ? "ACCOUNT_NOT_FOUND" : "SERVER_OK"));


}



EN_serverError_t isBlockedAccount(ST_accountsDB_t* accountReference)
{
	if(accountReference->state == BLOCKED)
	{
		return BLOCKED_ACCOUNT;
	}
	else
	{
		return SERVER_OK;

	}
}

void isBlockedAccountTest(void)
{
	ST_accountsDB_t accountReference;
	EN_serverError_t serverError;

	printf("Tester Name: Abd El-Rahman Kadah\n");
	printf("Function Name: isBlockedAccountTest\n\n");

	printf("Test Case 1: Account is Blocked\n");

	printf("Input Data: 0 (RUNNING) or 1 (BLOCKED)\n");
	printf("Account State: ");
	scanf("%d", &(accountReference.state));
	serverError = isBlockedAccount(&accountReference);
	printf("Expected Result: BLOCKED_ACCOUNT\n");
	printf("Actual Result: %s\n\n", (serverError ? "BLOCKED_ACCOUNT" : "SERVER_OK"));

	printf("Test Case 2: Account is Running\n");

	printf("Input Data: 0 (RUNNING) or 1 (BLOCKED)\n");
	printf("Account State: ");
	scanf("%d", &(accountReference.state));
	serverError = isBlockedAccount(&accountReference);
	printf("Expected Result: SERVER_OK\n");
	printf("Actual Result: %s\n\n", (serverError ? "BLOCKED_ACCOUNT" : "SERVER_OK"));

}



EN_serverError_t isAmountAvailable(ST_terminalData_t* termData, ST_accountsDB_t* accountReference)
{
	if ((termData->transAmount) > (accountReference->balance))
	{
		return LOW_BALANCE;
	}
	else
	{
		return SERVER_OK;
	}
}

void isAmountAvailableTest(void)
{
	ST_terminalData_t termData;
	ST_accountsDB_t accountReference;
	EN_serverError_t serverError;

	printf("Tester Name: Abd El-Rahman Kadah\n");
	printf("Function Name: isAmountAvaialableTest\n\n");

	printf("Test Case 1: Transaction amount is larger than the balance\n");

	printf("Input Data: \n");
	printf("Account Balance: ");
	scanf("%f", &(accountReference.balance));

	printf("Transaction Amount: ");
	scanf("%f", &(termData.transAmount));

	serverError = isAmountAvailable(&termData, &accountReference);
	printf("Expected Result: LOW_BALANCE\n");
	printf("Actual Result: %s\n\n", (serverError ? "LOW_BALANCE" : "SERVER_OK"));

	printf("Test Case 2: Transaction amount is less than or equal to the balance\n");

	printf("Input Data: \n");
	printf("Account Balance: ");
	scanf("%f", &(accountReference.balance));

	printf("Transaction Amount: ");
	scanf("%f", &(termData.transAmount));

	serverError = isAmountAvailable(&termData, &accountReference);
	printf("Expected Result: SERVER_OK\n");
	printf("Actual Result: %s\n\n", (serverError ? "LOW_BALANCE" : "SERVER_OK"));

	
}

void listSavedTransactions(void)
{
	if (sequenceNumber == 0)
	{
		printf("The Transaction Database is empty");
		return;
	}
	else
	{
		for (uint32_t i = 0; i < sequenceNumber; i++)
		{
			printf("#########################\n");
			printf("Transaction Sequence Number: %lu\n", transactionDB[i].transactionSequenceNumber);
			printf("Transaction Date: %s\n", transactionDB[i].terminalData.transactionDate);
			printf("Transaction Amount: %f\n", transactionDB[i].terminalData.transAmount);
			printf("Transaction State: %s\n", "APPROVED"); //Because we are assuming that the only approved transactions that printed
			printf("Terminal Max Amount: %f\n", transactionDB[i].terminalData.maxTransAmount);
			printf("Cardholder Name: %s\n", transactionDB[i].cardHolderData.cardHolderName);
			printf("PAN: %s\n", transactionDB[i].cardHolderData.primaryAccountNumber);
			printf("Card Expiration Date: %s\n", transactionDB[i].cardHolderData.cardExpirationDate);
			printf("#########################\n");
		}

	}

}

void listSavedTransactionsTest(void)
{
	printf("Tester Name: Abd El-Rahman Kadah\n");
	printf("Function Name: listSavedTransastionTest\n\n");

	printf("Test Case 1: The transaction database is empty\n");

	printf("Input Data: Sequence Number is 0 \n");
	printf("Sequence Number: ");
	scanf("%lu", &sequenceNumber);
	while ((getchar()) != '\n'); //clear the input buffer 

	printf("Expected Result: The Transaction Database is empty\n");
	printf("Actual Result: ");
	listSavedTransactions();
	printf("\n\n");

	printf("Test Case 2: The transaction database is not empty\n");

	printf("Input Data: Sequence number is greater than 0 \n");
	printf("Sequence Number: ");
	scanf("%lu", &sequenceNumber);
	while ((getchar()) != '\n'); //clear the input buffer
	printf("Expected Result: Print the existing data\n");
	printf("Actual Result: ");
	printf("\n");
	listSavedTransactions();


}


EN_serverError_t saveTransaction(ST_transaction_t* transData)
{
	if (serverStatus == DISCONNECTED)
	{
		return SAVING_FAILED;
	}
	else
	{
		transData->transState = APPROVED;
		transData->transactionSequenceNumber = sequenceNumber;
		transactionDB[sequenceNumber] = (*transData);
		sequenceNumber += 1;
		listSavedTransactions();
		return SERVER_OK;
	}

}

void saveTransactionTest(void)
{
	ST_transaction_t transData;
	EN_serverError_t serverError;

	printf("Tester Name: Abd El-Rahman Kadah\n");
	printf("Function Name: saveTransactionTest\n\n");

	printf("Test Case 1: Server is disconnected\n");

	printf("Input Data: \n");
	printf("Transaction Date: ");
	gets(transData.terminalData.transactionDate);

	printf("Card Holder Name: ");
	gets(transData.cardHolderData.cardHolderName);

	printf("Primary Account Number: ");
	gets(transData.cardHolderData.primaryAccountNumber);

	printf("Card Expiration Date: ");
	gets(transData.cardHolderData.cardExpirationDate);

	printf("Transaction Amount: ");
	scanf("%f", &(transData.terminalData.transAmount));

	printf("Max Transaction Amount: ");
	scanf("%f", &(transData.terminalData.maxTransAmount));

	printf("Server Status: 0 (DISCONNECTED) or 1 (CONNECTED): ");
	scanf("%d", &serverStatus);
	while ((getchar()) != '\n'); //clear the input buffer

	serverError = saveTransaction(&transData);
	printf("Expected Result: SAVING_FAILED\n");
	printf("Actual Result: %s\n\n", (serverError ? "SAVING_FAILED" : "SERVER_OK"));

	printf("Test Case 2: Server is connected\n");

	printf("Input Data: \n");
	printf("Transaction Date: ");
	gets(transData.terminalData.transactionDate);

	printf("Card Holder Name: ");
	gets(transData.cardHolderData.cardHolderName);

	printf("Primary Account Number: ");
	gets(transData.cardHolderData.primaryAccountNumber);

	printf("Card Expiration Date: ");
	gets(transData.cardHolderData.cardExpirationDate);

	printf("Transaction Amount: ");
	scanf("%f", &(transData.terminalData.transAmount));

	printf("Max Transaction Amount: ");
	scanf("%f", &(transData.terminalData.maxTransAmount));

	printf("Server Status: 0 (DISCONNECTED) or 1 (CONNECTED): ");
	scanf("%d", &serverStatus);
	while ((getchar()) != '\n'); //clear the input buffer

	serverError = saveTransaction(&transData);
	printf("Expected Result: SERVER_OK\n");
	printf("Actual Result: %s\n\n", (serverError ? "SAVING_FAILED" : "SERVER_OK"));

}



EN_transState_t recieveTransactionData(ST_transaction_t* transData)
{
	ST_accountsDB_t accountReference;
	if (isValidAccount(&(transData->cardHolderData), &accountReference) == ACCOUNT_NOT_FOUND)
	{
		return FRAUD_CARD;
	}
	else if (isAmountAvailable(&(transData->terminalData), &accountReference) == LOW_BALANCE)
	{
		return DECLINED_INSUFFECIENT_FUND;
	}
	else if (isBlockedAccount(&accountReference) == BLOCKED_ACCOUNT)
	{
		return DECLINED_STOLEN_CARD;
	}
	else if(saveTransaction(transData) == SAVING_FAILED)
	{
		return INTERNAL_SERVER_ERROR;
	}
	else
	{
		(accountReference.balance) -= (transData->terminalData.transAmount);
		return APPROVED;
	}

}

void recieveTransactionDataTest(void)
{
	ST_transaction_t transData;
	EN_transState_t transError;

	printf("Tester Name: Abd El-Rahman Kadah\n");
	printf("Function Name: recieveTransactionDataTest\n\n");

	printf("Test Case 1: Account doesn't exist\n");

	printf("Input Data: \n");
	printf("Card Primary Account Number: ");
	gets(transData.cardHolderData.primaryAccountNumber);
	printf("Transaction Amount: ");
	scanf("%f", &(transData.terminalData.transAmount));
	while ((getchar()) != '\n'); //clear the input buffer
	transError = recieveTransactionData(&transData);
	printf("Expected Result: FRAUD_CARD\n");
	printf("Actual Result: %s\n\n", (transError? "FRAUD_CARD" : "SERVER_OK"));

	printf("Test Case 2: Account exits but trans amount exceeds the balance\n");

	printf("Input Data: \n");
	printf("Card Primary Account Number: ");
	gets(transData.cardHolderData.primaryAccountNumber);
	printf("Transaction Amount: ");
	scanf("%f", &(transData.terminalData.transAmount));
	while ((getchar()) != '\n'); //clear the input buffer
	transError = recieveTransactionData(&transData);
	printf("Expected Result: DECLINED_INSUFFECIENT_FUND\n");
	printf("Actual Result: %s\n\n", (transError ? "DECLINED_INSUFFECIENT_FUND" : "SERVER_OK"));

	printf("Test Case 3: Account exits but it is blocked\n");

	printf("Input Data: \n");
	printf("Card Primary Account Number: ");
	gets(transData.cardHolderData.primaryAccountNumber);
	printf("Transaction Amount: ");
	scanf("%f", &(transData.terminalData.transAmount));
	while ((getchar()) != '\n'); //clear the input buffer
	transError = recieveTransactionData(&transData);
	printf("Expected Result: DECLINED_STOLEN_CARD\n");
	printf("Actual Result: %s\n\n", (transError ? "DECLINED_STOLEN_CARD" : "SERVER_OK"));

	printf("Test Case 4: Account exits and is running and the trans amount is available\n");

	printf("Input Data: \n");
	printf("Card Primary Account Number: ");
	gets(transData.cardHolderData.primaryAccountNumber);
	printf("Transaction Amount: ");
	scanf("%f", &(transData.terminalData.transAmount));
	while ((getchar()) != '\n'); //clear the input buffer
	transError = recieveTransactionData(&transData);
	printf("Expected Result: APPROVED\n");
	printf("Actual Result: %s\n\n", (transError ? "DECLINED" : "APPROVED"));

}





