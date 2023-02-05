/*
 * EXINT_config.c
 *
 *  Created on: Feb 24, 2022
 *      Author: amrmo
 */
#include "../../LIB/std_types.h"
#include "../../LIB/ErrorStates.h"

#include "EXINT_config.h"
#include "EXINT_int.h"


EXINT_t EXINT_AstrExINTConfig[EXINT_NUM] = {
		{EXINTuint8_INT0, EXINTuint8_ENABLED, EXINTuint8_LOW_LEVEL},
};
