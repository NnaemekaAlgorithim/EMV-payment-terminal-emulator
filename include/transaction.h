/* transaction.h - Transaction processing interface
* Author: Nnaemeka Nwodo
* Date: 2025-05-14
*/

#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "card_reader.h"

#define MAX_REFERENCE_LENGTH 20
#define MAX_ERROR_MESSAGE_LENGTH 100

typedef struct
{
int success;
char reference[MAX_REFERENCE_LENGTH];
char error_message[MAX_ERROR_MESSAGE_LENGTH];
} TransactionResult;

TransactionResult process_transaction(const Card *card, double amount);

#endif /* TRANSACTION_H */
