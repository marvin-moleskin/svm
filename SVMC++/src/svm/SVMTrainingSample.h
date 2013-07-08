/*
 * SVMTrainingSample.h
 *
 *  Created on: Jun 16, 2013
 *      Author: marcin
 */

#ifndef SVMTRAININGSAMPLE_H_
#define SVMTRAININGSAMPLE_H_

#include <vector>



class SVMTrainingSample {

private:
	std::vector<double> v;
	int classVal;

public:
	SVMTrainingSample(std::vector<double> v, int classVal);
	virtual ~SVMTrainingSample();

	std::vector<double> getVector();
	int getClassVal();

	static std::vector<SVMTrainingSample> getSVMTrainingSamples();
};



#endif /* SVMTRAININGSAMPLE_H_ */
