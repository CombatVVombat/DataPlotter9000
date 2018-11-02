#include "sampledata.hpp"

cSampleData::cSampleData()
{
    rng.seed(std::random_device()());
}

void cSampleData::generateSinDataPoint(float i, float amplitude)
{
    data.push_back( int32_t(amplitude*sinf(i)) );
}

void cSampleData::generateRandomDataPoint(int32_t min, int32_t max)
{
    std::uniform_int_distribution<std::mt19937::result_type> distribution(min, max);
    int32_t random = distribution(rng);
    data.push_back(random);
}
