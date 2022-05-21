#include "operations.h"

double sum(const double& left, const double& right) {
	return left + right;
}

double dif(const double& left, const double& right) {
	return left - right;
}

double mult(const double& left, const double& right) {
	return left * right;
}

double div(const double& left, const double& right) {
	return left / right;
}

double myRemainder(const double& left, const double& right) {
	return int(left) % int(right);
}

double myPower(const double& left, const double& right) {
	return pow(left, right);
}

double myInverse(const double& x) {
	return 1.0 / x;
}