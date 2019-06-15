#include "medianFilter.h"
#include "adc.h"
#include "stdio.h"
#include "stdlib.h"

int compare(const void *a, const void *b){
    return (*(float*)b - *(float*)a);
}

float readMedian(ADC_HandleTypeDef pin, int samples){
    float raw[samples];
    for (int i = 0; i < samples; i++)
    {
        HAL_ADC_Start(&pin);
        HAL_ADC_PollForConversion(&pin, 100);
        raw[i] = ((float)HAL_ADC_GetValue(&pin)*3.3/4096);
        HAL_ADC_Stop(&pin);
    }
    qsort(raw, samples, sizeof(float), compare);
    return raw[samples/2];
}