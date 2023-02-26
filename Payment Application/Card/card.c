#include "card.h"


EN_cardError_t getCardHolderName(ST_cardData_t* cardData)
{
	uint8_t temp[50];
	printf("Enter the card holder name (20 - 24 chars): ");
	gets(temp);

	uint8_t* digitsAndSymbols = "0123456789-_."; //Illegal characters
	if ((temp == NULL)
		|| (strlen(temp) < 20)
		|| (strlen(temp) > 24)
		|| (strpbrk(temp, digitsAndSymbols)))
		/*
		* strpbrk() function
		Syntax :
			char *strpbrk(const char *s1, const char *s2)

		Parameters :
			s1 : string to be scanned.
			s2 : string containing the characters to match.
		Return Value :
			It returns a pointer to the character in s1 that
			matches one of the characters in s2, else returns NULL.
		*/
	{
		return WRONG_NAME;
	}
	else
	{
		strcpy(cardData->cardHolderName, temp);
		return CARD_OK;

	}
}

void getCardHolderNameTest(void)
{
	//Variables to store the testing data
	ST_cardData_t cardData; 
	EN_cardError_t error;

	printf("Tester Name: Abd El-Rahman Kadah\n");
	printf("Function Name: getCardHolderName\n\n");

	printf("Test Case 1: No entry\n");
	printf("Input Data: ");
	error = getCardHolderName(&cardData);
	printf("Expected Result: WRONG_NAME\n");
	printf("Actual Result: %s\n\n", (error? "WRONG_NAME":"CARD_OK"));

	printf("Test Case 2: The card holder name is greater than 24 characters\n");
	printf("Input Data: ");
	error = getCardHolderName(&cardData);
	printf("Expected Result: WRONG_NAME\n");
	printf("Actual Result: %s\n\n", (error ? "WRONG_NAME" : "CARD_OK"));

	printf("Test Case 3: The card holder name is less than 20 characters\n");
	printf("Input Data: ");
	error = getCardHolderName(&cardData);
	printf("Expected Result: WRONG_NAME\n");
	printf("Actual Result: %s\n\n", (error ? "WRONG_NAME" : "CARD_OK"));

	printf("Test Case 4: The card holder name has digits or special symbols\n");
	printf("Input Data: ");
	error = getCardHolderName(&cardData);
	printf("Expected Result: WRONG_NAME\n");
	printf("Actual Result: %s\n\n", (error ? "WRONG_NAME" : "CARD_OK"));


	printf("Test Case 5: The card holder name is correct\n");
	printf("Input Data: ");
	error = getCardHolderName(&cardData);
	printf("Expected Result: CARD_OK\n");
	printf("Actual Result: %s\n\n", (error ? "WRONG_NAME" : "CARD_OK"));


}



EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData)
{
	uint8_t temp[50];
	printf("Enter the card expiry date (MM/YY): ");
	gets(temp);

	if ((temp == NULL)
		|| (strlen(temp) < 5)
		|| (strlen(temp) > 5)
		|| (temp[2] != '/'))
	{
		return WRONG_EXP_DATE;
	}
	else
	{
		strcpy(cardData->cardExpirationDate, temp);
		return CARD_OK;
	}
	

}

void getCardExpiryDateTest(void)
{
	ST_cardData_t cardData;
	EN_cardError_t error;

	printf("Tester Name: Abd El-Rahman Kadah\n");
	printf("Function Name: getCardExpiryDate\n\n");


	printf("Test Case 1: No entry\n");
	printf("Input Data: ");
	error = getCardExpiryDate(&cardData);
	printf("Expected Result: WRONG_EXP_DATE\n");
	printf("Actual Result: %s\n\n", (error? "WRONG_EXP_DATE":"CARD_OK"));

	printf("Test Case 2: The card expiry date is more than 5 characters\n");
	printf("Input Data: ");
	error = getCardExpiryDate(&cardData);
	printf("Expected Result: WRONG_EXP_DATE\n");
	printf("Actual Result: %s\n\n", (error? "WRONG_EXP_DATE":"CARD_OK"));

	printf("Test Case 3: The card expiry date is less than 5 characters\n");
	printf("Input Data: ");
	error = getCardExpiryDate(&cardData);
	printf("Expected Result: WRONG_EXP_DATE\n");
	printf("Actual Result: %s\n\n", (error ? "WRONG_EXP_DATE" : "CARD_OK"));

	printf("Test Case 4: the / is missing or misplaced\n");
	printf("Input Data: ");
	error = getCardExpiryDate(&cardData);
	printf("Expected Result: WRONG_EXP_DATE\n");
	printf("Actual Result: %s\n\n", (error? "WRONG_EXP_DATE":"CARD_OK"));
	
	printf("Test Case 5: The card expiry date is correct\n");
	printf("Input Data: ");
	error = getCardExpiryDate(&cardData);
	printf("Expected Result: CARD_OK\n");
	printf("Actual Result: %s\n\n", (error? "WRONG_EXP_DATE":"CARD_OK"));
}



EN_cardError_t getCardPAN(ST_cardData_t* cardData)
{
	uint8_t temp[50];
	printf("Enter the card primary account number (16 - 19 nums): ");
	gets(temp);
	
	if ((temp == NULL)
		|| (strlen(temp) < 16)
		|| (strlen(temp) > 19))
	{
		return WRONG_PAN;
	}
	else
	{
		strcpy(cardData->primaryAccountNumber, temp);
		return CARD_OK;

	}

}

void getCardPANTest(void)
{
	ST_cardData_t cardData;
	EN_cardError_t error;

	printf("Tester Name: Abd El-Rahman Kadah\n");
	printf("Function Name: getCardPAN\n\n");


	printf("Test Case 1: No entry\n");
	printf("Input Data: ");
	error = getCardPAN(&cardData);
	printf("Expected Result: WRONG_PAN\n");
	printf("Actual Result: %s\n\n", (error? "WRONG_PAN":"CARD_OK"));

	printf("Test Case 2: The card PAN is greater than 19 characters\n");
	printf("Input Data: ");
	error = getCardPAN(&cardData);
	printf("Expected Result: WRONG_PAN\n");
	printf("Actual Result: %s\n\n", (error? "WRONG_PAN":"CARD_OK"));

	printf("Test Case 3: The card PAN is less than 16 characters\n");
	printf("Input Data: ");
	error = getCardPAN(&cardData);
	printf("Expected Result: WRONG_PAN\n");
	printf("Actual Result: %s\n\n", (error? "WRONG_PAN":"CARD_OK"));

	printf("Test Case 4: The card PAN is correct\n");
	printf("Input Data: ");
	error = getCardPAN(&cardData);
	printf("Expected Result: CARD_OK\n");
	printf("Actual Result: %s\n\n", (error ? "WRONG_PAN" : "CARD_OK"));

}