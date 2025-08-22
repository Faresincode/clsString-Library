#pragma once
#include<iostream>
#include<string>
#include <vector>
#include<iomanip>
//using namespace std;

class clsString
{

private:

	std::string _Text;
	int _Number;
	short _Num;
	char _Character;
	std::string _Delimiter;
	std::vector<std::string>_StringVector;
	std::vector<int>_IntVector;
	std::vector<short>_ShortVector;
	std::vector<char>_CharacterVector;

public:
	//============================== Defination Constractor =======================================
	
	clsString()
	{
		_Text = "";
		_Number = 0;
		_Character = ' ';
	}
	clsString(std::string Value="",int Number=0, short Num=0,char Character=' ')
	{
		this->_Text = Value;
		this->_Number = Number;
		this->_Character = Character;
		this->_Num = Num;
	}

	//=======================================================================================

	void setText(std::string Value)
	{
		this->_Text=Value;
	}
	std::string getText()
	{
		return this->_Text;
	}
	__declspec(property(get = getText, put = setText))std::string Value;

	void setNumber(int Number)
	{
		this->_Number = Number;
	}
	int getNumber()
	{
		return this->_Number;
	}
	__declspec(property(get = getNumber, put = setNumber))int Number;

	void setNum(short Num)
	{
		this->_Num = Num;
	}
	short getNum()
	{
		return this->_Num;
	}
	__declspec(property(get = getNum, put = setNum))short Number;

	void setCharacter(char Character)
	{
		this->_Character = Character;
	}
	char getCharacter()
	{
		return this->_Character;
	}
	__declspec(property(get = getCharacter, put = setCharacter))char Character;

	//====================================== vectors Property ==============================================

	void setStringVector(std::vector<std::string>StringVector)
	{
		this->_StringVector = StringVector;
	}
	std::vector<std::string>getStringVector()
	{
		return this->_StringVector;
	}
	__declspec(property(get = getStringVector, put = setStringVector))std::vector<std::string> StringVector;

	void setIntVector(std::vector<int>IntegerVector)
	{
		this->_IntVector = IntegerVector;
	}
	std::vector<int>getIntVector()
	{
		return this->_IntVector;
	}
	__declspec(property(get = getIntVector, put = setIntVector))std::vector<int> IntVector;

	void setShortVector(std::vector<short>IntegerVector)
	{
		this->_ShortVector = IntegerVector;
	}
	std::vector<short>getShortVector()
	{
		return this->_ShortVector;
	}
	__declspec(property(get = getShortVector, put = setShortVector))std::vector < short> ShortVector;

	void setCharacterVector(std::vector<char>IntegerVector)
	{
		this->_CharacterVector = IntegerVector;
	}
	std::vector<char>getCharacterVector()
	{
		return this->_CharacterVector;
	}
	__declspec(property(get = getCharacterVector, put = setCharacterVector))std::vector<char> CharacterVector;

	void setDelimiter(std::string Delimiter)
	{
		this->_Delimiter = Delimiter;
	}
	std::string getDelimiter()
	{
		return this->_Delimiter;
	}
	__declspec(property(get = getDelimiter, put = setDelimiter))std::string Delimiter;
	//=======================================================================================
	static std::string NumberToText(int Number)
	{

		if (Number == 0)
			return "";

		if (Number >= 1 && Number <= 19)
		{
			std::string arr[] = { "","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };
			return arr[Number] + " ";
		}

		if (Number >= 20 && Number <= 99)
		{
			std::string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
			return arr[Number / 10] + " " + NumberToText(Number % 10);
		}

		if (Number >= 100 && Number <= 199)
			return "One Hundred " + NumberToText(Number % 100);

		if (Number >= 200 && Number <= 999)
			return NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);

		if (Number >= 1000 && Number <= 1999)
			return "One Thousand " + NumberToText(Number % 1000);

		if (Number >= 2000 && Number <= 999999)
			return NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);

		if (Number >= 1000000 && Number <= 1999999)
			return "One Million " + NumberToText(Number % 1000000);

