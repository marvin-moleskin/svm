/*
 * SVMLinearSimple.h
 *
 *  Created on: Jun 16, 2013
 *      Author: marcin
 */

#ifndef SVMLINEARSIMPLE_H_
#define SVMLINEARSIMPLE_H_

#include <vector>
#include "SVMTrainingSample.h"

namespace svm {

	class SVMLinearSimple {

		private:
			std::vector<double> w;
			double b;

			double getDistanceFromLine(std::vector<double>& data);
			std::vector<std::vector<double> > getQuadraticObjectMatrix(std::vector<SVMTrainingSample>& trainingSamples);
			std::vector<double>& getYVector(std::vector<double>& yVector, std::vector<SVMTrainingSample> trainingSamples);

		public:
			SVMLinearSimple();
			virtual ~SVMLinearSimple();

			void train(std::vector<SVMTrainingSample> trainingSamples);
			int classify(std::vector<double> data);

			std::vector<double>& getWFromAlpha(std::vector<double>& wVector, std::vector<double>& alpha, std::vector<SVMTrainingSample>& trainingSamples);
			double getBFromW(std::vector<double>& wVector, std::vector<double>& alpha, std::vector<SVMTrainingSample>& trainingSamples);
	};

	#endif /* SVMLINEARSIMPLE_H_ */

}
