#pragma once
#include "AnalyzedData.h"
#include <fstream>
namespace ����������������������� {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� AnalysisForm
	/// </summary>
	public ref class AnalysisForm : public System::Windows::Forms::Form
	{
	public:
		AnalysisForm(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
		}
	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~AnalysisForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;

	protected: 
	private:
		/// <summary>
		/// ��������� ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ������������ ����� ��� ��������� ������������ - �� ���������
		/// ���������� ������� ������ ��� ������ ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->chart2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->chart1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->chart2))->BeginInit();
			this->SuspendLayout();
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(400, 6);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(211, 29);
			this->comboBox1->TabIndex = 2;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &AnalysisForm::comboBox1_SelectedIndexChanged);
			// 
			// chart1
			// 
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(12, 94);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::FastPoint;
			series1->Legend = L"Legend1";
			series1->Name = L"Haffman";
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::FastPoint;
			series2->Legend = L"Legend1";
			series2->Name = L"RLE";
			this->chart1->Series->Add(series1);
			this->chart1->Series->Add(series2);
			this->chart1->Size = System::Drawing::Size(382, 300);
			this->chart1->TabIndex = 3;
			this->chart1->Text = L"chart1";
			// 
			// label1
			// 
			this->label1->Location = System::Drawing::Point(12, 397);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(382, 57);
			this->label1->TabIndex = 5;
			this->label1->Text = L"������ �������� ������ ��� ���������� ���� �����...";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label2
			// 
			this->label2->Location = System::Drawing::Point(400, 397);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(382, 57);
			this->label2->TabIndex = 6;
			this->label2->Text = L"���������� �������� ������ ��� ���������� ���� �����...";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// chart2
			// 
			chartArea2->Name = L"ChartArea1";
			this->chart2->ChartAreas->Add(chartArea2);
			legend2->Name = L"Legend1";
			this->chart2->Legends->Add(legend2);
			this->chart2->Location = System::Drawing::Point(400, 94);
			this->chart2->Name = L"chart2";
			series3->ChartArea = L"ChartArea1";
			series3->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::FastPoint;
			series3->Legend = L"Legend1";
			series3->Name = L"Haffman";
			series4->ChartArea = L"ChartArea1";
			series4->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::FastPoint;
			series4->Legend = L"Legend1";
			series4->Name = L"RLE";
			this->chart2->Series->Add(series3);
			this->chart2->Series->Add(series4);
			this->chart2->Size = System::Drawing::Size(382, 300);
			this->chart2->TabIndex = 7;
			this->chart2->Text = L"chart2";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(179, 9);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(215, 21);
			this->label3->TabIndex = 8;
			this->label3->Text = L"�������� ������ �����: ";
			// 
			// label4
			// 
			this->label4->Location = System::Drawing::Point(12, 49);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(382, 42);
			this->label4->TabIndex = 9;
			this->label4->Text = L"����������� ������������ ������(OY) �� ������� �����(OX):";
			// 
			// label5
			// 
			this->label5->Location = System::Drawing::Point(400, 49);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(382, 42);
			this->label5->TabIndex = 10;
			this->label5->Text = L"����������� ������� ������(OY) �� ������� �����(OX):";
			// 
			// AnalysisForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 21);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(794, 465);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->chart2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->comboBox1);
			this->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->Margin = System::Windows::Forms::Padding(5);
			this->Name = L"AnalysisForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"�������������� ������";
			this->Load += gcnew System::EventHandler(this, &AnalysisForm::AnalysisForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->chart1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->chart2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	AnalyzedData^ data;
	int *BigEndian(int Numb)
	{
		//������� ����������� ����� � ��� ����� � ������� Big-Endian
		System::String^ Bits=ToBits(Numb, 16);
		int *result=new int[2];
		result[0]=ToNumber(Bits->Substring(8, 8));//low byte
		result[1]=ToNumber(Bits->Substring(0, 8));//high byte
		return result;
	}
	int BigEndian(int *mas)
	{
		System::String^ Bits=ToBits(mas[1], 8)+ToBits(mas[0], 8);//��������� ������� � ������� ���� � ����� ������
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
		System::String^ Encoding="       \a\b\t\n\v\f\r                   !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~��������������������������������������������������������������������������������������������������������������������������������";
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
		System::String^ Encoding="       \a\b\t\n\v\f\r                   !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~��������������������������������������������������������������������������������������������������������������������������������";
		for(int i=0; i<size; i++)
		{
			result+=Encoding->Substring(bytes[i], 1);
		}
		return result;
	}
	private: System::Void AnalysisForm_Load(System::Object^  sender, System::EventArgs^  e) {
				 data=gcnew AnalyzedData();
				 //��������� �����: ���������� �����(*) ��������-0|1(1) ������ �����(4) ����.������(2) ����� ��������� �����(3)  
				 //bool isDecompress=false;//���� true - ����������, ����� ������
				 int algorithm=0;
				 System::String^ ext;
				 unsigned long int fileSize, time;
				 double k;
				 std::ifstream file;
				 file.open("arch.dat", std::ios::binary);//���� � ����� � �������������� ������
				 if(file.is_open())
				 {
					 
					 int *byte=new int[1];
					 while((byte[0]=file.get())!=-1)
					 {
						 //���������� ���������� �����
						 ext="";
						 while(byte[0]!=0&&byte[0]!=1)
						 {
							 ext+=Decode(byte, 1);
							 byte[0]=file.get();
						 }
						 //���������� ��� ���������(������/��������������-0/1)
						 //isDecompress=byte[0];
						 algorithm=byte[0];
						 int *mas=new int[2];
						 //��������� ������ �����(4 �����)
						 mas[0]=file.get(); mas[1]=file.get();//��� ������� �����
						 fileSize=BigEndian(mas);
						 mas[0]=file.get(); mas[1]=file.get();//��� ������� �����
						 fileSize=ToNumber(ToBits(BigEndian(mas), 16)+ToBits(fileSize, 16));
						 //��������� ����������� ������(2 �����)
						 mas[0]=file.get(); mas[1]=file.get();
						 k=(double)BigEndian(mas)/100.0;
						 //��������� �����(3 �����)
						 mas[0]=file.get(); mas[1]=file.get();//��� ������� �����
						 time=BigEndian(mas);
						 time=ToNumber(ToBits(file.get(), 8)+ToBits(time, 16));
						 if(data->AddFile(ext, algorithm, fileSize, time, k*100.0)==true)//���� ������ ���� ����� ��� �� �����������;
							 comboBox1->Items->Add(ext);
					 }
				 }
				 else
				 {
					 MessageBox::Show("������������ ������ ��� �������!", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
				 }
				 file.close();
			 }
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
				 chart1->Series[0]->Points->Clear();
				 chart1->Series[1]->Points->Clear();
				 chart2->Series[0]->Points->Clear();
				 chart2->Series[1]->Points->Clear();
				 int i;
				 for(i=0; i<data->files.size(); i++)
				 {
					 if(data->files[i]->Extension==comboBox1->Text) break;
				 }
				 if(i==data->files.size()) return;
				 unsigned long int time0=0, time1=0;
				 double k0=0.0, k1=0.0;
				 for(int j=0; j<data->files[i]->file.size(); j++)
				 {
					 File^ info=data->files[i]->file[j];
					 if(info->algorithm==0) 
					 {
						 time0+=info->time;
						 k0+=info->k;
					 }
					 else 
					 {
						 time1+=info->time;
						 k1+=info->k;
					 }
					 chart1->Series[info->algorithm]->Points->AddXY(info->size, info->k);
					 chart2->Series[info->algorithm]->Points->AddXY(info->size, info->time);
				 }
				 label1->Text="� �������, ��� ���� ������ \""+comboBox1->Text+"\" ������ ������ ���������� �������� ";
				 if(k0>=k1&&k0!=0) label1->Text+="��������";
				 else label1->Text+="RLE";
				 label2->Text="� �������, ��� ���� ������ \""+comboBox1->Text+"\" ������ �������� ���������� �������� ";
				 if(time0<=time1&&time0!=0) label2->Text+="��������";
				 else label2->Text+="RLE";
			 }
};
}