		if (Number >= 2000000 && Number <= 999999999)
			return NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);

		if (Number >= 1000000000 && Number <= 1999999999)
			return "One Billion " + NumberToText(Number % 1000000000);
		else
			return NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);

	}
	std::string NumberToText()
	{
		return clsString::NumberToText(this->_Number);
	}

	static std::string WeekDayName(short DayOfWeekOrder)
	{
		if (DayOfWeekOrder < 1  || DayOfWeekOrder > 7)
			return "";
		std::string arrDayNames[7] = { "Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday" };
		return arrDayNames[DayOfWeekOrder - 1];
	}
	std::string WeekDayName()
	{
		return clsString::WeekDayName((short)_Number);
	}

	static std::string ShortWeekDayName(short DayOfWeekOrder)
	{
		return  (WeekDayName(DayOfWeekOrder)).substr(0,3);
	}
	std::string ShortWeekDayName()
	{
		return clsString::ShortWeekDayName((short)_Number);
	}
	 
	static std::string MonthName(short MonthNumber)
	{
		if (MonthNumber < 1 || MonthNumber>12)
			return "";
		std::string Months[12] ={"January", "February", "March","April", "May", "Jun","July", "August", "September","October", "November", "December"};
		return (Months[MonthNumber - 1]);
	}
	std::string MonthName()
	{
		return 	clsString::MonthName((short)_Number);
	}

	static std::string ShortMonthName(short MonthNumber)
	{
		return MonthName(MonthNumber).substr(0,3);
	}
	std::string ShortMonthName()
	{
		return clsString::ShortMonthName(_Number).substr(0, 3);
	}

	static std::vector<std::string>SplitString(std::string Text, std::string Delimiter)
	{
		std::vector <std::string> vWords;
		std::string word;
		short Position = 0;
		while ((Position = Text.find(Delimiter)) != std::string::npos)
		{
			word = Text.substr(0, Position);
			if (word != "")
			{
				vWords.push_back(word);
			}
			Text.erase(0, Position + Delimiter.length());

		}
		if (Text != "")
		{
			vWords.push_back(Text);
		}

		return vWords;
	}
	std::vector<std::string>SplitString()
	{
		return clsString::SplitString(_Text, _Delimiter);
	}
	
	static int RandomIntNum(int From, int To)
	{
		return 	rand() % (To - From + 1) + From;
	}

	//================================== Boolians Functions  ===================================
	static bool IsUpper(char character)
	{
		for (short i = 65; i <= 90; i++)
		{
			if (char(i) == character)
				return true;
		}
		return false;
	}
	bool IsUpper()
	{
		return clsString::IsUpper(this->_Character);
	}

	static bool IsLower(char Character)
	{

		for (short i = 97; i <= 122; i++)
		{
			if (char(i) == Character)
				return true;
		}
		return false;
	}
	bool IsLower()
	{
		return clsString::IsLower(this->_Character);
	}

	static bool IsVowel(char Letter)
	{
		Letter = ToLower(Letter);
		return (Letter == 'a') || (Letter == 'e') || (Letter == 'i') || (Letter == 'o') || (Letter == 'u');
	}
	bool IsVowel()
	{
		return  clsString::IsVowel(this->_Character);
	}

	static bool IsEmpty(const std::string Text)
	{
		return (clsString::Length(Text) == 0);
	}
	bool IsEmpty()
	{
		return clsString::IsEmpty(this->_Text);
	}

	static bool IsPunct(const char Character)
	{
		//Check All punctuation
		for (short i = 33; i <= 126; i++)
		{
			// Skip digits and letters 
			if ((i >= 48 && i <= 57) || (i >= 65 && i <= 90) || (i >= 97 && i <= 122))
				continue;
			if (char(i) == Character)
				return true;
		}
		return false;
	}
	bool IsPunct()
	{
		return clsString::IsPunct(this->_Character);
	}

	static bool IsContains(std::string Text, std::string SubText)
	{
		short SubTextLength = clsString::Length(SubText);
		for (int i = 0; i < (clsString::Length(Text) - SubTextLength); i++)
		{
			short j = 0;
			while (j < SubTextLength && Text[i + j] == SubText[j])
			{
				j++;
			}
			if (j == SubTextLength)
			{
				return true;
			}
		}
		return false;
	}
	bool IsContains(std::string SubText)
	{
		return IsContains(this->_Text, SubText);
	}

	static bool IsStartWith(const std::string Text, const char Character)
	{
		return Text[0] == Character;
	}
	bool IsStartWith(char Character)
	{
		return clsString::IsStartWith(this->_Text, Character);
	}

	static bool IsEndWith(const std::string Text, const char Character)
	{
		return Text[clsString::Length(Text) - 1] == Character;
	}
	bool IsEndWith(char Character)
	{
		return clsString::IsEndWith(this->_Text, Character);
	}

	static bool IsIntNumber(const char Character)
	{
		for (short i = 48; i <= 57; i++)
		{
			if (char(i) == Character)
				return true;
		}
		return false;
	}
	bool IsIntNumber()
	{
		return clsString::IsIntNumber(this->_Character);
	}

	static bool IsStringNumbers(std::string Text)
	{
		for (char& i : Text)
		{
			if (!IsIntNumber(i))
				return false;
		}
		return true;
	}
	bool IsStringNumbers()
	{
		return clsString::IsStringNumbers(this->_Text);
	}

	static bool IsCharExist(std::string Text, char Character)
	{
		for (char& i : Text)
		{
			if (i == Character)
				return true;
		}
		return false;
	}
	bool IsCharExist(char Character)
	{
		return clsString::IsCharExist(this->_Text, Character);
	}

	static bool IsPalindrome(std::string Text)
	{
		return (Text == Reverse(Text));
	}
	bool IsPalindrome()
	{
		return clsString::IsPalindrome(this->_Text);
	}

	static bool IsLetter(char Character)
	{
		Character = clsString::ToLower(Character);
		for (short i = 97; i <= 122; i++)
		{
			if (char(i) == Character)
				return true;
		}
		return false;
	}
	bool IsLetter()
	{
		return clsString::IsLetter(this->_Character);
	}

	static bool IsAlphabet(std::string Text)
	{
		for (char& i : Text)
		{
			if (!clsString::IsLetter(i))
				return false;
		}
		return true;
	}
	bool IsAlphabet()
	{
		return clsString::IsAlphabet(this->_Text);
	}

	//================================ Get Character ==========================================
	static char At(std::string Text, short CharacterIndex)
	{
		return Text[CharacterIndex];
	}
	char At(short CharacterIndex)
	{
		return At(this->_Text, CharacterIndex);
	}

	static char First(std::string Text)
	{
		return Text[0];
	}
	char First()
	{
		return this->_Text[0];
	}

	static char End(std::string Text)
	{
		return Text[clsString::Length(Text) - 1];
	}
	char End()
	{
		return End(this->_Text);
	}

	static char MostFrequentChar(std::string Text)
	{
		Text = clsString::ToLowerAll(Text);
		Text = clsString::RemoveChar(Text, ' ');
		short BigestCount = 0;
		char MostFrequentChar = ' ';
		for (char& i : Text)
		{
			short Counter = 0;
			for (char& j : Text)
			{
				if (i == j)
					Counter++;
			}
			if (BigestCount < Counter)
			{
				BigestCount = Counter;
				MostFrequentChar = i;
			}
		}
		return MostFrequentChar;
	}
	char MostFrequentChar()
	{
		return clsString::MostFrequentChar(this->_Text);
	}

	static char RandomChar(short From, short To)
	{
		return char(RandomIntNum(From, To));
	}

	//=============================== Upper and Lower ========================================
	static char ToLower(char Character)
	{
		if (IsUpper(Character))
		{
			short Counter = 0;
			for (short i = 65; i <= 90; i++)
			{
				if (char(i) == Character)
					return char(97 + Counter);
				Counter++;

			}
		}

		return Character;
	}
	char ToLower()
	{
		return clsString::ToLower(this->_Character);
	}

	static char ToUpper(char Character)
	{
		if (IsLower(Character))
		{
			short Counter = 0;
			for (short i = 97; i <= 122; i++)
			{
				if (char(i) == Character)
					return char(65 + Counter);
				Counter++;
			}
		}
		else
			return Character;
	}
	char ToUpper()
	{
		return clsString::ToUpper(this->_Character);
	}

	static std::string ToLowerAll(std::string TextString)
	{
		for (char&i : TextString)
		{
			i= clsString::ToLower(i) ;
		}
		return TextString;
	}
	std::string ToLowerAll()
	{
		return clsString::ToLowerAll(_Text);
	}

	static std::string ToUpperAll(std::string TextString)
	{
		for (char& i : TextString)
		{
			i=clsString::ToUpper(i);
		}
		return TextString;
	}
	std::string ToUpperAll()
	{
		return clsString::ToUpperAll(_Text);
	}

	static std::string ToUpperWords(std::string Text)
	{
		bool IsFirstLetter = true;
		for (int i = 0; i < clsString::Length(Text); i++)
		{
			if (Text[i] != ' ' && IsFirstLetter)
			{
				Text[i] = clsString::ToUpper(Text[i]);
			}
			IsFirstLetter = ((Text[i] == ' ') ? true : false);
		}
		return Text;
	}
	std::string ToUpperWords()

	{
		return clsString::ToUpperWords(this->_Text);
	}

	static std::string ToLowerWords(std::string Text)
	{
		bool IsFirstLetter = true;
		for (int i = 0; i < clsString::Length(Text); i++)
		{
			if (Text[i] != ' ' && IsFirstLetter)
			{
				Text[i] = clsString::ToLower(Text[i]);
			}
			IsFirstLetter = ((Text[i] == ' ') ? true : false);
		}
		return Text;
	}
	std::string ToLowerWords()

	{
		return clsString::ToLowerWords(this->_Text);
	}

	//================================== Counters ========================================
	static int Length(std::string Text)
	{
		int Counter = 0;
		for (char& i : Text)
			Counter++;
		return Counter;
	}
	int Length()
	{
		return clsString::Length(this->_Text);
	}

	static short CountSmallLetters(std::string Text)
	{
		short Counter = 0;
		for (short i = 0; i < clsString::Length(Text); i++)
		{
			if (IsLower(Text[i]))
				Counter++;
		}
		return Counter;
	}
	short CountSmallLetters()
	{
		return clsString::CountSmallLetters(this->_Text);
	}

	static short CountCapitalLetters(const std::string Text)
	{
		short Counter = 0;
		for (short i = 0; i < clsString::Length(Text); i++)
		{
			if (IsUpper(Text[i]))
				Counter++;
		}
		return Counter;
	}
	short CountCapitalLetters()
	{
		return clsString::CountCapitalLetters(this->_Text);
	}

	enum enWhatToCount { eSmallLetters = 0, eCapitalLetters = 2, eDigits = 3, ePunctuation = 4, eSpaces = 5, eAll = 6 };
	static short CountLetters(std::string S1, enWhatToCount WhatToCount = enWhatToCount::eAll)
	{
		short Counter = 0;
		switch (WhatToCount)
		{
		case enWhatToCount::eAll:
		{
			return S1.length();
		}

		case enWhatToCount::eSmallLetters:
		{
			for (short i = 0; i < S1.length(); i++)
			{
				if (islower(S1[i]))
					Counter++;
			}
			break;

		}

		case enWhatToCount::eCapitalLetters:
		{
			for (short i = 0; i < S1.length(); i++)
			{
				if (isupper(S1[i]))
					Counter++;
			}
			break;

		}

		case enWhatToCount::eDigits:
		{

			for (short i = 0; i < S1.length(); i++)
			{
				if (isdigit(S1[i]))
					Counter++;
			}
			break;
		}

		case enWhatToCount::ePunctuation:
		{
			for (short i = 0; i < S1.length(); i++)
			{
				if (ispunct(S1[i]))
					Counter++;
			}
			break;

		}

		case enWhatToCount::eSpaces:
		{

			for (short i = 0; i < S1.length(); i++)
			{
				if (S1[i] == ' ')
					Counter++;
			}
			break;
		}

		}
		return Counter;

	}

	static short CountChar(const std::string Text, char Character)
	{
		int Counter = 0;
		for (int i = 0; i < clsString::Length(Text); i++)
		{
			if (Text[i] == Character)
			{
				Counter++;
			}
		}
		return Counter;
	}
	short CountChar()
	{
		return clsString::CountChar(this->_Text, this->_Character);
	}

	static short CountLetter(const std::string Text, char Letter, bool MatchCase = true)
	{
		short Counter = 0;
		for (short i = 0; i < clsString::Length(Text); i++)
		{
			if (MatchCase)
			{
				if (Text[i] == Letter)
					Counter++;
			}
			else
			{
				if (ToLower(Text[i]) == ToLower(Letter))
					Counter++;
			}
		}

		return Counter;
	}
	short CountLetter(bool MatchCase = true)
	{
		return clsString::CountLetter(this->_Text, this->_Character, MatchCase);
	}

	static short CountMostFrequentChar(std::string Text)
	{
		return clsString::CountChar(Text, MostFrequentChar(Text));
	}
	short CountMostFrequentChar()
	{
		return clsString::CountMostFrequentChar(this->_Text);
	}

	static short CountVowels(const std::string Text)
	{
		short Counter = 0;
		for (short i = 0; i < clsString::Length(Text); i++)
		{
			if (IsVowel(Text[i]))
				Counter++;
		}
		return Counter;
	}
	short CountVowels()
	{
		return clsString::CountVowels(this->_Text);
	}

	static short CountWords(std::string Text, std::string Delimiter = " ")
	{

		std::cout << "\nYour string wrords are: \n\n";
		short Counter = 0;
		short pos = 0;
		std::string sWord; // define a string variable// use find() function to get the position of the delimiters
		while ((pos = Text.find(Delimiter)) != std::string::npos)
		{
			sWord = Text.substr(0, pos); // store the word
			if (sWord != "")
				Counter++;
			Text.erase(0, pos + Delimiter.length());
		}
		if (Text != "")
			Counter++;
		return Counter;
	}
	short CountWords()
	{
		return clsString::CountWords(this->_Text);
	}

	//=======================================================================================
	static std::string Left(std::string Text, short Steps)
	{
		return clsString::SubString(Text, 0, Steps);
	}
	std::string Left(short Steps)
	{
		return clsString::Left(this->_Text, Steps);
	}

	static std::string Right(std::string Text, int Steps)
	{
		int TextLength = clsString::Length(Text);
		return SubString(Text, TextLength - Steps, TextLength);
	}
	std::string Right(int Steps)
	{
		return clsString::Right(this->_Text, Steps);
	}

	static std::string TrimLeft(std::string Text)
	{
		for (short i = 0; i < clsString::Length(Text); i++)
		{
			if (Text[i] != ' ')
			{
				return Text.substr(i, clsString::Length(Text) - i);
			}
		}
		return "";
	}
	std::string TrimLeft()
	{
		return clsString::TrimLeft(this->_Text);
	}
	
	static std::string TrimRight(std::string Text)
	{
		for (short i = clsString::Length(Text) - 1; i >= 0; i--)
		{
			if (Text[i] != ' ')
			{
				return Text.substr(0, i + 1);
			}
		}
		return "";
	}
	std::string TrimRight()
	{
		return clsString::TrimRight(this->_Text);
	}

	static std::string Trim(std::string S1)
	{
		return clsString::TrimLeft(clsString::TrimRight(S1));
	}
	std::string Trim()
	{
		return clsString::Trim(this->_Text);
	}

	static std::string JoinString(const std::vector<std::string>vString, std::string  Delimiter=" ")
	{
		std::string Text = "";
		for (const std::string &s : vString)
		{
			Text += s + Delimiter;
		}
		return Text.substr(0, clsString::Length(Text) -  clsString::Length(Delimiter));
	}
	std::string JoinString()
	{
		return clsString::JoinString(this->_StringVector,this->_Delimiter);
	}

	static std::string ReverseWords(std::string Text,std::string Delimiter=" ")
	{
		std::vector <std::string >vString;
		std::string s2 = "";
		vString = SplitString(Text, Delimiter);
		std::vector<std::string>::iterator iter;
		iter = vString.end();
		while (iter != vString.begin())
		{
			--iter;
			s2 = s2 + *iter + " ";
		}
		s2 = s2.substr(0, s2.length() - 1);
		return s2;
	}
	std::string ReverseWords()
	{
		return ReverseWords(this->_Text);
	}

	static std::string ReplaceWordUsingSplit(std::string S1, std::string ToReplace, std::string ReplaceWith, bool MatchCase = true)
	{
		std::vector<std::string>vString=SplitString(S1, " ");
		for (std::string& word : vString)
		{
			if (MatchCase)
			{
				if (word == ToReplace)
				{
					word = ReplaceWith;
				}
			}
			else
			{
				if (ToLowerAll(word) == ToLowerAll(ToReplace))
				{
					word = ReplaceWith;
				}
			}
		}
		return clsString::JoinString(vString, " ");
	}
	std::string ReplaceWordUsingSplit( std::string ToReplace, std::string ReplaceWith, bool MatchCase = true)
	{
		return ReplaceWordUsingSplit(this->_Text, ToReplace, ReplaceWith, MatchCase);
	}
	
	static std::string ReplaceWord(std::string Text, std::string StringToReplace, std::string sRepalceTo)
	{
		short pos;
		while ((pos = Text.find(StringToReplace)) != std::string::npos)
		{
			Text = Text.replace(pos, clsString::Length(StringToReplace), sRepalceTo);
		}
		return Text;

	}
	std::string ReplaceWord(std::string StringToReplace, std::string sRepalceTo)
	{
		return ReplaceWord(this->_Text, StringToReplace, sRepalceTo);
	}

	static std::string ReplaceALL(std::string Text, std::string TextToReplace, std::string ReplaceWith)
	{
		short pos;

		while ((pos = clsString::Find(Text, TextToReplace)) != (std::string::npos))
		{
			Text = clsString::Erase(Text, pos, clsString::Length(TextToReplace) - 1);
			Text = clsString::Insert(Text, ReplaceWith, pos);
		}
		return Text;
	}
	std::string ReplaceALL(std::string TextToReplace, std::string ReplaceWith)
	{
		return clsString::ReplaceALL(this->_Text, TextToReplace, ReplaceWith);
	}

	//=======================================================================================
	static std::string FirstWord(std::string Text, std::string Delimiter = " ")
	{
		return clsString::SubString(Text, 0, clsString::Find(Text, Delimiter));
	}
	std::string FirstWord(std::string Delimiter = " ")
	{
		return clsString::FirstWord(this->_Text, Delimiter);
	}

	static std::string EndWord(std::string Text, std::string Delimiter = " ")
	{
		return clsString::FirstWord(clsString::ReverseWords(Text), Delimiter);
	}
	std::string EndWord(std::string Delimiter = " ")
	{
		return EndWord(this->_Text, Delimiter);
	}

	static std::string LongestWord(std::string Text, std::string Delimiter = " ")
	{
		std::string LongestWord = "";
		std::vector<std::string>vString = clsString::SplitString(Text, Delimiter);
		short BigestWordCount = 0;
		short Counter = 0;
		for (std::string& str : vString)
		{
			Counter = clsString::Length(str);
			if (Counter > BigestWordCount)
			{
				BigestWordCount = Counter;
				LongestWord = str;
			}
		}
		return LongestWord;
	}
	std::string LongWord(std::string Delimiter = " ")
	{
		return LongestWord(this->_Text, Delimiter);
	}

	static std::string ShortestWord(std::string Text, std::string Delimiter = " ")
	{
		std::string LowestWord = "";
		std::vector<std::string>vString = clsString::SplitString(Text, Delimiter);
		short LowestWordCount = 0;
		short Counter = 0;
		for (std::string& str : vString)
		{
			Counter = clsString::Length(str);
			if (Counter < LowestWordCount)
			{
				LowestWordCount = Counter;
				LowestWord = str;
			}
		}
		return LowestWord;
	}
	std::string ShortestWord(std::string Delimiter = " ")
	{
		return ShortestWord(this->_Text, Delimiter);
	}

	static std::string WordWrap(std::string Text, short MaxLineLength, std::string Delimiter = " ")
	{
		std::string WrapedString = "";
		std::vector<std::string>vString = clsString::SplitString(Text, Delimiter);
		short LineLengthCounter = 0;
		for (std::string& str : vString)
		{
			if (LineLengthCounter + clsString::Length(str) > MaxLineLength)
			{
				WrapedString += "\n";
				LineLengthCounter = 0;
			}
			WrapedString += str + Delimiter;
			LineLengthCounter += clsString::Length(str) + clsString::Length(Delimiter);
		}
		return WrapedString;
	}
	std::string WordWrap(short MaxLineLength, std::string Delimiter = " ")
	{
		return clsString::WordWrap(this->_Text, MaxLineLength, Delimiter);
	}

	static std::string RightHalf(std::string Text)
	{
		return clsString::Erase(Text, 0, (clsString::Length(Text) / 2) - 1);
	}
	std::string RightHalf()
	{
		return clsString::RightHalf(this->_Text);
	}

	static std::string LeftHalf(std::string Text)
	{
		return clsString::Erase(Text, clsString::Length(Text) / 2, clsString::Length(Text));
	}
	std::string LeftHalf()
	{
		return clsString::LeftHalf(this->_Text);
	}

	static std::string PadLeft(std::string Text, short TotalLength, char PaddingChar = ' ')
	{
		std::string NewString = "";
		for (short i = 0; i < TotalLength; i++)
			NewString += PaddingChar;
		NewString += Text;
		return NewString;
	}
	std::string PadLeft(short TotalLength, char PaddingChar = ' ')
	{
		return clsString::PadLeft(this->_Text, TotalLength, PaddingChar);
	}

	static std::string PadRight(std::string Text, short TotalLength, char PaddingChar = ' ')
	{
		for (short i = 1; i <= TotalLength; i++)
			Text += PaddingChar;
		return Text;
	}
	std::string PadRight(short TotalLength, char PaddingChar = ' ')
	{
		return clsString::PadRight(this->_Text, TotalLength, PaddingChar);
	}

	static std::string PadCenter(std::string Text, short TotalLength, char PaddingChar = ' ')
	{
		std::string NewString = "";
		NewString += LeftHalf(Text);
		for (int i = 1; i <= TotalLength; i++)
		{
			NewString += PaddingChar;
		}
		return NewString + RightHalf(Text);
	}
	std::string PadCenter(short TotalLength, char PaddingChar = ' ')
	{
		return clsString::PadCenter(this->_Text, TotalLength, PaddingChar);
	}

	//=======================================================================================

	static int Find(const std::string  Text, const std::string StringToFind)
	{
		int TextSize = clsString::Length(Text);
		short StringToFindSize = clsString::Length(StringToFind);
		if (StringToFindSize == 0) return 0; // empty pattern matches at 0
		for (int i = 0; i <= TextSize - StringToFindSize; i++)
		{
			short j = 0;
			while (j < StringToFindSize && Text[i + j] == StringToFind[j])
				j++;
			if (j == StringToFindSize)
				return i;
		}
		return std::string::npos; //if the program get to this point is mean that he is not match
	}
	int Find(const std::string StringToFind)
	{
		return Find(this->_Text, StringToFind);
	}

	static std::string Append(std::string Text, std::string TextToAdd)
	{
		return Text + TextToAdd;
	}
	std::string Append(std::string TextToAdd)
	{
		return clsString::Append(this->_Text, TextToAdd);
	}

	static std::string Push_Back(std::string Text,char CharacterToAdd)
	{
		return Text + CharacterToAdd;
	}
	std::string Push_Back(char CharacterToAdd)
	{
		return clsString::Push_Back(this->_Text, CharacterToAdd);
	}

	static std::string Insert(std::string Text, std::string TextToAdd, int Index)
	{
		std::string NewString = "";
		int Counter = 0;
		for (char& i : Text)
		{
			if (Counter == Index)
				NewString += TextToAdd;
			NewString += i;
			Counter++;

		}
		return NewString;
	}
	std::string Insert(std::string TextToAdd, short Index)
	{
		return clsString::Insert(this->_Text, TextToAdd, Index);
	}

	static std::string SubString(std::string Text, short From, short Steps)
	{
		std::string NewSubstring = "";
		for (int i = 0; i < clsString::Length(Text); i++)
		{
			if (i >= From && i < Steps + From)
			{
				NewSubstring += Text[i];
			}
		}
		return NewSubstring;
	}
	std::string SubString( short From, short Steps)
	{
		return clsString::SubString(this->_Text, From, Steps);
	}

	static std::string Repeat(std::string Text, short Count)
	{
		std::string NewString = "";
		for (short i = 1; i <= Count; i++)
		{
			NewString += Text;
		}
		return NewString;
	}
	std::string Repeat(short Count)
	{
		return clsString::Repeat(this->_Text, Count);
	}

	static std::string Reverse(std::string Text)
	{
		std::string RevercedString = "";
		for (short i = clsString::Length(Text) - 1; i >= 0; i--)
		{
			RevercedString += Text[i];
		}
		return RevercedString;
	}
	std::string Reverse()
	{
		return clsString::Reverse(this->_Text);
	}

	static char InvertChar(char Character)
	{
		return clsString::IsUpper(Character) ? clsString::ToLower(Character) : clsString::ToUpper(Character);
	}
	char InvertChar()
	{
		return clsString::InvertChar(this->_Character);
	}

	static std::string InvertAllStringLetterCase(std::string Text)
	{
		for (int i = 0; i < clsString::Length(Text); i++)
		{
			Text[i] = clsString::InvertChar(Text[i]);
		}
		return Text;
	}
	std::string InvertAllStringLetterCase()
	{
		return clsString::InvertAllStringLetterCase(this->_Text);
	}

	//============================== Encryption ==========================================

	static std::string Encrypt(std::string Text, int EncryptedKey)
	{
		for (int i = 0; i < clsString::Length(Text); i++)
			Text[i] = char((int)Text[i] + EncryptedKey);
		return Text;
	}
	std::string Encrypt(int EncryptedKey)
	{
		return Encrypt(this->_Text, EncryptedKey);
	}

	static std::string Decrypt(std::string Text, int EncryptedKey)
	{
		for (int i = 0; i < clsString::Length(Text); i++)
			Text[i] = char((int)Text[i] - EncryptedKey);
		return Text;
	}
	std::string Decrypt(int EncryptedKey)
	{
		return clsString::Decrypt(this->_Text, EncryptedKey);
	}

	//============================ Remove Functions ============================================

	static std::string RemovePunct(std::string Text)
	{
		std::string StringWithoutPunct = "";
		for (char &i: Text)
		{
			if (!clsString::IsPunct(i))
				StringWithoutPunct += i;
		}
		return StringWithoutPunct;
	}
	std::string RemovePunct()
	{
		return clsString::RemovePunct(this->_Text);
	}

	std::string EraseFromTo(std::string Text, short From, short To)
	{
		std::string NewString = "";
		for (short i = 0; i < clsString::Length(Text); i++)
		{
			if (i >= From && i <= To)
				continue;
			NewString += Text[i];
		}
		return NewString;
	}
	std::string EraseFromTo(short From, short To)
	{
		return clsString::EraseFromTo(this->_Text,From, To);
	}

	static std::string Erase(std::string Text, short From, short Steps)
	{
		std::string NewString = "";
		for (short i = 0; i < clsString::Length(Text); i++)
		{
			if (i >= From && i <= From + Steps)
				continue;
			NewString += Text[i];
		}
		return NewString;
	}
	std::string Erase(short From, short Steps)
	{
		return clsString::Erase(this->_Text, From, Steps);
	}

	static std::string RemoveChar(std::string Text, char Character)
	{
		std::string NewString = "";
		for (char& i : Text)
		{
			if (i == Character)
				continue;
			NewString += i;
		}
		return NewString;
	}
	std::string RemoveChar(char Character)
	{
		return RemoveChar(this->_Text,Character);
	}

	static std::string RemoveDuplicateCharacters(std::string Text)
	{
		std::string NewString = "";
		for (char& i : Text)
		{
			if (clsString::IsCharExist(NewString, i))
				continue;
			for (char& j : Text)
			{
				if (i == j)
				{
					NewString += i;
					break;
				}
			}
		}

		return NewString;
	}
	std::string RemoveDuplicateCharacters()
	{
		return clsString::RemoveDuplicateCharacters(this->_Text);
	}

	static std::string RemoveExtraSpaces(std::string Text)
	{
		return clsString::ReplaceALL(Text, "  ", " ");
	}
	std::string RemoveExtraSpaces()
	{
		return RemoveExtraSpaces(this->_Text);
	}

	static std::string RemoveLeadingChar(std::string Text,char LeadingCharacter)
	{
		short Counter = 0;
		for (char& i : Text)
		{
			if (i != LeadingCharacter)
				break;
			Counter++;
		}
		return clsString::Erase(Text, 0, Counter);
	}
	std::string RemoveLeadingChar(char LeadingCharacter)
	{
		return clsString::RemoveLeadingChar(this->_Text,LeadingCharacter);
	}

	//============================= Conversion ========================================

	static int ToInt(std::string Text)
	{
		int IntegerNumber;
		if (IsStringNumbers(Text))
		{
			IntegerNumber = (Text[0]) - '0';
			short Counter = 0;
			while (Counter < Text.length() - 1)
			{
				Counter++;
				IntegerNumber = (IntegerNumber * 10) + ((Text[Counter]) - '0');
			}
		}
		return IntegerNumber;
	}
	int ToInt()
	{
		return clsString::ToInt(this->_Text);
	}

	static int CharToInt(char Character)
	{
		if (IsIntNumber(Character))
			return Character - '0';
		else
			return -1;
	}
	int CharToInt()
	{
		return clsString::CharToInt(this->_Character);
	}

	//============================= Escape Sequences ========================================

	static std::string Tabs(int NumberOfTabs)
	{
		std::string Tab = "";
		for (int i = 1; i <= NumberOfTabs; i++)
			Tab += "\t";
		return Tab;
	}
	static std::string BackSlashN(int NumberOfBackSlashN)
	{
		std::string BackSlash = "";
		for (int i = 1; i <= NumberOfBackSlashN; i++)
			BackSlash += "\n";
		return BackSlash;
	}
	static std::string Ring(int NumberOfRing)
	{
		std::string Ring = "";
		for (int i = 1; i <= NumberOfRing; i++)
			Ring += "\a";
		return Ring;
	}

	//============================= Conversion ========================================
	static std::string Spaces(short NumberOfSpaces)
	{
		std::string Spaces = "";
		for (short i = 1; i <= NumberOfSpaces; i++)
			Spaces += " ";
		return Spaces;
	}
	std::string Spaces()
	{
		return clsString::Spaces((short)_Number);
	}

	static void PrintAllStringVowels(std::string Text)
	{
		short Counter = 0;
		std::cout << "\n Vowels In String are : ";
		for (char& i : Text)
		{
			if (IsVowel(i))
				std::cout << std::setw(3) << i;
		}
		std::cout << std::endl;

	}
	void PrintAllStringVowels()
	{
		clsString::PrintAllStringVowels(this->_Text);
	}

	static void PrintStringWords(std::string S1)
	{
		std::string delim = " "; // delimiter
		std::cout << "\nYour string wrords are: \n\n";
		short pos = 0;
		std::string sWord; // define a string variable// use find() function to get the position of the delimiters
		while ((pos = S1.find(delim)) != std::string::npos)
		{
			sWord = S1.substr(0, pos); // store the word
			if (sWord != "")
			{
				std::cout << sWord << std::endl;
			}
			S1.erase(0, pos + delim.length());
		}
		if (S1 != "")
		{
			std::cout << S1 << std::endl; // it print last word of the string.
		}
	}
	void PrintStringWords()
	{
		return clsString::PrintStringWords(this->_Text);
	}



};

