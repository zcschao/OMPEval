# distutils: language = c++
from libcpp.vector cimport vector
from libcpp.string cimport string
from pyompeval.ompeval cimport Evaluator

cdef class OmpEval:
    cdef Evaluator evaluator

    def __cinit__(self,enumerateAll=False,stdevTarget=2e-5,threadCount=0):
        self.evaluator = Evaluator(enumerateAll,stdevTarget,threadCount)

    def evaluate(self, handRanges,  boardCards, deadCards):
        cdef vector[string] chandRanges
        for h in handRanges:
            chandRanges.push_back(h.encode("utf-8"))
        cdef string cboardCards
        cboardCards=boardCards.encode("utf-8")
        cdef string cdeadCards
        cdeadCards=deadCards.encode("utf-8")
        return self.evaluator.evaluate(chandRanges,cboardCards,cdeadCards)