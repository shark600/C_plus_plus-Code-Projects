// declaring functions
std::vector<std::vector<double>> matrix(int rows,int cols);
void print_matrix(std::vector<std::vector<double>> A, int rows, int cols);
std::vector<double> rand_col(std::vector<std::vector<double>> A,int rows,int cols);
void print_vector(std::vector<double> v);
std::vector<double> mat_x_vect(std::vector<std::vector<double>> A,std::vector<double> v,int rows,int cols);
double norm(std::vector<double> v);
std::vector<double> normalize_vect(std::vector<double> v, double norm_vec, int rows);
double new_d(std::vector<double> new_v, std::vector<double> v, int rows);