#include<iostream>
#include<locale>
using namespace std;
struct splitted_string
{
    char** words;
    int num_of_words;
};

splitted_string split(char string[], char separator, int string_len)
{
    splitted_string ans;
	int separator_num_of_ind = 0;
	ans.num_of_words = 1;
	for (int i=0; i<string_len + 1; i++)
	{
		if (string[i] == separator && (i != string_len)){
			separator_num_of_ind +=1;
			ans.num_of_words +=1;
		} else if (i == 0 || i == string_len){
			separator_num_of_ind +=1;
	    }
	}
	int* separator_ind = new int[separator_num_of_ind];
	int j =0 ;
	for (int i=0; i<string_len; i++)
	{
		if (string[i] == separator){
			separator_ind[j] = i;
			j++;
		} else if (i == 0 || i == string_len-1 ){
			separator_ind[j] = i;
			j++;
		}
	}
	ans.words = new char*[ans.num_of_words];
	for (int word_n =0; word_n < ans.num_of_words;word_n++)
	{
		int differ = separator_ind[word_n + 1] - separator_ind[word_n] -1;
		if ((word_n == 0 && string[0] != separator) || (word_n == ans.num_of_words - 1 && (string[string_len-1] != separator))){
		    differ += 1;
		}
		ans.words[word_n] = new char[differ];
		for (int letter_n =0;letter_n < differ;letter_n ++)
		{
		    int ind = separator_ind[word_n] + 1 + letter_n;
		    if (word_n == 0 && (string[0] != separator))
		    {
		        ind -= 1;
		    }
			ans.words[word_n][letter_n] = string[ind];
		}
	}
	return ans;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << " Это программа для разделения строки на подстроки по вводимому символу" << endl<< " Укажите его: ";
	char mystr[] = "my secret servise";
	char sep;
	cin >> sep;
	int mystr_len = sizeof(mystr) - 1;
	splitted_string subs = split(&mystr[0], sep, mystr_len);//sep
	for (int h=0;h < subs.num_of_words; h++)
	{
	    cout << subs.words[h]<< endl;
	}
	return 0;
}
