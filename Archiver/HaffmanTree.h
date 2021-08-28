#pragma once
#include <ctime>
class Node//узел
{
public:
	int symbol;//символ(байт)
	unsigned long int frequency;//количество вхождений появления(частота); max=4 294 967 295; min=0;
	int *code;
	int codeLength;
	Node *left;//левый потомок
	Node *right;//правый потомок
	Node *parent;//предок
	//Node(char Symbol, unsigned long int Frequency, Node *Parent, Node *Left, Node *Right)
	//{
	//	symbol=Symbol; 
	//	frequency=Frequency; 
	//	left=Left; 
	//	right=Right; 
	//	parent=Parent;
	//}
	Node()
	{
		left=0;
		right=0;
		parent=0;
		code=0;
		codeLength=0;
	}
	Node(int Symbol, unsigned long int Frequency)
	{
		symbol=Symbol; 
		frequency=Frequency; 
		left=0; 
		right=0; 
		parent=0;
		code=0;
		codeLength=0;
	}
	Node(unsigned long int Frequency)
	{
		symbol=-1; 
		frequency=Frequency; 
		left=0; 
		right=0; 
		parent=0;
	}
	//Node(){left=0; right=0; parent=0;}
	~Node(){delete [] code;}
};
public ref class HaffmanTree
{
private:
	Node *root;
	Node **data;
	int nodeCount;
public:
	HaffmanTree()
	{
		data=new Node*[256];
		for(int i=0; i<256; i++)
		{
			data[i]=new Node(i,0);
		}
		nodeCount=0;
	}
	~HaffmanTree(){}
	void QuickSort(int left, int right, bool key)//key==true - сортируем по частоте, иначе по символам
		 {
			 //сортирует по возрастанию
			 int temp;
			 if(left<right)
			 {
				 temp=Partition(left, right, key);
				 if(temp!=left) QuickSort(left, temp, key);
				 if(temp+1!=right) QuickSort(temp+1, right, key);
			 }
		 }
	int Partition(int left, int right, bool key)//функция возвращающая границу разбиения для функции quickSort
		 {
			 //принцип разбиения: a[i]<x | a[i]>=x , где x - произвольное число из массива
			 //char x, symbol, frequency;
			 Node *x, *temp;
			 int i=left, j=right;
			 //x=data[1][left];//опорный элемент
			 //shift++;
			 x=data[left];
			 for(;;)
			 {
				 if(key==true)//сортируем по частоте
				 {
					 while(data[j]->frequency>=x->frequency&&j!=left)
					 {
						 //compare++;
						 j--;
					 }
					 while(data[i]->frequency<x->frequency&&i!=right)
					 {
						 //compare++;
						 i++;
					 }
				 }
				 else //сортируем по символам
				 {
					 while(data[j]->symbol>=x->symbol&&j!=left)
					 {
						 //compare++;
						 j--;
					 }
					 while(data[i]->symbol<x->symbol&&i!=right)
					 {
						 //compare++;
						 i++;
					 }
				 }
				 if(i<j)
				 //меняем местами меньший элемент с большим, чтобы справа оказались элементы >x, а слева <=x
				 {
					 //shift++;
					 temp=data[i];
					 data[i]=data[j];
					 data[j]=temp;
				 }
				 else return j;
			 }
		 }
	void MinimizeFrequency()//unsigned long int *mas)
	{
		//уменьшает частоты в отсортированном массиве
		int min=1;//минимальное частота на которую можно заменить
		//ищем первый существующий символ:
		int i;
		for(i=0; i<256; i++)
		{
			if(data[i]->frequency==0) continue;
			//if(mas[i]==0) continue;
			else break;
		}
		//unsigned long int temp=mas[i];
		unsigned long int temp=data[i]->frequency;//число хранящее предыдущие одинаковые частоты(если частоты такие 2 2 2 8 3 3, 
		//то на 1й и 2й позиции надо помнить, что предыдущие частоты были так же равны 2, чтобы все три
		//двойки заменились на одно число min, так же на 5й позиции надо помнить что перед 3кой шла тройка, 
		//чтобы обе заменить на одинаковое число)
		data[i]->frequency=min;
		for(i=i+1; i<256; i++)
		{
			if(data[i]->frequency==0) continue;
			if(data[i]->frequency!=temp) {temp=data[i]->frequency; min++;}
			data[i]->frequency=min;
			//if(mas[i]==0) continue;
			//if(mas[i]!=temp) {temp=mas[i]; min++;}
			//mas[i]=min;
		}
	}
	void Add(int Symbol, unsigned long int Frequency)
	{
		//for(int i=0; i<nodeCount; i++)
		//{
		//	if(data[i]->symbol==Symbol) return;//если такой символ уже есть, то не добавляем
		//}
		//if(Frequency<=255) 
		data[Symbol]->frequency=Frequency;
		//else data[nodeCount]=new Node(Symbol, 255);
		nodeCount++;
	}
	void TreeBuilding()
	{
		QuickSort(0, 255, true);//сортируем данные по возрастанию частоты с помощью быстрой сортировки
		MinimizeFrequency();
		Node** NodeList=new Node*[nodeCount];
		for(int i=0, j=0; i<256; i++)
		{
			if(data[i]->frequency==0) continue;
			NodeList[j]=data[i];
			j++;
		}
		int listSize=nodeCount;
		while(listSize!=1)
		{
			Node** TempList=new Node*[listSize-1];//вспомогательный список с новым количеством узлов
			//объединяем первые два узла(они минимальны)
			TempList[0]=new Node(NodeList[0]->frequency+NodeList[1]->frequency);
			TempList[0]->left=NodeList[0]; TempList[0]->right=NodeList[1];
			NodeList[0]->parent=TempList[0]; NodeList[1]->parent=TempList[0];
			//копируем в temp все остальные узлы
			for(int i=1; i<listSize-1; i++)
			{
				TempList[i]=NodeList[i+1];
			}
			listSize--;
			NodeList=new Node*[listSize];
			for(int i=0, j=1; i<listSize; i++, j++)
			{
				//вставляем первый элемент так, чтобы все значения шли по возрастанию
				if(j==listSize||(j!=i&&TempList[0]->frequency<=TempList[j]->frequency))//срабатывает только один раз, после чего i и j уравниваются
				{
					NodeList[i]=TempList[0];
					j--;
				}
				else 
				{
					NodeList[i]=TempList[j];
				}
			}
		}
		root=NodeList[0];
	}
	void Clear()
	{
		root=0;
		delete[] data;
		//data=new Node*[256];
		data=0;
		nodeCount=0;
	}
	void Coding()
	{
		System::String^ Code;
		for(int i=0; i<256; i++)
		{
			Node *x=data[i];
			if(x->frequency==0) continue;//если частота символа 0, значит такого символа нет => переходим на следующую итерацию
			Code=nullptr;
			while(x!=root)
			{
				if(x==x->parent->left) Code+="0";
				else Code+="1";
				x=x->parent;
			}
			if(Code!=nullptr) 
			{
				data[i]->code=new int[Code->Length];
				for(int j=Code->Length-1; j>=0; j--) 
					data[i]->code[j]=System::Convert::ToInt32(Code->Substring(Code->Length-1-j, 1));
				data[i]->codeLength=Code->Length;
			}
		}
		QuickSort(0, 255, false);//сортируем данные по возрастанию кода символа
	}
	System::String^ GetCode(int Symbol)
	{
		if(Symbol<0||Symbol>255) return "Ошибка!";
		Node *x=data[Symbol];
		//for(int i=0; i<nodeCount; i++)
		//{
		//	if(data[i]->symbol==Symbol) x=data[i];
		//}
		if(x->frequency!=0) 
		{
			System::String^ result="";
			for(int i=0; i<x->codeLength; i++) 
				result+=x->code[i];
			return result;
		}
		else return "Такого символа нет!";
	}
	int GetSymbol(System::String^ &Code)
	{
		if(Code=="") return -1;
		Node *x=root;
		int i=0;
		while(x->symbol==-1&&i<Code->Length)
		{
			if(Code->Substring(i, 1)=="0") x=x->left;
			else x=x->right;
			i++;
		}
		if(x->symbol!=-1) 
		{
			if(i<Code->Length) Code=Code->Substring(i, Code->Length-i);
			else Code="";
			return x->symbol;
		}
		else return -1;
	}
	int GetByte(System::String^ code)
	{
		int result=0;
		for(int i=0; i<8; i++)
		{
			int temp=0;
			if(code->Substring(i, 1)=="1")
			{
				temp=1;
				for(int j=0; j<8-i-1; j++) temp*=2;
			}
			result+=temp;
		}
		return result;
	}
	int **GetData()
	{
		int **result=new int*[nodeCount];
		QuickSort(0, 255, true);//отсортируем по частоте по возрастанию перед выводом
		for(int i=0, j=0; i<256; i++)
		{
			if(data[i]->frequency!=0)
			{
				result[j]=new int[2];
				result[j][0]=data[i]->frequency;
				result[j][1]=data[i]->symbol;
				j++;
			}
		}
		return result;
	}
	int GetCount()
	{
		return nodeCount;
	}
	//   A   B   C   D   E   F   G   H
	//   3   1   1   1  1/2 1/2 1/2 1/2
	//   |   |   |___|   |___|   |___|
	//   |   |   0 | 1   0 | 1   0 | 1
	//   3   1     2       1       1
	//   |   |_____|_______|       |
	//   |   0   | |________1______| 
	//   |       2  0       |       1
	//   |_______|          3
    //     0 | 1            |
	//     	 5              |
	//       |______________|
	//       0      |       1
	//              8
	//каждая левая ветвь - 0
	//каждое правая - 1
};
