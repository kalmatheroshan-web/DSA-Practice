#include <iostream>

using namespace std;

int get_len(char ch[])
{
    int i = 0, len = 0;
    while (ch[i++] != '\0')
    {
        len++;
    }

    return len;
}

// reverse string
void reverse(char ch[])
{
    int st = 0, end = get_len(ch) - 1;
    while (st <= end)
    {
        swap(ch[st++], ch[end--]);
    }
}

// replace all spaces
void replace_space(char ch[])
{
    int i = 0;
    while (ch[i] != '\0')
    {
        if (ch[i] == ' ')
        {
            ch[i] = '@';
        }
        i++;
    }
}

// palindrom check
bool is_palidrom(char ch[])
{
    int st = 0, end = get_len(ch) - 1;

    while (st <= end)
    {
        if (ch[st] != ch[end])
        {
            return false;
        }
        st++, end--;
    }
    return true;
}

void to_upper(char ch[])
{
    int i = 0;

    while (ch[i] != 0)
    {
        if (ch[i] >= 'a' && ch[i] <= 'z')
        {
            int cnt = ch[i] - 'a';
            ch[i] = 'A' + cnt;
        }
        i++;
    }
}

void to_lower(char ch[])
{
    int i = 0;
    while (ch[i] != 0)
    {
        if (ch[i] >= 'A' && ch[i] <= 'Z')
        {
            ch[i] = ch[i] - 'A' + 'a';
        }
        i++;
    }
}

int main()
{

    // //get the length of an array
    // char name[100];
    // cin >> name;
    // cout << "value : " << name << endl;
    // cout << "length of that string " << get_len(name) << endl;
    // cout << "Length is " << strlen(name) << endl;

    // char res[] = "Love";
    // reverse(res);
    // cout << res << endl;

    // char input[] = "I Love the Dosa";
    // cout << "Before : " << input << endl;
    // replace_space(input);
    // cout << "After : " << input << endl;

    // cout << "is palindrome : " << is_palidrom("kadak") << endl;

    char ch[20] = "roshan Kalmathe";
    // to_upper(ch);
    // cout << ch << endl;
    // to_lower(ch);
    // cout << ch << endl;

    return 0;
} 