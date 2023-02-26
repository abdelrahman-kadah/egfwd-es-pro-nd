#include "terminal.h"

EN_terminalError_t getTransactionDate(ST_terminalData_t *termData)
{
	uint8_t temp[50];
	printf("Enter the transaction date (DD/MM/YYYY): ");
	gets(temp);

	uint8_t* characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	if((temp == NULL)
		|| (strlen(temp) < 10)
		|| (temp[2] != '/')
		|| (temp[5] != '/')
		|| (strpbrk(temp, characters) != NULL))
	{
			return WRONG_DATE;
	}
	else
	{
		strcpy(termData->transactionDate, temp);
		return TERMINAL_OK;

	}
}

void getTransactionDateTest(void)
{
	ST_terminalData_t termData;
	EN_terminalError_t termError;

	printf("Tester Name: Abd El-Rahman Kadah\n");
	printf("Function Name: getTransactionDateTest\n\n");

	printf("Test Case 1: No Entry\n");
	printf("Input Data: ");
	termError = getTransactionDate(&termData);
	printf("Expected Result: WRONG_DATE\n");
	printf("Actual Result: %s\n\n", (termError? "WRONG_DATE":"TERMINAL_OK"));

	printf("Test Case 2: The transaction date is less than 10 characters\n");
	printf("Input Data: ");
	termError = getTransactionDate(&termData);
	printf("Expected Result: WRONG_DATE\n");
	printf("Actual Result: %s\n\n", (termError? "WRONG_DATE":"TERMINAL_OK"));

	printf("Test Case 3: The first / is missed or misplaced\n");
	printf("Input Data: ");
	termError = getTransactionDate(&termData);
	printf("Expected Result: WRONG_DATE\n");
	printf("Actual Result: %s\n\n", (termError? "WRONG_DATE":"TERMINAL_OK"));

	printf("Test Case 4: The second / is missed or misplaced\n");
	printf("Input Data: ");
	termError = getTransactionDate(&termData);
	printf("Expected Result: WRONG_DATE\n");
	printf("Actual Result: %s\n\n", (termError? "WRONG_DATE":"TERMINAL_OK"));

	printf("Test Case 5: The transaction date has alphapetical characters\n");
	printf("Input Data: ");
	termError = getTransactionDate(&termData);
	printf("Expected Result: WRONG_DATE\n");
	printf("Actual Result: %s\n\n", (termError? "WRONG_DATE":"TERMINAL_OK"));

	printf("Test Case 6: The transaction date is correct\n");
	printf("Input Data: ");
	termError = getTransactionDate(&termData);
	printf("Expected Result: TERMINAL_OK\n");
	printf("Actual Result: %s\n\n", (termError? "WRONG_DATE":"TERMINAL_OK"));

}



EN_terminalError_t isCardExpired(ST_cardData_t *cardData, ST_terminalData_t *termData)
{
	uint8_t cardMonth[3];
	uint8_t cardYear[3];
	uint8_t transMonth[3];
	uint8_t transYear[3];

	for (uint8_t i = 0; i < 3; i++)
	{
		cardMonth[i] = cardData->cardExpirationDate[i];
		cardYear[i] = cardData->cardExpirationDate[i + 3];
		transMonth[i] = termData->transactionDate[i + 3];
		transYear[i] = termData->transactionDate[i + 8];
	}

	if (strcmp(cardYear, transYear) == 1) //The card expiry date is larget than the trans year
	{
		return TERMINAL_OK;
	}
	else if (strcmp(cardYear, transYear) == 0) //The transaction year equals the card exipty year
	{
		//The card expiry month is greater than or equal to the trans month
		if ((strcmp(cardMonth, transMonth) == 1) || (strcmp(cardMonth, transMonth) == 0)) 
		{
			return TERMINAL_OK;
		}
		else
		{
			//the card expiry month is less than the trans month
			return EXPIRED_CARD;
		}

	}
	else
	{
		return EXPIRED_CARD;
	}
}

void isCardExpiredTest(void)
{
	ST_cardData_t cardData;
	ST_terminalData_t termData;
	EN_terminalError_t termError;

	printf("Tester Name: Abd El-Rahman Kadah\n");
	printf("Function Name: isCardExpiredTest\n\n");


	//Test Case 1: card expired due to year
	printf("Test Case 1: Card is expired due to year\n");
	printf("Input Data: \n");

	printf("Card Expiry Date (MM/YY): ");
	gets(cardData.cardExpirationDate);
	printf("Transaction Date (DD/MM/YYYY): ");
	gets(termData.transactionDate);

	termError = isCardExpired(&cardData, &termData);
	printf("Expected Result: EXPIRED_CARD\n");
	printf("Actual Result: %s\n\n", (termError ? "EXPIRED_CARD" : "TERMINAL_OK"));

	//Test Case 2: card expired due to month 
	printf("Test Case 2: Card is expired due to month \n");
	printf("Input Data: \n");

	printf("Card Expiry Date (MM/YY): ");
	gets(cardData.cardExpirationDate);
	printf("Transaction Date (DD/MM/YYYY): ");
	gets(termData.transactionDate);

	termError = isCardExpired(&cardData, &termData);
	printf("Expected Result: EXPIRED_CARD\n");
	printf("Actual Result: %s\n\n", (termError ? "EXPIRED_CARD" : "TERMINAL_OK"));

	//Test Case 3: card is not expired
	printf("Test Case 3: Card is not expired\n");
	printf("Input Data: \n");

	printf("Card Expiry Date (MM/YY): ");
	gets(cardData.cardExpirationDate);
	printf("Transaction Date (DD/MM/YYYY): ");
	gets(termData.transactionDate);

	termError = isCardExpired(&cardData, &termData);
	printf("Expected Result: TERMINAL_OK\n");
	printf("Actual Result: %s\n\n", (termError ? "EXPIRED_CARD" : "TERMINAL_OK"));

}



