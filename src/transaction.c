/*
transaction.c - Implementation of transaction processing
* Author: Nnaemeka Nwodo
* Date: 2025-05-14
*/

#include <stdio.h>
#include <string.h>
#include <time.h>
#include "transaction.h"

/**
 * log_transaction - Logs a transaction to a file
 *
 * Description: This function logs details of a transaction to a file named
 * "transactions.log". The log includes the timestamp, card's Primary Account
 * Number (PAN), transaction amount, reference number, success status, and
 * any error message. If the file cannot be opened, the function silently
 * returns without logging.
 *
 * @param card: Pointer to a Card struct containing card details
 * @param amount: Transaction amount
 * @param result: Pointer to a TransactionResult struct with transaction outcome
 */
static void log_transaction(const Card *card, double amount,
const TransactionResult *result)
{
FILE *file = fopen("transactions.log", "a");
if (file == NULL)
{
return;
}

time_t now = time(NULL);
char *timestamp = ctime(&now);
timestamp[strcspn(timestamp, "\n")] = '\0'; /* Remove newline */

fprintf(file, "[%s] Card: %s, Amount: %.2f, Ref: %s, Success: %d, Error: %s\n",
timestamp, card->pan, amount, result->reference,
result->success, result->error_message);
fclose(file);
}

/**
 * process_transaction - Processes a card transaction
 *
 * Description: This function simulates processing a transaction for a given
 * card and amount. It checks if the amount is valid (greater than zero). If
 * invalid, it logs and returns a failed result with an error message. If valid,
 * it simulates a successful transaction, generates a reference number based on
 * the current timestamp, logs the transaction, and returns the result.
 *
 * @param card: Pointer to a Card struct containing card details
 * @param amount: Transaction amount
 *
 * Return: TransactionResult struct indicating success or failure
 */
TransactionResult process_transaction(const Card *card, double amount)
{
TransactionResult result = {0};

if (amount <= 0)
{
result.success = 0;
strncpy(result.error_message, "Invalid transaction amount.",
MAX_ERROR_MESSAGE_LENGTH - 1);
log_transaction(card, amount, &result);
return (result);
}

/* Simulate transaction success */
result.success = 1;
snprintf(result.reference, MAX_REFERENCE_LENGTH, "TXN%ld", time(NULL));

log_transaction(card, amount, &result);
return (result);
}
