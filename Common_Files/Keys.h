/*
 * Keys.h
 *
 *  Created on: 15.10.2015
 *      Author: Mario
 */

#ifndef SOURCES_COMMON_FILES_KEYS_H_
#define SOURCES_COMMON_FILES_KEYS_H_
#include "Platform.h"

#if PL_CONFIG_HAS_KEYS
typedef enum{
#if PL_CONFIG_NOF_KEYS >= 1
#error
  KEY_BUTTON1,
#endif
#if PL_CONFIG_NOF_KEYS >= 2
  KEY_BUTTON2,
#endif
} KEY_Buttons ;
#endif

#define


#endif /* SOURCES_COMMON_FILES_KEYS_H_ */
