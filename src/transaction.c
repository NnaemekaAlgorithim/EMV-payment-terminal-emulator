/* transaction.c - Implementation of transaction processing
* Author: Nnaemeka Nwodo
* Date: 2025-05-14
*/

#include <stdio.h>
#include <string.h>
#include <time.h>
#include "transaction.h"

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
