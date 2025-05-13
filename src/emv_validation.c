#include <string.h>
#include "../include/emv_validation.h"

int is_emv_compliant(Card card) {
    // Basic EMV compliance check (VISA/MasterCard BINs)
    if (strncmp(card.pan, "4", 1) == 0 || strncmp(card.pan, "5", 1) == 0) {
        return 1; // VISA or MasterCard
    }
    return 0;
}
