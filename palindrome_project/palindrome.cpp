#include <string>

// Defining the two implementation of palindrome code

bool palindrome1(std::string text)
{
bool output;
std::string backward_text = "";
for (int i = text.size()-1; i>=0 ;i--)
{
 backward_text = backward_text + text[i] ;
}

if (backward_text == text)
{
output = true;  
}
else
{
output = false;
}
return output;
}

bool palindrome2(std::string text)
{
//block of code containing instructions the function is to perform;

	//determines how many letters from the frontend and backend respectively are to be compared.
	int quotient = text.size()/2;   
	bool output;

		// progressively compares the letter from the frontend index with its corresponding index from the backend.
		// if the number of words is odd it will skip the middle letter
		for (int ii = 0; ii <= quotient-1; ii++)
			{	
		
			// once there is a mismatch along the way during the comparison, it reports false (not a palindrome) and escapes the for loop. Check is finished. 
			// If there is no mistmatch during the check, it reports true (it is a palindrome.
			if (text[ii] != text[text.size()-1-ii])
				{
				output = false;
				break;
				}
				output = true;
				
			}
			
	return output;

}
