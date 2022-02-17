#ifndef __TOKEN__
#define __TOKEN__

#include<bits/stdc++.h>
using namespace std;

int linecount = 1;

char const *const SY_MULTI_LETTER_SYMBOL[] = { ">=", "<=", "==", "!=", "&&", "||" };
char const *const SY_SINGLE_LETTER_SYMBOL[] = { "+", "-", "!", "*", "/", "%", ">", "<", "=", ";", "(", ")", ",", "{", "}", "[", "]" };
char const *const SY_OPERATOR[] = { "+", "-", "!", "*", "/", "%", /*  "+", "-",  */
">", "<", ">=", "<=", "==", "!=", "&&", "||", "=" };
char const *const SY_OTHER_SYMBOL[] = { ";", "(", ")", ",", "{", "}", "[", "]" };

const unsigned int SY_OTHER_SYMBOL_LEN = sizeof(SY_OTHER_SYMBOL) / sizeof(SY_OTHER_SYMBOL[0]);
const unsigned int SY_OPERATOR_LEN = sizeof(SY_OPERATOR) / sizeof(SY_OPERATOR[0]);
const unsigned int SY_SINGLE_LETTER_SYMBOL_LEN = sizeof(SY_SINGLE_LETTER_SYMBOL) / sizeof(SY_MULTI_LETTER_SYMBOL[0]);
const unsigned int SY_MULTI_LETTER_SYMBOL_LEN = sizeof(SY_MULTI_LETTER_SYMBOL) / sizeof(SY_MULTI_LETTER_SYMBOL[0]);

enum TYPE {
	UNKNOWN, ERRORID,

	OPERATOR, SYMBOL, DEC_DIGIT, HEX_DIGIT, OCT_DIGIT,

	CONST, INT, VOID, IF, ELSE, WHILE, CONTINUE, BREAK, RETURN,

	IDENTIFIER
};

class Token {
private:
	char const *start;
	int length;
	string name;
	TYPE type;
	int line;

public:
	Token();
	Token(char const *start, int length, char const *const name, int line);
	Token(char const *start, int length, char const *const name, int line, TYPE type);
	~Token();

	int getLength() const;
	void setLength(int length);
	const string& getName() const;
	void setName(const string &name);
	const char* getStart() const;
	void setStart(const char *start);
	TYPE getType() const;
	void setType(TYPE type);
	int getLine();
};


Token::Token() :
		Token(nullptr, -1, nullptr, -1) {

}
Token::Token(char const *start, int length, char const *const name, int line) :
		Token(start, length, name, line, UNKNOWN) {

}
Token::Token(char const *start, int length, char const *const name, int line, TYPE type) :
		start(start), length(length), name(name), type(type), line(line) {

}
Token::~Token() {

}

int Token::getLine()
{
	return this->line;
}

int Token::getLength() const {
	return length;
}

void Token::setLength(int length) {
	this->length = length;
}

const string& Token::getName() const {
	return name;
}

void Token::setName(const string &name) {
	this->name = name;
}

const char* Token::getStart() const {
	return start;
}

void Token::setStart(const char *start) {
	this->start = start;
}

TYPE Token::getType() const {
	return type;
}

void Token::setType(TYPE type) {
	this->type = type;
}

