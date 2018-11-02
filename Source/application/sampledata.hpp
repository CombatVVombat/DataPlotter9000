#ifndef SAMPLEDATA_HPP_INCLUDED
#define SAMPLEDATA_HPP_INCLUDED

#include <ctime>
#include <iostream>
#include <math.h>
#include <random>
#include <stdint.h>
#include <vector>

class cSampleData
{
public:
    cSampleData();
    void generateRandomDataPoint(int32_t min, int32_t max);
    void generateSinDataPoint(float, float amplitude);
    std::vector<int32_t> data;

private:
    std::mt19937 rng;

};



#endif // SAMPLEDATA_HPP_INCLUDED
