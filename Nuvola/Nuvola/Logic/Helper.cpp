#include "Helper.h"

// recieves the type code of the message from socket (3 bytes)
// and returns the code. if no message found in the socket returns 0 (which means the client disconnected)
int Helper::getMessageTypeCode(SOCKET sc)
{
	char* s = "";

	try
	{
		s = getPartFromSocket(sc, 3);
	}
	catch (exception e)
	{
		cout << e.what() << endl;
	}

	std::string msg(s);

	if (msg == "")
		return 0;

	int res = std::atoi(s);
	delete s;
	return  res;
}

// recieve data from socket according byteSize
// returns the data as int
int Helper::getIntPartFromSocket(SOCKET sc, int bytesNum)
{
	char* s = "";
	try
	{
		s = getPartFromSocket(sc, bytesNum, 0);
	}
	catch (std::exception e)
	{
		cout << e.what() << endl;
	}
	return atoi(s);
}

// recieve data from socket according byteSize
// returns the data as string
string Helper::getStringPartFromSocket(SOCKET sc, int bytesNum)
{
	char* s = "";
	try
	{
		s = getPartFromSocket(sc, bytesNum, 0);
	}
	catch (std::exception e)
	{
		cout << e.what() << endl;
	}

	string res(s);
	res = MsgEncrypt::Decipher(res, "cipher");
	return res;
}

// return string after padding zeros if necessary
string Helper::getPaddedNumber(int num, int digits)
{
	std::ostringstream ostr;
	ostr << std::setw(digits) << std::setfill('0') << num;
	return ostr.str();

}

// recieve data from socket according byteSize
// this is private function
char* Helper::getPartFromSocket(SOCKET sc, int bytesNum)
{
	return getPartFromSocket(sc, bytesNum, 0);
}

char* Helper::getPartFromSocket(SOCKET sc, int bytesNum, int flags)
{
	if (bytesNum == 0)
	{
		return "";
	}

	char* data = new char[bytesNum + 1];
	int res = recv(sc, data, bytesNum, flags);

	if (res == INVALID_SOCKET)
	{
		std::string s = "Error while recieving from socket: ";
		s += std::to_string(sc);
		throw std::exception(s.c_str());
	}

	data[bytesNum] = 0;
	return data;
}

// send data to socket
// this is private function
void Helper::sendData(SOCKET sc, std::string message)
{
	const char* data = message.c_str();

	if (send(sc, data, message.size(), 0) == INVALID_SOCKET)
	{
		throw std::exception("Error while sending message to client");
	}
}

std::vector<std::string> Helper::split(const std::string &text, char sep)
{
	std::vector<std::string> tokens;
	std::size_t start = 0, end = 0;
	while ((end = text.find(sep, start)) != std::string::npos)
	{
		tokens.push_back(text.substr(start, end - start));
		start = end + 1;
	}
	tokens.push_back(text.substr(start));
	return tokens;
}

int Helper::getFileSize(string path)
{
	std::ifstream f;
	f.open(path, std::ios_base::binary | std::ios_base::in);

	if (!f.good() || f.eof() || !f.is_open())
	{
		return 0;
	}

	f.seekg(0, std::ios_base::beg);
	std::ifstream::pos_type begin_pos = f.tellg();
	f.seekg(0, std::ios_base::end);

	return static_cast<int>(f.tellg() - begin_pos);
}

string Helper::getFileExtension(string fileName)
{
	if (fileName.find_last_of(".") != std::string::npos)
		return fileName.substr(fileName.find_last_of(".") + 1);
	return "";
}

string Helper::getFileNameFromPath(string fileName)
{
	const size_t last_slash_idx = fileName.find_last_of("\\/");
	if (std::string::npos != last_slash_idx)
	{
		fileName.erase(0, last_slash_idx + 1);
	}

	// Remove extension if present.
	const size_t period_idx = fileName.rfind('.');
	if (std::string::npos != period_idx)
	{
		fileName.erase(period_idx);
	}

	return fileName;
}

string Helper::getCurrentPath()
{
	// Getting the current working path of the program
	char buffer[MAX_PATH];
	GetModuleFileNameA(NULL, buffer, MAX_PATH);
	string::size_type pos = string(buffer).find_last_of("\\/");
	return string(buffer).substr(0, pos);
}

std::wstring Helper::s2ws(const std::string& s)
{
	// The function converts a string to a wstring
	int len;
	int slength = (int)s.length() + 1;
	len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
	wchar_t* buf = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
	std::wstring r(buf);
	delete[] buf;
	return r;
}

void Helper::sendBlockingData(SOCKET sc, std::string message)
{
	const char* data = message.c_str();

	if (send(sc, data, message.size(), 0) == INVALID_SOCKET)
	{
		throw std::exception("Error while sending message to client");
	}
}

void Helper::moveFileToDrive(const std::string &fileName)
{
	string newLoc = "N:\\" + fileName; // Creating the new path of the file

	std::wstring wsFileName = Helper::s2ws(fileName);
	LPCWSTR lpFileName = wsFileName.c_str();
	std::wstring wsNewLoc = Helper::s2ws(newLoc);
	LPCWSTR lpNewLoc = wsNewLoc.c_str(); // Converting the file name and the new location path to LPCWSTR

	if (!MoveFile(lpFileName, lpNewLoc)) // Moving the file to the new location
	{
		throw std::exception("Error while moving file to VHD");
	}
}