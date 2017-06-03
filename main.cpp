#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int str_parser(string S)
{
	//string S = "We test coders. Give us a try?";
	// Copy of sentence
	char s_copy[100];

	int c_index = 0;
	for (char c : S)
	{
		s_copy[c_index] = c;
		c_index++;
	}
	s_copy[c_index] = '\0';


	// Define the list of delimiters for sentences 
	char sentence_delims[3] = { '.', '?', '!' };

	//Define delim for words
	char word_delim = ' ';

	int max_words = 0;
	vector<string> sentences;

	char* tok_pointer;
	tok_pointer = strtok(s_copy, sentence_delims);
	while (tok_pointer != NULL)
	{
		sentences.push_back(string(tok_pointer));
		tok_pointer = strtok(NULL, sentence_delims);
	}
	// Have sentences, get word count

	for (string test_string : sentences) // normally use a reference, but actually want a copy of each string here
	{
		string temp_str;
		stringstream temp_stream;
		temp_stream.str(test_string);
		int i = 0;
		while (getline(temp_stream, temp_str, word_delim))
		{
			if (temp_str == "")
				continue;
			i++;
		}

		if (i > max_words)
			max_words = i;
	}
	return max_words;
}

// Count the number of perfect squares that appear in the range of A to B, inclusive
int sqrt_counter(int A, int B) {
	//int A = 4;
	//int B = 17;
	int num_whole_sqs = 0;

	// Slow iterative way
	//for (int test = A; test <= B; ++test)
	//{
	//	// test for integer
	//	if (sqrt(abs(test)) == floor(sqrt(abs(test))))
	//		num_whole_sqs++;

	//}

	// Better time complexity due to less sqrt operations 
	int sqrtA = sqrt(abs(A));
	int sqrtB = sqrt(abs(B));

	int diff = floor(sqrtB) - ceil(sqrtA);

	if (diff > 0)
		num_whole_sqs = diff + 1;

	return num_whole_sqs;
}

int main()
{
	string S = "We test coders. Give us a try?";
	int max_words = str_parser(S);

	int A = 5;
	int B = 6;
	int num_squares = sqrt_counter(A, B);
}