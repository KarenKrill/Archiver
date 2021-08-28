#pragma once
#include <fstream>
#include <vcclr.h>//для преобразования из "System::String ^" в "const wchar_t *"
#include <cliext\vector>
#include "HaffmanTree.h"
#include <ctime>
#define Algorithm_Haffman 0
#define Algorithm_RLE 1
#define Algorithm_KWE 2
public ref class Compression//класс "архиватора"
{
private:
	int Algorithm;
	int time;
	unsigned long int fileSize;
	double k;
	System::String ^OpenPath, ^SavePath, ^FileExtension;
public:
	Compression(){Algorithm=Algorithm_Haffman;}
	~Compression(){}
	void RLE_Encoding()
	{
		std::ifstream InStream;
		std::ofstream OutStream;
		InStream.open(ToWchart(OpenPath), std::ios::binary);
		OutStream.open(ToWchart(SavePath), std::ios::binary);
		int x1=0, x2=0, count=0;
		if(!InStream.eof()) x1=InStream.get();
		else x1=-1;
		while(x1!=-1)
		{
			count=1;
			if((x2=InStream.get())==EOF) x2=-1;
			while(x1==x2&&x1!=-1)
			{
				count++;
				x1=x2;
				if((x2=InStream.get())==EOF) x2=-1;
				if(count==255) 
				{
					break;
				}
			}
			if(x1!=-1)
			{
				OutStream.put(x1);
				OutStream.put(count);
			}
			x1=x2;
		}
		InStream.close();
		OutStream.close();
	}
	bool RLE_Decoding()
	{
		std::ifstream InStream;
		std::ofstream OutStream;
		InStream.open(ToWchart(OpenPath), std::ios::binary);
		OutStream.open(ToWchart(SavePath), std::ios::binary);
		InStream.seekg(6, std::ios::beg);
		int x, count;
		while((x=InStream.get())!=EOF)
		{
			if((count=InStream.get())==EOF) 
			{
				InStream.close();
				OutStream.close();
				return false;//если произойдёт, значит файл не является файлом сжатым с помощью RLE
			}
			while(count!=0)
			{
				OutStream.put(x);
				count--;
			}
		}
		InStream.close();
		OutStream.close();
		return true;
	}
	void Haffman_Encoding()
	{
		std::ifstream InStream;
		std::ofstream OutStream;
		InStream.open(ToWchart(OpenPath), std::ios::binary);
		OutStream.open(ToWchart(SavePath), std::ios::binary);
		//---------------------------------ПЛАН-----------------------------------//
		//1. определить частоты различных байтов(символов)
		//2. "построить" кодовое дерево Хаффмана(создать отдельный класс для этого)
		//3. заполнить словарь
		//4. закодировать исходный файл при помощи словаря
		OutStream.put(0);//для количества количества остаточных бит в конце файла
		HaffmanTree^ H_Tree=gcnew HaffmanTree();
		//1. Определяем частоты различных байтов(символов)
		unsigned long int *bytesCount=new unsigned long int[256];
		for(int i=0; i<256; i++) bytesCount[i]=0;
		int x1=InStream.get();
		int count=0;
		while(!InStream.eof())
		{
			if(bytesCount[x1]<4294967296) bytesCount[x1]++;
			x1=InStream.get();
		}
		//2. Строим кодовое дерево Хаффмана
		for(int i=0; i<=255; i++)
		{
			if(bytesCount[i]>0) 
			{
				H_Tree->Add(i, bytesCount[i]);
			}
		}
		InStream.close();
		InStream.open(ToWchart(OpenPath), std::ios::binary);
		H_Tree->TreeBuilding();//узлы сортируются по частоте и строится дерево
		//3. Заполняем словарь
		int **map=H_Tree->GetData();
		for(int i=0; i<H_Tree->GetCount(); i++)
		{
			OutStream.put(map[i][0]);//частота вхождений
			OutStream.put(map[i][1]);//символ
		}
		OutStream.put(0);//конец словаря
		//4. Кодируем исходный файл при помощи словаря
		H_Tree->Coding();//подсчитать коды для каждого символа+сортировка по коду символа
		System::String^ code="";
		x1=InStream.get();
		while(!InStream.eof())
		{
			while(code->Length<8)
			{
				if(!InStream.eof()) 
				{
					code+=H_Tree->GetCode(x1);
					x1=InStream.get();
				}
				else break;
			}
			if(code->Length>=8) OutStream.put(H_Tree->GetByte(code->Substring(0, 8)));
			if(code->Length>8) code=code->Substring(8, code->Length-8);
			else if(code->Length==8) code="";
		}
		while(code->Length>8) 
		{
			OutStream.put(H_Tree->GetByte(code->Substring(0, 8))); 
			code=code->Substring(8, code->Length-8);
		}
		int EndBitCount=0;
		while(code->Length<8&&code->Length>0) {code+="0"; EndBitCount++;}
		if(code->Length!=0) OutStream.put(H_Tree->GetByte(code->Substring(0, 8)));
		OutStream.seekp(6);
		OutStream.put(EndBitCount);
		InStream.close();
		OutStream.close();
	}
	void Haffman_Decoding()
	{
		std::ifstream InStream;
		std::ofstream OutStream;
		InStream.open(ToWchart(OpenPath), std::ios::binary);
		OutStream.open(ToWchart(SavePath), std::ios::binary);
		InStream.seekg(6, std::ios::beg);
		int x;
		double time;
		time=clock();
		int EndBitCount=InStream.get();
		unsigned long int frequency;
		HaffmanTree^ H_Tree=gcnew HaffmanTree();
		//считываем словарь
		while((frequency=InStream.get())!=0)
		{
			x=InStream.get();
			H_Tree->Add(x, frequency);
		}
		H_Tree->TreeBuilding();
			
		System::String^ Code="";
		x=InStream.get();
		int x2=InStream.get();
		while(x!=-1)
		{
			for(int i=7; i>=0; i--)
			{
				int temp=1;
				for(int j=0; j<i; j++) temp*=2;
				if(x>=temp) 
				{
					Code+="1";
					x-=temp;
				}
				else if(x2!=-1||i+1>EndBitCount) Code+="0";
			}
			int byte;
			while((byte=H_Tree->GetSymbol(Code))!=-1)
			{
				OutStream.put(byte);
			}
			x=x2;
			x2=InStream.get();
		}
		InStream.close();
		OutStream.close();
	}
	const wchar_t *ToWchart(System::String^ str)
	{
		pin_ptr<const wchar_t> result=PtrToStringChars(str);
		return result;
	}
	int *BigEndian(int Numb)
	{
		//функция переводящая число в два байта в формате Big-Endian
		System::String^ Bits=ToBits(Numb, 16);
		int *result=new int[2];
		result[0]=ToNumber(Bits->Substring(8, 8));//low byte
		result[1]=ToNumber(Bits->Substring(0, 8));//high byte
		return result;
	}
	int BigEndian(int *mas)
	{
		System::String^ Bits=ToBits(mas[1], 8)+ToBits(mas[0], 8);//соединяем старший и младший байт в одной строке
		return ToNumber(Bits);
	}
	System::String^ ToBits(unsigned long int Numb, int Size)
	{
		System::String^ result="";
		int i=Size-1;
		while(i>=0)
		{
			if(Numb>=pow(2.0, i))
			{
				result+="1";
				Numb-=(unsigned long int)pow(2.0, i);
			}
			else result+="0";
			i--;
		}
		return result;
	}
	unsigned long int ToNumber(System::String^ Bits)
	{
		unsigned long int result=0;
		for(int i=0; i<Bits->Length; i++)
		{
			if(Bits->Substring(i, 1)=="1")
			{
				result+=(unsigned long int)pow(2.0, Bits->Length-i-1);
			}
		}
		return result;
	}	
	int *Encode(System::String^ str)
	{
		int *result=new int[str->Length];
		System::String^ Encoding="       \a\b\t\n\v\f\r                   !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~ЂЃ‚ѓ„…†‡€‰Љ‹ЊЌЋЏђ‘’“”•–—™љ›њќћџ ЎўЈ¤Ґ¦§Ё©Є«¬­®Ї°±Ііґµ¶·ё№є»јЅѕїАБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдежзийклмнопрстуфхцчшщъыьэюя";
		for(int i=0; i<str->Length; i++)
		{
			int j=Encoding->Length-1;
			while(j>=0&&str->Substring(i, 1)!=Encoding->Substring(j, 1)) j--;
			result[i]=j;
		}
		return result;
	}
	System::String ^Decode(int *bytes, int size)
	{
		System::String^ result;
		System::String^ Encoding="       \a\b\t\n\v\f\r                   !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~ЂЃ‚ѓ„…†‡€‰Љ‹ЊЌЋЏђ‘’“”•–—™љ›њќћџ ЎўЈ¤Ґ¦§Ё©Є«¬­®Ї°±Ііґµ¶·ё№є»јЅѕїАБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдежзийклмнопрстуфхцчшщъыьэюя";
		for(int i=0; i<size; i++)
		{
			result+=Encoding->Substring(bytes[i], 1);
		}
		return result;
	}
	void SaveResults()
	{
		//структура файла: расширение файла(*) Алгоритм0|1(1) размер файла(4) коэф.сжатия(2) время обработки файла(3)  
		std::ofstream file;
		file.open("arch.dat", std::ios::app|std::ios::binary);
		ExtensionDefinition();//определяем расширение файла
		int *ext=Encode(this->FileExtension);
		for(int i=0; i<FileExtension->Length; i++)
		{
			file.put(ext[i]);
		}
		file.put(Algorithm);//0 Haffan, 1 RLE
		int *mas=BigEndian(fileSize);
		mas=BigEndian(ToNumber(ToBits(fileSize, 32)->Substring(16,16)));
		file.put(mas[0]); file.put(mas[1]);//два младших байта размера файла
		mas=BigEndian(ToNumber(ToBits(fileSize, 32)->Substring(0,16)));
		file.put(mas[0]); file.put(mas[1]);//два старших байта размера файла
		mas=BigEndian((int)(k+0.000001));
		file.put(mas[0]); file.put(mas[1]);//2 байта коэф. сжатия
		mas=BigEndian(ToNumber(ToBits(time, 24)->Substring(8, 16)));
		file.put(mas[0]); file.put(mas[1]);//два младших байта времени обработки файла
		file.put(ToNumber(ToBits(time, 24)->Substring(0, 8)));//cтарший байт времени обработки файла
		file.close();
	}
	void ExtensionDefinition()
	{
		int i=OpenPath->Length-1;
		while(i>=0&&OpenPath->Substring(i, 1)!=".") i--;
		if(i!=-1) FileExtension=OpenPath->Substring(i+1, OpenPath->Length-i-1);
		else FileExtension="?";
	}
	bool Compress(System::String^ openPath, System::String^ savePath)//сжать файл, лежащий по пути Path, и сохранить по пути Directory
	{
		OpenPath=openPath; SavePath=savePath;
		std::ofstream OutStream;
		OutStream.open(ToWchart(SavePath), std::ios::binary);
		if(!OutStream.is_open()) return false;
		OutStream.put(46); OutStream.put(97); OutStream.put(114); OutStream.put(99); OutStream.put(104); //метка .arch файла
		OutStream.put(Algorithm);//запоминаем номер алгоритма в файле
		time=clock();
		if(Algorithm==Algorithm_RLE) RLE_Encoding();
		else if(Algorithm==Algorithm_KWE){/*алгоритм LZW*/}
		else if(Algorithm==Algorithm_Haffman) Haffman_Encoding();
		time=clock()-time;
		std::ifstream InStream(ToWchart(OpenPath), std::ios::binary);
		InStream.seekg(0, std::ios::end);
		k=(double)InStream.tellg();
		fileSize=InStream.tellg();
		InStream.close();
		InStream.open(ToWchart(SavePath), std::ios::binary);
		InStream.seekg(0, std::ios::end);
		k/=(double)InStream.tellg();
		k*=100.0;
		InStream.close();
		SaveResults();
		return true;
	}
	bool Uncompress(System::String^ openPath, System::String^ savePath)//распаковать файл, лежащий по пути Path, в указанную папку Directory
	{
		std::ifstream InStream;
		std::ofstream OutStream;
		pin_ptr<const wchar_t> name=PtrToStringChars(openPath);
		InStream.open(name, std::ios::binary);
		name=PtrToStringChars(savePath);
		OutStream.open(name, std::ios::binary);
		if(OutStream.is_open()==false)
		{
			int i=openPath->Length-1;
			while(openPath->Substring(i, 1)!="\\") i--;
			name=PtrToStringChars(savePath+"\\"+openPath->Substring(i+1, openPath->Length-i-1));
			OutStream.open(name, std::ios::binary);
		}
		if(!InStream.is_open()||!OutStream.is_open()) return false;
		int temp;
		//если первые байты не 46 97 114 99 104 (.arch) и последующий байт больше двух (номер алгоритма)
		if(InStream.get()!=46||InStream.get()!=97||InStream.get()!=114||InStream.get()!=99||InStream.get()!=104||(temp=InStream.get())>2||temp==-1) return false;
		InStream.close();
		OutStream.close();
		OpenPath=openPath; SavePath=savePath;
		Algorithm=temp;
		if(Algorithm==Algorithm_RLE) RLE_Decoding();
		else if(Algorithm==Algorithm_Haffman) Haffman_Decoding();
		//SaveResults();
		return true;
	}
	System::Void ChangeAlgorithm(int i)
	{
		Algorithm=i;
	}
	System::String^ READ(System::String^ Path, System::String^ Separator, bool Numeration)
			 {
				 std::ifstream InStream;
				 System::String^ result;
				 pin_ptr<const wchar_t> name=PtrToStringChars(Path);
				 InStream.open(name, std::ios::binary);
				 int i, counter=0;
				 while((i=InStream.get())!=EOF)
				 {
					 if(Numeration) result+=System::Convert::ToString(++counter)+"). ";
					 result+=i+Separator;
				 }
				 InStream.close();
				 return result;
			 }
	bool WRITE(System::String^ Path, System::String^ Text, System::String^ Separator)
			 {
				 std::ofstream OutStream;
				 pin_ptr<const wchar_t> name=PtrToStringChars(Path);
				 OutStream.open(name, std::ios::binary);
				 if(!OutStream.is_open()) return false;
				 System::String^ temp;
				 for(int i=0; i<Text->Length; i++)
				 {
					 temp="";
					 while(Text->Substring(i, 1)!=Separator) 
					 {
						 temp+=Text->Substring(i, 1);
						 if(i!=Text->Length-1) i++;
						 else {i++; break;}
					 }
					 if(temp!="") OutStream.put(System::Convert::ToInt32(temp));
				 }
				 OutStream.close();
				 return true;
			 }
};