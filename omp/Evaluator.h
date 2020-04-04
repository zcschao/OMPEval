#ifndef OMP_EVALUATOR_H
#define OMP_EVALUATOR_H
#include "Evaluator.h"
#include "EquityCalculator.h"

class Evaluator {
public:
    Evaluator();
	Evaluator(bool _enumerateAll, double _stdevTarget, int _threadCount);
	std::vector<double> evaluate(
		std::vector<std::string> handRanges,
		std::string boardCards,
		std::string deadCards);


private:
	// omp::EquityCalculator eqc;
	bool enumerateAll;
	double stdevTarget;
	unsigned threadCount;
	std::function<void(const omp::EquityCalculator::Results&)> callback;
	double updateInterval;
};


#endif