#pragma once
#include <cliext\vector>
public ref class File
{
public:
	int algorithm;//0-Haffman, 1-RLE
	unsigned long int size, time;//размер исходного файла и время сжатия
	double k;//коэф. сжатия
public:
	File(int alg, unsigned long int s, unsigned long int t, double coeff){algorithm=alg; size=s; time=t; k=coeff;}
	~File(){}
};
public ref class Files
{
public:
	System::String^ Extension;
	cliext::vector<File^> file;
public:
	Files(){Extension="?";}
	Files(System::String^ ext){Extension=ext;}
	~Files(){}
	void Add(int algorithm, unsigned long int size, unsigned long int time, double k)
	{
		file.push_back(gcnew File(algorithm, size, time, k));
	}
};
public ref class AnalyzedData
{
public:
	cliext::vector<Files^> files;
public:
	AnalyzedData(){}
	~AnalyzedData(){}
	bool AddFile(System::String^ extension, int algorithm, unsigned long int size, unsigned long int time, double k)
	{
		int i;
		for(i=0; i<files.size(); i++)
		{
			if(files[i]->Extension==extension) break;
		}
		if(i==files.size())
		{
			Files^ newType=gcnew Files(extension);
			newType->Add(algorithm, size, time, k);
			files.push_back(newType);
			return true;//такого типа файла ещё не было
		}
		else files[i]->Add(algorithm, size, time, k);
		return false;//такой тип файлов уже был
	}
};