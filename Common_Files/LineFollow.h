/*
 * LineFollow.h
 *
 *  Created on: 02.12.2015
 *      Author: Cornel
 */

#ifndef SOURCES_COMMON_FILES_LINEFOLLOW_H_
#define SOURCES_COMMON_FILES_LINEFOLLOW_H_


#include "Platform.h"
#if PL_CONFIG_HAS_LINE_FOLLOW

#if PL_CONFIG_HAS_SHELL
#include "CLS1.h"

uint8_t LF_ParseCommand(const unsigned char *cmd, bool *handled, const CLS1_StdIOType *io);
#endif

void LF_StartFollowing(void);
void LF_StopFollowing(void);
bool LF_IsFollowing(void);
static bool FollowSegment(void);

void LF_Init(void);
void LF_Deinit(void);

#endif /* PL_CONFIG_HAS_LINE_FOLLOW */




#endif /* SOURCES_COMMON_FILES_LINEFOLLOW_H_ */
