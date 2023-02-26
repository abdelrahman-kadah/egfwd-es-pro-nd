#include "app.h"


void appStart(void)
{
	ST_transaction_t transData;

	if (getCardHolderName(&(transData.cardHolderData)) == WRONG_NAME)
	{
		printf("Wrong Card Name");
		return;
	}

	if (getCardExpiryDate(&(transData.cardHolderData)) == WRONG_EXP_DATE)
	{
		printf("Wrong Expiry Date ");
		return;
	}

	if (getCardPAN(&(transData.cardHolderData)) == WRONG_PAN)
	{
		printf("Wrong PAN");
		return;
	}

	if (getTransactionDate(&(transData.terminalData)) == WRONG_DATE)
	{
		printf("Wrong Date");
		return;
	}

	if (isCardExpired(&(transData.cardHolderData), &(transData.terminalData)) == EXPIRED_CARD)
	{
		printf("Declined\nExpired Card");
		return;
	}

	if (setMaxAmount(&(transData.terminalData), 10000.0) == INVALID_MAX_AMOUNT)
	{
		printf("Invalid Max Amount");
		return;
	}

	if (getTransactionAmount(&(transData.terminalData)) == INVALID_AMOUNT)
	{
		printf("Invalid Amount");
		return;
	}

	if (isBelowMaxAmount(&(transData.terminalData)) == EXCEED_MAX_AMOUNT)
	{
		printf("Declined\nExceeding Limit");
		return;
	}


	switch (recieveTransactionData(&transData))
	{
	case FRAUD_CARD:
		printf("Declined\nInvalid Account");
		return;
	case DECLINED_INSUFFECIENT_FUND:
		printf("Declined\nInsuffecient Fund");
		return;
	case DECLINED_STOLEN_CARD:
		printf("Declined\nStolen Card");
		return;
	case APPROVED:
		return;

	}

}