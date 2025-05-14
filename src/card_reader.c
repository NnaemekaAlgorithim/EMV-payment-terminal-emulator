/*
* card_reader.c - Implementation of card reading and validation
* Author: Nnaemeka Nwodo
* Date: 2025-05-14
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "card_reader.h"


/**
* read_card - Reads card information from the user.
* @card: Pointer to a Card structure to store the card details.
*
* Reads the Primary Account Number (PAN) and expiry date from the user.
* Validates the inputs to ensure they are properly formatted.
*
* Return: 1 if the card is successfully read and validated, 0 otherwise.
*/
int read_card(Card *card)
{
printf("Enter card PAN (Primary Account Number): ");

if (fgets(card->pan, MAX_PAN_LENGTH, stdin) == NULL)
{
return (0);
}

card->pan[strcspn(card->pan, "\n")] = '\0'; /* Remove newline */

/* Validate PAN input */
for (int i = 0; card->pan[i]; i++)
{

if (!isdigit(card->pan[i]))
{
return (0);
}

}

printf("Enter expiry date (MMYY): ");

if (fgets(card->expiry_date, EXPIRY_LENGTH, stdin) == NULL)
{
return (0);
}

card->expiry_date[strcspn(card->expiry_date, "\n")] = '\0';

return (validate_expiry_date(card->expiry_date));
}


/**
* validate_expiry_date - Validates the card expiry date.
* @expiry: String representing the expiry date in MMYY format.
*
* Checks that the expiry date consists of exactly 4 digits and that
* the month (MM) is between 1 and 12.
*
* Return: 1 if the expiry date is valid, 0 otherwise.
*/
int validate_expiry_date(const char *expiry)
{

if (strlen(expiry) != 4)
{
return (0);
}

for (int i = 0; i < 4; i++)
{

if (!isdigit(expiry[i]))
{
return (0);
}

}

int month = (expiry[0] - '0') * 10 + (expiry[1] - '0');
return (month >= 1 && month <= 12);
}


/**
* validate_card - Validates a card using the Luhn algorithm.
* @card: Pointer to a Card structure containing the card details.
*
* Uses the Luhn algorithm to validate the card's Primary Account Number (PAN).
*
* Return: 1 if the card is valid, 0 otherwise.
*/
int validate_card(const Card *card)
{

/* Simple Luhn Algorithm for PAN validation */
int sum = 0;
int alternate = 0;
int len = strlen(card->pan);

for (int i = len - 1; i >= 0; i--)
{
int digit = card->pan[i] - '0';

if (alternate)
{
digit *= 2;
sum += (digit > 9) ? (digit - 9) : digit;
}
else
{
sum += digit;
}

alternate = !alternate;
}

return (sum % 10 == 0);
}
