#include "globalSettings.h"
#include <stdlib.h>

#include "flashWriting.h"

#include "pwms.h"
#include "pwmStabilityTest.h"
#include "battery.h"
#include "network.h"


const settingID_t PWM1_ENABLED_SID = 0;
const settingID_t PWM2_ENABLED_SID = 1;
const settingID_t PWM3_ENABLED_SID = 2;
const settingID_t PWM4_ENABLED_SID = 3;
const settingID_t PWM_PERIOD_SID = 4;
const settingID_t PWM1_STEP_SID = 5;
const settingID_t PWM2_STEP_SID = 6;
const settingID_t PWM3_STEP_SID = 7;
const settingID_t PWM4_STEP_SID = 8;
const settingID_t PWM_AUTO_STEP_ADJUST_SID = 9;
const settingID_t STABILITY_TEST_PWMID_SID = 10;
const settingID_t STABILITY_TEST_DUTY_SID = 11;
const settingID_t STABILITY_TEST_STATE_SID = 12;
const settingID_t BATT_CHARGED_UPP_SID = 13;
const settingID_t BATT_CHARGED_LOW_SID = 14;
const settingID_t NET_SWITCH_UPP_SID = 15;
const settingID_t NET_SWITCH_LOW_SID = 16;
const settingID_t ADC_BATT_UPP_SID = 17;
const settingID_t NET_SWITCH_TIME_SPAN_S_SID = 18;

typedef struct
{
    settingName_t name;
    settingType_t t;

    void *value;

    settingChangeClbk_t clbk;
}settingData_t;

settingData_t settings[] = {
                                {"PWM1_ENABLED", BOOL_T, NULL, &pwmSettingsChange},
                                {"PWM2_ENABLED", BOOL_T, NULL, &pwmSettingsChange},
                                {"PWM3_ENABLED", BOOL_T, NULL, &pwmSettingsChange},
                                {"PWM4_ENABLED", BOOL_T, NULL, &pwmSettingsChange},
                                {"PWM_PERIOD", DOUBLE_T, NULL, &pwmSettingsChange},
                                {"PWM1_STEP", DOUBLE_T, NULL, &pwmSettingsChange},
                                {"PWM2_STEP", DOUBLE_T, NULL, &pwmSettingsChange},
                                {"PWM3_STEP", DOUBLE_T, NULL, &pwmSettingsChange},
                                {"PWM4_STEP", DOUBLE_T, NULL, &pwmSettingsChange},
                                {"PWM_AUTO_STEP_ADJUST", BOOL_T, NULL, &pwmSettingsChange},
                                {"STABILITY_TEST_PWMID", INT_T, NULL, &settingChangeStabilityTest},
                                {"STABILITY_TEST_DUTY", DOUBLE_T, NULL, &settingChangeStabilityTest},
                                {"STABILITY_TEST_STATE", BOOL_T, NULL, &settingChangeStabilityTest},
                                {"BATT_CHARGED_UPP", DOUBLE_T, NULL, &batterySettingsChange},
                                {"BATT_CHARGED_LOW", DOUBLE_T, NULL, &batterySettingsChange},
                                {"NET_SWITCH_UPP", DOUBLE_T, NULL, &networkSettingsChange},
                                {"NET_SWITCH_LOW", DOUBLE_T, NULL, &networkSettingsChange},
                                {"ADC_BATT_UPP_SID", DOUBLE_T, NULL, NULL},
                                {"NET_SWITCH_TIME_SPAN_S", DOUBLE_T, NULL, &networkSettingsChange}
};

int sNum = sizeof(settings)/sizeof(settingData_t);

static const int sizes [] = {sizeof(double), sizeof(int), sizeof(long int), sizeof(settingName_t), sizeof(bool_t)};



/*
 * Inizializza le impostazioni
 */
void initSettings ()
{
    bool_t val;
    double valD;
    int valI;
    int i, init = 0;
    
    for (i = 0; i < sNum; i++)
    {
        settings[i].value = malloc(sizes[settings[i].t]);
    }

    loadFromFlash();

    getData(0, sizeof(int), &init);

    if (init == 0)
    {
        val = TRUE_B;
        setSetting (PWM1_ENABLED_SID, &val);

        val = FALSE_B;
        setSetting (PWM2_ENABLED_SID, &val);

        val = TRUE_B;
        setSetting (PWM3_ENABLED_SID, &val);

        val = FALSE_B;
        setSetting (PWM4_ENABLED_SID, &val);

        valD = 25.0;
        setSetting(PWM_PERIOD_SID, &valD);

        valD = 4.0;
        setSetting(PWM1_STEP_SID, &valD);

        valD = 4.0;
        setSetting(PWM2_STEP_SID, &valD);

        valD = 4.0;
        setSetting(PWM3_STEP_SID, &valD);

        valD = 4.0;
        setSetting(PWM4_STEP_SID, &valD);

        val = TRUE_B;
        setSetting (PWM_AUTO_STEP_ADJUST_SID, &val);

        valI = PWM1_ID;
        setSetting (STABILITY_TEST_PWMID_SID, &valI);

        valD = 50.0;
        setSetting (STABILITY_TEST_DUTY_SID, &valD);

        val = FALSE_B;
        setSetting (STABILITY_TEST_STATE_SID, &val);

        valD = 56;
        setSetting (BATT_CHARGED_UPP_SID, &valD);

        valD = 55;
        setSetting (BATT_CHARGED_LOW_SID, &valD);

        valD = 47;
        setSetting (NET_SWITCH_UPP_SID, &valD);

        valD = 41;
        setSetting (NET_SWITCH_LOW_SID, &valD);

        valD = 62.66;
        setSetting (ADC_BATT_UPP_SID, &valD);

        valD = 20.0;
        setSetting(NET_SWITCH_TIME_SPAN_S_SID, &valD);

        init = 1;
        
        setData(0, sizeof(int), &init);
        
        saveSettingsToFlash();
    }
    else
    {
        loadSettingsFromFlash();

        init = 3;

        setData(0, sizeof(int), &init);
    }

}

/*
 * Modifica il valore di un'impostazione
 */
void setSetting (settingID_t sid, const void *v)
{
    memcpy (settings[sid].value, v, sizes[settings[sid].t]);

    if (settings[sid].clbk != NULL)
        settings[sid].clbk(sid, settings[sid].value);
}

/*
 * Ritorna il valore di un'impostazione
 */
void *getSetting (settingID_t sid)
{
    return settings[sid].value;
}

/*
 * Salva le impostazioni sulla memoria flash
 */
void saveSettingsToFlash ()
{
    unsigned int offset = 2;
    int i;

    for (i = 0; i < sNum; i++)
    {
        setData(offset, sizes[settings[i].t], settings[i].value);
        offset += sizes[settings[i].t];
    }

    saveToFlash();
}

/*
 * Carica le impostazioni dalla memoria flash
 */
void loadSettingsFromFlash ()
{
    unsigned int offset = 2;
    int i;

    loadFromFlash();

    for (i = 0; i < sNum; i++)
    {
        getData(offset, sizes[settings[i].t], settings[i].value);
        setSetting(i, settings[i].value);
        offset += sizes[settings[i].t];
    }
}