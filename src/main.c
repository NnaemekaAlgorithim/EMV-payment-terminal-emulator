/* main.c - Main entry point for the EMV payment terminal simulator
* Author: Nnaemeka Nwodo
* Date: 2025-05-14
*/

#include <stdio.h>
#include "card_reader.h"
#include "emv_validation.h"
#include "transaction.h"

int main(void)
{
Card card;
printf("Welcome to the Payment Terminal Simulator\n");

if (!read_card(&card))
{
printf("Invalid card input. Exiting...\n");
return (1);
}

if (!validate_card(&card))
{
printf("Invalid card detected. Exiting...\n");
return (1);
}

if (!is_emv_compliant(&card))
{
printf("Card is not EMV compliant. Exiting...\n");
return (1);
}

printf("Card validated. Processing transaction...\n");
TransactionResult result = process_transaction(&card, 100.0);

if (result.success)
{
printf("Transaction successful! Reference: %s\n", result.reference);
}
else
{
printf("Transaction failed: %s\n", result.error_message);
}

return 0;
}
