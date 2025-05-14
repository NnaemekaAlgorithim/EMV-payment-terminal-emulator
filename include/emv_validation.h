/* emv_validation.h - EMV compliance checking interface
* Author: Nnaemeka Nwodo
* Date: 2025-05-14
*/

#ifndef EMV_VALIDATION_H
#define EMV_VALIDATION_H

#include "card_reader.h"

int is_emv_compliant(const Card *card);

#endif /* EMV_VALIDATION_H */
