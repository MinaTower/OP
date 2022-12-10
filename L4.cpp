#include<iostream>
#include<locale>
using namespace std;
struct splitted_string
{
    char** words;
    int num_of_words;
};

splitted_string split(char strin[], char separator, int string_len)
{
    setlocale(LC_ALL, "Russian");
    splitted_string ans;
	int separator_num_of_ind = 0;
	ans.num_of_words = 1;
	for (int i=0; i<string_len + 1; i++)
	{
		if (strin[i] == separator && (i != string_len)){
			separator_num_of_ind +=1;
			ans.num_of_words +=1;
		} else if (i == 0 || i == string_len){
			separator_num_of_ind +=1;
	    }
	}
	if (ans.num_of_words == 1 && strin[string_len]!=separator){
		ans.words = &strin;
		return ans;
	}
	int* separator_ind = new int[separator_num_of_ind];
	int j = 0;
	for (int i=0; i<string_len; i++)
	{
		if (strin[i] == separator){
			separator_ind[j] = i;
			j++;
		} else if (i == 0 || i == string_len-1 ){
			separator_ind[j] = i;
			j++;
		}
	}
	ans.words = new char*[ans.num_of_words];
	for (int word_n =0; word_n < ans.num_of_words; word_n++)
	{
		int differ = separator_ind[word_n + 1] - separator_ind[word_n] ;
		if ((word_n == 0 && strin[0] != separator) || (word_n == ans.num_of_words - 1 && (strin[string_len-1] != separator))){
		    differ += 1;
		}
		ans.words[word_n] = new char[differ];
		for (int letter_n =0;letter_n < differ - 1;letter_n ++)
		{
		    int ind = separator_ind[word_n] + 1 + letter_n;
		    if (word_n == 0 && (strin[0] != separator))
		    {
		        ind -= 1;
		    }
			ans.words[word_n][letter_n] = strin[ind];
		}
		ans.words[word_n][differ -1] = '\0';
	}
	return ans;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << " Это программа для разделения строки на подстроки по вводимому символу" << endl<<" Ваш символ - пробел(y/n)? " ;
    char if_space;
    char sep = ' ';
    cin >> if_space;
    if (if_space == 'n'){
    	cout <<" Укажите его: ";
    	cin >> sep;
    	if (-33 < int(sep) && (int(sep) < -16 )){
            sep += 16;
        } else if (-128 <= int(sep) && (int(sep) < -16)) {
            sep += 64;
        }
    }// для не-дурака
	char mystr[] = "Бездыханная жертва невесомо покоилась на мощных руках. Мистер Фогг и сэр Фрэнсис Кромарти застыли на месте. Проводник в страхе склонил голову, Паспарту, без сомнения, тоже был потрясён!";//"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдеёжзийклмнопрстуфхцчшщъыьэюя";//"Alice was beginning to get very tired of sitting by her sister on the bank, and of having nothing to do: once or twice she had peeped into the book her sister was reading, but it had no pictures or conversations in it, 'and what is the use of a book,' thought Alice 'without pictures or conversations?'";//"my secret servise";
	int mystr_len = sizeof(mystr) - 1;
	splitted_string subs = split(&mystr[0], sep, mystr_len);

	cout <<endl<< " Полученный результат:"<< endl;
	for (int h=0; h < subs.num_of_words; h++)
	{
	    cout << ' '<<subs.words[h]<<endl;
	}
	return 0;
}
