/*
 * SVMQPSolver.h
 *
 *  Created on: Jun 23, 2013
 *      Author: marcin
 */

#ifndef SVMQPSOLVER_H_
#define SVMQPSOLVER_H_

#include <vector>

#include <CGAL/basic.h>
#include <CGAL/QP_models.h>
#include <CGAL/QP_functions.h>
#include <CGAL/QP_solution.h>
#include <CGAL/Quotient.h>

// choose exact integral type
//#ifdef CGAL_USE_GMP
//#include <CGAL/Gmpz.h>
//typedef CGAL::Gmpz ET;
//#else
#include <CGAL/MP_Float.h>
typedef CGAL::MP_Float ET;
//#endif

// program and solution types
typedef CGAL::Quadratic_program<double> Program;
typedef CGAL::Quadratic_program_solution<ET> Solution;


namespace svm {

	class SVMQPSolver {

		private:
			void setMatrixD(Program& qp, const std::vector<std::vector<double> >& quadraticObjMatrix);

		public:
			SVMQPSolver();
			virtual ~SVMQPSolver();

			void solve();
			std::vector<double>& solve2(std::vector<double>& alpha, std::vector<std::vector<double> >& quadraticObjMatrix, std::vector<double>& yVector);
	};

} /* namespace svm */
#endif /* SVMQPSOLVER_H_ */