EN_terminalError_t getTransactionAmount(ST_terminalData_t* termData)
{
	float temp;
	printf("Enter the transaction amount (Max: 10000$): ");
	scanf("%f", &temp);

	if (temp <= 0)
	{
		return INVALID_AMOUNT;
	}
	else
	{
		termData->transAmount = temp;
		return TERMINAL_OK;
	}
}

void getTransactionAmountTest(void)
{
	ST_terminalData_t termData;
	EN_terminalError_t termError;

	printf("Tester Name: Abd El-Rahman Kadah\n");
	printf("Function Name: getTransactionAmountTest\n\n");

	printf("Test Case 1: Transaction amount is zero\n");
	printf("Input Data: ");
	termError = getTransactionAmount(&termData);
	printf("Expected Result: INVALID_AMOUNT\n");
	printf("Actual Result: %s\n\n", (termError ? "INVALID_AMOUNT" : "TERMINAL_OK"));

	printf("Test Case 2: Transaction amount is less than zero\n");
	printf("Input Data: ");
	termError = getTransactionAmount(&termData);
	printf("Expected Result: INVALID_AMOUNT\n");
	printf("Actual Result: %s\n\n", (termError ? "INVALID_AMOUNT" : "TERMINAL_OK"));

	printf("Test Case 3: Transaction amount is valid (greater than 0)\n");
	printf("Input Data: ");
	termError = getTransactionAmount(&termData);
	printf("Expected Result: TERMINAL_OK\n");
	printf("Actual Result: %s\n\n", (termError ? "INVALID_AMOUNT" : "TERMINAL_OK"));
}



EN_terminalError_t setMaxAmount(ST_terminalData_t* termData, float maxAmount)
{

	if (maxAmount <= 0)
	{
		return INVALID_MAX_AMOUNT;
	}
	else
	{
		termData->maxTransAmount = maxAmount;
		return TERMINAL_OK;
	}
}

void setMaxAmountTest(void)
{
	ST_terminalData_t termData;
	float maxAmount;
	EN_terminalError_t termError;

	printf("Tester Name: Abd El-Rahman Kadah\n");
	printf("Function Name: setMaxAmountTest\n\n");

	printf("Test Case 1: maximum amount is zero\n");
	printf("Input Data: Enter the Maximum Amount: ");
	scanf("%f", &maxAmount);
	termError = setMaxAmount(&termData, maxAmount);
	printf("Expected Result: INVALID_MAX_AMOUNT\n");
	printf("Actual Result: %s\n\n", (termError ? "INVALID_MAX_AMOUNT" : "TERMINAL_OK"));

	printf("Test Case 2: maximum amount is less than zero\n");
	printf("Input Data: Enter the Maximum Amount: ");
	scanf("%f", &maxAmount);
	termError = setMaxAmount(&termData, maxAmount);
	printf("Expected Result: INVALID_MAX_AMOUNT\n");
	printf("Actual Result: %s\n\n", (termError ? "INVALID_MAX_AMOUNT" : "TERMINAL_OK"));

	printf("Test Case 3: maximum amount is valid (greater than 0)\n");
	printf("Input Data: Enter the Maximum Amount: ");
	scanf("%f", &maxAmount);
	termError = setMaxAmount(&termData, maxAmount);
	printf("Expected Result: TERMINAL_OK\n");
	printf("Actual Result: %s\n\n", (termError ? "INVALID_MAX_AMOUNT" : "TERMINAL_OK"));

	
}



EN_terminalError_t isBelowMaxAmount(ST_terminalData_t* termData)
{
	if (termData->transAmount > termData->maxTransAmount)
	{
		return EXCEED_MAX_AMOUNT;

	}
	else
	{
		return TERMINAL_OK;
	}
}

void isBelowMaxAmountTest(void)
{
	ST_terminalData_t termData;
	EN_terminalError_t termError;

	printf("Tester Name: Abd El-Rahman Kadah\n");
	printf("Function Name: isBelowMaxAmountTest\n\n");

	printf("Test Case 1: transaction amount is larger than maximum amount\n");
	printf("Input Data: \n");

	printf("Maximum amount: ");
	scanf("%f", &(termData.maxTransAmount));

	printf("Transaction amomunt: ");
	scanf("%f", &(termData.transAmount));

	termError = isBelowMaxAmount(&termData);
	printf("Expected Result: EXCEED_MAX_AMOUNT\n");
	printf("Actual Result: %s\n\n", (termError ? "EXCEED_MAX_AMOUNT" : "TERMINAL_OK"));

	printf("Test Case 2: transaction amount is less than maximum amount\n");
	printf("Input Data: \n");

	printf("Maximum amount: ");
	scanf("%f", &(termData.maxTransAmount));

	printf("Transaction amomunt: ");
	scanf("%f", &(termData.transAmount));

	termError = isBelowMaxAmount(&termData);
	printf("Expected Result: TERMINAL_OK\n");
	printf("Actual Result: %s\n\n", (termError ? "EXCEED_MAX_AMOUNT" : "TERMINAL_OK"));
}