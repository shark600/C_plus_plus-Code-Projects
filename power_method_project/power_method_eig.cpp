#include <iostream>
#include <eigen3/Eigen/Eigen>
#include <random>

int main()
{
	//Enter the dimension of your matrix
	int rows,cols;
	std::cout << "\n\nEnter the number of rows of the matrix: ";
	std::cin >> rows;
	std::cout << "\n\nEnter the number of columns of the matrix: ";
	std::cin >> cols;
	std::cout << "\n\nA "<<rows<<" by "<<cols<<" matrix will be created\n";
	
	// Check for square matrix
	if (rows != cols)
	{
		std::cout << "\n\n'A' MUST BE A SQUARE MATRIX\n\n";
		exit(0);
	}
	
	// Creating a matrix
	Eigen::MatrixXd A(rows,cols);
	
	//Creating a user-defined matrix
	std::cout << "\n\nInput values for the "<<rows<<" by "<<cols<<" matrix:\n\n";
	for (int ii = 0; ii < rows; ii++) 
	{
		for (int jj = 0; jj < cols; jj++) 
		{
			std::cout << "\nA[" << ii+1 << "][" << jj+1<< "]=  ";
			std::cin >> A(ii,jj);
		}
	}

	// Pinting the value of the A matrix	
    std::cout << "\n\nMatrix A is:\n" <<A<<"\n";
	
	// Initialize
	double tau = 0.0001;
	auto d = INFINITY;
	int jj = 0;
	double norm_vec;
	
	// Selecting a random vector
	/* 1. Seed the random number engine */
	//random_device provides a non-deterministic seed if available.
	std::random_device random;

	/* 2. Choose a random number engine (Mersenne Twister is popular) */
	std::mt19937 generate(random());

	/* 3. Define the distribution  */
	int min = 0; //minimum value generated
	int max = cols-1;//maximum value generated
	std::uniform_int_distribution<> distrib(min, max);

	/* 4. Generate and print a random number */
	int rand_numb = distrib(generate);
	
	Eigen::VectorXd v = A.col(rand_numb);
	
	while (d>tau)
	{
	// Computes A*v
	Eigen::VectorXd previous_v =  v;
	v = A*v;
	
	//Euclidean norm of v
	norm_vec = v.norm();
	
	//Normalize vector v
	v.normalize();
	
	// Compute d
	d = (v - previous_v).norm();
	if (d <= tau)
	break;
	jj = jj+1;
	}
	
	std::cout << "\n\nThe largest eigenvalue of A is:\t"<<norm_vec<<"\n";
	std::cout << "\n\nThe eigenvector associated with the largest eigenvalue is:\n\n\nv =\n"<< v <<std::endl;
	std::cout << "\n\nThe value of d is:\t"<<d<<"\n\n";
	std::cout << "\nNumber of iteration(s) :=\t" << jj<<"\n\n";
	return 0;
}