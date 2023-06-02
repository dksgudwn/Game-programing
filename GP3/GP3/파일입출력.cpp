#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	//파일 쓰기, 읽기
	//open(), is_open(), close(), write()
	//std::ofstream writeFile("test2.txt", std::ios_base::out); //of: output file
	//writeFile.open("test.txt");
	//std::ofstream writeFile("test2.txt"); //of: output file
	//char arr[8] = "JunYong";
	//if (writeFile.is_open())
	//{
	//	writeFile.write(arr, 7);
	//	writeFile << "겜프" << std::endl;
	//	writeFile << "재희";
	//}
	/*std::ofstream writeFile("test3.txt");
	std::string str;
	for (int i = 0; i < 5; i++)
	{
		std::cin >> str;
		writeFile << str << std::endl;
	}
	writeFile.close();*/

	//std::ifstream readFile("test3.txt");//input
	//if (readFile.is_open())
	//{
	//	while (!readFile.eof())
	//	{
	//		std::cout << readFile.get() << std::endl;
	//	}
	//}
	std::ifstream readFile("test2.txt");
	/*string str;
	while (getline(readFile, str))
		cout << str << endl;*/
	char buf[1024];
	while (!readFile.eof())
	{
		readFile.getline(buf, 12);
		cout << buf << endl;
	}

}