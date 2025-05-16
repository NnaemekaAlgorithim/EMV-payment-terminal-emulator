/*
* emv_validation.c - Implementation of EMV compliance checking
* Author: Nnaemeka Nwodo
* Date: 2025-05-14
*/

#include <string.h>
#include "emv_validation.h"

/**
 * is_emv_compliant - Checks if a card is EMV compliant
 *
 * Description: This function determines if a card is EMV compliant by
 * checking the first digit of the card's Primary Account Number (PAN).
 * It returns true if the PAN starts with '4' (VISA) or '5' (MasterCard),
 * indicating EMV compliance, and false otherwise.
 *
 * @param card: Pointer to a Card struct containing the card details
 *
 * Return: 1 if the card is EMV compliant, 0 otherwise
 */
int is_emv_compliant(const Card *card)
{
/* Check for VISA (starts with 4) or MasterCard (starts with 5) */
if (card->pan[0] == '4' || card->pan[0] == '5')
{
return (1);
}
return (0);
}
