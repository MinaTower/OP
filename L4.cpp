#include<iostream>
using namespace std;
char** split(char* string, char separator)
{
	int string_len = sizeof(string) -1;
	int separator_num_of_ind = 0;
	int num_words = 1;
	for (int i=0; i<string_len; i++)
	{
		if (string[i] == separator){
			separator_num_of_ind +=1;
			num_words +=1;
		} else if (i == 0 || i == string_len-1 ){
			separator_num_of_ind +=1;
	}
	int* separator_ind = new int[separator_num_of_ind];
	int j =0 ;
	for (i=0; i<string_len; i++)
	{
		if (string[i] == separator){
			separator_ind[j] = i;
			j++;
		} else if (i == 0 || i == string_len-1 ){
			separator_ind[j] = i;
			j++;
		}
	}
	char** answer = new char*[num_words];
	for (int word_n =0;word_n < num_words;word_n++)
	{
		int differ = separator_ind[word_n + 1] - separator_ind[word_n];
		answer[word_n] = new char[differ];
		for (int letter_n =0;letter_n < differ;letter_n ++)
		{
			answer[word_n][letter_n] = string[separator_ind[word_n] + letter_n];
		}
	}
	return answer;
	}
}
	
int main()
{
	char* mystr[] = 'my secret servise';
	int s_len = sizeof(mystr) -1;
	char** subs = split(&mystr[0], 's');
	for (int h=0;h < s_len; h++)
	{
		cout << subs[h];
	}
	return 0;
}
