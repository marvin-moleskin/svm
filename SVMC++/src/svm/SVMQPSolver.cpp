/*
 * SVMQPSolver.cpp
 *
 *  Created on: Jun 23, 2013
 *      Author: marcin
 */

#include <iostream>
#include <cassert>


#include "SVMQPSolver.h"



namespace svm {

	SVMQPSolver::SVMQPSolver() {
		// TODO Auto-generated constructor stub

	}

	SVMQPSolver::~SVMQPSolver() {
		// TODO Auto-generated destructor stub
	}

	void SVMQPSolver::solve() {

		 // by default, we have a nonnegative QP with Ax <= b
		  Program qp (CGAL::SMALLER, true, 0, false, 0);

		  // now set the non-default entries:
		  const int X = 0;
		  const int Y = 1;
		  qp.set_a(X, 0,  1); qp.set_a(Y, 0, 1); qp.set_b(0, 7);  //  x + y  <= 7
		  qp.set_a(X, 1, -1); qp.set_a(Y, 1, 2); qp.set_b(1, 4);  // -x + 2y <= 4
		  qp.set_u(Y, true, 4);                                   //       y <= 4
		  qp.set_d(X, X, 2); qp.set_d (Y, Y, 8); // !!specify 2D!!    x^2 + 4 y^2
		  qp.set_c(Y, -32);                                       // -32y
		  qp.set_c0(64);                                          // +64

		  // solve the program, using ET as the exact type
		  Solution s = CGAL::solve_quadratic_program(qp, ET());
		  assert (s.solves_quadratic_program(qp));

		  // output solution
		  std::cout << s;
		  return;
	}

	std::vector<double>& SVMQPSolver::solve2(std::vector<double>& result ,std::vector<std::vector<double> >& quadraticObjMatrix, std::vector<double>& yVector) {

		 // by default, we have a nonnegative QP with Ax <= b
		  Program qp (CGAL::EQUAL, true, 0, false, 0);

		  // example
		  // qp.set_d(X, X, 2); qp.set_d (Y, Y, 8); // !!specify 2D!!    x^2 + 4 y^2
		  // qp.set_c(Y, -32);                                       // -32y
		  // qp.set_c0(64);                                          // +64
		  setMatrixD(qp, quadraticObjMatrix); // lots of doubts what that matrix should be :/

		  // example
		  // now set the non-default entries:
		  // const int X = 0;
		  // const int Y = 1;

		  // set constraints (vector split to basic elements)
		  for(unsigned i=0; i<yVector.size(); i++) {

//			  example:
//			  qp.set_a(X, 0,  1); qp.set_a(Y, 0, 1); qp.set_b(0, 7);  //  x + y  <= 7
//			  qp.set_a(X, 1, -1); qp.set_a(Y, 1, 2); qp.set_b(1, 4);  // -x + 2y <= 4
//			  qp.set_u(Y, true, 4);                                   //       y <= 4

			  // y*alpha = 0;
			  qp.set_a(i, 0,  yVector[i]);
			  qp.set_b(0, 0);
		  }

		  for(unsigned i=0; i<yVector.size(); i++) {

			  // example
			  // qp.set_c(Y, -32);                                       // -32y
			  qp.set_c(i, -1);
		  }

		  // solve the program, using ET as the exact type
		  Solution s = CGAL::solve_nonnegative_quadratic_program(qp, ET());
		  assert (s.solves_quadratic_program(qp));

		  int i=0;
		  for (Solution::Variable_value_iterator
			   it = s.variable_values_begin();
			   it < s.variable_values_end();
			   ++it, i++)
		  {
			  CGAL::Quotient<ET> quotient = *it;
			  ET numerator = quotient.numerator();
			  ET denominator = quotient.denominator();
			  double numeratorD = CGAL::to_double(numerator);
			  double denominatorD = CGAL::to_double(denominator);
			  double valD = numeratorD / denominatorD;
			  result[i] = valD;
		  }

		  // output solution
//		  std::cout << s;

		  //TODO remove that as it returns empty vector
		  return result;
	}

	void SVMQPSolver::setMatrixD(Program& qp, const std::vector<std::vector<double> >& quadraticObjMatrix) {
		for(unsigned i=0; i<quadraticObjMatrix.size(); i++) {
			for(unsigned j=0; j<quadraticObjMatrix.size(); j++) {
				// set_d needs only values for lower diagonal (triangular?) part of matrix - I guess
				// that's why we will just skip upper diagonal elements
				if (i >= j) {
					qp.set_d(i, j, quadraticObjMatrix[i][j]);
				}
			}
		}
	}

} /* namespace svm */
