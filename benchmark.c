#include <stdio.h>
#include <windows.h>
#include <profileapi.h>
#include "benchmark.h"

double PCFreq = 0.0;
__int64 CounterStart = 0;

void start_counter(void) {
    LARGE_INTEGER li;
    if(!QueryPerformanceFrequency(&li))
        printf_s("QueryPerformanceFrequency failed!\n");
    PCFreq = li.QuadPart / 1000.0;
    QueryPerformanceCounter(&li);
    CounterStart = li.QuadPart;
}

double get_counter(void) {
    LARGE_INTEGER li;
    QueryPerformanceCounter(&li);
    return (li.QuadPart - (double)CounterStart) / PCFreq;
}
