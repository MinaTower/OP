#include<iostream>
#include<locale>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    cout << " Это программа для нахождения в заданном тексте слова с наибольшей долей букв из определяемого набора."<< endl;
    char specials[] = "аеиАЕИ";
    char mytext[] = "Дурсли содрогались при одной мысли о том, что скажут соседи, если на Тисовую улицу пожалуют Поттеры. Дурсли знали, что у Поттеров тоже есть маленький сын, но они никогда его не видели.";//ГП и ФК, Росмэн
    int textSize = sizeof(mytext);
    double ans_proportion = 0;
    int word_length = 0;
    int specials_counter = 0;
    int ans[] = {0, 0};//indexes of the beginning and the end of the answer
    int word_starts = 0;
    for (int i = 0; i < textSize; i++)
    {
        if (isalpha(mytext[i])) {
            word_length ++;
            for (int g = 0; g < sizeof(specials); g++)
            {
                if (mytext[i] == specials[g]) {
                    specials_counter += 1;
                }
            }
        } else if (mytext[i] == '-') {
            //
        } else {
            if (ans_proportion <= double(specials_counter)/word_length) {
                ans_proportion = double(specials_counter)/word_length;
                ans[1] = i;
                ans[0] = word_starts + 1;
                if (word_starts == 0) {
                    ans[0] = word_starts;
                }
            }
            specials_counter = 0;
            word_length = 0;
            word_starts = i;
        }
    }
    cout << " Для текста" << endl << mytext << endl << " словом, имеющим наибольшую долю символов набора" << endl << specials << endl << " является, например, " << endl;
    for (int k = ans[0]; k < ans[1]; k++)
    {
        cout << mytext[k];
    }
    cout << endl;
    return 0;
}
