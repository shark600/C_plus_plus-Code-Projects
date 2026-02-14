#include <iostream>
#include <chrono>
#include "palindrome.hpp"


int main()
	{
		// Prompting the user for the text
		std::string word;
		std::cout << "Type the word and press 'Enter': ";
		std::cin >> word;
		std::cout << "\n";
		
		
		// Palindrome1 = Checking how long it takes to execute the function Palindrome1()
		// Start the clock
		std::chrono::high_resolution_clock::time_point start1 = std::chrono::high_resolution_clock::now();
		
		// Execute the function Palindrome1()
		bool check_is_palindrome1 = palindrome1(word);
			if (check_is_palindrome1 == true)
			{
				std::cout << "The word "<< word << " is a palindrome.";
			}
			else
			{
				std::cout << "The word "<< word << " is NOT a palindrome.";
			}
		std::cout << "\n";
		
		// Stop the clock
		std::chrono::high_resolution_clock::time_point end1 = std::chrono::high_resolution_clock::now();
		
		// Measure time taken for palindrome1() to execute:
		 std::chrono::duration<double, std::milli> time_span1 = end1 - start1;
		 
		// Print time taken for palindrome1() to run
		std::cout << "Time taken for  palindrome1() to run is: " << time_span1.count() << " milliseconds.\n\n";	
				
		
		// Palindrome2 = Checking how long it takes to execute the function Palindrome2()
		// Start the clock
		std::chrono::high_resolution_clock::time_point start2 = std::chrono::high_resolution_clock::now();
		
		// Execute the function Palindrome2()
		bool check_is_palindrome2 = palindrome2(word);
		
			if (check_is_palindrome2 == true)
			{
				std::cout << "The word "<< word << " is a palindrome.";
			}
			else
			{
				std::cout << "The word "<< word << " is NOT a palindrome.";
			}
		std::cout << "\n";
		
		// Stop the clock
		std::chrono::high_resolution_clock::time_point end2 = std::chrono::high_resolution_clock::now();
		
		// Measure time taken for palindrome2() to execute:
		 std::chrono::duration<double, std::milli> time_span2 = end2 - start2;
		 
		// Print time taken for palindrome2() to run
		std::cout << "Time taken for  palindrome2() to run is: " << time_span2.count() << " milliseconds.\n\n";
	}		