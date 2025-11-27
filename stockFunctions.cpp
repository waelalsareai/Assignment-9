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
      if (values.at(i) > maxVal)
            maxVal = values.at(i);
    }

    return maxVal;
}

double average(const std::vector<double>& values, int startDay, int endDay)
{
  double sum = 0.0;
  for (int i = startDay; i <= endDay; i++) {
    sum += values.at(i);
  }
  int count = endDay - startDay + 1;
  return sum / count;
}

