#ifndef FFX_FMV_PLAYER_H
#define FFX_FMV_PLAYER_H

#include <stdint.h>

int FFX_FMV_Init(void);
int FFX_FMV_Load(const char *webmPath);
int FFX_FMV_NextFrame(void);
void *FFX_FMV_GetFrameSRV(void);
int FFX_FMV_GetWidth(void);
int FFX_FMV_GetHeight(void);
void FFX_FMV_Shutdown(void);

#endif
