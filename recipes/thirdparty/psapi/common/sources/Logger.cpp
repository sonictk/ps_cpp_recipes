#include "PITypes.h"
#include "Logger.h"
#include "PIUFile.h"

const bool Logger::addEndOfLine = true;

Logger::Logger( const char * inString )
{

	if (GetFullPathToDesktop(fullPath, MAX_PATH))
	{
		fullPath[0] = '\0';
	}
	
	PIstrlcat(fullPath, inString, MAX_PATH-1);

	PIstrlcat(fullPath, ".log", MAX_PATH-1);
	
}

Logger::~Logger()
{
	try
	{
		fileOut.close();
	}
	catch (...)
	{
		/* Do nothing here, guarding against destructor throwing. */
	}
}
	
void Logger::Write( const char * inMessage, const bool endOfLine )
{
	Open();
	fileOut << inMessage;
	if (endOfLine)
		fileOut << endl;
	Close();
}
	
void Logger::Write( const int32 inValue, const bool endOfLine )
{
	Open();
	fileOut << inValue;
	if (endOfLine)
		fileOut << endl;
	Close();
}

void Logger::Write( const double inValue, const bool endOfLine )
{
	Open();
	fileOut << inValue;
	if (endOfLine)
		fileOut << endl;
	Close();
}

void Logger::Write( const string & inValue, const bool endOfLine )
{
	Write(inValue.c_str(), endOfLine);
}

void Logger::Write( vector<string> & inValue, const bool endOfLine )
{
	vector<string>::iterator iter = inValue.begin();
	while (iter != inValue.end())
	{
		Write((*iter).c_str(), endOfLine);
		iter++;
	}
}

void Logger::Write( ps_wstring & inValue, const bool endOfLine )
{
	ASZString zString;
	if (!sASZString2->MakeFromUnicode((ASUnicode*)inValue.c_str(), inValue.size(), &zString))
	{
		ASUInt32 utf8Size = sASZString2->LengthAsUTF8String(zString);
		unsigned char * utf8Buffer = new unsigned char[utf8Size];
		if (!sASZString2->AsUTF8String(zString, utf8Buffer, utf8Size, true /* check string size */)) 
		{
			Write((char*)utf8Buffer, endOfLine);
		}
		sASZString2->Release(zString);
		delete [] utf8Buffer;
	}
}

void Logger::Write( vector<ps_wstring> & inValue, const bool endOfLine )
{
	vector<ps_wstring>::iterator iter = inValue.begin();
	while (iter != inValue.end())
	{
		ASZString zString;
		if (!sASZString2->MakeFromUnicode((*iter).c_str(), (*iter).size(), &zString))
		{
			ASUInt32 utf8Size = sASZString2->LengthAsUTF8String(zString);
			unsigned char * utf8Buffer = new unsigned char[utf8Size];
			if (!sASZString2->AsUTF8String(zString, utf8Buffer, utf8Size, true /* check string size */)) 
			{
				Write((char*)utf8Buffer, endOfLine);
			}
			sASZString2->Release(zString);
			delete [] utf8Buffer;
		}
		iter++;
	}
}

void Logger::Open(void)
{
	fileOut.open(fullPath, ios_base::app|ios_base::out);
}

void Logger::Close(void)
{
	fileOut.close();
}
// end Logger.cpp