bool read_file2string(char const *const file_path, string &str) {
	ifstream file(file_path);
	if (!file)
		return false;
	str.assign((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
	return true;
}

inline bool is_start_with(char const *const s1, char const *const s2) {
	return !strncmp(s1, s2, strlen(s2));
}

inline bool is_identifier_start_letter(char ch) {
	return isalpha(ch) || ch == '_';
}

inline bool is_identifier_letter(char ch) {
	return isalpha(ch) || isdigit(ch) || ch == '_';
}

inline shared_ptr<Token> new_identifier_token(char const *&current) {
	char const *start = current;
	while (is_identifier_letter(*++current))
		;
	char const *end = current;
	return shared_ptr<Token>(new Token(start, end - start, string(start, end).c_str(), linecount));
}

inline shared_ptr<Token> new_literal_token(char const *&current) {
	char const *start = current;
	int flag = 1;
	int count = 0;
	if ('0' != *current) {
		while (isdigit(*++current))
			;
		while (flag)
		{
			count ++;
			if(*current >= 'a' && *current <= 'z')
				current ++ ;
			else if(*current >= 'A' && *current <= 'Z')
				current ++;
			else if(*current == '_')
				current ++;
			else
				flag = 0;
		}
		char const *end = current;
		if(count == 1)
			return shared_ptr<Token>(new Token(start, end - start, string(start, end).c_str(), linecount));
		else
			return shared_ptr<Token>(new Token(start, end - start, string(start, end).c_str(), linecount, ERRORID));
	}

	++current;
	if ('x' != *current && 'X' != *current) {
		if (strchr("01234567", *current))
			while (strchr("01234567", *++current))
				;
		while (flag)
		{
			count ++;
			if(*current >= 'a' && *current <= 'z')
				current ++ ;
			else if(*current >= 'A' && *current <= 'Z')
				current ++;
			else if(*current == '_')
				current ++;
			else if(*current == '8' || *current == '9')
				current ++;
			else
				flag = 0;
		}
		char const *end = current;
		if(count == 1)
			return shared_ptr<Token>(new Token(start, end - start, string(start, end).c_str(), linecount));
		else
			return shared_ptr<Token>(new Token(start, end - start, string(start, end).c_str(), linecount, ERRORID));
	}
	{
		while (strchr("0123456789abcdefABCDEF", *++current))
			;
		while (flag)
		{
			count ++;
			if(*current >= 'g' && *current <= 'z')
				current ++ ;
			else if(*current >= 'G' && *current <= 'Z')
				current ++;
			else if(*current == '_')
				current ++;
			else
				flag = 0;
		}
		char const *end = current;
		if(count == 1)
			return shared_ptr<Token>(new Token(start, end - start, string(start, end).c_str(), linecount));
		else
			return shared_ptr<Token>(new Token(start, end - start, string(start, end).c_str(), linecount, ERRORID));
	}
}

inline bool is_multi_letter_symbol(char const *current) {
	for (int i = 0; i < SY_MULTI_LETTER_SYMBOL_LEN; ++i) {
		if (is_start_with(current, SY_MULTI_LETTER_SYMBOL[i]))
			return true;
	}
	return false;
}

inline shared_ptr<Token> new_multi_letter_symbol(char const *&current) {
	char const *start = current;
	for (int i = 0; i < SY_MULTI_LETTER_SYMBOL_LEN; ++i) {
		if (is_start_with(current, SY_MULTI_LETTER_SYMBOL[i])) {
			current += strlen(SY_MULTI_LETTER_SYMBOL[i]);
			char const *end = current;
			return shared_ptr<Token>(new Token(start, end - start, string(start, end).c_str(), linecount));
		}
	}
	//never reached!
	return nullptr;
}

inline bool is_single_letter_symbol(char const *current) {
	for (int i = 0; i < SY_SINGLE_LETTER_SYMBOL_LEN; ++i) {
		if (is_start_with(current, SY_SINGLE_LETTER_SYMBOL[i]))
			return true;
	}
	return false;
}

inline shared_ptr<Token> new_single_letter_symbol(char const *&current) {
	char const *start = current;
	for (int i = 0; i < SY_SINGLE_LETTER_SYMBOL_LEN; ++i) {
		if (is_start_with(current, SY_SINGLE_LETTER_SYMBOL[i])) {
			current += strlen(SY_SINGLE_LETTER_SYMBOL[i]);
			char const *end = current;
			return shared_ptr<Token>(new Token(start, end - start, string(start, end).c_str(), linecount));
		}
	}
	//never reached!
	return nullptr;
}

bool is_include_in_array(char const *const*const array, const unsigned int array_len, char const *const str) {
	for (int i = 0; i < array_len; ++i) {
		if (!strcmp(str, array[i])) {
			return true;
		}
	}
	return false;
}

bool string2tokens(char const *const str, vector<shared_ptr<Token>> &tokens) {

	char const *current = str;

	while (*current) {
		//空字符
		if (isspace(*current)) {
			if((*current) == '\n')
				linecount++;
			++current;
			continue;
		}
		//行注释
		if (is_start_with(current, "//")) {
			current += 2;
			while ('\n' != *(current++))
				if((*current) == '\n')
					linecount++;	
			continue;
		}
		//块注释
		if (is_start_with(current, "/*")) {
			while (!is_start_with(++current, "*/"))
				if((*current) == '\n')
					linecount++;
            
			current += 2;
			continue;
		}
		//标识符
		if (is_identifier_start_letter(*current)) {
			tokens.push_back(new_identifier_token(current));
			continue;
		}
		//数字
		if (isdigit(*current)) {
			tokens.push_back(new_literal_token(current));
			continue;
		}
		//多字符运算符
		if (is_multi_letter_symbol(current)) {
			tokens.push_back(new_multi_letter_symbol(current));
			continue;
		}
		//单字符运算符
		if (is_single_letter_symbol(current)) {
			tokens.push_back(new_single_letter_symbol(current));
			continue;
		}

		cout << "Error: Comment error at line "<< linecount <<"： Missing comment symbol" << endl;

		return false;
	}
	return true;
}

long long hex2dec (const char *arr)
{
	int temp,n;
	n = strlen(arr);               
    long long sum = 0;             
    for (int i = 0; arr[i]!='\0'; i++)         
    {
        switch (arr[i])
        {
        case 'A': temp = 10; break;
        case 'B': temp = 11; break;
        case 'C': temp = 12; break;
        case 'D': temp = 13; break;
        case 'E': temp = 14; break;
        case 'F': temp = 15; break;
        default: temp = arr[i] - '0'; break;
        }
        sum = sum + temp * pow(16, n - 1- i);
    }
	return sum;
}

long long oct2dec(const char * arr)
{
	int temp,n;
	n = strlen(arr);               
    long long sum = 0;             
    for (int i = 0; arr[i]!='\0'; i++)         
    {
		temp = arr[i] - '0';
        sum = sum + temp * pow(8, n - 1- i);
    }
	return sum;
}

void tokenoutput(vector<shared_ptr<Token>> &tokens)
{
	for (vector<shared_ptr<Token>>::iterator it = tokens.begin(), end = tokens.end(); it != end; ++it)
	{
		if ((*it)->getType() == ERRORID)
		{
			cout << "Error: ERRORID at line "<< (*it)->getLine()  <<": "<< (*it)->getName() << endl;
			continue;
		}
		
		char const *const name = (*it)->getName().c_str();
		if (is_include_in_array(SY_OPERATOR, SY_OPERATOR_LEN, name)) {
			cout << "<OPERATOR>" << endl;
			continue;
		}
		if (is_include_in_array(SY_OTHER_SYMBOL, SY_OTHER_SYMBOL_LEN, name)) {
			cout << "<SYMBOL>" << endl;
			continue;
		}
		if (isdigit(*name)) {
			if ('0' != *name)
				cout << "<NUM, " << name << ">" << endl;
			else if ('x' == *(name + 1) || 'X' == *(name + 1))
				cout << "<NUM, " << hex2dec(name+2) << ">" << endl;
			else
				cout << "<NUM, " << oct2dec(name+1) << ">" << endl;
			continue;
		}
		if (!strcmp("const", name))
			cout << "<CONST>" << endl;
		else if (!strcmp("int", name))
			cout << "<INT>" << endl;
		else if (!strcmp("void", name))
			cout << "<VOID>" << endl;
		else if (!strcmp("if", name))
			cout << "<IF>" << endl;
		else if (!strcmp("else", name))
			cout << "<ELSE>" << endl;
		else if (!strcmp("while", name))
			cout << "<WHILE>" << endl;
		else if (!strcmp("continue", name))
			cout << "<CONTINUE>" << endl;
		else if (!strcmp("break", name))
			cout << "<BREAK>" << endl;
		else if (!strcmp("return", name))
			cout << "<RETURN>" << endl;
		else
			cout << "<ID, " << name << ">" << endl;
		continue;
	}
}

#endif