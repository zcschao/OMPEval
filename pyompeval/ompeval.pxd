from libcpp.vector cimport vector
from libcpp.string cimport string
from libcpp cimport bool

cdef extern from "omp/Evaluator.h":
    cdef cppclass Evaluator:
        Evaluator() except +
        Evaluator(bool enumerateAll,double stdevTarget,int threadCount) except +
        vector[double] evaluate(vector[string] handRanges,string boardCards,string deadCards) except +