// ============================================================================
// ffx_types.h — FFX Shared Types and Macros
// Phase 3-E: FFX Game Stubs
// ============================================================================

#ifndef FFX_TYPES_H
#define FFX_TYPES_H

// Platform includes
#include <stddef.h>
#include <stdint.h>

// Debug/Stub macro — prints function name when called in debug builds
#ifdef _DEBUG
    #include <stdio.h>
    #define STUBBED(name) do { \
        printf("[STUB] %s called (0x" #name ")\n", name); \
    } while(0)
#else
    #define STUBBED(name) ((void)0)
#endif

// FFX basic integer types
typedef int32_t FFX_BOOL;
typedef int32_t FFX_RESULT;

// Common FFX result codes
#define FFX_OK            0
#define FFX_FAIL         -1
#define FFX_TRUE          1
#define FFX_FALSE         0

// Battle HUD gauge types
typedef enum {
    GAUGE_TYPE_HP = 0,
    GAUGE_TYPE_MP = 1,
    GAUGE_TYPE_OVERDRIVE = 2,
    GAUGE_TYPE_STATUS = 3,
    GAUGE_TYPE_CTB = 4,
} FFX_GaugeType;

// Encounter trigger types
typedef enum {
    ENCOUNTER_TRIGGER_DISTANCE = 0,
    ENCOUNTER_TRIGGER_TOUCH = 1,
    ENCOUNTER_TRIGGER_EVENT = 2,
    ENCOUNTER_TRIGGER_SCRIPT = 3,
} FFX_EncounterTriggerType;

// Field map states
typedef enum {
    FIELD_STATE_INACTIVE = 0,
    FIELD_STATE_LOADING = 1,
    FIELD_STATE_ACTIVE = 2,
    FIELD_STATE_TRANSITION = 3,
} FFX_FieldState;

// Menu event types
typedef enum {
    MENU_EVENT_SELECT = 0,
    MENU_EVENT_CONFIRM = 1,
    MENU_EVENT_CANCEL = 2,
    MENU_EVENT_NAVIGATE = 3,
    MENU_EVENT_POPUP = 4,
} FFX_MenuEvent;

#endif // FFX_TYPES_H
