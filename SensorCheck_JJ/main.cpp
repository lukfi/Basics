#include <iostream>
#include <vector>

struct Measure
{
    uint32_t timestamp;
    double amplitude;
};

struct Result
{

};

void CompareSensors(const std::vector<Measure>& reference, const std::vector<Measure>& sensor)
{
    uint32_t refSize = reference.size();
    uint32_t sensSize = sensor.size();

    uint32_t refPos = 0;
    uint32_t sensPos = 0;

    uint32_t correctCount = 0;
    uint32_t missingCount = 0;
    uint32_t extraCount = 0;

    for (; refPos < refSize; ++refPos)
    {
        uint32_t timestamp = reference[refPos].timestamp;
        double amplitude = reference[refPos].amplitude;

        if (sensPos == sensSize)
        {
            printf("%d missing (%d total)\n", timestamp, refSize - refPos);
            break;
        }

        while (sensPos < sensSize)
        {
            if (sensor[sensPos].timestamp == timestamp)
            {
                // check amplitude
                if (sensor[sensPos].amplitude == amplitude)
                {
                    ++correctCount;
                    printf("%d OK\n", timestamp);
                }
                else
                {
                    printf("%d wrong\n", timestamp);
                }
                ++sensPos;
                break;
            }
            else if  (sensor[sensPos].timestamp > timestamp)
            {
                ++missingCount;
                printf("%d missing\n", timestamp);
                break;
            }
            printf("%d extra\n", sensor[sensPos].timestamp);
            ++extraCount;
            ++sensPos;
        }
    }
    extraCount += sensSize - sensPos;
    printf("total extra: %d\n", extraCount);
}

int main()
{

    std::vector<Measure> reference = {{1000, 7.0},
                                      {1002, 7.1},
                                      {1003, 7.2},
                                      {1004, 7.4},
                                      {1005, 7.4},
                                      {1006, 7.5},
                                      {1010, 7.6},
                                      {1011, 7.6},
                                      {1012, 7.6}
                                     };

    std::vector<Measure> sensor    = {{1000, 7.0}, // ok
                                      {1001, 7.1}, // extra
                                      {1002, 7.2}, // wrong
                                      {1003, 7.3}, // wrong
                                      {1004, 7.4}, // ok
                                      {1005, 7.5}, // wrong
                                      {1006, 7.5}, // ok
                                                   // missing
                                      {1013, 7.5}, // extra
                                      {1014, 7.5}  // extra
                                     };

    CompareSensors(reference, sensor);
}
