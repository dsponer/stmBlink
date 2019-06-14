#ifndef __medianFilter_H
#define __medianFilter_H
#ifdef __cplusplus
 extern "C" {
#endif

#include "main.h"

int compare(const void *a, const void *b);
float readMedian(ADC_HandleTypeDef pin, int samples);

#ifdef __cplusplus
}
#endif
#endif