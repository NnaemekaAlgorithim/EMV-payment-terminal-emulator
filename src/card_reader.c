#include <stdio.h>
#include <string.h>
#include "../include/card_reader.h"

Card read_card() {
    Card card;
    printf("Enter card PAN (Primary Account Number): ");
    scanf("%19s", card.pan);
    printf("Enter expiry date (MMYY): ");
    scanf("%4s", card.expiry_date);

    return card;
}

int validate_card(Card card) {
    // Simple Luhn Algorithm for PAN validation
    int sum = 0, alternate = 0;
    for (int i = strlen(card.pan) - 1; i >= 0; i--) {
        int digit = card.pan[i] - '0';
        if (alternate) digit *= 2;
        sum += (digit > 9) ? (digit - 9) : digit;
        alternate = !alternate;
    }
    return (sum % 10 == 0);
}
