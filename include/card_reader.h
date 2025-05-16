/**
* card_reader.h - Card reading and validation interface
* Author: Nnaemeka Nwodo
* Date: 2025-05-14
*/

#ifndef CARD_READER_H
#define CARD_READER_H

#define MAX_PAN_LENGTH 20
#define EXPIRY_LENGTH 5

/**
 * struct Card - Represents a payment card
 *
 * Description: This struct stores details of a payment card used in the
 * payment terminal simulator. It contains the card's Primary Account Number
 * (PAN) and expiry date, used for validation and transaction processing.
 *
 * Fields:
 *   pan: Character array storing the card's PAN (up to MAX_PAN_LENGTH)
 *   expiry_date: Character array storing the expiry date (MMYY format)
 */
typedef struct
{
char pan[MAX_PAN_LENGTH];
char expiry_date[EXPIRY_LENGTH];
} Card;

int read_card(Card *card);
int validate_card(const Card *card);
int validate_expiry_date(const char *expiry);

#endif /* CARD_READER_H */
