/*
 * SVMTrainingSample.cpp
 *
 *  Created on: Jun 16, 2013
 *      Author: marcin
 */

#include "SVMTrainingSample.h"


SVMTrainingSample::SVMTrainingSample(std::vector<double> v, int classVal) {
	this->v = v;
	this->classVal = classVal;
}

SVMTrainingSample::~SVMTrainingSample() {
	// TODO Auto-generated destructor stub
}

std::vector<double> SVMTrainingSample::getVector() {
	return v;
}

int SVMTrainingSample::getClassVal() {
	return classVal;
}

std::vector<SVMTrainingSample> SVMTrainingSample::getSVMTrainingSamples() {

	std::vector<SVMTrainingSample> samples;
	int inputVectorSize = 3;

	std::vector<double> sample1Vec;
	sample1Vec.resize(inputVectorSize);
	sample1Vec[0] = 1.0;
	sample1Vec[1] = 1.0;
	sample1Vec[2] = 2.0;
	SVMTrainingSample sample1(sample1Vec, -1);
	samples.push_back(sample1);

	std::vector<double> sample2Vec;
	sample2Vec.resize(inputVectorSize);
	sample2Vec[0] = 3.0;
	sample2Vec[1] = 2.0;
	sample2Vec[2] = 2.5;
	SVMTrainingSample sample2(sample2Vec, -1);
	samples.push_back(sample2);

	std::vector<double> sample3Vec;
	sample3Vec.resize(inputVectorSize);
	sample3Vec[0] = 5.0;
	sample3Vec[1] = 4.0;
	sample3Vec[2] = 1.0;
	SVMTrainingSample sample3(sample3Vec, -1);
	samples.push_back(sample3);

	std::vector<double> sample4Vec;
	sample4Vec.resize(inputVectorSize);
	sample4Vec[0] = 2.0;
	sample4Vec[1] = 2.0;
	sample4Vec[2] = 5.2;
	SVMTrainingSample sample4(sample4Vec, 1);
	samples.push_back(sample4);

	std::vector<double> sample5Vec;
	sample5Vec.resize(inputVectorSize);
	sample5Vec[0] = 2.0;
	sample5Vec[1] = 3.0;
	sample5Vec[2] = 6.0;
	SVMTrainingSample sample5(sample5Vec, 1);
	samples.push_back(sample5);

	std::vector<double> sample6Vec;
	sample6Vec.resize(inputVectorSize);
	sample6Vec[0] = 2.5;
	sample6Vec[1] = 2.5;
	sample6Vec[2] = 6.0;
	SVMTrainingSample sample6(sample6Vec, 1);
	samples.push_back(sample6);


	return samples;
}

