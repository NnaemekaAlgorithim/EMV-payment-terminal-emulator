#include <stdio.h>
#include "card_reader.h"
#include "transaction.h"
#include "emv_validation.h"

int main() {
    printf("Welcome to the Payment Terminal Simulator\n");

    Card card = read_card();
    if (!validate_card(card)) {
        printf("Invalid card detected. Exiting...\n");
        return 1;
    }

    printf("Card validated. Processing transaction...\n");
    TransactionResult result = process_transaction(card, 100.0); // Simulate $100 transaction

    if (result.success) {
        printf("Transaction successful! Reference: %s\n", result.reference);
    } else {
        printf("Transaction failed: %s\n", result.error_message);
    }

    return 0;
}
