#pragma once

namespace КурсоваяРаботаархиватор {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для PropertiesForm
	/// </summary>
	public ref class PropertiesForm : public System::Windows::Forms::Form
	{
	public:
		PropertiesForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
		PropertiesForm(System::String^ type, System::String^ path)
		{
			InitializeComponent();
			Path=path;
			if(type=="Folder") 
			{
				this->Text="Свойства папки";
				System::IO::DirectoryInfo^ folder=gcnew System::IO::DirectoryInfo(Path);
				textBox1->Text=Path;
				textBox2->Text+=((System::IO::FileSystemInfo^)folder)->CreationTime.ToString();
				textBox3->Text+=folder->Attributes.ToString();
				backgroundWorker1->RunWorkerAsync();
			}
			else 
			{
				this->Text="Свойства файла";
				System::IO::FileInfo^ file=gcnew System::IO::FileInfo(Path);
				textBox1->Text=Path;
				textBox2->Text+=((System::IO::FileSystemInfo^)file)->CreationTime.ToString();
				textBox3->Text+=file->Attributes.ToString();
				textBox4->Text=file->Length.ToString()+" байт";
			}
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~PropertiesForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;

	private: System::Windows::Forms::Label^  label2;

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::Label^  label4;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;

	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 6);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(80, 15);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Полный путь";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 94);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(86, 15);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Дата создания";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 179);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(63, 15);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Атрибуты";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 24);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(253, 53);
			this->textBox1->TabIndex = 5;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(12, 112);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->Size = System::Drawing::Size(253, 53);
			this->textBox2->TabIndex = 6;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(14, 197);
			this->textBox3->Multiline = true;
			this->textBox3->Name = L"textBox3";
			this->textBox3->ReadOnly = true;
			this->textBox3->Size = System::Drawing::Size(253, 53);
			this->textBox3->TabIndex = 7;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(14, 279);
			this->textBox4->Multiline = true;
			this->textBox4->Name = L"textBox4";
			this->textBox4->ReadOnly = true;
			this->textBox4->Size = System::Drawing::Size(253, 53);
			this->textBox4->TabIndex = 8;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(12, 261);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(47, 15);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Размер";
			// 
			// backgroundWorker1
			// 
			this->backgroundWorker1->WorkerReportsProgress = true;
			this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &PropertiesForm::backgroundWorker1_DoWork);
			this->backgroundWorker1->ProgressChanged += gcnew System::ComponentModel::ProgressChangedEventHandler(this, &PropertiesForm::backgroundWorker1_ProgressChanged);
			// 
			// PropertiesForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(277, 344);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->Name = L"PropertiesForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Свойства";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::String^ Path;
private: unsigned long int fileSize;
private: void GetSize(System::IO::DirectoryInfo^ dir, BackgroundWorker^ worker)
		 {
			 try
			 {
				 for each (System::IO::DirectoryInfo^ subdir in dir->GetDirectories())
				 {
					 GetSize(subdir, worker);
				 }
				 //Перебираем файлы
				 for each (System::IO::FileInfo^ file in dir->GetFiles())
				 {
					 fileSize+=file->Length;
				 }
				 worker->ReportProgress(0);
			 }
			 catch(System::UnauthorizedAccessException^)
			 {
				 //при отказе доступа к данным
				 //MessageBox::Show("Отказанно в доступе к системным данным!", "Добавление вершины дерева", MessageBoxButtons::OK, MessageBoxIcon::Error);
				 //return;
			 }
		 }
private: System::Void backgroundWorker1_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {
			 fileSize=0;
			 GetSize(gcnew System::IO::DirectoryInfo(Path), backgroundWorker1);
		 }
private: System::Void backgroundWorker1_ProgressChanged(System::Object^  sender, System::ComponentModel::ProgressChangedEventArgs^  e) {
			 textBox4->Text=fileSize.ToString()+" байт";
		 }
};
}
