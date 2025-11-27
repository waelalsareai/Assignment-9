#include "stockFunctions.h"
#include <cmath>
#include <sstream>
using namespace std;

double percentChange(const vector<double>& values, int startDay, int endDay) {
    double start = values.at(startDay);
    double end = values.at(endDay);
    return (end - start) / start * 100.0;
}

double highestValue(const std::vector<double>& values, int startDay, int endDay)
{
    double maxVal = values.at(startDay);

    for (int i = startDay + 1; i <= endDay; i++) {
      