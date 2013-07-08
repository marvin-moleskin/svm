/*
 * SVMLinearSimple.cpp
 *
 *  Created on: Jun 16, 2013
 *      Author: marcin
 */

#include "SVMLinearSimple.h"
#include "SVMQPSolver.h"
#include <numeric>

namespace svm {

	SVMLinearSimple::SVMLinearSimple() {

	}

	SVMLinearSimple::~SVMLinearSimple() {

	}

	void SVMLinearSimple::train(std::vector<SVMTrainingSample> trainingSamples) {

		int numberOfTrainingSamples = trainingSamples.size();
		int dimensionOfTrainingSamples = trainingSamples[0].getVector().size();

		w.resize(dimensionOfTrainingSamples);
		for(unsigned int i=0; i < w.size(); i++) {
			w[i] = 0.0;
		}

		std::cout << "train is called\n";

		// should end up in finding w vector
		// it is quadratic programming problem
		std::vector<std::vector<double> > quadraticObjMatrix = getQuadraticObjectMatrix(trainingSamples);
		std::vector<double> yVector;
		getYVector(yVector, trainingSamples);

		std::cout << "going to create solver\n";

		SVMQPSolver solver;
		std::vector<double> alpha;
		alpha.resize(numberOfTrainingSamples);
		solver.solve2(alpha, quadraticObjMatrix, yVector);

		std::cout << "alpha size: " << alpha.size() << "\n";
		for(unsigned i = 0; i<alpha.size(); i++) {
			std::cout << "alpha " << i << ":" << alpha[i] << "\n";
		}

		getWFromAlpha(w, alpha, trainingSamples);

		std::cout << "wVector size: " << w.size() << "\n";
		for(unsigned i = 0; i<w.size(); i++) {
			std::cout << "wVector " << i << ":" << w[i] << "\n";
		}

		double b = getBFromW(w, alpha, trainingSamples);
		std::cout << "b: " << b;
	}

	int SVMLinearSimple::classify(std::vector<double> data) {

		return 0;
	}

	double SVMLinearSimple::getDistanceFromLine(std::vector<double>& data) {

		double sum = 0;

		for(unsigned int i=0; i < w.size(); i++) {
			sum += w[i] + data[i];
		}
		sum += b;
		return sum;
	}

	std::vector<std::vector<double> > SVMLinearSimple::getQuadraticObjectMatrix(std::vector<SVMTrainingSample>& trainingSamples) {

		std::vector<std::vector<double> > matrix;
		unsigned noTrainingSamples = trainingSamples.size();

		// resize
		matrix.resize(noTrainingSamples);
		for(unsigned i=0; i<noTrainingSamples; i++) {
			matrix[i].resize(noTrainingSamples);
		}

		// i is row, j is column
		for(unsigned i=0; i<noTrainingSamples; i++) {
			for(unsigned j=0; j<noTrainingSamples; j++) {
				SVMTrainingSample trainingSample = trainingSamples[i];

				double yFst = (double) trainingSamples[i].getClassVal();
				double ySnd = (double) trainingSamples[j].getClassVal();

				std::vector<double> xFst = trainingSamples[i].getVector();
				std::vector<double> xSnd = trainingSamples[j].getVector();

				double dotProductOfX = std::inner_product(xFst.begin(), xFst.end(), xSnd.begin(), 0.0);

				double cellVal = yFst * ySnd * dotProductOfX;
				// y(row +1)
				// y(column + 1)
				matrix[i][j] = cellVal;
			}
		}
		return matrix;
	}

	std::vector<double>& SVMLinearSimple::getYVector(std::vector<double>& yVector, std::vector<SVMTrainingSample> trainingSamples) {

		yVector.resize(trainingSamples.size());

		for(unsigned i=0; i<trainingSamples.size(); i++) {
			yVector[i] = trainingSamples[i].getClassVal();
		}
		return yVector;
	}


	std::vector<double>& SVMLinearSimple::getWFromAlpha(std::vector<double>& wVector, std::vector<double>& alpha, std::vector<SVMTrainingSample>& trainingSamples) {

		for(unsigned int i=0; i < trainingSamples.size(); i++) {

			double classVal = trainingSamples[i].getClassVal();
			double alphaVal = alpha[i];

			for(unsigned int j=0; j < wVector.size(); j++) {
				w[j] += classVal * alphaVal * trainingSamples[i].getVector()[j];
			}
		}

		return wVector;
	}

	double SVMLinearSimple::getBFromW(std::vector<double>& wVector, std::vector<double>& alpha, std::vector<SVMTrainingSample>& trainingSamples) {
		for(unsigned int i=0; i < alpha.size(); i++) {
			if (alpha[i] != 0) {

				// debug
//				std::cout << "found support vector: \n";
//				for(unsigned int j=0; j < trainingSamples[i].getVector().size(); j++) {
//					std::cout << "\tvector val: " << trainingSamples[i].getVector()[j] << "\n";
//				}

				double b = 0;
				double classVal = trainingSamples[i].getClassVal();
				double dotProductOfWAndX = std::inner_product(wVector.begin(), wVector.end(), trainingSamples[i].getVector().begin(), 0.0);

				b = 1.0 / classVal - dotProductOfWAndX;
				return b;
			}
		}
		throw "Couldn't find support vector";
	}
}

