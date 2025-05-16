/* transaction.h - Transaction processing interface
* Author: Nnaemeka Nwodo
* Date: 2025-05-14
*/

#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "card_reader.h"

#define MAX_REFERENCE_LENGTH 20
#define MAX_ERROR_MESSAGE_LENGTH 100

/**
 * struct TransactionResult - Represents the outcome of a transaction
 *
 * Description: This struct stores the result of a transaction processed
 * by the payment terminal simulator. It includes a success indicator,
 * a reference number for successful transactions, and an error message
 * for failed transactions.
 *
 * Fields:
 *   success: Integer indicating transaction success (1) or failure (0)
 *   reference: Character array for the transaction reference number
 *   error_message: Character array for the error message (if any)
*/
typedef struct
{
int success;
char reference[MAX_REFERENCE_LENGTH];
char error_message[MAX_ERROR_MESSAGE_LENGTH];
} TransactionResult;

TransactionResult process_transaction(const Card *card, double amount);

#endif /* TRANSACTION_H */
