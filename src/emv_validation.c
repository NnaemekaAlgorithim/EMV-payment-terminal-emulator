/* emv_validation.c - Implementation of EMV compliance checking
* Author: Nnaemeka Nwodo
* Date: 2025-05-14
*/

#include <string.h>
#include "emv_validation.h"

int is_emv_compliant(const Card *card)
{
/* Check for VISA (starts with 4) or MasterCard (starts with 5) */
if (card->pan[0] == '4' || card->pan[0] == '5')
{
return (1);
}
return 0;
}
