#include <iostream>
#include <random>

//Creating a matrix
std::vector<std::vector<double>> matrix(int rows,int cols)
{
std::vector<std::vector<double>> A(rows,std::vector<double>(cols,0));
std::cout << "\n\nInput values for the "<<rows<<" by "<<cols<<" matrix:\n\n";
    for (int ii = 0; ii < rows; ii++) 
	{
        for (int jj = 0; jj < cols; jj++) 
		{
            std::cout << "\nA[" << ii+1 << "][" << jj+1<< "]=  ";
            std::cin >> A[ii][jj];
        }
    }
return A;
}

// Function to print the given A matrix
void print_matrix(std::vector<std::vector<double>> A, int rows, int cols)
{
	for (int ii = 0; ii < rows; ii++)
	{
		for (int jj = 0; jj < cols; jj++)
		{
		std::cout << A[ii][jj]<<"\t";
		}
	std::cout <<"\n";
	}
return;
}

// Function selecting a random number
std::vector<double> rand_col(std::vector<std::vector<double>> A,int rows,int cols)
{	
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
	
	std::vector<double> v;
	
	for (int kk = 0; kk < rows; kk++)
	{
		v.push_back(A[kk][rand_numb]);
	}
return v;
}

// Function to print the vector v
void print_vector(std::vector<double> v)
{
	for (int ll = 0; ll < v.size(); ll++)
	{
		std::cout << v[ll] << "\n";
	}
return;
}

// Function to multiply matrix to a vector
std::vector<double> mat_x_vect(std::vector<std::vector<double>> A,std::vector<double> v,int rows,int cols)
{
	std::vector<double> vect(rows,0.0);
	for (int mm = 0; mm < rows; mm++)
	{
		for (int nn = 0; nn < rows; nn++)
		{
			vect[mm] = vect[mm] + (A[mm][nn]*v[nn]);
		}
	}
return vect;
}

// The Euclidean Norm of a Vector
double norm(std::vector<double> v)
{
	double sqrsumv = 0;
	for (int oo = 0; oo < v.size(); oo++)
	{
		sqrsumv += pow(v[oo],2);
	}
	double norm_vec = std::sqrt(sqrsumv);
	
return norm_vec;
}

// The normalize new vector
std::vector<double> normalize_vect(std::vector<double> v, double norm_vec, int rows)
{
	std::vector<double> new_v(rows,0.0);
	for (int pp = 0; pp < v.size(); pp++)
	{
		new_v[pp]  = v[pp]/norm_vec;
	}
return new_v;
}

// Compute d
double new_d(std::vector<double> new_v, std::vector<double> v, int rows)
{
	std::vector<double> d_vect(rows,0.0);
		for (int qq = 0; qq < v.size(); qq++)
	{
		d_vect[qq]  = new_v[qq] - v[qq];
	}
	double d = norm(d_vect);
return d;
}