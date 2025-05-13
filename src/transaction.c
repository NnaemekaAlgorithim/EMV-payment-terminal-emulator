#include <stdio.h>
#include <string.h>
#include <time.h>
#include "transaction.h"

TransactionResult process_transaction(Card card, double amount) {
    TransactionResult result;
    if (amount <= 0) {
        result.success = 0;
        strcpy(result.error_message, "Invalid transaction amount.");
        return result;
    }

    // Simulate success
    result.success = 1;
    snprintf(result.reference, sizeof(result.reference), "TXN%ld", time(NULL));

    // Log the transaction
    FILE *file = fopen("transactions.log", "a");
    fprintf(file, "Card: %s, Amount: %.2f, Reference: %s\n", card.pan, amount, result.reference);
    fclose(file);

    return result;
}
