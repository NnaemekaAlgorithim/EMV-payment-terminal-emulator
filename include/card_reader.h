#ifndef CARD_READER_H
#define CARD_READER_H

typedef struct {
    char pan[20];
    char expiry_date[5];
} Card;

Card read_card();
int validate_card(Card card);

#endif
