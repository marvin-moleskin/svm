//============================================================================
// Name        : SimpleDotProduct.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include "SVMTrainingSample.h"
#include "SVMLinearSimple.h"
#include "SVMQPSolver.h"

using namespace svm;


int main() {

	std::vector<SVMTrainingSample> trainingSamples = SVMTrainingSample::getSVMTrainingSamples();

	// debug
	for(unsigned i = 0; i<trainingSamples.size(); i++) {
		std::cout << "sample: " << i << "\n";
		std::cout << "\tvector:" << "\n";
		for(unsigned j=0; j<trainingSamples[i].getVector().size(); j++) {
			std::vector<double> xVector = trainingSamples[i].getVector();
			std::cout << "\t" << xVector[j];
		}
		std::cout << "\n" << "classVal: " << trainingSamples[i].getClassVal() << "\n\n";
	}

//	SVMQPSolver solver;
//	solver.solve();


	SVMLinearSimple svmLinearSimple;
	svmLinearSimple.train(trainingSamples);

//	vector<double> data;
//	data.push_back(10.2);
//	data.push_back(12.1);

//	int classVal = svmLinearSimple.classify(data);
//	cout << "classVal: " << classVal;
}


