#include "fan.h"
#include "globalPinout.h"

#define FAN_ON_VAL 1
#define FAN_OFF_VAL 0

fanState_t s;

/*
 * Aggiorna lo stato della ventola in base alla corrente media
 */
void updateFanState (voltageV_t aC)
{
    if (aC > FAN_SWITCH_UPPER_VOLTAGE)
    {
        setFanState(FAN_ON);
    }
    else if (aC < FAN_SWITCH_LOWER_VOLTAGE)
    {
        setFanState(FAN_OFF);
    }
}

/*
 * Imposta lo stato della ventola
 */
void setFanState (fanState_t fS)
{
    s = fS;

    if (s == FAN_ON)
    {
        FANCON_LAT = FAN_ON_VAL;
    }
    else
    {
        FANCON_LAT = FAN_OFF_VAL;
    }
}

/*
 * Ritorna lo stato della ventola
 */
fanState_t getFanState ()
{
    return s;
}