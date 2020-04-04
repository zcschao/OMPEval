
#include "Evaluator.h"
#include "EquityCalculator.h"
#include <iostream>
using namespace omp;
using namespace std;

Evaluator::Evaluator(){}

Evaluator::Evaluator(bool _enumerateAll, double _stdevTarget, int _threadCount) {
	enumerateAll = _enumerateAll;
	stdevTarget = _stdevTarget;
	threadCount = _threadCount;


	updateInterval = 0.25; // Callback called every 0.25s.
}


vector<double> Evaluator::evaluate(
	vector<string> handRanges,
	string boardCards,
	string deadCards) {
	vector<CardRange> ranges;
	for (string &r : handRanges) {
		ranges.push_back(CardRange(r));
	}
	uint64_t board = boardCards.empty() ? 0 : CardRange::getCardMask(boardCards);
	uint64_t dead = deadCards.empty() ? 0 : CardRange::getCardMask(deadCards);


	EquityCalculator eq;
	callback = [&eq](const EquityCalculator::Results& results) {
		cout << results.equity[0] << " " << 100 * results.progress
			<< " " << 1e-6 * results.intervalSpeed << endl;
		if (results.time > 1) // Stop after 1s
			eq.stop();
	};

	eq.start(ranges, board, dead, enumerateAll, stdevTarget,
		callback, updateInterval, threadCount);
	eq.wait();

	vector<double> equity;
	auto r = eq.getResults();
	for (int i = 0; i < handRanges.size(); i++) {
		equity.push_back(r.equity[i]);
	}
	return equity;
}