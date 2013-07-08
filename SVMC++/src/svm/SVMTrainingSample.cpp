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
	int inputVectorSize = 2;

	std::vector<double> sample1Vec;
	sample1Vec.resize(inputVectorSize);
	sample1Vec[0] = 0.5;
	sample1Vec[1] = 1.3;
	SVMTrainingSample sample1(sample1Vec, -1);
	samples.push_back(sample1);

	std::vector<double> sample2Vec;
	sample2Vec.resize(inputVectorSize);
	sample2Vec[0] = 0.75;
	sample2Vec[1] = 2;
	SVMTrainingSample sample2(sample2Vec, -1);
	samples.push_back(sample2);

	std::vector<double> sample3Vec;
	sample3Vec.resize(inputVectorSize);
	sample3Vec[0] = 1;
	sample3Vec[1] = 0.6;
	SVMTrainingSample sample3(sample3Vec, -1);
	samples.push_back(sample3);

	std::vector<double> sample4Vec;
	sample4Vec.resize(inputVectorSize);
	sample4Vec[0] = 1.25;
	sample4Vec[1] = 1.4;
	SVMTrainingSample sample4(sample4Vec, -1);
	samples.push_back(sample4);

	std::vector<double> sample5Vec;
	sample5Vec.resize(inputVectorSize);
	sample5Vec[0] = 0.4;
	sample5Vec[1] = 3.2;
	SVMTrainingSample sample5(sample5Vec, 1);
	samples.push_back(sample5);

	std::vector<double> sample6Vec;
	sample6Vec.resize(inputVectorSize);
	sample6Vec[0] = 1.8;
	sample6Vec[1] = 3.1;
	SVMTrainingSample sample6(sample6Vec, 1);
	samples.push_back(sample6);

	std::vector<double> sample7Vec;
	sample7Vec.resize(inputVectorSize);
	sample7Vec[0] = 2.5;
	sample7Vec[1] = 1.8;
	SVMTrainingSample sample7(sample7Vec, 1);
	samples.push_back(sample7);

	std::vector<double> sample8Vec;
	sample8Vec.resize(inputVectorSize);
	sample8Vec[0] = 3.6;
	sample8Vec[1] = 0.8;
	SVMTrainingSample sample8(sample8Vec, 1);
	samples.push_back(sample8);



	return samples;
}

