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

double standardDev(const std::vector<double>& values, int startDay, int endDay)
{
  double mean = average(values, startDay, endDay);

  double sumSqDiff = 0.0;

  for (int i = startDay; i <= endDay; i++) {
    double diff = values.at(i) - mean;
    sumSqDiff += diff * diff;
  }

  int count = endDay - startDay +1;
  double variance = sumSqDiff / count;
  return std::sqrt(variance);
}

std::vector<double> getChangeVector(const std::vector<double>& values)
{
  std::vector<double> changes(values.size());

  if (values.empty()) {
    return changes;
  }

  changes[0] = 0.0;

  for (std::size_t i=1; i < values.size()); ++i)