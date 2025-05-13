#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "card_reader.h"

typedef struct {
    int success;
    char reference[20];
    char error_message[100];
} TransactionResult;

TransactionResult process_transaction(Card card, double amount);

#endif
