#include <iostream>
#include <vector>
#include <random>
#include "power_method_functions.hpp"

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
	std::vector<std::vector<double>> A = matrix(rows,cols);
	
	// Calling the function that prints the give A matrix
	std::cout << "\n\nMatrix A is:\n";
	print_matrix(A,rows,cols);
	
	// Initialize
	double tau = 0.0001;
	auto d = INFINITY;
	int jj = 0;
	double norm_vec;
	
	// Selecting a random vector
	std::vector<double> v = rand_col(A,rows,cols);
	
 	while (d>tau)
	{
	// Computes A*v
	std::vector<double> previous_v =  v;
	v = mat_x_vect(A,v,rows,cols);
	
	//Euclidean norm of v
	norm_vec = norm(v);
	
	//Normalize vector v
	v = normalize_vect(v,norm_vec,rows); 
	
	//print_vector(v);
	
 	// Compute d
	d = new_d(v,previous_v,rows);
	if (d <= tau)
	break;
	jj = jj+1;
	} 
	
	std::cout << "\n\nThe largest eigen value of A is:\t"<<norm_vec<<"\n";
	std::cout << "\n\nThe eigenvector associated with the largest eigenvalue is:\n\n\nv =\n";
	print_vector(v);
	std::cout << "\n\nThe value of d is:\t"<<d<<"\n\n";
	std::cout << "\nNumber of iteration(s) :=\t" << jj<<"\n\n";
	return 0;
}